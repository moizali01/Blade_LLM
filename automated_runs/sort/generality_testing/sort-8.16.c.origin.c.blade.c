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
typedef __uid_t uid_t;
struct stat {
  __dev_t st_dev;
  __ino_t st_ino;
  __nlink_t st_nlink;
  __mode_t st_mode;
  __uid_t st_uid;
  __gid_t st_gid;

  __dev_t st_rdev;
  __off_t st_size;
  __blksize_t st_blksize;
  __blkcnt_t st_blocks;

  struct timespec st_mtim;
  struct timespec st_ctim;
  __syscall_slong_t __glibc_reserved[3];
};
typedef __ino_t ino_t;
typedef __dev_t dev_t;
struct hash_tuning {
  float shrink_threshold;

  float growth_threshold;

  _Bool is_n_buckets;
};
typedef struct hash_tuning Hash_tuning;
struct hash_table;

struct hash_table;
typedef struct hash_table Hash_table;
typedef unsigned long uintmax_t;
typedef long __off64_t;
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

  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;

  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;

  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;

  void *__pad4;
  size_t __pad5;

  char _unused2[(15UL * sizeof(int) - 4UL * sizeof(void *)) - sizeof(size_t)];
};
typedef __off_t off_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;

struct allocator;

struct allocator {
  void *(*allocate)(size_t);
  void *(*reallocate)(void *, size_t);
  void (*free)(void *);
  void (*die)(size_t);
};
typedef long ptrdiff_t;
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

  int val;
};
typedef unsigned int uint32_t;
typedef int __pid_t;
typedef __pid_t pid_t;
typedef int wchar_t;
typedef int nl_item;
typedef unsigned int wint_t;
typedef long __suseconds_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
union __anonunion___value_23 {

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
struct __anonstruct___sigset_t_9 {};
typedef struct __anonstruct___sigset_t_9 __sigset_t;
typedef __sigset_t sigset_t;
struct timezone {};
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
};
struct Tokens {
  size_t n_tok;
  char **tok;
  size_t *tok_len;
  struct obstack o_data;
  struct obstack o_tok;
  struct obstack o_tok_len;
};

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
struct randread_source {
  FILE *source;
  void (*handler)(void const *);
  void const *handler_arg;
  union __anonunion_buf_30 buf;
};
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

  char *val;
};
struct mbuiter_multi {
  _Bool in_shift;
  mbstate_t state;
  _Bool next_done;
  struct mbchar cur;
};
typedef struct mbuiter_multi mbui_iterator_t;
enum nproc_query {
  NPROC_ALL = 0,
  NPROC_CURRENT = 1,
  NPROC_CURRENT_OVERRIDABLE = 2
};
typedef unsigned long __cpu_mask;
struct __anonstruct_cpu_set_t_24 {
  __cpu_mask __bits[1024UL / (8UL * sizeof(__cpu_mask))];
};
typedef struct __anonstruct_cpu_set_t_24 cpu_set_t;
struct md5_ctx {
  uint32_t A;
  uint32_t B;
  uint32_t C;
  uint32_t D;
  uint32_t total[2];
  uint32_t buflen;
  uint32_t buffer[32];
};
struct __pthread_internal_list {

  struct __pthread_internal_list *__next;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;

  short __spins;

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
struct lconv {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;

  char *positive_sign;

  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;

  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;

  char int_p_sep_by_space;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};
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
struct F_triple {
  char *name;

  dev_t st_dev;
};
typedef long __clock_t;
union sigval {
  int sival_int;
};
typedef union sigval sigval_t;
typedef __clock_t __sigchld_clock_t;
struct __anonstruct__kill_23 {
  __pid_t si_pid;
  __uid_t si_uid;
};
struct __anonstruct__timer_24 {

  int si_overrun;
  sigval_t si_sigval;
};
struct __anonstruct__rt_25 {
  __pid_t si_pid;

  sigval_t si_sigval;
};
struct __anonstruct__sigchld_26 {

  int si_status;

  __sigchld_clock_t si_stime;
};
struct __anonstruct__sigfault_27 {
  void *si_addr;
  short si_addr_lsb;
};
struct __anonstruct__sigpoll_28 {

  int si_fd;
};
struct __anonstruct__sigsys_29 {

  int _syscall;
  unsigned int _arch;
};
union __anonunion__sifields_22 {
  int _pad[128UL / sizeof(int) - 4UL];

  struct __anonstruct__timer_24 _timer;
  struct __anonstruct__rt_25 _rt;
  struct __anonstruct__sigchld_26 _sigchld;

  struct __anonstruct__sigpoll_28 _sigpoll;
  struct __anonstruct__sigsys_29 _sigsys;
};
struct __anonstruct_siginfo_t_21 {
  int si_signo;
  int si_errno;

  union __anonunion__sifields_22 _sifields;
};

struct sigaction {

  __sigset_t sa_mask;
  int sa_flags;
};
enum __anonenum_fadvice_t_19 {
  FADVISE_NORMAL = 0,
  FADVISE_SEQUENTIAL = 2,
  FADVISE_NOREUSE = 5,
  FADVISE_DONTNEED = 4,
  FADVISE_WILLNEED = 3,
  FADVISE_RANDOM = 1
};
typedef enum __anonenum_fadvice_t_19 fadvice_t;
typedef unsigned long __rlim_t;
typedef unsigned long pthread_t;
union pthread_attr_t {
  char __size[56];
  long __align;
};
typedef union pthread_attr_t pthread_attr_t;
struct __anonstruct___data_7 {
  int __lock;
  unsigned int __futex;

  unsigned long long __wakeup_seq;
  unsigned long long __woken_seq;
  void *__mutex;

  unsigned int __broadcast_seq;
};
union __anonunion_pthread_cond_t_6 {};
typedef union __anonunion_pthread_cond_t_6 pthread_cond_t;

typedef union __anonunion_pthread_condattr_t_8 pthread_condattr_t;
typedef void (*__sighandler_t)(int);
enum __rlimit_resource {
  RLIMIT_CPU = 0,
  RLIMIT_FSIZE = 1,
  RLIMIT_DATA = 2,
  RLIMIT_STACK = 3,
  RLIMIT_CORE = 4,
  __RLIMIT_RSS = 5,
  RLIMIT_NOFILE = 7,
  __RLIMIT_OFILE = 7,
  RLIMIT_AS = 9,
  __RLIMIT_NPROC = 6,
  __RLIMIT_MEMLOCK = 8,
  __RLIMIT_LOCKS = 10,
  __RLIMIT_SIGPENDING = 11,
  __RLIMIT_MSGQUEUE = 12,
  __RLIMIT_NICE = 13,
  __RLIMIT_RTPRIO = 14,
  __RLIMIT_RTTIME = 15,
  __RLIMIT_NLIMITS = 16,
  __RLIM_NLIMITS = 16
};
typedef __rlim_t rlim_t;
struct rlimit {
  rlim_t rlim_cur;
  rlim_t rlim_max;
};
typedef enum __rlimit_resource __rlimit_resource_t;
enum blanktype { bl_start = 0, bl_end = 1, bl_both = 2 };
struct line {
  char *text;
  size_t length;
  char *keybeg;
  char *keylim;
};
struct buffer {
  char *buf;
  size_t used;
  size_t nlines;
  size_t alloc;
  size_t left;

  _Bool eof;
};
struct keyfield {
  size_t sword;
  size_t schar;
  size_t eword;
  size_t echar;
  _Bool const *ignore;
  char const *translate;
  _Bool skipsblanks;
  _Bool skipeblanks;
  _Bool numeric;
  _Bool random;
  _Bool general_numeric;
  _Bool human_numeric;
  _Bool month;
  _Bool reverse;
  _Bool version;
  _Bool obsolete_used;
  struct keyfield *next;
};
struct month {
  char const *name;
  int val;
};
struct merge_node {
  struct line *lo;
  struct line *hi;
  struct line *end_lo;
  struct line *end_hi;
  struct line **dest;
  size_t nlo;
  size_t nhi;
  struct merge_node *parent;
  struct merge_node *lo_child;
  struct merge_node *hi_child;
  unsigned int level;
  _Bool queued;
  pthread_mutex_t lock;
};
struct merge_node_queue {
  struct heap *priority_queue;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
};

struct tempnode {
  struct tempnode *volatile next;
  pid_t pid;
  char state;
  char name[1];
};
struct sortfile {
  char const *name;
  struct tempnode *temp;
};
union __anonunion_101 {
  int __in;
};

struct thread_args {
  struct line *lines;
  size_t nthreads;
  size_t total_lines;
  struct merge_node *node;
  struct merge_node_queue *queue;
  FILE *tfp;
  char const *output_temp;
};
struct timespec dtotimespec(double sec);
struct timespec dtotimespec(double sec) {
  double min_representable;
  double max_representable;
  struct timespec r;
  time_t s;
  double frac;
  long ns;

  {
    min_representable =
        (double)(~(((1L << (sizeof(time_t) * 8UL - 2UL)) - 1L) * 2L + 1L));

    r.tv_sec = ~(((1L << (sizeof(time_t) * 8UL - 2UL)) - 1L) * 2L + 1L);
    r.tv_nsec = (__syscall_slong_t)0;
  }
}
__attribute__((__noreturn__)) void xalloc_die(void);

extern __attribute__((__nothrow__)) void *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    memcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    stat)(char const *__restrict __file, struct stat *__restrict __buf);
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__))
                                     fstat)(int __fd, struct stat *__buf);
extern int close(int __fd);
char const diacrit_base[256];
char const diacrit_diac[256];

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
Hash_table *(__attribute__((__warn_unused_result__))
             hash_initialize)(size_t candidate, Hash_tuning const *tuning,
                              size_t (*hasher)(void const *, size_t),
                              _Bool (*comparator)(void const *, void const *),
                              void (*data_freer)(void *));
void *(__attribute__((__warn_unused_result__))
       hash_insert)(Hash_table *table___0, void const *entry);
int hash_insert_if_absent(Hash_table *table___0, void const *entry,
                          void const **matched_ent);

extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((
    __leaf__)) __assert_fail)(char const *__assertion, char const *__file,
                              unsigned int __line, char const *__function);
int fd_safer(int fd);

char const *quote(char const *name);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           gettext)(char const *__msgid)
    __attribute__((__format_arg__(1)));

extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

int close_stream(FILE *stream);
int volatile exit_failure;
char *quotearg_colon(char const *arg);
static char const *file_name;
static _Bool ignore_EPIPE;
void close_stdout(void) {
  char const *write_error;

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
extern struct _IO_FILE *stdin;
int rpl_fflush(FILE *stream);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        ferror_unlocked)(FILE *__stream);
int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);
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

    tmp___1 = rpl_fclose(stream);

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
            }
            return (-1);
          }
        }
      }
    }
    return (0);
  }
}
int rpl_fcntl(int fd, int action, ...);
extern __attribute__((__nothrow__)) void *(
    __attribute__((__nonnull__(1), __leaf__))
    memchr)(void const *__s, int __c, size_t __n) __attribute__((__pure__));

extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__))
                                                       abort)(void);
struct allocator const stdlib_allocator;

extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1),
                                                          __leaf__))
                                           strchr)(char const *__s, int __c)
    __attribute__((__pure__));
size_t triple_hash(void const *x, size_t table_size) __attribute__((__pure__));

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1),
                                                          __leaf__))
                                           strdup)(char const *__s)
    __attribute__((__malloc__));
int c_tolower(int c) __attribute__((__const__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));

int c_strcasecmp(char const *s1, char const *s2) {
  register unsigned char const *p1;
  register unsigned char const *p2;
  unsigned char c1;
  unsigned char c2;

  {
    p1 = (unsigned char const *)s1;
    p2 = (unsigned char const *)s2;

    while (1) {
      c1 = (unsigned char)c_tolower((int)*p1);

      p1++;
      p2++;
    }
  while_break:;
    return ((int)c1 - (int)c2);
  }
}
_Bool c_isalnum(int c) __attribute__((__const__));

_Bool c_isdigit(int c) __attribute__((__const__));

_Bool c_isalnum(int c) __attribute__((__const__));
_Bool c_isalnum(int c) {
  int tmp;

  {
    if (c >= 48) {
      if (c <= 57) {
        tmp = 1;
      } else {
        goto _L;
      }
    } else {
    _L:
      if ((c & -33) >= 65) {
        if ((c & -33) <= 90) {

        } else {
        }
      } else {
        tmp = 0;
      }
    }
    return ((_Bool)tmp);
  }
}
_Bool c_isalpha(int c) __attribute__((__const__));
_Bool c_isalpha(int c) {
  int tmp;

  {
    if ((c & -33) >= 65) {
      if ((c & -33) <= 90) {
        tmp = 1;
      } else {
      }
    } else {
      tmp = 0;
    }
    return ((_Bool)tmp);
  }
}
_Bool c_isdigit(int c) __attribute__((__const__));
_Bool c_isdigit(int c) {
  int tmp;

  {
    if (c >= 48) {
      if (c <= 57) {
        tmp = 1;
      } else {
        tmp = 0;
      }
    } else {
      tmp = 0;
    }
    return ((_Bool)tmp);
  }
}

int c_tolower(int c) __attribute__((__const__));
int c_tolower(int c) {
  int tmp;

  { return (tmp); }
}
char *last_component(char const *name) __attribute__((__pure__));
char *last_component(char const *name) {
  char const *base;
  char const *p;
  _Bool saw_slash;

  {
    base = name + 0;
    saw_slash = (_Bool)0;

    if (!((int const) * base == 47)) {
      goto while_break;
    }
    base++;

  while_break:
    p = base;
    while (1) {

      p++;
    }
  while_break___0:;
    return ((char *)base);
  }
}
__inline static unsigned char to_uchar(char ch) {

  { return ((unsigned char)ch); }
}

void (*argmatch_die)(void);
ptrdiff_t __xargmatch_internal(char const *context, char const *arg,
                               char const *const *arglist, char const *vallist,
                               size_t valsize, void (*exit_fn)(void));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1),
                                                          __leaf__))
                                           getenv)(char const *__name);

extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcpy)(char *__restrict __dest, char const *__restrict __src);
char const *simple_backup_suffix = "~";
ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize)
    __attribute__((__pure__));
void argmatch_invalid(char const *context, char const *value,
                      ptrdiff_t problem);
void argmatch_valid(char const *const *arglist, char const *vallist,
                    size_t valsize);

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strncmp)(char const *__s1, char const *__s2, size_t __n)
    __attribute__((__pure__));
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char const *quote_n(int n, char const *name);

static void __argmatch_die(void) {

  { return; }
}

ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize)
    __attribute__((__pure__));
ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize) {
  size_t i;
  size_t arglen;
  ptrdiff_t matchind;
  _Bool ambiguous;
  int tmp;
  size_t tmp___0;
  int tmp___1;

  {
    matchind = (ptrdiff_t)-1;
    ambiguous = (_Bool)0;

    i = (size_t)0;

    if (!*(arglist + i)) {
      goto while_break;
    }
    tmp___1 = strncmp((char const *)*(arglist + i), arg, arglen);
    if (!tmp___1) {
      tmp___0 = strlen((char const *)*(arglist + i));
      if (tmp___0 == arglen) {
        return ((ptrdiff_t)i);
      } else {
        if (matchind == -1L) {
          matchind = (ptrdiff_t)i;
        } else {
          if ((unsigned long)vallist == (unsigned long)((void *)0)) {
            ambiguous = (_Bool)1;
          } else {
            tmp = memcmp((void const *)(vallist + valsize * (size_t)matchind),
                         (void const *)(vallist + valsize * i), valsize);
            if (tmp) {
              ambiguous = (_Bool)1;
            }
          }
        }
      }
    }

  while_break:;
    if (ambiguous) {

    } else {
      return (matchind);
    }
  }
}
void argmatch_invalid(char const *context, char const *value,
                      ptrdiff_t problem) {
  char const *format;
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char const *tmp___2;
  char *tmp___3;

  {

    tmp___1 = tmp;

    format = (char const *)tmp___1;
    tmp___2 = quote_n(1, context);
    tmp___3 = quotearg_n_style(0, (enum quoting_style)6, value);
    error(0, 0, format, tmp___3, tmp___2);
    return;
  }
}

extern
    __attribute__((__nothrow__)) void *(__attribute__((__warn_unused_result__,
                                                       __leaf__))
                                        realloc)(void *__ptr, size_t __size);
struct allocator const stdlib_allocator = {
    (void *(*)(size_t))(&malloc), (void *(*)(void *, size_t))(&realloc),
    (void (*)(void *))(&free), (void (*)(size_t))((void *)0)};
__inline static void *xnmalloc(size_t n, size_t s)
    __attribute__((__malloc__, __alloc_size__(1, 2)));
__inline static void *xnmalloc(size_t n, size_t s)
    __attribute__((__malloc__, __alloc_size__(1, 2)));
__inline static void *xnmalloc(size_t n, size_t s) {
  int tmp;
  void *tmp___0;

  {

    tmp = -2;

    if ((size_t)tmp / s < n) {
      xalloc_die();
    }
    tmp___0 = xmalloc(n * s);
    return (tmp___0);
  }
}
extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));

static strtol_error bkm_scale(uintmax_t *x, int scale_factor) {

  {

    *x = 0xffffffffffffffffUL;

    *x *= (uintmax_t)scale_factor;
    return ((strtol_error)0);
  }
}
static strtol_error bkm_scale_by_power(uintmax_t *x, int base, int power) {
  strtol_error err;
  strtol_error tmp;
  int tmp___0;

  {

    while (1) {
      tmp___0 = power;
      power--;
      if (!tmp___0) {
        goto while_break;
      }
      tmp = bkm_scale(x, base);
    }
  while_break:;
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

    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {
        if (*(*p)) {
          tmp___2 = strchr(valid_suffixes, (int)*(*p));

        } else {
          return ((strtol_error)4);
        }
      } else {
        return ((strtol_error)4);
      }
    } else {
      tmp___4 = __errno_location();
      if (*tmp___4 != 0) {
        tmp___3 = __errno_location();

        return ((strtol_error)4);
      }
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
      if (tmp___6) {
        if ((int)*(*(p + 0) + 1) == 105) {
          goto case_105;
        }
        if ((int)*(*(p + 0) + 1) == 66) {
          goto case_66;
        }
        if ((int)*(*(p + 0) + 1) == 68) {
          goto case_66;
        }
        goto switch_break;
      case_105:
        if ((int)*(*(p + 0) + 2) == 66) {
          suffixes += 2;
        }
        goto switch_break;
      case_66:
        base = 1000;
        suffixes++;
        goto switch_break;
      switch_break:;
      }
      if ((int)*(*p) == 98) {
        goto case_98;
      }
      if ((int)*(*p) == 66) {
        goto case_66___0;
      }
      if ((int)*(*p) == 99) {
        goto case_99;
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
      if ((int)*(*p) == 80) {
        goto case_80;
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
    case_98:
      overflow = bkm_scale(&tmp, 512);
      goto switch_break___0;
    case_66___0:
      overflow = bkm_scale(&tmp, 1024);
      goto switch_break___0;
    case_99:
      overflow = (strtol_error)0;
      goto switch_break___0;
    case_69:
      overflow = bkm_scale_by_power(&tmp, base, 6);
      goto switch_break___0;
    case_71:
      overflow = bkm_scale_by_power(&tmp, base, 3);
      goto switch_break___0;
    case_107:
      overflow = bkm_scale_by_power(&tmp, base, 1);
      goto switch_break___0;
    case_77:
      overflow = bkm_scale_by_power(&tmp, base, 2);
      goto switch_break___0;
    case_80:
      overflow = bkm_scale_by_power(&tmp, base, 5);
      goto switch_break___0;
    case_84:
      overflow = bkm_scale_by_power(&tmp, base, 4);
      goto switch_break___0;
    case_119:
      overflow = bkm_scale(&tmp, 2);
      goto switch_break___0;
    case_89:
      overflow = bkm_scale_by_power(&tmp, base, 8);
      goto switch_break___0;
    case_90:
      overflow = bkm_scale_by_power(&tmp, base, 7);
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

    return (err);
  }
}
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes);

static strtol_error bkm_scale___0(unsigned long *x, int scale_factor) {

  {

    *x *= (unsigned long)scale_factor;
    return ((strtol_error)0);
  }
}

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {

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
    if (0 <= strtol_base) {
      if (!(strtol_base <= 36)) {
        __assert_fail("0 <= strtol_base && strtol_base <= 36",
                      "/home/khheo/project/program-reduce/benchmark/"
                      "coreutils-8.16/lib/xstrtol.c",
                      96U, "xstrtoul");
      }
    } else {
    }

    q = s;
    ch = (unsigned char)*q;
    while (1) {

      q++;
      ch = (unsigned char)*q;
    }
  while_break:;

    tmp___1 = __errno_location();
    *tmp___1 = 0;

    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {
        if (*(*p)) {
          tmp___2 = strchr(valid_suffixes, (int)*(*p));
          if (tmp___2) {
            tmp = 1UL;
          } else {
            return ((strtol_error)4);
          }
        } else {
          return ((strtol_error)4);
        }
      } else {
        return ((strtol_error)4);
      }
    } else {
      tmp___4 = __errno_location();
      if (*tmp___4 != 0) {
        tmp___3 = __errno_location();
        if (*tmp___3 != 34) {
          return ((strtol_error)4);
        }
        err = (strtol_error)1;
      }
    }

    *val = tmp;

    suffixes = 1;
    tmp___5 = strchr(valid_suffixes, (int)*(*p));
    if (!tmp___5) {
    }
    tmp___6 = strchr(valid_suffixes, '0');
    if (tmp___6) {

      goto case_66;

      goto switch_break;
    case_105:
      if ((int)*(*(p + 0) + 2) == 66) {
        suffixes += 2;
      }
      goto switch_break;
    case_66:

      suffixes++;

    switch_break:;
    }

    if ((int)*(*p) == 99) {
      goto case_99;
    }

    if ((int)*(*p) == 77) {
    }

    goto case_80;

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

    overflow = bkm_scale___0(&tmp, 512);

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

  case_107:

  case_77:
    overflow = bkm_scale_by_power___0(&tmp, base, 2);

  case_80:
    overflow = bkm_scale_by_power___0(&tmp, base, 5);

  case_84:

  case_119:
    overflow = bkm_scale___0(&tmp, 2);
    goto switch_break___0;
  case_89:
    overflow = bkm_scale_by_power___0(&tmp, base, 8);
    goto switch_break___0;
  case_90:

    goto switch_break___0;

    *val = tmp;
    return ((strtol_error)((unsigned int)err | 2U));
  switch_break___0:
    err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
    *p += suffixes;
  }
}
extern
    __attribute__((__nothrow__)) long(__attribute__((__nonnull__(1), __leaf__))
                                      strtol)(char const *__restrict __nptr,
                                              char **__restrict __endptr,
                                              int __base);

static void xstrtol_error(enum strtol_error err, int opt_idx, char c,
                          struct option const *long_options___2,
                          char const *arg, int exit_status) {
  char const *hyphens;
  char const *msgid;
  char const *option;

  char *tmp;

  {
    hyphens = "--";
    if ((unsigned int)err == 4U) {
      goto case_4;
    }
    if ((unsigned int)err == 2U) {
      goto case_2;
    }

    if ((unsigned int)err == 1U) {
      goto case_1;
    }
    goto switch_default;
  switch_default:
    abort();
  case_4:

  case_2:

  case_1:
    msgid = "%s%s argument \'%s\' too large";

  switch_break:;

    tmp = gettext(msgid);
    error(exit_status, 0, (char const *)tmp, hyphens, option, arg);
    return;
  }
}

void xstrtol_fatal(enum strtol_error err, int opt_idx, char c,
                   struct option const *long_options___2, char const *arg) {

  {
    xstrtol_error(err, opt_idx, c, long_options___2, arg, (int)exit_failure);
    abort();
  }
}

int xnanosleep(double seconds);

char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg,
                           size_t argsize);
int xmemcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size);
static void collate_error(int collation_errno, char const *s1, size_t s1len,
                          char const *s2, size_t s2len) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;

  char *tmp___3;

  {
    tmp = gettext("string comparison failed");

    error(0, 0, (char const *)tmp___0);
    tmp___1 = quotearg_n_style_mem(1, (enum quoting_style)6, s2, s2len);

    tmp___3 = gettext("The strings compared were %s and %s.");

    return;
  }
}
int xmemcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {
  int diff;
  int tmp;
  int collation_errno;
  int *tmp___0;

  {
    tmp = memcoll0(s1, s1size, s2, s2size);
    diff = tmp;
    tmp___0 = __errno_location();
    collation_errno = *tmp___0;
    if (collation_errno) {
      collate_error(collation_errno, s1, s1size - 1UL, s2, s2size - 1UL);
    }
    return (diff);
  }
}

__inline static void *x2nrealloc(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {

    if (!p) {

    } else {
      if (0xaaaaaaaaaaaaaaaaUL / s <= n) {
        xalloc_die();
      }
      n += (n + 1UL) / 2UL;
    }

    tmp = xrealloc(p, n * s);
    return (tmp);
  }
}
extern
    __attribute__((__nothrow__)) void *(__attribute__((__leaf__))
                                        calloc)(size_t __nmemb, size_t __size)
        __attribute__((__malloc__));
extern
    __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1),
                                                       __leaf__))
                                        memset)(void *__s, int __c, size_t __n);

void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    tmp = malloc(n);
    p = tmp;

    return (p);
  }
}
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
void *xrealloc(void *p, size_t n) {

  { return (p); }
}

void *xcalloc(size_t n, size_t s) {
  void *p;

  {
    p = calloc(n, s);
    if (!p) {
      xalloc_die();
    }
    return (p);
  }
}
void *xmemdup(void const *p, size_t s)
    __attribute__((__malloc__, __alloc_size__(2)));
void *xmemdup(void const *p, size_t s) {
  void *tmp;
  void *tmp___0;

  {
    tmp = xmalloc(s);
    tmp___0 = memcpy(tmp, p, s);
    return (tmp___0);
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
void version_etc_arn(FILE *stream, char const *command_name,
                     char const *package, char const *version,
                     char const *const *authors, size_t n_authors);
void version_etc_va(FILE *stream, char const *command_name, char const *package,
                    char const *version, va_list authors);
void version_etc(FILE *stream, char const *command_name, char const *package,
                 char const *version, ...) __attribute__((__sentinel__));
void version_etc_arn(FILE *stream, char const *command_name,
                     char const *package, char const *version,
                     char const *const *authors, size_t n_authors) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;

  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  char *tmp___10;

  {

    fprintf(stream, "%s %s\n", package, version);

    tmp = gettext("(C)");
    fprintf(stream, version_etc_copyright, tmp, 2012);
    tmp___0 =
        gettext("\nLicense GPLv3+: GNU GPL version 3 or later "
                "<http://gnu.org/licenses/gpl.html>.\nThis is free software: "
                "you are free to change and redistribute it.\nThere is NO "
                "WARRANTY, to the extent permitted by law.\n\n");
    fputs_unlocked((char const *)tmp___0, stream);

    if (n_authors == 1UL) {
      goto case_1;
    }

    goto case_3;

    goto case_8;

    if (n_authors == 9UL) {
    }

  case_0:

  case_1:

    goto switch_break;
  case_2:
    tmp___2 = gettext("Written by %s and %s.\n");

    goto switch_break;
  case_3:

    fprintf(stream, (char const *)tmp___3, *(authors + 0), *(authors + 1),
            *(authors + 2));
    goto switch_break;
  case_4:

  case_5:
    tmp___5 = gettext("Written by %s, %s, %s,\n%s, and %s.\n");

  case_6:

    fprintf(stream, (char const *)tmp___6, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5));
    goto switch_break;
  case_7:

    fprintf(stream, (char const *)tmp___7, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6));

  case_8:

  case_9:
    tmp___9 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, and %s.\n");
    fprintf(stream, (char const *)tmp___9, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6), *(authors + 7), *(authors + 8));

    tmp___10 = gettext(
        "Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, %s, and others.\n");
    fprintf(stream, (char const *)tmp___10, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6), *(authors + 7), *(authors + 8));

  switch_break:;
    return;
  }
}
void version_etc_va(FILE *stream, char const *command_name, char const *package,
                    char const *version, va_list authors) {
  size_t n_authors;
  char const *authtab[10];

  {

    while (1) {

      n_authors++;
    }
  while_break:
    version_etc_arn(stream, command_name, package, version,
                    (char const *const *)(authtab), n_authors);
    return;
  }
}

void version_etc(FILE *stream, char const *command_name, char const *package,
                 char const *version, ...) {
  va_list authors;

  {
    __builtin_va_start(authors, version);
    version_etc_va(stream, command_name, package, version, authors);
    __builtin_va_end(authors);
  }
}
char const version_etc_copyright[47] = {
    (char const)'C', (char const)'o', (char const)'p',   (char const)'y',
    (char const)'r', (char const)'i', (char const)'g',   (char const)'h',
    (char const)'t', (char const)' ', (char const)'%',   (char const)'s',
    (char const)' ', (char const)'%', (char const)'d',   (char const)' ',
    (char const)'F', (char const)'r', (char const)'e',   (char const)'e',
    (char const)' ', (char const)'S', (char const)'o',   (char const)'f',
    (char const)'t', (char const)'w', (char const)'a',   (char const)'r',
    (char const)'e', (char const)' ', (char const)'F',   (char const)'o',
    (char const)'u', (char const)'n', (char const)'d',   (char const)'a',
    (char const)'t', (char const)'i', (char const)'o',   (char const)'n',
    (char const)',', (char const)' ', (char const)'I',   (char const)'n',
    (char const)'c', (char const)'.', (char const)'\000'};

char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1);

#pragma GCC diagnostic ignored "-Wtype-limits"
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1) {
  char *p;

  {

    if (i < 0UL) {
      while (1) {
        p--;
        *p = (char)(48UL - i % 10UL);
        i /= 10UL;
      }
    while_break:

      *p = (char)'-';
    } else {
      while (1) {

        *p = (char)(48UL + i % 10UL);
        i /= 10UL;

        goto while_break___0;
      }
    while_break___0:;
    }
    return (p);
  }
}
#pragma GCC diagnostic ignored "-Wtype-limits"
char *(__attribute__((__warn_unused_result__)) uinttostr)(unsigned int i,
                                                          char *buf___1);
char *(__attribute__((__warn_unused_result__)) uinttostr)(unsigned int i,
                                                          char *buf___1) {
  char *p;

  {
    p = buf___1 + ((sizeof(unsigned int) * 8UL) * 146UL + 484UL) / 485UL;
    *p = (char)0;
    if (i < 0U) {
      while (1) {
        p--;

        if (!(i != 0U)) {
        }
      }
    while_break:
      p--;

    } else {
      while (1) {

        *p = (char)(48U + i % 10U);
        i /= 10U;
        if (!(i != 0U)) {
        }
      }
    while_break___0:;
    }
    return (p);
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        mbsinit)(mbstate_t const *__ps)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__))
       mbrtowc)(wchar_t *__restrict __pwc, char const *__restrict __s,
                size_t __n, mbstate_t *__restrict __p);

#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag, ...);
int __attribute__((__pure__))
strnumcmp(char const *a, char const *b, int decimal_point___0,
          int thousands_sep___0);
__inline static int __attribute__((__pure__))
fraccompare(char const *a, char const *b, char decimal_point___0) {
  char const *tmp;
  char const *tmp___0;

  {
    if ((int const) * a == (int const)decimal_point___0) {

    } else {
    _L:
      tmp___0 = a;
      a++;
      if ((int const) * tmp___0 == (int const)decimal_point___0) {

        while (1) {

          if (!((int const) * a == 48)) {
            goto while_break___0;
          }
        }
      while_break___0:;
        return ((int __attribute__((__pure__)))((unsigned int)*a - 48U <= 9U));
      } else {
        tmp = b;
        b++;
      }
    }
  }
}
__inline static int __attribute__((__pure__))
numcompare(char const *a, char const *b, int decimal_point___0,
           int thousands_sep___0) {
  unsigned char tmpa;
  unsigned char tmpb;
  int tmp;
  size_t log_a;
  size_t log_b;
  int __attribute__((__pure__)) tmp___0;
  int tmp___1;
  int __attribute__((__pure__)) tmp___2;
  int tmp___3;

  {
    tmpa = (unsigned char)*a;
    tmpb = (unsigned char)*b;
    if ((int)tmpa == 45) {

      a++;
      tmpa = (unsigned char)*a;
      if (!((int)tmpa == 48)) {
      }

    while_break:;
      if ((int)tmpb != 45) {
        if ((int)tmpa == decimal_point___0) {
          while (1) {
            a++;
            tmpa = (unsigned char)*a;
            if (!((int)tmpa == 48)) {
              goto while_break___0;
            }
          }
        while_break___0:;
        }
        if ((unsigned int)tmpa - 48U <= 9U) {
          return ((int __attribute__((__pure__))) - 1);
        }
        while (1) {

          if (!((int)tmpb == 48)) {
            if (!((int)tmpb == thousands_sep___0)) {
              goto while_break___1;
            }
          }
          b++;
          tmpb = (unsigned char)*b;
        }
      while_break___1:;
        if ((int)tmpb == decimal_point___0) {
          while (1) {
            b++;
            tmpb = (unsigned char)*b;
            if (!((int)tmpb == 48)) {
              goto while_break___2;
            }
          }
        while_break___2:;
        }
        return (
            (int __attribute__((__pure__)))(-((unsigned int)tmpb - 48U <= 9U)));
      }

      b++;
      tmpb = (unsigned char)*b;
      if (!((int)tmpb == 48)) {
        if (!((int)tmpb == thousands_sep___0)) {
        }
      }

    while_break___3:;
      while (1) {

        if ((int)tmpa == (int)tmpb) {
          if (!((unsigned int)tmpa - 48U <= 9U)) {
          }
        } else {
          goto while_break___4;
        }
        while (1) {
          a++;
          tmpa = (unsigned char)*a;
          if (!((int)tmpa == thousands_sep___0)) {
            goto while_break___5;
          }
        }
      while_break___5:;
        while (1) {
          b++;
          tmpb = (unsigned char)*b;

          goto while_break___6;
        }
      while_break___6:;
      }
    while_break___4:;
      if ((int)tmpa == decimal_point___0) {
        if (!((unsigned int)tmpb - 48U <= 9U)) {
          tmp___0 = fraccompare(b, a, (char)decimal_point___0);
          return (tmp___0);
        } else {
          goto _L;
        }
      } else {
      _L:
        if ((int)tmpb == decimal_point___0) {
          if (!((unsigned int)tmpa - 48U <= 9U)) {
            tmp___0 = fraccompare(b, a, (char)decimal_point___0);
            return (tmp___0);
          }
        }
      }
      tmp = (int)tmpb - (int)tmpa;
      log_a = (size_t)0;
      while (1) {

        if (!((unsigned int)tmpa - 48U <= 9U)) {
          goto while_break___7;
        }

        a++;
        tmpa = (unsigned char)*a;

        goto while_break___8;

      while_break___8:
        log_a++;
      }
    while_break___7:
      log_b = (size_t)0;
      while (1) {

        if (!((unsigned int)tmpb - 48U <= 9U)) {
          goto while_break___9;
        }
        while (1) {
          b++;
          tmpb = (unsigned char)*b;
          if (!((int)tmpb == thousands_sep___0)) {
            goto while_break___10;
          }
        }
      while_break___10:
        log_b++;
      }
    while_break___9:;
      if (log_a != log_b) {
        if (log_a < log_b) {
          tmp___1 = 1;
        } else {
          tmp___1 = -1;
        }
        return ((int __attribute__((__pure__)))tmp___1);
      }
      if (!log_a) {
        return ((int __attribute__((__pure__)))0);
      }
      return ((int __attribute__((__pure__)))tmp);
    } else {
      if ((int)tmpb == 45) {
        while (1) {
          b++;
          tmpb = (unsigned char)*b;

          if (!((int)tmpb == thousands_sep___0)) {
            goto while_break___11;
          }
        }
      while_break___11:;

        while (1) {

          if (!((int)tmpa == 48)) {
            if (!((int)tmpa == thousands_sep___0)) {
              goto while_break___13;
            }
          }
          a++;
          tmpa = (unsigned char)*a;
        }
      while_break___13:;
        if ((int)tmpa == decimal_point___0) {
          while (1) {
            a++;

            if (!((int)tmpa == 48)) {
              goto while_break___14;
            }
          }
        while_break___14:;
        }
        return (
            (int __attribute__((__pure__)))((unsigned int)tmpa - 48U <= 9U));
      } else {
        while (1) {

          if (!((int)tmpa == 48)) {
            if (!((int)tmpa == thousands_sep___0)) {
              goto while_break___15;
            }
          }
          a++;
        }
      while_break___15:;
        while (1) {

          if (!((int)tmpb == 48)) {
            if (!((int)tmpb == thousands_sep___0)) {
              goto while_break___16;
            }
          }
          b++;
          tmpb = (unsigned char)*b;
        }
      while_break___16:;

        ;
        if ((int)tmpa == decimal_point___0) {

          tmp___2 = fraccompare(a, b, (char)decimal_point___0);

          goto _L___0;

        } else {
        _L___0:
          if ((int)tmpb == decimal_point___0) {
            if (!((unsigned int)tmpa - 48U <= 9U)) {

              return (tmp___2);
            }
          }
        }
        tmp = (int)tmpa - (int)tmpb;
        log_a = (size_t)0;
        while (1) {

          if (!((unsigned int)tmpa - 48U <= 9U)) {
            goto while_break___20;
          }
          while (1) {
            a++;
            tmpa = (unsigned char)*a;
            if (!((int)tmpa == thousands_sep___0)) {
              goto while_break___21;
            }
          }
        while_break___21:
          log_a++;
        }
      while_break___20:
        log_b = (size_t)0;
        while (1) {

          if (!((unsigned int)tmpb - 48U <= 9U)) {
            goto while_break___22;
          }
          while (1) {
            b++;
            tmpb = (unsigned char)*b;

            goto while_break___23;
          }
        while_break___23:
          log_b++;
        }
      while_break___22:;
        if (log_a != log_b) {

          return ((int __attribute__((__pure__)))tmp___3);
        }

        return ((int __attribute__((__pure__)))tmp);
      }
    }
  }
}
int __attribute__((__pure__))
strnumcmp(char const *a, char const *b, int decimal_point___0,
          int thousands_sep___0) {
  int __attribute__((__pure__)) tmp;

  {
    tmp = numcompare(a, b, decimal_point___0, thousands_sep___0);
    return (tmp);
  }
}

size_t strnlen1(char const *string, size_t maxlen) __attribute__((__pure__));
size_t strnlen1(char const *string, size_t maxlen) {
  char const *end;
  char const *tmp;

  {

    end = tmp;
    if ((unsigned long)end != (unsigned long)((void *)0)) {

    } else {
      return (maxlen);
    }
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        tolower)(int __c);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) sigprocmask)(
    int __how, sigset_t const *__restrict __set, sigset_t *__restrict __oset);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        feof_unlocked)(FILE *__stream);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        raise)(int __sig);
extern __attribute__((__nothrow__)) __pid_t fork(void);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);

extern int fgetc(FILE *__stream);
extern void _obstack_newchunk(struct obstack *, int);
extern int _obstack_begin(struct obstack *, int, int, void *(*)(long),
                          void (*)(void *));
void readtokens0_init(struct Tokens *t);
_Bool readtokens0(FILE *in, struct Tokens *t);
void readtokens0_init(struct Tokens *t) {

  {
    t->n_tok = (size_t)0;
    t->tok = (char **)((void *)0);
    t->tok_len = (size_t *)((void *)0);

    _obstack_begin(&t->o_tok, 0, 0, (void *(*)(long))(&malloc),
                   (void (*)(void *))(&free));

    return;
  }
}
static void save_token(struct Tokens *t) {
  size_t len;
  struct obstack const *__o;
  char const *s;
  struct obstack *__o1;
  void *__value;
  char *tmp;
  char *tmp___0;
  struct obstack *__o___0;
  struct obstack *__o1___0;
  struct obstack *__o___1;
  int __len;

  {

    len = (size_t)((unsigned int)(__o->next_free - __o->object_base) - 1U);
    __o1 = &t->o_data;
    __value = (void *)__o1->object_base;
    if ((unsigned long)__o1->next_free == (unsigned long)__value) {
      __o1->maybe_empty_object = 1U;
    }
    if (sizeof(long) < sizeof(void *)) {

    } else {
    }

    __o1->next_free =
        tmp + (((__o1->next_free - tmp___0) + (long)__o1->alignment_mask) &
               (long)(~__o1->alignment_mask));
    if (__o1->next_free - (char *)__o1->chunk >
        __o1->chunk_limit - (char *)__o1->chunk) {
      __o1->next_free = __o1->chunk_limit;
    }
    __o1->object_base = __o1->next_free;
    s = (char const *)__value;

    if ((unsigned long)(__o___0->next_free + sizeof(void *)) >
        (unsigned long)__o___0->chunk_limit) {
      _obstack_newchunk(__o___0, (int)sizeof(void *));
    }
    __o1___0 = __o___0;
    *((void const **)__o1___0->next_free) = (void const *)s;
    __o1___0->next_free += sizeof(void const *);

    __len = (int)sizeof(len);
    if ((unsigned long)(__o___1->next_free + __len) >
        (unsigned long)__o___1->chunk_limit) {
      _obstack_newchunk(__o___1, __len);
    }

    __o___1->next_free += __len;
  }
}
_Bool readtokens0(FILE *in, struct Tokens *t) {
  int c;
  int tmp;
  size_t len;
  struct obstack const *__o;
  struct obstack *__o___0;
  char *tmp___0;
  struct obstack *__o___1;
  char *tmp___1;
  struct obstack *__o___2;
  struct obstack *__o1;
  struct obstack *__o1___0;
  void *__value;
  char *tmp___2;
  char *tmp___3;
  struct obstack *__o1___1;
  void *__value___0;
  char *tmp___4;
  char *tmp___5;
  int tmp___6;
  int tmp___7;

  {
    while (1) {

      c = tmp;

      if (len) {
        __o___0 = &t->o_data;

        _obstack_newchunk(__o___0, 1);

        tmp___0 = __o___0->next_free;
        (__o___0->next_free)++;
      }
      goto while_break;

      __o___1 = &t->o_data;
      if ((unsigned long)(__o___1->next_free + 1) >
          (unsigned long)__o___1->chunk_limit) {
        _obstack_newchunk(__o___1, 1);
      }

      *tmp___1 = (char)c;

      save_token(t);
    }
  while_break:

    if ((unsigned long)(__o___2->next_free + sizeof(void *)) >
        (unsigned long)__o___2->chunk_limit) {
      _obstack_newchunk(__o___2, (int)sizeof(void *));
    }
    __o1 = __o___2;
    *((void const **)__o1->next_free) = (void const *)((void *)0);
    __o1->next_free += sizeof(void const *);

    __value = (void *)__o1___0->object_base;
    if ((unsigned long)__o1___0->next_free == (unsigned long)__value) {
      __o1___0->maybe_empty_object = 1U;
    }

    __o1___0->next_free =
        tmp___2 +
        (((__o1___0->next_free - tmp___3) + (long)__o1___0->alignment_mask) &
         (long)(~__o1___0->alignment_mask));
    if (__o1___0->next_free - (char *)__o1___0->chunk >
        __o1___0->chunk_limit - (char *)__o1___0->chunk) {
      __o1___0->next_free = __o1___0->chunk_limit;
    }
    __o1___0->object_base = __o1___0->next_free;

    __value___0 = (void *)__o1___1->object_base;
    if ((unsigned long)__o1___1->next_free == (unsigned long)__value___0) {
      __o1___1->maybe_empty_object = 1U;
    }

    if (sizeof(long) < sizeof(void *)) {
      tmp___5 = __o1___1->object_base;
    } else {
    }
    __o1___1->next_free =
        tmp___4 +
        (((__o1___1->next_free - tmp___5) + (long)__o1___1->alignment_mask) &
         (long)(~__o1___1->alignment_mask));

    __o1___1->next_free = __o1___1->chunk_limit;

    __o1___1->object_base = __o1___1->next_free;

    tmp___6 = ferror(in);
    if (tmp___6) {
      tmp___7 = 0;
    } else {
    }
    return ((_Bool)tmp___7);
  }
}
extern int getc_unlocked(FILE *__stream);

void randread(struct randread_source *s, void *buf___1, size_t size);
int randread_free(struct randread_source *s);

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__))
    gettimeofday)(struct timeval *__restrict __tv, __timezone_ptr_t __tz);

extern __attribute__((__nothrow__))
__pid_t(__attribute__((__leaf__)) getppid)(void);

void isaac_seed(struct isaac_state *s);
void isaac_refill(struct isaac_state *s, isaac_word *result);
FILE *fopen_safer(char const *file, char const *mode);
static void randread_error(void const *file_name___3) {

  char const *tmp___1;
  int *tmp___2;

  { abort(); }
}
static struct randread_source *simple_new(FILE *source,
                                          void const *handler_arg) {
  struct randread_source *s;
  struct randread_source *tmp;

  {

    s = tmp;

    s->handler = &randread_error;
    s->handler_arg = handler_arg;
    return (s);
  }
}
static void get_nonce(void *buffer, size_t bufsize___1, size_t bytes_bound) {
  char *buf___1;
  ssize_t seeded;
  int fd;
  int tmp;
  size_t tmp___0;
  struct timeval v;
  size_t nbytes;
  unsigned long tmp___1;
  pid_t v___0;
  size_t nbytes___0;
  unsigned long tmp___2;
  pid_t v___1;
  size_t nbytes___1;
  unsigned long tmp___3;

  size_t nbytes___2;
  unsigned long tmp___4;
  uid_t v___3;
  size_t nbytes___3;
  unsigned long tmp___5;

  {

    if ((size_t)seeded < bufsize___1) {

      nbytes___0 = tmp___2;
      v___0 = getpid();
      memcpy((void *)(buf___1 + seeded), (void const *)(&v___0), nbytes___0);
      seeded = (ssize_t)((size_t)seeded + nbytes___0);
    }

    nbytes___1 = tmp___3;
    v___1 = getppid();
    memcpy((void *)(buf___1 + seeded), (void const *)(&v___1), nbytes___1);
    seeded = (ssize_t)((size_t)seeded + nbytes___1);

    return;
  }
}
struct randread_source *randread_new(char const *name, size_t bytes_bound) {
  struct randread_source *tmp;
  FILE *source;
  struct randread_source *s;
  unsigned long tmp___0;

  {
    if (bytes_bound == 0UL) {
      tmp = simple_new((FILE *)((void *)0), (void const *)((void *)0));
      return (tmp);
    } else {
      source = (FILE *)((void *)0);
      if (name) {
        source = fopen_safer(name, "rb");
        if (!source) {
          return ((struct randread_source *)((void *)0));
        }
      }
      s = simple_new(source, (void const *)name);
      if (source) {
        if (sizeof(s->buf.c) < bytes_bound) {
          tmp___0 = sizeof(s->buf.c);
        } else {
          tmp___0 = bytes_bound;
        }
        setvbuf(source, s->buf.c, 0, tmp___0);
      } else {
        s->buf.isaac.buffered = (size_t)0;
        get_nonce((void *)(s->buf.isaac.state.m), sizeof(s->buf.isaac.state.m),
                  bytes_bound);
        isaac_seed(&s->buf.isaac.state);
      }
      return (s);
    }
  }
}

static void readisaac(struct isaac *isaac, unsigned char *p, size_t size) {
  size_t inbytes;
  isaac_word *wp;

  {
    inbytes = isaac->buffered;
    while (1) {

      memcpy((void *)p,
             (void const *)((isaac->data.b +
                             (unsigned long)(1 << 8) * sizeof(isaac_word)) -
                            inbytes),
             inbytes);

    while_break___0:
      p = (unsigned char *)wp;
      isaac_refill(&isaac->state, isaac->data.w);
      inbytes = (unsigned long)(1 << 8) * sizeof(isaac_word);
    }

    return;
  }
}
void randread(struct randread_source *s, void *buf___1, size_t size) {

  { return; }
}
int randread_free(struct randread_source *s) {
  FILE *source;
  int tmp;
  int tmp___0;

  {
    source = s->source;
    memset((void *)s, 0, sizeof(*s));
    free((void *)s);
    if (source) {
      tmp = rpl_fclose(source);
      tmp___0 = tmp;
    } else {
      tmp___0 = 0;
    }
    return (tmp___0);
  }
}

__inline static isaac_word just(isaac_word a) {
  isaac_word desired_bits;

  {
    desired_bits = ((1UL << 1) << ((1 << 6) - 1)) - 1UL;
    return (a & desired_bits);
  }
}
__inline static isaac_word ind(isaac_word const *m, isaac_word x) {
  isaac_word tmp;

  { return (tmp); }
}
void isaac_refill(struct isaac_state *s, isaac_word *result) {
  isaac_word a;
  isaac_word b;
  isaac_word *m;
  isaac_word *r;
  isaac_word x;
  isaac_word y;
  isaac_word tmp;
  isaac_word tmp___0;
  isaac_word tmp___1;
  isaac_word tmp___2;
  isaac_word x___0;
  isaac_word y___0;
  isaac_word tmp___3;
  isaac_word tmp___4;
  isaac_word tmp___5;
  isaac_word tmp___6;
  isaac_word tmp___7;
  isaac_word tmp___8;
  isaac_word x___1;
  isaac_word y___1;
  isaac_word tmp___9;
  isaac_word tmp___10;
  isaac_word tmp___11;
  isaac_word tmp___12;
  isaac_word x___2;
  isaac_word y___2;
  isaac_word tmp___13;
  isaac_word tmp___14;

  isaac_word tmp___16;
  isaac_word tmp___17;
  isaac_word tmp___18;
  isaac_word x___3;
  isaac_word y___3;
  isaac_word tmp___19;
  isaac_word tmp___20;
  isaac_word tmp___21;
  isaac_word tmp___22;
  isaac_word x___4;
  isaac_word y___4;
  isaac_word tmp___23;

  isaac_word tmp___26;
  isaac_word tmp___27;
  isaac_word tmp___28;
  isaac_word x___5;
  isaac_word y___5;
  isaac_word tmp___29;
  isaac_word tmp___30;
  isaac_word tmp___31;
  isaac_word tmp___32;
  isaac_word x___6;
  isaac_word y___6;
  isaac_word tmp___33;
  isaac_word tmp___34;

  isaac_word tmp___36;
  isaac_word tmp___37;
  isaac_word tmp___38;

  {
    a = s->a;
    (s->c)++;
    b = s->b + s->c;

    r = result;

    if (1 << 6 == 32) {

    } else {
      tmp = (isaac_word)0;
    }

    a = (tmp ^ tmp___0) + *(m + 128);
    x = *(m + 0);
    tmp___1 = ind((isaac_word const *)(s->m), x);
    y = (tmp___1 + a) + b;
    *(m + 0) = y;
    tmp___2 = ind((isaac_word const *)(s->m), y >> 8);
    b = just(tmp___2 + x);
    *(r + 0) = b;

    if (1 << 6 == 32) {
      tmp___4 = just(a);
      tmp___6 = tmp___4 >> 6;
    } else {
      tmp___5 = just(a);
    }
    a = (tmp___3 ^ tmp___6) + *(m + 129);
    x___0 = *(m + 1);
    tmp___7 = ind((isaac_word const *)(s->m), x___0);
    y___0 = (tmp___7 + a) + b;
    *(m + 1) = y___0;
    tmp___8 = ind((isaac_word const *)(s->m), y___0 >> 8);
    b = just(tmp___8 + x___0);
    *(r + 1) = b;
    if (1 << 6 == 32) {

    } else {
      tmp___9 = (isaac_word)0;
    }

    a = (tmp___9 ^ tmp___10) + *(m + 130);
    x___1 = *(m + 2);
    tmp___11 = ind((isaac_word const *)(s->m), x___1);
    y___1 = (tmp___11 + a) + b;
    *(m + 2) = y___1;
    tmp___12 = ind((isaac_word const *)(s->m), y___1 >> 8);
    b = just(tmp___12 + x___1);
    *(r + 2) = b;

    a = (tmp___13 ^ tmp___16) + *(m + 131);
    x___2 = *(m + 3);
    tmp___17 = ind((isaac_word const *)(s->m), x___2);
    y___2 = (tmp___17 + a) + b;
    *(m + 3) = y___2;
    tmp___18 = ind((isaac_word const *)(s->m), y___2 >> 8);
    b = just(tmp___18 + x___2);
    *(r + 3) = b;
    r += 4;
    m += 4;
    if (!((unsigned long)m < (unsigned long)(s->m + 128))) {
      goto while_break;
    }

  while_break:;
    while (1) {

      tmp___20 = a << 13;

      tmp___20 = ~(a ^ (a << 21));

      a = (tmp___19 ^ tmp___20) + *(m + -128);
      x___3 = *(m + 0);
      tmp___21 = ind((isaac_word const *)(s->m), x___3);
      y___3 = (tmp___21 + a) + b;
      *(m + 0) = y___3;
      tmp___22 = ind((isaac_word const *)(s->m), y___3 >> 8);
      b = just(tmp___22 + x___3);
      *(r + 0) = b;

      tmp___23 = a;

      a = (tmp___23 ^ tmp___26) + *(m + -127);
      x___4 = *(m + 1);
      tmp___27 = ind((isaac_word const *)(s->m), x___4);
      y___4 = (tmp___27 + a) + b;
      *(m + 1) = y___4;
      tmp___28 = ind((isaac_word const *)(s->m), y___4 >> 8);
      b = just(tmp___28 + x___4);
      *(r + 1) = b;
      if (1 << 6 == 32) {
        tmp___29 = a;
      } else {
        tmp___29 = (isaac_word)0;
      }

      a = (tmp___29 ^ tmp___30) + *(m + -126);
      x___5 = *(m + 2);
      tmp___31 = ind((isaac_word const *)(s->m), x___5);
      y___5 = (tmp___31 + a) + b;
      *(m + 2) = y___5;
      tmp___32 = ind((isaac_word const *)(s->m), y___5 >> 8);
      b = just(tmp___32 + x___5);
      *(r + 2) = b;

      if (1 << 6 == 32) {
        tmp___34 = just(a);
        tmp___36 = tmp___34 >> 16;
      } else {
      }
      a = (tmp___33 ^ tmp___36) + *(m + -125);
      x___6 = *(m + 3);
      tmp___37 = ind((isaac_word const *)(s->m), x___6);
      y___6 = (tmp___37 + a) + b;
      *(m + 3) = y___6;
      tmp___38 = ind((isaac_word const *)(s->m), y___6 >> 8);
      b = just(tmp___38 + x___6);
      *(r + 3) = b;
      r += 4;
      m += 4;
    }
  while_break___0:
    s->a = a;
  }
}
void isaac_seed(struct isaac_state *s) {
  isaac_word a;
  unsigned long tmp;
  isaac_word b;
  unsigned long tmp___0;
  isaac_word c;
  unsigned long tmp___1;
  isaac_word d;
  unsigned long tmp___2;
  isaac_word e;
  unsigned long tmp___3;
  isaac_word f;
  unsigned long tmp___4;
  isaac_word g;
  unsigned long tmp___5;
  isaac_word h;
  unsigned long tmp___6;
  int i;
  isaac_word tmp___7;
  isaac_word tmp___8;
  isaac_word tmp___9;

  int i___0;
  isaac_word tmp___11;
  isaac_word tmp___12;
  isaac_word tmp___13;
  isaac_word tmp___14;
  isaac_word tmp___15;
  isaac_word tmp___16;

  {
    if (1 << 6 == 32) {
      tmp = 325574490UL;
    } else {
      tmp = 7240739780546808700UL;
    }
    a = tmp;

    b = tmp___0;

    c = tmp___1;

    tmp___2 = 255990488UL;

    d = tmp___2;

    e = tmp___3;

    f = tmp___4;

    g = tmp___5;

    tmp___6 = 811634969UL;

    h = tmp___6;
    i = 0;

  while_break:
    i___0 = 0;
    while (1) {

      if (!(i___0 < 1 << 8)) {
        goto while_break___0;
      }

      c += s->m[i___0 + 2];

      f += s->m[i___0 + 5];

      a -= e;
      tmp___11 = just(h);
      f ^= tmp___11 >> 9;

      b -= f;
      g ^= a << 9;

      c -= g;
      tmp___12 = just(b);
      h ^= tmp___12 >> 23;
      b += c;
      d -= h;
      a ^= c << 15;
      c += d;

      tmp___13 = just(d);
      b ^= tmp___13 >> 14;
      d += e;

      c ^= e << 20;

      tmp___14 = just(f);
      d ^= tmp___14 >> 17;

      s->m[i___0] = a;
      s->m[i___0 + 1] = b;

      s->m[i___0 + 5] = f;
      s->m[i___0 + 6] = g;
    }
  while_break___0:
    tmp___16 = (isaac_word)0;

    tmp___15 = tmp___16;
    s->b = tmp___15;
    s->a = tmp___15;
    return;
  }
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
char const *const quoting_style_args[9];
enum quoting_style const quoting_style_vals[8];
int set_char_quoting(struct quoting_options *o, char c, int i);
char *quotearg_char(char const *arg, char ch);

__inline static char *xcharalloc(size_t n)
    __attribute__((__malloc__, __alloc_size__(1)));
__inline static char *xcharalloc(size_t n) {
  void *tmp;
  void *tmp___0;
  void *tmp___1;

  {

    tmp = xmalloc(n);
    tmp___1 = tmp;

    tmp___0 = xnmalloc(n, sizeof(char));
    tmp___1 = tmp___0;

    return ((char *)tmp___1);
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        iswprint)(wint_t __wc);
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

    tmp = o;

    tmp = &default_quoting_options;

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
  unsigned int tmp;

  {
    o.style = (enum quoting_style)0;

    o.quote_these_too[0] = 0U;
    tmp = 1U;
    while (1) {

      goto while_break;

      o.quote_these_too[tmp] = 0U;
    }
  while_break:
    o.left_quote = (char const *)((void *)0);

    if ((unsigned int)style == 8U) {
    }
    o.style = style;
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

  size_t bytes;

  int tmp___4;
  int tmp___5;
  size_t ilim;
  int tmp___6;
  size_t tmp___7;

  {

    quote_string = (char const *)0;

    backslash_escapes = (_Bool)0;
    tmp = __ctype_get_mb_cur_max();
    unibyte_locale = (_Bool)(tmp == 1UL);
    elide_outer_quotes = (_Bool)((flags & 2) != 0);
    if ((unsigned int)quoting_style == 4U) {
      goto case_4;
    }

    if ((unsigned int)quoting_style == 0U) {
      goto case_0;
    }
    goto switch_default;
  case_4:

  case_3:

    backslash_escapes = (_Bool)1;
    quote_string = "\"";
    quote_string_len = (size_t)1;
    goto switch_break;
  case_5:

    elide_outer_quotes = (_Bool)0;
    goto switch_break;

    if ((unsigned int)quoting_style != 8U) {
      left_quote = gettext_quote("`", quoting_style);
    }

    quote_string = right_quote;
    quote_string_len = strlen(quote_string);
    goto switch_break;
  case_1:
    quoting_style = (enum quoting_style)2;
    elide_outer_quotes = (_Bool)1;

    quote_string_len = (size_t)1;
    goto switch_break;
  case_0:

  switch_default:

  switch_break:
    i = (size_t)0;

    if (argsize == 0xffffffffffffffffUL) {
      tmp___6 = (int const) * (arg + i) == 0;
    } else {
      tmp___6 = i == argsize;
    }
    if (tmp___6) {
    }
    is_right_quote = (_Bool)0;
    if (backslash_escapes) {
    }
    c = (unsigned char)*(arg + i);
    if ((int)c == 0) {
    }

    if ((int)c == 7) {
      goto case_7___0;
    }

    if ((int)c == 12) {
      goto case_12;
    }
    if ((int)c == 10) {
      goto case_10;
    }

    if ((int)c == 9) {
      goto case_9;
    }

    if ((int)c == 123) {
      goto case_123;
    }
    if ((int)c == 125) {
      goto case_123;
    }

    if ((int)c == 126) {
    }

    goto case_32;

    if ((int)c == 36) {
      goto case_32;
    }
    if ((int)c == 38) {
      goto case_32;
    }
    if ((int)c == 40) {
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

    if ((int)c == 62) {
      goto case_32;
    }

    if ((int)c == 39) {
    }

    goto case_37;

    if ((int)c == 44) {
      goto case_37;
    }
    if ((int)c == 45) {
      goto case_37;
    }

    if ((int)c == 48) {
      goto case_37;
    }
    if ((int)c == 49) {
    }

    if ((int)c == 51) {
      goto case_37;
    }
    if ((int)c == 52) {
      goto case_37;
    }

    goto case_37;

    if ((int)c == 55) {
      goto case_37;
    }

    goto case_37;

    goto case_37;

    if ((int)c == 66) {
      goto case_37;
    }
    if ((int)c == 67) {
      goto case_37;
    }

    if ((int)c == 70) {
      goto case_37;
    }

    if ((int)c == 72) {
      goto case_37;
    }

    if ((int)c == 76) {
      goto case_37;
    }

    if ((int)c == 79) {
      goto case_37;
    }

    goto case_37;

    if ((int)c == 81) {
      goto case_37;
    }

    goto case_37;

    goto case_37;

    if ((int)c == 88) {
      goto case_37;
    }
    if ((int)c == 89) {
      goto case_37;
    }

    goto case_37;

    goto case_37;

    if ((int)c == 100) {
    }
    if ((int)c == 101) {
    }
    if ((int)c == 102) {
    }
    if ((int)c == 103) {
      goto case_37;
    }

    if ((int)c == 108) {
      goto case_37;
    }
    if ((int)c == 109) {
    }
    if ((int)c == 110) {
      goto case_37;
    }

    if ((int)c == 113) {
      goto case_37;
    }

    if ((int)c == 115) {
      goto case_37;
    }

    if ((int)c == 117) {
    }

    if ((int)c == 119) {
      goto case_37;
    }

    goto case_37;

    goto switch_default___2;
  case_0___0:
    if (backslash_escapes) {

      while (1) {

        *(buffer + len) = (char)'\\';

        len++;
        goto while_break___4;
      }
    while_break___4:;
      if (i + 1UL < argsize) {
      }
      c = (unsigned char)'0';
    } else {
      if (flags & 1) {
        goto __Cont;
      }
    }

  case_63:

    if ((unsigned int)quoting_style == 3U) {
      goto case_3___0;
    }

    if (elide_outer_quotes) {
      goto force_outer_quoting_style;
    }
    goto switch_break___1;
  case_3___0:

    if (i + 2UL < argsize) {
    }

    goto switch_break___1;
  switch_default___1:

  switch_break___1:;
    goto switch_break___0;
  case_7___0:

  case_8___0:

  case_12:
    esc = (unsigned char)'f';
    goto c_escape;
  case_10:
    esc = (unsigned char)'n';

  case_13:
    esc = (unsigned char)'r';
    goto c_and_shell_escape;
  case_9:
    esc = (unsigned char)'t';

  case_11:
    esc = (unsigned char)'v';
    goto c_escape;
  case_92:
    esc = c;
    if (backslash_escapes) {

      if (quote_string_len) {
      }
    }
  c_and_shell_escape:

  c_escape:
    if (backslash_escapes) {
      c = esc;
    }
    goto switch_break___0;
  case_123:
    if (argsize == 0xffffffffffffffffUL) {
      tmp___1 = (int const) * (arg + 1) == 0;
    } else {
    }
    if (!tmp___1) {
      goto switch_break___0;
    }
  case_35:

  case_32:
    if ((unsigned int)quoting_style == 2U) {
    }
    goto switch_break___0;
  case_39___0:

    if (elide_outer_quotes) {
      goto force_outer_quoting_style;
    }

    *(buffer + len) = (char)'\'';

    len++;
    goto while_break___11;

  while_break___11:;
    while (1) {

      len++;
    }
  while_break___12:;

    goto while_break___13;

  while_break___13:;

  case_37:
    goto switch_break___0;
  switch_default___2:

    if (backslash_escapes) {
      if (!printable) {
      _L___0:
        ilim = i + m;

        while (1) {
        }
      while_break___22:

        c = (unsigned char)*(arg + i);

      while_break___17:;
        goto store_c;
      }
    }

  switch_break___0:;
    if (backslash_escapes) {
      goto _L___3;
    } else {
      if (elide_outer_quotes) {
      _L___3:

        if (!(*(quote_these_too + (unsigned long)c / (sizeof(int) * 8UL)) &
              (unsigned int const)(1 << (unsigned long)c %
                                            (sizeof(int) * 8UL)))) {
          goto _L___2;
        }

      } else {
      _L___2:
        if (!is_right_quote) {
          goto store_c;
        }
      }
    }
  store_escape:

      ;
  store_c:
    while (1) {

      len++;
      goto while_break___24;
    }
  while_break___24:;
  __Cont:

  while_break___3:;
    if (len == 0UL) {
    }

    *(buffer + len) = (char)'\000';

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

    sv = slotvec;

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
      if (preallocated) {
        *sv = slotvec0;
      }
      memset((void *)(sv + nslots), 0, (n1 - (size_t)nslots) * sizeof(*sv));
      nslots = (unsigned int)n1;
    }

    flags = (int)(options->flags | 1);
    tmp___2 = quotearg_buffer_restyled(
        val, size, arg, argsize, (enum quoting_style)options->style, flags,
        (unsigned int const *)(options->quote_these_too),
        (char const *)options->left_quote, (char const *)options->right_quote);
    qsize = tmp___2;

    size = qsize + 1UL;

    val = xcharalloc(size);

    quotearg_buffer_restyled(
        val, size, arg, argsize, (enum quoting_style)options->style, flags,
        (unsigned int const *)(options->quote_these_too),
        (char const *)options->left_quote, (char const *)options->right_quote);

    tmp___3 = __errno_location();

    return (val);
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;
  struct quoting_options tmp;
  char *tmp___0;

  {

    o = tmp;
    tmp___0 = quotearg_n_options(n, arg, (size_t)-1,
                                 (struct quoting_options const *)(&o));
  }
}
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg,
                           size_t argsize) {
  struct quoting_options o;
  struct quoting_options tmp;
  char *tmp___0;

  {
    tmp = quoting_options_from_style(s);
    o = tmp;
    tmp___0 = quotearg_n_options(n, arg, argsize,
                                 (struct quoting_options const *)(&o));
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

  { return (tmp); }
}
char *quotearg_colon(char const *arg) {
  char *tmp;

  {
    tmp = quotearg_char(arg, (char)':');
    return (tmp);
  }
}
struct quoting_options quote_quoting_options = {(enum quoting_style)6,
                                                0,
                                                {0U},
                                                (char const *)((void *)0),
                                                (char const *)((void *)0)};
char const *quote_n(int n, char const *name) {
  char const *tmp;

  {
    tmp = (char const *)quotearg_n_options(
        n, name, (size_t)-1,
        (struct quoting_options const *)(&quote_quoting_options));
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
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
__inline static void mbuiter_multi_next(struct mbuiter_multi *iter) {
  int tmp;
  size_t tmp___0;
  size_t tmp___1;
  int tmp___2;
  _Bool tmp___3;

  {
    if (iter->next_done) {
      return;
    }
    if (iter->in_shift) {
      goto with_shift;
    }

    if (tmp___3) {
      iter->cur.bytes = (size_t)1;
      iter->cur.wc = (wchar_t) * (iter->cur.ptr);
      iter->cur.wc_valid = (_Bool)1;
    } else {

      if (!tmp) {
        __assert_fail("mbsinit (&iter->state)",
                      "/home/khheo/project/program-reduce/benchmark/"
                      "coreutils-8.16/lib/mbuiter.h",
                      142U, "mbuiter_multi_next");
      }

    with_shift:

      tmp___1 = strnlen1(iter->cur.ptr, tmp___0);
      iter->cur.bytes =
          mbrtowc(&iter->cur.wc, iter->cur.ptr, tmp___1, &iter->state);
      if (iter->cur.bytes == 0xffffffffffffffffUL) {
        iter->cur.bytes = (size_t)1;
        iter->cur.wc_valid = (_Bool)0;
      } else {
        if (iter->cur.bytes == 0xfffffffffffffffeUL) {

          iter->cur.wc_valid = (_Bool)0;
        } else {
          if (iter->cur.bytes == 0UL) {

            if (!((int const) * (iter->cur.ptr) == 0)) {
              __assert_fail("*iter->cur.ptr == \'\\0\'",
                            "/home/khheo/project/program-reduce/benchmark/"
                            "coreutils-8.16/lib/mbuiter.h",
                            170U, "mbuiter_multi_next");
            }
          }

          tmp___2 = mbsinit((mbstate_t const *)(&iter->state));
        }
      }
    }

    return;
  }
}
char const *program_name;
void set_program_name(char const *argv0);
extern char *program_invocation_name;

extern int fputs(char const *__restrict __s, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1),
                                                          __leaf__))
                                           strrchr)(char const *__s, int __c)
    __attribute__((__pure__));

extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    stpcpy)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        pipe)(int *__pipedes);
double physmem_total(void);

double physmem_total(void) {
  double pages;
  double tmp;

  {
    tmp = (double)sysconf(85);

    return ((double)67108864);
  }
}

int dup_safer(int fd);

unsigned long num_processors(enum nproc_query query) {
  char const *envvalue;
  char const *tmp;

  char *endptr;
  unsigned long value;
  unsigned long tmp___1;

  unsigned long tmp___3;
  _Bool tmp___4;

  unsigned long tmp___5;
  long nprocs___1;
  long tmp___6;

  long tmp___7;
  unsigned long nprocs_current;
  unsigned long tmp___8;

  {
    if ((unsigned int)query == 2U) {
      tmp = (char const *)getenv("OMP_NUM_THREADS");
      envvalue = tmp;
      if ((unsigned long)envvalue != (unsigned long)((void *)0)) {

      while_break:
        tmp___4 = c_isdigit((int)*envvalue);
        if (tmp___4) {
          endptr = (char *)((void *)0);

          value = tmp___1;
          if ((unsigned long)endptr != (unsigned long)((void *)0)) {

          while_break___0:;
          }
        }
      }
      query = (enum nproc_query)1;
    }
    if ((unsigned int)query == 1U) {

      tmp___6 = sysconf(84);

      if (nprocs___1 > 0L) {
      }
    } else {
      tmp___7 = sysconf(83);
    }
    return (1UL);
  }
}
extern int nanosleep(struct timespec const *__requested_time,
                     struct timespec *__remaining);
int(__attribute__((__nonnull__(1)))
    rpl_nanosleep)(struct timespec const *requested_delay,
                   struct timespec *remaining_delay) {

  time_t limit;
  time_t seconds;
  struct timespec intermediate;
  int result;
  int tmp___0;

  {

    intermediate.tv_nsec = (__syscall_slong_t)requested_delay->tv_nsec;

    intermediate.tv_sec = seconds;
  }
}
int mkstemp_safer(char *templ);

__inline static int strcoll_loop(char const *s1, size_t s1size, char const *s2,
                                 size_t s2size) {
  int diff;
  size_t size1;
  size_t tmp;
  size_t size2;
  size_t tmp___0;
  int *tmp___1;
  int *tmp___2;

  {

    tmp___1 = __errno_location();
    *tmp___1 = 0;
    diff = strcoll(s1, s2);
    if (diff) {

    } else {
      tmp___2 = __errno_location();
      if (*tmp___2) {

      } else {
      }
    }

    goto while_break;

    tmp = strlen(s1);
    size1 = tmp + 1UL;
    tmp___0 = strlen(s2);
    size2 = tmp___0 + 1UL;

    s2 += size2;
    s1size -= size1;

    if (s1size == 0UL) {
      return (-(s2size != 0UL));
    }

  while_break:;
    return (diff);
  }
}
int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {
  int *tmp;
  int tmp___0;
  int tmp___1;

  {
    if (s1size == s2size) {
      tmp___1 = memcmp((void const *)s1, (void const *)s2, s1size);
      if (tmp___1 == 0) {
        tmp = __errno_location();

        return (0);
      } else {
        tmp___0 = strcoll_loop(s1, s1size, s2, s2size);
        return (tmp___0);
      }
    } else {
      tmp___0 = strcoll_loop(s1, s1size, s2, s2size);
      return (tmp___0);
    }
  }
}

__attribute__((__nothrow__)) void(__attribute__((__leaf__))
                                  md5_process_block)(void const *buffer,
                                                     size_t len,
                                                     struct md5_ctx *ctx);

__attribute__((__nothrow__)) void *(__attribute__((__leaf__))
                                    md5_finish_ctx)(struct md5_ctx *ctx,
                                                    void *resbuf);
__attribute__((__nothrow__)) void *(__attribute__((__leaf__))
                                    md5_read_ctx)(struct md5_ctx const *ctx,
                                                  void *resbuf);
static unsigned char const fillbuf___2[64] = {(unsigned char const)128,
                                              (unsigned char const)0};
__attribute__((__nothrow__)) void(__attribute__((__leaf__))
                                  md5_init_ctx)(struct md5_ctx *ctx);

__attribute__((__nothrow__)) void *(__attribute__((__leaf__))
                                    md5_read_ctx)(struct md5_ctx const *ctx,
                                                  void *resbuf);

__attribute__((__nothrow__)) void *(__attribute__((__leaf__))
                                    md5_finish_ctx)(struct md5_ctx *ctx,
                                                    void *resbuf);

__attribute__((__nothrow__)) void(__attribute__((__leaf__))
                                  md5_process_bytes)(void const *buffer,
                                                     size_t len,
                                                     struct md5_ctx *ctx);
void(__attribute__((__leaf__))
     md5_process_bytes)(void const *buffer, size_t len, struct md5_ctx *ctx) {
  size_t left_over;
  size_t add;
  size_t tmp;
  size_t left_over___0;

  {
    if (ctx->buflen != 0U) {

      if (128UL - left_over > len) {
        tmp = len;
      } else {
      }
      add = tmp;
      memcpy((void *)((char *)(ctx->buffer) + left_over), buffer, add);
      ctx->buflen = (uint32_t)((size_t)ctx->buflen + add);
      if (ctx->buflen > 64U) {
        md5_process_block((void const *)(ctx->buffer),
                          (size_t)(ctx->buflen & 4294967232U), ctx);
        ctx->buflen &= 63U;
      }

      len -= add;
    }
    if (len >= 64UL) {

      len &= 63UL;
    }
    if (len > 0UL) {
      left_over___0 = (size_t)ctx->buflen;
      memcpy((void *)((char *)(ctx->buffer) + left_over___0), buffer, len);

      md5_process_block((void const *)(ctx->buffer), (size_t)64, ctx);

      ctx->buflen = (uint32_t)left_over___0;
    }
    return;
  }
}

void(__attribute__((__leaf__))
     md5_process_block)(void const *buffer, size_t len, struct md5_ctx *ctx) {
  uint32_t correct_words[16];
  uint32_t const *words;
  size_t nwords;
  uint32_t const *endp;
  uint32_t A;
  uint32_t B;
  uint32_t C;
  uint32_t D;
  uint32_t *cwp;
  uint32_t A_save;
  uint32_t B_save;
  uint32_t C_save;
  uint32_t D_save;
  uint32_t *tmp;
  uint32_t tmp___0;
  uint32_t *tmp___1;
  uint32_t tmp___2;
  uint32_t *tmp___3;

  uint32_t *tmp___5;
  uint32_t tmp___6;
  uint32_t *tmp___7;
  uint32_t tmp___8;

  uint32_t tmp___10;
  uint32_t *tmp___11;
  uint32_t tmp___12;
  uint32_t *tmp___13;
  uint32_t tmp___14;
  uint32_t *tmp___15;
  uint32_t tmp___16;
  uint32_t *tmp___17;
  uint32_t tmp___18;
  uint32_t *tmp___19;
  uint32_t tmp___20;
  uint32_t *tmp___21;
  uint32_t tmp___22;
  uint32_t *tmp___23;
  uint32_t tmp___24;
  uint32_t *tmp___25;
  uint32_t tmp___26;
  uint32_t *tmp___27;
  uint32_t tmp___28;
  uint32_t *tmp___29;
  uint32_t tmp___30;

  {
    words = (uint32_t const *)buffer;

    endp = words + nwords;
    A = ctx->A;

    D = ctx->D;
    ctx->total[0] = (uint32_t)((size_t)ctx->total[0] + len);
    if ((size_t)ctx->total[0] < len) {
    }
    while (1) {

      if (!((unsigned long)words < (unsigned long)endp)) {
        goto while_break;
      }

      A_save = A;
      B_save = B;
      C_save = C;
      D_save = D;
      while (1) {
        tmp = cwp;
        cwp++;
        tmp___0 = (uint32_t)*words;

        A += ((D ^ (B & (C ^ D))) + tmp___0) + 3614090360U;

        A = (A << 7) | (A >> 25);
        A += B;
        goto while_break___0;
      }
    while_break___0:;
      while (1) {
        tmp___1 = cwp;
        cwp++;
        tmp___2 = (uint32_t)*words;

        D += ((C ^ (A & (B ^ C))) + tmp___2) + 3905402710U;
        words++;

        goto while_break___1;
      }
    while_break___1:;

      ;
      while (1) {
        tmp___5 = cwp;
        cwp++;

        *tmp___5 = tmp___6;

        words++;

        B += C;
        goto while_break___3;
      }
    while_break___3:;
      while (1) {
        tmp___7 = cwp;

        tmp___8 = (uint32_t)*words;

        A += ((D ^ (B & (C ^ D))) + tmp___8) + 4118548399U;

        A = (A << 7) | (A >> 25);
        A += B;
      }
    while_break___4:;
      while (1) {

        D = (D << 12) | (D >> 20);
        D += A;
      }
    while_break___5:;
      while (1) {
        tmp___11 = cwp;
        cwp++;

        words++;
        C = (C << 17) | (C >> 15);
        C += D;
      }
    while_break___6:;
      while (1) {
        tmp___13 = cwp;
        cwp++;

        B += C;
        goto while_break___7;
      }
    while_break___7:;
      while (1) {

        cwp++;

        *tmp___15 = tmp___16;
        A += ((D ^ (B & (C ^ D))) + tmp___16) + 1770035416U;
        words++;

        A += B;
        goto while_break___8;
      }
    while_break___8:;
      while (1) {

        tmp___18 = (uint32_t)*words;

        D += ((C ^ (A & (B ^ C))) + tmp___18) + 2336552879U;
        words++;
        D = (D << 12) | (D >> 20);
        D += A;
      }
    while_break___9:;
      while (1) {
        tmp___19 = cwp;

        tmp___20 = (uint32_t)*words;

        C += ((B ^ (D & (A ^ B))) + tmp___20) + 4294925233U;
        words++;
      }

      ;

      tmp___22 = (uint32_t)*words;
      *tmp___21 = tmp___22;
      B += ((A ^ (C & (D ^ A))) + tmp___22) + 2304563134U;
      words++;

      B += C;
      goto while_break___11;

    while_break___11:;
      while (1) {
        tmp___23 = cwp;
        cwp++;
        tmp___24 = (uint32_t)*words;
        *tmp___23 = tmp___24;
        A += ((D ^ (B & (C ^ D))) + tmp___24) + 1804603682U;

        A = (A << 7) | (A >> 25);

        goto while_break___12;
      }
    while_break___12:;
      while (1) {
        tmp___25 = cwp;
        cwp++;

        *tmp___25 = tmp___26;
        D += ((C ^ (A & (B ^ C))) + tmp___26) + 4254626195U;
        words++;

        D += A;
      }
    while_break___13:;
      while (1) {
        tmp___27 = cwp;
        cwp++;

        *tmp___27 = tmp___28;

        words++;

        goto while_break___14;
      }
    while_break___14:;
      while (1) {
        tmp___29 = cwp;

        words++;
        B = (B << 22) | (B >> 10);

        goto while_break___15;
      }
    while_break___15:;
      while (1) {
        A += ((C ^ (D & (B ^ C))) + correct_words[1]) + 4129170786U;
        A = (A << 5) | (A >> 27);
        A += B;
        goto while_break___16;
      }
    while_break___16:;
      while (1) {
        D += ((B ^ (C & (A ^ B))) + correct_words[6]) + 3225465664U;

        D += A;
        goto while_break___17;
      }
    while_break___17:;
      while (1) {
        C += ((A ^ (B & (D ^ A))) + correct_words[11]) + 643717713U;
        C = (C << 14) | (C >> 18);
        C += D;
      }
    while_break___18:;
      while (1) {
        B += ((D ^ (A & (C ^ D))) + correct_words[0]) + 3921069994U;
        B = (B << 20) | (B >> 12);
        B += C;
        goto while_break___19;
      }
    while_break___19:;

    while_break___20:;

      D = (D << 9) | (D >> 23);

      goto while_break___21;

    while_break___21:;
      while (1) {

        C = (C << 14) | (C >> 18);
        C += D;
        goto while_break___22;
      }
    while_break___22:;

      B += ((D ^ (A & (C ^ D))) + correct_words[4]) + 3889429448U;
      B = (B << 20) | (B >> 12);
      B += C;

    while_break___23:;
      while (1) {

        A += B;
      }
    while_break___24:;
      while (1) {

        D = (D << 9) | (D >> 23);
        D += A;
        goto while_break___25;
      }
    while_break___25:;

    while_break___26:;

    while_break___27:;

    while_break___28:;
      while (1) {
        D += ((B ^ (C & (A ^ B))) + correct_words[2]) + 4243563512U;

        goto while_break___29;
      }
    while_break___29:;
      while (1) {

        C = (C << 14) | (C >> 18);

        goto while_break___30;
      }
    while_break___30:;
      while (1) {
        B += ((D ^ (A & (C ^ D))) + correct_words[12]) + 2368359562U;

        goto while_break___31;
      }
    while_break___31:;

    while_break___32:;
      while (1) {

        D = (D << 11) | (D >> 21);

        goto while_break___33;
      }
    while_break___33:;

      ;
      while (1) {

        B += C;
        goto while_break___35;
      }
    while_break___35:;
      while (1) {

        A += B;
      }
    while_break___36:;
      while (1) {
        D += (((A ^ B) ^ C) + correct_words[4]) + 1272893353U;
        D = (D << 11) | (D >> 21);
      }

      ;

      C += (((D ^ A) ^ B) + correct_words[7]) + 4139469664U;
      C = (C << 16) | (C >> 16);
      C += D;
      goto while_break___38;

    while_break___38:;
      while (1) {

        B += C;
        goto while_break___39;
      }
    while_break___39:;
      while (1) {
        A += (((B ^ C) ^ D) + correct_words[13]) + 681279174U;

        goto while_break___40;
      }
    while_break___40:;

      ;
      while (1) {

        C += D;
      }

      ;

    while_break___43:;
      while (1) {
        A += (((B ^ C) ^ D) + correct_words[9]) + 3654602809U;
      }
    while_break___44:;
      while (1) {
        D += (((A ^ B) ^ C) + correct_words[12]) + 3873151461U;

        D += A;
        goto while_break___45;
      }
    while_break___45:;

    while_break___46:;
      while (1) {

        B = (B << 23) | (B >> 9);
        B += C;
        goto while_break___47;
      }
    while_break___47:;
      while (1) {
        A += ((C ^ (B | ~D)) + correct_words[0]) + 4096336452U;

        A += B;
        goto while_break___48;
      }
    while_break___48:;
      while (1) {
        D += ((B ^ (A | ~C)) + correct_words[7]) + 1126891415U;
        D = (D << 10) | (D >> 22);
      }
    while_break___49:;
      while (1) {
        C += ((A ^ (D | ~B)) + correct_words[14]) + 2878612391U;
        C = (C << 15) | (C >> 17);

        goto while_break___50;
      }
    while_break___50:;

      ;
      while (1) {
        A += ((C ^ (B | ~D)) + correct_words[12]) + 1700485571U;
        A = (A << 6) | (A >> 26);

        goto while_break___52;
      }
    while_break___52:;
      while (1) {

        D = (D << 10) | (D >> 22);
        D += A;
        goto while_break___53;
      }
    while_break___53:;
      while (1) {

        C = (C << 15) | (C >> 17);
      }
    while_break___54:;

      B += ((D ^ (C | ~A)) + correct_words[1]) + 2240044497U;

      goto while_break___55;

    while_break___55:;
      while (1) {
        A += ((C ^ (B | ~D)) + correct_words[8]) + 1873313359U;
        A = (A << 6) | (A >> 26);
        A += B;
        goto while_break___56;
      }
    while_break___56:;
      while (1) {

        D = (D << 10) | (D >> 22);
        D += A;
        goto while_break___57;
      }
    while_break___57:;
      while (1) {
        C += ((A ^ (D | ~B)) + correct_words[6]) + 2734768916U;

        C += D;
        goto while_break___58;
      }
    while_break___58:;
      while (1) {
        B += ((D ^ (C | ~A)) + correct_words[13]) + 1309151649U;

        B += C;
        goto while_break___59;
      }
    while_break___59:;
      while (1) {
        A += ((C ^ (B | ~D)) + correct_words[4]) + 4149444226U;
        A = (A << 6) | (A >> 26);
        A += B;
        goto while_break___60;
      }
    while_break___60:;

      D += ((B ^ (A | ~C)) + correct_words[11]) + 3174756917U;

      goto while_break___61;

    while_break___61:;
      while (1) {

        C = (C << 15) | (C >> 17);

        goto while_break___62;
      }
    while_break___62:;

    while_break___63:
      A += A_save;

      C += C_save;
      D += D_save;
    }
  while_break:
    ctx->A = A;
    ctx->B = B;

    ctx->D = D;
    return;
  }
}

int mbsnwidth(char const *string, size_t nbytes, int flags) {
  char const *p;
  char const *plimit;
  int width;
  mbstate_t mbstate;
  wchar_t wc;
  size_t bytes;
  int w;
  int tmp;
  int tmp___0;
  size_t tmp___1;
  unsigned char c;
  char const *tmp___2;
  unsigned short const **tmp___3;
  unsigned short const **tmp___4;

  {
    p = string;
    plimit = p + nbytes;
    width = 0;
    tmp___1 = __ctype_get_mb_cur_max();
    if (tmp___1 > 1UL) {
      while (1) {

        if (!((unsigned long)p < (unsigned long)plimit)) {
          goto while_break;
        }
        if ((int const) * p == 32) {
          goto case_32;
        }
        if ((int const) * p == 33) {
          goto case_32;
        }
        if ((int const) * p == 34) {
          goto case_32;
        }
        if ((int const) * p == 35) {
          goto case_32;
        }
        if ((int const) * p == 37) {
          goto case_32;
        }
        if ((int const) * p == 38) {
          goto case_32;
        }
        if ((int const) * p == 39) {
          goto case_32;
        }
        if ((int const) * p == 40) {
          goto case_32;
        }
        if ((int const) * p == 41) {
          goto case_32;
        }
        if ((int const) * p == 42) {
          goto case_32;
        }
        if ((int const) * p == 43) {
          goto case_32;
        }
        if ((int const) * p == 44) {
          goto case_32;
        }
        if ((int const) * p == 45) {
          goto case_32;
        }
        if ((int const) * p == 46) {
          goto case_32;
        }
        if ((int const) * p == 47) {
          goto case_32;
        }
        if ((int const) * p == 48) {
          goto case_32;
        }
        if ((int const) * p == 49) {
          goto case_32;
        }
        if ((int const) * p == 50) {
          goto case_32;
        }
        if ((int const) * p == 51) {
          goto case_32;
        }
        if ((int const) * p == 52) {
          goto case_32;
        }
        if ((int const) * p == 53) {
          goto case_32;
        }
        if ((int const) * p == 54) {
          goto case_32;
        }
        if ((int const) * p == 55) {
          goto case_32;
        }
        if ((int const) * p == 56) {
          goto case_32;
        }
        if ((int const) * p == 57) {
          goto case_32;
        }
        if ((int const) * p == 58) {
          goto case_32;
        }
        if ((int const) * p == 59) {
          goto case_32;
        }
        if ((int const) * p == 60) {
          goto case_32;
        }
        if ((int const) * p == 61) {
          goto case_32;
        }
        if ((int const) * p == 62) {
          goto case_32;
        }
        if ((int const) * p == 63) {
          goto case_32;
        }
        if ((int const) * p == 65) {
          goto case_32;
        }
        if ((int const) * p == 66) {
          goto case_32;
        }
        if ((int const) * p == 67) {
          goto case_32;
        }
        if ((int const) * p == 68) {
          goto case_32;
        }
        if ((int const) * p == 69) {
          goto case_32;
        }
        if ((int const) * p == 70) {
          goto case_32;
        }
        if ((int const) * p == 71) {
          goto case_32;
        }
        if ((int const) * p == 72) {
          goto case_32;
        }
        if ((int const) * p == 73) {
          goto case_32;
        }
        if ((int const) * p == 74) {
          goto case_32;
        }
        if ((int const) * p == 75) {
          goto case_32;
        }
        if ((int const) * p == 76) {
          goto case_32;
        }
        if ((int const) * p == 77) {
          goto case_32;
        }
        if ((int const) * p == 78) {
          goto case_32;
        }
        if ((int const) * p == 79) {
          goto case_32;
        }
        if ((int const) * p == 80) {
          goto case_32;
        }
        if ((int const) * p == 81) {
          goto case_32;
        }
        if ((int const) * p == 82) {
          goto case_32;
        }
        if ((int const) * p == 83) {
          goto case_32;
        }
        if ((int const) * p == 84) {
          goto case_32;
        }
        if ((int const) * p == 85) {
          goto case_32;
        }
        if ((int const) * p == 86) {
          goto case_32;
        }
        if ((int const) * p == 87) {
          goto case_32;
        }
        if ((int const) * p == 88) {
          goto case_32;
        }
        if ((int const) * p == 89) {
          goto case_32;
        }
        if ((int const) * p == 90) {
          goto case_32;
        }
        if ((int const) * p == 91) {
          goto case_32;
        }
        if ((int const) * p == 92) {
          goto case_32;
        }
        if ((int const) * p == 93) {
          goto case_32;
        }
        if ((int const) * p == 94) {
          goto case_32;
        }
        if ((int const) * p == 95) {
          goto case_32;
        }
        if ((int const) * p == 97) {
          goto case_32;
        }
        if ((int const) * p == 98) {
          goto case_32;
        }
        if ((int const) * p == 99) {
          goto case_32;
        }
        if ((int const) * p == 100) {
          goto case_32;
        }
        if ((int const) * p == 101) {
          goto case_32;
        }
        if ((int const) * p == 102) {
          goto case_32;
        }
        if ((int const) * p == 103) {
          goto case_32;
        }
        if ((int const) * p == 104) {
          goto case_32;
        }
        if ((int const) * p == 105) {
          goto case_32;
        }
        if ((int const) * p == 106) {
          goto case_32;
        }
        if ((int const) * p == 107) {
          goto case_32;
        }
        if ((int const) * p == 108) {
          goto case_32;
        }
        if ((int const) * p == 109) {
          goto case_32;
        }
        if ((int const) * p == 110) {
          goto case_32;
        }
        if ((int const) * p == 111) {
          goto case_32;
        }
        if ((int const) * p == 112) {
          goto case_32;
        }
        if ((int const) * p == 113) {
          goto case_32;
        }
        if ((int const) * p == 114) {
          goto case_32;
        }
        if ((int const) * p == 115) {
          goto case_32;
        }
        if ((int const) * p == 116) {
          goto case_32;
        }
        if ((int const) * p == 117) {
          goto case_32;
        }
        if ((int const) * p == 118) {
          goto case_32;
        }
        if ((int const) * p == 119) {
          goto case_32;
        }
        if ((int const) * p == 120) {
          goto case_32;
        }
        if ((int const) * p == 121) {
          goto case_32;
        }
        if ((int const) * p == 122) {
          goto case_32;
        }
        if ((int const) * p == 123) {
          goto case_32;
        }
        if ((int const) * p == 124) {
          goto case_32;
        }
        if ((int const) * p == 125) {
          goto case_32;
        }
        if ((int const) * p == 126) {
          goto case_32;
        }
        goto switch_default;
      case_32:
        p++;
        width++;
        goto switch_break;
      switch_default:
        memset((void *)(&mbstate), 0, sizeof(mbstate));
        while (1) {
          bytes = mbrtowc(&wc, p, (size_t)(plimit - p), &mbstate);
          if (bytes == 0xffffffffffffffffUL) {
            if (!(flags & 1)) {
              p++;
              width++;
              goto while_break___0;
            } else {
              return (-1);
            }
          }
          if (bytes == 0xfffffffffffffffeUL) {
            if (!(flags & 1)) {
              p = plimit;
              width++;
              goto while_break___0;
            } else {
              return (-1);
            }
          }
          if (bytes == 0UL) {
            bytes = (size_t)1;
          }
          w = wcwidth(wc);
          if (w >= 0) {
            if (w > 2147483647 - width) {
              goto overflow;
            }
            width += w;
          } else {
            if (!(flags & 2)) {
              tmp = iswcntrl((wint_t)wc);
              if (!tmp) {
                if (width == 2147483647) {
                  goto overflow;
                }
                width++;
              }
            } else {
              return (-1);
            }
          }
          p += bytes;
          tmp___0 = mbsinit((mbstate_t const *)(&mbstate));
          if (tmp___0) {
            goto while_break___0;
          }
        }
      while_break___0:;
        goto switch_break;
      switch_break:;
      }
    while_break:;
      return (width);
    }
    while (1) {

      if (!((unsigned long)p < (unsigned long)plimit)) {
        goto while_break___1;
      }
      tmp___2 = p;
      p++;
      c = (unsigned char)*tmp___2;
      tmp___4 = __ctype_b_loc();
      if ((int const) * (*tmp___4 + (int)c) & 16384) {
        if (width == 2147483647) {
          goto overflow;
        }
        width++;
      } else {
        if (!(flags & 2)) {
          tmp___3 = __ctype_b_loc();
          if (!((int const) * (*tmp___3 + (int)c) & 2)) {
            if (width == 2147483647) {
              goto overflow;
            }
            width++;
          }
        } else {
          return (-1);
        }
      }
    }
  while_break___1:;
    return (width);
  overflow:
    return (2147483647);
  }
}

extern __attribute__((__nothrow__))
wint_t(__attribute__((__leaf__)) towlower)(wint_t __wc);
int(__attribute__((__nonnull__(1, 2))) mbscasecmp)(char const *s1,
                                                   char const *s2) {
  mbui_iterator_t iter1;
  mbui_iterator_t iter2;
  int cmp;
  wint_t tmp;
  wint_t tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___4;
  int tmp___5;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  int tmp___11;
  int tmp___12;
  int tmp___13;
  int tmp___14;
  int tmp___15;
  int tmp___16;
  unsigned char const *p1;

  unsigned char c1;
  unsigned char c2;
  int tmp___18;
  unsigned short const **tmp___19;

  unsigned short const **tmp___22;
  size_t tmp___25;

  {
    if ((unsigned long)s1 == (unsigned long)s2) {
    }
    tmp___25 = __ctype_get_mb_cur_max();

    memset((void *)(&iter1.state), '\000', sizeof(mbstate_t));
    iter1.next_done = (_Bool)0;
    iter2.cur.ptr = s2;

    memset((void *)(&iter2.state), '\000', sizeof(mbstate_t));
    iter2.next_done = (_Bool)0;
    while (1) {
      mbuiter_multi_next(&iter1);

      if (tmp___13) {
        mbuiter_multi_next(&iter2);
        if (iter2.cur.wc_valid) {
          if (iter2.cur.wc == 0) {
            tmp___14 = 0;
          } else {
            tmp___14 = 1;
          }
        } else {
          tmp___14 = 1;
        }

        goto while_break;

      } else {
        goto while_break;
      }
      if (iter1.cur.wc_valid) {
        if (iter2.cur.wc_valid) {
          tmp = towlower((wint_t)iter1.cur.wc);
          tmp___0 = towlower((wint_t)iter2.cur.wc);
          tmp___1 = (int)tmp - (int)tmp___0;
        } else {
          tmp___1 = -1;
        }
        tmp___12 = tmp___1;
      } else {
        if (iter2.cur.wc_valid) {
          tmp___11 = 1;
        } else {
          if (iter1.cur.bytes == iter2.cur.bytes) {
            tmp___2 = memcmp((void const *)iter1.cur.ptr,
                             (void const *)iter2.cur.ptr, iter1.cur.bytes);
            tmp___10 = tmp___2;
          } else {
            if (iter1.cur.bytes < iter2.cur.bytes) {
              tmp___5 = memcmp((void const *)iter1.cur.ptr,
                               (void const *)iter2.cur.ptr, iter1.cur.bytes);
              if (tmp___5 > 0) {
                tmp___4 = 1;
              } else {
                tmp___4 = -1;
              }
              tmp___9 = tmp___4;
            } else {
              tmp___8 = memcmp((void const *)iter1.cur.ptr,
                               (void const *)iter2.cur.ptr, iter2.cur.bytes);
              if (tmp___8 >= 0) {
                tmp___7 = 1;
              } else {
                tmp___7 = -1;
              }
              tmp___9 = tmp___7;
            }
            tmp___10 = tmp___9;
          }
          tmp___11 = tmp___10;
        }
        tmp___12 = tmp___11;
      }
      cmp = tmp___12;
      if (cmp != 0) {
        return (cmp);
      }
      iter1.cur.ptr += iter1.cur.bytes;
      iter1.next_done = (_Bool)0;
      iter2.cur.ptr += iter2.cur.bytes;
    }
  while_break:
    mbuiter_multi_next(&iter1);
    if (iter1.cur.wc_valid) {
      if (iter1.cur.wc == 0) {
        tmp___15 = 0;
      } else {
      }
    } else {
      tmp___15 = 1;
    }
    if (tmp___15) {
      return (1);
    }
    mbuiter_multi_next(&iter2);

    tmp___16 = 1;

    return (0);

    while (1) {

      if ((int const) * (*tmp___19 + (int)*p1) & 256) {

        c1 = (unsigned char)tmp___18;
      } else {
        c1 = (unsigned char)*p1;
      }
      tmp___22 = __ctype_b_loc();

      if ((int)c1 == 0) {
        goto while_break___0;
      }
    }
  while_break___0:;
  }
}

extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__))
                                                       exit)(int __status);
extern int optind;

extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     pthread_mutex_init)(
        pthread_mutex_t *__mutex, pthread_mutexattr_t const *__mutexattr);
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
extern __attribute__((__nothrow__))
FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);
extern int fscanf(FILE *__restrict __stream, char const *__restrict __format,
                  ...);
extern int ungetc(int __c, FILE *__stream);
static char const *volatile charset_aliases;
static char const *get_charset_aliases(void) {
  char const *cp;
  char const *dir;
  char const *base;
  char *file_name___3;
  size_t dir_len___0;
  size_t tmp;
  size_t base_len___0;
  size_t tmp___0;
  int add_slash;
  int tmp___1;
  int fd;
  FILE *fp;
  char *res_ptr;
  size_t res_size;
  int c;
  char buf1[51];
  char buf2[51];
  size_t l1;
  size_t l2;
  char *old_res_ptr;
  int tmp___3;

  {
    cp = (char const *)charset_aliases;
    if ((unsigned long)cp == (unsigned long)((void *)0)) {
      base = "charset.alias";
      dir = (char const *)getenv("CHARSETALIASDIR");
      if ((unsigned long)dir == (unsigned long)((void *)0)) {
        dir = "/usr/local/lib";
      } else {
        if ((int const) * (dir + 0) == 0) {
          dir = "/usr/local/lib";
        }
      }
      tmp = strlen(dir);
      dir_len___0 = tmp;
      tmp___0 = strlen(base);
      base_len___0 = tmp___0;
      if (dir_len___0 > 0UL) {
        if (!((int const) * (dir + (dir_len___0 - 1UL)) == 47)) {
          tmp___1 = 1;
        } else {
          tmp___1 = 0;
        }
      } else {
        tmp___1 = 0;
      }
      add_slash = tmp___1;
      file_name___3 = (char *)malloc(
          ((dir_len___0 + (size_t)add_slash) + base_len___0) + 1UL);
      if ((unsigned long)file_name___3 != (unsigned long)((void *)0)) {
        memcpy((void *)file_name___3, (void const *)dir, dir_len___0);
        if (add_slash) {
          *(file_name___3 + dir_len___0) = (char)'/';
        }
        memcpy((void *)((file_name___3 + dir_len___0) + add_slash),
               (void const *)base, base_len___0 + 1UL);
      }
      if ((unsigned long)file_name___3 == (unsigned long)((void *)0)) {
        cp = "";
      } else {
        fd = open((char const *)file_name___3, 131072);
        if (fd < 0) {
          cp = "";
        } else {
          fp = fdopen(fd, "r");
          if ((unsigned long)fp == (unsigned long)((void *)0)) {
            close(fd);
            cp = "";
          } else {
            res_ptr = (char *)((void *)0);
            res_size = (size_t)0;
            while (1) {
              c = getc_unlocked(fp);
              if (c == -1) {
                goto while_break;
              }
              if (c == 10) {
                goto __Cont;
              } else {
                if (c == 32) {
                  goto __Cont;
                } else {
                  if (c == 9) {
                    goto __Cont;
                  }
                }
              }
              if (c == 35) {
                while (1) {
                  c = getc_unlocked(fp);
                  if (c == -1) {
                    goto while_break___0;
                  } else {
                    if (c == 10) {
                      goto while_break___0;
                    }
                  }
                }
              while_break___0:;
                if (c == -1) {
                  goto while_break;
                }
                goto __Cont;
              }
              ungetc(c, fp);
              tmp___3 = fscanf(fp, "%50s %50s", buf1, buf2);
              if (tmp___3 < 2) {
                goto while_break;
              }
              l1 = strlen((char const *)(buf1));
              l2 = strlen((char const *)(buf2));
              old_res_ptr = res_ptr;
              if (res_size == 0UL) {
                res_size = ((l1 + 1UL) + l2) + 1UL;
                res_ptr = (char *)malloc(res_size + 1UL);
              } else {
                res_size += ((l1 + 1UL) + l2) + 1UL;
                res_ptr = (char *)realloc((void *)res_ptr, res_size + 1UL);
              }
              if ((unsigned long)res_ptr == (unsigned long)((void *)0)) {
                res_size = (size_t)0;
                free((void *)old_res_ptr);
                goto while_break;
              }
              strcpy(((res_ptr + res_size) - (l2 + 1UL)) - (l1 + 1UL),
                     (char const *)(buf1));
              strcpy((res_ptr + res_size) - (l2 + 1UL), (char const *)(buf2));
            __Cont:;
            }
          while_break:
            rpl_fclose(fp);
            if (res_size == 0UL) {
              cp = "";
            } else {
              *(res_ptr + res_size) = (char)'\000';
              cp = (char const *)res_ptr;
            }
          }
        }
        free((void *)file_name___3);
      }
      charset_aliases = cp;
    }
    return (cp);
  }
}
char const *locale_charset(void) {
  char const *codeset;
  char const *aliases;
  size_t tmp;

  size_t tmp___1;
  int tmp___2;

  {
    codeset = (char const *)nl_langinfo(14);
    if ((unsigned long)codeset == (unsigned long)((void *)0)) {
    }
    aliases = get_charset_aliases();
    while (1) {

      if (tmp___2 == 0) {
        tmp___1 = strlen(aliases);
        codeset = (aliases + tmp___1) + 1;

      } else {
      }
      tmp = strlen(aliases);
    }
  while_break:;
    if ((int const) * (codeset + 0) == 0) {
      codeset = "ASCII";
    }
  }
}

#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
extern __attribute__((__nothrow__)) struct lconv *(__attribute__((__leaf__))
                                                   localeconv)(void);

int heap_insert(struct heap *heap, void *item);

static size_t heapify_down(void **array, size_t count, size_t initial,
                           int (*compare___0)(void const *, void const *));
static void heapify_up(void **array, size_t count,
                       int (*compare___0)(void const *, void const *));
static int heap_default_compare(void const *a, void const *b) {

  { return (0); }
}
struct heap *heap_alloc(int (*compare___0)(void const *, void const *),
                        size_t n_reserve) {
  struct heap *heap;
  struct heap *tmp;

  {
    tmp = (struct heap *)xmalloc(sizeof(*heap));
    heap = tmp;
    if (n_reserve == 0UL) {
      n_reserve = (size_t)1;
    }
    heap->array = (void **)xnmalloc(n_reserve, sizeof(*(heap->array)));

    heap->capacity = n_reserve;
    heap->count = (size_t)0;
    if (compare___0) {
      heap->compare = compare___0;
    } else {
      heap->compare = &heap_default_compare;
    }
    return (heap);
  }
}

int heap_insert(struct heap *heap, void *item) {

  {
    if (heap->capacity - 1UL <= heap->count) {
      heap->array = (void **)x2nrealloc((void *)heap->array, &heap->capacity,
                                        sizeof(*(heap->array)));
    }
    (heap->count)++;
    *(heap->array + heap->count) = item;
    heapify_up(heap->array, heap->count, heap->compare);
  }
}
void *heap_remove_top(struct heap *heap) {
  void *top;

  {

    top = *(heap->array + 1);

    (heap->count)--;

    heapify_down(heap->array, heap->count, (size_t)1, heap->compare);
    return (top);
  }
}
static size_t heapify_down(void **array, size_t count, size_t initial,
                           int (*compare___0)(void const *, void const *)) {
  void *element;
  size_t parent;
  size_t child;
  int tmp;
  int tmp___0;

  {

    parent = initial;
    while (1) {

      if (!(parent <= count / 2UL)) {
        goto while_break;
      }
      child = 2UL * parent;
      if (child < count) {
        tmp = (*compare___0)((void const *)*(array + child),
                             (void const *)*(array + (child + 1UL)));
        if (tmp < 0) {
          child++;
        }
      }
      tmp___0 =
          (*compare___0)((void const *)*(array + child), (void const *)element);
      if (tmp___0 <= 0) {
        goto while_break;
      }
      *(array + parent) = *(array + child);
      parent = child;
    }
  while_break:
    *(array + parent) = element;
  }
}
static void heapify_up(void **array, size_t count,
                       int (*compare___0)(void const *, void const *)) {
  size_t k;
  void *new_element;

  {
    k = count;
    new_element = *(array + k);

    if (k != 1UL) {

    } else {
      goto while_break;
    }
    *(array + k) = *(array + k / 2UL);
    k /= 2UL;

  while_break:
    *(array + k) = new_element;
    return;
  }
}

static size_t __attribute__((__pure__))
compute_bucket_size(size_t candidate, Hash_tuning const *tuning) {
  float new_candidate;
  int tmp;

  {
    if (!tuning->is_n_buckets) {
      new_candidate =
          (float)((float const)candidate / tuning->growth_threshold);
      if ((float)0xffffffffffffffffUL <= new_candidate) {
        return ((size_t __attribute__((__pure__)))0);
      }
      candidate = (size_t)new_candidate;
    }
    candidate = next_prime(candidate);
    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp = -1;
    } else {
      tmp = -2;
    }
    if ((size_t)tmp / sizeof(struct hash_entry *) < candidate) {
      return ((size_t __attribute__((__pure__)))0);
    }
    return ((size_t __attribute__((__pure__)))candidate);
  }
}

size_t hash_pjw(void const *x, size_t tablesize) {
  char const *s;
  size_t h;

  {

    while (1) {

      if (!*s) {
        goto while_break;
      }
      h = (unsigned long)*s + ((h << 9) | (h >> (sizeof(size_t) * 8UL - 9UL)));
      s++;
    }
  while_break:;
  }
}

_Bool hard_locale(int category) {
  _Bool hard;

  { return (hard); }
}

extern void(__attribute__((__nonnull__(1, 4)))
            qsort)(void *__base, size_t __nmemb, size_t __size,
                   int (*__compar)(void const *, void const *));

FILE *fopen_safer(char const *file, char const *mode) {
  FILE *fp;
  FILE *tmp;

  {
    tmp = fopen(file, mode);
    fp = tmp;

    return (fp);
  }
}

static char const *match_suffix(char const **str) {

  { ; }
}
__inline static int order(unsigned char c) {
  _Bool tmp;
  _Bool tmp___0;

  {

    if (tmp___0) {
      return (0);
    } else {
      tmp = c_isalpha((int)c);
      if (tmp) {
        return ((int)c);
      } else {
        if ((int)c == 126) {
          return (-1);
        } else {
          return (((int)c + 255) + 1);
        }
      }
    }
  }
}
static int __attribute__((__pure__))
verrevcmp(char const *s1, size_t s1_len, char const *s2, size_t s2_len) {
  size_t s1_pos;
  size_t s2_pos;
  int first_diff;
  int s1_c;
  int tmp;
  int tmp___0;
  int s2_c;
  int tmp___1;
  int tmp___2;
  _Bool tmp___3;
  _Bool tmp___4;
  _Bool tmp___5;
  _Bool tmp___6;
  _Bool tmp___7;
  _Bool tmp___8;

  {

    while (1) {

      if (!(s1_pos < s1_len)) {
        if (!(s2_pos < s2_len)) {
          goto while_break;
        }
      }
      first_diff = 0;
      while (1) {

        if (s1_pos < s1_len) {
          tmp___3 = c_isdigit((int)*(s1 + s1_pos));
          if (tmp___3) {
            goto _L;
          }
        } else {
        _L:
          if (s2_pos < s2_len) {
            tmp___4 = c_isdigit((int)*(s2 + s2_pos));
            if (tmp___4) {
              goto while_break___0;
            }
          } else {
            goto while_break___0;
          }
        }
        if (s1_pos == s1_len) {
          tmp___0 = 0;
        } else {
          tmp = order((unsigned char)*(s1 + s1_pos));
          tmp___0 = tmp;
        }
        s1_c = tmp___0;
        if (s2_pos == s2_len) {
          tmp___2 = 0;
        } else {
          tmp___1 = order((unsigned char)*(s2 + s2_pos));
          tmp___2 = tmp___1;
        }
        s2_c = tmp___2;
        if (s1_c != s2_c) {
          return ((int __attribute__((__pure__)))(s1_c - s2_c));
        }
        s1_pos++;
        s2_pos++;
      }
    while_break___0:;
      while (1) {

        if (!((int const) * (s1 + s1_pos) == 48)) {
          goto while_break___1;
        }
        s1_pos++;
      }
    while_break___1:;
      while (1) {

        if (!((int const) * (s2 + s2_pos) == 48)) {
          goto while_break___2;
        }
        s2_pos++;
      }
    while_break___2:;
      while (1) {
        tmp___5 = c_isdigit((int)*(s1 + s1_pos));
        if (tmp___5) {
          tmp___6 = c_isdigit((int)*(s2 + s2_pos));
          if (!tmp___6) {
            goto while_break___3;
          }
        } else {
          goto while_break___3;
        }
        if (!first_diff) {
          first_diff =
              (int)((int const) * (s1 + s1_pos) - (int const) * (s2 + s2_pos));
        }
        s1_pos++;
        s2_pos++;
      }
    while_break___3:
      tmp___7 = c_isdigit((int)*(s1 + s1_pos));
      if (tmp___7) {
        return ((int __attribute__((__pure__)))1);
      }
      tmp___8 = c_isdigit((int)*(s2 + s2_pos));
      if (tmp___8) {
        return ((int __attribute__((__pure__))) - 1);
      }
      if (first_diff) {
        return ((int __attribute__((__pure__)))first_diff);
      }
    }
  while_break:;
  }
}
int filevercmp(char const *s1, char const *s2) {
  char const *s1_pos;
  char const *s2_pos;
  char const *s1_suffix;
  char const *s2_suffix;
  size_t s1_len;
  size_t s2_len;
  int result;
  int simple_cmp;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  char const *tmp___4;
  char const *tmp___5;
  int tmp___6;
  int tmp___7;

  {
    tmp = strcmp(s1, s2);
    simple_cmp = tmp;
    if (simple_cmp == 0) {
      return (0);
    }
    if (!*s1) {
      return (-1);
    }
    if (!*s2) {
      return (1);
    }
    tmp___0 = strcmp(".", s1);
    if (0 == tmp___0) {
      return (-1);
    }
    tmp___1 = strcmp(".", s2);
    if (0 == tmp___1) {
      return (1);
    }
    tmp___2 = strcmp("..", s1);
    if (0 == tmp___2) {
      return (-1);
    }
    tmp___3 = strcmp("..", s2);
    if (0 == tmp___3) {
      return (1);
    }
    if ((int const) * s1 == 46) {
      if ((int const) * s2 != 46) {
        return (-1);
      }
    }
    if ((int const) * s1 != 46) {
      if ((int const) * s2 == 46) {
        return (1);
      }
    }
    if ((int const) * s1 == 46) {
      if ((int const) * s2 == 46) {
        s1++;
        s2++;
      }
    }
    s1_pos = s1;
    s2_pos = s2;
    s1_suffix = match_suffix(&s1_pos);
    s2_suffix = match_suffix(&s2_pos);
    if (s1_suffix) {
      tmp___4 = s1_suffix;
    } else {
      tmp___4 = s1_pos;
    }
    s1_len = (size_t)(tmp___4 - s1);
    if (s2_suffix) {
      tmp___5 = s2_suffix;
    } else {
      tmp___5 = s2_pos;
    }
    s2_len = (size_t)(tmp___5 - s2);
    if (s1_suffix) {
      goto _L;
    } else {
      if (s2_suffix) {
      _L:
        if (s1_len == s2_len) {
          tmp___6 = strncmp(s1, s2, s1_len);
          if (0 == tmp___6) {
            s1_len = (size_t)(s1_pos - s1);
            s2_len = (size_t)(s2_pos - s2);
          }
        }
      }
    }
    result = (int)verrevcmp(s1, s1_len, s2, s2_len);
    if (result == 0) {
      tmp___7 = simple_cmp;
    } else {
      tmp___7 = result;
    }
    return (tmp___7);
  }
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"

int fd_safer(int fd) {

  {}
}

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {

  int result;

  { result = fclose(fp); }
}

int dup_safer(int fd) {

  {}
}

extern char *optarg;

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1))) pthread_mutex_unlock)(pthread_mutex_t *__mutex);

static int decimal_point;
static int thousands_sep;
static _Bool hard_LC_COLLATE;

static char eolchar = (char)'\n';
static _Bool blanks[256];
static _Bool nonprinting[256];
static _Bool nondictionary[256];
static char fold_toupper[256];
static struct month monthtab[12] = {
    {"APR", 4}, {"AUG", 8}, {"DEC", 12}, {"FEB", 2},  {"JAN", 1},  {"JUL", 7},
    {"JUN", 6}, {"MAR", 3}, {"MAY", 5},  {"NOV", 11}, {"OCT", 10}, {"SEP", 9}};
static size_t merge_buffer_size = (size_t)262144;
static size_t sort_size;

static _Bool reverse;
static _Bool stable;
static int tab = 128;
static _Bool unique;

static struct keyfield *keylist;

static void die(char const *message, char const *file) {

  char const *tmp___0;
  int *tmp___1;

  {

    tmp___1 = __errno_location();
    error(0, *tmp___1, "%s: %s", message, tmp___0);
    exit(2);
  }
}

void usage(int status) {

  { exit(status); }
}
static char const short_options[31] = {
    (char const)'-', (char const)'b', (char const)'c',   (char const)'C',
    (char const)'d', (char const)'f', (char const)'g',   (char const)'h',
    (char const)'i', (char const)'k', (char const)':',   (char const)'m',
    (char const)'M', (char const)'n', (char const)'o',   (char const)':',
    (char const)'r', (char const)'R', (char const)'s',   (char const)'S',
    (char const)':', (char const)'t', (char const)':',   (char const)'T',
    (char const)':', (char const)'u', (char const)'V',   (char const)'y',
    (char const)':', (char const)'z', (char const)'\000'};
static struct option const long_options___1[31] = {
    {"ignore-leading-blanks", 0, (int *)((void *)0), 'b'},
    {"check", 2, (int *)((void *)0), 128},
    {"compress-program", 1, (int *)((void *)0), 129},
    {"debug", 0, (int *)((void *)0), 130},
    {"dictionary-order", 0, (int *)((void *)0), 'd'},
    {"ignore-case", 0, (int *)((void *)0), 'f'},
    {"files0-from", 1, (int *)((void *)0), 131},
    {"general-numeric-sort", 0, (int *)((void *)0), 'g'},
    {"ignore-nonprinting", 0, (int *)((void *)0), 'i'},
    {"key", 1, (int *)((void *)0), 'k'},
    {"merge", 0, (int *)((void *)0), 'm'},
    {"month-sort", 0, (int *)((void *)0), 'M'},
    {"numeric-sort", 0, (int *)((void *)0), 'n'},
    {"human-numeric-sort", 0, (int *)((void *)0), 'h'},
    {"version-sort", 0, (int *)((void *)0), 'V'},
    {"random-sort", 0, (int *)((void *)0), 'R'},
    {"random-source", 1, (int *)((void *)0), 133},
    {"sort", 1, (int *)((void *)0), 134},
    {"output", 1, (int *)((void *)0), 'o'},
    {"reverse", 0, (int *)((void *)0), 'r'},
    {"stable", 0, (int *)((void *)0), 's'},
    {"batch-size", 1, (int *)((void *)0), 132},
    {"buffer-size", 1, (int *)((void *)0), 'S'},
    {"field-separator", 1, (int *)((void *)0), 't'},
    {"temporary-directory", 1, (int *)((void *)0), 'T'},
    {"unique", 0, (int *)((void *)0), 'u'},
    {"zero-terminated", 0, (int *)((void *)0), 'z'},
    {"parallel", 1, (int *)((void *)0), 135},
    {"help", 0, (int *)((void *)0), -130},
    {"version", 0, (int *)((void *)0), -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
static char const *const check_args[4] = {"quiet", "silent", "diagnose-first",
                                          (char const *)((void *)0)};
static char const check_types[3] = {(char const)'C', (char const)'C',
                                    (char const)'c'};
static char const *const sort_args[7] = {
    "general-numeric", "human-numeric",          "month", "numeric", "random",
    "version",         (char const *)((void *)0)};
static char const sort_types[6] = {(char const)'g', (char const)'h',
                                   (char const)'M', (char const)'n',
                                   (char const)'R', (char const)'V'};
static sigset_t caught_signals;

static struct tempnode *volatile temphead;

static FILE *stream_open(char const *file, char const *how) {

  FILE *tmp___0;

  {
    if (!file) {
      return (stdout);
    }

    tmp___0 = fopen_safer(file, how);
    return (tmp___0);
  }
}
static FILE *xfopen(char const *file, char const *how) {
  FILE *fp;
  FILE *tmp;

  {
    tmp = stream_open(file, how);
    fp = tmp;

    return (fp);
  }
}
static void xfclose(FILE *fp, char const *file) {

  { ; }
}

static struct tempnode *maybe_create_temp(FILE **pfp,
                                          _Bool survive_fd_exhaustion) {

  {}
}
static struct tempnode *create_temp(FILE **pfp) {

  {}
}
static FILE *open_temp(struct tempnode *temp) {
  int tempfd;

  {

    close(tempfd);

    ;
  }
}

static void zaptemp(char const *name) {

  { ; }
}

static void inittables(void) {
  size_t i;

  int tmp___0;
  unsigned short const **tmp___1;
  int tmp___2;
  unsigned short const **tmp___3;

  int tmp___5;

  {
    i = (size_t)0;
    while (1) {

      if (!(i < 256UL)) {
        goto while_break;
      }

      tmp___0 = 0;

      blanks[i] = (_Bool)tmp___0;
      tmp___1 = __ctype_b_loc();

      nonprinting[i] = (_Bool)tmp___2;
      tmp___3 = __ctype_b_loc();

      nondictionary[i] = (_Bool)tmp___5;
      fold_toupper[i] = (char)toupper((int)i);
      i++;
    }
  while_break:;
  }
}

static size_t default_sort_size(void) {

  double total;
  double tmp___0;
  double mem;
  double tmp___1;
  struct rlimit rlimit;
  size_t size;
  int tmp___2;

  size_t tmp___5;

  {

    tmp___0 = physmem_total();
    total = tmp___0;

    tmp___1 = total / (double)8;

    mem = tmp___1;
    size = 0xffffffffffffffffUL;
    tmp___2 = getrlimit((__rlimit_resource_t)2, &rlimit);

    size = (size_t)mem;

    tmp___5 = size;

    return (tmp___5);
  }
}
static size_t size_bound;
static size_t sort_buffer_size(FILE *const *fps, size_t nfps,
                               char *const *files, size_t nfiles,
                               size_t line_bytes) {

  size_t size;
  size_t i;
  struct stat st;
  off_t file_size;
  size_t worst_case;

  int tmp___0;
  int tmp___1;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {

    i = (size_t)0;

    if (i < nfps) {
      tmp___0 = fileno((FILE *)*(fps + i));
      tmp___1 = fstat(tmp___0, &st);
      tmp___7 = tmp___1;
    } else {
      tmp___6 = strcmp((char const *)*(files + i), "-");
      if (tmp___6 == 0) {
        tmp___3 = fstat(0, &st);
        tmp___5 = tmp___3;
      } else {
        tmp___4 = stat((char const *)*(files + i), &st);
        tmp___5 = tmp___4;
      }
      tmp___7 = tmp___5;
    }

    if ((st.st_mode & 61440U) == 32768U) {
      file_size = st.st_size;
    } else {
      if (sort_size) {
        return (sort_size);
      }
      file_size = (off_t)131072;
    }

    size_bound = default_sort_size();

    return (size_bound);

    if (size_bound - size <= worst_case) {
      return (size_bound);
    }

    ;
  }
}
static void initbuf(struct buffer *buf___1, size_t line_bytes, size_t alloc) {
  size_t tmp;
  size_t tmp___0;

  {

    buf___1->buf = (char *)malloc(alloc);

  while_break:

    buf___1->alloc = alloc;
    tmp___0 = (size_t)0;
    buf___1->nlines = tmp___0;
    tmp = tmp___0;

    buf___1->used = tmp;
  }
}
__inline static struct line *buffer_linelim(struct buffer const *buf___1) {

  { return ((struct line *)(buf___1->buf + buf___1->alloc)); }
}
static char *begfield(struct line const *line, struct keyfield const *key) {
  char *ptr;
  char *lim;
  size_t sword;

  size_t tmp;
  unsigned char tmp___0;
  unsigned char tmp___1;
  size_t tmp___2;
  unsigned char tmp___3;

  {
    ptr = (char *)line->text;
    lim = (ptr + line->length) - 1;
    sword = (size_t)key->sword;

    if (tab != 128) {
      while (1) {

        if ((unsigned long)ptr < (unsigned long)lim) {
          tmp = sword;
          sword--;
          if (!tmp) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        while (1) {

          if ((unsigned long)ptr < (unsigned long)lim) {
            if (!((int)*ptr != tab)) {
              goto while_break___0;
            }
          } else {
            goto while_break___0;
          }
          ptr++;
        }
      while_break___0:;
        if ((unsigned long)ptr < (unsigned long)lim) {
          ptr++;
        }
      }
    while_break:;
    } else {
      while (1) {

        if ((unsigned long)ptr < (unsigned long)lim) {
          tmp___2 = sword;
          sword--;
          if (!tmp___2) {
            goto while_break___1;
          }
        } else {
          goto while_break___1;
        }
        while (1) {

          if ((unsigned long)ptr < (unsigned long)lim) {
            tmp___0 = to_uchar(*ptr);
            if (!blanks[tmp___0]) {
              goto while_break___2;
            }
          } else {
            goto while_break___2;
          }
          ptr++;
        }
      while_break___2:;
        while (1) {

          if ((unsigned long)ptr < (unsigned long)lim) {
            tmp___1 = to_uchar(*ptr);
            if (blanks[tmp___1]) {
              goto while_break___3;
            }
          } else {
            goto while_break___3;
          }
          ptr++;
        }
      while_break___3:;
      }
    while_break___1:;
    }
    if (key->skipsblanks) {
      while (1) {

        if ((unsigned long)ptr < (unsigned long)lim) {
          tmp___3 = to_uchar(*ptr);
          if (!blanks[tmp___3]) {
            goto while_break___4;
          }
        } else {
          goto while_break___4;
        }
        ptr++;
      }
    while_break___4:;
    }

    return (ptr);
  }
}
static char *limfield(struct line const *line, struct keyfield const *key) {
  char *ptr;
  char *lim;
  size_t eword;
  size_t echar;
  size_t tmp;
  unsigned char tmp___0;
  unsigned char tmp___1;
  size_t tmp___2;
  unsigned char tmp___3;

  {
    ptr = (char *)line->text;
    lim = (ptr + line->length) - 1;
    eword = (size_t)key->eword;
    echar = (size_t)key->echar;
    if (echar == 0UL) {
      eword++;
    }
    if (tab != 128) {
      while (1) {

        if ((unsigned long)ptr < (unsigned long)lim) {
          tmp = eword;
          eword--;
          if (!tmp) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        while (1) {

          if ((unsigned long)ptr < (unsigned long)lim) {
            if (!((int)*ptr != tab)) {
              goto while_break___0;
            }
          } else {
            goto while_break___0;
          }
          ptr++;
        }
      while_break___0:;
        if ((unsigned long)ptr < (unsigned long)lim) {
          if (eword) {
            ptr++;
          } else {
            if (echar) {
              ptr++;
            }
          }
        }
      }
    while_break:;
    } else {
      while (1) {

        if ((unsigned long)ptr < (unsigned long)lim) {
          tmp___2 = eword;
          eword--;
          if (!tmp___2) {
            goto while_break___1;
          }
        } else {
          goto while_break___1;
        }
        while (1) {

          if ((unsigned long)ptr < (unsigned long)lim) {
            tmp___0 = to_uchar(*ptr);
            if (!blanks[tmp___0]) {
              goto while_break___2;
            }
          } else {
            goto while_break___2;
          }
          ptr++;
        }
      while_break___2:;
        while (1) {

          if ((unsigned long)ptr < (unsigned long)lim) {
            tmp___1 = to_uchar(*ptr);
            if (blanks[tmp___1]) {
              goto while_break___3;
            }
          } else {
            goto while_break___3;
          }
          ptr++;
        }
      while_break___3:;
      }
    while_break___1:;
    }
    if (echar != 0UL) {
      if (key->skipeblanks) {
        while (1) {

          if ((unsigned long)ptr < (unsigned long)lim) {
            tmp___3 = to_uchar(*ptr);
            if (!blanks[tmp___3]) {
              goto while_break___4;
            }
          } else {
            goto while_break___4;
          }
          ptr++;
        }
      while_break___4:;
      }
      if ((unsigned long)lim < (unsigned long)(ptr + echar)) {
        ptr = lim;
      } else {
        ptr += echar;
      }
    }
    return (ptr);
  }
}
static _Bool fillbuf___7(struct buffer *buf___1, FILE *fp, char const *file) {
  struct keyfield const *key;
  char eol;
  size_t line_bytes;

  char *ptr;
  struct line *linelim;
  struct line *tmp;
  struct line *line;
  size_t avail;
  char *line_start;
  char *tmp___0;
  size_t readsize;
  size_t bytes_read;
  size_t tmp___1;
  char *ptrlim;
  char *p;

  struct line *tmp___8;

  {
    key = (struct keyfield const *)keylist;
    eol = eolchar;

    ptr = buf___1->buf + buf___1->used;
    tmp = buffer_linelim((struct buffer const *)buf___1);
    linelim = tmp;
    line = linelim - buf___1->nlines;

    if (buf___1->nlines) {
      tmp___0 = line->text + line->length;
    } else {
      tmp___0 = buf___1->buf;
    }
    line_start = tmp___0;

    tmp___1 = fread_unlocked((void *)ptr, (size_t)1, readsize, fp);
    bytes_read = tmp___1;
    ptrlim = ptr + bytes_read;

    buf___1->eof = (_Bool)1;
    if ((unsigned long)buf___1->buf == (unsigned long)ptrlim) {
      return ((_Bool)0);
    }

    while (1) {
      p = (char *)memchr((void const *)ptr, (int)eol, (size_t)(ptrlim - ptr));
      if (!p) {
        goto while_break___1;
      }
      *p = (char)'\000';
      ptr = p + 1;
      line--;
      line->text = line_start;
      line->length = (size_t)(ptr - line_start);

      avail -= line_bytes;

      line->keylim = p;

      line->keybeg = begfield((struct line const *)line, key);

      line_start = ptr;
    }
  while_break___1:

  while_break___0:
    buf___1->used = (size_t)(ptr - buf___1->buf);
    tmp___8 = buffer_linelim((struct buffer const *)buf___1);
    buf___1->nlines = (size_t)(tmp___8 - line);
  }
}
static char const unit_order[256] = {
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
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)6,
    (char const)0, (char const)3, (char const)0, (char const)0, (char const)0,
    (char const)1, (char const)0, (char const)2, (char const)0, (char const)0,
    (char const)5, (char const)0, (char const)0, (char const)0, (char const)4,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)8,
    (char const)7, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)1, (char const)0, (char const)0,
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
    (char const)0};
static int __attribute__((__pure__)) find_unit_order(char const *number) {
  _Bool minus_sign;
  char const *p;
  int nonzero;
  unsigned char ch;
  char const *tmp;
  char const *tmp___0;
  int order___0;
  int tmp___1;

  {
    minus_sign = (_Bool)((int const) * number == 45);
    p = number + (int)minus_sign;
    nonzero = 0;
    while (1) {

      while (1) {
        tmp = p;
        p++;
        ch = (unsigned char)*tmp;
        if (!((unsigned int)ch - 48U <= 9U)) {
          goto while_break___0;
        }
        nonzero |= (int)ch - 48;
      }
    while_break___0:;
      if (!((int)ch == thousands_sep)) {
        goto while_break;
      }
    }
  while_break:;
    if ((int)ch == decimal_point) {
      while (1) {
        tmp___0 = p;
        p++;
        ch = (unsigned char)*tmp___0;
        if (!((unsigned int)ch - 48U <= 9U)) {
          goto while_break___1;
        }
        nonzero |= (int)ch - 48;
      }
    while_break___1:;
    }
    if (nonzero) {
      order___0 = (int)unit_order[ch];
      if (minus_sign) {
        tmp___1 = -order___0;
      } else {
        tmp___1 = order___0;
      }
      return ((int __attribute__((__pure__)))tmp___1);
    } else {
      return ((int __attribute__((__pure__)))0);
    }
  }
}
static int human_numcompare(char const *a, char const *b) {

  int tmp___4;

  {

    ;

    return (tmp___4);
  }
}
static int numcompare___3(char const *a, char const *b) {
  unsigned char tmp;

  int tmp___1;

  {
    while (1) {
      tmp = to_uchar((char)*a);
      if (!blanks[tmp]) {
        goto while_break;
      }
      a++;
    }
  while_break:;

    tmp___1 = (int)strnumcmp(a, b, decimal_point, thousands_sep);
    return (tmp___1);
  }
}

static int general_numcompare(char const *sa, char const *sb) {
  char *ea;
  char *eb;
  long double a;
  long double tmp;
  long double b;
  long double tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {
    tmp = strtold(sa, &ea);
    a = tmp;
    tmp___0 = strtold(sb, &eb);
    b = tmp___0;
    if ((unsigned long)sa == (unsigned long)ea) {
      if ((unsigned long)sb == (unsigned long)eb) {
        tmp___1 = 0;
      } else {
        tmp___1 = -1;
      }
      return (tmp___1);
    }
    if ((unsigned long)sb == (unsigned long)eb) {
      return (1);
    }
    if (a < b) {
      tmp___7 = -1;
    } else {
      if (a > b) {
        tmp___6 = 1;
      } else {
        if (a == b) {
          tmp___5 = 0;
        } else {
          if (b == b) {
            tmp___4 = -1;
          } else {
            if (a == a) {
              tmp___3 = 1;
            } else {
              tmp___2 = nan_compare(sa, sb);
              tmp___3 = tmp___2;
            }
            tmp___4 = tmp___3;
          }
          tmp___5 = tmp___4;
        }
        tmp___6 = tmp___5;
      }
      tmp___7 = tmp___6;
    }
    return (tmp___7);
  }
}
static int getmonth(char const *month, char **ea) {
  size_t lo;
  size_t hi;
  unsigned char tmp;
  size_t ix;
  char const *m;
  char const *n;
  unsigned char tmp___0;
  unsigned char tmp___1;
  unsigned char tmp___2;
  unsigned char tmp___3;
  unsigned char tmp___4;
  unsigned char tmp___5;

  {
    lo = (size_t)0;
    hi = (size_t)12;
    while (1) {
      tmp = to_uchar((char)*month);
      if (!blanks[tmp]) {
        goto while_break;
      }
      month++;
    }
  while_break:;
    while (1) {
      ix = (lo + hi) / 2UL;
      m = month;
      n = monthtab[ix].name;
      while (1) {

        if (!*n) {
          if (ea) {
            *ea = (char *)m;
          }
          return (monthtab[ix].val);
        }
        tmp___3 = to_uchar((char)*m);
        tmp___4 = to_uchar(fold_toupper[tmp___3]);
        tmp___5 = to_uchar((char)*n);
        if ((int)tmp___4 < (int)tmp___5) {
          hi = ix;
          goto while_break___1;
        } else {
          tmp___0 = to_uchar((char)*m);
          tmp___1 = to_uchar(fold_toupper[tmp___0]);
          tmp___2 = to_uchar((char)*n);
          if ((int)tmp___1 > (int)tmp___2) {
            lo = ix + 1UL;
            goto while_break___1;
          }
        }
        m++;
        n++;
      }
    while_break___1:;
      if (!(lo < hi)) {
        goto while_break___0;
      }
    }
  while_break___0:;
    return (0);
  }
}
static struct md5_ctx random_md5_state;

static int compare_random(char *__restrict texta, size_t lena,
                          char *__restrict textb, size_t lenb) {
  int xfrm_diff;
  char stackbuf[4000];
  char *buf___1;
  size_t bufsize___1;
  void *allocated;
  uint32_t dig[2][16UL / sizeof(uint32_t)];
  struct md5_ctx s[2];
  char const *lima;
  char const *limb;
  size_t guess_bufsize;
  size_t sizea;
  size_t tmp;
  size_t tmp___0;
  _Bool a_fits;
  size_t sizeb;
  size_t tmp___1;
  char *tmp___2;
  size_t tmp___3;
  size_t tmp___4;
  size_t tmp___5;
  size_t tmp___6;
  size_t tmp___7;
  int diff;
  int tmp___8;
  size_t tmp___9;

  {
    xfrm_diff = 0;
    buf___1 = stackbuf;
    bufsize___1 = sizeof(stackbuf);
    allocated = (void *)0;
    s[1] = random_md5_state;
    s[0] = s[1];
    if (hard_LC_COLLATE) {
      lima = (char const *)(texta + lena);
      limb = (char const *)(textb + lenb);
      while (1) {
        guess_bufsize = 3UL * (lena + lenb) + 2UL;
        if (bufsize___1 < guess_bufsize) {
          if (guess_bufsize > (bufsize___1 * 3UL) / 2UL) {
            bufsize___1 = guess_bufsize;
          } else {
            bufsize___1 = (bufsize___1 * 3UL) / 2UL;
          }
          free(allocated);
          allocated = malloc(bufsize___1);
          buf___1 = (char *)allocated;
          if (!buf___1) {
            buf___1 = stackbuf;
            bufsize___1 = sizeof(stackbuf);
          }
        }
        if ((unsigned long)texta < (unsigned long)lima) {
          tmp = xstrxfrm(buf___1, (char const *)texta, bufsize___1);
          tmp___0 = tmp + 1UL;
        } else {
          tmp___0 = (size_t)0;
        }
        sizea = tmp___0;
        a_fits = (_Bool)(sizea <= bufsize___1);
        if ((unsigned long)textb < (unsigned long)limb) {
          if (a_fits) {
            tmp___1 = bufsize___1 - sizea;
          } else {
            tmp___1 = (size_t)0;
          }
          if (a_fits) {
            tmp___2 = buf___1 + sizea;
          } else {
            tmp___2 = (char *)((void *)0);
          }
          tmp___3 = xstrxfrm(tmp___2, (char const *)textb, tmp___1);
          tmp___4 = tmp___3 + 1UL;
        } else {
          tmp___4 = (size_t)0;
        }
        sizeb = tmp___4;
        if (a_fits) {
          if (!(sizea + sizeb <= bufsize___1)) {
            goto _L;
          }
        } else {
        _L:
          bufsize___1 = sizea + sizeb;
          if (bufsize___1 < 6148914691236517205UL) {
            bufsize___1 = (bufsize___1 * 3UL) / 2UL;
          }
          free(allocated);
          allocated = xmalloc(bufsize___1);
          buf___1 = (char *)allocated;
          if ((unsigned long)texta < (unsigned long)lima) {
            strxfrm(buf___1, (char const *)texta, sizea);
          }
          if ((unsigned long)textb < (unsigned long)limb) {
            strxfrm(buf___1 + sizea, (char const *)textb, sizeb);
          }
        }
        if ((unsigned long)texta < (unsigned long)lima) {
          tmp___5 = strlen((char const *)texta);
          texta += tmp___5 + 1UL;
        }
        if ((unsigned long)textb < (unsigned long)limb) {
          tmp___6 = strlen((char const *)textb);
          textb += tmp___6 + 1UL;
        }
        if (!((unsigned long)texta < (unsigned long)lima)) {
          if (!((unsigned long)textb < (unsigned long)limb)) {
            lena = sizea;
            texta = buf___1;
            lenb = sizeb;
            textb = buf___1 + sizea;
            goto while_break;
          }
        }
        md5_process_bytes((void const *)buf___1, sizea, &s[0]);
        md5_process_bytes((void const *)(buf___1 + sizea), sizeb, &s[1]);
        if (!xfrm_diff) {
          if (sizea < sizeb) {
            tmp___7 = sizea;
          } else {
            tmp___7 = sizeb;
          }
          xfrm_diff = memcmp((void const *)buf___1,
                             (void const *)(buf___1 + sizea), tmp___7);
          if (!xfrm_diff) {
            xfrm_diff = (sizea > sizeb) - (sizea < sizeb);
          }
        }
      }
    while_break:;
    }
    md5_process_bytes((void const *)texta, lena, &s[0]);
    md5_finish_ctx(&s[0], (void *)(dig[0]));
    md5_process_bytes((void const *)textb, lenb, &s[1]);
    md5_finish_ctx(&s[1], (void *)(dig[1]));
    tmp___8 =
        memcmp((void const *)(dig[0]), (void const *)(dig[1]), sizeof(dig[0]));
    diff = tmp___8;
    if (!diff) {
      if (!xfrm_diff) {
        if (lena < lenb) {
          tmp___9 = lena;
        } else {
          tmp___9 = lenb;
        }
        xfrm_diff = memcmp((void const *)texta, (void const *)textb, tmp___9);
        if (!xfrm_diff) {
          xfrm_diff = (lena > lenb) - (lena < lenb);
        }
      }
      diff = xfrm_diff;
    }
    free(allocated);
    return (diff);
  }
}

__inline static _Bool key_numeric(struct keyfield const *key) {
  int tmp;

  {
    if (key->numeric) {
      tmp = 1;
    } else {
      if (key->general_numeric) {
        tmp = 1;
      } else {
        if (key->human_numeric) {
          tmp = 1;
        } else {
          tmp = 0;
        }
      }
    }
    return ((_Bool)tmp);
  }
}

static _Bool default_key_compare(struct keyfield const *key) {

  int tmp___0;

  { return ((_Bool)tmp___0); }
}
static void key_to_opts(struct keyfield const *key, char *opts___1) {
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

  {
    if (key->skipsblanks) {
      tmp = opts___1;
      opts___1++;
      *tmp = (char)'b';
    } else {
      if (key->skipeblanks) {
        tmp = opts___1;
        opts___1++;
        *tmp = (char)'b';
      }
    }
    if ((unsigned long)key->ignore == (unsigned long)(nondictionary)) {
      tmp___0 = opts___1;
      opts___1++;
      *tmp___0 = (char)'d';
    }
    if (key->translate) {
      tmp___1 = opts___1;
      opts___1++;
      *tmp___1 = (char)'f';
    }
    if (key->general_numeric) {
      tmp___2 = opts___1;
      opts___1++;
      *tmp___2 = (char)'g';
    }
    if (key->human_numeric) {
      tmp___3 = opts___1;
      opts___1++;
      *tmp___3 = (char)'h';
    }
    if ((unsigned long)key->ignore == (unsigned long)(nonprinting)) {
      tmp___4 = opts___1;
      opts___1++;
      *tmp___4 = (char)'i';
    }
    if (key->month) {
      tmp___5 = opts___1;
      opts___1++;
      *tmp___5 = (char)'M';
    }
    if (key->numeric) {
      tmp___6 = opts___1;
      opts___1++;
      *tmp___6 = (char)'n';
    }
    if (key->random) {
      tmp___7 = opts___1;
      opts___1++;
      *tmp___7 = (char)'R';
    }
    if (key->reverse) {
      tmp___8 = opts___1;
      opts___1++;
      *tmp___8 = (char)'r';
    }
    if (key->version) {
      tmp___9 = opts___1;
      opts___1++;
      *tmp___9 = (char)'V';
    }
    *opts___1 = (char)'\000';
    return;
  }
}
static void key_warnings(struct keyfield const *gkey, _Bool gkey_only) {
  struct keyfield const *key;
  struct keyfield ugkey;
  unsigned long keynum;
  size_t sword;
  size_t eword;
  char tmp[((sizeof(uintmax_t) * 8UL) * 146UL + 484UL) / 485UL + 1UL];
  char
      obuf[(((sizeof(sword) * 8UL) * 146UL + 484UL) / 485UL + 1UL) * 2UL + 4UL];
  char
      nbuf[(((sizeof(sword) * 8UL) * 146UL + 484UL) / 485UL + 1UL) * 2UL + 5UL];
  char *po;
  char *pn;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  char const *tmp___8;
  char const *tmp___9;
  char *tmp___10;
  char *tmp___11;
  _Bool implicit_skip;
  _Bool tmp___12;
  int tmp___13;
  _Bool maybe_space_aligned;
  _Bool tmp___14;
  int tmp___15;
  _Bool line_offset;
  int tmp___16;
  char *tmp___17;
  size_t sword___0;
  size_t eword___0;
  char *tmp___18;
  _Bool tmp___19;
  _Bool ugkey_reverse;
  char opts___1[sizeof(short_options)];
  size_t tmp___20;
  unsigned long tmp___21;
  char *tmp___22;
  _Bool tmp___23;
  char *tmp___24;

  {
    ugkey = (struct keyfield) * gkey;
    keynum = 1UL;
    key = (struct keyfield const *)keylist;
    while (1) {

      if (!key) {
        goto while_break;
      }
      if (key->obsolete_used) {
        sword = (size_t)key->sword;
        eword = (size_t)key->eword;
        po = obuf;
        pn = nbuf;
        if (sword == 0xffffffffffffffffUL) {
          sword++;
        }
        tmp___0 = umaxtostr(sword, tmp);
        tmp___1 = stpcpy(po, "+");
        po = stpcpy(tmp___1, (char const *)tmp___0);
        tmp___2 = umaxtostr(sword + 1UL, tmp);
        tmp___3 = stpcpy(pn, "-k ");
        pn = stpcpy(tmp___3, (char const *)tmp___2);
        if (key->eword != 0xffffffffffffffffUL) {
          tmp___4 = umaxtostr(eword + 1UL, tmp);
          tmp___5 = stpcpy(po, " -");
          stpcpy(tmp___5, (char const *)tmp___4);
          tmp___6 = umaxtostr((eword + 1UL) +
                                  (size_t)(key->echar == 0xffffffffffffffffUL),
                              tmp);
          tmp___7 = stpcpy(pn, ",");
          stpcpy(tmp___7, (char const *)tmp___6);
        }
        tmp___8 = quote_n(1, (char const *)(nbuf));
        tmp___9 = quote_n(0, (char const *)(obuf));
        tmp___10 = gettext("obsolescent key %s used; consider %s instead");
        error(0, 0, (char const *)tmp___10, tmp___9, tmp___8);
      }
      if (key->sword != 0xffffffffffffffffUL) {
        if (key->eword < key->sword) {
          tmp___11 = gettext("key %lu has zero width and will be ignored");
          error(0, 0, (char const *)tmp___11, keynum);
        }
      }
      tmp___12 = key_numeric(key);
      if (tmp___12) {
        tmp___13 = 1;
      } else {
        if (key->month) {
          tmp___13 = 1;
        } else {
          tmp___13 = 0;
        }
      }
      implicit_skip = (_Bool)tmp___13;
      if (!hard_LC_COLLATE) {
        tmp___14 = default_key_compare(key);
        if (tmp___14) {
          if (key->schar) {
            tmp___15 = 0;
          } else {
            if (key->echar) {
              tmp___15 = 0;
            } else {
              tmp___15 = 1;
            }
          }
        } else {
          tmp___15 = 0;
        }
      } else {
        tmp___15 = 0;
      }
      maybe_space_aligned = (_Bool)tmp___15;
      if (key->eword == 0UL) {
        if (key->echar != 0UL) {
          tmp___16 = 1;
        } else {
          tmp___16 = 0;
        }
      } else {
        tmp___16 = 0;
      }
      line_offset = (_Bool)tmp___16;
      if (!gkey_only) {
        if (tab == 128) {
          if (!line_offset) {
            if (!key->skipsblanks) {
              if (implicit_skip) {
                goto _L___0;
              } else {
                if (maybe_space_aligned) {
                  goto _L___0;
                } else {
                  tmp___17 = gettext("leading blanks are significant in key "
                                     "%lu; consider also specifying \'b\'");
                  error(0, 0, (char const *)tmp___17, keynum);
                }
              }
            } else {
            _L___0:
              if (!key->skipsblanks) {
                if (key->schar) {
                  tmp___17 = gettext("leading blanks are significant in key "
                                     "%lu; consider also specifying \'b\'");
                  error(0, 0, (char const *)tmp___17, keynum);
                } else {
                  goto _L;
                }
              } else {
              _L:
                if (!key->skipeblanks) {
                  if (key->echar) {
                    tmp___17 = gettext("leading blanks are significant in key "
                                       "%lu; consider also specifying \'b\'");
                    error(0, 0, (char const *)tmp___17, keynum);
                  }
                }
              }
            }
          }
        }
      }
      if (!gkey_only) {
        tmp___19 = key_numeric(key);
        if (tmp___19) {
          sword___0 = (size_t)(key->sword + 1UL);
          eword___0 = (size_t)(key->eword + 1UL);
          if (!sword___0) {
            sword___0++;
          }
          if (!eword___0) {
            tmp___18 = gettext("key %lu is numeric and spans multiple fields");
            error(0, 0, (char const *)tmp___18, keynum);
          } else {
            if (sword___0 < eword___0) {
              tmp___18 =
                  gettext("key %lu is numeric and spans multiple fields");
              error(0, 0, (char const *)tmp___18, keynum);
            }
          }
        }
      }
      if (ugkey.ignore) {
        if ((unsigned long)ugkey.ignore == (unsigned long)key->ignore) {
          ugkey.ignore = (_Bool const *)((void *)0);
        }
      }
      if (ugkey.translate) {
        if ((unsigned long)ugkey.translate == (unsigned long)key->translate) {
          ugkey.translate = (char const *)((void *)0);
        }
      }
      ugkey.skipsblanks = (_Bool)((int)ugkey.skipsblanks & !key->skipsblanks);
      ugkey.skipeblanks = (_Bool)((int)ugkey.skipeblanks & !key->skipeblanks);
      ugkey.month = (_Bool)((int)ugkey.month & !key->month);
      ugkey.numeric = (_Bool)((int)ugkey.numeric & !key->numeric);
      ugkey.general_numeric =
          (_Bool)((int)ugkey.general_numeric & !key->general_numeric);
      ugkey.human_numeric =
          (_Bool)((int)ugkey.human_numeric & !key->human_numeric);
      ugkey.random = (_Bool)((int)ugkey.random & !key->random);
      ugkey.version = (_Bool)((int)ugkey.version & !key->version);
      ugkey.reverse = (_Bool)((int)ugkey.reverse & !key->reverse);
      key = (struct keyfield const *)key->next;
      keynum++;
    }
  while_break:
    tmp___23 = default_key_compare((struct keyfield const *)(&ugkey));
    if (tmp___23) {
      if (ugkey.reverse) {
        if (stable) {
          goto _L___2;
        } else {
          if (unique) {
          _L___2:
            if (keylist) {
            _L___1:
              ugkey_reverse = ugkey.reverse;
              if (!stable) {
                if (!unique) {
                  ugkey.reverse = (_Bool)0;
                }
              }
              key_to_opts((struct keyfield const *)(&ugkey), opts___1);
              tmp___20 = strlen((char const *)(opts___1));
              tmp___21 = select_plural(tmp___20);
              tmp___22 = ngettext("option \'-%s\' is ignored",
                                  "options \'-%s\' are ignored", tmp___21);
              error(0, 0, (char const *)tmp___22, opts___1);
              ugkey.reverse = ugkey_reverse;
            }
          }
        }
      }
    } else {
      goto _L___1;
    }
    if (ugkey.reverse) {
      if (!stable) {
        if (!unique) {
          if (keylist) {
            tmp___24 =
                gettext("option \'-r\' only applies to last-resort comparison");
            error(0, 0, (char const *)tmp___24);
          }
        }
      }
    }
    return;
  }
}
static int keycompare(struct line const *a, struct line const *b) {
  struct keyfield *key;
  char *texta;
  char *textb;
  char *lima;
  char *limb;
  int diff;
  char const *translate;
  _Bool const *ignore;
  size_t lena;
  size_t lenb;
  char *ta;
  char *tb;
  size_t tlena;
  size_t tlenb;
  char enda;
  char endb;
  void *allocated;
  char stackbuf[4000];
  size_t i;

  size_t tmp;
  unsigned char tmp___0;

  size_t tmp___2;
  unsigned char tmp___3;

  unsigned char tmp___7;
  unsigned char tmp___8;
  unsigned char tmp___9;
  unsigned char tmp___10;
  unsigned char tmp___11;
  unsigned char tmp___12;
  unsigned char tmp___13;
  unsigned char tmp___14;
  unsigned char tmp___15;
  unsigned char tmp___16;
  char *tmp___17;
  unsigned char tmp___18;
  unsigned char tmp___19;
  char *tmp___20;
  unsigned char tmp___21;
  unsigned char tmp___22;
  size_t tmp___23;

  unsigned char tmp___25;
  unsigned char tmp___26;
  int tmp___27;

  {
    key = keylist;
    texta = (char *)a->keybeg;
    textb = (char *)b->keybeg;
    lima = (char *)a->keylim;
    limb = (char *)b->keylim;

    translate = key->translate;

    lena = (size_t)(lima - texta);
    lenb = (size_t)(limb - textb);

    goto _L___2;

    if (key->version) {
    _L___2:

      if (translate) {

        ta = stackbuf;
        allocated = (void *)0;

        tb = (ta + lena) + 1;
        i = (size_t)0;
        tlena = i;
        while (1) {

          if (!(i < lena)) {
            goto while_break___0;
          }

          tmp = tlena;
          tlena++;

          tmp___0 = to_uchar(*(texta + i));
          *(ta + tmp) = (char)*(translate + (int)tmp___0);

          i++;
        }
      while_break___0:
        *(ta + tlena) = (char)'\000';
        i = (size_t)0;
        tlenb = i;
        while (1) {

          if (!(i < lenb)) {
            goto while_break___1;
          }

          tmp___2 = tlenb;
          tlenb++;

          tmp___3 = to_uchar(*(textb + i));
          *(tb + tmp___2) = (char)*(translate + (int)tmp___3);

          i++;
        }
      while_break___1:
        *(tb + tlenb) = (char)'\000';
      } else {
        ta = texta;
        tlena = lena;
        enda = *(ta + tlena);
        *(ta + tlena) = (char)'\000';
        tb = textb;
        tlenb = lenb;
        endb = *(tb + tlenb);
        *(tb + tlenb) = (char)'\000';
      }

      if (key->numeric) {
        diff = numcompare___3((char const *)ta, (char const *)tb);
      } else {

        diff = human_numcompare((char const *)ta, (char const *)tb);

        diff = xmemcoll0((char const *)ta, tlena + 1UL, (char const *)tb,
                         tlenb + 1UL);
      }
      if (ignore) {
        free(allocated);
      } else {
        if (translate) {
          free(allocated);
        } else {
          *(ta + tlena) = enda;
          *(tb + tlenb) = endb;
        }
      }
    } else {
      if (ignore) {
        if (translate) {
          while (1) {

            while (1) {

              while (1) {

                if ((unsigned long)texta < (unsigned long)lima) {
                  tmp___7 = to_uchar(*texta);
                  if (!*(ignore + (int)tmp___7)) {
                    goto while_break___4;
                  }
                } else {
                  goto while_break___4;
                }
                texta++;
              }
            while_break___4:;
              while (1) {

                if ((unsigned long)textb < (unsigned long)limb) {
                  tmp___8 = to_uchar(*textb);
                  if (!*(ignore + (int)tmp___8)) {
                    goto while_break___5;
                  }
                } else {
                  goto while_break___5;
                }
                textb++;
              }
            while_break___5:;
              if ((unsigned long)texta < (unsigned long)lima) {
                if (!((unsigned long)textb < (unsigned long)limb)) {
                  goto while_break___3;
                }
              } else {
                goto while_break___3;
              }
              tmp___9 = to_uchar(*texta);
              tmp___10 = to_uchar((char)*(translate + (int)tmp___9));
              tmp___11 = to_uchar(*textb);
              tmp___12 = to_uchar((char)*(translate + (int)tmp___11));
              diff = (int)tmp___10 - (int)tmp___12;
              if (diff) {
                goto not_equal;
              }
              texta++;
              textb++;
            }
          while_break___3:
            diff = ((unsigned long)texta < (unsigned long)lima) -
                   ((unsigned long)textb < (unsigned long)limb);
            goto while_break___2;
          }
        while_break___2:;
        } else {
          while (1) {

            while (1) {

              while (1) {

                if ((unsigned long)texta < (unsigned long)lima) {
                  tmp___13 = to_uchar(*texta);
                  if (!*(ignore + (int)tmp___13)) {
                    goto while_break___8;
                  }
                } else {
                  goto while_break___8;
                }
                texta++;
              }
            while_break___8:;
              while (1) {

                if ((unsigned long)textb < (unsigned long)limb) {
                  tmp___14 = to_uchar(*textb);
                  if (!*(ignore + (int)tmp___14)) {
                    goto while_break___9;
                  }
                } else {
                  goto while_break___9;
                }
                textb++;
              }
            while_break___9:;
              if ((unsigned long)texta < (unsigned long)lima) {
                if (!((unsigned long)textb < (unsigned long)limb)) {
                  goto while_break___7;
                }
              } else {
                goto while_break___7;
              }
              tmp___15 = to_uchar(*texta);
              tmp___16 = to_uchar(*textb);
              diff = (int)tmp___15 - (int)tmp___16;
              if (diff) {
                goto not_equal;
              }
              texta++;
              textb++;
            }
          while_break___7:
            diff = ((unsigned long)texta < (unsigned long)lima) -
                   ((unsigned long)textb < (unsigned long)limb);
            goto while_break___6;
          }
        while_break___6:;
        }
      } else {
        if (lena == 0UL) {
          diff = -(lenb != 0UL);
        } else {
          if (lenb == 0UL) {
            goto greater;
          } else {
            if (translate) {
              while (1) {

                if ((unsigned long)texta < (unsigned long)lima) {
                  if (!((unsigned long)textb < (unsigned long)limb)) {
                    goto while_break___10;
                  }
                } else {
                  goto while_break___10;
                }
                tmp___17 = texta;
                texta++;
                tmp___18 = to_uchar(*tmp___17);
                tmp___19 = to_uchar((char)*(translate + (int)tmp___18));
                tmp___20 = textb;
                textb++;
                tmp___21 = to_uchar(*tmp___20);
                tmp___22 = to_uchar((char)*(translate + (int)tmp___21));
                diff = (int)tmp___19 - (int)tmp___22;
                if (diff) {
                  goto not_equal;
                }
              }
            while_break___10:;
            } else {
              if (lena < lenb) {
                tmp___23 = lena;
              } else {
                tmp___23 = lenb;
              }
              diff = memcmp((void const *)texta, (void const *)textb, tmp___23);
              if (diff) {
                goto not_equal;
              }
            }
            if (lena < lenb) {
              diff = -1;
            } else {
              diff = lena != lenb;
            }
          }
        }
      }
    }

    goto not_equal;

    key = key->next;

    if (key->eword != 0xffffffffffffffffUL) {
      lima = limfield(a, (struct keyfield const *)key);
      limb = limfield(b, (struct keyfield const *)key);
    } else {
      lima = (char *)((a->text + a->length) - 1);
      limb = (char *)((b->text + b->length) - 1);
    }
    if (key->sword != 0xffffffffffffffffUL) {
      texta = begfield(a, (struct keyfield const *)key);
      textb = begfield(b, (struct keyfield const *)key);
    } else {
      texta = (char *)a->text;
      textb = (char *)b->text;
      if (key->skipsblanks) {
        while (1) {

          if ((unsigned long)texta < (unsigned long)lima) {
            tmp___25 = to_uchar(*texta);
            if (!blanks[tmp___25]) {
              goto while_break___11;
            }
          } else {
            goto while_break___11;
          }
          texta++;
        }
      while_break___11:;
        while (1) {

          if ((unsigned long)textb < (unsigned long)limb) {
            tmp___26 = to_uchar(*textb);
            if (!blanks[tmp___26]) {
              goto while_break___12;
            }
          } else {
            goto while_break___12;
          }
          textb++;
        }
      while_break___12:;
      }
    }

  while_break:;
    return (0);
  greater:
    diff = 1;
  not_equal:

    tmp___27 = diff;

    return (tmp___27);
  }
}
static int compare(struct line const *a, struct line const *b) {
  int diff;
  size_t alen;
  size_t blen;
  size_t tmp;
  int tmp___0;

  {

    diff = keycompare(a, b);
    if (diff) {
      return (diff);
    } else {
    }

    if (hard_LC_COLLATE) {
      diff = xmemcoll0((char const *)a->text, alen + 1UL, (char const *)b->text,
                       blen + 1UL);
    } else {

      diff = memcmp((void const *)a->text, (void const *)b->text, tmp);
      if (!diff) {
        if (alen < blen) {
          diff = -1;
        } else {
          diff = alen != blen;
        }
      }
    }

    tmp___0 = diff;

    return (tmp___0);
  }
}
static void write_line(struct line const *line, FILE *fp,
                       char const *output_file) {
  char *buf___1;
  size_t n_bytes;
  char *ebuf;

  size_t tmp___3;

  {
    buf___1 = (char *)line->text;
    n_bytes = (size_t)line->length;
    ebuf = buf___1 + n_bytes;

  _L:
    *(ebuf + -1) = eolchar;
    tmp___3 = fwrite_unlocked((void const *)buf___1, (size_t)1, n_bytes, fp);

    return;
  }
}

static size_t open_input_files(struct sortfile *files, size_t nfiles,
                               FILE ***pfps) {
  FILE **fps;
  FILE **tmp;
  int i;
  FILE *tmp___0;
  FILE *tmp___1;

  {

    fps = tmp;

    while (1) {

      if (!((size_t)i < nfiles)) {
        goto while_break;
      }
      if ((files + i)->temp) {
        if ((int)((files + i)->temp)->state != 0) {
          tmp___0 = open_temp((files + i)->temp);
          *(fps + i) = tmp___0;
        } else {
          tmp___1 = stream_open((files + i)->name, "r");
          *(fps + i) = tmp___1;
        }
      } else {
        tmp___1 = stream_open((files + i)->name, "r");
        *(fps + i) = tmp___1;
      }
      if (!*(fps + i)) {
        goto while_break;
      }
      i++;
    }
  while_break:;
    return ((size_t)i);
  }
}
static void mergefps(struct sortfile *files, size_t ntemps, size_t nfiles,
                     FILE *ofp, char const *output_file, FILE **fps) {
  struct buffer *buffer;

  struct line saved___0;
  struct line const *savedline;
  size_t savealloc;
  struct line const **cur;

  struct line const **base;

  size_t *ord;

  size_t i;
  size_t j;
  size_t t;
  struct keyfield const *key;
  size_t tmp___3;
  struct line const *linelim;
  struct line const *tmp___4;
  _Bool tmp___5;
  int tmp___6;
  struct line const *smallest;
  int tmp___7;
  struct line const *linelim___0;
  struct line const *tmp___8;
  _Bool tmp___9;
  size_t lo;
  size_t hi;
  size_t probe;
  size_t ord0;
  size_t count_of_smaller_lines;
  int cmp;
  int tmp___10;

  {

    while (1) {

      if (!(i < nfiles)) {
        goto while_break;
      }
      if (merge_buffer_size > sort_size / nfiles) {
        tmp___3 = merge_buffer_size;
      } else {
        tmp___3 = sort_size / nfiles;
      }
      initbuf(buffer + i, sizeof(struct line), tmp___3);
      tmp___5 = fillbuf___7(buffer + i, *(fps + i), (files + i)->name);
      if (tmp___5) {
        tmp___4 = (struct line const *)buffer_linelim(
            (struct buffer const *)(buffer + i));
        linelim = tmp___4;
        *(cur + i) = linelim - 1;
        *(base + i) = linelim - (buffer + i)->nlines;
        i++;
      } else {
        xfclose(*(fps + i), (files + i)->name);
        if (i < ntemps) {
          ntemps--;
          zaptemp((files + i)->name);
        }
        free((void *)(buffer + i)->buf);
        nfiles--;
        j = i;
        while (1) {

          if (!(j < nfiles)) {
            goto while_break___0;
          }
          *(files + j) = *(files + (j + 1UL));
          *(fps + j) = *(fps + (j + 1UL));
          j++;
        }
      while_break___0:;
      }
    }
  while_break:

    while (1) {

      if (!(i < nfiles)) {
        goto while_break___2;
      }
      tmp___6 = compare(*(cur + *(ord + (i - 1UL))), *(cur + *(ord + i)));
      if (0 < tmp___6) {
        t = *(ord + (i - 1UL));
        *(ord + (i - 1UL)) = *(ord + i);
        *(ord + i) = t;
        i = (size_t)0;
      }
      i++;
    }
  while_break___2:;
    while (1) {
    while_continue___3:;
      if (!nfiles) {
        goto while_break___3;
      }
      smallest = *(cur + *(ord + 0));
      if (unique) {
        if (savedline) {
          tmp___7 = compare(savedline, smallest);
          if (tmp___7) {
            savedline = (struct line const *)((void *)0);
            write_line((struct line const *)(&saved___0), ofp, output_file);
          }
        }
        if (!savedline) {
          savedline = (struct line const *)(&saved___0);
          if (savealloc < (size_t)smallest->length) {
            while (1) {

              if (!savealloc) {
                savealloc = (size_t)smallest->length;
                goto while_break___4;
              }
              savealloc *= 2UL;
              if (!(savealloc < (size_t)smallest->length)) {
                goto while_break___4;
              }
            }
          while_break___4:
            free((void *)saved___0.text);
            saved___0.text = (char *)xmalloc(savealloc);
          }
          saved___0.length = (size_t)smallest->length;
          memcpy((void *)saved___0.text, (void const *)smallest->text,
                 saved___0.length);
          if (key) {
            saved___0.keybeg =
                saved___0.text + (smallest->keybeg - smallest->text);
            saved___0.keylim =
                saved___0.text + (smallest->keylim - smallest->text);
          }
        }
      } else {
        write_line(smallest, ofp, output_file);
      }
      if ((unsigned long)*(base + *(ord + 0)) < (unsigned long)smallest) {
        *(cur + *(ord + 0)) = smallest - 1;
      } else {
        tmp___9 = fillbuf___7(buffer + *(ord + 0), *(fps + *(ord + 0)),
                              (files + *(ord + 0))->name);
        if (tmp___9) {
          tmp___8 = (struct line const *)buffer_linelim(
              (struct buffer const *)(buffer + *(ord + 0)));
          linelim___0 = tmp___8;
          *(cur + *(ord + 0)) = linelim___0 - 1;
          *(base + *(ord + 0)) = linelim___0 - (buffer + *(ord + 0))->nlines;
        } else {
          i = (size_t)1;
          while (1) {

            if (!(i < nfiles)) {
              goto while_break___5;
            }
            if (*(ord + i) > *(ord + 0)) {
              (*(ord + i))--;
            }
            i++;
          }
        while_break___5:
          nfiles--;
          xfclose(*(fps + *(ord + 0)), (files + *(ord + 0))->name);
          if (*(ord + 0) < ntemps) {
            ntemps--;
            zaptemp((files + *(ord + 0))->name);
          }
          free((void *)(buffer + *(ord + 0))->buf);
          i = *(ord + 0);
          while (1) {

            if (!(i < nfiles)) {
              goto while_break___6;
            }
            *(fps + i) = *(fps + (i + 1UL));
            *(files + i) = *(files + (i + 1UL));
            *(buffer + i) = *(buffer + (i + 1UL));
            *(cur + i) = *(cur + (i + 1UL));
            *(base + i) = *(base + (i + 1UL));
            i++;
          }
        while_break___6:
          i = (size_t)0;
          while (1) {

            if (!(i < nfiles)) {
              goto while_break___7;
            }
            *(ord + i) = *(ord + (i + 1UL));
            i++;
          }
        while_break___7:;
          goto while_continue___3;
        }
      }
      lo = (size_t)1;
      hi = nfiles;
      probe = lo;
      ord0 = *(ord + 0);
      while (1) {

        if (!(lo < hi)) {
          goto while_break___8;
        }
        tmp___10 = compare(*(cur + ord0), *(cur + *(ord + probe)));
        cmp = tmp___10;
        if (cmp < 0) {
          hi = probe;
        } else {
          if (cmp == 0) {
            if (ord0 < *(ord + probe)) {
              hi = probe;
            } else {
              lo = probe + 1UL;
            }
          } else {
            lo = probe + 1UL;
          }
        }
        probe = (lo + hi) / 2UL;
      }
    while_break___8:
      count_of_smaller_lines = lo - 1UL;
      j = (size_t)0;
      while (1) {

        if (!(j < count_of_smaller_lines)) {
          goto while_break___9;
        }
        *(ord + j) = *(ord + (j + 1UL));
        j++;
      }
    while_break___9:
      *(ord + count_of_smaller_lines) = ord0;
    }
  while_break___3:;
  }
}
static size_t mergefiles(struct sortfile *files, size_t ntemps, size_t nfiles,
                         FILE *ofp, char const *output_file) {
  FILE **fps;
  size_t nopened;
  size_t tmp;

  {
    tmp = open_input_files(files, nfiles, &fps);
    nopened = tmp;
  }
}
static void mergelines(struct line *__restrict t, size_t nlines,
                       struct line const *__restrict lo) {
  size_t nlo;
  size_t nhi;
  struct line *hi;
  int tmp;

  {
    nlo = nlines / 2UL;
    nhi = nlines - nlo;
    hi = (struct line *)(t - nlo);
    while (1) {
      tmp =
          compare((struct line const *)(lo - 1), (struct line const *)(hi - 1));
      if (tmp <= 0) {
        t--;
        lo--;
        *t = (struct line) * lo;
        nlo--;
        if (!nlo) {
          return;
        }
      } else {
        t--;
        hi--;
        *t = *hi;
        nhi--;
        if (!nhi) {
          while (1) {
            t--;
            lo--;
            *t = (struct line) * lo;
            nlo--;
            if (!nlo) {
              goto while_break___0;
            }
          }
        while_break___0:;
          return;
        }
      }
    }
  }
}
static void sequential_sort(struct line *__restrict lines, size_t nlines,
                            struct line *__restrict temp, _Bool to_temp) {
  int swap___1;
  int tmp;
  size_t nlo;
  size_t nhi;
  struct line *lo;
  struct line *hi;
  size_t tmp___0;
  struct line *dest;
  struct line const *sorted_lo;

  {
    if (nlines == 2UL) {
      tmp = compare((struct line const *)(lines + -1),
                    (struct line const *)(lines + -2));
      swap___1 = 0 < tmp;
      if (to_temp) {
        *(temp + -1) = *(lines + (-1 - swap___1));
        *(temp + -2) = *(lines + (-2 + swap___1));
      } else {
        if (swap___1) {
          *(temp + -1) = *(lines + -1);
          *(lines + -1) = *(lines + -2);
          *(lines + -2) = *(temp + -1);
        }
      }
    } else {
      nlo = nlines / 2UL;
      nhi = nlines - nlo;
      lo = (struct line *)lines;
      hi = (struct line *)(lines - nlo);
      if (to_temp) {
        tmp___0 = nlo;
      } else {
        tmp___0 = (size_t)0;
      }
      sequential_sort(hi, nhi, temp - tmp___0, to_temp);
      if (1UL < nlo) {
        sequential_sort(lo, nlo, temp, (_Bool)(!to_temp));
      } else {

        *(temp + -1) = *(lo + -1);
      }
      if (to_temp) {
        dest = (struct line *)temp;
        sorted_lo = (struct line const *)lines;
      } else {
        dest = (struct line *)lines;
        sorted_lo = (struct line const *)temp;
      }
      mergelines(dest, nlines, sorted_lo);
    }
    return;
  }
}
static struct merge_node *init_node(struct merge_node *__restrict parent,
                                    struct merge_node *__restrict node_pool,
                                    struct line *dest, size_t nthreads,
                                    size_t total_lines, _Bool is_lo_child);
static struct merge_node *merge_tree_init(size_t nthreads, size_t nlines,
                                          struct line *dest) {
  struct merge_node *merge_tree;
  struct merge_node *tmp;
  struct merge_node *root;

  size_t tmp___3;

  {
    tmp = (struct merge_node *)xmalloc((2UL * sizeof(*merge_tree)) * nthreads);
    merge_tree = tmp;
    root = merge_tree;

    tmp___3 = nlines;
    root->nhi = tmp___3;

    init_node(root, root + 1, dest, nthreads, nlines, (_Bool)0);
    return (merge_tree);
  }
}

static struct merge_node *init_node(struct merge_node *__restrict parent,
                                    struct merge_node *__restrict node_pool,
                                    struct line *dest, size_t nthreads,
                                    size_t total_lines, _Bool is_lo_child) {
  size_t nlines;
  size_t tmp;
  size_t nlo;
  size_t nhi;
  struct line *lo;
  struct line *hi;
  struct line **parent_end;
  struct line **tmp___0;
  struct merge_node *node;
  struct merge_node *__restrict tmp___1;
  struct line *tmp___2;
  struct line *tmp___3;
  size_t lo_threads;
  size_t hi_threads;
  struct merge_node *tmp___4;
  struct merge_node *tmp___5;

  {

    tmp = parent->nhi;

    nlines = tmp;
    nlo = nlines / 2UL;
    nhi = nlines - nlo;
    lo = dest - total_lines;
    hi = lo - nlo;

    parent_end = tmp___0;
    tmp___1 = node_pool;
    node_pool++;
    node = (struct merge_node *)tmp___1;
    tmp___2 = lo;
    node->end_lo = tmp___2;
    node->lo = tmp___2;
    tmp___3 = hi;
    node->end_hi = tmp___3;
    node->hi = tmp___3;
    node->dest = parent_end;
    node->nlo = nlo;
    node->nhi = nhi;
    node->parent = (struct merge_node *)parent;
    node->level = parent->level + 1U;
    node->queued = (_Bool)0;
    pthread_mutex_init(&node->lock, (pthread_mutexattr_t const *)((void *)0));
    if (nthreads > 1UL) {
      lo_threads = nthreads / 2UL;
      hi_threads = nthreads - lo_threads;
      node->lo_child = (struct merge_node *)node_pool;
      tmp___4 =
          init_node(node, node_pool, lo, lo_threads, total_lines, (_Bool)1);
      node_pool = tmp___4;
      node->hi_child = (struct merge_node *)node_pool;
      tmp___5 =
          init_node(node, node_pool, hi, hi_threads, total_lines, (_Bool)0);
      node_pool = tmp___5;
    } else {
      node->lo_child = (struct merge_node *)((void *)0);
      node->hi_child = (struct merge_node *)((void *)0);
    }
    return ((struct merge_node *)node_pool);
  }
}
static int compare_nodes(void const *a, void const *b) {
  struct merge_node const *nodea;
  struct merge_node const *nodeb;

  {

    nodeb = (struct merge_node const *)b;
    if (nodea->level == nodeb->level) {
      return (nodea->nlo + nodea->nhi < nodeb->nlo + nodeb->nhi);
    }
  }
}

__inline static void unlock_node(struct merge_node *node) {

  { pthread_mutex_unlock(&node->lock); }
}
static void queue_destroy(struct merge_node_queue *queue) {

  {
    heap_free(queue->priority_queue);
    pthread_cond_destroy(&queue->cond);
    pthread_mutex_destroy(&queue->mutex);
    return;
  }
}
static void queue_init(struct merge_node_queue *queue, size_t nthreads) {

  { queue->priority_queue = heap_alloc(&compare_nodes, 2UL * nthreads); }
}
static void queue_insert(struct merge_node_queue *queue,
                         struct merge_node *node) {

  { heap_insert(queue->priority_queue, (void *)node); }
}
static struct merge_node *queue_pop(struct merge_node_queue *queue) {
  struct merge_node *node;

  {

    node = (struct merge_node *)heap_remove_top(queue->priority_queue);

  while_break:

    return (node);
  }
}

static void write_unique(struct line const *line, FILE *tfp,
                         char const *temp_output) {

  { write_line(line, tfp, temp_output); }
}
static void mergelines_node(struct merge_node *__restrict node,
                            size_t total_lines, FILE *tfp,
                            char const *temp_output) {
  struct line *lo_orig;
  struct line *hi_orig;
  size_t to_merge;
  size_t merged_lo;
  size_t merged_hi;
  struct line *dest;
  int tmp;
  size_t tmp___0;
  size_t tmp___1;
  size_t tmp___2;
  int tmp___3;

  {
    lo_orig = node->lo;
    hi_orig = node->hi;

    if (node->level > 1U) {

      while (1) {

        if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
          if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
            tmp___0 = to_merge;
            to_merge--;
            if (!tmp___0) {
              goto while_break;
            }
          } else {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        tmp = compare((struct line const *)(node->lo - 1),
                      (struct line const *)(node->hi - 1));
        if (tmp <= 0) {
          dest--;
          (node->lo)--;
          *dest = *(node->lo);
        } else {
          dest--;
          (node->hi)--;
          *dest = *(node->hi);
        }
      }
    while_break:
      merged_lo = (size_t)(lo_orig - node->lo);
      merged_hi = (size_t)(hi_orig - node->hi);
      if (node->nhi == merged_hi) {
        while (1) {

          if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
            tmp___1 = to_merge;
            to_merge--;
            if (!tmp___1) {
              goto while_break___0;
            }
          } else {
            goto while_break___0;
          }
          dest--;
          (node->lo)--;
          *dest = *(node->lo);
        }
      while_break___0:;
      } else {
        if (node->nlo == merged_lo) {
          while (1) {

            if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
              tmp___2 = to_merge;
              to_merge--;
              if (!tmp___2) {
                goto while_break___1;
              }
            } else {
              goto while_break___1;
            }
            dest--;
            (node->hi)--;
            *dest = *(node->hi);
          }
        while_break___1:;
        }
      }
      *(node->dest) = dest;
    } else {

      if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
        if ((unsigned long)node->hi != (unsigned long)node->end_hi) {

        } else {
          goto while_break___2;
        }
      } else {
        goto while_break___2;
      }
      tmp___3 = compare((struct line const *)(node->lo - 1),
                        (struct line const *)(node->hi - 1));
      if (tmp___3 <= 0) {
        (node->lo)--;
        write_unique((struct line const *)node->lo, tfp, temp_output);
      } else {
        (node->hi)--;
        write_unique((struct line const *)node->hi, tfp, temp_output);
      }

    while_break___2:
      merged_lo = (size_t)(lo_orig - node->lo);
      merged_hi = (size_t)(hi_orig - node->hi);
      if (node->nhi == merged_hi) {

        (node->lo)--;
        write_unique((struct line const *)node->lo, tfp, temp_output);

      while_break___3:;
      } else {
        if (node->nlo == merged_lo) {

          if ((unsigned long)node->hi != (unsigned long)node->end_hi) {

            to_merge--;

          } else {
            goto while_break___4;
          }
          (node->hi)--;
          write_unique((struct line const *)node->hi, tfp, temp_output);

        while_break___4:;
        }
      }
    }
    merged_lo = (size_t)(lo_orig - node->lo);
    merged_hi = (size_t)(hi_orig - node->hi);
    node->nlo -= merged_lo;
    node->nhi -= merged_hi;
    return;
  }
}
static void queue_check_insert(struct merge_node_queue *queue,
                               struct merge_node *node) {
  _Bool lo_avail;

  { queue_insert(queue, node); }
}
static void queue_check_insert_parent(struct merge_node_queue *queue,
                                      struct merge_node *node) {

  {

    if (node->nlo + node->nhi == 0UL) {
      queue_insert(queue, node->parent);
    }
  }
}
static void merge_loop(struct merge_node_queue *queue, size_t total_lines,
                       FILE *tfp, char const *temp_output) {
  struct merge_node *node;
  struct merge_node *tmp;

  {
    while (1) {
      tmp = queue_pop(queue);
      node = tmp;
      if (node->level == 0U) {

        goto while_break;
      }
      mergelines_node(node, total_lines, tfp, temp_output);
      queue_check_insert(queue, node);
      queue_check_insert_parent(queue, node);
    }
  while_break:;
  }
}

static void sortlines(struct line *__restrict lines, size_t nthreads,
                      size_t total_lines, struct merge_node *node,
                      struct merge_node_queue *queue, FILE *tfp,
                      char const *temp_output) {
  size_t nlines;
  size_t lo_threads;
  size_t hi_threads;
  pthread_t thread;
  struct thread_args args;
  size_t nlo;
  size_t nhi;
  struct line *temp;
  int tmp;

  {

    args.nthreads = lo_threads;

    args.node = node->lo_child;

    if (131072UL <= nlines) {

      if (tmp == 0) {
        sortlines(lines - node->nlo, hi_threads, total_lines, node->hi_child,
                  queue, tfp, temp_output);
        pthread_join(thread, (void **)((void *)0));
      } else {
        goto _L___0;
      }
    } else {
      goto _L___0;
    }

  _L___0:
    nlo = node->nlo;
    nhi = node->nhi;
    temp = (struct line *)(lines - total_lines);

    sequential_sort(lines - nlo, nhi, temp - nlo / 2UL, (_Bool)0);

    sequential_sort(lines, nlo, temp, (_Bool)0);

    node->lo = (struct line *)lines;
    node->hi = (struct line *)(lines - nlo);
    node->end_lo = (struct line *)(lines - nlo);
    node->end_hi = (struct line *)((lines - nlo) - nhi);
    queue_insert(queue, node);
    merge_loop(queue, total_lines, tfp, temp_output);
  }
}
static void avoid_trashing_input(struct sortfile *files, size_t ntemps,
                                 size_t nfiles, char const *outfile) {
  size_t i;
  _Bool got_outstat;
  struct stat outstat;
  struct tempnode *tempcopy;
  _Bool is_stdin;
  int tmp;
  _Bool same;
  struct stat instat;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  FILE *tftp;

  {

    while (1) {

      if (!(i < nfiles)) {
        goto while_break;
      }
      tmp = strcmp((files + i)->name, "-");
      is_stdin = (_Bool)(tmp == 0);
      if (outfile) {
        tmp___7 = strcmp(outfile, (files + i)->name);
        if (tmp___7 == 0) {
          if (!is_stdin) {
            same = (_Bool)1;
          } else {
            goto _L___0;
          }
        } else {
          goto _L___0;
        }
      } else {
      _L___0:
        if (!got_outstat) {
          if (outfile) {
            tmp___0 = stat(outfile, &outstat);
            tmp___2 = tmp___0;
          } else {
            tmp___1 = fstat(1, &outstat);
            tmp___2 = tmp___1;
          }
          if (tmp___2 != 0) {
            goto while_break;
          }
          got_outstat = (_Bool)1;
        }
        if (is_stdin) {
          tmp___3 = fstat(0, &instat);
          tmp___5 = tmp___3;
        } else {
          tmp___4 = stat((files + i)->name, &instat);
          tmp___5 = tmp___4;
        }
        if (tmp___5 == 0) {
          if (instat.st_ino == outstat.st_ino) {
            if (instat.st_dev == outstat.st_dev) {
              tmp___6 = 1;
            } else {
              tmp___6 = 0;
            }
          } else {
            tmp___6 = 0;
          }
        } else {
          tmp___6 = 0;
        }
        same = (_Bool)tmp___6;
      }
      if (same) {
        if (!tempcopy) {
          tempcopy = create_temp(&tftp);
          mergefiles(files + i, (size_t)0, (size_t)1, tftp,
                     (char const *)(tempcopy->name));
        }
        (files + i)->name = (char const *)(tempcopy->name);
        (files + i)->temp = tempcopy;
      }
      i++;
    }
  while_break:;
  }
}
static void merge(struct sortfile *files, size_t ntemps, size_t nfiles,
                  char const *output_file) {
  size_t in;

  size_t tmp___2;

  FILE **fps;
  size_t nopened;
  size_t tmp___8;
  FILE *ofp;
  FILE *tmp___9;
  char *tmp___10;
  int *tmp___11;
  char *tmp___12;
  FILE *tfp___1;
  struct tempnode *temp___1;
  size_t tmp___13;
  size_t tmp___14;

  {

  while_break:
    avoid_trashing_input(files, ntemps, nfiles, output_file);
    while (1) {
      tmp___8 = open_input_files(files, nfiles, &fps);
      nopened = tmp___8;
      if (nopened == nfiles) {
        tmp___9 = stream_open(output_file, "w");
        ofp = tmp___9;
        if (ofp) {
          mergefps(files, ntemps, nfiles, ofp, output_file, fps);
          goto while_break___1;
        }
        tmp___11 = __errno_location();
        if (*tmp___11 != 24) {
          tmp___10 = gettext("open failed");
          die((char const *)tmp___10, output_file);
        } else {
          if (nopened <= 2UL) {
            tmp___10 = gettext("open failed");
            die((char const *)tmp___10, output_file);
          }
        }
      } else {
        if (nopened <= 2UL) {
          tmp___12 = gettext("open failed");
          die((char const *)tmp___12, (files + nopened)->name);
        }
      }
      while (1) {
        nopened--;
        xfclose(*(fps + nopened), (files + nopened)->name);
        temp___1 = maybe_create_temp(&tfp___1, (_Bool)(!(nopened <= 2UL)));
        if (!(!temp___1)) {
          goto while_break___2;
        }
      }
    while_break___2:;
      if (ntemps < nopened) {
        tmp___13 = ntemps;
      } else {
        tmp___13 = nopened;
      }
      mergefps(files + 0, tmp___13, nopened, tfp___1,
               (char const *)(temp___1->name), fps);
      if (ntemps < nopened) {
        tmp___14 = ntemps;
      } else {
        tmp___14 = nopened;
      }
      ntemps -= tmp___14;
      (files + 0)->name = (char const *)(temp___1->name);
      (files + 0)->temp = temp___1;
      memmove((void *)(files + 1), (void const *)(files + nopened),
              (nfiles - nopened) * sizeof(*files));
      ntemps++;
      nfiles -= nopened - 1UL;
    }
  while_break___1:;
    return;
  }
}
static void sort(char *const *files, size_t nfiles, char const *output_file,
                 size_t nthreads) {
  struct buffer buf___1;
  size_t ntemps;
  _Bool output_file_created;
  char const *temp_output;
  char const *file;
  FILE *fp;
  FILE *tmp;
  FILE *tfp;
  size_t bytes_per_line;
  size_t tmp___0;
  size_t mult;
  size_t tmp___1;
  struct line *line;
  struct tempnode *tmp___2;
  struct merge_node_queue queue;
  struct merge_node *merge_tree;
  struct merge_node *tmp___3;
  struct merge_node *root;
  _Bool tmp___4;
  size_t i;
  struct tempnode *node;
  struct sortfile *tempfiles;
  struct sortfile *tmp___5;

  {
    ntemps = (size_t)0;

    buf___1.alloc = (size_t)0;
    while (1) {

      file = (char const *)*files;
      tmp = xfopen(file, "r");
      fp = tmp;

      bytes_per_line = mult * sizeof(struct line);

      if (!buf___1.alloc) {
        tmp___1 = sort_buffer_size((FILE *const *)(&fp), (size_t)1, files,
                                   nfiles, bytes_per_line);
        initbuf(&buf___1, bytes_per_line, tmp___1);
      }
      buf___1.eof = (_Bool)0;
      files++;
      nfiles--;

      tmp___4 = fillbuf___7(&buf___1, fp, file);

      if (nfiles) {

        buf___1.left = buf___1.used;
        goto while_break___1;
      }

      line = buffer_linelim((struct buffer const *)(&buf___1));
      if (buf___1.eof) {
        if (!nfiles) {
          if (!ntemps) {

            tfp = xfopen(output_file, "w");

          } else {
            ntemps++;
            tmp___2 = create_temp(&tfp);
            temp_output = (char const *)(tmp___2->name);
          }
        } else {
          ntemps++;
          tmp___2 = create_temp(&tfp);
          temp_output = (char const *)(tmp___2->name);
        }
      } else {
        ntemps++;
        tmp___2 = create_temp(&tfp);
        temp_output = (char const *)(tmp___2->name);
      }

      queue_init(&queue, nthreads);
      tmp___3 = merge_tree_init(nthreads, buf___1.nlines, line);
      merge_tree = tmp___3;
      root = merge_tree + 1;
      sortlines(line, nthreads, buf___1.nlines, root, &queue, tfp, temp_output);

      xfclose(tfp, temp_output);

      goto finish;

    while_break___1:
      xfclose(fp, file);
    }

    ;
  finish:

    if (!output_file_created) {
      node = (struct tempnode *)temphead;
      tmp___5 = (struct sortfile *)xnmalloc(ntemps, sizeof(*tempfiles));
      tempfiles = tmp___5;
      i = (size_t)0;
      while (1) {

        if (!node) {
          goto while_break___2;
        }
        (tempfiles + i)->name = (char const *)(node->name);
        (tempfiles + i)->temp = node;
        node = (struct tempnode *)node->next;
        i++;
      }
    while_break___2:
      merge(tempfiles, ntemps, ntemps, output_file);
      free((void *)tempfiles);
    }
  }
}
static void insertkey(struct keyfield *key_arg) {
  struct keyfield **p;
  struct keyfield *key;
  struct keyfield *tmp;

  {
    tmp = (struct keyfield *)xmemdup((void const *)key_arg, sizeof(*key));
    key = tmp;
    p = &keylist;

    *p = key;
  }
}

static void check_ordering_compatibility(void) {
  struct keyfield *key;
  char opts___1[sizeof(short_options)];
  _Bool tmp;
  _Bool tmp___0;

  {
    key = keylist;
    while (1) {

      if (!key) {
        goto while_break;
      }
      if (1 < ((((int)key->numeric + (int)key->general_numeric) +
                (int)key->human_numeric) +
               (int)key->month) +
                  (((int)key->version | (int)key->random) | !(!key->ignore))) {
        tmp___0 = (_Bool)0;
        key->reverse = tmp___0;
        tmp = tmp___0;
        key->skipeblanks = tmp;
        key->skipsblanks = tmp;
        key_to_opts((struct keyfield const *)key, opts___1);
        incompatible_options((char const *)(opts___1));
      }
      key = key->next;
    }
  while_break:;
    return;
  }
}
static char const *parse_field_count(char const *string, size_t *val,
                                     char const *msgid) {
  char *suffix;
  uintmax_t n;
  strtol_error tmp;
  char const *tmp___0;
  char *tmp___1;
  char *tmp___2;

  {
    tmp = xstrtoumax(string, &suffix, 10, &n, "");
    if ((unsigned int)tmp == 0U) {
      goto case_0;
    }
    if ((unsigned int)tmp == 2U) {
      goto case_0;
    }
    if ((unsigned int)tmp == 1U) {
      goto case_1;
    }
    if ((unsigned int)tmp == 3U) {
      goto case_1;
    }
    if ((unsigned int)tmp == 4U) {
      goto case_4;
    }
    goto switch_break;
  case_0:
    *val = n;
    if (*val == n) {
      goto switch_break;
    }
  case_1:
    *val = 0xffffffffffffffffUL;
    goto switch_break;
  case_4:
    if (msgid) {
      tmp___0 = quote(string);
      tmp___1 = gettext(msgid);
      tmp___2 = gettext("%s: invalid count at start of %s");
      error(2, 0, (char const *)tmp___2, tmp___1, tmp___0);
    }
    return ((char const *)((void *)0));
  switch_break:;
    return ((char const *)suffix);
  }
}
static char *set_ordering(char const *s, struct keyfield *key,
                          enum blanktype blanktype) {

  {

    if (!*s) {
    }

    if ((int const) * s == 110) {
      goto case_110;
    }

    key->translate = (char const *)(fold_toupper);
    goto switch_break;

  case_110:
    key->numeric = (_Bool)1;

  switch_break:

  while_break:;
  }
}
static struct keyfield *key_init(struct keyfield *key) {

  {
    memset((void *)key, 0, sizeof(*key));
    key->eword = 0xffffffffffffffffUL;
  }
}

int main(int argc, char **argv) {
  struct keyfield *key;
  struct keyfield key_buf;
  struct keyfield gkey;

  char const *s;
  int c;

  _Bool mergeonly;

  _Bool need_random;
  size_t nthreads;
  size_t nfiles;

  char **files;
  char *files_from;
  struct Tokens tok;
  char const *outfile;
  struct lconv const *locale;
  struct lconv const *tmp___1;

  int oi;

  size_t tmp___10;

  char str[2];

  size_t tmp___17;

  FILE *stream;
  char const *tmp___27;
  char *tmp___28;
  char *tmp___29;
  char const *tmp___30;
  char *tmp___31;
  int *tmp___32;
  int tmp___33;
  char const *tmp___34;
  char *tmp___35;
  _Bool tmp___36;
  int tmp___37;
  size_t i___0;
  char const *tmp___38;
  char *tmp___39;
  unsigned long file_number;
  char *tmp___40;
  char *tmp___41;
  int tmp___42;
  char const *tmp___43;
  char *tmp___44;
  _Bool tmp___45;

  struct sortfile *sortfiles;

  size_t i___1;

  size_t nthreads_max;

  {

    nfiles = (size_t)0;

    files_from = (char *)((void *)0);

    setlocale(6, "");

    hard_LC_COLLATE = hard_locale(3);

    tmp___1 = (struct lconv const *)localeconv();
    locale = tmp___1;

    thousands_sep = (int)to_uchar(*(locale->thousands_sep));

    inittables();

    key_init(&gkey);

    files = (char **)xnmalloc((size_t)argc, sizeof(*files));
    while (1) {

    _L___1:
      c = getopt_long(argc, (char *const *)argv, short_options,
                      long_options___1, &oi);
      if (c == -1) {

        goto while_break___1;

      } else {
        if (c == 1) {
          goto case_1;
        }

        goto case_98;

      case_1:

        tmp___10 = nfiles;
        nfiles++;
        *(files + tmp___10) = optarg;

      case_98:
        str[0] = (char)c;

        set_ordering((char const *)(str), &gkey, (enum blanktype)2);
        goto switch_break;

      case_99:

        key = key_init(&key_buf);

        if (!key->sword) {
          if (!key->schar) {
            key->sword = 0xffffffffffffffffUL;
          }
        }

        if ((int const) * s != 44) {
          key->eword = 0xffffffffffffffffUL;
          key->echar = (size_t)0;
        } else {
          s = parse_field_count(s + 1, &key->eword,
                                "invalid number after \',\'");
          tmp___17 = key->eword;
          (key->eword)--;
          if (!tmp___17) {
            badfieldspec((char const *)optarg, "field number is zero");
          }
          if ((int const) * s == 46) {
            s = parse_field_count(s + 1, &key->echar,
                                  "invalid number after \'.\'");
          }
          s = (char const *)set_ordering(s, key, (enum blanktype)1);
        }

        insertkey(key);

      switch_break:;
      }
    }
  while_break___1:;
    if (files_from) {
      if (nfiles) {
        tmp___27 = quote((char const *)*(files + 0));
        tmp___28 = gettext("extra operand %s");
        error(0, 0, (char const *)tmp___28, tmp___27);
        tmp___29 =
            gettext("file operands cannot be combined with --files0-from");
        fprintf(stderr, "%s\n", tmp___29);
        usage(2);
      }
      tmp___33 = strcmp((char const *)files_from, "-");
      if (tmp___33 == 0) {
        stream = stdin;
      } else {
        stream = fopen_safer((char const *)files_from, "r");
        if ((unsigned long)stream == (unsigned long)((void *)0)) {
          tmp___30 = quote((char const *)files_from);
          tmp___31 = gettext("cannot open %s for reading");
          tmp___32 = __errno_location();
          error(2, *tmp___32, (char const *)tmp___31, tmp___30);
        }
      }
      readtokens0_init(&tok);
      tmp___36 = readtokens0(stream, &tok);
      if (tmp___36) {
        tmp___37 = rpl_fclose(stream);
        if (tmp___37 != 0) {
          tmp___34 = quote((char const *)files_from);
          tmp___35 = gettext("cannot read file names from %s");
          error(2, 0, (char const *)tmp___35, tmp___34);
        }
      } else {
        tmp___34 = quote((char const *)files_from);
        tmp___35 = gettext("cannot read file names from %s");
        error(2, 0, (char const *)tmp___35, tmp___34);
      }
      if (tok.n_tok) {
        free((void *)files);
        files = tok.tok;
        nfiles = tok.n_tok;
        i___0 = (size_t)0;
        while (1) {

          if (!(i___0 < nfiles)) {
            goto while_break___3;
          }
          tmp___42 = strcmp((char const *)*(files + i___0), "-");
          if (tmp___42 == 0) {
            tmp___38 = quote((char const *)*(files + i___0));
            tmp___39 = gettext("when reading file names from stdin, no file "
                               "name of %s allowed");
            error(2, 0, (char const *)tmp___39, tmp___38);
          } else {
            if ((int)*(*(files + i___0) + 0) == 0) {
              file_number = i___0 + 1UL;
              tmp___40 = quotearg_colon((char const *)files_from);
              tmp___41 = gettext("%s:%lu: invalid zero-length file name");
              error(2, 0, (char const *)tmp___41, tmp___40, file_number);
            }
          }
          i___0++;
        }
      while_break___3:;
      } else {
        tmp___43 = quote((char const *)files_from);
        tmp___44 = gettext("no input from %s");
        error(2, 0, (char const *)tmp___44, tmp___43);
      }
    }
    key = keylist;
    while (1) {

      if (!key) {
        goto while_break___4;
      }
      tmp___45 = default_key_compare((struct keyfield const *)key);
      if (tmp___45) {
        if (!key->reverse) {
          key->ignore = gkey.ignore;
          key->translate = gkey.translate;
          key->skipsblanks = gkey.skipsblanks;
          key->skipeblanks = gkey.skipeblanks;
          key->month = gkey.month;
          key->numeric = gkey.numeric;
          key->general_numeric = gkey.general_numeric;
          key->human_numeric = gkey.human_numeric;
          key->version = gkey.version;
          key->random = gkey.random;
          key->reverse = gkey.reverse;
        }
      }
      need_random = (_Bool)((int)need_random | (int)key->random);
      key = key->next;
    }
  while_break___4:;

    insertkey(&gkey);

    reverse = gkey.reverse;

    if (mergeonly) {

      i___1 = (size_t)0;

      merge(sortfiles, (size_t)0, nfiles, outfile);
    } else {

      nthreads = (size_t)8;

      nthreads_max = 0xffffffffffffffffUL / (2UL * sizeof(struct merge_node));

      sort((char *const *)files, nfiles, outfile, nthreads);
    }
  }
}
