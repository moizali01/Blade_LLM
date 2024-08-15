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
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  __syscall_slong_t __glibc_reserved[3];
};
typedef __ino_t ino_t;
typedef __dev_t dev_t;
struct hash_tuning {

  float growth_threshold;
  float growth_factor;
  _Bool is_n_buckets;
};
typedef struct hash_tuning Hash_tuning;

struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
typedef unsigned long uintmax_t;
typedef long __off64_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;
struct _IO_marker {};
struct _IO_FILE {
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;

  char *_IO_write_base;
  char *_IO_write_ptr;

  char *_IO_save_base;

  struct _IO_FILE *_chain;

  __off_t _old_offset;

  _IO_lock_t *_lock;
  __off64_t _offset;
};
typedef __off_t off_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;

struct allocator {
  void *(*allocate)(size_t);
  void *(*reallocate)(void *, size_t);
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
struct option {};
typedef unsigned int uint32_t;
typedef int __pid_t;
typedef __pid_t pid_t;
typedef int wchar_t;

typedef unsigned int wint_t;

struct timeval {
  __time_t tv_sec;
};

struct __anonstruct___mbstate_t_22 {};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
typedef __mbstate_t mbstate_t;
struct mbchar {
  char const *ptr;
  size_t bytes;
  _Bool wc_valid;
  wchar_t wc;
};
struct __anonstruct___sigset_t_9 {
  unsigned long __val[1024UL / (8UL * sizeof(unsigned long))];
};
typedef struct __anonstruct___sigset_t_9 __sigset_t;
typedef __sigset_t sigset_t;

union __anonunion_temp_26 {
  long tempint;
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
};
union __anonunion_data_31 {

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

  union __anonunion_buf_30 buf;
};

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

struct __anonstruct_cpu_set_t_24 {};
typedef struct __anonstruct_cpu_set_t_24 cpu_set_t;
struct md5_ctx {

  uint32_t buflen;
};
struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_mutex_s {

  unsigned int __count;
  int __owner;

  int __kind;

  __pthread_list_t __list;
};
union __anonunion_pthread_mutex_t_11 {
  struct __pthread_mutex_s __data;
};
typedef union __anonunion_pthread_mutex_t_11 pthread_mutex_t;

typedef union __anonunion_pthread_mutexattr_t_12 pthread_mutexattr_t;

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
  ino_t st_ino;
  dev_t st_dev;
};

union __anonunion___sigaction_handler_41 {
  void (*sa_handler)(int);
};
struct sigaction {
  union __anonunion___sigaction_handler_41 __sigaction_handler;
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

typedef union pthread_attr_t pthread_attr_t;
struct __anonstruct___data_7 {
  int __lock;

  unsigned long long __total_seq;
  unsigned long long __wakeup_seq;
  unsigned long long __woken_seq;

  unsigned int __broadcast_seq;
};
union __anonunion_pthread_cond_t_6 {
  struct __anonstruct___data_7 __data;
};
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
  size_t line_bytes;
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

  struct keyfield *next;
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
struct cs_status {
  _Bool valid;
  sigset_t sigs;
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

struct thread_args {
  struct line *lines;
  size_t nthreads;
  size_t total_lines;
  struct merge_node *node;
  struct merge_node_queue *queue;
  FILE *tfp;
  char const *output_temp;
};

__attribute__((__noreturn__)) void xalloc_die(void);

extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(
    size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) memcpy)(
    void *__restrict __dest, void const *__restrict __src, size_t __n);

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
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(
    size_t candidate, Hash_tuning const *tuning,
    size_t (*hasher)(void const *, size_t),
    _Bool (*comparator)(void const *, void const *),
    void (*data_freer)(void *));
void *(__attribute__((__warn_unused_result__)) hash_insert)(
    Hash_table *table___0, void const *entry);
int hash_insert_if_absent(Hash_table *table___0, void const *entry,
                          void const **matched_ent);

void close_stdout(void);
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern __attribute__((__noreturn__)) void _exit(int __status);
int close_stream(FILE *stream);
int volatile exit_failure;

static char const *file_name;
static _Bool ignore_EPIPE;
void close_stdout(void) {

  char const *tmp;

  int *tmp___1;

  int tmp___3;
  int *tmp___4;
  int tmp___5;

  {
    tmp___3 = close_stream(stdout);
    if (tmp___3 != 0) {
      if (ignore_EPIPE) {
        tmp___4 = __errno_location();

      } else {
      _L:
        tmp = (char const *)gettext("write error");

        _exit((int)exit_failure);
      }
    }
    tmp___5 = close_stream(stderr);
  }
}
extern struct _IO_FILE *stdin;
int rpl_fflush(FILE *stream);

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);

int close_stream(FILE *stream) {
  _Bool some_pending;
  size_t tmp;
  _Bool prev_fail;
  int tmp___0;
  _Bool fclose_fail;
  int tmp___1;

  int *tmp___3;

  {
    tmp = __fpending(stream);

    tmp___0 = ferror_unlocked(stream);
    prev_fail = (_Bool)(tmp___0 != 0);
    tmp___1 = rpl_fclose(stream);
    fclose_fail = (_Bool)(tmp___1 != 0);
    if (prev_fail) {

    } else {
      if (fclose_fail) {
        if (some_pending) {

        } else {

          if (*tmp___3 != 9) {
          _L___0:
            if (!fclose_fail) {
            }
          }
        }
      }
    }
    return (0);
  }
}
int rpl_fcntl(int fd, int action, ...);

_Bool triple_compare_ino_str(void const *x, void const *y)
    __attribute__((__pure__));
void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strdup)(char const *__s)
    __attribute__((__malloc__));
int c_tolower(int c) __attribute__((__const__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));
int c_strcasecmp(char const *s1, char const *s2) {
  register unsigned char const *p1;
  register unsigned char const *p2;
  unsigned char c1;
  unsigned char c2;

  {
    p1 = (unsigned char const *)s1;
    p2 = (unsigned char const *)s2;
    if ((unsigned long)p1 == (unsigned long)p2) {
    }

    if ((int)c1 == 0) {
      goto while_break;
    }
    p1++;
    p2++;
    if (!((int)c1 == (int)c2)) {
      goto while_break;
    }

  while_break:;
    return ((int)c1 - (int)c2);
  }
}
_Bool c_isalnum(int c) __attribute__((__const__));
_Bool c_isalpha(int c) __attribute__((__const__));
_Bool c_isdigit(int c) __attribute__((__const__));

_Bool c_isalnum(int c) __attribute__((__const__));
_Bool c_isalnum(int c) {
  int tmp;

  {
    if (c >= 48) {
      if (c <= 57) {
        tmp = 1;
      } else {
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

    } else {
      tmp = 0;
    }
    return ((_Bool)tmp);
  }
}
_Bool c_isspace(int c) __attribute__((__const__));
_Bool c_isspace(int c) {
  int tmp;

  {
    if (c == 32) {

    } else {
      if (c == 9) {

      } else {
        if (c == 10) {

        } else {
          if (c == 11) {

          } else {
            if (c == 12) {

            } else {
              if (c == 13) {

              } else {
              }
            }
          }
        }
      }
    }
    return ((_Bool)tmp);
  }
}
int c_tolower(int c) __attribute__((__const__));

char *last_component(char const *name) __attribute__((__pure__));
char *last_component(char const *name) {
  char const *base;
  char const *p;
  _Bool saw_slash;

  {

    saw_slash = (_Bool)0;
    while (1) {
    }

    ;
    return ((char *)base);
  }
}
__inline static unsigned char to_uchar(char ch) {

  {}
}

void (*argmatch_die)(void);

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2,
                                          size_t __n) __attribute__((__pure__));

ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize)
    __attribute__((__pure__));

ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize) {
  size_t i;
  size_t arglen;
  ptrdiff_t matchind;
  _Bool ambiguous;

  size_t tmp___0;
  int tmp___1;

  {
    matchind = (ptrdiff_t)-1;
    ambiguous = (_Bool)0;
    arglen = strlen(arg);
    i = (size_t)0;

  while_break:;
    if (ambiguous) {

    } else {
    }
  }
}

struct allocator const stdlib_allocator = {
    (void *(*)(size_t))(&malloc), (void *(*)(void *, size_t))(&realloc),
    (void (*)(void *))(&free), (void (*)(size_t))((void *)0)};

__inline static void *xnmalloc(size_t n, size_t s)
    __attribute__((__malloc__, __alloc_size__(1, 2)));
__inline static void *xnmalloc(size_t n, size_t s) {
  int tmp;
  void *tmp___0;

  {

    if ((size_t)tmp / s < n) {
    }
    tmp___0 = xmalloc(n * s);
    return (tmp___0);
  }
}
extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));

strtol_error xstrtoumax(char const *s, char **ptr, int strtol_base,
                        uintmax_t *val, char const *valid_suffixes);
static strtol_error bkm_scale(uintmax_t *x, int scale_factor) {

  {
    if (0xffffffffffffffffUL / (unsigned long)scale_factor < *x) {
    }
  }
}
static strtol_error bkm_scale_by_power(uintmax_t *x, int base, int power) {
  strtol_error err;

  {
    err = (strtol_error)0;

    ;
    return (err);
  }
}
strtol_error xstrtoumax(char const *s, char **ptr, int strtol_base,
                        uintmax_t *val, char const *valid_suffixes) {

  char **p;
  uintmax_t tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;
  unsigned short const **tmp___0;
  int *tmp___1;
  char *tmp___2;

  int *tmp___4;
  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;

  {
    err = (strtol_error)0;

    if (ptr) {

    } else {
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

    tmp = strtoumax(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {
        if (*(*p)) {
          tmp___2 = strchr(valid_suffixes, (int)*(*p));
          if (tmp___2) {

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
    }
    if (!valid_suffixes) {
      *val = tmp;
      return (err);
    }
    if ((int)*(*p) != 0) {
      base = 1024;

      tmp___5 = strchr(valid_suffixes, (int)*(*p));
      if (!tmp___5) {
        *val = tmp;
        return ((strtol_error)((unsigned int)err | 2U));
      }

      if ((int)*(*p) == 98) {
        goto case_98;
      }

      if ((int)*(*p) == 99) {
      }
      if ((int)*(*p) == 69) {
        goto case_69;
      }
      if ((int)*(*p) == 71) {
        goto case_71;
      }
      if ((int)*(*p) == 103) {
      }

      if ((int)*(*p) == 75) {
      }

      if ((int)*(*p) == 80) {
      }
      if ((int)*(*p) == 84) {
        goto case_84;
      }
      if ((int)*(*p) == 116) {
        goto case_84;
      }
      if ((int)*(*p) == 119) {
      }
      if ((int)*(*p) == 89) {
      }
      if ((int)*(*p) == 90) {
        goto case_90;
      }

    case_98:
      overflow = bkm_scale(&tmp, 512);
      goto switch_break___0;

      overflow = bkm_scale(&tmp, 1024);
      goto switch_break___0;
    case_99:
      overflow = (strtol_error)0;
      goto switch_break___0;
    case_69:

    case_71:

    case_107:
      overflow = bkm_scale_by_power(&tmp, base, 1);

      overflow = bkm_scale_by_power(&tmp, base, 2);
      goto switch_break___0;
    case_80:
      overflow = bkm_scale_by_power(&tmp, base, 5);

    case_84:
      overflow = bkm_scale_by_power(&tmp, base, 4);
      goto switch_break___0;
    case_119:

      goto switch_break___0;
    case_89:
      overflow = bkm_scale_by_power(&tmp, base, 8);
      goto switch_break___0;
    case_90:
      overflow = bkm_scale_by_power(&tmp, base, 7);
      goto switch_break___0;

    switch_break___0:
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
      *p += suffixes;
    }
    *val = tmp;
    return (err);
  }
}
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes);
extern __attribute__((__nothrow__)) unsigned long(__attribute__((
    __nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr,
                                        char **__restrict __endptr, int __base);
static strtol_error bkm_scale___0(unsigned long *x, int scale_factor) {

  {
    if (0xffffffffffffffffUL / (unsigned long)scale_factor < *x) {
    }
    *x *= (unsigned long)scale_factor;
    return ((strtol_error)0);
  }
}
static strtol_error bkm_scale_by_power___0(unsigned long *x, int base,
                                           int power) {
  strtol_error err;
  strtol_error tmp;

  {

    tmp = bkm_scale___0(x, base);
    err = (strtol_error)((unsigned int)err | (unsigned int)tmp);

    ;
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

  char *tmp___2;

  int *tmp___4;
  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;

  {

    if (0 <= strtol_base) {

    } else {
    }
    if (ptr) {
      p = ptr;
    } else {
      p = &t_ptr;
    }
    q = s;
    ch = (unsigned char)*q;

    if (!((int const) * (*tmp___0 + (int)ch) & 8192)) {
    }
    q++;

  while_break:;
    if ((int)ch == 45) {
      return ((strtol_error)4);
    }

    tmp = strtoul(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {

    } else {
      tmp___4 = __errno_location();
    }

    if ((int)*(*p) != 0) {
      base = 1024;
      suffixes = 1;
      tmp___5 = strchr(valid_suffixes, (int)*(*p));
      if (!tmp___5) {
        *val = tmp;
        return ((strtol_error)((unsigned int)err | 2U));
      }

      if ((int)*(*p) == 98) {
        goto case_98;
      }

      if ((int)*(*p) == 71) {
        goto case_71;
      }
      if ((int)*(*p) == 103) {
      }
      if ((int)*(*p) == 107) {
      }

      if ((int)*(*p) == 77) {
      }

      if ((int)*(*p) == 80) {
      }
      if ((int)*(*p) == 84) {
        goto case_84;
      }

      if ((int)*(*p) == 119) {
      }
      if ((int)*(*p) == 89) {
        goto case_89;
      }
      if ((int)*(*p) == 90) {
        goto case_90;
      }

    case_98:

      overflow = bkm_scale___0(&tmp, 1024);

    case_99:
      overflow = (strtol_error)0;

      overflow = bkm_scale_by_power___0(&tmp, base, 6);
      goto switch_break___0;
    case_71:
      overflow = bkm_scale_by_power___0(&tmp, base, 3);

    case_107:
      overflow = bkm_scale_by_power___0(&tmp, base, 1);

    case_77:
      overflow = bkm_scale_by_power___0(&tmp, base, 2);
      goto switch_break___0;
    case_80:
      overflow = bkm_scale_by_power___0(&tmp, base, 5);
      goto switch_break___0;
    case_84:
      overflow = bkm_scale_by_power___0(&tmp, base, 4);

    case_119:

      goto switch_break___0;
    case_89:

      goto switch_break___0;
    case_90:
      overflow = bkm_scale_by_power___0(&tmp, base, 7);

    switch_default:
      *val = tmp;

    switch_break___0:
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
    }

    return (err);
  }
}
extern __attribute__((__nothrow__)) long(__attribute__((
    __nonnull__(1), __leaf__)) strtol)(char const *__restrict __nptr,
                                       char **__restrict __endptr, int __base);
__attribute__((__noreturn__)) void
xstrtol_fatal(enum strtol_error err, int opt_idx, char c,
              struct option const *long_options___2, char const *arg);
static void xstrtol_error(enum strtol_error err, int opt_idx, char c,
                          struct option const *long_options___2,
                          char const *arg, int exit_status) {
  char const *hyphens;
  char const *msgid;
  char const *option;

  char *tmp;

  {

    if ((unsigned int)err == 2U) {
      goto case_2;
    }
    if ((unsigned int)err == 3U) {
      goto case_2;
    }

  case_4:

  case_2:
    msgid = "invalid suffix in %s%s argument \'%s\'";

  switch_break:;

    tmp = gettext(msgid);
    error(exit_status, 0, (char const *)tmp, hyphens, option, arg);
    return;
  }
}
__attribute__((__noreturn__)) void
xstrtol_fatal(enum strtol_error err, int opt_idx, char c,
              struct option const *long_options___2, char const *arg);
void xstrtol_fatal(enum strtol_error err, int opt_idx, char c,
                   struct option const *long_options___2, char const *arg) {

  {
    xstrtol_error(err, opt_idx, c, long_options___2, arg, (int)exit_failure);
    abort();
  }
}

int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size);

int xmemcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size);
static void collate_error(int collation_errno, char const *s1, size_t s1len,
                          char const *s2, size_t s2len) {

  {}
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

    return (diff);
  }
}

void *xmemdup(void const *p, size_t s)
    __attribute__((__malloc__, __alloc_size__(2)));
__inline static void *x2nrealloc(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {
    n = *pn;
    if (!p) {
      if (!n) {
        n = 128UL / s;
      }
    } else {
      if (0xaaaaaaaaaaaaaaaaUL / s <= n) {
        xalloc_die();
      }
      n += (n + 1UL) / 2UL;
    }
    *pn = n;
    tmp = xrealloc(p, n * s);
    return (tmp);
  }
}

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    tmp = malloc(n);
    p = tmp;
    if (!p) {
    }
    return (p);
  }
}
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
void *xrealloc(void *p, size_t n) {

  {
    if (!n) {
    }
    p = realloc(p, n);
    if (!p) {
    }
    return (p);
  }
}
void *xcalloc(size_t n, size_t s)
    __attribute__((__malloc__, __alloc_size__(1, 2)));
void *xcalloc(size_t n, size_t s) {
  void *p;

  {
    p = calloc(n, s);
    if (!p) {
    }
    return (p);
  }
}

__attribute__((__noreturn__)) void xalloc_die(void);
void xalloc_die(void) {
  char *tmp;

  { tmp = gettext("memory exhausted"); }
}

void version_etc_arn(FILE *stream, char const *command_name,
                     char const *package, char const *version,
                     char const *const *authors, size_t n_authors);

char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1);
char const *locale_charset(void);
#pragma GCC diagnostic ignored "-Wtype-limits"
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1) {
  char *p;

  {
    p = buf___1 + ((sizeof(uintmax_t) * 8UL) * 146UL + 484UL) / 485UL;

    return (p);
  }
}
#pragma GCC diagnostic ignored "-Wtype-limits"

char *(__attribute__((__warn_unused_result__)) uinttostr)(unsigned int i,
                                                          char *buf___1) {
  char *p;

  {

    if (i < 0U) {

      p--;

    while_break:
      p--;

    } else {

      p--;
      *p = (char)(48U + i % 10U);

      if (!(i != 0U)) {
        goto while_break___0;
      }

    while_break___0:;
    }
    return (p);
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) mbsinit)(
    mbstate_t const *__ps) __attribute__((__pure__));

unsigned int const is_basic_table[8];
__inline static _Bool is_basic(char c) {

  {}
}

int __attribute__((__pure__)) strnumcmp(char const *a, char const *b,
                                        int decimal_point___0,
                                        int thousands_sep___0);
__inline static int __attribute__((__pure__))
fraccompare(char const *a, char const *b, char decimal_point___0) {
  char const *tmp;
  char const *tmp___0;

  {
    if ((int const) * a == (int const)decimal_point___0) {
      if ((int const) * b == (int const)decimal_point___0) {
        while (1) {
          a++;
          b++;
          if (!((int const) * a == (int const) * b)) {
            goto while_break;
          }
          if (!((unsigned int)*a - 48U <= 9U)) {
            return ((int __attribute__((__pure__)))0);
          }
        }
      while_break:;
        if ((unsigned int)*a - 48U <= 9U) {
          if ((unsigned int)*b - 48U <= 9U) {
            return ((int __attribute__((__pure__)))((int const) * a -
                                                    (int const) * b));
          }
        }
        if ((unsigned int)*a - 48U <= 9U) {
          goto a_trailing_nonzero;
        }
        if ((unsigned int)*b - 48U <= 9U) {
        }
        return ((int __attribute__((__pure__)))0);
      } else {
      }
    } else {
    _L:
      tmp___0 = a;
      a++;
      if ((int const) * tmp___0 == (int const)decimal_point___0) {
      a_trailing_nonzero:
        while (1) {

          a++;
        }
      while_break___0:;
        return ((int __attribute__((__pure__)))((unsigned int)*a - 48U <= 9U));
      } else {
        tmp = b;
        b++;
        if ((int const) * tmp == (int const)decimal_point___0) {
        b_trailing_nonzero:

          if (!((int const) * b == 48)) {
            goto while_break___1;
          }
          b++;

        while_break___1:;
          return (
              (int __attribute__((__pure__)))(-((unsigned int)*b - 48U <= 9U)));
        }
      }
    }
    return ((int __attribute__((__pure__)))0);
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
        if (!((int)tmpa == thousands_sep___0)) {
          goto while_break;
        }
      }

    while_break:;
      if ((int)tmpb != 45) {
        if ((int)tmpa == decimal_point___0) {

          if (!((int)tmpa == 48)) {
            goto while_break___0;
          }

        while_break___0:;
        }
        if ((unsigned int)tmpa - 48U <= 9U) {
          return ((int __attribute__((__pure__))) - 1);
        }
        while (1) {

          b++;
          tmpb = (unsigned char)*b;
        }

        ;
        if ((int)tmpb == decimal_point___0) {

          b++;
          tmpb = (unsigned char)*b;
          if (!((int)tmpb == 48)) {
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

      if ((int)tmpa == (int)tmpb) {
        if (!((unsigned int)tmpa - 48U <= 9U)) {
        }
      } else {
      }
      while (1) {
        a++;
        tmpa = (unsigned char)*a;
        if (!((int)tmpa == thousands_sep___0)) {
          goto while_break___5;
        }
      }
    while_break___5:;

      b++;
      tmpb = (unsigned char)*b;
      if (!((int)tmpb == thousands_sep___0)) {
        goto while_break___6;
      }

    while_break___6:;

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

      while_break___8:
        log_a++;
      }
    while_break___7:
      log_b = (size_t)0;
      while (1) {

        if (!((unsigned int)tmpb - 48U <= 9U)) {
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

    } else {
      if ((int)tmpb == 45) {
        while (1) {
          b++;
          tmpb = (unsigned char)*b;
        }
      while_break___11:;
        if ((int)tmpb == decimal_point___0) {

          b++;
          tmpb = (unsigned char)*b;
          if (!((int)tmpb == 48)) {
          }

        while_break___12:;
        }
        if ((unsigned int)tmpb - 48U <= 9U) {
          return ((int __attribute__((__pure__)))1);
        }
        while (1) {

          if (!((int)tmpa == 48)) {
            if (!((int)tmpa == thousands_sep___0)) {
              goto while_break___13;
            }
          }

          tmpa = (unsigned char)*a;
        }
      while_break___13:;
        if ((int)tmpa == decimal_point___0) {
          while (1) {
            a++;
            tmpa = (unsigned char)*a;
            if (!((int)tmpa == 48)) {
              goto while_break___14;
            }
          }
        while_break___14:;
        }
        return (
            (int __attribute__((__pure__)))((unsigned int)tmpa - 48U <= 9U));
      } else {

        if (!((int)tmpa == 48)) {
          if (!((int)tmpa == thousands_sep___0)) {
          }
        }
        a++;
        tmpa = (unsigned char)*a;

      while_break___15:;

        if (!((int)tmpb == 48)) {
          if (!((int)tmpb == thousands_sep___0)) {
            goto while_break___16;
          }
        }
        b++;
        tmpb = (unsigned char)*b;

      while_break___16:;

        a++;
        tmpa = (unsigned char)*a;
        if (!((int)tmpa == thousands_sep___0)) {
          goto while_break___18;
        }

      while_break___18:;

        b++;
        tmpb = (unsigned char)*b;
        if (!((int)tmpb == thousands_sep___0)) {
          goto while_break___19;
        }

      while_break___19:;

      while_break___17:;
        if ((int)tmpa == decimal_point___0) {
          if (!((unsigned int)tmpb - 48U <= 9U)) {
            tmp___2 = fraccompare(a, b, (char)decimal_point___0);
            return (tmp___2);
          } else {
            goto _L___0;
          }
        } else {
        _L___0:
          if ((int)tmpb == decimal_point___0) {
            if (!((unsigned int)tmpa - 48U <= 9U)) {
              tmp___2 = fraccompare(a, b, (char)decimal_point___0);
              return (tmp___2);
            }
          }
        }
        tmp = (int)tmpa - (int)tmpb;
        log_a = (size_t)0;

        if (!((unsigned int)tmpa - 48U <= 9U)) {
          goto while_break___20;
        }
        while (1) {
          a++;
          tmpa = (unsigned char)*a;
        }
      while_break___21:
        log_a++;

      while_break___20:
        log_b = (size_t)0;

        ;
        if (log_a != log_b) {
          if (log_a < log_b) {
            tmp___3 = -1;
          } else {
          }
          return ((int __attribute__((__pure__)))tmp___3);
        }
        if (!log_a) {
        }
        return ((int __attribute__((__pure__)))tmp);
      }
    }
  }
}
int __attribute__((__pure__)) strnumcmp(char const *a, char const *b,
                                        int decimal_point___0,
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
    tmp = (char const *)memchr((void const *)string, '\000', maxlen);
    end = tmp;
    if ((unsigned long)end != (unsigned long)((void *)0)) {
      return ((size_t)((end - string) + 1L));
    } else {
    }
  }
}

extern int fgetc(FILE *__stream);
extern void _obstack_newchunk(struct obstack *, int);
extern int _obstack_begin(struct obstack *, int, int, void *(*)(long),
                          void (*)(void *));
void readtokens0_init(struct Tokens *t);
_Bool readtokens0(FILE *in, struct Tokens *t);
void readtokens0_init(struct Tokens *t) {

  {
    t->n_tok = (size_t)0;

    t->tok_len = (size_t *)((void *)0);
    _obstack_begin(&t->o_data, 0, 0, (void *(*)(long))(&malloc),
                   (void (*)(void *))(&free));
    _obstack_begin(&t->o_tok, 0, 0, (void *(*)(long))(&malloc),
                   (void (*)(void *))(&free));
    _obstack_begin(&t->o_tok_len, 0, 0, (void *(*)(long))(&malloc),
                   (void (*)(void *))(&free));
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
    __o = (struct obstack const *)(&t->o_data);
    len = (size_t)((unsigned int)(__o->next_free - __o->object_base) - 1U);
    __o1 = &t->o_data;
    __value = (void *)__o1->object_base;
    if ((unsigned long)__o1->next_free == (unsigned long)__value) {
      __o1->maybe_empty_object = 1U;
    }
    if (sizeof(long) < sizeof(void *)) {
      tmp = __o1->object_base;
    } else {
      tmp = (char *)0;
    }
    if (sizeof(long) < sizeof(void *)) {
      tmp___0 = __o1->object_base;
    } else {
      tmp___0 = (char *)0;
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
    __o___0 = &t->o_tok;
    if ((unsigned long)(__o___0->next_free + sizeof(void *)) >
        (unsigned long)__o___0->chunk_limit) {
    }
    __o1___0 = __o___0;
    *((void const **)__o1___0->next_free) = (void const *)s;
    __o1___0->next_free += sizeof(void const *);
    __o___1 = &t->o_tok_len;

    if ((unsigned long)(__o___1->next_free + __len) >
        (unsigned long)__o___1->chunk_limit) {
      _obstack_newchunk(__o___1, __len);
    }
    memcpy((void *)__o___1->next_free, (void const *)(&len), (size_t)__len);
    __o___1->next_free += __len;
    (t->n_tok)++;
    return;
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
      tmp = fgetc(in);
      c = tmp;
      if (c == -1) {
        __o = (struct obstack const *)(&t->o_data);
        len = (size_t)((unsigned int)(__o->next_free - __o->object_base));
        if (len) {
          __o___0 = &t->o_data;
          if ((unsigned long)(__o___0->next_free + 1) >
              (unsigned long)__o___0->chunk_limit) {
            _obstack_newchunk(__o___0, 1);
          }
          tmp___0 = __o___0->next_free;
          (__o___0->next_free)++;

          save_token(t);
        }
        goto while_break;
      }
      __o___1 = &t->o_data;
      if ((unsigned long)(__o___1->next_free + 1) >
          (unsigned long)__o___1->chunk_limit) {
        _obstack_newchunk(__o___1, 1);
      }
      tmp___1 = __o___1->next_free;
      (__o___1->next_free)++;

      if (c == 0) {
        save_token(t);
      }
    }
  while_break:
    __o___2 = &t->o_tok;
    if ((unsigned long)(__o___2->next_free + sizeof(void *)) >
        (unsigned long)__o___2->chunk_limit) {
      _obstack_newchunk(__o___2, (int)sizeof(void *));
    }
    __o1 = __o___2;
    *((void const **)__o1->next_free) = (void const *)((void *)0);
    __o1->next_free += sizeof(void const *);
    __o1___0 = &t->o_tok;
    __value = (void *)__o1___0->object_base;
    if ((unsigned long)__o1___0->next_free == (unsigned long)__value) {
    }
    if (sizeof(long) < sizeof(void *)) {
      tmp___2 = __o1___0->object_base;
    } else {
    }
    if (sizeof(long) < sizeof(void *)) {
      tmp___3 = __o1___0->object_base;
    } else {
    }
    __o1___0->next_free =
        tmp___2 +
        (((__o1___0->next_free - tmp___3) + (long)__o1___0->alignment_mask) &
         (long)(~__o1___0->alignment_mask));
    if (__o1___0->next_free - (char *)__o1___0->chunk >
        __o1___0->chunk_limit - (char *)__o1___0->chunk) {
    }
    __o1___0->object_base = __o1___0->next_free;
    t->tok = (char **)__value;
    __o1___1 = &t->o_tok_len;
    __value___0 = (void *)__o1___1->object_base;
    if ((unsigned long)__o1___1->next_free == (unsigned long)__value___0) {
    }
    if (sizeof(long) < sizeof(void *)) {
      tmp___4 = __o1___1->object_base;
    } else {
    }
    if (sizeof(long) < sizeof(void *)) {
      tmp___5 = __o1___1->object_base;
    } else {
      tmp___5 = (char *)0;
    }
    __o1___1->next_free =
        tmp___4 +
        (((__o1___1->next_free - tmp___5) + (long)__o1___1->alignment_mask) &
         (long)(~__o1___1->alignment_mask));
    if (__o1___1->next_free - (char *)__o1___1->chunk >
        __o1___1->chunk_limit - (char *)__o1___1->chunk) {
      __o1___1->next_free = __o1___1->chunk_limit;
    }

    t->tok_len = (size_t *)__value___0;
    tmp___6 = ferror(in);

    return ((_Bool)tmp___7);
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(
    FILE *__stream);

void isaac_seed(struct isaac_state *s);

FILE *fopen_safer(char const *file, char const *mode);
static void randread_error(void const *file_name___3) {

  { abort(); }
}
static struct randread_source *simple_new(FILE *source,
                                          void const *handler_arg) {
  struct randread_source *s;

  {

    s->source = source;
    s->handler = &randread_error;
  }
}
static void get_nonce(void *buffer, size_t bufsize___1, size_t bytes_bound) {
  char *buf___1;
  ssize_t seeded;
  int fd;
  int tmp;

  struct timeval v;
  size_t nbytes;

  pid_t v___0;
  size_t nbytes___0;
  unsigned long tmp___2;

  size_t nbytes___1;

  uid_t v___2;
  size_t nbytes___2;

  {
    buf___1 = (char *)buffer;

    fd = tmp;

    if ((size_t)seeded < bufsize___1) {
      if (sizeof(v___0) < bufsize___1 - (size_t)seeded) {

      } else {
        tmp___2 = bufsize___1 - (size_t)seeded;
      }
      nbytes___0 = tmp___2;
      v___0 = getpid();
      memcpy((void *)(buf___1 + seeded), (void const *)(&v___0), nbytes___0);
      seeded = (ssize_t)((size_t)seeded + nbytes___0);
    }

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

    } else {

      if (source) {
        if (sizeof(s->buf.c) < bytes_bound) {

        } else {
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
static void readsource(struct randread_source *s, unsigned char *p,
                       size_t size) {
  size_t inbytes;

  int *tmp___0;
  int *tmp___1;
  int tmp___3;

  {

  while_break:;
    return;
  }
}
static void readisaac(struct isaac *isaac, unsigned char *p, size_t size) {
  size_t inbytes;
  isaac_word *wp;

  {
    inbytes = isaac->buffered;

    memcpy((void *)p,
           (void const *)((isaac->data.b +
                           (unsigned long)(1 << 8) * sizeof(isaac_word)) -
                          inbytes),
           inbytes);
    p += inbytes;
    size -= inbytes;
    wp = (isaac_word *)p;

    p = (unsigned char *)wp;
  }
}
void randread(struct randread_source *s, void *buf___1, size_t size) {

  {
    if (s->source) {
      readsource(s, (unsigned char *)buf___1, size);
    } else {
      readisaac(&s->buf.isaac, (unsigned char *)buf___1, size);
    }
    return;
  }
}
int randread_free(struct randread_source *s) {
  FILE *source;
  int tmp;
  int tmp___0;

  {

    if (source) {
      tmp = rpl_fclose(source);

    } else {
    }
    return (tmp___0);
  }
}

void isaac_refill(struct isaac_state *s, isaac_word *result) {
  isaac_word a;

  isaac_word *m;
  isaac_word *r;
  isaac_word x;

  {
    a = s->a;

    m = s->m;
    r = result;

    ;

    return;
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

  int i___0;
  isaac_word tmp___11;

  isaac_word tmp___16;

  {

    a = tmp;
    if (1 << 6 == 32) {

    } else {
    }
    b = tmp___0;

    c = tmp___1;
    if (1 << 6 == 32) {

    } else {
    }
    d = tmp___2;
    if (1 << 6 == 32) {

    } else {
      tmp___3 = 0x82f053db8355e0ceUL;
    }
    e = tmp___3;

    f = tmp___4;

    g = tmp___5;
    if (1 << 6 == 32) {
      tmp___6 = 811634969UL;
    } else {
      tmp___6 = 0x98f5704f6c44c0abUL;
    }
    h = tmp___6;
    i = 0;

    i___0 = 0;

    tmp___16 = (isaac_word)0;
  }
}

struct quoting_options quote_quoting_options;
__inline static char *xcharalloc(size_t n)
    __attribute__((__malloc__, __alloc_size__(1)));

static struct quoting_options
quoting_options_from_style(enum quoting_style style) {
  struct quoting_options o;
  unsigned int tmp;

  { o.left_quote = (char const *)((void *)0); }
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

  _Bool elide_outer_quotes;
  unsigned char c;
  unsigned char esc;
  _Bool is_right_quote;

  size_t m;
  _Bool printable;
  unsigned short const **tmp___2;
  mbstate_t mbstate;
  wchar_t w;
  size_t bytes;
  size_t tmp___3;

  int tmp___5;
  size_t ilim;
  int tmp___6;
  size_t tmp___7;

  {
    len = (size_t)0;
    quote_string = (char const *)0;

    if ((unsigned int)quoting_style == 4U) {
    }
    if ((unsigned int)quoting_style == 3U) {
      goto case_3;
    }
    if ((unsigned int)quoting_style == 5U) {
    }
    if ((unsigned int)quoting_style == 6U) {
    }

    if ((unsigned int)quoting_style == 8U) {
    }

    if ((unsigned int)quoting_style == 2U) {
    }

  case_4:
    quoting_style = (enum quoting_style)3;
    elide_outer_quotes = (_Bool)1;
  case_3:

  case_5:

    elide_outer_quotes = (_Bool)0;

  case_6:

    quote_string_len = strlen(quote_string);

    quoting_style = (enum quoting_style)2;
    elide_outer_quotes = (_Bool)1;
  case_2:
    if (!elide_outer_quotes) {

      ;
    }
    quote_string = "\'";

    goto switch_break;

  switch_break:
    i = (size_t)0;

    if (argsize == 0xffffffffffffffffUL) {
      tmp___6 = (int const) * (arg + i) == 0;
    } else {
      tmp___6 = i == argsize;
    }
    if (tmp___6) {
      goto while_break___3;
    }

    c = (unsigned char)*(arg + i);

    if ((int)c == 63) {
    }

    if ((int)c == 12) {
      goto case_12;
    }
    if ((int)c == 10) {
    }
    if ((int)c == 13) {
    }
    if ((int)c == 9) {
    }

    if ((int)c == 92) {
      goto case_92;
    }
    if ((int)c == 123) {
      goto case_123;
    }

    if ((int)c == 35) {
      goto case_35;
    }

    if ((int)c == 32) {
    }

    if ((int)c == 34) {
    }

    if ((int)c == 38) {
      goto case_32;
    }
    if ((int)c == 40) {
      goto case_32;
    }
    if ((int)c == 41) {
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
    if ((int)c == 91) {
      goto case_32;
    }
    if ((int)c == 94) {
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
    if ((int)c == 46) {
      goto case_37;
    }
    if ((int)c == 47) {
      goto case_37;
    }
    if ((int)c == 48) {
    }
    if ((int)c == 49) {
      goto case_37;
    }
    if ((int)c == 50) {
    }
    if ((int)c == 51) {
    }
    if ((int)c == 52) {
    }
    if ((int)c == 53) {
      goto case_37;
    }
    if ((int)c == 54) {
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
    }
    if ((int)c == 75) {
    }
    if ((int)c == 76) {
      goto case_37;
    }
    if ((int)c == 77) {
    }
    if ((int)c == 78) {
      goto case_37;
    }
    if ((int)c == 79) {
      goto case_37;
    }
    if ((int)c == 80) {
    }
    if ((int)c == 81) {
      goto case_37;
    }
    if ((int)c == 82) {
    }
    if ((int)c == 83) {
    }
    if ((int)c == 84) {
      goto case_37;
    }
    if ((int)c == 85) {
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
    }
    if ((int)c == 97) {
    }
    if ((int)c == 98) {
    }

    if ((int)c == 100) {
    }

    if ((int)c == 102) {
    }
    if ((int)c == 103) {
    }

    if ((int)c == 105) {
    }
    if ((int)c == 106) {
    }
    if ((int)c == 107) {
    }

    if ((int)c == 109) {
    }
    if ((int)c == 110) {
      goto case_37;
    }

    if ((int)c == 114) {
      goto case_37;
    }
    if ((int)c == 115) {
    }
    if ((int)c == 116) {
    }

    if ((int)c == 119) {
    }

  case_0___0:

  case_63:

    if ((unsigned int)quoting_style == 3U) {
    }

  case_2___0:

  case_3___0:

    goto switch_break___1;
  switch_break___1:;
    goto switch_break___0;

  case_8___0:

    goto c_escape;
  case_12:
    esc = (unsigned char)'f';
    goto c_escape;
  case_10:

  case_13:

  case_9:
    esc = (unsigned char)'t';

  case_11:

    goto c_escape;
  case_92:
    esc = c;

  c_escape:

    goto switch_break___0;
  case_123:

  case_35:

  case_32:

  case_39___0:

  case_37:

  switch_default___2:
    if (unibyte_locale) {
      m = (size_t)1;

      printable = (_Bool)(((int const) * (*tmp___2 + (int)c) & 16384) != 0);
    } else {
      memset((void *)(&mbstate), 0, sizeof(mbstate));
      m = (size_t)0;

      if (argsize == 0xffffffffffffffffUL) {
        argsize = strlen(arg);
      }

      tmp___3 = mbrtowc(&w, arg + (i + m), argsize - (i + m), &mbstate);
      bytes = tmp___3;
      if (bytes == 0UL) {
        goto while_break___14;
      } else {
      }
      tmp___5 = mbsinit((mbstate_t const *)(&mbstate));

    while_break___14:;
    }
    if (1UL < m) {

    } else {
      if (backslash_escapes) {
        if (!printable) {

          ilim = i + m;

          if (backslash_escapes) {

          } else {
          _L:
            if (is_right_quote) {

              if (len < buffersize) {
              }
              len++;

            while_break___21:
              is_right_quote = (_Bool)0;
            }
          }
          if (ilim <= i + 1UL) {
          }

          if (len < buffersize) {
            *(buffer + len) = (char)c;
          }
          len++;
          goto while_break___22;

        while_break___22:
          i++;
          c = (unsigned char)*(arg + i);

        while_break___17:;
          goto store_c;
        }
      }
    }
  switch_break___0:;

  store_escape:

      ;
  store_c:

      ;
  __Cont:
    i++;

  while_break___3:;

  force_outer_quoting_style:
    tmp___7 = quotearg_buffer_restyled(
        buffer, buffersize, arg, argsize, quoting_style, flags & -3,
        (unsigned int const *)((void *)0), left_quote, right_quote);
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

  {

    e = *tmp;
    n0 = (unsigned int)n;
    sv = slotvec;
    if (n < 0) {
    }
    if (nslots <= n0) {
      n1 = (size_t)(n0 + 1U);
      preallocated = (_Bool)((unsigned long)sv == (unsigned long)(&slotvec0));

      if ((size_t)tmp___0 / sizeof(*sv) < n1) {
      }
      if (preallocated) {

      } else {
        tmp___1 = sv;
      }
      sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
      slotvec = sv;

      memset((void *)(sv + nslots), 0, (n1 - (size_t)nslots) * sizeof(*sv));
      nslots = (unsigned int)n1;
    }

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
      }

      quotearg_buffer_restyled(val, size, arg, argsize,
                               (enum quoting_style)options->style, flags,
                               (unsigned int const *)(options->quote_these_too),
                               (char const *)options->left_quote,
                               (char const *)options->right_quote);
    }
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
  }
}
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg,
                           size_t argsize) {
  struct quoting_options o;

  char *tmp___0;

  {

    tmp___0 = quotearg_n_options(n, arg, argsize,
                                 (struct quoting_options const *)(&o));
    return (tmp___0);
  }
}

char *quotearg_colon(char const *arg) {
  char *tmp;

  { return (tmp); }
}

char const *quote_n(int n, char const *name) {
  char const *tmp;

  {
    tmp = (char const *)quotearg_n_options(
        n, name, (size_t)-1,
        (struct quoting_options const *)(&quote_quoting_options));
  }
}
char const *quote(char const *name) {
  char const *tmp;

  {}
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
__inline static void mbuiter_multi_next(struct mbuiter_multi *iter) {
  int tmp;
  size_t tmp___0;
  size_t tmp___1;
  int tmp___2;
  _Bool tmp___3;

  {

    if (iter->in_shift) {
    }
    tmp___3 = is_basic((char)*(iter->cur.ptr));
    if (tmp___3) {
      iter->cur.bytes = (size_t)1;
      iter->cur.wc = (wchar_t) * (iter->cur.ptr);
      iter->cur.wc_valid = (_Bool)1;
    } else {
      tmp = mbsinit((mbstate_t const *)(&iter->state));

      iter->in_shift = (_Bool)1;
    with_shift:
      tmp___0 = __ctype_get_mb_cur_max();
      tmp___1 = strnlen1(iter->cur.ptr, tmp___0);
      iter->cur.bytes =
          mbrtowc(&iter->cur.wc, iter->cur.ptr, tmp___1, &iter->state);
      if (iter->cur.bytes == 0xffffffffffffffffUL) {
        iter->cur.bytes = (size_t)1;
        iter->cur.wc_valid = (_Bool)0;
      } else {
        if (iter->cur.bytes == 0xfffffffffffffffeUL) {
          iter->cur.bytes = strlen(iter->cur.ptr);
          iter->cur.wc_valid = (_Bool)0;
        } else {
          if (iter->cur.bytes == 0UL) {
            iter->cur.bytes = (size_t)1;
          }
          iter->cur.wc_valid = (_Bool)1;
          tmp___2 = mbsinit((mbstate_t const *)(&iter->state));
          if (tmp___2) {
            iter->in_shift = (_Bool)0;
          }
        }
      }
    }
    iter->next_done = (_Bool)1;
  }
}
char const *program_name;

void set_program_name(char const *argv0) {
  char const *slash;

  {

    if ((unsigned long)slash != (unsigned long)((void *)0)) {

    } else {
    }

    return;
  }
}

double physmem_available(void);

double physmem_total(void) {
  double pages;
  double tmp;
  double pagesize;
  double tmp___0;

  {
    tmp = (double)sysconf(85);
    pages = tmp;
    tmp___0 = (double)sysconf(30);
    pagesize = tmp___0;
    if ((double)0 <= pages) {
      if ((double)0 <= pagesize) {
        return (pages * pagesize);
      }
    }
  }
}
double physmem_available(void) {
  double pages;
  double tmp;

  double tmp___0;

  {

    pages = tmp;
    tmp___0 = (double)sysconf(30);

    if ((double)0 <= pages) {
    }
  }
}

#pragma GCC diagnostic ignored "-Wtype-limits"
unsigned long num_processors(enum nproc_query query);

static unsigned long num_processors_via_affinity_mask(void) {
  cpu_set_t set;
  unsigned long count;
  int tmp;

  {
    tmp = sched_getaffinity(0, sizeof(set), &set);
    if (tmp == 0) {
      count = (unsigned long)__sched_cpucount(sizeof(cpu_set_t),
                                              (cpu_set_t const *)(&set));
      if (count > 0UL) {
        return (count);
      }
    }
    return (0UL);
  }
}
unsigned long num_processors(enum nproc_query query) {

  unsigned long value;
  unsigned long tmp___1;

  unsigned long nprocs___0;
  unsigned long tmp___5;
  long nprocs___1;
  long tmp___6;
  long nprocs___2;

  unsigned long nprocs_current;
  unsigned long tmp___8;

  {

    if ((unsigned int)query == 1U) {
      tmp___5 = num_processors_via_affinity_mask();
      nprocs___0 = tmp___5;
      if (nprocs___0 > 0UL) {
        return (nprocs___0);
      }
      tmp___6 = sysconf(84);
      nprocs___1 = tmp___6;
      if (nprocs___1 > 0L) {
        return ((unsigned long)nprocs___1);
      }
    } else {

      if (nprocs___2 == 1L) {

        nprocs_current = tmp___8;
        if (nprocs_current > 0UL) {
          nprocs___2 = (long)nprocs_current;
        }
      }
      if (nprocs___2 > 0L) {
        return ((unsigned long)nprocs___2);
      }
    }
    return (1UL);
  }
}

int(__attribute__((__nonnull__(1))) rpl_nanosleep)(
    struct timespec const *requested_delay, struct timespec *remaining_delay) {

  time_t seconds;

  int tmp___0;

  {

    seconds = (time_t)requested_delay->tv_sec;

    return (tmp___0);
  }
}
int mkstemp_safer(char *templ);

int mkstemp_safer(char *templ) {
  int tmp;
  int tmp___0;

  {
    tmp = mkstemp(templ);

    return (tmp___0);
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcoll)(char const *__s1, char const *__s2)
    __attribute__((__pure__));
__inline static int strcoll_loop(char const *s1, size_t s1size, char const *s2,
                                 size_t s2size) {
  int diff;
  size_t size1;
  size_t tmp;
  size_t size2;
  size_t tmp___0;
  int *tmp___1;
  int *tmp___2;
  int tmp___3;

  {
    while (1) {
      tmp___1 = __errno_location();
      *tmp___1 = 0;
      diff = strcoll(s1, s2);

      if (tmp___3) {
        goto while_break;
      }
      tmp = strlen(s1);
      size1 = tmp + 1UL;
      tmp___0 = strlen(s2);
      size2 = tmp___0 + 1UL;
      s1 += size1;
      s2 += size2;
      s1size -= size1;
      s2size -= size2;
      if (s1size == 0UL) {
      }
    }
  while_break:;
    return (diff);
  }
}
int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {

  int tmp___0;
  int tmp___1;

  {
    if (s1size == s2size) {
      tmp___1 = memcmp((void const *)s1, (void const *)s2, s1size);
      if (tmp___1 == 0) {

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

int mbsnwidth(char const *string, size_t nbytes, int flags);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) iswcntrl)(
    wint_t __wc);
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

    if (tmp___1 > 1UL) {

      if (!((unsigned long)p < (unsigned long)plimit)) {
      }

      if ((int const) * p == 33) {
      }

      if ((int const) * p == 35) {
        goto case_32;
      }
      if ((int const) * p == 37) {
      }
      if ((int const) * p == 38) {
      }
      if ((int const) * p == 39) {
      }
      if ((int const) * p == 40) {
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
      }
      if ((int const) * p == 45) {
        goto case_32;
      }
      if ((int const) * p == 46) {
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
      }
      if ((int const) * p == 57) {
      }
      if ((int const) * p == 58) {
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
      }
      if ((int const) * p == 63) {
        goto case_32;
      }
      if ((int const) * p == 65) {
      }
      if ((int const) * p == 66) {
      }

      if ((int const) * p == 68) {
        goto case_32;
      }
      if ((int const) * p == 69) {
        goto case_32;
      }
      if ((int const) * p == 70) {
      }
      if ((int const) * p == 71) {
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

      if ((int const) * p == 78) {
        goto case_32;
      }
      if ((int const) * p == 79) {
      }
      if ((int const) * p == 80) {
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
      }
      if ((int const) * p == 92) {
      }
      if ((int const) * p == 93) {
        goto case_32;
      }
      if ((int const) * p == 94) {
        goto case_32;
      }
      if ((int const) * p == 95) {
      }
      if ((int const) * p == 97) {
        goto case_32;
      }
      if ((int const) * p == 98) {
      }
      if ((int const) * p == 99) {
      }
      if ((int const) * p == 100) {
        goto case_32;
      }
      if ((int const) * p == 101) {
      }
      if ((int const) * p == 102) {
        goto case_32;
      }
      if ((int const) * p == 103) {
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

    case_32:
      p++;
      width++;

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

        w = wcwidth(wc);
        if (w >= 0) {

          width += w;
        } else {
          if (!(flags & 2)) {

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
      }
    while_break___0:;

      ;

    while_break:;
    }
    while (1) {

      if (!((unsigned long)p < (unsigned long)plimit)) {
      }

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
int(__attribute__((__nonnull__(1, 2))) mbscasecmp)(char const *s1,
                                                   char const *s2);

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
  unsigned char const *p2;
  unsigned char c1;
  unsigned char c2;
  int tmp___18;

  unsigned short const **tmp___22;
  size_t tmp___25;

  {

    tmp___25 = __ctype_get_mb_cur_max();
    if (tmp___25 > 1UL) {
      iter1.cur.ptr = s1;
      iter1.in_shift = (_Bool)0;
      memset((void *)(&iter1.state), '\000', sizeof(mbstate_t));

      iter2.cur.ptr = s2;
      iter2.in_shift = (_Bool)0;
      memset((void *)(&iter2.state), '\000', sizeof(mbstate_t));
      iter2.next_done = (_Bool)0;
      while (1) {
        mbuiter_multi_next(&iter1);
        if (iter1.cur.wc_valid) {
          if (iter1.cur.wc == 0) {
            tmp___13 = 0;
          } else {
            tmp___13 = 1;
          }
        } else {
          tmp___13 = 1;
        }
        if (tmp___13) {
          mbuiter_multi_next(&iter2);
          if (iter2.cur.wc_valid) {
            if (iter2.cur.wc == 0) {
              tmp___14 = 0;
            } else {
            }
          } else {
            tmp___14 = 1;
          }
          if (!tmp___14) {
            goto while_break;
          }
        } else {
        }
        if (iter1.cur.wc_valid) {
          if (iter2.cur.wc_valid) {
            tmp = towlower((wint_t)iter1.cur.wc);
            tmp___0 = towlower((wint_t)iter2.cur.wc);
            tmp___1 = (int)tmp - (int)tmp___0;
          } else {
          }
          tmp___12 = tmp___1;
        } else {
          if (iter2.cur.wc_valid) {

          } else {
            if (iter1.cur.bytes == iter2.cur.bytes) {
              tmp___2 = memcmp((void const *)iter1.cur.ptr,
                               (void const *)iter2.cur.ptr, iter1.cur.bytes);

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
          tmp___15 = 1;
        }
      } else {
        tmp___15 = 1;
      }
      if (tmp___15) {
        return (1);
      }
      mbuiter_multi_next(&iter2);
      if (iter2.cur.wc_valid) {
        if (iter2.cur.wc == 0) {
          tmp___16 = 0;
        } else {
          tmp___16 = 1;
        }
      } else {
        tmp___16 = 1;
      }

    } else {
      p1 = (unsigned char const *)s1;
      p2 = (unsigned char const *)s2;

      tmp___22 = __ctype_b_loc();

      if ((int)c1 == 0) {
        goto while_break___0;
      }
      p1++;
      p2++;
      if (!((int)c1 == (int)c2)) {
      }

    while_break___0:;
      return ((int)c1 - (int)c2);
    }
  }
}
unsigned int const is_basic_table[8] = {
    (unsigned int const)6656, (unsigned int const)4294967279U,
    (unsigned int const)4294967294U, (unsigned int const)2147483646};

extern int optind;

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_init)(
    pthread_mutex_t *__mutex, pthread_mutexattr_t const *__mutexattr);

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

    if ((unsigned long)cp == (unsigned long)((void *)0)) {

      if ((unsigned long)dir == (unsigned long)((void *)0)) {
        dir = "/usr/local/lib";
      } else {
      }
      tmp = strlen(dir);
      dir_len___0 = tmp;
      tmp___0 = strlen(base);
      base_len___0 = tmp___0;

      add_slash = tmp___1;
      file_name___3 = (char *)malloc(
          ((dir_len___0 + (size_t)add_slash) + base_len___0) + 1UL);
      if ((unsigned long)file_name___3 != (unsigned long)((void *)0)) {

        if (add_slash) {
          *(file_name___3 + dir_len___0) = (char)'/';
        }
        memcpy((void *)((file_name___3 + dir_len___0) + add_slash),
               (void const *)base, base_len___0 + 1UL);
      }
      if ((unsigned long)file_name___3 == (unsigned long)((void *)0)) {

      } else {
        fd = open((char const *)file_name___3, 131072);
        if (fd < 0) {

        } else {
          fp = fdopen(fd, "r");
          if ((unsigned long)fp == (unsigned long)((void *)0)) {

          } else {

            res_size = (size_t)0;
            while (1) {
              c = getc_unlocked(fp);

              if (c == 10) {
                goto __Cont;
              } else {
              }

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
              }
              strcpy(((res_ptr + res_size) - (l2 + 1UL)) - (l1 + 1UL),
                     (char const *)(buf1));
              strcpy((res_ptr + res_size) - (l2 + 1UL), (char const *)(buf2));
            __Cont:;
            }
          while_break:

            if (res_size == 0UL) {

            } else {
              *(res_ptr + res_size) = (char)'\000';
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

  {

    aliases = get_charset_aliases();

    ;
  }
}

struct heap *heap_alloc(int (*compare___0)(void const *, void const *),
                        size_t n_reserve);

int heap_insert(struct heap *heap, void *item);
void *heap_remove_top(struct heap *heap);
static size_t heapify_down(void **array, size_t count, size_t initial,
                           int (*compare___0)(void const *, void const *));
static void heapify_up(void **array, size_t count,
                       int (*compare___0)(void const *, void const *));

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
    }
    return (heap);
  }
}
void heap_free(struct heap *heap) {

  { free((void *)heap->array); }
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
  size_t tmp;

  {

    top = *(heap->array + 1);
    tmp = heap->count;
    (heap->count)--;
    *(heap->array + 1) = *(heap->array + tmp);
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
    element = *(array + initial);
    parent = initial;

    if (!(parent <= count / 2UL)) {
      goto while_break;
    }

    if (child < count) {

      if (tmp < 0) {
        child++;
      }
    }

    if (tmp___0 <= 0) {
    }
    *(array + parent) = *(array + child);
    parent = child;

  while_break:
    *(array + parent) = element;
    return (parent);
  }
}
static void heapify_up(void **array, size_t count,
                       int (*compare___0)(void const *, void const *)) {
  size_t k;
  void *new_element;
  int tmp;

  {
    k = count;
    new_element = *(array + k);

    if (k != 1UL) {
      tmp = (*compare___0)((void const *)*(array + k / 2UL),
                           (void const *)new_element);
      if (!(tmp <= 0)) {
        goto while_break;
      }
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
size_t hash_string(char const *string, size_t n_buckets)
    __attribute__((__pure__));

static struct hash_tuning const default_tuning = {0.0f, 1.0f, 0.8f, 1.414f,
                                                  (_Bool)0};
static struct hash_entry *safe_hasher(Hash_table const *table___0,
                                      void const *key) {
  size_t n;

  {

    if (!(n < (size_t)table___0->n_buckets)) {
    }
  }
}

static size_t raw_hasher(void const *data, size_t n) {

  {}
}
static _Bool raw_comparator(void const *a, void const *b) {

  { return ((_Bool)((unsigned long)a == (unsigned long)b)); }
}
static _Bool check_tuning(Hash_table *table___0) {
  Hash_tuning const *tuning;
  float epsilon;

  {
    tuning = table___0->tuning;
    if ((unsigned long)tuning == (unsigned long)(&default_tuning)) {
    }
    epsilon = 0.1f;

    table___0->tuning = &default_tuning;
    return ((_Bool)0);
  }
}
static size_t __attribute__((__pure__))
compute_bucket_size(size_t candidate, Hash_tuning const *tuning) {

  { return ((size_t __attribute__((__pure__)))candidate); }
}
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(
    size_t candidate, Hash_tuning const *tuning,
    size_t (*hasher)(void const *, size_t),
    _Bool (*comparator)(void const *, void const *),
    void (*data_freer)(void *)) {
  Hash_table *table___0;
  _Bool tmp;

  {
    if ((unsigned long)hasher == (unsigned long)((void *)0)) {
      hasher = &raw_hasher;
    }
    if ((unsigned long)comparator == (unsigned long)((void *)0)) {
      comparator = &raw_comparator;
    }
    table___0 = (Hash_table *)malloc(sizeof(*table___0));
    if ((unsigned long)table___0 == (unsigned long)((void *)0)) {
      return ((Hash_table *)((void *)0));
    }
    if (!tuning) {
      tuning = &default_tuning;
    }
    table___0->tuning = tuning;
    tmp = check_tuning(table___0);

    table___0->n_buckets = (size_t)compute_bucket_size(candidate, tuning);
    if (!table___0->n_buckets) {
    }

    if ((unsigned long)table___0->bucket == (unsigned long)((void *)0)) {
    }
    table___0->bucket_limit =
        (struct hash_entry const *)(table___0->bucket + table___0->n_buckets);
    table___0->n_buckets_used = (size_t)0;
    table___0->n_entries = (size_t)0;
    table___0->hasher = hasher;
    table___0->comparator = comparator;
    table___0->data_freer = data_freer;

    return (table___0);
  fail:

    return ((Hash_table *)((void *)0));
  }
}

static void free_entry(Hash_table *table___0, struct hash_entry *entry) {

  {
    entry->data = (void *)0;

    table___0->free_entry_list = entry;
  }
}
static void *hash_find_entry(Hash_table *table___0, void const *entry,
                             struct hash_entry **bucket_head, _Bool delete) {
  struct hash_entry *bucket;
  struct hash_entry *tmp;
  struct hash_entry *cursor;
  void *data;
  struct hash_entry *next;
  _Bool tmp___0;
  void *data___0;
  struct hash_entry *next___0;
  _Bool tmp___1;

  {
    tmp = safe_hasher((Hash_table const *)table___0, entry);
    bucket = tmp;
    *bucket_head = bucket;
    if ((unsigned long)bucket->data == (unsigned long)((void *)0)) {
      return ((void *)0);
    }
    if ((unsigned long)entry == (unsigned long)bucket->data) {

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

      } else {

        if (tmp___1) {
        _L___0:
          data___0 = (cursor->next)->data;
          if (delete) {
            next___0 = cursor->next;
            cursor->next = next___0->next;
          }
          return (data___0);
        }
      }
      cursor = cursor->next;
    }
  while_break:;
  }
}
static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {
  struct hash_entry *bucket;
  struct hash_entry *cursor;
  struct hash_entry *next;
  void *data;
  struct hash_entry *new_bucket;
  struct hash_entry *new_entry;
  struct hash_entry *tmp;

  {

    while (1) {

      if (!((unsigned long)bucket < (unsigned long)src->bucket_limit)) {
      }
      if (bucket->data) {
        cursor = bucket->next;
        while (1) {

          if (!cursor) {
          }
          data = cursor->data;
          new_bucket = safe_hasher((Hash_table const *)dst, (void const *)data);
          next = cursor->next;
          if (new_bucket->data) {
            cursor->next = new_bucket->next;
            new_bucket->next = cursor;
          } else {
            new_bucket->data = data;
            (dst->n_buckets_used)++;
            free_entry(dst, cursor);
          }
          cursor = next;
        }
      while_break___0:
        data = bucket->data;
        bucket->next = (struct hash_entry *)((void *)0);

        new_bucket = safe_hasher((Hash_table const *)dst, (void const *)data);
        if (new_bucket->data) {
          tmp = allocate_entry(dst);

          if ((unsigned long)new_entry == (unsigned long)((void *)0)) {
          }
          new_entry->data = data;
          new_entry->next = new_bucket->next;
          new_bucket->next = new_entry;
        } else {

          (dst->n_buckets_used)++;
        }
        bucket->data = (void *)0;
        (src->n_buckets_used)--;
      }
    __Cont:
      bucket++;
    }
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

    new_size = tmp;

    if (new_size == table___0->n_buckets) {
    }
    new_table = &storage;
    new_table->bucket =
        (struct hash_entry *)calloc(new_size, sizeof(*(new_table->bucket)));
    if ((unsigned long)new_table->bucket == (unsigned long)((void *)0)) {
      return ((_Bool)0);
    }
    new_table->n_buckets = new_size;
    new_table->bucket_limit =
        (struct hash_entry const *)(new_table->bucket + new_size);

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

      table___0->n_buckets_used = new_table->n_buckets_used;
      table___0->free_entry_list = new_table->free_entry_list;
      return ((_Bool)1);
    }
    table___0->free_entry_list = new_table->free_entry_list;
    tmp___1 = transfer_entries(table___0, new_table, (_Bool)1);
    if (tmp___1) {
      tmp___2 = transfer_entries(table___0, new_table, (_Bool)0);
      if (!tmp___2) {
        abort();
      }
    } else {
    }
    free((void *)new_table->bucket);
    return ((_Bool)0);
  }
}
int hash_insert_if_absent(Hash_table *table___0, void const *entry,
                          void const **matched_ent) {
  void *data;
  struct hash_entry *bucket;
  Hash_tuning const *tuning;
  float candidate;
  float tmp;
  _Bool tmp___0;
  void *tmp___1;

  struct hash_entry *tmp___2;

  {

    data = hash_find_entry(table___0, entry, &bucket, (_Bool)0);

    check_tuning(table___0);
    if ((float const)table___0->n_buckets_used >
        (table___0->tuning)->growth_threshold *
            (float const)table___0->n_buckets) {
      tuning = table___0->tuning;
      if (tuning->is_n_buckets) {
        tmp =
            (float)((float const)table___0->n_buckets * tuning->growth_factor);
      } else {
        tmp = (float)(((float const)table___0->n_buckets *
                       tuning->growth_factor) *
                      tuning->growth_threshold);
      }
      candidate = tmp;
      if ((float)0xffffffffffffffffUL <= candidate) {
      }

      if (!tmp___0) {
        return (-1);
      }
      tmp___1 = hash_find_entry(table___0, entry, &bucket, (_Bool)0);
    }

    bucket->data = (void *)entry;
    (table___0->n_entries)++;
    (table___0->n_buckets_used)++;
    return (1);
  }
}

size_t hash_pjw(void const *x, size_t tablesize) __attribute__((__pure__));
size_t triple_hash(void const *x, size_t table_size) __attribute__((__pure__));
size_t triple_hash(void const *x, size_t table_size) {
  struct F_triple const *p;
  size_t tmp;
  size_t tmp___0;

  {
    p = (struct F_triple const *)x;
    tmp___0 = hash_pjw((void const *)p->name, table_size);

    return ((tmp ^ (unsigned long)p->st_ino) % table_size);
  }
}

_Bool triple_compare_ino_str(void const *x, void const *y) {
  struct F_triple const *a;
  struct F_triple const *b;
  int tmp___0;
  int tmp___1;

  {
    a = (struct F_triple const *)x;
    b = (struct F_triple const *)y;
    if (a->st_ino == b->st_ino) {
      if (a->st_dev == b->st_dev) {
        tmp___1 = strcmp((char const *)a->name, (char const *)b->name);

      } else {
        tmp___0 = 0;
      }
    } else {
      tmp___0 = 0;
    }
    return ((_Bool)tmp___0);
  }
}

size_t hash_pjw(void const *x, size_t tablesize) {
  char const *s;
  size_t h;

  {
    h = (size_t)0;
    s = (char const *)x;
    while (1) {

      if (!*s) {
        goto while_break;
      }
      h = (unsigned long)*s + ((h << 9) | (h >> (sizeof(size_t) * 8UL - 9UL)));
      s++;
    }
  while_break:;
    return (h % tablesize);
  }
}

extern void(__attribute__((__nonnull__(1, 4))) qsort)(
    void *__base, size_t __nmemb, size_t __size,
    int (*__compar)(void const *, void const *));
extern int fseeko(FILE *__stream, __off_t __off, int __whence);

int(__attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp, off_t offset,
                                                int whence) {
  off_t pos;
  int tmp;
  off_t tmp___0;
  int tmp___1;

  {
    if ((unsigned long)fp->_IO_read_end == (unsigned long)fp->_IO_read_ptr) {
      if ((unsigned long)fp->_IO_write_ptr ==
          (unsigned long)fp->_IO_write_base) {
        if ((unsigned long)fp->_IO_save_base == (unsigned long)((void *)0)) {
          tmp = fileno(fp);

          pos = tmp___0;
          if (pos == -1L) {
          }

          fp->_offset = pos;
        }
      }
    }

    return (tmp___1);
  }
}

FILE *fopen_safer(char const *file, char const *mode) {
  FILE *fp;
  FILE *tmp;
  int fd;
  int tmp___0;
  int f;
  int tmp___1;
  int e;
  int *tmp___2;
  int *tmp___3;

  int *tmp___4;

  int tmp___6;

  {
    tmp = fopen(file, mode);
    fp = tmp;
    if (fp) {
      tmp___0 = fileno(fp);
      fd = tmp___0;
      if (0 <= fd) {
        if (fd <= 2) {
          tmp___1 = dup_safer(fd);

          if (f < 0) {
            tmp___2 = __errno_location();

            rpl_fclose(fp);

            *tmp___3 = e;
            return ((FILE *)((void *)0));
          }
          tmp___6 = rpl_fclose(fp);
          if (tmp___6 != 0) {

          } else {
            fp = fdopen(f, mode);
            if (!fp) {

              tmp___4 = __errno_location();

              close(f);

              return ((FILE *)((void *)0));
            }
          }
        }
      }
    }
    return (fp);
  }
}
int filevercmp(char const *s1, char const *s2);
static char const *match_suffix(char const **str) {
  char const *match;
  _Bool read_alpha;
  _Bool tmp;
  _Bool tmp___0;

  {
    match = (char const *)((void *)0);
    read_alpha = (_Bool)0;
    while (1) {

      if (!*(*str)) {
        goto while_break;
      }
      if (read_alpha) {

        tmp = c_isalpha((int)*(*str));
        if (!tmp) {
        }
      } else {
        if (46 == (int)*(*str)) {

          if (!match) {
            match = *str;
          }
        } else {
          tmp___0 = c_isalnum((int)*(*str));
        }
      }
      (*str)++;
    }
  while_break:;
  }
}
__inline static int order(unsigned char c) {
  _Bool tmp;
  _Bool tmp___0;

  {
    tmp___0 = c_isdigit((int)c);
    if (tmp___0) {

    } else {
      tmp = c_isalpha((int)c);
    }
  }
}
static int __attribute__((__pure__)) verrevcmp(char const *s1, size_t s1_len,
                                               char const *s2, size_t s2_len) {
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
    s1_pos = (size_t)0;
    s2_pos = (size_t)0;

    if (!(s1_pos < s1_len)) {
      if (!(s2_pos < s2_len)) {
        goto while_break;
      }
    }
    first_diff = 0;

    if (s1_pos < s1_len) {
      tmp___3 = c_isdigit((int)*(s1 + s1_pos));

    } else {
    _L:
      if (s2_pos < s2_len) {
        tmp___4 = c_isdigit((int)*(s2 + s2_pos));
        if (tmp___4) {
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

  while_break___0:;

    if (!((int const) * (s1 + s1_pos) == 48)) {
    }
    s1_pos++;

  while_break___1:;

  while_break___2:;

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

    tmp___3 = strcmp("..", s2);

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

int rpl_fflush(FILE *stream) {

  {}
}
int fd_safer(int fd) {

  {}
}

static int have_dupfd_cloexec = 0;
int rpl_fcntl(int fd, int action, ...) {
  va_list arg;
  int result;
  int target;

  int *tmp___0;

  int *tmp___3;

  void *p;
  void *tmp___5;

  {
    result = -1;

    if (0 <= have_dupfd_cloexec) {
      result = fcntl(fd, action, target);
      if (0 <= result) {
        have_dupfd_cloexec = 1;
      } else {
        tmp___0 = __errno_location();
      }
    } else {
      result = rpl_fcntl(fd, 0, target);
    }

    p = tmp___5;
    result = fcntl(fd, action, p);

    return (result);
  }
}
extern int fclose(FILE *__stream);
int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {
  int saved_errno;
  int fd;
  int result;
  int tmp;

  int tmp___1;
  int tmp___2;
  __off_t tmp___3;
  int tmp___4;

  {

    fd = fileno(fp);
    if (fd < 0) {
      tmp = fclose(fp);
      return (tmp);
    }

    if (tmp___1 != 0) {
      tmp___2 = fileno(fp);

      if (tmp___3 != -1L) {
      _L:
        tmp___4 = rpl_fflush(fp);
      }
    } else {
    }
    result = fclose(fp);
  }
}

void fadvise(FILE *fp, fadvice_t advice) {

  { return; }
}

int dup_safer(int fd) {
  int tmp;

  { return (tmp); }
}

extern char *optarg;
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 3))) pthread_create)(pthread_t *__restrict __newthread,
                                        pthread_attr_t const *__restrict __attr,
                                        void *(*__start_routine)(void *),
                                        void *__restrict __arg);
extern int pthread_join(pthread_t __th, void **__thread_return);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) pthread_mutex_destroy)(pthread_mutex_t *__mutex);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1))) pthread_mutex_lock)(pthread_mutex_t *__mutex);

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) pthread_cond_init)(
    pthread_cond_t *__restrict __cond,
    pthread_condattr_t const *__restrict __cond_attr);

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1))) pthread_cond_signal)(pthread_cond_t *__cond);
extern int(__attribute__((__nonnull__(1, 2))) pthread_cond_wait)(
    pthread_cond_t *__restrict __cond, pthread_mutex_t *__restrict __mutex);
extern __attribute__((__nothrow__))
__sighandler_t(__attribute__((__leaf__)) signal)(int __sig,
                                                 void (*__handler)(int));

extern int fputc_unlocked(int __c, FILE *__stream);

extern size_t fwrite_unlocked(void const *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);

static int decimal_point;
static int thousands_sep;
static _Bool hard_LC_COLLATE;

static char eolchar = (char)'\n';
static _Bool blanks[256];
static _Bool nonprinting[256];
static _Bool nondictionary[256];
static char fold_toupper[256];

static size_t merge_buffer_size = (size_t)262144;
static size_t sort_size;
static char const **temp_dirs;
static size_t temp_dir_count;
static size_t temp_dir_alloc;
static _Bool reverse;

static int tab = 128;
static _Bool unique;
static _Bool have_read_stdin;
static struct keyfield *keylist;
static char const *compress_program;
static _Bool debug;
static unsigned int nmerge = 16U;
static __attribute__((__noreturn__)) void die(char const *message,
                                              char const *file);
static __attribute__((__noreturn__)) void die(char const *message,
                                              char const *file);
static void die(char const *message, char const *file) {

  char const *tmp___0;
  int *tmp___1;

  {

    tmp___1 = __errno_location();
    error(0, *tmp___1, "%s: %s", message, tmp___0);
    exit(2);
  }
}
__attribute__((__noreturn__)) void usage(int status);
void usage(int status) {

  {
    if (status != 0) {

    } else {
    }
    exit(status);
  }
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
static struct cs_status cs_enter(void) {
  struct cs_status status;
  int tmp;

  {
    tmp = sigprocmask(0, (sigset_t const *)(&caught_signals), &status.sigs);
    status.valid = (_Bool)(tmp == 0);
    return (status);
  }
}
static void cs_leave(struct cs_status status) {

  {}
}
static struct tempnode *volatile temphead;
static struct tempnode *volatile *temptail = &temphead;
static Hash_table *proctab;
static size_t proctab_hasher(void const *entry, size_t tabsize) {
  struct tempnode const *node;

  {
    node = (struct tempnode const *)entry;
    return ((unsigned long)node->pid % tabsize);
  }
}

static pid_t nprocs;
static _Bool delete_proc(pid_t pid);
static pid_t reap(pid_t pid) {
  int status;
  pid_t cpid;
  int tmp;
  pid_t tmp___0;
  pid_t tmp___1;
  char *tmp___2;
  int *tmp___3;

  {

    tmp___1 = waitpid(tmp___0, &status, tmp);
    cpid = tmp___1;
    if (cpid < 0) {

      tmp___3 = __errno_location();

    } else {
      if (0 < cpid) {
      }
    }
    return (cpid);
  }
}
static void register_proc(struct tempnode *temp) {

  {

    temp->state = (char)1;

    return;
  }
}
static _Bool delete_proc(pid_t pid) {
  struct tempnode test;

  struct tempnode *tmp;

  {

    tmp = (struct tempnode *)hash_delete(proctab, (void const *)(&test));

    return ((_Bool)1);
  }
}
static void wait_proc(pid_t pid) {
  _Bool tmp;

  {

    if (tmp) {
      reap(pid);
    }
  }
}
static void reap_exited(void) {
  pid_t tmp;

  {

  while_continue:;
    if (0 < nprocs) {
      tmp = reap(0);

    } else {
    }
    goto while_continue;

  while_break:;
    return;
  }
}

static void reap_all(void) {

  {

    if (!(0 < nprocs)) {
    }

  while_break:;
  }
}
static void cleanup(void) {
  struct tempnode const *node;

  {
    node = (struct tempnode const *)temphead;

    if (!node) {
    }
    unlink((char const *)(node->name));

  while_break:
    temphead = (struct tempnode *)((void *)0);
    return;
  }
}
static void exit_cleanup(void) {
  struct cs_status cs;

  {
  }
}
static struct tempnode *create_temp_file(int *pfd, _Bool survive_fd_exhaustion);
static char const slashbase[12] = {
    (char const)'/', (char const)'s', (char const)'o', (char const)'r',
    (char const)'t', (char const)'X', (char const)'X', (char const)'X',
    (char const)'X', (char const)'X', (char const)'X', (char const)'\000'};
static size_t temp_dir_index;
static struct tempnode *create_temp_file(int *pfd,
                                         _Bool survive_fd_exhaustion) {
  int fd;
  int saved_errno;
  char const *temp_dir;
  size_t len;
  size_t tmp;
  struct tempnode *node;
  struct tempnode *tmp___0;
  char *file;
  struct cs_status cs;
  int *tmp___1;
  int *tmp___2;

  {
    temp_dir = *(temp_dirs + temp_dir_index);
    tmp = strlen(temp_dir);
    len = tmp;
    tmp___0 = (struct tempnode *)xmalloc(
        ((unsigned long)(&((struct tempnode *)0)->name) + len) +
        sizeof(slashbase));
    node = tmp___0;
    file = node->name;
    memcpy((void *)file, (void const *)temp_dir, len);
    memcpy((void *)(file + len), (void const *)(slashbase), sizeof(slashbase));
    node->next = (struct tempnode *)((void *)0);
    temp_dir_index++;
    if (temp_dir_index == temp_dir_count) {
    }
    cs = cs_enter();
    fd = mkstemp_safer(file);
    if (0 <= fd) {
      *temptail = node;
      temptail = &node->next;
    }
    tmp___1 = __errno_location();
    saved_errno = *tmp___1;
    cs_leave(cs);

    *tmp___2 = saved_errno;

    *pfd = fd;
    return (node);
  }
}
static FILE *stream_open(char const *file, char const *how) {
  FILE *fp;
  int tmp;
  FILE *tmp___0;

  {
    if (!file) {
      return (stdout);
    }
    if ((int const) * how == 114) {
      tmp = strcmp(file, "-");
      if (tmp == 0) {

        fp = stdin;
      } else {
        fp = fopen_safer(file, how);
      }
      fadvise(fp, (fadvice_t)2);
      return (fp);
    }
    tmp___0 = fopen_safer(file, how);
    return (tmp___0);
  }
}
static FILE *xfopen(char const *file, char const *how) {
  FILE *fp;
  FILE *tmp;
  char *tmp___0;

  {
    tmp = stream_open(file, how);
    fp = tmp;
    if (!fp) {
      tmp___0 = gettext("open failed");
      die((char const *)tmp___0, file);
    }
    return (fp);
  }
}
static void xfclose(FILE *fp, char const *file) {
  int tmp;
  int tmp___0;

  int tmp___4;

  {
    tmp = fileno(fp);

    tmp___0 = feof_unlocked(fp);

  case_1:

  switch_default:
    tmp___4 = rpl_fclose(fp);

    ;
    return;
  }
}

static pid_t pipe_fork(int *pipefds, size_t tries) {

  int saved_errno;
  double wait_retry;
  pid_t pid;

  int tmp;
  int *tmp___0;

  int *tmp___4;
  int *tmp___5;

  {
    wait_retry = 0.25;
    tmp = pipe(pipefds);
    if (tmp < 0) {
      return (-1);
    }
    if (nmerge + 1U < (unsigned int)nprocs) {
      reap_some();
    }

  while_break:;
    if (pid < 0) {

      saved_errno = *tmp___4;
      close(*(pipefds + 0));

      tmp___5 = __errno_location();

    } else {
      if (pid == 0) {

      } else {
      }
    }
    return (pid);
  }
}
static struct tempnode *maybe_create_temp(FILE **pfp,
                                          _Bool survive_fd_exhaustion) {
  int tempfd;
  struct tempnode *node;
  struct tempnode *tmp;
  int pipefds[2];

  char *tmp___3;

  {
    tmp = create_temp_file(&tempfd, survive_fd_exhaustion);
    node = tmp;

    *pfp = fdopen(tempfd, "w");
    if (!*pfp) {
      tmp___3 = gettext("couldn\'t create temporary file");
      die((char const *)tmp___3, (char const *)(node->name));
    }
    return (node);
  }
}
static struct tempnode *create_temp(FILE **pfp) {
  struct tempnode *tmp;

  {
    tmp = maybe_create_temp(pfp, (_Bool)0);
    return (tmp);
  }
}
static FILE *open_temp(struct tempnode *temp) {
  int tempfd;
  int pipefds[2];
  FILE *fp;
  pid_t child;
  pid_t tmp;

  int *tmp___2;
  int *tmp___3;
  char *tmp___4;
  int *tmp___5;

  {

    if ((int)temp->state == 1) {
      wait_proc(temp->pid);
    }

    if (tempfd < 0) {
    }

    child = tmp;
    if (child == -1) {
    }
    if (child == 0) {
      goto case_0;
    }

  case_neg_1:
    tmp___2 = __errno_location();

    close(tempfd);
    tmp___3 = __errno_location();

  case_0:

    close(tempfd);

    close(pipefds[1]);

    tmp___5 = __errno_location();
    error(2, *tmp___5, (char const *)tmp___4, compress_program);

    register_proc(temp);
    close(tempfd);
    close(pipefds[1]);
    fp = fdopen(pipefds[0], "r");

    ;
    return (fp);
  }
}
static void add_temp_dir(char const *dir) {
  size_t tmp;

  {
    if (temp_dir_count == temp_dir_alloc) {
      temp_dirs = (char const **)x2nrealloc((void *)temp_dirs, &temp_dir_alloc,
                                            sizeof(*temp_dirs));
    }
    tmp = temp_dir_count;
    temp_dir_count++;
    *(temp_dirs + tmp) = dir;
  }
}
static void zaptemp(char const *name) {
  struct tempnode *volatile *pnode;
  struct tempnode *node;
  struct tempnode *next;
  int unlink_status;
  int unlink_errno;
  struct cs_status cs;
  int *tmp;

  {
    unlink_errno = 0;
    pnode = &temphead;
    while (1) {
      node = (struct tempnode *)*pnode;
      if (!((unsigned long)(node->name) != (unsigned long)name)) {
        goto while_break;
      }
      goto __Cont;
    __Cont:
      pnode = &node->next;
    }
  while_break:;

    next = (struct tempnode *)node->next;
    cs = cs_enter();
    unlink_status = unlink(name);
    tmp = __errno_location();

    *pnode = next;

    return;
  }
}

static void inittables(void) {
  size_t i;
  unsigned short const **tmp;
  int tmp___0;
  unsigned short const **tmp___1;
  int tmp___2;
  unsigned short const **tmp___3;
  unsigned short const **tmp___4;
  int tmp___5;

  size_t j;

  {
    i = (size_t)0;

    if (!(i < 256UL)) {
    }
    tmp = __ctype_b_loc();

    blanks[i] = (_Bool)tmp___0;
    tmp___1 = __ctype_b_loc();

    nonprinting[i] = (_Bool)tmp___2;
    tmp___3 = __ctype_b_loc();
    if ((int const) * (*tmp___3 + (int)i) & 8) {
      tmp___5 = 0;
    } else {

      if ((int const) * (*tmp___4 + (int)i) & 1) {
        tmp___5 = 0;
      } else {
        tmp___5 = 1;
      }
    }
    nondictionary[i] = (_Bool)tmp___5;
    fold_toupper[i] = (char)toupper((int)i);
    i++;

  while_break:;
  }
}

static void specify_sort_size(int oi, char c, char const *s) {
  uintmax_t n;
  char *suffix;
  enum strtol_error e;
  enum strtol_error tmp;
  double mem;
  double tmp___0;

  {

    e = tmp;
    if ((unsigned int)e == 0U) {
      if ((unsigned int)*(suffix + -1) - 48U <= 9U) {
        if (n <= 18014398509481983UL) {
          n *= 1024UL;
        } else {
          e = (enum strtol_error)1;
        }
      }
    }
    if ((unsigned int)e == 2U) {
      if ((unsigned int)*(suffix + -1) - 48U <= 9U) {
        if (!*(suffix + 1)) {

          goto switch_break;

          if (mem < (double)0xffffffffffffffffUL) {
            n = (uintmax_t)mem;
            e = (enum strtol_error)0;
          } else {
          }
          goto switch_break;
        switch_break:;
        }
      }
    }
    if ((unsigned int)e == 0U) {
      if (n < sort_size) {
        return;
      }

      if (sort_size == n) {
        if (sort_size > (unsigned long)nmerge * (2UL + sizeof(struct line))) {

        } else {
        }
        return;
      }
      e = (enum strtol_error)1;
    }
    xstrtol_fatal(e, oi, c, long_options___1, s);
  }
}
static size_t specify_nthreads(int oi, char c, char const *s) {
  unsigned long nthreads;
  enum strtol_error e;
  enum strtol_error tmp;

  {
    tmp = xstrtoul(s, (char **)((void *)0), 10, &nthreads, "");

    if ((unsigned int)e == 1U) {
      return (0xffffffffffffffffUL);
    }
    if ((unsigned int)e != 0U) {
    }

    return (nthreads);
  }
}
static size_t default_sort_size(void) {
  double avail;
  double tmp;
  double total;
  double tmp___0;
  double mem;
  double tmp___1;
  struct rlimit rlimit;
  size_t size;
  int tmp___2;

  int tmp___4;
  size_t tmp___5;

  {
    tmp = physmem_available();
    avail = tmp;
    tmp___0 = physmem_total();
    total = tmp___0;

    mem = tmp___1;
    size = 0xffffffffffffffffUL;
    tmp___2 = getrlimit((__rlimit_resource_t)2, &rlimit);
    if (tmp___2 == 0) {
      if (rlimit.rlim_cur < size) {
        size = rlimit.rlim_cur;
      }
    }

    size /= 2UL;
    tmp___4 = getrlimit((__rlimit_resource_t)5, &rlimit);
    if (tmp___4 == 0) {
      if ((rlimit.rlim_cur / 16UL) * 15UL < size) {
      }
    }
    if (mem < (double)size) {
    }

    return (tmp___5);
  }
}
static size_t size_bound;
static size_t sort_buffer_size(FILE *const *fps, size_t nfps,
                               char *const *files, size_t nfiles,
                               size_t line_bytes) {
  size_t worst_case_per_input_byte;
  size_t size;
  size_t i;
  struct stat st;
  off_t file_size;
  size_t worst_case;
  char *tmp;
  int tmp___0;
  int tmp___1;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {
    worst_case_per_input_byte = line_bytes + 1UL;
    size = worst_case_per_input_byte + 1UL;
    i = (size_t)0;
    while (1) {

      if (!(i < nfiles)) {
        goto while_break;
      }
      if (i < nfps) {
        tmp___0 = fileno((FILE *)*(fps + i));
        tmp___1 = fstat(tmp___0, &st);

      } else {
        tmp___6 = strcmp((char const *)*(files + i), "-");
        if (tmp___6 == 0) {
          tmp___3 = fstat(0, &st);

        } else {
        }
        tmp___7 = tmp___5;
      }
      if (tmp___7 != 0) {
        tmp = gettext("stat failed");
        die((char const *)tmp, (char const *)*(files + i));
      }
      if ((st.st_mode & 61440U) == 32768U) {
        file_size = st.st_size;
      } else {
        if (sort_size) {
          return (sort_size);
        }
      }
      if (!size_bound) {
        size_bound = sort_size;
        if (!size_bound) {
          size_bound = default_sort_size();
        }
      }
      worst_case = (size_t)file_size * worst_case_per_input_byte + 1UL;

      size += worst_case;
      i++;
    }
  while_break:;
    return (size);
  }
}
static void initbuf(struct buffer *buf___1, size_t line_bytes, size_t alloc) {
  size_t tmp;
  size_t tmp___0;

  {

    alloc += sizeof(struct line) - alloc % sizeof(struct line);
    buf___1->buf = (char *)malloc(alloc);
    if (buf___1->buf) {
      goto while_break;
    }

    if (alloc <= line_bytes + 1UL) {
    }

  while_break:
    buf___1->line_bytes = line_bytes;
    buf___1->alloc = alloc;
    tmp___0 = (size_t)0;
    buf___1->nlines = tmp___0;
    tmp = tmp___0;
    buf___1->left = tmp;

    buf___1->eof = (_Bool)0;
    return;
  }
}
__inline static struct line *buffer_linelim(struct buffer const *buf___1) {

  { return ((struct line *)(buf___1->buf + buf___1->alloc)); }
}
static char *begfield(struct line const *line, struct keyfield const *key) {
  char *ptr;
  char *lim;
  size_t sword;
  size_t schar;
  size_t tmp;

  unsigned char tmp___3;

  {
    ptr = (char *)line->text;
    lim = (ptr + line->length) - 1;
    sword = (size_t)key->sword;
    schar = (size_t)key->schar;
    if (tab != 128) {

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp = sword;

        if (!tmp) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      while (1) {

        if ((unsigned long)ptr < (unsigned long)lim) {
          if (!((int)*ptr != tab)) {
          }
        } else {
        }
        ptr++;
      }
    while_break___0:;
      if ((unsigned long)ptr < (unsigned long)lim) {
        ptr++;
      }

    while_break:;
    } else {

    while_break___1:;
    }
    if (key->skipsblanks) {

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp___3 = to_uchar(*ptr);
        if (!blanks[tmp___3]) {
          goto while_break___4;
        }
      } else {
        goto while_break___4;
      }
      ptr++;

    while_break___4:;
    }
    if ((unsigned long)lim < (unsigned long)(ptr + schar)) {

    } else {
      ptr += schar;
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

  {
    ptr = (char *)line->text;
    lim = (ptr + line->length) - 1;
    eword = (size_t)key->eword;
    echar = (size_t)key->echar;

    if (tab != 128) {

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp = eword;
        eword--;
        if (!tmp) {
          goto while_break;
        }
      } else {
        goto while_break;
      }

      if ((unsigned long)ptr < (unsigned long)lim) {
        if (!((int)*ptr != tab)) {
        }
      } else {
        goto while_break___0;
      }
      ptr++;

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

    while_break:;
    } else {

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

    while_break___1:;
    }
    if (echar != 0UL) {
      if (key->skipeblanks) {

      while_break___4:;
      }
      if ((unsigned long)lim < (unsigned long)(ptr + echar)) {

      } else {
        ptr += echar;
      }
    }
    return (ptr);
  }
}
static _Bool fillbuf___7(struct buffer *buf___1, FILE *fp, char const *file) {

  char eol;
  size_t line_bytes;
  size_t mergesize;
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
  char *tmp___2;
  int tmp___3;
  char *tmp___4;
  int tmp___5;

  struct line *tmp___8;
  size_t line_alloc;

  {

    eol = eolchar;
    line_bytes = buf___1->line_bytes;
    mergesize = merge_buffer_size - (2UL + sizeof(struct line));
    if (buf___1->eof) {
      return ((_Bool)0);
    }
    if (buf___1->used != buf___1->left) {
      memmove((void *)buf___1->buf,
              (void const *)((buf___1->buf + buf___1->used) - buf___1->left),
              buf___1->left);
      buf___1->used = buf___1->left;
      buf___1->nlines = (size_t)0;
    }

    ptr = buf___1->buf + buf___1->used;
    tmp = buffer_linelim((struct buffer const *)buf___1);
    linelim = tmp;
    line = linelim - buf___1->nlines;
    avail = (size_t)(((char *)linelim - buf___1->nlines * line_bytes) - ptr);
    if (buf___1->nlines) {
      tmp___0 = line->text + line->length;
    } else {
      tmp___0 = buf___1->buf;
    }
    line_start = tmp___0;

    if (!(line_bytes + 1UL < avail)) {
      goto while_break___0;
    }
    readsize = (avail - 1UL) / (line_bytes + 1UL);
    tmp___1 = fread_unlocked((void *)ptr, (size_t)1, readsize, fp);
    bytes_read = tmp___1;
    ptrlim = ptr + bytes_read;
    avail -= bytes_read;
    if (bytes_read != readsize) {
      tmp___3 = ferror_unlocked(fp);
      if (tmp___3) {
        tmp___2 = gettext("read failed");
      }
      tmp___5 = feof_unlocked(fp);
      if (tmp___5) {
        buf___1->eof = (_Bool)1;
        if ((unsigned long)buf___1->buf == (unsigned long)ptrlim) {
        }
        if ((unsigned long)line_start != (unsigned long)ptrlim) {
          if ((int)*(ptrlim + -1) != (int)eol) {

            ptrlim++;
            *tmp___4 = eol;
          }
        }
      }
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
      if (mergesize > line->length) {

      } else {
        mergesize = line->length;
      }
      avail -= line_bytes;

      line_start = ptr;
    }
  while_break___1:
    ptr = ptrlim;
    if (buf___1->eof) {
      goto while_break___0;
    }

  while_break___0:
    buf___1->used = (size_t)(ptr - buf___1->buf);
    tmp___8 = buffer_linelim((struct buffer const *)buf___1);
    buf___1->nlines = (size_t)(tmp___8 - line);
    if (buf___1->nlines != 0UL) {

      merge_buffer_size = mergesize + (2UL + sizeof(struct line));
      return ((_Bool)1);
    }
    line_alloc = buf___1->alloc / sizeof(struct line);
    buf___1->buf = (char *)x2nrealloc((void *)buf___1->buf, &line_alloc,
                                      sizeof(struct line));
    buf___1->alloc = line_alloc * sizeof(struct line);

    return ((_Bool)0);
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
      }
    }
  while_break:;
    if ((int)ch == decimal_point) {

      if (!((unsigned int)ch - 48U <= 9U)) {
        goto while_break___1;
      }
      nonzero |= (int)ch - 48;

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

  unsigned char tmp___0;
  int diff;
  int __attribute__((__pure__)) tmp___1;
  int __attribute__((__pure__)) tmp___2;
  int tmp___3;
  int tmp___4;

  {

    ;

    tmp___0 = to_uchar((char)*b);
    if (!blanks[tmp___0]) {
    }
    b++;

  while_break___0:
    tmp___1 = find_unit_order(a);
    tmp___2 = find_unit_order(b);
    diff = (int)(tmp___1 - tmp___2);
    if (diff) {
      tmp___4 = diff;
    } else {
      tmp___3 = (int)strnumcmp(a, b, decimal_point, thousands_sep);
    }
    return (tmp___4);
  }
}
static int numcompare___3(char const *a, char const *b) {
  unsigned char tmp;
  unsigned char tmp___0;
  int tmp___1;

  {

    tmp = to_uchar((char)*a);
    if (!blanks[tmp]) {
      goto while_break;
    }
    a++;

  while_break:;
    while (1) {
      tmp___0 = to_uchar((char)*b);
      if (!blanks[tmp___0]) {
        goto while_break___0;
      }
      b++;
    }
  while_break___0:
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

    } else {
      if (a > b) {
        tmp___6 = 1;
      } else {
        if (a == b) {
          tmp___5 = 0;
        } else {

          tmp___5 = tmp___4;
        }
        tmp___6 = tmp___5;
      }
      tmp___7 = tmp___6;
    }
    return (tmp___7);
  }
}

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

    bufsize___1 = sizeof(stackbuf);

    s[0] = s[1];
    if (hard_LC_COLLATE) {
      lima = (char const *)(texta + lena);
      limb = (char const *)(textb + lenb);

      guess_bufsize = 3UL * (lena + lenb) + 2UL;
      if (bufsize___1 < guess_bufsize) {

        free(allocated);
        allocated = malloc(bufsize___1);
        buf___1 = (char *)allocated;
      }
      if ((unsigned long)texta < (unsigned long)lima) {
        tmp = xstrxfrm(buf___1, (char const *)texta, bufsize___1);
        tmp___0 = tmp + 1UL;
      } else {
      }
      sizea = tmp___0;
      a_fits = (_Bool)(sizea <= bufsize___1);
      if ((unsigned long)textb < (unsigned long)limb) {
        if (a_fits) {

        } else {
        }
        if (a_fits) {
          tmp___2 = buf___1 + sizea;
        } else {
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

      ;
    }

    tmp___8 =
        memcmp((void const *)(dig[0]), (void const *)(dig[1]), sizeof(dig[0]));

    if (!diff) {
      if (!xfrm_diff) {
        if (lena < lenb) {

        } else {
          tmp___9 = lenb;
        }
        xfrm_diff = memcmp((void const *)texta, (void const *)textb, tmp___9);
        if (!xfrm_diff) {
          xfrm_diff = (lena > lenb) - (lena < lenb);
        }
      }
    }

    return (diff);
  }
}

__inline static _Bool key_numeric(struct keyfield const *key) {
  int tmp;

  { return ((_Bool)tmp); }
}
static void debug_key(struct line const *line, struct keyfield const *key) {
  char *text;
  char *beg;
  char *lim;
  char saved___0;
  unsigned char tmp;
  char *tighter_lim;

  _Bool found_digit;

  _Bool tmp___5;
  size_t offset;
  size_t tmp___6;
  size_t width;
  size_t tmp___7;

  {
    text = (char *)line->text;
    beg = text;
    lim = (text + line->length) - 1;
    if (key) {
      if (key->sword != 0xffffffffffffffffUL) {
        beg = begfield(line, key);
      }
      if (key->eword != 0xffffffffffffffffUL) {
        lim = limfield(line, key);
      }
      if (key->skipsblanks) {

      } else {
        if (key->month) {
          goto _L___0;
        } else {

          if (tmp___5) {
          _L___0:
            saved___0 = *lim;

            tmp = to_uchar(*beg);
            if (!blanks[tmp]) {
              goto while_break;
            }
            beg++;

          while_break:
            tighter_lim = beg;

            *lim = saved___0;
            lim = tighter_lim;
          }
        }
      }
    }
    tmp___6 = debug_width((char const *)text, (char const *)beg);
    offset = tmp___6;
    tmp___7 = debug_width((char const *)beg, (char const *)lim);
    width = tmp___7;
    mark_key(offset, width);
    return;
  }
}
static void debug_line(struct line const *line) {
  struct keyfield const *key;

  {

  while_break:;
    return;
  }
}
static _Bool default_key_compare(struct keyfield const *key) {
  _Bool tmp;
  int tmp___0;

  {
    if (key->ignore) {

    } else {
      if (key->translate) {

      } else {
        if (key->skipsblanks) {

        } else {
          if (key->skipeblanks) {

          } else {
            tmp = key_numeric(key);
            if (tmp) {

            } else {
              if (key->month) {

              } else {
                if (key->version) {

                } else {
                }
              }
            }
          }
        }
      }
    }
    return ((_Bool)tmp___0);
  }
}
static void key_to_opts(struct keyfield const *key, char *opts___1) {

  { return; }
}
static void key_warnings(struct keyfield const *gkey, _Bool gkey_only) {
  struct keyfield const *key;
  struct keyfield ugkey;
  unsigned long keynum;
  size_t sword;
  size_t eword;

  char
      obuf[(((sizeof(sword) * 8UL) * 146UL + 484UL) / 485UL + 1UL) * 2UL + 4UL];

  _Bool tmp___23;

  {
    ugkey = (struct keyfield) * gkey;

    key = (struct keyfield const *)keylist;

    tmp___23 = default_key_compare((struct keyfield const *)(&ugkey));
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
  size_t size;
  size_t tmp;
  unsigned char tmp___0;
  unsigned char tmp___1;
  size_t tmp___2;

  unsigned char tmp___4;

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
  _Bool tmp___24;
  unsigned char tmp___25;
  unsigned char tmp___26;
  int tmp___27;

  {

    texta = (char *)a->keybeg;
    textb = (char *)b->keybeg;
    lima = (char *)a->keylim;

    translate = key->translate;
    ignore = key->ignore;

    if ((unsigned long)textb > (unsigned long)limb) {

    } else {
    }
    lena = (size_t)(lima - texta);
    lenb = (size_t)(limb - textb);
    if (hard_LC_COLLATE) {
      goto _L___2;
    } else {
      tmp___24 = key_numeric((struct keyfield const *)key);
      if (tmp___24) {

      } else {
        if (key->month) {

        } else {
          if (key->random) {

          } else {
            if (key->version) {
            _L___2:
              if (ignore) {
                goto _L___1;
              } else {
                if (translate) {
                _L___1:
                  size = ((lena + 1UL) + lenb) + 1UL;
                  if (size <= sizeof(stackbuf)) {
                    ta = stackbuf;
                    allocated = (void *)0;
                  } else {
                    allocated = xmalloc(size);
                    ta = (char *)allocated;
                  }
                  tb = (ta + lena) + 1;
                  i = (size_t)0;
                  tlena = i;

                  if (!(i < lena)) {
                  }
                  if (ignore) {
                    tmp___1 = to_uchar(*(texta + i));
                    if (!*(ignore + (int)tmp___1)) {
                    }
                  } else {
                  _L:

                    tlena++;
                    if (translate) {
                      tmp___0 = to_uchar(*(texta + i));
                      *(ta + tmp) = (char)*(translate + (int)tmp___0);
                    } else {
                      *(ta + tmp) = *(texta + i);
                    }
                  }
                  i++;

                while_break___0:
                  *(ta + tlena) = (char)'\000';
                  i = (size_t)0;
                  tlenb = i;
                  while (1) {

                    if (!(i < lenb)) {
                    }
                    if (ignore) {
                      tmp___4 = to_uchar(*(textb + i));
                      if (!*(ignore + (int)tmp___4)) {
                        goto _L___0;
                      }
                    } else {
                    _L___0:
                      tmp___2 = tlenb;
                      tlenb++;
                    }
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
              }
              if (key->numeric) {
                diff = numcompare___3((char const *)ta, (char const *)tb);
              } else {
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

                while_break___4:;

                  if ((unsigned long)textb < (unsigned long)limb) {
                    tmp___8 = to_uchar(*textb);
                    if (!*(ignore + (int)tmp___8)) {
                    }
                  } else {
                    goto while_break___5;
                  }
                  textb++;

                while_break___5:;
                  if ((unsigned long)texta < (unsigned long)lima) {
                    if (!((unsigned long)textb < (unsigned long)limb)) {
                    }
                  } else {
                    goto while_break___3;
                  }
                  tmp___9 = to_uchar(*texta);
                  tmp___10 = to_uchar((char)*(translate + (int)tmp___9));
                  tmp___11 = to_uchar(*textb);
                  tmp___12 = to_uchar((char)*(translate + (int)tmp___11));
                  diff = (int)tmp___10 - (int)tmp___12;

                  texta++;
                  textb++;

                while_break___3:
                  diff = ((unsigned long)texta < (unsigned long)lima) -
                         ((unsigned long)textb < (unsigned long)limb);
                  goto while_break___2;

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

                      if ((unsigned long)textb < (unsigned long)limb) {
                        tmp___14 = to_uchar(*textb);
                        if (!*(ignore + (int)tmp___14)) {
                          goto while_break___9;
                        }
                      } else {
                        goto while_break___9;
                      }
                      textb++;

                    while_break___9:;
                      if ((unsigned long)texta < (unsigned long)lima) {
                        if (!((unsigned long)textb < (unsigned long)limb)) {
                          goto while_break___7;
                        }
                      } else {
                      }
                      tmp___15 = to_uchar(*texta);
                      tmp___16 = to_uchar(*textb);
                      diff = (int)tmp___15 - (int)tmp___16;

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

                  } else {
                    if (translate) {

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

                    while_break___10:;
                    } else {

                      diff = memcmp((void const *)texta, (void const *)textb,
                                    tmp___23);
                      if (diff) {
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (diff) {
    }
    key = key->next;
    if (!key) {
      goto while_break;
    }
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
    if (key->reverse) {
      tmp___27 = -diff;
    } else {
    }
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
    if (keylist) {
      diff = keycompare(a, b);
    }
    alen = (size_t)(a->length - 1UL);
    blen = (size_t)(b->length - 1UL);
    if (alen == 0UL) {
      diff = -(blen != 0UL);
    } else {
      if (blen == 0UL) {
        diff = 1;
      } else {
        if (hard_LC_COLLATE) {
          diff = xmemcoll0((char const *)a->text, alen + 1UL,
                           (char const *)b->text, blen + 1UL);
        } else {
          if (alen < blen) {
            tmp = alen;
          } else {
            tmp = blen;
          }
          diff = memcmp((void const *)a->text, (void const *)b->text, tmp);
          if (!diff) {
            if (alen < blen) {
              diff = -1;
            } else {
              diff = alen != blen;
            }
          }
        }
      }
    }
    if (reverse) {
      tmp___0 = -diff;
    } else {
      tmp___0 = diff;
    }
    return (tmp___0);
  }
}
static void write_line(struct line const *line, FILE *fp,
                       char const *output_file) {
  char *buf___1;
  size_t n_bytes;
  char *ebuf;
  char const *c;

  size_t tmp___3;

  {
    buf___1 = (char *)line->text;
    n_bytes = (size_t)line->length;
    ebuf = buf___1 + n_bytes;
    if (!output_file) {
      if (debug) {
        c = (char const *)buf___1;

        debug_line(line);
      } else {
        goto _L;
      }
    } else {
    _L:
      *(ebuf + -1) = eolchar;
      tmp___3 = fwrite_unlocked((void const *)buf___1, (size_t)1, n_bytes, fp);
    }
  }
}
static _Bool check(char const *file_name___3, char checkonly) {
  FILE *fp;
  FILE *tmp;
  struct buffer buf___1;
  struct line temp;
  size_t alloc;
  uintmax_t line_number;
  struct keyfield const *key;
  _Bool nonunique;

  size_t tmp___0;
  struct line const *line;
  struct line const *tmp___1;
  struct line const *linebase;

  int tmp___6;

  _Bool tmp___8;

  {
    tmp = xfopen(file_name___3, "r");

    alloc = (size_t)0;
    line_number = (uintmax_t)0;
    key = (struct keyfield const *)keylist;
    nonunique = (_Bool)(!unique);

    if (merge_buffer_size > sort_size) {
      tmp___0 = merge_buffer_size;
    } else {
    }
    initbuf(&buf___1, sizeof(struct line), tmp___0);
    temp.text = (char *)((void *)0);

    tmp___8 = fillbuf___7(&buf___1, fp, file_name___3);
    if (!tmp___8) {
      goto while_break;
    }
    tmp___1 =
        (struct line const *)buffer_linelim((struct buffer const *)(&buf___1));
    line = tmp___1;
    linebase = line - buf___1.nlines;

  while_break___0:
    line_number += buf___1.nlines;
    if (alloc < (size_t)line->length) {

      if (!alloc) {
        alloc = (size_t)line->length;
        goto while_break___1;
      }
      if (!(alloc < (size_t)line->length)) {
      }

    while_break___1:

      temp.text = (char *)xmalloc(alloc);
    }
    memcpy((void *)temp.text, (void const *)line->text, (size_t)line->length);
    temp.length = (size_t)line->length;

  while_break:
    xfclose(fp, file_name___3);
    free((void *)buf___1.buf);
    free((void *)temp.text);
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
    tmp = (FILE **)xnmalloc(nfiles, sizeof(*fps));
    *pfps = tmp;
    fps = tmp;

    if (!((size_t)i < nfiles)) {
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
    }
    i++;

  while_break:;
    return ((size_t)i);
  }
}
static void mergefps(struct sortfile *files, size_t ntemps, size_t nfiles,
                     FILE *ofp, char const *output_file, FILE **fps) {
  struct buffer *buffer;
  struct buffer *tmp;
  struct line saved___0;
  struct line const *savedline;
  size_t savealloc;
  struct line const **cur;
  struct line const **tmp___0;
  struct line const **base;
  struct line const **tmp___1;
  size_t *ord;
  size_t *tmp___2;
  size_t i;
  size_t j;

  struct keyfield const *key;
  size_t tmp___3;
  struct line const *linelim;
  struct line const *tmp___4;
  _Bool tmp___5;

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
    tmp = (struct buffer *)xnmalloc(nfiles, sizeof(*buffer));
    buffer = tmp;
    savedline = (struct line const *)((void *)0);
    savealloc = (size_t)0;
    tmp___0 = (struct line const **)xnmalloc(nfiles, sizeof(*cur));
    cur = tmp___0;
    tmp___1 = (struct line const **)xnmalloc(nfiles, sizeof(*base));
    base = tmp___1;
    tmp___2 = (size_t *)xnmalloc(nfiles, sizeof(*ord));
    ord = tmp___2;
    key = (struct keyfield const *)keylist;

    i = (size_t)0;

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

      linelim = tmp___4;
      *(cur + i) = linelim - 1;
      *(base + i) = linelim - (buffer + i)->nlines;
      i++;
    } else {
      xfclose(*(fps + i), (files + i)->name);

      free((void *)(buffer + i)->buf);
      nfiles--;
      j = i;

      if (!(j < nfiles)) {
      }

      j++;

    while_break___0:;
    }

  while_break:

    if (!(i < nfiles)) {
    }
    *(ord + i) = i;
    i++;

  while_break___1:

  while_break___2:;

    ;
    if (!nfiles) {
      goto while_break___3;
    }
    smallest = *(cur + *(ord + 0));
    if (unique) {
      if (savedline) {
        tmp___7 = compare(savedline, smallest);
        if (tmp___7) {
          savedline = (struct line const *)((void *)0);
        }
      }
      if (!savedline) {
        savedline = (struct line const *)(&saved___0);
        if (savealloc < (size_t)smallest->length) {

          saved___0.text = (char *)xmalloc(savealloc);
        }
        saved___0.length = (size_t)smallest->length;
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

      } else {
        i = (size_t)1;

        if (!(i < nfiles)) {
        }

      while_break___5:
        nfiles--;
        xfclose(*(fps + *(ord + 0)), (files + *(ord + 0))->name);
        if (*(ord + 0) < ntemps) {
        }
        free((void *)(buffer + *(ord + 0))->buf);
        i = *(ord + 0);

        if (!(i < nfiles)) {
        }
        *(fps + i) = *(fps + (i + 1UL));
        *(files + i) = *(files + (i + 1UL));
        *(buffer + i) = *(buffer + (i + 1UL));
        *(cur + i) = *(cur + (i + 1UL));
        *(base + i) = *(base + (i + 1UL));

      while_break___6:
        i = (size_t)0;

        ;
      }
    }
    lo = (size_t)1;

    probe = lo;
    ord0 = *(ord + 0);
    while (1) {

      if (!(lo < hi)) {
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

  while_break___3:;
    if (unique) {
      if (savedline) {

        free((void *)saved___0.text);
      }
    }
    xfclose(ofp, output_file);
    free((void *)fps);
    free((void *)buffer);
  }
}
static size_t mergefiles(struct sortfile *files, size_t ntemps, size_t nfiles,
                         FILE *ofp, char const *output_file) {
  FILE **fps;
  size_t nopened;
  size_t tmp;
  char *tmp___0;

  {
    tmp = open_input_files(files, nfiles, &fps);
    nopened = tmp;
    if (nopened < nfiles) {
      if (nopened < 2UL) {

        die((char const *)tmp___0, (files + nopened)->name);
      }
    }
    mergefps(files, ntemps, nopened, ofp, output_file, fps);
    return (nopened);
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

    return;
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
        if (!to_temp) {
          *(temp + -1) = *(lo + -1);
        }
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
  struct line *tmp___0;
  struct line *tmp___1;
  struct line *tmp___2;
  size_t tmp___3;

  {
    tmp = (struct merge_node *)xmalloc((2UL * sizeof(*merge_tree)) * nthreads);
    merge_tree = tmp;
    root = merge_tree;
    tmp___2 = (struct line *)((void *)0);
    root->end_hi = tmp___2;

    root->end_lo = tmp___1;

    root->hi = tmp___0;
    root->lo = tmp___0;
    root->dest = (struct line **)((void *)0);
    tmp___3 = nlines;
    root->nhi = tmp___3;
    root->nlo = tmp___3;
    root->parent = (struct merge_node *)((void *)0);
    root->level = 0U;

    pthread_mutex_init(&root->lock, (pthread_mutexattr_t const *)((void *)0));
    init_node(root, root + 1, dest, nthreads, nlines, (_Bool)0);
    return (merge_tree);
  }
}
static void merge_tree_destroy(struct merge_node *merge_tree) {

  {}
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
    if (is_lo_child) {
      tmp = parent->nlo;
    } else {
      tmp = parent->nhi;
    }
    nlines = tmp;
    nlo = nlines / 2UL;
    nhi = nlines - nlo;
    lo = dest - total_lines;
    hi = lo - nlo;
    if (is_lo_child) {
      tmp___0 = &parent->end_lo;
    } else {
      tmp___0 = &parent->end_hi;
    }
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

      node->hi_child = (struct merge_node *)((void *)0);
    }
    return ((struct merge_node *)node_pool);
  }
}
static int compare_nodes(void const *a, void const *b) {
  struct merge_node const *nodea;
  struct merge_node const *nodeb;

  {
    nodea = (struct merge_node const *)a;
    nodeb = (struct merge_node const *)b;
    if (nodea->level == nodeb->level) {
      return (nodea->nlo + nodea->nhi < nodeb->nlo + nodeb->nhi);
    }
    return (nodea->level < nodeb->level);
  }
}
__inline static void lock_node(struct merge_node *node) {

  { pthread_mutex_lock(&node->lock); }
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

  {
    queue->priority_queue = heap_alloc(&compare_nodes, 2UL * nthreads);
    pthread_mutex_init(&queue->mutex, (pthread_mutexattr_t const *)((void *)0));
    pthread_cond_init(&queue->cond, (pthread_condattr_t const *)((void *)0));
    return;
  }
}
static void queue_insert(struct merge_node_queue *queue,
                         struct merge_node *node) {

  {
    pthread_mutex_lock(&queue->mutex);
    heap_insert(queue->priority_queue, (void *)node);
    node->queued = (_Bool)1;
    pthread_mutex_unlock(&queue->mutex);

    return;
  }
}
static struct merge_node *queue_pop(struct merge_node_queue *queue) {
  struct merge_node *node;

  {
    pthread_mutex_lock(&queue->mutex);
    while (1) {
      node = (struct merge_node *)heap_remove_top(queue->priority_queue);
      if (node) {
        goto while_break;
      }
      pthread_cond_wait(&queue->cond, &queue->mutex);
    }
  while_break:
    pthread_mutex_unlock(&queue->mutex);
    lock_node(node);
    node->queued = (_Bool)0;
    return (node);
  }
}

static void write_unique(struct line const *line, FILE *tfp,
                         char const *temp_output) {
  int tmp;

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

  size_t tmp___1;

  int tmp___3;
  size_t tmp___4;
  size_t tmp___5;
  size_t tmp___6;

  {
    lo_orig = node->lo;
    hi_orig = node->hi;
    to_merge = (total_lines >> 2U * (node->level + 1U)) + 1UL;
    if (node->level > 1U) {
      dest = *(node->dest);

    while_break:
      merged_lo = (size_t)(lo_orig - node->lo);
      merged_hi = (size_t)(hi_orig - node->hi);
      if (node->nhi == merged_hi) {

        if ((unsigned long)node->lo != (unsigned long)node->end_lo) {

          to_merge--;
          if (!tmp___1) {
          }
        } else {
        }
        dest--;
        (node->lo)--;
        *dest = *(node->lo);

      while_break___0:;
      } else {
        if (node->nlo == merged_lo) {

        while_break___1:;
        }
      }
      *(node->dest) = dest;
    } else {

      if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
        if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
          tmp___4 = to_merge;
          to_merge--;
          if (!tmp___4) {
            goto while_break___2;
          }
        } else {
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
        while (1) {

          if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
            tmp___5 = to_merge;
            to_merge--;
            if (!tmp___5) {
            }
          } else {
          }
          (node->lo)--;
          write_unique((struct line const *)node->lo, tfp, temp_output);
        }
      while_break___3:;
      } else {
        if (node->nlo == merged_lo) {
          while (1) {

            if ((unsigned long)node->hi != (unsigned long)node->end_hi) {

              to_merge--;
              if (!tmp___6) {
              }
            } else {
              goto while_break___4;
            }
            (node->hi)--;
            write_unique((struct line const *)node->hi, tfp, temp_output);
          }
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
  _Bool hi_avail;
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    if (!node->queued) {
      lo_avail = (_Bool)(node->lo - node->end_lo != 0L);
      hi_avail = (_Bool)(node->hi - node->end_hi != 0L);
      if (lo_avail) {
        if (hi_avail) {
          tmp = 1;
        } else {
          if (!node->nhi) {
            tmp = 1;
          } else {
            tmp = 0;
          }
        }
        tmp___1 = tmp;
      } else {

        tmp___1 = tmp___0;
      }
      if (tmp___1) {
        queue_insert(queue, node);
      }
    }
    return;
  }
}
static void queue_check_insert_parent(struct merge_node_queue *queue,
                                      struct merge_node *node) {

  {
    if (node->level > 1U) {
      lock_node(node->parent);
      queue_check_insert(queue, node->parent);
      unlock_node(node->parent);
    } else {
      if (node->nlo + node->nhi == 0UL) {
        queue_insert(queue, node->parent);
      }
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
        unlock_node(node);

        goto while_break;
      }
      mergelines_node(node, total_lines, tfp, temp_output);
      queue_check_insert(queue, node);
      queue_check_insert_parent(queue, node);
      unlock_node(node);
    }
  while_break:;
    return;
  }
}
static void sortlines(struct line *__restrict lines, size_t nthreads,
                      size_t total_lines, struct merge_node *node,
                      struct merge_node_queue *queue, FILE *tfp,
                      char const *temp_output);
static void *sortlines_thread(void *data) {
  struct thread_args const *args;

  {
    args = (struct thread_args const *)data;
    sortlines((struct line *)args->lines, (size_t)args->nthreads,
              (size_t)args->total_lines, (struct merge_node *)args->node,
              (struct merge_node_queue *)args->queue, (FILE *)args->tfp,
              (char const *)args->output_temp);
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
    nlines = node->nlo + node->nhi;
    lo_threads = nthreads / 2UL;
    hi_threads = nthreads - lo_threads;
    args.lines = (struct line *)lines;
    args.nthreads = lo_threads;
    args.total_lines = total_lines;
    args.node = node->lo_child;
    args.queue = queue;
    args.tfp = tfp;
    args.output_temp = temp_output;
    if (nthreads > 1UL) {
      if (131072UL <= nlines) {
        tmp = pthread_create(&thread, (pthread_attr_t const *)((void *)0),
                             &sortlines_thread, (void *)(&args));
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
    } else {
    _L___0:
      nlo = node->nlo;
      nhi = node->nhi;
      temp = (struct line *)(lines - total_lines);
      if (1UL < nhi) {
        sequential_sort(lines - nlo, nhi, temp - nlo / 2UL, (_Bool)0);
      }
      if (1UL < nlo) {
        sequential_sort(lines, nlo, temp, (_Bool)0);
      }
      node->lo = (struct line *)lines;
      node->hi = (struct line *)(lines - nlo);
      node->end_lo = (struct line *)(lines - nlo);
      node->end_hi = (struct line *)((lines - nlo) - nhi);
      queue_insert(queue, node);
      merge_loop(queue, total_lines, tfp, temp_output);
    }
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

  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  FILE *tftp;

  {
    got_outstat = (_Bool)0;

    i = ntemps;
    while (1) {

      if (!(i < nfiles)) {
        goto while_break;
      }
      tmp = strcmp((files + i)->name, "-");
      is_stdin = (_Bool)(tmp == 0);
      if (outfile) {
        tmp___7 = strcmp(outfile, (files + i)->name);

      } else {
      _L___0:
        if (!got_outstat) {
          if (outfile) {

          } else {
          }
          if (tmp___2 != 0) {
            goto while_break;
          }
        }
        if (is_stdin) {
          tmp___3 = fstat(0, &instat);

        } else {

          tmp___5 = tmp___4;
        }

        same = (_Bool)tmp___6;
      }
      if (same) {
        if (!tempcopy) {

          mergefiles(files + i, (size_t)0, (size_t)1, tftp,
                     (char const *)(tempcopy->name));
        }
        (files + i)->name = (char const *)(tempcopy->name);
      }
      i++;
    }
  while_break:;
  }
}
static void merge(struct sortfile *files, size_t ntemps, size_t nfiles,
                  char const *output_file) {
  size_t in;
  size_t out;
  size_t remainder;
  size_t cheap_slots;
  FILE *tfp;
  struct tempnode *temp;
  struct tempnode *tmp;
  size_t num_merged;
  size_t tmp___0;
  size_t tmp___1;
  size_t tmp___2;
  size_t nshortmerge;
  FILE *tfp___0;
  struct tempnode *temp___0;
  struct tempnode *tmp___3;
  size_t num_merged___0;
  size_t tmp___4;
  size_t tmp___5;
  size_t tmp___6;
  size_t tmp___7;
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

    in = (size_t)0;
    out = in;
    while (1) {

      if (!((size_t)nmerge <= nfiles - in)) {
        goto while_break___0;
      }
      tmp = create_temp(&tfp);
      temp = tmp;
      if (ntemps < (size_t)nmerge) {

      } else {
        tmp___0 = (size_t)nmerge;
      }
      tmp___1 = mergefiles(files + in, tmp___0, (size_t)nmerge, tfp,
                           (char const *)(temp->name));
      num_merged = tmp___1;
      if (ntemps < num_merged) {
        tmp___2 = ntemps;
      } else {
      }
      ntemps -= tmp___2;
      (files + out)->name = (char const *)(temp->name);
      (files + out)->temp = temp;
      in += num_merged;
      out++;
    }
  while_break___0:
    remainder = nfiles - in;
    cheap_slots = (unsigned long)nmerge - out % (unsigned long)nmerge;
    if (cheap_slots < remainder) {
      nshortmerge = (remainder - cheap_slots) + 1UL;
      tmp___3 = create_temp(&tfp___0);

      if (ntemps < nshortmerge) {

      } else {
      }
      tmp___5 = mergefiles(files + in, tmp___4, nshortmerge, tfp___0,
                           (char const *)(temp___0->name));
      num_merged___0 = tmp___5;
      if (ntemps < num_merged___0) {
        tmp___6 = ntemps;
      } else {
        tmp___6 = num_merged___0;
      }
      ntemps -= tmp___6;
      (files + out)->name = (char const *)(temp___0->name);
      tmp___7 = out;
      out++;
      (files + tmp___7)->temp = temp___0;
      in += num_merged___0;
    }
    memmove((void *)(files + out), (void const *)(files + in),
            (nfiles - in) * sizeof(*files));
    ntemps += out;
    nfiles -= in - out;

  while_break:
    avoid_trashing_input(files, ntemps, nfiles, output_file);

    tmp___8 = open_input_files(files, nfiles, &fps);
    nopened = tmp___8;
    if (nopened == nfiles) {
      tmp___9 = stream_open(output_file, "w");
      ofp = tmp___9;
      if (ofp) {
        mergefps(files, ntemps, nfiles, ofp, output_file, fps);
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

    nopened--;
    xfclose(*(fps + nopened), (files + nopened)->name);
    temp___1 = maybe_create_temp(&tfp___1, (_Bool)(!(nopened <= 2UL)));

  while_break___2:;

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
    output_file_created = (_Bool)0;
    buf___1.alloc = (size_t)0;

    if (!nfiles) {
      goto while_break;
    }
    file = (char const *)*files;
    tmp = xfopen(file, "r");
    fp = tmp;
    if (nthreads > 1UL) {
      tmp___0 = (size_t)1;
      mult = (size_t)1;
      while (1) {

        if (!(tmp___0 < nthreads)) {
          goto while_break___0;
        }
        tmp___0 *= 2UL;
      }
    while_break___0:
      bytes_per_line = mult * sizeof(struct line);
    } else {
      bytes_per_line = (sizeof(struct line) * 3UL) / 2UL;
    }
    if (!buf___1.alloc) {
      tmp___1 = sort_buffer_size((FILE *const *)(&fp), (size_t)1, files, nfiles,
                                 bytes_per_line);
      initbuf(&buf___1, bytes_per_line, tmp___1);
    }
    buf___1.eof = (_Bool)0;

    nfiles--;
    while (1) {
      tmp___4 = fillbuf___7(&buf___1, fp, file);

      if (buf___1.eof) {
        if (nfiles) {
          if (bytes_per_line + 1UL < (buf___1.alloc - buf___1.used) -
                                         bytes_per_line * buf___1.nlines) {
            buf___1.left = buf___1.used;
          }
        }
      }
      line = buffer_linelim((struct buffer const *)(&buf___1));
      if (buf___1.eof) {
        if (!nfiles) {
          if (!ntemps) {
            if (!buf___1.left) {
              xfclose(fp, file);
              tfp = xfopen(output_file, "w");
              temp_output = output_file;
              output_file_created = (_Bool)1;
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
      } else {
        ntemps++;
        tmp___2 = create_temp(&tfp);
        temp_output = (char const *)(tmp___2->name);
      }
      if (1UL < buf___1.nlines) {
        queue_init(&queue, nthreads);
        tmp___3 = merge_tree_init(nthreads, buf___1.nlines, line);
        merge_tree = tmp___3;
        root = merge_tree + 1;
        sortlines(line, nthreads, buf___1.nlines, root, &queue, tfp,
                  temp_output);
        queue_destroy(&queue);
        pthread_mutex_destroy(&root->lock);
        merge_tree_destroy(merge_tree);
      } else {
        write_unique((struct line const *)(line - 1), tfp, temp_output);
      }
      xfclose(tfp, temp_output);
      if (output_file_created) {
        goto finish;
      }
    }

    xfclose(fp, file);

  while_break:;
  finish:

    if (!output_file_created) {
      node = (struct tempnode *)temphead;
      tmp___5 = (struct sortfile *)xnmalloc(ntemps, sizeof(*tempfiles));
      tempfiles = tmp___5;
      i = (size_t)0;

      if (!node) {
      }
      (tempfiles + i)->name = (char const *)(node->name);
      (tempfiles + i)->temp = node;
      node = (struct tempnode *)node->next;

    while_break___2:
      merge(tempfiles, ntemps, ntemps, output_file);
      free((void *)tempfiles);
    }
    reap_all();
    return;
  }
}
static void insertkey(struct keyfield *key_arg) {
  struct keyfield **p;
  struct keyfield *key;
  struct keyfield *tmp;

  {

    key = tmp;
    p = &keylist;

    if (!*p) {
      goto while_break;
    }
    goto __Cont;
  __Cont:
    p = &(*p)->next;

  while_break:
    *p = key;
  }
}

static void badfieldspec(char const *spec, char const *msgid) {

  char *tmp___0;

  {}
}

static __attribute__((__noreturn__)) void
incompatible_options(char const *opts___1);
static void incompatible_options(char const *opts___1) {

  {}
}
static void check_ordering_compatibility(void) {
  struct keyfield *key;

  _Bool tmp___0;

  {
    key = keylist;

    if (!key) {
      goto while_break;
    }

    key = key->next;

  while_break:;
  }
}
static char const *parse_field_count(char const *string, size_t *val,
                                     char const *msgid) {
  char *suffix;
  uintmax_t n;
  strtol_error tmp;

  {
    tmp = xstrtoumax(string, &suffix, 10, &n, "");
    if ((unsigned int)tmp == 0U) {
    }
    if ((unsigned int)tmp == 2U) {
      goto case_0;
    }
    if ((unsigned int)tmp == 1U) {
      goto case_1;
    }

    goto switch_break;
  case_0:

  case_1:

  switch_break:;
  }
}
static char *set_ordering(char const *s, struct keyfield *key,
                          enum blanktype blanktype) {

  {

    if (!*s) {
      goto while_break;
    }
    if ((int const) * s == 98) {
      goto case_98;
    }
    if ((int const) * s == 100) {
    }
    if ((int const) * s == 102) {
      goto case_102;
    }

    if ((int const) * s == 104) {
    }

    if ((int const) * s == 77) {
    }
    if ((int const) * s == 110) {
      goto case_110;
    }

    if ((int const) * s == 114) {
      goto case_114;
    }
    if ((int const) * s == 86) {
      goto case_86;
    }

  case_98:

  case_100:
    key->ignore = (_Bool const *)(nondictionary);

  case_102:
    key->translate = (char const *)(fold_toupper);
    goto switch_break;
  case_103:

  case_104:

    goto switch_break;

    if (!key->ignore) {
    }
    goto switch_break;
  case_77:
    key->month = (_Bool)1;

  case_110:
    key->numeric = (_Bool)1;

    key->random = (_Bool)1;
    goto switch_break;
  case_114:
    key->reverse = (_Bool)1;

  case_86:

    return ((char *)s);
  switch_break:

  while_break:;
  }
}
static struct keyfield *key_init(struct keyfield *key) {

  {}
}

int main(int argc, char **argv);
static int const sig[11] = {(int const)14, (int const)1,  (int const)2,
                            (int const)13, (int const)3,  (int const)15,
                            (int const)29, (int const)27, (int const)26,
                            (int const)24, (int const)25};

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
  _Bool posixly_correct;

  _Bool obsolete_usage;

  char **files;
  char *files_from;
  struct Tokens tok;
  char const *outfile;
  struct lconv const *locale;
  struct lconv const *tmp___1;
  size_t i;
  struct sigaction act;
  int tmp___2;
  int oi;

  _Bool minus_pos_usage;
  int tmp___5;
  int tmp___6;

  size_t tmp___10;
  ptrdiff_t tmp___11;
  char str[2];

  size_t tmp___15;

  size_t tmp___17;

  char const *p;
  FILE *stream;

  char const *tmp___30;
  char *tmp___31;
  int *tmp___32;
  int tmp___33;
  char const *tmp___34;
  char *tmp___35;
  _Bool tmp___36;
  int tmp___37;
  size_t i___0;

  unsigned long file_number;

  int tmp___42;
  char const *tmp___43;
  char *tmp___44;
  _Bool tmp___45;
  _Bool tmp___46;

  char const *tmp_dir;
  char const *tmp___51;
  char const *tmp___52;

  struct sortfile *sortfiles;
  struct sortfile *tmp___58;
  size_t i___1;
  unsigned long np;
  unsigned long tmp___59;
  size_t nthreads_max;

  int tmp___61;

  {

    mergeonly = (_Bool)0;

    nthreads = (size_t)0;
    nfiles = (size_t)0;

    files_from = (char *)((void *)0);
    outfile = (char const *)((void *)0);

    locale = tmp___1;

    inittables();

    if (!(i < 11UL)) {
      goto while_break;
    }

  while_break:

    act.sa_mask = caught_signals;

    if (!(i < 11UL)) {
      goto while_break___0;
    }
    tmp___2 = sigismember((sigset_t const *)(&caught_signals), (int)sig[i]);

  while_break___0:

    key_init(&gkey);

    files = (char **)xnmalloc((size_t)argc, sizeof(*files));

    oi = -1;
    if (c == -1) {
      goto _L;
    } else {
      if (posixly_correct) {

      } else {
      _L___1:
        c = getopt_long(argc, (char *const *)argv, short_options,
                        long_options___1, &oi);
        if (c == -1) {
        _L:
          if (argc <= optind) {
          }

          nfiles++;

        } else {

          if (c == 102) {
            goto case_98;
          }

          if (c == 104) {
            goto case_98;
          }
          if (c == 105) {
            goto case_98;
          }
          if (c == 77) {
          }
          if (c == 110) {
          }
          if (c == 114) {
          }
          if (c == 82) {
            goto case_98;
          }

          if (c == 99) {
            goto case_99;
          }

          if (c == 129) {
          }
          if (c == 130) {
            goto case_130;
          }

          if (c == 107) {
            goto case_107;
          }

          if (c == 83) {
          }
          if (c == 116) {
          }
          if (c == 84) {
          }
          if (c == 135) {
          }

          if (c == 122) {
          }

        case_1:
          key = (struct keyfield *)((void *)0);
          if ((int)*(optarg + 0) == 43) {

            minus_pos_usage = (_Bool)tmp___5;

            obsolete_usage = (_Bool)((int)obsolete_usage | tmp___6);
          }
          if (!key) {

            nfiles++;
            *(files + tmp___10) = optarg;
          }
          goto switch_break;

          tmp___11 = __xargmatch_internal("--sort", (char const *)optarg,
                                          sort_args, sort_types,
                                          sizeof(sort_types[0]), argmatch_die);
          c = (int)sort_types[tmp___11];
        case_98:
          str[0] = (char)c;

          set_ordering((char const *)(str), &gkey, (enum blanktype)2);

        case_99:

        case_129:

        case_130:

          files_from = optarg;

        case_107:
          key = key_init(&key_buf);
          s = parse_field_count((char const *)optarg, &key->sword,
                                "invalid number at field start");
          tmp___15 = key->sword;
          (key->sword)--;
          if (!tmp___15) {
          }
          if ((int const) * s == 46) {
            s = parse_field_count(s + 1, &key->schar,
                                  "invalid number after \'.\'");

            (key->schar)--;
          }
          if (!key->sword) {
            if (!key->schar) {
            }
          }
          s = (char const *)set_ordering(s, key, (enum blanktype)0);
          if ((int const) * s != 44) {
            key->eword = 0xffffffffffffffffUL;
            key->echar = (size_t)0;
          } else {
            s = parse_field_count(s + 1, &key->eword,
                                  "invalid number after \',\'");
            tmp___17 = key->eword;
            (key->eword)--;
            if (!tmp___17) {
            }

            s = (char const *)set_ordering(s, key, (enum blanktype)1);
          }

          mergeonly = (_Bool)1;

          goto switch_break;

          outfile = (char const *)optarg;

          goto switch_break;
        case_83:

        case_116:

          goto switch_break;
        case_84:

        case_135:

        case_121:
          if ((unsigned long)optarg == (unsigned long)*(argv + (optind - 1))) {

          while_break___2:
            optind -= (int const) * p != 0;
          }

        case_122:

          exit(0);

        switch_break:;
        }
      }
    }

  while_break___1:;
    if (files_from) {

      tmp___33 = strcmp((char const *)files_from, "-");
      if (tmp___33 == 0) {

      } else {
        stream = fopen_safer((char const *)files_from, "r");
        if ((unsigned long)stream == (unsigned long)((void *)0)) {

          tmp___31 = gettext("cannot open %s for reading");

          error(2, *tmp___32, (char const *)tmp___31, tmp___30);
        }
      }
      readtokens0_init(&tok);
      tmp___36 = readtokens0(stream, &tok);
      if (tmp___36) {
        tmp___37 = rpl_fclose(stream);
        if (tmp___37 != 0) {
        }
      } else {

        error(2, 0, (char const *)tmp___35, tmp___34);
      }
      if (tok.n_tok) {
        free((void *)files);
        files = tok.tok;
        nfiles = tok.n_tok;

        if (!(i___0 < nfiles)) {
          goto while_break___3;
        }
        tmp___42 = strcmp((char const *)*(files + i___0), "-");
        if (tmp___42 == 0) {

        } else {
        }
        i___0++;

      while_break___3:;
      } else {
        tmp___43 = quote((char const *)files_from);
        tmp___44 = gettext("no input from %s");
        error(2, 0, (char const *)tmp___44, tmp___43);
      }
    }
    key = keylist;

    if (!key) {
      goto while_break___4;
    }
    tmp___45 = default_key_compare((struct keyfield const *)key);
    if (tmp___45) {
    }

    key = key->next;

  while_break___4:;
    if (!keylist) {
      tmp___46 = default_key_compare((struct keyfield const *)(&gkey));
      if (!tmp___46) {
      }
    }
    check_ordering_compatibility();

    reverse = gkey.reverse;
    if (need_random) {
    }
    if (temp_dir_count == 0UL) {

      tmp_dir = tmp___51;

      add_temp_dir(tmp___52);
    }

    if (0UL < sort_size) {
    }

    if (mergeonly) {
      tmp___58 = (struct sortfile *)xcalloc(nfiles, sizeof(*sortfiles));
      sortfiles = tmp___58;
      i___1 = (size_t)0;

      if (!(i___1 < nfiles)) {
      }
      (sortfiles + i___1)->name = (char const *)*(files + i___1);
      i___1++;

    while_break___5:
      merge(sortfiles, (size_t)0, nfiles, outfile);
    } else {
      if (!nthreads) {
        tmp___59 = num_processors((enum nproc_query)2);
        np = tmp___59;
        if (np < 8UL) {
          nthreads = np;
        } else {
          nthreads = (size_t)8;
        }
      }
      nthreads_max = 0xffffffffffffffffUL / (2UL * sizeof(struct merge_node));
      if (nthreads < nthreads_max) {

      } else {
        nthreads = nthreads_max;
      }
      sort((char *const *)files, nfiles, outfile, nthreads);
    }
    if (have_read_stdin) {
      tmp___61 = rpl_fclose(stdin);
    }
    exit(0);
  }
}
