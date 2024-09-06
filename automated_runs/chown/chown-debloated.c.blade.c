
typedef unsigned long size_t;
typedef long __off_t;
typedef long __off64_t;
struct _IO_FILE;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
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
enum quoting_style {
  literal_quoting_style = 0,
  shell_quoting_style = 1,
  shell_always_quoting_style = 2,
  c_quoting_style = 3,
  c_maybe_quoting_style = 4,
  escape_quoting_style = 5,
  locale_quoting_style = 6,
  clocale_quoting_style = 7,
  custom_quoting_style = 8
};
enum strtol_error {
  LONGINT_OK = 0,
  LONGINT_OVERFLOW = 1,
  LONGINT_INVALID_SUFFIX_CHAR = 2,
  LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
  LONGINT_INVALID = 4
};
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

typedef struct __anonstruct___fsid_t_1 __fsid_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsfilcnt_t;
typedef long __fsword_t;
struct Active_dir {
  dev_t dev;
  ino_t ino;
  FTSENT *fts_ent;
};

enum Change_status {
  CH_NOT_APPLIED = 1,
  CH_SUCCEEDED = 2,
  CH_FAILED = 3,
  CH_NO_CHANGE_REQUESTED = 4
};
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
enum RCH_status {
  RC_ok = 2,
  RC_excluded = 3,
  RC_inode_changed = 4,
  RC_do_ordinary_chown = 5,
  RC_error = 6
};
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern int close(int __fd);
extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag, ...);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) tolower)(
    int __c);
extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s)
    __attribute__((__pure__));
extern int fclose(FILE *__stream);
int dup_safer(int fd);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2),
                                                       __leaf__)) strncmp)(
    char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
__attribute__((__noreturn__)) void xalloc_die(void);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(
    size_t __size) __attribute__((__malloc__));
char *last_component(char const *name);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) gettext)(
    char const *__msgid) __attribute__((__format_arg__(1)));
void *hash_lookup(Hash_table const *table___0, void const *entry);
void *(__attribute__((__warn_unused_result__)) hash_insert)(
    Hash_table *table___0, void const *entry);
void triple_free(void *x);
void *xmalloc(size_t n) __attribute__((__malloc__));
char *xstrdup(char const *string) __attribute__((__malloc__));
extern DIR *fdopendir(int __fd);
DIR *rpl_fdopendir(int fd);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(2), __leaf__)) fstat)(int __fd, struct stat *__buf);

int fd_safer(int fd) {
  int f;
  int tmp;
  int e;
  int *tmp___0;
  int *tmp___1;

  { return (fd); }
}
int volatile exit_failure;
int volatile exit_failure = (int volatile)1;
extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) int(
    __attribute__((__leaf__)) ferror_unlocked)(FILE *__stream);
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__)) __ctype_get_mb_cur_max)(void);
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(
    void *__ptr);
extern
    __attribute__((__nothrow__,
                   __noreturn__)) void(__attribute__((__leaf__)) abort)(void);
extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1), __leaf__)) memset)(void *__s, int __c, size_t __n);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strchr)(char const *__s, int __c)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strrchr)(char const *__s, int __c)
    __attribute__((__pure__));
int mbscasecmp(char const *s1, char const *s2);
extern __attribute__((__nothrow__))
wint_t(__attribute__((__leaf__)) towlower)(wint_t __wc);
size_t hash_string(char const *string, size_t n_buckets);
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(
    size_t candidate, Hash_tuning const *tuning,
    size_t (*hasher)(void const *, size_t),
    _Bool (*comparator)(void const *, void const *),
    void (*data_freer)(void *));
void hash_free(Hash_table *table___0);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((
    __leaf__)) __assert_fail)(char const *__assertion, char const *__file,
                              unsigned int __line, char const *__function);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) mbsinit)(
    mbstate_t const *__ps) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrtowc)(
    wchar_t *__restrict __pwc, char const *__restrict __s, size_t __n,
    mbstate_t *__restrict __p);
unsigned int const is_basic_table[8];

size_t strnlen1(char const *string, size_t maxlen);

void *xrealloc(void *p, size_t n);
extern int fcntl(int __fd, int __cmd, ...);

extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) memcpy)(
    void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchown)(
    int __fd, __uid_t __owner, __gid_t __group);
char const diacrit_base[256];
char const diacrit_diac[256];
char const diacrit_base[256] = {
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)'A', (char const)'B', (char const)'C',
    (char const)'D', (char const)'E', (char const)'F', (char const)'G',
    (char const)'H', (char const)'I', (char const)'J', (char const)'K',
    (char const)'L', (char const)'M', (char const)'N', (char const)'O',
    (char const)'P', (char const)'Q', (char const)'R', (char const)'S',
    (char const)'T', (char const)'U', (char const)'V', (char const)'W',
    (char const)'X', (char const)'Y', (char const)'Z', (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)'a', (char const)'b', (char const)'c',
    (char const)'d', (char const)'e', (char const)'f', (char const)'g',
    (char const)'h', (char const)'i', (char const)'j', (char const)'k',
    (char const)'l', (char const)'m', (char const)'n', (char const)'o',
    (char const)'p', (char const)'q', (char const)'r', (char const)'s',
    (char const)'t', (char const)'u', (char const)'v', (char const)'w',
    (char const)'x', (char const)'y', (char const)'z', (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)'A', (char const)'A', (char const)'A', (char const)'A',
    (char const)'A', (char const)'A', (char const)'A', (char const)'C',
    (char const)'E', (char const)'E', (char const)'E', (char const)'E',
    (char const)'I', (char const)'I', (char const)'I', (char const)'I',
    (char const)0,   (char const)'N', (char const)'O', (char const)'O',
    (char const)'O', (char const)'O', (char const)'O', (char const)0,
    (char const)'O', (char const)'U', (char const)'U', (char const)'U',
    (char const)'U', (char const)'Y', (char const)0,   (char const)0,
    (char const)'a', (char const)'a', (char const)'a', (char const)'a',
    (char const)'a', (char const)'a', (char const)'a', (char const)'c',
    (char const)'e', (char const)'e', (char const)'e', (char const)'e',
    (char const)'i', (char const)'i', (char const)'i', (char const)'i',
    (char const)0,   (char const)'n', (char const)'o', (char const)'o',
    (char const)'o', (char const)'o', (char const)'o', (char const)0,
    (char const)'o', (char const)'u', (char const)'u', (char const)'u',
    (char const)'u', (char const)'y', (char const)0,   (char const)'y'};
char const diacrit_diac[256] = {
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)4,
    (char const)0, (char const)3, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)6, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)3, (char const)2, (char const)4,
    (char const)6, (char const)5, (char const)8, (char const)1, (char const)7,
    (char const)3, (char const)2, (char const)4, (char const)5, (char const)3,
    (char const)2, (char const)4, (char const)5, (char const)0, (char const)6,
    (char const)3, (char const)2, (char const)4, (char const)6, (char const)5,
    (char const)0, (char const)9, (char const)3, (char const)2, (char const)4,
    (char const)5, (char const)2, (char const)0, (char const)0, (char const)3,
    (char const)2, (char const)4, (char const)6, (char const)5, (char const)8,
    (char const)1, (char const)7, (char const)3, (char const)2, (char const)4,
    (char const)5, (char const)3, (char const)2, (char const)4, (char const)5,
    (char const)0, (char const)6, (char const)3, (char const)2, (char const)4,
    (char const)6, (char const)5, (char const)0, (char const)9, (char const)3,
    (char const)2, (char const)4, (char const)5, (char const)2, (char const)0,
    (char const)0};
void cycle_check_init(struct cycle_check_state *state);
_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb);
__inline static _Bool is_zero_or_power_of_two(uintmax_t i) {

  { return ((_Bool)((i & (i - 1UL)) == 0UL)); }
}
void cycle_check_init(struct cycle_check_state *state) {

  {
    state->chdir_counter = (uintmax_t)0;
    state->magic = 9827862;
    return;
  }
}
_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb) {
  _Bool tmp;

  {

    if (state->chdir_counter) {
      if (sb->st_ino == (__ino_t const)state->dev_ino.st_ino) {
        if (sb->st_dev == (__dev_t const)state->dev_ino.st_dev) {
          return ((_Bool)1);
        }
      }
    }
    (state->chdir_counter)++;
    tmp = is_zero_or_power_of_two(state->chdir_counter);
    if (tmp) {

      state->dev_ino.st_dev = (dev_t)sb->st_dev;
      state->dev_ino.st_ino = (ino_t)sb->st_ino;
    }
    return ((_Bool)0);
  }
}
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

    tmp___5 = close_stream(stderr);
    if (tmp___5 != 0) {
      _exit((int)exit_failure);
    }
    return;
  }
}
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__)) __fpending)(FILE *__fp);
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

    return (0);
  }
}
int set_cloexec_flag(int desc, _Bool value);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchdir)(
    int __fd);
extern int(__attribute__((__nonnull__(2))) openat)(int __fd, char const *__file,
                                                   int __oflag, ...);
extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1), __leaf__)) memchr)(void const *__s, int __c, size_t __n)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1, 2), __leaf__)) memmove)(void *__dest, void const *__src,
                                           size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file,
                                         struct stat *__restrict __buf);
size_t triple_hash(void const *x, size_t table_size);
_Bool triple_compare_ino_str(void const *x, void const *y);

char const *simple_backup_suffix;
void (*argmatch_die)(void);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2,
                                          size_t __n) __attribute__((__pure__));
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
DIR *opendir_safer(char const *name);
char const *simple_backup_suffix = "~";
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format,
                   ...);
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char const *quote_n(int n, char const *name);
__attribute__((__noreturn__)) void usage(int status);
extern __attribute__((__nothrow__)) void *(__attribute__((
    __warn_unused_result__, __leaf__)) realloc)(void *__ptr, size_t __size);
__inline static void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__));
__inline static void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__));

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes);
extern __attribute__((__nothrow__)) unsigned long(__attribute__((
    __nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr,
                                        char **__restrict __endptr, int __base);
static strtol_error bkm_scale___0(unsigned long *x, int scale_factor) {

  {

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
    while (1) {
      tmp___0 = power;
      power--;
      if (!tmp___0) {
        goto while_break;
      }
      tmp = bkm_scale___0(x, base);
      err = (strtol_error)((unsigned int)err | (unsigned int)tmp);
    }
  while_break:;
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
  unsigned char ch;
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

    tmp___1 = __errno_location();
    *tmp___1 = 0;
    tmp = strtoul(s, p, strtol_base);

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

      if ((int)*(*p) == 98) {
        goto case_98;
      }
      if ((int)*(*p) == 66) {
        goto case_66___0;
      }
      if ((int)*(*p) == 99) {
        goto case_99;
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

      if ((int)*(*p) == 77) {
        goto case_77;
      }

      if ((int)*(*p) == 80) {
        goto case_80;
      }
      if ((int)*(*p) == 84) {
        goto case_84;
      }
      if ((int)*(*p) == 116) {
        goto case_84;
      }

      if ((int)*(*p) == 89) {
        goto case_89;
      }

      goto switch_default;
    case_98:
      overflow = bkm_scale___0(&tmp, 512);
      goto switch_break___0;
    case_66___0:
      overflow = bkm_scale___0(&tmp, 1024);
      goto switch_break___0;
    case_99:
      overflow = (strtol_error)0;
      goto switch_break___0;
    case_69:
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
    case_80:
      overflow = bkm_scale_by_power___0(&tmp, base, 5);
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
    }
    *val = tmp;
    return (err);
  }
}
void *xmemdup(void const *p, size_t s) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) calloc)(
    size_t __nmemb, size_t __size) __attribute__((__malloc__));
void *xmalloc(size_t n) __attribute__((__malloc__));
void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    tmp = malloc(n);
    p = tmp;

    return (p);
  }
}
void *xrealloc(void *p, size_t n) {

  {
    p = realloc(p, n);

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
__attribute__((__nothrow__))
FTS *(__attribute__((__warn_unused_result__, __leaf__)) fts_open)(
    char *const *argv, int options,
    int (*compar)(FTSENT const **, FTSENT const **));
FTS *xfts_open(char *const *argv, int options,
               int (*compar)(FTSENT const **, FTSENT const **));
_Bool cycle_warning_required(FTS const *fts, FTSENT const *ent);
FTS *xfts_open(char *const *argv, int options,
               int (*compar)(FTSENT const **, FTSENT const **)) {
  FTS *fts;
  FTS *tmp;
  int *tmp___0;

  {
    tmp = fts_open(argv, options | 512, compar);
    fts = tmp;

    return (fts);
  }
}
_Bool cycle_warning_required(FTS const *fts, FTSENT const *ent) {
  int tmp;

  { return ((_Bool)tmp); }
}
__attribute__((__noreturn__)) void xalloc_die(void);

extern int printf(char const *__restrict __format, ...);
extern int fputs_unlocked(char const *__restrict __s,
                          FILE *__restrict __stream);
char const version_etc_copyright[47];
void version_etc_arn(FILE *stream, char const *command_name,
                     char const *package, char const *version,
                     char const *const *authors, size_t n_authors);
void version_etc_va(FILE *stream, char const *command_name, char const *package,
                    char const *version, va_list authors);
void version_etc(FILE *stream, char const *command_name, char const *package,
                 char const *version, ...) __attribute__((__sentinel__));

void version_etc(FILE *stream, char const *command_name, char const *package,
                 char const *version, ...) __attribute__((__sentinel__));

char const *parse_user_spec(char const *spec, uid_t *uid, gid_t *gid,
                            char **username, char **groupname);
extern void endpwent(void);
extern struct passwd *getpwnam(char const *__name);
extern void endgrent(void);
extern struct group *getgrgid(__gid_t __gid);
extern struct group *getgrnam(char const *__name);
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1);
static char const *parse_with_separator(char const *spec, char const *separator,
                                        uid_t *uid, gid_t *gid, char **username,
                                        char **groupname);
static char const *E_invalid_user = "invalid user";
static char const *E_invalid_group = "invalid group";
static char const *E_bad_spec = "invalid spec";
static char const *parse_with_separator(char const *spec, char const *separator,
                                        uid_t *uid, gid_t *gid, char **username,
                                        char **groupname) {
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

        use_login_group = (_Bool)tmp___1;
        if (use_login_group) {
          error_msg = E_bad_spec;
        } else {
          tmp___3 =
              xstrtoul((char const *)u, (char **)((void *)0), 10, &tmp___2, "");
          if ((unsigned int)tmp___3 == 0U) {

          } else {
            error_msg = E_invalid_user;
          }
        }
      } else {
        unum = pwd->pw_uid;
        if ((unsigned long)g == (unsigned long)((void *)0)) {
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
char const *parse_user_spec(char const *spec, uid_t *uid, gid_t *gid,
                            char **username, char **groupname) {
  char const *colon;
  char const *tmp;
  char const *error_msg;
  char const *tmp___0;
  char const *dot;
  char const *tmp___1;
  char const *tmp___2;

  {
    tmp = (char const *)strchr(spec, ':');
    colon = tmp;
    tmp___0 = parse_with_separator(spec, colon, uid, gid, username, groupname);
    error_msg = tmp___0;

    return (error_msg);
  }
}
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1) {
  char *p;

  {
    p = buf___1 + (((sizeof(uintmax_t) * 8UL) * 146UL) / 485UL + 1UL);
    *p = (char)0;

  while_break:;
    return (p);
  }
}

struct dev_ino *get_root_dev_ino(struct dev_ino *root_d_i);

reg_syntax_t rpl_re_syntax_options;
char const *const quoting_style_args[9];
enum quoting_style const quoting_style_vals[8];
int set_char_quoting(struct quoting_options *o, char c, int i);
char *quotearg_char(char const *arg, char ch);
char *quotearg_char_mem(char const *arg, size_t argsize, char ch);
__inline static char *xcharalloc(size_t n) __attribute__((__malloc__));
__inline static char *xcharalloc(size_t n) __attribute__((__malloc__));
__inline static char *xcharalloc(size_t n) {
  void *tmp;
  void *tmp___0;
  void *tmp___1;

  { return ((char *)tmp___1); }
}
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) iswprint)(
    wint_t __wc);
char const *const quoting_style_args[9] = {
    "literal", "shell",   "shell-always", "c", "c-maybe", "escape",
    "locale",  "clocale", (char const *)0};
enum quoting_style const quoting_style_vals[8] = {
    (enum quoting_style const)0, (enum quoting_style const)1,
    (enum quoting_style const)2, (enum quoting_style const)3,
    (enum quoting_style const)4, (enum quoting_style const)5,
    (enum quoting_style const)6, (enum quoting_style const)7};
static struct quoting_options default_quoting_options;
int set_char_quoting(struct quoting_options *o, char c, int i) {
  unsigned char uc;
  unsigned int *p;
  struct quoting_options *tmp;
  int shift;
  int r;

  {
    uc = (unsigned char)c;

    p = tmp->quote_these_too + (unsigned long)uc / (sizeof(int) * 8UL);
    shift = (int)((unsigned long)uc % (sizeof(int) * 8UL));
    r = (int)((*p >> shift) & 1U);
    *p ^= (unsigned int)(((i & 1) ^ r) << shift);
    return (r);
  }
}
static struct quoting_options
quoting_options_from_style(enum quoting_style style) {
  struct quoting_options o;

  {
    o.style = style;
    o.flags = 0;
    memset((void *)(o.quote_these_too), 0, sizeof(o.quote_these_too));
    return (o);
  }
}

static size_t
quotearg_buffer_restyled(char *buffer, size_t buffersize, char const *arg,
                         size_t argsize, enum quoting_style quoting_style,
                         int flags, unsigned int const *quote_these_too,
                         char const *left_quote, char const *right_quote) {
  size_t i;
  size_t len;
  char const *quote_string;
  size_t quote_string_len;
  _Bool backslash_escapes;
  _Bool unibyte_locale;
  size_t tmp;
  _Bool elide_outer_quotes;
  unsigned char c;
  unsigned char esc;
  _Bool is_right_quote;
  int tmp___0;
  int tmp___1;
  size_t m;
  _Bool printable;
  unsigned short const **tmp___2;
  mbstate_t mbstate;
  wchar_t w;
  size_t bytes;
  size_t tmp___3;
  size_t j;
  int tmp___4;
  int tmp___5;
  size_t ilim;
  int tmp___6;
  size_t tmp___7;

  {
    len = (size_t)0;
    quote_string = (char const *)0;
    quote_string_len = (size_t)0;
    backslash_escapes = (_Bool)0;
    tmp = __ctype_get_mb_cur_max();
    unibyte_locale = (_Bool)(tmp == 1UL);
    elide_outer_quotes = (_Bool)((flags & 2) != 0);

    goto switch_default;
  case_4:
    quoting_style = (enum quoting_style)3;
    elide_outer_quotes = (_Bool)1;
  case_3:

    backslash_escapes = (_Bool)1;
    quote_string = "\"";
    quote_string_len = (size_t)1;
    goto switch_break;
  case_5:
    backslash_escapes = (_Bool)1;
    elide_outer_quotes = (_Bool)0;
    goto switch_break;
  case_6:

    if (!elide_outer_quotes) {
      quote_string = left_quote;
      while (1) {

        if (!*quote_string) {
          goto while_break___0;
        }
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)*quote_string;
          }
          len++;
          goto while_break___1;
        }
      while_break___1:
        quote_string++;
      }
    while_break___0:;
    }
    backslash_escapes = (_Bool)1;
    quote_string = right_quote;
    quote_string_len = strlen(quote_string);
    goto switch_break;
  case_1:
    quoting_style = (enum quoting_style)2;
    elide_outer_quotes = (_Bool)1;
  case_2:
    if (!elide_outer_quotes) {
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)'\'';
        }
        len++;
        goto while_break___2;
      }
    while_break___2:;
    }
    quote_string = "\'";
    quote_string_len = (size_t)1;
    goto switch_break;
  case_0:
    elide_outer_quotes = (_Bool)0;
    goto switch_break;
  switch_default:
    abort();
  switch_break:
    i = (size_t)0;
    while (1) {

      if (argsize == 0xffffffffffffffffUL) {
        tmp___6 = (int const) * (arg + i) == 0;
      } else {
        tmp___6 = i == argsize;
      }
      if (tmp___6) {
        goto while_break___3;
      }
      is_right_quote = (_Bool)0;

      c = (unsigned char)*(arg + i);

      goto switch_default___2;
    case_0___0:
      if (backslash_escapes) {

        while (1) {

          len++;
          goto while_break___4;
        }
      while_break___4:;
        if (i + 1UL < argsize) {
        }
        c = (unsigned char)'0';
      } else {
      }
      goto switch_break___0;
    case_63:

      goto switch_default___1;
    case_2___0:

      goto switch_break___1;
    case_3___0:
      if (flags & 4) {
        if (i + 2UL < argsize) {
        }
      }
      goto switch_break___1;
    switch_default___1:
      goto switch_break___1;
    switch_break___1:;
      goto switch_break___0;
    case_7___0:
      esc = (unsigned char)'a';
      goto c_escape;
    case_8___0:
      esc = (unsigned char)'b';
      goto c_escape;
    case_12:
      esc = (unsigned char)'f';
      goto c_escape;
    case_10:
      esc = (unsigned char)'n';
      goto c_and_shell_escape;
    case_13:
      esc = (unsigned char)'r';
      goto c_and_shell_escape;
    case_9:
      esc = (unsigned char)'t';
      goto c_and_shell_escape;
    case_11:
      esc = (unsigned char)'v';
      goto c_escape;
    case_92:
      esc = c;

    c_and_shell_escape:

    c_escape:
      if (backslash_escapes) {
        c = esc;
        goto store_escape;
      }
      goto switch_break___0;
    case_123:

    case_35:

    case_32:

      goto switch_break___0;
    case_39___0:

      goto switch_break___0;
    case_37:
      goto switch_break___0;
    switch_default___2:
      if (unibyte_locale) {
        m = (size_t)1;
        tmp___2 = __ctype_b_loc();
        printable = (_Bool)(((int const) * (*tmp___2 + (int)c) & 16384) != 0);
      } else {
        memset((void *)(&mbstate), 0, sizeof(mbstate));
        m = (size_t)0;
        printable = (_Bool)1;
        if (argsize == 0xffffffffffffffffUL) {
          argsize = strlen(arg);
        }

      while_break___14:;
      }
      if (1UL < m) {
        goto _L___0;
      } else {
        if (backslash_escapes) {
          if (!printable) {
          _L___0:
            ilim = i + m;
            while (1) {

              if (backslash_escapes) {
                if (!printable) {

                  while (1) {

                    if (len < buffersize) {
                      *(buffer + len) = (char)'\\';
                    }
                    len++;
                    goto while_break___18;
                  }
                while_break___18:;

                while_break___19:;

                while_break___20:
                  c = (unsigned char)(48 + ((int)c & 7));
                } else {
                  goto _L;
                }
              } else {
              _L:
                if (is_right_quote) {

                while_break___21:
                  is_right_quote = (_Bool)0;
                }
              }
              if (ilim <= i + 1UL) {
                goto while_break___17;
              }
              while (1) {

                if (len < buffersize) {
                  *(buffer + len) = (char)c;
                }
                len++;
                goto while_break___22;
              }
            while_break___22:
              i++;
              c = (unsigned char)*(arg + i);
            }
          while_break___17:;
            goto store_c;
          }
        }
      }
    switch_break___0:;

    store_escape:

    while_break___23:;
    store_c:
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)c;
        }
        len++;
        goto while_break___24;
      }
    while_break___24:;
    __Cont:
      i++;
    }
  while_break___3:;

    if (quote_string) {
    }
    if (len < buffersize) {
      *(buffer + len) = (char)'\000';
    }
    return (len);
  force_outer_quoting_style:
    tmp___7 = quotearg_buffer_restyled(
        buffer, buffersize, arg, argsize, quoting_style, flags & -3,
        (unsigned int const *)((void *)0), left_quote, right_quote);
    return (tmp___7);
  }
}
static char slot0[256];
static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options) {
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

    if (nslots <= n0) {
      n1 = (size_t)(n0 + 1U);
      preallocated = (_Bool)((unsigned long)sv == (unsigned long)(&slotvec0));

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
    tmp___2 = quotearg_buffer_restyled(
        val, size, arg, argsize, (enum quoting_style)options->style, flags,
        (unsigned int const *)(options->quote_these_too),
        (char const *)options->left_quote, (char const *)options->right_quote);
    qsize = tmp___2;
    if (size <= qsize) {
      size = qsize + 1UL;
      (sv + n)->size = size;
      if ((unsigned long)val != (unsigned long)(slot0)) {
        free((void *)val);
      }
      val = xcharalloc(size);
      (sv + n)->val = val;
      quotearg_buffer_restyled(val, size, arg, argsize,
                               (enum quoting_style)options->style, flags,
                               (unsigned int const *)(options->quote_these_too),
                               (char const *)options->left_quote,
                               (char const *)options->right_quote);
    }
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
    tmp___0 = quotearg_n_options(n, arg, (size_t)-1,
                                 (struct quoting_options const *)(&o));
    return (tmp___0);
  }
}
char *quotearg_char_mem(char const *arg, size_t argsize, char ch) {
  struct quoting_options options;
  char *tmp;

  {
    options = default_quoting_options;
    set_char_quoting(&options, ch, 1);
    tmp = quotearg_n_options(0, arg, argsize,
                             (struct quoting_options const *)(&options));
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
  char const *base;
  int tmp;
  int tmp___0;

  {

    slash = (char const *)strrchr(argv0, '/');

    program_name = argv0;
    program_invocation_name = (char *)argv0;
    return;
  }
}
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) stpcpy)(char *__restrict __dest,
                                          char const *__restrict __src);
extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) dirfd)(DIR *__dirp);

int openat_safer(int fd, char const *file, int flags, ...) {
  mode_t mode;
  va_list ap;
  int tmp;
  int tmp___0;

  {
    mode = (mode_t)0;

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

    tmp = open(file, flags, mode);
    tmp___0 = fd_safer(tmp);
    return (tmp___0);
  }
}

unsigned int const is_basic_table[8] = {
    (unsigned int const)6656, (unsigned int const)4294967279U,
    (unsigned int const)4294967294U, (unsigned int const)2147483646};
extern __attribute__((__nothrow__, __noreturn__)) void(
    __attribute__((__leaf__)) exit)(int __status);
extern int optind;
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) getopt_long)(
    int ___argc, char *const *___argv, char const *__shortopts,
    struct option const *__longopts, int *__longind);

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
    while (1) {

      if (!(i < 4)) {
        goto while_break;
      }
      ir->ir_data[i] = default_val;
      i++;
    }
  while_break:
    ir->ir_default_val = default_val;
    return;
  }
}
_Bool i_ring_empty(I_ring const *ir) {

  { return ((_Bool)ir->ir_empty); }
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
_Bool(__attribute__((__warn_unused_result__)) hash_rehash)(
    Hash_table *table___0, size_t candidate);
void *hash_delete(Hash_table *table___0, void const *entry);

static struct hash_tuning const default_tuning = {
    (float)0.0, (float)1.0, (float)0.8, (float)1.414, (_Bool)0};

static size_t next_prime(size_t candidate) {
  _Bool tmp;

  {
    if (candidate < 10UL) {
      candidate = (size_t)10;
    }
    candidate |= 1UL;

  while_break:;
    return (candidate);
  }
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
  int tmp;

  {
    if (!tuning->is_n_buckets) {
      new_candidate =
          (float)((float const)candidate / tuning->growth_threshold);

      candidate = (size_t)new_candidate;
    }
    candidate = next_prime(candidate);

    return (candidate);
  }
}
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(
    size_t candidate, Hash_tuning const *tuning,
    size_t (*hasher)(void const *, size_t),
    _Bool (*comparator)(void const *, void const *),
    void (*data_freer)(void *)) {
  Hash_table *table___0;
  _Bool tmp;

  {

    table___0 = (Hash_table *)malloc(sizeof(*table___0));
    if ((unsigned long)table___0 == (unsigned long)((void *)0)) {
      return ((Hash_table *)((void *)0));
    }

    table___0->tuning = tuning;
    tmp = check_tuning(table___0);

    table___0->n_buckets = compute_bucket_size(candidate, tuning);
    if (!table___0->n_buckets) {
      goto fail;
    }
    table___0->bucket = (struct hash_entry *)calloc(
        table___0->n_buckets, sizeof(*(table___0->bucket)));
    if ((unsigned long)table___0->bucket == (unsigned long)((void *)0)) {
      goto fail;
    }
    table___0->bucket_limit =
        (struct hash_entry const *)(table___0->bucket + table___0->n_buckets);
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
    tmp = (*(table___0->hasher))(entry, table___0->n_buckets);
    bucket = table___0->bucket + tmp;

    *bucket_head = bucket;
    if ((unsigned long)bucket->data == (unsigned long)((void *)0)) {
      return ((void *)0);
    }
    if ((unsigned long)entry == (unsigned long)bucket->data) {
      goto _L;
    } else {
      tmp___0 = (*(table___0->comparator))(entry, (void const *)bucket->data);
      if (tmp___0) {
      _L:
        data = bucket->data;
        if (delete) {
        }
        return (data);
      }
    }
    cursor = bucket;

  while_break:;
    return ((void *)0);
  }
}
static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {
  struct hash_entry *bucket;
  struct hash_entry *cursor;
  struct hash_entry *next;
  void *data;
  struct hash_entry *new_bucket;
  size_t tmp;
  size_t tmp___0;
  struct hash_entry *new_entry;
  struct hash_entry *tmp___1;

  {
    bucket = src->bucket;

  while_break:;
    return ((_Bool)1);
  }
}
_Bool(__attribute__((__warn_unused_result__)) hash_rehash)(
    Hash_table *table___0, size_t candidate) {
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

    if (new_size == table___0->n_buckets) {
      return ((_Bool)1);
    }
    new_table = &storage;
    new_table->bucket =
        (struct hash_entry *)calloc(new_size, sizeof(*(new_table->bucket)));

    new_table->n_buckets = new_size;
    new_table->bucket_limit =
        (struct hash_entry const *)(new_table->bucket + new_size);
    new_table->n_buckets_used = (size_t)0;
    new_table->n_entries = (size_t)0;
    new_table->tuning = table___0->tuning;
    new_table->hasher = table___0->hasher;
    new_table->comparator = table___0->comparator;
    new_table->data_freer = table___0->data_freer;
    new_table->free_entry_list = table___0->free_entry_list;
    tmp___0 = transfer_entries(new_table, table___0, (_Bool)0);
    if (tmp___0) {
      free((void *)table___0->bucket);
      table___0->bucket = new_table->bucket;
      table___0->bucket_limit = new_table->bucket_limit;
      table___0->n_buckets = new_table->n_buckets;
      table___0->n_buckets_used = new_table->n_buckets_used;
      table___0->free_entry_list = new_table->free_entry_list;
      return ((_Bool)1);
    }
    table___0->free_entry_list = new_table->free_entry_list;
    tmp___1 = transfer_entries(table___0, new_table, (_Bool)1);

    free((void *)new_table->bucket);
    return ((_Bool)0);
  }
}
void *(__attribute__((__warn_unused_result__)) hash_insert)(
    Hash_table *table___0, void const *entry) {
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

    data = hash_find_entry(table___0, entry, &bucket, (_Bool)0);
    if ((unsigned long)data != (unsigned long)((void *)0)) {
      return (data);
    }
    if ((float const)table___0->n_buckets_used >
        (table___0->tuning)->growth_threshold *
            (float const)table___0->n_buckets) {
      check_tuning(table___0);
    }
    if (bucket->data) {
      tmp___2 = allocate_entry(table___0);
      new_entry = tmp___2;

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

size_t hash_pjw(void const *x, size_t tablesize);

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2, 3),
                                                       __leaf__)) fstatat)(
    int __fd, char const *__restrict __file, struct stat *__restrict __buf,
    int __flag);
__attribute__((__nothrow__)) int(__attribute__((__warn_unused_result__,
                                                __leaf__)) fts_close)(FTS *sp);
__attribute__((__nothrow__))
FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp);
__attribute__((__nothrow__)) int(__attribute__((__leaf__)) fts_set)(
    FTS *sp __attribute__((__unused__)), FTSENT *p, int instr);
extern void(__attribute__((__nonnull__(1, 4))) qsort)(
    void *__base, size_t __nmemb, size_t __size,
    int (*__compar)(void const *, void const *));
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
static _Bool AD_compare(void const *x, void const *y) {
  struct Active_dir const *ax;
  struct Active_dir const *ay;
  int tmp;

  {
    ax = (struct Active_dir const *)x;
    ay = (struct Active_dir const *)y;

    return ((_Bool)tmp);
  }
}
static size_t AD_hash(void const *x, size_t table_size) {
  struct Active_dir const *ax;

  {
    ax = (struct Active_dir const *)x;
    return ((uintmax_t)ax->ino % table_size);
  }
}
static _Bool setup_dir(FTS *fts) {

  {
    if (fts->fts_options & 258) {
      fts->fts_cycle.ht =
          hash_initialize((size_t)31, (Hash_tuning const *)((void *)0),
                          &AD_hash, &AD_compare, (void (*)(void *))(&free));

    } else {
      fts->fts_cycle.state =
          (struct cycle_check_state *)malloc(sizeof(*(fts->fts_cycle.state)));

      cycle_check_init(fts->fts_cycle.state);
    }
    return ((_Bool)1);
  }
}
static _Bool enter_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;
  struct Active_dir *ad;
  struct Active_dir *tmp;
  struct Active_dir *ad_from_table;
  _Bool tmp___0;

  {
    if (fts->fts_options & 258) {
      st = (struct stat const *)(ent->fts_statp);
      tmp = (struct Active_dir *)malloc(sizeof(*ad));
      ad = tmp;

      ad->dev = (dev_t)st->st_dev;
      ad->ino = (ino_t)st->st_ino;
      ad->fts_ent = ent;
      ad_from_table =
          (struct Active_dir *)hash_insert(fts->fts_cycle.ht, (void const *)ad);
      if ((unsigned long)ad_from_table != (unsigned long)ad) {
        free((void *)ad);

        ent->fts_cycle = ad_from_table->fts_ent;
        ent->fts_info = (unsigned short)2;
      }
    } else {
      tmp___0 = cycle_check(fts->fts_cycle.state,
                            (struct stat const *)(ent->fts_statp));
      if (tmp___0) {
        ent->fts_cycle = ent;
        ent->fts_info = (unsigned short)2;
      }
    }
    return ((_Bool)1);
  }
}
static void leave_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;
  struct Active_dir obj;
  void *found;
  FTSENT *parent;

  {
    st = (struct stat const *)(ent->fts_statp);

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

  while_break:;
    if (required) {
      p->fts_statp[0].st_size = (__off_t)2;
    } else {
      p->fts_statp[0].st_size = (__off_t)1;
    }
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

    open_flags = 67840 | tmp;
    if (sp->fts_options & 512) {
      tmp___0 = openat_safer((int)sp->fts_cwd_fd, dir, open_flags);
      tmp___2 = tmp___0;
    } else {
      tmp___1 = open_safer(dir, open_flags);
      tmp___2 = tmp___1;
    }
    fd = tmp___2;

    return (fd);
  }
}
__attribute__((__nothrow__))
FTS *(__attribute__((__warn_unused_result__, __leaf__)) fts_open)(
    char *const *argv, int options,
    int (*compar)(FTSENT const **, FTSENT const **));
FTS *(__attribute__((__warn_unused_result__, __leaf__)) fts_open)(
    char *const *argv, int options,
    int (*compar)(FTSENT const **, FTSENT const **)) {
  FTS *sp;
  FTSENT *p;
  FTSENT *root;
  size_t nitems;
  FTSENT *parent;
  FTSENT *tmp;
  _Bool defer_stat;
  int *tmp___0;
  int *tmp___1;
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

    if ((unsigned long)*argv != (unsigned long)((void *)0)) {
      parent = fts_alloc(sp, "", (size_t)0);

      parent->fts_level = (ptrdiff_t)-1;
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

      p->fts_level = (ptrdiff_t)0;
      p->fts_parent = parent;
      p->fts_accpath = p->fts_name;
      if (defer_stat) {

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

__attribute__((__nothrow__)) int(__attribute__((__warn_unused_result__,
                                                __leaf__)) fts_close)(FTS *sp);
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

    free((void *)sp->fts_array);
    free((void *)sp->fts_path);

    fd_ring_clear(&sp->fts_fd_ring);

    free_dir(sp);
    free((void *)sp);

    return (0);
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(2), __leaf__)) fstatfs)(int __fildes, struct statfs *__buf);

__attribute__((__nothrow__))
FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp);
FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp) {
  FTSENT *p;
  FTSENT *tmp;
  unsigned short instr;
  char *t;
  int *tmp___0;
  int tmp___1;
  int *tmp___2;
  int tmp___3;
  struct _ftsent *tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int *tmp___10;
  int tmp___11;
  size_t tmp___12;
  char *tmp___13;
  FTSENT *parent;
  _Bool tmp___14;
  int *tmp___15;
  _Bool tmp___16;
  int *tmp___17;
  struct _ftsent *tmp___18;
  int *tmp___19;
  int tmp___20;
  int tmp___21;
  int tmp___22;
  int tmp___23;
  int tmp___24;
  int saved_errno;
  int *tmp___25;
  int *tmp___26;
  int *tmp___27;
  int tmp___28;
  int tmp___29;
  int *tmp___30;
  int tmp___31;
  FTSENT *tmp___32;

  {

    p = sp->fts_cur;
    instr = p->fts_instr;
    p->fts_instr = (unsigned short)3;
    if ((int)instr == 1) {
      p->fts_info = fts_stat(sp, p, (_Bool)0);
      return (p);
    }

    if ((int)p->fts_info == 1) {

      if ((unsigned long)sp->fts_child != (unsigned long)((void *)0)) {
        tmp___3 = fts_safe_changedir(sp, p, -1, (char const *)p->fts_accpath);
        if (tmp___3) {
          tmp___2 = __errno_location();
          p->fts_errno = *tmp___2;
          p->fts_flags = (unsigned short)((int)p->fts_flags | 1);
          p = sp->fts_child;
          while (1) {

            if (!((unsigned long)p != (unsigned long)((void *)0))) {
              goto while_break___0;
            }
            p->fts_accpath = (p->fts_parent)->fts_accpath;
            p = p->fts_link;
          }
        while_break___0:;
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

    name:
      if ((int)*((p->fts_parent)->fts_path +
                 ((p->fts_parent)->fts_pathlen - 1UL)) == 47) {
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
      if ((int)p->fts_info == 11) {
        if (p->fts_statp[0].st_size == 2L) {
          parent = p->fts_parent;
          if (0L < p->fts_level) {

          } else {
          _L___4:
            p->fts_info = fts_stat(sp, p, (_Bool)0);
            if ((p->fts_statp[0].st_mode & 61440U) == 16384U) {
              if (p->fts_level != 0L) {
                if (parent->fts_n_dirs_remaining) {
                  (parent->fts_n_dirs_remaining)--;
                }
              }
            }
          }
        } else {

        while_break___2:;
        }
      }
      if ((int)p->fts_info == 1) {
        if (p->fts_level == 0L) {
          sp->fts_dev = p->fts_statp[0].st_dev;
        }
        tmp___16 = enter_dir(sp, p);
        if (!tmp___16) {
          tmp___15 = __errno_location();
          *tmp___15 = 12;
          return ((FTSENT *)((void *)0));
        }
      }
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

  while_break___3:
    *(sp->fts_path + p->fts_pathlen) = (char)'\000';

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
__attribute__((__nothrow__)) int(__attribute__((__leaf__)) fts_set)(
    FTS *sp __attribute__((__unused__)), FTSENT *p, int instr);

static void set_stat_type(struct stat *st, unsigned int dtype) {
  mode_t type;

  {

    goto switch_default;
  case_6:
    type = (mode_t)24576;
    goto switch_break;
  case_2:
    type = (mode_t)8192;
    goto switch_break;
  case_4:
    type = (mode_t)16384;
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
  case_12:
    type = (mode_t)49152;
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
  int dir_fd;
  int tmp___5;
  int *tmp___6;
  int tmp___7;
  char *tmp___8;
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
  int tmp___20;
  int tmp___21;
  int tmp___22;
  int tmp___23;
  int tmp___24;
  int tmp___25;
  int tmp___26;
  _Bool tmp___27;

  {
    cur = sp->fts_cur;

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
    }

    if (nlinks) {
      goto _L___0;
    } else {
      if (type == 3) {
      _L___0:
        tmp___5 = dirfd(dirp);
        dir_fd = tmp___5;

        if (dir_fd < 0) {
          goto _L;
        } else {
          tmp___7 =
              fts_safe_changedir(sp, cur, dir_fd, (char const *)((void *)0));
          if (tmp___7) {
          _L:

            cur->fts_flags = (unsigned short)((int)cur->fts_flags | 1);
            descend = (_Bool)0;
            closedir(dirp);

            dirp = (DIR *)((void *)0);
          } else {
            descend = (_Bool)1;
          }
        }
      } else {
        descend = (_Bool)0;
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
      if ((unsigned long)sp->fts_compar == (unsigned long)((void *)0) ||
          sp->fts_options & 1024) {

        skip_stat = (_Bool)tmp___17;
        p->fts_info = (unsigned short)11;
        set_stat_type(p->fts_statp, (unsigned int)dp->d_type);
        fts_set_stat_required(p, (_Bool)(!skip_stat));

        is_dir = (_Bool)tmp___18;
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);

        is_dir = (_Bool)tmp___19;
      }

      p->fts_link = (struct _ftsent *)((void *)0);
      if ((unsigned long)head == (unsigned long)((void *)0)) {
        tail = p;
        head = tail;
      } else {
        tail->fts_link = p;
        tail = p;
      }
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

    if (descend) {
      if (type == 1 || !nitems) {
        if (cur->fts_level == 0L) {
          fd_ring_clear(&sp->fts_fd_ring);

          tmp___26 = tmp___24;
        } else {
          tmp___25 = fts_safe_changedir(sp, cur->fts_parent, -1, "..");
          tmp___26 = tmp___25;
        }
        if (tmp___26) {
          cur->fts_info = (unsigned short)7;
          sp->fts_options |= 8192;
          fts_lfree(head);
          return ((FTSENT *)((void *)0));
        }
      }
    }

    return (head);
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;
  int saved_errno;
  int *tmp;
  int *tmp___0;
  int *tmp___1;
  int tmp___2;
  int tmp___3;
  int *tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {
    sbp = p->fts_statp;

    if ((sbp->st_mode & 61440U) == 16384U) {

      p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;
      if ((int)p->fts_name[0] == 46) {
      }
      return ((unsigned short)1);
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

    } else {
      tmp = &fts_compar;
    }
    compare = tmp;
    if (nitems > sp->fts_nitems) {
      sp->fts_nitems = nitems + 40UL;
      if (0xffffffffffffffffUL / sizeof(*a) < sp->fts_nitems) {
        free((void *)sp->fts_array);
        sp->fts_array = (struct _ftsent **)((void *)0);
        sp->fts_nitems = (size_t)0;
        return (head);
      } else {
        a = (FTSENT **)realloc((void *)sp->fts_array,
                               sp->fts_nitems * sizeof(*a));
        if (!a) {
          free((void *)sp->fts_array);
          sp->fts_array = (struct _ftsent **)((void *)0);
          sp->fts_nitems = (size_t)0;
          return (head);
        }
      }
      sp->fts_array = a;
    }
    ap = sp->fts_array;
    p = head;

  while_break:
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

  while_break:
    p = head;

  while_break___1:;
    return;
  }
}
static size_t fts_maxarglen(char *const *argv) {
  size_t len;
  size_t max;

  {
    max = (size_t)0;

  while_break:;
    return (max + 1UL);
  }
}
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir) {
  int ret;
  _Bool is_dotdot;
  int tmp;
  int tmp___0;
  int newfd;
  int parent_fd;
  _Bool tmp___1;
  struct stat sb;
  int tmp___2;
  int *tmp___3;
  int tmp___4;
  int oerrno;
  int *tmp___5;
  int *tmp___6;

  {

    is_dotdot = (_Bool)tmp___0;

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

    ret = fchdir(newfd);
  bail:

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
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2),
                                                       __leaf__)) fchownat)(
    int __fd, char const *__file, __uid_t __owner, __gid_t __group, int __flag);
__inline static int chownat(int fd, char const *file, uid_t owner,
                            gid_t group) {
  int tmp;

  {
    tmp = fchownat(fd, file, owner, group, 0);
    return (tmp);
  }
}
__inline static int lchownat(int fd, char const *file, uid_t owner,
                             gid_t group) {
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
extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid,
                         uid_t required_uid, gid_t required_gid,
                         struct Chown_option const *chopt);

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
  char
      buf___1[((((sizeof(intmax_t) * 8UL - 1UL) * 146UL) / 485UL + 1UL) + 1UL) +
              1UL];
  struct group *grp;
  struct group *tmp;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;

  {
    tmp = getgrgid(gid);
    grp = tmp;

    tmp___3 = xstrdup((char const *)tmp___2);
    return (tmp___3);
  }
}
extern char *uid_to_name(uid_t uid) {
  char
      buf___1[((((sizeof(intmax_t) * 8UL - 1UL) * 146UL) / 485UL + 1UL) + 1UL) +
              1UL];
  struct passwd *pwd;
  struct passwd *tmp;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;

  {
    tmp = getpwuid(uid);
    pwd = tmp;

    tmp___3 = xstrdup((char const *)tmp___2);
    return (tmp___3);
  }
}

static enum RCH_status restricted_chown(int cwd_fd, char const *file,
                                        struct stat const *orig_st, uid_t uid,
                                        gid_t gid, uid_t required_uid,
                                        gid_t required_gid) {
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

        return ((enum RCH_status)tmp___0);
      }
    }
    tmp___6 = fstat(fd, &st);
    if (tmp___6 != 0) {
      status = (enum RCH_status)6;
    } else {
      if (orig_st->st_ino == (__ino_t const)st.st_ino) {

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
static _Bool change_file_owner(FTS *fts, FTSENT *ent, uid_t uid, gid_t gid,
                               uid_t required_uid, gid_t required_gid,
                               struct Chown_option const *chopt) {
  char const *file_full_name;
  char const *file;
  struct stat const *file_stats;
  struct stat stat_buf;
  _Bool ok;
  _Bool do_chown;
  _Bool symlink_changed;
  char const *tmp;
  char *tmp___0;
  char const *tmp___1;
  char const *tmp___2;
  char *tmp___3;
  int tmp___4;
  char *tmp___5;
  FTSENT *tmp___6;
  char const *tmp___7;
  char *tmp___8;
  char const *tmp___9;
  char *tmp___10;
  char const *tmp___11;
  char *tmp___12;
  char const *tmp___13;
  char *tmp___14;
  _Bool tmp___15;
  char const *tmp___16;
  char *tmp___17;
  int *tmp___18;
  int tmp___19;
  int tmp___20;
  char const *tmp___21;
  char *tmp___22;
  char const *tmp___23;
  char const *tmp___24;
  char *tmp___25;
  int tmp___26;
  char *tmp___27;
  int tmp___28;
  int *tmp___29;
  enum RCH_status err;
  enum RCH_status tmp___30;
  int tmp___31;
  char const *tmp___32;
  char *tmp___33;
  char *tmp___34;
  char *tmp___35;
  int *tmp___36;
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
    if ((int)ent->fts_info == 10) {
      goto case_10;
    }

    if ((int)ent->fts_info == 4) {
      goto case_4;
    }
    if ((int)ent->fts_info == 2) {
      goto case_2;
    }
    goto switch_default;
  case_1:

    goto switch_break;
  case_6:
    if (!chopt->recurse) {
      return ((_Bool)1);
    }
    goto switch_break;
  case_10:

    ok = (_Bool)0;
    goto switch_break;
  case_7:

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
  case_2:
    tmp___15 = cycle_warning_required((FTS const *)fts, (FTSENT const *)ent);
    if (tmp___15) {

    while_break___0:;
      return ((_Bool)0);
    }
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

    if (do_chown) {
      if (!chopt->affect_symlink_referent) {
        tmp___28 = lchownat(fts->fts_cwd_fd, file, uid, gid);
        ok = (_Bool)(tmp___28 == 0);

      } else {
        tmp___30 = restricted_chown(fts->fts_cwd_fd, file, file_stats, uid, gid,
                                    required_uid, required_gid);
        err = tmp___30;

        if ((unsigned int)err == 5U) {
          goto case_5;
        }

        goto switch_default___0;
      case_2___0:
        goto switch_break___0;
      case_5:
        tmp___31 = chownat(fts->fts_cwd_fd, file, uid, gid);
        ok = (_Bool)(tmp___31 == 0);
        goto switch_break___0;
      case_6___0:
        ok = (_Bool)0;
        goto switch_break___0;
      case_4___0:
        do_chown = (_Bool)0;
        ok = (_Bool)0;
        goto switch_break___0;
      switch_default___0:
        abort();
      switch_break___0:;
      }
      if (do_chown) {
      }
    }

    if (!chopt->recurse) {
      fts_set(fts, ent, 4);
    }
    return (ok);
  }
}
extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid,
                         uid_t required_uid, gid_t required_gid,
                         struct Chown_option const *chopt) {
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
        }
      }
    }
    stat_flags = tmp;
    tmp___0 = xfts_open((char *const *)files, bit_flags | stat_flags,
                        (int (*)(FTSENT const **, FTSENT const **))((void *)0));
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
      tmp___4 = change_file_owner(fts, ent, uid, gid, required_uid,
                                  required_gid, chopt);
      ok = (_Bool)((int)ok & (int)tmp___4);
    }
  while_break:
    tmp___7 = fts_close(fts);

    return (ok);
  }
}
extern char *optarg;
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) atexit)(void (*__func)(void));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__leaf__)) textdomain)(char const *__domainname);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __leaf__)) bindtextdomain)(char const *__domainname, char const *__dirname);

static char *reference_file;
static struct option const long_options___1[14] = {
    {"recursive", 0, (int *)((void *)0), 'R'},
    {"changes", 0, (int *)((void *)0), 'c'},
    {"dereference", 0, (int *)((void *)0), 128},
    {"from", 1, (int *)((void *)0), 129},
    {"no-dereference", 0, (int *)((void *)0), 'h'},
    {"no-preserve-root", 0, (int *)((void *)0), 130},
    {"preserve-root", 0, (int *)((void *)0), 131},
    {"quiet", 0, (int *)((void *)0), 'f'},
    {"silent", 0, (int *)((void *)0), 'f'},
    {"reference", 1, (int *)((void *)0), 132},
    {"verbose", 0, (int *)((void *)0), 'v'},
    {"help", 0, (int *)((void *)0), -130},
    {"version", 0, (int *)((void *)0), -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
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
  char *tmp___1;
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
  char const *tmp___12;
  char *tmp___13;
  int *tmp___14;
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
      optc = getopt_long(argc, (char *const *)argv, "HLPRcfhv",
                         long_options___1, (int *)((void *)0));
      if (!(optc != -1)) {
        goto while_break;
      }

      goto switch_default;
    case_72:
      bit_flags = 17;
      goto switch_break;
    case_76:
      bit_flags = 2;
      goto switch_break;
    case_80:
      bit_flags = 16;
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
      tmp = parse_user_spec((char const *)optarg, &required_uid, &required_gid,
                            &u_dummy, &g_dummy);
      e = tmp;
      if (e) {
        tmp___0 = quote((char const *)optarg);
        error(1, 0, "%s: %s", e, tmp___0);
      }
      goto switch_break;
    case_82:
      chopt.recurse = (_Bool)1;
      goto switch_break;
    case_99:
      chopt.verbosity = (enum Verbosity)1;
      goto switch_break;
    case_102:
      chopt.force_silent = (_Bool)1;
      goto switch_break;
    case_118:
      chopt.verbosity = (enum Verbosity)0;
      goto switch_break;
    case_neg_130:
      usage(0);
      goto switch_break;
    case_neg_131:
      version_etc(stdout, "chown", "GNU coreutils", Version, "David MacKenzie",
                  "Jim Meyering", (char *)((void *)0));
      exit(0);
      goto switch_break;
    switch_default:
      usage(1);
    switch_break:;
    }
  while_break:;

    chopt.affect_symlink_referent = (_Bool)(dereference != 0);

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
      tmp___10 = parse_user_spec((char const *)*(argv + optind), &uid, &gid,
                                 &chopt.user_name, &chopt.group_name);
      e___0 = tmp___10;

      optind++;
    }

    bit_flags |= 1024;
    ok = chown_files(argv + optind, bit_flags, uid, gid, required_uid,
                     required_gid, (struct Chown_option const *)(&chopt));
    chopt_free(&chopt);
    if (ok) {
      tmp___15 = 0;
    } else {
      tmp___15 = 1;
    }
    exit(tmp___15);
  }
}
