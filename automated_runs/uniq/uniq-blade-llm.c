typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef unsigned long size_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __uid_t uid_t;
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
typedef __ino_t ino_t;
typedef __dev_t dev_t;
struct di_set;
struct di_set;
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
struct ino_map;
struct ino_map;
typedef size_t hashint;

typedef unsigned long uintmax_t;
struct dev_ino {
  ino_t st_ino;
  dev_t st_dev;
};

typedef long __off64_t;
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
typedef __off_t off_t;
struct cd_buf {
  int fd;
};
typedef long __ssize_t;
typedef __ssize_t ssize_t;
struct allocator;
struct allocator;
struct allocator {
  void *(*allocate)(size_t);
  void *(*reallocate)(void *, size_t);
  void (*free)(void *);
  void (*die)(size_t);
};
typedef long ptrdiff_t;
enum canonicalize_mode_t { CAN_EXISTING = 0, CAN_ALL_BUT_LAST = 1, CAN_MISSING = 2, CAN_NOLINKS = 4 };
typedef enum canonicalize_mode_t canonicalize_mode_t;
typedef unsigned int __socklen_t;
typedef __socklen_t socklen_t;
typedef unsigned short sa_family_t;

struct addrinfo {
  int ai_flags;
  int ai_family;
  int ai_socktype;
  int ai_protocol;
  socklen_t ai_addrlen;
  struct sockaddr *ai_addr;
  char *ai_canonname;
  struct addrinfo *ai_next;
};
struct __locale_data;
struct __locale_data;
struct __locale_struct {
  struct __locale_data *__locales[13];
  unsigned short const *__ctype_b;
  int const *__ctype_tolower;
  int const *__ctype_toupper;
  char const *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;

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
enum numbered_backup_result { BACKUP_IS_SAME_LENGTH = 0, BACKUP_IS_LONGER = 1, BACKUP_IS_NEW = 2 };
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
struct argv_iterator;
struct argv_iterator;
enum argv_iter_err { AI_ERR_OK = 1, AI_ERR_EOF = 2, AI_ERR_MEM = 3, AI_ERR_READ = 4 };

enum quoting_style { literal_quoting_style = 0, shell_quoting_style = 1, shell_always_quoting_style = 2, c_quoting_style = 3, c_maybe_quoting_style = 4, escape_quoting_style = 5, locale_quoting_style = 6, clocale_quoting_style = 7, custom_quoting_style = 8 };
enum strtol_error { LONGINT_OK = 0, LONGINT_OVERFLOW = 1, LONGINT_INVALID_SUFFIX_CHAR = 2, LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3, LONGINT_INVALID = 4 };
typedef enum strtol_error strtol_error;
struct option {
  char const *name;
  int has_arg;
  int *flag;
  int val;
};
typedef long intmax_t;
typedef void *iconv_t;
typedef __nlink_t nlink_t;
struct I_ring {
  int ir_data[4];
  int ir_default_val;
  unsigned int ir_front;
  unsigned int ir_back;
  _Bool ir_empty;
};
typedef struct I_ring I_ring;
struct _ftsent;
struct _ftsent;
union __anonunion_fts_cycle_25 {
  struct hash_table *ht;
  struct cycle_check_state *state;
};
struct __anonstruct_FTS_24 {
  struct _ftsent *fts_cur;
  struct _ftsent *fts_child;
  struct _ftsent **fts_array;
  dev_t fts_dev;
  char *fts_path;
  int fts_rfd;
  int fts_cwd_fd;
  size_t fts_pathlen;
  size_t fts_nitems;
  int (*fts_compar)(struct _ftsent const **, struct _ftsent const **);
  int fts_options;
  struct hash_table *fts_leaf_optimization_works_ht;
  union __anonunion_fts_cycle_25 fts_cycle;
  I_ring fts_fd_ring;
};
typedef struct __anonstruct_FTS_24 FTS;
struct _ftsent {
  struct _ftsent *fts_cycle;
  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;
  DIR *fts_dirp;
  long fts_number;
  void *fts_pointer;
  char *fts_accpath;
  char *fts_path;
  int fts_errno;
  int fts_symfd;
  size_t fts_pathlen;
  FTS *fts_fts;
  ptrdiff_t fts_level;
  size_t fts_namelen;
  nlink_t fts_n_dirs_remaining;
  unsigned short fts_info;
  unsigned short fts_flags;
  unsigned short fts_instr;
  struct stat fts_statp[1];
  char fts_name[1];
};
typedef struct _ftsent FTSENT;
typedef unsigned int uint32_t;
typedef uint32_t ucs4_t;
typedef int __pid_t;
typedef __pid_t pid_t;
typedef int __sig_atomic_t;
typedef __sig_atomic_t sig_atomic_t;
struct __anonstruct_slaves_entry_t_50 {
  sig_atomic_t volatile used;
  pid_t volatile child;
};
typedef struct __anonstruct_slaves_entry_t_50 slaves_entry_t;

union __anonunion_53 {
  int __in;
  int __i;
};
union __anonunion_54 {
  int __in;
  int __i;
};

union __anonunion_56 {
  int __in;
  int __i;
};

typedef int wchar_t;
typedef int nl_item;
typedef unsigned int wint_t;
enum __anonenum_arg_type_27 {
  TYPE_NONE = 0,
  TYPE_SCHAR = 1,
  TYPE_UCHAR = 2,
  TYPE_SHORT = 3,
  TYPE_USHORT = 4,
  TYPE_INT = 5,
  TYPE_UINT = 6,
  TYPE_LONGINT = 7,
  TYPE_ULONGINT = 8,
  TYPE_LONGLONGINT = 9,
  TYPE_ULONGLONGINT = 10,
  TYPE_DOUBLE = 11,
  TYPE_LONGDOUBLE = 12,
  TYPE_CHAR = 13,
  TYPE_WIDE_CHAR = 14,
  TYPE_STRING = 15,
  TYPE_WIDE_STRING = 16,
  TYPE_POINTER = 17,
  TYPE_COUNT_SCHAR_POINTER = 18,
  TYPE_COUNT_SHORT_POINTER = 19,
  TYPE_COUNT_INT_POINTER = 20,
  TYPE_COUNT_LONGINT_POINTER = 21,
  TYPE_COUNT_LONGLONGINT_POINTER = 22
};
typedef enum __anonenum_arg_type_27 arg_type;
union __anonunion_a_29 {
  signed char a_schar;
  unsigned char a_uchar;
  short a_short;
  unsigned short a_ushort;
  int a_int;
  unsigned int a_uint;
  long a_longint;
  unsigned long a_ulongint;
  long long a_longlongint;
  unsigned long long a_ulonglongint;
  float a_float;
  double a_double;
  long double a_longdouble;
  int a_char;
  wint_t a_wide_char;
  char const *a_string;
  wchar_t const *a_wide_string;
  void *a_pointer;
  signed char *a_count_schar_pointer;
  short *a_count_short_pointer;
  int *a_count_int_pointer;
  long *a_count_longint_pointer;
  long long *a_count_longlongint_pointer;
};
struct __anonstruct_argument_28 {
  arg_type type;
  union __anonunion_a_29 a;
};
typedef struct __anonstruct_argument_28 argument;

typedef struct __anonstruct_arguments_30 arguments;
struct __anonstruct_char_directive_31 {
  char const *dir_start;
  char const *dir_end;
  int flags;
  char const *width_start;
  char const *width_end;
  size_t width_arg_index;
  char const *precision_start;
  char const *precision_end;
  size_t precision_arg_index;
  char conversion;
  size_t arg_index;
};
typedef struct __anonstruct_char_directive_31 char_directive;
struct __anonstruct_char_directives_32 {
  size_t count;
  char_directive *dir;
  size_t max_width_length;
  size_t max_precision_length;
  char_directive direct_alloc_dir[7];
};
typedef struct __anonstruct_char_directives_32 char_directives;
typedef unsigned short fpucw_t;

typedef long __suseconds_t;

struct fs_res {
  dev_t dev;
  int resolution;
  _Bool exact;
};

typedef unsigned char uint8_t;
union __anonunion___value_23 {
  unsigned int __wch;
  char __wchb[4];
};
struct __anonstruct___mbstate_t_22 {
  int __count;
  union __anonunion___value_23 __value;
};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
typedef __mbstate_t mbstate_t;
struct mbchar {
  char const *ptr;
  size_t bytes;
  _Bool wc_valid;
  wchar_t wc;
  char buf[24];
};
struct mbiter_multi {
  char const *limit;
  _Bool in_shift;
  mbstate_t state;
  _Bool next_done;
  struct mbchar cur;
};
typedef struct mbiter_multi mbi_iterator_t;
typedef uintmax_t randint;
struct randint_source;
struct randint_source;

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
struct __anonstruct___sigset_t_9 {
  unsigned long __val[1024UL / (8UL * sizeof(unsigned long))];
};
typedef struct __anonstruct___sigset_t_9 __sigset_t;
typedef __sigset_t sigset_t;
struct sched_param {
  int __sched_priority;
};
struct __anonstruct_posix_spawnattr_t_50 {
  short __flags;
  pid_t __pgrp;
  sigset_t __sd;
  sigset_t __ss;
  struct sched_param __sp;
  int __policy;
  int __pad[16];
};
typedef struct __anonstruct_posix_spawnattr_t_50 posix_spawnattr_t;
struct __spawn_action;
struct __spawn_action;

typedef struct __anonstruct_posix_spawn_file_actions_t_51 posix_spawn_file_actions_t;
struct numname {
  int num;
  char const name[8];
};
typedef unsigned long uint64_t;
typedef uint64_t u64;

struct sha1_ctx {
  uint32_t A;
  uint32_t B;
  uint32_t C;
  uint32_t D;
  uint32_t E;
  uint32_t total[2];
  uint32_t buflen;
  uint32_t buffer[32];
};
typedef int __clockid_t;
typedef __clockid_t clockid_t;

enum __anonenum_state_14 { INITIAL_STATE = 0, FD_STATE = 1, FD_POST_CHDIR_STATE = 2, FORKING_STATE = 3, ERROR_STATE = 4, FINAL_STATE = 5 };
union __anonunion_val_15 {
  int fd;
  int errnum;
  pid_t child;
};
struct savewd {
  enum __anonenum_state_14 state;
  union __anonunion_val_15 val;
};
union __anonunion_52___0 {
  int __in;
  int __i;
};

typedef int __int32_t;
struct __exit_status {
  short e_termination;
  short e_exit;
};

typedef struct utmpx STRUCT_UTMP;
struct obstack;
struct obstack;
struct _obstack_chunk {
  char *limit;
  struct _obstack_chunk *prev;
  char contents[4];
};
union __anonunion_temp_26 {
  long tempint;
  void *tempptr;
};
struct obstack {
  long chunk_size;
  struct _obstack_chunk *chunk;
  char *object_base;
  char *next_free;
  char *chunk_limit;
  union __anonunion_temp_26 temp;
  int alignment_mask;
  struct _obstack_chunk *(*chunkfun)(void *, long);
  void (*freefun)(void *, struct _obstack_chunk *);
  void *extra_arg;
  unsigned int use_extra_arg : 1;
  unsigned int maybe_empty_object : 1;
  unsigned int alloc_failed : 1;
};
struct tokenbuffer {
  size_t size;
  char *buffer;
};
typedef struct tokenbuffer token_buffer;
typedef size_t word;
struct randread_source;
struct randread_source;
typedef unsigned long uint_least64_t;
typedef struct timezone *__restrict __timezone_ptr_t;
typedef uint_least64_t isaac_word;
struct isaac_state {
  isaac_word m[1 << 8];
  isaac_word a;
  isaac_word b;
  isaac_word c;
};
union __anonunion_data_31 {
  isaac_word w[1 << 8];
  unsigned char b[(unsigned long)(1 << 8) * sizeof(isaac_word)];
};
struct isaac {
  size_t buffered;
  struct isaac_state state;
  union __anonunion_data_31 data;
};
union __anonunion_buf_30 {
  char c[2UL * ((unsigned long)(1 << 8) * sizeof(isaac_word))];
  struct isaac isaac;
};

typedef Hash_table sparse_map;

struct quoting_options;
struct quoting_options;
struct quoting_options {
  enum quoting_style style;
  int flags;
  unsigned int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
  char const *left_quote;
  char const *right_quote;
};
struct slotvec {
  size_t size;
  char *val;
};
typedef struct mbchar mbchar_t;
struct mbuiter_multi {
  _Bool in_shift;
  mbstate_t state;
  _Bool next_done;
  struct mbchar cur;
};
typedef struct mbuiter_multi mbui_iterator_t;
typedef long long_time_t;
struct __anonstruct_textint_27 {
  _Bool negative;
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
struct __anonstruct_relative_time_31 {
  long year;
  long month;
  long day;
  long hour;
  long minutes;
  long_time_t seconds;
  long ns;
};
typedef struct __anonstruct_relative_time_31 relative_time;

typedef struct __anonstruct_parser_control_32 parser_control;
union YYSTYPE;
union YYSTYPE;
union YYSTYPE {
  long intval;
  textint textintval;
  struct timespec timespec;
  relative_time rel;
};
typedef union YYSTYPE YYSTYPE;
typedef unsigned char yytype_uint8;
typedef signed char yytype_int8;
typedef short yytype_int16;
union yyalloc {
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};
enum nproc_query { NPROC_ALL = 0, NPROC_CURRENT = 1, NPROC_CURRENT_OVERRIDABLE = 2 };
typedef unsigned long __cpu_mask;

typedef struct __anonstruct_cpu_set_t_24 cpu_set_t;

struct mode_change;
struct mode_change;

typedef unsigned long longword;

typedef enum __anonenum_mbs_align_t_1 mbs_align_t;
typedef unsigned long uintptr_t;
struct preliminary_header {
  void *next;
  char room[sizeof(int)];
};
struct header {
  void *next;
};
struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  short __spins;
  short __elision;
  __pthread_list_t __list;
};
union __anonunion_pthread_mutex_t_11 {
  struct __pthread_mutex_s __data;
  char __size[40];
  long __align;
};
typedef union __anonunion_pthread_mutex_t_11 pthread_mutex_t;
union __anonunion_pthread_mutexattr_t_12 {
  char __size[4];
  int __align;
};
typedef union __anonunion_pthread_mutexattr_t_12 pthread_mutexattr_t;
typedef int pthread_once_t;
typedef pthread_mutex_t gl_recursive_lock_t;
struct linebuffer {
  size_t size;
  size_t length;
  char *buffer;
};

typedef union __anonunion_memory_double_1 memory_double;
struct ino_map_ent {
  ino_t ino;
  size_t mapped_ino;
};

struct heap;
struct heap;
struct heap {
  void **array;
  size_t capacity;
  size_t count;
  int (*compare)(void const *, void const *);
};
struct hash_entry {
  void *data;
  struct hash_entry *next;
};

struct F_triple {
  char *name;
  ino_t st_ino;
  dev_t st_dev;
};
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

typedef long long xtime_t;
struct __anonstruct___fsid_t_1 {
  int __val[2];
};
typedef struct __anonstruct___fsid_t_1 __fsid_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsfilcnt_t;
typedef long __fsword_t;
struct Active_dir {
  dev_t dev;
  ino_t ino;
  FTSENT *fts_ent;
};
struct statfs {
  __fsword_t f_type;
  __fsword_t f_bsize;
  __fsblkcnt_t f_blocks;
  __fsblkcnt_t f_bfree;
  __fsblkcnt_t f_bavail;
  __fsfilcnt_t f_files;
  __fsfilcnt_t f_ffree;
  __fsid_t f_fsid;
  __fsword_t f_namelen;
  __fsword_t f_frsize;
  __fsword_t f_flags;
  __fsword_t f_spare[4];
};
struct LCO_ent {
  dev_t st_dev;
  _Bool opt_ok;
};
struct fs_usage {
  uintmax_t fsu_blocksize;
  uintmax_t fsu_blocks;
  uintmax_t fsu_bfree;
  uintmax_t fsu_bavail;
  _Bool fsu_bavail_top_bit_set;
  uintmax_t fsu_files;
  uintmax_t fsu_ffree;
};
typedef long __clock_t;
union sigval {
  int sival_int;
  void *sival_ptr;
};
typedef union sigval sigval_t;
typedef __clock_t __sigchld_clock_t;
struct __anonstruct__kill_23 {
  __pid_t si_pid;
  __uid_t si_uid;
};
struct __anonstruct__timer_24 {
  int si_tid;
  int si_overrun;
  sigval_t si_sigval;
};
struct __anonstruct__rt_25 {
  __pid_t si_pid;
  __uid_t si_uid;
  sigval_t si_sigval;
};
struct __anonstruct__sigchld_26 {
  __pid_t si_pid;
  __uid_t si_uid;
  int si_status;
  __sigchld_clock_t si_utime;
  __sigchld_clock_t si_stime;
};
struct __anonstruct__sigfault_27 {
  void *si_addr;
  short si_addr_lsb;
};
struct __anonstruct__sigpoll_28 {
  long si_band;
  int si_fd;
};
struct __anonstruct__sigsys_29 {
  void *_call_addr;
  int _syscall;
  unsigned int _arch;
};
union __anonunion__sifields_22 {
  int _pad[128UL / sizeof(int) - 4UL];
  struct __anonstruct__kill_23 _kill;
  struct __anonstruct__timer_24 _timer;
  struct __anonstruct__rt_25 _rt;
  struct __anonstruct__sigchld_26 _sigchld;
  struct __anonstruct__sigfault_27 _sigfault;
  struct __anonstruct__sigpoll_28 _sigpoll;
  struct __anonstruct__sigsys_29 _sigsys;
};
struct __anonstruct_siginfo_t_21 {
  int si_signo;
  int si_errno;
  int si_code;
  union __anonunion__sifields_22 _sifields;
};
typedef struct __anonstruct_siginfo_t_21 siginfo_t;
union __anonunion___sigaction_handler_41 {
  void (*sa_handler)(int);
  void (*sa_sigaction)(int, siginfo_t *, void *);
};
struct sigaction {
  union __anonunion___sigaction_handler_41 __sigaction_handler;
  __sigset_t sa_mask;
  int sa_flags;
  void (*sa_restorer)(void);
};
typedef void (*sa_handler_t)(int);
struct __anonstruct_actions_entry_t_50 {
  void (*volatile action)(void);
};
typedef struct __anonstruct_actions_entry_t_50 actions_entry_t;
enum __anonenum_fadvice_t_19 { FADVISE_NORMAL = 0, FADVISE_SEQUENTIAL = 2, FADVISE_NOREUSE = 5, FADVISE_DONTNEED = 4, FADVISE_WILLNEED = 3, FADVISE_RANDOM = 1 };
typedef enum __anonenum_fadvice_t_19 fadvice_t;
struct exclude;
struct exclude;
struct patopts {
  char const *pattern;
  int options;
};
struct exclude_pattern {
  struct patopts *exclude;
  size_t exclude_alloc;
  size_t exclude_count;
};
enum exclude_type { exclude_hash = 0, exclude_pattern = 1 };
union __anonunion_v_29 {
  Hash_table *table;
  struct exclude_pattern pat;
};
struct exclude_segment {
  struct exclude_segment *next;
  enum exclude_type type;
  int options;
  union __anonunion_v_29 v;
};

enum countmode { count_occurrences = 0, count_none = 1 };
enum delimit_method { DM_NONE = 0, DM_PREPEND = 1, DM_SEPARATE = 2 };
enum Skip_field_option_type { SFO_NONE = 0, SFO_OBSOLETE = 1, SFO_NEW = 2 };
extern __attribute__((__nothrow__)) int snprintf(char *__restrict __s, size_t __maxlen, char const *__restrict __format, ...);
extern __attribute__((__nothrow__)) double(__attribute__((__nonnull__(1), __leaf__)) strtod)(char const *__restrict __nptr, char **__restrict __endptr);
__attribute__((__noreturn__)) void xalloc_die(void);
char *last_component(char const *name) __attribute__((__pure__));
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int *(__attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file, struct stat *__restrict __buf);

extern int close(int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) chown)(char const *__file, __uid_t __owner, __gid_t __group);

char const diacrit_base[256];
char const diacrit_diac[256];
char const diacrit_base[256] = {
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)'A', (char const)'B', (char const)'C', (char const)'D', (char const)'E', (char const)'F', (char const)'G', (char const)'H', (char const)'I', (char const)'J', (char const)'K', (char const)'L', (char const)'M', (char const)'N', (char const)'O',
    (char const)'P', (char const)'Q', (char const)'R', (char const)'S', (char const)'T', (char const)'U', (char const)'V', (char const)'W', (char const)'X', (char const)'Y', (char const)'Z', (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)'a', (char const)'b', (char const)'c', (char const)'d', (char const)'e', (char const)'f', (char const)'g', (char const)'h', (char const)'i', (char const)'j', (char const)'k', (char const)'l', (char const)'m', (char const)'n', (char const)'o',
    (char const)'p', (char const)'q', (char const)'r', (char const)'s', (char const)'t', (char const)'u', (char const)'v', (char const)'w', (char const)'x', (char const)'y', (char const)'z', (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)'A', (char const)'A', (char const)'A', (char const)'A', (char const)'A', (char const)'A', (char const)'A', (char const)'C', (char const)'E', (char const)'E', (char const)'E', (char const)'E', (char const)'I', (char const)'I', (char const)'I', (char const)'I',
    (char const)0,   (char const)'N', (char const)'O', (char const)'O', (char const)'O', (char const)'O', (char const)'O', (char const)0,   (char const)'O', (char const)'U', (char const)'U', (char const)'U', (char const)'U', (char const)'Y', (char const)0,   (char const)0,
    (char const)'a', (char const)'a', (char const)'a', (char const)'a', (char const)'a', (char const)'a', (char const)'a', (char const)'c', (char const)'e', (char const)'e', (char const)'e', (char const)'e', (char const)'i', (char const)'i', (char const)'i', (char const)'i',
    (char const)0,   (char const)'n', (char const)'o', (char const)'o', (char const)'o', (char const)'o', (char const)'o', (char const)0,   (char const)'o', (char const)'u', (char const)'u', (char const)'u', (char const)'u', (char const)'y', (char const)0,   (char const)'y'};
char const diacrit_diac[256] = {
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)4,
    (char const)0, (char const)3, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)6, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)3, (char const)2, (char const)4, (char const)6, (char const)5, (char const)8, (char const)1, (char const)7, (char const)3, (char const)2, (char const)4, (char const)5, (char const)3, (char const)2, (char const)4, (char const)5, (char const)0,
    (char const)6, (char const)3, (char const)2, (char const)4, (char const)6, (char const)5, (char const)0, (char const)9, (char const)3, (char const)2, (char const)4, (char const)5, (char const)2, (char const)0, (char const)0, (char const)3, (char const)2, (char const)4, (char const)6,
    (char const)5, (char const)8, (char const)1, (char const)7, (char const)3, (char const)2, (char const)4, (char const)5, (char const)3, (char const)2, (char const)4, (char const)5, (char const)0, (char const)6, (char const)3, (char const)2, (char const)4, (char const)6, (char const)5,
    (char const)0, (char const)9, (char const)3, (char const)2, (char const)4, (char const)5, (char const)2, (char const)0, (char const)0};
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(void *__ptr);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) __assert_fail)(char const *__assertion, char const *__file, unsigned int __line, char const *__function);
extern int(__attribute__((__nonnull__(1))) creat)(char const *__file, mode_t __mode);
extern void error(int __status, int __errnum, char const *__format, ...);
char const *quote(char const *name);

void close_stdout(void);
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern __attribute__((__noreturn__)) void _exit(int __status);
int close_stream(FILE *stream);
int volatile exit_failure;
char *quotearg_colon(char const *arg);
static char const *file_name;
static _Bool ignore_EPIPE;
void close_stdout(void) {
  char const *write_error;
  char const *tmp;
  int tmp___3;
  int *tmp___4;
  int tmp___5;

  {
    { tmp___3 = close_stream(stdout); }
    if (tmp___3 != 0) {
      if (ignore_EPIPE) {
        {
          tmp___4 = __errno_location();
        }

      } else {
      _L: {
        tmp = (char const *)gettext("write error");
        write_error = tmp;
      }

        { _exit((int)exit_failure); }
      }
    }
    { tmp___5 = close_stream(stderr); }
    if (tmp___5 != 0) {
      {
        _exit((int)exit_failure);
      }
    }
    return;
  }
}
extern struct _IO_FILE *stdin;
int rpl_fflush(FILE *stream);
int(__attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp, off_t offset, int whence);
static char const *file_name___0;

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);

int close_stream(FILE *stream) {
  _Bool some_pending;
  size_t tmp;
  _Bool prev_fail;
  int tmp___0;
  _Bool fclose_fail;
  int tmp___1;
  int *tmp___2;
  int *tmp___3;

  {
    {
      tmp = __fpending(stream);
      some_pending = (_Bool)(tmp != 0UL);
      tmp___0 = ferror_unlocked(stream);
      prev_fail = (_Bool)(tmp___0 != 0);
      tmp___1 = rpl_fclose(stream);
      fclose_fail = (_Bool)(tmp___1 != 0);
    }
    if (prev_fail) {
      goto _L___0;
    } else {
      if (fclose_fail) {
        if (some_pending) {
          goto _L___0;
        } else {
          { tmp___3 = __errno_location(); }
          if (*tmp___3 != 9) {
          _L___0:
            if (!fclose_fail) {
              {
                tmp___2 = __errno_location();
                *tmp___2 = 0;
              }
            }
            return (-1);
          }
        }
      }
    }
    return (0);
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchdir)(int __fd);
extern int(__attribute__((__nonnull__(2))) openat)(int __fd, char const *__file, int __oflag, ...);

extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s) __attribute__((__pure__));
extern __attribute__((__nothrow__)) ssize_t(__attribute__((__nonnull__(1, 2), __leaf__)) readlink)(char const *__restrict __path, char *__restrict __buf, size_t __len);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) abort)(void);
struct allocator const stdlib_allocator;
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memmove)(void *__dest, void const *__src, size_t __n);

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file, struct stat *__restrict __buf);
void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strdup)(char const *__s) __attribute__((__malloc__));

extern __attribute__((__nothrow__)) char const *(__attribute__((__leaf__)) gai_strerror)(int __ecode);
static int last_cherror;
static struct addrinfo hints;

static locale_t volatile c_locale_cache;

static locale_t volatile c_locale_cache___0;
int c_tolower(int c) __attribute__((__const__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));

int c_tolower(int c) __attribute__((__const__));
char *last_component(char const *name) __attribute__((__pure__));

char const *simple_backup_suffix;
void (*argmatch_die)(void);
ptrdiff_t __xargmatch_internal(char const *context, char const *arg, char const *const *arglist, char const *vallist, size_t valsize, void (*exit_fn)(void));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2, size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) long(__attribute__((__nonnull__(1), __leaf__)) pathconf)(char const *__path, int __name);
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
char const *simple_backup_suffix = "~";

extern __ssize_t getdelim(char **__restrict __lineptr, size_t *__restrict __n, int __delimiter, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) feof)(FILE *__stream);

void argmatch_invalid(char const *context, char const *value, ptrdiff_t problem);

extern int fprintf(FILE *__restrict __stream, char const *__restrict __format, ...);
extern int putc_unlocked(int __c, FILE *__stream);

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strncmp)(char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char const *quote_n(int n, char const *name);
__attribute__((__noreturn__)) void usage(int status);
static void __argmatch_die(void) {

  {
    { usage(1); }
    return;
  }
}
void (*argmatch_die)(void) = &__argmatch_die;
ptrdiff_t argmatch(char const *arg, char const *const *arglist, char const *vallist, size_t valsize) __attribute__((__pure__));

struct allocator const stdlib_allocator = {(void *(*)(size_t))(&malloc), (void *(*)(void *, size_t))(&realloc), (void (*)(void *))(&free), (void (*)(size_t))((void *)0)};

extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n, FILE *__restrict __stream);
__inline static void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__, __alloc_size__(1, 2)));
__inline static void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__, __alloc_size__(1, 2)));

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base, unsigned long *val, char const *valid_suffixes);
extern __attribute__((__nothrow__)) unsigned long(__attribute__((__nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr, char **__restrict __endptr, int __base);

extern __attribute__((__nothrow__)) long(__attribute__((__nonnull__(1), __leaf__)) strtol)(char const *__restrict __nptr, char **__restrict __endptr, int __base);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ferror)(FILE *__stream);
int memcoll(char *s1, size_t s1len, char *s2, size_t s2len);
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg, size_t argsize);
int xmemcoll(char *s1, size_t s1len, char *s2, size_t s2len);
int xmemcoll(char *s1, size_t s1len, char *s2, size_t s2len) {
  int diff;
  int tmp;
  int collation_errno;
  int *tmp___0;

  {
    {
      tmp = memcoll(s1, s1len, s2, s2len);
      diff = tmp;
      tmp___0 = __errno_location();
      collation_errno = *tmp___0;
    }
    if (collation_errno) {
      {
      }
    }
    return (diff);
  }
}
void *x2realloc(void *p, size_t *pn);
__inline static void *x2nrealloc(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {
    n = *pn;
    if (!p) {
      if (!n) {
        n = 128UL / s;
        n += (size_t)(!n);
      }
    } else {

      n += (n + 1UL) / 2UL;
    }
    {
      *pn = n;
      tmp = xrealloc(p, n * s);
    }
    return (tmp);
  }
}
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) calloc)(size_t __nmemb, size_t __size) __attribute__((__malloc__));

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
void *xrealloc(void *p, size_t n) {

  {
    { p = realloc(p, n); }
    if (!p) {
      if (n) {
        {
          xalloc_die();
        }
      }
    }
    return (p);
  }
}
void *x2realloc(void *p, size_t *pn) {
  void *tmp;

  {
    { tmp = x2nrealloc(p, pn, (size_t)1); }
    return (tmp);
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) gethostname)(char *__name, size_t __len);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) getcwd)(char *__buf, size_t __size);
FILE *freopen_safer(char const *name, char const *mode, FILE *f);
__attribute__((__noreturn__)) void xalloc_die(void);
void xalloc_die(void) {
  char *tmp;

  {
    {
      tmp = gettext("memory exhausted");
      error((int)exit_failure, 0, "%s", tmp);
      abort();
    }
  }
}
extern __attribute__((__nothrow__)) __uid_t(__attribute__((__leaf__)) geteuid)(void);
static _Bool initialized;
static _Bool can_write;
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2) __attribute__((__pure__));

static signed char const nonspacing_table_ind[240] = {
    (signed char const)0,    (signed char const)1,    (signed char const)2,    (signed char const)3,    (signed char const)4,    (signed char const)5,    (signed char const)6,    (signed char const)7,    (signed char const)8,    (signed char const)9,    (signed char const) - 1,
    (signed char const)10,   (signed char const)11,   (signed char const)12,   (signed char const)13,   (signed char const) - 1, (signed char const)14,   (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const)15,   (signed char const) - 1, (signed char const)16,   (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const)17,   (signed char const)18,   (signed char const)19,   (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const)20,   (signed char const) - 1, (signed char const)21,   (signed char const)22,   (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const)23,   (signed char const) - 1, (signed char const) - 1, (signed char const)24,   (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1,
    (signed char const) - 1, (signed char const)25,   (signed char const)26,   (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1, (signed char const) - 1};

extern __pid_t waitpid(__pid_t __pid, int *__stat_loc, int __options);
static slaves_entry_t static_slaves[32];

static int volatile slaves_count = (int volatile)0;

static _Bool cleanup_slaves_registered = (_Bool)0;
extern size_t fwrite(void const *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __s);
extern int printf(char const *__restrict __format, ...);
char const version_etc_copyright[47];

extern void error_at_line(int __status, int __errnum, char const *__fname, unsigned int __lineno, char const *__format, ...);

static int utimensat_works_really;

static int utimensat_works_really___0;
static int lutimensat_works_really;
static Hash_table *ht;
static struct fs_res *new_dst_res;
extern void endpwent(void);
extern struct passwd *getpwnam(char const *__name);
extern void endgrent(void);
extern struct group *getgrgid(__gid_t __gid);
extern struct group *getgrnam(char const *__name);
static char const *E_invalid_user = "invalid user";
static char const *E_invalid_group = "invalid group";
static char const *E_bad_spec = "invalid spec";
extern iconv_t iconv_open(char const *__tocode, char const *__fromcode);
extern size_t iconv(iconv_t __cd, char **__restrict __inbuf, size_t *__restrict __inbytesleft, char **__restrict __outbuf, size_t *__restrict __outbytesleft);
char const *locale_charset(void);
static int initialized___0;
static int is_utf8;
static iconv_t utf8_to_local;

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) mbsinit)(mbstate_t const *__ps) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrtowc)(wchar_t *__restrict __pwc, char const *__restrict __s, size_t __n, mbstate_t *__restrict __p);

unsigned int const is_basic_table[8];
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
extern int(__attribute__((__nonnull__(1))) open)(char const *__file, int __oflag, ...);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) mkdir)(char const *__path, __mode_t __mode);

extern int iconv_close(iconv_t __cd);

extern char **environ;
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) sigprocmask)(int __how, sigset_t const *__restrict __set, sigset_t *__restrict __oset);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) posix_spawnattr_init)(posix_spawnattr_t *__attr);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) posix_spawnattr_destroy)(posix_spawnattr_t *__attr);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) posix_spawnattr_setflags)(posix_spawnattr_t *_attr, short __flags);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) posix_spawn_file_actions_init)(posix_spawn_file_actions_t *__file_actions);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) posix_spawn_file_actions_addclose)(posix_spawn_file_actions_t *__file_actions, int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) posix_spawn_file_actions_adddup2)(posix_spawn_file_actions_t *__file_actions, int __fd, int __newfd);

extern __attribute__((__nothrow__)) int sprintf(char *__restrict __s, char const *__restrict __format, ...);

extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) feof_unlocked)(FILE *__stream);
static unsigned char const fillbuf[128] = {(unsigned char const)128, (unsigned char const)0};

static unsigned char const fillbuf___1[64] = {(unsigned char const)128, (unsigned char const)0};

extern __attribute__((__nothrow__)) __pid_t fork(void);
extern DIR *fdopendir(int __fd);
extern ssize_t write(int __fd, void const *__buf, size_t __n);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) unlink)(char const *__name);

extern void setutxent(void);
extern void endutxent(void);
extern struct utmpx *getutxent(void);
extern int utmpxname(char const *__file);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strncpy)(char *__restrict __dest, char const *__restrict __src, size_t __n);
extern int fgetc(FILE *__stream);
extern void _obstack_newchunk(struct obstack *, int);
extern int _obstack_begin(struct obstack *, int, int, void *(*)(long), void (*)(void *));
extern void obstack_free(struct obstack *obstack, void *block);
extern int getc_unlocked(FILE *__stream);
extern FILE *fopen(char const *__restrict __filename, char const *__restrict __modes);
extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern __off_t ftello(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) setvbuf)(FILE *__restrict __stream, char *__restrict __buf, int __modes, size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) gettimeofday)(struct timeval *__restrict __tv, __timezone_ptr_t __tz);

extern __attribute__((__nothrow__)) __uid_t(__attribute__((__leaf__)) getuid)(void);

enum quoting_style const quoting_style_vals[8];
int set_char_quoting(struct quoting_options *o, char c, int i);
char *quotearg_char(char const *arg, char ch);
char *quotearg_char_mem(char const *arg, size_t argsize, char ch);
struct quoting_options quote_quoting_options;
__inline static char *xcharalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));

char const *const quoting_style_args[9] = {(char const * /* const  */) "literal", (char const * /* const  */) "shell",  (char const * /* const  */) "shell-always", (char const * /* const  */) "c", (char const * /* const  */) "c-maybe",
                                           (char const * /* const  */) "escape",  (char const * /* const  */) "locale", (char const * /* const  */) "clocale",      (char const * /* const  */)0};

static struct quoting_options default_quoting_options;

static char slot0[256];
static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;

char const *quote_n(int n, char const *name) {
  char const *tmp;

  { return (tmp); }
}
char const *quote(char const *name) {
  char const *tmp;

  {
    { tmp = quote_n(0, name); }
    return (tmp);
  }
}

char const *program_name;
void set_program_name(char const *argv0);
extern char *program_invocation_name;
extern char *program_invocation_short_name;
extern int fputs(char const *__restrict __s, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strrchr)(char const *__s, int __c) __attribute__((__pure__));
char const *program_name = (char const *)((void *)0);
void set_program_name(char const *argv0) {
  char const *slash;

  {
    if ((unsigned long)argv0 == (unsigned long)((void *)0)) {
      {

        abort();
      }
    }
    { slash = (char const *)strrchr(argv0, '/'); }

    program_name = argv0;
    program_invocation_name = (char *)argv0;
    return;
  }
}

extern __attribute__((__nothrow__)) long double(__attribute__((__leaf__)) ldexpl)(long double __x, int __exponent);

int posix2_version(void);
int posix2_version(void) {
  long v;
  char const *s;
  char const *tmp;
  long tmp___1;
  long tmp___2;

  {
    {
      v = 200809L;
      tmp = (char const *)getenv("_POSIX2_VERSION");
      s = tmp;
    }

    if (v < (-0x7FFFFFFF - 1)) {
      tmp___2 = (-0x7FFFFFFF - 1);
    } else {

      tmp___2 = tmp___1;
    }
    return ((int)tmp___2);
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) pipe)(int *__pipedes);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) pipe2)(int *__pipedes, int __flags);
static int have_pipe2_really;

static yytype_uint8 const yytranslate[278] = {
    (yytype_uint8 const)0,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)26, (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)27,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)25, (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)23, (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)24, (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)1,  (yytype_uint8 const)2,  (yytype_uint8 const)3,  (yytype_uint8 const)4,  (yytype_uint8 const)5,  (yytype_uint8 const)6,  (yytype_uint8 const)7,  (yytype_uint8 const)8,
    (yytype_uint8 const)9,  (yytype_uint8 const)10, (yytype_uint8 const)11, (yytype_uint8 const)12, (yytype_uint8 const)13, (yytype_uint8 const)14, (yytype_uint8 const)15, (yytype_uint8 const)16, (yytype_uint8 const)17, (yytype_uint8 const)18, (yytype_uint8 const)19, (yytype_uint8 const)20,
    (yytype_uint8 const)21, (yytype_uint8 const)22};

static yytype_uint8 const yydefact[114] = {
    (yytype_uint8 const)5,  (yytype_uint8 const)0,  (yytype_uint8 const)0,  (yytype_uint8 const)2,  (yytype_uint8 const)3,  (yytype_uint8 const)85, (yytype_uint8 const)87, (yytype_uint8 const)84, (yytype_uint8 const)86, (yytype_uint8 const)4,  (yytype_uint8 const)82, (yytype_uint8 const)83,
    (yytype_uint8 const)1,  (yytype_uint8 const)56, (yytype_uint8 const)59, (yytype_uint8 const)65, (yytype_uint8 const)68, (yytype_uint8 const)73, (yytype_uint8 const)62, (yytype_uint8 const)81, (yytype_uint8 const)37, (yytype_uint8 const)35, (yytype_uint8 const)28, (yytype_uint8 const)0,
    (yytype_uint8 const)0,  (yytype_uint8 const)30, (yytype_uint8 const)0,  (yytype_uint8 const)88, (yytype_uint8 const)0,  (yytype_uint8 const)0,  (yytype_uint8 const)31, (yytype_uint8 const)6,  (yytype_uint8 const)7,  (yytype_uint8 const)16, (yytype_uint8 const)8,  (yytype_uint8 const)21,
    (yytype_uint8 const)9,  (yytype_uint8 const)10, (yytype_uint8 const)12, (yytype_uint8 const)11, (yytype_uint8 const)49, (yytype_uint8 const)13, (yytype_uint8 const)52, (yytype_uint8 const)74, (yytype_uint8 const)53, (yytype_uint8 const)14, (yytype_uint8 const)15, (yytype_uint8 const)38,
    (yytype_uint8 const)29, (yytype_uint8 const)0,  (yytype_uint8 const)45, (yytype_uint8 const)54, (yytype_uint8 const)57, (yytype_uint8 const)63, (yytype_uint8 const)66, (yytype_uint8 const)69, (yytype_uint8 const)60, (yytype_uint8 const)39, (yytype_uint8 const)36, (yytype_uint8 const)90,
    (yytype_uint8 const)32, (yytype_uint8 const)75, (yytype_uint8 const)76, (yytype_uint8 const)78, (yytype_uint8 const)79, (yytype_uint8 const)80, (yytype_uint8 const)77, (yytype_uint8 const)55, (yytype_uint8 const)58, (yytype_uint8 const)64, (yytype_uint8 const)67, (yytype_uint8 const)70,
    (yytype_uint8 const)61, (yytype_uint8 const)40, (yytype_uint8 const)18, (yytype_uint8 const)47, (yytype_uint8 const)90, (yytype_uint8 const)0,  (yytype_uint8 const)0,  (yytype_uint8 const)22, (yytype_uint8 const)89, (yytype_uint8 const)71, (yytype_uint8 const)72, (yytype_uint8 const)33,
    (yytype_uint8 const)0,  (yytype_uint8 const)51, (yytype_uint8 const)44, (yytype_uint8 const)0,  (yytype_uint8 const)0,  (yytype_uint8 const)34, (yytype_uint8 const)43, (yytype_uint8 const)48, (yytype_uint8 const)50, (yytype_uint8 const)27, (yytype_uint8 const)25, (yytype_uint8 const)41,
    (yytype_uint8 const)0,  (yytype_uint8 const)17, (yytype_uint8 const)46, (yytype_uint8 const)91, (yytype_uint8 const)19, (yytype_uint8 const)90, (yytype_uint8 const)0,  (yytype_uint8 const)23, (yytype_uint8 const)26, (yytype_uint8 const)0,  (yytype_uint8 const)0,  (yytype_uint8 const)25,
    (yytype_uint8 const)42, (yytype_uint8 const)25, (yytype_uint8 const)20, (yytype_uint8 const)24, (yytype_uint8 const)0,  (yytype_uint8 const)25};
static yytype_int8 const yypgoto[26] = {(yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)20,
                                        (yytype_int8 const)-68, (yytype_int8 const)-27, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
                                        (yytype_int8 const)60,  (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-92, (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)43};
static yytype_int8 const yydefgoto[26] = {(yytype_int8 const)-1,  (yytype_int8 const)2,   (yytype_int8 const)3,  (yytype_int8 const)4,  (yytype_int8 const)31, (yytype_int8 const)32, (yytype_int8 const)33, (yytype_int8 const)34, (yytype_int8 const)35,
                                          (yytype_int8 const)103, (yytype_int8 const)104, (yytype_int8 const)36, (yytype_int8 const)37, (yytype_int8 const)38, (yytype_int8 const)39, (yytype_int8 const)40, (yytype_int8 const)41, (yytype_int8 const)42,
                                          (yytype_int8 const)43,  (yytype_int8 const)44,  (yytype_int8 const)9,  (yytype_int8 const)10, (yytype_int8 const)11, (yytype_int8 const)45, (yytype_int8 const)46, (yytype_int8 const)93};
static yytype_uint8 const yytable[113] = {
    (yytype_uint8 const)79,  (yytype_uint8 const)67,  (yytype_uint8 const)68,  (yytype_uint8 const)69,  (yytype_uint8 const)70, (yytype_uint8 const)71, (yytype_uint8 const)72,  (yytype_uint8 const)58,  (yytype_uint8 const)73,  (yytype_uint8 const)100, (yytype_uint8 const)107, (yytype_uint8 const)74,
    (yytype_uint8 const)75,  (yytype_uint8 const)101, (yytype_uint8 const)110, (yytype_uint8 const)76,  (yytype_uint8 const)49, (yytype_uint8 const)50, (yytype_uint8 const)101, (yytype_uint8 const)102, (yytype_uint8 const)113, (yytype_uint8 const)77,  (yytype_uint8 const)59,  (yytype_uint8 const)78,
    (yytype_uint8 const)61,  (yytype_uint8 const)62,  (yytype_uint8 const)63,  (yytype_uint8 const)64,  (yytype_uint8 const)65, (yytype_uint8 const)66, (yytype_uint8 const)61,  (yytype_uint8 const)62,  (yytype_uint8 const)63,  (yytype_uint8 const)64,  (yytype_uint8 const)65,  (yytype_uint8 const)66,
    (yytype_uint8 const)101, (yytype_uint8 const)101, (yytype_uint8 const)92,  (yytype_uint8 const)111, (yytype_uint8 const)90, (yytype_uint8 const)91, (yytype_uint8 const)106, (yytype_uint8 const)112, (yytype_uint8 const)88,  (yytype_uint8 const)111, (yytype_uint8 const)5,   (yytype_uint8 const)6,
    (yytype_uint8 const)7,   (yytype_uint8 const)8,   (yytype_uint8 const)88,  (yytype_uint8 const)13,  (yytype_uint8 const)14, (yytype_uint8 const)15, (yytype_uint8 const)16,  (yytype_uint8 const)17,  (yytype_uint8 const)18,  (yytype_uint8 const)19,  (yytype_uint8 const)20,  (yytype_uint8 const)21,
    (yytype_uint8 const)22,  (yytype_uint8 const)1,   (yytype_uint8 const)23,  (yytype_uint8 const)24,  (yytype_uint8 const)25, (yytype_uint8 const)26, (yytype_uint8 const)27,  (yytype_uint8 const)28,  (yytype_uint8 const)29,  (yytype_uint8 const)79,  (yytype_uint8 const)30,  (yytype_uint8 const)51,
    (yytype_uint8 const)52,  (yytype_uint8 const)53,  (yytype_uint8 const)54,  (yytype_uint8 const)55,  (yytype_uint8 const)56, (yytype_uint8 const)12, (yytype_uint8 const)57,  (yytype_uint8 const)61,  (yytype_uint8 const)62,  (yytype_uint8 const)63,  (yytype_uint8 const)64,  (yytype_uint8 const)65,
    (yytype_uint8 const)66,  (yytype_uint8 const)60,  (yytype_uint8 const)48,  (yytype_uint8 const)80,  (yytype_uint8 const)47, (yytype_uint8 const)6,  (yytype_uint8 const)83,  (yytype_uint8 const)8,   (yytype_uint8 const)81,  (yytype_uint8 const)82,  (yytype_uint8 const)26,  (yytype_uint8 const)84,
    (yytype_uint8 const)85,  (yytype_uint8 const)86,  (yytype_uint8 const)87,  (yytype_uint8 const)94,  (yytype_uint8 const)95, (yytype_uint8 const)96, (yytype_uint8 const)89,  (yytype_uint8 const)105, (yytype_uint8 const)97,  (yytype_uint8 const)98,  (yytype_uint8 const)99,  (yytype_uint8 const)0,
    (yytype_uint8 const)108, (yytype_uint8 const)109, (yytype_uint8 const)101, (yytype_uint8 const)0,   (yytype_uint8 const)88};
static yytype_int8 const yycheck[113] = {(yytype_int8 const)27, (yytype_int8 const)5,   (yytype_int8 const)6,  (yytype_int8 const)7,  (yytype_int8 const)8,  (yytype_int8 const)9,  (yytype_int8 const)10,  (yytype_int8 const)4,  (yytype_int8 const)12, (yytype_int8 const)15,  (yytype_int8 const)102,
                                         (yytype_int8 const)15, (yytype_int8 const)16,  (yytype_int8 const)19, (yytype_int8 const)15, (yytype_int8 const)19, (yytype_int8 const)19, (yytype_int8 const)20,  (yytype_int8 const)19, (yytype_int8 const)25, (yytype_int8 const)112, (yytype_int8 const)25,
                                         (yytype_int8 const)19, (yytype_int8 const)27,  (yytype_int8 const)5,  (yytype_int8 const)6,  (yytype_int8 const)7,  (yytype_int8 const)8,  (yytype_int8 const)9,   (yytype_int8 const)10, (yytype_int8 const)5,  (yytype_int8 const)6,   (yytype_int8 const)7,
                                         (yytype_int8 const)8,  (yytype_int8 const)9,   (yytype_int8 const)10, (yytype_int8 const)19, (yytype_int8 const)19, (yytype_int8 const)19, (yytype_int8 const)107, (yytype_int8 const)19, (yytype_int8 const)20, (yytype_int8 const)25,  (yytype_int8 const)25,
                                         (yytype_int8 const)25, (yytype_int8 const)113, (yytype_int8 const)19, (yytype_int8 const)20, (yytype_int8 const)21, (yytype_int8 const)22, (yytype_int8 const)25,  (yytype_int8 const)5,  (yytype_int8 const)6,  (yytype_int8 const)7,   (yytype_int8 const)8,
                                         (yytype_int8 const)9,  (yytype_int8 const)10,  (yytype_int8 const)11, (yytype_int8 const)12, (yytype_int8 const)13, (yytype_int8 const)14, (yytype_int8 const)23,  (yytype_int8 const)16, (yytype_int8 const)17, (yytype_int8 const)18,  (yytype_int8 const)19,
                                         (yytype_int8 const)20, (yytype_int8 const)21,  (yytype_int8 const)22, (yytype_int8 const)96, (yytype_int8 const)24, (yytype_int8 const)5,  (yytype_int8 const)6,   (yytype_int8 const)7,  (yytype_int8 const)8,  (yytype_int8 const)9,   (yytype_int8 const)10,
                                         (yytype_int8 const)0,  (yytype_int8 const)12,  (yytype_int8 const)5,  (yytype_int8 const)6,  (yytype_int8 const)7,  (yytype_int8 const)8,  (yytype_int8 const)9,   (yytype_int8 const)10, (yytype_int8 const)25, (yytype_int8 const)4,   (yytype_int8 const)27,
                                         (yytype_int8 const)26, (yytype_int8 const)20,  (yytype_int8 const)30, (yytype_int8 const)22, (yytype_int8 const)9,  (yytype_int8 const)9,  (yytype_int8 const)19,  (yytype_int8 const)24, (yytype_int8 const)3,  (yytype_int8 const)19,  (yytype_int8 const)26,
                                         (yytype_int8 const)20, (yytype_int8 const)20,  (yytype_int8 const)20, (yytype_int8 const)59, (yytype_int8 const)27, (yytype_int8 const)84, (yytype_int8 const)20,  (yytype_int8 const)20, (yytype_int8 const)-1, (yytype_int8 const)20,  (yytype_int8 const)20,
                                         (yytype_int8 const)19, (yytype_int8 const)-1,  (yytype_int8 const)25};
static yytype_uint8 const yystos[114] = {
    (yytype_uint8 const)0,  (yytype_uint8 const)23, (yytype_uint8 const)29, (yytype_uint8 const)30, (yytype_uint8 const)31, (yytype_uint8 const)19, (yytype_uint8 const)20, (yytype_uint8 const)21, (yytype_uint8 const)22, (yytype_uint8 const)48, (yytype_uint8 const)49, (yytype_uint8 const)50,
    (yytype_uint8 const)0,  (yytype_uint8 const)5,  (yytype_uint8 const)6,  (yytype_uint8 const)7,  (yytype_uint8 const)8,  (yytype_uint8 const)9,  (yytype_uint8 const)10, (yytype_uint8 const)11, (yytype_uint8 const)12, (yytype_uint8 const)13, (yytype_uint8 const)14, (yytype_uint8 const)16,
    (yytype_uint8 const)17, (yytype_uint8 const)18, (yytype_uint8 const)19, (yytype_uint8 const)20, (yytype_uint8 const)21, (yytype_uint8 const)22, (yytype_uint8 const)24, (yytype_uint8 const)32, (yytype_uint8 const)33, (yytype_uint8 const)34, (yytype_uint8 const)35, (yytype_uint8 const)36,
    (yytype_uint8 const)39, (yytype_uint8 const)40, (yytype_uint8 const)41, (yytype_uint8 const)42, (yytype_uint8 const)43, (yytype_uint8 const)44, (yytype_uint8 const)45, (yytype_uint8 const)46, (yytype_uint8 const)47, (yytype_uint8 const)51, (yytype_uint8 const)52, (yytype_uint8 const)26,
    (yytype_uint8 const)4,  (yytype_uint8 const)19, (yytype_uint8 const)20, (yytype_uint8 const)5,  (yytype_uint8 const)6,  (yytype_uint8 const)7,  (yytype_uint8 const)8,  (yytype_uint8 const)9,  (yytype_uint8 const)10, (yytype_uint8 const)12, (yytype_uint8 const)4,  (yytype_uint8 const)19,
    (yytype_uint8 const)46, (yytype_uint8 const)5,  (yytype_uint8 const)6,  (yytype_uint8 const)7,  (yytype_uint8 const)8,  (yytype_uint8 const)9,  (yytype_uint8 const)10, (yytype_uint8 const)5,  (yytype_uint8 const)6,  (yytype_uint8 const)7,  (yytype_uint8 const)8,  (yytype_uint8 const)9,
    (yytype_uint8 const)10, (yytype_uint8 const)12, (yytype_uint8 const)15, (yytype_uint8 const)16, (yytype_uint8 const)19, (yytype_uint8 const)25, (yytype_uint8 const)27, (yytype_uint8 const)38, (yytype_uint8 const)46, (yytype_uint8 const)9,  (yytype_uint8 const)9,  (yytype_uint8 const)46,
    (yytype_uint8 const)24, (yytype_uint8 const)3,  (yytype_uint8 const)19, (yytype_uint8 const)26, (yytype_uint8 const)25, (yytype_uint8 const)53, (yytype_uint8 const)19, (yytype_uint8 const)20, (yytype_uint8 const)19, (yytype_uint8 const)53, (yytype_uint8 const)20, (yytype_uint8 const)20,
    (yytype_uint8 const)20, (yytype_uint8 const)36, (yytype_uint8 const)20, (yytype_uint8 const)20, (yytype_uint8 const)15, (yytype_uint8 const)19, (yytype_uint8 const)25, (yytype_uint8 const)37, (yytype_uint8 const)38, (yytype_uint8 const)27, (yytype_uint8 const)25, (yytype_uint8 const)50,
    (yytype_uint8 const)20, (yytype_uint8 const)20, (yytype_uint8 const)15, (yytype_uint8 const)37, (yytype_uint8 const)25, (yytype_uint8 const)50};
static yytype_uint8 const yyr1[92] = {
    (yytype_uint8 const)0,  (yytype_uint8 const)28, (yytype_uint8 const)29, (yytype_uint8 const)29, (yytype_uint8 const)30, (yytype_uint8 const)31, (yytype_uint8 const)31, (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32,
    (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)33, (yytype_uint8 const)34, (yytype_uint8 const)35, (yytype_uint8 const)35, (yytype_uint8 const)35, (yytype_uint8 const)35, (yytype_uint8 const)36, (yytype_uint8 const)36,
    (yytype_uint8 const)36, (yytype_uint8 const)37, (yytype_uint8 const)37, (yytype_uint8 const)38, (yytype_uint8 const)39, (yytype_uint8 const)39, (yytype_uint8 const)40, (yytype_uint8 const)40, (yytype_uint8 const)40, (yytype_uint8 const)40, (yytype_uint8 const)40, (yytype_uint8 const)40,
    (yytype_uint8 const)40, (yytype_uint8 const)41, (yytype_uint8 const)41, (yytype_uint8 const)41, (yytype_uint8 const)41, (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42,
    (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)43, (yytype_uint8 const)44, (yytype_uint8 const)44, (yytype_uint8 const)44, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)47, (yytype_uint8 const)48, (yytype_uint8 const)48,
    (yytype_uint8 const)49, (yytype_uint8 const)49, (yytype_uint8 const)50, (yytype_uint8 const)50, (yytype_uint8 const)51, (yytype_uint8 const)52, (yytype_uint8 const)53, (yytype_uint8 const)53};

static table const meridian_table[5] = {{"AM", 270, 0}, {"A.M.", 270, 0}, {"PM", 270, 1}, {"P.M.", 270, 1}, {(char const *)((void *)0), 0, 0}};
static table const dst_table[1] = {{"DST", 259, 0}};

static table const military_table[26] = {{"A", 273, -60}, {"B", 273, -120}, {"C", 273, -180}, {"D", 273, -240}, {"E", 273, -300}, {"F", 273, -360}, {"G", 273, -420}, {"H", 273, -480}, {"I", 273, -540}, {"K", 273, -600}, {"L", 273, -660}, {"M", 273, -720}, {"N", 273, 60},
                                         {"O", 273, 120}, {"P", 273, 180},  {"Q", 273, 240},  {"R", 273, 300},  {"S", 273, 360},  {"T", 'T', 0},    {"U", 273, 480},  {"V", 273, 540},  {"W", 273, 600},  {"X", 273, 660},  {"Y", 273, 720},  {"Z", 273, 0},    {(char const *)((void *)0), 0, 0}};
extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) access)(char const *__name, int __type);
static int proc_status = 0;

extern int(__attribute__((__nonnull__(1))) mkstemp)(char *__template);

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcoll)(char const *__s1, char const *__s2) __attribute__((__pure__));
__inline static int strcoll_loop(char const *s1, size_t s1size, char const *s2, size_t s2size) {
  int diff;
  size_t size1;
  size_t tmp;
  size_t size2;
  size_t tmp___0;
  int *tmp___1;
  int *tmp___2;
  int tmp___3;

  {
    {
      while (1) {
        ;
        {
          tmp___1 = __errno_location();
          *tmp___1 = 0;
          diff = strcoll(s1, s2);
        }
        if (diff) {
          tmp___3 = 1;
        } else {
          { tmp___2 = __errno_location(); }
        }
        if (tmp___3) {
          goto while_break;
        }
        {
          tmp = strlen(s1);
          size1 = tmp + 1UL;
          tmp___0 = strlen(s2);
          size2 = tmp___0 + 1UL;
          s1 += size1;
          s2 += size2;
          s1size -= size1;
          s2size -= size2;
        }

        if (s2size == 0UL) {
          return (1);
        }
      }
    while_break: /* CIL Label */;
    }
    return (diff);
  }
}
int memcoll(char *s1, size_t s1len, char *s2, size_t s2len) {
  int diff;
  int *tmp;
  char n1;
  char n2;
  int tmp___0;

  {
    if (s1len == s2len) {
      {
        tmp___0 = memcmp((void const *)s1, (void const *)s2, s1len);
      }
      if (tmp___0 == 0) {
        {
          tmp = __errno_location();
          *tmp = 0;
          diff = 0;
        }
      } else {
        goto _L;
      }
    } else {
    _L: {
      n1 = *(s1 + s1len);
      n2 = *(s2 + s2len);
      *(s1 + s1len) = (char)'\000';
      *(s2 + s2len) = (char)'\000';
      diff = strcoll_loop((char const *)s1, s1len + 1UL, (char const *)s2, s2len + 1UL);
      *(s1 + s1len) = n1;
      *(s2 + s2len) = n2;
    }
    }
    return (diff);
  }
}

int memcasecmp(void const *vs1, void const *vs2, size_t n) __attribute__((__pure__));
int memcasecmp(void const *vs1, void const *vs2, size_t n) {
  size_t i;
  char const *s1;
  char const *s2;

  {
    s1 = (char const *)vs1;
    s2 = (char const *)vs2;
    i = (size_t)0;
    { ; }
    return (0);
  }
}
static unsigned char const fillbuf___2[64] = {(unsigned char const)128, (unsigned char const)0};

extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(1), __leaf__)) strnlen)(char const *__string, size_t __maxlen) __attribute__((__pure__));

extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbstowcs)(wchar_t *__restrict __pwcs, char const *__restrict __s, size_t __n);
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) wcstombs)(char *__restrict __s, wchar_t const *__restrict __pwcs, size_t __n);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) mempcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);

unsigned int const is_basic_table[8] = {(unsigned int const)6656, (unsigned int const)4294967279U, (unsigned int const)4294967294U, (unsigned int const)2147483646};
static void *mmalloca_results[257];
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) exit)(int __status);
extern int optind;
extern int opterr;
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) getopt_long)(int ___argc, char *const *___argv, char const *__shortopts, struct option const *__longopts, int *__longind);
static struct option const long_options[3] = {{"help", 0, (int *)((void *)0), 'h'}, {"version", 0, (int *)((void *)0), 'v'}, {(char const *)((void *)0), 0, (int *)((void *)0), 0}};

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) pthread_mutexattr_init)(pthread_mutexattr_t *__attr);

extern __attribute__((__nothrow__)) FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);
extern int fscanf(FILE *__restrict __stream, char const *__restrict __format, ...);
extern int ungetc(int __c, FILE *__stream);
static char const *volatile charset_aliases;

static int have_follow_really;
void initbuffer(struct linebuffer *linebuffer);
struct linebuffer *readlinebuffer_delim(struct linebuffer *linebuffer, FILE *stream, char delimiter);
void initbuffer(struct linebuffer *linebuffer) {

  {
    { memset((void *)linebuffer, 0, sizeof(*linebuffer)); }
    return;
  }
}
struct linebuffer *readlinebuffer_delim(struct linebuffer *linebuffer, FILE *stream, char delimiter) {
  int c;
  char *buffer;
  char *p;
  char *end;
  int tmp;
  int tmp___0;
  size_t oldsize;
  char *tmp___1;

  {
    {
      buffer = linebuffer->buffer;
      p = linebuffer->buffer;
      end = buffer + linebuffer->size;
      tmp = feof_unlocked(stream);
    }
    if (tmp) {
      return ((struct linebuffer *)((void *)0));
    }
    {
      while (1) {
        ;
        { c = getc_unlocked(stream); }
        if (c == -1) {
          if ((unsigned long)p == (unsigned long)buffer) {
            return ((struct linebuffer *)((void *)0));
          } else {
            { tmp___0 = ferror_unlocked(stream); }
            if (tmp___0) {
              return ((struct linebuffer *)((void *)0));
            }
          }
          if ((int)*(p + -1) == (int)delimiter) {
            goto while_break;
          }
          c = (int)delimiter;
        }
        if ((unsigned long)p == (unsigned long)end) {
          {
            oldsize = linebuffer->size;
            buffer = (char *)x2realloc((void *)buffer, &linebuffer->size);
            p = buffer + oldsize;
            linebuffer->buffer = buffer;
            end = buffer + linebuffer->size;
          }
        }
        tmp___1 = p;
        p++;
        *tmp___1 = (char)c;
        if (!(c != (int)delimiter)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */;
    }
    linebuffer->length = (size_t)(p - buffer);
    return (linebuffer);
  }
}

#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
extern struct passwd *getpwuid(__uid_t __uid);
static struct userid *user_alist;
static struct userid *nouser_alist;
static struct userid *group_alist;
static struct userid *nogroup_alist;
extern __attribute__((__nothrow__)) struct lconv *(__attribute__((__leaf__)) localeconv)(void);

static int const block_size_opts[2] = {(int const)176, (int const)144};

_Bool hard_locale(int category);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) setlocale)(int __category, char const *__locale);
_Bool hard_locale(int category) {
  _Bool hard;
  char const *p;
  char const *tmp;

  {
    {
      hard = (_Bool)1;
      tmp = (char const *)setlocale(category, (char const *)((void *)0));
      p = tmp;
    }

    return (hard);
  }
}
extern void setgrent(void);
extern struct group *getgrent(void);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) clock_gettime)(clockid_t __clock_id, struct timespec *__tp);
extern int fflush_unlocked(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) __fsetlocking)(FILE *__fp, int __type);

static char *buf;
static size_t bufsize;
extern void(__attribute__((__nonnull__(1, 4))) qsort)(void *__base, size_t __nmemb, size_t __size, int (*__compar)(void const *, void const *));

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) statfs)(char const *__file, struct statfs *__buf);
extern int fseeko(FILE *__stream, __off_t __off, int __whence);
extern __attribute__((__nothrow__)) __off_t(__attribute__((__leaf__)) lseek)(int __fd, __off_t __offset, int __whence);
int(__attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp, off_t offset, int whence) {
  off_t pos;
  int tmp;
  off_t tmp___0;
  int tmp___1;

  {
    if ((unsigned long)fp->_IO_read_end == (unsigned long)fp->_IO_read_ptr) {

      if ((unsigned long)fp->_IO_save_base == (unsigned long)((void *)0)) {
        {
          tmp = fileno(fp);
          tmp___0 = lseek(tmp, offset, whence);
          pos = tmp___0;
        }
        if (pos == -1L) {
          return (-1);
        }
        fp->_flags &= -17;
        fp->_offset = pos;
        return (0);
      }
    }
    { tmp___1 = fseeko(fp, offset, whence); }
    return (tmp___1);
  }
}
extern FILE *freopen(char const *__restrict __filename, char const *__restrict __modes, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) dup2)(int __fd, int __fd2);
static _Bool protect_fd(int fd) {
  int value;
  int tmp;
  int *tmp___0;

  {
    {
      tmp = open("/dev/null", 0);
      value = tmp;
    }
    if (value != fd) {
      if (0 <= value) {
        {
          close(value);
          tmp___0 = __errno_location();
          *tmp___0 = 9;
        }
      }
      return ((_Bool)0);
    }
    return ((_Bool)1);
  }
}
FILE *freopen_safer(char const *name, char const *mode, FILE *f) {
  _Bool protect_in;
  _Bool protect_out;
  _Bool protect_err;
  int saved_errno;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  _Bool tmp___3;
  _Bool tmp___4;
  _Bool tmp___5;
  int *tmp___6;
  int *tmp___7;

  {
    {
      protect_in = (_Bool)0;
      protect_out = (_Bool)0;
      protect_err = (_Bool)0;
      tmp = fileno(f);
    }
    {

      if (tmp == 0) {
        goto case_0;
      }
      goto switch_default;
    switch_default: { /* CIL Label */
      tmp___0 = dup2(2, 2);
    }

    case_2: { /* CIL Label */
      tmp___1 = dup2(1, 1);
    }

    case_1: { /* CIL Label */
      tmp___2 = dup2(0, 0);
    }

    case_0: /* CIL Label */
      goto switch_break;
    switch_break: /* CIL Label */;
    }
    if (protect_in) {
      {
        tmp___5 = protect_fd(0);
      }

    } else {
      if (protect_out) {
        {
          tmp___4 = protect_fd(1);
        }

      } else {
        if (protect_err) {
          {
            tmp___3 = protect_fd(2);
          }
          if (tmp___3) {
            {
            }
          } else {
            f = (FILE *)((void *)0);
          }
        } else {
          { f = freopen((char const * /* __restrict  */)name, (char const * /* __restrict  */)mode, (FILE * /* __restrict  */)f); }
        }
      }
    }
    {
      tmp___6 = __errno_location();
      saved_errno = *tmp___6;
    }

    if (protect_out) {
      {
        close(1);
      }
    }
    if (protect_in) {
      {
        close(0);
      }
    }
    if (!f) {
      {
        tmp___7 = __errno_location();
        *tmp___7 = saved_errno;
      }
    }
    return (f);
  }
}

extern int fputc(int __c, FILE *__stream);
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
extern int fflush(FILE *__stream);

__inline static void clear_ungetc_buffer_preserving_position(FILE *fp) {

  {
    if (fp->_flags & 256) {
      {
        rpl_fseeko(fp, (off_t)0, 1);
      }
    }
    return;
  }
}
int rpl_fflush(FILE *stream) {
  int tmp___1;

  {

    {
      clear_ungetc_buffer_preserving_position(stream);
      tmp___1 = fflush(stream);
    }
    return (tmp___1);
  }
}
extern int fcntl(int __fd, int __cmd, ...);
static int have_dupfd_cloexec = 0;
extern int fclose(FILE *__stream);
int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {
  int saved_errno;
  int fd;
  int result;
  int tmp;
  int *tmp___0;
  int tmp___1;
  int tmp___2;
  __off_t tmp___3;
  int tmp___4;
  int *tmp___5;

  {
    {
      saved_errno = 0;
      result = 0;
      fd = fileno(fp);
    }
    if (fd < 0) {
      {
        tmp = fclose(fp);
      }
      return (tmp);
    }
    { tmp___1 = __freading(fp); }
    if (tmp___1 != 0) {
      {
        tmp___2 = fileno(fp);
        tmp___3 = lseek(tmp___2, (__off_t)0, 1);
      }
      if (tmp___3 != -1L) {
      _L: { tmp___4 = rpl_fflush(fp); }
        if (tmp___4) {
          {
            tmp___0 = __errno_location();
            saved_errno = *tmp___0;
          }
        }
      }
    } else {
      goto _L;
    }
    { result = fclose(fp); }
    if (saved_errno != 0) {
      {
        tmp___5 = __errno_location();
        *tmp___5 = saved_errno;
        result = -1;
      }
    }
    return (result);
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) sigaction)(int __sig, struct sigaction const *__restrict __act, struct sigaction *__restrict __oact);
static int fatal_signals[7] = {2, 15, 1, 13, 24, 25, 0};
static _Bool fatal_signals_initialized = (_Bool)0;
static actions_entry_t static_actions[32];
static actions_entry_t *volatile actions = (actions_entry_t * /* volatile  */)(static_actions);
static int volatile actions_count = (int volatile)0;

static struct sigaction saved_sigactions[64];
static _Bool cleanup_initialized = (_Bool)0;
static sigset_t fatal_signal_set;
static _Bool fatal_signal_set_initialized = (_Bool)0;

void fdadvise(int fd, off_t offset, off_t len, fadvice_t advice);
void fadvise(FILE *fp, fadvice_t advice);

void fadvise(FILE *fp, fadvice_t advice) {

  { return; }
}
int volatile exit_failure = (int volatile)1;

extern int fnmatch(char const *__pattern, char const *__name, int __flags);
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma weak pthread_mutex_init
#pragma weak pthread_mutex_lock
#pragma weak pthread_mutex_unlock
#pragma weak pthread_mutex_destroy
#pragma weak pthread_rwlock_init
#pragma weak pthread_rwlock_rdlock
#pragma weak pthread_rwlock_wrlock
#pragma weak pthread_rwlock_unlock
#pragma weak pthread_rwlock_destroy
#pragma weak pthread_once
#pragma weak pthread_cond_init
#pragma weak pthread_cond_wait
#pragma weak pthread_cond_signal
#pragma weak pthread_cond_broadcast
#pragma weak pthread_cond_destroy
#pragma weak pthread_mutexattr_init
#pragma weak pthread_mutexattr_settype
#pragma weak pthread_mutexattr_destroy
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
char const *Version = "8.16";
extern char *optarg;

extern int putchar_unlocked(int __c);
extern size_t fwrite_unlocked(void const *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);

static _Bool hard_LC_COLLATE;
static size_t skip_fields;
static size_t skip_chars;
static size_t check_chars;
static enum countmode countmode;
static _Bool output_unique;
static _Bool output_first_repeated;
static _Bool output_later_repeated;
static _Bool ignore_case;

static enum delimit_method delimit_groups;
static struct option const longopts[12] = {{"count", 0, (int *)((void *)0), 'c'},           {"repeated", 0, (int *)((void *)0), 'd'},    {"all-repeated", 2, (int *)((void *)0), 'D'}, {"ignore-case", 0, (int *)((void *)0), 'i'},
                                           {"unique", 0, (int *)((void *)0), 'u'},          {"skip-fields", 1, (int *)((void *)0), 'f'}, {"skip-chars", 1, (int *)((void *)0), 's'},   {"check-chars", 1, (int *)((void *)0), 'w'},
                                           {"zero-terminated", 0, (int *)((void *)0), 'z'}, {"help", 0, (int *)((void *)0), -130},       {"version", 0, (int *)((void *)0), -131},     {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
__attribute__((__noreturn__)) void usage(int status);
void usage(int status) {

  {

    { exit(status); }
  }
}

static char *__attribute__((__pure__)) find_field(struct linebuffer const *line) {
  size_t count;
  char const *lp;
  size_t size;
  size_t i;
  unsigned short const **tmp;
  unsigned short const **tmp___1;
  size_t tmp___3;

  {
    lp = (char const *)line->buffer;
    size = (size_t)(line->length - 1UL);
    i = (size_t)0;
    count = (size_t)0;
    {
      while (1) {
        ;
        if (count < skip_fields) {
          if (!(i < size)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        { ; }
        { ; }
        count++;
      }
    while_break: /* CIL Label */;
    }
    if (skip_chars < size - i) {
      tmp___3 = skip_chars;
    } else {
      tmp___3 = size - i;
    }
    i += tmp___3;
    return ((char * /* __attribute__((__pure__)) */)(line->buffer + i));
  }
}
static _Bool different(char *old, char *new, size_t oldlen, size_t newlen) {
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___3;

  {

    if (ignore_case) {
      if (oldlen != newlen) {
        tmp___0 = 1;
      } else {
        { tmp = memcasecmp((void const *)old, (void const *)new, oldlen); }
      }
      return ((_Bool)tmp___0);
    } else {
      if (hard_LC_COLLATE) {
        {
          tmp___1 = xmemcoll(old, oldlen, new, newlen);
        }
        return ((_Bool)(tmp___1 != 0));
      } else {

        return ((_Bool)tmp___3);
      }
    }
  }
}
static void writeline(struct linebuffer const *line, _Bool match, uintmax_t linecount) {
  int tmp___0;

  {

    if (!tmp___0) {
      return;
    }

    { fwrite_unlocked((void const * /* __restrict  */)line->buffer, sizeof(char), (size_t)line->length, (FILE * /* __restrict  */)stdout); }
    return;
  }
}
static void check_file(char const *infile, char const *outfile, char delimiter) {
  struct linebuffer lb1;
  struct linebuffer lb2;
  struct linebuffer *thisline;
  struct linebuffer *prevline;
  int *tmp;
  int tmp___0;
  FILE *tmp___1;
  int tmp___3;
  char *prevfield;
  size_t prevlen;
  char *thisfield;
  size_t thislen;
  struct linebuffer *tmp___5;
  struct linebuffer *_tmp;
  _Bool tmp___6;
  int tmp___7;
  char *prevfield___0;
  size_t prevlen___0;
  uintmax_t match_count;
  _Bool first_delimiter;
  struct linebuffer *tmp___8;
  _Bool match;
  char *thisfield___0;
  size_t thislen___0;
  int tmp___9;
  struct linebuffer *tmp___10;
  _Bool tmp___11;
  int tmp___12;
  int tmp___14;
  char *tmp___15;
  int tmp___16;
  int tmp___17;

  {
    { tmp___0 = strcmp(infile, "-"); }
    if (!(tmp___0 == 0)) {
      {
        tmp___1 = freopen_safer(infile, "r", stdin);
      }
      if (!tmp___1) {
        {
          tmp = __errno_location();
          error(1, *tmp, "%s", infile);
        }
      }
    }
    { tmp___3 = strcmp(outfile, "-"); }

    {
      fadvise(stdin, (fadvice_t)2);
      thisline = &lb1;
      prevline = &lb2;
      initbuffer(thisline);
      initbuffer(prevline);
    }
    if (output_unique) {
      if (output_first_repeated) {
        if ((unsigned int)countmode == 1U) {
          {
            while (1) {
              ;
              { tmp___7 = feof_unlocked(stdin); }
              if (tmp___7) {
                goto while_break;
              }
              { tmp___5 = readlinebuffer_delim(thisline, stdin, delimiter); }
              if ((unsigned long)tmp___5 == (unsigned long)((struct linebuffer *)0)) {
                goto while_break;
              }
              {
                thisfield = (char *)find_field((struct linebuffer const *)thisline);
                thislen = (thisline->length - 1UL) - (size_t)(thisfield - thisline->buffer);
              }
              if (prevline->length == 0UL) {
                goto _L;
              } else {
                { tmp___6 = different(thisfield, prevfield, thislen, prevlen); }
                if (tmp___6) {
                _L: { fwrite_unlocked((void const * /* __restrict  */)thisline->buffer, sizeof(char), thisline->length, (FILE * /* __restrict  */)stdout); }
                  {
                    while (1) {
                      ;
                      _tmp = prevline;
                      prevline = thisline;
                      thisline = _tmp;
                      goto while_break___0;
                    }
                  while_break___0: /* CIL Label */;
                  }
                  prevfield = thisfield;
                  prevlen = thislen;
                }
              }
            }
          while_break: /* CIL Label */;
          }
        } else {
          goto _L___2;
        }
      } else {
        goto _L___2;
      }
    } else {
    _L___2: {
      match_count = (uintmax_t)0;
      first_delimiter = (_Bool)1;
      tmp___8 = readlinebuffer_delim(prevline, stdin, delimiter);
    }
      if ((unsigned long)tmp___8 == (unsigned long)((struct linebuffer *)0)) {
        goto closefiles;
      }
      {
        prevfield___0 = (char *)find_field((struct linebuffer const *)prevline);
        prevlen___0 = (prevline->length - 1UL) - (size_t)(prevfield___0 - prevline->buffer);
      }
      {
        while (1) {
          ;
          { tmp___14 = feof_unlocked(stdin); }
          if (tmp___14) {
            goto while_break___1;
          }
          { tmp___10 = readlinebuffer_delim(thisline, stdin, delimiter); }
          if ((unsigned long)tmp___10 == (unsigned long)((struct linebuffer *)0)) {
            {
              tmp___9 = ferror_unlocked(stdin);
            }
            if (tmp___9) {
              goto closefiles;
            }
            goto while_break___1;
          }
          {

            thislen___0 = (thisline->length - 1UL) - (size_t)(thisfield___0 - thisline->buffer);
            tmp___11 = different(thisfield___0, prevfield___0, thislen___0, prevlen___0);
          }

          match = (_Bool)tmp___12;
          match_count += (uintmax_t)match;

          if (!match) {
            goto _L___0;
          } else {
            if (output_later_repeated) {
            _L___0: {}
              { ; }
              prevfield___0 = thisfield___0;
              prevlen___0 = thislen___0;
            }
          }
        }
      while_break___1: /* CIL Label */;
      }
      { writeline((struct linebuffer const *)prevline, (_Bool)0, match_count); }
    }
  closefiles: { tmp___16 = ferror_unlocked(stdin); }
    if (tmp___16) {
      {
        tmp___15 = gettext("error reading %s");
        error(1, 0, (char const *)tmp___15, infile);
      }
    } else {
      { tmp___17 = rpl_fclose(stdin); }
      if (tmp___17 != 0) {
        {
          tmp___15 = gettext("error reading %s");
          error(1, 0, (char const *)tmp___15, infile);
        }
      }
    }
    {
      free((void *)lb1.buffer);
      free((void *)lb2.buffer);
    }
    return;
  }
}
int main(int argc, char **argv) {
  int optc;
  _Bool posixly_correct;
  char *tmp;
  enum Skip_field_option_type skip_field_option_type;
  int nfiles;
  char const *file[2];
  char delimiter;
  int tmp___2;
  int tmp___3;
  char const *tmp___4;
  char *tmp___5;
  int tmp___6;
  int tmp___7;

  {
    {
      optc = 0;
      tmp = getenv("POSIXLY_CORRECT");
      posixly_correct = (_Bool)((unsigned long)tmp != (unsigned long)((void *)0));
      skip_field_option_type = (enum Skip_field_option_type)0;
      nfiles = 0;
      delimiter = (char)'\n';
      file[1] = "-";
      file[0] = file[1];
      set_program_name((char const *)*(argv + 0));
      setlocale(6, "");
      bindtextdomain("coreutils", "/usr/local/share/locale");
      textdomain("coreutils");
      hard_LC_COLLATE = hard_locale(3);
      atexit(&close_stdout);
      skip_chars = (size_t)0;
      skip_fields = (size_t)0;
      check_chars = 0xffffffffffffffffUL;
      output_first_repeated = (_Bool)1;
      output_unique = output_first_repeated;
      output_later_repeated = (_Bool)0;
      countmode = (enum countmode)1;
      delimit_groups = (enum delimit_method)0;
    }
    {
      while (1) {
        ;
        if (optc == -1) {
          goto _L___2;
        } else {
          if (posixly_correct) {

          } else {
          _L___3: { optc = getopt_long(argc, (char *const *)argv, "-0123456789Dcdf:is:uw:z", longopts, (int *)((void *)0)); }
            if (optc == -1) {
            _L___2:
              if (argc <= optind) {
                goto while_break;
              }

              tmp___2 = nfiles;
              nfiles++;
              tmp___3 = optind;
              optind++;
              file[tmp___2] = (char const *)*(argv + tmp___3);
            } else {
              {
                if (optc == 1) {
                  goto case_1;
                }

                goto switch_default;
              case_1: /* CIL Label */
                if ((int)*(optarg + 0) == 43) {
                  {
                    tmp___7 = posix2_version();
                  }

                } else {
                  if (nfiles == 2) {
                    {
                      tmp___4 = quote((char const *)optarg);
                      tmp___5 = gettext("extra operand %s");
                      error(0, 0, (char const *)tmp___5, tmp___4);
                      usage(1);
                    }
                  } else {
                    tmp___6 = nfiles;
                    nfiles++;
                    file[tmp___6] = (char const *)optarg;
                  }
                }
                goto switch_break;

                skip_field_option_type = (enum Skip_field_option_type)1;
                goto switch_break;
                goto switch_break;
                output_unique = (_Bool)0;
                goto switch_break;
                output_unique = (_Bool)0;
                output_later_repeated = (_Bool)1;

                goto switch_break;
              case_102: { /* CIL Label */
                skip_field_option_type = (enum Skip_field_option_type)2;
                skip_fields = size_opt((char const *)optarg, "invalid number of fields to skip");
              }
                goto switch_break;
                goto switch_break;
              case_115: { /* CIL Label */
                skip_chars = size_opt((char const *)optarg, "invalid number of bytes to skip");
              }
                goto switch_break;
                goto switch_break;
              case_119: { /* CIL Label */
                check_chars = size_opt((char const *)optarg, "invalid number of bytes to compare");
              }
                goto switch_break;
                goto switch_break;
              case_neg_130: { /* CIL Label */
                usage(0);
              }
                goto switch_break;
              case_neg_131: { /* CIL Label */
                version_etc(stdout, "uniq", "GNU coreutils", Version, "Richard M. Stallman", "David MacKenzie", (char *)((void *)0));
                exit(0);
              }
                goto switch_break;
              switch_default: { /* CIL Label */
                usage(1);
              }
              switch_break: /* CIL Label */;
              }
            }
          }
        }
      }
    while_break: /* CIL Label */;
    }
    {
      check_file(file[0], file[1], delimiter);
      exit(0);
    }
  }
}
