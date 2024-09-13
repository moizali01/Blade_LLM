typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __off64_t;
typedef int __pid_t;
typedef long __time_t;
typedef int __clockid_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef long __ssize_t;
typedef long __syscall_slong_t;
typedef __mode_t mode_t;
typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __ssize_t ssize_t;
typedef __time_t time_t;
typedef __clockid_t clockid_t;
typedef unsigned long size_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
struct stat {
  __dev_t st_dev;
  __ino_t st_ino;
  __nlink_t st_nlink;
  __mode_t st_mode;
  __uid_t st_uid;
  __gid_t st_gid;
  int __pad0;
  __dev_t st_rdev;
  __off_t st_size;
  __blksize_t st_blksize;
  __blkcnt_t st_blocks;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  __syscall_slong_t __glibc_reserved[3];
};
struct mtop {
  short mt_op;
  int mt_count;
};
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
struct _IO_FILE {
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[(15UL * sizeof(int) - 4UL * sizeof(void *)) - sizeof(size_t)];
};
typedef unsigned long uintmax_t;
struct posix_header {
  char name[100];
  char mode[8];
  char uid[8];
  char gid[8];
  char size[12];
  char mtime[12];
  char chksum[8];
  char typeflag;
  char linkname[100];
  char magic[6];
  char version[2];
  char uname[32];
  char gname[32];
  char devmajor[8];
  char devminor[8];
  char prefix[155];
};
struct sparse {
  char offset[12];
  char numbytes[12];
};
struct sparse_header {
  struct sparse sp[21];
  char isextended;
};
struct oldgnu_header {
  char unused_pad1[345];
  char atime[12];
  char ctime[12];
  char offset[12];
  char longnames[4];
  char unused_pad2;
  struct sparse sp[4];
  char isextended;
  char realsize[12];
};
struct star_header {
  char name[100];
  char mode[8];
  char uid[8];
  char gid[8];
  char size[12];
  char mtime[12];
  char chksum[8];
  char typeflag;
  char linkname[100];
  char magic[6];
  char version[2];
  char uname[32];
  char gname[32];
  char devmajor[8];
  char devminor[8];
  char prefix[131];
  char atime[12];
  char ctime[12];
};
struct star_in_header {
  char fill[345];
  char prefix[1];
  char fill2;
  char fill3[8];
  char isextended;
  struct sparse sp[4];
  char realsize[12];
  char offset[12];
  char atime[12];
  char ctime[12];
  char mfill[8];
  char xmagic[4];
};
struct star_ext_header {
  struct sparse sp[21];
  char isextended;
};
struct sp_array {
  off_t offset;
  size_t numbytes;
};
struct tar_stat_info {
  char *orig_file_name;
  char *file_name;
  int had_trailing_slash;
  char *link_name;
  unsigned int devminor;
  unsigned int devmajor;
  char *uname;
  char *gname;
  struct stat stat;
  unsigned long atime_nsec;
  unsigned long mtime_nsec;
  unsigned long ctime_nsec;
  off_t archive_file_size;
  _Bool is_sparse;
  size_t sparse_map_avail;
  size_t sparse_map_size;
  struct sp_array *sparse_map;
};
union block {
  char buffer[512];
  struct posix_header header;
  struct star_header star_header;
  struct oldgnu_header oldgnu_header;
  struct sparse_header sparse_header;
  struct star_in_header star_in_header;
  struct star_ext_header star_ext_header;
};
typedef double tarlong;
enum subcommand {
  UNKNOWN_SUBCOMMAND = 0,
  APPEND_SUBCOMMAND = 1,
  CAT_SUBCOMMAND = 2,
  CREATE_SUBCOMMAND = 3,
  DELETE_SUBCOMMAND = 4,
  DIFF_SUBCOMMAND = 5,
  EXTRACT_SUBCOMMAND = 6,
  LIST_SUBCOMMAND = 7,
  UPDATE_SUBCOMMAND = 8
};
enum access_mode { ACCESS_READ = 0, ACCESS_WRITE = 1, ACCESS_UPDATE = 2 };
typedef __dev_t dev_t;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
struct utimbuf {
  __time_t actime;
  __time_t modtime;
};
enum archive_format {
  DEFAULT_FORMAT = 0,
  V7_FORMAT = 1,
  OLDGNU_FORMAT = 2,
  USTAR_FORMAT = 3,
  POSIX_FORMAT = 4,
  STAR_FORMAT = 5,
  GNU_FORMAT = 6
};
enum read_header {
  HEADER_STILL_UNREAD = 0,
  HEADER_SUCCESS = 1,
  HEADER_SUCCESS_EXTENDED = 2,
  HEADER_ZERO_BLOCK = 3,
  HEADER_END_OF_FILE = 4,
  HEADER_FAILURE = 5
};
typedef __ino_t ino_t;
typedef __gid_t gid_t;
typedef __uid_t uid_t;
struct obstack;
struct obstack;
struct mode_change {
  char op;
  char flags;
  mode_t affected;
  mode_t value;
  struct mode_change *next;
};
struct name {
  struct name *next;
  size_t length;
  uintmax_t found_count;
  int isdir;
  char firstch;
  char regexp;
  int change_dir;
  char const *dir_contents;
  char fake;
  char name[1];
};
enum dump_status {
  dump_status_ok = 0,
  dump_status_short = 1,
  dump_status_fail = 2,
  dump_status_not_implemented = 3
};
struct xheader {
  struct obstack *stk;
  size_t size;
  char *buffer;
};
struct hash_tuning {
  float shrink_threshold;
  float shrink_factor;
  float growth_threshold;
  float growth_factor;
  _Bool is_n_buckets;
};
typedef struct hash_tuning Hash_tuning;
struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
struct link {
  dev_t dev;
  ino_t ino;
  size_t nlink;
  char name[1];
};
enum old_files {
  DEFAULT_OLD_FILES = 0,
  NO_OVERWRITE_DIR_OLD_FILES = 1,
  OVERWRITE_OLD_FILES = 2,
  UNLINK_FIRST_OLD_FILES = 3,
  KEEP_OLD_FILES = 4,
  KEEP_NEWER_FILES = 5
};
enum remove_option {
  ORDINARY_REMOVE_OPTION = 0,
  RECURSIVE_REMOVE_OPTION = 1,
  WANT_DIRECTORY_REMOVE_OPTION = 2
};
enum permstatus {
  UNKNOWN_PERMSTATUS = 0,
  ARCHIVED_PERMSTATUS = 1,
  INTERDIR_PERMSTATUS = 2
};
struct delayed_set_stat {
  struct delayed_set_stat *next;
  struct stat stat_info;
  size_t file_name_len;
  mode_t invert_permissions;
  enum permstatus permstatus;
  _Bool after_symlinks;
  char file_name[1];
};
struct string_list;
struct string_list;
struct delayed_symlink {
  struct delayed_symlink *next;
  dev_t dev;
  ino_t ino;
  time_t mtime;
  uid_t uid;
  gid_t gid;
  struct string_list *sources;
  char target[1];
};
struct string_list {
  struct string_list *next;
  char string[1];
};
enum strtol_error {
  LONGINT_OK = 0,
  LONGINT_OVERFLOW = 1,
  LONGINT_INVALID_SUFFIX_CHAR = 2,
  LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
  LONGINT_INVALID = 4
};
typedef enum strtol_error strtol_error;
struct _obstack_chunk {
  char *limit;
  struct _obstack_chunk *prev;
  char contents[4];
};
struct obstack {
  long chunk_size;
  struct _obstack_chunk *chunk;
  char *object_base;
  char *next_free;
  char *chunk_limit;
  long temp;
  int alignment_mask;
  struct _obstack_chunk *(*chunkfun)(void *, long);
  void (*freefun)(void *, struct _obstack_chunk *);
  void *extra_arg;
  unsigned int use_extra_arg : 1;
  unsigned int maybe_empty_object : 1;
  unsigned int alloc_failed : 1;
};
struct keyword_list {
  struct keyword_list *next;
  char *pattern;
  char *value;
};
struct xhdr_tab {
  char const *keyword;
  void (*coder)(struct tar_stat_info const *, char const *, struct xheader *,
                void *data);
  void (*decoder)(struct tar_stat_info *, char const *);
  _Bool protect;
};
enum children { NO_CHILDREN = 0, CHANGED_CHILDREN = 1, ALL_CHILDREN = 2 };
struct directory {
  dev_t device_number;
  ino_t inode_number;
  enum children children;
  _Bool nfs;
  _Bool found;
  char name[1];
};
struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long tm_gmtoff;
  char const *tm_zone;
};
enum quoting_style {
  literal_quoting_style = 0,
  shell_quoting_style = 1,
  shell_always_quoting_style = 2,
  c_quoting_style = 3,
  escape_quoting_style = 4,
  locale_quoting_style = 5,
  clocale_quoting_style = 6
};
struct quoting_options;
struct quoting_options;
enum backup_type { none = 0, simple = 1, numbered_existing = 2, numbered = 3 };
struct saved_cwd {
  int desc;
  char *name;
};
struct wd {
  char const *name;
  int saved;
  struct saved_cwd saved_cwd;
};
struct passwd {
  char *pw_name;
  char *pw_passwd;
  __uid_t pw_uid;
  __gid_t pw_gid;
  char *pw_gecos;
  char *pw_dir;
  char *pw_shell;
};
struct group {
  char *gr_name;
  char *gr_passwd;
  __gid_t gr_gid;
  char **gr_mem;
};
struct exclude;
struct exclude;
typedef int __daddr_t;
typedef void (*__sighandler_t)(int);
struct mtget {
  long mt_type;
  long mt_resid;
  long mt_dsreg;
  long mt_gstat;
  long mt_erreg;
  __daddr_t mt_fileno;
  __daddr_t mt_blkno;
};
struct tar_sparse_file;
struct tar_sparse_file;
enum sparse_scan_state { scan_begin = 0, scan_block = 1, scan_end = 2 };
struct tar_sparse_optab {
  _Bool (*init)(struct tar_sparse_file *);
  _Bool (*done)(struct tar_sparse_file *);
  _Bool (*sparse_member_p)(struct tar_sparse_file *);
  _Bool (*dump_header)(struct tar_sparse_file *);
  _Bool (*fixup_header)(struct tar_sparse_file *);
  _Bool (*decode_header)(struct tar_sparse_file *);
  _Bool (*scan_block)(struct tar_sparse_file *, enum sparse_scan_state, void *);
  _Bool (*dump_region)(struct tar_sparse_file *, size_t);
  _Bool (*extract_region)(struct tar_sparse_file *, size_t);
};
struct tar_sparse_file {
  int fd;
  size_t dumped_size;
  struct tar_stat_info *stat_info;
  struct tar_sparse_optab *optab;
  void *closure;
};
enum oldgnu_add_status { add_ok = 0, add_finish = 1, add_fail = 2 };
union __anonunion_56 {
  int __in;
  int __i;
};
union __anonunion_57 {
  int __in;
  int __i;
};
union __anonunion_58 {
  int __in;
  int __i;
};
union __anonunion_59 {
  int __in;
  int __i;
};
union __anonunion_60 {
  int __in;
  int __i;
};
union __anonunion_61 {
  int __in;
  int __i;
};
union __anonunion_62 {
  int __in;
  int __i;
};
union __anonunion_63 {
  int __in;
  int __i;
};
union __anonunion_64 {
  int __in;
  int __i;
};
union __anonunion_65 {
  int __in;
  int __i;
};
union __anonunion_66 {
  int __in;
  int __i;
};
union __anonunion_67 {
  int __in;
  int __i;
};
struct option {
  char const *name;
  int has_arg;
  int *flag;
  int val;
};
struct fmttab {
  char const *name;
  enum archive_format fmt;
};
typedef void *iconv_t;
struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
};
struct __dirstream;
struct __dirstream;
typedef struct __dirstream DIR;
struct patopts {
  char const *pattern;
  int options;
};
struct exclude {
  struct patopts *exclude;
  size_t exclude_alloc;
  size_t exclude_count;
};
struct __anonstruct_textint_27 {
  long value;
  size_t digits;
};
typedef struct __anonstruct_textint_27 textint;
struct __anonstruct_table_28 {
  char const *name;
  int type;
  int value;
};
typedef struct __anonstruct_table_28 table;
struct __anonstruct_parser_control_31 {
  char const *input;
  long day_ordinal;
  int day_number;
  int local_isdst;
  long time_zone;
  int meridian;
  textint year;
  long month;
  long day;
  long hour;
  long minutes;
  struct timespec seconds;
  long rel_year;
  long rel_month;
  long rel_day;
  long rel_hour;
  long rel_minutes;
  long rel_seconds;
  long rel_ns;
  _Bool timespec_seen;
  size_t dates_seen;
  size_t days_seen;
  size_t local_zones_seen;
  size_t rels_seen;
  size_t times_seen;
  size_t zones_seen;
  table local_time_zone_table[3];
};
typedef struct __anonstruct_parser_control_31 parser_control;
union __anonunion_YYSTYPE_32 {
  long intval;
  textint textintval;
  struct timespec timespec;
};
typedef union __anonunion_YYSTYPE_32 YYSTYPE;
typedef long __suseconds_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};

typedef struct timezone *__restrict __timezone_ptr_t;
struct hash_entry {
  void *data;
  struct hash_entry *next;
};
typedef long ptrdiff_t;
struct hash_table {
  struct hash_entry *bucket;
  struct hash_entry const *bucket_limit;
  size_t n_buckets;
  size_t n_buckets_used;
  size_t n_entries;
  Hash_tuning const *tuning;
  size_t (*hasher)(void const *, size_t);
  _Bool (*comparator)(void const *, void const *);
  void (*data_freer)(void *);
  struct hash_entry *free_entry_list;
};
struct lconv {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};
typedef int wchar_t;
union __anonunion___value_23 {
  unsigned int __wch;
  char __wchb[4];
};
struct __anonstruct___mbstate_t_22 {
  int __count;
  union __anonunion___value_23 __value;
};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
typedef unsigned int wint_t;
typedef __mbstate_t mbstate_t;
struct quoting_options {
  enum quoting_style style;
  int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
};
struct slotvec {
  size_t size;
  char *val;
};
/* #pragma merger("0","000.buffer.o.i","") */
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) memcpy)(
    void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1), __leaf__)) memset)(void *__s, int __c, size_t __n);
extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1), __leaf__)) memchr)(void const *__s, int __c, size_t __n)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest,
                                          char const *__restrict __src);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcat)(char *__restrict __dest,
                                          char const *__restrict __src);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strchr)(char const *__s, int __c)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag, ...);
extern int(__attribute__((__nonnull__(1))) creat)(char const *__file,
                                                  mode_t __mode);
extern __attribute__((__nothrow__))
__off_t(__attribute__((__leaf__)) lseek)(int __fd, __off_t __offset,
                                         int __whence);
extern int close(int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ioctl)(
    int __fd, unsigned long __request, ...);
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(
    void *__ptr);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) valloc)(
    size_t __size) __attribute__((__malloc__));
extern
    __attribute__((__nothrow__,
                   __noreturn__)) void(__attribute__((__leaf__)) abort)(void);
extern int system(char const *__command);
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int fclose(FILE *__stream);
extern int fflush_unlocked(FILE *__stream);
extern FILE *fopen(char const *__restrict __filename,
                   char const *__restrict __modes);
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format,
                   ...);
extern __attribute__((__nothrow__)) int
sprintf(char *__restrict __s, char const *__restrict __format, ...);
extern int fscanf(FILE *__restrict __stream, char const *__restrict __format,
                  ...);
extern int fputc_unlocked(int __c, FILE *__stream);
extern char *fgets_unlocked(char *__restrict __s, int __n,
                            FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(
    __attribute__((__leaf__)) ferror_unlocked)(FILE *__stream);
extern __attribute__((__nothrow__))
time_t(__attribute__((__leaf__)) time)(time_t *__timer);
extern
    __attribute__((__nothrow__)) int(__attribute__((__leaf__)) clock_gettime)(
        clockid_t __clock_id, struct timespec *__tp);
int strip_trailing_slashes(char *path);
extern void error(int __status, int __errnum, char const *__format, ...);
void *xmalloc(size_t n);
char *xstrdup(char const *string);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) gettext)(
    char const *__msgid) __attribute__((__format_arg__(1)));
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) ngettext)(
    char const *__msgid1, char const *__msgid2, unsigned long __n)
    __attribute__((__format_arg__(1), __format_arg__(2)));
extern int fnmatch(char const *__pattern, char const *__name, int __flags);
char *human_readable(uintmax_t n, char *buf, int opts,
                     uintmax_t from_block_size, uintmax_t to_block_size);
char *quotearg_colon(char const *arg);
char const *quote_n(int n, char const *name);
char const *quote(char const *name);
size_t safe_read(int fd, void *buf, size_t count);
enum subcommand subcommand_option;
int blocking_factor;
size_t record_size;
_Bool backup_option;
_Bool checkpoint_option;
char const *use_compress_program_option;
_Bool force_local_option;
char const *info_script_option;
_Bool multi_volume_option;
_Bool read_full_records_option;
char const *rsh_command_option;
tarlong tape_length_option;
_Bool to_stdout_option;
_Bool totals_option;
int verbose_option;
_Bool verify_option;
char const *volno_file_option;
char const *volume_label_option;
int archive;
_Bool dev_null_output;
struct timespec start_timespec;
struct tar_stat_info current_stat_info;
char const **archive_name_array;
int archive_names;
char const **archive_name_cursor;
char const *index_file_name;
enum access_mode access_mode;
FILE *stdlis;
char *save_name;
off_t save_sizeleft;
off_t save_totsize;
_Bool write_archive_to_stdout;
size_t available_space_after(union block *pointer);
off_t current_block_ordinal(void);
void close_archive(void);
void closeout_volume_number(void);
union block *find_next_block(void);
void flush_read(void);
void flush_write(void);
void flush_archive(void);
void init_volume_number(void);
void open_archive(enum access_mode wanted_access);
void print_total_written(void);
void reset_eof(void);
void set_next_block_after(union block *block);
void clear_read_error_count(void);
void xclose(int fd);
__attribute__((__noreturn__)) void archive_write_error(ssize_t status);
void archive_read_error(void);
void finish_header(struct tar_stat_info *st, union block *header,
                   off_t block_ordinal);
void off_to_chars(off_t v, char *p, size_t s);
void time_to_chars(time_t v, char *p, size_t s);
_Bool now_verifying;
void verify_volume(void);
__attribute__((__noreturn__)) void fatal_exit(void);
char *stringify_uintmax_t_backwards(uintmax_t o___0, char *buf);
off_t off_from_header(char const *p, size_t s);
uintmax_t uintmax_from_header(char const *p, size_t s);
void assign_string(char **string, char const *value);
_Bool maybe_backup_file(char const *path, int this_is_the_archive);
void undo_last_backup(void);
void close_error(char const *name);
void close_warn(char const *name);
void open_error(char const *name);
__attribute__((__noreturn__)) void open_fatal(char const *name);
void open_warn(char const *name);
void read_error(char const *name);
void write_error(char const *name);
__attribute__((__noreturn__)) void
write_fatal_details(char const *name, ssize_t status, size_t size);
char *safer_name_suffix(char const *file_name, _Bool link_target);
void tar_stat_destroy(struct tar_stat_info *st);
char *output_start;
void sys_detect_dev_null_output(void);
void sys_save_archive_dev_ino(void);
void sys_drain_input_pipe(void);
void sys_wait_for_child(pid_t child_pid___0);
void sys_spawn_shell(void);
pid_t sys_child_open_for_compress(void);
pid_t sys_child_open_for_uncompress(void);
size_t sys_write_archive_buffer(void);
_Bool sys_get_archive_stat(void);
char *rmt_path__;
int rmt_open__(char const *path, int open_mode, int bias,
               char const *remote_shell);
int rmt_close__(int handle);
size_t rmt_read__(int handle, char *buffer___2, size_t length);
off_t rmt_lseek__(int handle, off_t offset, int whence);
int rmt_ioctl__(int handle, int operation, char *argument);
static tarlong prev_written;
static tarlong bytes_written;
union block *record_start;
union block *record_end;
union block *current_block;
off_t records_read;
off_t records_written;
static off_t record_start_block;
static void backspace_output(void);
static _Bool new_volume(enum access_mode mode);
static pid_t child_pid;
static int read_error_count;
static int hit_eof;
static int checkpoint;
_Bool time_to_start_writing;
static int volno = 1;
static int global_volno = 1;
static char *real_s_name;
static off_t real_s_totsize;
static off_t real_s_sizeleft;
void clear_read_error_count(void) {

  {
    read_error_count = 0;
    return;
  }
}

off_t current_block_ordinal(void) {

  { return (record_start_block + (current_block - record_start)); }
}
void reset_eof(void) {

  {
    if (hit_eof) {
      hit_eof = 0;
      current_block = record_start;
      record_end = record_start + blocking_factor;
      access_mode = (enum access_mode)1;
    }
    return;
  }
}
union block *find_next_block(void) {

  {
    if ((unsigned long)current_block == (unsigned long)record_end) {
      if (hit_eof) {
        return ((union block *)0);
      }
      { flush_archive(); }
      if ((unsigned long)current_block == (unsigned long)record_end) {
        hit_eof = 1;
        return ((union block *)0);
      }
    }
    return (current_block);
  }
}
void set_next_block_after(union block *block) {

  {
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!((unsigned long)block >= (unsigned long)current_block)) {
          goto while_break;
        }
        current_block++;
      }
    while_break: /* CIL Label */
        ;
    }
    if ((unsigned long)current_block > (unsigned long)record_end) {
      {
        abort();
      }
    }
    return;
  }
}
size_t available_space_after(union block *pointer) {

  { return ((size_t)(record_end->buffer - pointer->buffer)); }
}
void xclose(int fd) {
  char *tmp;
  int tmp___0;
  char *__cil_tmp4;

  {
    { tmp___0 = close(fd); }

    return;
  }
}
static _Bool check_label_pattern(union block *label) {
  char *string;
  _Bool result;
  void *tmp;
  int tmp___0;
  size_t tmp___1;
  void *tmp___2;
  int tmp___3;
  char *__cil_tmp9;
  char *__cil_tmp10;

  {
    {
      tmp = memchr((void const *)(label->header.name), '\000',
                   sizeof(label->header.name));
    }
    if (!tmp) {
      return ((_Bool)0);
    }
    {
      tmp___0 =
          fnmatch(volume_label_option, (char const *)(label->header.name), 0);
    }
    if (tmp___0 == 0) {
      return ((_Bool)1);
    }

    {
      tmp___1 = strlen(volume_label_option);
      tmp___2 = xmalloc((tmp___1 + sizeof(" Volume [1-9]*")) + 1UL);
      string = (char *)tmp___2;
      strcpy((char * /* __restrict  */)string,
             (char const * /* __restrict  */)volume_label_option);
      strcat((char * /* __restrict  */)string,
             (char const * /* __restrict  */) " Volume [1-9]*");
      tmp___3 =
          fnmatch((char const *)string, (char const *)(label->header.name), 0);
      result = (_Bool)(tmp___3 == 0);
      free((void *)string);
    }
    return (result);
  }
}
void open_archive(enum access_mode wanted_access) {
  int backed_up_flag;
  char *tmp;
  char *tmp___0;
  void *tmp___1;
  void *tmp___2;
  char *tmp___3;
  int tmp___4;
  char *tmp___5;
  int tmp___7;
  int tmp___8;
  void *tmp___9;
  int tmp___11;
  int tmp___12;
  void *tmp___13;
  int tmp___15;
  int tmp___16;
  void *tmp___17;
  int tmp___19;
  int tmp___20;
  void *tmp___21;
  int tmp___22;
  int saved_errno;
  int *tmp___23;
  int *tmp___24;
  _Bool tmp___25;
  union block *label;
  union block *tmp___26;
  char const *tmp___27;
  char *tmp___28;
  char const *tmp___29;
  char const *tmp___30;
  char *tmp___31;
  _Bool tmp___32;
  unsigned int tmp___33;
  char *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;
  char *__cil_tmp39;
  char *__cil_tmp40;
  char *__cil_tmp41;
  char *__cil_tmp42;

  {
    backed_up_flag = 0;
    if (index_file_name) {
      {
        stdlis = fopen((char const * /* __restrict  */)index_file_name,
                       (char const * /* __restrict  */) "w");
      }

    } else {
      if (to_stdout_option) {
        stdlis = stderr;
      } else {
        stdlis = stdout;
      }
    }
    if (record_size == 0UL) {
      {
        tmp = gettext("Invalid value for record_size");
        error(0, 0, (char const *)tmp);
        fatal_exit();
      }
    }

    {
      tar_stat_destroy(&current_stat_info);
      save_name = (char *)0;
      real_s_name = (char *)0;
    }
    if (multi_volume_option) {
      {
        tmp___1 = valloc(record_size + 1024UL);
        record_start = (union block *)tmp___1;
      }

    } else {
      {
        tmp___2 = valloc(record_size);
        record_start = (union block *)tmp___2;
      }
    }
    if (!record_start) {
      {
        tmp___3 = gettext("Cannot allocate memory for blocking factor %d");
        error(0, 0, (char const *)tmp___3, blocking_factor);
        fatal_exit();
      }
    }
    current_block = record_start;
    record_end = record_start + blocking_factor;
    if ((unsigned int)wanted_access == 2U) {
      tmp___33 = 0U;
    } else {
      tmp___33 = (unsigned int)wanted_access;
    }
    access_mode = (enum access_mode)tmp___33;
    if (use_compress_program_option) {
      {
        if ((unsigned int)wanted_access == 0U) {
          goto case_0;
        }
        if ((unsigned int)wanted_access == 1U) {
          goto case_1;
        }
        if ((unsigned int)wanted_access == 2U) {
          goto case_2;
        }
        goto switch_break;
      case_0: { /* CIL Label */
        child_pid = sys_child_open_for_uncompress();
        read_full_records_option = (_Bool)0;
      }
        goto switch_break;
      case_1: { /* CIL Label */
        child_pid = sys_child_open_for_compress();
      }
        goto switch_break;
      case_2: { /* CIL Label */
        abort();
      }
        goto switch_break;
      switch_break: /* CIL Label */
          ;
      }

    } else {
      { tmp___22 = strcmp(*(archive_name_array + 0), "-"); }
      if (tmp___22 == 0) {
        read_full_records_option = (_Bool)1;

        {
          if ((unsigned int)wanted_access == 0U) {
            goto case_0___0;
          }
          if ((unsigned int)wanted_access == 1U) {
            goto case_1___0;
          }
          if ((unsigned int)wanted_access == 2U) {
            goto case_2___0;
          }
          goto switch_break___0;
        case_0___0: /* CIL Label */
          archive = 0;
          goto switch_break___0;
        case_1___0: /* CIL Label */
          archive = 1;
          stdlis = stderr;
          goto switch_break___0;
        case_2___0: /* CIL Label */
          archive = 0;
          stdlis = stderr;
          write_archive_to_stdout = (_Bool)1;
          goto switch_break___0;
        switch_break___0: /* CIL Label */
            ;
        }
      } else {
        if (verify_option) {
          if (!force_local_option) {
            {
              rmt_path__ = strchr(*(archive_name_array + 0), ':');
            }
            if (rmt_path__) {
              if ((unsigned long)rmt_path__ >
                  (unsigned long)*(archive_name_array + 0)) {
                {
                  tmp___9 = memchr(
                      (void const *)*(archive_name_array + 0), '/',
                      (size_t)(rmt_path__ - (char *)*(archive_name_array + 0)));
                }

              } else {
                {
                  tmp___8 = open(*(archive_name_array + 0), 66,
                                 ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                     ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                  archive = tmp___8;
                }
              }
            } else {
              {
                tmp___8 = open(*(archive_name_array + 0), 66,
                               ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                   ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                archive = tmp___8;
              }
            }
          } else {
            {
              tmp___8 = open(*(archive_name_array + 0), 66,
                             ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                 ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
              archive = tmp___8;
            }
          }
        } else {
          {
            if ((unsigned int)wanted_access == 0U) {
              goto case_0___1;
            }
            if ((unsigned int)wanted_access == 1U) {
              goto case_1___1;
            }
            if ((unsigned int)wanted_access == 2U) {
              goto case_2___1;
            }
            goto switch_break___1;
          case_0___1: /* CIL Label */
            if (!force_local_option) {
              {
                rmt_path__ = strchr(*(archive_name_array + 0), ':');
              }
              if (rmt_path__) {
                if ((unsigned long)rmt_path__ >
                    (unsigned long)*(archive_name_array + 0)) {
                  {
                    tmp___13 =
                        memchr((void const *)*(archive_name_array + 0), '/',
                               (size_t)(rmt_path__ -
                                        (char *)*(archive_name_array + 0)));
                  }
                  if (tmp___13) {
                    {
                      tmp___12 =
                          open(*(archive_name_array + 0), 0,
                               ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                   ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                      archive = tmp___12;
                    }
                  } else {
                    {
                      tmp___11 = rmt_open__(*(archive_name_array + 0), 0,
                                            1 << 30, rsh_command_option);
                      archive = tmp___11;
                    }
                  }
                } else {
                  {
                    tmp___12 =
                        open(*(archive_name_array + 0), 0,
                             ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                 ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                    archive = tmp___12;
                  }
                }
              } else {
                {
                  tmp___12 = open(*(archive_name_array + 0), 0,
                                  ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                      ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                  archive = tmp___12;
                }
              }
            } else {
              {
                tmp___12 = open(*(archive_name_array + 0), 0,
                                ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                    ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                archive = tmp___12;
              }
            }
            goto switch_break___1;
          case_1___1: /* CIL Label */

            goto switch_break___1;
          case_2___1: /* CIL Label */

            goto switch_break___1;
          switch_break___1: /* CIL Label */
              ;
          }
        }
      }
    }

    {
      sys_detect_dev_null_output();
      sys_save_archive_dev_ino();
    }
    {
      if ((unsigned int)wanted_access == 2U) {
        goto case_2___2;
      }
      if ((unsigned int)wanted_access == 0U) {
        goto case_0___2;
      }

      goto switch_break___2;
    case_2___2: /* CIL Label */
      records_written = (off_t)0;
    case_0___2: { /* CIL Label */
      records_read = (off_t)0;
      record_end = record_start;
      find_next_block();
    }

      goto switch_break___2;
    case_1___2: /* CIL Label */
      records_written = (off_t)0;
      if (volume_label_option) {
        {
          memset((void *)record_start, 0, (size_t)512);
        }
        if (multi_volume_option) {
          {
            sprintf((char * /* __restrict  */)(record_start->header.name),
                    (char const * /* __restrict  */) "%s Volume 1",
                    volume_label_option);
          }
        } else {
          {
            strcpy((char * /* __restrict  */)(record_start->header.name),
                   (char const * /* __restrict  */)volume_label_option);
          }
        }
        {
          assign_string(&current_stat_info.file_name,
                        (char const *)(record_start->header.name));
          current_stat_info.had_trailing_slash =
              strip_trailing_slashes(current_stat_info.file_name);
          record_start->header.typeflag = (char)'V';
          time_to_chars(start_timespec.tv_sec, record_start->header.mtime,
                        sizeof(record_start->header.mtime));
          finish_header(&current_stat_info, record_start, (off_t)-1);
        }
      }
      goto switch_break___2;
    switch_break___2: /* CIL Label */
        ;
    }
    return;
  }
}

__attribute__((__noreturn__)) void archive_write_error(ssize_t status);
void archive_write_error(ssize_t status) {
  int e;
  int *tmp;
  int *tmp___0;

  {

    { write_fatal_details(*archive_name_cursor, status, record_size); }
  }
}
void archive_read_error(void) {
  char *tmp;
  char *tmp___0;
  int tmp___1;
  char *__cil_tmp4;
  char *__cil_tmp5;

  {
    { read_error(*archive_name_cursor); }
    if (record_start_block == 0L) {
      {
        tmp = gettext("At beginning of tape, quitting now");
        error(0, 0, (char const *)tmp);
        fatal_exit();
      }
    }
    tmp___1 = read_error_count;
    read_error_count++;
    if (tmp___1 > 10) {
      {
        tmp___0 = gettext("Too many errors, quitting");
        error(0, 0, (char const *)tmp___0);
        fatal_exit();
      }
    }
    return;
  }
}
static void short_read(size_t status) {
  size_t left;
  char *more;
  size_t tmp;
  size_t tmp___0;
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char *tmp___1;
  char *tmp___2;
  unsigned long rest;
  char *tmp___3;
  unsigned long rsize;
  char *tmp___4;
  void *__cil_tmp13;
  char *__cil_tmp14;

  {
    more = record_start->buffer + status;
    left = record_size - status;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(left % 512UL != 0UL)) {
        }
        if (status) {
          {
            while (1) {
            while_continue___0: /* CIL Label */
                ;
              if (archive >= 1 << 30) {
                {
                  tmp = rmt_read__(archive - (1 << 30), more, left);
                  status = tmp;
                }
              } else {
                {
                  tmp___0 = safe_read(archive, (void *)more, left);
                  status = tmp___0;
                }
              }
              if (!(status == 0xffffffffffffffffUL)) {
                goto while_break___0;
              }
              { archive_read_error(); }
            }
          while_break___0: /* CIL Label */
              ;
          }
        }
        if (status == 0UL) {
          {
            tmp___1 = stringify_uintmax_t_backwards(
                record_size - left,
                buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                       1UL));
            tmp___2 = gettext("Read %s bytes from %s");
            error(0, 0, (char const *)tmp___2, tmp___1, *archive_name_cursor);
          }
          goto while_break;
        }
        if (!read_full_records_option) {
          {
            rest = record_size - left;
            tmp___3 = ngettext("Unaligned block (%lu byte) in archive",
                               "Unaligned block (%lu bytes) in archive", rest);
            error(0, 0, (char const *)tmp___3, rest);
            fatal_exit();
          }
        }
        left -= status;
        more += status;
      }
    while_break: /* CIL Label */
        ;
    }

    record_end = record_start + (record_size - left) / 512UL;
    records_read++;
    return;
  }
}
void flush_read(void) {
  size_t status;
  char *tmp;
  char *tmp___0;
  size_t tmp___1;
  size_t tmp___2;
  union block *cursor;
  _Bool tmp___3;
  _Bool tmp___4;
  size_t tmp___5;
  size_t tmp___6;
  char const *tmp___7;
  char const *tmp___8;
  char *tmp___9;
  _Bool tmp___10;
  char const *tmp___11;
  char *tmp___12;
  char *tmp___13;
  uintmax_t s1;
  uintmax_t s2;
  char const *tmp___14;
  char *tmp___15;
  int tmp___16;
  char totsizebuf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char s1buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char s2buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char *tmp___17;
  char *tmp___18;
  char *tmp___19;
  char const *tmp___20;
  char *tmp___21;
  char *tmp___22;
  off_t tmp___23;
  int *tmp___24;
  void *__cil_tmp34;
  void *__cil_tmp35;
  void *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;
  char *__cil_tmp39;
  char *__cil_tmp40;
  char *__cil_tmp41;
  char *__cil_tmp42;
  char *__cil_tmp43;

  {

    read_error_count = 0;

  error_loop:
    if (archive >= 1 << 30) {
      {
        tmp___1 =
            rmt_read__(archive - (1 << 30), record_start->buffer, record_size);
        status = tmp___1;
      }
    } else {
      {
        tmp___2 =
            safe_read(archive, (void *)(record_start->buffer), record_size);
        status = tmp___2;
      }
    }
    if (status == record_size) {
      records_read++;
      return;
    }
    if (status == 0UL) {
      goto _L___1;
    } else {
      if (status == 0xffffffffffffffffUL) {
        {
          tmp___24 = __errno_location();
        }
        if (*tmp___24 == 28) {
        _L___1:
          if (multi_volume_option) {
          try_volume: {
            if ((unsigned int)subcommand_option == 1U) {
              goto case_1;
            }
            if ((unsigned int)subcommand_option == 2U) {
              goto case_1;
            }
            if ((unsigned int)subcommand_option == 8U) {
              goto case_1;
            }
            goto switch_default;
          case_1:   /* CIL Label */
          case_2:   /* CIL Label */
          case_8: { /* CIL Label */
            tmp___3 = new_volume((enum access_mode)2);
          }
            if (!tmp___3) {
              return;
            }
            goto switch_break;
          switch_default: { /* CIL Label */
            tmp___4 = new_volume((enum access_mode)0);
          }
            if (!tmp___4) {
              return;
            }
            goto switch_break;
          switch_break: /* CIL Label */
              ;
          }
            {
              while (1) {
              while_continue: /* CIL Label */
                  ;
                if (archive >= 1 << 30) {
                  {
                    tmp___5 = rmt_read__(archive - (1 << 30),
                                         record_start->buffer, record_size);
                    status = tmp___5;
                  }
                } else {
                  {
                    tmp___6 = safe_read(archive, (void *)(record_start->buffer),
                                        record_size);
                    status = tmp___6;
                  }
                }
                if (!(status == 0xffffffffffffffffUL)) {
                  goto while_break;
                }
                { archive_read_error(); }
              }
            while_break: /* CIL Label */
                ;
            }
            if (status != record_size) {
              {
                short_read(status);
              }
            }
            cursor = record_start;
            if ((int)cursor->header.typeflag == 86) {
              if (volume_label_option) {
                {
                  tmp___10 = check_label_pattern(cursor);
                }
                if (!tmp___10) {
                  {
                    tmp___7 = quote_n(1, volume_label_option);
                    tmp___8 = quote_n(0, (char const *)(cursor->header.name));
                    tmp___9 = gettext("Volume %s does not match %s");
                    error(0, 0, (char const *)tmp___9, tmp___8, tmp___7);
                    volno--;
                    global_volno--;
                  }
                  goto try_volume;
                }
              }

              cursor++;
            } else {
            }
            if (real_s_name) {
              if ((int)cursor->header.typeflag != 77) {
                goto _L;
              } else {
                {
                  tmp___16 = strcmp((char const *)(cursor->header.name),
                                    (char const *)real_s_name);
                }
                if (tmp___16) {
                _L: {
                  tmp___14 = quote((char const *)real_s_name);
                  tmp___15 = gettext("%s is not continued on this volume");
                  error(0, 0, (char const *)tmp___15, tmp___14);
                  volno--;
                  global_volno--;
                }
                  goto try_volume;
                }
              }
              {
                s1 = uintmax_from_header((char const *)(cursor->header.size),
                                         sizeof(cursor->header.size));
                s2 = uintmax_from_header(
                    (char const *)(cursor->oldgnu_header.offset),
                    sizeof(cursor->oldgnu_header.offset));
              }
              if ((uintmax_t)real_s_totsize != s1 + s2) {
                goto _L___3;
              } else {
                if (s1 + s2 < s2) {
                _L___3: { /* CIL Label */
                  tmp___17 = stringify_uintmax_t_backwards(
                      s2,
                      s2buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL +
                                1UL) +
                               1UL));
                  tmp___18 = stringify_uintmax_t_backwards(
                      s1,
                      s1buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL +
                                1UL) +
                               1UL));
                  tmp___19 = stringify_uintmax_t_backwards(
                      (uintmax_t)save_totsize,
                      totsizebuf +
                          ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL +
                            1UL) +
                           1UL));
                  tmp___20 = quote((char const *)(cursor->header.name));
                  tmp___21 = gettext("%s is the wrong size (%s != %s + %s)");
                  error(0, 0, (char const *)tmp___21, tmp___20, tmp___19,
                        tmp___18, tmp___17);
                  volno--;
                  global_volno--;
                }
                  goto try_volume;
                }
              }
              {
                tmp___23 = off_from_header(
                    (char const *)(cursor->oldgnu_header.offset),
                    sizeof(cursor->oldgnu_header.offset));
              }
              if (real_s_totsize - real_s_sizeleft != tmp___23) {
                {
                  tmp___22 = gettext("This volume is out of sequence");
                  error(0, 0, (char const *)tmp___22);
                  volno--;
                  global_volno--;
                }
                goto try_volume;
              }
              cursor++;
            }
            current_block = cursor;
            records_read++;
            return;
          } else {
            goto _L___2;
          }
        } else {
          goto _L___2;
        }
      } else {
      _L___2:
        if (status == 0xffffffffffffffffUL) {
          {
            archive_read_error();
          }
          goto error_loop;
        }
      }
    }
    { short_read(status); }
    return;
  }
}
void flush_archive(void) {

  {
    record_start_block += record_end - record_start;
    current_block = record_start;
    record_end = record_start + blocking_factor;

    {
      if ((unsigned int)access_mode == 0U) {
        goto case_0;
      }

      goto switch_break;
    case_0: { /* CIL Label */
      flush_read();
    }
      goto switch_break;
    case_1: { /* CIL Label */
      flush_write();
    }
      goto switch_break;
    case_2: { /* CIL Label */
      abort();
    }
    switch_break: /* CIL Label */
        ;
    }
    return;
  }
}
static void backspace_output(void) {
  struct mtop operation;
  int tmp;
  int tmp___0;
  int tmp___1;
  int *tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  off_t position;
  off_t tmp___6;
  __off_t tmp___7;
  off_t tmp___8;
  char *tmp___9;
  off_t tmp___10;
  __off_t tmp___11;
  off_t tmp___12;
  char *__cil_tmp17;

  {
    operation.mt_op = (short)4;
    operation.mt_count = 1;
    if (archive >= 1 << 30) {
      {
        tmp = rmt_ioctl__(
            archive - (1 << 30),
            (int)((unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) |
                                  1U) |
                  (sizeof(struct mtop) << 16)),
            (char *)(&operation));
        tmp___1 = tmp;
      }
    } else {
      {
        tmp___0 = ioctl(
            archive,
            (unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) | 1U) |
                (sizeof(struct mtop) << 16),
            (char *)(&operation));
        tmp___1 = tmp___0;
      }
    }
    if (tmp___1 >= 0) {
      return;
    }
    { tmp___2 = __errno_location(); }
    if (*tmp___2 == 5) {
      if (archive >= 1 << 30) {
        {
          tmp___3 = rmt_ioctl__(
              archive - (1 << 30),
              (int)((unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) |
                                    1U) |
                    (sizeof(struct mtop) << 16)),
              (char *)(&operation));
          tmp___5 = tmp___3;
        }
      } else {
        {
          tmp___4 = ioctl(
              archive,
              (unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) | 1U) |
                  (sizeof(struct mtop) << 16),
              (char *)(&operation));
          tmp___5 = tmp___4;
        }
      }
    }
    if (archive >= 1 << 30) {
      {
        tmp___6 = rmt_lseek__(archive - (1 << 30), (off_t)0, 1);
        tmp___8 = tmp___6;
      }
    } else {
      {
        tmp___7 = lseek(archive, (off_t)0, 1);
        tmp___8 = tmp___7;
      }
    }
    position = tmp___8;
    position = (off_t)((size_t)position - record_size);
    if (position < 0L) {
      position = (off_t)0;
    }
    if (archive >= 1 << 30) {
      {
        tmp___10 = rmt_lseek__(archive - (1 << 30), position, 0);
        tmp___12 = tmp___10;
      }
    } else {
      {
        tmp___11 = lseek(archive, position, 0);
        tmp___12 = tmp___11;
      }
    }

    return;
  }
}
void close_archive(void) {
  int tmp;
  int tmp___0;
  int tmp___1;
  union block *tmp___2;

  {

    { sys_drain_input_pipe(); }

    if (archive >= 1 << 30) {
      {
        tmp = rmt_close__(archive - (1 << 30));
        tmp___1 = tmp;
      }
    } else {
      {
        tmp___0 = close(archive);
        tmp___1 = tmp___0;
      }
    }
    if (tmp___1 != 0) {
      {
        close_warn(*archive_name_cursor);
      }
    }
    {
      sys_wait_for_child(child_pid);
      tar_stat_destroy(&current_stat_info);
    }
    if (save_name) {
      {
        free((void *)save_name);
      }
    }
    if (real_s_name) {
      {
        free((void *)real_s_name);
      }
    }

    { free((void *)tmp___2); }
    return;
  }
}

static FILE *read_file;
static int looped;
static _Bool new_volume(enum access_mode mode) {
  FILE *tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  char *tmp___3;
  char *tmp___4;
  int tmp___5;
  char input_buffer[80];
  char const *tmp___6;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  char *tmp___10;
  char *tmp___11;
  char *tmp___12;
  char *tmp___13;
  char *name;
  char *cursor;
  char *tmp___14;
  int tmp___16;
  int tmp___17;
  void *tmp___18;
  int tmp___20;
  int tmp___21;
  void *tmp___22;
  int tmp___24;
  int tmp___25;
  void *tmp___26;
  int tmp___28;
  int tmp___29;
  void *tmp___30;
  int tmp___31;
  void *__cil_tmp34;
  char *__cil_tmp35;
  char *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;
  char *__cil_tmp39;
  char *__cil_tmp40;
  char *__cil_tmp41;
  char *__cil_tmp42;

  {
    if (!read_file) {
      if (!info_script_option) {
        if (archive == 0) {
          {
            tmp = fopen((char const * /* __restrict  */) "/dev/tty",
                        (char const * /* __restrict  */) "r");
            read_file = tmp;
          }
        } else {
          read_file = stdin;
        }
      }
    }

    if (tmp___2 != 0) {
      {
        close_warn(*archive_name_cursor);
      }
    }
    global_volno++;
    if (global_volno < 0) {
      {
        tmp___3 = gettext("Volume number overflow");
        error(0, 0, (char const *)tmp___3);
        fatal_exit();
      }
    }
    volno++;
    archive_name_cursor++;

  tryagain:
    if (looped) {
    }
    { tmp___31 = strcmp(*(archive_name_cursor + 0), "-"); }
    if (tmp___31 == 0) {
      read_full_records_option = (_Bool)1;
      archive = 0;
    } else {
      if (verify_option) {
        if (!force_local_option) {
          {
            rmt_path__ = strchr(*archive_name_cursor, ':');
          }
          if (rmt_path__) {
            if ((unsigned long)rmt_path__ >
                (unsigned long)*archive_name_cursor) {
              {
                tmp___18 =
                    memchr((void const *)*archive_name_cursor, '/',
                           (size_t)(rmt_path__ - (char *)*archive_name_cursor));
              }
              if (tmp___18) {
                {
                  tmp___17 = open(*archive_name_cursor, 66,
                                  ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                      ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                  archive = tmp___17;
                }
              } else {
                {
                  tmp___16 = rmt_open__(*archive_name_cursor, 66, 1 << 30,
                                        rsh_command_option);
                  archive = tmp___16;
                }
              }
            } else {
              {
                tmp___17 = open(*archive_name_cursor, 66,
                                ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                    ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                archive = tmp___17;
              }
            }
          } else {
            {
              tmp___17 = open(*archive_name_cursor, 66,
                              ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                  ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
              archive = tmp___17;
            }
          }
        } else {
          {
            tmp___17 = open(*archive_name_cursor, 66,
                            ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
            archive = tmp___17;
          }
        }
      } else {
        {
          if ((unsigned int)mode == 0U) {
            goto case_0;
          }

          goto switch_break___0;
        case_0: /* CIL Label */
          if (!force_local_option) {
            {
              rmt_path__ = strchr(*archive_name_cursor, ':');
            }
            if (rmt_path__) {
              if ((unsigned long)rmt_path__ >
                  (unsigned long)*archive_name_cursor) {
                {
                  tmp___22 = memchr(
                      (void const *)*archive_name_cursor, '/',
                      (size_t)(rmt_path__ - (char *)*archive_name_cursor));
                }
                if (tmp___22) {
                  {
                    tmp___21 =
                        open(*archive_name_cursor, 0,
                             ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                 ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                    archive = tmp___21;
                  }
                } else {
                  {
                    tmp___20 = rmt_open__(*archive_name_cursor, 0, 1 << 30,
                                          rsh_command_option);
                    archive = tmp___20;
                  }
                }
              } else {
                {
                  tmp___21 = open(*archive_name_cursor, 0,
                                  ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                      ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                  archive = tmp___21;
                }
              }
            } else {
              {
                tmp___21 = open(*archive_name_cursor, 0,
                                ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                    ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                archive = tmp___21;
              }
            }
          } else {
            {
              tmp___21 = open(*archive_name_cursor, 0,
                              ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                  ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
              archive = tmp___21;
            }
          }
          goto switch_break___0;
        case_1: /* CIL Label */

          goto switch_break___0;
        case_2: /* CIL Label */
          if (!force_local_option) {
            {
              rmt_path__ = strchr(*archive_name_cursor, ':');
            }
            if (rmt_path__) {
              if ((unsigned long)rmt_path__ >
                  (unsigned long)*archive_name_cursor) {
                {
                  tmp___30 = memchr(
                      (void const *)*archive_name_cursor, '/',
                      (size_t)(rmt_path__ - (char *)*archive_name_cursor));
                }

              } else {
                {
                  tmp___29 = open(*archive_name_cursor, 66,
                                  ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                      ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                  archive = tmp___29;
                }
              }
            } else {
              {
                tmp___29 = open(*archive_name_cursor, 66,
                                ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                    ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                archive = tmp___29;
              }
            }
          } else {
            {
              tmp___29 = open(*archive_name_cursor, 66,
                              ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                  ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
              archive = tmp___29;
            }
          }
          goto switch_break___0;
        switch_break___0: /* CIL Label */
            ;
        }
      }
    }
    if (archive < 0) {
      {
        open_warn(*archive_name_cursor);
      }

      goto tryagain;
    }
    return ((_Bool)1);
  }
}
/* #pragma merger("0","001.compare.o.i","") */
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2,
                                          size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2),
                                                       __leaf__)) strncmp)(
    char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__))
ssize_t(__attribute__((__nonnull__(1, 2), __leaf__)) readlink)(
    char const *__restrict __path, char *__restrict __buf, size_t __len);
extern int fsync(int __fd);
extern int vfprintf(FILE *__restrict __s, char const *__restrict __format,
                    __gnuc_va_list __arg);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) utime)(char const *__file,
                                      struct utimbuf const *__file_times);
__attribute__((__noreturn__)) void xalloc_die(void);
int exit_status;
_Bool atime_preserve_option;
_Bool dereference_option;
void diff_archive(void);
void diff_init(void);
char *get_directory_contents(char *path, dev_t device);
union block *current_header;
enum archive_format current_format;
void decode_header(union block *header, struct tar_stat_info *stat_info,
                   enum archive_format *format_pointer, int do_user_group);
void print_header(struct tar_stat_info *st, off_t block_ordinal);
enum read_header read_header(_Bool raw_extended_headers);
void skip_member(void);
int deref_stat(_Bool deref, char const *name, struct stat *buf);
void readlink_error(char const *name);
void readlink_warn(char const *name);
void seek_error_details(char const *name, off_t offset);
void seek_warn(char const *name);
void stat_error(char const *name);
void stat_warn(char const *name);
_Bool sys_compare_uid(struct stat *a, struct stat *b);
_Bool sys_compare_gid(struct stat *a, struct stat *b);
_Bool sys_compare_links(struct stat *link_data, struct stat *stat_data);
void report_difference(struct tar_stat_info *st __attribute__((__unused__)),
                       char const *fmt, ...);
_Bool sparse_diff_file(int fd, struct tar_stat_info *st);
static int diff_handle;
static char *diff_buffer;
void diff_init(void) {
  void *tmp;

  {
    {
      tmp = valloc(record_size);
      diff_buffer = (char *)tmp;
    }
    if (!diff_buffer) {
      {
        xalloc_die();
      }
    }
    return;
  }
}
void report_difference(struct tar_stat_info *st __attribute__((__unused__)),
                       char const *fmt, ...) {
  va_list ap;
  char *tmp;

  { return; }
}
static int process_noop(size_t size __attribute__((__unused__)),
                        char *data __attribute__((__unused__))) {

  { return (1); }
}
static int process_rawdata(size_t bytes, char *buffer___2) {
  size_t status;
  size_t tmp;
  char *tmp___0;
  char *tmp___1;
  int tmp___2;
  char *__cil_tmp8;

  {
    {
      tmp = safe_read(diff_handle, (void *)diff_buffer, bytes);
      status = tmp;
    }
    if (status != bytes) {
      if (status == 0xffffffffffffffffUL) {
        {
          read_error((char const *)current_stat_info.file_name);
          report_difference(&current_stat_info, (char const *)((void *)0));
        }
      } else {
        {
          tmp___0 = ngettext("Could only read %lu of %lu byte",
                             "Could only read %lu of %lu bytes", bytes);
          report_difference(&current_stat_info, (char const *)tmp___0, status,
                            bytes);
        }
      }
      return (0);
    }
    {
      tmp___2 =
          memcmp((void const *)buffer___2, (void const *)diff_buffer, bytes);
    }
    if (tmp___2) {
      {
        tmp___1 = gettext("Contents differ");
        report_difference(&current_stat_info, (char const *)tmp___1);
      }
      return (0);
    }
    return (1);
  }
}
static char *dumpdir_cursor;
static int process_dumpdir(size_t bytes, char *buffer___2) {
  char *tmp;
  int tmp___0;
  char *__cil_tmp5;

  {
    {
      tmp___0 =
          memcmp((void const *)buffer___2, (void const *)dumpdir_cursor, bytes);
    }

    dumpdir_cursor += bytes;
    return (1);
  }
}
static void read_and_process(off_t size, int (*processor)(size_t, char *)) {
  union block *data_block;
  size_t data_size;
  char *tmp;
  int tmp___0;
  char *__cil_tmp7;

  {

    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!size) {
          goto while_break;
        }
        { data_block = find_next_block(); }

        { data_size = available_space_after(data_block); }
        if (data_size > (size_t)size) {
          data_size = (size_t)size;
        }
        { tmp___0 = (*processor)(data_size, data_block->buffer); }
        if (!tmp___0) {
          processor = &process_noop;
        }
        {
          set_next_block_after(
              (union block *)((data_block->buffer + data_size) - 1));
          size = (off_t)((size_t)size - data_size);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static int get_stat_data(char const *file_name, struct stat *stat_data) {
  int status;
  int tmp;
  int *tmp___0;

  {
    {
      tmp = deref_stat(dereference_option, file_name, stat_data);
      status = tmp;
    }
    if (status != 0) {
      {
        tmp___0 = __errno_location();
      }
      if (*tmp___0 == 2) {
        {
          stat_warn(file_name);
        }
      } else {
        { stat_error(file_name); }
      }
      { report_difference(&current_stat_info, (char const *)((void *)0)); }
      return (0);
    }
    return (1);
  }
}
void diff_archive(void) {
  struct stat stat_data;
  int status;
  struct utimbuf restore_times;
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  int tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  _Bool tmp___6;
  char *tmp___7;
  _Bool tmp___8;
  char *tmp___9;
  char *tmp___10;
  struct stat file_data;
  struct stat link_data;
  int tmp___11;
  int tmp___12;
  char const *tmp___13;
  char *tmp___14;
  _Bool tmp___15;
  size_t len;
  size_t tmp___16;
  char *linkbuf;
  void *tmp___17;
  ssize_t tmp___18;
  int *tmp___19;
  char *tmp___20;
  int tmp___21;
  int tmp___22;
  char *tmp___23;
  char *tmp___24;
  char *tmp___25;
  char *dumpdir_buffer;
  char *tmp___26;
  int tmp___27;
  char *tmp___28;
  char *tmp___29;
  off_t offset;
  int tmp___30;
  char *tmp___31;
  char *tmp___32;
  __off_t tmp___33;
  int tmp___34;
  int tmp___35;
  void *__cil_tmp47;
  void *__cil_tmp48;
  void *__cil_tmp49;
  char *__cil_tmp50;
  char *__cil_tmp51;
  char *__cil_tmp52;
  char *__cil_tmp53;
  char *__cil_tmp54;
  char *__cil_tmp55;
  char *__cil_tmp56;
  char *__cil_tmp57;
  char *__cil_tmp58;
  char *__cil_tmp59;
  char *__cil_tmp60;
  char *__cil_tmp61;
  char *__cil_tmp62;
  char *__cil_tmp63;
  char *__cil_tmp64;
  char *__cil_tmp65;
  char *__cil_tmp66;
  char *__cil_tmp67;

  {
    {
      set_next_block_after(current_header);
      decode_header(current_header, &current_stat_info, &current_format, 1);
    }

    {
      if ((int)current_header->header.typeflag == 0) {
        goto case_0;
      }
      if ((int)current_header->header.typeflag == 48) {
        goto case_0;
      }
      if ((int)current_header->header.typeflag == 83) {
        goto case_0;
      }

      if ((int)current_header->header.typeflag == 49) {
        goto case_49;
      }
      if ((int)current_header->header.typeflag == 50) {
        goto case_50;
      }
      if ((int)current_header->header.typeflag == 51) {
        goto case_51;
      }
      if ((int)current_header->header.typeflag == 52) {
        goto case_51;
      }
      if ((int)current_header->header.typeflag == 54) {
        goto case_51;
      }
      if ((int)current_header->header.typeflag == 68) {
        goto case_68;
      }
      if ((int)current_header->header.typeflag == 53) {
        goto really_dir;
      }
      if ((int)current_header->header.typeflag == 86) {
        goto case_86;
      }
      if ((int)current_header->header.typeflag == 77) {
        goto case_77;
      }
      goto switch_default;
    switch_default: { /* CIL Label */
      tmp___0 = quotearg_colon((char const *)current_stat_info.file_name);
      tmp___1 = gettext("%s: Unknown file type \'%c\', diffed as normal file");
      error(0, 0, (char const *)tmp___1, tmp___0,
            (int)current_header->header.typeflag);
      exit_status = 2;
    }
    case_0:  /* CIL Label */
    case_48: /* CIL Label */
    case_83: /* CIL Label */
    case_55: /* CIL Label */
      if (current_stat_info.had_trailing_slash) {
        goto really_dir;
      }
      {
        tmp___2 = get_stat_data((char const *)current_stat_info.file_name,
                                &stat_data);
      }
      if (!tmp___2) {
        {
          skip_member();
        }
        goto quit;
      }
      if (!((stat_data.st_mode & 61440U) == 32768U)) {
        {
          tmp___3 = gettext("File type differs");
          report_difference(&current_stat_info, (char const *)tmp___3);
          skip_member();
        }
        goto quit;
      }

      { tmp___6 = sys_compare_uid(&stat_data, &current_stat_info.stat); }
      if (!tmp___6) {
        {
          tmp___5 = gettext("Uid differs");
          report_difference(&current_stat_info, (char const *)tmp___5);
        }
      }
      { tmp___8 = sys_compare_gid(&stat_data, &current_stat_info.stat); }
      if (!tmp___8) {
        {
          tmp___7 = gettext("Gid differs");
          report_difference(&current_stat_info, (char const *)tmp___7);
        }
      }
      if (stat_data.st_mtim.tv_sec != current_stat_info.stat.st_mtim.tv_sec) {
        {
          tmp___9 = gettext("Mod time differs");
          report_difference(&current_stat_info, (char const *)tmp___9);
        }
      }
      if ((int)current_header->header.typeflag != 83) {
        if (stat_data.st_size != current_stat_info.stat.st_size) {
          {
            tmp___10 = gettext("Size differs");
            report_difference(&current_stat_info, (char const *)tmp___10);
            skip_member();
          }
          goto quit;
        }
      }
      { diff_handle = open((char const *)current_stat_info.file_name, 0); }
      if (diff_handle < 0) {
        {
          open_error((char const *)current_stat_info.file_name);
          skip_member();
          report_difference(&current_stat_info, (char const *)((void *)0));
        }
        goto quit;
      }
      restore_times.actime = stat_data.st_atim.tv_sec;
      restore_times.modtime = stat_data.st_mtim.tv_sec;
      if (current_stat_info.is_sparse) {
        {
          sparse_diff_file(diff_handle, &current_stat_info);
        }
      } else {

        { read_and_process(current_stat_info.stat.st_size, &process_rawdata); }
      }
      { status = close(diff_handle); }
      if (status != 0) {
        {
          close_error((char const *)current_stat_info.file_name);
        }
      }

    quit:
      goto switch_break;
    case_49: { /* CIL Label */
      tmp___11 =
          get_stat_data((char const *)current_stat_info.file_name, &file_data);
    }
      if (!tmp___11) {
        goto switch_break;
      }
      {
        tmp___12 = get_stat_data((char const *)current_stat_info.link_name,
                                 &link_data);
      }
      if (!tmp___12) {
        goto switch_break;
      }
      { tmp___15 = sys_compare_links(&file_data, &link_data); }

      goto switch_break;
    case_50: { /* CIL Label */
      tmp___16 = strlen((char const *)current_stat_info.link_name);
      len = tmp___16;
      tmp___17 = __builtin_alloca(len + 1UL);
      linkbuf = (char *)tmp___17;
      tmp___18 =
          readlink((char const * /* __restrict  */)current_stat_info.file_name,
                   (char * /* __restrict  */)linkbuf, len + 1UL);
      status = (int)tmp___18;
    }
      if (status < 0) {
        {
          tmp___19 = __errno_location();
        }
        if (*tmp___19 == 2) {
          {
            readlink_warn((char const *)current_stat_info.file_name);
          }
        } else {
          { readlink_error((char const *)current_stat_info.file_name); }
        }
        { report_difference(&current_stat_info, (char const *)((void *)0)); }
      } else {
      }
      goto switch_break;
    case_51:   /* CIL Label */
    case_52:   /* CIL Label */
    case_54: { /* CIL Label */
      tmp___22 =
          get_stat_data((char const *)current_stat_info.file_name, &stat_data);
    }
      if (!tmp___22) {
        goto switch_break;
      }
      if ((int)current_header->header.typeflag == 51) {
        tmp___35 = !((stat_data.st_mode & 61440U) == 8192U);
      } else {
        if ((int)current_header->header.typeflag == 52) {
          tmp___34 = !((stat_data.st_mode & 61440U) == 24576U);
        } else {
          tmp___34 = !((stat_data.st_mode & 61440U) == 4096U);
        }
        tmp___35 = tmp___34;
      }

      if ((int)current_header->header.typeflag == 51) {
        goto _L___3;
      } else {
        if ((int)current_header->header.typeflag == 52) {
        _L___3: /* CIL Label */
          if (current_stat_info.stat.st_rdev != stat_data.st_rdev) {
            {
              tmp___24 = gettext("Device number differs");
              report_difference(&current_stat_info, (char const *)tmp___24);
            }
            goto switch_break;
          }
        }
      }

      goto switch_break;
    case_68: { /* CIL Label */
      tmp___26 = get_directory_contents(current_stat_info.file_name, (dev_t)0);
      dumpdir_buffer = tmp___26;
    }

      if (dumpdir_buffer) {
        {
          dumpdir_cursor = dumpdir_buffer;
          read_and_process(current_stat_info.stat.st_size, &process_dumpdir);
          free((void *)dumpdir_buffer);
        }
      } else {
        { read_and_process(current_stat_info.stat.st_size, &process_noop); }
      }

    really_dir:
    case_53: { /* CIL Label */
      tmp___27 =
          get_stat_data((char const *)current_stat_info.file_name, &stat_data);
    }
      if (!tmp___27) {
        goto switch_break;
      }
      if (!((stat_data.st_mode & 61440U) == 16384U)) {
        {
          tmp___28 = gettext("File type differs");
          report_difference(&current_stat_info, (char const *)tmp___28);
        }
        goto switch_break;
      }

      goto switch_break;
    case_86: /* CIL Label */
      goto switch_break;
    case_77: /* CIL Label */
      if (current_stat_info.had_trailing_slash) {
        goto really_dir;
      }
      {
        tmp___30 = get_stat_data((char const *)current_stat_info.file_name,
                                 &stat_data);
      }
      if (!tmp___30) {
        goto switch_break;
      }
      if (!((stat_data.st_mode & 61440U) == 32768U)) {
        {
          tmp___31 = gettext("File type differs");
          report_difference(&current_stat_info, (char const *)tmp___31);
          skip_member();
        }
        goto switch_break;
      }
      {
        offset = off_from_header(
            (char const *)(current_header->oldgnu_header.offset),
            sizeof(current_header->oldgnu_header.offset));
      }
      if (stat_data.st_size != current_stat_info.stat.st_size + offset) {
        {
          tmp___32 = gettext("Size differs");
          report_difference(&current_stat_info, (char const *)tmp___32);
          skip_member();
        }
        goto switch_break;
      }
      { diff_handle = open((char const *)current_stat_info.file_name, 0); }
      if (diff_handle < 0) {
        {
          open_error((char const *)current_stat_info.file_name);
          report_difference(&current_stat_info, (char const *)((void *)0));
          skip_member();
        }
        goto switch_break;
      }
      { tmp___33 = lseek(diff_handle, offset, 0); }
      if (tmp___33 < 0L) {
        {
          seek_error_details((char const *)current_stat_info.file_name, offset);
          report_difference(&current_stat_info, (char const *)((void *)0));
        }
        goto switch_break;
      }

      { read_and_process(current_stat_info.stat.st_size, &process_rawdata); }

      { status = close(diff_handle); }
      if (status != 0) {
        {
          close_error((char const *)current_stat_info.file_name);
        }
      }
      goto switch_break;
    switch_break: /* CIL Label */
        ;
    }
    return;
  }
}
void verify_volume(void) {
  struct mtop operation;
  int status;
  off_t tmp;
  __off_t tmp___0;
  off_t tmp___1;
  int *tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  enum read_header status___0;
  enum read_header tmp___7;
  int counter;
  char *tmp___8;

  {

    {
      fsync(archive);
      ioctl(archive, (unsigned long)((unsigned int)(2 << 8) | 75U));
      operation.mt_op = (short)2;
      operation.mt_count = 1;
    }
    if (archive >= 1 << 30) {
      {
        tmp___5 = rmt_ioctl__(
            archive - (1 << 30),
            (int)((unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) |
                                  1U) |
                  (sizeof(struct mtop) << 16)),
            (char *)(&operation));
        status = tmp___5;
      }
    } else {
      {
        tmp___6 = ioctl(
            archive,
            (unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) | 1U) |
                (sizeof(struct mtop) << 16),
            (char *)(&operation));
        status = tmp___6;
      }
    }
    if (status < 0) {
      {
        tmp___2 = __errno_location();
      }
      if (*tmp___2 != 5) {
        goto _L;
      } else {
        if (archive >= 1 << 30) {
          {
            tmp___3 = rmt_ioctl__(
                archive - (1 << 30),
                (int)((unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) |
                                      1U) |
                      (sizeof(struct mtop) << 16)),
                (char *)(&operation));
            status = tmp___3;
          }
        } else {
          {
            tmp___4 = ioctl(
                archive,
                (unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) | 1U) |
                    (sizeof(struct mtop) << 16),
                (char *)(&operation));
            status = tmp___4;
          }
        }
        if (status < 0) {
        _L:
          if (archive >= 1 << 30) {
            {
              tmp = rmt_lseek__(archive - (1 << 30), (off_t)0, 0);
              tmp___1 = tmp;
            }
          } else {
            {
              tmp___0 = lseek(archive, (off_t)0, 0);
              tmp___1 = tmp___0;
            }
          }
          if (tmp___1 != 0L) {
            {
              seek_warn(*(archive_name_array + 0));
            }
            return;
          }
        }
      }
    }
    {
      access_mode = (enum access_mode)0;
      now_verifying = (_Bool)1;
      flush_read();
    }
    {

    while_break: /* CIL Label */
        ;
    }
    access_mode = (enum access_mode)1;
    now_verifying = (_Bool)0;
    return;
  }
}
/* #pragma merger("0","002.create.o.i","") */
extern __attribute__((__nothrow__)) unsigned int(
    __attribute__((__leaf__)) gnu_dev_major)(unsigned long long __dev)
    __attribute__((__const__));
extern __attribute__((__nothrow__)) unsigned int(
    __attribute__((__leaf__)) gnu_dev_minor)(unsigned long long __dev)
    __attribute__((__const__));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) strncpy)(
    char *__restrict __dest, char const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strdup)(char const *__s)
    __attribute__((__malloc__));
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(2), __leaf__)) fstat)(int __fd, struct stat *__buf);
extern __attribute__((__nothrow__))
__uid_t(__attribute__((__leaf__)) getuid)(void);
extern __attribute__((__nothrow__))
__gid_t(__attribute__((__leaf__)) getgid)(void);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) unlink)(char const *__name);
char *savedir(char const *dir);
void *xrealloc(void *p, size_t n);
mode_t mode_adjust(mode_t oldmode, struct mode_change const *changes);
enum archive_format archive_format;
int after_date_option;
gid_t group_option;
_Bool ignore_failed_read_option;
_Bool incremental_option;
_Bool interactive_option;
char const *listed_incremental_option;
struct mode_change *mode_option;
struct timespec newer_mtime_option;
int recursion_option;
_Bool numeric_owner_option;
_Bool one_file_system_option;
uid_t owner_option;
_Bool remove_files_option;
_Bool sparse_option;
_Bool file_dumpable_p(struct tar_stat_info *st);
void create_archive(void);
void pad_archive(off_t size_left);
void dump_file(char *p, int top_level, dev_t parent_device);
union block *start_header(struct tar_stat_info *st);
void simple_finish_header(union block *header);
union block *start_private_header(char const *name, size_t size);
void write_eot(void);
void check_links(void);
void gid_to_chars(gid_t v, char *p, size_t s);
void major_to_chars(int v, char *p, size_t s);
void minor_to_chars(int v, char *p, size_t s);
void mode_to_chars(mode_t v, char *p, size_t s);
void size_to_chars(size_t v, char *p, size_t s);
void uid_to_chars(uid_t v, char *p, size_t s);
void uintmax_to_chars(uintmax_t v, char *p, size_t s);
void string_to_chars(char *str, char *p, size_t s);
void write_directory_file(void);
struct xheader extended_header;
void close_diag(char const *name);
void open_diag(char const *name);
void read_diag_details(char const *name, off_t offset, size_t size);
void readlink_diag(char const *name);
void savedir_diag(char const *name);
void stat_diag(char const *name);
void unlink_error(char const *name);
struct name *gnu_list_name;
void gid_to_gname(gid_t gid, char **gname);
int gname_to_gid(char const *gname, gid_t *gidp);
void uid_to_uname(uid_t uid, char **uname);
int uname_to_uid(char const *uname, uid_t *uidp);
char *name_next(int change_dirs);
void collect_and_sort_names(void);
char *name_from_list(void);
void blank_name_list(void);
_Bool excluded_name(char const *name);
_Bool is_avoided_name(char const *name);
int confirm(char const *message_action, char const *message_name);
void tar_stat_init(struct tar_stat_info *st);
void xheader_store(char const *keyword, struct tar_stat_info const *st,
                   void *data);
void xheader_write(char type, char *name, struct xheader *xhdr);
void xheader_write_global(void);
void xheader_finish(struct xheader *xhdr);
char *xheader_xhdr_name(struct tar_stat_info *st);
void sys_stat_nanoseconds(struct tar_stat_info *st);
_Bool sys_file_is_archive(struct tar_stat_info *p);
_Bool sparse_file_p(struct tar_stat_info *st);
enum dump_status sparse_dump_file(int fd, struct tar_stat_info *st);
_Bool string_ascii_p(char const *str);
void *hash_lookup(Hash_table const *table___0, void const *entry);
void *hash_get_first(Hash_table const *table___0);
void *hash_get_next(Hash_table const *table___0, void const *entry);
Hash_table *hash_initialize(size_t candidate, Hash_tuning const *tuning,
                            size_t (*hasher)(void const *, size_t),
                            _Bool (*comparator)(void const *, void const *),
                            void (*data_freer)(void *));
void *hash_insert(Hash_table *table___0, void const *entry);
static void to_octal(uintmax_t value, char *where, size_t size) {
  uintmax_t v;
  size_t i;

  {
    v = value;
    i = size;
    {

    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static void to_base256(int negative, uintmax_t value, char *where,
                       size_t size) {
  uintmax_t v;
  uintmax_t propagated_sign_bits;
  size_t i;

  {
    v = value;
    propagated_sign_bits = (uintmax_t)(-negative) << (8UL * sizeof(v) - 8UL);
    i = size;
    {

    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static int warned_once;
static void to_chars(int negative, uintmax_t value, size_t valsize,
                     uintmax_t (*substitute)(int *), char *where, size_t size,
                     char const *type) {
  int base256_allowed;
  char *tmp;
  uintmax_t maxval;
  char valbuf[((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL) +
              1UL];
  char maxbuf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char minbuf[((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL) +
              1UL];
  char const *minval_string;
  char const *maxval_string;
  char *tmp___0;
  char const *value_string;
  uintmax_t m;
  char *p;
  char *tmp___1;
  char *p___0;
  char *tmp___2;
  char *tmp___3;
  int negsub;
  uintmax_t sub;
  uintmax_t tmp___4;
  uintmax_t s;
  char subbuf[((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL) +
              1UL];
  char *sub_string;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  int tmp___8;
  int tmp___9;
  unsigned long tmp___10;
  unsigned long tmp___11;
  unsigned long tmp___12;
  unsigned long tmp___13;
  unsigned long tmp___14;
  unsigned long tmp___15;
  void *__cil_tmp41;
  void *__cil_tmp42;
  void *__cil_tmp43;
  void *__cil_tmp44;
  char *__cil_tmp45;
  char *__cil_tmp46;
  char *__cil_tmp47;
  char *__cil_tmp48;

  {
    if ((unsigned int)archive_format == 6U) {
      tmp___8 = 1;
    } else {
      if ((unsigned int)archive_format == 2U) {
        tmp___8 = 1;
      } else {
        tmp___8 = 0;
      }
    }
    base256_allowed = tmp___8;
    if (!negative) {
      if ((size - 1UL) * 3UL < sizeof(uintmax_t) * 8UL) {
        tmp___15 = (1UL << (size - 1UL) * 3UL) - 1UL;
      } else {
        tmp___15 = (uintmax_t)-1;
      }
      if (value <= tmp___15) {
        {
          *(where + (size - 1UL)) = (char)'\000';
          to_octal(value, where, size - 1UL);
        }
      } else {
        goto _L___5;
      }
    } else {
    _L___5: /* CIL Label */
      if (negative) {
        tmp___13 = 0xffffffffffffffffUL - value;
      } else {
        tmp___13 = value;
      }
      if ((size - 1UL) * 8UL < sizeof(uintmax_t) * 8UL) {
        tmp___14 = (1UL << (size - 1UL) * 8UL) - 1UL;
      } else {
        tmp___14 = (uintmax_t)-1;
      }
      if (tmp___13 <= tmp___14) {
        if (base256_allowed) {
          if (negative) {
            tmp___9 = -1;
          } else {
            tmp___9 = 1 << 7;
          }
          {
            *(where + 0) = (char)tmp___9;
            to_base256(negative, value, where + 1, size - 1UL);
          }
        } else {
          goto _L___4;
        }
      } else {
      _L___4: /* CIL Label */
        if (negative) {

        } else {
        _L___3: /* CIL Label */
          if (base256_allowed) {
            if ((size - 1UL) * 8UL < sizeof(uintmax_t) * 8UL) {
              tmp___11 = (1UL << (size - 1UL) * 8UL) - 1UL;
            } else {
              tmp___11 = (uintmax_t)-1;
            }
            maxval = tmp___11;
          } else {
            if ((size - 1UL) * 3UL < sizeof(uintmax_t) * 8UL) {
              tmp___12 = (1UL << (size - 1UL) * 3UL) - 1UL;
            } else {
              tmp___12 = (uintmax_t)-1;
            }
            maxval = tmp___12;
          }
          {
            tmp___0 = stringify_uintmax_t_backwards(
                maxval,
                maxbuf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                          1UL));
            maxval_string = (char const *)tmp___0;
          }
          if (base256_allowed) {
            if (maxval + 1UL) {
              m = maxval + 1UL;
            } else {
              m = maxval / 2UL + 1UL;
            }
            {
              tmp___1 = stringify_uintmax_t_backwards(
                  m, (minbuf + 1) +
                         ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                          1UL));
              p = tmp___1;
              p--;
              *p = (char)'-';
              minval_string = (char const *)p;
            }
          } else {
            minval_string = "0";
          }
          if (negative) {
            {
              tmp___2 = stringify_uintmax_t_backwards(
                  -value,
                  (valbuf + 1) +
                      ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                       1UL));
              p___0 = tmp___2;
              p___0--;
              *p___0 = (char)'-';
              value_string = (char const *)p___0;
            }
          } else {
            {
              tmp___3 = stringify_uintmax_t_backwards(
                  value,
                  valbuf +
                      ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                       1UL));
              value_string = (char const *)tmp___3;
            }
          }
          if (substitute) {
            {
              tmp___4 = (*substitute)(&negsub);
              sub = tmp___4 & maxval;
              negsub &= (unsigned int)archive_format == 6U;
            }

            {
              tmp___5 = stringify_uintmax_t_backwards(
                  s, (subbuf + 1) +
                         ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                          1UL));
              sub_string = tmp___5;
            }

            {
              tmp___6 =
                  gettext("value %s out of %s range %s..%s; substituting %s");
              error(0, 0, (char const *)tmp___6, value_string, type,
                    minval_string, maxval_string, sub_string);
              to_chars(negsub, s, valsize, (uintmax_t(*)(int *))0, where, size,
                       type);
            }
          } else {
            {
              tmp___7 = gettext("value %s out of %s range %s..%s");
              error(0, 0, (char const *)tmp___7, value_string, type,
                    minval_string, maxval_string);
              exit_status = 2;
            }
          }
        }
      }
    }
    return;
  }
}
static gid_t gid_nobody;
static uintmax_t gid_substitute(int *negative) {
  gid_t r;
  int tmp;
  char *__cil_tmp4;

  {

    r = gid_nobody;
    *negative = r < 0U;
    return ((uintmax_t)r);
  }
}
void gid_to_chars(gid_t v, char *p, size_t s) {
  char *__cil_tmp4;

  {
    {
      to_chars(v < 0U, (uintmax_t)v, sizeof(v), &gid_substitute, p, s, "gid_t");
    }
    return;
  }
}
void major_to_chars(int v, char *p, size_t s) {
  char *__cil_tmp4;

  {
    {
      to_chars(v < 0, (uintmax_t)v, sizeof(v), (uintmax_t(*)(int *))0, p, s,
               "major_t");
    }
    return;
  }
}
void minor_to_chars(int v, char *p, size_t s) {
  char *__cil_tmp4;

  {
    {
      to_chars(v < 0, (uintmax_t)v, sizeof(v), (uintmax_t(*)(int *))0, p, s,
               "minor_t");
    }
    return;
  }
}
void mode_to_chars(mode_t v, char *p, size_t s) {
  int negative;
  uintmax_t u;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  char *__cil_tmp18;

  {
    if (256 >> 3 == 32) {
      if (128 >> 3 == 16) {
        if (64 >> 3 == 8) {
          if ((256 >> 3) >> 3 == 4) {
            if ((128 >> 3) >> 3 == 2) {
              if ((64 >> 3) >> 3 == 1) {
                if ((unsigned int)archive_format != 4U) {
                  if ((unsigned int)archive_format != 3U) {

                  } else {
                    goto _L___10;
                  }
                } else {
                  goto _L___10;
                }
              } else {
                goto _L___10;
              }
            } else {
              goto _L___10;
            }
          } else {
            goto _L___10;
          }
        } else {
          goto _L___10;
        }
      } else {
        goto _L___10;
      }
    } else {
    _L___10: /* CIL Label */
      negative = 0;
      if (v & 2048U) {
        tmp = 2048;
      } else {
        tmp = 0;
      }
      if (v & 1024U) {
        tmp___0 = 1024;
      } else {
        tmp___0 = 0;
      }
      if (v & 512U) {
        tmp___1 = 512;
      } else {
        tmp___1 = 0;
      }
      if (v & 256U) {
        tmp___2 = 256;
      } else {
        tmp___2 = 0;
      }
      if (v & 128U) {
        tmp___3 = 128;
      } else {
        tmp___3 = 0;
      }
      if (v & 64U) {
        tmp___4 = 64;
      } else {
        tmp___4 = 0;
      }
      if (v & (unsigned int)(256 >> 3)) {
        tmp___5 = 32;
      } else {
        tmp___5 = 0;
      }
      if (v & (unsigned int)(128 >> 3)) {
        tmp___6 = 16;
      } else {
        tmp___6 = 0;
      }
      if (v & (unsigned int)(64 >> 3)) {
        tmp___7 = 8;
      } else {
        tmp___7 = 0;
      }
      if (v & (unsigned int)((256 >> 3) >> 3)) {
        tmp___8 = 4;
      } else {
        tmp___8 = 0;
      }
      if (v & (unsigned int)((128 >> 3) >> 3)) {
        tmp___9 = 2;
      } else {
        tmp___9 = 0;
      }
      if (v & (unsigned int)((64 >> 3) >> 3)) {
        tmp___10 = 1;
      } else {
        tmp___10 = 0;
      }
      u = (uintmax_t)(((((((((((tmp | tmp___0) | tmp___1) | tmp___2) |
                             tmp___3) |
                            tmp___4) |
                           tmp___5) |
                          tmp___6) |
                         tmp___7) |
                        tmp___8) |
                       tmp___9) |
                      tmp___10);
    }
    {
      to_chars(negative, u, sizeof(v), (uintmax_t(*)(int *))0, p, s, "mode_t");
    }
    return;
  }
}
void off_to_chars(off_t v, char *p, size_t s) {
  char *__cil_tmp4;

  {
    {
      to_chars(v < 0L, (uintmax_t)v, sizeof(v), (uintmax_t(*)(int *))0, p, s,
               "off_t");
    }
    return;
  }
}
void size_to_chars(size_t v, char *p, size_t s) {
  char *__cil_tmp4;

  {
    { to_chars(0, v, sizeof(v), (uintmax_t(*)(int *))0, p, s, "size_t"); }
    return;
  }
}
void time_to_chars(time_t v, char *p, size_t s) {
  char *__cil_tmp4;

  {
    {
      to_chars(v < 0L, (uintmax_t)v, sizeof(v), (uintmax_t(*)(int *))0, p, s,
               "time_t");
    }
    return;
  }
}
static uid_t uid_nobody;
static uintmax_t uid_substitute(int *negative) {
  uid_t r;
  int tmp;
  char *__cil_tmp4;

  {

    r = uid_nobody;
    *negative = r < 0U;
    return ((uintmax_t)r);
  }
}
void uid_to_chars(uid_t v, char *p, size_t s) {
  char *__cil_tmp4;

  {
    {
      to_chars(v < 0U, (uintmax_t)v, sizeof(v), &uid_substitute, p, s, "uid_t");
    }
    return;
  }
}
void uintmax_to_chars(uintmax_t v, char *p, size_t s) {
  char *__cil_tmp4;

  {
    { to_chars(0, v, sizeof(v), (uintmax_t(*)(int *))0, p, s, "uintmax_t"); }
    return;
  }
}

_Bool file_dumpable_p(struct tar_stat_info *st) {
  int tmp;

  {
    if (dev_null_output) {
      tmp = 0;
    } else {
    }
    return ((_Bool)tmp);
  }
}
void write_eot(void) {
  union block *pointer;
  union block *tmp;
  size_t tmp___0;

  {
    {
      tmp = find_next_block();
      pointer = tmp;
      memset((void *)(pointer->buffer), 0, (size_t)512);
      set_next_block_after(pointer);
      pointer = find_next_block();
      tmp___0 = available_space_after(pointer);
      memset((void *)(pointer->buffer), 0, tmp___0);
      set_next_block_after(pointer);
    }
    return;
  }
}
static void tar_copy_str(char *dst, char const *src, size_t len) {

  {
    {
      *(dst + (len - 1UL)) = (char)0;
      strncpy((char * /* __restrict  */)dst,
              (char const * /* __restrict  */)src, len);
    }
    return;
  }
}
union block *start_private_header(char const *name, size_t size) {
  time_t t;
  union block *header;
  union block *tmp;
  __uid_t tmp___0;
  __gid_t tmp___1;
  char *__cil_tmp8;
  char *__cil_tmp9;

  {
    {
      tmp = find_next_block();
      header = tmp;
      memset((void *)(header->buffer), 0, sizeof(union block));
      tar_copy_str(header->header.name, name, (size_t)100);
      off_to_chars((off_t)size, header->header.size,
                   sizeof(header->header.size));
      time(&t);
      time_to_chars(t, header->header.mtime, sizeof(header->header.mtime));
      mode_to_chars((mode_t)((33152 | (256 >> 3)) | ((256 >> 3) >> 3)),
                    header->header.mode, sizeof(header->header.mode));
      tmp___0 = getuid();
      uid_to_chars(tmp___0, header->header.uid, sizeof(header->header.uid));
      tmp___1 = getgid();
      gid_to_chars(tmp___1, header->header.gid, sizeof(header->header.gid));
      major_to_chars(0, header->header.devmajor,
                     sizeof(header->header.devmajor));
      major_to_chars(0, header->header.devminor,
                     sizeof(header->header.devminor));
      strncpy((char * /* __restrict  */)(header->header.magic),
              (char const * /* __restrict  */) "ustar", (size_t)6);
      strncpy((char * /* __restrict  */)(header->header.version),
              (char const * /* __restrict  */) "00", (size_t)2);
    }
    return (header);
  }
}
static union block *write_short_name(struct tar_stat_info *st) {
  union block *header;
  union block *tmp;

  {
    {
      tmp = find_next_block();
      header = tmp;
      memset((void *)(header->buffer), 0, sizeof(union block));
      tar_copy_str(header->header.name, (char const *)st->file_name,
                   (size_t)100);
    }
    return (header);
  }
}
static void write_gnu_long_link(struct tar_stat_info *st, char const *p,
                                char type) {
  size_t size;
  size_t tmp;
  size_t bufsize;
  union block *header;
  char *__cil_tmp8;
  char *__cil_tmp9;

  {
    {
      tmp = strlen(p);
      size = tmp + 1UL;
      header = start_private_header("././@LongLink", size);
      strcpy((char * /* __restrict  */)(header->header.magic),
             (char const * /* __restrict  */) "ustar  ");
      header->header.typeflag = type;
      finish_header(st, header, (off_t)-1);
      header = find_next_block();
      bufsize = available_space_after(header);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(bufsize < size)) {
          goto while_break;
        }
        {
          memcpy((void * /* __restrict  */)(header->buffer),
                 (void const * /* __restrict  */)p, bufsize);
          p += bufsize;
          size -= bufsize;
          set_next_block_after(header + (bufsize - 1UL) / 512UL);
          header = find_next_block();
          bufsize = available_space_after(header);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      memcpy((void * /* __restrict  */)(header->buffer),
             (void const * /* __restrict  */)p, size);
      memset((void *)(header->buffer + size), 0, bufsize - size);
      set_next_block_after(header + (size - 1UL) / 512UL);
    }
    return;
  }
}
static size_t split_long_name(char const *name, size_t length) {
  size_t i;

  {
    if (length > 155UL) {
      length = (size_t)157;
    }
    i = length - 1UL;
    {

    while_break: /* CIL Label */
        ;
    }
    return (i);
  }
}
static union block *write_ustar_long_name(char const *name) {
  size_t length;
  size_t tmp;
  size_t i;
  union block *header;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *__cil_tmp10;
  char *__cil_tmp11;
  char *__cil_tmp12;

  {
    {
      tmp = strlen(name);
      length = tmp;
    }
    if (length > 256UL) {
      {
        tmp___0 = quotearg_colon(name);
        tmp___1 = gettext("%s: file name is too long (max %d); not dumped");
        error(0, 0, (char const *)tmp___1, tmp___0, 256);
        exit_status = 2;
      }
      return ((union block *)((void *)0));
    }
    { i = split_long_name(name, length); }

    {
      header = find_next_block();
      memset((void *)(header->buffer), 0, sizeof(header->buffer));
      memcpy((void * /* __restrict  */)(header->header.prefix),
             (void const * /* __restrict  */)name, i);
      memcpy((void * /* __restrict  */)(header->header.name),
             (void const * /* __restrict  */)((name + i) + 1),
             (length - i) - 1UL);
    }
    return (header);
  }
}
static void write_long_link(struct tar_stat_info *st) {
  char *tmp;
  char *tmp___0;
  char *__cil_tmp4;
  char *__cil_tmp5;

  {
    {
      if ((unsigned int)archive_format == 4U) {
        goto case_4;
      }
      if ((unsigned int)archive_format == 1U) {
        goto case_1;
      }

      if ((unsigned int)archive_format == 5U) {
        goto case_1;
      }
      if ((unsigned int)archive_format == 2U) {
        goto case_2;
      }

      goto switch_default;
    case_4: { /* CIL Label */
      xheader_store("linkpath", (struct tar_stat_info const *)st, (void *)0);
    }
      goto switch_break;
    case_1:   /* CIL Label */
    case_3:   /* CIL Label */
    case_5: { /* CIL Label */
      tmp = quotearg_colon((char const *)st->link_name);
      tmp___0 = gettext("%s: link name is too long; not dumped");
      error(0, 0, (char const *)tmp___0, tmp);
      exit_status = 2;
    }
      goto switch_break;
    case_2:   /* CIL Label */
    case_6: { /* CIL Label */
      write_gnu_long_link(st, (char const *)st->link_name, (char)'K');
    }
      goto switch_break;
    switch_default: { /* CIL Label */
      abort();
    }
    switch_break: /* CIL Label */
        ;
    }
    return;
  }
}
static union block *write_long_name(struct tar_stat_info *st) {
  char *tmp;
  char *tmp___0;
  size_t tmp___1;
  union block *tmp___2;
  union block *tmp___3;
  char *__cil_tmp7;
  char *__cil_tmp8;

  {
    {
      if ((unsigned int)archive_format == 4U) {
        goto case_4;
      }
      if ((unsigned int)archive_format == 1U) {
        goto case_1;
      }
      if ((unsigned int)archive_format == 3U) {
        goto case_3;
      }
      if ((unsigned int)archive_format == 5U) {
        goto case_3;
      }
      if ((unsigned int)archive_format == 2U) {
        goto case_2;
      }
      if ((unsigned int)archive_format == 6U) {
        goto case_2;
      }
      goto switch_default;
    case_4: { /* CIL Label */
      xheader_store("path", (struct tar_stat_info const *)st, (void *)0);
    }
      goto switch_break;
    case_1: { /* CIL Label */
      tmp___1 = strlen((char const *)st->file_name);
    }
      if (tmp___1 > 99UL) {
        {
          tmp = quotearg_colon((char const *)st->file_name);
          tmp___0 = gettext("%s: file name is too long (max %d); not dumped");
          error(0, 0, (char const *)tmp___0, tmp, 99);
          exit_status = 2;
        }
        return ((union block *)((void *)0));
      }
      goto switch_break;
    case_3:   /* CIL Label */
    case_5: { /* CIL Label */
      tmp___2 = write_ustar_long_name((char const *)st->file_name);
    }
      return (tmp___2);
    case_2:   /* CIL Label */
    case_6: { /* CIL Label */
      write_gnu_long_link(st, (char const *)st->file_name, (char)'L');
    }
      goto switch_break;
    switch_default: { /* CIL Label */
      abort();
    }
    switch_break: /* CIL Label */
        ;
    }
    { tmp___3 = write_short_name(st); }
    return (tmp___3);
  }
}
static union block *write_extended(struct tar_stat_info *st,
                                   union block *old_header) {
  union block *header;
  union block hp;
  char *p;
  void *__cil_tmp6;
  void *__cil_tmp7;
  void *__cil_tmp8;
  void *__cil_tmp9;
  void *__cil_tmp10;
  void *__cil_tmp11;
  void *__cil_tmp12;
  void *__cil_tmp13;
  void *__cil_tmp14;
  void *__cil_tmp15;
  void *__cil_tmp16;
  void *__cil_tmp17;
  void *__cil_tmp18;
  void *__cil_tmp19;
  void *__cil_tmp20;
  void *__cil_tmp21;
  void *__cil_tmp22;
  void *__cil_tmp23;
  void *__cil_tmp24;
  void *__cil_tmp25;
  void *__cil_tmp26;
  void *__cil_tmp27;
  void *__cil_tmp28;
  void *__cil_tmp29;
  void *__cil_tmp30;
  void *__cil_tmp31;
  void *__cil_tmp32;
  void *__cil_tmp33;
  void *__cil_tmp34;
  void *__cil_tmp35;
  void *__cil_tmp36;
  void *__cil_tmp37;
  void *__cil_tmp38;
  void *__cil_tmp39;
  void *__cil_tmp40;
  void *__cil_tmp41;
  void *__cil_tmp42;
  void *__cil_tmp43;
  void *__cil_tmp44;
  int __cil_tmp45;
  void *__cil_tmp46;
  void *__cil_tmp47;
  void *__cil_tmp48;
  void *__cil_tmp49;
  int __cil_tmp50;
  void *__cil_tmp51;
  void *__cil_tmp52;
  void *__cil_tmp53;
  void *__cil_tmp54;
  void *__cil_tmp55;
  void *__cil_tmp56;
  int __cil_tmp57;
  void *__cil_tmp58;
  void *__cil_tmp59;
  void *__cil_tmp60;
  void *__cil_tmp61;
  void *__cil_tmp62;
  void *__cil_tmp63;
  void *__cil_tmp64;
  void *__cil_tmp65;
  void *__cil_tmp66;
  int __cil_tmp67;
  void *__cil_tmp68;
  void *__cil_tmp69;

  {

    {
      xheader_finish(&extended_header);
      memcpy((void * /* __restrict  */)(hp.buffer),
             (void const * /* __restrict  */)old_header, sizeof(hp));
      p = xheader_xhdr_name(st);
      xheader_write((char)'x', p, &extended_header);
      free((void *)p);
      header = find_next_block();
      memcpy((void * /* __restrict  */)header,
             (void const * /* __restrict  */)(&hp.buffer), sizeof(hp.buffer));
    }
    return (header);
  }
}
static union block *write_header_name(struct tar_stat_info *st) {
  union block *tmp;
  union block *tmp___0;
  union block *tmp___1;
  size_t tmp___2;
  _Bool tmp___3;
  char *__cil_tmp7;

  {
    if ((unsigned int)archive_format == 4U) {
      {
        tmp___3 = string_ascii_p((char const *)st->file_name);
      }
      if (tmp___3) {
        goto _L;
      } else {
        {
          xheader_store("path", (struct tar_stat_info const *)st, (void *)0);
          tmp = write_short_name(st);
        }
        return (tmp);
      }
    } else {
    _L: { tmp___2 = strlen((char const *)st->file_name); }
      if (100UL < tmp___2) {
        {
          tmp___0 = write_long_name(st);
        }
        return (tmp___0);
      } else {
        { tmp___1 = write_short_name(st); }
        return (tmp___1);
      }
    }
  }
}
union block *start_header(struct tar_stat_info *st) {
  union block *header;
  mode_t tmp;
  size_t tmp___0;
  _Bool tmp___1;
  size_t tmp___2;
  _Bool tmp___3;
  int tmp___4;
  char *__cil_tmp9;
  char *__cil_tmp10;
  char *__cil_tmp11;
  char *__cil_tmp12;
  char *__cil_tmp13;
  char *__cil_tmp14;
  char *__cil_tmp15;
  char *__cil_tmp16;
  char *__cil_tmp17;
  char *__cil_tmp18;
  char *__cil_tmp19;
  char *__cil_tmp20;
  char *__cil_tmp21;
  char *__cil_tmp22;

  {
    { header = write_header_name(st); }
    if (!header) {
      return ((union block *)((void *)0));
    }

    if ((unsigned int)archive_format == 1U) {
      {
        mode_to_chars(
            st->stat.st_mode &
                (unsigned int)(3584 |
                               (((64 | (64 >> 3)) | ((64 >> 3) >> 3)) |
                                (((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                 ((256 | (256 >> 3)) | ((256 >> 3) >> 3))))),
            header->header.mode, sizeof(header->header.mode));
      }
    } else {
      if ((unsigned int)archive_format == 3U) {
        {
          mode_to_chars(
              st->stat.st_mode &
                  (unsigned int)(3584 |
                                 (((64 | (64 >> 3)) | ((64 >> 3) >> 3)) |
                                  (((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                   ((256 | (256 >> 3)) | ((256 >> 3) >> 3))))),
              header->header.mode, sizeof(header->header.mode));
        }
      } else {
        {
          mode_to_chars(st->stat.st_mode, header->header.mode,
                        sizeof(header->header.mode));
        }
      }
    }
    if (st->stat.st_uid > 2097151U) {
      if ((unsigned int)archive_format == 4U) {
        {
          xheader_store("uid", (struct tar_stat_info const *)st, (void *)0);
        }
      } else {
        {
          uid_to_chars(st->stat.st_uid, header->header.uid,
                       sizeof(header->header.uid));
        }
      }
    } else {
      {
        uid_to_chars(st->stat.st_uid, header->header.uid,
                     sizeof(header->header.uid));
      }
    }
    if (st->stat.st_gid > 2097151U) {
      if ((unsigned int)archive_format == 4U) {
        {
          xheader_store("gid", (struct tar_stat_info const *)st, (void *)0);
        }
      } else {
        {
          gid_to_chars(st->stat.st_gid, header->header.gid,
                       sizeof(header->header.gid));
        }
      }
    } else {
      {
        gid_to_chars(st->stat.st_gid, header->header.gid,
                     sizeof(header->header.gid));
      }
    }
    if (st->stat.st_size > 2147483647L) {
      if ((unsigned int)archive_format == 4U) {
        {
          xheader_store("size", (struct tar_stat_info const *)st, (void *)0);
        }
      } else {
        {
          off_to_chars(st->stat.st_size, header->header.size,
                       sizeof(header->header.size));
        }
      }
    } else {
      {
        off_to_chars(st->stat.st_size, header->header.size,
                     sizeof(header->header.size));
      }
    }
    {
      time_to_chars(st->stat.st_mtim.tv_sec, header->header.mtime,
                    sizeof(header->header.mtime));
    }
    if ((st->stat.st_mode & 61440U) == 8192U) {
      goto _L___3;
    } else {
      if ((st->stat.st_mode & 61440U) == 24576U) {
      _L___3: { /* CIL Label */
        st->devmajor = gnu_dev_major((unsigned long long)st->stat.st_rdev);
        st->devminor = gnu_dev_minor((unsigned long long)st->stat.st_rdev);
      }
        if (st->devmajor > 2097151U) {
          if ((unsigned int)archive_format == 4U) {
            {
              xheader_store("devmajor", (struct tar_stat_info const *)st,
                            (void *)0);
            }
          } else {
            {
              major_to_chars((int)st->devmajor, header->header.devmajor,
                             sizeof(header->header.devmajor));
            }
          }
        } else {
          {
            major_to_chars((int)st->devmajor, header->header.devmajor,
                           sizeof(header->header.devmajor));
          }
        }
        if (st->devminor > 2097151U) {
          if ((unsigned int)archive_format == 4U) {
            {
              xheader_store("devminor", (struct tar_stat_info const *)st,
                            (void *)0);
            }
          } else {
            {
              major_to_chars((int)st->devminor, header->header.devminor,
                             sizeof(header->header.devminor));
            }
          }
        } else {
          {
            major_to_chars((int)st->devminor, header->header.devminor,
                           sizeof(header->header.devminor));
          }
        }
      } else {
        {
          major_to_chars(0, header->header.devmajor,
                         sizeof(header->header.devmajor));
          minor_to_chars(0, header->header.devminor,
                         sizeof(header->header.devminor));
        }
      }
    }
    if ((unsigned int)archive_format == 4U) {
      {
        xheader_store("atime", (struct tar_stat_info const *)st, (void *)0);
        xheader_store("ctime", (struct tar_stat_info const *)st, (void *)0);
      }
    } else {
      if (incremental_option) {
        if ((unsigned int)archive_format == 2U) {
          {
            time_to_chars(st->stat.st_atim.tv_sec, header->oldgnu_header.atime,
                          sizeof(header->oldgnu_header.atime));
            time_to_chars(st->stat.st_ctim.tv_sec, header->oldgnu_header.ctime,
                          sizeof(header->oldgnu_header.ctime));
          }
        } else {
          if ((unsigned int)archive_format == 6U) {
            {
              time_to_chars(st->stat.st_atim.tv_sec,
                            header->oldgnu_header.atime,
                            sizeof(header->oldgnu_header.atime));
              time_to_chars(st->stat.st_ctim.tv_sec,
                            header->oldgnu_header.ctime,
                            sizeof(header->oldgnu_header.ctime));
            }
          }
        }
      }
    }
    if ((unsigned int)archive_format == 1U) {
      tmp___4 = '\000';
    } else {
      tmp___4 = '0';
    }
    header->header.typeflag = (char)tmp___4;
    {
      if ((unsigned int)archive_format == 1U) {
        goto case_1;
      }
      if ((unsigned int)archive_format == 2U) {
        goto case_2;
      }
      if ((unsigned int)archive_format == 6U) {
        goto case_2;
      }
      if ((unsigned int)archive_format == 4U) {
        goto case_4;
      }
      if ((unsigned int)archive_format == 3U) {
        goto case_4;
      }
      goto switch_default;
    case_1: /* CIL Label */
      goto switch_break;
    case_2:   /* CIL Label */
    case_6: { /* CIL Label */
      strcpy((char * /* __restrict  */)(header->header.magic),
             (char const * /* __restrict  */) "ustar  ");
    }
      goto switch_break;
    case_4:   /* CIL Label */
    case_3: { /* CIL Label */
      strncpy((char * /* __restrict  */)(header->header.magic),
              (char const * /* __restrict  */) "ustar", (size_t)6);
      strncpy((char * /* __restrict  */)(header->header.version),
              (char const * /* __restrict  */) "00", (size_t)2);
    }
      goto switch_break;
    switch_default: { /* CIL Label */
      abort();
    }
    switch_break: /* CIL Label */
        ;
    }

    return (header);
  }
}
void simple_finish_header(union block *header) {
  size_t i;
  int sum;
  char *p;
  char *tmp;
  size_t tmp___0;
  char *__cil_tmp7;

  {
    {
      memcpy((void * /* __restrict  */)(header->header.chksum),
             (void const * /* __restrict  */) "        ",
             sizeof(header->header.chksum));
      sum = 0;
      p = header->buffer;
      i = sizeof(*header);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        tmp___0 = i;
        i--;
        if (!(tmp___0 != 0UL)) {
          goto while_break;
        }
        tmp = p;
        p++;
        sum += 255 & (int)*tmp;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      uintmax_to_chars((uintmax_t)sum, header->header.chksum, (size_t)7);
      set_next_block_after(header);
    }
    return;
  }
}
void finish_header(struct tar_stat_info *st, union block *header,
                   off_t block_ordinal) {

  {
    if (verbose_option) {
      if ((int)header->header.typeflag != 75) {
      }
    }
    {
      header = write_extended(st, header);
      simple_finish_header(header);
    }
    return;
  }
}
void pad_archive(off_t size_left) {
  union block *blk;

  {
    {

    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static enum dump_status dump_regular_file(int fd, struct tar_stat_info *st) {
  off_t size_left;
  off_t block_ordinal;
  union block *blk;
  size_t bufsize;
  size_t count;
  size_t tmp;
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  void *__cil_tmp13;

  {
    {
      size_left = st->stat.st_size;
      block_ordinal = current_block_ordinal();
      blk = start_header(st);
    }
    if (!blk) {
      return ((enum dump_status)2);
    }
    if ((unsigned int)archive_format != 1U) {
    }
    { finish_header(st, blk, block_ordinal); }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(size_left > 0L)) {
          goto while_break;
        }

        {
          blk = find_next_block();
          bufsize = available_space_after(blk);
        }
        if ((size_t)size_left < bufsize) {
          bufsize = (size_t)size_left;
          count = bufsize % 512UL;
          if (count) {
            {
              memset((void *)(blk->buffer + size_left), 0, 512UL - count);
            }
          }
        }
        if (fd < 0) {
          count = bufsize;
        } else {
          {
            tmp = safe_read(fd, (void *)(blk->buffer), bufsize);
            count = tmp;
          }
        }
        if (count == 0xffffffffffffffffUL) {
          {
            read_diag_details((char const *)st->orig_file_name,
                              st->stat.st_size - size_left, bufsize);
            pad_archive(size_left);
          }
          return ((enum dump_status)1);
        }
        {
          size_left = (off_t)((size_t)size_left - count);
          set_next_block_after(blk + (bufsize - 1UL) / 512UL);
        }
        if (count != bufsize) {
          {
            memset((void *)(blk->buffer + count), 0, bufsize - count);
            tmp___0 = stringify_uintmax_t_backwards(
                (uintmax_t)size_left,
                buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                       1UL));
            tmp___1 = quotearg_colon((char const *)st->orig_file_name);
            tmp___2 =
                ngettext("%s: File shrank by %s byte; padding with zeros",
                         "%s: File shrank by %s bytes; padding with zeros",
                         (unsigned long)size_left);
            error(0, 0, (char const *)tmp___2, tmp___1, tmp___0);
          }

          { pad_archive(size_left); }
          return ((enum dump_status)1);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return ((enum dump_status)0);
  }
}
static void dump_regular_finish(int fd, struct tar_stat_info *st,
                                time_t original_ctime) {
  struct stat final_stat;
  char *tmp;
  char *tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  void *__cil_tmp10;
  char *__cil_tmp11;

  {
    if (fd >= 0) {
      {
        tmp___1 = fstat(fd, &final_stat);
      }

      { tmp___2 = close(fd); }
      if (tmp___2 != 0) {
        {
          close_diag((char const *)st->orig_file_name);
        }
      }
    }

    return;
  }
}
static void dump_dir0(char *directory, struct tar_stat_info *st, int top_level,
                      dev_t parent_device) {
  dev_t our_device;
  union block *blk;
  off_t block_ordinal;
  off_t tmp;
  off_t size_left;
  off_t totsize;
  size_t bufsize;
  ssize_t count;
  char const *buffer___2;
  char const *p_buffer;
  size_t size;
  size_t tmp___0;
  _Bool tmp___1;
  char *tmp___2;
  char *tmp___3;
  char const *entry;
  size_t entry_len;
  char *name_buf;
  char *tmp___4;
  size_t name_size;
  size_t tmp___5;
  size_t name_len;
  void *tmp___6;
  _Bool tmp___7;
  char *__cil_tmp29;

  {
    {
      our_device = st->stat.st_dev;
      tmp___1 = is_avoided_name((char const *)st->orig_file_name);
    }
    if (!tmp___1) {
      {
        blk = (union block *)((void *)0);
        tmp = current_block_ordinal();
        block_ordinal = tmp;
        st->stat.st_size = (__off_t)0;
        blk = start_header(st);
      }
      if (!blk) {
        return;
      }
      if (incremental_option) {
        blk->header.typeflag = (char)'D';
      } else {
        blk->header.typeflag = (char)'5';
      }
      if (!incremental_option) {
        {
          finish_header(st, blk, block_ordinal);
        }
      } else {
        if (gnu_list_name->dir_contents) {
          {
            block_ordinal = current_block_ordinal();
            buffer___2 = gnu_list_name->dir_contents;
            totsize = (off_t)0;
          }
          if (buffer___2) {
            p_buffer = buffer___2;
            {
              while (1) {
              while_continue: /* CIL Label */
                  ;
                if (!*p_buffer) {
                  goto while_break;
                }
                {
                  tmp___0 = strlen(p_buffer);
                  size = tmp___0 + 1UL;
                  totsize = (off_t)((size_t)totsize + size);
                  p_buffer += size;
                }
              }
            while_break: /* CIL Label */
                ;
            }
          }
          {
            totsize++;
            off_to_chars(totsize, blk->header.size, sizeof(blk->header.size));
            finish_header(st, blk, block_ordinal);
            p_buffer = buffer___2;
            size_left = totsize;
          }
          {
            while (1) {
            while_continue___0: /* CIL Label */
                ;
              if (!(size_left > 0L)) {
                goto while_break___0;
              }

              {
                blk = find_next_block();
                bufsize = available_space_after(blk);
              }
              if ((size_t)size_left < bufsize) {
                bufsize = (size_t)size_left;
                count = (ssize_t)(bufsize % 512UL);
                if (count) {
                  {
                    memset((void *)(blk->buffer + size_left), 0,
                           (size_t)(512L - count));
                  }
                }
              }
              {
                memcpy((void * /* __restrict  */)(blk->buffer),
                       (void const * /* __restrict  */)p_buffer, bufsize);
                size_left = (off_t)((size_t)size_left - bufsize);
                p_buffer += bufsize;
                set_next_block_after(blk + (bufsize - 1UL) / 512UL);
              }
            }
          while_break___0: /* CIL Label */
              ;
          }

          return;
        }
      }
    }

    if (one_file_system_option) {
      if (!top_level) {
        if (parent_device != st->stat.st_dev) {

          return;
        }
      }
    }
    {
      tmp___4 = strdup((char const *)st->orig_file_name);
      name_buf = tmp___4;
      tmp___5 = strlen((char const *)name_buf);
      name_size = tmp___5;
      name_len = name_size;
      entry = (char const *)directory;
    }
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        { entry_len = strlen(entry); }
        if (!(entry_len != 0UL)) {
          goto while_break___1;
        }
        if (name_size < name_len + entry_len) {
          {
            name_size = name_len + entry_len;
            tmp___6 = xrealloc((void *)name_buf, name_size + 1UL);
            name_buf = (char *)tmp___6;
          }
        }
        {
          strcpy((char * /* __restrict  */)(name_buf + name_len),
                 (char const * /* __restrict  */)entry);
          tmp___7 = excluded_name((char const *)name_buf);
        }
        if (!tmp___7) {
          {
            dump_file(name_buf, 0, our_device);
          }
        }
        entry += entry_len + 1UL;
      }
    while_break___1: /* CIL Label */
        ;
    }
    { free((void *)name_buf); }
    return;
  }
}
static void ensure_slash(char **pstr) {
  size_t len;
  size_t tmp;
  void *tmp___0;
  size_t tmp___1;

  {
    {
      tmp = strlen((char const *)*pstr);
      len = tmp;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (len >= 1UL) {
          if (!((int)*(*pstr + (len - 1UL)) == 47)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        len--;
      }
    while_break: /* CIL Label */
        ;
    }
    if (!((int)*(*pstr + len) == 47)) {
      {
        tmp___0 = xrealloc((void *)*pstr, len + 2UL);
        *pstr = (char *)tmp___0;
      }
    }
    tmp___1 = len;
    len++;
    *(*pstr + tmp___1) = (char)'/';
    *(*pstr + len) = (char)'\000';
    return;
  }
}
static _Bool dump_dir(struct tar_stat_info *st, int top_level,
                      dev_t parent_device) {
  char *directory;

  {
    { directory = savedir((char const *)st->orig_file_name); }
    if (!directory) {
      {
        savedir_diag((char const *)st->orig_file_name);
      }
      return ((_Bool)0);
    }
    {
      ensure_slash(&st->orig_file_name);
      ensure_slash(&st->file_name);
      dump_dir0(directory, st, top_level, parent_device);
      free((void *)directory);
    }
    return ((_Bool)1);
  }
}

static void unknown_file_error(char *p) {
  char *tmp;
  char *tmp___0;
  char *__cil_tmp4;

  {
    {
      tmp = quotearg_colon((char const *)p);
      tmp___0 = gettext("%s: Unknown file type; file ignored");
      error(0, 0, (char const *)tmp___0, tmp);
    }

    return;
  }
}
static Hash_table *link_table;
static _Bool dump_hard_link(struct tar_stat_info *st) {
  struct link lp;
  struct link *duplicate;
  off_t block_ordinal;
  union block *blk;
  char const *link_name;
  char *tmp;
  size_t tmp___0;
  int tmp___1;
  void *tmp___2;
  void *__cil_tmp11;

  {
    if (link_table) {
      if (st->stat.st_nlink > 1UL) {
        {
          lp.ino = st->stat.st_ino;
          lp.dev = st->stat.st_dev;
          tmp___2 =
              hash_lookup((Hash_table const *)link_table, (void const *)(&lp));
          duplicate = (struct link *)tmp___2;
        }
        if (duplicate) {
          {
            tmp = safer_name_suffix((char const *)(duplicate->name), (_Bool)1);
            link_name = (char const *)tmp;
            (duplicate->nlink)--;
            block_ordinal = current_block_ordinal();
            assign_string(&st->link_name, link_name);
            tmp___0 = strlen(link_name);
          }
          if (100UL < tmp___0) {
            {
              write_long_link(st);
            }
          }
          {
            st->stat.st_size = (__off_t)0;
            blk = start_header(st);
          }
          if (!blk) {
            return ((_Bool)1);
          }
          {
            tar_copy_str(blk->header.linkname, link_name, (size_t)100);
            blk->header.typeflag = (char)'1';
            finish_header(st, blk, block_ordinal);
          }

          return ((_Bool)1);
        }
      }
    }
    return ((_Bool)0);
  }
}
static void file_count_links(struct tar_stat_info *st) {
  struct link *duplicate;
  struct link *lp;
  size_t tmp;
  void *tmp___0;
  void *tmp___1;

  { return; }
}
void check_links(void) {
  struct link *lp;
  void *tmp;
  void *tmp___0;
  char *tmp___1;
  char *__cil_tmp5;

  {
    if (!link_table) {
      return;
    }
    {
      tmp = hash_get_first((Hash_table const *)link_table);
      lp = (struct link *)tmp;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!lp) {
          goto while_break;
        }

        {
          tmp___0 =
              hash_get_next((Hash_table const *)link_table, (void const *)lp);
          lp = (struct link *)tmp___0;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static void dump_file0(struct tar_stat_info *st, char *p, int top_level,
                       dev_t parent_device) {
  union block *header;
  char type;
  time_t original_ctime;
  struct utimbuf restore_times;
  off_t block_ordinal;
  int tmp;
  char *tmp___0;
  int tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  _Bool tmp___6;
  _Bool tmp___7;
  int fd;
  enum dump_status status;
  char *tmp___8;
  char *tmp___9;
  int *tmp___10;
  _Bool tmp___11;
  _Bool tmp___12;
  char *buffer___2;
  int size;
  size_t linklen;
  void *tmp___13;
  ssize_t tmp___14;
  int tmp___15;
  char *tmp___16;
  char *tmp___17;
  _Bool tmp___20;
  unsigned int tmp___21;
  unsigned int tmp___22;
  int tmp___23;
  char *__cil_tmp38;
  char *__cil_tmp39;
  char *__cil_tmp40;
  char *__cil_tmp41;
  char *__cil_tmp42;

  {
    block_ordinal = (off_t)-1;

    {
      assign_string(&st->orig_file_name, (char const *)p);
      tmp___0 = safer_name_suffix((char const *)p, (_Bool)0);
      assign_string(&st->file_name, (char const *)tmp___0);
      tmp___1 = deref_stat(dereference_option, (char const *)p, &st->stat);
    }
    if (tmp___1 != 0) {
      {
        stat_diag((char const *)p);
      }
      return;
    }
    {
      st->archive_file_size = st->stat.st_size;
      sys_stat_nanoseconds(st);
      original_ctime = st->stat.st_ctim.tv_sec;
      restore_times.actime = st->stat.st_atim.tv_sec;
      restore_times.modtime = st->stat.st_mtim.tv_sec;
    }

    { tmp___6 = sys_file_is_archive(st); }
    if (tmp___6) {
      {
        tmp___4 = quotearg_colon((char const *)p);
        tmp___5 = gettext("%s: file is the archive; not dumped");
        error(0, 0, (char const *)tmp___5, tmp___4);
      }
      return;
    }
    if ((st->stat.st_mode & 61440U) == 16384U) {
      {
        dump_dir(st, top_level, parent_device);
      }

      return;
    } else {
      { tmp___20 = is_avoided_name((char const *)p); }
      if (tmp___20) {
        return;
      } else {
        { tmp___7 = dump_hard_link(st); }
        if (tmp___7) {
          return;
        }
        if ((st->stat.st_mode & 61440U) == 32768U) {
          goto _L___6;
        } else {
          if (0) {
          _L___6: { /* CIL Label */
            tmp___11 = file_dumpable_p(st);
          }
            if (tmp___11) {
              {
                fd = open((char const *)st->orig_file_name, 0);
              }
              if (fd < 0) {
                if (!top_level) {
                  {
                    tmp___10 = __errno_location();
                  }
                  if (*tmp___10 == 2) {
                    {
                      tmp___8 =
                          quotearg_colon((char const *)st->orig_file_name);
                      tmp___9 = gettext("%s: File removed before we read it");
                      error(0, 0, (char const *)tmp___9, tmp___8);
                    }
                  } else {
                    { open_diag((char const *)st->orig_file_name); }
                  }
                } else {
                  { open_diag((char const *)st->orig_file_name); }
                }
                return;
              }
            } else {
              fd = -1;
            }
            if (sparse_option) {
              {
                tmp___12 = sparse_file_p(st);
              }
              if (tmp___12) {
                {
                  status = sparse_dump_file(fd, st);
                }
                if ((unsigned int)status == 3U) {
                  {
                    status = dump_regular_file(fd, st);
                  }
                }
              } else {
                { status = dump_regular_file(fd, st); }
              }
            } else {
              { status = dump_regular_file(fd, st); }
            }
            {
              if ((unsigned int)status == 0U) {
                goto case_0;
              }
              if ((unsigned int)status == 1U) {
                goto case_1;
              }
              if ((unsigned int)status == 2U) {
                goto case_2;
              }
              if ((unsigned int)status == 3U) {
                goto case_3;
              }
              goto switch_break;
            case_0: /* CIL Label */

            {
              dump_regular_finish(fd, st, original_ctime);
            }
              goto switch_break;
            case_1: /* CIL Label */

            {
              close(fd);
            }
              goto switch_break;
            case_2: { /* CIL Label */
              close(fd);
            }
              return;
            case_3: { /* CIL Label */
              abort();
            }
            switch_break: /* CIL Label */
                ;
            }

            { file_count_links(st); }
            return;
          } else {
            if ((st->stat.st_mode & 61440U) == 40960U) {
              linklen = (size_t)st->stat.st_size;

              {
                tmp___13 = __builtin_alloca(linklen + 1UL);
                buffer___2 = (char *)tmp___13;
                tmp___14 = readlink((char const * /* __restrict  */)p,
                                    (char * /* __restrict  */)buffer___2,
                                    linklen + 1UL);
                size = (int)tmp___14;
              }
              if (size < 0) {
                {
                  readlink_diag((char const *)p);
                }
                return;
              }
              {
                *(buffer___2 + size) = (char)'\000';
                assign_string(&st->link_name, (char const *)buffer___2);
              }
              if (size > 100) {
                {
                  write_long_link(st);
                }
              }
              {
                block_ordinal = current_block_ordinal();
                st->stat.st_size = (__off_t)0;
                header = start_header(st);
              }
              if (!header) {
                return;
              }
              {
                tar_copy_str(header->header.linkname, (char const *)buffer___2,
                             (size_t)100);
                header->header.typeflag = (char)'2';
                finish_header(st, header, block_ordinal);
              }

              { file_count_links(st); }
              return;
            } else {
              if ((st->stat.st_mode & 61440U) == 8192U) {
                type = (char)'3';
              } else {
                if ((st->stat.st_mode & 61440U) == 24576U) {
                  type = (char)'4';
                } else {
                  if ((st->stat.st_mode & 61440U) == 4096U) {
                    type = (char)'6';
                  } else {
                    if ((st->stat.st_mode & 61440U) == 49152U) {
                      {
                        tmp___16 = quotearg_colon((char const *)p);
                        tmp___17 = gettext("%s: socket ignored");
                        error(0, 0, (char const *)tmp___17, tmp___16);
                      }
                      return;
                    } else {
                      { unknown_file_error(p); }
                      return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    {
      block_ordinal = current_block_ordinal();
      st->stat.st_size = (__off_t)0;
      header = start_header(st);
    }
    if (!header) {
      return;
    }
    header->header.typeflag = type;
    if ((int)type != 54) {
      {
        tmp___21 = gnu_dev_major((unsigned long long)st->stat.st_rdev);
        major_to_chars((int)tmp___21, header->header.devmajor,
                       sizeof(header->header.devmajor));
        tmp___22 = gnu_dev_minor((unsigned long long)st->stat.st_rdev);
        minor_to_chars((int)tmp___22, header->header.devminor,
                       sizeof(header->header.devminor));
      }
    }
    { finish_header(st, header, block_ordinal); }

    return;
  }
}
void dump_file(char *p, int top_level, dev_t parent_device) {
  struct tar_stat_info st;
  void *__cil_tmp5;

  {
    {
      tar_stat_init(&st);
      dump_file0(&st, p, top_level, parent_device);
      tar_stat_destroy(&st);
    }
    return;
  }
}
/* #pragma merger("0","003.delete.o.i","") */
_Bool ignore_zeros_option;
uintmax_t occurrence_option;
void delete_archive_members(void);
size_t recent_long_name_blocks;
size_t recent_long_link_blocks;
void truncate_warn(char const *name);
void name_gather(void);
void names_notfound(void);
struct name *name_scan(char const *path);
void xheader_decode(struct tar_stat_info *st);
int sys_truncate(int fd);
static union block *new_record;
static int new_blocks;
static _Bool acting_as_filter;
union block *recent_long_name;
union block *recent_long_link;
static off_t records_skipped;

/* #pragma merger("0","004.extract.o.i","") */
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file,
                                         struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) chmod)(char const *__file, __mode_t __mode);
extern __attribute__((__nothrow__))
__mode_t(__attribute__((__leaf__)) umask)(__mode_t __mask);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) mkdir)(char const *__path, __mode_t __mode);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) mknod)(char const *__path, __mode_t __mode,
                                      __dev_t __dev);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) mkfifo)(char const *__path, __mode_t __mode);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) access)(char const *__name, int __type);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) chown)(char const *__file, __uid_t __owner,
                                      __gid_t __group);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) lchown)(char const *__file, __uid_t __owner,
                                       __gid_t __group);
extern __attribute__((__nothrow__))
__uid_t(__attribute__((__leaf__)) geteuid)(void);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) link)(char const *__from, char const *__to);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__)) symlink)(char const *__from,
                                                          char const *__to);
char *base_name(char const *name);
void (*xalloc_fail_func)(void);
size_t full_write(int fd, void const *buf, size_t count);
_Bool absolute_names_option;
enum old_files old_files_option;
_Bool recursive_unlink_option;
int same_owner_option;
int same_permissions_option;
size_t strip_path_elements;
_Bool touch_option;
_Bool we_are_root;
void extr_init(void);
void extract_archive(void);
void extract_finish(void);
void gnu_restore(char const *directory_name);
char const *tartime(time_t t);
void print_for_mkdir(char *pathname, int length, mode_t mode);
void skip_file(off_t size);
void extract_mangle(void);
int remove_any_file(char const *path, enum remove_option option);
void chmod_error_details(char const *name, mode_t mode);
void chown_error_details(char const *name, uid_t uid, gid_t gid);
void link_error(char const *target, char const *source);
void mkdir_error(char const *name);
void mkfifo_error(char const *name);
void mknod_error(char const *name);
void symlink_error(char const *contents, char const *name);
void utime_error(char const *name);
void write_error_details(char const *name, size_t status, size_t size);
size_t stripped_prefix_len(char const *file_name, size_t num);
_Bool contains_dot_dot(char const *name);
_Bool sparse_member_p(struct tar_stat_info *st);
enum dump_status sparse_extract_file(int fd, struct tar_stat_info *st,
                                     off_t *size);
static mode_t newdir_umask;
static mode_t current_umask;
static struct delayed_set_stat *delayed_set_stat_head;
static struct delayed_symlink *delayed_symlink_head;
void extr_init(void) {
  __uid_t tmp;

  {
    {
      tmp = geteuid();
      we_are_root = (_Bool)(tmp == 0U);
      same_permissions_option += (int)we_are_root;
      same_owner_option += (int)we_are_root;
      xalloc_fail_func = &extract_finish;
      newdir_umask = umask((__mode_t)0);
    }
    if (0 < same_permissions_option) {
      current_umask = (mode_t)0;
    } else {
      {
        umask(newdir_umask);
        current_umask = newdir_umask;
      }
    }
    return;
  }
}
static void set_mode(char const *file_name, struct stat const *stat_info,
                     struct stat const *cur_info, mode_t invert_permissions,
                     enum permstatus permstatus, char typeflag) {
  mode_t mode;
  struct stat st;
  int tmp;
  int tmp___0;
  void *__cil_tmp11;

  {
    if (0 < same_permissions_option) {
      if ((unsigned int)permstatus != 2U) {
        mode = (mode_t)stat_info->st_mode;
        if ((unsigned int)permstatus == 1U) {
          if (!(mode & (unsigned int)(~(
                           ((64 | (64 >> 3)) | ((64 >> 3) >> 3)) |
                           (((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                            ((256 | (256 >> 3)) | ((256 >> 3) >> 3))))))) {
          }
        }
      } else {
        goto _L___3;
      }
    } else {
    _L___3: /* CIL Label */
      if (!invert_permissions) {
        return;
      } else {

        mode = (mode_t)(cur_info->st_mode ^
                        (unsigned int const)invert_permissions);
      }
    }
    { tmp___0 = chmod(file_name, mode); }
    if (tmp___0 != 0) {
      {
        chmod_error_details(file_name, mode);
      }
    }
    return;
  }
}
static void check_time(char const *file_name, time_t t) {
  time_t now;
  char const *tmp;
  char *tmp___0;
  char const *tmp___1;
  char *tmp___2;
  char *__cil_tmp8;
  char *__cil_tmp9;

  {
    if (t <= 0L) {
      {
        tmp = tartime(t);
        tmp___0 = gettext("%s: implausibly old time stamp %s");
        error(0, 0, (char const *)tmp___0, file_name, tmp);
      }
    } else {
      if (start_timespec.tv_sec < t) {
        {
          now = time((time_t *)0);
        }
      }
    }
    return;
  }
}
static void set_stat(char const *file_name, struct stat const *stat_info,
                     struct stat const *cur_info, mode_t invert_permissions,
                     enum permstatus permstatus, char typeflag) {
  struct utimbuf utimbuf;
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    if ((int)typeflag != 50) {
      if (!touch_option) {
        if ((unsigned int)permstatus != 2U) {
          if (incremental_option) {
            utimbuf.actime = (__time_t)stat_info->st_atim.tv_sec;
          } else {
            utimbuf.actime = start_timespec.tv_sec;
          }
          {
            utimbuf.modtime = (__time_t)stat_info->st_mtim.tv_sec;
            tmp = utime(file_name, (struct utimbuf const *)(&utimbuf));
          }
          if (tmp < 0) {
            {
              utime_error(file_name);
            }
          } else {
            {
              check_time(file_name, utimbuf.actime);
              check_time(file_name, utimbuf.modtime);
            }
          }
        }
      }
      {
        set_mode(file_name, stat_info, cur_info, invert_permissions, permstatus,
                 typeflag);
      }
    }
    if (0 < same_owner_option) {
      if ((unsigned int)permstatus != 2U) {
        if ((int)typeflag == 50) {
          {
            tmp___0 = lchown(file_name, (__uid_t)stat_info->st_uid,
                             (__gid_t)stat_info->st_gid);
          }

        } else {
          {
            tmp___1 = chown(file_name, (__uid_t)stat_info->st_uid,
                            (__gid_t)stat_info->st_gid);
          }
          if (tmp___1 < 0) {
            {
              chown_error_details(file_name, (uid_t)stat_info->st_uid,
                                  (gid_t)stat_info->st_gid);
            }
          }
        }
      }
    }
    return;
  }
}
static void delay_set_stat(char const *file_name, struct stat const *stat_info,
                           mode_t invert_permissions,
                           enum permstatus permstatus) {
  size_t file_name_len;
  size_t tmp;
  struct delayed_set_stat *data;
  void *tmp___0;

  {
    {
      tmp = strlen(file_name);
      file_name_len = tmp;
      tmp___0 =
          xmalloc(((unsigned long)(&((struct delayed_set_stat *)0)->file_name) +
                   file_name_len) +
                  1UL);
      data = (struct delayed_set_stat *)tmp___0;
      data->file_name_len = file_name_len;
      strcpy((char * /* __restrict  */)(data->file_name),
             (char const * /* __restrict  */)file_name);
      data->invert_permissions = invert_permissions;
      data->permstatus = permstatus;
      data->after_symlinks = (_Bool)0;
      data->stat_info = (struct stat) * stat_info;
      data->next = delayed_set_stat_head;
      delayed_set_stat_head = data;
    }
    return;
  }
}
static void repair_delayed_set_stat(char const *dir,
                                    struct stat const *dir_stat_info) {
  struct delayed_set_stat *data;
  struct stat st;
  int tmp;
  char *tmp___0;
  char *tmp___1;
  void *__cil_tmp8;
  char *__cil_tmp9;

  {
    data = delayed_set_stat_head;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!data) {
          goto while_break;
        }
        {
          tmp = stat((char const * /* __restrict  */)(data->file_name),
                     (struct stat * /* __restrict  */)(&st));
        }
        if (tmp != 0) {
          {
            stat_error((char const *)(data->file_name));
          }
          return;
        }
        if (st.st_dev == (__dev_t)dir_stat_info->st_dev) {
          if (st.st_ino == (__ino_t)dir_stat_info->st_ino) {
            data->stat_info = current_stat_info.stat;
            data->invert_permissions =
                (unsigned int)(((64 | (64 >> 3)) | ((64 >> 3) >> 3)) |
                               (((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                ((256 | (256 >> 3)) | ((256 >> 3) >> 3)))) &
                (current_stat_info.stat.st_mode ^ st.st_mode);
            data->permstatus = (enum permstatus)1;
            return;
          }
        }
        data = data->next;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      tmp___0 = quotearg_colon(dir);
      tmp___1 = gettext("%s: Unexpected inconsistency when making directory");
      error(0, 0, (char const *)tmp___1, tmp___0);
      exit_status = 2;
    }
    return;
  }
}
static int make_directories(char *file_name) {
  char *cursor0;
  char *cursor;
  int did_something;
  int mode;
  int invert_permissions;
  int status;
  int *tmp;
  int tmp___0;
  int *tmp___1;

  {
    cursor0 = file_name + 0;
    did_something = 0;
    cursor = cursor0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!*cursor) {
          goto while_break;
        }
        if (!((int)*cursor == 47)) {
          goto __Cont;
        }

        *cursor = (char)'\000';
        mode =
            (int)((unsigned int)(((64 | (64 >> 3)) | ((64 >> 3) >> 3)) |
                                 (((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                  ((256 | (256 >> 3)) | ((256 >> 3) >> 3)))) &
                  ~newdir_umask);

        {
          status = mkdir((char const *)file_name,
                         (__mode_t)(mode ^ invert_permissions));
        }
        if (status == 0) {
          {
            delay_set_stat((char const *)file_name,
                           (struct stat const *)(&current_stat_info.stat),
                           (mode_t)invert_permissions, (enum permstatus)2);
            print_for_mkdir(file_name, (int)(cursor - file_name), (mode_t)mode);
            did_something = 1;
            *cursor = (char)'/';
          }
          goto __Cont;
        }
        {
          *cursor = (char)'/';
          tmp___1 = __errno_location();
        }
        if (*tmp___1 == 17) {
          goto __Cont;
        } else {
          { tmp = __errno_location(); }
          if (*tmp == 38) {
            goto _L___3;
          } else {
            if (0) {
            _L___3: { /* CIL Label */
              tmp___0 = access((char const *)file_name, 2);
            }
              if (tmp___0 == 0) {
                goto __Cont;
              }
            }
          }
        }
        goto while_break;
      __Cont:
        cursor++;
      }
    while_break: /* CIL Label */
        ;
    }
    return (did_something);
  }
}
static _Bool file_newer_p(char const *file_name,
                          struct tar_stat_info *tar_stat) {
  struct stat st;
  int tmp;
  void *__cil_tmp5;

  {
    {
      tmp = stat((char const * /* __restrict  */)file_name,
                 (struct stat * /* __restrict  */)(&st));
    }
    if (tmp) {
      {
        stat_warn(file_name);
      }
      return ((_Bool)1);
    }
    if (!((st.st_mode & 61440U) == 16384U)) {
      if (st.st_mtim.tv_sec >= tar_stat->stat.st_mtim.tv_sec) {
        return ((_Bool)1);
      }
    }
    return ((_Bool)0);
  }
}
static int prepare_to_extract(char const *file_name) {
  int tmp;
  int *tmp___0;
  int *tmp___1;
  char *tmp___2;
  _Bool tmp___3;
  char *__cil_tmp7;

  {

    {
      if ((unsigned int)old_files_option == 3U) {
        goto case_3;
      }
      if ((unsigned int)old_files_option == 5U) {
        goto case_5;
      }
      goto switch_default;
    case_3: { /* CIL Label */
      tmp = remove_any_file(file_name,
                            (enum remove_option)recursive_unlink_option);
    }
      if (!tmp) {
        {
          tmp___0 = __errno_location();
        }
      }
      goto switch_break;
    case_5: { /* CIL Label */
      tmp___3 = file_newer_p(file_name, &current_stat_info);
    }
      if (tmp___3) {
        {
          tmp___2 = gettext("Current `%s\' is newer");
          error(0, 0, (char const *)tmp___2, file_name);
        }
        return (0);
      }
      goto switch_break;
    switch_default: /* CIL Label */
      goto switch_break;
    switch_break: /* CIL Label */
        ;
    }
    return (1);
  }
}
static int maybe_recoverable(char *file_name, int *interdir_made) {
  int e;
  int *tmp;
  int *tmp___0;
  int *tmp___1;
  _Bool tmp___2;
  int r;
  int tmp___3;
  int *tmp___4;
  int *tmp___5;
  int tmp___6;

  {
    {
      tmp = __errno_location();
      e = *tmp;
    }
    if (*interdir_made) {
      return (0);
    }
    { tmp___0 = __errno_location(); }
    {
      if (*tmp___0 == 17) {
        goto case_17;
      }

      goto switch_default;
    case_17: { /* CIL Label */
      if ((unsigned int)old_files_option == 4U) {
        goto case_4;
      }
      if ((unsigned int)old_files_option == 5U) {
        goto case_5;
      }

      if ((unsigned int)old_files_option == 1U) {
        goto case_0;
      }

      goto switch_break___0;
    case_4: /* CIL Label */
      return (0);
    case_5: { /* CIL Label */
      tmp___2 = file_newer_p((char const *)file_name, &current_stat_info);
    }
      if (tmp___2) {
        {
          tmp___1 = __errno_location();
          *tmp___1 = e;
        }
        return (0);
      }
    case_0:   /* CIL Label */
    case_1:   /* CIL Label */
    case_2: { /* CIL Label */
      tmp___3 = remove_any_file((char const *)file_name, (enum remove_option)0);
      r = tmp___3;
      tmp___4 = __errno_location();
      *tmp___4 = 17;
    }
      return (r);
    case_3: /* CIL Label */
      goto switch_break___0;
    switch_break___0: /* CIL Label */
        ;
    }
    case_2___0: { /* CIL Label */
      tmp___6 = make_directories(file_name);
    }
      if (!tmp___6) {
        {
          tmp___5 = __errno_location();
          *tmp___5 = 2;
        }
        return (0);
      }
      *interdir_made = 1;
      return (1);
    switch_default: /* CIL Label */
      return (0);
    switch_break: /* CIL Label */
        ;
    }
  }
}
static void apply_nonancestor_delayed_set_stat(char const *file_name,
                                               _Bool after_symlinks) {
  size_t file_name_len;
  size_t tmp;
  _Bool check_for_renamed_directories;
  struct delayed_set_stat *data;
  _Bool skip_this_one;
  struct stat st;
  struct stat const *cur_info;
  int tmp___0;
  char *tmp___1;
  char *tmp___2;
  int tmp___3;
  void *__cil_tmp14;
  char *__cil_tmp15;
  char *__cil_tmp16;

  {
    {
      tmp = strlen(file_name);
      file_name_len = tmp;
      check_for_renamed_directories = (_Bool)0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!delayed_set_stat_head) {
          goto while_break;
        }
        data = delayed_set_stat_head;
        skip_this_one = (_Bool)0;
        cur_info = (struct stat const *)0;
        check_for_renamed_directories =
            (_Bool)((int)check_for_renamed_directories |
                    (int)data->after_symlinks);
        if ((int)after_symlinks < (int)data->after_symlinks) {
          goto while_break;
        } else {
          if (data->file_name_len < file_name_len) {
            if (*(file_name + data->file_name_len)) {
              if ((int const) * (file_name + data->file_name_len) == 47) {
                goto _L___3;
              } else {
                if ((int const) * (file_name + (data->file_name_len - 1UL)) ==
                    47) {
                _L___3: { /* CIL Label */
                  tmp___0 = memcmp((void const *)file_name,
                                   (void const *)(data->file_name),
                                   data->file_name_len);
                }
                  if (tmp___0 == 0) {
                    goto while_break;
                  }
                }
              }
            }
          }
        }
        if (check_for_renamed_directories) {
          {
            cur_info = (struct stat const *)(&st);
            tmp___3 = stat((char const * /* __restrict  */)(data->file_name),
                           (struct stat * /* __restrict  */)(&st));
          }
          if (tmp___3 != 0) {
            {
              stat_error((char const *)(data->file_name));
              skip_this_one = (_Bool)1;
            }
          } else {
            if (st.st_dev == data->stat_info.st_dev) {
              if (!(st.st_ino == data->stat_info.st_ino)) {
                {
                  tmp___1 = quotearg_colon((char const *)(data->file_name));
                  tmp___2 = gettext("%s: Directory renamed before its status "
                                    "could be extracted");
                  error(0, 0, (char const *)tmp___2, tmp___1);
                  exit_status = 2;
                  skip_this_one = (_Bool)1;
                }
              }
            } else {
              {
                tmp___1 = quotearg_colon((char const *)(data->file_name));
                tmp___2 = gettext("%s: Directory renamed before its status "
                                  "could be extracted");
                error(0, 0, (char const *)tmp___2, tmp___1);
                exit_status = 2;
                skip_this_one = (_Bool)1;
              }
            }
          }
        }
        if (!skip_this_one) {
          {
            set_stat((char const *)(data->file_name),
                     (struct stat const *)(&data->stat_info), cur_info,
                     data->invert_permissions, data->permstatus, (char)'5');
          }
        }
        {
          delayed_set_stat_head = data->next;
          free((void *)data);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static int conttype_diagnosed;
void extract_archive(void) {
  union block *data_block;
  int fd;
  int status;
  size_t count;
  size_t written;
  int openflag;
  mode_t mode;
  off_t size;
  int interdir_made;
  char typeflag;
  char *file_name;
  int tmp;
  size_t prefix_len;
  size_t tmp___0;
  int e;
  int *tmp___1;
  char *tmp___2;
  char *tmp___3;
  _Bool tmp___4;
  _Bool tmp___5;
  int tmp___6;
  char *tmp___7;
  int tmp___8;
  char *tmp___9;
  int *tmp___10;
  int tmp___11;
  int tmp___12;
  struct stat st;
  int tmp___13;
  struct delayed_set_stat *h;
  struct delayed_symlink *p;
  size_t tmp___14;
  void *tmp___15;
  size_t tmp___16;
  void *tmp___17;
  int tmp___18;
  int tmp___19;
  char *tmp___20;
  int tmp___21;
  int tmp___22;
  _Bool tmp___23;
  int tmp___24;
  char const *link_name;
  char *tmp___25;
  struct stat st1;
  struct stat st2;
  int e___0;
  struct delayed_symlink *ds;
  struct string_list *p___0;
  size_t tmp___26;
  void *tmp___27;
  int tmp___28;
  int tmp___29;
  int *tmp___30;
  int *tmp___31;
  int tmp___32;
  int tmp___33;
  int tmp___34;
  int tmp___35;
  int tmp___36;
  int tmp___37;
  struct stat st___0;
  int tmp___38;
  int *tmp___39;
  int *tmp___40;
  int tmp___41;
  int *tmp___42;
  char const *tmp___43;
  char *tmp___44;
  char *tmp___45;
  char *tmp___46;
  char *tmp___47;
  char *tmp___48;
  char *tmp___49;
  int tmp___50;
  int tmp___51;
  int tmp___52;
  int tmp___53;
  int tmp___54;
  void *__cil_tmp80;
  void *__cil_tmp81;
  void *__cil_tmp82;
  void *__cil_tmp83;
  char *__cil_tmp84;
  char *__cil_tmp85;
  char *__cil_tmp86;
  char *__cil_tmp87;
  char *__cil_tmp88;
  char *__cil_tmp89;
  char *__cil_tmp90;
  char *__cil_tmp91;

  {
    {
      interdir_made = 0;
      set_next_block_after(current_header);
      decode_header(current_header, &current_stat_info, &current_format, 1);
    }

    if (verbose_option) {
      {
        print_header(&current_stat_info, (off_t)-1);
      }
    }
    {
      file_name = safer_name_suffix((char const *)current_stat_info.file_name,
                                    (_Bool)0);
    }
    if (strip_path_elements) {
      {
        tmp___0 =
            stripped_prefix_len((char const *)file_name, strip_path_elements);
        prefix_len = tmp___0;
      }

      file_name += prefix_len;
    }
    { apply_nonancestor_delayed_set_stat((char const *)file_name, (_Bool)0); }

    { tmp___5 = sparse_member_p(&current_stat_info); }
    if (tmp___5) {
      tmp___50 = 'S';
    } else {
      tmp___50 = (int)current_header->header.typeflag;
    }
    typeflag = (char)tmp___50;
    {
      if ((int)typeflag == 83) {
        goto case_83;
      }
      if ((int)typeflag == 0) {
        goto case_83;
      }
      if ((int)typeflag == 48) {
        goto case_83;
      }
      if ((int)typeflag == 55) {
        goto case_83;
      }
      if ((int)typeflag == 50) {
        goto case_50;
      }
      if ((int)typeflag == 49) {
        goto case_49;
      }
      if ((int)typeflag == 51) {
        goto case_51;
      }
      if ((int)typeflag == 52) {
        goto case_52;
      }
      if ((int)typeflag == 54) {
        goto case_54;
      }
      if ((int)typeflag == 53) {
        goto really_dir;
      }
      if ((int)typeflag == 68) {
        goto really_dir;
      }

      if ((int)typeflag == 77) {
        goto case_77;
      }

      goto switch_default;
    case_83: /* CIL Label */
    case_0:  /* CIL Label */
    case_48: /* CIL Label */
    case_55: /* CIL Label */
      if (current_stat_info.had_trailing_slash) {
        goto really_dir;
      }
    again_file:
      if ((unsigned int)old_files_option == 2U) {
        tmp___51 = 512;
      } else {
        tmp___51 = 128;
      }
      openflag = 65 | tmp___51;
      mode = (current_stat_info.stat.st_mode &
              (unsigned int)(((64 | (64 >> 3)) | ((64 >> 3) >> 3)) |
                             (((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                              ((256 | (256 >> 3)) | ((256 >> 3) >> 3))))) &
             ~current_umask;
      if (to_stdout_option) {
        fd = 1;
        goto extract_file;
      }
      { tmp___6 = prepare_to_extract((char const *)file_name); }
      if (!tmp___6) {
        {
          skip_member();
        }

        goto switch_break;
      }
      if ((int)typeflag == 55) {
      }
      { fd = open((char const *)file_name, openflag, mode); }
      if (fd < 0) {
        {
          tmp___8 = maybe_recoverable(file_name, &interdir_made);
        }
        if (tmp___8) {
          goto again_file;
        }
        {
          open_error((char const *)file_name);
          skip_member();
        }

        goto switch_break;
      }
    extract_file:
      if (current_stat_info.is_sparse) {
        {
          sparse_extract_file(fd, &current_stat_info, &size);
        }
      } else {
        size = current_stat_info.stat.st_size;
        {
          while (1) {
          while_continue: /* CIL Label */
              ;
            if (!(size > 0L)) {
              goto while_break;
            }

            { data_block = find_next_block(); }
            if (!data_block) {
              {
                tmp___9 = gettext("Unexpected EOF in archive");
                error(0, 0, (char const *)tmp___9);
                exit_status = 2;
              }
              goto while_break;
            }
            { written = available_space_after(data_block); }
            if (written > (size_t)size) {
              written = (size_t)size;
            }
            {
              tmp___10 = __errno_location();
              *tmp___10 = 0;
              count =
                  full_write(fd, (void const *)(data_block->buffer), written);
              size = (off_t)((size_t)size - count);
              set_next_block_after(
                  (union block *)((data_block->buffer + written) - 1));
            }
            if (count != written) {
              {
                write_error_details((char const *)file_name, count, written);
              }
              goto while_break;
            }
          }
        while_break: /* CIL Label */
            ;
        }
      }
      { skip_file(size); }

      { status = close(fd); }
      if (status < 0) {
        {
          close_error((char const *)file_name);
        }
      }

      {
        set_stat((char const *)file_name,
                 (struct stat const *)(&current_stat_info.stat),
                 (struct stat const *)0, (mode_t)0, (enum permstatus)tmp___52,
                 typeflag);
      }
      goto switch_break;
    case_50: { /* CIL Label */
      tmp___11 = prepare_to_extract((char const *)file_name);
    }
      if (!tmp___11) {
        goto switch_break;
      }
      if (absolute_names_option) {
        goto _L;
      } else {
        if ((int)*(current_stat_info.link_name + 0) == 47) {
          goto _L___0;
        } else {
          {
            tmp___23 =
                contains_dot_dot((char const *)current_stat_info.link_name);
          }
          if (tmp___23) {
          _L___0: {

          while_break___0: /* CIL Label */
              ;
          }
            status = -1;
            if (fd < 0) {
              {
                open_error((char const *)file_name);
              }
            } else {
              { tmp___22 = fstat(fd, &st); }
              if (tmp___22 != 0) {
                {
                  stat_error((char const *)file_name);
                  close(fd);
                }
              } else {
                { tmp___21 = close(fd); }
                if (tmp___21 != 0) {
                  {
                    close_error((char const *)file_name);
                  }
                } else {
                  {
                    tmp___14 =
                        strlen((char const *)current_stat_info.link_name);
                    tmp___15 =
                        xmalloc(((unsigned long)(&((struct delayed_symlink *)0)
                                                      ->target) +
                                 tmp___14) +
                                1UL);
                    p = (struct delayed_symlink *)tmp___15;
                    p->next = delayed_symlink_head;
                    delayed_symlink_head = p;
                    p->dev = st.st_dev;
                    p->ino = st.st_ino;
                    p->mtime = st.st_mtim.tv_sec;
                    p->uid = current_stat_info.stat.st_uid;
                    p->gid = current_stat_info.stat.st_gid;
                    tmp___16 = strlen((char const *)file_name);
                    tmp___17 = xmalloc(
                        ((unsigned long)(&((struct string_list *)0)->string) +
                         tmp___16) +
                        1UL);
                    p->sources = (struct string_list *)tmp___17;
                    (p->sources)->next = (struct string_list *)0;
                    strcpy((char * /* __restrict  */)((p->sources)->string),
                           (char const * /* __restrict  */)file_name);
                    strcpy((char * /* __restrict  */)(p->target),
                           (char const * /* __restrict  */)
                               current_stat_info.link_name);
                    h = delayed_set_stat_head;
                  }
                  if (h) {
                    if (!h->after_symlinks) {
                      {
                        tmp___19 = strncmp((char const *)file_name,
                                           (char const *)(h->file_name),
                                           h->file_name_len);
                      }
                      if (tmp___19 == 0) {
                        if ((int)*(file_name + h->file_name_len) == 47) {
                          {
                            tmp___20 = base_name((char const *)file_name);
                          }
                          if ((unsigned long)tmp___20 ==
                              (unsigned long)((file_name + h->file_name_len) +
                                              1)) {
                            {
                              while (1) {
                              while_continue___1: /* CIL Label */
                                  ;
                                {
                                  h->after_symlinks = (_Bool)1;
                                  tmp___18 = stat(
                                      (char const * /* __restrict  */)(
                                          h->file_name),
                                      (struct stat * /* __restrict  */)(&st));
                                }
                                if (tmp___18 != 0) {
                                  {
                                    stat_error((char const *)(h->file_name));
                                  }
                                } else {
                                  h->stat_info.st_dev = st.st_dev;
                                  h->stat_info.st_ino = st.st_ino;
                                }
                                h = h->next;
                                if (h) {
                                  if (!(!h->after_symlinks)) {
                                    goto while_break___1;
                                  }
                                } else {
                                  goto while_break___1;
                                }
                              }
                            while_break___1: /* CIL Label */
                                ;
                            }
                          }
                        }
                      }
                    }
                  }
                  status = 0;
                }
              }
            }
          } else {
          _L: {

          while_break___2: /* CIL Label */
              ;
          }
            if (status == 0) {
              {
                set_stat((char const *)file_name,
                         (struct stat const *)(&current_stat_info.stat),
                         (struct stat const *)0, (mode_t)0, (enum permstatus)0,
                         (char)'2');
              }
            } else {
              {
                symlink_error((char const *)current_stat_info.link_name,
                              (char const *)file_name);
              }
            }
          }
        }
      }

      goto switch_break;
    case_49: { /* CIL Label */
      tmp___24 = prepare_to_extract((char const *)file_name);
    }
      if (!tmp___24) {
        goto switch_break;
      }
    again_link: {
      tmp___25 = safer_name_suffix((char const *)current_stat_info.link_name,
                                   (_Bool)1);
      link_name = (char const *)tmp___25;
      status = link(link_name, (char const *)file_name);
    }
      if (status == 0) {
        ds = delayed_symlink_head;
        if (ds) {
          {
            tmp___28 = stat((char const * /* __restrict  */)link_name,
                            (struct stat * /* __restrict  */)(&st1));
          }
          if (tmp___28 == 0) {
            {
              while (1) {
              while_continue___3: /* CIL Label */
                  ;
                if (!ds) {
                  goto while_break___3;
                }
                if (ds->dev == st1.st_dev) {
                  if (ds->ino == st1.st_ino) {
                    if (ds->mtime == st1.st_mtim.tv_sec) {
                      {
                        tmp___26 = strlen((char const *)file_name);
                        tmp___27 =
                            xmalloc(((unsigned long)(&((struct string_list *)0)
                                                          ->string) +
                                     tmp___26) +
                                    1UL);
                        p___0 = (struct string_list *)tmp___27;
                        strcpy((char * /* __restrict  */)(p___0->string),
                               (char const * /* __restrict  */)file_name);
                        p___0->next = ds->sources;
                        ds->sources = p___0;
                      }
                      goto while_break___3;
                    }
                  }
                }
                ds = ds->next;
              }
            while_break___3: /* CIL Label */
                ;
            }
          }
        }
        goto switch_break;
      }
      { tmp___29 = maybe_recoverable(file_name, &interdir_made); }

      {
        tmp___31 = __errno_location();
        e___0 = *tmp___31;
        tmp___32 = stat((char const * /* __restrict  */)link_name,
                        (struct stat * /* __restrict  */)(&st1));
      }
      if (tmp___32 == 0) {
        {
          tmp___33 = stat((char const * /* __restrict  */)file_name,
                          (struct stat * /* __restrict  */)(&st2));
        }
        if (tmp___33 == 0) {
          if (st1.st_dev == st2.st_dev) {
            if (st1.st_ino == st2.st_ino) {
              goto switch_break;
            }
          }
        }
      }
      { link_error(link_name, (char const *)file_name); }

      goto switch_break;
    case_51: /* CIL Label */
      current_stat_info.stat.st_mode |= 8192U;
      goto make_node;
    case_52: /* CIL Label */
      current_stat_info.stat.st_mode |= 24576U;
    make_node: { tmp___34 = prepare_to_extract((char const *)file_name); }
      if (!tmp___34) {
        goto switch_break;
      }
      {
        status = mknod((char const *)file_name, current_stat_info.stat.st_mode,
                       current_stat_info.stat.st_rdev);
      }
      if (status != 0) {
        {
          tmp___35 = maybe_recoverable(file_name, &interdir_made);
        }
        if (tmp___35) {
          goto make_node;
        }
        { mknod_error((char const *)file_name); }

        goto switch_break;
      }
      {
        set_stat((char const *)file_name,
                 (struct stat const *)(&current_stat_info.stat),
                 (struct stat const *)0, (mode_t)0, (enum permstatus)1,
                 typeflag);
      }
      goto switch_break;
    case_54: { /* CIL Label */
      tmp___36 = prepare_to_extract((char const *)file_name);
    }
      if (!tmp___36) {
        goto switch_break;
      }
      {
        while (1) {
        while_continue___4: /* CIL Label */
            ;
          {
            status =
                mkfifo((char const *)file_name, current_stat_info.stat.st_mode);
          }
          if (!(status != 0)) {
            goto while_break___4;
          }
          { tmp___37 = maybe_recoverable(file_name, &interdir_made); }
          if (!tmp___37) {
            goto while_break___4;
          }
        }
      while_break___4: /* CIL Label */
          ;
      }
      if (status == 0) {
        {
          set_stat((char const *)file_name,
                   (struct stat const *)(&current_stat_info.stat),
                   (struct stat const *)((void *)0), (mode_t)0,
                   (enum permstatus)1, typeflag);
        }
      } else {
        { mkfifo_error((char const *)file_name); }
      }
      goto switch_break;
    really_dir:
    case_53: /* CIL Label */
    case_68: /* CIL Label */
      if (incremental_option) {
        {
          gnu_restore((char const *)file_name);
        }
      } else {
        if ((int)typeflag == 68) {
          {
            skip_member();
          }
        }
      }
      if (we_are_root) {
        tmp___53 = 0;
      } else {
        tmp___53 = 192;
      }
      {
        mode = (current_stat_info.stat.st_mode | (unsigned int)tmp___53) &
               (unsigned int)(((64 | (64 >> 3)) | ((64 >> 3) >> 3)) |
                              (((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                               ((256 | (256 >> 3)) | ((256 >> 3) >> 3))));
        status = prepare_to_extract((char const *)file_name);
      }
      if (status == 0) {
        goto switch_break;
      }
      if (status < 0) {
        goto directory_exists;
      }
    again_dir: { status = mkdir((char const *)file_name, mode); }
      if (status != 0) {
        {
          tmp___40 = __errno_location();
        }
        if (*tmp___40 == 17) {
          if (interdir_made) {
            goto _L___3;
          } else {
            if ((unsigned int)old_files_option == 0U) {
              goto _L___3;
            } else {
              if ((unsigned int)old_files_option == 2U) {
              _L___3: { /* CIL Label */
                tmp___38 = stat((char const * /* __restrict  */)file_name,
                                (struct stat * /* __restrict  */)(&st___0));
              }
                if (tmp___38 == 0) {
                  if (interdir_made) {
                    {
                      repair_delayed_set_stat((char const *)file_name,
                                              (struct stat const *)(&st___0));
                    }
                    goto switch_break;
                  }
                  if ((st___0.st_mode & 61440U) == 16384U) {
                    mode = st___0.st_mode & ~current_umask;
                    goto directory_exists;
                  }
                }
                {
                  tmp___39 = __errno_location();
                  *tmp___39 = 17;
                }
              }
            }
          }
        }
        { tmp___41 = maybe_recoverable(file_name, &interdir_made); }
        if (tmp___41) {
          goto again_dir;
        }
        { tmp___42 = __errno_location(); }
      }
    directory_exists:
      if (status == 0) {
        goto _L___4;
      } else {
        if ((unsigned int)old_files_option == 0U) {
          goto _L___4;
        } else {
          if ((unsigned int)old_files_option == 2U) {
          _L___4: /* CIL Label */
            if (status == 0) {
              tmp___54 = 1;
            } else {
              tmp___54 = 0;
            }
            {
              delay_set_stat(
                  (char const *)file_name,
                  (struct stat const *)(&current_stat_info.stat),
                  (unsigned int)(((64 | (64 >> 3)) | ((64 >> 3) >> 3)) |
                                 (((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                  ((256 | (256 >> 3)) | ((256 >> 3) >> 3)))) &
                      (mode ^ current_stat_info.stat.st_mode),
                  (enum permstatus)tmp___54);
            }
          }
        }
      }
      goto switch_break;
    case_86: /* CIL Label */

      goto switch_break;
    case_78: { /* CIL Label */
      extract_mangle();
    }
      goto switch_break;
    case_77: { /* CIL Label */
      tmp___45 = quotearg_colon((char const *)current_stat_info.file_name);
      tmp___46 = gettext(
          "%s: Cannot extract -- file is continued from another volume");
      error(0, 0, (char const *)tmp___46, tmp___45);
      exit_status = 2;
      skip_member();
    }

      goto switch_break;
    case_76:   /* CIL Label */
    case_75: { /* CIL Label */
      tmp___47 = gettext("Visible long name error");
      error(0, 0, (char const *)tmp___47);
      exit_status = 2;
      skip_member();
    }

      goto switch_break;
    switch_default: { /* CIL Label */
      tmp___48 = quotearg_colon((char const *)file_name);
      tmp___49 =
          gettext("%s: Unknown file type \'%c\', extracted as normal file");
      error(0, 0, (char const *)tmp___49, tmp___48, (int)typeflag);
    }
      goto again_file;
    switch_break: /* CIL Label */
        ;
    }
    return;
  }
}
static void apply_delayed_symlinks(void) {
  struct delayed_symlink *ds;
  struct string_list *sources;
  char const *valid_source;
  char const *source;
  struct stat st;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  struct string_list *next;
  struct delayed_symlink *next___0;
  void *__cil_tmp12;

  {
    ds = delayed_symlink_head;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!ds) {
          goto while_break;
        }
        sources = ds->sources;
        valid_source = (char const *)0;
        sources = ds->sources;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            if (!sources) {
              goto while_break___0;
            }
            {
              source = (char const *)(sources->string);
              tmp___2 = lstat((char const * /* __restrict  */)source,
                              (struct stat * /* __restrict  */)(&st));
            }
            if (tmp___2 == 0) {
              if (st.st_dev == ds->dev) {
                if (st.st_ino == ds->ino) {
                  if (st.st_mtim.tv_sec == ds->mtime) {
                    {
                      tmp___1 = unlink(source);
                    }
                    if (tmp___1 != 0) {
                      {
                        unlink_error(source);
                      }
                    } else {
                      if (valid_source) {
                        {
                          tmp___0 = link(valid_source, source);
                        }
                        if (!(tmp___0 == 0)) {
                          goto _L;
                        }
                      } else {
                      _L: { tmp = symlink((char const *)(ds->target), source); }
                        if (tmp != 0) {
                          {
                            symlink_error((char const *)(ds->target), source);
                          }
                        } else {
                          {
                            valid_source = source;
                            st.st_uid = ds->uid;
                            st.st_gid = ds->gid;
                            set_stat(source, (struct stat const *)(&st),
                                     (struct stat const *)0, (mode_t)0,
                                     (enum permstatus)0, (char)'2');
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            sources = sources->next;
          }
        while_break___0: /* CIL Label */
            ;
        }
        sources = ds->sources;
        {

        while_break___1: /* CIL Label */
            ;
        }
        {
          next___0 = ds->next;
          free((void *)ds);
          ds = next___0;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    delayed_symlink_head = (struct delayed_symlink *)0;
    return;
  }
}
void extract_finish(void) {
  char *__cil_tmp1;
  char *__cil_tmp2;

  {
    {
      apply_nonancestor_delayed_set_stat("", (_Bool)0);
      apply_delayed_symlinks();
      apply_nonancestor_delayed_set_stat("", (_Bool)1);
    }
    return;
  }
}
__attribute__((__noreturn__)) void fatal_exit(void);
void fatal_exit(void) {
  char *tmp;
  char *__cil_tmp2;

  {
    {
      extract_finish();
      tmp = gettext("Error is not recoverable: exiting now");
      error(2, 0, (char const *)tmp);
      abort();
    }
  }
}
/* #pragma merger("0","005.xheader.o.i","") */
extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(2), __leaf__)) strtok)(char *__restrict __s,
                                       char const *__restrict __delim);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) stpcpy)(char *__restrict __dest,
                                          char const *__restrict __src);
extern __attribute__((__nothrow__))
__pid_t(__attribute__((__leaf__)) getpid)(void);
extern __attribute__((__nothrow__)) unsigned long(__attribute__((
    __nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr,
                                        char **__restrict __endptr, int __base);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) calloc)(
    size_t __nmemb, size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);
char *dir_name(char const *path);
strtol_error xstrtoumax(char const *s, char **ptr, int strtol_base,
                        uintmax_t *val, char const *valid_suffixes);
__attribute__((__noreturn__)) void usage(int status);
void xheader_decode_global(void);
void xheader_read(union block *p, size_t size);
void xheader_destroy(struct xheader *xhdr);
char *xheader_ghdr_name(void);
void xheader_set_option(char *string);
_Bool utf8_convert(_Bool to_utf, char const *input, char **output);
extern void _obstack_newchunk(struct obstack *, int);
extern int _obstack_begin(struct obstack *, int, int, void *(*)(long),
                          void (*)(void *));
extern void obstack_free(struct obstack *obstack, void *block);
static _Bool xheader_protected_pattern_p(char const *pattern);
static _Bool xheader_protected_keyword_p(char const *keyword);
static __attribute__((__noreturn__)) void xheader_set_single_keyword(char *kw);
static void code_string(char const *string, char const *keyword,
                        struct xheader *xhdr);
static void extended_header_init(void);
static size_t global_header_count;
static struct keyword_list *keyword_pattern_list;
static struct keyword_list *keyword_global_override_list;
static struct keyword_list *keyword_override_list;
static struct keyword_list *global_header_override_list;
static char *exthdr_name;
static char *globexthdr_name;
static _Bool xheader_keyword_deleted_p(char const *kw) {
  struct keyword_list *kp;
  int tmp;

  {
    kp = keyword_pattern_list;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!kp) {
          goto while_break;
        }
        { tmp = fnmatch((char const *)kp->pattern, kw, 0); }

        kp = kp->next;
      }
    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)0);
  }
}
static _Bool xheader_keyword_override_p(char const *keyword) {
  struct keyword_list *kp;
  int tmp;

  {
    kp = keyword_override_list;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!kp) {
          goto while_break;
        }
        { tmp = strcmp((char const *)kp->pattern, keyword); }
        if (tmp == 0) {
          return ((_Bool)1);
        }
        kp = kp->next;
      }
    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)0);
  }
}
static void xheader_list_append(struct keyword_list **root, char const *kw,
                                char const *value) {
  struct keyword_list *kp;
  void *tmp;
  char *tmp___0;

  {
    {
      tmp = xmalloc(sizeof(*kp));
      kp = (struct keyword_list *)tmp;
      kp->pattern = xstrdup(kw);
    }
    if (value) {
      {
        tmp___0 = xstrdup(value);
        kp->value = tmp___0;
      }
    } else {
      kp->value = (char *)((void *)0);
    }
    kp->next = *root;
    *root = kp;
    return;
  }
}
static void xheader_list_destroy(struct keyword_list **root) {
  struct keyword_list *kw;
  struct keyword_list *next;

  {

    return;
  }
}
static __attribute__((__noreturn__)) void xheader_set_single_keyword(char *kw);
static void xheader_set_single_keyword(char *kw) {
  char *tmp;
  char *__cil_tmp3;

  {
    {
      tmp = gettext("Keyword %s is unknown or not yet imlemented");
      error(0, 0, (char const *)tmp, kw);
      usage(2);
    }
  }
}
static void xheader_set_keyword_equal(char *kw, char *eq) {
  _Bool global;
  char *p;
  unsigned short const **tmp;
  unsigned short const **tmp___0;
  char *tmp___1;
  _Bool tmp___2;
  char *tmp___3;
  _Bool tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  char *__cil_tmp14;
  char *__cil_tmp15;

  {
    global = (_Bool)1;
    p = eq;
    if ((int)*(eq + -1) == 58) {
      p--;
      global = (_Bool)0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if ((unsigned long)p > (unsigned long)kw) {
          {
            tmp = __ctype_b_loc();
          }
          if (!((int const) * (*tmp + (int)*p) & 8192)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        p--;
      }
    while_break: /* CIL Label */
        ;
    }
    *p = (char)0;
    p = eq + 1;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (*p) {
          {
            tmp___0 = __ctype_b_loc();
          }
          if (!((int const) * (*tmp___0 + (int)*p) & 8192)) {
            goto while_break___0;
          }
        } else {
          goto while_break___0;
        }
        p++;
      }
    while_break___0: /* CIL Label */
        ;
    }
    { tmp___7 = strcmp((char const *)kw, "delete"); }
    if (tmp___7 == 0) {
      {
        tmp___2 = xheader_protected_pattern_p((char const *)p);
      }
      if (tmp___2) {
        {
          tmp___1 = gettext("Pattern %s cannot be used");
          error(0, 0, (char const *)tmp___1, p);
          usage(2);
        }
      }
      {
        xheader_list_append(&keyword_pattern_list, (char const *)p,
                            (char const *)((void *)0));
      }
    } else {
      { tmp___6 = strcmp((char const *)kw, "exthdr.name"); }
      if (tmp___6 == 0) {
        {
          assign_string(&exthdr_name, (char const *)p);
        }
      } else {
        { tmp___5 = strcmp((char const *)kw, "globexthdr.name"); }
        if (tmp___5 == 0) {
          {
            assign_string(&globexthdr_name, (char const *)p);
          }
        } else {
          { tmp___4 = xheader_protected_keyword_p((char const *)kw); }
          if (tmp___4) {
            {
              tmp___3 = gettext("Keyword %s cannot be overridden");
              error(0, 0, (char const *)tmp___3, kw);
              usage(2);
            }
          }
          if (global) {
            {
              xheader_list_append(&keyword_global_override_list,
                                  (char const *)kw, (char const *)p);
            }
          } else {
            {
              xheader_list_append(&keyword_override_list, (char const *)kw,
                                  (char const *)p);
            }
          }
        }
      }
    }
    return;
  }
}
void xheader_set_option(char *string) {
  char *token;
  char *p;
  char *tmp;

  {
    {
      token = strtok((char * /* __restrict  */)string,
                     (char const * /* __restrict  */) ",");
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!token) {
          goto while_break;
        }
        {
          tmp = strchr((char const *)token, '=');
          p = tmp;
        }
        if (!p) {
          {
            xheader_set_single_keyword(token);
          }
        } else {
          { xheader_set_keyword_equal(token, p); }
        }
        {
          token = strtok((char * /* __restrict  */)((void *)0),
                         (char const * /* __restrict  */) ",");
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static void to_decimal(uintmax_t value, char *where, size_t size) {
  size_t i;
  size_t j;
  size_t tmp;
  size_t tmp___0;
  char c;

  {
    i = (size_t)0;
    tmp = i;
    i++;
    *(where + tmp) = (char)0;
    {

    while_break: /* CIL Label */
        ;
    }
    j = (size_t)0;
    i--;
    {

    while_break___0: /* CIL Label */
        ;
    }
    return;
  }
}
static char *xheader_format_name(struct tar_stat_info *st, char const *fmt,
                                 _Bool allow_n) {
  char *buf;
  size_t len;
  size_t tmp;
  char *q;
  char const *p;
  char *dir;
  char *base;
  char pidbuf[64];
  char nbuf[64];
  char *tmp___0;
  size_t tmp___1;
  size_t tmp___2;
  __pid_t tmp___3;
  size_t tmp___4;
  size_t tmp___5;
  char *tmp___6;
  void *tmp___7;
  char *tmp___8;
  char const *tmp___9;
  char *tmp___10;
  char const *tmp___11;
  char *tmp___12;
  char const *tmp___13;
  char *tmp___14;
  char const *tmp___15;
  void *__cil_tmp29;
  void *__cil_tmp30;

  {
    {
      tmp = strlen(fmt);
      len = tmp;
      dir = (char *)((void *)0);
      base = (char *)((void *)0);
      p = fmt;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (*p) {
          {
            tmp___6 = strchr(p, '%');
            p = (char const *)tmp___6;
          }
          if (!p) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        {
          if ((int const) * (p + 1) == 37) {
            goto case_37;
          }
          if ((int const) * (p + 1) == 100) {
            goto case_100;
          }
          if ((int const) * (p + 1) == 102) {
            goto case_102;
          }
          if ((int const) * (p + 1) == 112) {
            goto case_112;
          }
          if ((int const) * (p + 1) == 110) {
            goto case_110;
          }
          goto switch_break;
        case_37: /* CIL Label */
          len--;
          goto switch_break;
        case_100: /* CIL Label */
          if (st) {
            {
              tmp___0 = dir_name((char const *)st->orig_file_name);
              dir = safer_name_suffix((char const *)tmp___0, (_Bool)0);
              tmp___1 = strlen((char const *)dir);
              len += tmp___1 - 1UL;
            }
          }
          goto switch_break;
        case_102: /* CIL Label */
          if (st) {
            {
              base = base_name((char const *)st->orig_file_name);
              tmp___2 = strlen((char const *)base);
              len += tmp___2 - 1UL;
            }
          }
          goto switch_break;
        case_112: { /* CIL Label */
          tmp___3 = getpid();
          to_decimal((uintmax_t)tmp___3, pidbuf, sizeof(pidbuf));
          tmp___4 = strlen((char const *)(pidbuf));
          len += tmp___4 - 1UL;
        }
          goto switch_break;
        case_110: /* CIL Label */

          goto switch_break;
        switch_break: /* CIL Label */
            ;
        }
        p++;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      tmp___7 = xmalloc(len + 1UL);
      buf = (char *)tmp___7;
      q = buf;
      p = fmt;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!*p) {
          goto while_break___0;
        }
        if ((int const) * p == 37) {
          {
            if ((int const) * (p + 1) == 37) {
              goto case_37___0;
            }
            if ((int const) * (p + 1) == 100) {
              goto case_100___0;
            }
            if ((int const) * (p + 1) == 102) {
              goto case_102___0;
            }
            if ((int const) * (p + 1) == 112) {
              goto case_112___0;
            }

            goto switch_default;
          case_37___0: /* CIL Label */
            tmp___8 = q;
            q++;
            tmp___9 = p;
            p++;
            *tmp___8 = (char)*tmp___9;
            p++;
            goto switch_break___0;
          case_100___0: /* CIL Label */
            if (dir) {
              {
                q = stpcpy((char * /* __restrict  */)q,
                           (char const * /* __restrict  */)dir);
              }
            }
            p += 2;
            goto switch_break___0;
          case_102___0: /* CIL Label */
            if (base) {
              {
                q = stpcpy((char * /* __restrict  */)q,
                           (char const * /* __restrict  */)base);
              }
            }
            p += 2;
            goto switch_break___0;
          case_112___0: { /* CIL Label */
            q = stpcpy((char * /* __restrict  */)q,
                       (char const * /* __restrict  */)(pidbuf));
            p += 2;
          }
            goto switch_break___0;
          case_110___0: /* CIL Label */
            if (allow_n) {
              {
                q = stpcpy((char * /* __restrict  */)q,
                           (char const * /* __restrict  */)(nbuf));
                p += 2;
              }
            }
          switch_default: /* CIL Label */
            tmp___10 = q;
            q++;
            tmp___11 = p;
            p++;
            *tmp___10 = (char)*tmp___11;
            if (*p) {
              tmp___12 = q;
              q++;
              tmp___13 = p;
              p++;
              *tmp___12 = (char)*tmp___13;
            }
          switch_break___0: /* CIL Label */
              ;
          }
        } else {
          tmp___14 = q;
          q++;
          tmp___15 = p;
          p++;
          *tmp___14 = (char)*tmp___15;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if ((unsigned long)q > (unsigned long)buf) {
          if (!((int)*(q + -1) == 47)) {
            goto while_break___1;
          }
        } else {
          goto while_break___1;
        }
        q--;
      }
    while_break___1: /* CIL Label */
        ;
    }
    *q = (char)0;
    return (buf);
  }
}
char *xheader_xhdr_name(struct tar_stat_info *st) {
  char *tmp;
  char *__cil_tmp3;

  {
    if (!exthdr_name) {
      {
        assign_string(&exthdr_name, "%d/PaxHeaders.%p/%f");
      }
    }
    { tmp = xheader_format_name(st, (char const *)exthdr_name, (_Bool)0); }
    return (tmp);
  }
}
char *xheader_ghdr_name(void) {
  size_t len;
  char const *tmp;
  char *tmp___0;
  size_t tmp___1;
  void *tmp___2;
  char *tmp___3;
  char *__cil_tmp7;
  char *__cil_tmp8;
  char *__cil_tmp9;
  char *__cil_tmp10;

  {

    {
      tmp___3 = xheader_format_name((struct tar_stat_info *)((void *)0),
                                    (char const *)globexthdr_name, (_Bool)1);
    }
    return (tmp___3);
  }
}
void xheader_write(char type, char *name, struct xheader *xhdr) {
  union block *header;
  size_t size;
  char *p;
  size_t len;

  {
    {
      size = xhdr->size;
      header = start_private_header((char const *)name, size);
      header->header.typeflag = type;
      simple_finish_header(header);
      p = xhdr->buffer;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          header = find_next_block();
          len = (size_t)512;
        }
        if (len > size) {
          len = size;
        }
        {
          memcpy((void * /* __restrict  */)(header->buffer),
                 (void const * /* __restrict  */)p, len);
        }
        if (len < 512UL) {
          {
            memset((void *)(header->buffer + len), 0, 512UL - len);
          }
        }
        {
          p += len;
          size -= len;
          set_next_block_after(header);
        }
        if (!(size > 0UL)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    { xheader_destroy(xhdr); }
    return;
  }
}
void xheader_write_global(void) {
  char *name;
  struct keyword_list *kp;

  {
    if (!keyword_global_override_list) {
      return;
    }
    {
      extended_header_init();
      kp = keyword_global_override_list;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!kp) {
          goto while_break;
        }
        {
          code_string((char const *)kp->value, (char const *)kp->pattern,
                      &extended_header);
          kp = kp->next;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      xheader_finish(&extended_header);
      name = xheader_ghdr_name();
      xheader_write((char)'g', name, &extended_header);
      free((void *)name);
      global_header_count++;
    }
    return;
  }
}
struct xhdr_tab const xhdr_tab[17];
static struct xhdr_tab const *locate_handler(char const *keyword) {
  struct xhdr_tab const *p;
  int tmp;

  {
    p = xhdr_tab;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!p->keyword) {
          goto while_break;
        }
        { tmp = strcmp((char const *)p->keyword, keyword); }
        if (tmp == 0) {
          return (p);
        }
        p++;
      }
    while_break: /* CIL Label */
        ;
    }
    return ((struct xhdr_tab const *)((void *)0));
  }
}
static _Bool xheader_protected_pattern_p(char const *pattern) {
  struct xhdr_tab const *p;
  int tmp;

  {
    p = xhdr_tab;
    {

    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)0);
  }
}
static _Bool xheader_protected_keyword_p(char const *keyword) {
  struct xhdr_tab const *p;
  int tmp;

  {
    p = xhdr_tab;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!p->keyword) {
          goto while_break;
        }
        if (p->protect) {
          {
            tmp = strcmp((char const *)p->keyword, keyword);
          }
          if (tmp == 0) {
            return ((_Bool)1);
          }
        }
        p++;
      }
    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)0);
  }
}

static void run_override_list(struct keyword_list *kp,
                              struct tar_stat_info *st) {
  struct xhdr_tab const *t;
  struct xhdr_tab const *tmp;

  {
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!kp) {
          goto while_break;
        }
        {
          tmp = locate_handler((char const *)kp->pattern);
          t = tmp;
        }
        if (t) {
          {
            (*(t->decoder))(st, (char const *)kp->value);
          }
        }
        kp = kp->next;
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}

void xheader_decode(struct tar_stat_info *st) {
  char *p;
  char *endp;
  _Bool tmp;

  {
    {
      run_override_list(keyword_global_override_list, st);
      run_override_list(global_header_override_list, st);
    }
    if (extended_header.size) {
      p = extended_header.buffer + 512;
      endp = extended_header.buffer + (extended_header.size - 1UL);
      {

      while_break: /* CIL Label */
          ;
      }
    }
    { run_override_list(keyword_override_list, st); }
    return;
  }
}

void xheader_decode_global(void) {
  char *p;
  char *endp;
  _Bool tmp;

  {
    if (extended_header.size) {
      {
        p = extended_header.buffer + 512;
        endp = extended_header.buffer + (extended_header.size - 1UL);
        xheader_list_destroy(&global_header_override_list);
      }
      {

      while_break: /* CIL Label */
          ;
      }
    }
    return;
  }
}
static void extended_header_init(void) {
  void *tmp;

  {
    if (!extended_header.stk) {
      {
        tmp = xmalloc(sizeof(*(extended_header.stk)));
        extended_header.stk = (struct obstack *)tmp;
        _obstack_begin(extended_header.stk, 0, 0, (void *(*)(long))(&xmalloc),
                       (void (*)(void *))(&free));
      }
    }
    return;
  }
}
void xheader_store(char const *keyword, struct tar_stat_info const *st,
                   void *data) {
  struct xhdr_tab const *t;
  _Bool tmp;
  _Bool tmp___0;

  {

    { t = locate_handler(keyword); }
    if (!t) {
      return;
    }
    { tmp = xheader_keyword_deleted_p(keyword); }
    if (tmp) {
      return;
    } else {
      { tmp___0 = xheader_keyword_override_p(keyword); }
      if (tmp___0) {
        return;
      }
    }
    {
      extended_header_init();
      (*(t->coder))(st, keyword, &extended_header, data);
    }
    return;
  }
}
void xheader_read(union block *p, size_t size) {
  size_t j;
  size_t nblocks;
  void *tmp;
  size_t len;

  {
    {
      j = (size_t)0;
      free((void *)extended_header.buffer);
      size += 512UL;
      extended_header.size = size;
      nblocks = ((size + 512UL) - 1UL) / 512UL;
      tmp = xmalloc(size + 1UL);
      extended_header.buffer = (char *)tmp;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        len = size;
        if (len > 512UL) {
          len = (size_t)512;
        }
        {
          memcpy((void * /* __restrict  */)(extended_header.buffer + j),
                 (void const * /* __restrict  */)(p->buffer), len);
          set_next_block_after(p);
          p = find_next_block();
          j += len;
          size -= len;
        }
        if (!(size > 0UL)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static size_t format_uintmax(uintmax_t val, char *buf, size_t s) {
  char *p;
  char *tmp;
  char *tmp___0;

  {
    if (!buf) {
      s = (size_t)0;
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          s++;
          val /= 10UL;
          if (!(val != 0UL)) {
            goto while_break;
          }
        }
      while_break: /* CIL Label */
          ;
      }
    } else {
      p = (buf + s) - 1;
      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;
          tmp = p;
          p--;
          *tmp = (char)(val % 10UL + 48UL);
          val /= 10UL;
          if (!(val != 0UL)) {
            goto while_break___0;
          }
        }
      while_break___0: /* CIL Label */
          ;
      }
      {
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          if (!((unsigned long)p >= (unsigned long)buf)) {
            goto while_break___1;
          }
          tmp___0 = p;
          p--;
          *tmp___0 = (char)'0';
        }
      while_break___1: /* CIL Label */
          ;
      }
    }
    return (s);
  }
}
static void xheader_print(struct xheader *xhdr, char const *keyword,
                          char const *value) {
  size_t len;
  size_t tmp;
  size_t tmp___0;
  size_t p;
  size_t n;
  char nbuf[100];
  struct obstack *__o;
  int __len;
  struct obstack *__o___0;
  char *tmp___1;
  struct obstack *__o___1;
  int __len___0;
  size_t tmp___2;
  struct obstack *__o___2;
  char *tmp___3;
  struct obstack *__o___3;
  int __len___1;
  size_t tmp___4;
  struct obstack *__o___4;
  char *tmp___5;
  void *__cil_tmp24;

  {
    {
      tmp = strlen(keyword);
      tmp___0 = strlen(value);
      len = (tmp + tmp___0) + 3UL;
      n = (size_t)0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          p = n;
          n = format_uintmax(len + p, (char *)((void *)0), (size_t)0);
        }
        if (!(n != p)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      format_uintmax(len + n, nbuf, n);
      __o = xhdr->stk;
      __len = (int)n;
    }
    if ((unsigned long)(__o->next_free + __len) >
        (unsigned long)__o->chunk_limit) {
      {
        _obstack_newchunk(__o, __len);
      }
    }
    {
      memcpy((void * /* __restrict  */)__o->next_free,
             (void const * /* __restrict  */)(nbuf), (size_t)__len);
      __o->next_free += __len;
      __o___0 = xhdr->stk;
    }
    if ((unsigned long)(__o___0->next_free + 1) >
        (unsigned long)__o___0->chunk_limit) {
      {
        _obstack_newchunk(__o___0, 1);
      }
    }
    {
      tmp___1 = __o___0->next_free;
      (__o___0->next_free)++;
      *tmp___1 = (char)' ';
      __o___1 = xhdr->stk;
      tmp___2 = strlen(keyword);
      __len___0 = (int)tmp___2;
    }

    {
      memcpy((void * /* __restrict  */)__o___1->next_free,
             (void const * /* __restrict  */)keyword, (size_t)__len___0);
      __o___1->next_free += __len___0;
      __o___2 = xhdr->stk;
    }
    if ((unsigned long)(__o___2->next_free + 1) >
        (unsigned long)__o___2->chunk_limit) {
      {
        _obstack_newchunk(__o___2, 1);
      }
    }
    {
      tmp___3 = __o___2->next_free;
      (__o___2->next_free)++;
      *tmp___3 = (char)'=';
      __o___3 = xhdr->stk;
      tmp___4 = strlen(value);
      __len___1 = (int)tmp___4;
    }

    {
      memcpy((void * /* __restrict  */)__o___3->next_free,
             (void const * /* __restrict  */)value, (size_t)__len___1);
      __o___3->next_free += __len___1;
      __o___4 = xhdr->stk;
    }

    tmp___5 = __o___4->next_free;
    (__o___4->next_free)++;
    *tmp___5 = (char)'\n';
    return;
  }
}
void xheader_finish(struct xheader *xhdr) {
  struct keyword_list *kp;
  struct obstack *__o;
  char *tmp;
  struct obstack *__o1;
  void *value;

  {
    kp = keyword_override_list;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!kp) {
          goto while_break;
        }
        {
          code_string((char const *)kp->value, (char const *)kp->pattern, xhdr);
          kp = kp->next;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    __o = xhdr->stk;
    if ((unsigned long)(__o->next_free + 1) > (unsigned long)__o->chunk_limit) {
      {
        _obstack_newchunk(__o, 1);
      }
    }
    tmp = __o->next_free;
    (__o->next_free)++;
    *tmp = (char)0;
    __o1 = xhdr->stk;
    value = (void *)__o1->object_base;
    if ((unsigned long)__o1->next_free == (unsigned long)value) {
      __o1->maybe_empty_object = 1U;
    }
    __o1->next_free =
        (char *)0 +
        (((__o1->next_free - (char *)0) + (long)__o1->alignment_mask) &
         (long)(~__o1->alignment_mask));

    {
      __o1->object_base = __o1->next_free;
      xhdr->buffer = (char *)value;
      xhdr->size = strlen((char const *)xhdr->buffer);
    }
    return;
  }
}
void xheader_destroy(struct xheader *xhdr) {
  struct obstack *__o;
  void *__obj;
  char *tmp;

  {
    if (xhdr->stk) {
      __o = xhdr->stk;
      __obj = (void *)0;

      {
        free((void *)xhdr->stk);
        xhdr->stk = (struct obstack *)((void *)0);
      }
    } else {
      { free((void *)xhdr->buffer); }
    }
    xhdr->buffer = (char *)0;
    xhdr->size = (size_t)0;
    return;
  }
}
static void code_string(char const *string, char const *keyword,
                        struct xheader *xhdr) {
  char *outstr;
  _Bool tmp;

  {
    { tmp = utf8_convert((_Bool)1, string, &outstr); }
    if (!tmp) {
      {
        outstr = xstrdup(string);
      }
    }
    {
      xheader_print(xhdr, keyword, (char const *)outstr);
      free((void *)outstr);
    }
    return;
  }
}
static void decode_string(char **string, char const *arg) {
  _Bool tmp;

  {
    if (*string) {
      {
        free((void *)*string);
        *string = (char *)((void *)0);
      }
    }
    { tmp = utf8_convert((_Bool)0, arg, string); }
    if (!tmp) {
      {
        assign_string(string, arg);
      }
    }
    return;
  }
}
static void code_time(time_t t, unsigned long nano, char const *keyword,
                      struct xheader *xhdr) {
  char sbuf[200];
  size_t s;
  size_t tmp;
  size_t tmp___0;
  size_t tmp___1;
  void *__cil_tmp10;

  {
    {
      tmp = format_uintmax((uintmax_t)t, (char *)((void *)0), (size_t)0);
      s = tmp;
    }
    if (s + 11UL >= sizeof(sbuf)) {
      return;
    }
    {
      format_uintmax((uintmax_t)t, sbuf, s);
      tmp___0 = s;
      s++;
      sbuf[tmp___0] = (char)'.';
      tmp___1 = format_uintmax(nano, sbuf + s, (size_t)9);
      s += tmp___1;
      sbuf[s] = (char)0;
      xheader_print(xhdr, keyword, (char const *)(sbuf));
    }
    return;
  }
}
static void decode_time(char const *arg, time_t *secs, unsigned long *nsecs) {
  uintmax_t u;
  char *p;
  strtol_error tmp;
  strtol_error tmp___0;
  char *__cil_tmp8;
  char *__cil_tmp9;

  {
    { tmp___0 = xstrtoumax(arg, &p, 10, &u, ""); }
    if ((unsigned int)tmp___0 == 0U) {
      *secs = (time_t)u;
      if ((int)*p == 46) {
        {
          tmp = xstrtoumax((char const *)(p + 1), (char **)((void *)0), 10, &u,
                           "");
        }
        if ((unsigned int)tmp == 0U) {
          *nsecs = u;
        }
      }
    }
    return;
  }
}
static void code_num(uintmax_t value, char const *keyword,
                     struct xheader *xhdr) {
  char sbuf[100];
  size_t s;
  size_t tmp;
  void *__cil_tmp7;

  {
    {
      tmp = format_uintmax(value, (char *)((void *)0), (size_t)0);
      s = tmp;
      format_uintmax(value, sbuf, s);
      sbuf[s] = (char)0;
      xheader_print(xhdr, keyword, (char const *)(sbuf));
    }
    return;
  }
}
static void dummy_coder(struct tar_stat_info const *st
                        __attribute__((__unused__)),
                        char const *keyword __attribute__((__unused__)),
                        struct xheader *xhdr __attribute__((__unused__)),
                        void *data __attribute__((__unused__))) {

  { return; }
}
static void dummy_decoder(struct tar_stat_info *st __attribute__((__unused__)),
                          char const *arg __attribute__((__unused__))) {

  { return; }
}
static void atime_coder(struct tar_stat_info const *st, char const *keyword,
                        struct xheader *xhdr,
                        void *data __attribute__((__unused__))) {

  {
    {
      code_time((time_t)st->stat.st_atim.tv_sec, (unsigned long)st->atime_nsec,
                keyword, xhdr);
    }
    return;
  }
}
static void atime_decoder(struct tar_stat_info *st, char const *arg) {

  {
    { decode_time(arg, &st->stat.st_atim.tv_sec, &st->atime_nsec); }
    return;
  }
}
static void gid_coder(struct tar_stat_info const *st, char const *keyword,
                      struct xheader *xhdr,
                      void *data __attribute__((__unused__))) {

  {
    { code_num((uintmax_t)st->stat.st_gid, keyword, xhdr); }
    return;
  }
}
static void gid_decoder(struct tar_stat_info *st, char const *arg) {
  uintmax_t u;
  strtol_error tmp;
  char *__cil_tmp5;

  {
    { tmp = xstrtoumax(arg, (char **)((void *)0), 10, &u, ""); }
    if ((unsigned int)tmp == 0U) {
      st->stat.st_gid = (__gid_t)u;
    }
    return;
  }
}
static void gname_coder(struct tar_stat_info const *st, char const *keyword,
                        struct xheader *xhdr,
                        void *data __attribute__((__unused__))) {

  {
    { code_string((char const *)st->gname, keyword, xhdr); }
    return;
  }
}
static void gname_decoder(struct tar_stat_info *st, char const *arg) {

  {
    { decode_string(&st->gname, arg); }
    return;
  }
}
static void linkpath_coder(struct tar_stat_info const *st, char const *keyword,
                           struct xheader *xhdr,
                           void *data __attribute__((__unused__))) {

  {
    { code_string((char const *)st->link_name, keyword, xhdr); }
    return;
  }
}
static void linkpath_decoder(struct tar_stat_info *st, char const *arg) {

  {
    { decode_string(&st->link_name, arg); }
    return;
  }
}
static void ctime_coder(struct tar_stat_info const *st, char const *keyword,
                        struct xheader *xhdr,
                        void *data __attribute__((__unused__))) {

  {
    {
      code_time((time_t)st->stat.st_ctim.tv_sec, (unsigned long)st->ctime_nsec,
                keyword, xhdr);
    }
    return;
  }
}
static void ctime_decoder(struct tar_stat_info *st, char const *arg) {

  {
    { decode_time(arg, &st->stat.st_ctim.tv_sec, &st->ctime_nsec); }
    return;
  }
}
static void mtime_coder(struct tar_stat_info const *st, char const *keyword,
                        struct xheader *xhdr,
                        void *data __attribute__((__unused__))) {

  {
    {
      code_time((time_t)st->stat.st_mtim.tv_sec, (unsigned long)st->mtime_nsec,
                keyword, xhdr);
    }
    return;
  }
}
static void mtime_decoder(struct tar_stat_info *st, char const *arg) {

  {
    { decode_time(arg, &st->stat.st_mtim.tv_sec, &st->mtime_nsec); }
    return;
  }
}
static void path_coder(struct tar_stat_info const *st, char const *keyword,
                       struct xheader *xhdr,
                       void *data __attribute__((__unused__))) {

  {
    { code_string((char const *)st->file_name, keyword, xhdr); }
    return;
  }
}
static void path_decoder(struct tar_stat_info *st, char const *arg) {

  {
    {
      decode_string(&st->orig_file_name, arg);
      decode_string(&st->file_name, arg);
      st->had_trailing_slash = strip_trailing_slashes(st->file_name);
    }
    return;
  }
}
static void size_coder(struct tar_stat_info const *st, char const *keyword,
                       struct xheader *xhdr,
                       void *data __attribute__((__unused__))) {

  {
    { code_num((uintmax_t)st->stat.st_size, keyword, xhdr); }
    return;
  }
}
static void size_decoder(struct tar_stat_info *st, char const *arg) {
  uintmax_t u;
  __off_t tmp;
  strtol_error tmp___0;
  char *__cil_tmp6;

  {
    { tmp___0 = xstrtoumax(arg, (char **)((void *)0), 10, &u, ""); }
    if ((unsigned int)tmp___0 == 0U) {
      tmp = (__off_t)u;
      st->stat.st_size = tmp;
      st->archive_file_size = tmp;
    }
    return;
  }
}
static void uid_coder(struct tar_stat_info const *st, char const *keyword,
                      struct xheader *xhdr,
                      void *data __attribute__((__unused__))) {

  {
    { code_num((uintmax_t)st->stat.st_uid, keyword, xhdr); }
    return;
  }
}
static void uid_decoder(struct tar_stat_info *st, char const *arg) {
  uintmax_t u;
  strtol_error tmp;
  char *__cil_tmp5;

  {
    { tmp = xstrtoumax(arg, (char **)((void *)0), 10, &u, ""); }
    if ((unsigned int)tmp == 0U) {
      st->stat.st_uid = (__uid_t)u;
    }
    return;
  }
}
static void uname_coder(struct tar_stat_info const *st, char const *keyword,
                        struct xheader *xhdr,
                        void *data __attribute__((__unused__))) {

  {
    { code_string((char const *)st->uname, keyword, xhdr); }
    return;
  }
}
static void uname_decoder(struct tar_stat_info *st, char const *arg) {

  {
    { decode_string(&st->uname, arg); }
    return;
  }
}
static void sparse_size_coder(struct tar_stat_info const *st,
                              char const *keyword, struct xheader *xhdr,
                              void *data) {

  {
    { size_coder(st, keyword, xhdr, data); }
    return;
  }
}
static void sparse_size_decoder(struct tar_stat_info *st, char const *arg) {
  uintmax_t u;
  strtol_error tmp;
  char *__cil_tmp5;

  {
    { tmp = xstrtoumax(arg, (char **)((void *)0), 10, &u, ""); }
    if ((unsigned int)tmp == 0U) {
      st->stat.st_size = (__off_t)u;
    }
    return;
  }
}
static void sparse_numblocks_coder(struct tar_stat_info const *st,
                                   char const *keyword, struct xheader *xhdr,
                                   void *data __attribute__((__unused__))) {

  {
    { code_num((uintmax_t)st->sparse_map_avail, keyword, xhdr); }
    return;
  }
}
static void sparse_numblocks_decoder(struct tar_stat_info *st,
                                     char const *arg) {
  uintmax_t u;
  void *tmp;
  strtol_error tmp___0;
  char *__cil_tmp6;

  {
    { tmp___0 = xstrtoumax(arg, (char **)((void *)0), 10, &u, ""); }
    if ((unsigned int)tmp___0 == 0U) {
      {
        st->sparse_map_size = u;
        tmp = calloc(st->sparse_map_size, sizeof(*(st->sparse_map + 0)));
        st->sparse_map = (struct sp_array *)tmp;
        st->sparse_map_avail = (size_t)0;
      }
    }
    return;
  }
}
static void sparse_offset_coder(struct tar_stat_info const *st,
                                char const *keyword, struct xheader *xhdr,
                                void *data) {
  size_t i;

  {
    {
      i = *((size_t *)data);
      code_num((uintmax_t)(st->sparse_map + i)->offset, keyword, xhdr);
    }
    return;
  }
}
static void sparse_offset_decoder(struct tar_stat_info *st, char const *arg) {
  uintmax_t u;
  strtol_error tmp;
  char *__cil_tmp5;

  {
    { tmp = xstrtoumax(arg, (char **)((void *)0), 10, &u, ""); }

    return;
  }
}
static void sparse_numbytes_coder(struct tar_stat_info const *st,
                                  char const *keyword, struct xheader *xhdr,
                                  void *data) {
  size_t i;

  {
    {
      i = *((size_t *)data);
      code_num((st->sparse_map + i)->numbytes, keyword, xhdr);
    }
    return;
  }
}
static void sparse_numbytes_decoder(struct tar_stat_info *st, char const *arg) {
  uintmax_t u;
  void *tmp;
  size_t tmp___0;
  strtol_error tmp___1;
  char *__cil_tmp7;

  {
    { tmp___1 = xstrtoumax(arg, (char **)((void *)0), 10, &u, ""); }

    return;
  }
}
struct xhdr_tab const xhdr_tab[17] = {
    {"atime", &atime_coder, &atime_decoder, (_Bool)0},
    {"comment", &dummy_coder, &dummy_decoder, (_Bool)0},
    {"charset", &dummy_coder, &dummy_decoder, (_Bool)0},
    {"ctime", &ctime_coder, &ctime_decoder, (_Bool)0},
    {"gid", &gid_coder, &gid_decoder, (_Bool)0},
    {"gname", &gname_coder, &gname_decoder, (_Bool)0},
    {"linkpath", &linkpath_coder, &linkpath_decoder, (_Bool)0},
    {"mtime", &mtime_coder, &mtime_decoder, (_Bool)0},
    {"path", &path_coder, &path_decoder, (_Bool)0},
    {"size", &size_coder, &size_decoder, (_Bool)0},
    {"uid", &uid_coder, &uid_decoder, (_Bool)0},
    {"uname", &uname_coder, &uname_decoder, (_Bool)0},
    {"GNU.sparse.size", &sparse_size_coder, &sparse_size_decoder, (_Bool)1},
    {"GNU.sparse.numblocks", &sparse_numblocks_coder, &sparse_numblocks_decoder,
     (_Bool)1},
    {"GNU.sparse.offset", &sparse_offset_coder, &sparse_offset_decoder,
     (_Bool)1},
    {"GNU.sparse.numbytes", &sparse_numbytes_coder, &sparse_numbytes_decoder,
     (_Bool)1},
    {(char const *)((void *)0),
     (void (*)(struct tar_stat_info const *, char const *, struct xheader *,
               void *data))((void *)0),
     (void (*)(struct tar_stat_info *, char const *))((void *)0), (_Bool)0}};
/* #pragma merger("0","006.incremen.o.i","") */
extern void(__attribute__((__nonnull__(1, 4))) qsort)(
    void *__base, size_t __nmemb, size_t __size,
    int (*__compar)(void const *, void const *));
extern __attribute__((__nothrow__))
FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);
extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream);
extern int fseek(FILE *__stream, long __off, int __whence);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(
    FILE *__stream);
size_t hash_do_for_each(Hash_table const *table___0,
                        _Bool (*processor)(void *, void *),
                        void *processor_data);
size_t hash_string(char const *string, size_t n_buckets);
char const *program_name;
void read_directory_file(void);
char *quote_copy_string(char const *string);
int unquote_string(char *string);
void savedir_error(char const *name);
void seek_error(char const *name);
void truncate_error(char const *name);
char *new_name(char const *path, char const *name);
static Hash_table *directory_table;
static unsigned int hash_directory(void const *entry, unsigned int n_buckets) {
  struct directory const *directory;
  size_t tmp;

  {
    {
      directory = (struct directory const *)entry;
      tmp = hash_string((char const *)(directory->name), (size_t)n_buckets);
    }
    return ((unsigned int)tmp);
  }
}
static _Bool compare_directories(void const *entry1, void const *entry2) {
  struct directory const *directory1;
  struct directory const *directory2;
  int tmp;

  {
    {
      directory1 = (struct directory const *)entry1;
      directory2 = (struct directory const *)entry2;
      tmp = strcmp((char const *)(directory1->name),
                   (char const *)(directory2->name));
    }
    return ((_Bool)(tmp == 0));
  }
}
static struct directory *note_directory(char const *name, dev_t dev, ino_t ino,
                                        _Bool nfs, _Bool found) {
  size_t size;
  size_t tmp;
  struct directory *directory;
  void *tmp___0;
  void *tmp___1;

  {
    {
      tmp = strlen(name);
      size = ((unsigned long)(&((struct directory *)0)->name) + tmp) + 1UL;
      tmp___0 = xmalloc(size);
      directory = (struct directory *)tmp___0;
      directory->device_number = dev;
      directory->inode_number = ino;
      directory->children = (enum children)1;
      directory->nfs = nfs;
      directory->found = found;
      strcpy((char * /* __restrict  */)(directory->name),
             (char const * /* __restrict  */)name);
    }
    if (directory_table) {
      goto _L;
    } else {
      {
        directory_table =
            hash_initialize((size_t)0, (Hash_tuning const *)0,
                            (size_t(*)(void const *, size_t))(&hash_directory),
                            &compare_directories, (void (*)(void *))0);
      }
      if (directory_table) {
      _L: { tmp___1 = hash_insert(directory_table, (void const *)directory); }

      } else {
        { xalloc_die(); }
      }
    }
    return (directory);
  }
}
static struct directory *find_directory(char *name) {
  size_t size;
  size_t tmp;
  struct directory *dir;
  void *tmp___0;
  void *tmp___1;

  {
    if (!directory_table) {
      return ((struct directory *)0);
    } else {
      {
        tmp = strlen((char const *)name);
        size = ((unsigned long)(&((struct directory *)0)->name) + tmp) + 1UL;
        tmp___0 = __builtin_alloca(size);
        dir = (struct directory *)tmp___0;
        strcpy((char * /* __restrict  */)(dir->name),
               (char const * /* __restrict  */)name);
        tmp___1 =
            hash_lookup((Hash_table const *)directory_table, (void const *)dir);
      }
      return ((struct directory *)tmp___1);
    }
  }
}
static int compare_dirents(void const *first, void const *second) {
  int tmp;

  {
    {
      tmp = strcmp((char const *)(*((char *const *)first) + 1),
                   (char const *)(*((char *const *)second) + 1));
    }
    return (tmp);
  }
}
static void scan_path(struct obstack *stk, char *path, dev_t device) {
  char *dirp;
  char *tmp;
  char const *entry;
  size_t entrylen;
  char *name_buffer___0;
  size_t name_buffer_size;
  size_t name_length;
  struct directory *directory;
  enum children children;
  int *tmp___0;
  size_t tmp___1;
  void *tmp___2;
  size_t tmp___3;
  void *tmp___4;
  struct obstack *__o;
  char *tmp___5;
  struct stat stat_data;
  int tmp___6;
  _Bool nfs;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  char *tmp___10;
  struct obstack *__o___0;
  char *tmp___11;
  struct obstack *__o___1;
  char *tmp___12;
  struct obstack *__o___2;
  char *tmp___13;
  struct obstack *__o___3;
  char *tmp___14;
  _Bool tmp___15;
  struct obstack *__o___4;
  int __len;
  struct obstack *__o___5;
  int __len___0;
  unsigned int tmp___16;
  int tmp___17;
  void *__cil_tmp42;
  char *__cil_tmp43;
  char *__cil_tmp44;
  char *__cil_tmp45;
  char *__cil_tmp46;

  {
    {
      tmp = savedir((char const *)path);
      dirp = tmp;
    }
    if (!dirp) {
      {
        savedir_error((char const *)path);
      }
    }
    {
      tmp___0 = __errno_location();
      *tmp___0 = 0;
      tmp___1 = strlen((char const *)path);
      name_buffer_size = tmp___1 + 100UL;
      tmp___2 = xmalloc(name_buffer_size + 2UL);
      name_buffer___0 = (char *)tmp___2;
      strcpy((char * /* __restrict  */)name_buffer___0,
             (char const * /* __restrict  */)path);
      tmp___3 = strlen((char const *)path);
    }
    if (!((int)*(path + (tmp___3 - 1UL)) == 47)) {
      {
        strcat((char * /* __restrict  */)name_buffer___0,
               (char const * /* __restrict  */) "/");
      }
    }
    {
      name_length = strlen((char const *)name_buffer___0);
      directory = find_directory(path);
    }
    if (directory) {
      tmp___16 = (unsigned int)directory->children;
    } else {
      tmp___16 = 1U;
    }
    children = (enum children)tmp___16;
    if (dirp) {
      if ((unsigned int)children != 0U) {
        entry = (char const *)dirp;
        {
          while (1) {
          while_continue: /* CIL Label */
              ;
            { entrylen = strlen(entry); }
            if (!(entrylen != 0UL)) {
              goto while_break;
            }
            if (name_buffer_size <= entrylen + name_length) {
              {
                while (1) {
                while_continue___0: /* CIL Label */
                    ;
                  name_buffer_size += 100UL;
                  if (!(name_buffer_size <= entrylen + name_length)) {
                    goto while_break___0;
                  }
                }
              while_break___0: /* CIL Label */
                  ;
              }
              {
                tmp___4 =
                    xrealloc((void *)name_buffer___0, name_buffer_size + 2UL);
                name_buffer___0 = (char *)tmp___4;
              }
            }
            {
              strcpy((char * /* __restrict  */)(name_buffer___0 + name_length),
                     (char const * /* __restrict  */)entry);
              tmp___15 = excluded_name((char const *)name_buffer___0);
            }
            if (tmp___15) {
              __o = stk;
              if ((unsigned long)(__o->next_free + 1) >
                  (unsigned long)__o->chunk_limit) {
                {
                  _obstack_newchunk(__o, 1);
                }
              }
              tmp___5 = __o->next_free;
              (__o->next_free)++;
              *tmp___5 = (char)'N';
            } else {
              {
                tmp___6 = deref_stat(dereference_option,
                                     (char const *)name_buffer___0, &stat_data);
              }
              if (tmp___6) {
                {
                  stat_diag((char const *)name_buffer___0);
                }
                goto __Cont;
              }
              if ((stat_data.st_mode & 61440U) == 16384U) {
                {
                  nfs = (_Bool)((stat_data.st_dev &
                                 (0xffffffffffffffffUL
                                  << (sizeof(stat_data.st_dev) * 8UL - 1UL))) !=
                                0UL);
                  directory = find_directory(name_buffer___0);
                }
                if ((unsigned long)directory != (unsigned long)((void *)0)) {

                  directory->found = (_Bool)1;
                } else {

                  {
                    directory = note_directory((char const *)name_buffer___0,
                                               stat_data.st_dev,
                                               stat_data.st_ino, nfs, (_Bool)1);
                  }

                  directory->children = (enum children)tmp___17;
                }

                __o___0 = stk;
                if ((unsigned long)(__o___0->next_free + 1) >
                    (unsigned long)__o___0->chunk_limit) {
                  {
                    _obstack_newchunk(__o___0, 1);
                  }
                }
                tmp___11 = __o___0->next_free;
                (__o___0->next_free)++;
                *tmp___11 = (char)'D';
              } else {
                if (one_file_system_option) {

                } else {
                _L___12: /* CIL Label */
                  if ((unsigned int)children == 1U) {

                  } else {
                  _L___10: /* CIL Label */
                    __o___3 = stk;
                    if ((unsigned long)(__o___3->next_free + 1) >
                        (unsigned long)__o___3->chunk_limit) {
                      {
                        _obstack_newchunk(__o___3, 1);
                      }
                    }
                    tmp___14 = __o___3->next_free;
                    (__o___3->next_free)++;
                    *tmp___14 = (char)'Y';
                  }
                }
              }
            }
            __o___4 = stk;
            __len = (int)(entrylen + 1UL);
            if ((unsigned long)(__o___4->next_free + __len) >
                (unsigned long)__o___4->chunk_limit) {
              {
                _obstack_newchunk(__o___4, __len);
              }
            }
            {
              memcpy((void * /* __restrict  */)__o___4->next_free,
                     (void const * /* __restrict  */)entry, (size_t)__len);
              __o___4->next_free += __len;
            }
          __Cont:
            entry += entrylen + 1UL;
          }
        while_break: /* CIL Label */
            ;
        }
      }
    }
    __o___5 = stk;
    __len___0 = 2;
    if ((unsigned long)(__o___5->next_free + __len___0) >
        (unsigned long)__o___5->chunk_limit) {
      {
        _obstack_newchunk(__o___5, __len___0);
      }
    }
    {
      memcpy((void * /* __restrict  */)__o___5->next_free,
             (void const * /* __restrict  */) "\000\000", (size_t)__len___0);
      __o___5->next_free += __len___0;
      free((void *)name_buffer___0);
    }
    if (dirp) {
      {
        free((void *)dirp);
      }
    }
    return;
  }
}
static char *sort_obstack(struct obstack *stk) {
  char *pointer;
  struct obstack *__o1;
  void *value;
  size_t counter;
  char *cursor;
  char *buffer___2;
  char **array;
  char **array_cursor;
  size_t tmp;
  struct obstack *__h;
  struct obstack *__o;
  int __len;
  struct obstack *__o1___0;
  void *value___0;
  size_t tmp___0;
  char **tmp___1;
  void *tmp___2;
  char *string;
  char *tmp___3;
  char tmp___4;
  char *tmp___5;

  {
    __o1 = stk;
    value = (void *)__o1->object_base;
    if ((unsigned long)__o1->next_free == (unsigned long)value) {
      __o1->maybe_empty_object = 1U;
    }
    __o1->next_free =
        (char *)0 +
        (((__o1->next_free - (char *)0) + (long)__o1->alignment_mask) &
         (long)(~__o1->alignment_mask));
    if (__o1->next_free - (char *)__o1->chunk >
        __o1->chunk_limit - (char *)__o1->chunk) {
      __o1->next_free = __o1->chunk_limit;
    }
    __o1->object_base = __o1->next_free;
    pointer = (char *)value;
    counter = (size_t)0;
    cursor = pointer;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!*cursor) {
          goto while_break;
        }
        {
          counter++;
          tmp = strlen((char const *)cursor);
          cursor += tmp + 1UL;
        }
      }
    while_break: /* CIL Label */
        ;
    }

    __h = stk;
    __o = __h;
    __len = (int)(sizeof(char *) * (counter + 1UL));
    if (__o->chunk_limit - __o->next_free < (long)__len) {
      {
        _obstack_newchunk(__o, __len);
      }
    }
    __o->next_free += __len;
    __o1___0 = __h;
    value___0 = (void *)__o1___0->object_base;
    if ((unsigned long)__o1___0->next_free == (unsigned long)value___0) {
      __o1___0->maybe_empty_object = 1U;
    }
    __o1___0->next_free =
        (char *)0 +
        (((__o1___0->next_free - (char *)0) + (long)__o1___0->alignment_mask) &
         (long)(~__o1___0->alignment_mask));
    if (__o1___0->next_free - (char *)__o1___0->chunk >
        __o1___0->chunk_limit - (char *)__o1___0->chunk) {
      __o1___0->next_free = __o1___0->chunk_limit;
    }
    __o1___0->object_base = __o1___0->next_free;
    array = (char **)value___0;
    array_cursor = array;
    cursor = pointer;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!*cursor) {
          goto while_break___0;
        }
        {
          tmp___1 = array_cursor;
          array_cursor++;
          *tmp___1 = cursor;
          tmp___0 = strlen((char const *)cursor);
          cursor += tmp___0 + 1UL;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    {
      *array_cursor = (char *)0;
      qsort((void *)array, counter, sizeof(char *), &compare_dirents);
      tmp___2 = xmalloc((size_t)((cursor - pointer) + 2L));
      buffer___2 = (char *)tmp___2;
      cursor = buffer___2;
      array_cursor = array;
    }
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!*array_cursor) {
          goto while_break___1;
        }
        string = *array_cursor;
        {
          while (1) {
          while_continue___2: /* CIL Label */
              ;
            tmp___3 = cursor;
            cursor++;
            tmp___5 = string;
            string++;
            tmp___4 = *tmp___5;
            *tmp___3 = tmp___4;
            if (!tmp___4) {
              goto while_break___2;
            }
            goto while_continue___2;
          }
        while_break___2: /* CIL Label */
            ;
        }
        array_cursor++;
      }
    while_break___1: /* CIL Label */
        ;
    }
    *cursor = (char)'\000';
    return (buffer___2);
  }
}
char *get_directory_contents(char *path, dev_t device) {
  struct obstack stk;
  char *buffer___2;
  struct obstack *__o;
  void *__obj;
  char *tmp;

  {
    {
      _obstack_begin(&stk, 0, 0, (void *(*)(long))(&xmalloc),
                     (void (*)(void *))(&free));
      scan_path(&stk, path, device);
      buffer___2 = sort_obstack(&stk);
      __o = &stk;
      __obj = (void *)0;
    }

    return (buffer___2);
  }
}
static FILE *listed_incremental_stream;

static _Bool write_directory_file_entry(void *entry, void *data) {
  struct directory const *directory;
  FILE *fp;
  int e;
  char *str;
  char *tmp;
  int *tmp___0;
  int *tmp___1;
  int tmp___2;
  int tmp___3;
  char *tmp___4;

  {
    directory = (struct directory const *)entry;
    fp = (FILE *)data;
    if (directory->found) {
      {
        tmp = quote_copy_string((char const *)(directory->name));
        str = tmp;
      }
      if (str) {
        tmp___4 = (char * /* const  */)str;
      } else {
        tmp___4 = directory->name;
      }
      {
        fprintf(
            (FILE * /* __restrict  */)fp,
            (char const * /* __restrict  */)("+%lu %lu %s\n" + !directory->nfs),
            (unsigned long)directory->device_number,
            (unsigned long)directory->inode_number, tmp___4);
        tmp___0 = __errno_location();
        e = *tmp___0;
      }
      if (str) {
        {
          free((void *)str);
        }
      }
      {
        tmp___1 = __errno_location();
        *tmp___1 = e;
      }
    }
    { tmp___2 = ferror_unlocked(fp); }
    if (tmp___2) {
      tmp___3 = 0;
    } else {
      tmp___3 = 1;
    }
    return ((_Bool)tmp___3);
  }
}
void write_directory_file(void) {
  FILE *fp;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;

  {
    fp = listed_incremental_stream;
    if (!fp) {
      return;
    }
    { tmp = fseek(fp, 0L, 0); }
    if (tmp != 0) {
      {
        seek_error(listed_incremental_option);
      }
    }
    {
      tmp___0 = fileno(fp);
      tmp___1 = sys_truncate(tmp___0);
    }

    {
      fprintf((FILE * /* __restrict  */)fp,
              (char const * /* __restrict  */) "%lu\n",
              (unsigned long)start_timespec.tv_sec);
      tmp___2 = ferror_unlocked(fp);
    }
    if (!tmp___2) {
      if (directory_table) {
        {
          hash_do_for_each((Hash_table const *)directory_table,
                           &write_directory_file_entry, (void *)fp);
        }
      }
    }
    { tmp___3 = ferror_unlocked(fp); }

    { tmp___4 = fclose(fp); }
    if (tmp___4 != 0) {
      {
        close_error(listed_incremental_option);
      }
    }
    return;
  }
}
void gnu_restore(char const *directory_name) {
  char *archive_dir;
  char *current_dir;
  char *cur;
  char *arc;
  size_t size;
  size_t copied;
  union block *data_block;
  char *to;
  void *tmp;
  char *tmp___0;
  size_t tmp___1;
  size_t tmp___2;
  int tmp___3;
  char *p;
  char *tmp___4;
  char const *tmp___5;
  char *tmp___6;
  int e;
  int *tmp___7;
  char *tmp___8;
  char *tmp___9;
  int tmp___10;
  int tmp___11;
  char *__cil_tmp25;
  char *__cil_tmp26;
  char *__cil_tmp27;
  char *__cil_tmp28;

  {
    { current_dir = savedir(directory_name); }
    if (!current_dir) {
      {
        skip_member();
      }
      return;
    }
    size = (size_t)current_stat_info.stat.st_size;

    {
      tmp = xmalloc(size);
      archive_dir = (char *)tmp;
      to = archive_dir;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(size > 0UL)) {
          goto while_break;
        }
        { data_block = find_next_block(); }
        if (!data_block) {
          {
            tmp___0 = gettext("Unexpected EOF in archive");
            error(0, 0, (char const *)tmp___0);
            exit_status = 2;
          }
          goto while_break;
        }
        { copied = available_space_after(data_block); }
        if (copied > size) {
          copied = size;
        }
        {
          memcpy((void * /* __restrict  */)to,
                 (void const * /* __restrict  */)(data_block->buffer), copied);
          to += copied;
          set_next_block_after(
              (union block *)((data_block->buffer + copied) - 1));
          size -= copied;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    cur = current_dir;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!*cur) {
          goto while_break___0;
        }
        arc = archive_dir;
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            if (!*arc) {
              goto while_break___1;
            }
            {
              arc++;
              tmp___3 = strcmp((char const *)arc, (char const *)cur);
            }
            if (!tmp___3) {
              goto while_break___1;
            }
            {
              tmp___2 = strlen((char const *)arc);
              arc += tmp___2 + 1UL;
            }
          }
        while_break___1: /* CIL Label */
            ;
        }

        {
          tmp___1 = strlen((char const *)cur);
          cur += tmp___1 + 1UL;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    {
      free((void *)current_dir);
      free((void *)archive_dir);
    }
    return;
  }
}
/* #pragma merger("0","007.list.o.i","") */
extern __attribute__((__nothrow__)) unsigned long long(__attribute__((
    __leaf__)) gnu_dev_makedev)(unsigned int __major, unsigned int __minor)
    __attribute__((__const__));
extern int putc_unlocked(int __c, FILE *__stream);
extern size_t fwrite_unlocked(void const *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) struct tm *(
    __attribute__((__leaf__)) gmtime)(time_t const *__timer);
extern __attribute__((__nothrow__)) struct tm *(
    __attribute__((__leaf__)) localtime)(time_t const *__timer);
struct quoting_options *clone_quoting_options(struct quoting_options *o___0);
void set_quoting_style(struct quoting_options *o___0, enum quoting_style s);
size_t quotearg_buffer(char *buffer___2, size_t buffersize, char const *arg,
                       size_t argsize, struct quoting_options const *o___0);
char *quotearg(char const *arg);
_Bool utc_option;
_Bool block_number_option;
_Bool show_omitted_dirs_option;
gid_t gid_from_header(char const *p, size_t s);
int major_from_header(char const *p, size_t s);
int minor_from_header(char const *p, size_t s);
mode_t mode_from_header(char const *p, size_t s);
size_t size_from_header(char const *p, size_t s);
time_t time_from_header(char const *p, size_t s);
uid_t uid_from_header(char const *p, size_t s);
void list_archive(void);
void read_and(void (*do_something)(void));
void decode_mode(mode_t mode, char *string);
int name_match(char const *path);
_Bool all_names_found(struct tar_stat_info *p);
_Bool sparse_fixup_header(struct tar_stat_info *st);
enum dump_status sparse_skip_file(struct tar_stat_info *st);
static uintmax_t from_header(char const *where0, size_t digs, char const *type,
                             uintmax_t minus_minval, uintmax_t maxval);

static char base64_map[256];
static void base64_init(void) {
  int i;

  {
    {
      memset((void *)(base64_map), 64, sizeof(base64_map));
      i = 0;
    }
    {

    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
void read_and(void (*do_something)(void)) {
  enum read_header status;
  enum read_header prev_status;
  char *tmp;
  char *tmp___0;
  int tmp___1;
  _Bool tmp___2;
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  off_t tmp___3;
  char *tmp___4;
  char *tmp___5;
  char buf___0[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  off_t tmp___6;
  char *tmp___7;
  char *tmp___8;
  char buf___1[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  off_t tmp___9;
  char *tmp___10;
  char *tmp___11;
  char *tmp___12;
  char buf___2[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  off_t block_ordinal;
  off_t tmp___13;
  char *tmp___14;
  char *tmp___15;
  char *tmp___16;
  _Bool tmp___17;
  void *__cil_tmp28;
  void *__cil_tmp29;
  void *__cil_tmp30;
  void *__cil_tmp31;
  char *__cil_tmp32;
  char *__cil_tmp33;
  char *__cil_tmp34;
  char *__cil_tmp35;
  char *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;

  {
    {
      status = (enum read_header)0;
      base64_init();
      name_gather();
      open_archive((enum access_mode)0);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          prev_status = status;
          tar_stat_destroy(&current_stat_info);
          xheader_destroy(&extended_header);
          status = read_header((_Bool)0);
        }
        {
          if ((unsigned int)status == 0U) {
            goto case_0;
          }

          if ((unsigned int)status == 1U) {
            goto case_1;
          }
          if ((unsigned int)status == 3U) {
            goto case_3;
          }

          goto switch_break;
        case_0:   /* CIL Label */
        case_2: { /* CIL Label */
          abort();
        }
        case_1: { /* CIL Label */
          tmp___1 = name_match((char const *)current_stat_info.file_name);
        }

          { (*do_something)(); }
          goto __Cont;
        case_3: /* CIL Label */
          if (block_number_option) {
            {
              tmp___3 = current_block_ordinal();
              tmp___4 = stringify_uintmax_t_backwards(
                  (uintmax_t)tmp___3,
                  buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                         1UL));
              tmp___5 = gettext("block %s: ** Block of NULs **\n");
              fprintf((FILE * /* __restrict  */)stdlis,
                      (char const * /* __restrict  */)tmp___5, tmp___4);
            }
          }
          { set_next_block_after(current_header); }
          if (!ignore_zeros_option) {
            {
              status = read_header((_Bool)0);
            }
            if ((unsigned int)status == 3U) {
              goto switch_break;
            }
            {
              tmp___6 = current_block_ordinal();
              tmp___7 = stringify_uintmax_t_backwards(
                  (uintmax_t)tmp___6,
                  buf___0 +
                      ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                       1UL));
              tmp___8 = gettext("A lone zero block at %s");
              error(0, 0, (char const *)tmp___8, tmp___7);
            }
            goto switch_break;
          }
          status = prev_status;
          goto __Cont;
        case_4: /* CIL Label */

          goto switch_break;
        case_5: { /* CIL Label */
          set_next_block_after(current_header);
        }
          {
            if ((unsigned int)prev_status == 0U) {
              goto case_0___0;
            }
            if ((unsigned int)prev_status == 3U) {
              goto case_3___0;
            }
            if ((unsigned int)prev_status == 1U) {
              goto case_3___0;
            }

            if ((unsigned int)prev_status == 5U) {
              goto case_4___0;
            }
            if ((unsigned int)prev_status == 2U) {
              goto case_2___0;
            }
            goto switch_break___1;
          case_0___0: { /* CIL Label */
            tmp___12 = gettext("This does not look like a tar archive");
            error(0, 0, (char const *)tmp___12);
            exit_status = 2;
          }
          case_3___0: /* CIL Label */
          case_1___0: /* CIL Label */

          {
            tmp___16 = gettext("Skipping to next header");
            error(0, 0, (char const *)tmp___16);
            exit_status = 2;
          }
            goto switch_break___1;
          case_4___0: /* CIL Label */
          case_5___0: /* CIL Label */
            goto switch_break___1;
          case_2___0: { /* CIL Label */
            abort();
          }
          switch_break___1: /* CIL Label */
              ;
          }
          goto __Cont;
        switch_break: /* CIL Label */
            ;
        }
        goto while_break;
      __Cont: { tmp___17 = all_names_found(&current_stat_info); }
        if (tmp___17) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      close_archive();
      names_notfound();
    }
    return;
  }
}
void list_archive(void) {
  off_t size;
  size_t written;
  size_t check;
  union block *data_block;
  char *tmp;
  int *tmp___0;
  char *__cil_tmp7;

  {
    { decode_header(current_header, &current_stat_info, &current_format, 0); }

    if (incremental_option) {
      if ((int)current_header->header.typeflag == 68) {
        {
          set_next_block_after(current_header);
        }
        if (multi_volume_option) {
          {
            assign_string(&save_name,
                          (char const *)current_stat_info.file_name);
            save_totsize = current_stat_info.stat.st_size;
          }
        }
        size = current_stat_info.stat.st_size;
        {
          while (1) {
          while_continue: /* CIL Label */
              ;
            if (!(size > 0L)) {
              goto while_break;
            }

            { data_block = find_next_block(); }
            if (!data_block) {
              {
                tmp = gettext("Unexpected EOF in archive");
                error(0, 0, (char const *)tmp);
                exit_status = 2;
              }
              goto while_break;
            }
            { written = available_space_after(data_block); }
            if (written > (size_t)size) {
              written = (size_t)size;
            }
            {
              tmp___0 = __errno_location();
              *tmp___0 = 0;
              check = fwrite_unlocked(
                  (void const * /* __restrict  */)(data_block->buffer),
                  sizeof(char), written, (FILE * /* __restrict  */)stdlis);
              set_next_block_after(
                  (union block *)((data_block->buffer + written) - 1));
            }
            if (check != written) {
              {
                write_error_details((char const *)current_stat_info.file_name,
                                    check, written);
                skip_file((off_t)((size_t)size - written));
              }
              goto while_break;
            }
            size = (off_t)((size_t)size - written);
          }
        while_break: /* CIL Label */
            ;
        }

        {
          fputc_unlocked('\n', stdlis);
          fflush_unlocked(stdlis);
        }
        return;
      }
    }

    { skip_member(); }

    return;
  }
}
enum read_header read_header(_Bool raw_extended_headers) {
  size_t i;
  int unsigned_sum;
  int signed_sum;
  int recorded_sum;
  uintmax_t parsed_sum;
  char *p;
  union block *header;
  union block *header_copy;
  char *bp;
  union block *data_block;
  size_t size;
  size_t written;
  union block *next_long_name;
  union block *next_long_link;
  size_t next_long_name_blocks;
  size_t next_long_link_blocks;
  char *tmp;
  size_t tmp___0;
  size_t tmp___1;
  size_t name_size;
  void *tmp___2;
  char *tmp___3;
  off_t tmp___4;
  off_t tmp___5;
  char const *name;
  struct posix_header const *h;
  char namebuf[((sizeof(h->prefix) + 1UL) + 100UL) + 1UL];
  char *np;
  size_t tmp___6;
  char *tmp___7;
  int tmp___8;
  void *__cil_tmp33;
  char *__cil_tmp34;

  {
    next_long_name = (union block *)0;
    next_long_link = (union block *)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          header = find_next_block();
          current_header = header;
        }
        if (!header) {
          return ((enum read_header)4);
        }
        unsigned_sum = 0;
        signed_sum = 0;
        p = header->buffer;
        i = sizeof(*header);
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            tmp___0 = i;
            i--;
            if (!(tmp___0 != 0UL)) {
              goto while_break___0;
            }
            unsigned_sum += (int)((unsigned char)*p);
            tmp = p;
            p++;
            signed_sum += (int)((signed char)*tmp);
          }
        while_break___0: /* CIL Label */
            ;
        }
        if (unsigned_sum == 0) {
          return ((enum read_header)3);
        }
        i = sizeof(header->header.chksum);
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            tmp___1 = i;
            i--;
            if (!(tmp___1 != 0UL)) {
              goto while_break___1;
            }
            unsigned_sum -= (int)((unsigned char)header->header.chksum[i]);
            signed_sum -= (int)((signed char)header->header.chksum[i]);
          }
        while_break___1: /* CIL Label */
            ;
        }
        {
          unsigned_sum = (int)((unsigned long)unsigned_sum +
                               32UL * sizeof(header->header.chksum));
          signed_sum = (int)((unsigned long)signed_sum +
                             32UL * sizeof(header->header.chksum));
          parsed_sum = from_header(
              (char const *)(header->header.chksum),
              sizeof(header->header.chksum), (char const *)0, (uintmax_t)0,
              (uintmax_t)(-1 - (-1 << (sizeof(int) * 8UL - 1UL))));
        }
        if (parsed_sum == 0xffffffffffffffffUL) {
          return ((enum read_header)5);
        }
        recorded_sum = (int)parsed_sum;
        if (unsigned_sum != recorded_sum) {
          if (signed_sum != recorded_sum) {
            return ((enum read_header)5);
          }
        }
        if ((int)header->header.typeflag == 49) {
          current_stat_info.stat.st_size = (__off_t)0;
        } else {
          {
            current_stat_info.stat.st_size =
                off_from_header((char const *)(header->header.size),
                                sizeof(header->header.size));
          }
        }
        if ((int)header->header.typeflag == 76) {
          goto _L___4;
        } else {
          if ((int)header->header.typeflag == 75) {
            goto _L___4;
          } else {
            if ((int)header->header.typeflag == 120) {
              goto _L___4;
            } else {
              if ((int)header->header.typeflag == 103) {
              _L___4: /* CIL Label */
                if (raw_extended_headers) {
                  return ((enum read_header)2);
                } else {
                  if ((int)header->header.typeflag == 76) {
                    goto _L___3;
                  } else {
                    if ((int)header->header.typeflag == 75) {
                    _L___3: /* CIL Label */
                      name_size = (size_t)current_stat_info.stat.st_size;
                      size = (name_size - name_size % 512UL) + 1024UL;
                      if (name_size != (size_t)current_stat_info.stat.st_size) {
                        {
                          xalloc_die();
                        }
                      } else {
                      }
                      {
                        tmp___2 = xmalloc(size + 1UL);
                        header_copy = (union block *)tmp___2;
                      }
                      if ((int)header->header.typeflag == 76) {
                        if (next_long_name) {
                          {
                            free((void *)next_long_name);
                          }
                        }
                        next_long_name = header_copy;
                        next_long_name_blocks = size / 512UL;
                      } else {
                        if (next_long_link) {
                          {
                            free((void *)next_long_link);
                          }
                        }
                        next_long_link = header_copy;
                        next_long_link_blocks = size / 512UL;
                      }
                      {
                        set_next_block_after(header);
                        *header_copy = *header;
                        bp = header_copy->buffer + 512;
                        size -= 512UL;
                      }
                      {
                        while (1) {
                        while_continue___2: /* CIL Label */
                            ;
                          if (!(size > 0UL)) {
                            goto while_break___2;
                          }
                          { data_block = find_next_block(); }
                          if (!data_block) {
                            {
                              tmp___3 = gettext("Unexpected EOF in archive");
                              error(0, 0, (char const *)tmp___3);
                              exit_status = 2;
                            }
                            goto while_break___2;
                          }
                          { written = available_space_after(data_block); }
                          if (written > size) {
                            written = size;
                          }
                          {
                            memcpy((void * /* __restrict  */)bp,
                                   (void const * /* __restrict  */)(
                                       data_block->buffer),
                                   written);
                            bp += written;
                            set_next_block_after(
                                (union block *)((data_block->buffer + written) -
                                                1));
                            size -= written;
                          }
                        }
                      while_break___2: /* CIL Label */
                          ;
                      }
                      *bp = (char)'\000';
                    } else {
                      if ((int)header->header.typeflag == 120) {
                        {
                          tmp___4 = off_from_header(
                              (char const *)(header->header.size),
                              sizeof(header->header.size));
                          xheader_read(header, (size_t)tmp___4);
                        }
                      } else {
                        if ((int)header->header.typeflag == 103) {
                          {
                            tmp___5 = off_from_header(
                                (char const *)(header->header.size),
                                sizeof(header->header.size));
                            xheader_read(header, (size_t)tmp___5);
                            xheader_decode_global();
                          }
                        }
                      }
                    }
                  }
                }
              } else {
                h = (struct posix_header const *)(&current_header->header);
                if (recent_long_name) {
                  {
                    free((void *)recent_long_name);
                  }
                }
                if (next_long_name) {
                  name = (char const *)(next_long_name->buffer + 512);
                  recent_long_name = next_long_name;
                  recent_long_name_blocks = next_long_name_blocks;
                } else {
                  np = namebuf;
                  if (h->prefix[0]) {
                    {
                      tmp___8 = strcmp((char const *)(h->magic), "ustar");
                    }
                  }
                  {
                    memcpy((void * /* __restrict  */)np,
                           (void const * /* __restrict  */)(h->name),
                           sizeof(h->name));
                    *(np + sizeof(h->name)) = (char)'\000';
                    name = (char const *)(namebuf);
                    recent_long_name = (union block *)0;
                    recent_long_name_blocks = (size_t)0;
                  }
                }
                {
                  assign_string(&current_stat_info.orig_file_name, name);
                  assign_string(&current_stat_info.file_name, name);
                  current_stat_info.had_trailing_slash =
                      strip_trailing_slashes(current_stat_info.file_name);
                }

                if (next_long_link) {
                  name = (char const *)(next_long_link->buffer + 512);
                  recent_long_link = next_long_link;
                  recent_long_link_blocks = next_long_link_blocks;
                } else {
                  {
                    memcpy((void * /* __restrict  */)(namebuf),
                           (void const * /* __restrict  */)(h->linkname),
                           sizeof(h->linkname));
                    namebuf[sizeof(h->linkname)] = (char)'\000';
                    name = (char const *)(namebuf);
                    recent_long_link = (union block *)0;
                    recent_long_link_blocks = (size_t)0;
                  }
                }
                { assign_string(&current_stat_info.link_name, name); }
                return ((enum read_header)1);
              }
            }
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
void decode_header(union block *header, struct tar_stat_info *stat_info,
                   enum archive_format *format_pointer, int do_user_group) {
  enum archive_format format;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  unsigned long long tmp___5;
  _Bool tmp___6;

  {
    { tmp___0 = strcmp((char const *)(header->header.magic), "ustar"); }
    if (tmp___0 == 0) {

    } else {
      { tmp = strcmp((char const *)(header->header.magic), "ustar  "); }
      if (tmp == 0) {
        format = (enum archive_format)2;
      } else {
        format = (enum archive_format)1;
      }
    }
    {
      *format_pointer = format;
      stat_info->stat.st_mode = mode_from_header(
          (char const *)(header->header.mode), sizeof(header->header.mode));
      stat_info->stat.st_mtim.tv_sec = time_from_header(
          (char const *)(header->header.mtime), sizeof(header->header.mtime));
      assign_string(&stat_info->uname, (char const *)(header->header.uname));
      assign_string(&stat_info->gname, (char const *)(header->header.gname));
      tmp___1 = major_from_header((char const *)(header->header.devmajor),
                                  sizeof(header->header.devmajor));
      stat_info->devmajor = (unsigned int)tmp___1;
      tmp___2 = minor_from_header((char const *)(header->header.devminor),
                                  sizeof(header->header.devminor));
      stat_info->devminor = (unsigned int)tmp___2;
      stat_info->stat.st_atim.tv_sec = start_timespec.tv_sec;
      stat_info->stat.st_ctim.tv_sec = start_timespec.tv_sec;
    }
    if ((unsigned int)format == 2U) {
      if (incremental_option) {
        {
          stat_info->stat.st_atim.tv_sec =
              time_from_header((char const *)(header->oldgnu_header.atime),
                               sizeof(header->oldgnu_header.atime));
          stat_info->stat.st_ctim.tv_sec =
              time_from_header((char const *)(header->oldgnu_header.ctime),
                               sizeof(header->oldgnu_header.ctime));
        }
      }
    }
    if ((unsigned int)format == 1U) {
      {
        stat_info->stat.st_uid = uid_from_header(
            (char const *)(header->header.uid), sizeof(header->header.uid));
        stat_info->stat.st_gid = gid_from_header(
            (char const *)(header->header.gid), sizeof(header->header.gid));
        stat_info->stat.st_rdev = (__dev_t)0;
      }
    } else {

      if (do_user_group) {
        if (numeric_owner_option) {
          {
            stat_info->stat.st_uid = uid_from_header(
                (char const *)(header->header.uid), sizeof(header->header.uid));
          }
        } else {
          if (!header->header.uname[0]) {
            {
              stat_info->stat.st_uid =
                  uid_from_header((char const *)(header->header.uid),
                                  sizeof(header->header.uid));
            }
          } else {
            {
              tmp___3 = uname_to_uid((char const *)(header->header.uname),
                                     &stat_info->stat.st_uid);
            }
            if (!tmp___3) {
              {
                stat_info->stat.st_uid =
                    uid_from_header((char const *)(header->header.uid),
                                    sizeof(header->header.uid));
              }
            }
          }
        }
        if (numeric_owner_option) {
          {
            stat_info->stat.st_gid = gid_from_header(
                (char const *)(header->header.gid), sizeof(header->header.gid));
          }
        } else {
          if (!header->header.gname[0]) {
            {
              stat_info->stat.st_gid =
                  gid_from_header((char const *)(header->header.gid),
                                  sizeof(header->header.gid));
            }
          } else {
            {
              tmp___4 = gname_to_gid((char const *)(header->header.gname),
                                     &stat_info->stat.st_gid);
            }
            if (!tmp___4) {
              {
                stat_info->stat.st_gid =
                    gid_from_header((char const *)(header->header.gid),
                                    sizeof(header->header.gid));
              }
            }
          }
        }
      }
      {
        if ((int)header->header.typeflag == 52) {
          goto case_52;
        }
        if ((int)header->header.typeflag == 51) {
          goto case_52;
        }
        goto switch_default;
      case_52:   /* CIL Label */
      case_51: { /* CIL Label */
        tmp___5 = gnu_dev_makedev(stat_info->devmajor, stat_info->devminor);
        stat_info->stat.st_rdev = (__dev_t)tmp___5;
      }
        goto switch_break;
      switch_default: /* CIL Label */
        stat_info->stat.st_rdev = (__dev_t)0;
      switch_break: /* CIL Label */
          ;
      }
    }
    {
      stat_info->archive_file_size = stat_info->stat.st_size;
      xheader_decode(stat_info);
      tmp___6 = sparse_member_p(stat_info);
    }

    return;
  }
}
static int warned_once___0;
static struct quoting_options *o;
static uintmax_t from_header(char const *where0, size_t digs, char const *type,
                             uintmax_t minus_minval, uintmax_t maxval) {
  uintmax_t value;
  char const *where;
  char const *lim;
  int negative;
  char *tmp;
  unsigned short const **tmp___0;
  char const *where1;
  uintmax_t overflow;
  char const *tmp___1;
  int digit;
  char *tmp___2;
  char *tmp___3;
  int dig;
  char *tmp___4;
  char const *tmp___5;
  char *string;
  void *tmp___6;
  char const *tmp___7;
  char *tmp___8;
  int signbit;
  uintmax_t topbits;
  char const *tmp___9;
  char const *tmp___10;
  char *tmp___11;
  char buf[1000];
  char *tmp___12;
  unsigned short const **tmp___13;
  char minval_buf[((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL) +
                  1UL];
  char maxval_buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char value_buf[((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL) +
                 1UL];
  char *minval_string;
  char *tmp___14;
  char *value_string;
  char *tmp___15;
  char *tmp___16;
  char *tmp___17;
  uintmax_t tmp___18;
  uintmax_t tmp___19;
  void *__cil_tmp44;
  void *__cil_tmp45;
  void *__cil_tmp46;
  void *__cil_tmp47;
  char *__cil_tmp48;
  char *__cil_tmp49;
  char *__cil_tmp50;
  char *__cil_tmp51;
  char *__cil_tmp52;
  char *__cil_tmp53;
  char *__cil_tmp54;
  char *__cil_tmp55;

  {
    where = where0;
    lim = where + digs;
    negative = 0;
    where += !*where;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if ((unsigned long)where == (unsigned long)lim) {
          if (type) {
            {
              tmp = gettext("Blanks in header where numeric %s value expected");
              error(0, 0, (char const *)tmp, type);
              exit_status = 2;
            }
          }
          return ((uintmax_t)-1);
        }
        { tmp___0 = __ctype_b_loc(); }
        if (!((int const) * (*tmp___0 + (int)((unsigned char)*where)) & 8192)) {
          goto while_break;
        }
        where++;
      }
    while_break: /* CIL Label */
        ;
    }
    value = (uintmax_t)0;
    if ((unsigned int)*where - 48U <= 7U) {
      where1 = where;
      overflow = (uintmax_t)0;
      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;
          tmp___1 = where;
          where++;
          value += (uintmax_t)((int const) * tmp___1 - 48);
          if ((unsigned long)where == (unsigned long)lim) {
            goto while_break___0;
          } else {
            if (!((unsigned int)*where - 48U <= 7U)) {
              goto while_break___0;
            }
          }
          overflow |= value ^ ((value << 3) >> 3);
          value <<= 3;
        }
      while_break___0: /* CIL Label */
          ;
      }
      if (overflow) {
        goto _L___3;
      } else {
        if (maxval < value) {
        _L___3: /* CIL Label */
          if (50 <= (int)*where1) {
            if (type) {
              digit = (int)(((int const) * where1 - 48) | 4);
              overflow = (uintmax_t)0;
              value = (uintmax_t)0;
              where = where1;
              {
                while (1) {
                while_continue___1: /* CIL Label */
                    ;
                  value += (uintmax_t)(7 - digit);
                  where++;
                  if ((unsigned long)where == (unsigned long)lim) {
                    goto while_break___1;
                  } else {
                    if (!((unsigned int)*where - 48U <= 7U)) {
                      goto while_break___1;
                    }
                  }
                  digit = (int)((int const) * where - 48);
                  overflow |= value ^ ((value << 3) >> 3);
                  value <<= 3;
                }
              while_break___1: /* CIL Label */
                  ;
              }
              value++;
              overflow |= (unsigned long)(!value);
              if (!overflow) {
                if (value <= minus_minval) {
                  {
                    tmp___2 = gettext("Archive octal value %.*s is out of %s "
                                      "range; assuming two\'s complement");
                    error(0, 0, (char const *)tmp___2, (int)(where - where1),
                          where1, type);
                    negative = 1;
                  }
                }
              }
            }
          }
        }
      }
      if (overflow) {

        return ((uintmax_t)-1);
      }
    } else {
      if ((int const) * where == 45) {
        goto _L___5;
      } else {
        if ((int const) * where == 43) {
        _L___5: /* CIL Label */

          tmp___5 = where;
          where++;
          negative = (int const) * tmp___5 == 45;
          {
            while (1) {
            while_continue___2: /* CIL Label */
                ;
              if ((unsigned long)where != (unsigned long)lim) {
                dig = (int)base64_map[(unsigned char)*where];
                if (!(dig < 64)) {
                  goto while_break___2;
                }
              } else {
                goto while_break___2;
              }
              if ((value << 6) >> 6 != value) {
                {
                  tmp___6 = __builtin_alloca(digs + 1UL);
                  string = (char *)tmp___6;
                  memcpy((void * /* __restrict  */)string,
                         (void const * /* __restrict  */)where0, digs);
                  *(string + digs) = (char)'\000';
                }
                if (type) {
                  {
                    tmp___7 = quote((char const *)string);
                    tmp___8 = gettext(
                        "Archive signed base-64 string %s is out of %s range");
                    error(0, 0, (char const *)tmp___8, tmp___7, type);
                    exit_status = 2;
                  }
                }
                return ((uintmax_t)-1);
              }
              value = (value << 6) | (unsigned long)dig;
              where++;
            }
          while_break___2: /* CIL Label */
              ;
          }
        } else {
          if ((int const) * where == -128) {
            goto _L___4;
          } else {
            if ((int const) * where == -1) {
            _L___4: /* CIL Label */
              signbit = (int)((int const) * where & (int const)(1 << 6));
              topbits = (uintmax_t)(-signbit)
                        << ((8UL * sizeof(uintmax_t) - 8UL) - 6UL);
              tmp___9 = where;
              where++;
              value = (uintmax_t)(((int const) * tmp___9 &
                                   (int const)((1 << 6) - 1)) -
                                  (int const)signbit);
              {
                while (1) {
                while_continue___3: /* CIL Label */
                    ;
                  tmp___10 = where;
                  where++;
                  value = (value << 8) + (uintmax_t)((unsigned char)*tmp___10);
                  if ((unsigned long)where == (unsigned long)lim) {
                    goto while_break___3;
                  }
                  if ((((value << 8) >> 8) | topbits) != value) {
                    if (type) {
                      {
                        tmp___11 = gettext(
                            "Archive base-256 value is out of %s range");
                        error(0, 0, (char const *)tmp___11, type);
                        exit_status = 2;
                      }
                    }
                    return ((uintmax_t)-1);
                  }
                }
              while_break___3: /* CIL Label */
                  ;
              }
              negative = signbit;
              if (negative) {
                value = -value;
              }
            }
          }
        }
      }
    }
    if ((unsigned long)where != (unsigned long)lim) {
      if (*where) {
        {
          tmp___13 = __ctype_b_loc();
        }
      }
    }
    if (negative) {
      tmp___19 = minus_minval;
    } else {
      tmp___19 = maxval;
    }
    if (value <= tmp___19) {
      if (negative) {
        tmp___18 = -value;
      } else {
        tmp___18 = value;
      }
      return (tmp___18);
    }
    if (type) {
      {
        tmp___14 = stringify_uintmax_t_backwards(
            minus_minval,
            (minval_buf + 1) +
                ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
        minval_string = tmp___14;
        tmp___15 = stringify_uintmax_t_backwards(
            value,
            (value_buf + 1) +
                ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
        value_string = tmp___15;
      }
      if (negative) {
        value_string--;
        *value_string = (char)'-';
      }
      if (minus_minval) {
        minval_string--;
        *minval_string = (char)'-';
      }
      {
        tmp___16 = stringify_uintmax_t_backwards(
            maxval,
            maxval_buf +
                ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
        tmp___17 = gettext("Archive value %s is out of %s range %s.%s");
        error(0, 0, (char const *)tmp___17, value_string, type, minval_string,
              tmp___16);
        exit_status = 2;
      }
    }
    return ((uintmax_t)-1);
  }
}
gid_t gid_from_header(char const *p, size_t s) {
  uintmax_t tmp;
  char *__cil_tmp4;

  {
    {
      tmp = from_header(p, s, "gid_t", -((uintmax_t)((gid_t)0)),
                        (uintmax_t)4294967295U);
    }
    return ((gid_t)tmp);
  }
}
int major_from_header(char const *p, size_t s) {
  uintmax_t tmp;
  char *__cil_tmp4;

  {
    {
      tmp = from_header(p, s, "major_t",
                        -((uintmax_t)(-1 << (sizeof(int) * 8UL - 1UL))),
                        (uintmax_t)(-1 - (-1 << (sizeof(int) * 8UL - 1UL))));
    }
    return ((int)tmp);
  }
}
int minor_from_header(char const *p, size_t s) {
  uintmax_t tmp;
  char *__cil_tmp4;

  {
    {
      tmp = from_header(p, s, "minor_t",
                        -((uintmax_t)(-1 << (sizeof(int) * 8UL - 1UL))),
                        (uintmax_t)(-1 - (-1 << (sizeof(int) * 8UL - 1UL))));
    }
    return ((int)tmp);
  }
}
mode_t mode_from_header(char const *p, size_t s) {
  unsigned int u;
  uintmax_t tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  int tmp___11;
  char *__cil_tmp17;

  {
    {
      tmp = from_header(p, s, "mode_t", -((uintmax_t)((mode_t)0)),
                        0xffffffffffffffffUL);
      u = (unsigned int)tmp;
    }
    if (u & 2048U) {
      tmp___0 = 2048;
    } else {
      tmp___0 = 0;
    }
    if (u & 1024U) {
      tmp___1 = 1024;
    } else {
      tmp___1 = 0;
    }
    if (u & 512U) {
      tmp___2 = 512;
    } else {
      tmp___2 = 0;
    }
    if (u & 256U) {
      tmp___3 = 256;
    } else {
      tmp___3 = 0;
    }
    if (u & 128U) {
      tmp___4 = 128;
    } else {
      tmp___4 = 0;
    }
    if (u & 64U) {
      tmp___5 = 64;
    } else {
      tmp___5 = 0;
    }
    if (u & 32U) {
      tmp___6 = 256 >> 3;
    } else {
      tmp___6 = 0;
    }
    if (u & 16U) {
      tmp___7 = 128 >> 3;
    } else {
      tmp___7 = 0;
    }
    if (u & 8U) {
      tmp___8 = 64 >> 3;
    } else {
      tmp___8 = 0;
    }
    if (u & 4U) {
      tmp___9 = (256 >> 3) >> 3;
    } else {
      tmp___9 = 0;
    }
    if (u & 2U) {
      tmp___10 = (128 >> 3) >> 3;
    } else {
      tmp___10 = 0;
    }
    if (u & 1U) {
      tmp___11 = (64 >> 3) >> 3;
    } else {
      tmp___11 = 0;
    }
    return (
        (mode_t)(((((((((((tmp___0 | tmp___1) | tmp___2) | tmp___3) | tmp___4) |
                       tmp___5) |
                      tmp___6) |
                     tmp___7) |
                    tmp___8) |
                   tmp___9) |
                  tmp___10) |
                 tmp___11));
  }
}
off_t off_from_header(char const *p, size_t s) {
  uintmax_t tmp;
  char *__cil_tmp4;

  {
    {
      tmp =
          from_header(p, s, "off_t", (uintmax_t)0,
                      (uintmax_t)(-1L - (-1L << (sizeof(off_t) * 8UL - 1UL))));
    }
    return ((off_t)tmp);
  }
}
size_t size_from_header(char const *p, size_t s) {
  uintmax_t tmp;
  char *__cil_tmp4;

  {
    { tmp = from_header(p, s, "size_t", (uintmax_t)0, 0xffffffffffffffffUL); }
    return (tmp);
  }
}
time_t time_from_header(char const *p, size_t s) {
  uintmax_t tmp;
  char *__cil_tmp4;

  {
    {
      tmp = from_header(
          p, s, "time_t", -((uintmax_t)(-1L << (sizeof(time_t) * 8UL - 1UL))),
          (uintmax_t)(-1L - (-1L << (sizeof(time_t) * 8UL - 1UL))));
    }
    return ((time_t)tmp);
  }
}
uid_t uid_from_header(char const *p, size_t s) {
  uintmax_t tmp;
  char *__cil_tmp4;

  {
    {
      tmp = from_header(p, s, "uid_t", -((uintmax_t)((uid_t)0)),
                        (uintmax_t)4294967295U);
    }
    return ((uid_t)tmp);
  }
}
uintmax_t uintmax_from_header(char const *p, size_t s) {
  uintmax_t tmp;
  char *__cil_tmp4;

  {
    {
      tmp = from_header(p, s, "uintmax_t", (uintmax_t)0, 0xffffffffffffffffUL);
    }
    return (tmp);
  }
}
char *stringify_uintmax_t_backwards(uintmax_t o___0, char *buf) {

  {
    buf--;
    *buf = (char)'\000';
    {

    while_break: /* CIL Label */
        ;
    }
    return (buf);
  }
}
static char buffer[27UL];
char const *tartime(time_t t) {
  char *p;
  struct tm *tm;
  struct tm *tmp;
  struct tm *tmp___0;
  struct tm *tmp___1;
  uintmax_t tmp___2;
  char *__cil_tmp8;

  {

    tm = tmp___1;
    if (tm) {
      {
        sprintf(
            (char * /* __restrict  */)(buffer),
            (char const * /* __restrict  */) "%04ld-%02d-%02d %02d:%02d:%02d",
            (long)tm->tm_year + 1900L, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour,
            tm->tm_min, tm->tm_sec);
      }
      return ((char const *)(buffer));
    }
    if (t < 0L) {
      tmp___2 = -((uintmax_t)t);
    } else {
      tmp___2 = (uintmax_t)t;
    }
    { p = stringify_uintmax_t_backwards(tmp___2, buffer + sizeof(buffer)); }
    if (t < 0L) {
      p--;
      *p = (char)'-';
    }
    {

    while_break: /* CIL Label */
        ;
    }
    return ((char const *)p);
  }
}
static int ugswidth = 18;
void print_header(struct tar_stat_info *st, off_t block_ordinal) {
  char modes[11];
  char const *time_stamp;
  char *temp_name;
  char uform[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char gform[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char *user;
  char *group;
  char size[2UL * ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL)];
  char uintbuf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  int pad;
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  size_t tmp___3;
  uintmax_t u;
  uintmax_t tmp___4;
  uid_t tmp___5;
  uintmax_t g;
  uintmax_t tmp___6;
  gid_t tmp___7;
  unsigned int tmp___8;
  char *tmp___9;
  unsigned int tmp___10;
  char *tmp___11;
  char *tmp___12;
  size_t tmp___13;
  size_t tmp___14;
  size_t tmp___15;
  char *tmp___16;
  char *tmp___17;
  char *tmp___18;
  char *tmp___19;
  char type_string[2];
  char const *tmp___20;
  char *tmp___21;
  char *tmp___22;
  char *tmp___23;
  char *tmp___24;
  uintmax_t tmp___25;
  char *tmp___26;
  char *tmp___27;
  char *tmp___28;
  void *__cil_tmp47;
  void *__cil_tmp48;
  void *__cil_tmp49;
  void *__cil_tmp50;
  void *__cil_tmp51;
  void *__cil_tmp52;
  void *__cil_tmp53;
  char *__cil_tmp54;
  char *__cil_tmp55;
  char *__cil_tmp56;
  char *__cil_tmp57;
  char *__cil_tmp58;
  char *__cil_tmp59;
  char *__cil_tmp60;
  char *__cil_tmp61;
  char *__cil_tmp62;
  char *__cil_tmp63;
  char *__cil_tmp64;
  char *__cil_tmp65;

  {
    if (st->orig_file_name) {
      temp_name = st->orig_file_name;
    } else {
      temp_name = st->file_name;
    }
    if (block_number_option) {

      {
        block_ordinal =
            (off_t)((size_t)block_ordinal - recent_long_name_blocks);
        block_ordinal =
            (off_t)((size_t)block_ordinal - recent_long_link_blocks);
        tmp = stringify_uintmax_t_backwards(
            (uintmax_t)block_ordinal,
            buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
        tmp___0 = gettext("block %s: ");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */)tmp___0, tmp);
      }
    }
    if (verbose_option <= 1) {
      {
        tmp___1 = quotearg((char const *)temp_name);
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */) "%s\n", tmp___1);
      }
    } else {
      modes[0] = (char)'?';
      {
        if ((int)current_header->header.typeflag == 86) {
          goto case_86;
        }
        if ((int)current_header->header.typeflag == 77) {
          goto case_77;
        }
        if ((int)current_header->header.typeflag == 78) {
          goto case_78;
        }
        if ((int)current_header->header.typeflag == 76) {
          goto case_76;
        }
        if ((int)current_header->header.typeflag == 75) {
          goto case_76;
        }
        if ((int)current_header->header.typeflag == 83) {
          goto case_83;
        }
        if ((int)current_header->header.typeflag == 48) {
          goto case_83;
        }
        if ((int)current_header->header.typeflag == 0) {
          goto case_83;
        }
        if ((int)current_header->header.typeflag == 49) {
          goto case_49;
        }
        if ((int)current_header->header.typeflag == 68) {
          goto case_68;
        }
        if ((int)current_header->header.typeflag == 53) {
          goto case_53;
        }
        if ((int)current_header->header.typeflag == 50) {
          goto case_50;
        }
        if ((int)current_header->header.typeflag == 52) {
          goto case_52;
        }
        if ((int)current_header->header.typeflag == 51) {
          goto case_51;
        }
        if ((int)current_header->header.typeflag == 54) {
          goto case_54;
        }
        if ((int)current_header->header.typeflag == 55) {
          goto case_55;
        }
        goto switch_break;
      case_86: /* CIL Label */
        modes[0] = (char)'V';
        goto switch_break;
      case_77: /* CIL Label */
        modes[0] = (char)'M';
        goto switch_break;
      case_78: /* CIL Label */
        modes[0] = (char)'N';
        goto switch_break;
      case_76:   /* CIL Label */
      case_75: { /* CIL Label */
        modes[0] = (char)'L';
        tmp___2 = gettext("Visible longname error");
        error(0, 0, (char const *)tmp___2);
        exit_status = 2;
      }
        goto switch_break;
      case_83:  /* CIL Label */
      case_48:  /* CIL Label */
      case_0: { /* CIL Label */
        modes[0] = (char)'-';
        tmp___3 = strlen((char const *)temp_name);
      }
        if ((int)*(temp_name + (tmp___3 - 1UL)) == 47) {
          modes[0] = (char)'d';
        }
        goto switch_break;
      case_49: /* CIL Label */
        modes[0] = (char)'h';
        goto switch_break;
      case_68: /* CIL Label */
        modes[0] = (char)'d';
        goto switch_break;
      case_53: /* CIL Label */
        modes[0] = (char)'d';
        goto switch_break;
      case_50: /* CIL Label */
        modes[0] = (char)'l';
        goto switch_break;
      case_52: /* CIL Label */
        modes[0] = (char)'b';
        goto switch_break;
      case_51: /* CIL Label */
        modes[0] = (char)'c';
        goto switch_break;
      case_54: /* CIL Label */
        modes[0] = (char)'p';
        goto switch_break;
      case_55: /* CIL Label */
        modes[0] = (char)'C';
        goto switch_break;
      switch_break: /* CIL Label */
          ;
      }
      {
        decode_mode(st->stat.st_mode, modes + 1);
        time_stamp = tartime(st->stat.st_mtim.tv_sec);
      }

      {
        if ((int)current_header->header.typeflag == 51) {
          goto case_51___0;
        }

        goto switch_default;
      case_51___0:   /* CIL Label */
      case_52___0: { /* CIL Label */
        tmp___8 = gnu_dev_major((unsigned long long)st->stat.st_rdev);
        tmp___9 = stringify_uintmax_t_backwards(
            (uintmax_t)tmp___8,
            uintbuf +
                ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
        strcpy((char * /* __restrict  */)(size),
               (char const * /* __restrict  */)tmp___9);
        strcat((char * /* __restrict  */)(size),
               (char const * /* __restrict  */) ",");
        tmp___10 = gnu_dev_minor((unsigned long long)st->stat.st_rdev);
        tmp___11 = stringify_uintmax_t_backwards(
            (uintmax_t)tmp___10,
            uintbuf +
                ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
        strcat((char * /* __restrict  */)(size),
               (char const * /* __restrict  */)tmp___11);
      }
        goto switch_break___0;
      switch_default: { /* CIL Label */
        tmp___12 = stringify_uintmax_t_backwards(
            (uintmax_t)st->stat.st_size,
            uintbuf +
                ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
        strcpy((char * /* __restrict  */)(size),
               (char const * /* __restrict  */)tmp___12);
      }
        goto switch_break___0;
      switch_break___0: /* CIL Label */
          ;
      }
      {
        tmp___13 = strlen((char const *)user);
        tmp___14 = strlen((char const *)group);
        tmp___15 = strlen((char const *)(size));
        pad = (int)(((tmp___13 + tmp___14) + tmp___15) + 1UL);
      }
      if (pad > ugswidth) {
        ugswidth = pad;
      }
      {
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */) "%s %s/%s %*s%s %s", modes,
                user, group, ugswidth - pad, "", size, time_stamp);
        tmp___16 = quotearg((char const *)temp_name);
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */) " %s", tmp___16);
      }
      {
        if ((int)current_header->header.typeflag == 50) {
          goto case_50___0;
        }
        if ((int)current_header->header.typeflag == 49) {
          goto case_49___0;
        }
        if ((int)current_header->header.typeflag == 0) {
          goto case_0___0;
        }
        if ((int)current_header->header.typeflag == 48) {
          goto case_0___0;
        }
        if ((int)current_header->header.typeflag == 83) {
          goto case_0___0;
        }

        if ((int)current_header->header.typeflag == 53) {
          goto case_0___0;
        }

        if ((int)current_header->header.typeflag == 55) {
          goto case_0___0;
        }

        if ((int)current_header->header.typeflag == 75) {
          goto case_75___0;
        }
        if ((int)current_header->header.typeflag == 76) {
          goto case_76___0;
        }

        if ((int)current_header->header.typeflag == 77) {
          goto case_77___0;
        }
        if ((int)current_header->header.typeflag == 78) {
          goto case_78___0;
        }
        goto switch_default___0;
      case_50___0: { /* CIL Label */
        tmp___17 = quotearg((char const *)st->link_name);
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */) " -> %s\n", tmp___17);
      }
        goto switch_break___1;
      case_49___0: { /* CIL Label */
        tmp___18 = quotearg((char const *)st->link_name);
        tmp___19 = gettext(" link to %s\n");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */)tmp___19, tmp___18);
      }
        goto switch_break___1;
      switch_default___0: { /* CIL Label */
        type_string[0] = current_header->header.typeflag;
        type_string[1] = (char)'\000';
        tmp___20 = quote((char const *)(type_string));
        tmp___21 = gettext(" unknown file type %s\n");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */)tmp___21, tmp___20);
      }
        goto switch_break___1;
      case_0___0:    /* CIL Label */
      case_48___0:   /* CIL Label */
      case_83___0:   /* CIL Label */
      case_51___1:   /* CIL Label */
      case_52___1:   /* CIL Label */
      case_53___0:   /* CIL Label */
      case_54___0:   /* CIL Label */
      case_55___0:   /* CIL Label */
      case_68___0: { /* CIL Label */
        putc_unlocked('\n', stdlis);
      }
        goto switch_break___1;
      case_75___0: { /* CIL Label */
        tmp___22 = gettext("--Long Link--\n");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */)tmp___22);
      }
        goto switch_break___1;
      case_76___0: { /* CIL Label */
        tmp___23 = gettext("--Long Name--\n");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */)tmp___23);
      }
        goto switch_break___1;
      case_86___0: { /* CIL Label */
        tmp___24 = gettext("--Volume Header--\n");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */)tmp___24);
      }
        goto switch_break___1;
      case_77___0: { /* CIL Label */
        tmp___25 = uintmax_from_header(
            (char const *)(current_header->oldgnu_header.offset),
            sizeof(current_header->oldgnu_header.offset));
        tmp___26 = stringify_uintmax_t_backwards(
            tmp___25,
            uintbuf +
                ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
        strcpy((char * /* __restrict  */)(size),
               (char const * /* __restrict  */)tmp___26);
        tmp___27 = gettext("--Continued at byte %s--\n");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */)tmp___27, size);
      }
        goto switch_break___1;
      case_78___0: { /* CIL Label */
        tmp___28 = gettext("--Mangled file names--\n");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */)tmp___28);
      }
        goto switch_break___1;
      switch_break___1: /* CIL Label */
          ;
      }
    }
    { fflush_unlocked(stdlis); }
    return;
  }
}
void print_for_mkdir(char *pathname, int length, mode_t mode) {
  char modes[11];
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  off_t tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  void *__cil_tmp11;
  void *__cil_tmp12;
  char *__cil_tmp13;
  char *__cil_tmp14;

  {
    if (verbose_option > 1) {
      {
        modes[0] = (char)'d';
        decode_mode(mode, modes + 1);
      }

      {
        tmp___2 = quotearg((char const *)pathname);
        tmp___3 = gettext("Creating directory:");
        fprintf((FILE * /* __restrict  */)stdlis,
                (char const * /* __restrict  */) "%s %*s %.*s\n", modes,
                ugswidth + 18, tmp___3, length, tmp___2);
      }
    }
    return;
  }
}
void skip_file(off_t size) {
  union block *x;
  char *tmp;
  char *__cil_tmp4;

  {

    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(size > 0L)) {
          goto while_break;
        }
        { x = find_next_block(); }
        if (!x) {
          {
            tmp = gettext("Unexpected EOF in archive");
            error(0, 0, (char const *)tmp);
            fatal_exit();
          }
        }
        {
          set_next_block_after(x);
          size -= 512L;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
void skip_member(void) {
  char save_typeflag;
  _Bool tmp;

  {
    {
      save_typeflag = current_header->header.typeflag;
      set_next_block_after(current_header);
      assign_string(&save_name, (char const *)current_stat_info.file_name);
      tmp = sparse_member_p(&current_stat_info);
    }
    if (tmp) {
      {
        sparse_skip_file(&current_stat_info);
      }
    } else {
      if ((int)save_typeflag != 53) {
        {
          skip_file(current_stat_info.stat.st_size);
        }
      }
    }
    return;
  }
}
/* #pragma merger("0","008.mangle.o.i","") */
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) rename)(
    char const *__old, char const *__new);
void extract_mangle(void) {
  off_t size;
  char *buffer___2;
  void *tmp;
  char *copy;
  char *cursor;
  union block *block;
  union block *tmp___0;
  size_t available;
  char *tmp___1;
  char *next_cursor;
  char *name;
  char *name_end;
  char *tmp___2;
  int tmp___3;
  char const *tmp___4;
  char *tmp___5;
  char *tmp___6;
  int *tmp___7;
  char *tmp___8;
  int tmp___9;
  int tmp___10;
  char const *tmp___11;
  char *tmp___12;
  char *tmp___13;
  int *tmp___14;
  char *tmp___15;
  int tmp___16;
  int tmp___17;
  int tmp___18;
  char *tmp___19;
  int tmp___20;
  int tmp___21;
  char *__cil_tmp33;
  char *__cil_tmp34;
  char *__cil_tmp35;
  char *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;

  {
    {
      size = current_stat_info.stat.st_size;
      tmp = xmalloc((size_t)(size + 1L));
      buffer___2 = (char *)tmp;
      copy = buffer___2;
      cursor = buffer___2;
    }
    if ((size_t)size != (size_t)size) {
      {
        xalloc_die();
      }
    } else {
      if ((size_t)size == 0xffffffffffffffffUL) {
        {
          xalloc_die();
        }
      }
    }
    *(buffer___2 + size) = (char)'\000';
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(size > 0L)) {
          goto while_break;
        }
        {
          tmp___0 = find_next_block();
          block = tmp___0;
        }
        if (!block) {
          {
            tmp___1 = gettext("Unexpected EOF in mangled names");
            error(0, 0, (char const *)tmp___1);
            exit_status = 2;
          }
          return;
        }
        { available = available_space_after(block); }
        if (available > (size_t)size) {
          available = (size_t)size;
        }
        {
          memcpy((void * /* __restrict  */)copy,
                 (void const * /* __restrict  */)(block->buffer), available);
          copy += available;
          size = (off_t)((size_t)size - available);
          set_next_block_after(
              (union block *)((block->buffer + available) - 1));
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!*cursor) {
          goto while_break___0;
        }
        {
          next_cursor = strchr((char const *)cursor, '\n');
          tmp___2 = next_cursor;
          next_cursor++;
          *tmp___2 = (char)'\000';
          tmp___21 = strncmp((char const *)cursor, "Rename ", (size_t)7);
        }
        if (tmp___21) {
          {
            tmp___20 = strncmp((char const *)cursor, "Symlink ", (size_t)8);
          }

        } else {
          {
            name = cursor + 7;
            name_end = strchr((char const *)name, ' ');
          }
          {

          while_break___2: /* CIL Label */
              ;
          }
          *name_end = (char)'\000';
          if ((int)*(next_cursor + -2) == 47) {
            *(next_cursor + -2) = (char)'\000';
          }
          {
            unquote_string(name_end + 4);
            tmp___9 = rename((char const *)name, (char const *)(name_end + 4));
          }
          if (tmp___9) {
            {
              tmp___4 = quote_n(1, (char const *)(name_end + 4));
              tmp___5 = quotearg_colon((char const *)name);
              tmp___6 = gettext("%s: Cannot rename to %s");
              tmp___7 = __errno_location();
              error(0, *tmp___7, (char const *)tmp___6, tmp___5, tmp___4);
              exit_status = 2;
            }
          } else {
            if (verbose_option) {
              {
                tmp___8 = gettext("Renamed %s to %s");
                error(0, 0, (char const *)tmp___8, name, name_end + 4);
              }
            }
          }
        }
        cursor = next_cursor;
      }
    while_break___0: /* CIL Label */
        ;
    }
    return;
  }
}
/* #pragma merger("0","009.misc.o.i","") */
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) pipe)(
    int *__pipedes);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) chdir)(char const *__path);
extern __attribute__((__nothrow__)) __pid_t fork(void);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) rmdir)(char const *__path);
char *find_backup_file_name(char const *file, enum backup_type backup_type___0);
enum backup_type backup_type;
int chdir_arg(char const *dir);
void chdir_do(int i);
__attribute__((__noreturn__)) void chdir_fatal(char const *name);
__attribute__((__noreturn__)) void exec_fatal(char const *name);
void read_error_details(char const *name, off_t offset, size_t size);
__attribute__((__noreturn__)) void read_fatal(char const *name);
__attribute__((__noreturn__)) void
read_fatal_details(char const *name, off_t offset, size_t size);
void read_warn_details(char const *name, off_t offset, size_t size);
void savedir_warn(char const *name);
void seek_warn_details(char const *name, off_t offset);
void seek_diag_details(char const *name, off_t offset);
void waitpid_error(char const *name);
pid_t xfork(void);
void xpipe(int *fd);
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
int save_cwd(struct saved_cwd *cwd);
int restore_cwd(struct saved_cwd const *cwd);
static __attribute__((__noreturn__)) void call_arg_fatal(char const *call,
                                                         char const *name);
void assign_string(char **string, char const *value) {
  char *tmp;

  {
    if (*string) {
      {
        free((void *)*string);
      }
    }
    if (value) {
      {
        tmp = xstrdup(value);
        *string = tmp;
      }
    } else {
      *string = (char *)0;
    }
    return;
  }
}
char *quote_copy_string(char const *string) {
  char const *source;
  char *destination;
  char *buffer___2;
  int copying;
  int character;
  char const *tmp;
  size_t length;
  size_t tmp___0;
  void *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  int tmp___5;

  {
    source = string;
    destination = (char *)0;
    buffer___2 = (char *)0;
    copying = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!*source) {
          goto while_break;
        }
        tmp = source;
        source++;
        character = (int)*tmp;
        {
          if (character == 10) {
            goto case_10;
          }

          goto switch_default;
        case_10: /* CIL Label */
        case_92: /* CIL Label */
          if (!copying) {
            {
              length = (size_t)((source - string) - 1L);
              copying = 1;
              tmp___0 = strlen(source);
              tmp___1 = xmalloc(((length + 2UL) + 2UL * tmp___0) + 1UL);
              buffer___2 = (char *)tmp___1;
              memcpy((void * /* __restrict  */)buffer___2,
                     (void const * /* __restrict  */)string, length);
              destination = buffer___2 + length;
            }
          }
          tmp___2 = destination;
          destination++;
          *tmp___2 = (char)'\\';
          tmp___3 = destination;
          destination++;
          if (character == 92) {
            tmp___5 = '\\';
          } else {
            tmp___5 = 'n';
          }
          *tmp___3 = (char)tmp___5;
          goto switch_break;
        switch_default: /* CIL Label */
          if (copying) {
            tmp___4 = destination;
            destination++;
            *tmp___4 = (char)character;
          }
          goto switch_break;
        switch_break: /* CIL Label */
            ;
        }
      }
    while_break: /* CIL Label */
        ;
    }

    return ((char *)0);
  }
}
int unquote_string(char *string) {
  int result;
  char *source;
  char *destination;
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  int value;
  char *tmp___6;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  char *tmp___10;
  char *tmp___11;
  char *tmp___12;
  char *tmp___13;
  char *tmp___14;
  char *tmp___15;
  char *tmp___16;

  {
    result = 1;
    source = string;
    destination = string;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!*source) {
          goto while_break;
        }
        if ((int)*source == 92) {
          source++;
          {
            if ((int)*source == 92) {
              goto case_92;
            }
            if ((int)*source == 110) {
              goto case_110;
            }
            if ((int)*source == 116) {
              goto case_116;
            }
            if ((int)*source == 102) {
              goto case_102;
            }
            if ((int)*source == 98) {
              goto case_98;
            }
            if ((int)*source == 114) {
              goto case_114;
            }
            if ((int)*source == 63) {
              goto case_63;
            }
            if ((int)*source == 48) {
              goto case_48;
            }
            if ((int)*source == 49) {
              goto case_48;
            }
            if ((int)*source == 50) {
              goto case_48;
            }

            if ((int)*source == 53) {
              goto case_48;
            }
            if ((int)*source == 54) {
              goto case_48;
            }
            if ((int)*source == 55) {
              goto case_48;
            }
            goto switch_default;
          case_92: /* CIL Label */
            tmp = destination;
            destination++;
            *tmp = (char)'\\';
            source++;
            goto switch_break;
          case_110: /* CIL Label */
            tmp___0 = destination;
            destination++;
            *tmp___0 = (char)'\n';
            source++;
            goto switch_break;
          case_116: /* CIL Label */
            tmp___1 = destination;
            destination++;
            *tmp___1 = (char)'\t';
            source++;
            goto switch_break;
          case_102: /* CIL Label */
            tmp___2 = destination;
            destination++;
            *tmp___2 = (char)'\f';
            source++;
            goto switch_break;
          case_98: /* CIL Label */
            tmp___3 = destination;
            destination++;
            *tmp___3 = (char)'\b';
            source++;
            goto switch_break;
          case_114: /* CIL Label */
            tmp___4 = destination;
            destination++;
            *tmp___4 = (char)'\r';
            source++;
            goto switch_break;
          case_63: /* CIL Label */
            tmp___5 = destination;
            destination++;
            *tmp___5 = (char)127;
            source++;
            goto switch_break;
          case_48: /* CIL Label */
          case_49: /* CIL Label */
          case_50: /* CIL Label */
          case_51: /* CIL Label */
          case_52: /* CIL Label */
          case_53: /* CIL Label */
          case_54: /* CIL Label */
          case_55: /* CIL Label */
            tmp___6 = source;
            source++;
            value = (int)*tmp___6 - 48;
            if ((int)*source < 48) {
              tmp___7 = destination;
              destination++;
              *tmp___7 = (char)value;
              goto switch_break;
            } else {
              if ((int)*source > 55) {
                tmp___7 = destination;
                destination++;
                *tmp___7 = (char)value;
                goto switch_break;
              }
            }
            tmp___8 = source;
            source++;
            value = (value * 8 + (int)*tmp___8) - 48;
            if ((int)*source < 48) {
              tmp___9 = destination;
              destination++;
              *tmp___9 = (char)value;
              goto switch_break;
            } else {
              if ((int)*source > 55) {
                tmp___9 = destination;
                destination++;
                *tmp___9 = (char)value;
                goto switch_break;
              }
            }
            tmp___10 = source;
            source++;
            value = (value * 8 + (int)*tmp___10) - 48;
            tmp___11 = destination;
            destination++;
            *tmp___11 = (char)value;
            goto switch_break;
          switch_default: /* CIL Label */
            result = 0;
            tmp___12 = destination;
            destination++;
            *tmp___12 = (char)'\\';
            if (*source) {
              tmp___13 = destination;
              destination++;
              tmp___14 = source;
              source++;
              *tmp___13 = *tmp___14;
            }
            goto switch_break;
          switch_break: /* CIL Label */
              ;
          }
        } else {
          if ((unsigned long)source != (unsigned long)destination) {
            tmp___15 = destination;
            destination++;
            tmp___16 = source;
            source++;
            *tmp___15 = *tmp___16;
          } else {
            source++;
            destination++;
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if ((unsigned long)source != (unsigned long)destination) {
      *destination = (char)'\000';
    }
    return (result);
  }
}
static char *before_backup_name;
static char *after_backup_name;
static _Bool must_be_dot_or_slash(char const *path) {
  int tmp;

  {
    path += 0;
    if ((int const) * (path + 0) == 47) {
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if ((int const) * (path + 1) == 47) {
            path++;
          } else {
            if ((int const) * (path + 1) == 46) {
              if ((int const) *
                      (path + (2 + ((int const) * (path + 2) == 46))) ==
                  47) {
                path += 2 + ((int const) * (path + 2) == 46);
              } else {
                return ((_Bool)(!*(path + 1)));
              }
            } else {
              return ((_Bool)(!*(path + 1)));
            }
          }
        }
      while_break: /* CIL Label */
          ;
      }
    } else {
      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;

          path += 2;
          {
            while (1) {
            while_continue___1: /* CIL Label */
                ;
              if (!((int const) * path == 47)) {
                goto while_break___1;
              }
              path++;
            }
          while_break___1: /* CIL Label */
              ;
          }
        }
      while_break___0: /* CIL Label */
          ;
      }

      return ((_Bool)tmp);
    }
  }
}
static int safer_rmdir(char const *path) {
  int *tmp;
  _Bool tmp___0;
  int tmp___1;

  {
    { tmp___0 = must_be_dot_or_slash(path); }
    if (tmp___0) {
      {
        tmp = __errno_location();
        *tmp = 0;
      }
      return (-1);
    }
    { tmp___1 = rmdir(path); }
    return (tmp___1);
  }
}
int remove_any_file(char const *path, enum remove_option option) {
  int tmp;
  int *tmp___0;
  int *tmp___1;
  int tmp___2;
  int *tmp___3;
  int tmp___4;
  int tmp___5;
  char *directory;
  char *tmp___6;
  char const *entry;
  size_t entrylen;
  char *path_buffer;
  char *tmp___7;
  int r;
  int tmp___8;
  int e;
  int *tmp___9;
  int *tmp___10;
  int tmp___11;

  {

    { tmp___2 = safer_rmdir(path); }
    if (tmp___2 == 0) {
      return (1);
    }
    { tmp___3 = __errno_location(); }
    {
      if (*tmp___3 == 20) {
        goto case_20;
      }

      goto switch_break;
    case_20: /* CIL Label */

      return (tmp___5);
    case_0:    /* CIL Label */
    case_17:   /* CIL Label */
    case_39: { /* CIL Label */

      goto switch_break___0;
    case_0___0: /* CIL Label */
      goto switch_break___0;
    case_2: /* CIL Label */
      return (-1);
    case_1: { /* CIL Label */
      tmp___6 = savedir(path);
      directory = tmp___6;
    }
      if (!directory) {
        return (0);
      }
      entry = (char const *)directory;
      {

      while_break: /* CIL Label */
          ;
      }
      {
        free((void *)directory);
        tmp___11 = safer_rmdir(path);
      }
      return (tmp___11 == 0);
    switch_break___0: /* CIL Label */
        ;
    }
      goto switch_break;
    switch_break: /* CIL Label */
        ;
    }
    return (0);
  }
}
_Bool maybe_backup_file(char const *path, int this_is_the_archive) {
  struct stat file_stat;
  void *tmp;
  int *tmp___0;
  int tmp___1;
  char const *tmp___2;
  char const *tmp___3;
  char *tmp___4;
  int e;
  int *tmp___5;
  char const *tmp___6;
  char *tmp___7;
  char *tmp___8;
  int tmp___9;
  void *__cil_tmp16;
  char *__cil_tmp17;
  char *__cil_tmp18;

  {
    if (this_is_the_archive) {
    }
    {
      tmp___1 = stat((char const * /* __restrict  */)path,
                     (struct stat * /* __restrict  */)(&file_stat));
    }
    if (tmp___1) {
      {
        tmp___0 = __errno_location();
      }

      { stat_error(path); }
      return ((_Bool)0);
    }
    if ((file_stat.st_mode & 61440U) == 16384U) {
      return ((_Bool)1);
    }

    {
      assign_string(&before_backup_name, path);
      assign_string(&after_backup_name, (char const *)0);
      after_backup_name = find_backup_file_name(path, backup_type);
    }

    {
      tmp___9 = rename((char const *)before_backup_name,
                       (char const *)after_backup_name);
    }
  }
}
void undo_last_backup(void) {
  int e;
  int *tmp;
  char const *tmp___0;
  char *tmp___1;
  char *tmp___2;
  int tmp___3;
  char const *tmp___4;
  char const *tmp___5;
  char *tmp___6;
  char *__cil_tmp10;
  char *__cil_tmp11;

  { return; }
}
int deref_stat(_Bool deref, char const *name, struct stat *buf) {
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    if (deref) {
      {
        tmp = stat((char const * /* __restrict  */)name,
                   (struct stat * /* __restrict  */)buf);
        tmp___1 = tmp;
      }
    } else {
      {
        tmp___0 = lstat((char const * /* __restrict  */)name,
                        (struct stat * /* __restrict  */)buf);
        tmp___1 = tmp___0;
      }
    }
    return (tmp___1);
  }
}
static struct wd *wd;
static size_t wds;
static size_t wd_alloc;
int chdir_arg(char const *dir) {
  void *tmp;
  size_t tmp___0;
  char *__cil_tmp4;

  {
    if (wds == wd_alloc) {
      {
        wd_alloc = 2UL * (wd_alloc + 1UL);
        tmp = xrealloc((void *)wd, sizeof(*wd) * wd_alloc);
        wd = (struct wd *)tmp;
      }
      if (!wds) {
        (wd + wds)->name = ".";
        (wd + wds)->saved = 0;
        wds++;
      }
    }
    if (*(dir + 0)) {
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if ((int const) * (dir + 0) == 46) {
            if (!((int const) * (dir + 1) == 47)) {
              goto while_break;
            }
          } else {
            goto while_break;
          }
          dir += 2;
          {
            while (1) {
            while_continue___0: /* CIL Label */
                ;
              if (!((int const) * dir == 47)) {
                goto while_break___0;
              }
              goto __Cont;
            __Cont:
              dir++;
            }
          while_break___0: /* CIL Label */
              ;
          }
        }
      while_break: /* CIL Label */
          ;
      }
      if (!*(dir + ((int const) * (dir + 0) == 46))) {
        return ((int)(wds - 1UL));
      }
    }
    (wd + wds)->name = dir;
    (wd + wds)->saved = 0;
    tmp___0 = wds;
    wds++;
    return ((int)tmp___0);
  }
}
static int previous;
void chdir_do(int i) {
  struct wd *prev;
  struct wd *curr;
  char *tmp;
  int tmp___0;
  char *tmp___1;
  int tmp___2;
  int tmp___3;
  char *__cil_tmp9;
  char *__cil_tmp10;

  {
    if (previous != i) {
      prev = wd + previous;
      curr = wd + i;

      if (curr->saved) {
        {
          tmp___2 = restore_cwd((struct saved_cwd const *)(&curr->saved_cwd));
        }
        if (tmp___2) {
          {
            tmp___1 = gettext("Cannot change working directory");
            error(0, 0, (char const *)tmp___1);
            fatal_exit();
          }
        }
      } else {
        if (i) {
          if (!((int const) * (curr->name + 0) == 47)) {
            {
              chdir_do(i - 1);
            }
          }
        }
        { tmp___3 = chdir(curr->name); }
        if (tmp___3 != 0) {
          {
            chdir_fatal(curr->name);
          }
        }
      }
      previous = i;
    }
    return;
  }
}
void decode_mode(mode_t mode, char *string) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  int tmp___11;
  int tmp___12;
  int tmp___13;
  int tmp___14;
  int tmp___15;
  int tmp___16;
  int tmp___17;
  int tmp___18;
  int tmp___19;
  int tmp___20;
  int tmp___21;
  int tmp___22;

  {
    tmp = string;
    string++;
    if (mode & 256U) {
      tmp___8 = 'r';
    } else {
      tmp___8 = '-';
    }
    *tmp = (char)tmp___8;
    tmp___0 = string;
    string++;
    if (mode & 128U) {
      tmp___9 = 'w';
    } else {
      tmp___9 = '-';
    }
    *tmp___0 = (char)tmp___9;
    tmp___1 = string;
    string++;
    if (mode & 2048U) {
      if (mode & 64U) {
        tmp___10 = 's';
      } else {
        tmp___10 = 'S';
      }
      tmp___12 = tmp___10;
    } else {
      if (mode & 64U) {
        tmp___11 = 'x';
      } else {
        tmp___11 = '-';
      }
      tmp___12 = tmp___11;
    }
    *tmp___1 = (char)tmp___12;
    tmp___2 = string;
    string++;
    if (mode & (unsigned int)(256 >> 3)) {
      tmp___13 = 'r';
    } else {
      tmp___13 = '-';
    }
    *tmp___2 = (char)tmp___13;
    tmp___3 = string;
    string++;
    if (mode & (unsigned int)(128 >> 3)) {
      tmp___14 = 'w';
    } else {
      tmp___14 = '-';
    }
    *tmp___3 = (char)tmp___14;
    tmp___4 = string;
    string++;
    if (mode & 1024U) {
      if (mode & (unsigned int)(64 >> 3)) {
        tmp___15 = 's';
      } else {
        tmp___15 = 'S';
      }
      tmp___17 = tmp___15;
    } else {
      if (mode & (unsigned int)(64 >> 3)) {
        tmp___16 = 'x';
      } else {
        tmp___16 = '-';
      }
      tmp___17 = tmp___16;
    }
    *tmp___4 = (char)tmp___17;
    tmp___5 = string;
    string++;
    if (mode & (unsigned int)((256 >> 3) >> 3)) {
      tmp___18 = 'r';
    } else {
      tmp___18 = '-';
    }
    *tmp___5 = (char)tmp___18;
    tmp___6 = string;
    string++;
    if (mode & (unsigned int)((128 >> 3) >> 3)) {
      tmp___19 = 'w';
    } else {
      tmp___19 = '-';
    }
    *tmp___6 = (char)tmp___19;
    tmp___7 = string;
    string++;
    if (mode & 512U) {
      if (mode & (unsigned int)((64 >> 3) >> 3)) {
        tmp___20 = 't';
      } else {
        tmp___20 = 'T';
      }
      tmp___22 = tmp___20;
    } else {
      if (mode & (unsigned int)((64 >> 3) >> 3)) {
        tmp___21 = 'x';
      } else {
        tmp___21 = '-';
      }
      tmp___22 = tmp___21;
    }
    *tmp___7 = (char)tmp___22;
    *string = (char)'\000';
    return;
  }
}
static void call_arg_error(char const *call, char const *name) {
  int e;
  int *tmp;
  char *tmp___0;
  char *tmp___1;
  char *__cil_tmp7;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = quotearg_colon(name);
      tmp___1 = gettext("%s: Cannot %s");
      error(0, e, (char const *)tmp___1, tmp___0, call);
      exit_status = 2;
    }
    return;
  }
}
static __attribute__((__noreturn__)) void call_arg_fatal(char const *call,
                                                         char const *name);
static void call_arg_fatal(char const *call, char const *name) {
  int e;
  int *tmp;
  char *tmp___0;
  char *tmp___1;
  char *__cil_tmp7;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = quotearg_colon(name);
      tmp___1 = gettext("%s: Cannot %s");
      error(0, e, (char const *)tmp___1, tmp___0, call);
      fatal_exit();
    }
  }
}
static void call_arg_warn(char const *call, char const *name) {
  int e;
  int *tmp;
  char *tmp___0;
  char *tmp___1;
  char *__cil_tmp7;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = quotearg_colon(name);
      tmp___1 = gettext("%s: Warning: Cannot %s");
      error(0, e, (char const *)tmp___1, tmp___0, call);
    }
    return;
  }
}
__attribute__((__noreturn__)) void chdir_fatal(char const *name);
void chdir_fatal(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_fatal("chdir", name); }
  }
}
void chmod_error_details(char const *name, mode_t mode) {
  int e;
  int *tmp;
  char buf[10];
  char *tmp___0;
  char *tmp___1;
  void *__cil_tmp8;
  char *__cil_tmp9;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      decode_mode(mode, buf);
      tmp___0 = quotearg_colon(name);
      tmp___1 = gettext("%s: Cannot change mode to %s");
      error(0, e, (char const *)tmp___1, tmp___0, buf);
      exit_status = 2;
    }
    return;
  }
}
void chown_error_details(char const *name, uid_t uid, gid_t gid) {
  int e;
  int *tmp;
  char *tmp___0;
  char *tmp___1;
  char *__cil_tmp8;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = quotearg_colon(name);
      tmp___1 = gettext("%s: Cannot change ownership to uid %lu, gid %lu");
      error(0, e, (char const *)tmp___1, tmp___0, (unsigned long)uid,
            (unsigned long)gid);
      exit_status = 2;
    }
    return;
  }
}
void close_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("close", name); }
    return;
  }
}
void close_warn(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_warn("close", name); }
    return;
  }
}
void close_diag(char const *name) {

  {
    if (ignore_failed_read_option) {
      {
        close_warn(name);
      }
    } else {
      { close_error(name); }
    }
    return;
  }
}
__attribute__((__noreturn__)) void exec_fatal(char const *name);
void exec_fatal(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_fatal("exec", name); }
  }
}
void link_error(char const *target, char const *source) {
  int e;
  int *tmp;
  char const *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *__cil_tmp8;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = quote_n(1, target);
      tmp___1 = quotearg_colon(source);
      tmp___2 = gettext("%s: Cannot hard link to %s");
      error(0, e, (char const *)tmp___2, tmp___1, tmp___0);
      exit_status = 2;
    }
    return;
  }
}
void mkdir_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("mkdir", name); }
    return;
  }
}
void mkfifo_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("mkfifo", name); }
    return;
  }
}
void mknod_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("mknod", name); }
    return;
  }
}
void open_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("open", name); }
    return;
  }
}
__attribute__((__noreturn__)) void open_fatal(char const *name);
void open_fatal(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_fatal("open", name); }
  }
}
void open_warn(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_warn("open", name); }
    return;
  }
}
void open_diag(char const *name) {

  {
    if (ignore_failed_read_option) {
      {
        open_warn(name);
      }
    } else {
      { open_error(name); }
    }
    return;
  }
}
void read_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("read", name); }
    return;
  }
}
void read_error_details(char const *name, off_t offset, size_t size) {
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  int e;
  int *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  void *__cil_tmp10;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = stringify_uintmax_t_backwards(
          (uintmax_t)offset,
          buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
      tmp___1 = quotearg_colon(name);
      tmp___2 = ngettext("%s: Read error at byte %s, reading %lu byte",
                         "%s: Read error at byte %s, reading %lu bytes", size);
      error(0, e, (char const *)tmp___2, tmp___1, tmp___0, size);
      exit_status = 2;
    }
    return;
  }
}
void read_warn_details(char const *name, off_t offset, size_t size) {
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  int e;
  int *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  void *__cil_tmp10;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = stringify_uintmax_t_backwards(
          (uintmax_t)offset,
          buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
      tmp___1 = quotearg_colon(name);
      tmp___2 = ngettext(
          "%s: Warning: Read error at byte %s, reading %lu byte",
          "%s: Warning: Read error at byte %s, reading %lu bytes", size);
      error(0, e, (char const *)tmp___2, tmp___1, tmp___0, size);
    }
    return;
  }
}
void read_diag_details(char const *name, off_t offset, size_t size) {

  {
    if (ignore_failed_read_option) {
      {
        read_warn_details(name, offset, size);
      }
    } else {
      { read_error_details(name, offset, size); }
    }
    return;
  }
}
__attribute__((__noreturn__)) void read_fatal(char const *name);

__attribute__((__noreturn__)) void
read_fatal_details(char const *name, off_t offset, size_t size);

void readlink_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("readlink", name); }
    return;
  }
}
void readlink_warn(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_warn("readlink", name); }
    return;
  }
}
void readlink_diag(char const *name) {

  { return; }
}
void savedir_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("savedir", name); }
    return;
  }
}

void savedir_diag(char const *name) {

  { return; }
}
void seek_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("seek", name); }
    return;
  }
}
void seek_error_details(char const *name, off_t offset) {
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  int e;
  int *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  void *__cil_tmp9;
  char *__cil_tmp10;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = stringify_uintmax_t_backwards(
          (uintmax_t)offset,
          buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
      tmp___1 = quotearg_colon(name);
      tmp___2 = gettext("%s: Cannot seek to %s");
      error(0, e, (char const *)tmp___2, tmp___1, tmp___0);
      exit_status = 2;
    }
    return;
  }
}
void seek_warn(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_warn("seek", name); }
    return;
  }
}
void seek_warn_details(char const *name, off_t offset) {
  char buf[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL];
  int e;
  int *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  void *__cil_tmp9;
  char *__cil_tmp10;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = stringify_uintmax_t_backwards(
          (uintmax_t)offset,
          buf + ((((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) + 1UL));
      tmp___1 = quotearg_colon(name);
      tmp___2 = gettext("%s: Warning: Cannot seek to %s");
      error(0, e, (char const *)tmp___2, tmp___1, tmp___0);
    }
    return;
  }
}
void seek_diag_details(char const *name, off_t offset) {

  {
    if (ignore_failed_read_option) {
      {
        seek_warn_details(name, offset);
      }
    } else {
      { seek_error_details(name, offset); }
    }
    return;
  }
}
void symlink_error(char const *contents, char const *name) {
  int e;
  int *tmp;
  char const *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *__cil_tmp8;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = quote_n(1, contents);
      tmp___1 = quotearg_colon(name);
      tmp___2 = gettext("%s: Cannot create symlink to %s");
      error(0, e, (char const *)tmp___2, tmp___1, tmp___0);
      exit_status = 2;
    }
    return;
  }
}
void stat_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("stat", name); }
    return;
  }
}
void stat_warn(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_warn("stat", name); }
    return;
  }
}
void stat_diag(char const *name) {

  {
    if (ignore_failed_read_option) {
      {
        stat_warn(name);
      }
    } else {
      { stat_error(name); }
    }
    return;
  }
}
void truncate_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("truncate", name); }
    return;
  }
}
void truncate_warn(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_warn("truncate", name); }
    return;
  }
}
void unlink_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("unlink", name); }
    return;
  }
}
void utime_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("utime", name); }
    return;
  }
}

void write_error(char const *name) {
  char *__cil_tmp2;

  {
    { call_arg_error("write", name); }
    return;
  }
}
void write_error_details(char const *name, size_t status, size_t size) {
  char *tmp;

  {
    if (status == 0UL) {
      {
        write_error(name);
      }
    } else {
      {
        tmp = ngettext("%s: Wrote only %lu of %lu byte",
                       "%s: Wrote only %lu of %lu bytes", size);
        error(0, 0, (char const *)tmp, name, status, size);
        exit_status = 2;
      }
    }
    return;
  }
}
__attribute__((__noreturn__)) void
write_fatal_details(char const *name, ssize_t status, size_t size);
void write_fatal_details(char const *name, ssize_t status, size_t size) {

  {
    {
      write_error_details(name, (size_t)status, size);
      fatal_exit();
    }
  }
}
pid_t xfork(void) {
  pid_t p;
  __pid_t tmp;
  char *tmp___0;
  char *__cil_tmp4;
  char *__cil_tmp5;

  {
    {
      tmp = fork();
      p = tmp;
    }
    if (p == -1) {
      {
        tmp___0 = gettext("child process");
        call_arg_fatal("fork", (char const *)tmp___0);
      }
    }
    return (p);
  }
}
void xpipe(int *fd) {
  char *tmp;
  int tmp___0;
  char *__cil_tmp4;
  char *__cil_tmp5;

  {
    { tmp___0 = pipe(fd); }

    return;
  }
}
char const *quote_n(int n, char const *name) {
  char *tmp;

  {
    { tmp = quotearg_n_style(n, (enum quoting_style)5, name); }
    return ((char const *)tmp);
  }
}
char const *quote(char const *name) {
  char const *tmp;

  {
    { tmp = quote_n(0, name); }
    return (tmp);
  }
}
/* #pragma merger("0","00a.names.o.i","") */
extern int getc_unlocked(FILE *__stream);
extern struct passwd *getpwuid(__uid_t __uid);
extern struct passwd *getpwnam(char const *__name);
extern struct group *getgrgid(__gid_t __gid);
extern struct group *getgrnam(char const *__name);
_Bool excluded_filename(struct exclude const *ex, char const *f);
char filename_terminator;
struct exclude *excluded;
char const *files_from_option;
_Bool same_order_option;
_Bool starting_file_option;
void init_names(void);
void name_add(char const *name);
void name_init(void);
void name_term(void);
void name_close(void);
struct name *addname(char const *string, int change_dir___0);
void add_avoided_name(char const *name);
void request_stdin(char const *option);
static char *cached_uname;
static char *cached_gname;
static uid_t cached_uid;
static gid_t cached_gid;
static char *cached_no_such_uname;
static char *cached_no_such_gname;
static uid_t cached_no_such_uid;
static gid_t cached_no_such_gid;
void uid_to_uname(uid_t uid, char **uname) {
  struct passwd *passwd;
  char *__cil_tmp4;
  char *__cil_tmp5;

  {
    if (uid != 0U) {
      if (uid == cached_no_such_uid) {
        {
          *uname = strdup("");
        }
        return;
      }
    }
    if (!cached_uname) {
      goto _L___3;
    } else {
      if (uid != cached_uid) {
      _L___3: { /* CIL Label */
        passwd = getpwuid(uid);
      }
        if (passwd) {
          {
            cached_uid = uid;
            assign_string(&cached_uname, (char const *)passwd->pw_name);
          }
        } else {
          {
            cached_no_such_uid = uid;
            *uname = strdup("");
          }
          return;
        }
      }
    }
    { *uname = strdup((char const *)cached_uname); }
    return;
  }
}
void gid_to_gname(gid_t gid, char **gname) {
  struct group *group;
  char *__cil_tmp4;
  char *__cil_tmp5;

  {
    if (gid != 0U) {
      if (gid == cached_no_such_gid) {
        {
          *gname = strdup("");
        }
        return;
      }
    }

    { *gname = strdup((char const *)cached_gname); }
    return;
  }
}
int uname_to_uid(char const *uname, uid_t *uidp) {
  struct passwd *passwd;
  int tmp;
  int tmp___0;

  {
    if (cached_no_such_uname) {
      {
        tmp = strcmp(uname, (char const *)cached_no_such_uname);
      }
    }
    if (!cached_uname) {
      goto _L;
    } else {
      if ((int const) * (uname + 0) != (int const) * (cached_uname + 0)) {
        goto _L;
      } else {
        { tmp___0 = strcmp(uname, (char const *)cached_uname); }
        if (tmp___0 != 0) {
        _L: { passwd = getpwnam(uname); }
          if (passwd) {
            {
              cached_uid = passwd->pw_uid;
              assign_string(&cached_uname, (char const *)passwd->pw_name);
            }
          } else {
            { assign_string(&cached_no_such_uname, uname); }
            return (0);
          }
        }
      }
    }
    *uidp = cached_uid;
    return (1);
  }
}
int gname_to_gid(char const *gname, gid_t *gidp) {
  struct group *group;
  int tmp;
  int tmp___0;

  {
    if (cached_no_such_gname) {
      {
        tmp = strcmp(gname, (char const *)cached_no_such_gname);
      }
      if (tmp == 0) {
        return (0);
      }
    }
    if (!cached_gname) {
      goto _L;
    } else {
      if ((int const) * (gname + 0) != (int const) * (cached_gname + 0)) {
        goto _L;
      } else {
        { tmp___0 = strcmp(gname, (char const *)cached_gname); }
        if (tmp___0 != 0) {
        _L: { group = getgrnam(gname); }
          if (group) {
            {
              cached_gid = group->gr_gid;
              assign_string(&cached_gname, gname);
            }
          } else {
            { assign_string(&cached_no_such_gname, gname); }
            return (0);
          }
        }
      }
    }
    *gidp = cached_gid;
    return (1);
  }
}
static struct name *namelist;
static struct name **nametail = &namelist;
static char const **name_array;
static int allocated_names;
static int names;
static int name_index;
void init_names(void) {
  void *tmp;

  {
    {
      allocated_names = 10;
      tmp = xmalloc(sizeof(char const *) * (unsigned long)allocated_names);
      name_array = (char const **)tmp;
      names = 0;
    }
    return;
  }
}
void name_add(char const *name) {
  void *tmp;
  int tmp___0;

  {
    if (names == allocated_names) {
      {
        allocated_names *= 2;
        tmp = xrealloc((void *)name_array,
                       sizeof(char const *) * (unsigned long)allocated_names);
        name_array = (char const **)tmp;
      }
    }
    tmp___0 = names;
    names++;
    *(name_array + tmp___0) = name;
    return;
  }
}
static FILE *name_file;
static char *name_buffer;
static size_t name_buffer_length;
__inline static int is_pattern(char const *string) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  int tmp___2;

  {
    { tmp = strchr(string, '*'); }
    if (tmp) {
      tmp___2 = 1;
    } else {
      { tmp___0 = strchr(string, '['); }
    }
    return (tmp___2);
  }
}
void name_init(void) {
  void *tmp;
  int tmp___0;
  char *__cil_tmp3;

  {
    {
      tmp = xmalloc((size_t)102);
      name_buffer = (char *)tmp;
      name_buffer_length = (size_t)100;
    }
    if (files_from_option) {
      {
        tmp___0 = strcmp(files_from_option, "-");
      }
      if (tmp___0) {
        {
          name_file = fopen((char const * /* __restrict  */)files_from_option,
                            (char const * /* __restrict  */) "r");
        }
        if (!name_file) {
          {
            open_fatal(files_from_option);
          }
        }
      } else {
        {
          request_stdin("-T");
          name_file = stdin;
        }
      }
    }
    return;
  }
}
void name_term(void) {

  {
    {
      free((void *)name_buffer);
      free((void *)name_array);
    }
    return;
  }
}
static int read_name_from_file(void) {
  int character;
  size_t counter;
  void *tmp;
  size_t tmp___0;
  void *tmp___1;

  {
    counter = (size_t)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { character = getc_unlocked(name_file); }
        if (character != -1) {
          if (!(character != (int)filename_terminator)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        if (counter == name_buffer_length) {
          if (name_buffer_length * 2UL < name_buffer_length) {
            {
              xalloc_die();
            }
          }
          {
            name_buffer_length *= 2UL;
            tmp = xrealloc((void *)name_buffer, name_buffer_length + 2UL);
            name_buffer = (char *)tmp;
          }
        }
        tmp___0 = counter;
        counter++;
        *(name_buffer + tmp___0) = (char)character;
      }
    while_break: /* CIL Label */
        ;
    }
    if (counter == 0UL) {
      if (character == -1) {
        return (0);
      }
    }
    if (counter == name_buffer_length) {
      if (name_buffer_length * 2UL < name_buffer_length) {
        {
          xalloc_die();
        }
      }
      {
        name_buffer_length *= 2UL;
        tmp___1 = xrealloc((void *)name_buffer, name_buffer_length + 2UL);
        name_buffer = (char *)tmp___1;
      }
    }
    *(name_buffer + counter) = (char)'\000';
    return (1);
  }
}
char *name_next(int change_dirs) {
  char const *source;
  char *cursor;
  int chdir_flag;
  int tmp;
  size_t source_len;
  int tmp___0;
  void *tmp___1;
  size_t tmp___2;
  char *tmp___3;
  int tmp___4;
  int tmp___5;
  char *tmp___6;
  char *__cil_tmp14;

  {
    chdir_flag = 0;

    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (name_index == names) {
          if (!name_file) {
            goto while_break;
          }
          { tmp = read_name_from_file(); }
          if (!tmp) {
            goto while_break;
          }
        } else {
          {
            tmp___0 = name_index;
            name_index++;
            source = *(name_array + tmp___0);
            source_len = strlen(source);
          }
          if (name_buffer_length < source_len) {
            {
              while (1) {
              while_continue___0: /* CIL Label */
                  ;
                name_buffer_length *= 2UL;
                if (!name_buffer_length) {
                  {
                    xalloc_die();
                  }
                }
                if (!(name_buffer_length < source_len)) {
                  goto while_break___0;
                }
              }
            while_break___0: /* CIL Label */
                ;
            }
            {
              free((void *)name_buffer);
              tmp___1 = xmalloc(name_buffer_length + 2UL);
              name_buffer = (char *)tmp___1;
            }
          }
          {
            strcpy((char * /* __restrict  */)name_buffer,
                   (char const * /* __restrict  */)source);
          }
        }
        {
          tmp___2 = strlen((char const *)name_buffer);
          cursor = (name_buffer + tmp___2) - 1;
        }
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            if ((unsigned long)cursor > (unsigned long)name_buffer) {
              if (!((int)*cursor == 47)) {
                goto while_break___1;
              }
            } else {
              goto while_break___1;
            }
            tmp___3 = cursor;
            cursor--;
            *tmp___3 = (char)'\000';
          }
        while_break___1: /* CIL Label */
            ;
        }
        if (chdir_flag) {
          {
            tmp___4 = chdir((char const *)name_buffer);
          }
          if (tmp___4 < 0) {
            {
              chdir_fatal((char const *)name_buffer);
            }
          }
          chdir_flag = 0;
        } else {
          if (change_dirs) {
            {
              tmp___5 = strcmp((char const *)name_buffer, "-C");
            }
            if (tmp___5 == 0) {
              chdir_flag = 1;
            } else {
              { unquote_string(name_buffer); }
              return (name_buffer);
            }
          } else {
            { unquote_string(name_buffer); }
            return (name_buffer);
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }

    return ((char *)0);
  }
}

static struct name *buffer___0;
static size_t allocated_size;
static int change_dir;
void name_gather(void) {
  char const *name;
  void *tmp;
  char const *dir;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  int tmp___4;
  size_t needed_size;
  void *tmp___5;
  int change_dir___0;
  int change_dir0;
  char const *dir___0;
  char *tmp___6;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  int tmp___10;
  char *__cil_tmp19;
  char *__cil_tmp20;

  {
    if (same_order_option) {
      if (allocated_size == 0UL) {
        {
          allocated_size =
              ((unsigned long)(&((struct name *)0)->name) + 100UL) + 1UL;
          tmp = xmalloc(allocated_size);
          buffer___0 = (struct name *)tmp;
          memset((void *)buffer___0, 0, allocated_size);
        }
      }
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          {
            tmp___3 = name_next(0);
            name = (char const *)tmp___3;
          }
          if (name) {
            {
              tmp___4 = strcmp(name, "-C");
            }
            if (!(tmp___4 == 0)) {
              goto while_break;
            }
          } else {
            goto while_break;
          }
          {
            tmp___0 = name_next(0);
            dir = (char const *)tmp___0;
          }

          {
            tmp___2 = xstrdup(dir);
            change_dir = chdir_arg((char const *)tmp___2);
          }
        }
      while_break: /* CIL Label */
          ;
      }
      if (name) {
        {
          buffer___0->length = strlen(name);
          needed_size = ((unsigned long)(&((struct name *)0)->name) +
                         buffer___0->length) +
                        1UL;
        }
        if (allocated_size < needed_size) {
          {
            while (1) {
            while_continue___0: /* CIL Label */
                ;
              allocated_size *= 2UL;

              if (!(allocated_size < needed_size)) {
                goto while_break___0;
              }
            }
          while_break___0: /* CIL Label */
              ;
          }
          {
            tmp___5 = xrealloc((void *)buffer___0, allocated_size);
            buffer___0 = (struct name *)tmp___5;
          }
        }
        {
          buffer___0->change_dir = change_dir;
          strcpy((char * /* __restrict  */)(buffer___0->name),
                 (char const * /* __restrict  */)name);
          buffer___0->next = (struct name *)0;
          buffer___0->found_count = (uintmax_t)0;
          namelist = buffer___0;
          nametail = &namelist->next;
        }
      } else {
        if (change_dir) {
          {
            addname((char const *)0, change_dir);
          }
        }
      }
    } else {
      change_dir___0 = 0;
      {
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          change_dir0 = change_dir___0;
          {
            while (1) {
            while_continue___2: /* CIL Label */
                ;
              {
                tmp___9 = name_next(0);
                name = (char const *)tmp___9;
              }
              if (name) {
                {
                  tmp___10 = strcmp(name, "-C");
                }
                if (!(tmp___10 == 0)) {
                  goto while_break___2;
                }
              } else {
                goto while_break___2;
              }
              {
                tmp___6 = name_next(0);
                dir___0 = (char const *)tmp___6;
              }

              {
                tmp___8 = xstrdup(dir___0);
                change_dir___0 = chdir_arg((char const *)tmp___8);
              }
            }
          while_break___2: /* CIL Label */
              ;
          }
          if (name) {
            {
              addname(name, change_dir___0);
            }
          } else {
            if (change_dir___0 != change_dir0) {
              {
                addname((char const *)0, change_dir___0);
              }
            }
            goto while_break___1;
          }
        }
      while_break___1: /* CIL Label */
          ;
      }
    }
    return;
  }
}
struct name *addname(char const *string, int change_dir___0) {
  size_t length;
  size_t tmp;
  size_t tmp___0;
  struct name *name;
  void *tmp___1;
  int tmp___2;

  {
    if (string) {
      {
        tmp = strlen(string);
        tmp___0 = tmp;
      }
    } else {
      tmp___0 = (size_t)0;
    }
    {
      length = tmp___0;
      tmp___1 =
          xmalloc(((unsigned long)(&((struct name *)0)->name) + length) + 1UL);
      name = (struct name *)tmp___1;
    }
    if (string) {
      {
        name->fake = (char)0;
        strcpy((char * /* __restrict  */)(name->name),
               (char const * /* __restrict  */)string);
      }
    } else {
      name->fake = (char)1;
      name->name[0] = (char)0;
    }
    name->next = (struct name *)0;
    name->length = length;
    name->found_count = (uintmax_t)0;
    name->regexp = (char)0;
    name->firstch = (char)1;
    name->change_dir = change_dir___0;
    name->dir_contents = (char const *)0;
    if (string) {
      {
        tmp___2 = is_pattern(string);
      }
      if (tmp___2) {
        name->regexp = (char)1;
        if ((int const) * (string + 0) == 42) {
          name->firstch = (char)0;
        } else {
          if ((int const) * (string + 0) == 91) {
            name->firstch = (char)0;
          } else {
            if ((int const) * (string + 0) == 63) {
              name->firstch = (char)0;
            }
          }
        }
      }
    }
    *nametail = name;
    nametail = &name->next;
    return (name);
  }
}
static struct name *namelist_match(char const *path, size_t length) {
  struct name *p;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;

  {
    p = namelist;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!p) {
          goto while_break;
        }
        if (p->firstch) {
          if ((int)p->name[0] != (int)*(path + 0)) {
            goto __Cont;
          }
        }
        if (p->regexp) {
          {
            tmp = fnmatch((char const *)(p->name), path, recursion_option);
            tmp___2 = tmp == 0;
          }
        } else {
          if (p->length <= length) {
            if ((int const) * (path + p->length) == 0) {
              goto _L___3;
            } else {
              if ((int const) * (path + p->length) == 47) {
                if (recursion_option) {
                _L___3: { /* CIL Label */
                  tmp___0 = memcmp((void const *)path, (void const *)(p->name),
                                   p->length);
                }
                  if (tmp___0 == 0) {
                    tmp___1 = 1;
                  } else {
                    tmp___1 = 0;
                  }
                } else {
                  tmp___1 = 0;
                }
              } else {
                tmp___1 = 0;
              }
            }
          } else {
            tmp___1 = 0;
          }
          tmp___2 = tmp___1;
        }
        if (tmp___2) {
          return (p);
        }
      __Cont:
        p = p->next;
      }
    while_break: /* CIL Label */
        ;
    }
    return ((struct name *)0);
  }
}
int name_match(char const *path) {
  size_t length;
  size_t tmp;
  struct name *cursor;
  uintmax_t tmp___0;

  {
    {
      tmp = strlen(path);
      length = tmp;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        cursor = namelist;
        if (!cursor) {
          return (!files_from_option);
        }
        if (cursor->fake) {
          {
            chdir_do(cursor->change_dir);
            namelist = (struct name *)0;
            nametail = &namelist;
          }
          return (!files_from_option);
        }
        { cursor = namelist_match(path, length); }
        if (cursor) {
          if ((int const) * (path + cursor->length) == 47) {
            if (recursion_option) {
              if (cursor->found_count == 0UL) {
                (cursor->found_count)++;
              }
            } else {
              (cursor->found_count)++;
            }
          } else {
            (cursor->found_count)++;
          }
          if (starting_file_option) {
            {
              free((void *)namelist);
              namelist = (struct name *)0;
              nametail = &namelist;
            }
          }
          { chdir_do(cursor->change_dir); }
          if (occurrence_option == 0UL) {
            tmp___0 = cursor->found_count;
          } else {
            tmp___0 = (uintmax_t)(cursor->found_count == occurrence_option);
          }
          return ((int)tmp___0);
        }
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
_Bool all_names_found(struct tar_stat_info *p) {
  struct name const *cursor;
  size_t len;
  uintmax_t tmp;

  {
    if (!p->file_name) {
      return ((_Bool)0);
    } else {
      if (occurrence_option == 0UL) {
        return ((_Bool)0);
      } else {
      }
    }
    {
      len = strlen((char const *)p->file_name);
      cursor = (struct name const *)namelist;
    }
    {

    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
void names_notfound(void) {
  struct name const *cursor;
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *name;
  char *tmp___3;
  char *tmp___4;
  uintmax_t tmp___5;
  char *__cil_tmp10;
  char *__cil_tmp11;
  char *__cil_tmp12;

  {
    cursor = (struct name const *)namelist;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!cursor) {
          goto while_break;
        }
        if (occurrence_option == 0UL) {
          tmp___5 = cursor->found_count;
        } else {
          tmp___5 = (uintmax_t const)(cursor->found_count >=
                                      (uintmax_t const)occurrence_option);
        }
        if (!tmp___5) {
          if (!cursor->fake) {
            if (cursor->found_count == 0UL) {
              {
                tmp = quotearg_colon((char const *)(cursor->name));
                tmp___0 = gettext("%s: Not found in archive");
                error(0, 0, (char const *)tmp___0, tmp);
                exit_status = 2;
              }
            } else {
              {
                tmp___1 = quotearg_colon((char const *)(cursor->name));
                tmp___2 =
                    gettext("%s: Required occurrence not found in archive");
                error(0, 0, (char const *)tmp___2, tmp___1);
                exit_status = 2;
              }
            }
          }
        }
        cursor = (struct name const *)cursor->next;
      }
    while_break: /* CIL Label */
        ;
    }
    namelist = (struct name *)0;
    nametail = &namelist;

    return;
  }
}
static struct name *merge_sort(struct name *list, int length,
                               int (*compare)(struct name const *,
                                              struct name const *)) {
  struct name *first_list;
  struct name *second_list;
  int first_length;
  int second_length;
  struct name *result;
  struct name **merge_point;
  struct name *cursor;
  int counter;
  int tmp;
  int tmp___0;

  {
    if (length == 1) {
      return (list);
    }
    if (length == 2) {
      {
        tmp = (*compare)((struct name const *)list,
                         (struct name const *)list->next);
      }

      return (list);
    }
    first_list = list;
    first_length = (length + 1) / 2;
    second_length = length / 2;
    cursor = list;
    counter = first_length - 1;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!counter) {
          goto while_break;
        }
        goto __Cont;
      __Cont:
        cursor = cursor->next;
        counter--;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      second_list = cursor->next;
      cursor->next = (struct name *)0;
      first_list = merge_sort(first_list, first_length, compare);
      second_list = merge_sort(second_list, second_length, compare);
      merge_point = &result;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (first_list) {
          if (!second_list) {
            goto while_break___0;
          }
        } else {
          goto while_break___0;
        }
        {
          tmp___0 = (*compare)((struct name const *)first_list,
                               (struct name const *)second_list);
        }
        if (tmp___0 < 0) {
          cursor = first_list->next;
          *merge_point = first_list;
          merge_point = &first_list->next;
          first_list = cursor;
        } else {
          cursor = second_list->next;
          *merge_point = second_list;
          merge_point = &second_list->next;
          second_list = cursor;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    if (first_list) {
      *merge_point = first_list;
    } else {
      *merge_point = second_list;
    }
    return (result);
  }
}
static int compare_names(struct name const *n1, struct name const *n2) {
  int found_diff;
  int tmp;
  int tmp___0;
  uintmax_t tmp___1;
  uintmax_t tmp___2;

  {
    if (occurrence_option == 0UL) {
      tmp___1 = n2->found_count;
    } else {
      tmp___1 = (uintmax_t const)(n2->found_count >=
                                  (uintmax_t const)occurrence_option);
    }
    if (occurrence_option == 0UL) {
      tmp___2 = n1->found_count;
    } else {
      tmp___2 = (uintmax_t const)(n1->found_count >=
                                  (uintmax_t const)occurrence_option);
    }
    found_diff = (int)(tmp___1 - tmp___2);
    if (found_diff) {
      tmp___0 = found_diff;
    } else {
      {
        tmp = strcmp((char const *)(n1->name), (char const *)(n2->name));
        tmp___0 = tmp;
      }
    }
    return (tmp___0);
  }
}

void collect_and_sort_names(void) {
  struct name *name;
  struct name *next_name;
  int num_names;
  struct stat statbuf;
  int tmp;
  void *__cil_tmp6;
  char *__cil_tmp7;

  {
    { name_gather(); }

    if (!namelist) {
      {
        addname(".", 0);
      }
    }
    name = namelist;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!name) {
          goto while_break;
        }
        next_name = name->next;
        if (name->found_count) {
          goto __Cont;
        } else {
        }

        { chdir_do(name->change_dir); }
        if (name->fake) {
          goto __Cont;
        }
        {
          tmp = deref_stat(dereference_option, (char const *)(name->name),
                           &statbuf);
        }
        if (tmp != 0) {
          {
            stat_diag((char const *)(name->name));
          }
          goto __Cont;
        }

      __Cont:
        name = next_name;
      }
    while_break: /* CIL Label */
        ;
    }
    num_names = 0;
    name = namelist;
    {

    while_break___0: /* CIL Label */
        ;
    }
    {
      namelist = merge_sort(namelist, num_names, &compare_names);
      name = namelist;
    }
    {

    while_break___1: /* CIL Label */
        ;
    }
    return;
  }
}
struct name *name_scan(char const *path) {
  size_t length;
  size_t tmp;
  struct name *cursor;
  struct name *tmp___0;

  {
    {
      tmp = strlen(path);
      length = tmp;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          tmp___0 = namelist_match(path, length);
          cursor = tmp___0;
        }
        if (cursor) {
          return (cursor);
        }
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
char *name_from_list(void) {

  {
    if (!gnu_list_name) {
      gnu_list_name = namelist;
    }
    {

    while_break: /* CIL Label */
        ;
    }
    if (gnu_list_name) {
      {
        (gnu_list_name->found_count)++;
        chdir_do(gnu_list_name->change_dir);
      }
      return (gnu_list_name->name);
    }
    return ((char *)0);
  }
}
void blank_name_list(void) {
  struct name *name;

  {
    gnu_list_name = (struct name *)0;
    name = namelist;
    {

    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
char *new_name(char const *path, char const *name) {
  size_t pathlen;
  size_t tmp;
  size_t namesize;
  size_t tmp___0;
  int slash;
  char *buffer___2;
  void *tmp___1;
  int tmp___2;

  {
    {
      tmp = strlen(path);
      pathlen = tmp;
      tmp___0 = strlen(name);
      namesize = tmp___0 + 1UL;
    }
    if (pathlen) {

    } else {
      tmp___2 = 0;
    }
    {
      slash = tmp___2;
      tmp___1 = xmalloc((pathlen + (size_t)slash) + namesize);
      buffer___2 = (char *)tmp___1;
      memcpy((void * /* __restrict  */)buffer___2,
             (void const * /* __restrict  */)path, pathlen);
      *(buffer___2 + pathlen) = (char)'/';
      memcpy((void * /* __restrict  */)((buffer___2 + pathlen) + slash),
             (void const * /* __restrict  */)name, namesize);
    }
    return (buffer___2);
  }
}
_Bool excluded_name(char const *name) {
  _Bool tmp;

  {
    { tmp = excluded_filename((struct exclude const *)excluded, name + 0); }
    return (tmp);
  }
}
static unsigned int hash_string_hasher(void const *name,
                                       unsigned int n_buckets) {
  size_t tmp;

  {
    { tmp = hash_string((char const *)name, (size_t)n_buckets); }
    return ((unsigned int)tmp);
  }
}
static _Bool hash_string_compare(void const *name1, void const *name2) {
  int tmp;

  {
    { tmp = strcmp((char const *)name1, (char const *)name2); }
    return ((_Bool)(tmp == 0));
  }
}
static _Bool hash_string_insert(Hash_table **table___0, char const *string) {
  Hash_table *t;
  char *s;
  char *tmp;
  char *e;
  Hash_table *tmp___0;
  void *tmp___1;

  {
    {
      t = *table___0;
      tmp = xstrdup(string);
      s = tmp;
    }
    if (t) {
      goto _L;
    } else {
      {
        t = hash_initialize(
            (size_t)0, (Hash_tuning const *)0,
            (size_t(*)(void const *, size_t))(&hash_string_hasher),
            &hash_string_compare, (void (*)(void *))0);
        tmp___0 = t;
        *table___0 = tmp___0;
      }
      if (tmp___0) {
      _L: {
        tmp___1 = hash_insert(t, (void const *)s);
        e = (char *)tmp___1;
      }
        if (!e) {
          {
            xalloc_die();
          }
        }
      } else {
        { xalloc_die(); }
      }
    }
    if ((unsigned long)e == (unsigned long)s) {
      return ((_Bool)1);
    } else {
      { free((void *)s); }
      return ((_Bool)0);
    }
  }
}
static _Bool hash_string_lookup(Hash_table const *table___0,
                                char const *string) {
  void *tmp;
  int tmp___0;

  {
    if (table___0) {
      {
        tmp = hash_lookup(table___0, (void const *)string);
      }
      if (tmp) {
        tmp___0 = 1;
      } else {
        tmp___0 = 0;
      }
    } else {
      tmp___0 = 0;
    }
    return ((_Bool)tmp___0);
  }
}
static Hash_table *avoided_name_table;

_Bool is_avoided_name(char const *name) {
  _Bool tmp;

  {
    { tmp = hash_string_lookup((Hash_table const *)avoided_name_table, name); }
    return (tmp);
  }
}
static Hash_table *prefix_table[2];
static char const *const diagnostic[2] = {
    (char const * /* const  */) "Removing leading `%s\' from member names",
    (char const
         * /* const  */) "Removing leading `%s\' from hard link targets"};
static char const *const diagnostic___0[2] = {
    (char const * /* const  */) "Substituting `.\' for empty member name",
    (char const * /* const  */) "Substituting `.\' for empty hard link target"};
char *safer_name_suffix(char const *file_name, _Bool link_target) {
  char const *p;
  size_t prefix_len;
  char c;
  char const *tmp;
  char *prefix;
  void *tmp___0;
  char *tmp___1;
  _Bool tmp___2;
  char *tmp___3;
  char *__cil_tmp12;

  {
    if (absolute_names_option) {
      p = file_name;
    } else {
      prefix_len = (size_t)0;
      p = file_name + prefix_len;
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if (!*p) {
            goto while_break;
          }
          if ((int const) * (p + 0) == 46) {
          }
          {
            while (1) {
            while_continue___0: /* CIL Label */
                ;
              tmp = p;
              p++;
              c = (char)*tmp;
              if ((int)c == 47) {
                goto while_break___0;
              }
              if (!*p) {
                goto while_break___0;
              }
            }
          while_break___0: /* CIL Label */
              ;
          }
        }
      while_break: /* CIL Label */
          ;
      }
      p = file_name + prefix_len;
      {
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          if (!((int const) * p == 47)) {
            goto while_break___1;
          }
          goto __Cont;
        __Cont:
          p++;
        }
      while_break___1: /* CIL Label */
          ;
      }
      prefix_len = (size_t)(p - file_name);
      if (prefix_len) {
        {
          tmp___0 = __builtin_alloca(prefix_len + 1UL);
          prefix = (char *)tmp___0;
          memcpy((void * /* __restrict  */)prefix,
                 (void const * /* __restrict  */)file_name, prefix_len);
          *(prefix + prefix_len) = (char)'\000';
          tmp___2 = hash_string_insert(&prefix_table[link_target],
                                       (char const *)prefix);
        }
      }
    }
    if (!*p) {

      p = ".";
    }
    return ((char *)p);
  }
}
size_t stripped_prefix_len(char const *file_name, size_t num) {
  char const *p;
  _Bool slash;

  {
    p = file_name + 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!((int const) * p == 47)) {
          goto while_break;
        }
        p++;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!*p) {
          goto while_break___0;
        }
        slash = (_Bool)((int const) * p == 47);
        p++;
        if (slash) {
          num--;
          if (num == 0UL) {
            return ((size_t)(p - file_name));
          }
          {
            while (1) {
            while_continue___1: /* CIL Label */
                ;
              if (!((int const) * p == 47)) {
                goto while_break___1;
              }
              p++;
            }
          while_break___1: /* CIL Label */
              ;
          }
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    return ((size_t)-1);
  }
}
_Bool contains_dot_dot(char const *name) {
  char const *p;
  char const *tmp;

  {
    p = name + 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if ((int const) * (p + 0) == 46) {
          if ((int const) * (p + 1) == 46) {
            if ((int const) * (p + 2) == 47) {
              return ((_Bool)1);
            } else {
            }
          }
        }
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            tmp = p;
            p++;
            if (!*tmp) {
              return ((_Bool)0);
            }
            if (!(!((int const) * p == 47))) {
              goto while_break___0;
            }
          }
        while_break___0: /* CIL Label */
            ;
        }
        p++;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
/* #pragma merger("0","00b.rtapelib.o.i","") */
extern
    __attribute__((__nothrow__)) int(__attribute__((__leaf__)) dup)(int __fd);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__)) execl)(char const *__path,
                                                        char const *__arg, ...);
extern __attribute__((__nothrow__))
__sighandler_t(__attribute__((__leaf__)) signal)(int __sig,
                                                 void (*__handler)(int));
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) atoi)(char const *__nptr)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) long(
    __attribute__((__nonnull__(1), __leaf__)) atol)(char const *__nptr)
    __attribute__((__pure__));
char const *rmt_command_option;
void sys_reset_uid_gid(void);
size_t rmt_write__(int handle, char *buffer___2, size_t length);
static int from_remote[4][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
static int to_remote[4][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
static void _rmt_shutdown(int handle, int errno_value) {
  int *tmp;

  {
    {
      close(from_remote[handle][0]);
      close(to_remote[handle][1]);
      from_remote[handle][0] = -1;
      to_remote[handle][1] = -1;
      tmp = __errno_location();
      *tmp = errno_value;
    }
    return;
  }
}
static int do_command(int handle, char const *buffer___2) {
  size_t length;
  size_t tmp;
  void (*pipe_handler)();
  void (*tmp___0)(int);
  ssize_t written;
  size_t tmp___1;

  {
    {
      tmp = strlen(buffer___2);
      length = tmp;
      tmp___0 = signal(13, (void (*)(int))1);
      pipe_handler = (void (*)())tmp___0;
      tmp___1 =
          full_write(to_remote[handle][1], (void const *)buffer___2, length);
      written = (ssize_t)tmp___1;
      signal(13, (void (*)(int))pipe_handler);
    }
    if ((size_t)written == length) {
      return (0);
    }
    { _rmt_shutdown(handle, 5); }
    return (-1);
  }
}
static char *get_status_string(int handle, char *command_buffer) {
  char *cursor;
  int counter;
  size_t tmp;
  char character;
  size_t tmp___0;
  int *tmp___1;
  int *tmp___2;

  {
    counter = 0;
    cursor = command_buffer;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(counter < 64)) {
          goto while_break;
        }
        { tmp = safe_read(from_remote[handle][0], (void *)cursor, (size_t)1); }
        if (tmp != 1UL) {
          {
            _rmt_shutdown(handle, 5);
          }
          return ((char *)0);
        }
        if ((int)*cursor == 10) {
          *cursor = (char)'\000';
          goto while_break;
        }
        counter++;
        cursor++;
      }
    while_break: /* CIL Label */
        ;
    }
    if (counter == 64) {
      {
        _rmt_shutdown(handle, 5);
      }
      return ((char *)0);
    }
    cursor = command_buffer;
    {

    while_break___0: /* CIL Label */
        ;
    }
    if ((int)*cursor == 69) {
      goto _L___3;
    } else {
      if ((int)*cursor == 70) {
      _L___3: { /* CIL Label */
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          {
            tmp___0 = safe_read(from_remote[handle][0], (void *)(&character),
                                (size_t)1);
          }
          if (!(tmp___0 == 1UL)) {
            goto while_break___1;
          }
          if ((int)character == 10) {
            goto while_break___1;
          }
        }
      while_break___1: /* CIL Label */
          ;
      }
        {
          tmp___1 = __errno_location();
          *tmp___1 = atoi((char const *)(cursor + 1));
        }

        return ((char *)0);
      }
    }

    return (cursor + 1);
  }
}
static long get_status(int handle) {
  char command_buffer[64];
  char const *status;
  char *tmp;
  long result;
  long tmp___0;
  int *tmp___1;
  void *__cil_tmp8;

  {
    {
      tmp = get_status_string(handle, command_buffer);
      status = (char const *)tmp;
    }
    if (status) {
      {
        tmp___0 = atol(status);
        result = tmp___0;
      }
      if (0L <= result) {
        return (result);
      }
      {
        tmp___1 = __errno_location();
        *tmp___1 = 5;
      }
    }
    return (-1L);
  }
}

static void encode_oflag(char *buf, int oflag) {
  char *__cil_tmp3;
  char *__cil_tmp4;
  char *__cil_tmp5;
  char *__cil_tmp6;
  char *__cil_tmp7;
  char *__cil_tmp8;
  char *__cil_tmp9;
  char *__cil_tmp10;
  char *__cil_tmp11;
  char *__cil_tmp12;
  char *__cil_tmp13;
  char *__cil_tmp14;
  char *__cil_tmp15;

  {
    {
      sprintf((char * /* __restrict  */)buf,
              (char const * /* __restrict  */) "%d ", oflag);
    }
    {
      if ((oflag & 3) == 0) {
        goto case_0;
      }
      if ((oflag & 3) == 2) {
        goto case_2;
      }
      if ((oflag & 3) == 1) {
        goto case_1;
      }
      goto switch_default;
    case_0: { /* CIL Label */
      strcat((char * /* __restrict  */)buf,
             (char const * /* __restrict  */) "O_RDONLY");
    }
      goto switch_break;
    case_2: { /* CIL Label */
      strcat((char * /* __restrict  */)buf,
             (char const * /* __restrict  */) "O_RDWR");
    }
      goto switch_break;
    case_1: { /* CIL Label */
      strcat((char * /* __restrict  */)buf,
             (char const * /* __restrict  */) "O_WRONLY");
    }
      goto switch_break;
    switch_default: { /* CIL Label */
      abort();
    }
    switch_break: /* CIL Label */
        ;
    }

    if (oflag & 64) {
      {
        strcat((char * /* __restrict  */)buf,
               (char const * /* __restrict  */) "|O_CREAT");
      }
    }

    if (oflag & 2048) {
      {
        strcat((char * /* __restrict  */)buf,
               (char const * /* __restrict  */) "|O_NONBLOCK");
      }
    }

    return;
  }
}
int rmt_open__(char const *path, int open_mode, int bias,
               char const *remote_shell) {
  int remote_pipe_number;
  char *path_copy;
  char *remote_host;
  char *remote_file;
  char *remote_user;
  int *tmp;
  char *cursor;
  int *tmp___0;
  char const *remote_shell_basename;
  pid_t status;
  char *tmp___1;
  int e;
  int *tmp___2;
  int *tmp___3;
  int tmp___4;
  int tmp___5;
  int e___0;
  int *tmp___6;
  int *tmp___7;
  char *tmp___8;
  int *tmp___9;
  size_t remote_file_len;
  size_t tmp___10;
  char *command_buffer;
  void *tmp___11;
  int e___1;
  int *tmp___12;
  int tmp___13;
  long tmp___14;
  char const *tmp___15;
  char const *tmp___16;
  char *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;
  char *__cil_tmp39;
  char *__cil_tmp40;
  char *__cil_tmp41;

  {
    remote_pipe_number = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(remote_pipe_number < 4)) {
          goto while_break;
        }
        if (from_remote[remote_pipe_number][0] == -1) {
          if (to_remote[remote_pipe_number][1] == -1) {
            goto while_break;
          }
        }
        remote_pipe_number++;
      }
    while_break: /* CIL Label */
        ;
    }

    {
      path_copy = xstrdup(path);
      remote_host = path_copy;
      remote_user = (char *)0;
      remote_file = (char *)0;
      cursor = path_copy;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!*cursor) {
          goto while_break___0;
        }
        {
          if ((int)*cursor == 10) {
            goto case_10;
          }
          if ((int)*cursor == 64) {
            goto case_64;
          }
          if ((int)*cursor == 58) {
            goto case_58;
          }
          goto switch_default;
        switch_default: /* CIL Label */
          goto switch_break;
        case_10: { /* CIL Label */
          free((void *)path_copy);
          tmp___0 = __errno_location();
          *tmp___0 = 2;
        }
          return (-1);
        case_64: /* CIL Label */

          goto switch_break;
        case_58: /* CIL Label */
          if (!remote_file) {
            *cursor = (char)'\000';
            remote_file = cursor + 1;
          }
          goto switch_break;
        switch_break: /* CIL Label */
            ;
        }
        cursor++;
      }
    while_break___0: /* CIL Label */
        ;
    }

    {
      tmp___1 = base_name(remote_shell);
      remote_shell_basename = (char const *)tmp___1;
      tmp___4 = pipe(to_remote[remote_pipe_number]);
    }
    if (tmp___4 == -1) {
      goto _L;
    } else {
      { tmp___5 = pipe(from_remote[remote_pipe_number]); }
      if (tmp___5 == -1) {
      _L: {
        tmp___2 = __errno_location();
        e = *tmp___2;
        free((void *)path_copy);
        tmp___3 = __errno_location();
        *tmp___3 = e;
      }
        return (-1);
      }
    }
    { status = fork(); }

    if (status == 0) {
      {
        close(0);
        dup(to_remote[remote_pipe_number][0]);
        close(to_remote[remote_pipe_number][0]);
        close(to_remote[remote_pipe_number][1]);
        close(1);
        dup(from_remote[remote_pipe_number][1]);
        close(from_remote[remote_pipe_number][0]);
        close(from_remote[remote_pipe_number][1]);
        sys_reset_uid_gid();
      }

      {
        tmp___8 = gettext("Cannot execute remote shell");
        tmp___9 = __errno_location();
        error(128, *tmp___9, (char const *)tmp___8);
      }
    }
    {
      close(from_remote[remote_pipe_number][1]);
      close(to_remote[remote_pipe_number][0]);
      tmp___10 = strlen((char const *)remote_file);
      remote_file_len = tmp___10;
      tmp___11 = xmalloc(remote_file_len + 1000UL);
      command_buffer = (char *)tmp___11;
      sprintf((char * /* __restrict  */)command_buffer,
              (char const * /* __restrict  */) "O%s\n", remote_file);
      encode_oflag((command_buffer + remote_file_len) + 2, open_mode);
      strcat((char * /* __restrict  */)command_buffer,
             (char const * /* __restrict  */) "\n");
      tmp___13 = do_command(remote_pipe_number, (char const *)command_buffer);
    }
    if (tmp___13 == -1) {
      goto _L___0;
    } else {
      { tmp___14 = get_status(remote_pipe_number); }
      if (tmp___14 == -1L) {
      _L___0: {
        tmp___12 = __errno_location();
        e___1 = *tmp___12;
        free((void *)command_buffer);
        free((void *)path_copy);
        _rmt_shutdown(remote_pipe_number, e___1);
      }
        return (-1);
      }
    }
    {
      free((void *)command_buffer);
      free((void *)path_copy);
    }
    return (remote_pipe_number + bias);
  }
}
int rmt_close__(int handle) {
  long status;
  int tmp;
  int *tmp___0;
  char *__cil_tmp5;

  {
    { tmp = do_command(handle, "C\n"); }
    if (tmp == -1) {
      return (-1);
    }
    {
      status = get_status(handle);
      tmp___0 = __errno_location();
      _rmt_shutdown(handle, *tmp___0);
    }
    return ((int)status);
  }
}
size_t rmt_read__(int handle, char *buffer___2, size_t length) {
  char command_buffer[64];
  size_t status;
  size_t rlen;
  size_t counter;
  int tmp;
  long tmp___0;
  void *__cil_tmp10;
  char *__cil_tmp11;

  {
    {
      sprintf((char * /* __restrict  */)(command_buffer),
              (char const * /* __restrict  */) "R%lu\n", length);
      tmp = do_command(handle, (char const *)(command_buffer));
    }
    if (tmp == -1) {
      return ((size_t)-1);
    } else {
      {
        tmp___0 = get_status(handle);
        status = (size_t)tmp___0;
      }
      if (status == 0xffffffffffffffffUL) {
        return ((size_t)-1);
      }
    }
    counter = (size_t)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(counter < status)) {
          goto while_break;
        }
        {
          rlen = safe_read(from_remote[handle][0], (void *)buffer___2,
                           status - counter);
        }
        if (rlen == 0xffffffffffffffffUL) {
          {
            _rmt_shutdown(handle, 5);
          }
          return ((size_t)-1);
        } else {
          if (rlen == 0UL) {
            {
              _rmt_shutdown(handle, 5);
            }
            return ((size_t)-1);
          }
        }
        counter += rlen;
        buffer___2 += rlen;
      }
    while_break: /* CIL Label */
        ;
    }
    return (status);
  }
}
size_t rmt_write__(int handle, char *buffer___2, size_t length) {
  char command_buffer[64];
  void (*pipe_handler)();
  size_t written;
  int tmp;
  void (*tmp___0)(int);
  long r;
  long tmp___1;
  void *__cil_tmp11;
  char *__cil_tmp12;

  {
    {
      sprintf((char * /* __restrict  */)(command_buffer),
              (char const * /* __restrict  */) "W%lu\n", length);
      tmp = do_command(handle, (char const *)(command_buffer));
    }
    if (tmp == -1) {
      return ((size_t)0);
    }
    {
      tmp___0 = signal(13, (void (*)(int))1);
      pipe_handler = (void (*)())tmp___0;
      written =
          full_write(to_remote[handle][1], (void const *)buffer___2, length);
      signal(13, (void (*)(int))pipe_handler);
    }
    if (written == length) {
      {
        tmp___1 = get_status(handle);
        r = tmp___1;
      }
      if (r < 0L) {
        return ((size_t)0);
      }

      written = (size_t)r;
    }
    { _rmt_shutdown(handle, 5); }
    return (written);
  }
}
off_t rmt_lseek__(int handle, off_t offset, int whence) {
  char command_buffer[64];
  char operand_buffer[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                      1UL];
  uintmax_t u;
  char *p;
  int tmp;
  off_t tmp___0;
  void *__cil_tmp10;
  void *__cil_tmp11;
  char *__cil_tmp12;

  {
    if (offset < 0L) {
      u = -((uintmax_t)offset);
    } else {
      u = (uintmax_t)offset;
    }
    p = operand_buffer + sizeof(operand_buffer);
    p--;
    *p = (char)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        p--;
        *p = (char)(48 + (int)(u % 10UL));
        u /= 10UL;
        if (!(u != 0UL)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if (offset < 0L) {
      p--;
      *p = (char)'-';
    }
    {

      goto switch_default;
    case_0: /* CIL Label */
      whence = 0;
      goto switch_break;
    case_1: /* CIL Label */
      whence = 1;
      goto switch_break;
    case_2: /* CIL Label */
      whence = 2;
      goto switch_break;
    switch_default: { /* CIL Label */
      abort();
    }
    switch_break: /* CIL Label */
        ;
    }
    {
      sprintf((char * /* __restrict  */)(command_buffer),
              (char const * /* __restrict  */) "L%s\n%d\n", p, whence);
      tmp = do_command(handle, (char const *)(command_buffer));
    }
    if (tmp == -1) {
      return ((off_t)-1);
    }
    { tmp___0 = get_status_off(handle); }
    return (tmp___0);
  }
}
int rmt_ioctl__(int handle, int operation, char *argument) {
  int *tmp;
  char command_buffer[64];
  char operand_buffer[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                      1UL];
  uintmax_t u;
  char *p;
  int tmp___0;
  long tmp___1;
  ssize_t status;
  size_t counter;
  int tmp___2;
  char copy;
  void *__cil_tmp15;
  void *__cil_tmp16;
  char *__cil_tmp17;
  char *__cil_tmp18;

  {
    {
      if (operation ==
          (int)((unsigned long)(((1U << 30) | (unsigned int)(109 << 8)) | 1U) |
                (sizeof(struct mtop) << 16))) {
        goto case_exp;
      }
      if (operation ==
          (int)((unsigned long)(((2U << 30) | (unsigned int)(109 << 8)) | 2U) |
                (sizeof(struct mtget) << 16))) {
        goto case_exp___0;
      }
      goto switch_default;
    switch_default: { /* CIL Label */
      tmp = __errno_location();
      *tmp = 95;
    }
      return (-1);
    case_exp: /* CIL Label */
      if (((struct mtop *)argument)->mt_count < 0) {
        u = -((uintmax_t)((struct mtop *)argument)->mt_count);
      } else {
        u = (uintmax_t)((struct mtop *)argument)->mt_count;
      }
      p = operand_buffer + sizeof(operand_buffer);
      p--;
      *p = (char)0;
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          p--;
          *p = (char)(48 + (int)(u % 10UL));
          u /= 10UL;
          if (!(u != 0UL)) {
            goto while_break;
          }
        }
      while_break: /* CIL Label */
          ;
      }
      if (((struct mtop *)argument)->mt_count < 0) {
        p--;
        *p = (char)'-';
      }
      {
        sprintf((char * /* __restrict  */)(command_buffer),
                (char const * /* __restrict  */) "I%d\n%s\n",
                (int)((struct mtop *)argument)->mt_op, p);
        tmp___0 = do_command(handle, (char const *)(command_buffer));
      }
      if (tmp___0 == -1) {
        return (-1);
      }
      { tmp___1 = get_status(handle); }
      return ((int)tmp___1);
    case_exp___0: { /* CIL Label */
      tmp___2 = do_command(handle, "S");
    }

      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;
          if (!(status > 0L)) {
            goto while_break___0;
          }
          {
            counter = safe_read(from_remote[handle][0], (void *)argument,
                                (size_t)status);
          }
          if (counter == 0xffffffffffffffffUL) {
            {
              _rmt_shutdown(handle, 5);
            }
            return (-1);
          } else {
            if (counter == 0UL) {
              {
                _rmt_shutdown(handle, 5);
              }
              return (-1);
            }
          }
          status = (ssize_t)((size_t)status - counter);
          argument += counter;
        }
      while_break___0: /* CIL Label */
          ;
      }
      if (((struct mtget *)argument)->mt_type < 256L) {
        return (0);
      }
      counter = (size_t)0;
      {
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          if (!(counter < (size_t)status)) {
            goto while_break___1;
          }
          copy = *(argument + counter);
          *(argument + counter) = *(argument + (counter + 1UL));
          *(argument + (counter + 1UL)) = copy;
          counter += 2UL;
        }
      while_break___1: /* CIL Label */
          ;
      }
      return (0);
    switch_break: /* CIL Label */
        ;
    }
  }
}
/* #pragma merger("0","00c.sparse.o.i","") */
static _Bool tar_sparse_member_p(struct tar_sparse_file *file) {
  _Bool tmp;

  { return ((_Bool)0); }
}
static _Bool tar_sparse_init(struct tar_sparse_file *file) {
  _Bool tmp;

  {
    file->dumped_size = (size_t)0;
    if ((file->optab)->init) {
      {
        tmp = (*((file->optab)->init))(file);
      }
      return (tmp);
    }
    return ((_Bool)1);
  }
}
static _Bool tar_sparse_done(struct tar_sparse_file *file) {
  _Bool tmp;

  {
    if ((file->optab)->done) {
      {
        tmp = (*((file->optab)->done))(file);
      }
      return (tmp);
    }
    return ((_Bool)1);
  }
}
static _Bool tar_sparse_scan(struct tar_sparse_file *file,
                             enum sparse_scan_state state, void *block) {
  _Bool tmp;

  {
    if ((file->optab)->scan_block) {
      {
        tmp = (*((file->optab)->scan_block))(file, state, block);
      }
      return (tmp);
    }
    return ((_Bool)1);
  }
}
static _Bool tar_sparse_dump_region(struct tar_sparse_file *file, size_t i) {
  _Bool tmp;

  {
    if ((file->optab)->dump_region) {
      {
        tmp = (*((file->optab)->dump_region))(file, i);
      }
      return (tmp);
    }
    return ((_Bool)0);
  }
}
static _Bool tar_sparse_extract_region(struct tar_sparse_file *file, size_t i) {
  _Bool tmp;

  {
    if ((file->optab)->extract_region) {
      {
        tmp = (*((file->optab)->extract_region))(file, i);
      }
      return (tmp);
    }
    return ((_Bool)0);
  }
}
static _Bool tar_sparse_dump_header(struct tar_sparse_file *file) {
  _Bool tmp;

  {
    if ((file->optab)->dump_header) {
      {
        tmp = (*((file->optab)->dump_header))(file);
      }
      return (tmp);
    }
    return ((_Bool)0);
  }
}
static _Bool tar_sparse_decode_header(struct tar_sparse_file *file) {
  _Bool tmp;

  { return ((_Bool)1); }
}
static _Bool tar_sparse_fixup_header(struct tar_sparse_file *file) {
  _Bool tmp;

  { return ((_Bool)1); }
}
static _Bool lseek_or_error(struct tar_sparse_file *file, off_t offset,
                            int whence) {
  __off_t tmp;

  {
    { tmp = lseek(file->fd, offset, whence); }
    if (tmp < 0L) {
      {
        seek_diag_details((char const *)(file->stat_info)->orig_file_name,
                          offset);
      }
      return ((_Bool)0);
    }
    return ((_Bool)1);
  }
}
static _Bool zero_block_p(char *buffer___2, size_t size) {
  char *tmp;
  size_t tmp___0;

  {
    {

    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
static void sparse_add_map(struct tar_sparse_file *file, struct sp_array *sp) {
  void *tmp;
  void *tmp___0;
  size_t tmp___1;

  {
    if ((unsigned long)(file->stat_info)->sparse_map ==
        (unsigned long)((void *)0)) {
      {
        tmp = xmalloc(21UL * sizeof(*((file->stat_info)->sparse_map + 0)));
        (file->stat_info)->sparse_map = (struct sp_array *)tmp;
        (file->stat_info)->sparse_map_size = (size_t)21;
      }
    } else {
    }
    tmp___1 = (file->stat_info)->sparse_map_avail;
    ((file->stat_info)->sparse_map_avail)++;
    *((file->stat_info)->sparse_map + tmp___1) = *sp;
    return;
  }
}
static char buffer___1[512];
static _Bool sparse_scan_file(struct tar_sparse_file *file) {
  size_t count;
  size_t offset;
  struct sp_array sp;
  _Bool tmp;
  _Bool tmp___0;
  _Bool tmp___1;
  _Bool tmp___2;
  _Bool tmp___3;
  _Bool tmp___4;

  {
    {
      offset = (size_t)0;
      sp.offset = (off_t)0;
      sp.numbytes = (size_t)0;
      tmp = lseek_or_error(file, (off_t)0, 0);
    }
    if (!tmp) {
      return ((_Bool)0);
    }
    {
      memset((void *)(buffer___1), 0, (size_t)512);
      (file->stat_info)->sparse_map_size = (size_t)0;
      (file->stat_info)->archive_file_size = (off_t)0;
      tmp___0 = tar_sparse_scan(file, (enum sparse_scan_state)0, (void *)0);
    }
    if (!tmp___0) {
      return ((_Bool)0);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          count = safe_read(file->fd, (void *)(buffer___1), sizeof(buffer___1));
        }
        if (count != 0UL) {
          if (!(count != 0xffffffffffffffffUL)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        { tmp___3 = zero_block_p(buffer___1, count); }
        if (tmp___3) {
          if (sp.numbytes) {
            {
              sparse_add_map(file, &sp);
              sp.numbytes = (size_t)0;
              tmp___1 =
                  tar_sparse_scan(file, (enum sparse_scan_state)1, (void *)0);
            }
            if (!tmp___1) {
              return ((_Bool)0);
            }
          }
        } else {
          if (sp.numbytes == 0UL) {
            sp.offset = (off_t)offset;
          }
          {
            sp.numbytes += count;
            (file->stat_info)->archive_file_size =
                (off_t)((size_t)(file->stat_info)->archive_file_size + count);
            tmp___2 = tar_sparse_scan(file, (enum sparse_scan_state)1,
                                      (void *)(buffer___1));
          }
          if (!tmp___2) {
            return ((_Bool)0);
          }
        }
        {
          offset += count;
          memset((void *)(buffer___1), 0, (size_t)512);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if (sp.numbytes == 0UL) {
      sp.offset = (off_t)offset;
    }
    {
      sparse_add_map(file, &sp);
      (file->stat_info)->archive_file_size =
          (off_t)((size_t)(file->stat_info)->archive_file_size + count);
      tmp___4 = tar_sparse_scan(file, (enum sparse_scan_state)2, (void *)0);
    }
    return (tmp___4);
  }
}
static struct tar_sparse_optab oldgnu_optab;
static struct tar_sparse_optab star_optab;
static struct tar_sparse_optab pax_optab;
static _Bool sparse_select_optab(struct tar_sparse_file *file) {
  unsigned int tmp;

  {
    if ((unsigned int)current_format == 0U) {
      tmp = (unsigned int)archive_format;
    } else {
      tmp = (unsigned int)current_format;
    }
    {

      if (tmp == 3U) {
        goto case_1;
      }

      if (tmp == 4U) {
        goto case_4;
      }
      if (tmp == 5U) {
        goto case_5;
      }
      goto switch_default;
    case_1: /* CIL Label */
    case_3: /* CIL Label */
      return ((_Bool)0);
    case_2: /* CIL Label */
    case_6: /* CIL Label */
      file->optab = &oldgnu_optab;
      goto switch_break;
    case_4: /* CIL Label */
      file->optab = &pax_optab;
      goto switch_break;
    case_5: /* CIL Label */
      file->optab = &star_optab;
      goto switch_break;
    switch_default: /* CIL Label */
      return ((_Bool)0);
    switch_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
static _Bool sparse_dump_region(struct tar_sparse_file *file, size_t i) {
  union block *blk;
  off_t bytes_left;
  _Bool tmp;
  size_t bufsize;
  size_t bytes_read;
  off_t tmp___0;

  {
    {
      bytes_left = (off_t)((file->stat_info)->sparse_map + i)->numbytes;
      tmp =
          lseek_or_error(file, ((file->stat_info)->sparse_map + i)->offset, 0);
    }
    if (!tmp) {
      return ((_Bool)0);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(bytes_left > 0L)) {
          goto while_break;
        }
        if (bytes_left > 512L) {
          tmp___0 = (off_t)512;
        } else {
          tmp___0 = bytes_left;
        }
        {
          bufsize = (size_t)tmp___0;
          blk = find_next_block();
          memset((void *)(blk->buffer), 0, (size_t)512);
          bytes_read = safe_read(file->fd, (void *)(blk->buffer), bufsize);
        }
        if (bytes_read == 0xffffffffffffffffUL) {
          {
            read_diag_details(
                (char const *)(file->stat_info)->orig_file_name,
                (off_t)(((size_t)((file->stat_info)->sparse_map + i)->offset +
                         ((file->stat_info)->sparse_map + i)->numbytes) -
                        (size_t)bytes_left),
                bufsize);
          }
          return ((_Bool)0);
        }
        {
          bytes_left = (off_t)((size_t)bytes_left - bytes_read);
          file->dumped_size += bytes_read;
          set_next_block_after(blk);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
static _Bool sparse_extract_region(struct tar_sparse_file *file, size_t i) {
  size_t write_size;
  _Bool tmp;
  int tmp___0;
  size_t count;
  size_t wrbytes;
  union block *blk;
  union block *tmp___1;
  char *tmp___2;
  char *__cil_tmp11;

  {
    {
      tmp =
          lseek_or_error(file, ((file->stat_info)->sparse_map + i)->offset, 0);
    }
    if (!tmp) {
      return ((_Bool)0);
    }
    write_size = ((file->stat_info)->sparse_map + i)->numbytes;
    if (write_size == 0UL) {
      {
        tmp___0 = sys_truncate(file->fd);
      }
      if (tmp___0) {
        {
          truncate_warn((char const *)(file->stat_info)->orig_file_name);
        }
      }
    } else {
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if (!(write_size > 0UL)) {
            goto while_break;
          }
          if (write_size > 512UL) {
            wrbytes = (size_t)512;
          } else {
            wrbytes = write_size;
          }
          {
            tmp___1 = find_next_block();
            blk = tmp___1;
          }
          if (!blk) {
            {
              tmp___2 = gettext("Unexpected EOF in archive");
              error(0, 0, (char const *)tmp___2);
              exit_status = 2;
            }
            return ((_Bool)0);
          }
          {
            set_next_block_after(blk);
            count = full_write(file->fd, (void const *)(blk->buffer), wrbytes);
            write_size -= count;
            file->dumped_size += count;
          }
          if (count != wrbytes) {
            {
              write_error_details(
                  (char const *)(file->stat_info)->orig_file_name, count,
                  wrbytes);
            }
            return ((_Bool)0);
          }
        }
      while_break: /* CIL Label */
          ;
      }
    }
    return ((_Bool)1);
  }
}
enum dump_status sparse_dump_file(int fd, struct tar_stat_info *st) {
  _Bool rc___1;
  struct tar_sparse_file file;
  _Bool tmp;
  _Bool tmp___0;
  size_t i;
  _Bool tmp___1;
  int tmp___2;

  {
    {
      file.stat_info = st;
      file.fd = fd;
      tmp = sparse_select_optab(&file);
    }
    if (tmp) {
      {
        tmp___0 = tar_sparse_init(&file);
      }
      if (!tmp___0) {
        return ((enum dump_status)3);
      }
    } else {
      return ((enum dump_status)3);
    }
    { rc___1 = sparse_scan_file(&file); }
    if (rc___1) {
      if ((file.optab)->dump_region) {
        {
          tar_sparse_dump_header(&file);
        }
        if (fd >= 0) {
          i = (size_t)0;
          {
            while (1) {
            while_continue: /* CIL Label */
                ;
              if (rc___1) {
                if (!(i < (file.stat_info)->sparse_map_avail)) {
                  goto while_break;
                }
              } else {
                goto while_break;
              }
              {
                rc___1 = tar_sparse_dump_region(&file, i);
                i++;
              }
            }
          while_break: /* CIL Label */
              ;
          }
        }
      }
    }
    {
      pad_archive((off_t)((size_t)(file.stat_info)->archive_file_size -
                          file.dumped_size));
      tmp___1 = tar_sparse_done(&file);
    }
    if (tmp___1) {
      if (rc___1) {
        tmp___2 = 0;
      } else {
        tmp___2 = 1;
      }
    } else {
      tmp___2 = 1;
    }
    return ((enum dump_status)tmp___2);
  }
}
_Bool sparse_file_p(struct tar_stat_info *st) {

  {
    return ((_Bool)(st->stat.st_blocks <
                    st->stat.st_size / 512L +
                        (__off_t)(st->stat.st_size % 512L != 0L)));
  }
}
_Bool sparse_member_p(struct tar_stat_info *st) {
  struct tar_sparse_file file;
  _Bool tmp;
  _Bool tmp___0;

  {
    { tmp = sparse_select_optab(&file); }
    if (!tmp) {
      return ((_Bool)0);
    }
    {
      file.stat_info = st;
      tmp___0 = tar_sparse_member_p(&file);
    }
    return (tmp___0);
  }
}
_Bool sparse_fixup_header(struct tar_stat_info *st) {
  struct tar_sparse_file file;
  _Bool tmp;
  _Bool tmp___0;

  {
    { tmp = sparse_select_optab(&file); }
    if (!tmp) {
      return ((_Bool)0);
    }
    {
      file.stat_info = st;
      tmp___0 = tar_sparse_fixup_header(&file);
    }
    return (tmp___0);
  }
}
enum dump_status sparse_extract_file(int fd, struct tar_stat_info *st,
                                     off_t *size) {
  _Bool rc___1;
  struct tar_sparse_file file;
  size_t i;
  _Bool tmp;
  _Bool tmp___0;
  _Bool tmp___1;
  int tmp___2;

  {
    {
      rc___1 = (_Bool)1;
      file.stat_info = st;
      file.fd = fd;
      tmp = sparse_select_optab(&file);
    }
    if (tmp) {
      {
        tmp___0 = tar_sparse_init(&file);
      }
      if (!tmp___0) {
        return ((enum dump_status)3);
      }
    } else {
      return ((enum dump_status)3);
    }
    {
      rc___1 = tar_sparse_decode_header(&file);
      i = (size_t)0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (rc___1) {
          if (!(i < (file.stat_info)->sparse_map_avail)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        {
          rc___1 = tar_sparse_extract_region(&file, i);
          i++;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      *size = (off_t)((size_t)(file.stat_info)->archive_file_size -
                      file.dumped_size);
      tmp___1 = tar_sparse_done(&file);
    }
    if (tmp___1) {
      if (rc___1) {
        tmp___2 = 0;
      } else {
        tmp___2 = 1;
      }
    } else {
      tmp___2 = 1;
    }
    return ((enum dump_status)tmp___2);
  }
}
enum dump_status sparse_skip_file(struct tar_stat_info *st) {
  _Bool rc___1;
  struct tar_sparse_file file;
  _Bool tmp;
  _Bool tmp___0;
  _Bool tmp___1;
  int tmp___2;

  {
    {
      rc___1 = (_Bool)1;
      file.stat_info = st;
      file.fd = -1;
      tmp = sparse_select_optab(&file);
    }
    if (tmp) {
      {
        tmp___0 = tar_sparse_init(&file);
      }
      if (!tmp___0) {
        return ((enum dump_status)3);
      }
    } else {
      return ((enum dump_status)3);
    }
    {
      rc___1 = tar_sparse_decode_header(&file);
      skip_file((file.stat_info)->archive_file_size);
      tmp___1 = tar_sparse_done(&file);
    }
    if (tmp___1) {
      if (rc___1) {
        tmp___2 = 0;
      } else {
        tmp___2 = 1;
      }
    } else {
      tmp___2 = 1;
    }
    return ((enum dump_status)tmp___2);
  }
}
static char diff_buffer___0[512];
static _Bool check_sparse_region(struct tar_sparse_file *file, off_t beg,
                                 off_t end) {
  _Bool tmp;
  size_t bytes_read;
  size_t rdsize;
  char *tmp___0;
  _Bool tmp___1;
  char *__cil_tmp9;

  {
    { tmp = lseek_or_error(file, beg, 0); }
    if (!tmp) {
      return ((_Bool)0);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(beg < end)) {
          goto while_break;
        }
        rdsize = (size_t)(end - beg);
        if (rdsize > 512UL) {
          rdsize = (size_t)512;
        }
        {
          memset((void *)(diff_buffer___0), 0, (size_t)512);
          bytes_read = safe_read(file->fd, (void *)(diff_buffer___0), rdsize);
        }
        if (bytes_read == 0xffffffffffffffffUL) {
          {
            read_diag_details((char const *)(file->stat_info)->orig_file_name,
                              beg, rdsize);
          }
          return ((_Bool)0);
        }
        { tmp___1 = zero_block_p(diff_buffer___0, bytes_read); }
        if (!tmp___1) {
          {
            tmp___0 = gettext("File fragment at %lu is not a hole");
            report_difference(file->stat_info, (char const *)tmp___0, beg);
          }
          return ((_Bool)0);
        }
        beg = (off_t)((size_t)beg + bytes_read);
      }
    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
static _Bool check_data_region(struct tar_sparse_file *file, size_t i) {
  size_t size_left;
  _Bool tmp;
  size_t bytes_read;
  size_t rdsize;
  union block *blk;
  union block *tmp___0;
  char *tmp___1;
  char *tmp___2;
  int tmp___3;
  char *__cil_tmp12;
  char *__cil_tmp13;

  {
    {
      tmp =
          lseek_or_error(file, ((file->stat_info)->sparse_map + i)->offset, 0);
    }
    if (!tmp) {
      return ((_Bool)0);
    }
    size_left = ((file->stat_info)->sparse_map + i)->numbytes;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(size_left > 0UL)) {
          goto while_break;
        }
        if (size_left > 512UL) {
          rdsize = (size_t)512;
        } else {
          rdsize = size_left;
        }
        {
          tmp___0 = find_next_block();
          blk = tmp___0;
        }

        {
          set_next_block_after(blk);
          bytes_read = safe_read(file->fd, (void *)(diff_buffer___0), rdsize);
        }
        if (bytes_read == 0xffffffffffffffffUL) {
          {
            read_diag_details(
                (char const *)(file->stat_info)->orig_file_name,
                (off_t)(((size_t)((file->stat_info)->sparse_map + i)->offset +
                         ((file->stat_info)->sparse_map + i)->numbytes) -
                        size_left),
                rdsize);
          }
          return ((_Bool)0);
        }
        {
          file->dumped_size += bytes_read;
          size_left -= bytes_read;
          tmp___3 = memcmp((void const *)(blk->buffer),
                           (void const *)(diff_buffer___0), rdsize);
        }
        if (tmp___3) {
          {
            tmp___2 = gettext("Contents differ");
            report_difference(file->stat_info, (char const *)tmp___2);
          }
          return ((_Bool)0);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
_Bool sparse_diff_file(int fd, struct tar_stat_info *st) {
  _Bool rc___1;
  struct tar_sparse_file file;
  size_t i;
  off_t offset;
  _Bool tmp;
  _Bool tmp___0;
  _Bool tmp___1;
  _Bool tmp___2;
  int tmp___3;

  {
    {
      rc___1 = (_Bool)1;
      offset = (off_t)0;
      file.stat_info = st;
      file.fd = fd;
      tmp = sparse_select_optab(&file);
    }
    if (tmp) {
      {
        tmp___0 = tar_sparse_init(&file);
      }
      if (!tmp___0) {
        return ((_Bool)1);
      }
    } else {
      return ((_Bool)1);
    }
    {
      rc___1 = tar_sparse_decode_header(&file);
      i = (size_t)0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (rc___1) {
          if (!(i < (file.stat_info)->sparse_map_avail)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        {
          tmp___1 = check_sparse_region(
              &file, offset, ((file.stat_info)->sparse_map + i)->offset);
        }
        if (tmp___1) {
          {
            tmp___2 = check_data_region(&file, i);
          }
          if (tmp___2) {
            tmp___3 = 1;
          } else {
            tmp___3 = 0;
          }
        } else {
          tmp___3 = 0;
        }
        rc___1 = (_Bool)tmp___3;
        offset = (off_t)((size_t)((file.stat_info)->sparse_map + i)->offset +
                         ((file.stat_info)->sparse_map + i)->numbytes);
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
    if (!rc___1) {
      {
        skip_file((off_t)((size_t)(file.stat_info)->archive_file_size -
                          file.dumped_size));
      }
    }
    { tar_sparse_done(&file); }
    return (rc___1);
  }
}
static _Bool oldgnu_sparse_member_p(struct tar_sparse_file *file
                                    __attribute__((__unused__))) {

  { return ((_Bool)((int)current_header->header.typeflag == 83)); }
}
static enum oldgnu_add_status oldgnu_add_sparse(struct tar_sparse_file *file,
                                                struct sparse *s) {
  struct sp_array sp;

  {
    if ((int)s->numbytes[0] == 0) {
      return ((enum oldgnu_add_status)1);
    }
    {
      sp.offset = off_from_header((char const *)(s->offset), sizeof(s->offset));
      sp.numbytes =
          size_from_header((char const *)(s->numbytes), sizeof(s->numbytes));
    }
    if (sp.offset < 0L) {
      return ((enum oldgnu_add_status)2);
    } else {
      if ((size_t)(file->stat_info)->stat.st_size <
          (size_t)sp.offset + sp.numbytes) {
        return ((enum oldgnu_add_status)2);
      } else {
      }
    }
    { sparse_add_map(file, &sp); }
    return ((enum oldgnu_add_status)0);
  }
}
static _Bool oldgnu_fixup_header(struct tar_sparse_file *file) {

  {
    {
      (file->stat_info)->archive_file_size = (file->stat_info)->stat.st_size;
      (file->stat_info)->stat.st_size = off_from_header(
          (char const *)(current_header->oldgnu_header.realsize),
          sizeof(current_header->oldgnu_header.realsize));
    }
    return ((_Bool)1);
  }
}
static enum oldgnu_add_status rc;
static _Bool oldgnu_get_sparse_info(struct tar_sparse_file *file) {
  size_t i;
  union block *h;
  int ext_p;
  char *tmp;
  char *tmp___0;
  char *__cil_tmp7;
  char *__cil_tmp8;

  {
    h = current_header;
    (file->stat_info)->sparse_map_size = (size_t)0;
    i = (size_t)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(i < 4UL)) {
          goto while_break;
        }
        { rc = oldgnu_add_sparse(file, &h->oldgnu_header.sp[i]); }
        if ((unsigned int)rc != 0U) {
          goto while_break;
        }
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
    ext_p = (int)h->oldgnu_header.isextended;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;

        { h = find_next_block(); }
        if (!h) {
          {
            tmp = gettext("Unexpected EOF in archive");
            error(0, 0, (char const *)tmp);
            exit_status = 2;
          }
          return ((_Bool)0);
        }
        {
          set_next_block_after(h);
          i = (size_t)0;
        }
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;

            {
              rc = oldgnu_add_sparse(file, &h->sparse_header.sp[i]);
              i++;
            }
          }
        while_break___1: /* CIL Label */
            ;
        }
        ext_p = (int)h->sparse_header.isextended;
      }
    while_break___0: /* CIL Label */
        ;
    }
    if ((unsigned int)rc == 2U) {
      {
        tmp___0 = gettext("%s: invalid sparse archive member");
        error(0, 0, (char const *)tmp___0, (file->stat_info)->orig_file_name);
        exit_status = 2;
      }
      return ((_Bool)0);
    }
    return ((_Bool)1);
  }
}
static void oldgnu_store_sparse_info(struct tar_sparse_file *file,
                                     size_t *pindex, struct sparse *sp,
                                     size_t sparse_size) {

  {
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (*pindex < (file->stat_info)->sparse_map_avail) {
          if (!(sparse_size > 0UL)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        {
          off_to_chars(((file->stat_info)->sparse_map + *pindex)->offset,
                       sp->offset, sizeof(sp->offset));
          size_to_chars(((file->stat_info)->sparse_map + *pindex)->numbytes,
                        sp->numbytes, sizeof(sp->numbytes));
          sparse_size--;
          sp++;
          (*pindex)++;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static _Bool oldgnu_dump_header(struct tar_sparse_file *file) {
  off_t block_ordinal;
  off_t tmp;
  union block *blk;
  size_t i;

  {
    {
      tmp = current_block_ordinal();
      block_ordinal = tmp;
      blk = start_header(file->stat_info);
      blk->header.typeflag = (char)'S';
    }
    if ((file->stat_info)->sparse_map_avail > 4UL) {
      blk->oldgnu_header.isextended = (char)1;
    }
    {
      off_to_chars((file->stat_info)->stat.st_size, blk->oldgnu_header.realsize,
                   sizeof(blk->oldgnu_header.realsize));
      off_to_chars((file->stat_info)->archive_file_size, blk->header.size,
                   sizeof(blk->header.size));
      i = (size_t)0;
      oldgnu_store_sparse_info(file, &i, blk->oldgnu_header.sp, (size_t)4);
      blk->oldgnu_header.isextended =
          (char)(i < (file->stat_info)->sparse_map_avail);
      finish_header(file->stat_info, blk, block_ordinal);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(i < (file->stat_info)->sparse_map_avail)) {
          goto while_break;
        }
        {
          blk = find_next_block();
          memset((void *)(blk->buffer), 0, (size_t)512);
          oldgnu_store_sparse_info(file, &i, blk->sparse_header.sp, (size_t)21);
          set_next_block_after(blk);
        }
        if (i < (file->stat_info)->sparse_map_avail) {
          blk->sparse_header.isextended = (char)1;
        } else {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
static struct tar_sparse_optab oldgnu_optab = {
    (_Bool(*)(struct tar_sparse_file *))((void *)0),
    (_Bool(*)(struct tar_sparse_file *))((void *)0),
    &oldgnu_sparse_member_p,
    &oldgnu_dump_header,
    &oldgnu_fixup_header,
    &oldgnu_get_sparse_info,
    (_Bool(*)(struct tar_sparse_file *, enum sparse_scan_state, void *))(
        (void *)0),
    &sparse_dump_region,
    &sparse_extract_region};

static enum oldgnu_add_status rc___0;

static _Bool pax_sparse_member_p(struct tar_sparse_file *file) {

  {
    return ((_Bool)((file->stat_info)->archive_file_size !=
                    (file->stat_info)->stat.st_size));
  }
}
static _Bool pax_dump_header(struct tar_sparse_file *file) {
  off_t block_ordinal;
  off_t tmp;
  union block *blk;
  size_t i;
  char *__cil_tmp6;
  char *__cil_tmp7;
  char *__cil_tmp8;
  char *__cil_tmp9;

  {
    {
      tmp = current_block_ordinal();
      block_ordinal = tmp;
      xheader_store("GNU.sparse.size",
                    (struct tar_stat_info const *)file->stat_info, (void *)0);
      xheader_store("GNU.sparse.numblocks",
                    (struct tar_stat_info const *)file->stat_info, (void *)0);
      i = (size_t)0;
    }
    {

    while_break: /* CIL Label */
        ;
    }
    {
      blk = start_header(file->stat_info);
      off_to_chars((file->stat_info)->archive_file_size, blk->header.size,
                   sizeof(blk->header.size));
      finish_header(file->stat_info, blk, block_ordinal);
    }
    return ((_Bool)1);
  }
}
static struct tar_sparse_optab pax_optab = {
    (_Bool(*)(struct tar_sparse_file *))((void *)0),
    (_Bool(*)(struct tar_sparse_file *))((void *)0),
    &pax_sparse_member_p,
    &pax_dump_header,
    (_Bool(*)(struct tar_sparse_file *))((void *)0),
    (_Bool(*)(struct tar_sparse_file *))((void *)0),
    (_Bool(*)(struct tar_sparse_file *, enum sparse_scan_state, void *))(
        (void *)0),
    &sparse_dump_region,
    &sparse_extract_region};
/* #pragma merger("0","00d.system.o.i","") */
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) execlp)(char const *__file, char const *__arg,
                                          ...);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) setuid)(
    __uid_t __uid);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) setgid)(
    __gid_t __gid);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ftruncate)(
    int __fd, __off_t __length);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) kill)(
    __pid_t __pid, int __sig);
extern __pid_t waitpid(__pid_t __pid, int *__stat_loc, int __options);
extern __attribute__((__nothrow__, __noreturn__)) void(
    __attribute__((__leaf__)) exit)(int __status);
dev_t ar_dev;
ino_t ar_ino;
void sys_stat_nanoseconds(struct tar_stat_info *st) {

  {
    st->atime_nsec = (unsigned long)st->stat.st_atim.tv_nsec;
    st->mtime_nsec = (unsigned long)st->stat.st_mtim.tv_nsec;
    st->ctime_nsec = (unsigned long)st->stat.st_ctim.tv_nsec;
    return;
  }
}
static struct stat archive_stat;
_Bool sys_get_archive_stat(void) {
  int tmp;

  {
    { tmp = fstat(archive, &archive_stat); }
    return ((_Bool)(tmp == 0));
  }
}
_Bool sys_file_is_archive(struct tar_stat_info *p) {
  int tmp;

  { return ((_Bool)tmp); }
}
void sys_save_archive_dev_ino(void) {

  {
    if (!(archive >= 1 << 30)) {
      if ((archive_stat.st_mode & 61440U) == 32768U) {
        ar_dev = archive_stat.st_dev;
        ar_ino = archive_stat.st_ino;
      } else {
        ar_dev = (dev_t)0;
      }
    } else {
      ar_dev = (dev_t)0;
    }
    return;
  }
}
static char const dev_null[10] = {
    (char const)'/', (char const)'d',   (char const)'e', (char const)'v',
    (char const)'/', (char const)'n',   (char const)'u', (char const)'l',
    (char const)'l', (char const)'\000'};
void sys_detect_dev_null_output(void) {
  struct stat dev_null_stat;
  int tmp;
  int tmp___0;
  int tmp___1;
  void *__cil_tmp5;

  {
    { tmp = strcmp(*(archive_name_array + 0), dev_null); }

    dev_null_output = (_Bool)tmp___1;
    return;
  }
}
void sys_drain_input_pipe(void) {
  size_t r;
  size_t tmp;
  size_t tmp___0;

  {
    if ((unsigned int)access_mode == 0U) {
      if (!(archive >= 1 << 30)) {
        if ((archive_stat.st_mode & 61440U) == 4096U) {
          goto _L___3;
        } else {
          if ((archive_stat.st_mode & 61440U) == 49152U) {
          _L___3: { /* CIL Label */
            while (1) {
            while_continue: /* CIL Label */
                ;
              if (archive >= 1 << 30) {
                {
                  tmp = rmt_read__(archive - (1 << 30), record_start->buffer,
                                   record_size);
                  r = tmp;
                }
              } else {
                {
                  tmp___0 = safe_read(archive, (void *)(record_start->buffer),
                                      record_size);
                  r = tmp___0;
                }
              }

              goto while_continue;
            }
          while_break: /* CIL Label */
              ;
          }
          }
        }
      }
    }
    return;
  }
}
void sys_wait_for_child(pid_t child_pid___0) {
  int wait_status;
  int *tmp;
  __pid_t tmp___0;
  union __anonunion_56 __constr_expr_0;
  char *tmp___1;
  union __anonunion_57 __constr_expr_1;
  char *tmp___2;
  union __anonunion_58 __constr_expr_2;
  union __anonunion_59 __constr_expr_3;
  char *__cil_tmp11;
  char *__cil_tmp12;

  {
    if (child_pid___0) {
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          { tmp___0 = waitpid(child_pid___0, &wait_status, 0); }
          if (!(tmp___0 == -1)) {
            goto while_break;
          }
          { tmp = __errno_location(); }
        }
      while_break: /* CIL Label */
          ;
      }
      __constr_expr_3.__in = wait_status;
      if ((int)((signed char)((__constr_expr_3.__i & 127) + 1)) >> 1 > 0) {
        {
          __constr_expr_0.__in = wait_status;
          tmp___1 = gettext("Child died with signal %d");
          error(0, 0, (char const *)tmp___1, __constr_expr_0.__i & 127);
          exit_status = 2;
        }
      } else {
        __constr_expr_2.__in = wait_status;
        if ((__constr_expr_2.__i & 65280) >> 8 != 0) {
          {
            __constr_expr_1.__in = wait_status;
            tmp___2 = gettext("Child returned status %d");
            error(0, 0, (char const *)tmp___2,
                  (__constr_expr_1.__i & 65280) >> 8);
            exit_status = 2;
          }
        }
      }
    }
    return;
  }
}
void sys_spawn_shell(void) {
  pid_t child;
  char const *shell;
  char *tmp;
  int wait_status;
  int *tmp___0;
  __pid_t tmp___1;
  char *__cil_tmp7;
  char *__cil_tmp8;

  {
    {
      tmp = getenv("SHELL");
      shell = (char const *)tmp;
    }

    { child = xfork(); }

    return;
  }
}
_Bool sys_compare_uid(struct stat *a, struct stat *b) {

  { return ((_Bool)(a->st_uid == b->st_uid)); }
}
_Bool sys_compare_gid(struct stat *a, struct stat *b) {

  { return ((_Bool)(a->st_gid == b->st_gid)); }
}
_Bool sys_compare_links(struct stat *link_data, struct stat *stat_data) {
  int tmp;

  { return ((_Bool)tmp); }
}
int sys_truncate(int fd) {
  off_t pos;
  __off_t tmp;
  int tmp___0;
  int tmp___1;

  {
    {
      tmp = lseek(fd, (off_t)0, 1);
      pos = tmp;
    }

    return (tmp___1);
  }
}
void sys_reset_uid_gid(void) {
  __uid_t tmp;
  __gid_t tmp___0;

  {
    {
      tmp = getuid();
      setuid(tmp);
      tmp___0 = getgid();
      setgid(tmp___0);
    }
    return;
  }
}
static int is_regular_file(char const *name) {
  struct stat stbuf;
  int *tmp;
  int tmp___0;
  void *__cil_tmp5;

  {
    {
      tmp___0 = stat((char const * /* __restrict  */)name,
                     (struct stat * /* __restrict  */)(&stbuf));
    }
    if (tmp___0 == 0) {
      return ((stbuf.st_mode & 61440U) == 32768U);
    } else {
      { tmp = __errno_location(); }
      return (*tmp == 2);
    }
  }
}
size_t sys_write_archive_buffer(void) {
  size_t tmp;
  size_t tmp___0;
  size_t tmp___1;

  {
    if (archive >= 1 << 30) {
      {
        tmp =
            rmt_write__(archive - (1 << 30), record_start->buffer, record_size);
        tmp___1 = tmp;
      }
    } else {
      {
        tmp___0 = full_write(archive, (void const *)(record_start->buffer),
                             record_size);
        tmp___1 = tmp___0;
      }
    }
    return (tmp___1);
  }
}
static void xdup2(int from, int into) {
  int status;
  int tmp;
  int e;
  int *tmp___0;
  char *tmp___1;
  int *tmp___2;
  int e___0;
  int *tmp___3;
  char *tmp___4;
  char *__cil_tmp12;
  char *__cil_tmp13;

  {
    if (from != into) {
      {
        tmp = close(into);
        status = tmp;
      }
      if (status != 0) {
        {
          tmp___2 = __errno_location();
        }
      }
      { status = dup(from); }
      if (status != into) {
        if (status < 0) {
          {
            tmp___3 = __errno_location();
            e___0 = *tmp___3;
            tmp___4 = gettext("Cannot dup");
            error(0, e___0, (char const *)tmp___4);
            fatal_exit();
          }
        }
        { abort(); }
      }
      { xclose(from); }
    }
    return;
  }
}
pid_t sys_child_open_for_compress(void) {
  int parent_pipe[2];
  int child_pipe[2];
  pid_t grandchild_pid;
  pid_t child_pid___0;
  int wait_status;
  char *tmp;
  int saved_errno;
  int *tmp___0;
  int *tmp___1;
  int tmp___2;
  void *tmp___3;
  int tmp___4;
  char *tmp___5;
  int tmp___7;
  int tmp___8;
  void *tmp___9;
  int tmp___10;
  size_t status;
  char *cursor;
  size_t length;
  size_t size;
  int *tmp___11;
  __pid_t tmp___12;
  union __anonunion_60 __constr_expr_4;
  union __anonunion_61 __constr_expr_5;
  union __anonunion_62 __constr_expr_6;
  union __anonunion_63 __constr_expr_7;
  void *__cil_tmp28;
  void *__cil_tmp29;
  char *__cil_tmp30;
  char *__cil_tmp31;

  {
    {
      xpipe(parent_pipe);
      child_pid___0 = xfork();
    }
    if (child_pid___0 > 0) {
      {
        archive = parent_pipe[1];
        xclose(parent_pipe[0]);
      }
      return (child_pid___0);
    }
    {
      tmp = gettext("tar (child)");
      program_name = (char const *)tmp;
      xdup2(parent_pipe[0], 0);
      xclose(parent_pipe[1]);
      tmp___2 = strcmp(*(archive_name_array + 0), "-");
    }
    if (tmp___2 != 0) {
      if (!force_local_option) {
        {
          rmt_path__ = strchr(*(archive_name_array + 0), ':');
        }

      } else {
      _L___1: { tmp___4 = is_regular_file(*(archive_name_array + 0)); }
        if (tmp___4) {

          {
            archive = creat(*(archive_name_array + 0),
                            (mode_t)(((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                     ((256 | (256 >> 3)) | ((256 >> 3) >> 3))));
          }
          if (archive < 0) {
            {
              tmp___0 = __errno_location();
              saved_errno = *tmp___0;
            }

            {
              tmp___1 = __errno_location();
              *tmp___1 = saved_errno;
              open_fatal(*(archive_name_array + 0));
            }
          }
          {
            xdup2(archive, 1);
            execlp(use_compress_program_option, use_compress_program_option,
                   (char *)0);
            exec_fatal(use_compress_program_option);
          }
        }
      }
    }
    {
      xpipe(child_pipe);
      grandchild_pid = xfork();
    }

    {
      xdup2(child_pipe[0], 0);
      xclose(child_pipe[1]);
      tmp___10 = strcmp(*(archive_name_array + 0), "-");
    }

    {

    while_break: /* CIL Label */
        ;
    }
    {

    while_break___1: /* CIL Label */
        ;
    }
    __constr_expr_7.__in = wait_status;
    if ((int)((signed char)((__constr_expr_7.__i & 127) + 1)) >> 1 > 0) {
      {
        __constr_expr_4.__in = wait_status;
        kill(child_pid___0, __constr_expr_4.__i & 127);
        exit_status = 2;
      }
    } else {
      __constr_expr_6.__in = wait_status;
      if ((__constr_expr_6.__i & 65280) >> 8 != 0) {
        __constr_expr_5.__in = wait_status;
        exit_status = (__constr_expr_5.__i & 65280) >> 8;
      }
    }
    { exit(exit_status); }
  }
}
pid_t sys_child_open_for_uncompress(void) {
  int parent_pipe[2];
  int child_pipe[2];
  pid_t grandchild_pid;
  pid_t child_pid___0;
  int wait_status;
  char *tmp;
  int tmp___0;
  void *tmp___1;
  int tmp___2;
  char *tmp___3;
  int tmp___5;
  int tmp___6;
  void *tmp___7;
  int tmp___8;
  char *cursor;
  size_t maximum;
  size_t count;
  size_t status;
  size_t tmp___9;
  size_t tmp___10;
  size_t tmp___11;
  int *tmp___12;
  __pid_t tmp___13;
  union __anonunion_64 __constr_expr_8;
  union __anonunion_65 __constr_expr_9;
  union __anonunion_66 __constr_expr_10;
  union __anonunion_67 __constr_expr_11;
  void *__cil_tmp28;
  void *__cil_tmp29;
  char *__cil_tmp30;
  char *__cil_tmp31;

  {
    {
      xpipe(parent_pipe);
      child_pid___0 = xfork();
    }
    if (child_pid___0 > 0) {
      {
        read_full_records_option = (_Bool)1;
        archive = parent_pipe[0];
        xclose(parent_pipe[1]);
      }
      return (child_pid___0);
    }
    {
      tmp = gettext("tar (child)");
      program_name = (char const *)tmp;
      xdup2(parent_pipe[1], 1);
      xclose(parent_pipe[0]);
      tmp___0 = strcmp(*(archive_name_array + 0), "-");
    }
    if (tmp___0 != 0) {
    }
    {
      xpipe(child_pipe);
      grandchild_pid = xfork();
    }

    {
      xdup2(child_pipe[1], 1);
      xclose(child_pipe[0]);
      tmp___8 = strcmp(*(archive_name_array + 0), "-");
    }
    if (tmp___8 == 0) {
      archive = 0;
    } else {
      if (!force_local_option) {
        {
          rmt_path__ = strchr(*(archive_name_array + 0), ':');
        }
        if (rmt_path__) {
          if ((unsigned long)rmt_path__ >
              (unsigned long)*(archive_name_array + 0)) {
            {
              tmp___7 = memchr(
                  (void const *)*(archive_name_array + 0), '/',
                  (size_t)(rmt_path__ - (char *)*(archive_name_array + 0)));
            }
            if (tmp___7) {
              {
                tmp___6 = open(*(archive_name_array + 0), 0,
                               ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                   ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
                archive = tmp___6;
              }
            } else {
              {
                tmp___5 = rmt_open__(*(archive_name_array + 0), 0, 1 << 30,
                                     rsh_command_option);
                archive = tmp___5;
              }
            }
          } else {
            {
              tmp___6 = open(*(archive_name_array + 0), 0,
                             ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                 ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
              archive = tmp___6;
            }
          }
        } else {
          {
            tmp___6 = open(*(archive_name_array + 0), 0,
                           ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                               ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
            archive = tmp___6;
          }
        }
      } else {
        {
          tmp___6 = open(*(archive_name_array + 0), 0,
                         ((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                             ((256 | (256 >> 3)) | ((256 >> 3) >> 3)));
          archive = tmp___6;
        }
      }
    }
    if (archive < 0) {
      {
        open_fatal(*(archive_name_array + 0));
      }
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { clear_read_error_count(); }
      error_loop:
        if (archive >= 1 << 30) {
          {
            tmp___9 = rmt_read__(archive - (1 << 30), record_start->buffer,
                                 record_size);
            status = tmp___9;
          }
        } else {
          {
            tmp___10 =
                safe_read(archive, (void *)(record_start->buffer), record_size);
            status = tmp___10;
          }
        }

        if (status == 0UL) {
          goto while_break;
        }
        cursor = record_start->buffer;
        maximum = status;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            if (!maximum) {
              goto while_break___0;
            }
            if (maximum < 512UL) {
              count = maximum;
            } else {
              count = (size_t)512;
            }
            { tmp___11 = full_write(1, (void const *)cursor, count); }
            if (tmp___11 != count) {
              {
                write_error(use_compress_program_option);
              }
            }
            cursor += count;
            maximum -= count;
          }
        while_break___0: /* CIL Label */
            ;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    { xclose(1); }
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        { tmp___13 = waitpid(grandchild_pid, &wait_status, 0); }
        if (!(tmp___13 == -1)) {
          goto while_break___1;
        }
        { tmp___12 = __errno_location(); }
      }
    while_break___1: /* CIL Label */
        ;
    }
    __constr_expr_11.__in = wait_status;
    if ((int)((signed char)((__constr_expr_11.__i & 127) + 1)) >> 1 > 0) {
      {
        __constr_expr_8.__in = wait_status;
        kill(child_pid___0, __constr_expr_8.__i & 127);
        exit_status = 2;
      }
    } else {
      __constr_expr_10.__in = wait_status;
    }
    { exit(exit_status); }
  }
}
/* #pragma merger("0","00e.tar.o.i","") */
extern char *optarg;
extern int optind;
extern int printf(char const *__restrict __format, ...);
extern int puts(char const *__s);
extern int fputs_unlocked(char const *__restrict __s,
                          FILE *__restrict __stream);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) setlocale)(
    int __category, char const *__locale);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__leaf__)) textdomain)(char const *__domainname);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __leaf__)) bindtextdomain)(char const *__domainname, char const *__dirname);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) getopt_long)(
    int ___argc, char *const *___argv, char const *__shortopts,
    struct option const *__longopts, int *__longind);
char const *simple_backup_suffix;
enum backup_type xget_version(char const *context, char const *version);
struct exclude *new_exclude(void);
void add_exclude(struct exclude *ex, char const *pattern, int options);
int add_exclude_file(void (*add_func)(struct exclude *, char const *, int),
                     struct exclude *ex, char const *filename, int options,
                     char line_end);
struct mode_change *mode_compile(char const *mode_string,
                                 unsigned int masked_ops);
int check_links_option;
int allocated_archive_names;
void update_archive(void);
_Bool get_date(struct timespec *result, char const *p,
               struct timespec const *now);
void prepend_default_options(char const *options, int *pargc, char ***pargv);
static char const *stdin_used_by;
void request_stdin(char const *option) {
  char *tmp;
  char *__cil_tmp3;

  {

    stdin_used_by = option;
    return;
  }
}
static FILE *confirm_file;
static int confirm_file_EOF;
int confirm(char const *message_action, char const *message_name) {
  char const *tmp;
  int reply;
  int tmp___0;
  int tmp___1;
  int character;
  int tmp___2;
  char *__cil_tmp9;
  char *__cil_tmp10;

  {
    if (!confirm_file) {
    }
    {
      tmp = quote(message_name);
      fprintf((FILE * /* __restrict  */)stdlis,
              (char const * /* __restrict  */) "%s %s?", message_action, tmp);
      fflush_unlocked(stdlis);
    }

    reply = tmp___1;
    character = reply;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(character != 10)) {
          goto while_break;
        }

        { character = getc_unlocked(confirm_file); }
      }
    while_break: /* CIL Label */
        ;
    }

    return (tmp___2);
  }
}
static struct fmttab const fmttab[6] = {
    {"v7", (enum archive_format)1},
    {"oldgnu", (enum archive_format)2},
    {"ustar", (enum archive_format)3},
    {"posix", (enum archive_format)4},
    {"gnu", (enum archive_format)6},
    {(char const *)((void *)0), (enum archive_format)0}};
static void set_archive_format(char const *name) {
  struct fmttab const *p;
  char *tmp;
  char *tmp___0;
  int tmp___1;
  char *__cil_tmp6;

  {
    p = fmttab;
    {

    while_break: /* CIL Label */
        ;
    }
    archive_format = (enum archive_format)p->fmt;
    return;
  }
}
static char const *archive_format_string(enum archive_format fmt) {
  struct fmttab const *p;
  char *__cil_tmp3;

  {
    p = fmttab;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!p->name) {
          goto while_break;
        }

        p++;
      }
    while_break: /* CIL Label */
        ;
    }
    return ("unknown?");
  }
}
static void assert_format(unsigned int fmt_mask) {
  char *tmp;
  char *__cil_tmp3;

  { return; }
}
static int show_help;
static int show_version;
static struct option long_options[104] = {
    {"absolute-names", 0, (int *)0, 'P'},
    {"after-date", 1, (int *)0, 'N'},
    {"anchored", 0, (int *)0, 128},
    {"append", 0, (int *)0, 'r'},
    {"atime-preserve", 0, (int *)0, 129},
    {"backup", 2, (int *)0, 130},
    {"block-number", 0, (int *)0, 'R'},
    {"blocking-factor", 1, (int *)0, 'b'},
    {"bzip2", 0, (int *)0, 'j'},
    {"catenate", 0, (int *)0, 'A'},
    {"checkpoint", 0, (int *)0, 131},
    {"check-links", 0, &check_links_option, 1},
    {"compare", 0, (int *)0, 'd'},
    {"compress", 0, (int *)0, 'Z'},
    {"concatenate", 0, (int *)0, 'A'},
    {"confirmation", 0, (int *)0, 'w'},
    {"create", 0, (int *)0, 'c'},
    {"delete", 0, (int *)0, 132},
    {"dereference", 0, (int *)0, 'h'},
    {"diff", 0, (int *)0, 'd'},
    {"directory", 1, (int *)0, 'C'},
    {"exclude", 1, (int *)0, 133},
    {"exclude-from", 1, (int *)0, 'X'},
    {"extract", 0, (int *)0, 'x'},
    {"file", 1, (int *)0, 'f'},
    {"files-from", 1, (int *)0, 'T'},
    {"force-local", 0, (int *)0, 134},
    {"format", 1, (int *)0, 135},
    {"get", 0, (int *)0, 'x'},
    {"group", 1, (int *)0, 136},
    {"gunzip", 0, (int *)0, 'z'},
    {"gzip", 0, (int *)0, 'z'},
    {"help", 0, &show_help, 1},
    {"ignore-case", 0, (int *)0, 137},
    {"ignore-failed-read", 0, (int *)0, 138},
    {"ignore-zeros", 0, (int *)0, 'i'},
    {"incremental", 0, (int *)0, 'G'},
    {"index-file", 1, (int *)0, 139},
    {"info-script", 1, (int *)0, 'F'},
    {"interactive", 0, (int *)0, 'w'},
    {"keep-newer-files", 0, (int *)0, 140},
    {"keep-old-files", 0, (int *)0, 'k'},
    {"label", 1, (int *)0, 'V'},
    {"list", 0, (int *)0, 't'},
    {"listed-incremental", 1, (int *)0, 'g'},
    {"mode", 1, (int *)0, 141},
    {"multi-volume", 0, (int *)0, 'M'},
    {"new-volume-script", 1, (int *)0, 'F'},
    {"newer", 1, (int *)0, 'N'},
    {"newer-mtime", 1, (int *)0, 142},
    {"null", 0, (int *)0, 148},
    {"no-anchored", 0, (int *)0, 143},
    {"no-ignore-case", 0, (int *)0, 144},
    {"no-overwrite-dir", 0, (int *)0, 145},
    {"no-wildcards", 0, (int *)0, 146},
    {"no-wildcards-match-slash", 0, (int *)0, 147},
    {"no-recursion", 0, &recursion_option, 0},
    {"no-same-owner", 0, &same_owner_option, -1},
    {"no-same-permissions", 0, &same_permissions_option, -1},
    {"numeric-owner", 0, (int *)0, 149},
    {"occurrence", 2, (int *)0, 150},
    {"old-archive", 0, (int *)0, 'o'},
    {"one-file-system", 0, (int *)0, 'l'},
    {"overwrite", 0, (int *)0, 151},
    {"owner", 1, (int *)0, 152},
    {"pax-option", 1, (int *)0, 153},
    {"portability", 0, (int *)0, 'o'},
    {"posix", 0, (int *)0, 154},
    {"preserve", 0, (int *)0, 155},
    {"preserve-order", 0, (int *)0, 's'},
    {"preserve-permissions", 0, (int *)0, 'p'},
    {"recursion", 0, &recursion_option, 1 << 3},
    {"recursive-unlink", 0, (int *)0, 157},
    {"read-full-records", 0, (int *)0, 'B'},
    {"record-size", 1, (int *)0, 156},
    {"remove-files", 0, (int *)0, 158},
    {"rmt-command", 1, (int *)0, 159},
    {"rsh-command", 1, (int *)0, 160},
    {"same-order", 0, (int *)0, 's'},
    {"same-owner", 0, &same_owner_option, 1},
    {"same-permissions", 0, (int *)0, 'p'},
    {"show-defaults", 0, (int *)0, 161},
    {"show-omitted-dirs", 0, (int *)0, 162},
    {"sparse", 0, (int *)0, 'S'},
    {"starting-file", 1, (int *)0, 'K'},
    {"strip-path", 1, (int *)0, 163},
    {"suffix", 1, (int *)0, 164},
    {"tape-length", 1, (int *)0, 'L'},
    {"to-stdout", 0, (int *)0, 'O'},
    {"totals", 0, (int *)0, 165},
    {"touch", 0, (int *)0, 'm'},
    {"uncompress", 0, (int *)0, 'Z'},
    {"ungzip", 0, (int *)0, 'z'},
    {"unlink-first", 0, (int *)0, 'U'},
    {"update", 0, (int *)0, 'u'},
    {"utc", 0, (int *)0, 167},
    {"use-compress-program", 1, (int *)0, 166},
    {"verbose", 0, (int *)0, 'v'},
    {"verify", 0, (int *)0, 'W'},
    {"version", 0, &show_version, 1},
    {"volno-file", 1, (int *)0, 168},
    {"wildcards", 0, (int *)0, 169},
    {"wildcards-match-slash", 0, (int *)0, 170},
    {(char const *)0, 0, (int *)0, 0}};
__attribute__((__noreturn__)) void usage(int status);
void usage(int status) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  char *tmp___10;
  char *tmp___11;
  char *tmp___12;
  char *tmp___13;
  char *tmp___14;
  char const *tmp___15;
  char *tmp___16;
  char *tmp___17;
  char *__cil_tmp21;
  char *__cil_tmp22;
  char *__cil_tmp23;
  char *__cil_tmp24;
  char *__cil_tmp25;
  char *__cil_tmp26;
  char *__cil_tmp27;
  char *__cil_tmp28;
  char *__cil_tmp29;
  char *__cil_tmp30;
  char *__cil_tmp31;
  char *__cil_tmp32;
  char *__cil_tmp33;
  char *__cil_tmp34;
  char *__cil_tmp35;
  char *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;

  {
    if (status != 0) {
      {
        tmp = gettext("Try `%s --help\' for more information.\n");
        fprintf((FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */)tmp, program_name);
      }
    } else {
      {
        tmp___0 = gettext(
            "GNU `tar\' saves many files together into a single tape or disk "
            "archive, and\ncan restore individual files from the archive.\n");
        fputs_unlocked((char const * /* __restrict  */)tmp___0,
                       (FILE * /* __restrict  */)stdout);
        tmp___1 =
            gettext("\nUsage: %s [OPTION]... [FILE]...\n\nExamples:\n  %s -cf "
                    "archive.tar foo bar  # Create archive.tar from files foo "
                    "and bar.\n  %s -tvf archive.tar         # List all files "
                    "in archive.tar verbosely.\n  %s -xf archive.tar          "
                    "# Extract all files from archive.tar.\n");
        printf((char const * /* __restrict  */)tmp___1, program_name,
               program_name, program_name, program_name);
        tmp___2 = gettext("\nIf a long option shows an argument as mandatory, "
                          "then it is mandatory\nfor the equivalent short "
                          "option also.  Similarly for optional arguments.\n");
        fputs_unlocked((char const * /* __restrict  */)tmp___2,
                       (FILE * /* __restrict  */)stdout);

        fputs_unlocked((char const * /* __restrict  */)tmp___3,
                       (FILE * /* __restrict  */)stdout);

        fputs_unlocked((char const * /* __restrict  */)tmp___4,
                       (FILE * /* __restrict  */)stdout);

        fputs_unlocked((char const * /* __restrict  */)tmp___5,
                       (FILE * /* __restrict  */)stdout);

        fputs_unlocked((char const * /* __restrict  */)tmp___6,
                       (FILE * /* __restrict  */)stdout);
        tmp___7 = gettext(
            "\nDevice blocking:\n  -b, --blocking-factor=BLOCKS   BLOCKS x 512 "
            "bytes per record\n      --record-size=SIZE         SIZE bytes per "
            "record, multiple of 512\n  -i, --ignore-zeros             ignore "
            "zeroed blocks in archive (means EOF)\n  -B, --read-full-records   "
            "     reblock as we read (for 4.2BSD pipes)\n");
        fputs_unlocked((char const * /* __restrict  */)tmp___7,
                       (FILE * /* __restrict  */)stdout);

        fputs_unlocked((char const * /* __restrict  */)tmp___8,
                       (FILE * /* __restrict  */)stdout);

        fputs_unlocked((char const * /* __restrict  */)tmp___9,
                       (FILE * /* __restrict  */)stdout);
        tmp___10 = gettext("  -N, --newer=DATE-OR-FILE     only store files "
                           "newer than DATE-OR-FILE\n      --newer-mtime=DATE  "
                           "     compare date and time when data changed "
                           "only\n      --after-date=DATE        same as -N\n");
        fputs_unlocked((char const * /* __restrict  */)tmp___10,
                       (FILE * /* __restrict  */)stdout);
        tmp___11 =
            gettext("      --backup[=CONTROL]       backup before removal, "
                    "choose version control\n      --suffix=SUFFIX          "
                    "backup before removal, override usual suffix\n");
        fputs_unlocked((char const * /* __restrict  */)tmp___11,
                       (FILE * /* __restrict  */)stdout);

        fputs_unlocked((char const * /* __restrict  */)tmp___12,
                       (FILE * /* __restrict  */)stdout);
        tmp___13 = gettext(
            "\nCompatibility options:\n  -o                                 "
            "when creating, same as --old-archive\n                            "
            "         when extracting, same as --no-same-owner\n");
        fputs_unlocked((char const * /* __restrict  */)tmp___13,
                       (FILE * /* __restrict  */)stdout);
        tmp___14 =
            gettext("\nThe backup suffix is `~\', unless set with --suffix or "
                    "SIMPLE_BACKUP_SUFFIX.\nThe version control may be set "
                    "with --backup or VERSION_CONTROL, values are:\n\n  t, "
                    "numbered     make numbered backups\n  nil, existing   "
                    "numbered if numbered backups exist, simple otherwise\n  "
                    "never, simple   always make simple backups\n");
        fputs_unlocked((char const * /* __restrict  */)tmp___14,
                       (FILE * /* __restrict  */)stdout);
        tmp___15 = archive_format_string((enum archive_format)6);
        tmp___16 =
            gettext("\nARCHIVE may be FILE, HOST:FILE or USER@HOST:FILE; DATE "
                    "may be a textual date\nor a file name starting with `/\' "
                    "or `.\', in which case the file\'s date is used.\n*This* "
                    "`tar\' defaults to `--format=%s -f%s -b%d\'.\n");
        printf((char const * /* __restrict  */)tmp___16, tmp___15, "-", 20);
        tmp___17 = gettext("\nReport bugs to <%s>.\n");
        printf((char const * /* __restrict  */)tmp___17, "bug-tar@gnu.org");
      }
    }
    { exit(status); }
  }
}
static void set_subcommand_option(enum subcommand subcommand) {
  char *tmp;
  char *__cil_tmp3;

  {

    subcommand_option = subcommand;
    return;
  }
}
static void set_use_compress_program_option(char const *string) {
  char *tmp;
  int tmp___0;
  char *__cil_tmp4;

  {

    use_compress_program_option = string;
    return;
  }
}
static void decode_options(int argc, char **argv) {
  int optchar;
  int input_files;
  char const *textual_date_option;
  char const *backup_suffix_string;
  char const *version_control_string;
  int exclude_options;
  _Bool o_option;
  int pax_option;
  char *tmp;
  int new_argc;
  char **new_argv;
  char *const *in;
  char **out;
  char const *letter;
  char buffer___2[3];
  char const *cursor;
  size_t tmp___0;
  void *tmp___1;
  char **tmp___2;
  char *const *tmp___3;
  char *const *tmp___4;
  char **tmp___5;
  char *tmp___6;
  char **tmp___7;
  char *const *tmp___8;
  char *tmp___9;
  char **tmp___10;
  char *const *tmp___11;
  char *tmp___12;
  uintmax_t u;
  char *tmp___13;
  char *tmp___14;
  strtol_error tmp___15;
  void *tmp___16;
  int tmp___17;
  char *tmp___18;
  uintmax_t u___0;
  char *tmp___19;
  char *tmp___20;
  strtol_error tmp___21;
  char *tmp___22;
  struct stat st;
  char *tmp___23;
  int tmp___24;
  char const *tmp___25;
  char const *tmp___26;
  char *tmp___27;
  _Bool tmp___28;
  int e;
  int *tmp___29;
  char *tmp___30;
  int tmp___31;
  char *tmp___32;
  uintmax_t g;
  char *tmp___33;
  char *tmp___34;
  strtol_error tmp___35;
  size_t tmp___36;
  int tmp___37;
  char *tmp___38;
  uintmax_t u___1;
  char *tmp___39;
  char *tmp___40;
  strtol_error tmp___41;
  uintmax_t u___2;
  char *tmp___42;
  char *tmp___43;
  strtol_error tmp___44;
  size_t tmp___45;
  int tmp___46;
  uintmax_t u___3;
  char *tmp___47;
  char *tmp___48;
  strtol_error tmp___49;
  char *tmp___50;
  char const *tmp___51;
  uintmax_t u___4;
  char *tmp___52;
  char *tmp___53;
  strtol_error tmp___54;
  char *tmp___55;
  char *tmp___56;
  char *tmp___57;
  char *tmp___58;
  char *tmp___59;
  char *tmp___60;
  char *tmp___61;
  char *tmp___62;
  size_t volume_label_max_len;
  char *tmp___63;
  char *tmp___64;
  size_t tmp___65;
  char *tmp___66;
  char *tmp___67;
  char *tmp___68;
  char *tmp___69;
  char *tmp___70;
  char *tmp___71;
  int tmp___72;
  char *tmp___73;
  int tmp___74;
  char *tmp___75;
  char const *treated_as;
  char const *tmp___76;
  char *tmp___77;
  int tmp___78;
  unsigned long tmp___79;
  void *__cil_tmp110;
  void *__cil_tmp111;
  char *__cil_tmp112;
  char *__cil_tmp113;
  char *__cil_tmp114;
  char *__cil_tmp115;
  char *__cil_tmp116;
  char *__cil_tmp117;
  char *__cil_tmp118;
  char *__cil_tmp119;
  char *__cil_tmp120;
  char *__cil_tmp121;
  char *__cil_tmp122;
  char *__cil_tmp123;
  char *__cil_tmp124;
  char *__cil_tmp125;
  char *__cil_tmp126;
  char *__cil_tmp127;
  char *__cil_tmp128;
  char *__cil_tmp129;
  char *__cil_tmp130;
  char *__cil_tmp131;
  char *__cil_tmp132;
  char *__cil_tmp133;
  char *__cil_tmp134;
  char *__cil_tmp135;
  char *__cil_tmp136;
  char *__cil_tmp137;
  char *__cil_tmp138;
  char *__cil_tmp139;
  char *__cil_tmp140;
  char *__cil_tmp141;
  char *__cil_tmp142;
  char *__cil_tmp143;
  char *__cil_tmp144;
  char *__cil_tmp145;
  char *__cil_tmp146;
  char *__cil_tmp147;
  char *__cil_tmp148;
  char *__cil_tmp149;
  char *__cil_tmp150;
  char *__cil_tmp151;
  char *__cil_tmp152;
  char *__cil_tmp153;
  char *__cil_tmp154;
  char *__cil_tmp155;
  char *__cil_tmp156;
  char *__cil_tmp157;
  char *__cil_tmp158;
  char *__cil_tmp159;
  char *__cil_tmp160;
  char *__cil_tmp161;
  char *__cil_tmp162;
  char *__cil_tmp163;
  char *__cil_tmp164;
  char *__cil_tmp165;
  char *__cil_tmp166;
  char *__cil_tmp167;
  char *__cil_tmp168;
  char *__cil_tmp169;
  char *__cil_tmp170;
  char *__cil_tmp171;
  char *__cil_tmp172;

  {
    {
      textual_date_option = (char const *)0;
      version_control_string = (char const *)0;
      exclude_options = 1 << 28;
      o_option = (_Bool)0;
      pax_option = 0;
      subcommand_option = (enum subcommand)0;
      archive_format = (enum archive_format)0;
      blocking_factor = 20;
      record_size = (size_t)10240;
      excluded = new_exclude();
      newer_mtime_option.tv_sec = -1L << (sizeof(time_t) * 8UL - 1UL);
      newer_mtime_option.tv_nsec = (__syscall_slong_t)-1;
      recursion_option = 1 << 3;
      owner_option = (uid_t)-1;
      group_option = (gid_t)-1;
      tmp = getenv("SIMPLE_BACKUP_SUFFIX");
      backup_suffix_string = (char const *)tmp;
    }
    if (argc > 1) {
    }
    {
      input_files = 0;
      tmp___12 = getenv("TAR_OPTIONS");
      prepend_default_options((char const *)tmp___12, &argc, &argv);
    }
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        {
          optchar = getopt_long(
              argc, (char *const *)argv,
              "-01234567ABC:F:GIK:L:MN:OPRST:UV:WX:Zb:cdf:g:hijklmoprstuvwxyz",
              (struct option const *)(long_options), (int *)0);
        }
        if (!(optchar != -1)) {
          goto while_break___1;
        }
        {
          if (optchar == 63) {
            goto case_63;
          }
          if (optchar == 0) {
            goto case_0;
          }
          if (optchar == 1) {
            goto case_1;
          }
          if (optchar == 65) {
            goto case_65;
          }

          if (optchar == 67) {
            goto case_67;
          }

          if (optchar == 102) {
            goto case_102;
          }
          if (optchar == 70) {
            goto case_70;
          }

          if (optchar == 104) {
            goto case_104;
          }
          if (optchar == 105) {
            goto case_105;
          }
          if (optchar == 73) {
            goto case_73;
          }
          if (optchar == 106) {
            goto case_106;
          }
          if (optchar == 107) {
            goto case_107;
          }
          if (optchar == 75) {
            goto case_75;
          }

          if (optchar == 76) {
            goto case_76;
          }

          if (optchar == 111) {
            goto case_111;
          }

          if (optchar == 112) {
            goto case_112;
          }

          if (optchar == 83) {
            goto case_83;
          }

          if (optchar == 84) {
            goto case_84;
          }

          if (optchar == 118) {
            goto case_118;
          }

          if (optchar == 120) {
            goto case_120;
          }

          if (optchar == 129) {
            goto case_129;
          }

          if (optchar == 130) {
            goto case_130;
          }
          if (optchar == 132) {
            goto case_132;
          }

          if (optchar == 134) {
            goto case_134;
          }
          if (optchar == 135) {
            goto case_135;
          }
          if (optchar == 139) {
            goto case_139;
          }
          if (optchar == 137) {
            goto case_137;
          }

          if (optchar == 136) {
            goto case_136;
          }
          if (optchar == 141) {
            goto case_141;
          }
          if (optchar == 143) {
            goto case_143;
          }
          if (optchar == 144) {
            goto case_144;
          }
          if (optchar == 145) {
            goto case_145;
          }
          if (optchar == 146) {
            goto case_146;
          }
          if (optchar == 147) {
            goto case_147;
          }

          if (optchar == 149) {
            goto case_149;
          }

          if (optchar == 151) {
            goto case_151;
          }
          if (optchar == 152) {
            goto case_152;
          }
          if (optchar == 153) {
            goto case_153;
          }
          if (optchar == 154) {
            goto case_154;
          }

          if (optchar == 157) {
            goto case_157;
          }

          if (optchar == 159) {
            goto case_159;
          }

          if (optchar == 163) {
            goto case_163;
          }

          if (optchar == 169) {
            goto case_169;
          }
          if (optchar == 170) {
            goto case_170;
          }
          if (optchar == 48) {
            goto case_48;
          }

          if (optchar == 50) {
            goto case_48;
          }

          goto switch_break;
        case_63: { /* CIL Label */
          usage(2);
        }
        case_0: /* CIL Label */
          goto switch_break;
        case_1: { /* CIL Label */
          name_add((char const *)optarg);
          input_files++;
        }
          goto switch_break;
        case_65: { /* CIL Label */
          set_subcommand_option((enum subcommand)2);
        }
          goto switch_break;
        case_98: { /* CIL Label */
          tmp___15 = xstrtoumax((char const *)optarg, (char **)0, 10, &u, "");
        }

          goto switch_break;
        case_66: /* CIL Label */
          read_full_records_option = (_Bool)1;
          goto switch_break;
        case_99: { /* CIL Label */
          set_subcommand_option((enum subcommand)3);
        }
          goto switch_break;
        case_67: { /* CIL Label */
          name_add("-C");
          name_add((char const *)optarg);
        }
          goto switch_break;
        case_100: { /* CIL Label */
          set_subcommand_option((enum subcommand)5);
        }
          goto switch_break;
        case_102: /* CIL Label */
          if (archive_names == allocated_archive_names) {
            {
              allocated_archive_names *= 2;
              tmp___16 = xrealloc((void *)archive_name_array,
                                  sizeof(char const *) *
                                      (unsigned long)allocated_archive_names);
              archive_name_array = (char const **)tmp___16;
            }
          }
          tmp___17 = archive_names;
          archive_names++;
          *(archive_name_array + tmp___17) = (char const *)optarg;
          goto switch_break;
        case_70: /* CIL Label */
          info_script_option = (char const *)optarg;
          multi_volume_option = (_Bool)1;
          goto switch_break;
        case_103: /* CIL Label */
          listed_incremental_option = (char const *)optarg;
          after_date_option = 1;
        case_71: /* CIL Label */
          incremental_option = (_Bool)1;
          goto switch_break;
        case_104: /* CIL Label */
          dereference_option = (_Bool)1;
          goto switch_break;
        case_105: /* CIL Label */
          ignore_zeros_option = (_Bool)1;
          goto switch_break;
        case_73: { /* CIL Label */
          tmp___18 = gettext("Warning: the -I option is not supported; perhaps "
                             "you meant -j or -T?");
          error(0, 0, (char const *)tmp___18);
          usage(2);
        }
          goto switch_break;
        case_106: { /* CIL Label */
          set_use_compress_program_option("bzip2");
        }
          goto switch_break;
        case_107: /* CIL Label */
          old_files_option = (enum old_files)4;
          goto switch_break;
        case_75: { /* CIL Label */
          starting_file_option = (_Bool)1;
          addname((char const *)optarg, 0);
        }
          goto switch_break;
        case_108: /* CIL Label */
          one_file_system_option = (_Bool)1;
          goto switch_break;
        case_76: { /* CIL Label */
          tmp___21 =
              xstrtoumax((char const *)optarg, (char **)0, 10, &u___0, "");
        }

          tape_length_option = (tarlong)1024 * (tarlong)u___0;
          multi_volume_option = (_Bool)1;
          goto switch_break;
        case_109: /* CIL Label */
          touch_option = (_Bool)1;
          goto switch_break;
        case_77: /* CIL Label */
          multi_volume_option = (_Bool)1;
          goto switch_break;
        case_78: /* CIL Label */
          after_date_option = 1;
        case_142: /* CIL Label */

          goto switch_break;
        case_111: /* CIL Label */
          o_option = (_Bool)1;
          goto switch_break;
        case_79: /* CIL Label */
          to_stdout_option = (_Bool)1;
          goto switch_break;
        case_112: /* CIL Label */
          same_permissions_option = 1;
          goto switch_break;
        case_80: /* CIL Label */
          absolute_names_option = (_Bool)1;
          goto switch_break;
        case_114: { /* CIL Label */
          set_subcommand_option((enum subcommand)1);
        }
          goto switch_break;
        case_82: /* CIL Label */
          block_number_option = (_Bool)1;
          goto switch_break;
        case_115: /* CIL Label */
          same_order_option = (_Bool)1;
          goto switch_break;
        case_83: /* CIL Label */
          sparse_option = (_Bool)1;
          goto switch_break;
        case_116: { /* CIL Label */
          set_subcommand_option((enum subcommand)7);
          verbose_option++;
        }
          goto switch_break;
        case_84: /* CIL Label */
          files_from_option = (char const *)optarg;
          goto switch_break;
        case_117: { /* CIL Label */
          set_subcommand_option((enum subcommand)8);
        }
          goto switch_break;
        case_85: /* CIL Label */
          old_files_option = (enum old_files)3;
          goto switch_break;
        case_167: /* CIL Label */
          utc_option = (_Bool)1;
          goto switch_break;
        case_118: /* CIL Label */
          verbose_option++;
          goto switch_break;
        case_86: /* CIL Label */
          volume_label_option = (char const *)optarg;
          goto switch_break;
        case_119: /* CIL Label */
          interactive_option = (_Bool)1;
          goto switch_break;
        case_87: /* CIL Label */
          verify_option = (_Bool)1;
          goto switch_break;
        case_120: { /* CIL Label */
          set_subcommand_option((enum subcommand)6);
        }
          goto switch_break;
        case_88: { /* CIL Label */
          tmp___31 =
              add_exclude_file(&add_exclude, excluded, (char const *)optarg,
                               exclude_options | recursion_option, (char)'\n');
        }

          goto switch_break;
        case_121: { /* CIL Label */
          tmp___32 = gettext(
              "Warning: the -y option is not supported; perhaps you meant -j?");
          error(0, 0, (char const *)tmp___32);
          usage(2);
        }
          goto switch_break;
        case_122: { /* CIL Label */
          set_use_compress_program_option("gzip");
        }
          goto switch_break;
        case_90: { /* CIL Label */
          set_use_compress_program_option("compress");
        }
          goto switch_break;
        case_128: /* CIL Label */
          exclude_options |= 1 << 30;
          goto switch_break;
        case_129: /* CIL Label */
          atime_preserve_option = (_Bool)1;
          goto switch_break;
        case_131: /* CIL Label */
          checkpoint_option = (_Bool)1;
          goto switch_break;
        case_130: /* CIL Label */
          backup_option = (_Bool)1;

          goto switch_break;
        case_132: { /* CIL Label */
          set_subcommand_option((enum subcommand)4);
        }
          goto switch_break;
        case_133: { /* CIL Label */
          add_exclude(excluded, (char const *)optarg,
                      exclude_options | recursion_option);
        }
          goto switch_break;
        case_134: /* CIL Label */
          force_local_option = (_Bool)1;
          goto switch_break;
        case_135: { /* CIL Label */
          set_archive_format((char const *)optarg);
        }
          goto switch_break;
        case_139: /* CIL Label */
          index_file_name = (char const *)optarg;
          goto switch_break;
        case_137: /* CIL Label */
          exclude_options |= 1 << 4;
          goto switch_break;
        case_138: /* CIL Label */
          ignore_failed_read_option = (_Bool)1;
          goto switch_break;
        case_140: /* CIL Label */
          old_files_option = (enum old_files)5;
          goto switch_break;
        case_136: { /* CIL Label */
          tmp___36 = strlen((char const *)optarg);
        }

          goto switch_break;
        case_141: { /* CIL Label */
          mode_option = mode_compile((char const *)optarg, 7U);
        }
          if ((unsigned long)mode_option ==
              (unsigned long)((struct mode_change *)0)) {
            {
              tmp___38 = gettext("Invalid mode given on option");
              error(0, 0, (char const *)tmp___38);
              fatal_exit();
            }
          }

          goto switch_break;
        case_143: /* CIL Label */
          exclude_options &= ~(1 << 30);
          goto switch_break;
        case_144: /* CIL Label */
          exclude_options &= ~(1 << 4);
          goto switch_break;
        case_145: /* CIL Label */
          old_files_option = (enum old_files)1;
          goto switch_break;
        case_146: /* CIL Label */
          exclude_options &= ~(1 << 28);
          goto switch_break;
        case_147: /* CIL Label */
          exclude_options |= 1;
          goto switch_break;
        case_148: /* CIL Label */
          filename_terminator = (char)'\000';
          goto switch_break;
        case_149: /* CIL Label */
          numeric_owner_option = (_Bool)1;
          goto switch_break;
        case_150: /* CIL Label */

          goto switch_break;
        case_151: /* CIL Label */
          old_files_option = (enum old_files)2;
          goto switch_break;
        case_152: { /* CIL Label */
          tmp___45 = strlen((char const *)optarg);
        }
          if (tmp___45 < 32UL) {
            {
              tmp___46 = uname_to_uid((char const *)optarg, &owner_option);
            }

          } else {
          _L___0: {
            tmp___44 =
                xstrtoumax((char const *)optarg, (char **)0, 10, &u___2, "");
          }
            if ((unsigned int)tmp___44 == 0U) {

            } else {
              {
                tmp___42 = gettext("Invalid owner");
                tmp___43 = quotearg_colon((char const *)optarg);
                error(0, 0, "%s: %s", tmp___43, tmp___42);
                fatal_exit();
              }
            }
          }
          goto switch_break;
        case_153: { /* CIL Label */
          pax_option++;
          xheader_set_option(optarg);
        }
          goto switch_break;
        case_154: { /* CIL Label */
          set_archive_format("posix");
        }
          goto switch_break;
        case_155: /* CIL Label */
          same_permissions_option = 1;
          same_order_option = (_Bool)1;
          goto switch_break;
        case_156: { /* CIL Label */
          tmp___49 =
              xstrtoumax((char const *)optarg, (char **)0, 10, &u___3, "");
        }

          record_size = u___3;

          blocking_factor = (int)(record_size / 512UL);
          goto switch_break;
        case_157: /* CIL Label */
          recursive_unlink_option = (_Bool)1;
          goto switch_break;
        case_158: /* CIL Label */
          remove_files_option = (_Bool)1;
          goto switch_break;
        case_159: /* CIL Label */
          rmt_command_option = (char const *)optarg;
          goto switch_break;
        case_160: /* CIL Label */
          rsh_command_option = (char const *)optarg;
          goto switch_break;
        case_161: { /* CIL Label */
          tmp___51 = archive_format_string((enum archive_format)6);
          printf((char const * /* __restrict  */) "--format=%s -f%s -b%d\n",
                 tmp___51, "-", 20);
          exit(0);
        }
        case_163: { /* CIL Label */
          tmp___54 =
              xstrtoumax((char const *)optarg, (char **)0, 10, &u___4, "");
        }

          strip_path_elements = u___4;
          goto switch_break;
        case_164: /* CIL Label */
          backup_option = (_Bool)1;
          backup_suffix_string = (char const *)optarg;
          goto switch_break;
        case_165: /* CIL Label */
          totals_option = (_Bool)1;
          goto switch_break;
        case_166: { /* CIL Label */
          set_use_compress_program_option((char const *)optarg);
        }
          goto switch_break;
        case_168: /* CIL Label */
          volno_file_option = (char const *)optarg;
          goto switch_break;
        case_169: /* CIL Label */
          exclude_options |= 1 << 28;
          goto switch_break;
        case_170: /* CIL Label */
          exclude_options &= -2;
          goto switch_break;
        case_48:   /* CIL Label */
        case_49:   /* CIL Label */
        case_50:   /* CIL Label */
        case_51:   /* CIL Label */
        case_52:   /* CIL Label */
        case_53:   /* CIL Label */
        case_54:   /* CIL Label */
        case_55: { /* CIL Label */
          tmp___55 =
              gettext("Options `-[0-7][lmh]\' not supported by *this* tar");
          error(0, 0, (char const *)tmp___55);
          usage(2);
        }
        switch_break: /* CIL Label */
            ;
        }
      }
    while_break___1: /* CIL Label */
        ;
    }

    {
      while (1) {
      while_continue___2: /* CIL Label */
          ;
        if (!(optind < argc)) {
          goto while_break___2;
        }
        {
          name_add((char const *)*(argv + optind));
          input_files++;
          optind++;
        }
      }
    while_break___2: /* CIL Label */
        ;
    }

    if ((unsigned int)archive_format == 0U) {
      if (pax_option) {
        archive_format = (enum archive_format)4;
      } else {
        archive_format = (enum archive_format)6;
      }
    }

    if (sparse_option) {
      {
        assert_format((unsigned int)(((1 << 2) | (1 << 6)) | (1 << 4)));
      }
    }
    if (occurrence_option) {
      if (!input_files) {
        if (!files_from_option) {
          {
            tmp___58 =
                gettext("--occurrence is meaningless without a file list");
            error(0, 0, (char const *)tmp___58);
            usage(2);
          }
        }
      }
      if ((unsigned int)subcommand_option != 4U) {
      }
    }
    if (archive_names == 0) {
      {
        archive_names = 1;
        tmp___60 = getenv("TAPE");
        *(archive_name_array + 0) = (char const *)tmp___60;
      }
    }

    {
      if ((unsigned int)subcommand_option == 3U) {
        goto case_3;
      }
      if ((unsigned int)subcommand_option == 6U) {
        goto case_6;
      }

      if ((unsigned int)subcommand_option == 2U) {
        goto case_2;
      }

      goto switch_default;
    case_3: /* CIL Label */

      goto switch_break___0;
    case_6: /* CIL Label */
    case_7: /* CIL Label */
    case_5: /* CIL Label */
      archive_name_cursor = archive_name_array;
      {
        while (1) {
        while_continue___3: /* CIL Label */
            ;
          if (!((unsigned long)archive_name_cursor <
                (unsigned long)(archive_name_array + archive_names))) {
            goto while_break___3;
          }
          { tmp___72 = strcmp(*archive_name_cursor, "-"); }
          if (!tmp___72) {
            {
              request_stdin("-f");
            }
          }
          archive_name_cursor++;
        }
      while_break___3: /* CIL Label */
          ;
      }
      goto switch_break___0;
    case_2:     /* CIL Label */
    case_8:     /* CIL Label */
    case_1___0: /* CIL Label */
      archive_name_cursor = archive_name_array;
      {
        while (1) {
        while_continue___4: /* CIL Label */
            ;
          if (!((unsigned long)archive_name_cursor <
                (unsigned long)(archive_name_array + archive_names))) {
            goto while_break___4;
          }
          { tmp___74 = strcmp(*archive_name_cursor, "-"); }
          if (!tmp___74) {
            {
              tmp___73 =
                  gettext("Options `-Aru\' are incompatible with `-f -\'");
              error(0, 0, (char const *)tmp___73);
              usage(2);
            }
          }
          archive_name_cursor++;
        }
      while_break___4: /* CIL Label */
          ;
      }
    switch_default: /* CIL Label */
      goto switch_break___0;
    switch_break___0: /* CIL Label */
        ;
    }
    archive_name_cursor = archive_name_array;

    if (verbose_option) {
    }
    return;
  }
}
int main(int argc, char **argv) {
  int tmp;
  void *tmp___0;
  char *tmp___1;
  char *tmp___2;
  int tmp___3;
  int tmp___4;
  char *tmp___5;
  int tmp___6;
  int tmp___7;
  char *__cil_tmp12;
  char *__cil_tmp13;
  char *__cil_tmp14;
  char *__cil_tmp15;

  {
    { tmp = clock_gettime(0, &start_timespec); }

    {
      program_name = (char const *)*(argv + 0);
      setlocale(6, "");
      bindtextdomain("tar", "/usr/local/share/locale");
      textdomain("tar");
      exit_status = 0;
      filename_terminator = (char)'\n';
      set_quoting_style((struct quoting_options *)0, (enum quoting_style)4);
      allocated_archive_names = 10;
      tmp___0 = xmalloc(sizeof(char const *) *
                        (unsigned long)allocated_archive_names);
      archive_name_array = (char const **)tmp___0;
      archive_names = 0;
      signal(17, (void (*)(int))0);
      init_names();
      decode_options(argc, argv);
      name_init();
    }

    {

      if ((unsigned int)subcommand_option == 2U) {
        goto case_2;
      }
      if ((unsigned int)subcommand_option == 8U) {
        goto case_2;
      }
      if ((unsigned int)subcommand_option == 1U) {
        goto case_2;
      }

      if ((unsigned int)subcommand_option == 6U) {
        goto case_6;
      }
      if ((unsigned int)subcommand_option == 7U) {
        goto case_7;
      }
      if ((unsigned int)subcommand_option == 5U) {
        goto case_5;
      }
      goto switch_break;
    case_0: { /* CIL Label */
      tmp___1 = gettext("You must specify one of the `-Acdtrux\' options");
      error(0, 0, (char const *)tmp___1);
      usage(2);
    }
    case_2:   /* CIL Label */
    case_8:   /* CIL Label */
    case_1: { /* CIL Label */
      update_archive();
    }
      goto switch_break;
    case_4: { /* CIL Label */
      delete_archive_members();
    }
      goto switch_break;
    case_3: { /* CIL Label */
      create_archive();
      name_close();
    }

      goto switch_break;
    case_6: { /* CIL Label */
      extr_init();
      read_and(&extract_archive);
      extract_finish();
    }
      goto switch_break;
    case_7: { /* CIL Label */
      read_and(&list_archive);
    }
      goto switch_break;
    case_5: { /* CIL Label */
      diff_init();
      read_and(&diff_archive);
    }
      goto switch_break;
    switch_break: /* CIL Label */
        ;
    }
    if (check_links_option) {
      {
        check_links();
      }
    }

    {
      free((void *)archive_name_array);
      name_term();
    }
    if ((unsigned long)stdlis != (unsigned long)stderr) {
      {
        tmp___3 = ferror_unlocked(stdlis);
      }
    }

    { tmp___6 = ferror_unlocked(stderr); }

    return (exit_status);
  }
}
void tar_stat_init(struct tar_stat_info *st) {

  {
    { memset((void *)st, 0, sizeof(*st)); }
    return;
  }
}
void tar_stat_destroy(struct tar_stat_info *st) {

  {
    {
      free((void *)st->orig_file_name);
      free((void *)st->file_name);
      free((void *)st->link_name);
      free((void *)st->uname);
      free((void *)st->gname);
      free((void *)st->sparse_map);
      memset((void *)st, 0, sizeof(*st));
    }
    return;
  }
}
/* #pragma merger("0","00f.update.o.i","") */

void update_archive(void) {
  enum read_header previous_status;
  int found_end;
  enum read_header status;
  enum read_header tmp;
  struct name *name;
  struct stat s;
  enum archive_format unused;
  int tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *path;
  _Bool tmp___3;
  int tmp___4;
  void *__cil_tmp14;
  char *__cil_tmp15;
  char *__cil_tmp16;
  char *__cil_tmp17;

  {
    {
      previous_status = (enum read_header)0;
      found_end = 0;
      name_gather();
      open_archive((enum access_mode)2);
      xheader_write_global();
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(!found_end)) {
          goto while_break;
        }
        {
          tmp = read_header((_Bool)0);
          status = tmp;
        }
        {
          if ((unsigned int)status == 0U) {
            goto case_0;
          }
          if ((unsigned int)status == 2U) {
            goto case_0;
          }
          if ((unsigned int)status == 1U) {
            goto case_1;
          }
          if ((unsigned int)status == 3U) {
            goto case_3;
          }
          if ((unsigned int)status == 4U) {
            goto case_4;
          }
          if ((unsigned int)status == 5U) {
            goto case_5;
          }
          goto switch_break;
        case_0:   /* CIL Label */
        case_2: { /* CIL Label */
          abort();
        }
        case_1: /* CIL Label */
          if ((unsigned int)subcommand_option == 8U) {
            {
              name = name_scan((char const *)current_stat_info.file_name);
            }
            if ((unsigned long)name != (unsigned long)((void *)0)) {
              {
                decode_header(current_header, &current_stat_info, &unused, 0);
                chdir_do(name->change_dir);
                tmp___0 =
                    deref_stat(dereference_option,
                               (char const *)current_stat_info.file_name, &s);
              }
            }
          }
          { skip_member(); }
          goto switch_break;
        case_3: /* CIL Label */
          current_block = current_header;
          found_end = 1;
          goto switch_break;
        case_4: /* CIL Label */
          found_end = 1;
          goto switch_break;
        case_5: { /* CIL Label */
          set_next_block_after(current_header);
        }
          {
            if ((unsigned int)previous_status == 0U) {
              goto case_0___0;
            }
            if ((unsigned int)previous_status == 1U) {
              goto case_1___0;
            }
            if ((unsigned int)previous_status == 3U) {
              goto case_1___0;
            }
            if ((unsigned int)previous_status == 5U) {
              goto case_5___0;
            }

            if ((unsigned int)previous_status == 2U) {
              goto case_4___0;
            }
            goto switch_break___0;
          case_0___0: { /* CIL Label */
            tmp___1 = gettext("This does not look like a tar archive");
            error(0, 0, (char const *)tmp___1);
          }
          case_1___0:   /* CIL Label */
          case_3___0: { /* CIL Label */
            tmp___2 = gettext("Skipping to next header");
            error(0, 0, (char const *)tmp___2);
            exit_status = 2;
          }
          case_5___0: /* CIL Label */
            goto switch_break___0;
          case_4___0:   /* CIL Label */
          case_2___0: { /* CIL Label */
            abort();
          }
          switch_break___0: /* CIL Label */
              ;
          }
          goto switch_break;
        switch_break: /* CIL Label */
            ;
        }
        previous_status = status;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      reset_eof();
      time_to_start_writing = (_Bool)1;
      output_start = current_block->buffer;
    }
    {

    while_break___0: /* CIL Label */
        ;
    }
    {
      write_eot();
      close_archive();
      names_notfound();
    }
    return;
  }
}
/* #pragma merger("0","010.utf8.o.i","") */
static iconv_t conv_desc[2] = {(iconv_t)-1, (iconv_t)-1};
static iconv_t utf8_init(_Bool to_utf) {

  {
    if ((unsigned long)conv_desc[(int)to_utf] == (unsigned long)((iconv_t)-1)) {
    }
    return (conv_desc[(int)to_utf]);
  }
}
_Bool utf8_convert(_Bool to_utf, char const *input, char **output) {
  char *ib;
  char *ob;
  size_t inlen;
  size_t outlen;
  size_t rc___1;
  iconv_t cd;
  iconv_t tmp;
  size_t tmp___0;
  char *tmp___1;
  void *tmp___2;

  {
    {
      tmp = utf8_init(to_utf);
      cd = tmp;
    }
    if ((unsigned long)cd == (unsigned long)((iconv_t)0)) {
      {
        *output = xstrdup(input);
      }
      return ((_Bool)1);
    } else {
    }
    {
      tmp___0 = strlen(input);
      inlen = tmp___0 + 1UL;
      outlen = inlen * 16UL + 1UL;
      tmp___2 = xmalloc(outlen);
      tmp___1 = (char *)tmp___2;
      *output = tmp___1;
      ob = tmp___1;
      ib = (char *)input;
      rc___1 = (size_t)0;
      *ob = (char)0;
    }
    return ((_Bool)(rc___1 != 0xffffffffffffffffUL));
  }
}
_Bool string_ascii_p(char const *str) {
  unsigned char const *p;

  {
    p = (unsigned char const *)str;
    {

    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
/* #pragma merger("0","011.addext.o.i","") */
extern __attribute__((__nothrow__)) long(__attribute__((
    __nonnull__(1), __leaf__)) pathconf)(char const *__path, int __name);
void addext(char *filename, char const *ext, int e);
size_t base_len(char const *name);

/* #pragma merger("0","012.argmatch.o.i","") */
int argmatch(char const *arg, char const *const *arglist, char const *vallist,
             size_t valsize);
void (*argmatch_die)(void);
void argmatch_invalid(char const *context, char const *value, int problem);
void argmatch_valid(char const *const *arglist, char const *vallist,
                    size_t valsize);
int __xargmatch_internal(char const *context, char const *arg,
                         char const *const *arglist, char const *vallist,
                         size_t valsize, void (*exit_fn)(void));
int volatile exit_failure;
static void __argmatch_die(void) {

  {
    { exit((int)exit_failure); }
  }
}
void (*argmatch_die)(void) = &__argmatch_die;
int argmatch(char const *arg, char const *const *arglist, char const *vallist,
             size_t valsize) {
  int i;
  size_t arglen;
  int matchind;
  int ambiguous;
  int tmp;
  size_t tmp___0;
  int tmp___1;

  {
    {
      matchind = -1;
      ambiguous = 0;
      arglen = strlen(arg);
      i = 0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!*(arglist + i)) {
          goto while_break;
        }
        { tmp___1 = strncmp((char const *)*(arglist + i), arg, arglen); }
        if (!tmp___1) {
          {
            tmp___0 = strlen((char const *)*(arglist + i));
          }
          if (tmp___0 == arglen) {
            return (i);
          } else {
            if (matchind == -1) {
              matchind = i;
            } else {
              if ((unsigned long)vallist == (unsigned long)((void *)0)) {
                ambiguous = 1;
              } else {
                {
                  tmp = memcmp(
                      (void const *)(vallist + valsize * (size_t)matchind),
                      (void const *)(vallist + valsize * (size_t)i), valsize);
                }
                if (tmp) {
                  ambiguous = 1;
                }
              }
            }
          }
        }
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
    if (ambiguous) {
      return (-2);
    } else {
      return (matchind);
    }
  }
}
void argmatch_invalid(char const *context, char const *value, int problem) {
  char const *format;
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char const *tmp___2;
  char *tmp___3;
  char *__cil_tmp10;
  char *__cil_tmp11;

  {

    {
      format = (char const *)tmp___1;
      tmp___2 = quote_n(1, context);
      tmp___3 = quotearg_n_style(0, (enum quoting_style)5, value);
      error(0, 0, format, tmp___3, tmp___2);
    }
    return;
  }
}
void argmatch_valid(char const *const *arglist, char const *vallist,
                    size_t valsize) {
  int i;
  char const *last_val;
  char *tmp;
  int tmp___0;
  char *__cil_tmp8;

  {
    {
      last_val = (char const *)((void *)0);
      tmp = gettext("Valid arguments are:");
      fprintf((FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */)tmp);
      i = 0;
    }
    {

    while_break: /* CIL Label */
        ;
    }
    { putc_unlocked('\n', stderr); }
    return;
  }
}
int __xargmatch_internal(char const *context, char const *arg,
                         char const *const *arglist, char const *vallist,
                         size_t valsize, void (*exit_fn)(void)) {
  int res;
  int tmp;

  {
    {
      tmp = argmatch(arg, arglist, vallist, valsize);
      res = tmp;
    }

    {
      argmatch_invalid(context, arg, res);
      argmatch_valid(arglist, vallist, valsize);
      (*exit_fn)();
    }
    return (-1);
  }
}
/* #pragma merger("0","013.backupfile.o.i","") */
extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(
    size_t __size) __attribute__((__malloc__));
enum backup_type get_version(char const *context, char const *version);
size_t dir_len(char const *path);
char const *simple_backup_suffix = "~";
static int max_backup_version(char const *file, char const *dir);
static int version_number(char const *base, char const *backup,
                          size_t base_length);
char *find_backup_file_name(char const *file,
                            enum backup_type backup_type___0) {
  size_t backup_suffix_size_max;
  size_t file_len;
  size_t tmp;
  size_t numbered_suffix_size_max;
  char *s;
  char const *suffix;
  size_t tmp___0;
  void *tmp___1;
  int highest_backup;
  size_t dirlen;
  size_t tmp___2;
  size_t tmp___3;
  char *tmp___4;
  char *numbered_suffix;
  char *__cil_tmp17;
  char *__cil_tmp18;

  {
    {
      tmp = strlen(file);
      file_len = tmp;
      numbered_suffix_size_max =
          (((sizeof(int) * 8UL - 1UL) * 302UL) / 1000UL + 2UL) + 4UL;
      suffix = simple_backup_suffix;
      tmp___0 = strlen(simple_backup_suffix);
      backup_suffix_size_max = tmp___0 + 1UL;
    }

    {
      tmp___1 = malloc(((file_len + 1UL) + backup_suffix_size_max) +
                       numbered_suffix_size_max);
      s = (char *)tmp___1;
    }

    return (s);
  }
}

static int version_number(char const *base, char const *backup,
                          size_t base_length) {
  int version;
  char const *p;
  int tmp;

  {
    {
      version = 0;
      tmp = strncmp(base, backup, base_length);
    }

    return (version);
  }
}

static enum backup_type const backup_types[8] = {
    (enum backup_type const)0, (enum backup_type const)0,
    (enum backup_type const)1, (enum backup_type const)1,
    (enum backup_type const)2, (enum backup_type const)2,
    (enum backup_type const)3, (enum backup_type const)3};

/* #pragma merger("0","014.basename.o.i","") */
char *base_name(char const *name) {
  char const *base;
  char const *p;

  {
    base = name + 0;
    p = base;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!*p) {
          goto while_break;
        }
        if ((int const) * p == 47) {
          {
            while (1) {
            while_continue___0: /* CIL Label */
                ;
              p++;
              if (!((int const) * p == 47)) {
                goto while_break___0;
              }
            }
          while_break___0: /* CIL Label */
              ;
          }
          if (!*p) {
            if ((int const) * base == 47) {
              base = p - 1;
            }
            goto while_break;
          }
          base = p;
        }
        p++;
      }
    while_break: /* CIL Label */
        ;
    }
    return ((char *)base);
  }
}
size_t base_len(char const *name) {
  size_t len;

  {
    { len = strlen(name); }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (1UL < len) {
          if (!((int const) * (name + (len - 1UL)) == 47)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        goto __Cont;
      __Cont:
        len--;
      }
    while_break: /* CIL Label */
        ;
    }
    return (len);
  }
}
/* #pragma merger("0","015.dirname.o.i","") */
size_t dir_len(char const *path) {
  size_t prefix_length;
  size_t length;
  char *tmp;

  {
    {
      prefix_length = (size_t)0;
      tmp = base_name(path);
      length = (size_t)(tmp - (char *)path);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(prefix_length < length)) {
          goto while_break;
        }
        if (!((int const) * (path + (length - 1UL)) == 47)) {
          return (length);
        }
        length--;
      }
    while_break: /* CIL Label */
        ;
    }
    return (prefix_length +
            (size_t)((int const) * (path + prefix_length) == 47));
  }
}
char *dir_name(char const *path) {
  size_t length;
  size_t tmp;
  int append_dot;
  char *newpath;
  void *tmp___0;
  size_t tmp___1;

  {
    {
      tmp = dir_len(path);
      length = tmp;
      append_dot = length == 0UL;
      tmp___0 = xmalloc((length + (size_t)append_dot) + 1UL);
      newpath = (char *)tmp___0;
      memcpy((void * /* __restrict  */)newpath,
             (void const * /* __restrict  */)path, length);
    }
    if (append_dot) {
      tmp___1 = length;
      length++;
      *(newpath + tmp___1) = (char)'.';
    }
    *(newpath + length) = (char)0;
    return (newpath);
  }
}
/* #pragma merger("0","016.exclude.o.i","") */
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__)) strcasecmp)(char const *__s1,
                                                             char const *__s2)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2),
                                                       __leaf__)) strncasecmp)(
    char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
void *xzalloc(size_t s);
void *x2realloc(void *p, size_t *pn);
void *x2nrealloc(void *p, size_t *pn, size_t s);

struct exclude *new_exclude(void) {
  struct exclude *tmp;
  void *tmp___0;

  {
    { tmp___0 = xzalloc(sizeof(*tmp)); }
    return ((struct exclude *)tmp___0);
  }
}

_Bool excluded_filename(struct exclude const *ex, char const *f) {
  size_t exclude_count;
  struct patopts const *exclude;
  size_t i;
  _Bool excluded___0;
  char const *pattern;
  int options;
  int (*matcher)(char const *, char const *, int);
  _Bool matched;
  int tmp;
  char const *p;
  int tmp___0;

  {
    exclude_count = (size_t)ex->exclude_count;
    if (exclude_count == 0UL) {
      return ((_Bool)0);
    } else {
      exclude = (struct patopts const *)ex->exclude;
      excluded___0 =
          (_Bool)(!(!((exclude + 0)->options & (int const)(1 << 29))));
      i = (size_t)0;
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if (!(i < exclude_count)) {
            goto while_break;
          }
          pattern = (char const *)(exclude + i)->pattern;
          options = (int)(exclude + i)->options;

          i++;
        }
      while_break: /* CIL Label */
          ;
      }
      return (excluded___0);
    }
  }
}

/* #pragma merger("0","017.exitfail.o.i","") */
int volatile exit_failure = (int volatile)1;
/* #pragma merger("0","018.full-write.o.i","") */
size_t safe_write(int fd, void const *buf, size_t count);
size_t full_write(int fd, void const *buf, size_t count) {
  size_t total;
  char const *ptr;
  size_t n_rw;
  size_t tmp;
  int *tmp___0;

  {
    total = (size_t)0;
    ptr = (char const *)buf;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(count > 0UL)) {
          goto while_break;
        }
        {
          tmp = safe_write(fd, (void const *)ptr, count);
          n_rw = tmp;
        }
        if (n_rw == 0xffffffffffffffffUL) {
          goto while_break;
        }
        if (n_rw == 0UL) {
          {
            tmp___0 = __errno_location();
            *tmp___0 = 28;
          }
          goto while_break;
        }
        total += n_rw;
        ptr += n_rw;
        count -= n_rw;
      }
    while_break: /* CIL Label */
        ;
    }
    return (total);
  }
}
/* #pragma merger("0","019.getdate.o.i","") */
__attribute__((__nothrow__))
time_t(__attribute__((__leaf__)) rpl_mktime)(struct tm *tp);
int gettime(struct timespec *ts);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) toupper)(
    int __c);
static int yyerror(char *s __attribute__((__unused__)));
static int yylex(YYSTYPE *lvalp, parser_control *pc);
static char const yytranslate[275] = {
    (char const)0,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)23, (char const)2,  (char const)2,  (char const)24,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)22, (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)21, (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)2,  (char const)2,  (char const)2,  (char const)2,
    (char const)1,  (char const)3,  (char const)4,  (char const)5,
    (char const)6,  (char const)7,  (char const)8,  (char const)9,
    (char const)10, (char const)11, (char const)12, (char const)13,
    (char const)14, (char const)15, (char const)16, (char const)17,
    (char const)18, (char const)19, (char const)20};
static short const yyr1[66] = {
    (short const)0,  (short const)25, (short const)25, (short const)26,
    (short const)27, (short const)27, (short const)28, (short const)28,
    (short const)28, (short const)28, (short const)28, (short const)28,
    (short const)28, (short const)29, (short const)29, (short const)29,
    (short const)29, (short const)29, (short const)30, (short const)30,
    (short const)31, (short const)31, (short const)31, (short const)32,
    (short const)32, (short const)32, (short const)33, (short const)33,
    (short const)33, (short const)33, (short const)33, (short const)33,
    (short const)33, (short const)33, (short const)33, (short const)34,
    (short const)34, (short const)35, (short const)35, (short const)35,
    (short const)35, (short const)35, (short const)35, (short const)35,
    (short const)35, (short const)35, (short const)35, (short const)35,
    (short const)35, (short const)35, (short const)35, (short const)35,
    (short const)35, (short const)35, (short const)35, (short const)35,
    (short const)35, (short const)36, (short const)36, (short const)37,
    (short const)37, (short const)38, (short const)38, (short const)39,
    (short const)40, (short const)40};
static short const yyr2[66] = {
    (short const)0, (short const)1, (short const)1, (short const)2,
    (short const)0, (short const)2, (short const)1, (short const)1,
    (short const)1, (short const)1, (short const)1, (short const)1,
    (short const)1, (short const)2, (short const)4, (short const)4,
    (short const)6, (short const)6, (short const)1, (short const)2,
    (short const)1, (short const)1, (short const)2, (short const)1,
    (short const)2, (short const)2, (short const)3, (short const)5,
    (short const)3, (short const)3, (short const)3, (short const)2,
    (short const)4, (short const)2, (short const)3, (short const)2,
    (short const)1, (short const)2, (short const)2, (short const)1,
    (short const)2, (short const)2, (short const)1, (short const)2,
    (short const)2, (short const)1, (short const)2, (short const)2,
    (short const)1, (short const)2, (short const)2, (short const)1,
    (short const)2, (short const)2, (short const)2, (short const)2,
    (short const)1, (short const)1, (short const)1, (short const)1,
    (short const)1, (short const)1, (short const)1, (short const)1,
    (short const)0, (short const)1};
static short const yydefact[81] = {
    (short const)4,  (short const)0,  (short const)1,  (short const)2,
    (short const)60, (short const)62, (short const)59, (short const)61,
    (short const)3,  (short const)57, (short const)58, (short const)23,
    (short const)45, (short const)21, (short const)48, (short const)18,
    (short const)51, (short const)0,  (short const)42, (short const)56,
    (short const)39, (short const)20, (short const)0,  (short const)63,
    (short const)0,  (short const)0,  (short const)5,  (short const)6,
    (short const)7,  (short const)8,  (short const)10, (short const)9,
    (short const)11, (short const)36, (short const)12, (short const)24,
    (short const)19, (short const)0,  (short const)31, (short const)22,
    (short const)44, (short const)47, (short const)50, (short const)41,
    (short const)53, (short const)38, (short const)25, (short const)43,
    (short const)46, (short const)13, (short const)49, (short const)33,
    (short const)40, (short const)52, (short const)37, (short const)0,
    (short const)0,  (short const)0,  (short const)54, (short const)55,
    (short const)35, (short const)30, (short const)0,  (short const)29,
    (short const)34, (short const)28, (short const)64, (short const)26,
    (short const)32, (short const)65, (short const)15, (short const)0,
    (short const)14, (short const)0,  (short const)64, (short const)27,
    (short const)17, (short const)16, (short const)0,  (short const)0,
    (short const)0};
static short const yydefgoto[16] = {
    (short const)78, (short const)2,  (short const)3,  (short const)26,
    (short const)27, (short const)28, (short const)29, (short const)30,
    (short const)31, (short const)32, (short const)33, (short const)8,
    (short const)9,  (short const)10, (short const)34, (short const)72};
static short const yypact[81] = {
    (short const) - 19,    (short const)29,       (short const) - 32768,
    (short const)15,       (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 8,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const)36,       (short const) - 32768, (short const) - 4,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const)38,       (short const)30,       (short const) - 5,
    (short const)39,       (short const)40,       (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const)49,       (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const)41,       (short const)32,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const)33,       (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const)42,       (short const)43,
    (short const)44,       (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const)45,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 6,     (short const)46,       (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const)19,
    (short const) - 32768, (short const)47,       (short const)8,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const)56,       (short const)57,       (short const) - 32768};
static short const yypgoto[16] = {
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 32768, (short const) - 32768,
    (short const) - 32768, (short const) - 11,    (short const) - 32768,
    (short const) - 10};
static short const yytable[71] = {
    (short const)46, (short const)47, (short const)1,  (short const)48,
    (short const)69, (short const)49, (short const)50, (short const)51,
    (short const)52, (short const)53, (short const)54, (short const)70,
    (short const)55, (short const)37, (short const)38, (short const)35,
    (short const)71, (short const)56, (short const)69, (short const)57,
    (short const)11, (short const)12, (short const)13, (short const)14,
    (short const)15, (short const)76, (short const)16, (short const)17,
    (short const)18, (short const)19, (short const)20, (short const)21,
    (short const)22, (short const)23, (short const)24, (short const)25,
    (short const)40, (short const)5,  (short const)41, (short const)7,
    (short const)36, (short const)42, (short const)39, (short const)43,
    (short const)44, (short const)45, (short const)4,  (short const)5,
    (short const)6,  (short const)7,  (short const)63, (short const)64,
    (short const)60, (short const)58, (short const)59, (short const)62,
    (short const)79, (short const)80, (short const)61, (short const)65,
    (short const)74, (short const)66, (short const)67, (short const)68,
    (short const)77, (short const)75, (short const)0,  (short const)0,
    (short const)0,  (short const)0,  (short const)73};
static short const yycheck[71] = {
    (short const)5,    (short const)6,    (short const)21,   (short const)8,
    (short const)10,   (short const)10,   (short const)11,   (short const)12,
    (short const)13,   (short const)14,   (short const)15,   (short const)17,
    (short const)17,   (short const)17,   (short const)18,   (short const)23,
    (short const)22,   (short const)22,   (short const)10,   (short const)24,
    (short const)5,    (short const)6,    (short const)7,    (short const)8,
    (short const)9,    (short const)17,   (short const)11,   (short const)12,
    (short const)13,   (short const)14,   (short const)15,   (short const)16,
    (short const)17,   (short const)18,   (short const)19,   (short const)20,
    (short const)6,    (short const)18,   (short const)8,    (short const)20,
    (short const)4,    (short const)11,   (short const)4,    (short const)13,
    (short const)14,   (short const)15,   (short const)17,   (short const)18,
    (short const)19,   (short const)20,   (short const)17,   (short const)18,
    (short const)3,    (short const)14,   (short const)14,   (short const)23,
    (short const)0,    (short const)0,    (short const)17,   (short const)17,
    (short const)71,   (short const)18,   (short const)18,   (short const)18,
    (short const)74,   (short const)18,   (short const) - 1, (short const) - 1,
    (short const) - 1, (short const) - 1, (short const)24};
int yyparse(void *parm);
int yyparse(void *parm) {
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;
  int yychar1;
  short yyssa[200];
  YYSTYPE yyvsa[200];
  short *yyss;
  YYSTYPE *yyvs;
  int yystacksize;
  int yyfree_stacks;
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
  YYSTYPE yyval;
  int yylen;
  YYSTYPE *yyvs1;
  short *yyss1;
  int size;
  void *tmp;
  void *tmp___0;
  int tmp___1;
  long tmp___2;
  void *__cil_tmp26;
  void *__cil_tmp27;
  int __cil_tmp28;
  char *__cil_tmp29;
  char *__cil_tmp30;

  {
    yychar1 = 0;
    yyss = yyssa;
    yyvs = yyvsa;
    yystacksize = 200;
    yyfree_stacks = 0;
    yystate = 0;
    yyerrstatus = 0;
    yynerrs = 0;
    yychar = -2;
    yyssp = yyss - 1;
    yyvsp = yyvs;
  yynewstate:
    yyssp++;
    *yyssp = (short)yystate;
    if ((unsigned long)yyssp >= (unsigned long)((yyss + yystacksize) - 1)) {
      yyvs1 = yyvs;
      yyss1 = yyss;
      size = (int)((yyssp - yyss) + 1L);
      if (yystacksize >= 10000) {
        {
          yyerror((char *)"parser stack overflow");
        }

        return (2);
      }
      yystacksize *= 2;

      {
        tmp = __builtin_alloca((unsigned long)yystacksize * sizeof(*yyssp));
        yyss = (short *)tmp;
        __builtin_memcpy(
            (void *)((char *)yyss), (void const *)((char *)yyss1),
            (unsigned long)((unsigned int)size * (unsigned int)sizeof(*yyssp)));
        tmp___0 = __builtin_alloca((unsigned long)yystacksize * sizeof(*yyvsp));
        yyvs = (YYSTYPE *)tmp___0;
        __builtin_memcpy(
            (void *)((char *)yyvs), (void const *)((char *)yyvs1),
            (unsigned long)((unsigned int)size * (unsigned int)sizeof(*yyvsp)));
        yyssp = (yyss + size) - 1;
        yyvsp = (yyvs + size) - 1;
      }
      if ((unsigned long)yyssp >= (unsigned long)((yyss + yystacksize) - 1)) {
        goto yyabortlab;
      }
    }
    goto yybackup;
  yybackup:
    yyn = (int)yypact[yystate];
    if (yyn == -32768) {
      goto yydefault;
    }
    if (yychar == -2) {
      {
        yychar = yylex(&yylval, (parser_control *)parm);
      }
    }
    if (yychar <= 0) {
      yychar1 = 0;
      yychar = 0;
    } else {
      if ((unsigned int)yychar <= 274U) {
        tmp___1 = (int const)yytranslate[yychar];
      } else {
        tmp___1 = (int const)41;
      }
      yychar1 = (int)tmp___1;
    }
    yyn += yychar1;
    if (yyn < 0) {
      goto yydefault;
    } else {
    }
    yyn = (int)yytable[yyn];
    if (yyn < 0) {
      if (yyn == -32768) {
        goto yyerrlab;
      }
      yyn = -yyn;
      goto yyreduce;
    } else {
      if (yyn == 0) {
        goto yyerrlab;
      }
    }
    if (yyn == 80) {
      goto yyacceptlab;
    }
    if (yychar != 0) {
      yychar = -2;
    }
    yyvsp++;
    *yyvsp = yylval;
    if (yyerrstatus) {
      yyerrstatus--;
    }
    yystate = yyn;
    goto yynewstate;
  yydefault:
    yyn = (int)yydefact[yystate];
    if (yyn == 0) {
      goto yyerrlab;
    }
  yyreduce:
    yylen = (int)yyr2[yyn];
    if (yylen > 0) {
      yyval = *(yyvsp + (1 - yylen));
    }
    {
      if (yyn == 3) {
        goto case_3;
      }

      if (yyn == 7) {
        goto case_7;
      }
      if (yyn == 8) {
        goto case_8;
      }
      if (yyn == 9) {
        goto case_9;
      }
      if (yyn == 10) {
        goto case_10;
      }
      if (yyn == 11) {
        goto case_11;
      }
      if (yyn == 13) {
        goto case_13;
      }
      if (yyn == 14) {
        goto case_14;
      }
      if (yyn == 15) {
        goto case_15;
      }
      if (yyn == 16) {
        goto case_16;
      }
      if (yyn == 17) {
        goto case_17;
      }
      if (yyn == 18) {
        goto case_18;
      }
      if (yyn == 19) {
        goto case_19;
      }
      if (yyn == 20) {
        goto case_20;
      }
      if (yyn == 21) {
        goto case_21;
      }
      if (yyn == 22) {
        goto case_22;
      }
      if (yyn == 23) {
        goto case_23;
      }
      if (yyn == 24) {
        goto case_24;
      }
      if (yyn == 25) {
        goto case_25;
      }
      if (yyn == 26) {
        goto case_26;
      }
      if (yyn == 27) {
        goto case_27;
      }
      if (yyn == 28) {
        goto case_28;
      }

      if (yyn == 30) {
        goto case_30;
      }
      if (yyn == 31) {
        goto case_31;
      }
      if (yyn == 32) {
        goto case_32;
      }
      if (yyn == 33) {
        goto case_33;
      }
      if (yyn == 34) {
        goto case_34;
      }
      if (yyn == 35) {
        goto case_35;
      }
      if (yyn == 37) {
        goto case_37;
      }
      if (yyn == 38) {
        goto case_38;
      }

      if (yyn == 40) {
        goto case_40;
      }
      if (yyn == 41) {
        goto case_41;
      }
      if (yyn == 42) {
        goto case_42;
      }
      if (yyn == 43) {
        goto case_43;
      }
      if (yyn == 44) {
        goto case_44;
      }
      if (yyn == 45) {
        goto case_45;
      }
      if (yyn == 46) {
        goto case_46;
      }
      if (yyn == 47) {
        goto case_47;
      }
      if (yyn == 48) {
        goto case_48;
      }
      if (yyn == 49) {
        goto case_49;
      }
      if (yyn == 50) {
        goto case_50;
      }
      if (yyn == 51) {
        goto case_51;
      }

      if (yyn == 53) {
        goto case_53;
      }

      if (yyn == 55) {
        goto case_55;
      }
      if (yyn == 56) {
        goto case_56;
      }
      if (yyn == 60) {
        goto case_60;
      }

      if (yyn == 64) {
        goto case_64;
      }
      if (yyn == 65) {
        goto case_65;
      }
      goto switch_break;
    case_3: /* CIL Label */
      ((parser_control *)parm)->seconds = (yyvsp + 0)->timespec;
      ((parser_control *)parm)->timespec_seen = (_Bool)1;
      goto switch_break;
    case_6: /* CIL Label */
      (((parser_control *)parm)->times_seen)++;
      goto switch_break;
    case_7: /* CIL Label */
      (((parser_control *)parm)->local_zones_seen)++;
      goto switch_break;
    case_8: /* CIL Label */
      (((parser_control *)parm)->zones_seen)++;
      goto switch_break;
    case_9: /* CIL Label */
      (((parser_control *)parm)->dates_seen)++;
      goto switch_break;
    case_10: /* CIL Label */
      (((parser_control *)parm)->days_seen)++;
      goto switch_break;
    case_11: /* CIL Label */
      (((parser_control *)parm)->rels_seen)++;
      goto switch_break;
    case_13: /* CIL Label */
      ((parser_control *)parm)->hour = (yyvsp + -1)->textintval.value;
      ((parser_control *)parm)->minutes = 0L;
      ((parser_control *)parm)->seconds.tv_sec = (__time_t)0;
      ((parser_control *)parm)->seconds.tv_nsec = (__syscall_slong_t)0;
      ((parser_control *)parm)->meridian = (int)(yyvsp + 0)->intval;
      goto switch_break;
    case_14: /* CIL Label */
      ((parser_control *)parm)->hour = (yyvsp + -3)->textintval.value;
      ((parser_control *)parm)->minutes = (yyvsp + -1)->textintval.value;
      ((parser_control *)parm)->seconds.tv_sec = (__time_t)0;
      ((parser_control *)parm)->seconds.tv_nsec = (__syscall_slong_t)0;
      ((parser_control *)parm)->meridian = (int)(yyvsp + 0)->intval;
      goto switch_break;
    case_15: /* CIL Label */
      ((parser_control *)parm)->hour = (yyvsp + -3)->textintval.value;
      ((parser_control *)parm)->minutes = (yyvsp + -1)->textintval.value;
      ((parser_control *)parm)->seconds.tv_sec = (__time_t)0;
      ((parser_control *)parm)->seconds.tv_nsec = (__syscall_slong_t)0;
      ((parser_control *)parm)->meridian = 2;
      (((parser_control *)parm)->zones_seen)++;
      ((parser_control *)parm)->time_zone =
          (yyvsp + 0)->textintval.value % 100L +
          ((yyvsp + 0)->textintval.value / 100L) * 60L;
      goto switch_break;
    case_16: /* CIL Label */
      ((parser_control *)parm)->hour = (yyvsp + -5)->textintval.value;
      ((parser_control *)parm)->minutes = (yyvsp + -3)->textintval.value;
      ((parser_control *)parm)->seconds = (yyvsp + -1)->timespec;
      ((parser_control *)parm)->meridian = (int)(yyvsp + 0)->intval;
      goto switch_break;
    case_17: /* CIL Label */
      ((parser_control *)parm)->hour = (yyvsp + -5)->textintval.value;
      ((parser_control *)parm)->minutes = (yyvsp + -3)->textintval.value;
      ((parser_control *)parm)->seconds = (yyvsp + -1)->timespec;
      ((parser_control *)parm)->meridian = 2;
      (((parser_control *)parm)->zones_seen)++;
      ((parser_control *)parm)->time_zone =
          (yyvsp + 0)->textintval.value % 100L +
          ((yyvsp + 0)->textintval.value / 100L) * 60L;
      goto switch_break;
    case_18: /* CIL Label */
      ((parser_control *)parm)->local_isdst = (int)(yyvsp + 0)->intval;
      goto switch_break;
    case_19: /* CIL Label */
      if ((yyvsp + -1)->intval < 0L) {
        tmp___2 = 1L;
      } else {
        tmp___2 = (yyvsp + -1)->intval + 1L;
      }
      ((parser_control *)parm)->local_isdst = (int)tmp___2;
      goto switch_break;
    case_20: /* CIL Label */
      ((parser_control *)parm)->time_zone = (yyvsp + 0)->intval;
      goto switch_break;
    case_21: /* CIL Label */
      ((parser_control *)parm)->time_zone = (yyvsp + 0)->intval + 60L;
      goto switch_break;
    case_22: /* CIL Label */
      ((parser_control *)parm)->time_zone = (yyvsp + -1)->intval + 60L;
      goto switch_break;
    case_23: /* CIL Label */
      ((parser_control *)parm)->day_ordinal = 1L;
      ((parser_control *)parm)->day_number = (int)(yyvsp + 0)->intval;
      goto switch_break;
    case_24: /* CIL Label */
      ((parser_control *)parm)->day_ordinal = 1L;
      ((parser_control *)parm)->day_number = (int)(yyvsp + -1)->intval;
      goto switch_break;
    case_25: /* CIL Label */
      ((parser_control *)parm)->day_ordinal = (yyvsp + -1)->textintval.value;
      ((parser_control *)parm)->day_number = (int)(yyvsp + 0)->intval;
      goto switch_break;
    case_26: /* CIL Label */
      ((parser_control *)parm)->month = (yyvsp + -2)->textintval.value;
      ((parser_control *)parm)->day = (yyvsp + 0)->textintval.value;
      goto switch_break;
    case_27: /* CIL Label */
      if (4UL <= (yyvsp + -4)->textintval.digits) {
        ((parser_control *)parm)->year = (yyvsp + -4)->textintval;
        ((parser_control *)parm)->month = (yyvsp + -2)->textintval.value;
        ((parser_control *)parm)->day = (yyvsp + 0)->textintval.value;
      } else {
        ((parser_control *)parm)->month = (yyvsp + -4)->textintval.value;
        ((parser_control *)parm)->day = (yyvsp + -2)->textintval.value;
        ((parser_control *)parm)->year = (yyvsp + 0)->textintval;
      }
      goto switch_break;
    case_28: /* CIL Label */
      ((parser_control *)parm)->year = (yyvsp + -2)->textintval;
      ((parser_control *)parm)->month = -(yyvsp + -1)->textintval.value;
      ((parser_control *)parm)->day = -(yyvsp + 0)->textintval.value;
      goto switch_break;
    case_29: /* CIL Label */
      ((parser_control *)parm)->day = (yyvsp + -2)->textintval.value;
      ((parser_control *)parm)->month = (yyvsp + -1)->intval;
      ((parser_control *)parm)->year.value = -(yyvsp + 0)->textintval.value;
      ((parser_control *)parm)->year.digits = (yyvsp + 0)->textintval.digits;
      goto switch_break;
    case_30: /* CIL Label */
      ((parser_control *)parm)->month = (yyvsp + -2)->intval;
      ((parser_control *)parm)->day = -(yyvsp + -1)->textintval.value;
      ((parser_control *)parm)->year.value = -(yyvsp + 0)->textintval.value;
      ((parser_control *)parm)->year.digits = (yyvsp + 0)->textintval.digits;
      goto switch_break;
    case_31: /* CIL Label */
      ((parser_control *)parm)->month = (yyvsp + -1)->intval;
      ((parser_control *)parm)->day = (yyvsp + 0)->textintval.value;
      goto switch_break;
    case_32: /* CIL Label */
      ((parser_control *)parm)->month = (yyvsp + -3)->intval;
      ((parser_control *)parm)->day = (yyvsp + -2)->textintval.value;
      ((parser_control *)parm)->year = (yyvsp + 0)->textintval;
      goto switch_break;
    case_33: /* CIL Label */
      ((parser_control *)parm)->day = (yyvsp + -1)->textintval.value;
      ((parser_control *)parm)->month = (yyvsp + 0)->intval;
      goto switch_break;
    case_34: /* CIL Label */
      ((parser_control *)parm)->day = (yyvsp + -2)->textintval.value;
      ((parser_control *)parm)->month = (yyvsp + -1)->intval;
      ((parser_control *)parm)->year = (yyvsp + 0)->textintval;
      goto switch_break;
    case_35: /* CIL Label */
      ((parser_control *)parm)->rel_ns = -((parser_control *)parm)->rel_ns;
      ((parser_control *)parm)->rel_seconds =
          -((parser_control *)parm)->rel_seconds;
      ((parser_control *)parm)->rel_minutes =
          -((parser_control *)parm)->rel_minutes;
      ((parser_control *)parm)->rel_hour = -((parser_control *)parm)->rel_hour;
      ((parser_control *)parm)->rel_day = -((parser_control *)parm)->rel_day;
      ((parser_control *)parm)->rel_month =
          -((parser_control *)parm)->rel_month;
      ((parser_control *)parm)->rel_year = -((parser_control *)parm)->rel_year;
      goto switch_break;
    case_37: /* CIL Label */
      ((parser_control *)parm)->rel_year +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_38: /* CIL Label */
      ((parser_control *)parm)->rel_year +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_39: /* CIL Label */
      ((parser_control *)parm)->rel_year += (yyvsp + 0)->intval;
      goto switch_break;
    case_40: /* CIL Label */
      ((parser_control *)parm)->rel_month +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_41: /* CIL Label */
      ((parser_control *)parm)->rel_month +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_42: /* CIL Label */
      ((parser_control *)parm)->rel_month += (yyvsp + 0)->intval;
      goto switch_break;
    case_43: /* CIL Label */
      ((parser_control *)parm)->rel_day +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_44: /* CIL Label */
      ((parser_control *)parm)->rel_day +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_45: /* CIL Label */
      ((parser_control *)parm)->rel_day += (yyvsp + 0)->intval;
      goto switch_break;
    case_46: /* CIL Label */
      ((parser_control *)parm)->rel_hour +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_47: /* CIL Label */
      ((parser_control *)parm)->rel_hour +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_48: /* CIL Label */
      ((parser_control *)parm)->rel_hour += (yyvsp + 0)->intval;
      goto switch_break;
    case_49: /* CIL Label */
      ((parser_control *)parm)->rel_minutes +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_50: /* CIL Label */
      ((parser_control *)parm)->rel_minutes +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_51: /* CIL Label */
      ((parser_control *)parm)->rel_minutes += (yyvsp + 0)->intval;
      goto switch_break;
    case_52: /* CIL Label */
      ((parser_control *)parm)->rel_seconds +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_53: /* CIL Label */
      ((parser_control *)parm)->rel_seconds +=
          (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
      goto switch_break;
    case_54: /* CIL Label */
      ((parser_control *)parm)->rel_seconds +=
          (yyvsp + -1)->timespec.tv_sec * (yyvsp + 0)->intval;
      ((parser_control *)parm)->rel_ns +=
          (yyvsp + -1)->timespec.tv_nsec * (yyvsp + 0)->intval;
      goto switch_break;
    case_55: /* CIL Label */
      ((parser_control *)parm)->rel_seconds +=
          (yyvsp + -1)->timespec.tv_sec * (yyvsp + 0)->intval;
      ((parser_control *)parm)->rel_ns +=
          (yyvsp + -1)->timespec.tv_nsec * (yyvsp + 0)->intval;
      goto switch_break;
    case_56: /* CIL Label */
      ((parser_control *)parm)->rel_seconds += (yyvsp + 0)->intval;
      goto switch_break;
    case_60: /* CIL Label */
      yyval.timespec.tv_sec = (yyvsp + 0)->textintval.value;
      yyval.timespec.tv_nsec = (__syscall_slong_t)0;
      goto switch_break;
    case_62: /* CIL Label */
      yyval.timespec.tv_sec = (yyvsp + 0)->textintval.value;
      yyval.timespec.tv_nsec = (__syscall_slong_t)0;
      goto switch_break;
    case_63: /* CIL Label */
      if (((parser_control *)parm)->dates_seen) {
        if (!((parser_control *)parm)->rels_seen) {
          if (((parser_control *)parm)->times_seen) {
            ((parser_control *)parm)->year = (yyvsp + 0)->textintval;
          } else {
          }
        } else {
          goto _L___4;
        }
      } else {
      _L___4: /* CIL Label */
        if (4UL < (yyvsp + 0)->textintval.digits) {
          (((parser_control *)parm)->dates_seen)++;
          ((parser_control *)parm)->day = (yyvsp + 0)->textintval.value % 100L;
          ((parser_control *)parm)->month =
              ((yyvsp + 0)->textintval.value / 100L) % 100L;
          ((parser_control *)parm)->year.value =
              (yyvsp + 0)->textintval.value / 10000L;
          ((parser_control *)parm)->year.digits =
              (yyvsp + 0)->textintval.digits - 4UL;
        } else {
          (((parser_control *)parm)->times_seen)++;
          if ((yyvsp + 0)->textintval.digits <= 2UL) {
            ((parser_control *)parm)->hour = (yyvsp + 0)->textintval.value;
            ((parser_control *)parm)->minutes = 0L;
          } else {
            ((parser_control *)parm)->hour =
                (yyvsp + 0)->textintval.value / 100L;
            ((parser_control *)parm)->minutes =
                (yyvsp + 0)->textintval.value % 100L;
          }
          ((parser_control *)parm)->seconds.tv_sec = (__time_t)0;
          ((parser_control *)parm)->seconds.tv_nsec = (__syscall_slong_t)0;
          ((parser_control *)parm)->meridian = 2;
        }
      }
      goto switch_break;
    case_64: /* CIL Label */
      yyval.intval = 2L;
      goto switch_break;
    case_65: /* CIL Label */
      yyval.intval = (yyvsp + 0)->intval;
      goto switch_break;
    switch_break: /* CIL Label */
        ;
    }
    yyvsp -= yylen;
    yyssp -= yylen;
    yyvsp++;
    *yyvsp = yyval;
    yyn = (int)yyr1[yyn];
    yystate = (int)((int const)yypgoto[yyn - 25] + (int const) * yyssp);
    if (yystate >= 0) {
      if (yystate <= 70) {
        if ((int const)yycheck[yystate] == (int const) * yyssp) {
          yystate = (int)yytable[yystate];
        } else {
          yystate = (int)yydefgoto[yyn - 25];
        }
      } else {
        yystate = (int)yydefgoto[yyn - 25];
      }
    } else {
      yystate = (int)yydefgoto[yyn - 25];
    }
    goto yynewstate;
  yyerrlab:
    if (!yyerrstatus) {
      {
        yynerrs++;
        yyerror((char *)"parse error");
      }
    }
    goto yyerrlab1;
  yyerrlab1:
    if (yyerrstatus == 3) {
      if (yychar == 0) {
        goto yyabortlab;
      }
      yychar = -2;
    }
    yyerrstatus = 3;
    goto yyerrhandle;
  yyerrdefault:

    yyvsp--;
    yyssp--;
    yystate = (int)*yyssp;
  yyerrhandle:
    yyn = (int)yypact[yystate];
    if (yyn == -32768) {
      goto yyerrdefault;
    }
    yyn++;
    if (yyn < 0) {
      goto yyerrdefault;
    } else {
      if (yyn > 70) {
        goto yyerrdefault;
      } else {
        if ((int const)yycheck[yyn] != 1) {
          goto yyerrdefault;
        }
      }
    }
    yyn = (int)yytable[yyn];

    if (yyn == 80) {
      goto yyacceptlab;
    }
    yyvsp++;
    *yyvsp = yylval;
    yystate = yyn;
    goto yynewstate;
  yyacceptlab:

    return (0);
  yyabortlab:
    if (yyfree_stacks) {
      {
        free((void *)yyss);
        free((void *)yyvs);
      }
    }
    return (1);
  }
}
static table const meridian_table[5] = {{"AM", 264, 0},
                                        {"A.M.", 264, 0},
                                        {"PM", 264, 1},
                                        {"P.M.", 264, 1},
                                        {(char const *)0, 0, 0}};
static table const dst_table[1] = {{"DST", 258, 0}};

static table const time_units_table[11] = {
    {"YEAR", 269, 1},   {"MONTH", 267, 1},      {"FORTNIGHT", 260, 14},
    {"WEEK", 260, 7},   {"DAY", 260, 1},        {"HOUR", 262, 1},
    {"MINUTE", 265, 1}, {"MIN", 265, 1},        {"SECOND", 268, 1},
    {"SEC", 268, 1},    {(char const *)0, 0, 0}};
static table const relative_time_table[20] = {
    {"TOMORROW", 260, 1}, {"YESTERDAY", 260, -1}, {"TODAY", 260, 0},
    {"NOW", 260, 0},      {"LAST", 272, -1},      {"THIS", 272, 0},
    {"NEXT", 272, 1},     {"FIRST", 272, 1},      {"THIRD", 272, 3},
    {"FOURTH", 272, 4},   {"FIFTH", 272, 5},      {"SIXTH", 272, 6},
    {"SEVENTH", 272, 7},  {"EIGHTH", 272, 8},     {"NINTH", 272, 9},
    {"TENTH", 272, 10},   {"ELEVENTH", 272, 11},  {"TWELFTH", 272, 12},
    {"AGO", 257, 1},      {(char const *)0, 0, 0}};
static table const time_zone_table[51] = {
    {"GMT", 270, 0},     {"UT", 270, 0},     {"UTC", 270, 0},
    {"WET", 270, 0},     {"WEST", 261, 0},   {"BST", 261, 0},
    {"ART", 270, -180},  {"BRT", 270, -180}, {"BRST", 261, -180},
    {"NST", 270, -210},  {"NDT", 261, -210}, {"AST", 270, -240},
    {"ADT", 261, -240},  {"CLT", 270, -240}, {"CLST", 261, -240},
    {"EST", 270, -300},  {"EDT", 261, -300}, {"CST", 270, -360},
    {"CDT", 261, -360},  {"MST", 270, -420}, {"MDT", 261, -420},
    {"PST", 270, -480},  {"PDT", 261, -480}, {"AKST", 270, -540},
    {"AKDT", 261, -540}, {"HST", 270, -600}, {"HAST", 270, -600},
    {"HADT", 261, -600}, {"SST", 270, -720}, {"WAT", 270, 60},
    {"CET", 270, 60},    {"CEST", 261, 60},  {"MET", 270, 60},
    {"MEZ", 270, 60},    {"MEST", 261, 60},  {"MESZ", 261, 60},
    {"EET", 270, 120},   {"EEST", 261, 120}, {"CAT", 270, 120},
    {"SAST", 270, 120},  {"EAT", 270, 180},  {"MSK", 270, 180},
    {"MSD", 261, 180},   {"IST", 270, 330},  {"SGT", 270, 480},
    {"KST", 270, 540},   {"JST", 270, 540},  {"GST", 270, 600},
    {"NZST", 270, 720},  {"NZDT", 261, 720}, {(char const *)0, 0, 0}};

static int yylex(YYSTYPE *lvalp, parser_control *pc) {
  unsigned char c;
  size_t count;
  unsigned short const **tmp;
  char const *p;
  int sign;
  unsigned long value;
  unsigned long value1;
  time_t s;
  int ns;
  int digits;
  unsigned long value1___0;
  char const *tmp___0;
  char const *tmp___1;
  char buff[20];
  char *p___0;
  table const *tp;
  char *tmp___2;
  unsigned short const **tmp___3;
  unsigned short const **tmp___4;
  char const *tmp___5;
  char const *tmp___6;
  int tmp___7;
  int tmp___8;
  void *__cil_tmp26;

  {
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            {
              c = (unsigned char)*(pc->input);
              tmp = __ctype_b_loc();
            }
            if (!(((int const) * (*tmp + (int)c) & 8192) != 0)) {
              goto while_break___0;
            }
            (pc->input)++;
          }
        while_break___0: /* CIL Label */
            ;
        }
        if ((unsigned int)c - 48U <= 9U) {
          goto _L___6;
        } else {
          if ((int)c == 45) {
            goto _L___6;
          } else {
            if ((int)c == 43) {
            _L___6: /* CIL Label */
              if ((int)c == 45) {
                goto _L___3;
              } else {
                if ((int)c == 43) {
                _L___3: /* CIL Label */
                  if ((int)c == 45) {
                    sign = -1;
                  } else {
                    sign = 1;
                  }
                  (pc->input)++;
                  c = (unsigned char)*(pc->input);
                  if (!((unsigned int)c - 48U <= 9U)) {
                    goto __Cont;
                  }
                } else {
                  sign = 0;
                }
              }
              p = pc->input;
              value = 0UL;
              {
                while (1) {
                while_continue___1: /* CIL Label */
                    ;
                  value1 = value + (unsigned long)((int)c - 48);
                  if (value1 < value) {
                    return ('?');
                  }
                  value = value1;
                  p++;
                  c = (unsigned char)*p;
                  if (!((unsigned int)c - 48U <= 9U)) {
                    goto while_break___1;
                  }
                  if (1844674407370955161UL < value) {
                    return ('?');
                  }
                  value *= 10UL;
                }
              while_break___1: /* CIL Label */
                  ;
              }
              if ((int)c == 46) {
                goto _L___5;
              } else {
                if ((int)c == 44) {
                _L___5: /* CIL Label */
                  if ((unsigned int)*(p + 1) - 48U <= 9U) {
                    if (sign < 0) {
                      s = (time_t)(-value);
                      if (0L < s) {
                        return ('?');
                      }
                      value1___0 = (unsigned long)(-s);
                    } else {
                      s = (time_t)value;
                      if (s < 0L) {
                        return ('?');
                      }
                      value1___0 = (unsigned long)s;
                    }
                    if (value != value1___0) {
                      return ('?');
                    }
                    p++;
                    tmp___0 = p;
                    p++;
                    ns = (int)((int const) * tmp___0 - 48);
                    digits = 2;
                    {
                      while (1) {
                      while_continue___2: /* CIL Label */
                          ;
                        if (!(digits <= 9)) {
                          goto while_break___2;
                        }
                        ns *= 10;
                        if ((unsigned int)*p - 48U <= 9U) {
                          tmp___1 = p;
                          p++;
                          ns += (int)((int const) * tmp___1 - 48);
                        }
                        digits++;
                      }
                    while_break___2: /* CIL Label */
                        ;
                    }
                    if (sign < 0) {
                      {
                        while (1) {
                        while_continue___3: /* CIL Label */
                            ;
                          if (!((unsigned int)*p - 48U <= 9U)) {
                            goto while_break___3;
                          }
                          if ((int const) * p != 48) {
                            ns++;
                            goto while_break___3;
                          }
                          p++;
                        }
                      while_break___3: /* CIL Label */
                          ;
                      }
                    }
                    {
                      while (1) {
                      while_continue___4: /* CIL Label */
                          ;
                        if (!((unsigned int)*p - 48U <= 9U)) {
                          goto while_break___4;
                        }
                        p++;
                      }
                    while_break___4: /* CIL Label */
                        ;
                    }

                    lvalp->timespec.tv_sec = s;
                    lvalp->timespec.tv_nsec = (__syscall_slong_t)ns;
                    pc->input = p;
                    if (sign) {
                      tmp___7 = 273;
                    } else {
                      tmp___7 = 274;
                    }
                    return (tmp___7);
                  } else {
                    goto _L___4;
                  }
                } else {
                _L___4: /* CIL Label */
                  if (sign < 0) {
                    lvalp->textintval.value = (long)(-value);

                  } else {
                    lvalp->textintval.value = (long)value;
                    if (lvalp->textintval.value < 0L) {
                      return ('?');
                    }
                  }
                  lvalp->textintval.digits = (size_t)(p - pc->input);
                  pc->input = p;
                  if (sign) {
                    tmp___8 = 271;
                  } else {
                    tmp___8 = 272;
                  }
                  return (tmp___8);
                }
              }
            }
          }
        }
        { tmp___4 = __ctype_b_loc(); }
        if ((int const) * (*tmp___4 + (int)c) & 1024) {
          p___0 = buff;
          {
            while (1) {
            while_continue___5: /* CIL Label */
                ;
              if ((unsigned long)p___0 <
                  (unsigned long)((buff + sizeof(buff)) - 1)) {
                tmp___2 = p___0;
                p___0++;
                *tmp___2 = (char)c;
              }
              {
                (pc->input)++;
                c = (unsigned char)*(pc->input);
                tmp___3 = __ctype_b_loc();
              }
            }
          while_break___5: /* CIL Label */
              ;
          }
          {
            *p___0 = (char)'\000';
            tp = lookup_word((parser_control const *)pc, buff);
          }
          if (!tp) {
            return ('?');
          }
          lvalp->intval = (long)tp->value;
          return ((int)tp->type);
        }
        if ((int)c != 40) {
          tmp___5 = pc->input;
          (pc->input)++;
          return ((int)*tmp___5);
        }
        count = (size_t)0;
        {
          while (1) {
          while_continue___6: /* CIL Label */
              ;
            tmp___6 = pc->input;
            (pc->input)++;
            c = (unsigned char)*tmp___6;
            if ((int)c == 0) {
              return ((int)c);
            }

            if (!(count != 0UL)) {
              goto while_break___6;
            }
          }
        while_break___6: /* CIL Label */
            ;
        }
      __Cont:;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
static int yyerror(char *s __attribute__((__unused__))) {

  { return (0); }
}

/* #pragma merger("0","01a.getopt1.o.i","") */
/* #pragma merger("0","01b.getopt.o.i","") */
/* #pragma merger("0","01c.gettime.o.i","") */
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) gettimeofday)(struct timeval *__restrict __tv,
                                             __timezone_ptr_t __tz);
int gettime(struct timespec *ts) {
  int tmp;
  struct timeval tv;
  int r;
  int tmp___0;

  {
    { tmp = clock_gettime(0, ts); }

    {
      tmp___0 = gettimeofday((struct timeval * /* __restrict  */)(&tv),
                             (__timezone_ptr_t)0);
      r = tmp___0;
    }
    if (r == 0) {
      ts->tv_sec = tv.tv_sec;
      ts->tv_nsec = tv.tv_usec * 1000L;
    }
    return (r);
  }
}
/* #pragma merger("0","01d.hash.o.i","") */
_Bool hash_rehash(Hash_table *table___0, size_t candidate);
static struct hash_tuning const default_tuning = {
    (float)0.0, (float)1.0, (float)0.8, (float)1.414, (_Bool)0};
void *hash_lookup(Hash_table const *table___0, void const *entry) {
  struct hash_entry const *bucket;
  size_t tmp;
  struct hash_entry const *cursor;
  _Bool tmp___0;

  {
    {
      tmp = (*(table___0->hasher))(entry, (size_t)table___0->n_buckets);
      bucket = (struct hash_entry const *)(table___0->bucket + tmp);
    }
    if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
      {
        abort();
      }
    }
    if ((unsigned long)bucket->data == (unsigned long)((void *)0)) {
      return ((void *)0);
    }
    cursor = bucket;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!cursor) {
          goto while_break;
        }
        {
          tmp___0 =
              (*(table___0->comparator))(entry, (void const *)cursor->data);
        }
        if (tmp___0) {
          return ((void *)cursor->data);
        }
        cursor = (struct hash_entry const *)cursor->next;
      }
    while_break: /* CIL Label */
        ;
    }
    return ((void *)0);
  }
}
void *hash_get_first(Hash_table const *table___0) {
  struct hash_entry const *bucket;

  {

    bucket = (struct hash_entry const *)table___0->bucket;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
          {
            abort();
          }
        } else {
          if (bucket->data) {
            return ((void *)bucket->data);
          }
        }
        bucket++;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
void *hash_get_next(Hash_table const *table___0, void const *entry) {
  struct hash_entry const *bucket;
  size_t tmp;
  struct hash_entry const *cursor;

  {
    {
      tmp = (*(table___0->hasher))(entry, (size_t)table___0->n_buckets);
      bucket = (struct hash_entry const *)(table___0->bucket + tmp);
    }

    cursor = bucket;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!cursor) {
          goto while_break;
        }
        if ((unsigned long)cursor->data == (unsigned long)entry) {
          if (cursor->next) {
            return ((cursor->next)->data);
          }
        }
        cursor = (struct hash_entry const *)cursor->next;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        bucket++;
        if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
          goto while_break___0;
        }
        if (bucket->data) {
          return ((void *)bucket->data);
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    return ((void *)0);
  }
}
size_t hash_do_for_each(Hash_table const *table___0,
                        _Bool (*processor)(void *, void *),
                        void *processor_data) {
  size_t counter;
  struct hash_entry const *bucket;
  struct hash_entry const *cursor;
  _Bool tmp;

  {
    counter = (size_t)0;
    bucket = (struct hash_entry const *)table___0->bucket;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
          goto while_break;
        }
        if (bucket->data) {
          cursor = bucket;
          {
            while (1) {
            while_continue___0: /* CIL Label */
                ;
              if (!cursor) {
                goto while_break___0;
              }
              { tmp = (*processor)((void *)cursor->data, processor_data); }
              if (!tmp) {
                return (counter);
              }
              counter++;
              cursor = (struct hash_entry const *)cursor->next;
            }
          while_break___0: /* CIL Label */
              ;
          }
        }
        bucket++;
      }
    while_break: /* CIL Label */
        ;
    }
    return (counter);
  }
}
size_t hash_string(char const *string, size_t n_buckets) {
  size_t value;
  char const *tmp;

  {
    value = (size_t)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!*string) {
          goto while_break;
        }
        tmp = string;
        string++;
        value = (value * 31UL + (size_t)((unsigned char)*tmp)) % n_buckets;
      }
    while_break: /* CIL Label */
        ;
    }
    return (value);
  }
}
static _Bool is_prime(size_t candidate) {
  size_t divisor;
  size_t square;
  int tmp;

  {
    divisor = (size_t)3;
    square = divisor * divisor;
    {

    while_break: /* CIL Label */
        ;
    }
    if (candidate % divisor) {
      tmp = 1;
    } else {
      tmp = 0;
    }
    return ((_Bool)tmp);
  }
}
static size_t next_prime(size_t candidate) {
  _Bool tmp;

  {
    if (candidate < 10UL) {
      candidate = (size_t)10;
    }
    candidate |= 1UL;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { tmp = is_prime(candidate); }
        if (tmp) {
          goto while_break;
        }
        candidate += 2UL;
      }
    while_break: /* CIL Label */
        ;
    }
    return (candidate);
  }
}
static _Bool check_tuning(Hash_table *table___0) {
  Hash_tuning const *tuning;
  float epsilon;

  {
    tuning = table___0->tuning;
    epsilon = 0.1f;
    if (epsilon < (float)tuning->growth_threshold) {
      if (tuning->growth_threshold < (float const)((float)1 - epsilon)) {
        if ((float)1 + epsilon < (float)tuning->growth_factor) {
          if ((float const)0 <= tuning->shrink_threshold) {
            if (tuning->shrink_threshold + (float const)epsilon <
                tuning->shrink_factor) {
              if (tuning->shrink_factor <= (float const)1) {
                if (tuning->shrink_threshold + (float const)epsilon <
                    tuning->growth_threshold) {
                  return ((_Bool)1);
                }
              }
            }
          }
        }
      }
    }
    table___0->tuning = &default_tuning;
    return ((_Bool)0);
  }
}
Hash_table *hash_initialize(size_t candidate, Hash_tuning const *tuning,
                            size_t (*hasher)(void const *, size_t),
                            _Bool (*comparator)(void const *, void const *),
                            void (*data_freer)(void *)) {
  Hash_table *table___0;
  void *tmp;
  _Bool tmp___0;
  float new_candidate;
  void *tmp___1;
  int tmp___2;
  int tmp___3;

  {
    if ((unsigned long)hasher == (unsigned long)((void *)0)) {
      return ((Hash_table *)((void *)0));
    } else {
      if ((unsigned long)comparator == (unsigned long)((void *)0)) {
        return ((Hash_table *)((void *)0));
      }
    }
    {
      tmp = malloc(sizeof(*table___0));
      table___0 = (Hash_table *)tmp;
    }
    if ((unsigned long)table___0 == (unsigned long)((void *)0)) {
      return ((Hash_table *)((void *)0));
    }

    {
      table___0->tuning = tuning;
      tmp___0 = check_tuning(table___0);
    }

    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp___2 = -1;
    } else {
      tmp___2 = -2;
    }
    if ((size_t)tmp___2 / sizeof(*(table___0->bucket)) < candidate) {
      goto fail;
    }
    { table___0->n_buckets = next_prime(candidate); }
    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp___3 = -1;
    } else {
      tmp___3 = -2;
    }
    if ((size_t)tmp___3 / sizeof(*(table___0->bucket)) < table___0->n_buckets) {
      goto fail;
    }
    {
      tmp___1 = calloc(table___0->n_buckets, sizeof(*(table___0->bucket)));
      table___0->bucket = (struct hash_entry *)tmp___1;
      table___0->bucket_limit =
          (struct hash_entry const *)(table___0->bucket + table___0->n_buckets);
      table___0->n_buckets_used = (size_t)0;
      table___0->n_entries = (size_t)0;
      table___0->hasher = hasher;
      table___0->comparator = comparator;
      table___0->data_freer = data_freer;
      table___0->free_entry_list = (struct hash_entry *)((void *)0);
    }
    return (table___0);
  fail: { free((void *)table___0); }
    return ((Hash_table *)((void *)0));
  }
}
static struct hash_entry *allocate_entry(Hash_table *table___0) {
  struct hash_entry *new;
  void *tmp;

  {
    if (table___0->free_entry_list) {
      new = table___0->free_entry_list;
      table___0->free_entry_list = new->next;
    } else {
      {
        tmp = malloc(sizeof(*new));
        new = (struct hash_entry *)tmp;
      }
    }
    return (new);
  }
}
static void free_entry(Hash_table *table___0, struct hash_entry *entry) {

  {
    entry->data = (void *)0;
    entry->next = table___0->free_entry_list;
    table___0->free_entry_list = entry;
    return;
  }
}
static void *hash_find_entry(Hash_table *table___0, void const *entry,
                             struct hash_entry **bucket_head, _Bool delete) {
  struct hash_entry *bucket;
  size_t tmp;
  struct hash_entry *cursor;
  void *data;
  struct hash_entry *next;
  _Bool tmp___0;
  void *data___0;
  struct hash_entry *next___0;
  _Bool tmp___1;

  {
    {
      tmp = (*(table___0->hasher))(entry, table___0->n_buckets);
      bucket = table___0->bucket + tmp;
    }
    if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
      {
        abort();
      }
    }
    *bucket_head = bucket;
    if ((unsigned long)bucket->data == (unsigned long)((void *)0)) {
      return ((void *)0);
    }
    { tmp___0 = (*(table___0->comparator))(entry, (void const *)bucket->data); }
    if (tmp___0) {
      data = bucket->data;

      return (data);
    }
    cursor = bucket;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!cursor->next) {
          goto while_break;
        }
        {
          tmp___1 = (*(table___0->comparator))(
              entry, (void const *)(cursor->next)->data);
        }
        if (tmp___1) {
          data___0 = (cursor->next)->data;
          if (delete) {
            {
              next___0 = cursor->next;
              cursor->next = next___0->next;
              free_entry(table___0, next___0);
            }
          }
          return (data___0);
        }
        cursor = cursor->next;
      }
    while_break: /* CIL Label */
        ;
    }
    return ((void *)0);
  }
}

void *hash_insert(Hash_table *table___0, void const *entry) {
  void *data;
  struct hash_entry *bucket;
  struct hash_entry *new_entry;
  struct hash_entry *tmp;
  Hash_tuning const *tuning;
  float candidate;
  _Bool tmp___0;
  float tmp___1;

  {

    { data = hash_find_entry(table___0, entry, &bucket, (_Bool)0); }
    if ((unsigned long)data != (unsigned long)((void *)0)) {
      return (data);
    }
    if (bucket->data) {
      {
        tmp = allocate_entry(table___0);
        new_entry = tmp;
      }
      if ((unsigned long)new_entry == (unsigned long)((void *)0)) {
        return ((void *)0);
      }
      new_entry->data = (void *)entry;
      new_entry->next = bucket->next;
      bucket->next = new_entry;
      (table___0->n_entries)++;
      return ((void *)entry);
    }
    bucket->data = (void *)entry;
    (table___0->n_entries)++;
    (table___0->n_buckets_used)++;
    if ((float const)table___0->n_buckets_used >
        (table___0->tuning)->growth_threshold *
            (float const)table___0->n_buckets) {
      {
        check_tuning(table___0);
      }
    }
    return ((void *)entry);
  }
}
/* #pragma merger("0","01e.human.o.i","") */
extern __attribute__((__nothrow__)) struct lconv *(
    __attribute__((__leaf__)) localeconv)(void);
extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1, 2), __leaf__)) memmove)(void *__dest, void const *__src,
                                           size_t __n);
static char const power_letter[9] = {
    (char const)0,   (char const)'K', (char const)'M',
    (char const)'G', (char const)'T', (char const)'P',
    (char const)'E', (char const)'Z', (char const)'Y'};
static long double adjust_value(int inexact_style, long double value) {
  uintmax_t u;
  int tmp;

  { return (value); }
}

char *human_readable(uintmax_t n, char *buf, int opts,
                     uintmax_t from_block_size, uintmax_t to_block_size) {
  int inexact_style;
  unsigned int base;
  uintmax_t amt;
  int tenths;
  int exponent;
  int exponent_max;
  char *p;
  char *psuffix;
  char const *integerlim;
  int rounding;
  char const *decimal_point;
  size_t decimal_pointlen;
  char const *grouping;
  char const *thousands_sep;
  struct lconv const *l;
  struct lconv *tmp;
  size_t pointlen;
  size_t tmp___0;
  size_t tmp___1;
  uintmax_t multiplier;
  uintmax_t divisor;
  uintmax_t r10;
  uintmax_t r2;
  long double dto_block_size;
  long double damt;
  size_t buflen;
  size_t nonintegerlen;
  long double tmp___2;
  long double e;
  long double tmp___3;
  long double tmp___4;
  unsigned int r10___0;
  unsigned int r2___0;
  int digit;
  uintmax_t power;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  int tmp___11;
  int tmp___12;
  int tmp___13;
  char *__cil_tmp50;
  char *__cil_tmp51;
  char *__cil_tmp52;
  char *__cil_tmp53;
  char *__cil_tmp54;
  char *__cil_tmp55;
  char *__cil_tmp56;

  {
    inexact_style = opts & 3;
    if (opts & 32) {
      tmp___8 = 1024;
    } else {
      tmp___8 = 1000;
    }
    {
      base = (unsigned int)tmp___8;
      exponent = -1;
      exponent_max = (int)(sizeof(power_letter) - 1UL);
      decimal_point = ".";
      decimal_pointlen = (size_t)1;
      grouping = "";
      thousands_sep = "";
      tmp = localeconv();
      l = (struct lconv const *)tmp;
      tmp___0 = strlen((char const *)l->decimal_point);
      pointlen = tmp___0;
    }

    {
      grouping = (char const *)l->grouping;
      tmp___1 = strlen((char const *)l->thousands_sep);
    }

    psuffix =
        (buf +
         ((((((2UL * sizeof(uintmax_t)) * 8UL) * 302UL) / 1000UL + 1UL) * 17UL -
           16UL) +
          3UL)) -
        3;
    p = psuffix;
    if (to_block_size <= from_block_size) {
      if (from_block_size % to_block_size == 0UL) {
        multiplier = from_block_size / to_block_size;
        amt = n * multiplier;
        if (amt / multiplier == n) {
          tenths = 0;
          rounding = 0;
          goto use_integer_arithmetic;
        }
      }
    } else {
      if (from_block_size != 0UL) {
        if (to_block_size % from_block_size == 0UL) {
          divisor = to_block_size / from_block_size;
          r10 = (n % divisor) * 10UL;
          r2 = (r10 % divisor) * 2UL;
          amt = n / divisor;
          tenths = (int)(r10 / divisor);
          if (r2 < divisor) {
            rounding = 0UL < r2;
          } else {
            rounding = 2 + (divisor < r2);
          }
          goto use_integer_arithmetic;
        }
      }
    }
    dto_block_size = (long double)to_block_size;
    damt = (long double)n * ((long double)from_block_size / dto_block_size);
    if (!(opts & 16)) {
      {
        tmp___2 = adjust_value(inexact_style, damt);
        sprintf((char * /* __restrict  */)buf,
                (char const * /* __restrict  */) "%.0Lf", tmp___2);
        buflen = strlen((char const *)buf);
        nonintegerlen = (size_t)0;
      }
    } else {
      e = (long double)1;
      exponent = 0;
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          e *= (long double)base;
          exponent++;
          if (e * (long double)base <= damt) {
            if (!(exponent < exponent_max)) {
              goto while_break;
            }
          } else {
            goto while_break;
          }
        }
      while_break: /* CIL Label */
          ;
      }
      {
        damt /= e;
        tmp___3 = adjust_value(inexact_style, damt);
        sprintf((char * /* __restrict  */)buf,
                (char const * /* __restrict  */) "%.1Lf", tmp___3);
        buflen = strlen((char const *)buf);
        nonintegerlen = decimal_pointlen + 1UL;
      }
      if ((1UL + nonintegerlen) + (size_t)(!(opts & 32)) < buflen) {
        {
          tmp___4 = adjust_value(inexact_style, damt * (long double)10);
          sprintf((char * /* __restrict  */)buf,
                  (char const * /* __restrict  */) "%.0Lf",
                  tmp___4 / (long double)10);
          buflen = strlen((char const *)buf);
          nonintegerlen = (size_t)0;
        }
      } else {
        if (opts & 8) {
        }
      }
    }
    {
      p = psuffix - buflen;
      memmove((void *)p, (void const *)buf, buflen);
      integerlim = (char const *)((p + buflen) - nonintegerlen);
    }
    goto do_grouping;
  use_integer_arithmetic:
    if (opts & 16) {
      exponent = 0;
      if ((uintmax_t)base <= amt) {
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            r10___0 = (unsigned int)((amt % (unsigned long)base) * 10UL +
                                     (unsigned long)tenths);
            r2___0 = (r10___0 % base) * 2U + (unsigned int)(rounding >> 1);
            amt /= (uintmax_t)base;
            tenths = (int)(r10___0 / base);
            if (r2___0 < base) {
              rounding = r2___0 + (unsigned int)rounding != 0U;
            } else {
              rounding = 2 + (base < r2___0 + (unsigned int)rounding);
            }
            exponent++;
            if ((uintmax_t)base <= amt) {
              if (!(exponent < exponent_max)) {
                goto while_break___0;
              }
            } else {
              goto while_break___0;
            }
          }
        while_break___0: /* CIL Label */
            ;
        }
        if (amt < 10UL) {
          if (inexact_style == 1) {
            tmp___10 = 2 < rounding + (tenths & 1);
          } else {

            tmp___10 = tmp___9;
          }
          if (tmp___10) {
            tenths++;
            rounding = 0;
            if (tenths == 10) {
              amt++;
              tenths = 0;
            }
          }
          if (amt < 10UL) {
            if (tenths) {
              goto _L___3;
            } else {
              if (!(opts & 8)) {
              _L___3: { /* CIL Label */
                p--;
                *p = (char)(48 + tenths);
                p -= decimal_pointlen;
                memcpy((void * /* __restrict  */)p,
                       (void const * /* __restrict  */)decimal_point,
                       decimal_pointlen);
                rounding = 0;
                tenths = rounding;
              }
              }
            }
          }
        }
      }
    }
    if (inexact_style == 1) {
      tmp___12 = 5 < tenths + (0UL < (unsigned long)rounding + (amt & 1UL));
    } else {
      if (inexact_style == 0) {
        if (0 < tenths + rounding) {
          tmp___11 = 1;
        } else {
          tmp___11 = 0;
        }
      } else {
        tmp___11 = 0;
      }
      tmp___12 = tmp___11;
    }
    if (tmp___12) {
      amt++;
      if (opts & 16) {
        if (amt == (uintmax_t)base) {
          if (exponent < exponent_max) {
            exponent++;
            if (!(opts & 8)) {
              {
                p--;
                *p = (char)'0';
                p -= decimal_pointlen;
                memcpy((void * /* __restrict  */)p,
                       (void const * /* __restrict  */)decimal_point,
                       decimal_pointlen);
              }
            }
            amt = (uintmax_t)1;
          }
        }
      }
    }
    integerlim = (char const *)p;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        digit = (int)(amt % 10UL);
        p--;
        *p = (char)(digit + 48);
        amt /= 10UL;
        if (!(amt != 0UL)) {
          goto while_break___1;
        }
      }
    while_break___1: /* CIL Label */
        ;
    }
  do_grouping:

    *psuffix = (char)'\000';
    return (p);
  }
}
static char const *const block_size_args[3] = {
    (char const * /* const  */) "human-readable",
    (char const * /* const  */) "si", (char const * /* const  */)0};
static int const block_size_opts[2] = {(int const)112, (int const)80};
/* #pragma merger("0","01f.mktime.o.i","") */
extern __attribute__((__nothrow__)) struct tm *(
    __attribute__((__leaf__)) localtime_r)(time_t const *__restrict __timer,
                                           struct tm *__restrict __tp);
__inline static int leapyear(int year) {
  int tmp;

  { return (tmp); }
}
static unsigned short const __mon_yday[2][13] = {
    {(unsigned short const)0, (unsigned short const)31,
     (unsigned short const)59, (unsigned short const)90,
     (unsigned short const)120, (unsigned short const)151,
     (unsigned short const)181, (unsigned short const)212,
     (unsigned short const)243, (unsigned short const)273,
     (unsigned short const)304, (unsigned short const)334,
     (unsigned short const)365},
    {(unsigned short const)0, (unsigned short const)31,
     (unsigned short const)60, (unsigned short const)91,
     (unsigned short const)121, (unsigned short const)152,
     (unsigned short const)182, (unsigned short const)213,
     (unsigned short const)244, (unsigned short const)274,
     (unsigned short const)305, (unsigned short const)335,
     (unsigned short const)366}};
__inline static time_t ydhms_diff(long year1, long yday1, int hour1, int min1,
                                  int sec1, int year0, int yday0, int hour0,
                                  int min0, int sec0) {
  int a4;
  int b4;
  int a100;
  int b100;
  int a400;
  int b400;
  int intervening_leap_days;
  time_t tyear1;
  time_t years;
  time_t days;
  time_t hours;
  time_t minutes;
  time_t seconds;

  {
    a4 = (int)(((year1 >> 2) + (long)(1900 >> 2)) - (long)(!(year1 & 3L)));
    b4 = ((year0 >> 2) + (1900 >> 2)) - !(year0 & 3);
    a100 = a4 / 25 - (a4 % 25 < 0);
    b100 = b4 / 25 - (b4 % 25 < 0);
    a400 = a100 >> 2;
    b400 = b100 >> 2;
    intervening_leap_days = ((a4 - b4) - (a100 - b100)) + (a400 - b400);
    tyear1 = year1;
    years = tyear1 - (time_t)year0;
    days = ((365L * years + yday1) - (time_t)yday0) +
           (time_t)intervening_leap_days;
    hours = (24L * days + (time_t)hour1) - (time_t)hour0;
    minutes = (60L * hours + (time_t)min1) - (time_t)min0;
    seconds = (60L * minutes + (time_t)sec1) - (time_t)sec0;
    return (seconds);
  }
}
static time_t guess_time_tm(long year, long yday, int hour, int min, int sec,
                            time_t const *t, struct tm const *tp) {
  time_t d;
  time_t tmp;
  time_t t1;
  long tmp___0;

  {
    if (tp) {
      {
        tmp = ydhms_diff(year, yday, hour, min, sec, (int)tp->tm_year,
                         (int)tp->tm_yday, (int)tp->tm_hour, (int)tp->tm_min,
                         (int)tp->tm_sec);
        d = tmp;
        t1 = (time_t)(*t + (time_t const)d);
      }
      if ((t1 < (time_t)*t) == (d < 0L)) {
        return (t1);
      }
    }
    if (*t < (time_t const)((((-1L << (sizeof(time_t) * 8UL - 1UL)) +
                              (-1L - (-1L << (sizeof(time_t) * 8UL - 1UL)))) >>
                             1) +
                            1L)) {
      tmp___0 =
          (-1L << (sizeof(time_t) * 8UL - 1UL)) +
          (time_t)(*t == (time_t const)(-1L << (sizeof(time_t) * 8UL - 1UL)));
    } else {
      tmp___0 =
          (-1L - (-1L << (sizeof(time_t) * 8UL - 1UL))) -
          (time_t)(*t ==
                   (time_t const)(-1L - (-1L << (sizeof(time_t) * 8UL - 1UL))));
    }
    return (tmp___0);
  }
}
static struct tm *ranged_convert(struct tm *(*convert)(time_t const *,
                                                       struct tm *),
                                 time_t *t, struct tm *tp) {
  struct tm *r;
  time_t bad;
  time_t ok;
  struct tm tm;
  time_t mid;
  time_t tmp;
  int tmp___0;

  {
    { r = (*convert)((time_t const *)t, tp); }
    if (!r) {
      if (*t) {
        bad = *t;
        ok = (time_t)0;
        {
          while (1) {
          while_continue: /* CIL Label */
              ;

            if (!(bad != ok + (time_t)tmp___0)) {
              goto while_break;
            }
            if (bad < 0L) {
              tmp = bad + ((ok - bad) >> 1);
            } else {
              tmp = ok + ((bad - ok) >> 1);
            }
            {
              *t = tmp;
              mid = tmp;
              r = (*convert)((time_t const *)t, tp);
            }
            if (r) {
              tm = *r;
              ok = mid;
            } else {
              bad = mid;
            }
          }
        while_break: /* CIL Label */
            ;
        }
        if (!r) {
          if (ok) {
            *t = ok;
            *tp = tm;
            r = tp;
          }
        }
      }
    }
    return (r);
  }
}
time_t mktime_internal(struct tm *tp,
                       struct tm *(*convert)(time_t const *, struct tm *),
                       time_t *offset) {
  time_t t;
  time_t gt;
  time_t t0;
  time_t t1;
  time_t t2;
  struct tm tm;
  int remaining_probes;
  int sec;
  int min;
  int hour;
  int mday;
  int mon;
  int year_requested;
  int isdst;
  int dst2;
  int mon_remainder;
  int negative_mon_remainder;
  int mon_years;
  long lyear_requested;
  long year;
  int mon_yday;
  int tmp;
  long lmday;
  long yday;
  time_t guessed_offset;
  int sec_requested;
  int ALOG2_SECONDS_PER_BIENNIUM;
  int ALOG2_MINUTES_PER_BIENNIUM;
  int ALOG2_HOURS_PER_BIENNIUM;
  int ALOG2_DAYS_PER_BIENNIUM;
  int LOG2_YEARS_PER_BIENNIUM;
  int approx_requested_biennia;
  int approx_biennia;
  int diff;
  int abs_diff;
  time_t time_t_max;
  time_t time_t_min;
  time_t overflow_threshold;
  time_t repaired_t0;
  struct tm *tmp___0;
  int stride;
  int duration_max;
  int delta_bound;
  int delta;
  int direction;
  time_t ot;
  struct tm otm;
  int sec_adjustment;
  struct tm *tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;

  {
    {
      remaining_probes = 6;
      sec = tp->tm_sec;
      min = tp->tm_min;
      hour = tp->tm_hour;
      mday = tp->tm_mday;
      mon = tp->tm_mon;
      year_requested = tp->tm_year;
      isdst = tp->tm_isdst;
      mon_remainder = mon % 12;
      negative_mon_remainder = mon_remainder < 0;
      mon_years = mon / 12 - negative_mon_remainder;
      lyear_requested = (long)year_requested;
      year = lyear_requested + (long)mon_years;
      tmp = leapyear((int)year);
      mon_yday = (int)((int const)__mon_yday[tmp][mon_remainder +
                                                  12 * negative_mon_remainder] -
                       1);
      lmday = (long)mday;
      yday = (long)mon_yday + lmday;
      guessed_offset = *offset;
      sec_requested = sec;
    }

    if (59 < sec) {
      sec = 59;
    }
    {
      t0 = ydhms_diff(year, yday, hour, min, sec, 70, 0, 0, 0,
                      (int)(-guessed_offset));
    }
    if ((((((-1L - (-1L << (sizeof(time_t) * 8UL - 1UL))) / 2147483647L) /
           366L) /
          24L) /
         60L) /
            60L <
        3L) {
      ALOG2_SECONDS_PER_BIENNIUM = 26;
      ALOG2_MINUTES_PER_BIENNIUM = 20;
      ALOG2_HOURS_PER_BIENNIUM = 14;
      ALOG2_DAYS_PER_BIENNIUM = 10;
      LOG2_YEARS_PER_BIENNIUM = 1;
      approx_requested_biennia =
          ((((year_requested >> LOG2_YEARS_PER_BIENNIUM) -
             (70 >> LOG2_YEARS_PER_BIENNIUM)) +
            (mday >> ALOG2_DAYS_PER_BIENNIUM)) +
           (hour >> ALOG2_HOURS_PER_BIENNIUM)) +
          (min >> ALOG2_MINUTES_PER_BIENNIUM);
      approx_biennia = (int)(t0 >> ALOG2_SECONDS_PER_BIENNIUM);
      diff = approx_biennia - approx_requested_biennia;
      if (diff < 0) {
        abs_diff = -diff;
      } else {
        abs_diff = diff;
      }
      time_t_max = -1L - (-1L << (sizeof(time_t) * 8UL - 1UL));
      time_t_min = -1L << (sizeof(time_t) * 8UL - 1UL);
      overflow_threshold =
          (time_t_max / 3L - time_t_min / 3L) >> ALOG2_SECONDS_PER_BIENNIUM;
      if (overflow_threshold < (time_t)abs_diff) {
        repaired_t0 = -1L - t0;
        approx_biennia = (int)(repaired_t0 >> ALOG2_SECONDS_PER_BIENNIUM);
        diff = approx_biennia - approx_requested_biennia;
        if (diff < 0) {
          abs_diff = -diff;
        } else {
          abs_diff = diff;
        }
        if (overflow_threshold < (time_t)abs_diff) {
          return ((time_t)-1);
        }
        guessed_offset += repaired_t0 - t0;
        t0 = repaired_t0;
      }
    }
    t2 = t0;
    t1 = t2;
    t = t1;
    dst2 = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          tmp___0 = ranged_convert(convert, &t, &tm);
          gt = guess_time_tm(year, yday, hour, min, sec, (time_t const *)(&t),
                             (struct tm const *)tmp___0);
        }
        if (!(t != gt)) {
          goto while_break;
        }
        if (t == t1) {
          if (t != t2) {
            if (tm.tm_isdst < 0) {
              goto offset_found;
            } else {
              if (isdst < 0) {
                tmp___3 = dst2 <= (tm.tm_isdst != 0);
              } else {
                tmp___3 = (isdst != 0) != (tm.tm_isdst != 0);
              }
              if (tmp___3) {
                goto offset_found;
              } else {
                goto _L___4;
              }
            }
          } else {
            goto _L___4;
          }
        } else {
        _L___4: /* CIL Label */
          remaining_probes--;
          if (remaining_probes == 0) {
            return ((time_t)-1);
          }
        }
        t1 = t2;
        t2 = t;
        t = gt;
        dst2 = tm.tm_isdst != 0;
      }
    while_break: /* CIL Label */
        ;
    }
    if (isdst != tm.tm_isdst) {
      if (0 <= isdst) {
        if (0 <= tm.tm_isdst) {
          stride = 601200;
          duration_max = 536454000;
          delta_bound = duration_max / 2 + stride;
          delta = stride;
          {

          while_break___0: /* CIL Label */
              ;
          }
        }
      }
    }
  offset_found:
    *offset = (guessed_offset + t) - t0;
    if (sec_requested != tm.tm_sec) {

      {
        sec_adjustment = tmp___4 - sec;
        t1 = t + (time_t)sec_requested;
        t2 = t1 + (time_t)sec_adjustment;
        tmp___1 = (*convert)((time_t const *)(&t), &tm);
      }

      if ((((t1 < t) != (sec_requested < 0)) |
           ((t2 < t1) != (sec_adjustment < 0))) |
          tmp___2) {
        return ((time_t)-1);
      }
    }
    *tp = tm;
    return (t);
  }
}
static time_t localtime_offset;
__attribute__((__nothrow__))
time_t(__attribute__((__leaf__)) rpl_mktime)(struct tm *tp);
time_t(__attribute__((__leaf__)) rpl_mktime)(struct tm *tp) {
  time_t tmp;

  {
    {
      tmp = mktime_internal(
          tp, (struct tm * (*)(time_t const *, struct tm *))(&localtime_r),
          &localtime_offset);
    }
    return (tmp);
  }
}
/* #pragma merger("0","020.modechange.o.i","") */
void mode_free(struct mode_change *changes);
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes);
static struct mode_change *make_node_op_equals(mode_t new_mode) {
  struct mode_change *p;
  void *tmp;

  {
    {
      tmp = malloc(sizeof(struct mode_change));
      p = (struct mode_change *)tmp;
    }
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      return (p);
    }
    p->next = (struct mode_change *)((void *)0);
    p->op = (char)'=';
    p->flags = (char)0;
    p->value = new_mode;
    p->affected = (mode_t)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
    return (p);
  }
}
static void mode_append_entry(struct mode_change **head,
                              struct mode_change **tail,
                              struct mode_change *e) {
  struct mode_change *tmp;

  {
    if ((unsigned long)*head == (unsigned long)((void *)0)) {
      tmp = e;
      *tail = tmp;
      *head = tmp;
    } else {
      (*tail)->next = e;
      *tail = e;
    }
    return;
  }
}
struct mode_change *mode_compile(char const *mode_string,
                                 unsigned int masked_ops) {
  struct mode_change *head;
  struct mode_change *tail;
  unsigned long octal_value;
  mode_t umask_value;
  struct mode_change *p;
  mode_t mode;
  strtol_error tmp;
  mode_t affected_bits;
  mode_t affected_masked;
  unsigned int ops_to_mask;
  int who_specified_p;
  struct mode_change *change;
  void *tmp___0;
  struct mode_change *p___0;
  struct mode_change *tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  int tmp___11;
  int tmp___12;
  int tmp___13;
  unsigned long tmp___14;
  int tmp___15;
  int tmp___16;
  int tmp___17;
  char *__cil_tmp34;

  {
    {
      head = (struct mode_change *)((void *)0);
      tmp = xstrtoul(mode_string, (char **)((void *)0), 8, &octal_value, "");
    }
    if ((unsigned int)tmp == 0U) {

      if (256 >> 3 == 32) {
        if (128 >> 3 == 16) {
          if (64 >> 3 == 8) {
            if ((256 >> 3) >> 3 == 4) {

            } else {
              goto _L___7;
            }
          } else {
            goto _L___7;
          }
        } else {
          goto _L___7;
        }
      } else {
      _L___7: /* CIL Label */
        if (octal_value & 2048UL) {
          tmp___2 = 2048;
        } else {
          tmp___2 = 0;
        }
        if (octal_value & 1024UL) {
          tmp___3 = 1024;
        } else {
          tmp___3 = 0;
        }
        if (octal_value & 512UL) {
          tmp___4 = 512;
        } else {
          tmp___4 = 0;
        }
        if (octal_value & 256UL) {
          tmp___5 = 256;
        } else {
          tmp___5 = 0;
        }
        if (octal_value & 128UL) {
          tmp___6 = 128;
        } else {
          tmp___6 = 0;
        }
        if (octal_value & 64UL) {
          tmp___7 = 64;
        } else {
          tmp___7 = 0;
        }
        if (octal_value & 32UL) {
          tmp___8 = 256 >> 3;
        } else {
          tmp___8 = 0;
        }
        if (octal_value & 16UL) {
          tmp___9 = 128 >> 3;
        } else {
          tmp___9 = 0;
        }
        if (octal_value & 8UL) {
          tmp___10 = 64 >> 3;
        } else {
          tmp___10 = 0;
        }
        if (octal_value & 4UL) {
          tmp___11 = (256 >> 3) >> 3;
        } else {
          tmp___11 = 0;
        }
        if (octal_value & 2UL) {
          tmp___12 = (128 >> 3) >> 3;
        } else {
          tmp___12 = 0;
        }
        if (octal_value & 1UL) {
          tmp___13 = (64 >> 3) >> 3;
        } else {
          tmp___13 = 0;
        }
        tmp___14 = (unsigned long)((
            mode_t)(((((((((((tmp___2 | tmp___3) | tmp___4) | tmp___5) |
                           tmp___6) |
                          tmp___7) |
                         tmp___8) |
                        tmp___9) |
                       tmp___10) |
                      tmp___11) |
                     tmp___12) |
                    tmp___13));
      }
      {
        mode = (mode_t)tmp___14;
        p = make_node_op_equals(mode);
      }
      if ((unsigned long)p == (unsigned long)((void *)0)) {
        return ((struct mode_change *)1);
      }
      { mode_append_entry(&head, &tail, p); }
      return (head);
    }
    {
      umask_value = umask((__mode_t)0);
      umask(umask_value);
      mode_string--;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        affected_bits = (mode_t)0;
        ops_to_mask = 0U;
        affected_bits = (mode_t)0;
        ops_to_mask = 0U;
        mode_string++;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            {
              if ((int const) * mode_string == 117) {
                goto case_117;
              }
              if ((int const) * mode_string == 103) {
                goto case_103;
              }
              if ((int const) * mode_string == 111) {
                goto case_111;
              }
              if ((int const) * mode_string == 97) {
                goto case_97;
              }
              goto switch_default;
            case_117: /* CIL Label */
              affected_bits |= 2496U;
              goto switch_break;
            case_103: /* CIL Label */
              affected_bits |= (unsigned int)(1024 | (448 >> 3));
              goto switch_break;
            case_111: /* CIL Label */
              affected_bits |= (unsigned int)(512 | ((448 >> 3) >> 3));
              goto switch_break;
            case_97: /* CIL Label */
              affected_bits |=
                  (unsigned int)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
              goto switch_break;
            switch_default: /* CIL Label */
              goto no_more_affected;
            switch_break: /* CIL Label */
                ;
            }
            mode_string++;
          }
        while_break___0: /* CIL Label */
            ;
        }
      no_more_affected:
        if (affected_bits) {
          who_specified_p = 1;
        } else {
          who_specified_p = 0;
          affected_bits = (mode_t)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
          ops_to_mask = masked_ops;
        }
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            if (!((int const) * mode_string == 61)) {
            }
            {
              tmp___0 = malloc(sizeof(struct mode_change));
              change = (struct mode_change *)tmp___0;
            }
            if ((unsigned long)change == (unsigned long)((void *)0)) {
              {
                mode_free(head);
              }
              return ((struct mode_change *)1);
            }
            change->next = (struct mode_change *)((void *)0);
            change->op = (char)*mode_string;
            affected_masked = affected_bits;
            if (!who_specified_p) {
              if ((int const) * mode_string == 61) {
                tmp___15 = 1;
              } else {
                tmp___15 = 0;
              }
              if (ops_to_mask & (unsigned int)tmp___15) {
                {
                  tmp___1 = make_node_op_equals((mode_t)0);
                  p___0 = tmp___1;
                }
                if ((unsigned long)p___0 == (unsigned long)((void *)0)) {
                  return ((struct mode_change *)1);
                }
                { mode_append_entry(&head, &tail, p___0); }
              }
            }

            if (ops_to_mask & (unsigned int)tmp___17) {
              affected_masked &= ~umask_value;
            }
            {
              change->affected = affected_masked;
              change->value = (mode_t)0;
              change->flags = (char)0;
              mode_append_entry(&head, &tail, change);
              mode_string++;
            }
            {
              while (1) {
              while_continue___2: /* CIL Label */
                  ;
                {

                  if ((int const) * mode_string == 119) {
                    goto case_119;
                  }
                  if ((int const) * mode_string == 88) {
                    goto case_88;
                  }

                  if ((int const) * mode_string == 103) {
                    goto case_103___0;
                  }
                  if ((int const) * mode_string == 111) {
                    goto case_111___0;
                  }
                  goto switch_default___0;
                case_114: /* CIL Label */
                  change->value |=
                      (unsigned int)((256 | (256 >> 3)) | ((256 >> 3) >> 3)) &
                      affected_masked;
                  goto switch_break___0;
                case_119: /* CIL Label */
                  change->value |=
                      (unsigned int)((128 | (128 >> 3)) | ((128 >> 3) >> 3)) &
                      affected_masked;
                  goto switch_break___0;
                case_88: /* CIL Label */
                  change->flags = (char)((int)change->flags | 1);
                case_120: /* CIL Label */
                  change->value |=
                      (unsigned int)((64 | (64 >> 3)) | ((64 >> 3) >> 3)) &
                      affected_masked;
                  goto switch_break___0;
                case_115: /* CIL Label */
                  change->value |= 3072U & affected_masked;
                  goto switch_break___0;
                case_116: /* CIL Label */
                  change->value |= 512U & affected_masked;
                  goto switch_break___0;
                case_117___0: /* CIL Label */
                  if (change->value) {
                    goto invalid;
                  }
                  change->value = (mode_t)448;
                  change->flags = (char)((int)change->flags | 2);
                  goto switch_break___0;
                case_103___0: /* CIL Label */
                  if (change->value) {
                    goto invalid;
                  }
                  change->value = (mode_t)(448 >> 3);
                  change->flags = (char)((int)change->flags | 2);
                  goto switch_break___0;
                case_111___0: /* CIL Label */
                  if (change->value) {
                    goto invalid;
                  }
                  change->value = (mode_t)((448 >> 3) >> 3);
                  change->flags = (char)((int)change->flags | 2);
                  goto switch_break___0;
                switch_default___0: /* CIL Label */
                  goto no_more_values;
                switch_break___0: /* CIL Label */
                    ;
                }
                mode_string++;
              }
            while_break___2: /* CIL Label */
                ;
            }
          no_more_values:;
          }
        while_break___1: /* CIL Label */
            ;
        }
        if (!((int const) * mode_string == 44)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }

  invalid: { mode_free(head); }
    return ((struct mode_change *)0);
  }
}
mode_t mode_adjust(mode_t oldmode, struct mode_change const *changes) {
  mode_t newmode;
  mode_t value;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {
    newmode = oldmode & (unsigned int)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!changes) {
          goto while_break;
        }
        if ((int const)changes->flags & 2) {
          value = newmode & (unsigned int)changes->value;
          if (changes->value & 448U) {
            if (value & 256U) {
              tmp = (256 >> 3) | ((256 >> 3) >> 3);
            } else {
              tmp = 0;
            }
            if (value & 128U) {
              tmp___0 = (128 >> 3) | ((128 >> 3) >> 3);
            } else {
              tmp___0 = 0;
            }
            if (value & 64U) {
              tmp___1 = (64 >> 3) | ((64 >> 3) >> 3);
            } else {
              tmp___1 = 0;
            }
            value |= (unsigned int)((tmp | tmp___0) | tmp___1);
          } else {
            if (changes->value & (unsigned int const)(448 >> 3)) {
              if (value & (unsigned int)(256 >> 3)) {
                tmp___2 = 256 | ((256 >> 3) >> 3);
              } else {
                tmp___2 = 0;
              }
              if (value & (unsigned int)(128 >> 3)) {
                tmp___3 = 128 | ((128 >> 3) >> 3);
              } else {
                tmp___3 = 0;
              }
              if (value & (unsigned int)(64 >> 3)) {
                tmp___4 = 64 | ((64 >> 3) >> 3);
              } else {
                tmp___4 = 0;
              }
              value |= (unsigned int)((tmp___2 | tmp___3) | tmp___4);
            } else {
              if (value & (unsigned int)((256 >> 3) >> 3)) {
                tmp___5 = 256 | (256 >> 3);
              } else {
                tmp___5 = 0;
              }
              if (value & (unsigned int)((128 >> 3) >> 3)) {
                tmp___6 = 128 | (128 >> 3);
              } else {
                tmp___6 = 0;
              }
              if (value & (unsigned int)((64 >> 3) >> 3)) {
                tmp___7 = 64 | (64 >> 3);
              } else {
                tmp___7 = 0;
              }
              value |= (unsigned int)((tmp___5 | tmp___6) | tmp___7);
            }
          }
          value &= (unsigned int)changes->affected;
        } else {
          value = (mode_t)changes->value;
          if ((int const)changes->flags & 1) {
            if (!((oldmode & 61440U) == 16384U)) {
              if ((newmode &
                   (unsigned int)((64 | (64 >> 3)) | ((64 >> 3) >> 3))) == 0U) {
                value &= (unsigned int)(~((64 | (64 >> 3)) | ((64 >> 3) >> 3)));
              }
            }
          }
        }
        {
          if ((int const)changes->op == 61) {
            goto case_61;
          }
          if ((int const)changes->op == 43) {
            goto case_43;
          }

          goto switch_break;
        case_61: /* CIL Label */
          newmode = (newmode & (unsigned int)(~changes->affected)) | value;
          goto switch_break;
        case_43: /* CIL Label */
          newmode |= value;
          goto switch_break;
        case_45: /* CIL Label */
          newmode &= ~value;
          goto switch_break;
        switch_break: /* CIL Label */
            ;
        }
        changes = (struct mode_change const *)changes->next;
      }
    while_break: /* CIL Label */
        ;
    }
    return (newmode);
  }
}
void mode_free(struct mode_change *changes) {
  register struct mode_change *next;

  {
    {

    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
/* #pragma merger("0","021.prepargs.o.i","") */

void prepend_default_options(char const *options, int *pargc, char ***pargv) {
  char *buf;
  size_t tmp;
  void *tmp___0;
  int prepended;
  int tmp___1;
  int argc;
  char *const *argv;
  char **pp;
  void *tmp___2;
  char **tmp___3;
  char *const *tmp___4;
  int tmp___5;
  char **tmp___6;
  char *tmp___7;
  char *const *tmp___8;

  { return; }
}
/* #pragma merger("0","022.quotearg.o.i","") */
char const *const quoting_style_args[8];
enum quoting_style const quoting_style_vals[7];
int set_char_quoting(struct quoting_options *o___0, char c, int i);
char *quotearg_n(int n, char const *arg);
char *quotearg_char(char const *arg, char ch);
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__)) __ctype_get_mb_cur_max)(void);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) mbsinit)(
    mbstate_t const *__ps) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrtowc)(
    wchar_t *__restrict __pwc, char const *__restrict __s, size_t __n,
    mbstate_t *__restrict __p);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) iswprint)(
    wint_t __wc);
char const *const quoting_style_args[8] = {
    (char const * /* const  */) "literal",
    (char const * /* const  */) "shell",
    (char const * /* const  */) "shell-always",
    (char const * /* const  */) "c",
    (char const * /* const  */) "escape",
    (char const * /* const  */) "locale",
    (char const * /* const  */) "clocale",
    (char const * /* const  */)0};
enum quoting_style const quoting_style_vals[7] = {
    (enum quoting_style const)0, (enum quoting_style const)1,
    (enum quoting_style const)2, (enum quoting_style const)3,
    (enum quoting_style const)4, (enum quoting_style const)5,
    (enum quoting_style const)6};
static struct quoting_options default_quoting_options;
struct quoting_options *clone_quoting_options(struct quoting_options *o___0) {
  int e;
  int *tmp;
  struct quoting_options *p;
  void *tmp___0;
  int *tmp___1;
  struct quoting_options *tmp___2;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = xmalloc(sizeof(*p));
      p = (struct quoting_options *)tmp___0;
    }
    if (o___0) {
      tmp___2 = o___0;
    } else {
      tmp___2 = &default_quoting_options;
    }
    {
      *p = *tmp___2;
      tmp___1 = __errno_location();
      *tmp___1 = e;
    }
    return (p);
  }
}
void set_quoting_style(struct quoting_options *o___0, enum quoting_style s) {
  struct quoting_options *tmp;

  {
    if (o___0) {
      tmp = o___0;
    } else {
      tmp = &default_quoting_options;
    }
    tmp->style = s;
    return;
  }
}
int set_char_quoting(struct quoting_options *o___0, char c, int i) {
  unsigned char uc;
  int *p;
  int shift;
  int r;
  struct quoting_options *tmp;

  {
    uc = (unsigned char)c;

    p = tmp->quote_these_too + (unsigned long)uc / (sizeof(int) * 8UL);
    shift = (int)((unsigned long)uc % (sizeof(int) * 8UL));
    r = (*p >> shift) & 1;
    *p ^= ((i & 1) ^ r) << shift;
    return (r);
  }
}
static char const *gettext_quote(char const *msgid, enum quoting_style s) {
  char const *translation;
  char *tmp;
  char *__cil_tmp5;

  {
    {
      tmp = gettext(msgid);
      translation = (char const *)tmp;
    }
    if ((unsigned long)translation == (unsigned long)msgid) {
      if ((unsigned int)s == 6U) {
        translation = "\"";
      }
    }
    return (translation);
  }
}
static size_t quotearg_buffer_restyled(char *buffer___2, size_t buffersize,
                                       char const *arg, size_t argsize,
                                       enum quoting_style quoting_style,
                                       struct quoting_options const *o___0) {
  size_t i;
  size_t len;
  char const *quote_string;
  size_t quote_string_len;
  int backslash_escapes;
  int unibyte_locale;
  size_t tmp;
  char const *left;
  char const *tmp___0;
  char const *right;
  char const *tmp___1;
  unsigned char c;
  unsigned char esc;
  int tmp___2;
  size_t m;
  int printable;
  unsigned short const **tmp___3;
  mbstate_t mbstate;
  wchar_t w;
  size_t bytes;
  size_t tmp___4;
  size_t j;
  int tmp___5;
  int tmp___6;
  size_t ilim;
  size_t tmp___7;
  int tmp___8;
  int tmp___9;
  void *__cil_tmp35;
  char *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;
  char *__cil_tmp39;

  {
    {
      len = (size_t)0;
      quote_string = (char const *)0;
      quote_string_len = (size_t)0;
      backslash_escapes = 0;
      tmp = __ctype_get_mb_cur_max();
      unibyte_locale = tmp == 1UL;
    }
    {
      if ((unsigned int)quoting_style == 3U) {
        goto case_3;
      }

      if ((unsigned int)quoting_style == 5U) {
        goto case_5;
      }
      if ((unsigned int)quoting_style == 6U) {
        goto case_5;
      }
      if ((unsigned int)quoting_style == 2U) {
        goto case_2;
      }
      goto switch_default;
    case_3: { /* CIL Label */
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (len < buffersize) {
          *(buffer___2 + len) = (char)'\"';
        }
        len++;
        goto while_break;
      }
    while_break: /* CIL Label */
        ;
    }
      backslash_escapes = 1;
      quote_string = "\"";
      quote_string_len = (size_t)1;
      goto switch_break;
    case_4: /* CIL Label */
      backslash_escapes = 1;
      goto switch_break;
    case_5:   /* CIL Label */
    case_6: { /* CIL Label */
      tmp___0 = gettext_quote("`", quoting_style);
      left = tmp___0;
      tmp___1 = gettext_quote("\'", quoting_style);
      right = tmp___1;
      quote_string = left;
    }
      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;
          if (!*quote_string) {
            goto while_break___0;
          }
          {
            while (1) {
            while_continue___1: /* CIL Label */
                ;
              if (len < buffersize) {
                *(buffer___2 + len) = (char)*quote_string;
              }
              len++;
              goto while_break___1;
            }
          while_break___1: /* CIL Label */
              ;
          }
          quote_string++;
        }
      while_break___0: /* CIL Label */
          ;
      }
      {
        backslash_escapes = 1;
        quote_string = right;
        quote_string_len = strlen(quote_string);
      }
      goto switch_break;
    case_2: { /* CIL Label */
      while (1) {
      while_continue___2: /* CIL Label */
          ;
        if (len < buffersize) {
          *(buffer___2 + len) = (char)'\'';
        }
        len++;
        goto while_break___2;
      }
    while_break___2: /* CIL Label */
        ;
    }
      quote_string = "\'";
      quote_string_len = (size_t)1;
      goto switch_break;
    switch_default: /* CIL Label */
      goto switch_break;
    switch_break: /* CIL Label */
        ;
    }
    i = (size_t)0;
    {
      while (1) {
      while_continue___3: /* CIL Label */
          ;
        if (argsize == 0xffffffffffffffffUL) {
          tmp___9 = (int const) * (arg + i) == 0;
        } else {
          tmp___9 = i == argsize;
        }
        if (tmp___9) {
          goto while_break___3;
        }
        if (backslash_escapes) {
          if (quote_string_len) {
          }
        }
        c = (unsigned char)*(arg + i);
        {
          if ((int)c == 0) {
            goto case_0;
          }
          if ((int)c == 63) {
            goto case_63;
          }
          if ((int)c == 7) {
            goto case_7;
          }
          if ((int)c == 8) {
            goto case_8;
          }
          if ((int)c == 12) {
            goto case_12;
          }
          if ((int)c == 10) {
            goto case_10;
          }
          if ((int)c == 13) {
            goto case_13;
          }
          if ((int)c == 9) {
            goto case_9;
          }
          if ((int)c == 11) {
            goto case_11;
          }
          if ((int)c == 92) {
            goto case_92;
          }
          if ((int)c == 123) {
            goto case_123;
          }
          if ((int)c == 125) {
            goto case_123;
          }
          if ((int)c == 35) {
            goto case_35;
          }
          if ((int)c == 126) {
            goto case_35;
          }
          if ((int)c == 32) {
            goto case_32;
          }
          if ((int)c == 33) {
            goto case_32;
          }

          if ((int)c == 40) {
            goto case_32;
          }
          if ((int)c == 41) {
            goto case_32;
          }
          if ((int)c == 42) {
            goto case_32;
          }
          if ((int)c == 59) {
            goto case_32;
          }
          if ((int)c == 60) {
            goto case_32;
          }
          if ((int)c == 61) {
            goto case_32;
          }
          if ((int)c == 62) {
            goto case_32;
          }

          if ((int)c == 96) {
            goto case_32;
          }

          if ((int)c == 39) {
            goto case_39___0;
          }
          if ((int)c == 37) {
            goto case_37;
          }
          if ((int)c == 43) {
            goto case_37;
          }
          if ((int)c == 44) {
            goto case_37;
          }
          if ((int)c == 45) {
            goto case_37;
          }

          if ((int)c == 47) {
            goto case_37;
          }
          if ((int)c == 48) {
            goto case_37;
          }
          if ((int)c == 49) {
            goto case_37;
          }
          if ((int)c == 50) {
            goto case_37;
          }
          if ((int)c == 51) {
            goto case_37;
          }
          if ((int)c == 52) {
            goto case_37;
          }
          if ((int)c == 53) {
            goto case_37;
          }

          if ((int)c == 55) {
            goto case_37;
          }
          if ((int)c == 56) {
            goto case_37;
          }
          if ((int)c == 57) {
            goto case_37;
          }
          if ((int)c == 58) {
            goto case_37;
          }
          if ((int)c == 65) {
            goto case_37;
          }
          if ((int)c == 66) {
            goto case_37;
          }
          if ((int)c == 67) {
            goto case_37;
          }
          if ((int)c == 68) {
            goto case_37;
          }
          if ((int)c == 69) {
            goto case_37;
          }
          if ((int)c == 70) {
            goto case_37;
          }
          if ((int)c == 71) {
            goto case_37;
          }
          if ((int)c == 72) {
            goto case_37;
          }
          if ((int)c == 73) {
            goto case_37;
          }
          if ((int)c == 74) {
            goto case_37;
          }
          if ((int)c == 75) {
            goto case_37;
          }
          if ((int)c == 76) {
            goto case_37;
          }
          if ((int)c == 77) {
            goto case_37;
          }
          if ((int)c == 78) {
            goto case_37;
          }
          if ((int)c == 79) {
            goto case_37;
          }
          if ((int)c == 80) {
            goto case_37;
          }
          if ((int)c == 81) {
            goto case_37;
          }
          if ((int)c == 82) {
            goto case_37;
          }
          if ((int)c == 83) {
            goto case_37;
          }
          if ((int)c == 84) {
            goto case_37;
          }

          if ((int)c == 86) {
            goto case_37;
          }
          if ((int)c == 87) {
            goto case_37;
          }
          if ((int)c == 88) {
            goto case_37;
          }
          if ((int)c == 89) {
            goto case_37;
          }
          if ((int)c == 90) {
            goto case_37;
          }
          if ((int)c == 93) {
            goto case_37;
          }
          if ((int)c == 95) {
            goto case_37;
          }
          if ((int)c == 97) {
            goto case_37;
          }
          if ((int)c == 98) {
            goto case_37;
          }
          if ((int)c == 99) {
            goto case_37;
          }
          if ((int)c == 100) {
            goto case_37;
          }

          if ((int)c == 102) {
            goto case_37;
          }
          if ((int)c == 103) {
            goto case_37;
          }
          if ((int)c == 104) {
            goto case_37;
          }

          if ((int)c == 107) {
            goto case_37;
          }
          if ((int)c == 108) {
            goto case_37;
          }
          if ((int)c == 109) {
            goto case_37;
          }
          if ((int)c == 110) {
            goto case_37;
          }
          if ((int)c == 111) {
            goto case_37;
          }

          if ((int)c == 113) {
            goto case_37;
          }
          if ((int)c == 114) {
            goto case_37;
          }
          if ((int)c == 115) {
            goto case_37;
          }

          if ((int)c == 117) {
            goto case_37;
          }

          if ((int)c == 119) {
            goto case_37;
          }
          if ((int)c == 120) {
            goto case_37;
          }
          if ((int)c == 121) {
            goto case_37;
          }

          goto switch_default___2;
        case_0: /* CIL Label */

          goto switch_break___0;
        case_63: { /* CIL Label */

          if ((unsigned int)quoting_style == 3U) {
            goto case_3___0;
          }
          goto switch_default___0;
        case_1: /* CIL Label */
          goto use_shell_always_quoting_style;
        case_3___0: /* CIL Label */
          if (i + 2UL < argsize) {
          }
          goto switch_break___1;
        switch_default___0: /* CIL Label */
          goto switch_break___1;
        switch_break___1: /* CIL Label */
            ;
        }
          goto switch_break___0;
        case_7: /* CIL Label */
          esc = (unsigned char)'a';
          goto c_escape;
        case_8: /* CIL Label */
          esc = (unsigned char)'b';
          goto c_escape;
        case_12: /* CIL Label */
          esc = (unsigned char)'f';
          goto c_escape;
        case_10: /* CIL Label */
          esc = (unsigned char)'n';
          goto c_and_shell_escape;
        case_13: /* CIL Label */
          esc = (unsigned char)'r';
          goto c_and_shell_escape;
        case_9: /* CIL Label */
          esc = (unsigned char)'t';
          goto c_and_shell_escape;
        case_11: /* CIL Label */
          esc = (unsigned char)'v';
          goto c_escape;
        case_92: /* CIL Label */
          esc = c;
          goto c_and_shell_escape;
        c_and_shell_escape:
          if ((unsigned int)quoting_style == 1U) {
            goto use_shell_always_quoting_style;
          }
        c_escape:
          if (backslash_escapes) {
            c = esc;
            goto store_escape;
          }
          goto switch_break___0;
        case_123: /* CIL Label */
        case_125: /* CIL Label */
          if (argsize == 0xffffffffffffffffUL) {
            tmp___8 = (int const) * (arg + 1) == 0;
          } else {
            tmp___8 = argsize == 1UL;
          }
          if (!tmp___8) {
            goto switch_break___0;
          }
        case_35:  /* CIL Label */
        case_126: /* CIL Label */
          if (i != 0UL) {
            goto switch_break___0;
          }
        case_32:     /* CIL Label */
        case_33___0: /* CIL Label */
        case_34:     /* CIL Label */
        case_36:     /* CIL Label */
        case_38:     /* CIL Label */
        case_40___0: /* CIL Label */
        case_41___0: /* CIL Label */
        case_42:     /* CIL Label */
        case_59:     /* CIL Label */
        case_60___0: /* CIL Label */
        case_61___0: /* CIL Label */
        case_62___0: /* CIL Label */
        case_91:     /* CIL Label */
        case_94:     /* CIL Label */
        case_96:     /* CIL Label */
        case_124:    /* CIL Label */
          if ((unsigned int)quoting_style == 1U) {
            goto use_shell_always_quoting_style;
          }
          goto switch_break___0;
        case_39___0: { /* CIL Label */
          if ((unsigned int)quoting_style == 1U) {
            goto case_1___0;
          }

          goto switch_default___1;
        case_1___0: /* CIL Label */
          goto use_shell_always_quoting_style;
        case_2___0: { /* CIL Label */
          while (1) {
          while_continue___11: /* CIL Label */
              ;
            if (len < buffersize) {
              *(buffer___2 + len) = (char)'\'';
            }
            len++;
            goto while_break___11;
          }
        while_break___11: /* CIL Label */
            ;
        }
          {

          while_break___12: /* CIL Label */
              ;
          }
          {
            while (1) {
            while_continue___13: /* CIL Label */
                ;
              if (len < buffersize) {
                *(buffer___2 + len) = (char)'\'';
              }
              len++;
              goto while_break___13;
            }
          while_break___13: /* CIL Label */
              ;
          }
          goto switch_break___3;
        switch_default___1: /* CIL Label */
          goto switch_break___3;
        switch_break___3: /* CIL Label */
            ;
        }
          goto switch_break___0;
        case_37:     /* CIL Label */
        case_43:     /* CIL Label */
        case_44:     /* CIL Label */
        case_45___0: /* CIL Label */
        case_46:     /* CIL Label */
        case_47___0: /* CIL Label */
        case_48:     /* CIL Label */
        case_49:     /* CIL Label */
        case_50:     /* CIL Label */
        case_51:     /* CIL Label */
        case_52:     /* CIL Label */
        case_53:     /* CIL Label */
        case_54:     /* CIL Label */
        case_55:     /* CIL Label */
        case_56:     /* CIL Label */
        case_57:     /* CIL Label */
        case_58:     /* CIL Label */
        case_65:     /* CIL Label */
        case_66:     /* CIL Label */
        case_67:     /* CIL Label */
        case_68:     /* CIL Label */
        case_69:     /* CIL Label */
        case_70:     /* CIL Label */
        case_71:     /* CIL Label */
        case_72:     /* CIL Label */
        case_73:     /* CIL Label */
        case_74:     /* CIL Label */
        case_75:     /* CIL Label */
        case_76:     /* CIL Label */
        case_77:     /* CIL Label */
        case_78:     /* CIL Label */
        case_79:     /* CIL Label */
        case_80:     /* CIL Label */
        case_81:     /* CIL Label */
        case_82:     /* CIL Label */
        case_83:     /* CIL Label */
        case_84:     /* CIL Label */
        case_85:     /* CIL Label */
        case_86:     /* CIL Label */
        case_87:     /* CIL Label */
        case_88:     /* CIL Label */
        case_89:     /* CIL Label */
        case_90:     /* CIL Label */
        case_93:     /* CIL Label */
        case_95:     /* CIL Label */
        case_97:     /* CIL Label */
        case_98:     /* CIL Label */
        case_99:     /* CIL Label */
        case_100:    /* CIL Label */
        case_101:    /* CIL Label */
        case_102:    /* CIL Label */
        case_103:    /* CIL Label */
        case_104:    /* CIL Label */
        case_105:    /* CIL Label */
        case_106:    /* CIL Label */
        case_107:    /* CIL Label */
        case_108:    /* CIL Label */
        case_109:    /* CIL Label */
        case_110:    /* CIL Label */
        case_111:    /* CIL Label */
        case_112:    /* CIL Label */
        case_113:    /* CIL Label */
        case_114:    /* CIL Label */
        case_115:    /* CIL Label */
        case_116:    /* CIL Label */
        case_117:    /* CIL Label */
        case_118:    /* CIL Label */
        case_119:    /* CIL Label */
        case_120:    /* CIL Label */
        case_121:    /* CIL Label */
        case_122:    /* CIL Label */
          goto switch_break___0;
        switch_default___2: /* CIL Label */
          if (unibyte_locale) {
            {
              m = (size_t)1;
              tmp___3 = __ctype_b_loc();
              printable = (int)((int const) * (*tmp___3 + (int)c) & 16384);
            }
          } else {
            {
              memset((void *)(&mbstate), 0, sizeof(mbstate));
              m = (size_t)0;
              printable = 1;
            }
            if (argsize == 0xffffffffffffffffUL) {
              {
                argsize = strlen(arg);
              }
            }
            {
              while (1) {
              while_continue___14: /* CIL Label */
                  ;
                {
                  tmp___4 =
                      mbrtowc((wchar_t * /* __restrict  */)(&w),
                              (char const * /* __restrict  */)(arg + (i + m)),
                              argsize - (i + m),
                              (mbstate_t * /* __restrict  */)(&mbstate));
                  bytes = tmp___4;
                }
                if (bytes == 0UL) {
                  goto while_break___14;
                } else {
                  if (bytes == 0xffffffffffffffffUL) {
                    printable = 0;
                    goto while_break___14;
                  } else {
                  }
                }
                { tmp___6 = mbsinit((mbstate_t const *)(&mbstate)); }
                if (tmp___6) {
                  goto while_break___14;
                }
              }
            while_break___14: /* CIL Label */
                ;
            }
          }
          if (1UL < m) {
            goto _L___3;
          } else {
            if (backslash_escapes) {
              if (!printable) {
              _L___3: /* CIL Label */
                ilim = i + m;
                {
                  while (1) {
                  while_continue___17: /* CIL Label */
                      ;
                    if (backslash_escapes) {
                      if (!printable) {
                        {
                          while (1) {
                          while_continue___18: /* CIL Label */
                              ;
                            if (len < buffersize) {
                              *(buffer___2 + len) = (char)'\\';
                            }
                            len++;
                            goto while_break___18;
                          }
                        while_break___18: /* CIL Label */
                            ;
                        }
                        {
                          while (1) {
                          while_continue___19: /* CIL Label */
                              ;
                            if (len < buffersize) {
                              *(buffer___2 + len) = (char)(48 + ((int)c >> 6));
                            }
                            len++;
                            goto while_break___19;
                          }
                        while_break___19: /* CIL Label */
                            ;
                        }
                        {
                          while (1) {
                          while_continue___20: /* CIL Label */
                              ;
                            if (len < buffersize) {
                              *(buffer___2 + len) =
                                  (char)(48 + (((int)c >> 3) & 7));
                            }
                            len++;
                            goto while_break___20;
                          }
                        while_break___20: /* CIL Label */
                            ;
                        }
                        c = (unsigned char)(48 + ((int)c & 7));
                      }
                    }
                    if (ilim <= i + 1UL) {
                      goto while_break___17;
                    }
                    {
                      while (1) {
                      while_continue___21: /* CIL Label */
                          ;
                        if (len < buffersize) {
                          *(buffer___2 + len) = (char)c;
                        }
                        len++;
                        goto while_break___21;
                      }
                    while_break___21: /* CIL Label */
                        ;
                    }
                    i++;
                    c = (unsigned char)*(arg + i);
                  }
                while_break___17: /* CIL Label */
                    ;
                }
                goto store_c;
              }
            }
          }
        switch_break___0: /* CIL Label */
            ;
        }
        if (backslash_escapes) {
          if (!(o___0->quote_these_too[(unsigned long)c / (sizeof(int) * 8UL)] &
                (1 << (unsigned long)c % (sizeof(int) * 8UL)))) {
            goto store_c;
          }
        } else {
          goto store_c;
        }
      store_escape: {
        while (1) {
        while_continue___22: /* CIL Label */
            ;
          if (len < buffersize) {
            *(buffer___2 + len) = (char)'\\';
          }
          len++;
          goto while_break___22;
        }
      while_break___22: /* CIL Label */
          ;
      }
      store_c: {
        while (1) {
        while_continue___23: /* CIL Label */
            ;
          if (len < buffersize) {
            *(buffer___2 + len) = (char)c;
          }
          len++;
          goto while_break___23;
        }
      while_break___23: /* CIL Label */
          ;
      }
        i++;
      }
    while_break___3: /* CIL Label */
        ;
    }

    if (len < buffersize) {
      *(buffer___2 + len) = (char)'\000';
    }
    return (len);
  use_shell_always_quoting_style: {
    tmp___7 = quotearg_buffer_restyled(buffer___2, buffersize, arg, argsize,
                                       (enum quoting_style)2, o___0);
  }
    return (tmp___7);
  }
}
size_t quotearg_buffer(char *buffer___2, size_t buffersize, char const *arg,
                       size_t argsize, struct quoting_options const *o___0) {
  struct quoting_options const *p;
  int e;
  int *tmp;
  size_t r;
  size_t tmp___0;
  int *tmp___1;

  {
    if (o___0) {
      p = o___0;
    } else {
      p = (struct quoting_options const *)(&default_quoting_options);
    }
    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = quotearg_buffer_restyled(buffer___2, buffersize, arg, argsize,
                                         (enum quoting_style)p->style, p);
      r = tmp___0;
      tmp___1 = __errno_location();
      *tmp___1 = e;
    }
    return (r);
  }
}
static char slot0[256];
static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options);
static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options) {
  int e;
  int *tmp;
  unsigned int n0;
  unsigned int n1;
  void *tmp___0;
  void *tmp___1;
  size_t size;
  char *val;
  size_t qsize;
  size_t tmp___2;
  void *tmp___3;
  int *tmp___4;
  int tmp___5;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      n0 = (unsigned int)n;
    }

    if (nslots <= n0) {
      n1 = n0 + 1U;
      if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
        tmp___5 = -1;
      } else {
        tmp___5 = -2;
      }
      if ((size_t)tmp___5 / sizeof(*slotvec) < (size_t)n1) {
        {
          xalloc_die();
        }
      }
      if ((unsigned long)slotvec == (unsigned long)(&slotvec0)) {
        {
          tmp___0 = xmalloc(sizeof(*slotvec));
          slotvec = (struct slotvec *)tmp___0;
          *slotvec = slotvec0;
        }
      }
      {
        tmp___1 =
            xrealloc((void *)slotvec, (unsigned long)n1 * sizeof(*slotvec));
        slotvec = (struct slotvec *)tmp___1;
        memset((void *)(slotvec + nslots), 0,
               (unsigned long)(n1 - nslots) * sizeof(*slotvec));
        nslots = n1;
      }
    }
    {
      size = (slotvec + n)->size;
      val = (slotvec + n)->val;
      tmp___2 = quotearg_buffer(val, size, arg, argsize, options);
      qsize = tmp___2;
    }
    if (size <= qsize) {
      size = qsize + 1UL;
      (slotvec + n)->size = size;
      if ((unsigned long)val != (unsigned long)(slot0)) {
        {
          free((void *)val);
        }
      }
      {
        tmp___3 = xmalloc(size);
        val = (char *)tmp___3;
        (slotvec + n)->val = val;
        quotearg_buffer(val, size, arg, argsize, options);
      }
    }
    {
      tmp___4 = __errno_location();
      *tmp___4 = e;
    }
    return (val);
  }
}
char *quotearg_n(int n, char const *arg) {
  char *tmp;

  {
    {
      tmp = quotearg_n_options(
          n, arg, (size_t)-1,
          (struct quoting_options const *)(&default_quoting_options));
    }
    return (tmp);
  }
}
char *quotearg(char const *arg) {
  char *tmp;

  {
    { tmp = quotearg_n(0, arg); }
    return (tmp);
  }
}
static struct quoting_options
quoting_options_from_style(enum quoting_style style) {
  struct quoting_options o___0;
  void *__cil_tmp3;

  {
    {
      o___0.style = style;
      memset((void *)(o___0.quote_these_too), 0, sizeof(o___0.quote_these_too));
    }
    return (o___0);
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o___0;
  struct quoting_options tmp;
  char *tmp___0;
  void *__cil_tmp7;
  void *__cil_tmp8;

  {
    {
      tmp = quoting_options_from_style(s);
      o___0 = tmp;
      tmp___0 = quotearg_n_options(n, arg, (size_t)-1,
                                   (struct quoting_options const *)(&o___0));
    }
    return (tmp___0);
  }
}
char *quotearg_char(char const *arg, char ch) {
  struct quoting_options options;
  char *tmp;
  void *__cil_tmp5;

  {
    {
      options = default_quoting_options;
      set_char_quoting(&options, ch, 1);
      tmp = quotearg_n_options(0, arg, (size_t)-1,
                               (struct quoting_options const *)(&options));
    }
    return (tmp);
  }
}
char *quotearg_colon(char const *arg) {
  char *tmp;

  {
    { tmp = quotearg_char(arg, (char)':'); }
    return (tmp);
  }
}
/* #pragma merger("0","023.quote.o.i","") */
/* #pragma merger("0","024.safe-read.o.i","") */
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
size_t safe_read(int fd, void *buf, size_t count) {
  ssize_t result;
  int *tmp;

  {
    if (count > 2147483647UL) {
      count = (size_t)2147475456;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { result = read(fd, buf, count); }
        if (result < 0L) {
          {
            tmp = __errno_location();
          }
          if (!(*tmp == 4)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return ((size_t)result);
  }
}
/* #pragma merger("0","025.safe-write.o.i","") */
extern ssize_t write(int __fd, void const *__buf, size_t __n);
size_t safe_write(int fd, void const *buf, size_t count) {
  ssize_t result;
  int *tmp;

  {

    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { result = write(fd, buf, count); }
        if (result < 0L) {
          {
            tmp = __errno_location();
          }
          if (!(*tmp == 4)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return ((size_t)result);
  }
}
/* #pragma merger("0","026.save-cwd.o.i","") */
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchdir)(
    int __fd);
char *xgetcwd(void);
static int have_working_fchdir = 1;
int save_cwd(struct saved_cwd *cwd) {

  {
    cwd->desc = -1;
    cwd->name = (char *)((void *)0);
    if (have_working_fchdir) {
      {
        cwd->desc = open(".", 65536);
      }
      if (cwd->desc < 0) {
        return (1);
      }
    }
    if (!have_working_fchdir) {
      {
        cwd->name = xgetcwd();
      }
    }
    return (0);
  }
}
int restore_cwd(struct saved_cwd const *cwd) {
  int tmp;
  int tmp___0;

  {
    if (0 <= (int)cwd->desc) {
      {
        tmp = fchdir((int)cwd->desc);
      }
      return (tmp < 0);
    } else {
      { tmp___0 = chdir((char const *)cwd->name); }
      return (tmp___0 < 0);
    }
  }
}
/* #pragma merger("0","027.savedir.o.i","") */
char *savedir(char const *dir) {
  DIR *dirp;
  struct dirent *dp;
  char *name_space;
  size_t allocated;
  size_t used;
  int save_errno;
  void *tmp;
  int *tmp___0;
  char const *entry;
  size_t entry_size;
  size_t tmp___1;
  void *tmp___2;
  int *tmp___3;
  int *tmp___4;
  int tmp___5;
  int *tmp___6;
  int tmp___7;
  int tmp___8;

  {
    {
      allocated = (size_t)512;
      used = (size_t)0;
      dirp = opendir(dir);
    }
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      return ((char *)((void *)0));
    }
    {
      tmp = xmalloc(allocated);
      name_space = (char *)tmp;
      tmp___0 = __errno_location();
      *tmp___0 = 0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { dp = readdir(dirp); }
        if (!((unsigned long)dp != (unsigned long)((void *)0))) {
          goto while_break;
        }
        entry = (char const *)(dp->d_name);
        if ((int const) * (entry + 0) != 46) {
          tmp___8 = 0;
        } else {
          if ((int const) * (entry + 1) != 46) {
            tmp___7 = 1;
          } else {
            tmp___7 = 2;
          }
          tmp___8 = tmp___7;
        }
        if ((int const) * (entry + tmp___8) != 0) {
          {
            tmp___1 = strlen(entry);
            entry_size = tmp___1 + 1UL;
          }
          if (used + entry_size < used) {
            {
              xalloc_die();
            }
          }

          {
            memcpy((void * /* __restrict  */)(name_space + used),
                   (void const * /* __restrict  */)entry, entry_size);
            used += entry_size;
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      *(name_space + used) = (char)'\000';
      tmp___3 = __errno_location();
      save_errno = *tmp___3;
      tmp___5 = closedir(dirp);
    }

    if (save_errno != 0) {
      {
        free((void *)name_space);
        tmp___6 = __errno_location();
        *tmp___6 = save_errno;
      }
      return ((char *)((void *)0));
    }
    return (name_space);
  }
}
/* #pragma merger("0","028.stripslash.o.i","") */
int strip_trailing_slashes(char *path) {
  char *base;
  char *tmp;
  char *base_lim;
  size_t tmp___0;
  int had_slash;

  {
    {
      tmp = base_name((char const *)path);
      base = tmp;
      tmp___0 = base_len((char const *)base);
      base_lim = base + tmp___0;
      had_slash = (int)*base_lim;
      *base_lim = (char)'\000';
    }
    return (had_slash);
  }
}
/* #pragma merger("0","029.xgetcwd.o.i","") */
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) getcwd)(
    char *__buf, size_t __size);
char *xgetcwd(void) {
  char *cwd;
  char *tmp;
  int *tmp___0;

  {
    {
      tmp = getcwd((char *)((void *)0), (size_t)0);
      cwd = tmp;
    }

    return (cwd);
  }
}
/* #pragma merger("0","02a.xmalloc.o.i","") */
char const xalloc_msg_memory_exhausted[17];
void *xclone(void const *p, size_t s);
extern __attribute__((__nothrow__)) void *(__attribute__((
    __warn_unused_result__, __leaf__)) realloc)(void *__ptr, size_t __size);
void (*xalloc_fail_func)(void) = (void (*)(void))0;
char const xalloc_msg_memory_exhausted[17] = {
    (char const)'m',   (char const)'e', (char const)'m', (char const)'o',
    (char const)'r',   (char const)'y', (char const)' ', (char const)'e',
    (char const)'x',   (char const)'h', (char const)'a', (char const)'u',
    (char const)'s',   (char const)'t', (char const)'e', (char const)'d',
    (char const)'\000'};
__attribute__((__noreturn__)) void xalloc_die(void);
void xalloc_die(void) {
  char *tmp;

  {

    {
      tmp = gettext(xalloc_msg_memory_exhausted);
      error((int)exit_failure, 0, "%s", tmp);
      abort();
    }
  }
}
__inline static void *xnmalloc_inline(size_t n, size_t s) {
  void *p;
  int tmp;

  {
    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp = -1;
    } else {
      tmp = -2;
    }
    if ((size_t)tmp / s < n) {
      {
        xalloc_die();
      }
    } else {
      { p = malloc(n * s); }
      if (!p) {
        {
          xalloc_die();
        }
      }
    }
    return (p);
  }
}
void *xmalloc(size_t n) {
  void *tmp;

  {
    { tmp = xnmalloc_inline(n, (size_t)1); }
    return (tmp);
  }
}
__inline static void *xnrealloc_inline(void *p, size_t n, size_t s) {
  int tmp;

  {
    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp = -1;
    } else {
      tmp = -2;
    }
    if ((size_t)tmp / s < n) {
      {
        xalloc_die();
      }
    } else {
      { p = realloc(p, n * s); }
      if (!p) {
        {
          xalloc_die();
        }
      }
    }
    return (p);
  }
}
void *xrealloc(void *p, size_t n) {
  void *tmp;

  {
    { tmp = xnrealloc_inline(p, n, (size_t)1); }
    return (tmp);
  }
}
__inline static void *x2nrealloc_inline(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {
    n = *pn;
    if (!p) {
      if (!n) {
        n = 64UL / s;
        n += (size_t)(!n);
      }
    } else {
      if (9223372036854775807UL / s < n) {
        {
          xalloc_die();
        }
      }
      n *= 2UL;
    }
    {
      *pn = n;
      tmp = xrealloc(p, n * s);
    }
    return (tmp);
  }
}
void *x2nrealloc(void *p, size_t *pn, size_t s) {
  void *tmp;

  {
    { tmp = x2nrealloc_inline(p, pn, s); }
    return (tmp);
  }
}
void *x2realloc(void *p, size_t *pn) {
  void *tmp;

  {
    { tmp = x2nrealloc_inline(p, pn, (size_t)1); }
    return (tmp);
  }
}
void *xzalloc(size_t s) {
  void *tmp;
  void *tmp___0;

  {
    {
      tmp = xmalloc(s);
      tmp___0 = memset(tmp, 0, s);
    }
    return (tmp___0);
  }
}
void *xclone(void const *p, size_t s) {
  void *tmp;
  void *tmp___0;

  {
    {
      tmp = xmalloc(s);
      tmp___0 = memcpy((void * /* __restrict  */)tmp,
                       (void const * /* __restrict  */)p, s);
    }
    return (tmp___0);
  }
}
/* #pragma merger("0","02b.xstrdup.o.i","") */
char *xstrdup(char const *string) {
  size_t tmp;
  void *tmp___0;

  {
    {
      tmp = strlen(string);
      tmp___0 = xclone((void const *)string, tmp + 1UL);
    }
    return ((char *)tmp___0);
  }
}
/* #pragma merger("0","02c.xstrtol.o.i","") */
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((
    __leaf__)) __assert_fail)(char const *__assertion, char const *__file,
                              unsigned int __line, char const *__function);
extern __attribute__((__nothrow__)) long(__attribute__((
    __nonnull__(1), __leaf__)) strtol)(char const *__restrict __nptr,
                                       char **__restrict __endptr, int __base);
/* #pragma merger("0","02d.xstrtoul.o.i","") */
static strtol_error bkm_scale___0(unsigned long *x, int scale_factor) {

  {
    if (0xffffffffffffffffUL / (unsigned long)scale_factor < *x) {
      *x = 0xffffffffffffffffUL;
      return ((strtol_error)1);
    }
    *x *= (unsigned long)scale_factor;
    return ((strtol_error)0);
  }
}
static strtol_error bkm_scale_by_power___0(unsigned long *x, int base,
                                           int power) {
  strtol_error err;
  strtol_error tmp;
  int tmp___0;

  {
    err = (strtol_error)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        tmp___0 = power;
        power--;
        if (!tmp___0) {
          goto while_break;
        }
        {
          tmp = bkm_scale___0(x, base);
          err = (strtol_error)((unsigned int)err | (unsigned int)tmp);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return (err);
  }
}
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned short const **tmp___0;
  int *tmp___1;
  char *tmp___2;
  int *tmp___3;
  int *tmp___4;
  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;
  char *tmp___6;

  {
    err = (strtol_error)0;

    if (ptr) {
      p = ptr;
    } else {
      p = &t_ptr;
    }
    q = s;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { tmp___0 = __ctype_b_loc(); }
        if (!((int const) * (*tmp___0 + (int)((unsigned char)*q)) & 8192)) {
          goto while_break;
        }
        q++;
      }
    while_break: /* CIL Label */
        ;
    }
    if ((int const) * q == 45) {
      return ((strtol_error)4);
    }
    {
      tmp___1 = __errno_location();
      *tmp___1 = 0;
      tmp = strtoul((char const * /* __restrict  */)s,
                    (char ** /* __restrict  */)p, strtol_base);
    }
    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {

      } else {
        return ((strtol_error)4);
      }
    } else {
      { tmp___4 = __errno_location(); }
    }

    if ((int)*(*p) != 0) {
      {
        base = 1024;
        suffixes = 1;
        tmp___5 = strchr(valid_suffixes, (int)*(*p));
      }
      if (!tmp___5) {
        *val = tmp;
        return ((strtol_error)((unsigned int)err | 2U));
      }
      { tmp___6 = strchr(valid_suffixes, '0'); }

      {
        if ((int)*(*p) == 98) {
          goto case_98;
        }
        if ((int)*(*p) == 66) {
          goto case_66___0;
        }

        if ((int)*(*p) == 71) {
          goto case_71;
        }
        if ((int)*(*p) == 103) {
          goto case_71;
        }
        if ((int)*(*p) == 107) {
          goto case_107;
        }
        if ((int)*(*p) == 75) {
          goto case_107;
        }
        if ((int)*(*p) == 77) {
          goto case_77;
        }
        if ((int)*(*p) == 109) {
          goto case_77;
        }

        if ((int)*(*p) == 84) {
          goto case_84;
        }

        if ((int)*(*p) == 119) {
          goto case_119;
        }
        if ((int)*(*p) == 89) {
          goto case_89;
        }
        if ((int)*(*p) == 90) {
          goto case_90;
        }
        goto switch_default;
      case_98: { /* CIL Label */
        overflow = bkm_scale___0(&tmp, 512);
      }
        goto switch_break___0;
      case_66___0: { /* CIL Label */
        overflow = bkm_scale___0(&tmp, 1024);
      }
        goto switch_break___0;
      case_99: /* CIL Label */
        overflow = (strtol_error)0;
        goto switch_break___0;
      case_69: { /* CIL Label */
        overflow = bkm_scale_by_power___0(&tmp, base, 6);
      }
        goto switch_break___0;
      case_71:    /* CIL Label */
      case_103: { /* CIL Label */
        overflow = bkm_scale_by_power___0(&tmp, base, 3);
      }
        goto switch_break___0;
      case_107:  /* CIL Label */
      case_75: { /* CIL Label */
        overflow = bkm_scale_by_power___0(&tmp, base, 1);
      }
        goto switch_break___0;
      case_77:    /* CIL Label */
      case_109: { /* CIL Label */
        overflow = bkm_scale_by_power___0(&tmp, base, 2);
      }
        goto switch_break___0;
      case_80: { /* CIL Label */
        overflow = bkm_scale_by_power___0(&tmp, base, 5);
      }
        goto switch_break___0;
      case_84:    /* CIL Label */
      case_116: { /* CIL Label */
        overflow = bkm_scale_by_power___0(&tmp, base, 4);
      }
        goto switch_break___0;
      case_119: { /* CIL Label */
        overflow = bkm_scale___0(&tmp, 2);
      }
        goto switch_break___0;
      case_89: { /* CIL Label */
        overflow = bkm_scale_by_power___0(&tmp, base, 8);
      }
        goto switch_break___0;
      case_90: { /* CIL Label */
        overflow = bkm_scale_by_power___0(&tmp, base, 7);
      }
        goto switch_break___0;
      switch_default: /* CIL Label */
        *val = tmp;
        return ((strtol_error)((unsigned int)err | 2U));
      switch_break___0: /* CIL Label */
          ;
      }
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
      *p += suffixes;
      if (*(*p)) {
        err = (strtol_error)((unsigned int)err | 2U);
      }
    }
    *val = tmp;
    return (err);
  }
}
/* #pragma merger("0","02e.xstrtoumax.o.i","") */
extern __attribute__((__nothrow__))
uintmax_t(__attribute__((__leaf__)) strtoumax)(char const *__restrict __nptr,
                                               char **__restrict __endptr,
                                               int __base);
static strtol_error bkm_scale___1(uintmax_t *x, int scale_factor) {

  {
    if (0xffffffffffffffffUL / (unsigned long)scale_factor < *x) {
      *x = 0xffffffffffffffffUL;
      return ((strtol_error)1);
    }
    *x *= (uintmax_t)scale_factor;
    return ((strtol_error)0);
  }
}
static strtol_error bkm_scale_by_power___1(uintmax_t *x, int base, int power) {
  strtol_error err;
  strtol_error tmp;
  int tmp___0;

  {
    err = (strtol_error)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        tmp___0 = power;
        power--;
        if (!tmp___0) {
          goto while_break;
        }
        {
          tmp = bkm_scale___1(x, base);
          err = (strtol_error)((unsigned int)err | (unsigned int)tmp);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return (err);
  }
}
strtol_error xstrtoumax(char const *s, char **ptr, int strtol_base,
                        uintmax_t *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  uintmax_t tmp;
  strtol_error err;
  char const *q;
  unsigned short const **tmp___0;
  int *tmp___1;
  char *tmp___2;
  int *tmp___3;
  int *tmp___4;
  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;
  char *tmp___6;

  {
    err = (strtol_error)0;
    if (0 <= strtol_base) {

    } else {
      {
        __assert_fail("0 <= strtol_base && strtol_base <= 36",
                      "/home/wslee/project/cbenchmarks/tar-1.14/lib/xstrtol.c",
                      117U, "xstrtoumax");
      }
    }
    if (ptr) {
      p = ptr;
    } else {
      p = &t_ptr;
    }
    q = s;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { tmp___0 = __ctype_b_loc(); }
        if (!((int const) * (*tmp___0 + (int)((unsigned char)*q)) & 8192)) {
          goto while_break;
        }
        q++;
      }
    while_break: /* CIL Label */
        ;
    }

    {
      tmp___1 = __errno_location();
      *tmp___1 = 0;
      tmp = strtoumax((char const * /* __restrict  */)s,
                      (char ** /* __restrict  */)p, strtol_base);
    }
    if ((unsigned long)*p == (unsigned long)s) {

    } else {
      { tmp___4 = __errno_location(); }
      if (*tmp___4 != 0) {
        {
          tmp___3 = __errno_location();
        }
        if (*tmp___3 != 34) {
          return ((strtol_error)4);
        }
        err = (strtol_error)1;
      }
    }
    if (!valid_suffixes) {
      *val = tmp;
      return (err);
    }
    if ((int)*(*p) != 0) {
      {
        base = 1024;
        suffixes = 1;
        tmp___5 = strchr(valid_suffixes, (int)*(*p));
      }
      if (!tmp___5) {
        *val = tmp;
        return ((strtol_error)((unsigned int)err | 2U));
      }
      { tmp___6 = strchr(valid_suffixes, '0'); }
      if (tmp___6) {
        {
          if ((int)*(*(p + 0) + 1) == 105) {
            goto case_105;
          }

          goto switch_break;
        case_105: /* CIL Label */

          goto switch_break;
        case_66: /* CIL Label */
        case_68: /* CIL Label */
          base = 1000;
          suffixes++;
          goto switch_break;
        switch_break: /* CIL Label */
            ;
        }
      }
      {
        if ((int)*(*p) == 98) {
          goto case_98;
        }

        if ((int)*(*p) == 69) {
          goto case_69;
        }
        if ((int)*(*p) == 71) {
          goto case_71;
        }
        if ((int)*(*p) == 103) {
          goto case_71;
        }
        if ((int)*(*p) == 107) {
          goto case_107;
        }
        if ((int)*(*p) == 75) {
          goto case_107;
        }
        if ((int)*(*p) == 77) {
          goto case_77;
        }
        if ((int)*(*p) == 109) {
          goto case_77;
        }

        if ((int)*(*p) == 84) {
          goto case_84;
        }
        if ((int)*(*p) == 116) {
          goto case_84;
        }
        if ((int)*(*p) == 119) {
          goto case_119;
        }
        if ((int)*(*p) == 89) {
          goto case_89;
        }
        if ((int)*(*p) == 90) {
          goto case_90;
        }
        goto switch_default;
      case_98: { /* CIL Label */
        overflow = bkm_scale___1(&tmp, 512);
      }
        goto switch_break___0;
      case_66___0: { /* CIL Label */
        overflow = bkm_scale___1(&tmp, 1024);
      }
        goto switch_break___0;
      case_99: /* CIL Label */
        overflow = (strtol_error)0;
        goto switch_break___0;
      case_69: { /* CIL Label */
        overflow = bkm_scale_by_power___1(&tmp, base, 6);
      }
        goto switch_break___0;
      case_71:    /* CIL Label */
      case_103: { /* CIL Label */
        overflow = bkm_scale_by_power___1(&tmp, base, 3);
      }
        goto switch_break___0;
      case_107:  /* CIL Label */
      case_75: { /* CIL Label */
        overflow = bkm_scale_by_power___1(&tmp, base, 1);
      }
        goto switch_break___0;
      case_77:    /* CIL Label */
      case_109: { /* CIL Label */
        overflow = bkm_scale_by_power___1(&tmp, base, 2);
      }
        goto switch_break___0;
      case_80: { /* CIL Label */
        overflow = bkm_scale_by_power___1(&tmp, base, 5);
      }
        goto switch_break___0;
      case_84:    /* CIL Label */
      case_116: { /* CIL Label */
        overflow = bkm_scale_by_power___1(&tmp, base, 4);
      }
        goto switch_break___0;
      case_119: { /* CIL Label */
        overflow = bkm_scale___1(&tmp, 2);
      }
        goto switch_break___0;
      case_89: { /* CIL Label */
        overflow = bkm_scale_by_power___1(&tmp, base, 8);
      }
        goto switch_break___0;
      case_90: { /* CIL Label */
        overflow = bkm_scale_by_power___1(&tmp, base, 7);
      }
        goto switch_break___0;
      switch_default: /* CIL Label */
        *val = tmp;
        return ((strtol_error)((unsigned int)err | 2U));
      switch_break___0: /* CIL Label */
          ;
      }
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
      *p += suffixes;
      if (*(*p)) {
        err = (strtol_error)((unsigned int)err | 2U);
      }
    }
    *val = tmp;
    return (err);
  }
}
/* #pragma merger("0","../../lib/addext.o.i","") */
/* #pragma merger("0","../../lib/argmatch.o.i","") */
/* #pragma merger("0","../../lib/backupfile.o.i","") */
/* #pragma merger("0","../../lib/basename.o.i","") */
/* #pragma merger("0","../../lib/dirname.o.i","") */
/* #pragma merger("0","../../lib/exclude.o.i","") */
/* #pragma merger("0","../../lib/exitfail.o.i","") */
/* #pragma merger("0","../../lib/full-write.o.i","") */
/* #pragma merger("0","../../lib/getdate.o.i","") */
/* #pragma merger("0","../../lib/getopt1.o.i","") */
/* #pragma merger("0","../../lib/getopt.o.i","") */
/* #pragma merger("0","../../lib/gettime.o.i","") */
/* #pragma merger("0","../../lib/hash.o.i","") */
/* #pragma merger("0","../../lib/human.o.i","") */
/* #pragma merger("0","../../lib/mktime.o.i","") */
/* #pragma merger("0","../../lib/modechange.o.i","") */
/* #pragma merger("0","../../lib/prepargs.o.i","") */
/* #pragma merger("0","../../lib/quotearg.o.i","") */
/* #pragma merger("0","../../lib/quote.o.i","") */
/* #pragma merger("0","../../lib/safe-read.o.i","") */
/* #pragma merger("0","../../lib/safe-write.o.i","") */
/* #pragma merger("0","../../lib/save-cwd.o.i","") */
/* #pragma merger("0","../../lib/savedir.o.i","") */
/* #pragma merger("0","../../lib/stripslash.o.i","") */
/* #pragma merger("0","../../lib/xgetcwd.o.i","") */
/* #pragma merger("0","../../lib/xmalloc.o.i","") */
/* #pragma merger("0","../../lib/xstrdup.o.i","") */
/* #pragma merger("0","../../lib/xstrtol.o.i","") */
/* #pragma merger("0","../../lib/xstrtoul.o.i","") */
/* #pragma merger("0","../../lib/xstrtoumax.o.i","") */
