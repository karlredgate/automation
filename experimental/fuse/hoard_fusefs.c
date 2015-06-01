
/*
 * cache /var/cache/hoard
 */

#define FUSE_USE_VERSION 25

#include <errno.h>
#include <sys/statfs.h>
#include <dirent.h>
#include <fuse.h>
#include <tcl.h>

Tcl_Interp *interp;

static int
statfs_op(const char *path, struct statvfs *st_buf) {
    int result = 0;

    result = statvfs(path, st_buf);
    if (result == -1)
        return -errno;
    return result;
}

static int
getattr_op(const char *path, struct stat *st_data) {
    int result = 0;

  Tcl_Eval(interp, "set f [open /h/kredgate/foolog a] ; puts $f getattr ; close $f");
printf( "PATH: %s\n", path);
    stat("/", st_data);

/*
    st_data->st_mode = 0777;
    st_data->st_uid = 0;
    st_data->st_gid = 0;
*/

    return result;
}

static int
getdir_op(const char *path, fuse_dirh_t h, fuse_dirfil_t fill) {
    int result = 0;
    struct dirent *entry;
    DIR *dir;

    dir = opendir(path);
    entry = readdir(dir);
    closedir(dir);

    /*
    typedef int (*fuse_dirfil_t) (fuse_dirh_t h, const char *name, int type, ino_t ino);
    */
    fill(h, "bar", 0, 0);
    return result;
}

static int
mknod_op(const char *path, mode_t mode, dev_t rdev) { 
  /*
  return create_new_file(path, mode, fuse_get_context()->uid, fuse_get_context()->gid, rdev);
  */
} 

static int
mkdir_op(const char *path, mode_t mode) { 
  /*
  return create_new_directory(path, mode, fuse_get_context()->uid, fuse_get_context()->gid);
  */
  Tcl_Obj *object = Tcl_NewStringObj(path, -1);
  Tcl_Eval(interp, "set f [open /h/kredgate/foolog w] ; puts $f {mkdir_op} ; close $f");
  return 0;
} 

static int
symlink_op(const char *from, const char *to) {
  /*
  return create_new_symlink(from, to, fuse_get_context()->uid, fuse_get_context()->gid);
  */
} 

static int
rename_op(const char *from, const char *to) {
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
/*
  metadata_t *metadata;
  version_t *version;
    
  metadata = rcs_translate_to_metadata(path, rcs_version_path);
  if (!metadata)
    return -ENOENT;
  version = rcs_find_version(metadata, LATEST, LATEST);
  if (!version)
    return -ENOENT;

  if (create_new_subversion(path, mode, version->v_uid, version->v_gid) != 0)
    return -errno;
*/
  return 0;
}

static int
chown_op(const char *path, uid_t uid, gid_t gid) {
/*
  metadata_t *metadata;
  version_t *version;

  metadata = rcs_translate_to_metadata(path, rcs_version_path);
  if (!metadata)
    return -ENOENT;
  version = rcs_find_version(metadata, LATEST, LATEST);
  if (!version)
    return -ENOENT;

  if (create_new_subversion(path, version->v_mode, uid, gid) != 0)
    return -errno;
*/
  return 0;
}

static int
truncate_op(const char *path, off_t size) {
/*
    int res;
    char *rpath;
    metadata_t *metadata;

    if (create_new_version(path) == -1)
      return -errno;

    rpath = rcs_translate_path(path, rcs_version_path);
    metadata = cache_get_metadata(path);
    metadata->md_timestamp = time(NULL);
    res = truncate(rpath, size);
    if(res == -1)
      return -errno;
*/
    return 0;
}

static int
utime_op(const char *path, struct utimbuf *buf) {
/*
  char *rpath;
  int res;

  rpath = rcs_translate_path(path, rcs_version_path);
  if (!rpath)
    return -ENOENT;

  res = utime(rpath, buf);
  if (res == -1)
    { 
      free(rpath);
      return -errno;
    }

  free(rpath);
*/
  return 0;
}

static int
open_op(const char *path, struct fuse_file_info *info) {
/*
  char *rpath;
  int res;

  if ((flags & O_WRONLY) || (flags & O_RDWR)) {
    if (create_new_version(path) == -1)
      return -errno;
  }

  rpath = rcs_translate_path(path, rcs_version_path);
  res = open(rpath, flags);
  free(rpath);
  if(res == -1)
    return -errno;
  close(res);
*/
  return 0;
}

static int
read_op( const char *path, char *buf, size_t size, off_t off, struct fuse_file_info *info ) {
/*
  char *rpath;
  int fd, res;

  rpath = rcs_translate_path(path, rcs_version_path);
  fd = open(rpath, O_RDONLY);
  if (fd == -1)
    { 
      free(rpath);
      return -errno;
    }
  res = pread(fd, buf, size, off);
  if (res == -1)
    res = -errno;
  close(fd);
  free(rpath);
  return res;
*/
  return 0;
}

static int
write_op( const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *info ) {
/*
  int fd;
  int res;
  char *rpath;

  rpath = rcs_translate_path(path, rcs_version_path);
  fd = open(rpath, O_WRONLY);
  if(fd == -1)
    {
      free(rpath);
      return -errno;
    }
  res = pwrite(fd, buf, size, offset);
  if(res == -1)
    res = -errno;
  close(fd);
  free(rpath);
  return res;
*/
  return 0;
}


static int
readlink_op(const char *path, char *buf, size_t size) {
    int result = 0;
    return result;
}

static int
fsync_op( const char *path, int isdatasync, struct fuse_file_info *info ) {
  /* No special treatment */
  (void) path;
  (void) isdatasync;
  return 0;
}

static int
release_op( const char *path, struct fuse_file_info *info ) {
  /* No special treatment */
  (void) path;
  return 0;
}

static int
unlink_op(const char *path) {
  return 0;     
}   

static int
rmdir_op(const char *path) {   
  return 0;
}

static int
access_op(const char *path, int arg) {   
  return 0;
}

static int
create_op(const char *path, mode_t mode, struct fuse_file_info *info) {   
  return 0;
}

static void *
init_op(void) {
    Tcl_Eval(interp, "set f [open /h/kredgate/foolog w] ; puts $f init ; close $f");
    return interp;
}

static void
destroy_op( void *data ) {
    Tcl_Interp *interp = (Tcl_Interp *)data;
    Tcl_Eval(interp, "set f [open /h/kredgate/foolog a] ; puts $f destroy ; close $f");
}

struct fuse_operations ops = {
    .getattr  = getattr_op,
    .readlink = readlink_op,
    .getdir   = getdir_op,
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

void MainLoop() {
    while (1) { sleep(3); }
}

static int
cache_cmd( ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj * CONST *objv ) {
    return TCL_OK;
}

static int
mount_cmd( ClientData data, Tcl_Interp *interp, int objc, Tcl_Obj * CONST *objv ) {
    char *mountpoint;
    if ( objc != 2 ) {
        Tcl_ResetResult( interp );
        Tcl_WrongNumArgs( interp, 1, objv, "directory" );
        return TCL_ERROR;
    }
    mountpoint = Tcl_GetStringFromObj( objv[1], NULL );
    /* check for presense */

    block: {
        int argc = 2;
        char *argv[] = { "fuse", mountpoint, (char *)0 };
        fuse_main( argc, argv, &ops );
    }
    return TCL_OK;
}

int AppInit( Tcl_Interp *_interp ) {
    interp = _interp;
    Tcl_CreateObjCommand( interp, "cache", cache_cmd, (ClientData)0, NULL);
    Tcl_CreateObjCommand( interp, "mount", mount_cmd, (ClientData)0, NULL);
    /* init fuse stuff */
    return TCL_OK;
}

int main( int argc, char **argv ) {
    int fargc = 2;
    char *fargv[] = { "KFS", "/dev/null" };
    /* chdir("/var/spine"); */
    Tcl_SetMainLoop( MainLoop );
    Tcl_Main(argc, argv, AppInit);
}

/*
 * vim:autoindent
 * vim:expandtab
 */
