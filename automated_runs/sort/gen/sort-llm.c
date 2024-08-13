typedef long __time_t;

typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;
};
typedef unsigned long size_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;

typedef unsigned int __mode_t;

typedef long __off_t;
typedef long __blksize_t;

struct stat {

  __mode_t st_mode;
  __uid_t st_uid;
  __gid_t st_gid;

  __dev_t st_rdev;
  __off_t st_size;
  __blksize_t st_blksize;

  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
};

struct hash_tuning {};
typedef struct hash_tuning Hash_tuning;
struct hash_table;

typedef struct hash_table Hash_table;
typedef unsigned long uintmax_t;
typedef long __off64_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef __off_t off_t;

typedef long ptrdiff_t;

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

  int val;
};
typedef unsigned int uint32_t;

typedef int wchar_t;

typedef unsigned int wint_t;

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
  unsigned int use_extra_arg : 1;
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
};

struct isaac {
  size_t buffered;
  struct isaac_state state;
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

  mbstate_t state;

  struct mbchar cur;
};
typedef struct mbuiter_multi mbui_iterator_t;

struct md5_ctx {
  uint32_t A;
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

  __pthread_list_t __list;
};
union __anonunion_pthread_mutex_t_11 {
  struct __pthread_mutex_s __data;
};
typedef union __anonunion_pthread_mutex_t_11 pthread_mutex_t;

typedef union __anonunion_pthread_mutexattr_t_12 pthread_mutexattr_t;

struct heap {
  void **array;
  size_t capacity;
  size_t count;
  int (*compare)(void const *, void const *);
};
struct hash_entry {
  void *data;
};
struct hash_table {
  struct hash_entry *bucket;

  size_t n_buckets;

  Hash_tuning const *tuning;
  size_t (*hasher)(void const *, size_t);
  _Bool (*comparator)(void const *, void const *);
};

union __anonunion___sigaction_handler_41 {
  void (*sa_handler)(int);
};
struct sigaction {
  union __anonunion___sigaction_handler_41 __sigaction_handler;
  __sigset_t sa_mask;
  int sa_flags;
  void (*sa_restorer)(void);
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

struct __anonstruct___data_7 {
  int __lock;

  unsigned long long __total_seq;
  unsigned long long __wakeup_seq;
  unsigned long long __woken_seq;
  void *__mutex;
  unsigned int __nwaiters;
};
union __anonunion_pthread_cond_t_6 {
  struct __anonstruct___data_7 __data;
};
typedef union __anonunion_pthread_cond_t_6 pthread_cond_t;

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

struct rlimit {};
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
struct month {};
struct merge_node {
  struct line *lo;
  struct line *hi;
  struct line *end_lo;
  struct line *end_hi;
  struct line **dest;
  size_t nlo;
  size_t nhi;
  struct merge_node *parent;

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

  char state;
  char name[1];
};
struct sortfile {
  char const *name;
  struct tempnode *temp;
};

struct thread_args {
  struct line *lines;

  struct merge_node *node;
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

int hash_insert_if_absent(Hash_table *table___0, void const *entry,
                          void const **matched_ent);

int fd_safer(int fd);

extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

int volatile exit_failure;

static _Bool ignore_EPIPE;
void close_stdout(void) {

  int tmp___3;

  int tmp___5;

  {

    if (tmp___3 != 0) {
      if (ignore_EPIPE) {

      } else {

        _exit((int)exit_failure);
      }
    }
    tmp___5 = close_stream(stderr);
  }
}

int rpl_fflush(FILE *stream);

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);

int close_stream(FILE *stream) {
  _Bool some_pending;

  _Bool prev_fail;

  _Bool fclose_fail;
  int tmp___1;

  {

    tmp___1 = rpl_fclose(stream);

    if (prev_fail) {

    } else {
      if (fclose_fail) {
        if (some_pending) {

        } else {
        }
      }
    }
  }
}

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));

int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));

_Bool c_isdigit(int c) __attribute__((__const__));

_Bool c_isalpha(int c) __attribute__((__const__));
_Bool c_isalpha(int c) {
  int tmp;

  { return ((_Bool)tmp); }
}

_Bool c_isdigit(int c) {
  int tmp;

  {
    if (c >= 48) {
      if (c <= 57) {

      } else {
      }
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
          }
        }
      }
    }
    return ((_Bool)tmp);
  }
}

int c_tolower(int c) {
  int tmp;

  { return (tmp); }
}
char *last_component(char const *name) __attribute__((__pure__));
char *last_component(char const *name) {
  char const *base;
  char const *p;

  {

    p = base;

    ;
    return ((char *)base);
  }
}

ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize) {
  size_t i;
  size_t arglen;
  ptrdiff_t matchind;
  _Bool ambiguous;

  {
    matchind = (ptrdiff_t)-1;

    arglen = strlen(arg);
    i = (size_t)0;

    ;
    if (ambiguous) {

    } else {
    }
  }
}

ptrdiff_t __xargmatch_internal(char const *context, char const *arg,
                               char const *const *arglist, char const *vallist,
                               size_t valsize, void (*exit_fn)(void)) {
  ptrdiff_t res;

  {}
}

__inline static void *xnmalloc(size_t n, size_t s) {

  void *tmp___0;

  {

    tmp___0 = xmalloc(n * s);
    return (tmp___0);
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

  int *tmp___4;
  int base;
  int suffixes;
  strtol_error overflow;

  {
    err = (strtol_error)0;
    if (0 <= strtol_base) {

    } else {
    }

    q = s;
    ch = (unsigned char)*q;

    if (!((int const) * (*tmp___0 + (int)ch) & 8192)) {
      goto while_break;
    }

  while_break:;

    tmp___1 = __errno_location();

    tmp = strtoumax(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {
        if (*(*p)) {

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

      return (err);
    }
    if ((int)*(*p) != 0) {

      if ((int)*(*p) == 116) {
      }

      goto switch_break___0;

      goto switch_break___0;

      goto switch_break___0;

      goto switch_break___0;
    case_71:
      overflow = bkm_scale_by_power(&tmp, base, 3);

    case_107:

      goto switch_break___0;

      goto switch_break___0;
    case_84:

      goto switch_break___0;

      goto switch_break___0;

    case_90:
      overflow = bkm_scale_by_power(&tmp, base, 7);
      goto switch_break___0;
    switch_default:
      *val = tmp;

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

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;

  int base;

  strtol_error overflow;

  {
    err = (strtol_error)0;
    if (0 <= strtol_base) {
      if (!(strtol_base <= 36)) {
      }
    } else {
    }
    if (ptr) {

    } else {
      p = &t_ptr;
    }
    q = s;
    ch = (unsigned char)*q;

    ;

    tmp = strtoul(s, p, strtol_base);

    if ((int)*(*p) != 0) {

      if ((int)*(*p) == 84) {
      }
      if ((int)*(*p) == 116) {
      }

      goto switch_break___0;

      goto switch_break___0;

      goto switch_break___0;
    case_71:

      overflow = bkm_scale_by_power___0(&tmp, base, 1);

      goto switch_break___0;

    case_84:

      goto switch_break___0;

      goto switch_break___0;
    case_89:

    case_90:

    switch_default:
      *val = tmp;

    switch_break___0:
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
    }
    *val = tmp;
    return (err);
  }
}

__attribute__((__noreturn__)) void
xstrtol_fatal(enum strtol_error err, int opt_idx, char c,
              struct option const *long_options___2, char const *arg);

__attribute__((__noreturn__)) void
xstrtol_fatal(enum strtol_error err, int opt_idx, char c,
              struct option const *long_options___2, char const *arg);

int xmemcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size);

int xmemcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {
  int diff;
  int tmp;
  int collation_errno;

  {
    tmp = memcoll0(s1, s1size, s2, s2size);

    if (collation_errno) {
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
    }

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

void *xrealloc(void *p, size_t n) {

  {

    p = realloc(p, n);
    if (!p) {
    }
    return (p);
  }
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

void *xmemdup(void const *p, size_t s) {
  void *tmp;
  void *tmp___0;

  {
    tmp = xmalloc(s);

    return (tmp___0);
  }
}

void xalloc_die(void) {
  char *tmp;

  { error((int)exit_failure, 0, "%s", tmp); }
}
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2)
    __attribute__((__pure__));

#pragma GCC diagnostic ignored "-Wtype-limits"
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1) {
  char *p;

  {

    *p = (char)0;
    if (i < 0UL) {

      p--;
      *p = (char)(48UL - i % 10UL);

      if (!(i != 0UL)) {
        goto while_break;
      }

    while_break:
      p--;

    } else {

      p--;
      *p = (char)(48UL + i % 10UL);

      if (!(i != 0UL)) {
      }

    while_break___0:;
    }
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
      *p = (char)(48U - i % 10U);
      i /= 10U;
      if (!(i != 0U)) {
      }

    while_break:
      p--;

    } else {

      p--;
      *p = (char)(48U + i % 10U);
      i /= 10U;
      if (!(i != 0U)) {
      }

    while_break___0:;
    }
    return (p);
  }
}

extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrtowc)(
    wchar_t *__restrict __pwc, char const *__restrict __s, size_t __n,
    mbstate_t *__restrict __p);
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

          if (!((int const) * a == (int const) * b)) {
            goto while_break;
          }
          if (!((unsigned int)*a - 48U <= 9U)) {
            return ((int __attribute__((__pure__)))0);
          }
        }
      while_break:;

        if ((unsigned int)*a - 48U <= 9U) {
          goto a_trailing_nonzero;
        }

      } else {
      }
    } else {
    _L:
      tmp___0 = a;
      a++;
      if ((int const) * tmp___0 == (int const)decimal_point___0) {
      a_trailing_nonzero:

        if (!((int const) * a == 48)) {
          goto while_break___0;
        }
        a++;

      while_break___0:;
        return ((int __attribute__((__pure__)))((unsigned int)*a - 48U <= 9U));
      } else {

        b++;
        if ((int const) * tmp == (int const)decimal_point___0) {

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
      while (1) {
        a++;

        if (!((int)tmpa == 48)) {
          if (!((int)tmpa == thousands_sep___0)) {
            goto while_break;
          }
        }
      }
    while_break:;
      if ((int)tmpb != 45) {

        if ((unsigned int)tmpa - 48U <= 9U) {
        }

        if (!((int)tmpb == 48)) {
        }
        b++;
        tmpb = (unsigned char)*b;

        ;
        if ((int)tmpb == decimal_point___0) {

          b++;
          tmpb = (unsigned char)*b;

          ;
        }
        return (
            (int __attribute__((__pure__)))(-((unsigned int)tmpb - 48U <= 9U)));
      }

      b++;
      tmpb = (unsigned char)*b;
      if (!((int)tmpb == 48)) {
        if (!((int)tmpb == thousands_sep___0)) {
          goto while_break___3;
        }
      }

    while_break___3:;

      if ((int)tmpa == (int)tmpb) {
        if (!((unsigned int)tmpa - 48U <= 9U)) {
          goto while_break___4;
        }
      } else {
        goto while_break___4;
      }

      a++;
      tmpa = (unsigned char)*a;
      if (!((int)tmpa == thousands_sep___0)) {
        goto while_break___5;
      }

    while_break___5:;

      tmpb = (unsigned char)*b;
      if (!((int)tmpb == thousands_sep___0)) {
        goto while_break___6;
      }

    while_break___6:;

    while_break___4:;
      if ((int)tmpa == decimal_point___0) {
        if (!((unsigned int)tmpb - 48U <= 9U)) {
          tmp___0 = fraccompare(b, a, (char)decimal_point___0);

        } else {
        }
      } else {
      _L:
        if ((int)tmpb == decimal_point___0) {
          if (!((unsigned int)tmpa - 48U <= 9U)) {
            tmp___0 = fraccompare(b, a, (char)decimal_point___0);
          }
        }
      }
      tmp = (int)tmpb - (int)tmpa;
      log_a = (size_t)0;

      if (!((unsigned int)tmpa - 48U <= 9U)) {
        goto while_break___7;
      }

      tmpa = (unsigned char)*a;
      if (!((int)tmpa == thousands_sep___0)) {
      }

    while_break___8:
      log_a++;

    while_break___7:

      while (1) {

        if (!((unsigned int)tmpb - 48U <= 9U)) {
          goto while_break___9;
        }

        b++;
        tmpb = (unsigned char)*b;

        log_b++;
      }
    while_break___9:;
      if (log_a != log_b) {
        if (log_a < log_b) {

        } else {
        }
        return ((int __attribute__((__pure__)))tmp___1);
      }

      return ((int __attribute__((__pure__)))tmp);
    } else {
      if ((int)tmpb == 45) {

        b++;

        if (!((int)tmpb == 48)) {
          if (!((int)tmpb == thousands_sep___0)) {
          }
        }

      while_break___11:;

        if ((unsigned int)tmpb - 48U <= 9U) {
          return ((int __attribute__((__pure__)))1);
        }
        while (1) {

          if (!((int)tmpa == 48)) {
          }
          a++;
          tmpa = (unsigned char)*a;
        }

        ;
        if ((int)tmpa == decimal_point___0) {

          a++;
          tmpa = (unsigned char)*a;
          if (!((int)tmpa == 48)) {
            goto while_break___14;
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

        tmpb = (unsigned char)*b;

      while_break___16:;

        if ((int)tmpa == (int)tmpb) {
          if (!((unsigned int)tmpa - 48U <= 9U)) {
            goto while_break___17;
          }
        } else {
          goto while_break___17;
        }

        a++;
        tmpa = (unsigned char)*a;
        if (!((int)tmpa == thousands_sep___0)) {
          goto while_break___18;
        }

      while_break___18:;

        b++;
        tmpb = (unsigned char)*b;
        if (!((int)tmpb == thousands_sep___0)) {
        }

      while_break___19:;

      while_break___17:;
        if ((int)tmpa == decimal_point___0) {
          if (!((unsigned int)tmpb - 48U <= 9U)) {
            tmp___2 = fraccompare(a, b, (char)decimal_point___0);
            return (tmp___2);
          } else {
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
        }

        tmpa = (unsigned char)*a;
        if (!((int)tmpa == thousands_sep___0)) {
        }

      while_break___21:
        log_a++;

      while_break___20:
        log_b = (size_t)0;
        while (1) {

          if (!((unsigned int)tmpb - 48U <= 9U)) {
          }
          while (1) {
            b++;
            tmpb = (unsigned char)*b;
            if (!((int)tmpb == thousands_sep___0)) {
              goto while_break___23;
            }
          }
        while_break___23:
          log_b++;
        }
      while_break___22:;
        if (log_a != log_b) {
          if (log_a < log_b) {

          } else {
            tmp___3 = 1;
          }
          return ((int __attribute__((__pure__)))tmp___3);
        }
        if (!log_a) {
        }
      }
    }
  }
}
int __attribute__((__pure__)) strnumcmp(char const *a, char const *b,
                                        int decimal_point___0,
                                        int thousands_sep___0) {
  int __attribute__((__pure__)) tmp;

  { tmp = numcompare(a, b, decimal_point___0, thousands_sep___0); }
}

extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
                             FILE *__restrict __stream);

extern void _obstack_newchunk(struct obstack *, int);

void readtokens0_init(struct Tokens *t);
_Bool readtokens0(FILE *in, struct Tokens *t);
void readtokens0_init(struct Tokens *t) {

  {

    t->tok = (char **)((void *)0);

    _obstack_begin(&t->o_data, 0, 0, (void *(*)(long))(&malloc),
                   (void (*)(void *))(&free));
  }
}
static void save_token(struct Tokens *t) {
  size_t len;
  struct obstack const *__o;

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

    __value = (void *)__o1->object_base;

    __o1->next_free =
        tmp + (((__o1->next_free - tmp___0) + (long)__o1->alignment_mask) &
               (long)(~__o1->alignment_mask));

    __o1->object_base = __o1->next_free;

    if ((unsigned long)(__o___0->next_free + sizeof(void *)) >
        (unsigned long)__o___0->chunk_limit) {
    }

    __o1___0->next_free += sizeof(void const *);

    if ((unsigned long)(__o___1->next_free + __len) >
        (unsigned long)__o___1->chunk_limit) {
      _obstack_newchunk(__o___1, __len);
    }
    memcpy((void *)__o___1->next_free, (void const *)(&len), (size_t)__len);
    __o___1->next_free += __len;
    (t->n_tok)++;
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

  struct obstack *__o1___0;
  void *__value;
  char *tmp___2;
  char *tmp___3;
  struct obstack *__o1___1;

  char *tmp___4;
  char *tmp___5;

  int tmp___7;

  {
    while (1) {
      tmp = fgetc(in);
      c = tmp;
      if (c == -1) {

        len = (size_t)((unsigned int)(__o->next_free - __o->object_base));
        if (len) {

          if ((unsigned long)(__o___0->next_free + 1) >
              (unsigned long)__o___0->chunk_limit) {
          }
          tmp___0 = __o___0->next_free;
          (__o___0->next_free)++;

          save_token(t);
        }
        goto while_break;
      }

      if ((unsigned long)(__o___1->next_free + 1) >
          (unsigned long)__o___1->chunk_limit) {
      }
      tmp___1 = __o___1->next_free;
      (__o___1->next_free)++;

      if (c == 0) {
        save_token(t);
      }
    }
  while_break:

    if ((unsigned long)(__o___2->next_free + sizeof(void *)) >
        (unsigned long)__o___2->chunk_limit) {
      _obstack_newchunk(__o___2, (int)sizeof(void *));
    }

    __value = (void *)__o1___0->object_base;

    __o1___0->next_free =
        tmp___2 +
        (((__o1___0->next_free - tmp___3) + (long)__o1___0->alignment_mask) &
         (long)(~__o1___0->alignment_mask));

    __o1___0->object_base = __o1___0->next_free;
    t->tok = (char **)__value;

    __o1___1->next_free =
        tmp___4 +
        (((__o1___1->next_free - tmp___5) + (long)__o1___1->alignment_mask) &
         (long)(~__o1___1->alignment_mask));

    __o1___1->next_free = __o1___1->chunk_limit;

    __o1___1->object_base = __o1___1->next_free;

    return ((_Bool)tmp___7);
  }
}

void isaac_seed(struct isaac_state *s);

FILE *fopen_safer(char const *file, char const *mode);

static struct randread_source *simple_new(FILE *source,
                                          void const *handler_arg) {
  struct randread_source *s;

  {

    s->source = source;
  }
}
static void get_nonce(void *buffer, size_t bufsize___1, size_t bytes_bound) {

  { return; }
}
struct randread_source *randread_new(char const *name, size_t bytes_bound) {
  struct randread_source *tmp;
  FILE *source;
  struct randread_source *s;
  unsigned long tmp___0;

  {
    if (bytes_bound == 0UL) {

      return (tmp);
    } else {

      if (name) {
        source = fopen_safer(name, "rb");
        if (!source) {
        }
      }
      s = simple_new(source, (void const *)name);
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
  size_t tmp;

  {

    inbytes = tmp;

    size -= inbytes;

    (*(s->handler))(s->handler_arg);

  while_break:;
    return;
  }
}

void randread(struct randread_source *s, void *buf___1, size_t size) {

  {
    if (s->source) {

    } else {
    }
    return;
  }
}
int randread_free(struct randread_source *s) {
  FILE *source;

  int tmp___0;

  { return (tmp___0); }
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

  isaac_word tmp___9;

  int i___0;

  isaac_word tmp___13;

  isaac_word tmp___16;

  {

    a = tmp;

    b = tmp___0;

    c = tmp___1;

    d = tmp___2;

    e = tmp___3;

    f = tmp___4;

    g = tmp___5;

    h = tmp___6;
    i = 0;

    if (!(i < 1 << 8)) {
      goto while_break;
    }
    a += s->m[i];
    b += s->m[i + 1];

    g ^= a << 9;

    c -= g;

    b += c;

    a ^= c << 15;
    c += d;
    e -= a;

    b ^= tmp___9 >> 14;
    d += e;

    c ^= e << 20;

    g -= c;

    s->m[i] = a;
    s->m[i + 1] = b;

    s->m[i + 3] = d;
    s->m[i + 4] = e;
    s->m[i + 5] = f;

    i += 8;

  while_break:

    while (1) {

      f += s->m[i___0 + 5];

      h += s->m[i___0 + 7];

      b -= f;
      g ^= a << 9;

      c -= g;

      b += c;

      a ^= c << 15;
      c += d;
      e -= a;

      b ^= tmp___13 >> 14;
      d += e;

      c ^= e << 20;
      e += f;
      g -= c;

      e ^= g << 14;

      s->m[i___0] = a;

      s->m[i___0 + 5] = f;
    }

    tmp___16 = (isaac_word)0;
  }
}

static size_t
quotearg_buffer_restyled(char *buffer, size_t buffersize, char const *arg,
                         size_t argsize, enum quoting_style quoting_style,
                         int flags, unsigned int const *quote_these_too,
                         char const *left_quote, char const *right_quote) {
  size_t i;
  size_t len;

  _Bool backslash_escapes;
  _Bool unibyte_locale;

  _Bool elide_outer_quotes;
  unsigned char c;
  unsigned char esc;
  _Bool is_right_quote;

  size_t m;
  _Bool printable;

  size_t ilim;
  int tmp___6;
  size_t tmp___7;

  {
    len = (size_t)0;

    if ((unsigned int)quoting_style == 0U) {
    }

    if (!elide_outer_quotes) {

      ;
    }

    if (!elide_outer_quotes) {

      ;
    }

  case_0:

    i = (size_t)0;
    while (1) {

      if (tmp___6) {
      }

      c = (unsigned char)*(arg + i);

      if ((int)c == 10) {
      }

      if ((int)c == 9) {
      }

      if ((int)c == 91) {
        goto case_32;
      }

      if ((int)c == 37) {
        goto case_37;
      }

      if ((int)c == 45) {
        goto case_37;
      }

      if ((int)c == 57) {
        goto case_37;
      }

      if ((int)c == 66) {
        goto case_37;
      }

      if ((int)c == 75) {
        goto case_37;
      }
      if ((int)c == 76) {
        goto case_37;
      }

      if ((int)c == 78) {
      }
      if ((int)c == 79) {
      }

      if ((int)c == 81) {
        goto case_37;
      }
      if ((int)c == 82) {
        goto case_37;
      }

      if ((int)c == 86) {
      }

      if ((int)c == 100) {
      }
      if ((int)c == 101) {
      }

      if ((int)c == 103) {
        goto case_37;
      }

      if (backslash_escapes) {

      while_break___4:;

      } else {
      }

      if (flags & 4) {
        if (i + 2UL < argsize) {
          if ((int const) * (arg + (i + 1UL)) == 63) {

            if ((int const) * (arg + (i + 2UL)) == 39) {
            }
            if ((int const) * (arg + (i + 2UL)) == 40) {
            }

            if ((int const) * (arg + (i + 2UL)) == 60) {
            }

          case_33:

          while_break___7:;

            ;

            if (len < buffersize) {
            }
            len++;
            goto while_break___9;

          while_break___9:;

            ;

            ;
          }
        }
      }

      ;

    case_7___0:

    case_10:

      goto c_and_shell_escape;
    case_13:
      esc = (unsigned char)'r';

    case_9:

      goto c_escape;

      esc = c;

    c_and_shell_escape:

    c_escape:

    case_32:

    case_37:

      if (unibyte_locale) {

      } else {

        ;
      }
      if (1UL < m) {
        goto _L___0;
      } else {
        if (backslash_escapes) {
          if (!printable) {
          _L___0:

            if (backslash_escapes) {
              if (!printable) {

                if (len < buffersize) {
                  *(buffer + len) = (char)'\\';
                }

                ;

                ;

                c = (unsigned char)(48 + ((int)c & 7));
              } else {
              }
            } else {
            _L:
              if (is_right_quote) {

                if (len < buffersize) {
                  *(buffer + len) = (char)'\\';
                }

                is_right_quote = (_Bool)0;
              }
            }
            if (ilim <= i + 1UL) {
            }

            if (len < buffersize) {
              *(buffer + len) = (char)c;
            }
            len++;

            c = (unsigned char)*(arg + i);

          while_break___17:;
          }
        }
      }

      ;
      if (backslash_escapes) {

      } else {
        if (elide_outer_quotes) {

          if (quote_these_too) {

          } else {
          }
        } else {
        _L___2:
          if (!is_right_quote) {
          }
        }
      }

      if (len < buffersize) {
        *(buffer + len) = (char)'\\';
      }
      len++;

      ;
    store_c:

      if (len < buffersize) {
        *(buffer + len) = (char)c;
      }
      len++;

      ;

      i++;
    }
  while_break___3:;

    if (len < buffersize) {
      *(buffer + len) = (char)'\000';
    }
    return (len);

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

  unsigned int n0;
  struct slotvec *sv;
  size_t n1;

  int tmp___0;
  struct slotvec *tmp___1;
  size_t size;
  char *val;
  int flags;
  size_t qsize;
  size_t tmp___2;
  int *tmp___3;

  {

    sv = slotvec;

    if (nslots <= n0) {

      if ((size_t)tmp___0 / sizeof(*sv) < n1) {
        xalloc_die();
      }

      sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
      slotvec = sv;

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

      (sv + n)->size = size;

      val = xcharalloc(size);
    }
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;

  {
  }
}
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg,
                           size_t argsize) {
  struct quoting_options o;

  {
  }
}

char *quotearg_colon(char const *arg) {

  {}
}

char const *quote_n(int n, char const *name) {
  char const *tmp;

  { return (tmp); }
}
char const *quote(char const *name) {
  char const *tmp;

  { return (tmp); }
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
__inline static void mbuiter_multi_next(struct mbuiter_multi *iter) {

  size_t tmp___0;
  size_t tmp___1;

  _Bool tmp___3;

  {

    tmp___3 = is_basic((char)*(iter->cur.ptr));
    if (tmp___3) {

      iter->cur.wc_valid = (_Bool)1;
    } else {

      tmp___0 = __ctype_get_mb_cur_max();

      iter->cur.bytes =
          mbrtowc(&iter->cur.wc, iter->cur.ptr, tmp___1, &iter->state);
    }
  }
}
char const *program_name;

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

#pragma GCC diagnostic ignored "-Wtype-limits"
unsigned long num_processors(enum nproc_query query);

int(__attribute__((__nonnull__(1))) rpl_nanosleep)(
    struct timespec const *requested_delay, struct timespec *remaining_delay) {

  time_t seconds;
  struct timespec intermediate;

  {

    intermediate.tv_sec = seconds;
  }
}

__inline static int strcoll_loop(char const *s1, size_t s1size, char const *s2,
                                 size_t s2size) {
  int diff;

  int *tmp___1;

  {
    while (1) {

      diff = strcoll(s1, s2);

      if (s1size == 0UL) {
      }
    }

    ;
  }
}
int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {

  {}
}

void(__attribute__((__leaf__)) md5_process_block)(void const *buffer,
                                                  size_t len,
                                                  struct md5_ctx *ctx) {
  uint32_t correct_words[16];
  uint32_t const *words;
  size_t nwords;
  uint32_t const *endp;
  uint32_t A;
  uint32_t B;
  uint32_t C;
  uint32_t D;
  uint32_t *cwp;

  uint32_t tmp___0;

  uint32_t tmp___2;

  uint32_t tmp___4;

  uint32_t tmp___8;

  uint32_t *tmp___11;
  uint32_t tmp___12;
  uint32_t *tmp___13;
  uint32_t tmp___14;

  uint32_t tmp___16;

  uint32_t tmp___20;

  uint32_t tmp___22;
  uint32_t *tmp___23;
  uint32_t tmp___24;

  uint32_t tmp___28;

  {
    words = (uint32_t const *)buffer;

    endp = words + nwords;

    if (!((unsigned long)words < (unsigned long)endp)) {
    }

    cwp++;
    tmp___0 = (uint32_t)*words;

    A += ((D ^ (B & (C ^ D))) + tmp___0) + 3614090360U;
    words++;

    ;

    tmp___2 = (uint32_t)*words;

    D += ((C ^ (A & (B ^ C))) + tmp___2) + 3905402710U;
    words++;

    ;

    tmp___4 = (uint32_t)*words;

    words++;
    C = (C << 17) | (C >> 15);

    ;
    while (1) {

      cwp++;

      words++;
      B = (B << 22) | (B >> 10);
    }

    ;
    while (1) {

      cwp++;
      tmp___8 = (uint32_t)*words;

      A += ((D ^ (B & (C ^ D))) + tmp___8) + 4118548399U;
      words++;

      A += B;
    }
  while_break___4:;

    ;
    while (1) {

      cwp++;
      tmp___12 = (uint32_t)*words;
      *tmp___11 = tmp___12;

      words++;
    }

    ;

    cwp++;
    tmp___14 = (uint32_t)*words;
    *tmp___13 = tmp___14;

    words++;

    ;
    while (1) {

      cwp++;

      A += ((D ^ (B & (C ^ D))) + tmp___16) + 1770035416U;

      A += B;
      goto while_break___8;
    }
  while_break___8:;

    ;

    cwp++;
    tmp___20 = (uint32_t)*words;

    C += ((B ^ (D & (A ^ B))) + tmp___20) + 4294925233U;
    words++;

  while_break___10:;

    cwp++;
    tmp___22 = (uint32_t)*words;

    B += ((A ^ (C & (D ^ A))) + tmp___22) + 2304563134U;

    ;

    cwp++;
    tmp___24 = (uint32_t)*words;
    *tmp___23 = tmp___24;

    A = (A << 7) | (A >> 25);

  while_break___12:;

    ;

    cwp++;

    C += ((B ^ (D & (A ^ B))) + tmp___28) + 2792965006U;
    words++;

    ;

    ;

    ;
    while (1) {
    }

    ;

    C = (C << 14) | (C >> 18);
    C += D;

    ;

    ;

    ;

    ;

    C = (C << 14) | (C >> 18);

    ;

    ;

    ;

    ;

    ;

    ;

  while_break___28:;

    ;

    ;

    ;

    ;
    while (1) {
    }

    ;

    ;

    ;

    ;

    ;

    ;

    goto while_break___39;

  while_break___39:;

    ;

    ;

    ;

  while_break___43:;

    ;

    ;

    ;

  while_break___47:;

  while_break___48:;

    ;

    ;

    ;

    ;

    ;

    C += D;
    goto while_break___54;

  while_break___54:;

    ;

    ;

    ;

    ;

    B = (B << 21) | (B >> 11);

    goto while_break___59;

  while_break___59:;

    ;

    ;

    ;

    B += ((D ^ (C | ~A)) + correct_words[9]) + 3951481745U;
    B = (B << 21) | (B >> 11);

    goto while_break___63;

  while_break___63:

  while_break:
    ctx->A = A;
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

  int tmp___0;
  size_t tmp___1;
  unsigned char c;

  unsigned short const **tmp___3;
  unsigned short const **tmp___4;

  {

    plimit = p + nbytes;
    width = 0;

    if (tmp___1 > 1UL) {

      if (!((unsigned long)p < (unsigned long)plimit)) {
      }

      if ((int const) * p == 34) {
        goto case_32;
      }

      if ((int const) * p == 42) {
        goto case_32;
      }
      if ((int const) * p == 43) {
      }

      if ((int const) * p == 46) {
        goto case_32;
      }
      if ((int const) * p == 47) {
      }

      if ((int const) * p == 55) {
        goto case_32;
      }

      if ((int const) * p == 58) {
      }

      if ((int const) * p == 62) {
        goto case_32;
      }

      if ((int const) * p == 65) {
        goto case_32;
      }

      if ((int const) * p == 70) {
        goto case_32;
      }

      if ((int const) * p == 72) {
      }

      if ((int const) * p == 76) {
      }

      if ((int const) * p == 78) {
        goto case_32;
      }
      if ((int const) * p == 79) {
        goto case_32;
      }
      if ((int const) * p == 80) {
      }

      if ((int const) * p == 82) {
        goto case_32;
      }

      if ((int const) * p == 89) {
      }

      if ((int const) * p == 99) {
      }

      if ((int const) * p == 102) {
        goto case_32;
      }

      if ((int const) * p == 109) {
        goto case_32;
      }
      if ((int const) * p == 110) {
      }
      if ((int const) * p == 111) {
      }

      if ((int const) * p == 114) {
        goto case_32;
      }
      if ((int const) * p == 115) {
      }

      if ((int const) * p == 124) {
        goto case_32;
      }
      if ((int const) * p == 125) {
        goto case_32;
      }
      if ((int const) * p == 126) {
      }
      goto switch_default;
    case_32:

      goto switch_break;
    switch_default:

      while (1) {
        bytes = mbrtowc(&wc, p, (size_t)(plimit - p), &mbstate);

        if (bytes == 0xfffffffffffffffeUL) {
        }

        w = wcwidth(wc);
        if (w >= 0) {

        } else {
        }
        p += bytes;
        tmp___0 = mbsinit((mbstate_t const *)(&mbstate));
      }

      ;
      goto switch_break;
    switch_break:;

    while_break:;
      return (width);
    }

    if (!((unsigned long)p < (unsigned long)plimit)) {
      goto while_break___1;
    }

    p++;

    if ((int const) * (*tmp___4 + (int)c) & 16384) {
      if (width == 2147483647) {
        goto overflow;
      }

    } else {
      if (!(flags & 2)) {

        if (!((int const) * (*tmp___3 + (int)c) & 2)) {
          if (width == 2147483647) {
            goto overflow;
          }
          width++;
        }
      } else {
      }
    }

  while_break___1:;
    return (width);
  overflow:
    return (2147483647);
  }
}

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

  int tmp___21;
  unsigned short const **tmp___22;
  size_t tmp___25;

  {

    if (tmp___25 > 1UL) {

      mbuiter_multi_next(&iter1);
      if (iter1.cur.wc_valid) {

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

      } else {
        goto while_break;
      }
      if (iter1.cur.wc_valid) {
        if (iter2.cur.wc_valid) {
          tmp = towlower((wint_t)iter1.cur.wc);

          tmp___1 = (int)tmp - (int)tmp___0;
        } else {
          tmp___1 = -1;
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

              } else {
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
      }
      iter1.cur.ptr += iter1.cur.bytes;

      iter2.cur.ptr += iter2.cur.bytes;

    while_break:
      mbuiter_multi_next(&iter1);

      if (tmp___15) {
      }

      if (iter2.cur.wc_valid) {

      } else {
        tmp___16 = 1;
      }

    } else {
      p1 = (unsigned char const *)s1;
      p2 = (unsigned char const *)s2;

      tmp___22 = __ctype_b_loc();
      if ((int const) * (*tmp___22 + (int)*p2) & 256) {

        c2 = (unsigned char)tmp___21;
      } else {
        c2 = (unsigned char)*p2;
      }

      p1++;
      p2++;
      if (!((int)c1 == (int)c2)) {
        goto while_break___0;
      }

    while_break___0:;
      return ((int)c1 - (int)c2);
    }
  }
}

extern int optind;

static char const *volatile charset_aliases;
static char const *get_charset_aliases(void) {
  char const *cp;
  char const *dir;
  char const *base;
  char *file_name___3;
  size_t dir_len___0;

  size_t base_len___0;

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

  int tmp___3;

  {

    if ((unsigned long)cp == (unsigned long)((void *)0)) {

      add_slash = tmp___1;
      file_name___3 = (char *)malloc(
          ((dir_len___0 + (size_t)add_slash) + base_len___0) + 1UL);
      if ((unsigned long)file_name___3 != (unsigned long)((void *)0)) {
        memcpy((void *)file_name___3, (void const *)dir, dir_len___0);
      }
      if ((unsigned long)file_name___3 == (unsigned long)((void *)0)) {

      } else {

        if (fd < 0) {

        } else {

          if ((unsigned long)fp == (unsigned long)((void *)0)) {

          } else {

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

            if ((unsigned long)res_ptr == (unsigned long)((void *)0)) {

              goto while_break;
            }
            strcpy(((res_ptr + res_size) - (l2 + 1UL)) - (l1 + 1UL),
                   (char const *)(buf1));

          __Cont:;

          while_break:
            rpl_fclose(fp);
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

  size_t tmp;

  {

    ;

    return (codeset);
  }
}

void heap_free(struct heap *heap);
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

    heap->array = (void **)xnmalloc(n_reserve, sizeof(*(heap->array)));

    heap->capacity = n_reserve;

    if (compare___0) {

    } else {
    }
    return (heap);
  }
}

int heap_insert(struct heap *heap, void *item) {

  {

    (heap->count)++;
    *(heap->array + heap->count) = item;
    heapify_up(heap->array, heap->count, heap->compare);
  }
}
void *heap_remove_top(struct heap *heap) {
  void *top;
  size_t tmp;

  {
    if (heap->count == 0UL) {
    }
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

  int tmp___0;

  {
    element = *(array + initial);
    parent = initial;

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
    while (1) {

      if (k != 1UL) {
        tmp = (*compare___0)((void const *)*(array + k / 2UL),
                             (void const *)new_element);
        if (!(tmp <= 0)) {
        }
      } else {
        goto while_break;
      }
      *(array + k) = *(array + k / 2UL);
      k /= 2UL;
    }
  while_break:
    *(array + k) = new_element;
    return;
  }
}

static size_t next_prime(size_t candidate) {

  {

  while_break:;
    return (candidate);
  }
}
static size_t raw_hasher(void const *data, size_t n) {

  {}
}
static _Bool raw_comparator(void const *a, void const *b) {

  {}
}

static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {

  void *data;

  {

  while_break:;
    return ((_Bool)1);
  }
}

int hash_insert_if_absent(Hash_table *table___0, void const *entry,
                          void const **matched_ent) {
  void *data;
  struct hash_entry *bucket;

  {

    bucket->data = (void *)entry;
  }
}
void *(__attribute__((__warn_unused_result__)) hash_insert)(
    Hash_table *table___0, void const *entry) {

  void *tmp___1;

  { return (tmp___1); }
}
void *hash_delete(Hash_table *table___0, void const *entry) {
  void *data;

  { return (data); }
}

extern void(__attribute__((__nonnull__(1, 4))) qsort)(
    void *__base, size_t __nmemb, size_t __size,
    int (*__compar)(void const *, void const *));

int(__attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp, off_t offset,
                                                int whence) {

  int tmp___1;

  { return (tmp___1); }
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
  int e___0;
  int *tmp___4;
  int *tmp___5;
  int tmp___6;

  {
    tmp = fopen(file, mode);
    fp = tmp;
    if (fp) {
      tmp___0 = fileno(fp);

      if (0 <= fd) {
        if (fd <= 2) {
          tmp___1 = dup_safer(fd);

          if (f < 0) {

            rpl_fclose(fp);
          }
          tmp___6 = rpl_fclose(fp);
          if (tmp___6 != 0) {

          } else {
            fp = fdopen(f, mode);
          }
        }
      }
    }
    return (fp);
  }
}
int filevercmp(char const *s1, char const *s2);

__inline static int order(unsigned char c) {

  {}
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
    while (1) {

      if (!(s1_pos < s1_len)) {
      }

      if (s1_pos < s1_len) {
        tmp___3 = c_isdigit((int)*(s1 + s1_pos));

      } else {

        if (s2_pos < s2_len) {
          tmp___4 = c_isdigit((int)*(s2 + s2_pos));
          if (tmp___4) {
          }
        } else {
          goto while_break___0;
        }
      }
      if (s1_pos == s1_len) {

      } else {
        tmp = order((unsigned char)*(s1 + s1_pos));
      }
      s1_c = tmp___0;
      if (s2_pos == s2_len) {

      } else {
      }
      s2_c = tmp___2;
      if (s1_c != s2_c) {
        return ((int __attribute__((__pure__)))(s1_c - s2_c));
      }
      s1_pos++;
      s2_pos++;

    while_break___0:;

      ;

      ;

      tmp___5 = c_isdigit((int)*(s1 + s1_pos));
      if (tmp___5) {

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
      }
      tmp___8 = c_isdigit((int)*(s2 + s2_pos));
      if (tmp___8) {
      }
    }

    ;
    return ((int __attribute__((__pure__)))0);
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

  char const *tmp___4;
  char const *tmp___5;
  int tmp___6;
  int tmp___7;

  {
    tmp = strcmp(s1, s2);

    if (simple_cmp == 0) {
    }

    if ((int const) * s1 == 46) {
    }

    s1_len = (size_t)(tmp___4 - s1);
    if (s2_suffix) {

    } else {
    }
    s2_len = (size_t)(tmp___5 - s2);
    if (s1_suffix) {

    } else {
      if (s2_suffix) {

        if (s1_len == s2_len) {
          tmp___6 = strncmp(s1, s2, s1_len);
          if (0 == tmp___6) {

            s2_len = (size_t)(s2_pos - s2);
          }
        }
      }
    }
    result = (int)verrevcmp(s1, s1_len, s2, s2_len);
    if (result == 0) {

    } else {
      tmp___7 = result;
    }
    return (tmp___7);
  }
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"

int rpl_fflush(FILE *stream) {
  int tmp;

  {
    if ((unsigned long)stream == (unsigned long)((void *)0)) {
      tmp = fflush(stream);

    } else {
    }
  }
}
int fd_safer(int fd) {

  {}
}

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {
  int saved_errno;
  int fd;
  int result;

  {

    if (fd < 0) {
    }

    result = fclose(fp);

    return (result);
  }
}

void fdadvise(int fd, off_t offset, off_t len, fadvice_t advice) {

  int tmp;

  { tmp = posix_fadvise(fd, offset, len, (int)advice); }
}
void fadvise(FILE *fp, fadvice_t advice) {
  int tmp;

  {
    if (fp) {
      tmp = fileno(fp);
      fdadvise(tmp, (off_t)0, (off_t)0, advice);
    }
  }
}

int dup_safer(int fd) {
  int tmp;

  { return (tmp); }
}

extern char *optarg;

extern int fputc_unlocked(int __c, FILE *__stream);

extern size_t fwrite_unlocked(void const *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);

static int decimal_point;
static int thousands_sep;
static _Bool hard_LC_COLLATE;

static char eolchar = (char)'\n';
static _Bool blanks[256];

static struct month monthtab[12] = {
    {"APR", 4}, {"AUG", 8}, {"DEC", 12}, {"FEB", 2},  {"JAN", 1},  {"JUL", 7},
    {"JUN", 6}, {"MAR", 3}, {"MAY", 5},  {"NOV", 11}, {"OCT", 10}, {"SEP", 9}};

static size_t sort_size;

static _Bool reverse;

static int tab = 128;
static _Bool unique;

static struct keyfield *keylist;
static char const *compress_program;

static unsigned int nmerge = 16U;

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

static struct tempnode *volatile temphead;

static void reap_all(void) {

  {

  while_break:;
  }
}
static void cleanup(void) {
  struct tempnode const *node;

  {

    temphead = (struct tempnode *)((void *)0);
  }
}

static struct tempnode *create_temp_file(int *pfd, _Bool survive_fd_exhaustion);
static char const slashbase[12] = {
    (char const)'/', (char const)'s', (char const)'o', (char const)'r',
    (char const)'t', (char const)'X', (char const)'X', (char const)'X',
    (char const)'X', (char const)'X', (char const)'X', (char const)'\000'};

static struct tempnode *create_temp_file(int *pfd,
                                         _Bool survive_fd_exhaustion) {
  int fd;

  char const *temp_dir;
  size_t len;
  size_t tmp;
  struct tempnode *node;
  struct tempnode *tmp___0;
  char *file;

  {

    len = tmp;
    tmp___0 = (struct tempnode *)xmalloc(
        ((unsigned long)(&((struct tempnode *)0)->name) + len) +
        sizeof(slashbase));
    node = tmp___0;
    file = node->name;
    memcpy((void *)file, (void const *)temp_dir, len);
    memcpy((void *)(file + len), (void const *)(slashbase), sizeof(slashbase));
    node->next = (struct tempnode *)((void *)0);

    fd = mkstemp_safer(file);
    if (0 <= fd) {
    }

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

      if (tmp == 0) {

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
    }
    return (fp);
  }
}
static void xfclose(FILE *fp, char const *file) {

  int tmp___4;

  {

    if (tmp___4 != 0) {
    }

    ;
  }
}

static struct tempnode *create_temp(FILE **pfp) {

  {}
}
static FILE *open_temp(struct tempnode *temp) {
  int tempfd;

  {

    if (tempfd < 0) {
    }

  case_neg_1:

  switch_default:

      ;
  }
}

static void specify_sort_size(int oi, char c, char const *s) {
  uintmax_t n;

  enum strtol_error e;

  {

    if ((unsigned int)e == 0U) {

      sort_size = n;
      if (sort_size == n) {

        return;
      }
      e = (enum strtol_error)1;
    }
    xstrtol_fatal(e, oi, c, long_options___1, s);
  }
}

static size_t default_sort_size(void) {
  double avail;

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
    if (avail > total / (double)8) {

    } else {
      tmp___1 = total / (double)8;
    }
    mem = tmp___1;
    size = 0xffffffffffffffffUL;
    tmp___2 = getrlimit((__rlimit_resource_t)2, &rlimit);

    if (mem < (double)size) {
      size = (size_t)mem;
    }
    if (size > (unsigned long)nmerge * (2UL + sizeof(struct line))) {
      tmp___5 = size;
    } else {
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

  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {
    worst_case_per_input_byte = line_bytes + 1UL;

    i = (size_t)0;
    while (1) {

      if (!(i < nfiles)) {
      }
      if (i < nfps) {

      } else {

        if (tmp___6 == 0) {

        } else {
          tmp___4 = stat((char const *)*(files + i), &st);
        }
        tmp___7 = tmp___5;
      }

      if ((st.st_mode & 61440U) == 32768U) {
        file_size = st.st_size;
      } else {
      }
      if (!size_bound) {

        if (!size_bound) {
          size_bound = default_sort_size();
        }
      }
      worst_case = (size_t)file_size * worst_case_per_input_byte + 1UL;
      if ((size_t)file_size != worst_case / worst_case_per_input_byte) {

      } else {
        if (size_bound - size <= worst_case) {
          return (size_bound);
        }
      }
      size += worst_case;
    }
  while_break:;
  }
}
static void initbuf(struct buffer *buf___1, size_t line_bytes, size_t alloc) {
  size_t tmp;
  size_t tmp___0;

  {

    buf___1->buf = (char *)malloc(alloc);
    if (buf___1->buf) {
      goto while_break;
    }

  while_break:
    buf___1->line_bytes = line_bytes;
    buf___1->alloc = alloc;
    tmp___0 = (size_t)0;
    buf___1->nlines = tmp___0;
    tmp = tmp___0;

    buf___1->used = tmp;
    buf___1->eof = (_Bool)0;
  }
}
__inline static struct line *buffer_linelim(struct buffer const *buf___1) {

  { return ((struct line *)(buf___1->buf + buf___1->alloc)); }
}
static char *begfield(struct line const *line, struct keyfield const *key) {
  char *ptr;
  char *lim;
  size_t sword;

  size_t tmp___2;

  {

    sword = (size_t)key->sword;

    if (tab != 128) {

      if ((unsigned long)ptr < (unsigned long)lim) {
        if (!((int)*ptr != tab)) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      ptr++;

    while_break___0:;

    while_break:;
    } else {

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp___2 = sword;

        if (!tmp___2) {
        }
      } else {
      }

    while_break___2:;

    while_break___3:;

    while_break___1:;
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

  unsigned char tmp___1;

  {

    eword = (size_t)key->eword;

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
      }

    while_break:;
    } else {

    while_break___2:;

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp___1 = to_uchar(*ptr);
        if (blanks[tmp___1]) {
        }
      } else {
        goto while_break___3;
      }
      ptr++;

    while_break___3:;

    while_break___1:;
    }
    if (echar != 0UL) {
    }
    return (ptr);
  }
}
static _Bool fillbuf___7(struct buffer *buf___1, FILE *fp, char const *file) {
  struct keyfield const *key;
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

  int tmp___5;

  struct line *tmp___8;
  size_t line_alloc;

  {
    key = (struct keyfield const *)keylist;
    eol = eolchar;
    line_bytes = buf___1->line_bytes;

    ptr = buf___1->buf + buf___1->used;
    tmp = buffer_linelim((struct buffer const *)buf___1);
    linelim = tmp;
    line = linelim - buf___1->nlines;

    if (buf___1->nlines) {

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

      if (tmp___5) {
        buf___1->eof = (_Bool)1;
        if ((unsigned long)buf___1->buf == (unsigned long)ptrlim) {
        }
      }
    }
    while (1) {
      p = (char *)memchr((void const *)ptr, (int)eol, (size_t)(ptrlim - ptr));
      if (!p) {
        goto while_break___1;
      }

      ptr = p + 1;
      line--;
      line->text = line_start;
      line->length = (size_t)(ptr - line_start);

      avail -= line_bytes;
      if (key) {
        if (key->eword == 0xffffffffffffffffUL) {

        } else {
        }
        if (key->sword != 0xffffffffffffffffUL) {

        } else {
        }
      }
      line_start = ptr;
    }
  while_break___1:

    if (buf___1->eof) {
    }

  while_break___0:
    buf___1->used = (size_t)(ptr - buf___1->buf);
    tmp___8 = buffer_linelim((struct buffer const *)buf___1);
    buf___1->nlines = (size_t)(tmp___8 - line);
    if (buf___1->nlines != 0UL) {

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

    p = number + (int)minus_sign;

    ch = (unsigned char)*tmp;
    if (!((unsigned int)ch - 48U <= 9U)) {
      goto while_break___0;
    }

  while_break___0:;

    ;

    if (nonzero) {
      order___0 = (int)unit_order[ch];

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

  int tmp___4;

  {

    a++;

    ;

    tmp___0 = to_uchar((char)*b);
    if (!blanks[tmp___0]) {
    }

  while_break___0:

    tmp___2 = find_unit_order(b);
    diff = (int)(tmp___1 - tmp___2);
    if (diff) {

    } else {
    }
    return (tmp___4);
  }
}
static int numcompare___3(char const *a, char const *b) {

  unsigned char tmp___0;
  int tmp___1;

  {

    ;

    if (!blanks[tmp___0]) {
    }

  while_break___0:
    tmp___1 = (int)strnumcmp(a, b, decimal_point, thousands_sep);
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

  int tmp___7;

  {
    tmp = strtold(sa, &ea);
    a = tmp;
    tmp___0 = strtold(sb, &eb);
    b = tmp___0;
    if ((unsigned long)sa == (unsigned long)ea) {

      return (tmp___1);
    }

    return (tmp___7);
  }
}

static int compare_random(char *__restrict texta, size_t lena,
                          char *__restrict textb, size_t lenb) {

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

  size_t tmp___0;
  _Bool a_fits;
  size_t sizeb;
  size_t tmp___1;
  char *tmp___2;
  size_t tmp___3;
  size_t tmp___4;

  size_t tmp___6;

  int diff;
  int tmp___8;

  {

    buf___1 = stackbuf;
    bufsize___1 = sizeof(stackbuf);

    if (hard_LC_COLLATE) {

      while (1) {

        if (bufsize___1 < guess_bufsize) {

          free(allocated);
          allocated = malloc(bufsize___1);
          buf___1 = (char *)allocated;
        }

        sizea = tmp___0;
        a_fits = (_Bool)(sizea <= bufsize___1);
        if ((unsigned long)textb < (unsigned long)limb) {
          if (a_fits) {

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
          }
        } else {
        _L:
          bufsize___1 = sizea + sizeb;

          free(allocated);
          allocated = xmalloc(bufsize___1);

          if ((unsigned long)texta < (unsigned long)lima) {
            strxfrm(buf___1, (char const *)texta, sizea);
          }
          if ((unsigned long)textb < (unsigned long)limb) {
            strxfrm(buf___1 + sizea, (char const *)textb, sizeb);
          }
        }

        if ((unsigned long)textb < (unsigned long)limb) {

          textb += tmp___6 + 1UL;
        }
        if (!((unsigned long)texta < (unsigned long)lima)) {
          if (!((unsigned long)textb < (unsigned long)limb)) {
            lena = sizea;
            texta = buf___1;
            lenb = sizeb;

            goto while_break;
          }
        }
      }
    while_break:;
    }

    tmp___8 =
        memcmp((void const *)(dig[0]), (void const *)(dig[1]), sizeof(dig[0]));
    diff = tmp___8;

    return (diff);
  }
}

static _Bool default_key_compare(struct keyfield const *key) {

  int tmp___0;

  { return ((_Bool)tmp___0); }
}
static void key_to_opts(struct keyfield const *key, char *opts___1) {

  {}
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

  unsigned char tmp___8;
  unsigned char tmp___9;
  unsigned char tmp___10;
  unsigned char tmp___11;
  unsigned char tmp___12;
  unsigned char tmp___13;
  unsigned char tmp___14;
  unsigned char tmp___15;
  unsigned char tmp___16;

  _Bool tmp___24;

  int tmp___27;

  {
    key = keylist;
    texta = (char *)a->keybeg;

    translate = key->translate;

    lena = (size_t)(lima - texta);
    lenb = (size_t)(limb - textb);
    if (hard_LC_COLLATE) {

    } else {

      if (tmp___24) {

      } else {
        if (key->month) {

        } else {
          if (key->random) {

          } else {
            if (key->version) {
            _L___2:
              if (ignore) {

              } else {
                if (translate) {
                _L___1:
                  size = ((lena + 1UL) + lenb) + 1UL;
                  if (size <= sizeof(stackbuf)) {
                    ta = stackbuf;

                  } else {
                    allocated = xmalloc(size);
                    ta = (char *)allocated;
                  }
                  tb = (ta + lena) + 1;
                  i = (size_t)0;
                  tlena = i;
                  while (1) {

                    if (!(i < lena)) {
                    }
                    if (ignore) {

                    } else {

                      tmp = tlena;
                    }
                    i++;
                  }
                while_break___0:
                  *(ta + tlena) = (char)'\000';
                  i = (size_t)0;
                  tlenb = i;

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

              if (ignore) {
                free(allocated);
              } else {
              }
            } else {
              if (ignore) {
                if (translate) {

                  texta++;

                while_break___4:;

                  if ((unsigned long)textb < (unsigned long)limb) {
                    tmp___8 = to_uchar(*textb);

                  } else {
                    goto while_break___5;
                  }
                  textb++;

                while_break___5:;

                  tmp___9 = to_uchar(*texta);
                  tmp___10 = to_uchar((char)*(translate + (int)tmp___9));
                  tmp___11 = to_uchar(*textb);
                  tmp___12 = to_uchar((char)*(translate + (int)tmp___11));
                  diff = (int)tmp___10 - (int)tmp___12;
                  if (diff) {
                  }
                  texta++;
                  textb++;

                  diff = ((unsigned long)texta < (unsigned long)lima) -
                         ((unsigned long)textb < (unsigned long)limb);

                  ;
                } else {

                  while (1) {

                    while (1) {

                      if ((unsigned long)texta < (unsigned long)lima) {

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

                while_break___6:;
                }
              } else {
                if (lena == 0UL) {

                } else {
                  if (lenb == 0UL) {
                    goto greater;
                  } else {
                  }
                }
              }
            }
          }
        }
      }
    }

    key = key->next;
    if (!key) {
      goto while_break;
    }
    if (key->eword != 0xffffffffffffffffUL) {

      limb = limfield(b, (struct keyfield const *)key);
    } else {
      lima = (char *)((a->text + a->length) - 1);
      limb = (char *)((b->text + b->length) - 1);
    }

  while_break:;
    return (0);
  greater:
    diff = 1;
  not_equal:
    if (key->reverse) {

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

            } else {
              diff = alen != blen;
            }
          }
        }
      }
    }
    if (reverse) {

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

  int tmp___1;

  size_t tmp___3;

  {
    buf___1 = (char *)line->text;
    n_bytes = (size_t)line->length;
    ebuf = buf___1 + n_bytes;
    if (!output_file) {

    } else {
    _L:
      *(ebuf + -1) = eolchar;
      tmp___3 = fwrite_unlocked((void const *)buf___1, (size_t)1, n_bytes, fp);
      if (tmp___3 != n_bytes) {
      }
    }
  }
}
static _Bool check(char const *file_name___3, char checkonly) {
  FILE *fp;
  FILE *tmp;
  struct buffer buf___1;
  struct line temp;

  _Bool ordered;
  size_t tmp___0;
  struct line const *line;

  {
    tmp = xfopen(file_name___3, "r");

    initbuf(&buf___1, sizeof(struct line), tmp___0);
    temp.text = (char *)((void *)0);

    return (ordered);
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

    *pfps = tmp;

    if ((files + i)->temp) {
      if ((int)((files + i)->temp)->state != 0) {

      } else {

        *(fps + i) = tmp___1;
      }
    } else {
      tmp___1 = stream_open((files + i)->name, "r");
      *(fps + i) = tmp___1;
    }
    if (!*(fps + i)) {
    }

  while_break:;
  }
}
static void mergefps(struct sortfile *files, size_t ntemps, size_t nfiles,
                     FILE *ofp, char const *output_file, FILE **fps) {
  struct buffer *buffer;
  struct buffer *tmp;
  struct line saved___0;
  struct line const *savedline;

  struct line const **cur;
  struct line const **tmp___0;
  struct line const **base;
  struct line const **tmp___1;
  size_t *ord;

  size_t i;
  size_t j;

  struct keyfield const *key;
  size_t tmp___3;
  struct line const *linelim;

  _Bool tmp___5;

  struct line const *smallest;

  size_t lo;
  size_t hi;
  size_t probe;
  size_t ord0;
  size_t count_of_smaller_lines;
  int cmp;
  int tmp___10;

  {

    buffer = tmp;

    cur = tmp___0;
    tmp___1 = (struct line const **)xnmalloc(nfiles, sizeof(*base));

    if (!(i < nfiles)) {
      goto while_break;
    }

    initbuf(buffer + i, sizeof(struct line), tmp___3);
    tmp___5 = fillbuf___7(buffer + i, *(fps + i), (files + i)->name);
    if (tmp___5) {

      *(base + i) = linelim - (buffer + i)->nlines;

    } else {

      nfiles--;

      if (!(j < nfiles)) {
      }

    while_break___0:;
    }

  while_break:

    if (!(i < nfiles)) {
    }
    *(ord + i) = i;
    i++;

  while_break___1:

      ;

    ;

    if (unique) {
      if (savedline) {
      }
      if (!savedline) {
        savedline = (struct line const *)(&saved___0);

        saved___0.length = (size_t)smallest->length;
        memcpy((void *)saved___0.text, (void const *)smallest->text,
               saved___0.length);
      }
    } else {
      write_line(smallest, ofp, output_file);
    }
    if ((unsigned long)*(base + *(ord + 0)) < (unsigned long)smallest) {

    } else {
    }

    hi = nfiles;

    if (!(lo < hi)) {
    }
    tmp___10 = compare(*(cur + ord0), *(cur + *(ord + probe)));

    if (cmp < 0) {

    } else {
    }
    probe = (lo + hi) / 2UL;

  while_break___8:
    count_of_smaller_lines = lo - 1UL;
    j = (size_t)0;

    ;
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

  size_t tmp___3;

  {
    tmp = (struct merge_node *)xmalloc((2UL * sizeof(*merge_tree)) * nthreads);
    merge_tree = tmp;
    root = merge_tree;

    tmp___0 = tmp___1;

    tmp___3 = nlines;
    root->nhi = tmp___3;
    root->nlo = tmp___3;

    root->level = 0U;

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

    } else {
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

    return ((struct merge_node *)node_pool);
  }
}
static int compare_nodes(void const *a, void const *b) {
  struct merge_node const *nodea;
  struct merge_node const *nodeb;

  {

    nodeb = (struct merge_node const *)b;

    return (nodea->level < nodeb->level);
  }
}

__inline static void unlock_node(struct merge_node *node) {

  { pthread_mutex_unlock(&node->lock); }
}

static void queue_init(struct merge_node_queue *queue, size_t nthreads) {

  { queue->priority_queue = heap_alloc(&compare_nodes, 2UL * nthreads); }
}
static void queue_insert(struct merge_node_queue *queue,
                         struct merge_node *node) {

  {

    heap_insert(queue->priority_queue, (void *)node);

    pthread_mutex_unlock(&queue->mutex);
  }
}
static struct merge_node *queue_pop(struct merge_node_queue *queue) {
  struct merge_node *node;

  {
    pthread_mutex_lock(&queue->mutex);

    node = (struct merge_node *)heap_remove_top(queue->priority_queue);
    if (node) {
    }

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

  int tmp___3;

  {
    lo_orig = node->lo;
    hi_orig = node->hi;
    to_merge = (total_lines >> 2U * (node->level + 1U)) + 1UL;
    if (node->level > 1U) {
      dest = *(node->dest);

    while_break:
      merged_lo = (size_t)(lo_orig - node->lo);
      merged_hi = (size_t)(hi_orig - node->hi);

      *(node->dest) = dest;
    } else {

      if ((unsigned long)node->lo != (unsigned long)node->end_lo) {

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

      while_break___3:;
      } else {
        if (node->nlo == merged_lo) {

          if ((unsigned long)node->hi != (unsigned long)node->end_hi) {

          } else {
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
  _Bool hi_avail;
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    if (!node->queued) {

      hi_avail = (_Bool)(node->hi - node->end_hi != 0L);
      if (lo_avail) {

        tmp___1 = tmp;
      } else {
        if (hi_avail) {

        } else {
          tmp___0 = 0;
        }
        tmp___1 = tmp___0;
      }
      if (tmp___1) {
        queue_insert(queue, node);
      }
    }
  }
}
static void queue_check_insert_parent(struct merge_node_queue *queue,
                                      struct merge_node *node) {

  {
    if (node->level > 1U) {

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
        queue_insert(queue, node);
        goto while_break;
      }
      mergelines_node(node, total_lines, tfp, temp_output);
      queue_check_insert(queue, node);
      queue_check_insert_parent(queue, node);
    }
  while_break:;
  }
}

static void *sortlines_thread(void *data) {

  {}
}
static void sortlines(struct line *__restrict lines, size_t nthreads,
                      size_t total_lines, struct merge_node *node,
                      struct merge_node_queue *queue, FILE *tfp,
                      char const *temp_output) {
  size_t nlines;

  size_t hi_threads;

  struct thread_args args;
  size_t nlo;
  size_t nhi;
  struct line *temp;
  int tmp;

  {
    nlines = node->nlo + node->nhi;

    args.lines = (struct line *)lines;

    if (nthreads > 1UL) {
      if (131072UL <= nlines) {

        if (tmp == 0) {
          sortlines(lines - node->nlo, hi_threads, total_lines, node->hi_child,
                    queue, tfp, temp_output);

        } else {
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

  _Bool same;

  int tmp___2;

  int tmp___6;

  {

    i = ntemps;

    if (!(i < nfiles)) {
    }

    if (outfile) {

    } else {
    _L___0:
      if (!got_outstat) {
        if (outfile) {

        } else {
        }
        if (tmp___2 != 0) {
        }
      }

      same = (_Bool)tmp___6;
    }

  while_break:;
  }
}
static void merge(struct sortfile *files, size_t ntemps, size_t nfiles,
                  char const *output_file) {
  size_t in;
  size_t out;

  FILE *tfp;

  FILE **fps;
  size_t nopened;
  size_t tmp___8;

  FILE *tfp___1;
  struct tempnode *temp___1;
  size_t tmp___13;
  size_t tmp___14;

  {

  while_break:
    avoid_trashing_input(files, ntemps, nfiles, output_file);

    nopened = tmp___8;

    ;

    mergefps(files + 0, tmp___13, nopened, tfp___1,
             (char const *)(temp___1->name), fps);

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

  size_t tmp___1;
  struct line *line;
  struct tempnode *tmp___2;
  struct merge_node_queue queue;
  struct merge_node *merge_tree;
  struct merge_node *tmp___3;
  struct merge_node *root;
  _Bool tmp___4;
  size_t i;

  struct sortfile *tempfiles;
  struct sortfile *tmp___5;

  {
    ntemps = (size_t)0;

    file = (char const *)*files;
    tmp = xfopen(file, "r");
    fp = tmp;

    if (!buf___1.alloc) {
      tmp___1 = sort_buffer_size((FILE *const *)(&fp), (size_t)1, files, nfiles,
                                 bytes_per_line);
      initbuf(&buf___1, bytes_per_line, tmp___1);
    }

    nfiles--;

    tmp___4 = fillbuf___7(&buf___1, fp, file);
    if (!tmp___4) {
      goto while_break___1;
    }

    line = buffer_linelim((struct buffer const *)(&buf___1));
    if (buf___1.eof) {
      if (!nfiles) {
        if (!ntemps) {
          if (!buf___1.left) {
            xfclose(fp, file);
            tfp = xfopen(output_file, "w");

            output_file_created = (_Bool)1;
          } else {
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
      sortlines(line, nthreads, buf___1.nlines, root, &queue, tfp, temp_output);

    } else {
      write_unique((struct line const *)(line - 1), tfp, temp_output);
    }
    xfclose(tfp, temp_output);
    if (output_file_created) {
      goto finish;
    }

  while_break___1:
    xfclose(fp, file);

    ;
  finish:

    if (!output_file_created) {

      tmp___5 = (struct sortfile *)xnmalloc(ntemps, sizeof(*tempfiles));

      i = (size_t)0;

    while_break___2:
      merge(tempfiles, ntemps, ntemps, output_file);
    }
    reap_all();
  }
}
static void insertkey(struct keyfield *key_arg) {
  struct keyfield **p;
  struct keyfield *key;
  struct keyfield *tmp;

  {
    tmp = (struct keyfield *)xmemdup((void const *)key_arg, sizeof(*key));
    key = tmp;

    while (1) {

      if (!*p) {
        goto while_break;
      }

      p = &(*p)->next;
    }
  while_break:
    *p = key;
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

  case_0:

      ;
  }
}
static char *set_ordering(char const *s, struct keyfield *key,
                          enum blanktype blanktype) {

  {

    if (!*s) {
    }

    if ((int const) * s == 105) {
    }

    if ((unsigned int)blanktype == 0U) {

    } else {
    }

    goto switch_break;

    goto switch_break;

    goto switch_break;

    goto switch_break;

    goto switch_break;
  case_105:

    goto switch_break;

    goto switch_break;

    goto switch_break;

  switch_break:

  while_break:;
  }
}

int main(int argc, char **argv);

int main(int argc, char **argv) {
  struct keyfield *key;
  struct keyfield key_buf;
  struct keyfield gkey;
  _Bool gkey_only;
  char const *s;
  int c;

  _Bool mergeonly;
  char *random_source;
  _Bool need_random;
  size_t nthreads;
  size_t nfiles;
  _Bool posixly_correct;
  char *tmp;
  _Bool obsolete_usage;

  char **files;
  char *files_from;
  struct Tokens tok;
  char const *outfile;
  struct lconv const *locale;
  struct lconv const *tmp___1;
  size_t i;
  struct sigaction act;

  int oi;
  size_t tmp___3;
  int tmp___4;
  _Bool minus_pos_usage;
  int tmp___5;

  char const *optarg1;
  int tmp___7;
  char *tmp___8;
  char *tmp___9;
  size_t tmp___10;
  ptrdiff_t tmp___11;
  char str[2];
  ptrdiff_t tmp___12;
  char *tmp___13;
  int tmp___14;
  size_t tmp___15;
  size_t tmp___16;
  size_t tmp___17;
  char *tmp___18;

  int tmp___21;

  char *tmp___22;
  char const *tmp___23;
  char *tmp___24;
  int tmp___25;
  char *tmp___26;
  char const *p;
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

  char *tmp___47;
  char const *tmp___48;
  char *tmp___49;
  char *tmp___50;
  char const *tmp_dir;
  char const *tmp___51;
  char const *tmp___52;
  char const *tmp___53;
  char *tmp___54;
  int tmp___56;

  struct sortfile *sortfiles;
  struct sortfile *tmp___58;
  size_t i___1;
  unsigned long np;

  size_t nthreads_max;

  {

    mergeonly = (_Bool)0;

    nfiles = (size_t)0;

    outfile = (char const *)((void *)0);

    if (!thousands_sep) {

    } else {
    }

    files = (char **)xnmalloc((size_t)argc, sizeof(*files));

    if (c == -1) {

    } else {
      if (posixly_correct) {

      } else {
      _L___1:
        c = getopt_long(argc, (char *const *)argv, short_options,
                        long_options___1, &oi);
        if (c == -1) {

          if (argc <= optind) {
          }

          *(files + tmp___3) = *(argv + tmp___4);
        } else {

          if (c == 109) {
          }

          if (c == 115) {
          }
          if (c == 83) {
            goto case_83;
          }
          if (c == 116) {
          }
          if (c == 84) {
            goto case_84;
          }

          key = (struct keyfield *)((void *)0);

          if (!key) {
            tmp___10 = nfiles;
            nfiles++;
            *(files + tmp___10) = optarg;
          }
          goto switch_break;

        case_99:

        case_107:
          key = key_init(&key_buf);
          s = parse_field_count((char const *)optarg, &key->sword,
                                "invalid number at field start");

          if ((int const) * s != 44) {

          } else {
            s = parse_field_count(s + 1, &key->eword,
                                  "invalid number after \',\'");

            s = (char const *)set_ordering(s, key, (enum blanktype)1);
          }

          insertkey(key);

        case_109:

        case_111:

          outfile = (char const *)optarg;

        case_115:

          goto switch_break;
        case_83:

        case_116:

        case_84:

        switch_default:

        switch_break:;
        }
      }
    }

  while_break___1:;
    if (files_from) {

      if (tmp___33 == 0) {

      } else {
        stream = fopen_safer((char const *)files_from, "r");
        if ((unsigned long)stream == (unsigned long)((void *)0)) {
        }
      }
      readtokens0_init(&tok);

      if (tok.n_tok) {

        nfiles = tok.n_tok;

        while (1) {
        }

        ;
      } else {
      }
    }
    key = keylist;

    if (!key) {
      goto while_break___4;
    }
    tmp___45 = default_key_compare((struct keyfield const *)key);

    key = key->next;

  while_break___4:;

    reverse = gkey.reverse;

    if (mergeonly) {

      merge(sortfiles, (size_t)0, nfiles, outfile);
    } else {
      if (!nthreads) {

        if (np < 8UL) {
          nthreads = np;
        } else {
        }
      }
      nthreads_max = 0xffffffffffffffffUL / (2UL * sizeof(struct merge_node));

      sort((char *const *)files, nfiles, outfile, nthreads);
    }

    exit(0);
  }
}
