
/** \file hoard.c
 * \brief Cluster fileystem.
 * Automatic IPv6/multicast based cluster/shared filesystem.
 */

/** \mainpage Hoard Filesystem

Some general description of how this fits together.

\dot
digraph {
    node1 -> node2;
}
\enddot

\section introduction Introduction
Some introductory comments.

\todo Add "write" interface
\todo Add "rename" interface
\todo Add sync routines and protocol
\todo Add CRC code (and use it)
\todo Look at mqueue interface
\todo Add stats for each filesytem interface call.

mininova.org
*/

/* this enables pread/pwrite */
#define _XOPEN_SOURCE 500

#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <ucontext.h>

#include <sys/stat.h>
#include <sys/statfs.h>
#include <fcntl.h>
#include <dirent.h>

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <pthread.h>
#include <syslog.h>

/* for networking */
#include <sys/socket.h>
#if 0
#include <arpa/inet.h>
#include <netinet/in.h>
#else
extern int inet_pton (int __af, char *__cp, void *__buf);
extern char *inet_ntop (int __af, void *__cp, char *__buf, socklen_t __len);
#endif
/*
 * we use linux/in.h, because otherwise we do not get a bunch of the constants we need, grumble
 */
#include <linux/in.h>
#include <net/if.h>

#include <linux/in6.h>
#include <linux/ipv6.h>
#include <linux/icmpv6.h>

#define FUSE_USE_VERSION 25
#include <fuse.h>

/* Network message types */
#define INVALID_REQUEST 0
#define   MKDIR_REQUEST 1
#define   RMDIR_REQUEST 2
#define SYMLINK_REQUEST 3
int send_symlink( const char *oldpath, const char *newpath );
#define  CREATE_REQUEST 4
#define   WRITE_REQUEST 5
#define  UNLINK_REQUEST 6
int send_unlink( const char *path );
#define  VALID_MESSAGE_TYPE 7

static struct sockaddr_in6 multicast_address;
static int multicast_socket;

/**
 * The UUID of this machine is determined from the SMBIOS information.  If SMBIOS
 * does not have a UUID, allocate one from the kernel interface.
 *
 * \todo The UUID should be read directly from the SMBIOS area.
 */
static char uuid_string[64];
void copy_uuid(char *src, char *dst) {
    int i = 0;
    while ( i < 64 ) {
        if (src[i] == '\0') break;
        if (src[i] == '\n') break;
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}
void read_uuid() {
    char buffer[80];
    FILE *f = fopen("/etc/sysconfig/spine", "r");
    uuid_string[0] = '\0';
    if ( f == NULL ) {
        /* syslog(LOG_ERR, "failed to read system UUID from /etc/sysconfig/spine"); */
        return; 
    }   
    while ( fgets(buffer, sizeof(buffer), f) != NULL ) {
        if ( buffer[0] != 'U' ) continue;
        if ( buffer[1] != 'U' ) continue;
        if ( buffer[2] != 'I' ) continue;
        if ( buffer[3] != 'D' ) continue;
        if ( buffer[4] != '=' ) continue;
        copy_uuid(buffer+5, uuid_string);
        break;
    }
    fclose(f);
    /* syslog( LOG_NOTICE, "system UUID is '%s'", uuid_string ); */

    /* also save uuid as 128-bit value */
}   

/*  */

/** @defgroup crc32 Simple CRC32
 *
 * @{
 */

unsigned long Ccitt32Table[] = {
    0x00000000L, 0xF26B8303L, 0xE13B70F7L, 0x1350F3F4L, 0xC79A971FL, 0x35F1141CL,
    0x26A1E7E8L, 0xD4CA64EBL, 0x8AD958CFL, 0x78B2DBCCL, 0x6BE22838L, 0x9989AB3BL,
    0x4D43CFD0L, 0xBF284CD3L, 0xAC78BF27L, 0x5E133C24L, 0x105EC76FL, 0xE235446CL,
    0xF165B798L, 0x030E349BL, 0xD7C45070L, 0x25AFD373L, 0x36FF2087L, 0xC494A384L,
    0x9A879FA0L, 0x68EC1CA3L, 0x7BBCEF57L, 0x89D76C54L, 0x5D1D08BFL, 0xAF768BBCL,
    0xBC267848L, 0x4E4DFB4BL, 0x20BD8EDEL, 0xD2D60DDDL, 0xC186FE29L, 0x33ED7D2AL,
    0xE72719C1L, 0x154C9AC2L, 0x061C6936L, 0xF477EA35L, 0xAA64D611L, 0x580F5512L,
    0x4B5FA6E6L, 0xB93425E5L, 0x6DFE410EL, 0x9F95C20DL, 0x8CC531F9L, 0x7EAEB2FAL,
    0x30E349B1L, 0xC288CAB2L, 0xD1D83946L, 0x23B3BA45L, 0xF779DEAEL, 0x05125DADL,
    0x1642AE59L, 0xE4292D5AL, 0xBA3A117EL, 0x4851927DL, 0x5B016189L, 0xA96AE28AL,
    0x7DA08661L, 0x8FCB0562L, 0x9C9BF696L, 0x6EF07595L, 0x417B1DBCL, 0xB3109EBFL,
    0xA0406D4BL, 0x522BEE48L, 0x86E18AA3L, 0x748A09A0L, 0x67DAFA54L, 0x95B17957L,
    0xCBA24573L, 0x39C9C670L, 0x2A993584L, 0xD8F2B687L, 0x0C38D26CL, 0xFE53516FL,
    0xED03A29BL, 0x1F682198L, 0x5125DAD3L, 0xA34E59D0L, 0xB01EAA24L, 0x42752927L,
    0x96BF4DCCL, 0x64D4CECFL, 0x77843D3BL, 0x85EFBE38L, 0xDBFC821CL, 0x2997011FL,
    0x3AC7F2EBL, 0xC8AC71E8L, 0x1C661503L, 0xEE0D9600L, 0xFD5D65F4L, 0x0F36E6F7L,
    0x61C69362L, 0x93AD1061L, 0x80FDE395L, 0x72966096L, 0xA65C047DL, 0x5437877EL,
    0x4767748AL, 0xB50CF789L, 0xEB1FCBADL, 0x197448AEL, 0x0A24BB5AL, 0xF84F3859L,
    0x2C855CB2L, 0xDEEEDFB1L, 0xCDBE2C45L, 0x3FD5AF46L, 0x7198540DL, 0x83F3D70EL,
    0x90A324FAL, 0x62C8A7F9L, 0xB602C312L, 0x44694011L, 0x5739B3E5L, 0xA55230E6L,
    0xFB410CC2L, 0x092A8FC1L, 0x1A7A7C35L, 0xE811FF36L, 0x3CDB9BDDL, 0xCEB018DEL,
    0xDDE0EB2AL, 0x2F8B6829L, 0x82F63B78L, 0x709DB87BL, 0x63CD4B8FL, 0x91A6C88CL,
    0x456CAC67L, 0xB7072F64L, 0xA457DC90L, 0x563C5F93L, 0x082F63B7L, 0xFA44E0B4L,
    0xE9141340L, 0x1B7F9043L, 0xCFB5F4A8L, 0x3DDE77ABL, 0x2E8E845FL, 0xDCE5075CL,
    0x92A8FC17L, 0x60C37F14L, 0x73938CE0L, 0x81F80FE3L, 0x55326B08L, 0xA759E80BL,
    0xB4091BFFL, 0x466298FCL, 0x1871A4D8L, 0xEA1A27DBL, 0xF94AD42FL, 0x0B21572CL,
    0xDFEB33C7L, 0x2D80B0C4L, 0x3ED04330L, 0xCCBBC033L, 0xA24BB5A6L, 0x502036A5L,
    0x4370C551L, 0xB11B4652L, 0x65D122B9L, 0x97BAA1BAL, 0x84EA524EL, 0x7681D14DL,
    0x2892ED69L, 0xDAF96E6AL, 0xC9A99D9EL, 0x3BC21E9DL, 0xEF087A76L, 0x1D63F975L,
    0x0E330A81L, 0xFC588982L, 0xB21572C9L, 0x407EF1CAL, 0x532E023EL, 0xA145813DL,
    0x758FE5D6L, 0x87E466D5L, 0x94B49521L, 0x66DF1622L, 0x38CC2A06L, 0xCAA7A905L,
    0xD9F75AF1L, 0x2B9CD9F2L, 0xFF56BD19L, 0x0D3D3E1AL, 0x1E6DCDEEL, 0xEC064EEDL,
    0xC38D26C4L, 0x31E6A5C7L, 0x22B65633L, 0xD0DDD530L, 0x0417B1DBL, 0xF67C32D8L,
    0xE52CC12CL, 0x1747422FL, 0x49547E0BL, 0xBB3FFD08L, 0xA86F0EFCL, 0x5A048DFFL,
    0x8ECEE914L, 0x7CA56A17L, 0x6FF599E3L, 0x9D9E1AE0L, 0xD3D3E1ABL, 0x21B862A8L,
    0x32E8915CL, 0xC083125FL, 0x144976B4L, 0xE622F5B7L, 0xF5720643L, 0x07198540L,
    0x590AB964L, 0xAB613A67L, 0xB831C993L, 0x4A5A4A90L, 0x9E902E7BL, 0x6CFBAD78L,
    0x7FAB5E8CL, 0x8DC0DD8FL, 0xE330A81AL, 0x115B2B19L, 0x020BD8EDL, 0xF0605BEEL,
    0x24AA3F05L, 0xD6C1BC06L, 0xC5914FF2L, 0x37FACCF1L, 0x69E9F0D5L, 0x9B8273D6L,
    0x88D28022L, 0x7AB90321L, 0xAE7367CAL, 0x5C18E4C9L, 0x4F48173DL, 0xBD23943EL,
    0xF36E6F75L, 0x0105EC76L, 0x12551F82L, 0xE03E9C81L, 0x34F4F86AL, 0xC69F7B69L,
    0xD5CF889DL, 0x27A40B9EL, 0x79B737BAL, 0x8BDCB4B9L, 0x988C474DL, 0x6AE7C44EL,
    0xBE2DA0A5L, 0x4C4623A6L, 0x5F16D052L, 0xAD7D5351L
};

/**
 * The crc argument allows you to build up a CRC gradually (eg - as you
 * read an input stream.  Pass in 0 the first time and pass in the result
 * of the last block for each subsequent block.
 */

unsigned long blockCRC32( unsigned int count, unsigned long crc, void *buffer ) {
    unsigned char *p = (unsigned char *)buffer;
    unsigned long temp1, temp2;

    while ( count-- != 0 ) {
        temp1 = ( crc >> 8 ) & 0x00FFFFFFL;
	temp2 = Ccitt32Table[ ((int)crc ^ *p++) & 0xFF ];
	crc = temp1 ^ temp2;
    }

    return crc;
}

unsigned long charCRC32( unsigned long crc, int c ) {
    unsigned long temp1, temp2;
    temp1 = ( crc >> 8 ) & 0x00FFFFFFL;
    temp2 = Ccitt32Table[ ((int)crc ^ c) & 0xff ];
    crc = temp1 ^ temp2;
    return crc;
}

unsigned long stringCRC32( char *s ) {
    return blockCRC32( strlen(s), 0, s );
}
/* @} */

/** @defgroup cache Cache Management Interface
 *
 * These routines are called both by the filsystem interface and by the
 * network interface.  The network interface is called in response to
 * messages from the peer nodes.
 *
 * @{
 */

char *cache = "/var/cache/hoard";
char *data = "/var/cache/hoard/data";
char *meta = "/var/cache/hoard/meta";
char *journal_filename = "/var/cache/hoard/journal";

/**
 * Each directory present in the filesystem is represented in the cache
 * by a directory of the same name and a hidden meta data directory named
 * "..."
 */

int cache_mkdir(const char *path, mode_t mode) { 
    int result = 0;
    char buffer[2048];

 syslog( LOG_NOTICE, "MKDIR: %s\n", path ); 

    strcpy(buffer, data);
    /* only really need to do this if path doesn't start with a "/" */
    strcat(buffer, "/");
    strcat(buffer, path);

    result = mkdir( buffer, mode );
    if ( result == -1 ) {
        syslog( LOG_NOTICE, "failed to mkdir %s in the cache: %s\n", path, strerror(errno) );
        return -errno;
    }
    /* lchown(path, fuse_get_context()->uid, fuse_get_context()->gid); */

    /* for meta data */
    strcat(buffer, "/...");
    result = mkdir( buffer, mode );
    if ( result == -1 ) {
        syslog( LOG_NOTICE, "failed to mkdir %s in the cache\n", buffer );
        return -errno;
    }
    /* lchown(path, fuse_get_context()->uid, fuse_get_context()->gid); */

    return 0;
} 

/**
 */

int cache_rmdir(const char *path) { 
    int result = 0;
    char buffer[512];
    char meta[512];

syslog( LOG_NOTICE, "RMDIR: %s\n", path );

    strcpy(buffer, data);
    strcat(buffer, path);

    strcpy(meta, buffer);
    strcat(meta, "/...");

    /**
     * must remove meta data dir first.
     * Should check for the presence of data in the metadata dir.
     */
    result = rmdir( meta );
    if ( result == -1 ) {
        /**
         * Here I need to check if we failed to remove it because the
         * meta dir was not present.  Because if so we can skip this
         * error.
         */
        return -errno;
    }

    result = rmdir( buffer );
    if ( result == -1 ) {
        return -errno;
    }

    return 0;
} 

/**
 */

int cache_symlink(const char *oldpath, const char *newpath) { 
    int result = 0;
    char buffer[2048];

/* syslog( LOG_NOTICE, "SYMLINK: %s => %s\n", newpath, oldpath ); */

    strcpy(buffer, data);
    strcat(buffer, newpath);

/* syslog( LOG_NOTICE, " linking: %s => %s\n", buffer, oldpath ); */
    result = symlink( oldpath, buffer );
    if ( result == -1 ) {
        return -errno;
    }
    /* lchown(path, fuse_get_context()->uid, fuse_get_context()->gid); */
    /* set mtime? */

    return 0;
} 

/**
 */

int cache_unlink( const char *path ) { 
    int result;
    char buffer[2048];

syslog( LOG_NOTICE, "UNLINK\n" );
    strcpy(buffer, data);
    strcat(buffer, path);

    result = unlink(buffer);
    if ( result == -1 ) {
        return -errno;
    }
    return 0;
}

/**
 */
static int
cache_write( const char *path, const char *buf, size_t size, off_t offset ) {
    int fd;
    int result = 0;
    char buffer[2048];
    int journal;

    /* syslog( LOG_NOTICE, "WRITE %d:%d\n", offset, size ); */
    strcpy(buffer, data);
    strcat(buffer, path);

    fd = open( buffer, O_CREAT | O_WRONLY );
    if ( fd == -1 ) {
        result = -errno;
        syslog( LOG_NOTICE, "write error opening '%s': %s\n", buffer, strerror(errno) );
        return result;
    }

    result = pwrite( fd, buf, size, offset );
    if ( result == -1 ) { 
        syslog( LOG_NOTICE, "error writing file\n" );
        close( fd );
        return -errno;
    }
    fdatasync( fd );
    close( fd );
    return result;
}

static int
cache_create(const char *path, mode_t mode ) {   
    int fd;
    char buffer[2048];

    /* syslog( LOG_NOTICE, "CREAT\n" ); */
    strcpy(buffer, data);
    strcat(buffer, path);

    fd = creat(buffer, mode);
    if ( fd == -1 ) {
        return -errno;
    }
    close( fd );
    return 0;
}

/* @} */

/** @defgroup filesystem The Filesystem Interface
 *
 * The following functions provide the FUSE interface to the shared filesystem.
 * Requests through this interface may also send network messages.
 *
 * @{
 */

struct hoard_context {
    int journal;
};
static struct hoard_context context;

/** @brief statfs_op
 */

static int
statfs_op(const char *path, struct statvfs *st_buf) {
    int result = 0;

    result = statvfs(path, st_buf);
    st_buf->f_bsize = 1024;
    st_buf->f_frsize = 1024;
    if (result == -1)
        return -errno;
    return result;
}

static int
getattr_op(const char *path, struct stat *st_data) {
    int result = 0;
    char buffer[2048];
    strcpy(buffer, data);
    strcat(buffer, path);

    result = lstat(buffer, st_data);
    if ( result == -1 ) {
        return -errno;
    }

/*
    st_data->st_mode = 0777;
    st_data->st_uid = 0;
    st_data->st_gid = 0;
*/

    return result;
}

static int
readdir_op(const char *path, void *__buffer, fuse_fill_dir_t fill, off_t offset, struct fuse_file_info *info) {
    int result = 0;
    struct dirent *entry;
    DIR *dir;
    char buffer[2048];

    strcpy(buffer, data);
    strcat(buffer, path);

    dir = opendir(buffer);
    if ( dir == 0 ) {
        result = -errno;
        /* log problem */
        return result;
    }
    while ( (entry = readdir(dir)) != 0 ) {
        struct stat st;
        /* do not include "..." */
        if ( strcmp("...", entry->d_name) == 0 ) {
syslog( LOG_NOTICE, "skipping ...\n" );
            continue;
        }
        memset(&st, 0, sizeof(st));
        st.st_ino = entry->d_ino;
        st.st_mode = entry->d_type << 12;
        if ( fill(__buffer, entry->d_name, &st, 0) ) break;
    }
    closedir(dir);

    return result;
}

static int
mknod_op(const char *path, mode_t mode, dev_t rdev) { 
syslog( LOG_NOTICE, "MKNOD\n" );
  /*
  return create_new_file(path, mode, fuse_get_context()->uid, fuse_get_context()->gid, rdev);
  */
} 

static int
mkdir_op(const char *path, mode_t mode) { 
    int result;
    result = cache_mkdir(path, mode);
    if ( result < 0 ) {
        syslog( LOG_WARNING, "mkdir result = %d, not forwarding mkdir request\n", result );
        return result;
    }
    send_mkdir( path, mode );
    return result;
} 

static int
rmdir_op(const char *path) {   
    int result;
    result = cache_rmdir( path );
    if ( result < 0 ) return result;
    send_rmdir( path );
    return result;
}

static int
symlink_op(const char *from, const char *to) {
    int result;
    result = cache_symlink( from, to );
    if ( result < 0 ) return result;
    send_symlink( from, to );
    return result;
} 

static int
rename_op(const char *from, const char *to) {
syslog( LOG_NOTICE, "RENAME\n" );
  /*
   * Not suppored, because there is always a fallback path, and we don't
   * version moves per se, so just let the calling program do the move
   * "manually".
   */
  (void)from;   
  (void)to;
  return -EXDEV;
}   

static int
link_op(const char *from, const char *to) {   
syslog( LOG_NOTICE, "LINK\n" );
  /*
   * Forbid hard links, since there is no way to make them point to a new
   * version if need be.
   */
  (void)from;   
  (void)to;     
  return -EPERM;
}

static int
chmod_op(const char *path, mode_t mode) {   
  return 0;
}

static int
chown_op(const char *path, uid_t uid, gid_t gid) {
  return 0;
}

static int
truncate_op(const char *path, off_t size) {
syslog( LOG_NOTICE, "TRUNCATE\n" );
    return 0;
}

static int
utime_op(const char *path, struct utimbuf *buf) {
/* syslog( LOG_NOTICE, "UTIME\n" ); */
  return 0;
}

static int
open_op(const char *path, struct fuse_file_info *info) {
syslog( LOG_NOTICE, "OPEN\n" );
  return 0;
}

static int
read_op( const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *info ) {
    int fd;
    int result = 0;
    char buffer[2048];

syslog( LOG_NOTICE, "READ\n" );
    strcpy(buffer, data);
    strcat(buffer, path);

    fd = open( buffer, O_RDONLY );
    if ( fd == -1 ) {
        result = -errno;
        /* log it */
        return result;
    }
    result = pread( fd, buf, size, offset );
    if ( result == -1 ) { 
        return -errno;
    }
    close( fd );
    return result;

}

static int
write_op( const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *info ) {
    int result;
    if ( size > 1024 ) return -EFBIG;
    result = cache_write( path, buf, size, offset );
    if ( result < 0 ) {
        syslog( LOG_WARNING, "write result = %d, not forwarding write request\n", result );
        return result;
    }
    send_write( path, buf, size, offset );
    return result;
}


static int
readlink_op(const char *path, char *buf, size_t size) {
    int result = 0;
    char buffer[2048];

syslog( LOG_NOTICE, "READLINK\n" );
    strcpy(buffer, data);
    strcat(buffer, path);

    result = readlink( buffer, buf, size - 1 );
    if ( result == -1 ) {
        return -errno;
    }
    buf[result] = '\0';
    return 0;
}

static int
fsync_op( const char *path, int isdatasync, struct fuse_file_info *info ) {
syslog( LOG_NOTICE, "FSYNC\n" );
  /* No special treatment */
  (void) path;
  (void) isdatasync;
  return 0;
}

static int
release_op( const char *path, struct fuse_file_info *info ) {
/* syslog( LOG_NOTICE, "RELEASE\n" ); */
  /* No special treatment */
  (void) path;
  return 0;
}

static int
unlink_op(const char *path) {
    int result;
    result = cache_unlink( path );
    if ( result < 0 ) return result;
    send_unlink( path );
    return result;
}   

static int
access_op(const char *path, int arg) {   
syslog( LOG_NOTICE, "ACCESS\n" );
  return 0;
}

static int
create_op(const char *path, mode_t mode, struct fuse_file_info *info) {   
    int result;
    result = cache_create( path, mode );
    if ( result < 0 ) return result;
    send_create( path, mode );
    return result;
}

static void *
init_op(void) {
    char *data = 0;

    context.journal = open( journal_filename, O_RDWR | O_CREAT | O_APPEND, 0777 );
    if ( context.journal == -1 ) {
        syslog( LOG_NOTICE, "failed to open journal\n" );
    }
    if ( write( context.journal, "start\n", 6 ) == -1 ) {
        perror( "start failed" );
    }

    return &context;
}

static void
destroy_op( void *data ) {
}

struct fuse_operations ops = {
    .getattr  = getattr_op,
    .readlink = readlink_op,
    .readdir  = readdir_op,
    .mknod    = mknod_op,
    .mkdir    = mkdir_op,
    .symlink  = symlink_op,
    .unlink   = unlink_op,
    .rmdir    = rmdir_op,
    .rename   = rename_op,
    .link     = link_op,
    .chmod    = chmod_op,
    .chown    = chown_op,
    .truncate = truncate_op,
    .utime    = utime_op,
    .open     = open_op,
    .read     = read_op,
    .write    = write_op,
    .statfs   = statfs_op,
    .release  = release_op,
    .fsync    = fsync_op,
    .init     = init_op,
    .destroy  = destroy_op,
    .access   = access_op,
    .create   = create_op,
};

/* @} */

/** @defgroup network The Network Interface
 *
 * The network interface communicates over the private link (only),
 * multicast IPv6 UDP messages that describe state change to the
 * shared filesystem.
 *
 * I probably want the transactions to be IDed so if one is missed
 * we can reattempt it.  However, if it is lost and then the node
 * goes does we cannot wait for the transaction before continuing.
 * Hmmm, unless it will not matter since the node is down and will
 * resync when it returns to service.
 *
 * \todo Need to add: request methods to send requests, message parsers
 * to dispatch messages, and message handlers to implement the message
 * handlers.
 * @{
 */

/** Bounce diagram.
 \msc
 Node0,Node1;
 Node0->Node1 [label="Sync CRC depth=1 /"];
 Node0<-Node1 [label="SyncAck CRC /"];

 Node0->Node1 [label="Sync CRC depth=1 /domains"];
 Node0<-Node1 [label="Mkdir mtime /domains/deadbeef"];
 Node0<-Node1 [label="SymLink mtime /domains/foo deadbeef"];
 Node0<-Node1 [label="Write mtime 0,32 /domains/junk [data...]"];
 Node0<-Node1 [label="SyncAck CRC /domains"];

 # Since the Ack/CRC still doesn't match, check each file.
 Node0->Node1 [label="Sync CRC depth=0 /domains/deadbeef"];
 Node0<-Node1 [label="SyncAck CRC /domains/deadbeef"];
 # ^^ this one should have matched, so no more node0->node1 for it.

 Node0->Node1 [label="Sync CRC depth=0 /domains/crap"];
 Node0<-Node1 [label="Unlink /domains/crap"];
 # ... continue with rest of /domains/... then
 Node0->Node1 [label="Sync CRC depth=1 /domains"];
 Node0<-Node1 [label="SyncAck CRC /domains"];
 # whole thing matches so done

 \endmsc
 */

/**
 * This is a request from the peer node to check if the given path
 * matches the CRC locally and transmit the path (and children) if
 * the CRC doesn't match.
 */

int Sync( int depth, char *path ) {
    /* Check that the path matches the CRC */

    /* send the change list if it doesn't */

    /**
     * send an Ack always, if it matched then you get just the Ack
     * then the requester will recheck the CRC
     */
}

int SyncAck( ) {
    /* check the CRC against the path */
    /* if it matches we're done */
    /* if it doesn't, validate each child/depth(0) -- which causes deletes */
}

/**
 * Create the local cache directory.  Do not error if the directory
 * already exists.
 */
int send_mkdir( const char *path, mode_t mode ) {
    char packet[1500];
    mode_t *mode_p;
    int length;
    int result;

    packet[0] = MKDIR_REQUEST;
    mode_p = (mode_t *)(packet + 4);
    *mode_p = htonl( mode );
    strcpy(packet+8, path);
    length = strlen(path) + 9;
    result = sendto( multicast_socket, packet, length, 0, (struct sockaddr *)&multicast_address, sizeof(multicast_address));
    if ( result == -1 ) {
        syslog(LOG_ERR, "failed to send mkdir message");
    } else {
        syslog(LOG_NOTICE, "send mkdir message: %s", path );
    }
}

int recv_mkdir( char *data ) {
    char path[512];
    mode_t mode;

    mode = ntohl( *( (uint32_t*)(data+3) ) );
    strcpy(path, data+7);
    cache_mkdir( path, mode );
}

/**
 * Create the local cache directory.  Do not error if the directory
 * already exists.
 */
int send_rmdir( const char *path ) {
    char packet[1500];
    int length;
    int result;

    packet[0] = RMDIR_REQUEST;
    strcpy(packet+1, path);
    length = strlen(path) + 2;
    result = sendto( multicast_socket, packet, length, 0, (struct sockaddr *)&multicast_address, sizeof(multicast_address));
    if ( result == -1 ) {
        syslog(LOG_ERR, "failed to send rmdir message");
    } else {
        syslog(LOG_NOTICE, "send rmdir message");
    }
}

int recv_rmdir( char *data ) {
    char path[512];
    strcpy(path, data);
    cache_rmdir( path );
}

/**
 * Create the symlink in the local cache.  If the link already exists, then
 * eliminate the old and create the new.  Probably more efficient to examine
 * the one that already exists and only recreate if it doesn't match the
 * requested link.
 \dot
 digraph {
     request [shape=record,label="{ 0x1 | {len | oldpath} | {len | newpath} }"];
 }
 \enddot
 */

int send_symlink( const char *oldpath, const char *newpath ) {
    char packet[1500];
    int oldlen, newlen;
    int length;
    int result;

    packet[0] = SYMLINK_REQUEST;
    oldlen = strlen(oldpath);
    newlen = strlen(newpath);
    strcpy(packet+1, oldpath);
    strcpy(packet+1+oldlen+1, newpath);
    length = oldlen + newlen + 3;
    result = sendto( multicast_socket, packet, length, 0, (struct sockaddr *)&multicast_address, sizeof(multicast_address));
    if ( result == -1 ) {
        syslog(LOG_ERR, "failed to send symlink message");
    } else {
        /* syslog(LOG_NOTICE, "send symlink message"); */
    }
}

int recv_symlink( char *data ) {
    char oldpath[512];
    char newpath[512];
    int oldlen, newlen;

    strcpy(oldpath, data);
    oldlen = strlen(oldpath);
    strcpy( newpath, data + oldlen + 1 );
    cache_symlink( oldpath, newpath );
}

/**
 */
int send_unlink( const char *path ) {
    char packet[1500];
    int length;
    int result;

    packet[0] = UNLINK_REQUEST;
    strcpy(packet+1, path);
    length = strlen(path) + 2;
    result = sendto( multicast_socket, packet, length, 0, (struct sockaddr *)&multicast_address, sizeof(multicast_address));
    if ( result == -1 ) {
        syslog(LOG_ERR, "failed to send unlink message");
    } else {
        /* syslog(LOG_NOTICE, "send unlink message"); */
    }
}

int recv_unlink( char *data ) {
    char path[512];
    strcpy( path, data );
    cache_unlink( path );
}

/**
 */
int send_write( const char *path, const char *buf, size_t size, off_t offset ) {
    char packet[1500];
    int length;
    int result;

    packet[0] = WRITE_REQUEST;
    *( (size_t *)(packet + 4) ) = htonl( size );
    *( (off_t  *)(packet + 8) ) = offset;
    strcpy(packet+16, path);
    length = strlen(path) + 17;
    memcpy( (packet+length), buf, size );
    length += size;
    result = sendto( multicast_socket, packet, length, 0, (struct sockaddr *)&multicast_address, sizeof(multicast_address));
    if ( result == -1 ) {
        syslog(LOG_ERR, "failed to send write message");
    } else {
        /* syslog(LOG_NOTICE, "send write message"); */
    }
}

int recv_write( char *data ) {
    size_t size;
    off_t offset;
    char path[512];
    char *buf;

    size   = ntohl( *( (size_t *)(data + 3) ) );
    offset = *( (off_t  *)(data + 7) );
    strcpy( path, data+15 );
    buf = data + strlen(path) + 16;
    cache_write( path, buf, size, offset );
}

/**
 */
int send_create( const char *path, mode_t mode ) {
    char packet[1500];
    mode_t *mode_p;
    int length;
    int result;

    packet[0] = CREATE_REQUEST;
    mode_p = (mode_t *)(packet + 4);
    *mode_p = htonl( mode );
    strcpy(packet+8, path);
    length = strlen(path) + 9;
    result = sendto( multicast_socket, packet, length, 0, (struct sockaddr *)&multicast_address, sizeof(multicast_address));
    if ( result == -1 ) {
        syslog(LOG_ERR, "failed to send create message");
    } else {
        /* syslog(LOG_NOTICE, "send create message"); */
    }
}

int recv_create( char *data ) {
    char path[512];
    mode_t mode;

    mode = ntohl( *( (uint32_t*)(data+3) ) );
    strcpy(path, data+7);
    cache_create( path, mode );
}


typedef int (*message_handler)(char *);
message_handler handlers[] = {
    0,
    recv_mkdir,
    recv_rmdir,
    recv_symlink,
    recv_create,
    recv_write,
    recv_unlink,
};

/**
 * Determine the message type and handoff the rest of the message
 * to the correct handler.  Log an error and drop the message if
 * the message type is unknown.  The message type is the first octet
 * of the message.
 \dot
 digraph {
     request [shape=record,label="type | body"];
 }
 \enddot
 */
void network_dispatch( void *data ) {
}

pthread_t network_thread;
pthread_t local_thread;

int join(int sock, int interface) {
    int result;
    struct ipv6_mreq m6;
    unsigned int flag;

    inet_pton(AF_INET6, "ff02::8998", &(m6.ipv6mr_multiaddr));
    /* if this were standard code we would use interface, since this is linux
     * we must use ifindex (stupid)
    m6.ipv6mr_interface = interface;
    */
    m6.ipv6mr_ifindex = interface;
    result = setsockopt(sock, IPPROTO_IPV6, IPV6_ADD_MEMBERSHIP, &m6, sizeof(m6));
    if ( result < 0 ) {
        syslog(LOG_ERR, "setsockopt failed");
        exit( 0 );
    }
    syslog(LOG_INFO, "joined hoard multicast group");
    flag = 0;
    result = setsockopt(sock, IPPROTO_IPV6, IPV6_MULTICAST_LOOP, &flag, sizeof(flag));
    if ( result < 0 ) {
        syslog(LOG_WARNING, "failed to turn off loopback of multicast packets");
    }
}

int initialize_network() {
    int result;
    int eth1;

    eth1 = if_nametoindex("eth1");

    multicast_socket = socket( AF_INET6, SOCK_DGRAM, 0 );
    if ( multicast_socket == - 1 ) {
        /* syslog( LOG_ERR, "failed to create socket" ); */
        exit( 0 );
    }
    multicast_address.sin6_family = AF_INET6;
    multicast_address.sin6_port = htons(8990);
    multicast_address.sin6_scope_id = eth1;
    inet_pton(AF_INET6, "ff02::8998", &(multicast_address.sin6_addr) );
    result = bind( multicast_socket, (struct sockaddr *)&multicast_address, sizeof(multicast_address) );
    if ( result == -1 ) {
        /* syslog( LOG_ERR, "bind failed\n" ); */
        exit( 0 );
    }
    join(multicast_socket, eth1);
    return multicast_socket;
}

/**
 * The main loop of the network thread waits for message packets.
 */

static unsigned char packet_buffer[4096];
static void *
watch_network( void *data ) {
    int result;
    struct sockaddr_in6 address;
    struct sockaddr_in6 sender;
    socklen_t sender_size;
    int bytes;
    int sock;

    sock = initialize_network();
    syslog( LOG_NOTICE, "waiting for a message\n" );
    for (;;) {
        int command;
        message_handler handler;

        /* wait for a packet */
        /* syslog( LOG_NOTICE, "waiting for a message\n" ); */
        bytes = recvfrom(sock, packet_buffer, sizeof packet_buffer, 0, (struct sockaddr *)&sender, &sender_size );
        if ( bytes < 0 ) continue;

        /* lookup command in table */
        command = packet_buffer[0];
        if ( command > VALID_MESSAGE_TYPE ) {
            syslog( LOG_NOTICE, "Invalid message type: %d\n", command );
            continue;
        }

        /* call command */
        handler = handlers[command];
        handler( packet_buffer+1 );
    }
}

/* @} */

/**
 * Main program.  Start threads then call the fuse startup, which starts its own threads.
 *
 * \todo Change to call the lower level fuse calls instead of the "lazy" (sic) functions.
 */
int main( int argc, char **argv ) {
    char *mountpoint = "/hoard";

    openlog("hoard", LOG_CONS, LOG_DAEMON);

    mkdir(cache, 0777);
    mkdir(data, 0777);
    mkdir(meta, 0777);
    mkdir(mountpoint, 0777);

    /* read the UUID from /etc/sysconfig/spine */
    read_uuid();

    /* start the unix socket thread */

    /* start the multicast v6 thread */
    if ( pthread_create(&network_thread, NULL, watch_network, NULL) ) {
        /* generate error */
        perror( "failed to create net thread" );
    }

    block: {
        int argc = 3;
        char *argv[] = { "fuse", mountpoint, "-f", (char *)0 };
        fuse_main( argc, argv, &ops );
    }
}

/*
 * vim:autoindent
 * vim:expandtab
 */
