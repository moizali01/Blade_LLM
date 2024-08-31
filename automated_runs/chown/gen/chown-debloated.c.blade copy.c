
typedef unsigned long size_t;
typedef long __off_t;
typedef long __off64_t;
struct _IO_FILE;
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
typedef long __time_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef long __syscall_slong_t;
typedef __mode_t mode_t;
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
typedef __ino_t ino_t;
typedef __dev_t dev_t;
struct hash_table;
struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
struct F_triple {
  char *name;
  ino_t st_ino;
  dev_t st_dev;
};
struct __dirstream;
struct __dirstream;
struct __dirstream;
typedef struct __dirstream DIR;
typedef int wchar_t;
union __anonunion___value_4 {
  unsigned int __wch;
  char __wchb[4];
};
struct __anonstruct___mbstate_t_3 {
  int __count;
  union __anonunion___value_4 __value;
};
typedef struct __anonstruct___mbstate_t_3 __mbstate_t;
typedef unsigned int wint_t;
struct hash_tuning {
  float shrink_threshold;
  float shrink_factor;
  float growth_threshold;
  float growth_factor;
  _Bool is_n_buckets;
};
typedef struct hash_tuning Hash_tuning;
typedef __mbstate_t mbstate_t;
struct mbchar {
  char const *ptr;
  size_t bytes;
  _Bool wc_valid;
  wchar_t wc;
  char buf[24];
};
struct mbuiter_multi {
  _Bool in_shift;
  mbstate_t state;
  _Bool next_done;
  struct mbchar cur;
};
typedef struct mbuiter_multi mbui_iterator_t;
typedef __gid_t gid_t;
typedef __uid_t uid_t;
typedef unsigned long uintmax_t;
struct dev_ino {
  ino_t st_ino;
  dev_t st_dev;
};
struct cycle_check_state {
  struct dev_ino dev_ino;
  uintmax_t chdir_counter;
  int magic;
};
typedef long ptrdiff_t;
struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
};
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
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
struct _ftsent;
union __anonunion_fts_cycle_29 {
  struct hash_table *ht;
  struct cycle_check_state *state;
};
struct __anonstruct_FTS_28 {
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
  union __anonunion_fts_cycle_29 fts_cycle;
  I_ring fts_fd_ring;
};
typedef struct __anonstruct_FTS_28 FTS;
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
typedef unsigned long reg_syntax_t;
struct quoting_options;
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
struct hash_entry {
  void *data;
  struct hash_entry *next;
};
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
enum Change_status { CH_NOT_APPLIED = 1, CH_SUCCEEDED = 2, CH_FAILED = 3, CH_NO_CHANGE_REQUESTED = 4 };
enum Verbosity { V_high = 0, V_changes_only = 1, V_off = 2 };
struct Chown_option {
  enum Verbosity verbosity;
  _Bool recurse;
  struct dev_ino *root_dev_ino;
  _Bool affect_symlink_referent;
  _Bool force_silent;
  char *user_name;
  char *group_name;
};
enum RCH_status { RC_ok = 2, RC_excluded = 3, RC_inode_changed = 4, RC_do_ordinary_chown = 5, RC_error = 6 };
extern __attribute__((__nothrow__)) int *(__attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern int close(int __fd);
extern int(__attribute__((__nonnull__(1))) open)(char const *__file, int __oflag, ...);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) tolower)(int __c);
extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s) __attribute__((__pure__));
extern int fclose(FILE *__stream);
int dup_safer(int fd);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2) __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strncmp)(char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
__attribute__((__noreturn__)) void xalloc_die(void);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(size_t __size) __attribute__((__malloc__));
char *last_component(char const *name);

void *hash_lookup(Hash_table const *table___0, void const *entry);

void triple_free(void *x);
void *xmalloc(size_t n) __attribute__((__malloc__));
char *xstrdup(char const *string) __attribute__((__malloc__));
extern DIR *fdopendir(int __fd);
DIR *rpl_fdopendir(int fd);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd, struct stat *__buf);
DIR *rpl_fdopendir(int fd) {
  struct stat st;
  int tmp;
  int *tmp___0;
  DIR *tmp___1;

  {
    tmp = fstat(fd, &st);
    if (tmp) {
      return ((DIR *)((void *)0));
    }
    if (!((st.st_mode & 61440U) == 16384U)) {
      tmp___0 = __errno_location();
      *tmp___0 = 20;
      return ((DIR *)((void *)0));
    }
    tmp___1 = fdopendir(fd);
    return (tmp___1);
  }
}
int fd_safer(int fd);
int fd_safer(int fd) {

  { return (fd); }
}
int volatile exit_failure;
int volatile exit_failure = (int volatile)1;

extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) __ctype_get_mb_cur_max)(void);
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(void *__ptr);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) abort)(void);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1), __leaf__)) memset)(void *__s, int __c, size_t __n);

extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strrchr)(char const *__s, int __c) __attribute__((__pure__));
int mbscasecmp(char const *s1, char const *s2);
extern __attribute__((__nothrow__)) wint_t(__attribute__((__leaf__)) towlower)(wint_t __wc);
size_t hash_string(char const *string, size_t n_buckets);
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(size_t candidate, Hash_tuning const *tuning, size_t (*hasher)(void const *, size_t), _Bool (*comparator)(void const *, void const *), void (*data_freer)(void *));
void hash_free(Hash_table *table___0);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) mbsinit)(mbstate_t const *__ps) __attribute__((__pure__));

unsigned int const is_basic_table[8];
size_t strnlen1(char const *string, size_t maxlen);
void *xrealloc(void *p, size_t n);
extern int fcntl(int __fd, int __cmd, ...);
int dup_safer(int fd) {
  int tmp;

  {
    tmp = fcntl(fd, 0, 3);
    return (tmp);
  }
}
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file, struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchown)(int __fd, __uid_t __owner, __gid_t __group);
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
void cycle_check_init(struct cycle_check_state *state);
_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb);

extern void error(int __status, int __errnum, char const *__format, ...);
char const *quote(char const *name);
void close_stdout(void);
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern __attribute__((__noreturn__)) void _exit(int __status);
int close_stream(FILE *stream);
char *quotearg_colon(char const *arg);
static char const *file_name;
static _Bool ignore_EPIPE;
void close_stdout(void) {
  char const *write_error;
  char const *tmp;
  char *tmp___0;
  int *tmp___1;
  int *tmp___2;
  int tmp___3;
  int *tmp___4;
  int tmp___5;

  {
    tmp___3 = close_stream(stdout);
    if (tmp___3 != 0) {
      if (ignore_EPIPE) {
        tmp___4 = __errno_location();
        if (!(*tmp___4 == 32)) {
          goto _L;
        }
      } else {
      _L:
        tmp = (char const *)gettext("write error");
        write_error = tmp;
        if (file_name) {
          tmp___0 = quotearg_colon(file_name);
          tmp___1 = __errno_location();
          error(0, *tmp___1, "%s: %s", tmp___0, write_error);
        } else {
          tmp___2 = __errno_location();
          error(0, *tmp___2, "%s", write_error);
        }
        _exit((int)exit_failure);
      }
    }
    tmp___5 = close_stream(stderr);

    return;
  }
}
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) __fpending)(FILE *__fp);
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
    tmp = __fpending(stream);
    some_pending = (_Bool)(tmp != 0UL);
    tmp___0 = ferror_unlocked(stream);
    prev_fail = (_Bool)(tmp___0 != 0);
    tmp___1 = fclose(stream);
    fclose_fail = (_Bool)(tmp___1 != 0);
    if (prev_fail) {
      goto _L___0;
    } else {
      if (fclose_fail) {
        if (some_pending) {
          goto _L___0;
        } else {
          tmp___3 = __errno_location();
          if (*tmp___3 != 9) {
          _L___0:
            if (!fclose_fail) {
              tmp___2 = __errno_location();
              *tmp___2 = 0;
            }
            return (-1);
          }
        }
      }
    }
    return (0);
  }
}
int set_cloexec_flag(int desc, _Bool value);
int set_cloexec_flag(int desc, _Bool value) {
  int flags;
  int tmp;
  int newflags;
  int tmp___0;
  int tmp___1;

  {
    tmp = fcntl(desc, 1, 0);
    flags = tmp;
    if (0 <= flags) {

      newflags = tmp___0;
      if (flags == newflags) {
        return (0);
      } else {
        tmp___1 = fcntl(desc, 2, newflags);
        if (tmp___1 != -1) {
          return (0);
        }
      }
    }
    return (-1);
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchdir)(int __fd);
extern int(__attribute__((__nonnull__(2))) openat)(int __fd, char const *__file, int __oflag, ...);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1), __leaf__)) memchr)(void const *__s, int __c, size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memmove)(void *__dest, void const *__src, size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file, struct stat *__restrict __buf);
size_t triple_hash(void const *x, size_t table_size);
_Bool triple_compare_ino_str(void const *x, void const *y);
char const *simple_backup_suffix;
void (*argmatch_die)(void);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2, size_t __n) __attribute__((__pure__));
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
DIR *opendir_safer(char const *name);
char const *simple_backup_suffix = "~";
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format, ...);
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char const *quote_n(int n, char const *name);
__attribute__((__noreturn__)) void usage(int status);
extern __attribute__((__nothrow__)) void *(__attribute__((__warn_unused_result__, __leaf__)) realloc)(void *__ptr, size_t __size);
__inline static void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__));
__inline static void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__));

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base, unsigned long *val, char const *valid_suffixes);
extern __attribute__((__nothrow__)) unsigned long(__attribute__((__nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr, char **__restrict __endptr, int __base);
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
static strtol_error bkm_scale_by_power___0(unsigned long *x, int base, int power) {
  strtol_error err;
  strtol_error tmp;
  int tmp___0;

  {
    err = (strtol_error)0;
    while (1) {
      tmp___0 = power;
      power--;

      tmp = bkm_scale___0(x, base);
      err = (strtol_error)((unsigned int)err | (unsigned int)tmp);
    }
    return (err);
  }
}
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base, unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;
  unsigned short const **tmp___0;
  int *tmp___1;
  int *tmp___4;
  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;
  char *tmp___6;

  {
    err = (strtol_error)0;
    if (0 <= strtol_base) {
      if (!(strtol_base <= 36)) {
        __assert_fail("0 <= strtol_base && strtol_base <= 36",
                      "/home/khheo/project/program-reduce/benchmark/"
                      "coreutils-8.2/lib/xstrtol.c",
                      83U, "xstrtoul");
      }
    } else {
      __assert_fail("0 <= strtol_base && strtol_base <= 36",
                    "/home/khheo/project/program-reduce/benchmark/"
                    "coreutils-8.2/lib/xstrtol.c",
                    83U, "xstrtoul");
    }
    if (ptr) {
      p = ptr;
    } else {
      p = &t_ptr;
    }
    q = s;
    ch = (unsigned char)*q;
    while (1) {
      tmp___0 = __ctype_b_loc();
      if (!((int const) * (*tmp___0 + (int)ch) & 8192)) {
        goto while_break;
      }
      q++;
      ch = (unsigned char)*q;
    }
  while_break:;
    if ((int)ch == 45) {
      return ((strtol_error)4);
    }
    tmp___1 = __errno_location();
    *tmp___1 = 0;
    tmp = strtoul(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {

    } else {
      tmp___4 = __errno_location();
    }
    if (!valid_suffixes) {
      *val = tmp;
      return (err);
    }
    if ((int)*(*p) != 0) {
      base = 1024;
      suffixes = 1;
      tmp___5 = strchr(valid_suffixes, (int)*(*p));
      if (!tmp___5) {
        *val = tmp;
        return ((strtol_error)((unsigned int)err | 2U));
      }
      tmp___6 = strchr(valid_suffixes, '0');

      if ((int)*(*p) == 66) {
        goto case_66___0;
      }

      if ((int)*(*p) == 71) {
        goto case_71;
      }

      if ((int)*(*p) == 107) {
        goto case_107;
      }
      if ((int)*(*p) == 75) {
        goto case_107;
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
      goto switch_break___0;
    case_66___0:
      overflow = bkm_scale___0(&tmp, 1024);
      goto switch_break___0;
      goto switch_break___0;
      overflow = bkm_scale_by_power___0(&tmp, base, 6);
      goto switch_break___0;
    case_71:
      overflow = bkm_scale_by_power___0(&tmp, base, 3);
      goto switch_break___0;
    case_107:
      overflow = bkm_scale_by_power___0(&tmp, base, 1);
      goto switch_break___0;
    case_77:
      overflow = bkm_scale_by_power___0(&tmp, base, 2);
      goto switch_break___0;
      goto switch_break___0;
    case_84:
      overflow = bkm_scale_by_power___0(&tmp, base, 4);
      goto switch_break___0;
    case_119:
      overflow = bkm_scale___0(&tmp, 2);
      goto switch_break___0;
    case_89:
      overflow = bkm_scale_by_power___0(&tmp, base, 8);
      goto switch_break___0;
    case_90:
      overflow = bkm_scale_by_power___0(&tmp, base, 7);
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
void *xmemdup(void const *p, size_t s) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) calloc)(size_t __nmemb, size_t __size) __attribute__((__malloc__));
void *xmalloc(size_t n) __attribute__((__malloc__));
void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    tmp = malloc(n);
    p = tmp;
    if (!p) {
      if (n != 0UL) {
        xalloc_die();
      }
    }
    return (p);
  }
}
void *xrealloc(void *p, size_t n) {

  {
    p = realloc(p, n);
    if (!p) {
      if (n != 0UL) {
        xalloc_die();
      }
    }
    return (p);
  }
}
void *xmemdup(void const *p, size_t s) __attribute__((__malloc__));
void *xmemdup(void const *p, size_t s) {
  void *tmp;
  void *tmp___0;

  {
    tmp = xmalloc(s);
    tmp___0 = memcpy(tmp, p, s);
    return (tmp___0);
  }
}
char *xstrdup(char const *string) __attribute__((__malloc__));
char *xstrdup(char const *string) {
  size_t tmp;
  char *tmp___0;

  {
    tmp = strlen(string);
    tmp___0 = (char *)xmemdup((void const *)string, tmp + 1UL);
    return (tmp___0);
  }
}
__attribute__((__nothrow__)) FTS *(__attribute__((__warn_unused_result__, __leaf__)) fts_open)(char *const *argv, int options, int (*compar)(FTSENT const **, FTSENT const **));
FTS *xfts_open(char *const *argv, int options, int (*compar)(FTSENT const **, FTSENT const **));
_Bool cycle_warning_required(FTS const *fts, FTSENT const *ent);
FTS *xfts_open(char *const *argv, int options, int (*compar)(FTSENT const **, FTSENT const **)) {
  FTS *fts;
  FTS *tmp;
  int *tmp___0;

  {
    tmp = fts_open(argv, options | 512, compar);
    fts = tmp;
    if ((unsigned long)fts == (unsigned long)((void *)0)) {
      tmp___0 = __errno_location();
      if (!(*tmp___0 != 22)) {
        __assert_fail("(*__errno_location ()) != 22",
                      "/home/khheo/project/program-reduce/benchmark/"
                      "coreutils-8.2/lib/xfts.c",
                      41U, "xfts_open");
      }
      xalloc_die();
    }
    return (fts);
  }
}

__attribute__((__noreturn__)) void xalloc_die(void);
void xalloc_die(void) {
  char *tmp;

  {
    tmp = gettext("memory exhausted");
    error((int)exit_failure, 0, "%s", tmp);
    abort();
  }
}
extern int printf(char const *__restrict __format, ...);

char const version_etc_copyright[47];
void version_etc_arn(FILE *stream, char const *command_name, char const *package, char const *version, char const *const *authors, size_t n_authors);

char const *parse_user_spec(char const *spec, uid_t *uid, gid_t *gid, char **username, char **groupname);
extern void endpwent(void);
extern struct passwd *getpwnam(char const *__name);
extern void endgrent(void);
extern struct group *getgrgid(__gid_t __gid);
extern struct group *getgrnam(char const *__name);
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i, char *buf___1);
static char const *parse_with_separator(char const *spec, char const *separator, uid_t *uid, gid_t *gid, char **username, char **groupname);
static char const *E_invalid_user = "invalid user";
static char const *E_invalid_group = "invalid group";
static char const *E_bad_spec = "invalid spec";
static char const *parse_with_separator(char const *spec, char const *separator, uid_t *uid, gid_t *gid, char **username, char **groupname) {
  char const *error_msg;
  struct passwd *pwd;
  struct group *grp;
  char *u;
  char const *g;
  char *gname;
  uid_t unum;
  gid_t gnum;
  char *tmp;
  size_t ulen;
  struct passwd *tmp___0;
  _Bool use_login_group;
  int tmp___1;
  unsigned long tmp___2;
  strtol_error tmp___3;
  char buf___1[(((sizeof(uintmax_t) * 8UL) * 146UL) / 485UL + 1UL) + 1UL];
  char *tmp___4;
  char *tmp___5;
  struct group *tmp___6;
  unsigned long tmp___7;
  strtol_error tmp___8;
  char const *tmp___9;

  {
    gname = (char *)((void *)0);
    unum = *uid;
    gnum = *gid;
    error_msg = (char const *)((void *)0);
    tmp = (char *)((void *)0);
    *groupname = tmp;
    *username = tmp;
    u = (char *)((void *)0);
    if ((unsigned long)separator == (unsigned long)((void *)0)) {
      if (*spec) {
        u = xstrdup(spec);
      }
    } else {
      ulen = (size_t)(separator - spec);
      if (ulen != 0UL) {
        u = (char *)xmemdup((void const *)spec, ulen + 1UL);
        *(u + ulen) = (char)'\000';
      }
    }
    if ((unsigned long)separator == (unsigned long)((void *)0)) {
      g = (char const *)((void *)0);
    } else {
      if ((int const) * (separator + 1) == 0) {
        g = (char const *)((void *)0);
      } else {
        g = separator + 1;
      }
    }
    if ((unsigned long)u != (unsigned long)((void *)0)) {
      if ((int)*u == 43) {
        pwd = (struct passwd *)((void *)0);
      } else {
        tmp___0 = getpwnam((char const *)u);
        pwd = tmp___0;
      }
      if ((unsigned long)pwd == (unsigned long)((void *)0)) {
        if ((unsigned long)separator != (unsigned long)((void *)0)) {
          if ((unsigned long)g == (unsigned long)((void *)0)) {
            tmp___1 = 1;
          } else {
            tmp___1 = 0;
          }
        } else {
          tmp___1 = 0;
        }
        use_login_group = (_Bool)tmp___1;
        if (use_login_group) {
          error_msg = E_bad_spec;
        } else {
          tmp___3 = xstrtoul((char const *)u, (char **)((void *)0), 10, &tmp___2, "");
          if ((unsigned int)tmp___3 == 0U) {
            if (tmp___2 <= 4294967295UL) {
              if ((uid_t)tmp___2 != 4294967295U) {
                unum = (uid_t)tmp___2;
              } else {
                error_msg = E_invalid_user;
              }
            } else {
              error_msg = E_invalid_user;
            }
          } else {
            error_msg = E_invalid_user;
          }
        }
      } else {
        unum = pwd->pw_uid;
        if ((unsigned long)g == (unsigned long)((void *)0)) {
          if ((unsigned long)separator != (unsigned long)((void *)0)) {
            gnum = pwd->pw_gid;
            grp = getgrgid(gnum);
            if (grp) {
              tmp___5 = grp->gr_name;
            } else {
              tmp___4 = umaxtostr((uintmax_t)gnum, buf___1);
              tmp___5 = tmp___4;
            }
            gname = xstrdup((char const *)tmp___5);
            endgrent();
          }
        }
      }
      endpwent();
    }
    if ((unsigned long)g != (unsigned long)((void *)0)) {
      if ((unsigned long)error_msg == (unsigned long)((void *)0)) {
        if ((int const) * g == 43) {
          grp = (struct group *)((void *)0);
        } else {
          tmp___6 = getgrnam(g);
          grp = tmp___6;
        }
        if ((unsigned long)grp == (unsigned long)((void *)0)) {
          tmp___8 = xstrtoul(g, (char **)((void *)0), 10, &tmp___7, "");
          if ((unsigned int)tmp___8 == 0U) {

          } else {
            error_msg = E_invalid_group;
          }
        } else {
          gnum = grp->gr_gid;
        }
        endgrent();
        gname = xstrdup(g);
      }
    }
    if ((unsigned long)error_msg == (unsigned long)((void *)0)) {
      *uid = unum;
      *gid = gnum;
      *username = u;
      *groupname = gname;
      u = (char *)((void *)0);
    } else {
      free((void *)gname);
    }
    free((void *)u);
    tmp___9 = (char const *)gettext(error_msg);
    return (tmp___9);
  }
}
char const *parse_user_spec(char const *spec, uid_t *uid, gid_t *gid, char **username, char **groupname) {
  char const *colon;
  char const *tmp;
  char const *error_msg;
  char const *tmp___0;
  char const *dot;
  char const *tmp___1;

  {
    tmp = (char const *)strchr(spec, ':');
    colon = tmp;
    tmp___0 = parse_with_separator(spec, colon, uid, gid, username, groupname);
    error_msg = tmp___0;
    if (!colon) {
      if (error_msg) {
        tmp___1 = (char const *)strchr(spec, '.');
        dot = tmp___1;
      }
    }
    return (error_msg);
  }
}
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i, char *buf___1) {
  char *p;

  {
    p = buf___1 + (((sizeof(uintmax_t) * 8UL) * 146UL) / 485UL + 1UL);
    *p = (char)0;

  while_break:;
    return (p);
  }
}
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
int open_safer(char const *file, int flags, ...);
struct dev_ino *get_root_dev_ino(struct dev_ino *root_d_i);
reg_syntax_t rpl_re_syntax_options;
char const *const quoting_style_args[9];
enum quoting_style const quoting_style_vals[8];
int set_char_quoting(struct quoting_options *o, char c, int i);
char *quotearg_char(char const *arg, char ch);
char *quotearg_char_mem(char const *arg, size_t argsize, char ch);
__inline static char *xcharalloc(size_t n) __attribute__((__malloc__));
__inline static char *xcharalloc(size_t n) __attribute__((__malloc__));

char const *const quoting_style_args[9] = {"literal", "shell", "shell-always", "c", "c-maybe", "escape", "locale", "clocale", (char const *)0};
enum quoting_style const quoting_style_vals[8] = {(enum quoting_style const)0, (enum quoting_style const)1, (enum quoting_style const)2, (enum quoting_style const)3, (enum quoting_style const)4, (enum quoting_style const)5, (enum quoting_style const)6, (enum quoting_style const)7};
static struct quoting_options default_quoting_options;
int set_char_quoting(struct quoting_options *o, char c, int i) {
  unsigned char uc;
  unsigned int *p;
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
    r = (int)((*p >> shift) & 1U);
    *p ^= (unsigned int)(((i & 1) ^ r) << shift);
    return (r);
  }
}
static struct quoting_options quoting_options_from_style(enum quoting_style style) {
  struct quoting_options o;

  {
    o.style = style;
    o.flags = 0;
    memset((void *)(o.quote_these_too), 0, sizeof(o.quote_these_too));
    return (o);
  }
}

static char slot0[256];
static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
static char *quotearg_n_options(int n, char const *arg, size_t argsize, struct quoting_options const *options) {
  int e;
  int *tmp;
  unsigned int n0;
  struct slotvec *sv;
  size_t n1;
  _Bool preallocated;
  int tmp___0;
  struct slotvec *tmp___1;
  size_t size;
  char *val;
  int flags;
  size_t qsize;
  size_t tmp___2;
  int *tmp___3;

  {
    tmp = __errno_location();
    e = *tmp;
    n0 = (unsigned int)n;
    sv = slotvec;
    if (n < 0) {
      abort();
    }
    if (nslots <= n0) {
      n1 = (size_t)(n0 + 1U);
      preallocated = (_Bool)((unsigned long)sv == (unsigned long)(&slotvec0));
      if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
        tmp___0 = -1;
      } else {
        tmp___0 = -2;
      }
      if ((size_t)tmp___0 / sizeof(*sv) < n1) {
        xalloc_die();
      }
      if (preallocated) {
        tmp___1 = (struct slotvec *)((void *)0);
      } else {
        tmp___1 = sv;
      }
      sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
      slotvec = sv;

      memset((void *)(sv + nslots), 0, (n1 - (size_t)nslots) * sizeof(*sv));
      nslots = (unsigned int)n1;
    }
    size = (sv + n)->size;
    val = (sv + n)->val;
    flags = (int)(options->flags | 1);

    qsize = tmp___2;

    tmp___3 = __errno_location();
    *tmp___3 = e;
    return (val);
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;
  struct quoting_options tmp;
  char *tmp___0;

  {
    tmp = quoting_options_from_style(s);
    o = tmp;
    tmp___0 = quotearg_n_options(n, arg, (size_t)-1, (struct quoting_options const *)(&o));
    return (tmp___0);
  }
}
char *quotearg_char_mem(char const *arg, size_t argsize, char ch) {
  struct quoting_options options;
  char *tmp;

  {
    options = default_quoting_options;
    set_char_quoting(&options, ch, 1);
    tmp = quotearg_n_options(0, arg, argsize, (struct quoting_options const *)(&options));
    return (tmp);
  }
}
char *quotearg_char(char const *arg, char ch) {
  char *tmp;

  {
    tmp = quotearg_char_mem(arg, (size_t)-1, ch);
    return (tmp);
  }
}
char *quotearg_colon(char const *arg) {
  char *tmp;

  {
    tmp = quotearg_char(arg, (char)':');
    return (tmp);
  }
}
char const *quote_n(int n, char const *name) {
  char const *tmp;

  {
    tmp = (char const *)quotearg_n_style(n, (enum quoting_style)6, name);
    return (tmp);
  }
}
char const *quote(char const *name) {
  char const *tmp;

  {
    tmp = quote_n(0, name);
    return (tmp);
  }
}
char const *program_name;
void set_program_name(char const *argv0);
extern char *program_invocation_name;
extern char *program_invocation_short_name;
extern int fputs(char const *__restrict __s, FILE *__restrict __stream);
char const *program_name = (char const *)((void *)0);
void set_program_name(char const *argv0) {
  char const *slash;

  {

    slash = (char const *)strrchr(argv0, '/');

    program_name = argv0;
    program_invocation_name = (char *)argv0;
    return;
  }
}

extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) dirfd)(DIR *__dirp);
DIR *opendir_safer(char const *name) {
  DIR *dp;
  DIR *tmp;
  int fd;
  int tmp___0;
  DIR *newdp;
  int e;
  int f;
  int tmp___1;
  int *tmp___2;
  int *tmp___3;

  {
    tmp = opendir(name);
    dp = tmp;
    if (dp) {
      tmp___0 = dirfd(dp);
      fd = tmp___0;
      if (0 <= fd) {
        if (fd <= 2) {
          tmp___1 = dup_safer(fd);
          f = tmp___1;
          newdp = rpl_fdopendir(f);
          tmp___2 = __errno_location();
          e = *tmp___2;
          if (!newdp) {
            close(f);
          }
          closedir(dp);
          tmp___3 = __errno_location();
          *tmp___3 = e;
          dp = newdp;
        }
      }
    }
    return (dp);
  }
}
int openat_safer(int fd, char const *file, int flags, ...);
int openat_safer(int fd, char const *file, int flags, ...) {
  mode_t mode;
  va_list ap;
  int tmp;
  int tmp___0;

  {
    mode = (mode_t)0;
    if (flags & 64) {
      __builtin_va_start(ap, flags);
      mode = __builtin_va_arg(ap, mode_t);
      __builtin_va_end(ap);
    }
    tmp = openat(fd, file, flags, mode);
    tmp___0 = fd_safer(tmp);
    return (tmp___0);
  }
}
int open_safer(char const *file, int flags, ...) {
  mode_t mode;
  va_list ap;
  int tmp;
  int tmp___0;

  {
    mode = (mode_t)0;
    if (flags & 64) {
      __builtin_va_start(ap, flags);
      mode = __builtin_va_arg(ap, mode_t);
      __builtin_va_end(ap);
    }
    tmp = open(file, flags, mode);
    tmp___0 = fd_safer(tmp);
    return (tmp___0);
  }
}
unsigned int const is_basic_table[8] = {(unsigned int const)6656, (unsigned int const)4294967279U, (unsigned int const)4294967294U, (unsigned int const)2147483646};
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) exit)(int __status);
extern int optind;
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) getopt_long)(int ___argc, char *const *___argv, char const *__shortopts, struct option const *__longopts, int *__longind);
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
extern struct passwd *getpwuid(__uid_t __uid);
void i_ring_init(I_ring *ir, int default_val);
int i_ring_push(I_ring *ir, int val);
int i_ring_pop(I_ring *ir);
_Bool i_ring_empty(I_ring const *ir);
void i_ring_init(I_ring *ir, int default_val) {
  int i;

  {
    ir->ir_empty = (_Bool)1;
    ir->ir_front = 0U;
    ir->ir_back = 0U;
    i = 0;

    ir->ir_default_val = default_val;
    return;
  }
}
_Bool i_ring_empty(I_ring const *ir) {

  { return ((_Bool)ir->ir_empty); }
}
int i_ring_push(I_ring *ir, int val) {
  unsigned int dest_idx;
  int old_val;

  {
    dest_idx = (ir->ir_front + (unsigned int)(!ir->ir_empty)) % 4U;
    old_val = ir->ir_data[dest_idx];
    ir->ir_data[dest_idx] = val;
    ir->ir_front = dest_idx;

    ir->ir_empty = (_Bool)0;
    return (old_val);
  }
}
int i_ring_pop(I_ring *ir) {
  int top_val;
  _Bool tmp;

  {
    tmp = i_ring_empty((I_ring const *)ir);
    if (tmp) {
      abort();
    }
    top_val = ir->ir_data[ir->ir_front];
    ir->ir_data[ir->ir_front] = ir->ir_default_val;
    if (ir->ir_front == ir->ir_back) {
      ir->ir_empty = (_Bool)1;
    } else {
      ir->ir_front = ((ir->ir_front + 4U) - 1U) % 4U;
    }
    return (top_val);
  }
}
_Bool(__attribute__((__warn_unused_result__)) hash_rehash)(Hash_table *table___0, size_t candidate);
void *hash_delete(Hash_table *table___0, void const *entry);

static struct hash_tuning const default_tuning = {(float)0.0, (float)1.0, (float)0.8, (float)1.414, (_Bool)0};

static _Bool is_prime(size_t candidate) {
  size_t divisor;
  size_t square;
  int tmp;

  {
    divisor = (size_t)3;
    square = divisor * divisor;
    while (1) {

      if (square < candidate) {

      } else {
        goto while_break;
      }
      divisor++;
      square += 4UL * divisor;
      divisor++;
    }
  while_break:;
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
    while (1) {

      if (0xffffffffffffffffUL != candidate) {
        tmp = is_prime(candidate);
        if (tmp) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      candidate += 2UL;
    }
  while_break:;
    return (candidate);
  }
}
static _Bool raw_comparator(void const *a, void const *b) {

  { return ((_Bool)((unsigned long)a == (unsigned long)b)); }
}
static _Bool check_tuning(Hash_table *table___0) {
  Hash_tuning const *tuning;
  float epsilon;

  {
    tuning = table___0->tuning;

    epsilon = 0.1f;
    table___0->tuning = &default_tuning;
    return ((_Bool)0);
  }
}
static size_t compute_bucket_size(size_t candidate, Hash_tuning const *tuning) {
  float new_candidate;

  {
    if (!tuning->is_n_buckets) {

      if ((float)0xffffffffffffffffUL <= new_candidate) {
        return ((size_t)0);
      }
      candidate = (size_t)new_candidate;
    }
    candidate = next_prime(candidate);

    return (candidate);
  }
}
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(size_t candidate, Hash_tuning const *tuning, size_t (*hasher)(void const *, size_t), _Bool (*comparator)(void const *, void const *), void (*data_freer)(void *)) {
  Hash_table *table___0;
  _Bool tmp;

  {

    if ((unsigned long)comparator == (unsigned long)((void *)0)) {
      comparator = &raw_comparator;
    }
    table___0 = (Hash_table *)malloc(sizeof(*table___0));
    if ((unsigned long)table___0 == (unsigned long)((void *)0)) {
      return ((Hash_table *)((void *)0));
    }

    table___0->tuning = tuning;
    tmp = check_tuning(table___0);
    if (!tmp) {
      goto fail;
    }
    table___0->n_buckets = compute_bucket_size(candidate, tuning);
    if (!table___0->n_buckets) {
      goto fail;
    }

    if ((unsigned long)table___0->bucket == (unsigned long)((void *)0)) {
      goto fail;
    }
    table___0->bucket_limit = (struct hash_entry const *)(table___0->bucket + table___0->n_buckets);
    table___0->n_buckets_used = (size_t)0;
    table___0->n_entries = (size_t)0;
    table___0->hasher = hasher;
    table___0->comparator = comparator;
    table___0->data_freer = data_freer;
    table___0->free_entry_list = (struct hash_entry *)((void *)0);
    return (table___0);
  fail:
    free((void *)table___0);
    return ((Hash_table *)((void *)0));
  }
}

static struct hash_entry *allocate_entry(Hash_table *table___0) {
  struct hash_entry *new;

  {
    if (table___0->free_entry_list) {
      new = table___0->free_entry_list;
      table___0->free_entry_list = new->next;
    } else {
      new = (struct hash_entry *)malloc(sizeof(*new));
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
static void *hash_find_entry(Hash_table *table___0, void const *entry, struct hash_entry **bucket_head, _Bool delete) {
  struct hash_entry *bucket;
  size_t tmp;
  struct hash_entry *cursor;
  void *data;
  _Bool tmp___0;
  void *data___0;
  struct hash_entry *next___0;
  _Bool tmp___1;

  {
    tmp = (*(table___0->hasher))(entry, table___0->n_buckets);
    bucket = table___0->bucket + tmp;

    *bucket_head = bucket;

    if ((unsigned long)entry == (unsigned long)bucket->data) {
      goto _L;
    } else {
      tmp___0 = (*(table___0->comparator))(entry, (void const *)bucket->data);
      if (tmp___0) {
      _L:
        data = bucket->data;
        return (data);
      }
    }
    cursor = bucket;
    while (1) {

      if (!cursor->next) {
        goto while_break;
      }
      if ((unsigned long)entry == (unsigned long)(cursor->next)->data) {
        goto _L___0;
      } else {
        tmp___1 = (*(table___0->comparator))(entry, (void const *)(cursor->next)->data);
        if (tmp___1) {
        _L___0:
          data___0 = (cursor->next)->data;
          if (delete) {
            next___0 = cursor->next;
            cursor->next = next___0->next;
            free_entry(table___0, next___0);
          }
          return (data___0);
        }
      }
      cursor = cursor->next;
    }
  while_break:;
    return ((void *)0);
  }
}
static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {
  struct hash_entry *bucket;

  {
    bucket = src->bucket;
    while (1) {

      if (!((unsigned long)bucket < (unsigned long)src->bucket_limit)) {
        goto while_break;
      }

      bucket++;
    }
  while_break:;
    return ((_Bool)1);
  }
}
_Bool(__attribute__((__warn_unused_result__)) hash_rehash)(Hash_table *table___0, size_t candidate) {
  Hash_table storage;
  Hash_table *new_table;
  size_t new_size;
  size_t tmp;
  _Bool tmp___0;
  _Bool tmp___1;
  _Bool tmp___2;

  {
    tmp = compute_bucket_size(candidate, table___0->tuning);
    new_size = tmp;
    if (!new_size) {
      return ((_Bool)0);
    }

    new_table = &storage;

    if ((unsigned long)new_table->bucket == (unsigned long)((void *)0)) {
      return ((_Bool)0);
    }
    new_table->n_buckets = new_size;

    new_table->n_buckets_used = (size_t)0;
    new_table->n_entries = (size_t)0;
    new_table->tuning = table___0->tuning;
    new_table->hasher = table___0->hasher;
    new_table->comparator = table___0->comparator;
    new_table->data_freer = table___0->data_freer;
    new_table->free_entry_list = table___0->free_entry_list;
    tmp___0 = transfer_entries(new_table, table___0, (_Bool)0);

    table___0->free_entry_list = new_table->free_entry_list;
    tmp___1 = transfer_entries(table___0, new_table, (_Bool)1);
    if (tmp___1) {
      tmp___2 = transfer_entries(table___0, new_table, (_Bool)0);

    } else {
      abort();
    }
    free((void *)new_table->bucket);
    return ((_Bool)0);
  }
}
void *(__attribute__((__warn_unused_result__)) hash_insert)(Hash_table *table___0, void const *entry) {
  void *data;
  struct hash_entry *bucket;
  Hash_tuning const *tuning;
  float candidate;
  float tmp;
  _Bool tmp___0;
  void *tmp___1;
  struct hash_entry *new_entry;
  struct hash_entry *tmp___2;

  {
    if (!entry) {
      abort();
    }
    data = hash_find_entry(table___0, entry, &bucket, (_Bool)0);
    if ((unsigned long)data != (unsigned long)((void *)0)) {
      return (data);
    }

    check_tuning(table___0);

    if (bucket->data) {
      tmp___2 = allocate_entry(table___0);
      new_entry = tmp___2;
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
    return ((void *)entry);
  }
}
void *hash_delete(Hash_table *table___0, void const *entry) {
  void *data;
  struct hash_entry *bucket;
  Hash_tuning const *tuning;
  size_t candidate;
  float tmp;
  _Bool tmp___0;

  {
    data = hash_find_entry(table___0, entry, &bucket, (_Bool)1);
    if (!data) {
      return ((void *)0);
    }
    (table___0->n_entries)--;
    if (!bucket->data) {
      (table___0->n_buckets_used)--;
      if ((float const)table___0->n_buckets_used < (table___0->tuning)->shrink_threshold * (float const)table___0->n_buckets) {
        check_tuning(table___0);

        tuning = table___0->tuning;

        candidate = (size_t)tmp;
        tmp___0 = hash_rehash(table___0, candidate);
      }
    }
    return (data);
  }
}
size_t hash_pjw(void const *x, size_t tablesize);

__attribute__((__nothrow__)) int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp);

extern void(__attribute__((__nonnull__(1, 4))) qsort)(void *__base, size_t __nmemb, size_t __size, int (*__compar)(void const *, void const *));
static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen);
static FTSENT *fts_build(FTS *sp, int type);
static void fts_lfree(FTSENT *head);
static void fts_load(FTS *sp, FTSENT *p);
static size_t fts_maxarglen(char *const *argv);
static void fts_padjust(FTS *sp, FTSENT *head);
static _Bool fts_palloc(FTS *sp, size_t more);
static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems);
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow);
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir);

static _Bool setup_dir(FTS *fts) {

  { return ((_Bool)1); }
}
static _Bool enter_dir(FTS *fts, FTSENT *ent) {

  { return ((_Bool)1); }
}
static void leave_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;
  struct Active_dir obj;
  void *found;
  FTSENT *parent;

  {
    st = (struct stat const *)(ent->fts_statp);
    if (fts->fts_options & 258) {
      obj.dev = (dev_t)st->st_dev;
      obj.ino = (ino_t)st->st_ino;
      found = hash_delete(fts->fts_cycle.ht, (void const *)(&obj));
      if (!found) {
        abort();
      }
      free(found);
    } else {
      parent = ent->fts_parent;
      if ((unsigned long)parent != (unsigned long)((void *)0)) {
        if (0L <= parent->fts_level) {
          while (1) {

            if ((fts->fts_cycle.state)->chdir_counter == 0UL) {
              abort();
            }
            if ((fts->fts_cycle.state)->dev_ino.st_ino == (ino_t)st->st_ino) {
              if ((fts->fts_cycle.state)->dev_ino.st_dev == (dev_t)st->st_dev) {

                (fts->fts_cycle.state)->dev_ino.st_ino = parent->fts_statp[0].st_ino;
              }
            }
            goto while_break;
          }
        while_break:;
        }
      }
    }
    return;
  }
}
static void free_dir(FTS *sp) {

  { return; }
}
static void fd_ring_clear(I_ring *fd_ring) {
  int fd;
  int tmp;
  _Bool tmp___0;

  {
    while (1) {
      tmp___0 = i_ring_empty((I_ring const *)fd_ring);
      if (tmp___0) {
        goto while_break;
      }
      tmp = i_ring_pop(fd_ring);
      fd = tmp;
      if (0 <= fd) {
        close(fd);
      }
    }
  while_break:;
    return;
  }
}
static void fts_set_stat_required(FTSENT *p, _Bool required) {

  {
    while (1) {

      if (!((int)p->fts_info == 11)) {
        abort();
      }
      goto while_break;
    }
  while_break:;
    if (required) {
      p->fts_statp[0].st_size = (__off_t)2;
    } else {
      p->fts_statp[0].st_size = (__off_t)1;
    }
    return;
  }
}
__inline static DIR *opendirat(int fd, char const *dir) {
  int new_fd;
  int tmp;
  DIR *dirp;
  int saved_errno;
  int *tmp___0;
  int *tmp___1;

  {
    tmp = openat_safer(fd, dir, 67840);
    new_fd = tmp;
    if (new_fd < 0) {
      return ((DIR *)((void *)0));
    }
    set_cloexec_flag(new_fd, (_Bool)1);
    dirp = rpl_fdopendir(new_fd);
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      tmp___0 = __errno_location();
      saved_errno = *tmp___0;
      close(new_fd);
      tmp___1 = __errno_location();
      *tmp___1 = saved_errno;
    }
    return (dirp);
  }
}
static void cwd_advance_fd(FTS *sp, int fd, _Bool chdir_down_one) {
  int old;
  int prev_fd_in_slot;
  int tmp;

  {
    old = sp->fts_cwd_fd;

    if (chdir_down_one) {
      tmp = i_ring_push(&sp->fts_fd_ring, old);
      prev_fd_in_slot = tmp;
      if (0 <= prev_fd_in_slot) {
        close(prev_fd_in_slot);
      }
    } else {
      if (!(sp->fts_options & 4)) {
        if (0 <= old) {
          close(old);
        }
      }
    }
    sp->fts_cwd_fd = fd;
    return;
  }
}
__inline static int diropen(FTS const *sp, char const *dir) {
  int open_flags;
  int tmp;
  int fd;
  int tmp___0;
  int tmp___1;
  int tmp___2;

  {
    if (sp->fts_options & 16) {
      tmp = 131072;
    } else {
      tmp = 0;
    }
    open_flags = 67840 | tmp;
    if (sp->fts_options & 512) {
      tmp___0 = openat_safer((int)sp->fts_cwd_fd, dir, open_flags);
      tmp___2 = tmp___0;
    } else {
      tmp___1 = open_safer(dir, open_flags);
      tmp___2 = tmp___1;
    }
    fd = tmp___2;
    if (0 <= fd) {
      set_cloexec_flag(fd, (_Bool)1);
    }
    return (fd);
  }
}
__attribute__((__nothrow__)) FTS *(__attribute__((__warn_unused_result__, __leaf__)) fts_open)(char *const *argv, int options, int (*compar)(FTSENT const **, FTSENT const **));
FTS *(__attribute__((__warn_unused_result__, __leaf__)) fts_open)(char *const *argv, int options, int (*compar)(FTSENT const **, FTSENT const **)) {
  FTS *sp;
  FTSENT *p;
  FTSENT *root;
  size_t nitems;
  FTSENT *parent;
  FTSENT *tmp;
  _Bool defer_stat;
  int *tmp___2;
  size_t maxarglen;
  size_t tmp___4;
  size_t tmp___5;
  _Bool tmp___6;
  int tmp___7;
  size_t len;
  size_t tmp___8;
  struct _ftsent *tmp___9;
  _Bool tmp___10;
  int tmp___11;

  {
    parent = (FTSENT *)((void *)0);
    tmp = (FTSENT *)((void *)0);

    if (!(options & 18)) {
      tmp___2 = __errno_location();
      *tmp___2 = 22;
      return ((FTS *)((void *)0));
    }
    sp = (FTS *)malloc(sizeof(FTS));
    if ((unsigned long)sp == (unsigned long)((void *)0)) {
      return ((FTS *)((void *)0));
    }
    memset((void *)sp, 0, sizeof(FTS));
    sp->fts_compar = compar;
    sp->fts_options = options;

    sp->fts_cwd_fd = -100;
    tmp___4 = fts_maxarglen(argv);
    maxarglen = tmp___4;
    if (maxarglen > 4096UL) {
      tmp___5 = maxarglen;
    } else {
      tmp___5 = (size_t)4096;
    }
    tmp___6 = fts_palloc(sp, tmp___5);
    if (!tmp___6) {
      goto mem1;
    }
    if ((unsigned long)*argv != (unsigned long)((void *)0)) {
      parent = fts_alloc(sp, "", (size_t)0);
      if ((unsigned long)parent == (unsigned long)((void *)0)) {
        goto mem2;
      }
      parent->fts_level = (ptrdiff_t)-1;
    }
    if ((unsigned long)compar == (unsigned long)((void *)0)) {
      tmp___7 = 1;
    } else {
      if (sp->fts_options & 1024) {
        tmp___7 = 1;
      } else {
        tmp___7 = 0;
      }
    }
    defer_stat = (_Bool)tmp___7;
    root = (FTSENT *)((void *)0);
    nitems = (size_t)0;
    while (1) {

      if (!((unsigned long)*argv != (unsigned long)((void *)0))) {
        goto while_break;
      }
      tmp___8 = strlen((char const *)*argv);
      len = tmp___8;
      p = fts_alloc(sp, (char const *)*argv, len);
      if ((unsigned long)p == (unsigned long)((void *)0)) {
        goto mem3;
      }
      p->fts_level = (ptrdiff_t)0;
      p->fts_parent = parent;
      p->fts_accpath = p->fts_name;
      if (defer_stat) {
        if ((unsigned long)root != (unsigned long)((void *)0)) {
          p->fts_info = (unsigned short)11;
          fts_set_stat_required(p, (_Bool)1);
        } else {
          p->fts_info = fts_stat(sp, p, (_Bool)0);
        }
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);
      }
      if (compar) {
        p->fts_link = root;
        root = p;
      } else {
        p->fts_link = (struct _ftsent *)((void *)0);
        if ((unsigned long)root == (unsigned long)((void *)0)) {
          root = p;
          tmp = root;
        } else {
          tmp->fts_link = p;
          tmp = p;
        }
      }
      argv++;
      nitems++;
    }
  while_break:;
    tmp___9 = fts_alloc(sp, "", (size_t)0);
    sp->fts_cur = tmp___9;
    if ((unsigned long)tmp___9 == (unsigned long)((void *)0)) {
      goto mem3;
    }
    (sp->fts_cur)->fts_link = root;
    (sp->fts_cur)->fts_info = (unsigned short)9;
    tmp___10 = setup_dir(sp);
    if (!tmp___10) {
      goto mem3;
    }
    if (!(sp->fts_options & 4)) {
      if (!(sp->fts_options & 512)) {
        tmp___11 = diropen((FTS const *)sp, ".");
        sp->fts_rfd = tmp___11;
      }
    }
    i_ring_init(&sp->fts_fd_ring, -1);
    return (sp);
  mem3:
    fts_lfree(root);
    free((void *)parent);
  mem2:
    free((void *)sp->fts_path);
  mem1:
    free((void *)sp);
    return ((FTS *)((void *)0));
  }
}
static void fts_load(FTS *sp, FTSENT *p) {
  size_t len;
  char *cp;
  size_t tmp;
  char *tmp___0;

  {
    tmp = p->fts_namelen;
    p->fts_pathlen = tmp;
    len = tmp;
    memmove((void *)sp->fts_path, (void const *)(p->fts_name), len + 1UL);
    cp = strrchr((char const *)(p->fts_name), '/');
    tmp___0 = sp->fts_path;
    p->fts_path = tmp___0;
    p->fts_accpath = tmp___0;
    return;
  }
}
__attribute__((__nothrow__)) int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp);
int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp) {
  FTSENT *freep;
  FTSENT *p;
  int saved_errno;
  int *tmp;
  int tmp___0;
  int *tmp___1;
  int tmp___2;
  int *tmp___3;
  int tmp___4;
  int *tmp___5;

  {
    saved_errno = 0;
    if (sp->fts_cur) {
      p = sp->fts_cur;

    while_break:
      free((void *)p);
    }
    if (sp->fts_child) {
      fts_lfree(sp->fts_child);
    }
    free((void *)sp->fts_array);
    free((void *)sp->fts_path);
    if (sp->fts_options & 512) {
      if (0 <= sp->fts_cwd_fd) {
        tmp___0 = close(sp->fts_cwd_fd);
        if (tmp___0) {
          tmp = __errno_location();
          saved_errno = *tmp;
        }
      }
    } else {
      if (!(sp->fts_options & 4)) {
        tmp___2 = fchdir(sp->fts_rfd);

        tmp___4 = close(sp->fts_rfd);
        if (tmp___4) {
          if (saved_errno == 0) {
            tmp___3 = __errno_location();
            saved_errno = *tmp___3;
          }
        }
      }
    }
    fd_ring_clear(&sp->fts_fd_ring);

    free_dir(sp);
    free((void *)sp);
    if (saved_errno) {
      tmp___5 = __errno_location();
      *tmp___5 = saved_errno;
      return (-1);
    }
    return (0);
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__)) fstatfs)(int __fildes, struct statfs *__buf);

FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp) {
  FTSENT *p;
  FTSENT *tmp;
  unsigned short instr;
  char *t;
  int *tmp___2;
  int tmp___3;
  struct _ftsent *tmp___4;
  size_t tmp___12;
  char *tmp___13;
  int *tmp___17;
  struct _ftsent *tmp___18;
  FTSENT *tmp___32;

  {
    if ((unsigned long)sp->fts_cur == (unsigned long)((void *)0)) {
      return ((FTSENT *)((void *)0));
    }
    p = sp->fts_cur;
    instr = p->fts_instr;
    p->fts_instr = (unsigned short)3;
    if ((int)instr == 1) {
      p->fts_info = fts_stat(sp, p, (_Bool)0);
      return (p);
    }
    if ((int)instr == 2) {
      if ((int)p->fts_info == 12) {
        goto _L;
      } else {
        if ((int)p->fts_info == 13) {
        _L:
          p->fts_info = fts_stat(sp, p, (_Bool)1);
          goto check_for_dir;
        }
      }
    }
    if ((int)p->fts_info == 1) {
      if ((int)instr == 4) {
        goto _L___0;
      } else {
        if (sp->fts_options & 64) {
          if (p->fts_statp[0].st_dev != sp->fts_dev) {
          _L___0:
            p->fts_info = (unsigned short)6;
            while (1) {
              leave_dir(sp, p);
              goto while_break;
            }
          while_break:;
            return (p);
          }
        }
      }

      if ((unsigned long)sp->fts_child != (unsigned long)((void *)0)) {
        tmp___3 = fts_safe_changedir(sp, p, -1, (char const *)p->fts_accpath);
        if (tmp___3) {
          tmp___2 = __errno_location();
          p->fts_errno = *tmp___2;
          p->fts_flags = (unsigned short)((int)p->fts_flags | 1);
          p = sp->fts_child;
        }
      } else {
        tmp___4 = fts_build(sp, 3);
        sp->fts_child = tmp___4;
      }
      p = sp->fts_child;
      sp->fts_child = (struct _ftsent *)((void *)0);
      goto name;
    }
  next:
    tmp = p;
    p = p->fts_link;
    if ((unsigned long)p != (unsigned long)((void *)0)) {
      sp->fts_cur = p;
      free((void *)tmp);
      if (p->fts_level == 0L) {
        fd_ring_clear(&sp->fts_fd_ring);

        free_dir(sp);
        fts_load(sp, p);
        setup_dir(sp);
        goto check_for_dir;
      }
      if ((int)p->fts_instr == 4) {
        goto next;
      }

    name:
      if ((int)*((p->fts_parent)->fts_path + ((p->fts_parent)->fts_pathlen - 1UL)) == 47) {
        tmp___12 = (p->fts_parent)->fts_pathlen - 1UL;
      } else {
        tmp___12 = (p->fts_parent)->fts_pathlen;
      }
      t = sp->fts_path + tmp___12;
      tmp___13 = t;
      t++;
      *tmp___13 = (char)'/';
      memmove((void *)t, (void const *)(p->fts_name), p->fts_namelen + 1UL);
    check_for_dir:
      sp->fts_cur = p;
      return (p);
    }
    p = tmp->fts_parent;
    sp->fts_cur = p;
    free((void *)tmp);
    if (p->fts_level == -1L) {
      free((void *)p);
      tmp___17 = __errno_location();
      *tmp___17 = 0;
      tmp___18 = (struct _ftsent *)((void *)0);
      sp->fts_cur = tmp___18;
      return (tmp___18);
    }
    while (1) {

      if (!((int)p->fts_info != 11)) {
        abort();
      }
      goto while_break___3;
    }
  while_break___3:
    *(sp->fts_path + p->fts_pathlen) = (char)'\000';
    if (p->fts_level == 0L) {
      fd_ring_clear(&sp->fts_fd_ring);
    }
    if (p->fts_errno) {
      p->fts_info = (unsigned short)7;
    } else {
      p->fts_info = (unsigned short)6;
    }
    if (p->fts_errno == 0) {
      while (1) {
        leave_dir(sp, p);
        goto while_break___4;
      }
    while_break___4:;
    }
    return (tmp___32);
  }
}

int(__attribute__((__leaf__)) fts_set)(FTS *sp __attribute__((__unused__)), FTSENT *p, int instr) {
  int *tmp;

  {
    p->fts_instr = (unsigned short)instr;
    return (0);
  }
}
static void set_stat_type(struct stat *st, unsigned int dtype) {
  mode_t type;

  {
    if (dtype == 6U) {
      goto case_6;
    }
    if (dtype == 2U) {
      goto case_2;
    }

    if (dtype == 1U) {
      goto case_1;
    }
    if (dtype == 10U) {
      goto case_10;
    }
    if (dtype == 8U) {
      goto case_8;
    }

    goto switch_default;
  case_6:
    type = (mode_t)24576;
    goto switch_break;
  case_2:
    type = (mode_t)8192;
    goto switch_break;
    goto switch_break;
  case_1:
    type = (mode_t)4096;
    goto switch_break;
  case_10:
    type = (mode_t)40960;
    goto switch_break;
  case_8:
    type = (mode_t)32768;
    goto switch_break;
    goto switch_break;
  switch_default:
    type = (mode_t)0;
  switch_break:
    st->st_mode = type;
    return;
  }
}
static FTSENT *fts_build(FTS *sp, int type) {
  struct dirent *dp;
  FTSENT *p;
  FTSENT *head;
  size_t nitems;
  FTSENT *cur;
  FTSENT *tail;
  DIR *dirp;
  void *oldaddr;
  int saved_errno;
  _Bool descend;
  _Bool doadjust;
  ptrdiff_t level;
  nlink_t nlinks;
  _Bool nostat;
  size_t len;
  size_t maxlen;
  size_t new_len;
  char *cp;
  int *tmp;
  DIR *tmp___0;
  DIR *tmp___1;
  int *tmp___2;
  _Bool tmp___3;
  int tmp___4;
  _Bool is_dir;
  size_t tmp___9;
  int *tmp___10;
  int *tmp___11;
  size_t tmp___12;
  _Bool tmp___13;
  size_t tmp___14;
  size_t tmp___15;
  int *tmp___16;
  _Bool skip_stat;
  int tmp___17;
  int tmp___18;
  int tmp___19;

  {
    cur = sp->fts_cur;
    if (!(sp->fts_options & 4)) {
      if (sp->fts_options & 512) {
        tmp___0 = opendirat(sp->fts_cwd_fd, (char const *)cur->fts_accpath);
        dirp = tmp___0;
      } else {
        tmp___1 = opendir_safer((char const *)cur->fts_accpath);
        dirp = tmp___1;
      }
    } else {
      tmp___1 = opendir_safer((char const *)cur->fts_accpath);
      dirp = tmp___1;
    }
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      if (type == 3) {
        cur->fts_info = (unsigned short)4;
        tmp = __errno_location();
        cur->fts_errno = *tmp;
      }
      return ((FTSENT *)((void *)0));
    }
    if ((int)cur->fts_info == 11) {
      cur->fts_info = fts_stat(sp, cur, (_Bool)0);
    } else {
      if (sp->fts_options & 256) {
        while (1) {
          leave_dir(sp, cur);
          goto while_break;
        }
      while_break:
        fts_stat(sp, cur, (_Bool)0);
        tmp___3 = enter_dir(sp, cur);
        if (!tmp___3) {
          tmp___2 = __errno_location();
          *tmp___2 = 12;
          return ((FTSENT *)((void *)0));
        }
      }
    }
    if (type == 2) {
      nlinks = (nlink_t)0;
      nostat = (_Bool)0;
    } else {
      if (sp->fts_options & 8) {
        if (sp->fts_options & 16) {
          if (sp->fts_options & 32) {
            tmp___4 = 0;
          } else {
            tmp___4 = 2;
          }
          nlinks = cur->fts_statp[0].st_nlink - (__nlink_t)tmp___4;
          nostat = (_Bool)1;
        } else {
          nlinks = (nlink_t)-1;
          nostat = (_Bool)0;
        }
      } else {
        nlinks = (nlink_t)-1;
        nostat = (_Bool)0;
      }
    }

    if ((int)*(cur->fts_path + (cur->fts_pathlen - 1UL)) == 47) {
      len = cur->fts_pathlen - 1UL;
    } else {
      len = cur->fts_pathlen;
    }

    len++;
    maxlen = sp->fts_pathlen - len;
    level = cur->fts_level + 1L;
    doadjust = (_Bool)0;
    tail = (FTSENT *)((void *)0);
    head = tail;
    nitems = (size_t)0;
    while (1) {

      if (dirp) {
        dp = readdir(dirp);
        if (!dp) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      if (!(sp->fts_options & 32)) {
        if ((int)dp->d_name[0] == 46) {
          if (!dp->d_name[1]) {
            goto __Cont;
          }
        }
      }
      tmp___9 = strlen((char const *)(dp->d_name));
      p = fts_alloc(sp, (char const *)(dp->d_name), tmp___9);
      if ((unsigned long)p == (unsigned long)((void *)0)) {
        goto mem1;
      }
      tmp___14 = strlen((char const *)(dp->d_name));
      if (tmp___14 >= maxlen) {
        oldaddr = (void *)sp->fts_path;
        tmp___12 = strlen((char const *)(dp->d_name));
        tmp___13 = fts_palloc(sp, (tmp___12 + len) + 1UL);
        if (!tmp___13) {
        mem1:
          tmp___10 = __errno_location();
          saved_errno = *tmp___10;
          free((void *)p);
          fts_lfree(head);
          closedir(dirp);
          cur->fts_info = (unsigned short)7;
          sp->fts_options |= 8192;
          tmp___11 = __errno_location();
          *tmp___11 = saved_errno;
          return ((FTSENT *)((void *)0));
        }

        maxlen = sp->fts_pathlen - len;
      }
      tmp___15 = strlen((char const *)(dp->d_name));
      new_len = len + tmp___15;
      if (new_len < len) {
        free((void *)p);
        fts_lfree(head);
        closedir(dirp);
        cur->fts_info = (unsigned short)7;
        sp->fts_options |= 8192;
        tmp___16 = __errno_location();
        *tmp___16 = 36;
        return ((FTSENT *)((void *)0));
      }
      p->fts_level = level;
      p->fts_parent = sp->fts_cur;
      p->fts_pathlen = new_len;
      p->fts_statp[0].st_ino = dp->d_ino;
      if (sp->fts_options & 4) {
        p->fts_accpath = p->fts_path;
        memmove((void *)cp, (void const *)(p->fts_name), p->fts_namelen + 1UL);
      } else {
        p->fts_accpath = p->fts_name;
      }
      if ((unsigned long)sp->fts_compar == (unsigned long)((void *)0) || sp->fts_options & 1024) {

        skip_stat = (_Bool)tmp___17;
        p->fts_info = (unsigned short)11;
        set_stat_type(p->fts_statp, (unsigned int)dp->d_type);
        fts_set_stat_required(p, (_Bool)(!skip_stat));
        if (sp->fts_options & 16) {
          if ((int)dp->d_type == 4) {
            tmp___18 = 1;
          } else {
            tmp___18 = 0;
          }
        } else {
          tmp___18 = 0;
        }
        is_dir = (_Bool)tmp___18;
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);
        if ((int)p->fts_info == 1) {
          tmp___19 = 1;
        } else {
          if ((int)p->fts_info == 2) {
            tmp___19 = 1;
          } else {
            if ((int)p->fts_info == 5) {
              tmp___19 = 1;
            } else {
              tmp___19 = 0;
            }
          }
        }
        is_dir = (_Bool)tmp___19;
      }

      p->fts_link = (struct _ftsent *)((void *)0);

      nitems++;
    __Cont:;
    }
  while_break___0:;
    if (dirp) {
      closedir(dirp);
    }
    if (doadjust) {
      fts_padjust(sp, head);
    }

    if (!nitems) {
      if (type == 3) {
        cur->fts_info = (unsigned short)6;
      }
      fts_lfree(head);
      return ((FTSENT *)((void *)0));
    }
    if (sp->fts_compar) {
      if (nitems > 1UL) {
        head = fts_sort(sp, head, nitems);
      }
    }
    return (head);
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;
  int saved_errno;
  int *tmp;
  int *tmp___1;
  int tmp___2;
  int tmp___3;
  int *tmp___4;
  int tmp___5;
  int tmp___6;

  {
    sbp = p->fts_statp;

    if (sp->fts_options & 2) {
      goto _L;
    } else {
      if (follow) {
      _L:
        tmp___3 = stat((char const *)p->fts_accpath, sbp);
        if (tmp___3) {
          tmp = __errno_location();
          saved_errno = *tmp;
          tmp___1 = __errno_location();
          if (*tmp___1 == 2) {
            tmp___2 = lstat((char const *)p->fts_accpath, sbp);
          }
          p->fts_errno = saved_errno;
          goto err;
        }
      } else {
        tmp___5 = fstatat(sp->fts_cwd_fd, (char const *)p->fts_accpath, sbp, 256);
        if (tmp___5) {
          tmp___4 = __errno_location();
          p->fts_errno = *tmp___4;
        err:
          memset((void *)sbp, 0, sizeof(struct stat));
          return ((unsigned short)10);
        }
      }
    }
    if ((sbp->st_mode & 61440U) == 16384U) {
      if (sp->fts_options & 32) {
        tmp___6 = 0;
      } else {
        tmp___6 = 2;
      }
      p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;

      return ((unsigned short)1);
    }
    if ((sbp->st_mode & 61440U) == 40960U) {
      return ((unsigned short)12);
    }
    if ((sbp->st_mode & 61440U) == 32768U) {
      return ((unsigned short)8);
    }
    return ((unsigned short)3);
  }
}
static int fts_compar(void const *a, void const *b) {
  FTSENT const **pa;
  FTSENT const **pb;
  int tmp;

  {
    pa = (FTSENT const **)a;
    pb = (FTSENT const **)b;
    tmp = (*(((*(pa + 0))->fts_fts)->fts_compar))(pa, pb);
    return (tmp);
  }
}
static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems) {
  FTSENT **ap;
  FTSENT *p;
  FTSENT *dummy = 0;
  int (*compare)(void const *, void const *);
  int (*tmp)(void const *, void const *);
  FTSENT **a;
  FTSENT **tmp___0;

  {
    if (sizeof(&dummy) == sizeof(void *)) {
      if ((long)(&dummy) == (long)((void *)(&dummy))) {
        tmp = (int (*)(void const *, void const *))sp->fts_compar;
      } else {
        tmp = &fts_compar;
      }
    } else {
      tmp = &fts_compar;
    }
    compare = tmp;
    if (nitems > sp->fts_nitems) {
      sp->fts_nitems = nitems + 40UL;

      sp->fts_array = a;
    }
    ap = sp->fts_array;
    p = head;

    qsort((void *)sp->fts_array, nitems, sizeof(FTSENT *), compare);
    ap = sp->fts_array;
    head = *ap;
    while (1) {
      nitems--;
      if (!nitems) {
        goto while_break___0;
      }
      (*(ap + 0))->fts_link = *(ap + 1);
      ap++;
    }
  while_break___0:
    (*(ap + 0))->fts_link = (struct _ftsent *)((void *)0);
    return (head);
  }
}
static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen) {
  FTSENT *p;
  size_t len;

  {
    len = sizeof(FTSENT) + namelen;
    p = (FTSENT *)malloc(len);
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      return ((FTSENT *)((void *)0));
    }
    memmove((void *)(p->fts_name), (void const *)name, namelen);
    p->fts_name[namelen] = (char)'\000';
    p->fts_namelen = namelen;
    p->fts_fts = sp;
    p->fts_path = sp->fts_path;
    p->fts_errno = 0;
    p->fts_flags = (unsigned short)0;
    p->fts_instr = (unsigned short)3;
    p->fts_number = 0L;
    p->fts_pointer = (void *)0;
    return (p);
  }
}
static void fts_lfree(FTSENT *head) {
  FTSENT *p;

  {
    while (1) {
      p = head;
      if (!p) {
        goto while_break;
      }
      head = head->fts_link;
      free((void *)p);
    }
  while_break:;
    return;
  }
}
static _Bool fts_palloc(FTS *sp, size_t more) {
  char *p;
  size_t new_len;
  int *tmp;

  {
    new_len = (sp->fts_pathlen + more) + 256UL;
    if (new_len < sp->fts_pathlen) {
      free((void *)sp->fts_path);
      sp->fts_path = (char *)((void *)0);
      tmp = __errno_location();
      *tmp = 36;
      return ((_Bool)0);
    }
    sp->fts_pathlen = new_len;
    p = (char *)realloc((void *)sp->fts_path, sp->fts_pathlen);
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      free((void *)sp->fts_path);
      sp->fts_path = (char *)((void *)0);
      return ((_Bool)0);
    }
    sp->fts_path = p;
    return ((_Bool)1);
  }
}
static void fts_padjust(FTS *sp, FTSENT *head) {
  FTSENT *p;
  char *addr;

  {
    addr = sp->fts_path;
    p = sp->fts_child;
    while (1) {

      if (!p) {
        goto while_break;
      }
      while (1) {

        if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
          p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
        }
        p->fts_path = addr;
        goto while_break___0;
      }
    while_break___0:
      p = p->fts_link;
    }
  while_break:
    p = head;
    while (1) {

      if (!(p->fts_level >= 0L)) {
        goto while_break___1;
      }
      while (1) {

        if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
          p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
        }
        p->fts_path = addr;
        goto while_break___2;
      }
    while_break___2:;
    }
  while_break___1:;
    return;
  }
}
static size_t fts_maxarglen(char *const *argv) {
  size_t len;
  size_t max;

  {
    max = (size_t)0;
    while (1) {

      if (!*argv) {
        goto while_break;
      }
      len = strlen((char const *)*argv);
      if (len > max) {
        max = len;
      }
      argv++;
    }
  while_break:;
    return (max + 1UL);
  }
}
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir) {
  int ret;
  _Bool is_dotdot;
  int tmp___0;
  int newfd;
  struct stat sb;
  int tmp___2;
  int *tmp___3;
  int tmp___4;
  int oerrno;
  int *tmp___5;
  int *tmp___6;

  {

    is_dotdot = (_Bool)tmp___0;
    if (sp->fts_options & 4) {
      if (sp->fts_options & 512) {
        if (0 <= fd) {
          close(fd);
        }
      }
      return (0);
    }

    newfd = fd;
    if (fd < 0) {
      newfd = diropen((FTS const *)sp, dir);
      if (newfd < 0) {
        return (-1);
      }
    }
    if (sp->fts_options & 2) {
      goto _L;
    } else {
      if (dir) {
        tmp___4 = strcmp(dir, "..");
        if (tmp___4 == 0) {
        _L:
          tmp___2 = fstat(newfd, &sb);
          if (tmp___2) {
            ret = -1;
            goto bail;
          }
          if (p->fts_statp[0].st_dev != sb.st_dev) {
            tmp___3 = __errno_location();
            *tmp___3 = 2;
            ret = -1;
            goto bail;
          } else {
            if (p->fts_statp[0].st_ino != sb.st_ino) {
              tmp___3 = __errno_location();
              *tmp___3 = 2;
              ret = -1;
              goto bail;
            }
          }
        }
      }
    }
    if (sp->fts_options & 512) {
      cwd_advance_fd(sp, newfd, (_Bool)(!is_dotdot));
      return (0);
    }
    ret = fchdir(newfd);
  bail:
    if (fd < 0) {
      tmp___5 = __errno_location();
      oerrno = *tmp___5;
      close(newfd);
      tmp___6 = __errno_location();
      *tmp___6 = oerrno;
    }
    return (ret);
  }
}
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
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
char const *Version = "8.2";
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__)) fchownat)(int __fd, char const *__file, __uid_t __owner, __gid_t __group, int __flag);
__inline static int chownat(int fd, char const *file, uid_t owner, gid_t group) {
  int tmp;

  {
    tmp = fchownat(fd, file, owner, group, 0);
    return (tmp);
  }
}
__inline static int lchownat(int fd, char const *file, uid_t owner, gid_t group) {
  int tmp;

  {
    tmp = fchownat(fd, file, owner, group, 256);
    return (tmp);
  }
}
extern void chopt_init(struct Chown_option *chopt);
extern void chopt_free(struct Chown_option *chopt __attribute__((__unused__)));
extern char *gid_to_name(gid_t gid);
extern char *uid_to_name(uid_t uid);
extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid, uid_t required_uid, gid_t required_gid, struct Chown_option const *chopt);

extern void chopt_init(struct Chown_option *chopt) {

  {
    chopt->verbosity = (enum Verbosity)2;
    chopt->root_dev_ino = (struct dev_ino *)((void *)0);
    chopt->affect_symlink_referent = (_Bool)1;
    chopt->recurse = (_Bool)0;
    chopt->force_silent = (_Bool)0;
    chopt->user_name = (char *)((void *)0);
    chopt->group_name = (char *)((void *)0);
    return;
  }
}
extern void chopt_free(struct Chown_option *chopt __attribute__((__unused__))) {

  {
    return;
  }
}
extern char *gid_to_name(gid_t gid) {
  char buf___1[((((sizeof(intmax_t) * 8UL - 1UL) * 146UL) / 485UL + 1UL) + 1UL) + 1UL];
  struct group *grp;
  struct group *tmp;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;

  {
    tmp = getgrgid(gid);
    grp = tmp;
    if (grp) {
      tmp___2 = grp->gr_name;
    } else {
      tmp___1 = umaxtostr((uintmax_t)gid, buf___1);
      tmp___2 = tmp___1;
    }
    tmp___3 = xstrdup((char const *)tmp___2);
    return (tmp___3);
  }
}
extern char *uid_to_name(uid_t uid) {
  char buf___1[((((sizeof(intmax_t) * 8UL - 1UL) * 146UL) / 485UL + 1UL) + 1UL) + 1UL];
  struct passwd *pwd;
  struct passwd *tmp;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;

  {
    tmp = getpwuid(uid);
    pwd = tmp;
    if (pwd) {
      tmp___2 = pwd->pw_name;
    } else {
      tmp___1 = umaxtostr((uintmax_t)uid, buf___1);
      tmp___2 = tmp___1;
    }
    tmp___3 = xstrdup((char const *)tmp___2);
    return (tmp___3);
  }
}
static void describe_change(char const *file, enum Change_status changed, char const *user, char const *group) {
  char const *fmt;
  char const *spec;
  char *spec_allocated;
  char const *tmp;
  char *tmp___0;
  size_t tmp___1;
  size_t tmp___2;
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
  char *tmp___15;
  char *tmp___16;
  char const *tmp___17;

  {
    spec_allocated = (char *)((void *)0);
    if ((unsigned int)changed == 1U) {
      tmp = quote(file);

      printf((char const *)tmp___0, tmp);
      return;
    }
    if (user) {
      if (group) {
        tmp___1 = strlen(user);
        tmp___2 = strlen(group);
        spec_allocated = (char *)xmalloc(((tmp___1 + 1UL) + tmp___2) + 1UL);
        tmp___3 = stpcpy(spec_allocated, user);
        tmp___4 = stpcpy(tmp___3, ":");
        stpcpy(tmp___4, group);
        spec = (char const *)spec_allocated;
      } else {
        spec = user;
      }
    } else {
      spec = group;
    }
    if ((unsigned int)changed == 2U) {
      goto case_2;
    }
    if ((unsigned int)changed == 3U) {
      goto case_3;
    }
    if ((unsigned int)changed == 4U) {
      goto case_4;
    }
    goto switch_default;
  case_2:
    if (user) {
      tmp___5 = gettext("changed ownership of %s to %s\n");
      fmt = (char const *)tmp___5;
    } else {
      if (group) {
        tmp___6 = gettext("changed group of %s to %s\n");
        tmp___8 = tmp___6;
      } else {
        tmp___7 = gettext("no change to ownership of %s\n");
        tmp___8 = tmp___7;
      }
      fmt = (char const *)tmp___8;
    }
    goto switch_break;
  case_3:
    if (user) {
      tmp___9 = gettext("failed to change ownership of %s to %s\n");
      fmt = (char const *)tmp___9;
    } else {
      if (group) {
        tmp___10 = gettext("failed to change group of %s to %s\n");
        tmp___12 = tmp___10;
      } else {
        tmp___11 = gettext("failed to change ownership of %s\n");
        tmp___12 = tmp___11;
      }
      fmt = (char const *)tmp___12;
    }
    goto switch_break;
  case_4:
    if (user) {
      tmp___13 = gettext("ownership of %s retained as %s\n");
      fmt = (char const *)tmp___13;
    } else {
      if (group) {
        tmp___14 = gettext("group of %s retained as %s\n");
        tmp___16 = tmp___14;
      } else {
        tmp___15 = gettext("ownership of %s retained\n");
        tmp___16 = tmp___15;
      }
      fmt = (char const *)tmp___16;
    }
    goto switch_break;
  switch_default:
    abort();
  switch_break:
    tmp___17 = quote(file);
    printf(fmt, tmp___17, spec);
    free((void *)spec_allocated);
    return;
  }
}
static enum RCH_status restricted_chown(int cwd_fd, char const *file, struct stat const *orig_st, uid_t uid, gid_t gid, uid_t required_uid, gid_t required_gid) {
  enum RCH_status status;
  struct stat st;
  int open_flags;
  int fd;
  int tmp___0;
  int *tmp___1;
  int *tmp___2;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int saved_errno;
  int *tmp___7;
  int *tmp___8;

  {
    status = (enum RCH_status)2;
    open_flags = 2304;
    if (required_uid == 4294967295U) {
      if (required_gid == 4294967295U) {
        return ((enum RCH_status)5);
      }
    }
    if (!((orig_st->st_mode & 61440U) == 32768U)) {
      if ((orig_st->st_mode & 61440U) == 16384U) {
        open_flags |= 65536;
      } else {
        return ((enum RCH_status)5);
      }
    }
    fd = openat(cwd_fd, file, open_flags);
    if (!(0 <= fd)) {
      tmp___2 = __errno_location();
      if (*tmp___2 == 13) {
        if ((orig_st->st_mode & 61440U) == 32768U) {
          fd = openat(cwd_fd, file, 1 | open_flags);
          if (!(0 <= fd)) {
            goto _L___0;
          }
        } else {
          goto _L___0;
        }
      } else {
      _L___0:
        tmp___1 = __errno_location();
        if (*tmp___1 == 13) {
          tmp___0 = 5;
        } else {
          tmp___0 = 6;
        }
        return ((enum RCH_status)tmp___0);
      }
    }
    tmp___6 = fstat(fd, &st);
    if (tmp___6 != 0) {
      status = (enum RCH_status)6;
    } else {
      if (orig_st->st_ino == (__ino_t const)st.st_ino) {
        if (orig_st->st_dev == (__dev_t const)st.st_dev) {
          if (required_uid == 4294967295U) {
            goto _L___2;
          } else {
            if (required_uid == st.st_uid) {
            _L___2:
              if (required_gid == 4294967295U) {
                goto _L___1;
              } else {
                if (required_gid == st.st_gid) {
                _L___1:
                  tmp___5 = fchown(fd, uid, gid);
                  if (tmp___5 == 0) {
                    tmp___4 = close(fd);
                    if (tmp___4 == 0) {
                      status = (enum RCH_status)2;
                    } else {
                      status = (enum RCH_status)6;
                    }
                    return (status);
                  } else {
                    status = (enum RCH_status)6;
                  }
                }
              }
            }
          }
        } else {
          status = (enum RCH_status)4;
        }
      } else {
        status = (enum RCH_status)4;
      }
    }
    tmp___7 = __errno_location();
    saved_errno = *tmp___7;
    close(fd);
    tmp___8 = __errno_location();
    *tmp___8 = saved_errno;
    return (status);
  }
}
static _Bool change_file_owner(FTS *fts, FTSENT *ent, uid_t uid, gid_t gid, uid_t required_uid, gid_t required_gid, struct Chown_option const *chopt) {
  char const *file_full_name;
  char const *file;
  struct stat const *file_stats;
  _Bool ok;
  _Bool do_chown;
  _Bool symlink_changed;
  char const *tmp___9;
  char *tmp___10;
  char const *tmp___11;
  char *tmp___12;
  int tmp___20;
  int tmp___28;
  enum RCH_status err;
  enum RCH_status tmp___30;
  int tmp___31;
  _Bool changed;
  int tmp___37;
  enum Change_status ch_status;
  int tmp___38;
  int tmp___39;
  int tmp___40;

  {
    file_full_name = (char const *)ent->fts_path;
    file = (char const *)ent->fts_accpath;
    ok = (_Bool)1;
    symlink_changed = (_Bool)1;
    if ((int)ent->fts_info == 1) {
      goto case_1;
    }
    if ((int)ent->fts_info == 6) {
      goto case_6;
    }

    if ((int)ent->fts_info == 7) {
      goto case_7;
    }
    if ((int)ent->fts_info == 4) {
      goto case_4;
    }

    goto switch_default;
  case_1:
    if (chopt->recurse) {
      return ((_Bool)1);
    }
    goto switch_break;
  case_6:
    if (!chopt->recurse) {
      return ((_Bool)1);
    }
    goto switch_break;
    goto switch_break;
  case_7:
    if (!chopt->force_silent) {
      tmp___9 = quote(file_full_name);
      tmp___10 = gettext("%s");
      error(0, ent->fts_errno, (char const *)tmp___10, tmp___9);
    }
    ok = (_Bool)0;
    goto switch_break;
  case_4:
    if (!chopt->force_silent) {
      tmp___11 = quote(file_full_name);
      tmp___12 = gettext("cannot read directory %s");
      error(0, ent->fts_errno, (char const *)tmp___12, tmp___11);
    }
    ok = (_Bool)0;
    goto switch_break;

    goto switch_break;
  switch_default:
    goto switch_break;
  switch_break:;
    if (!ok) {
      do_chown = (_Bool)0;
      file_stats = (struct stat const *)((void *)0);
    } else {
      if (required_uid == 4294967295U) {
        if (required_gid == 4294967295U) {
          if ((unsigned int const)chopt->verbosity == 2U) {
            if (!chopt->root_dev_ino) {
              if (!chopt->affect_symlink_referent) {
                do_chown = (_Bool)1;
                file_stats = (struct stat const *)(ent->fts_statp);
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
        file_stats = (struct stat const *)(ent->fts_statp);
        if (ok) {
          if (required_uid == 4294967295U) {
            goto _L;
          } else {
            if (required_uid == (uid_t)file_stats->st_uid) {
            _L:
              if (required_gid == 4294967295U) {
                tmp___20 = 1;
              } else {
                if (required_gid == (gid_t)file_stats->st_gid) {
                  tmp___20 = 1;
                } else {
                  tmp___20 = 0;
                }
              }
            } else {
              tmp___20 = 0;
            }
          }
        } else {
          tmp___20 = 0;
        }
        do_chown = (_Bool)tmp___20;
      }
    }
    if (ok) {
      if ((int)ent->fts_info == 1) {
        goto _L___4;
      } else {
        if ((int)ent->fts_info == 2) {
          goto _L___4;
        } else {
          if ((int)ent->fts_info == 6) {
            goto _L___4;
          } else {
            if ((int)ent->fts_info == 4) {
            _L___4:
              if (chopt->root_dev_ino) {
              }
            }
          }
        }
      }
    }
    if (do_chown) {
      if (!chopt->affect_symlink_referent) {
        tmp___28 = lchownat(fts->fts_cwd_fd, file, uid, gid);
        ok = (_Bool)(tmp___28 == 0);

      } else {
        tmp___30 = restricted_chown(fts->fts_cwd_fd, file, file_stats, uid, gid, required_uid, required_gid);
        err = tmp___30;

        if ((unsigned int)err == 5U) {
          goto case_5;
        }

        if ((unsigned int)err == 4U) {
          goto case_4___0;
        }
        if ((unsigned int)err == 3U) {
          goto case_4___0;
        }
        goto switch_default___0;
        goto switch_break___0;
      case_5:
        tmp___31 = chownat(fts->fts_cwd_fd, file, uid, gid);
        ok = (_Bool)(tmp___31 == 0);
        goto switch_break___0;
        goto switch_break___0;
      case_4___0:
        do_chown = (_Bool)0;
        ok = (_Bool)0;
        goto switch_break___0;
      switch_default___0:
        abort();
      switch_break___0:;
      }
    }
    if ((unsigned int const)chopt->verbosity != 2U) {

      changed = (_Bool)tmp___37;
      if (changed) {
        goto _L___6;
      } else {
        if ((unsigned int const)chopt->verbosity == 0U) {
        _L___6:
          if (!ok) {
            tmp___40 = 3;
          } else {
            if (!symlink_changed) {
              tmp___39 = 1;
            } else {
              if (!changed) {
                tmp___38 = 4;
              } else {
                tmp___38 = 2;
              }
              tmp___39 = tmp___38;
            }
            tmp___40 = tmp___39;
          }
          ch_status = (enum Change_status)tmp___40;
          describe_change(file_full_name, ch_status, (char const *)chopt->user_name, (char const *)chopt->group_name);
        }
      }
    }
    if (!chopt->recurse) {
      fts_set(fts, ent, 4);
    }
    return (ok);
  }
}
extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid, uid_t required_uid, gid_t required_gid, struct Chown_option const *chopt) {
  _Bool ok;
  int stat_flags;
  int tmp;
  FTS *fts;
  FTS *tmp___0;
  FTSENT *ent;
  char *tmp___1;
  int *tmp___2;
  int *tmp___3;
  _Bool tmp___4;
  char *tmp___5;
  int *tmp___6;
  int tmp___7;

  {
    ok = (_Bool)1;
    if (required_uid != 4294967295U) {
      tmp = 0;
    } else {
      if (required_gid != 4294967295U) {
        tmp = 0;
      } else {
        if (chopt->affect_symlink_referent) {
          tmp = 0;
        } else {
          if ((unsigned int const)chopt->verbosity != 2U) {
            tmp = 0;
          } else {
            tmp = 8;
          }
        }
      }
    }
    stat_flags = tmp;
    tmp___0 = xfts_open((char *const *)files, bit_flags | stat_flags, (int (*)(FTSENT const **, FTSENT const **))((void *)0));
    fts = tmp___0;
    while (1) {
      ent = fts_read(fts);
      if ((unsigned long)ent == (unsigned long)((void *)0)) {
        tmp___3 = __errno_location();
        if (*tmp___3 != 0) {
          if (!chopt->force_silent) {
            tmp___1 = gettext("fts_read failed");
            tmp___2 = __errno_location();
            error(0, *tmp___2, (char const *)tmp___1);
          }
          ok = (_Bool)0;
        }
        goto while_break;
      }
      tmp___4 = change_file_owner(fts, ent, uid, gid, required_uid, required_gid, chopt);
      ok = (_Bool)((int)ok & (int)tmp___4);
    }
  while_break:
    tmp___7 = fts_close(fts);
    if (tmp___7 != 0) {
      tmp___5 = gettext("fts_close failed");
      tmp___6 = __errno_location();
      error(0, *tmp___6, (char const *)tmp___5);
      ok = (_Bool)0;
    }
    return (ok);
  }
}
extern char *optarg;

__inline static char *bad_cast(char const *s) {

  { return ((char *)s); }
}
static char *reference_file;
static struct option const long_options___1[14] = {{"recursive", 0, (int *)((void *)0), 'R'},      {"changes", 0, (int *)((void *)0), 'c'},
                                                   {"dereference", 0, (int *)((void *)0), 128},    {"from", 1, (int *)((void *)0), 129},
                                                   {"no-dereference", 0, (int *)((void *)0), 'h'}, {"no-preserve-root", 0, (int *)((void *)0), 130},
                                                   {"preserve-root", 0, (int *)((void *)0), 131},  {"quiet", 0, (int *)((void *)0), 'f'},
                                                   {"silent", 0, (int *)((void *)0), 'f'},         {"reference", 1, (int *)((void *)0), 132},
                                                   {"verbose", 0, (int *)((void *)0), 'v'},        {"help", 0, (int *)((void *)0), -130},
                                                   {"version", 0, (int *)((void *)0), -131},       {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
__attribute__((__noreturn__)) void usage(int status);
void usage(int status) {

  { exit(status); }
}
static struct dev_ino dev_ino_buf;
int main(int argc, char **argv) {
  _Bool preserve_root;
  uid_t uid;
  gid_t gid;
  uid_t required_uid;
  gid_t required_gid;
  int bit_flags;
  int dereference;
  struct Chown_option chopt;
  _Bool ok;
  int optc;
  char *u_dummy;
  char *g_dummy;
  char const *e;
  char const *tmp;
  char const *tmp___0;
  char *tmp___2;
  char const *tmp___3;
  char *tmp___4;
  int tmp___5;
  struct stat ref_stats;
  char const *tmp___6;
  char *tmp___7;
  int *tmp___8;
  int tmp___9;
  char const *e___0;
  char const *tmp___10;
  char const *tmp___11;
  int tmp___15;

  {
    preserve_root = (_Bool)0;
    uid = (uid_t)-1;
    gid = (gid_t)-1;
    required_uid = (uid_t)-1;
    required_gid = (gid_t)-1;
    bit_flags = 16;
    dereference = -1;
    set_program_name((char const *)*(argv + 0));
    setlocale(6, "");
    bindtextdomain("coreutils", "/usr/local/share/locale");
    textdomain("coreutils");
    atexit(&close_stdout);
    chopt_init(&chopt);
    while (1) {
      optc = getopt_long(argc, (char *const *)argv, "HLPRcfhv", long_options___1, (int *)((void *)0));
      if (!(optc != -1)) {
        goto while_break;
      }
      if (optc == 72) {
        goto case_72;
      }
      if (optc == 76) {
        goto case_76;
      }

      if (optc == 104) {
        goto case_104;
      }
      if (optc == 128) {
        goto case_128;
      }
      if (optc == 130) {
        goto case_130;
      }
      if (optc == 131) {
        goto case_131;
      }
      if (optc == 132) {
        goto case_132;
      }
      if (optc == 129) {
        goto case_129;
      }
      if (optc == 82) {
        goto case_82;
      }

      if (optc == -130) {
        goto case_neg_130;
      }

      goto switch_default;
    case_72:
      bit_flags = 17;
      goto switch_break;
    case_76:
      bit_flags = 2;
      goto switch_break;
      goto switch_break;
    case_104:
      dereference = 0;
      goto switch_break;
    case_128:
      dereference = 1;
      goto switch_break;
    case_130:
      preserve_root = (_Bool)0;
      goto switch_break;
    case_131:
      preserve_root = (_Bool)1;
      goto switch_break;
    case_132:
      reference_file = optarg;
      goto switch_break;
    case_129:
      tmp = parse_user_spec((char const *)optarg, &required_uid, &required_gid, &u_dummy, &g_dummy);
      e = tmp;
      if (e) {
        tmp___0 = quote((char const *)optarg);
        error(1, 0, "%s: %s", e, tmp___0);
      }
      goto switch_break;
    case_82:
      chopt.recurse = (_Bool)1;
      goto switch_break;
      goto switch_break;
      chopt.force_silent = (_Bool)1;
      goto switch_break;
      chopt.verbosity = (enum Verbosity)0;
      goto switch_break;
    case_neg_130:
      usage(0);
      goto switch_break;

      exit(0);
      goto switch_break;
    switch_default:
      usage(1);
    switch_break:;
    }
  while_break:;
    chopt.affect_symlink_referent = (_Bool)(dereference != 0);
    if (reference_file) {
      tmp___5 = 1;
    } else {
      tmp___5 = 2;
    }
    if (argc - optind < tmp___5) {
      if (argc <= optind) {
        tmp___2 = gettext("missing operand");
        error(0, 0, (char const *)tmp___2);
      } else {
        tmp___3 = quote((char const *)*(argv + (argc - 1)));
        tmp___4 = gettext("missing operand after %s");
        error(0, 0, (char const *)tmp___4, tmp___3);
      }
      usage(1);
    }
    if (reference_file) {
      tmp___9 = stat((char const *)reference_file, &ref_stats);
      if (tmp___9) {
        tmp___6 = quote((char const *)reference_file);
        tmp___7 = gettext("failed to get attributes of %s");
        tmp___8 = __errno_location();
        error(1, *tmp___8, (char const *)tmp___7, tmp___6);
      }
      uid = ref_stats.st_uid;
      gid = ref_stats.st_gid;
      chopt.user_name = uid_to_name(ref_stats.st_uid);
      chopt.group_name = gid_to_name(ref_stats.st_gid);
    } else {
      tmp___10 = parse_user_spec((char const *)*(argv + optind), &uid, &gid, &chopt.user_name, &chopt.group_name);
      e___0 = tmp___10;
      if (e___0) {
        tmp___11 = quote((char const *)*(argv + optind));
        error(1, 0, "%s: %s", e___0, tmp___11);
      }
      if (!chopt.user_name) {
        if (chopt.group_name) {
          chopt.user_name = bad_cast("");
        }
      }
      optind++;
    }

    bit_flags |= 1024;
    ok = chown_files(argv + optind, bit_flags, uid, gid, required_uid, required_gid, (struct Chown_option const *)(&chopt));
    chopt_free(&chopt);
    if (ok) {
      tmp___15 = 0;
    } else {
      tmp___15 = 1;
    }
    exit(tmp___15);
  }
}
