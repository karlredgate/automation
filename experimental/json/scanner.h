
#define EOI     256
#define INTEGER 257
#define STRING  258
#define ERROR   259

extern int current_token;
extern char current_identifier[1024];
extern char current_string[4096];
extern long current_integer;

char * report_token( int token );
void init_scanner();
void get_next_token();
int look_ahead( int _token );
int required( int found );
int token( int _token );

/* vim: set autoindent expandtab sw=4 : */
