typedef unsigned long uintmax_t;
enum strtol_error { LONGINT_OK = 0, LONGINT_OVERFLOW = 1, LONGINT_INVALID_SUFFIX_CHAR = 2, LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3, LONGINT_INVALID = 4 };
typedef enum strtol_error strtol_error;
typedef long intmax_t;
typedef unsigned long size_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;
typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
enum quoting_style { literal_quoting_style = 0, shell_quoting_style = 1, shell_always_quoting_style = 2, c_quoting_style = 3, escape_quoting_style = 4, locale_quoting_style = 5, clocale_quoting_style = 6 };
typedef long ptrdiff_t;
typedef unsigned short __u_short;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef __u_short u_short;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __nlink_t nlink_t;
struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
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
struct dev_ino {
  ino_t st_ino;
  dev_t st_dev;
};

struct _ftsent;
struct _ftsent;

typedef struct __anonstruct_FTS_26 FTS;
struct _ftsent {
  struct _ftsent *fts_cycle;
  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;
  long fts_number;
  void *fts_pointer;
  char *fts_accpath;
  char *fts_path;
  int fts_errno;
  int fts_symfd;
  size_t fts_pathlen;
  ino_t fts_ino;
  dev_t fts_dev;
  nlink_t fts_nlink;
  int fts_level;
  u_short fts_namelen;
  u_short fts_info;
  u_short fts_flags;
  u_short fts_instr;
  struct stat *fts_statp;
  char fts_name[1];
};
typedef struct _ftsent FTSENT;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef long __off64_t;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

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
typedef int wchar_t;
typedef unsigned int wint_t;
enum __anonenum_arg_type_26 {
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
typedef enum __anonenum_arg_type_26 arg_type;
union __anonunion_a_28 {
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
struct __anonstruct_argument_27 {
  arg_type type;
  union __anonunion_a_28 a;
};
typedef struct __anonstruct_argument_27 argument;
struct __anonstruct_arguments_29 {
  unsigned int count;
  argument *arg;
};
typedef struct __anonstruct_arguments_29 arguments;
struct __anonstruct_char_directive_30 {
  char const *dir_start;
  char const *dir_end;
  int flags;
  char const *width_start;
  char const *width_end;
  int width_arg_index;
  char const *precision_start;
  char const *precision_end;
  int precision_arg_index;
  char conversion;
  int arg_index;
};
typedef struct __anonstruct_char_directive_30 char_directive;

typedef struct __anonstruct_char_directives_31 char_directives;
typedef long __suseconds_t;

typedef __gid_t gid_t;
typedef __uid_t uid_t;

typedef void *iconv_t;

union __anonunion___value_16 {
  unsigned int __wch;
  char __wchb[4];
};
struct __anonstruct___mbstate_t_15 {
  int __count;
  union __anonunion___value_16 __value;
};
typedef struct __anonstruct___mbstate_t_15 __mbstate_t;
typedef __mbstate_t mbstate_t;
struct numname {
  int num;
  char const name[8];
};
typedef unsigned int md5_uint32;
typedef unsigned long md5_uintptr;
struct sha_ctx {
  md5_uint32 A;
  md5_uint32 B;
  md5_uint32 C;
  md5_uint32 D;
  md5_uint32 E;
  md5_uint32 total[2];
  md5_uint32 buflen;
  char buffer[128];
};
typedef int __clockid_t;
typedef __clockid_t clockid_t;

struct __dirstream;
struct __dirstream;
typedef struct __dirstream DIR;
struct saved_cwd {
  int desc;
  char *name;
};
typedef int __int32_t;
typedef int __pid_t;

struct __anonstruct_ut_tv_27 {
  __int32_t tv_sec;
  __int32_t tv_usec;
};

typedef struct utmpx STRUCT_UTMP;

typedef struct tokenbuffer token_buffer;
struct quoting_options;
struct quoting_options;
struct quoting_options {
  enum quoting_style style;
  int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
};
struct slotvec {
  size_t size;
  char *val;
};
typedef __off_t off_t;
struct mntent {
  char *mnt_fsname;
  char *mnt_dir;
  char *mnt_type;
  char *mnt_opts;
  int mnt_freq;
  int mnt_passno;
};
struct mount_entry {
  char *me_devname;
  char *me_mountdir;
  char *me_type;
  dev_t me_dev;
  unsigned int me_dummy : 1;
  unsigned int me_remote : 1;
  unsigned int me_type_malloced : 1;
  struct mount_entry *me_next;
};
typedef __mode_t mode_t;
struct mode_change {
  char op;
  char flags;
  mode_t affected;
  mode_t value;
  struct mode_change *next;
};

struct ptr_list {
  char *dirname_end;
  struct ptr_list *next;
};
struct option {
  char const *name;
  int has_arg;
  int *flag;
  int val;
};
typedef int nl_item;
struct linebuffer {
  size_t size;
  size_t length;
  char *buffer;
};
union __anonunion_id_22 {
  uid_t u;
  gid_t g;
};

struct hash_entry {
  void *data;
  struct hash_entry *next;
};
struct hash_tuning {
  float shrink_threshold;
  float shrink_factor;
  float growth_threshold;
  float growth_factor;
  _Bool is_n_buckets;
};
typedef struct hash_tuning Hash_tuning;
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
typedef struct timezone *__restrict __timezone_ptr_t;
struct __anonstruct_textint_22 {
  int value;
  int digits;
};
typedef struct __anonstruct_textint_22 textint;
struct __anonstruct_table_23 {
  char const *name;
  int type;
  int value;
};
typedef struct __anonstruct_table_23 table;
struct __anonstruct_parser_control_25 {
  char const *input;
  int day_ordinal;
  int day_number;
  int local_isdst;
  int time_zone;
  int meridian;
  textint year;
  int month;
  int day;
  int hour;
  int minutes;
  int seconds;
  int rel_year;
  int rel_month;
  int rel_day;
  int rel_hour;
  int rel_minutes;
  int rel_seconds;
  int dates_seen;
  int days_seen;
  int local_zones_seen;
  int rels_seen;
  int times_seen;
  int zones_seen;
  table local_time_zone_table[3];
};
typedef struct __anonstruct_parser_control_25 parser_control;

typedef union YYSTYPE YYSTYPE;

typedef signed char yysigned_char;
typedef unsigned int __u_int;
typedef __u_int u_int;

struct __anonstruct___fsid_t_2 {
  int __val[2];
};
typedef struct __anonstruct___fsid_t_2 __fsid_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsfilcnt_t;
typedef long __fsword_t;
struct fs_usage {
  int fsu_blocksize;
  uintmax_t fsu_blocks;
  uintmax_t fsu_bfree;
  uintmax_t fsu_bavail;
  int fsu_bavail_top_bit_set;
  uintmax_t fsu_files;
  uintmax_t fsu_ffree;
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
struct exclude;
struct exclude;
struct patopts {
  char const *pattern;
  int options;
};

typedef unsigned int __socklen_t;
typedef unsigned int uint32_t;
typedef uint32_t in_addr_t;
struct in_addr {
  in_addr_t s_addr;
};
struct hostent {
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  int h_length;
  char **h_addr_list;
};
enum backup_type { none = 0, simple = 1, numbered_existing = 2, numbered = 3 };
extern __attribute__((__nothrow__)) unsigned short const **(__attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) rpmatch)(char const *response);
extern int getchar_unlocked(void);
extern __attribute__((__nothrow__)) uintmax_t(__attribute__((__leaf__)) strtoumax)(char const *__restrict __nptr, char **__restrict __endptr, int __base);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) __assert_fail)(char const *__assertion, char const *__file, unsigned int __line, char const *__function);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strchr)(char const *__s, int __c) __attribute__((__pure__));
extern __attribute__((__nothrow__)) int *(__attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) unsigned long(__attribute__((__nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr, char **__restrict __endptr, int __base);
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base, unsigned long *val, char const *valid_suffixes);

static strtol_error bkm_scale_by_power___0(unsigned long *x, int base, int power) {
  strtol_error err;

  {
    err = (strtol_error)0;
    { ; }
    return (err);
  }
}
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base, unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned short const **tmp___0;
  int *tmp___1;
  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;
  char *tmp___6;

  {
    err = (strtol_error)0;
    if (0 <= strtol_base) {
      if (!(strtol_base <= 36)) {
        {
          __assert_fail("0 <= strtol_base && strtol_base <= 36", "/home/khheo/project/benchmark/coreutils-5.2.1/lib/xstrtol.c", 117U, "xstrtoul");
        }
      }
    } else {
      { __assert_fail("0 <= strtol_base && strtol_base <= 36", "/home/khheo/project/benchmark/coreutils-5.2.1/lib/xstrtol.c", 117U, "xstrtoul"); }
    }
    if (ptr) {
      p = ptr;
    } else {
      p = &t_ptr;
    }
    q = s;
    { ; }

    {
      tmp___1 = __errno_location();
      *tmp___1 = 0;
      tmp = strtoul((char const * /* __restrict  */)s, (char ** /* __restrict  */)p, strtol_base);
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

      { tmp___6 = strchr(valid_suffixes, '0'); }

      if ((int)*(*p) == 99) {
        goto case_99;
      }
      if ((int)*(*p) == 69) {
        goto case_69;
      }
      if ((int)*(*p) == 103) {
        goto case_103;
      }
      if ((int)*(*p) == 71) {
        goto case_103;
      }
      if ((int)*(*p) == 75) {
        goto case_75;
      }
      if ((int)*(*p) == 107) {
        goto case_75;
      }
      if ((int)*(*p) == 109) {
        goto case_109;
      }
      if ((int)*(*p) == 77) {
        goto case_109;
      }

      if ((int)*(*p) == 84) {
        goto case_116;
      }

      if ((int)*(*p) == 90) {
        goto case_90;
      }
      goto switch_default;
    case_98: { overflow = bkm_scale___0(&tmp, 512); }
      goto switch_break___0;
    case_66___0: { overflow = bkm_scale___0(&tmp, 1024); }
      goto switch_break___0;
    case_99:
      overflow = (strtol_error)0;
      goto switch_break___0;
    case_69: { overflow = bkm_scale_by_power___0(&tmp, base, 6); }
      goto switch_break___0;
    case_103: { overflow = bkm_scale_by_power___0(&tmp, base, 3); }
      goto switch_break___0;
    case_75: { overflow = bkm_scale_by_power___0(&tmp, base, 1); }
      goto switch_break___0;
    case_109: { overflow = bkm_scale_by_power___0(&tmp, base, 2); }
      goto switch_break___0;
    case_80: { overflow = bkm_scale_by_power___0(&tmp, base, 5); }
      goto switch_break___0;
    case_116: { overflow = bkm_scale_by_power___0(&tmp, base, 4); }
      goto switch_break___0;
    case_119: { overflow = bkm_scale___0(&tmp, 2); }
      goto switch_break___0;
    case_89: { overflow = bkm_scale_by_power___0(&tmp, base, 8); }
      goto switch_break___0;
    case_90: { overflow = bkm_scale_by_power___0(&tmp, base, 7); }
      goto switch_break___0;
    switch_default:
      *val = tmp;
      return ((strtol_error)((unsigned int)err | 2U));
    switch_break___0:
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
extern __attribute__((__nothrow__)) long(__attribute__((__nonnull__(1), __leaf__)) strtol)(char const *__restrict __nptr, char **__restrict __endptr, int __base);
extern __attribute__((__nothrow__)) intmax_t(__attribute__((__leaf__)) strtoimax)(char const *__restrict __nptr, char **__restrict __endptr, int __base);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strndup)(char const *__string, size_t __n) __attribute__((__malloc__));
__attribute__((__noreturn__)) void xalloc_die(void);
extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s) __attribute__((__pure__));
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) rpl_free)(void *p);
extern __attribute__((__nothrow__)) ssize_t(__attribute__((__nonnull__(1, 2), __leaf__)) readlink)(char const *__restrict __path, char *__restrict __buf, size_t __len);
void *xmalloc(size_t n);
extern int nanosleep(struct timespec const *__requested_time, struct timespec *__remaining);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) gettext)(char const *__msgid) __attribute__((__format_arg__(1)));
extern void error(int __status, int __errnum, char const *__format, ...);
int volatile exit_failure;
void (*xalloc_fail_func)(void);
char const xalloc_msg_memory_exhausted[17];
void *xrealloc(void *p, size_t n);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) calloc)(size_t __nmemb, size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__warn_unused_result__, __leaf__)) realloc)(void *__ptr, size_t __size);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) abort)(void);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1), __leaf__)) memset)(void *__s, int __c, size_t __n);
void (*xalloc_fail_func)(void) = (void (*)(void))0;

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
extern int gethostname();
__attribute__((__nothrow__)) char *(__attribute__((__leaf__)) rpl_getcwd)(char *buf, size_t size);
char *xgetcwd(void);
char *xgetcwd(void) {
  char *cwd;
  char *tmp;

  {
    {
      tmp = rpl_getcwd((char *)((void *)0), (size_t)0);
      cwd = tmp;
    }

    return (cwd);
  }
}
char const *quote(char const *name);
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format, ...);
extern int vfprintf(FILE *__restrict __s, char const *__restrict __format, __gnuc_va_list __arg);
extern int putc_unlocked(int __c, FILE *__stream);
extern int fputs_unlocked(char const *__restrict __s, FILE *__restrict __stream);
char const *version_etc_copyright;
void version_etc_va(FILE *stream, char const *command_name, char const *package, char const *version, va_list authors);
void version_etc(FILE *stream, char const *command_name, char const *package, char const *version, ...);
char const *version_etc_copyright = "Copyright (C) 2004 Free Software Foundation, Inc.";

extern __attribute__((__nothrow__)) int snprintf(char *__restrict __s, size_t __maxlen, char const *__restrict __format, ...);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) utimes)(char const *__file, struct timeval const *__tvp);
extern __attribute__((__nothrow__)) int sprintf(char *__restrict __s, char const *__restrict __format, ...);
extern void endpwent(void);
extern struct passwd *getpwnam(char const *__name);
extern void endgrent(void);
extern struct group *getgrgid(__gid_t __gid);
extern struct group *getgrnam(char const *__name);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strdup)(char const *__s) __attribute__((__malloc__));
static char const *E_invalid_user = "invalid user";
static char const *E_invalid_group = "invalid group";
static char const *E_bad_spec = "cannot get the login group of a numeric UID";
static char const *E_cannot_omit_both = "cannot omit both user and group";
extern size_t fwrite(void const *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __s);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2) __attribute__((__pure__));
extern iconv_t iconv_open(char const *__tocode, char const *__fromcode);
extern size_t iconv(iconv_t __cd, char **__restrict __inbuf, size_t *__restrict __inbytesleft, char **__restrict __outbuf, size_t *__restrict __outbytesleft);
static int initialized;
static int is_utf8;
static iconv_t utf8_to_local;
extern __attribute__((__nothrow__)) struct tm *(__attribute__((__leaf__)) gmtime)(time_t const *__timer);
extern __attribute__((__nothrow__)) struct tm *(__attribute__((__leaf__)) localtime)(time_t const *__timer);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) asctime)(struct tm const *__tp);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) ctime)(time_t const *__timer);
char *base_name(char const *name);
size_t base_len(char const *name);
int strip_trailing_slashes(char *path);
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
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) tolower)(int __c);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) toupper)(int __c);
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) strftime)(char *__restrict __s, size_t __maxsize, char const *__restrict __format, struct tm const *__restrict __tp);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) mbsinit)(mbstate_t const *__ps) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrlen)(char const *__restrict __s, size_t __n, mbstate_t *__restrict __ps);
static mbstate_t const mbstate_zero;
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) __libc_current_sigrtmin)(void);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) __libc_current_sigrtmax)(void);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strncmp)(char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
static struct numname numname_table[35] = {{1, {(char const)'H', (char const)'U', (char const)'P', (char const)'\000'}},
                                           {2, {(char const)'I', (char const)'N', (char const)'T', (char const)'\000'}},
                                           {3, {(char const)'Q', (char const)'U', (char const)'I', (char const)'T', (char const)'\000'}},
                                           {4, {(char const)'I', (char const)'L', (char const)'L', (char const)'\000'}},
                                           {5, {(char const)'T', (char const)'R', (char const)'A', (char const)'P', (char const)'\000'}},
                                           {6, {(char const)'A', (char const)'B', (char const)'R', (char const)'T', (char const)'\000'}},
                                           {8, {(char const)'F', (char const)'P', (char const)'E', (char const)'\000'}},
                                           {9, {(char const)'K', (char const)'I', (char const)'L', (char const)'L', (char const)'\000'}},
                                           {7, {(char const)'B', (char const)'U', (char const)'S', (char const)'\000'}},
                                           {11, {(char const)'S', (char const)'E', (char const)'G', (char const)'V', (char const)'\000'}},
                                           {13, {(char const)'P', (char const)'I', (char const)'P', (char const)'E', (char const)'\000'}},
                                           {14, {(char const)'A', (char const)'L', (char const)'R', (char const)'M', (char const)'\000'}},
                                           {15, {(char const)'T', (char const)'E', (char const)'R', (char const)'M', (char const)'\000'}},
                                           {10, {(char const)'U', (char const)'S', (char const)'R', (char const)'1', (char const)'\000'}},
                                           {12, {(char const)'U', (char const)'S', (char const)'R', (char const)'2', (char const)'\000'}},
                                           {17, {(char const)'C', (char const)'H', (char const)'L', (char const)'D', (char const)'\000'}},
                                           {23, {(char const)'U', (char const)'R', (char const)'G', (char const)'\000'}},
                                           {19, {(char const)'S', (char const)'T', (char const)'O', (char const)'P', (char const)'\000'}},
                                           {20, {(char const)'T', (char const)'S', (char const)'T', (char const)'P', (char const)'\000'}},
                                           {18, {(char const)'C', (char const)'O', (char const)'N', (char const)'T', (char const)'\000'}},
                                           {21, {(char const)'T', (char const)'T', (char const)'I', (char const)'N', (char const)'\000'}},
                                           {22, {(char const)'T', (char const)'T', (char const)'O', (char const)'U', (char const)'\000'}},
                                           {31, {(char const)'S', (char const)'Y', (char const)'S', (char const)'\000'}},
                                           {29, {(char const)'P', (char const)'O', (char const)'L', (char const)'L', (char const)'\000'}},
                                           {26, {(char const)'V', (char const)'T', (char const)'A', (char const)'L', (char const)'R', (char const)'M', (char const)'\000'}},
                                           {27, {(char const)'P', (char const)'R', (char const)'O', (char const)'F', (char const)'\000'}},
                                           {24, {(char const)'X', (char const)'C', (char const)'P', (char const)'U', (char const)'\000'}},
                                           {25, {(char const)'X', (char const)'F', (char const)'S', (char const)'Z', (char const)'\000'}},
                                           {6, {(char const)'I', (char const)'O', (char const)'T', (char const)'\000'}},
                                           {17, {(char const)'C', (char const)'L', (char const)'D', (char const)'\000'}},
                                           {30, {(char const)'P', (char const)'W', (char const)'R', (char const)'\000'}},
                                           {28, {(char const)'W', (char const)'I', (char const)'N', (char const)'C', (char const)'H', (char const)'\000'}},
                                           {29, {(char const)'I', (char const)'O', (char const)'\000'}},
                                           {16, {(char const)'S', (char const)'T', (char const)'K', (char const)'F', (char const)'L', (char const)'T', (char const)'\000'}},
                                           {0, {(char const)'E', (char const)'X', (char const)'I', (char const)'T', (char const)'\000'}}};
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) feof_unlocked)(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ferror_unlocked)(FILE *__stream);
static unsigned char const fillbuf[64] = {(unsigned char const)128, (unsigned char const)0};
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) settimeofday)(struct timeval const *__tv, struct timezone const *__tz);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) clock_settime)(clockid_t __clock_id, struct timespec const *__tp);
extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
extern int close(int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) chdir)(char const *__path);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchdir)(int __fd);
extern int(__attribute__((__nonnull__(1))) open)(char const *__file, int __oflag, ...);
int save_cwd(struct saved_cwd *cwd);
int restore_cwd(struct saved_cwd const *cwd);
void free_cwd(struct saved_cwd *cwd);
static int have_working_fchdir = 1;
int save_cwd(struct saved_cwd *cwd) {

  {
    cwd->desc = -1;
    cwd->name = (char *)((void *)0);

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
void free_cwd(struct saved_cwd *cwd) {

  { return; }
}
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file, struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2, size_t __n) __attribute__((__pure__));
int same_name(char const *source, char const *dest);
char *dir_name(char const *path);
int same_name(char const *source, char const *dest) {
  char const *source_basename;
  char *tmp;
  char const *dest_basename;
  char *tmp___0;
  size_t source_baselen;
  size_t tmp___1;
  size_t dest_baselen;
  size_t tmp___2;
  _Bool identical_basenames;
  int tmp___4;
  _Bool compare_dirs;
  _Bool same;

  {
    {
      tmp = base_name(source);
      source_basename = (char const *)tmp;
      tmp___0 = base_name(dest);
      dest_basename = (char const *)tmp___0;
      tmp___1 = base_len(source_basename);
      source_baselen = tmp___1;
      tmp___2 = base_len(dest_basename);
      dest_baselen = tmp___2;
    }

    identical_basenames = (_Bool)tmp___4;
    compare_dirs = identical_basenames;
    same = (_Bool)0;

    return ((int)same);
  }
}
extern ssize_t write(int __fd, void const *__buf, size_t __n);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file, struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strncpy)(char *__restrict __dest, char const *__restrict __src, size_t __n);
extern void setutxent(void);
extern void endutxent(void);
extern struct utmpx *getutxent(void);
extern int utmpxname(char const *__file);
extern int getc_unlocked(FILE *__stream);
static char const *saved_delim = (char const *)((void *)0);
static char isdelim[256];
char const *const quoting_style_args[8];
enum quoting_style const quoting_style_vals[7];
int set_char_quoting(struct quoting_options *o, char c, int i);
size_t quotearg_buffer(char *buffer, size_t buffersize, char const *arg, size_t argsize, struct quoting_options const *o);
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char *quotearg_char(char const *arg, char ch);
char *quotearg_colon(char const *arg);
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) __ctype_get_mb_cur_max)(void);
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrtowc)(wchar_t *__restrict __pwc, char const *__restrict __s, size_t __n, mbstate_t *__restrict __p);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) iswprint)(wint_t __wc);
char const *const quoting_style_args[8] = {(char const * /* const  */) "literal", (char const * /* const  */) "shell",  (char const * /* const  */) "shell-always", (char const * /* const  */) "c",
                                           (char const * /* const  */) "escape",  (char const * /* const  */) "locale", (char const * /* const  */) "clocale",      (char const * /* const  */)((char const *)0)};
enum quoting_style const quoting_style_vals[7] = {(enum quoting_style const)0, (enum quoting_style const)1, (enum quoting_style const)2, (enum quoting_style const)3, (enum quoting_style const)4, (enum quoting_style const)5, (enum quoting_style const)6};
static struct quoting_options default_quoting_options;
int set_char_quoting(struct quoting_options *o, char c, int i) {
  unsigned char uc;
  int *p;
  struct quoting_options *tmp;
  int shift;
  int r;

  {
    uc = (unsigned char)c;
    if (o) {
      tmp = o;
    } else {
      tmp = &default_quoting_options;
    }
    p = tmp->quote_these_too + (unsigned long)uc / (sizeof(int) * 8UL);
    shift = (int)((unsigned long)uc % (sizeof(int) * 8UL));
    r = (*p >> shift) & 1;
    *p ^= ((i & 1) ^ r) << shift;
    return (r);
  }
}

static size_t quotearg_buffer_restyled(char *buffer, size_t buffersize, char const *arg, size_t argsize, enum quoting_style quoting_style, struct quoting_options const *o) {
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
  unsigned short const **tmp___3;
  size_t tmp___8;

  {
    {
      len = (size_t)0;
      quote_string = (char const *)0;
      quote_string_len = (size_t)0;
      backslash_escapes = 0;
      tmp = __ctype_get_mb_cur_max();
      unibyte_locale = tmp == 1UL;
    }

    goto switch_default;
  case_3: {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)'\"';
      }
      len++;
      goto while_break;
    };
  }
  while_break:
    backslash_escapes = 1;
    quote_string = "\"";
    quote_string_len = (size_t)1;
    goto switch_break;
    backslash_escapes = 1;
    goto switch_break;
  case_6: {
    tmp___0 = gettext_quote("`", quoting_style);
    left = tmp___0;
    tmp___1 = gettext_quote("\'", quoting_style);
    right = tmp___1;
    quote_string = left;
  }
    {
      while (1) {
        ;

        if (!*quote_string) {
          goto while_break___0;
        }
        { ; }
        quote_string++;
      };
    }
  while_break___0: {
    backslash_escapes = 1;
    quote_string = right;
    quote_string_len = strlen(quote_string);
  }
    goto switch_break;
  case_2: {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)'\'';
      }
      len++;
      goto while_break___2;
    };
  }
  while_break___2:
    quote_string = "\'";
    quote_string_len = (size_t)1;
    goto switch_break;
  switch_default:
    goto switch_break;
  switch_break:
    i = (size_t)0;
    { ; }

    if (len < buffersize) {
      *(buffer + len) = (char)'\000';
    }
    return (len);
  use_shell_always_quoting_style: { tmp___8 = quotearg_buffer_restyled(buffer, buffersize, arg, argsize, (enum quoting_style)2, o); }
    return (tmp___8);
  }
}
size_t quotearg_buffer(char *buffer, size_t buffersize, char const *arg, size_t argsize, struct quoting_options const *o) {
  struct quoting_options const *p;
  struct quoting_options const *tmp;
  int e;
  int *tmp___0;
  size_t r;
  size_t tmp___1;
  int *tmp___2;

  {
    if (o) {
      tmp = o;
    } else {
      tmp = (struct quoting_options const *)(&default_quoting_options);
    }
    {
      p = tmp;
      tmp___0 = __errno_location();
      e = *tmp___0;
      tmp___1 = quotearg_buffer_restyled(buffer, buffersize, arg, argsize, (enum quoting_style)p->style, p);
      r = tmp___1;
      tmp___2 = __errno_location();
      *tmp___2 = e;
    }
    return (r);
  }
}
static char slot0[256];
static char *quotearg_n_options(int n, char const *arg, size_t argsize, struct quoting_options const *options);
static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
static char *quotearg_n_options(int n, char const *arg, size_t argsize, struct quoting_options const *options) {
  int e;
  int *tmp;
  unsigned int n0;
  unsigned int n1;
  int tmp___0;
  void *tmp___1;
  void *tmp___2;
  size_t size;
  char *val;
  size_t qsize;
  size_t tmp___3;
  void *tmp___4;
  int *tmp___5;

  {
    {
      tmp = __errno_location();
      e = *tmp;
      n0 = (unsigned int)n;
    }
    if (n < 0) {
      {
        abort();
      }
    }
    if (nslots <= n0) {
      n1 = n0 + 1U;
      if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
        tmp___0 = -1;
      } else {
        tmp___0 = -2;
      }
      if ((size_t)tmp___0 / sizeof(*slotvec) < (size_t)n1) {
        {
          xalloc_die();
        }
      }
      if ((unsigned long)slotvec == (unsigned long)(&slotvec0)) {
        {
          tmp___1 = xmalloc(sizeof(*slotvec));
          slotvec = (struct slotvec *)tmp___1;
          *slotvec = slotvec0;
        }
      }
      {
        tmp___2 = xrealloc((void *)slotvec, (unsigned long)n1 * sizeof(*slotvec));
        slotvec = (struct slotvec *)tmp___2;
        memset((void *)(slotvec + nslots), 0, (unsigned long)(n1 - nslots) * sizeof(*slotvec));
        nslots = n1;
      }
    }
    {
      size = (slotvec + n)->size;
      val = (slotvec + n)->val;
      tmp___3 = quotearg_buffer(val, size, arg, argsize, options);
      qsize = tmp___3;
    }
    if (size <= qsize) {
      size = qsize + 1UL;
      (slotvec + n)->size = size;
      if ((unsigned long)val != (unsigned long)(slot0)) {
        {
          rpl_free((void *)val);
        }
      }
      {
        tmp___4 = xmalloc(size);
        val = (char *)tmp___4;
        (slotvec + n)->val = val;
        quotearg_buffer(val, size, arg, argsize, options);
      }
    }
    {
      tmp___5 = __errno_location();
      *tmp___5 = e;
    }
    return (val);
  }
}
static struct quoting_options quoting_options_from_style(enum quoting_style style) {
  struct quoting_options o;

  {
    {
      o.style = style;
      memset((void *)(o.quote_these_too), 0, sizeof(o.quote_these_too));
    }
    return (o);
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;
  struct quoting_options tmp;
  char *tmp___0;

  {
    {
      tmp = quoting_options_from_style(s);
      o = tmp;
      tmp___0 = quotearg_n_options(n, arg, (size_t)-1, (struct quoting_options const *)(&o));
    }
    return (tmp___0);
  }
}
char *quotearg_char(char const *arg, char ch) {
  struct quoting_options options;
  char *tmp;

  {
    {
      options = default_quoting_options;
      set_char_quoting(&options, ch, 1);
      tmp = quotearg_n_options(0, arg, (size_t)-1, (struct quoting_options const *)(&options));
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
char const *quote_n(int n, char const *name);
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
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);
extern __attribute__((__nothrow__)) time_t(__attribute__((__leaf__)) time)(time_t *__timer);
extern __attribute__((__nothrow__)) long(__attribute__((__leaf__)) sysconf)(int __name);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) mempcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strstr)(char const *__haystack, char const *__needle) __attribute__((__pure__));
extern __attribute__((__nothrow__)) FILE *(__attribute__((__leaf__)) setmntent)(char const *__file, char const *__mode);
extern __attribute__((__nothrow__)) struct mntent *(__attribute__((__leaf__)) getmntent)(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) endmntent)(FILE *__stream);
struct mode_change *mode_compile(char const *mode_string___0, unsigned int masked_ops);
mode_t mode_adjust(mode_t oldmode, struct mode_change const *changes);
void mode_free(struct mode_change *changes);
extern __attribute__((__nothrow__)) __mode_t(__attribute__((__leaf__)) umask)(__mode_t __mask);
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
static void mode_append_entry(struct mode_change **head, struct mode_change **tail, struct mode_change *e) {
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
struct mode_change *mode_compile(char const *mode_string___0, unsigned int masked_ops) {
  struct mode_change *head;
  struct mode_change *tail;
  unsigned long octal_value;
  mode_t umask_value;
  struct mode_change *p;
  mode_t mode;
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
  strtol_error tmp___11;
  mode_t affected_bits;
  mode_t affected_masked;
  unsigned int ops_to_mask;
  int who_specified_p;
  struct mode_change *change;
  void *tmp___12;
  int tmp___14;
  int tmp___15;
  int tmp___16;

  {
    {
      head = (struct mode_change *)((void *)0);
      tmp___11 = xstrtoul(mode_string___0, (char **)((void *)0), 8, &octal_value, "");
    }
    if ((unsigned int)tmp___11 == 0U) {

      if (256 >> 3 == 32) {
        if (128 >> 3 == 16) {
          if (64 >> 3 == 8) {
            if ((256 >> 3) >> 3 == 4) {
              if ((128 >> 3) >> 3 == 2) {
                if ((64 >> 3) >> 3 == 1) {
                  mode = (mode_t)octal_value;
                } else {
                  goto _L___3;
                }
              } else {
                goto _L___3;
              }
            } else {
              goto _L___3;
            }
          } else {
            goto _L___3;
          }
        } else {
          goto _L___3;
        }
      } else {
      _L___3:
        if (octal_value & 2048UL) {
          tmp = 2048;
        } else {
          tmp = 0;
        }
        if (octal_value & 1024UL) {
          tmp___0 = 1024;
        } else {
          tmp___0 = 0;
        }
        if (octal_value & 512UL) {
          tmp___1 = 512;
        } else {
          tmp___1 = 0;
        }
        if (octal_value & 256UL) {
          tmp___2 = 256;
        } else {
          tmp___2 = 0;
        }
        if (octal_value & 128UL) {
          tmp___3 = 128;
        } else {
          tmp___3 = 0;
        }
        if (octal_value & 64UL) {
          tmp___4 = 64;
        } else {
          tmp___4 = 0;
        }
        if (octal_value & 32UL) {
          tmp___5 = 256 >> 3;
        } else {
          tmp___5 = 0;
        }

        if (octal_value & 8UL) {
          tmp___7 = 64 >> 3;
        } else {
          tmp___7 = 0;
        }
        if (octal_value & 4UL) {
          tmp___8 = (256 >> 3) >> 3;
        } else {
          tmp___8 = 0;
        }
        if (octal_value & 2UL) {
          tmp___9 = (128 >> 3) >> 3;
        } else {
          tmp___9 = 0;
        }
        if (octal_value & 1UL) {
          tmp___10 = (64 >> 3) >> 3;
        } else {
          tmp___10 = 0;
        }
        mode = (mode_t)(((((((((((tmp | tmp___0) | tmp___1) | tmp___2) | tmp___3) | tmp___4) | tmp___5) | tmp___6) | tmp___7) | tmp___8) | tmp___9) | tmp___10);
      }
      { p = make_node_op_equals(mode); }

      { mode_append_entry(&head, &tail, p); }
      return (head);
    }
    {
      umask_value = umask((__mode_t)0);
      umask(umask_value);
      mode_string___0--;
    }
    {
      while (1) {
        ;
        affected_bits = (mode_t)0;
        ops_to_mask = 0U;
        affected_bits = (mode_t)0;
        ops_to_mask = 0U;
        mode_string___0++;
        {
          while (1) {
            ;

            if ((int const) * mode_string___0 == 117) {
              goto case_117;
            }
            if ((int const) * mode_string___0 == 103) {
              goto case_103;
            }
            if ((int const) * mode_string___0 == 111) {
              goto case_111;
            }
            if ((int const) * mode_string___0 == 97) {
              goto case_97;
            }
            goto switch_default;
          case_117:
            affected_bits |= 2496U;
            goto switch_break;
          case_103:
            affected_bits |= (unsigned int)(1024 | (448 >> 3));
            goto switch_break;
          case_111:
            affected_bits |= (unsigned int)(512 | ((448 >> 3) >> 3));
            goto switch_break;
          case_97:
            affected_bits |= (unsigned int)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
            goto switch_break;
          switch_default:
            goto no_more_affected;
          switch_break:
            mode_string___0++;
          };
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
            ;

            if (!((int const) * mode_string___0 == 61)) {
              if (!((int const) * mode_string___0 == 43)) {
                if (!((int const) * mode_string___0 == 45)) {
                  goto while_break___1;
                }
              }
            }
            {
              tmp___12 = malloc(sizeof(struct mode_change));
              change = (struct mode_change *)tmp___12;
            }
            if ((unsigned long)change == (unsigned long)((void *)0)) {
              {
                mode_free(head);
              }
              return ((struct mode_change *)1);
            }
            change->next = (struct mode_change *)((void *)0);
            change->op = (char)*mode_string___0;
            affected_masked = affected_bits;
            if (!who_specified_p) {
              if ((int const) * mode_string___0 == 61) {
                tmp___14 = 1;
              } else {
                tmp___14 = 0;
              }
            }
            if ((int const) * mode_string___0 == 61) {
              tmp___16 = 1;
            } else {

              tmp___16 = tmp___15;
            }
            if (ops_to_mask & (unsigned int)tmp___16) {
              affected_masked &= ~umask_value;
            }
            {
              change->affected = affected_masked;
              change->value = (mode_t)0;
              change->flags = (char)0;
              mode_append_entry(&head, &tail, change);
              mode_string___0++;
            }
            {
              while (1) {
                ;

                if ((int const) * mode_string___0 == 114) {
                  goto case_114;
                }
                if ((int const) * mode_string___0 == 119) {
                  goto case_119;
                }
                if ((int const) * mode_string___0 == 88) {
                  goto case_88;
                }
                if ((int const) * mode_string___0 == 120) {
                  goto case_120;
                }
                if ((int const) * mode_string___0 == 115) {
                  goto case_115;
                }
                if ((int const) * mode_string___0 == 116) {
                  goto case_116;
                }

                if ((int const) * mode_string___0 == 103) {
                  goto case_103___0;
                }
                if ((int const) * mode_string___0 == 111) {
                  goto case_111___0;
                }
                goto switch_default___0;
              case_114:
                change->value |= (unsigned int)((256 | (256 >> 3)) | ((256 >> 3) >> 3)) & affected_masked;
                goto switch_break___0;
              case_119:
                change->value |= (unsigned int)((128 | (128 >> 3)) | ((128 >> 3) >> 3)) & affected_masked;
                goto switch_break___0;
              case_88:
                change->flags = (char)((int)change->flags | 1);
              case_120:
                change->value |= (unsigned int)((64 | (64 >> 3)) | ((64 >> 3) >> 3)) & affected_masked;
                goto switch_break___0;
              case_115:
                change->value |= 3072U & affected_masked;
                goto switch_break___0;
              case_116:
                change->value |= 512U & affected_masked;
                goto switch_break___0;

                change->value = (mode_t)448;
                change->flags = (char)((int)change->flags | 2);
                goto switch_break___0;
              case_103___0:
                if (change->value) {
                  goto invalid;
                }
                change->value = (mode_t)(448 >> 3);
                change->flags = (char)((int)change->flags | 2);
                goto switch_break___0;
              case_111___0:
                if (change->value) {
                  goto invalid;
                }
                change->value = (mode_t)((448 >> 3) >> 3);
                change->flags = (char)((int)change->flags | 2);
                goto switch_break___0;
              switch_default___0:
                goto no_more_values;
              switch_break___0:
                mode_string___0++;
              };
            }

          no_more_values:;
          };
        }
      while_break___1:;
        if (!((int const) * mode_string___0 == 44)) {
          goto while_break;
        }
      };
    }
  while_break:;
    if ((int const) * mode_string___0 == 0) {
      return (head);
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

              if (value & (unsigned int)(64 >> 3)) {
                tmp___4 = 64 | ((64 >> 3) >> 3);
              } else {
                tmp___4 = 0;
              }
              value |= (unsigned int)((tmp___2 | tmp___3) | tmp___4);
            } else {

              value |= (unsigned int)((tmp___5 | tmp___6) | tmp___7);
            }
          }
          value &= (unsigned int)changes->affected;
        } else {
          value = (mode_t)changes->value;
          if ((int const)changes->flags & 1) {
            if (!((oldmode & 61440U) == 16384U)) {
              if ((newmode & (unsigned int)((64 | (64 >> 3)) | ((64 >> 3) >> 3))) == 0U) {
                value &= (unsigned int)(~((64 | (64 >> 3)) | ((64 >> 3) >> 3)));
              }
            }
          }
        }
        if ((int const)changes->op == 61) {
          goto case_61;
        }

        goto switch_break;
      case_61:
        newmode = (newmode & (unsigned int)(~changes->affected)) | value;
        goto switch_break;
        newmode |= value;
        goto switch_break;
        newmode &= ~value;
        goto switch_break;
      switch_break:
        changes = (struct mode_change const *)changes->next;
      };
    }
  while_break:;
    return (newmode);
  }
}
void mode_free(struct mode_change *changes) {

  {
    { ; }
    return;
  }
}
static unsigned short const __mon_yday[2][13] = {{(unsigned short const)0, (unsigned short const)31, (unsigned short const)59, (unsigned short const)90, (unsigned short const)120, (unsigned short const)151, (unsigned short const)181, (unsigned short const)212, (unsigned short const)243,
                                                  (unsigned short const)273, (unsigned short const)304, (unsigned short const)334, (unsigned short const)365},
                                                 {(unsigned short const)0, (unsigned short const)31, (unsigned short const)60, (unsigned short const)91, (unsigned short const)121, (unsigned short const)152, (unsigned short const)182, (unsigned short const)213, (unsigned short const)244,
                                                  (unsigned short const)274, (unsigned short const)305, (unsigned short const)335, (unsigned short const)366}};
static time_t localtime_offset;
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcoll)(char const *__s1, char const *__s2) __attribute__((__pure__));
static unsigned char const fillbuf___0[64] = {(unsigned char const)128, (unsigned char const)0};
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) wcwidth)(wchar_t __c);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) iswcntrl)(wint_t __wc);
int make_path(char const *argpath, int mode, int parent_mode, uid_t owner, gid_t group, int preserve_existing, char const *verbose_fmt_string);
int make_dir(char const *dir, char const *dirpath, mode_t mode, int *created_dir_p);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) chmod)(char const *__file, __mode_t __mode);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) mkdir)(char const *__path, __mode_t __mode);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) chown)(char const *__file, __uid_t __owner, __gid_t __group);
int make_dir(char const *dir, char const *dirpath, mode_t mode, int *created_dir_p) {
  int fail;
  int created_dir;
  int tmp;
  struct stat stats;
  int saved_errno;
  int *tmp___0;
  char const *tmp___1;
  char *tmp___2;
  int tmp___5;

  {
    {
      fail = 0;
      tmp = mkdir(dir, mode);
      created_dir = tmp == 0;
    }
    if (!created_dir) {
      {
        tmp___0 = __errno_location();
        saved_errno = *tmp___0;
        tmp___5 = stat((char const * /* __restrict  */)dir, (struct stat * /* __restrict  */)(&stats));
      }
      if (tmp___5) {
        {
          tmp___1 = quote(dirpath);
          tmp___2 = gettext("cannot create directory %s");
          error(0, saved_errno, (char const *)tmp___2, tmp___1);
          fail = 1;
        }
      }
    }
    if (created_dir_p) {
      *created_dir_p = created_dir;
    }
    return (fail);
  }
}
int make_path(char const *argpath, int mode, int parent_mode, uid_t owner, gid_t group, int preserve_existing, char const *verbose_fmt_string) {
  struct stat stats;
  int retval;
  char *slash;
  int tmp_mode;
  int re_protect;
  struct ptr_list *p;
  struct ptr_list *leading_dirs;
  int do_chdir;
  struct saved_cwd cwd;
  char *basename_dir;
  char *dirpath;
  mode_t oldmask;
  __mode_t tmp;
  size_t tmp___0;
  void *tmp___1;
  int tmp___2;
  int tmp___3;
  int newly_created_dir;
  int fail;
  int tmp___9;
  char const *tmp___11;
  char *tmp___12;
  int *tmp___13;
  int _saved_errno___0;
  int *tmp___14;
  char *tmp___15;
  int *tmp___16;
  int *tmp___17;
  int tmp___18;
  int tmp___19;
  char const *tmp___21;
  char *tmp___22;
  int *tmp___23;
  int tmp___28;
  int tmp___29;
  char *tmp___30;
  int tmp___36;
  char const *tmp___42;
  char *tmp___43;
  int *tmp___44;
  int tmp___45;
  int tmp___50;
  char const *tmp___51;
  char *tmp___52;
  int *tmp___53;
  int tmp___54;
  char const *dirpath___0;
  char const *tmp___55;
  char *tmp___56;
  int tmp___65;

  {
    {
      retval = 0;
      tmp___65 = stat((char const * /* __restrict  */)argpath, (struct stat * /* __restrict  */)(&stats));
    }
    if (tmp___65) {
      {
        leading_dirs = (struct ptr_list *)((void *)0);
        tmp = umask((__mode_t)0);
        oldmask = tmp;
        tmp___0 = strlen(argpath);
        tmp___1 = __builtin_alloca(tmp___0 + 1UL);
        dirpath = (char *)tmp___1;
        strcpy((char * /* __restrict  */)dirpath, (char const * /* __restrict  */)argpath);
        strip_trailing_slashes(dirpath);
      }
      if ((parent_mode & 192) != 192) {
        tmp_mode = 448;
        re_protect = 1;
      }
      { tmp___2 = save_cwd(&cwd); }

      do_chdir = tmp___3;

      slash = dirpath;
      { ; }
      {
        while (1) {
          ;
          {
            basename_dir = slash;
            slash = strchr((char const *)slash, '/');
          }
          if ((unsigned long)slash == (unsigned long)((void *)0)) {
            goto while_break___0;
          }
          if (!do_chdir) {
            basename_dir = dirpath;
          }
          {
            *slash = (char)'\000';
            fail = make_dir((char const *)basename_dir, (char const *)dirpath, (mode_t)tmp_mode, &newly_created_dir);
          }
          if (fail) {
            {
              while (1) {
                ;
                { umask(oldmask); }
                {
                  while (1) {
                    ;

                    if (do_chdir) {
                      {
                        tmp___9 = restore_cwd((struct saved_cwd const *)(&cwd));
                      }

                      { free_cwd(&cwd); }
                    }
                    goto while_break___2;
                  };
                }
              while_break___2:;
                goto while_break___1;
              };
            }
          while_break___1:;
            return (1);
          }
          if (newly_created_dir) {

            if (owner != 4294967295U) {
              goto _L___0;
            } else {
              if (group != 4294967295U) {
              _L___0: { tmp___19 = chown((char const *)basename_dir, owner, group); }
                if (tmp___19) {
                  {
                    tmp___11 = quote((char const *)dirpath);
                    tmp___12 = gettext("cannot change owner and/or group of %s");
                    tmp___13 = __errno_location();
                    error(0, *tmp___13, (char const *)tmp___12, tmp___11);
                  }
                  {
                    while (1) {
                      ;
                      { umask(oldmask); }
                      {
                        while (1) {
                          ;

                          if (do_chdir) {
                            {
                              tmp___18 = restore_cwd((struct saved_cwd const *)(&cwd));
                            }
                            if (tmp___18 != 0) {
                              {
                                tmp___14 = __errno_location();
                                _saved_errno___0 = *tmp___14;

                                tmp___16 = __errno_location();
                                error(0, *tmp___16, (char const *)tmp___15);
                                free_cwd(&cwd);
                                tmp___17 = __errno_location();
                                *tmp___17 = _saved_errno___0;
                              }
                              return (1);
                            }
                            { free_cwd(&cwd); }
                          }
                          goto while_break___4;
                        };
                      }
                    while_break___4:;
                      goto while_break___3;
                    };
                  }
                while_break___3:;
                  return (1);
                }
              }
            }
          }
          if (do_chdir) {
            {
              tmp___29 = chdir((char const *)basename_dir);
            }
            if (tmp___29 < 0) {
              {
                tmp___21 = quote((char const *)dirpath);
                tmp___22 = gettext("cannot chdir to directory %s");
                tmp___23 = __errno_location();
                error(0, *tmp___23, (char const *)tmp___22, tmp___21);
              }
              {
                while (1) {
                  ;
                  { umask(oldmask); }
                  {
                    while (1) {
                      ;

                      if (do_chdir) {
                        {
                          tmp___28 = restore_cwd((struct saved_cwd const *)(&cwd));
                        }

                        { free_cwd(&cwd); }
                      }
                      goto while_break___6;
                    };
                  }
                while_break___6:;
                  goto while_break___5;
                };
              }
            while_break___5:;
              return (1);
            }
          }
          tmp___30 = slash;
          slash++;
          *tmp___30 = (char)'/';
          {
            while (1) {
              ;

              if (!((int)*slash == 47)) {
                goto while_break___7;
              }
              slash++;
            };
          }
        while_break___7:;
        };
      }
    while_break___0:;
      if (!do_chdir) {
        basename_dir = dirpath;
      }
      {
        umask(oldmask);
        tmp___36 = make_dir((char const *)basename_dir, (char const *)dirpath, (mode_t)mode, (int *)((void *)0));
      }

      if (mode & ~((448 | (448 >> 3)) | ((448 >> 3) >> 3))) {
        {
          tmp___45 = chmod((char const *)basename_dir, (__mode_t)mode);
        }
        if (tmp___45) {
          {
            tmp___42 = quote((char const *)dirpath);
            tmp___43 = gettext("cannot change permissions of %s");
            tmp___44 = __errno_location();
            error(0, *tmp___44, (char const *)tmp___43, tmp___42);
            retval = 1;
          }
        }
      }
      {
        while (1) {
          ;

          if (do_chdir) {
            {
              tmp___50 = restore_cwd((struct saved_cwd const *)(&cwd));
            }

            { free_cwd(&cwd); }
          }
          goto while_break___10;
        };
      }
    while_break___10:
      p = leading_dirs;
      {
        while (1) {
          ;

          if (!((unsigned long)p != (unsigned long)((void *)0))) {
            goto while_break___11;
          }
          {
            *(p->dirname_end) = (char)'\000';
            tmp___54 = chmod((char const *)dirpath, (__mode_t)parent_mode);
          }
          if (tmp___54) {
            {
              tmp___51 = quote((char const *)dirpath);
              tmp___52 = gettext("cannot change permissions of %s");
              tmp___53 = __errno_location();
              error(0, *tmp___53, (char const *)tmp___52, tmp___51);
              retval = 1;
            }
          }
          p = p->next;
        };
      }
    while_break___11:;
    } else {
      dirpath___0 = argpath;
      if (!((stats.st_mode & 61440U) == 16384U)) {
        {
          tmp___55 = quote(dirpath___0);
          tmp___56 = gettext("%s exists but is not a directory");
          error(0, 0, (char const *)tmp___56, tmp___55);
        }
        return (1);
      }
    }
    return (retval);
  }
}
extern struct _IO_FILE *stdout;
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) exit)(int __status);
extern int optind;
extern int opterr;
extern int getopt_long(int ___argc, char *const *___argv, char const *__shortopts, struct option const *__longopts, int *__longind);
static struct option const long_options[3] = {{"help", 0, (int *)0, 'h'}, {"version", 0, (int *)0, 'v'}, {(char const *)0, 0, (int *)0, 0}};
extern int fclose(FILE *__stream);
extern FILE *fopen(char const *__restrict __filename, char const *__restrict __modes);
extern int fscanf(FILE *__restrict __stream, char const *__restrict __format, ...);
extern int ungetc(int __c, FILE *__stream);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) nl_langinfo)(nl_item __item);
static char const *volatile charset_aliases;
extern struct passwd *getpwuid(__uid_t __uid);
static struct userid *user_alist;
static struct userid *nouser_alist;
static struct userid *group_alist;
static struct userid *nogroup_alist;
extern __attribute__((__nothrow__)) struct lconv *(__attribute__((__leaf__)) localeconv)(void);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memmove)(void *__dest, void const *__src, size_t __n);
static char const power_letter[9] = {(char const)0, (char const)'K', (char const)'M', (char const)'G', (char const)'T', (char const)'P', (char const)'E', (char const)'Z', (char const)'Y'};
static char const *const block_size_args[3] = {(char const * /* const  */) "human-readable", (char const * /* const  */) "si", (char const * /* const  */)((char const *)0)};
static int const block_size_opts[2] = {(int const)112, (int const)80};
static struct hash_tuning const default_tuning = {(float)0.0, (float)1.0, (float)0.8, (float)1.414, (_Bool)0};
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) setlocale)(int __category, char const *__locale);
extern void setgrent(void);
extern struct group *getgrent(void);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) gettimeofday)(struct timeval *__restrict __tv, __timezone_ptr_t __tz);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) clock_gettime)(clockid_t __clock_id, struct timespec *__tp);
static unsigned char const yytranslate[274] = {
    (unsigned char const)0,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)20, (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)21, (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)19, (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)1,  (unsigned char const)2,  (unsigned char const)3,  (unsigned char const)4,  (unsigned char const)5,  (unsigned char const)6,  (unsigned char const)7, (unsigned char const)8,
    (unsigned char const)9,  (unsigned char const)10, (unsigned char const)11, (unsigned char const)12, (unsigned char const)13, (unsigned char const)14, (unsigned char const)15, (unsigned char const)16, (unsigned char const)17, (unsigned char const)18};
static unsigned char const yyr1[56] = {(unsigned char const)0,  (unsigned char const)22, (unsigned char const)23, (unsigned char const)23, (unsigned char const)24, (unsigned char const)24, (unsigned char const)24, (unsigned char const)24, (unsigned char const)24, (unsigned char const)24,
                                       (unsigned char const)24, (unsigned char const)25, (unsigned char const)25, (unsigned char const)25, (unsigned char const)25, (unsigned char const)25, (unsigned char const)26, (unsigned char const)26, (unsigned char const)27, (unsigned char const)27,
                                       (unsigned char const)27, (unsigned char const)28, (unsigned char const)28, (unsigned char const)28, (unsigned char const)29, (unsigned char const)29, (unsigned char const)29, (unsigned char const)29, (unsigned char const)29, (unsigned char const)29,
                                       (unsigned char const)29, (unsigned char const)29, (unsigned char const)29, (unsigned char const)30, (unsigned char const)30, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
                                       (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
                                       (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)32, (unsigned char const)33, (unsigned char const)33};
static unsigned char const yyr2[56] = {(unsigned char const)0, (unsigned char const)2, (unsigned char const)0, (unsigned char const)2, (unsigned char const)1, (unsigned char const)1, (unsigned char const)1, (unsigned char const)1, (unsigned char const)1, (unsigned char const)1,
                                       (unsigned char const)1, (unsigned char const)2, (unsigned char const)4, (unsigned char const)4, (unsigned char const)6, (unsigned char const)6, (unsigned char const)1, (unsigned char const)2, (unsigned char const)1, (unsigned char const)1,
                                       (unsigned char const)2, (unsigned char const)1, (unsigned char const)2, (unsigned char const)2, (unsigned char const)3, (unsigned char const)5, (unsigned char const)3, (unsigned char const)3, (unsigned char const)3, (unsigned char const)2,
                                       (unsigned char const)4, (unsigned char const)2, (unsigned char const)3, (unsigned char const)2, (unsigned char const)1, (unsigned char const)2, (unsigned char const)2, (unsigned char const)1, (unsigned char const)2, (unsigned char const)2,
                                       (unsigned char const)1, (unsigned char const)2, (unsigned char const)2, (unsigned char const)1, (unsigned char const)2, (unsigned char const)2, (unsigned char const)1, (unsigned char const)2, (unsigned char const)2, (unsigned char const)1,
                                       (unsigned char const)2, (unsigned char const)2, (unsigned char const)1, (unsigned char const)1, (unsigned char const)0, (unsigned char const)1};
static unsigned char const yydefact[66] = {(unsigned char const)2,  (unsigned char const)0,  (unsigned char const)1,  (unsigned char const)21, (unsigned char const)43, (unsigned char const)19, (unsigned char const)46, (unsigned char const)16, (unsigned char const)49, (unsigned char const)0,
                                           (unsigned char const)40, (unsigned char const)52, (unsigned char const)37, (unsigned char const)18, (unsigned char const)0,  (unsigned char const)53, (unsigned char const)3,  (unsigned char const)4,  (unsigned char const)5,  (unsigned char const)6,
                                           (unsigned char const)8,  (unsigned char const)7,  (unsigned char const)9,  (unsigned char const)34, (unsigned char const)10, (unsigned char const)22, (unsigned char const)17, (unsigned char const)0,  (unsigned char const)29, (unsigned char const)20,
                                           (unsigned char const)42, (unsigned char const)45, (unsigned char const)48, (unsigned char const)39, (unsigned char const)51, (unsigned char const)36, (unsigned char const)23, (unsigned char const)41, (unsigned char const)44, (unsigned char const)11,
                                           (unsigned char const)47, (unsigned char const)31, (unsigned char const)38, (unsigned char const)50, (unsigned char const)35, (unsigned char const)0,  (unsigned char const)0,  (unsigned char const)0,  (unsigned char const)33, (unsigned char const)28,
                                           (unsigned char const)0,  (unsigned char const)27, (unsigned char const)32, (unsigned char const)26, (unsigned char const)54, (unsigned char const)24, (unsigned char const)30, (unsigned char const)55, (unsigned char const)13, (unsigned char const)0,
                                           (unsigned char const)12, (unsigned char const)0,  (unsigned char const)54, (unsigned char const)25, (unsigned char const)15, (unsigned char const)14};
static yysigned_char const yydefgoto[12] = {(yysigned_char const)-1, (yysigned_char const)1,  (yysigned_char const)16, (yysigned_char const)17, (yysigned_char const)18, (yysigned_char const)19,
                                            (yysigned_char const)20, (yysigned_char const)21, (yysigned_char const)22, (yysigned_char const)23, (yysigned_char const)24, (yysigned_char const)60};
static yysigned_char const yypact[66] = {(yysigned_char const)-17, (yysigned_char const)0,   (yysigned_char const)-17, (yysigned_char const)1,   (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)19,  (yysigned_char const)-17, (yysigned_char const)-16,
                                         (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)32,  (yysigned_char const)26,  (yysigned_char const)14,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17,
                                         (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)27,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-13, (yysigned_char const)24,  (yysigned_char const)-17,
                                         (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17,
                                         (yysigned_char const)-17, (yysigned_char const)25,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)29,  (yysigned_char const)30,  (yysigned_char const)31,  (yysigned_char const)-17, (yysigned_char const)-17,
                                         (yysigned_char const)33,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)28,  (yysigned_char const)34,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)35,
                                         (yysigned_char const)-17, (yysigned_char const)36,  (yysigned_char const)-7,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17};
static yysigned_char const yypgoto[12] = {(yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17,
                                          (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-12};
static unsigned char const yytable[56] = {(unsigned char const)2,  (unsigned char const)27, (unsigned char const)28, (unsigned char const)57, (unsigned char const)49, (unsigned char const)3,  (unsigned char const)4,  (unsigned char const)5,  (unsigned char const)6,  (unsigned char const)7,
                                          (unsigned char const)64, (unsigned char const)8,  (unsigned char const)9,  (unsigned char const)10, (unsigned char const)11, (unsigned char const)12, (unsigned char const)13, (unsigned char const)14, (unsigned char const)15, (unsigned char const)36,
                                          (unsigned char const)37, (unsigned char const)25, (unsigned char const)38, (unsigned char const)26, (unsigned char const)39, (unsigned char const)40, (unsigned char const)41, (unsigned char const)42, (unsigned char const)43, (unsigned char const)44,
                                          (unsigned char const)48, (unsigned char const)45, (unsigned char const)30, (unsigned char const)46, (unsigned char const)31, (unsigned char const)47, (unsigned char const)29, (unsigned char const)32, (unsigned char const)57, (unsigned char const)33,
                                          (unsigned char const)34, (unsigned char const)35, (unsigned char const)51, (unsigned char const)52, (unsigned char const)50, (unsigned char const)58, (unsigned char const)53, (unsigned char const)59, (unsigned char const)54, (unsigned char const)55,
                                          (unsigned char const)65, (unsigned char const)56, (unsigned char const)0,  (unsigned char const)62, (unsigned char const)63, (unsigned char const)61};
static yysigned_char const yycheck[56] = {(yysigned_char const)0,  (yysigned_char const)17, (yysigned_char const)18, (yysigned_char const)10, (yysigned_char const)17, (yysigned_char const)5,  (yysigned_char const)6,  (yysigned_char const)7,  (yysigned_char const)8,  (yysigned_char const)9,
                                          (yysigned_char const)17, (yysigned_char const)11, (yysigned_char const)12, (yysigned_char const)13, (yysigned_char const)14, (yysigned_char const)15, (yysigned_char const)16, (yysigned_char const)17, (yysigned_char const)18, (yysigned_char const)5,
                                          (yysigned_char const)6,  (yysigned_char const)20, (yysigned_char const)8,  (yysigned_char const)4,  (yysigned_char const)10, (yysigned_char const)11, (yysigned_char const)12, (yysigned_char const)13, (yysigned_char const)14, (yysigned_char const)15,
                                          (yysigned_char const)3,  (yysigned_char const)17, (yysigned_char const)6,  (yysigned_char const)19, (yysigned_char const)8,  (yysigned_char const)21, (yysigned_char const)4,  (yysigned_char const)11, (yysigned_char const)10, (yysigned_char const)13,
                                          (yysigned_char const)14, (yysigned_char const)15, (yysigned_char const)17, (yysigned_char const)18, (yysigned_char const)20, (yysigned_char const)17, (yysigned_char const)17, (yysigned_char const)19, (yysigned_char const)18, (yysigned_char const)18,
                                          (yysigned_char const)62, (yysigned_char const)18, (yysigned_char const)-1, (yysigned_char const)18, (yysigned_char const)18, (yysigned_char const)21};
static unsigned char const yystos[66] = {(unsigned char const)0,  (unsigned char const)23, (unsigned char const)0,  (unsigned char const)5,  (unsigned char const)6,  (unsigned char const)7,  (unsigned char const)8,  (unsigned char const)9,  (unsigned char const)11, (unsigned char const)12,
                                         (unsigned char const)13, (unsigned char const)14, (unsigned char const)15, (unsigned char const)16, (unsigned char const)17, (unsigned char const)18, (unsigned char const)24, (unsigned char const)25, (unsigned char const)26, (unsigned char const)27,
                                         (unsigned char const)28, (unsigned char const)29, (unsigned char const)30, (unsigned char const)31, (unsigned char const)32, (unsigned char const)20, (unsigned char const)4,  (unsigned char const)17, (unsigned char const)18, (unsigned char const)4,
                                         (unsigned char const)6,  (unsigned char const)8,  (unsigned char const)11, (unsigned char const)13, (unsigned char const)14, (unsigned char const)15, (unsigned char const)5,  (unsigned char const)6,  (unsigned char const)8,  (unsigned char const)10,
                                         (unsigned char const)11, (unsigned char const)12, (unsigned char const)13, (unsigned char const)14, (unsigned char const)15, (unsigned char const)17, (unsigned char const)19, (unsigned char const)21, (unsigned char const)3,  (unsigned char const)17,
                                         (unsigned char const)20, (unsigned char const)17, (unsigned char const)18, (unsigned char const)17, (unsigned char const)18, (unsigned char const)18, (unsigned char const)18, (unsigned char const)10, (unsigned char const)17, (unsigned char const)19,
                                         (unsigned char const)33, (unsigned char const)21, (unsigned char const)18, (unsigned char const)18, (unsigned char const)17, (unsigned char const)33};
static table const meridian_table[5] = {{"AM", 265, 0}, {"A.M.", 265, 0}, {"PM", 265, 1}, {"P.M.", 265, 1}, {(char const *)0, 0, 0}};
static table const dst_table[1] = {{"DST", 259, 0}};

static table const time_units_table[11] = {{"YEAR", 270, 1}, {"MONTH", 268, 1}, {"FORTNIGHT", 261, 14}, {"WEEK", 261, 7}, {"DAY", 261, 1}, {"HOUR", 263, 1}, {"MINUTE", 266, 1}, {"MIN", 266, 1}, {"SECOND", 269, 1}, {"SEC", 269, 1}, {(char const *)0, 0, 0}};
static table const relative_time_table[20] = {{"TOMORROW", 261, 1}, {"YESTERDAY", 261, -1}, {"TODAY", 261, 0},   {"NOW", 261, 0},    {"LAST", 273, -1}, {"THIS", 273, 0},   {"NEXT", 273, 1},      {"FIRST", 273, 1},    {"THIRD", 273, 3}, {"FOURTH", 273, 4},
                                              {"FIFTH", 273, 5},    {"SIXTH", 273, 6},      {"SEVENTH", 273, 7}, {"EIGHTH", 273, 8}, {"NINTH", 273, 9}, {"TENTH", 273, 10}, {"ELEVENTH", 273, 11}, {"TWELFTH", 273, 12}, {"AGO", 258, 1},   {(char const *)0, 0, 0}};

static table const military_table[26] = {{"A", 271, -60}, {"B", 271, -120}, {"C", 271, -180}, {"D", 271, -240}, {"E", 271, -300}, {"F", 271, -360}, {"G", 271, -420}, {"H", 271, -480}, {"I", 271, -540}, {"K", 271, -600}, {"L", 271, -660}, {"M", 271, -720}, {"N", 271, 60},
                                         {"O", 271, 120}, {"P", 271, 180},  {"Q", 271, 240},  {"R", 271, 300},  {"S", 271, 360},  {"T", 271, 420},  {"U", 271, 480},  {"V", 271, 540},  {"W", 271, 600},  {"X", 271, 660},  {"Y", 271, 720},  {"Z", 271, 0},    {(char const *)0, 0, 0}};
extern char *getcwd(char *buf, size_t size);
__attribute__((__nothrow__)) char *(__attribute__((__leaf__)) rpl_getcwd)(char *buf, size_t size);
char *(__attribute__((__leaf__)) rpl_getcwd)(char *buf, size_t size) {
  char *cwd;
  char *tmp;
  size_t tmp___0;
  int tmp___1;
  int *tmp___2;

  {
    {
      tmp = getcwd(buf, size);
      cwd = tmp;
    }

    { tmp___0 = strlen((char const *)cwd); }
    if (tmp___0 <= 3839UL) {
      return (cwd);
    } else {
      { tmp___1 = same_name((char const *)cwd, "."); }
    }
    {
      rpl_free((void *)cwd);
      tmp___2 = __errno_location();
      *tmp___2 = 36;
    }
    return ((char *)((void *)0));
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd, struct stat *__buf);
extern void(__attribute__((__nonnull__(1, 4))) qsort)(void *__base, size_t __nmemb, size_t __size, int (*__compar)(void const *, void const *));
extern char *(__attribute__((__nonnull__(1))) strrchr)(char const *__s, int __c) __attribute__((__pure__));
extern int(__attribute__((__nonnull__(1))) dirfd)(DIR *__dirp);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) statfs)(char const *__file, struct statfs *__buf);
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(void *__ptr);
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) rpl_free)(void *p);
void(__attribute__((__leaf__)) rpl_free)(void *p) {

  {
    if (p) {
      {
        free(p);
      }
    }
    return;
  }
}
extern __attribute__((__nothrow__)) FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(FILE *__stream);
int volatile exit_failure = (int volatile)1;
extern struct _IO_FILE *stdin;
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcasecmp)(char const *__s1, char const *__s2) __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strncasecmp)(char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
extern int fnmatch(char const *__pattern, char const *__name, int __flags);
extern int fcntl(int __fd, int __cmd, ...);
size_t dir_len(char const *path);
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
void close_stdout(void);
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) __fpending)(FILE *__fp);
static char const *file_name;
void close_stdout(void) {
  int e;
  int tmp___0;
  int tmp___1;
  int tmp___4;
  char const *write_error;
  char *tmp___5;
  char *tmp___6;

  {
    { tmp___1 = ferror_unlocked(stdout); }
    if (tmp___1) {
      tmp___0 = 0;
    } else {
      tmp___0 = -1;
    }
    e = tmp___0;

    { tmp___4 = fclose(stdout); }

    if (0 <= e) {
      {
        tmp___5 = gettext("write error");
        write_error = (char const *)tmp___5;
      }
      if (file_name) {
        {
          tmp___6 = quotearg_colon(file_name);
          error((int)exit_failure, e, "%s: %s", tmp___6, write_error);
        }
      } else {
        { error((int)exit_failure, e, "%s", write_error); }
      }
    }
    return;
  }
}
extern struct hostent *gethostbyaddr(void const *__addr, __socklen_t __len, int __type);
extern struct hostent *gethostbyname(char const *__name);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) inet_ntoa)(struct in_addr __in);
extern __attribute__((__nothrow__)) double(__attribute__((__nonnull__(1), __leaf__)) strtod)(char const *__restrict __nptr, char **__restrict __endptr);
char *base_name(char const *name) {
  char const *base;
  char const *p;

  {
    base = name + 0;
    p = base;
    { ; }
    return ((char *)base);
  }
}
size_t base_len(char const *name) {
  size_t len;

  {
    { len = strlen(name); }
    { ; }
    return (len);
  }
}
void (*argmatch_die)(void);
char const *simple_backup_suffix;
char const *simple_backup_suffix = "~";
static char const *const backup_args[9] = {(char const * /* const  */) "none", (char const * /* const  */) "off",      (char const * /* const  */) "simple", (char const * /* const  */) "never",         (char const * /* const  */) "existing",
                                           (char const * /* const  */) "nil",  (char const * /* const  */) "numbered", (char const * /* const  */) "t",      (char const * /* const  */)((char const *)0)};
static enum backup_type const backup_types[8] = {(enum backup_type const)0, (enum backup_type const)0, (enum backup_type const)1, (enum backup_type const)1, (enum backup_type const)2, (enum backup_type const)2, (enum backup_type const)3, (enum backup_type const)3};
extern struct _IO_FILE *stderr;
void usage(int status);
extern __attribute__((__nothrow__)) long(__attribute__((__nonnull__(1), __leaf__)) pathconf)(char const *__path, int __name);
extern int printf(char const *__restrict __format, ...);
extern char *optarg;
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) atexit)(void (*__func)(void));
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) textdomain)(char const *__domainname);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) bindtextdomain)(char const *__domainname, char const *__dirname);
char *program_name;
static int create_parents;
static struct option const longopts[6] = {{"mode", 1, (int *)((void *)0), 'm'}, {"parents", 0, (int *)((void *)0), 'p'}, {"verbose", 0, (int *)((void *)0), 'v'}, {"help", 0, (int *)0, -130}, {"version", 0, (int *)0, -131}, {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
void usage(int status) {

  {

    { exit(status); }
  }
}
int main(int argc, char **argv) {
  mode_t newmode;
  mode_t parent_mode;
  char const *specified_mode;
  char const *verbose_fmt_string;
  int errors;
  int optc;
  char *tmp;
  mode_t umask_value;
  __mode_t tmp___1;
  struct mode_change *change;
  struct mode_change *tmp___2;
  __mode_t tmp___3;
  int fail;
  char *dir;
  char const *dir___0;
  int dir_created;
  char const *tmp___6;
  char *tmp___7;
  char const *tmp___8;
  char const *tmp___9;
  char *tmp___10;
  int *tmp___11;

  {
    {
      specified_mode = (char const *)((void *)0);
      verbose_fmt_string = (char const *)((void *)0);
      errors = 0;
      program_name = *(argv + 0);
      setlocale(6, "");
      bindtextdomain("coreutils", "/usr/local/share/locale");
      textdomain("coreutils");
      atexit(&close_stdout);
      create_parents = 0;
    }
    {
      while (1) {
        ;
        { optc = getopt_long(argc, (char *const *)argv, "pm:v", longopts, (int *)((void *)0)); }
        if (!(optc != -1)) {
          goto while_break;
        }

        if (optc == 109) {
          goto case_109;
        }

        goto switch_default;
        goto switch_break;
        create_parents = 1;
        goto switch_break;
      case_109:
        specified_mode = (char const *)optarg;
        goto switch_break;
      case_118: {
        tmp = gettext("created directory %s");
        verbose_fmt_string = (char const *)tmp;
      }
        goto switch_break;
      case_neg_130: { usage(0); }
        goto switch_break;
      case_neg_131: {
        version_etc(stdout, "mkdir", "coreutils", "5.2.1", "David MacKenzie", (char *)((void *)0));
        exit(0);
      }
        goto switch_break;
      switch_default: { usage(1); }
      switch_break:;
      };
    }
  while_break:;
    {
      newmode = (mode_t)((448 | (448 >> 3)) | ((448 >> 3) >> 3));
      tmp___1 = umask((__mode_t)0);
      umask_value = tmp___1;
      umask(umask_value);
      parent_mode = ((newmode & ~umask_value) | 128U) | 64U;
    }
    if (specified_mode) {
      {
        tmp___2 = mode_compile(specified_mode, 0U);
        change = tmp___2;
        tmp___3 = umask((__mode_t)0);
        newmode &= ~tmp___3;
      }

      { newmode = mode_adjust(newmode, (struct mode_change const *)change); }
    }
    {
      while (1) {
        ;

        if (!(optind < argc)) {
          goto while_break___0;
        }
        fail = 0;
        if (create_parents) {
          {
            dir = *(argv + optind);
            fail = make_path((char const *)dir, (int)newmode, (int)parent_mode, (uid_t)-1, (gid_t)-1, 1, verbose_fmt_string);
          }
        } else {
          {
            dir___0 = (char const *)*(argv + optind);
            fail = make_dir(dir___0, dir___0, newmode, &dir_created);
          }
          if (!fail) {
            if (!create_parents) {
              if (!dir_created) {
                {
                  tmp___6 = quote(dir___0);
                  tmp___7 = gettext("cannot create directory %s");
                  error(0, 17, (char const *)tmp___7, tmp___6);
                  fail = 1;
                }
              } else {
                goto _L;
              }
            } else {
            _L:
              if (verbose_fmt_string) {
                {
                  tmp___8 = quote(dir___0);
                  error(0, 0, verbose_fmt_string, tmp___8);
                }
              }
            }
          }
          if (fail == 0) {
            if (specified_mode) {
              if (dir_created) {
                {
                  fail = chmod(dir___0, newmode);
                }
                if (fail) {
                  {
                    tmp___9 = quote(dir___0);
                    tmp___10 = gettext("cannot set permissions of directory %s");
                    tmp___11 = __errno_location();
                    error(0, *tmp___11, (char const *)tmp___10, tmp___9);
                  }
                }
              }
            }
          }
        }
        if (fail) {
          errors = 1;
        }
        optind++;
      };
    }
  while_break___0: { exit(errors); }
  }
}
