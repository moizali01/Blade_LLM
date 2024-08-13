typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;
struct timespec {

  __syscall_slong_t tv_nsec;
};
typedef unsigned long size_t;

typedef unsigned int __uid_t;

typedef unsigned int __mode_t;

typedef long __off_t;

struct stat {

  __mode_t st_mode;

  __off_t st_size;
};

struct hash_tuning {

  _Bool is_n_buckets;
};
typedef struct hash_tuning Hash_tuning;

typedef struct hash_table Hash_table;
typedef unsigned long uintmax_t;
typedef long __off64_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef __off_t off_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;

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
struct option {};
typedef unsigned int uint32_t;
typedef int __pid_t;
typedef __pid_t pid_t;
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
struct __anonstruct___sigset_t_9 {};
typedef struct __anonstruct___sigset_t_9 __sigset_t;
typedef __sigset_t sigset_t;

struct _obstack_chunk {};
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
  isaac_word a;
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

  union __anonunion_buf_30 buf;
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
  uint32_t A;

  uint32_t C;

  uint32_t buflen;
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
  struct hash_entry *next;
};
struct hash_table {
  struct hash_entry *bucket;
  struct hash_entry const *bucket_limit;
  size_t n_buckets;
  size_t n_buckets_used;

  size_t (*hasher)(void const *, size_t);
  _Bool (*comparator)(void const *, void const *);
  void (*data_freer)(void *);
  struct hash_entry *free_entry_list;
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

typedef unsigned long pthread_t;

typedef union pthread_attr_t pthread_attr_t;
struct __anonstruct___data_7 {
  int __lock;

  unsigned long long __total_seq;
  unsigned long long __wakeup_seq;
  unsigned long long __woken_seq;
  void *__mutex;
};
union __anonunion_pthread_cond_t_6 {
  struct __anonstruct___data_7 __data;
};
typedef union __anonunion_pthread_cond_t_6 pthread_cond_t;

typedef union __anonunion_pthread_condattr_t_8 pthread_condattr_t;

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

extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) memcpy)(
    void *__restrict __dest, void const *__restrict __src, size_t __n);

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);

int fd_safer(int fd);

extern struct _IO_FILE *stdout;

extern struct _IO_FILE *stdin;

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);

int close_stream(FILE *stream) {

  _Bool prev_fail;

  _Bool fclose_fail;
  int tmp___1;

  {

    tmp___1 = rpl_fclose(stream);

    if (prev_fail) {

    } else {
      if (fclose_fail) {
      }
    }
  }
}

extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1, 2), __leaf__)) memmove)(void *__dest, void const *__src,
                                           size_t __n);

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));

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

    c1 = (unsigned char)c_tolower((int)*p1);
    c2 = (unsigned char)c_tolower((int)*p2);
    if ((int)c1 == 0) {
    }
    p1++;
    p2++;
    if (!((int)c1 == (int)c2)) {
      goto while_break;
    }

  while_break:;
  }
}

_Bool c_isdigit(int c) __attribute__((__const__));

_Bool c_isdigit(int c) __attribute__((__const__));
_Bool c_isdigit(int c) {
  int tmp;

  { return ((_Bool)tmp); }
}

_Bool c_isspace(int c) {
  int tmp;

  { return ((_Bool)tmp); }
}

int c_tolower(int c) {
  int tmp;

  { return (tmp); }
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

  {
    matchind = (ptrdiff_t)-1;

    arglen = strlen(arg);
    i = (size_t)0;

    ;
    if (ambiguous) {

    } else {
      return (matchind);
    }
  }
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

  int base;

  strtol_error overflow;
  char *tmp___5;

  {

    q = s;
    ch = (unsigned char)*q;

    ;

    tmp = strtoumax(s, p, strtol_base);

    if ((int)*(*p) != 0) {

      tmp___5 = strchr(valid_suffixes, (int)*(*p));

      if ((int)*(*p) == 80) {
      }

      goto switch_break___0;

    case_107:
      overflow = bkm_scale_by_power(&tmp, base, 1);
      goto switch_break___0;

      overflow = bkm_scale_by_power(&tmp, base, 2);

    case_80:
      overflow = bkm_scale_by_power(&tmp, base, 5);

    case_84:

    case_119:

    case_89:

      goto switch_break___0;

    switch_default:
      *val = tmp;

    switch_break___0:
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
    }
    *val = tmp;
    return (err);
  }
}

static strtol_error bkm_scale___0(unsigned long *x, int scale_factor) {

  { return ((strtol_error)0); }
}
static strtol_error bkm_scale_by_power___0(unsigned long *x, int base,
                                           int power) {
  strtol_error err;
  strtol_error tmp;
  int tmp___0;

  {
    err = (strtol_error)0;

    if (!tmp___0) {
    }
    tmp = bkm_scale___0(x, base);
    err = (strtol_error)((unsigned int)err | (unsigned int)tmp);

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

  int *tmp___4;
  int base;

  strtol_error overflow;

  {
    err = (strtol_error)0;

    if (ptr) {

    } else {
      p = &t_ptr;
    }
    q = s;
    ch = (unsigned char)*q;

    ;

    tmp = strtoul(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {

    } else {
      tmp___4 = __errno_location();
    }

    if ((int)*(*p) != 0) {

      if ((int)*(*p) == 69) {
      }

      if ((int)*(*p) == 84) {
      }

      goto switch_break___0;

      goto switch_break___0;
    case_69:

      goto switch_break___0;

      goto switch_break___0;

      goto switch_break___0;
    case_77:
      overflow = bkm_scale_by_power___0(&tmp, base, 2);
      goto switch_break___0;
    case_80:

      goto switch_break___0;
    case_84:
      overflow = bkm_scale_by_power___0(&tmp, base, 4);
      goto switch_break___0;
    case_119:

      overflow = bkm_scale_by_power___0(&tmp, base, 8);

    switch_default:
      *val = tmp;

    switch_break___0:
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
    }
    *val = tmp;
    return (err);
  }
}

int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size);

int xmemcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {
  int diff;
  int tmp;
  int collation_errno;
  int *tmp___0;

  {
    tmp = memcoll0(s1, s1size, s2, s2size);
    diff = tmp;

    collation_errno = *tmp___0;

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
  }
}

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
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

  {

    p = realloc(p, n);

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

  {}
}
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2)
    __attribute__((__pure__));

#pragma GCC diagnostic ignored "-Wtype-limits"

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

      *p = (char)(48U + i % 10U);
      i /= 10U;
      if (!(i != 0U)) {
        goto while_break___0;
      }

    while_break___0:;
    }
    return (p);
  }
}

extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrtowc)(
    wchar_t *__restrict __pwc, char const *__restrict __s, size_t __n,
    mbstate_t *__restrict __p);

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

        a++;
        b++;
        if (!((int const) * a == (int const) * b)) {
          goto while_break;
        }
        if (!((unsigned int)*a - 48U <= 9U)) {
        }

      while_break:;
        if ((unsigned int)*a - 48U <= 9U) {
          if ((unsigned int)*b - 48U <= 9U) {
            return ((int __attribute__((__pure__)))((int const) * a -
                                                    (int const) * b));
          }
        }
        if ((unsigned int)*a - 48U <= 9U) {
        }
        if ((unsigned int)*b - 48U <= 9U) {
        }

      } else {
        goto _L;
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

      while_break___0:;

      } else {

        if ((int const) * tmp == (int const)decimal_point___0) {
        b_trailing_nonzero:
          while (1) {

            if (!((int const) * b == 48)) {
              goto while_break___1;
            }
            b++;
          }
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

      tmpa = (unsigned char)*a;
      if (!((int)tmpa == 48)) {
      }

      ;
      if ((int)tmpb != 45) {
        if ((int)tmpa == decimal_point___0) {

          tmpa = (unsigned char)*a;
          if (!((int)tmpa == 48)) {
            goto while_break___0;
          }

        while_break___0:;
        }
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
          if (!((int)tmpb == 48)) {
            goto while_break___2;
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

      tmpa = (unsigned char)*a;

      ;
      while (1) {

        tmpb = (unsigned char)*b;
        if (!((int)tmpb == thousands_sep___0)) {
          goto while_break___6;
        }
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
            return (tmp___0);
          }
        }
      }
      tmp = (int)tmpb - (int)tmpa;
      log_a = (size_t)0;

      if (!((unsigned int)tmpa - 48U <= 9U)) {
        goto while_break___7;
      }

      log_a++;

    while_break___7:
      log_b = (size_t)0;
      while (1) {

        if (!((unsigned int)tmpb - 48U <= 9U)) {
        }

        log_b++;
      }
    while_break___9:;
      if (log_a != log_b) {
        if (log_a < log_b) {

        } else {
        }
        return ((int __attribute__((__pure__)))tmp___1);
      }
      if (!log_a) {
      }
      return ((int __attribute__((__pure__)))tmp);
    } else {
      if ((int)tmpb == 45) {

        ;
        if ((int)tmpb == decimal_point___0) {

          b++;
          tmpb = (unsigned char)*b;
          if (!((int)tmpb == 48)) {
          }

        while_break___12:;
        }
        if ((unsigned int)tmpb - 48U <= 9U) {
        }

        if (!((int)tmpa == 48)) {
          if (!((int)tmpa == thousands_sep___0)) {
            goto while_break___13;
          }
        }
        a++;
        tmpa = (unsigned char)*a;

      while_break___13:;
        if ((int)tmpa == decimal_point___0) {

          a++;
          tmpa = (unsigned char)*a;

          ;
        }

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

      while_break___16:;

        if ((int)tmpa == (int)tmpb) {
          if (!((unsigned int)tmpa - 48U <= 9U)) {
            goto while_break___17;
          }
        } else {
        }

        a++;
        tmpa = (unsigned char)*a;

        ;

        ;

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
        while (1) {

          if (!((unsigned int)tmpa - 48U <= 9U)) {
            goto while_break___20;
          }

          tmpa = (unsigned char)*a;

          log_a++;
        }
      while_break___20:
        log_b = (size_t)0;
        while (1) {

          if (!((unsigned int)tmpb - 48U <= 9U)) {
            goto while_break___22;
          }

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

extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n,
                             FILE *__restrict __stream);

void readtokens0_init(struct Tokens *t);
_Bool readtokens0(FILE *in, struct Tokens *t);
void readtokens0_init(struct Tokens *t) {

  {

    _obstack_begin(&t->o_data, 0, 0, (void *(*)(long))(&malloc),
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

  struct obstack *__o1___0;
  struct obstack *__o___1;
  int __len;

  {
    __o = (struct obstack const *)(&t->o_data);

    __value = (void *)__o1->object_base;
    if ((unsigned long)__o1->next_free == (unsigned long)__value) {
    }

    __o1->next_free =
        tmp + (((__o1->next_free - tmp___0) + (long)__o1->alignment_mask) &
               (long)(~__o1->alignment_mask));
    if (__o1->next_free - (char *)__o1->chunk >
        __o1->chunk_limit - (char *)__o1->chunk) {
      __o1->next_free = __o1->chunk_limit;
    }

    s = (char const *)__value;

    *((void const **)__o1___0->next_free) = (void const *)s;

    if ((unsigned long)(__o___1->next_free + __len) >
        (unsigned long)__o___1->chunk_limit) {
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

      if (c == -1) {
        __o = (struct obstack const *)(&t->o_data);
        len = (size_t)((unsigned int)(__o->next_free - __o->object_base));
        if (len) {

          if ((unsigned long)(__o___0->next_free + 1) >
              (unsigned long)__o___0->chunk_limit) {
            _obstack_newchunk(__o___0, 1);
          }

          (__o___0->next_free)++;
          *tmp___0 = (char)'\000';
          save_token(t);
        }
        goto while_break;
      }
      __o___1 = &t->o_data;

      (__o___1->next_free)++;
      *tmp___1 = (char)c;
      if (c == 0) {
      }
    }
  while_break:

    __o1 = __o___2;

    __o1->next_free += sizeof(void const *);
    __o1___0 = &t->o_tok;

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

    __o1___1->object_base = __o1___1->next_free;
    t->tok_len = (size_t *)__value___0;

    if (tmp___6) {

    } else {
    }
    return ((_Bool)tmp___7);
  }
}

void isaac_seed(struct isaac_state *s);
void isaac_refill(struct isaac_state *s, isaac_word *result);
FILE *fopen_safer(char const *file, char const *mode);
static void randread_error(void const *file_name___3) {

  { abort(); }
}
static struct randread_source *simple_new(FILE *source,
                                          void const *handler_arg) {
  struct randread_source *s;
  struct randread_source *tmp;

  {
    tmp = (struct randread_source *)xmalloc(sizeof(*s));

    s->source = source;
    s->handler = &randread_error;

    return (s);
  }
}
static void get_nonce(void *buffer, size_t bufsize___1, size_t bytes_bound) {

  ssize_t seeded;
  int fd;
  int tmp;

  {

    seeded = (ssize_t)0;

    fd = tmp;

    return;
  }
}
struct randread_source *randread_new(char const *name, size_t bytes_bound) {

  FILE *source;
  struct randread_source *s;
  unsigned long tmp___0;

  {
    if (bytes_bound == 0UL) {

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
    isaac_refill(&isaac->state, isaac->data.w);
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

  int tmp___0;

  { return (tmp___0); }
}

__inline static isaac_word just(isaac_word a) {

  {}
}
__inline static isaac_word ind(isaac_word const *m, isaac_word x) {
  isaac_word tmp;

  {
    if (sizeof(*m) * 8UL == (unsigned long)(1 << 6)) {

    } else {
      tmp = (isaac_word) * (m + (x / (isaac_word)((1 << 6) / 8) &
                                 (unsigned long)((1 << 8) - 1)));
    }
    return (tmp);
  }
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

  isaac_word tmp___16;
  isaac_word tmp___17;
  isaac_word tmp___18;

  isaac_word tmp___30;

  isaac_word tmp___36;

  {

    m = s->m;
    r = result;
    while (1) {

      a = (tmp ^ tmp___0) + *(m + 128);
      x = *(m + 0);
      tmp___1 = ind((isaac_word const *)(s->m), x);
      y = (tmp___1 + a) + b;
      *(m + 0) = y;
      tmp___2 = ind((isaac_word const *)(s->m), y >> 8);
      b = just(tmp___2 + x);
      *(r + 0) = b;

      if (1 << 6 == 32) {

      } else {
      }
      a = (tmp___3 ^ tmp___6) + *(m + 129);
      x___0 = *(m + 1);
      tmp___7 = ind((isaac_word const *)(s->m), x___0);
      y___0 = (tmp___7 + a) + b;
      *(m + 1) = y___0;
      tmp___8 = ind((isaac_word const *)(s->m), y___0 >> 8);
      b = just(tmp___8 + x___0);
      *(r + 1) = b;

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
    }

    ;

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

  isaac_word tmp___10;

  isaac_word tmp___11;

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
    }

    b += s->m[i + 1];
    c += s->m[i + 2];
    d += s->m[i + 3];
    e += s->m[i + 4];
    f += s->m[i + 5];
    g += s->m[i + 6];

    a -= e;

    f ^= tmp___7 >> 9;

    b -= f;

    c -= g;

    b += c;
    d -= h;

    c += d;

    d += e;
    f -= b;
    c ^= e << 20;
    e += f;

    d ^= tmp___10 >> 17;

    s->m[i] = a;
    s->m[i + 1] = b;
    s->m[i + 2] = c;
    s->m[i + 3] = d;
    s->m[i + 4] = e;
    s->m[i + 5] = f;

    s->m[i + 7] = h;
    i += 8;

  while_break:

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

  unsigned char c;

  _Bool is_right_quote;

  size_t m;
  _Bool printable;

  mbstate_t mbstate;
  wchar_t w;

  size_t tmp___3;

  size_t ilim;
  int tmp___6;
  size_t tmp___7;

  {

  switch_break:

    if (tmp___6) {
    }

    c = (unsigned char)*(arg + i);
    if ((int)c == 0) {
    }

    if ((int)c == 12) {
    }

    if ((int)c == 59) {
      goto case_32;
    }

    if ((int)c == 96) {
    }

    if ((int)c == 37) {
      goto case_37;
    }

    if ((int)c == 44) {
      goto case_37;
    }

    if ((int)c == 49) {
    }
    if ((int)c == 50) {
    }

    if ((int)c == 54) {
    }

    if ((int)c == 57) {
      goto case_37;
    }

    if ((int)c == 81) {
      goto case_37;
    }

    if ((int)c == 83) {
      goto case_37;
    }

    if ((int)c == 85) {
      goto case_37;
    }
    if ((int)c == 86) {
    }
    if ((int)c == 87) {
    }

    if ((int)c == 90) {
      goto case_37;
    }

    if ((int)c == 100) {
    }

    if ((int)c == 102) {
      goto case_37;
    }
    if ((int)c == 103) {
    }

    if ((int)c == 107) {
      goto case_37;
    }

    if ((int)c == 109) {
      goto case_37;
    }

  case_0___0:

    if (flags & 4) {
      if (i + 2UL < argsize) {
        if ((int const) * (arg + (i + 1UL)) == 63) {
          if ((int const) * (arg + (i + 2UL)) == 33) {
          }
          if ((int const) * (arg + (i + 2UL)) == 39) {
          }

          if ((int const) * (arg + (i + 2UL)) == 45) {
          }

          if ((int const) * (arg + (i + 2UL)) == 62) {
          }

        case_33:

            ;

          ;

          ;

          ;

          ;
        }
      }
    }

    ;
    goto switch_break___0;

  case_12:

    goto c_and_shell_escape;

  c_and_shell_escape:

  case_32:

  case_37:

    if (unibyte_locale) {

    } else {

      tmp___3 = mbrtowc(&w, arg + (i + m), argsize - (i + m), &mbstate);

      ;
    }
    if (1UL < m) {
      goto _L___0;
    } else {
      if (backslash_escapes) {
        if (!printable) {
        _L___0:

          if (backslash_escapes) {

          } else {
          _L:
            if (is_right_quote) {

              if (len < buffersize) {
              }
              len++;

              is_right_quote = (_Bool)0;
            }
          }
          if (ilim <= i + 1UL) {
          }

          if (len < buffersize) {
            *(buffer + len) = (char)c;
          }

          c = (unsigned char)*(arg + i);

        while_break___17:;
          goto store_c;
        }
      }
    }
  switch_break___0:;

    ;
  store_c:

    if (len < buffersize) {
      *(buffer + len) = (char)c;
    }
    len++;

    ;

    i++;

  while_break___3:;

  force_outer_quoting_style:

    return (tmp___7);
  }
}
static char slot0[256];
static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options) {

  unsigned int n0;
  struct slotvec *sv;
  size_t n1;

  int tmp___0;
  struct slotvec *tmp___1;
  size_t size;
  char *val;

  size_t qsize;
  size_t tmp___2;

  {

    sv = slotvec;

    if (nslots <= n0) {
      n1 = (size_t)(n0 + 1U);

      if ((size_t)tmp___0 / sizeof(*sv) < n1) {
      }

      sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
      slotvec = sv;
    }
    size = (sv + n)->size;
    val = (sv + n)->val;

    qsize = tmp___2;
    if (size <= qsize) {

      (sv + n)->size = size;

      val = xcharalloc(size);
      (sv + n)->val = val;
    }

    return (val);
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {

  {}
}
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg,
                           size_t argsize) {

  {}
}

char *quotearg_colon(char const *arg) {
  char *tmp;

  { return (tmp); }
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

  size_t tmp___1;

  _Bool tmp___3;

  {
    if (iter->next_done) {
    }
    if (iter->in_shift) {
      goto with_shift;
    }

    if (tmp___3) {

      iter->cur.wc = (wchar_t) * (iter->cur.ptr);

    } else {

      iter->in_shift = (_Bool)1;
    with_shift:

      iter->cur.bytes =
          mbrtowc(&iter->cur.wc, iter->cur.ptr, tmp___1, &iter->state);
    }
  }
}
char const *program_name;

static unsigned long num_processors_via_affinity_mask(void) {
  cpu_set_t set;
  unsigned long count;
  int tmp;

  {

    if (tmp == 0) {
      count = (unsigned long)__sched_cpucount(sizeof(cpu_set_t),
                                              (cpu_set_t const *)(&set));
      if (count > 0UL) {
        return (count);
      }
    }
  }
}
unsigned long num_processors(enum nproc_query query) {

  unsigned long value;

  unsigned long nprocs___0;
  unsigned long tmp___5;

  long nprocs___2;
  long tmp___7;

  {
    if ((unsigned int)query == 2U) {

      query = (enum nproc_query)1;
    }
    if ((unsigned int)query == 1U) {
      tmp___5 = num_processors_via_affinity_mask();

      if (nprocs___0 > 0UL) {
        return (nprocs___0);
      }

    } else {

      nprocs___2 = tmp___7;
    }
  }
}

int(__attribute__((__nonnull__(1))) rpl_nanosleep)(
    struct timespec const *requested_delay, struct timespec *remaining_delay) {

  time_t limit;
  time_t seconds;

  int tmp___0;

  {
    if (requested_delay->tv_nsec < 0L) {

    } else {
    }

    if (!(limit < seconds)) {
    }

  while_break:

    return (tmp___0);
  }
}

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

  size_t size2;

  int tmp___3;

  {

    diff = strcoll(s1, s2);
    if (diff) {

    } else {
    }
    if (tmp___3) {
      goto while_break;
    }

    s1size -= size1;
    s2size -= size2;
    if (s1size == 0UL) {
      return (-(s2size != 0UL));
    }

  while_break:;
    return (diff);
  }
}
int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {

  int tmp___0;

  {
    if (s1size == s2size) {

    } else {
      tmp___0 = strcoll_loop(s1, s1size, s2, s2size);
      return (tmp___0);
    }
  }
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
  uint32_t A_save;

  uint32_t *tmp;
  uint32_t tmp___0;

  uint32_t tmp___2;

  uint32_t tmp___4;

  uint32_t tmp___6;
  uint32_t *tmp___7;
  uint32_t tmp___8;
  uint32_t *tmp___9;
  uint32_t tmp___10;
  uint32_t *tmp___11;
  uint32_t tmp___12;

  uint32_t tmp___14;

  uint32_t tmp___16;
  uint32_t *tmp___17;
  uint32_t tmp___18;
  uint32_t *tmp___19;
  uint32_t tmp___20;

  uint32_t tmp___22;
  uint32_t *tmp___23;
  uint32_t tmp___24;

  uint32_t tmp___26;
  uint32_t *tmp___27;
  uint32_t tmp___28;

  {
    words = (uint32_t const *)buffer;
    nwords = len / sizeof(uint32_t);
    endp = words + nwords;

    C = ctx->C;

    while (1) {

      if (!((unsigned long)words < (unsigned long)endp)) {
      }
      cwp = correct_words;

      while (1) {
        tmp = cwp;
        cwp++;
        tmp___0 = (uint32_t)*words;
        *tmp = tmp___0;
        A += ((D ^ (B & (C ^ D))) + tmp___0) + 3614090360U;
        words++;
        A = (A << 7) | (A >> 25);
      }

      ;

      cwp++;
      tmp___2 = (uint32_t)*words;

      words++;
      D = (D << 12) | (D >> 20);

      ;
      while (1) {

        cwp++;

        C += ((B ^ (D & (A ^ B))) + tmp___4) + 606105819U;
        words++;
      }

      ;

      cwp++;
      tmp___6 = (uint32_t)*words;

      words++;

      goto while_break___3;

    while_break___3:;

      tmp___8 = (uint32_t)*words;
      *tmp___7 = tmp___8;
      A += ((D ^ (B & (C ^ D))) + tmp___8) + 4118548399U;
      words++;
      A = (A << 7) | (A >> 25);

      goto while_break___4;

    while_break___4:;

      tmp___9 = cwp;
      cwp++;
      tmp___10 = (uint32_t)*words;

      D += ((C ^ (A & (B ^ C))) + tmp___10) + 1200080426U;
      words++;

      D += A;

      ;
      while (1) {

        cwp++;
        tmp___12 = (uint32_t)*words;
        *tmp___11 = tmp___12;

        words++;

        C += D;
      }

      ;

      cwp++;
      tmp___14 = (uint32_t)*words;

      words++;

      ;

      cwp++;
      tmp___16 = (uint32_t)*words;

      A += ((D ^ (B & (C ^ D))) + tmp___16) + 1770035416U;
      words++;
      A = (A << 7) | (A >> 25);

      ;

      tmp___18 = (uint32_t)*words;
      *tmp___17 = tmp___18;
      D += ((C ^ (A & (B ^ C))) + tmp___18) + 2336552879U;
      words++;
      D = (D << 12) | (D >> 20);
      D += A;

      ;
      while (1) {
        tmp___19 = cwp;

        tmp___20 = (uint32_t)*words;

        C += ((B ^ (D & (A ^ B))) + tmp___20) + 4294925233U;
        words++;
      }

      ;

      cwp++;
      tmp___22 = (uint32_t)*words;

      B += ((A ^ (C & (D ^ A))) + tmp___22) + 2304563134U;
      words++;

      B += C;
      goto while_break___11;

    while_break___11:;

      tmp___23 = cwp;

      tmp___24 = (uint32_t)*words;
      *tmp___23 = tmp___24;

      words++;
      A = (A << 7) | (A >> 25);

      ;

      tmp___26 = (uint32_t)*words;

      D += ((C ^ (A & (B ^ C))) + tmp___26) + 4254626195U;
      words++;
      D = (D << 12) | (D >> 20);
      D += A;
      goto while_break___13;

    while_break___13:;

      tmp___28 = (uint32_t)*words;
      *tmp___27 = tmp___28;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      A = (A << 6) | (A >> 26);

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      ;

      A += A_save;
    }
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

  unsigned short const **tmp___4;

  {
    p = string;

    width = 0;

    if (tmp___1 > 1UL) {

      if (!((unsigned long)p < (unsigned long)plimit)) {
      }

      if ((int const) * p == 34) {
      }

      if ((int const) * p == 39) {
      }

      if ((int const) * p == 43) {
        goto case_32;
      }

      if ((int const) * p == 45) {
      }

      if ((int const) * p == 47) {
        goto case_32;
      }

      if ((int const) * p == 49) {
      }
      if ((int const) * p == 50) {
      }

      if ((int const) * p == 54) {
        goto case_32;
      }
      if ((int const) * p == 55) {
      }

      if ((int const) * p == 60) {
      }
      if ((int const) * p == 61) {
      }

      if ((int const) * p == 71) {
      }

      if ((int const) * p == 73) {
        goto case_32;
      }

      if ((int const) * p == 80) {
      }

      if ((int const) * p == 82) {
      }
      if ((int const) * p == 83) {
        goto case_32;
      }

      if ((int const) * p == 94) {
      }
      if ((int const) * p == 95) {
        goto case_32;
      }
      if ((int const) * p == 97) {
      }

      if ((int const) * p == 99) {
      }
      if ((int const) * p == 100) {
      }

      if ((int const) * p == 103) {
      }

      if ((int const) * p == 109) {
      }
      if ((int const) * p == 110) {
      }
      if ((int const) * p == 111) {
        goto case_32;
      }

      if ((int const) * p == 113) {
      }
      if ((int const) * p == 114) {
      }

      if ((int const) * p == 116) {
      }

      if ((int const) * p == 118) {
      }

      if ((int const) * p == 120) {
      }

      if ((int const) * p == 125) {
      }

    case_32:
      p++;

      goto switch_break;

      while (1) {
        bytes = mbrtowc(&wc, p, (size_t)(plimit - p), &mbstate);
        if (bytes == 0xffffffffffffffffUL) {
          if (!(flags & 1)) {
            p++;
            width++;

          } else {
            return (-1);
          }
        }

        w = wcwidth(wc);
        if (w >= 0) {
          if (w > 2147483647 - width) {
            goto overflow;
          }
          width += w;
        } else {
          if (!(flags & 2)) {

          } else {
          }
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

    if ((int const) * (*tmp___4 + (int)c) & 16384) {
      if (width == 2147483647) {
        goto overflow;
      }
      width++;
    } else {
      if (!(flags & 2)) {

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

      iter2.cur.ptr = s2;

      while (1) {
        mbuiter_multi_next(&iter1);
        if (iter1.cur.wc_valid) {

        } else {
          tmp___13 = 1;
        }
        if (tmp___13) {
          mbuiter_multi_next(&iter2);
          if (iter2.cur.wc_valid) {
            if (iter2.cur.wc == 0) {

            } else {
            }
          } else {
            tmp___14 = 1;
          }
          if (!tmp___14) {
            goto while_break;
          }
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
          return (cmp);
        }
        iter1.cur.ptr += iter1.cur.bytes;

        iter2.cur.ptr += iter2.cur.bytes;
      }
    while_break:
      mbuiter_multi_next(&iter1);

      if (tmp___15) {
        return (1);
      }
      mbuiter_multi_next(&iter2);
      if (iter2.cur.wc_valid) {
        if (iter2.cur.wc == 0) {

        } else {
        }
      } else {
        tmp___16 = 1;
      }
      if (tmp___16) {
        return (-1);
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
      if ((int)c1 == 0) {
        goto while_break___0;
      }
      p1++;

      if (!((int)c1 == (int)c2)) {
      }

    while_break___0:;
      return ((int)c1 - (int)c2);
    }
  }
}

extern int optind;

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) pthread_mutex_init)(
    pthread_mutex_t *__mutex, pthread_mutexattr_t const *__mutexattr);

static char const *get_charset_aliases(void) {
  char const *cp;

  char const *base;

  int fd;
  FILE *fp;

  { return (cp); }
}
char const *locale_charset(void) {
  char const *codeset;
  char const *aliases;

  int tmp___2;

  {

    if (!((int const) * aliases != 0)) {
    }
    tmp___2 = strcmp(codeset, aliases);

  while_break:;

    return (codeset);
  }
}

struct heap *heap_alloc(int (*compare___0)(void const *, void const *),
                        size_t n_reserve);
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
    heap->count = (size_t)0;
    if (compare___0) {

    } else {
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

    if (k != 1UL) {
      tmp = (*compare___0)((void const *)*(array + k / 2UL),
                           (void const *)new_element);

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

static size_t raw_hasher(void const *data, size_t n) {

  {}
}

static size_t __attribute__((__pure__))
compute_bucket_size(size_t candidate, Hash_tuning const *tuning) {

  {
    if (!tuning->is_n_buckets) {
    }

    return ((size_t __attribute__((__pure__)))candidate);
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
    }

    if (!tmp) {
    }
    table___0->n_buckets = (size_t)compute_bucket_size(candidate, tuning);
    if (!table___0->n_buckets) {
    }
    table___0->bucket = (struct hash_entry *)calloc(
        table___0->n_buckets, sizeof(*(table___0->bucket)));
    if ((unsigned long)table___0->bucket == (unsigned long)((void *)0)) {
    }
    table___0->bucket_limit =
        (struct hash_entry const *)(table___0->bucket + table___0->n_buckets);

    table___0->hasher = hasher;
    table___0->comparator = comparator;

    return (table___0);
  fail:

    return ((Hash_table *)((void *)0));
  }
}
static struct hash_entry *allocate_entry(Hash_table *table___0) {
  struct hash_entry *new;

  {
    if (table___0->free_entry_list) {

    } else {
    }
    return (new);
  }
}

static void *hash_find_entry(Hash_table *table___0, void const *entry,
                             struct hash_entry **bucket_head, _Bool delete) {
  struct hash_entry *bucket;
  struct hash_entry *tmp;
  struct hash_entry *cursor;

  {
    tmp = safe_hasher((Hash_table const *)table___0, entry);
    bucket = tmp;

    cursor = bucket;

    ;
    return ((void *)0);
  }
}
static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {
  struct hash_entry *bucket;
  struct hash_entry *cursor;

  {
    bucket = src->bucket;
    while (1) {

    __Cont:
      bucket++;
    }
  while_break:;
    return ((_Bool)1);
  }
}

int hash_insert_if_absent(Hash_table *table___0, void const *entry,
                          void const **matched_ent) {
  void *data;
  struct hash_entry *bucket;

  {

    if ((unsigned long)data != (unsigned long)((void *)0)) {
    }

    bucket->data = (void *)entry;

    (table___0->n_buckets_used)++;
  }
}
void *(__attribute__((__warn_unused_result__)) hash_insert)(
    Hash_table *table___0, void const *entry) {
  void const *matched_ent;

  int tmp;

  void *tmp___1;

  {
    tmp = hash_insert_if_absent(table___0, entry, &matched_ent);

    return (tmp___1);
  }
}
void *hash_delete(Hash_table *table___0, void const *entry) {

  {}
}
size_t hash_pjw(void const *x, size_t tablesize) __attribute__((__pure__));

extern void(__attribute__((__nonnull__(1, 4))) qsort)(
    void *__base, size_t __nmemb, size_t __size,
    int (*__compar)(void const *, void const *));
extern int fseeko(FILE *__stream, __off_t __off, int __whence);

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

  int *tmp___4;

  int tmp___6;

  {
    tmp = fopen(file, mode);
    fp = tmp;
    if (fp) {
      tmp___0 = fileno(fp);

      if (0 <= fd) {
        if (fd <= 2) {

          if (f < 0) {

            rpl_fclose(fp);

            return ((FILE *)((void *)0));
          }

          if (tmp___6 != 0) {

          } else {
            fp = fdopen(f, mode);
            if (!fp) {

              tmp___4 = __errno_location();
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

  { ; }
}
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
    while (1) {

      if (!(s1_pos < s1_len)) {
        if (!(s2_pos < s2_len)) {
          goto while_break;
        }
      }
      first_diff = 0;

      if (s1_pos < s1_len) {
        tmp___3 = c_isdigit((int)*(s1 + s1_pos));
        if (tmp___3) {
        }
      } else {
      _L:
        if (s2_pos < s2_len) {

          if (tmp___4) {
            goto while_break___0;
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
        tmp___1 = order((unsigned char)*(s2 + s2_pos));
      }
      s2_c = tmp___2;
      if (s1_c != s2_c) {
        return ((int __attribute__((__pure__)))(s1_c - s2_c));
      }
      s1_pos++;
      s2_pos++;

    while_break___0:;
      while (1) {

        if (!((int const) * (s1 + s1_pos) == 48)) {
          goto while_break___1;
        }
        s1_pos++;
      }
    while_break___1:;

      s2_pos++;

      ;

      tmp___5 = c_isdigit((int)*(s1 + s1_pos));
      if (tmp___5) {
        tmp___6 = c_isdigit((int)*(s2 + s2_pos));

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

  char const *tmp___4;
  char const *tmp___5;
  int tmp___6;
  int tmp___7;

  {
    tmp = strcmp(s1, s2);

    if (simple_cmp == 0) {
    }

    if ((int const) * s1 != 46) {
    }
    if ((int const) * s1 == 46) {
    }
    s1_pos = s1;

    s1_suffix = match_suffix(&s1_pos);
    s2_suffix = match_suffix(&s2_pos);
    if (s1_suffix) {

    } else {
      tmp___4 = s1_pos;
    }
    s1_len = (size_t)(tmp___4 - s1);
    if (s2_suffix) {

    } else {
      tmp___5 = s2_pos;
    }
    s2_len = (size_t)(tmp___5 - s2);
    if (s1_suffix) {

    } else {
      if (s2_suffix) {

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

    } else {
      tmp___7 = result;
    }
    return (tmp___7);
  }
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"

int rpl_fflush(FILE *stream) {
  int tmp;

  int tmp___1;

  {
    if ((unsigned long)stream == (unsigned long)((void *)0)) {
      tmp = fflush(stream);
      return (tmp);
    } else {
    }

    tmp___1 = fflush(stream);
    return (tmp___1);
  }
}
int fd_safer(int fd) {

  {
    if (0 <= fd) {
    }
  }
}
extern int fcntl(int __fd, int __cmd, ...);
static int have_dupfd_cloexec = 0;
int rpl_fcntl(int fd, int action, ...) {

  int result;
  int target;

  int tmp___1;

  void *p;

  {

    if (0 <= have_dupfd_cloexec) {
      result = fcntl(fd, action, target);
      if (0 <= result) {

      } else {
      }
    } else {
    }

    result = fcntl(fd, action, p);

    return (result);
  }
}

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {

  int fd;
  int result;
  int tmp;

  {

    fd = fileno(fp);
    if (fd < 0) {
      tmp = fclose(fp);
    }

    result = fclose(fp);

    return (result);
  }
}

void fadvise(FILE *fp, fadvice_t advice) {

  {}
}

int dup_safer(int fd) {

  {}
}

extern char *optarg;
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 3))) pthread_create)(pthread_t *__restrict __newthread,
                                        pthread_attr_t const *__restrict __attr,
                                        void *(*__start_routine)(void *),
                                        void *__restrict __arg);
extern int pthread_join(pthread_t __th, void **__thread_return);

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1))) pthread_mutex_lock)(pthread_mutex_t *__mutex);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1))) pthread_mutex_unlock)(pthread_mutex_t *__mutex);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) pthread_cond_init)(
    pthread_cond_t *__restrict __cond,
    pthread_condattr_t const *__restrict __cond_attr);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) pthread_cond_destroy)(pthread_cond_t *__cond);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1))) pthread_cond_signal)(pthread_cond_t *__cond);
extern int(__attribute__((__nonnull__(1, 2))) pthread_cond_wait)(
    pthread_cond_t *__restrict __cond, pthread_mutex_t *__restrict __mutex);

extern size_t fwrite_unlocked(void const *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);

static int decimal_point;
static int thousands_sep;
static _Bool hard_LC_COLLATE;

static char eolchar = (char)'\n';
static _Bool blanks[256];

static size_t sort_size;
static char const **temp_dirs;

static _Bool reverse;

static int tab = 128;
static _Bool unique;

static struct keyfield *keylist;

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
static struct tempnode *volatile *temptail = &temphead;
static Hash_table *proctab;

static _Bool proctab_comparator(void const *e1, void const *e2) {
  struct tempnode const *n1;
  struct tempnode const *n2;

  {
    n1 = (struct tempnode const *)e1;
    n2 = (struct tempnode const *)e2;
    return ((_Bool)(n1->pid == n2->pid));
  }
}

static pid_t reap(pid_t pid) {
  int status;
  pid_t cpid;
  int tmp;
  pid_t tmp___0;
  pid_t tmp___1;

  {

    tmp___1 = waitpid(tmp___0, &status, tmp);
    cpid = tmp___1;

    return (cpid);
  }
}

static void cleanup(void) {
  struct tempnode const *node;

  {
    node = (struct tempnode const *)temphead;

    temphead = (struct tempnode *)((void *)0);
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

  char const *temp_dir;
  size_t len;
  size_t tmp;
  struct tempnode *node;
  struct tempnode *tmp___0;
  char *file;

  {
    temp_dir = *(temp_dirs + temp_dir_index);
    tmp = strlen(temp_dir);

    tmp___0 = (struct tempnode *)xmalloc(
        ((unsigned long)(&((struct tempnode *)0)->name) + len) +
        sizeof(slashbase));
    node = tmp___0;
    file = node->name;
    memcpy((void *)file, (void const *)temp_dir, len);

    fd = mkstemp_safer(file);
    if (0 <= fd) {
      *temptail = node;
    }

    if (fd < 0) {

      free((void *)node);
      node = (struct tempnode *)((void *)0);
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
    }
    return (fp);
  }
}
static void xfclose(FILE *fp, char const *file) {
  int tmp;

  int tmp___2;

  {
    tmp = fileno(fp);

    if (tmp___2 != 0) {
    }

    ;
  }
}

static pid_t pipe_fork(int *pipefds, size_t tries) {
  struct tempnode *saved_temphead;
  int saved_errno;

  pid_t pid;

  int tmp;
  int *tmp___0;

  int *tmp___2;

  {

    tmp = pipe(pipefds);
    if (tmp < 0) {
      return (-1);
    }

    while (1) {

      saved_temphead = (struct tempnode *)temphead;

      pid = fork();

      saved_errno = *tmp___0;

      if (0 <= pid) {
        goto while_break;
      } else {
      }
    }
  while_break:;
    if (pid < 0) {

      close(*(pipefds + 1));

    } else {
    }
    return (pid);
  }
}
static struct tempnode *maybe_create_temp(FILE **pfp,
                                          _Bool survive_fd_exhaustion) {
  int tempfd;
  struct tempnode *node;
  struct tempnode *tmp;

  {
    tmp = create_temp_file(&tempfd, survive_fd_exhaustion);

    if (!node) {
    }

    *pfp = fdopen(tempfd, "w");
    if (!*pfp) {
    }
  }
}
static struct tempnode *create_temp(FILE **pfp) {
  struct tempnode *tmp;

  {
    tmp = maybe_create_temp(pfp, (_Bool)0);
  }
}
static FILE *open_temp(struct tempnode *temp) {
  int tempfd;
  int pipefds[2];

  pid_t tmp;

  int *tmp___1;

  {

    tempfd = open((char const *)(temp->name), 0);
    if (tempfd < 0) {
      return ((FILE *)((void *)0));
    }
    tmp = pipe_fork(pipefds, (size_t)9);

    ;
  }
}

static void inittables(void) {

  {

  while_break:;
  }
}

static void specify_sort_size(int oi, char c, char const *s) {
  uintmax_t n;
  char *suffix;
  enum strtol_error e;
  enum strtol_error tmp;

  {
    tmp = xstrtoumax(s, &suffix, 10, &n, "EgGkKmMPtTYZ");

    if ((unsigned int)e == 0U) {
      if (n < sort_size) {
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

    if ((unsigned int)e != 0U) {
    }

    return (nthreads);
  }
}
static size_t default_sort_size(void) {

  double tmp;
  double total;
  double tmp___0;
  double mem;
  double tmp___1;
  struct rlimit rlimit;
  size_t size;
  int tmp___2;

  size_t tmp___5;

  {
    tmp = physmem_available();

    total = tmp___0;

    mem = tmp___1;
    size = 0xffffffffffffffffUL;
    tmp___2 = getrlimit((__rlimit_resource_t)2, &rlimit);

    if (mem < (double)size) {
      size = (size_t)mem;
    }

    return (tmp___5);
  }
}
static size_t size_bound;
static size_t sort_buffer_size(FILE *const *fps, size_t nfps,
                               char *const *files, size_t nfiles,
                               size_t line_bytes) {

  size_t i;
  struct stat st;
  off_t file_size;

  char *tmp;
  int tmp___0;

  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {

    while (1) {

      if (!(i < nfiles)) {
      }
      if (i < nfps) {
        tmp___0 = fileno((FILE *)*(fps + i));

      } else {

        if (tmp___6 == 0) {

        } else {
          tmp___4 = stat((char const *)*(files + i), &st);
        }
        tmp___7 = tmp___5;
      }
      if (tmp___7 != 0) {

        die((char const *)tmp, (char const *)*(files + i));
      }
      if ((st.st_mode & 61440U) == 32768U) {
        file_size = st.st_size;
      } else {
      }
    }
  while_break:;
  }
}
static void initbuf(struct buffer *buf___1, size_t line_bytes, size_t alloc) {
  size_t tmp;
  size_t tmp___0;

  {
    while (1) {
      alloc += sizeof(struct line) - alloc % sizeof(struct line);
      buf___1->buf = (char *)malloc(alloc);
      if (buf___1->buf) {
        goto while_break;
      }
      alloc /= 2UL;
    }
  while_break:
    buf___1->line_bytes = line_bytes;
    buf___1->alloc = alloc;

    buf___1->nlines = tmp___0;
    tmp = tmp___0;
    buf___1->left = tmp;
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
  size_t schar;
  size_t tmp;
  unsigned char tmp___0;

  size_t tmp___2;

  {
    ptr = (char *)line->text;
    lim = (ptr + line->length) - 1;
    sword = (size_t)key->sword;
    schar = (size_t)key->schar;
    if (tab != 128) {

      if ((unsigned long)ptr < (unsigned long)lim) {

        sword--;
        if (!tmp) {
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

    while_break:;
    } else {
      while (1) {

        if ((unsigned long)ptr < (unsigned long)lim) {

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

        ptr++;

      while_break___3:;
      }
    while_break___1:;
    }
    if (key->skipsblanks) {

    while_break___4:;
    }
    if ((unsigned long)lim < (unsigned long)(ptr + schar)) {

    } else {
    }
    return (ptr);
  }
}
static char *limfield(struct line const *line, struct keyfield const *key) {
  char *ptr;
  char *lim;
  size_t eword;

  size_t tmp;
  unsigned char tmp___0;
  unsigned char tmp___1;

  {
    ptr = (char *)line->text;
    lim = (ptr + line->length) - 1;

    if (tab != 128) {

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp = eword;
        eword--;

      } else {
      }

      if ((unsigned long)ptr < (unsigned long)lim) {
        if (!((int)*ptr != tab)) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      ptr++;

    while_break___0:;

      ;
    } else {

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp___0 = to_uchar(*ptr);
        if (!blanks[tmp___0]) {
          goto while_break___2;
        }
      } else {
        goto while_break___2;
      }
      ptr++;

    while_break___2:;

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp___1 = to_uchar(*ptr);

      } else {
        goto while_break___3;
      }
      ptr++;

    while_break___3:;

    while_break___1:;
    }

    return (ptr);
  }
}
static _Bool fillbuf___7(struct buffer *buf___1, FILE *fp, char const *file) {

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
  char *tmp___2;
  int tmp___3;

  int tmp___5;

  struct line *tmp___8;
  size_t line_alloc;

  {

    eol = eolchar;

    if (buf___1->eof) {
      return ((_Bool)0);
    }
    if (buf___1->used != buf___1->left) {
      memmove((void *)buf___1->buf,
              (void const *)((buf___1->buf + buf___1->used) - buf___1->left),
              buf___1->left);

      buf___1->nlines = (size_t)0;
    }

    ptr = buf___1->buf + buf___1->used;
    tmp = buffer_linelim((struct buffer const *)buf___1);
    linelim = tmp;
    line = linelim - buf___1->nlines;
    avail = (size_t)(((char *)linelim - buf___1->nlines * line_bytes) - ptr);
    if (buf___1->nlines) {

    } else {
      tmp___0 = buf___1->buf;
    }
    line_start = tmp___0;

    if (!(line_bytes + 1UL < avail)) {
    }
    readsize = (avail - 1UL) / (line_bytes + 1UL);
    tmp___1 = fread_unlocked((void *)ptr, (size_t)1, readsize, fp);
    bytes_read = tmp___1;
    ptrlim = ptr + bytes_read;
    avail -= bytes_read;
    if (bytes_read != readsize) {
      tmp___3 = ferror_unlocked(fp);
      if (tmp___3) {

        die((char const *)tmp___2, file);
      }
      tmp___5 = feof_unlocked(fp);
      if (tmp___5) {
        buf___1->eof = (_Bool)1;
        if ((unsigned long)buf___1->buf == (unsigned long)ptrlim) {
          return ((_Bool)0);
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

      avail -= line_bytes;

      line_start = ptr;
    }
  while_break___1:

  while_break___0:
    buf___1->used = (size_t)(ptr - buf___1->buf);
    tmp___8 = buffer_linelim((struct buffer const *)buf___1);
    buf___1->nlines = (size_t)(tmp___8 - line);
    if (buf___1->nlines != 0UL) {
      buf___1->left = (size_t)(ptr - line_start);

      return ((_Bool)1);
    }

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
    nonzero = 0;

    ch = (unsigned char)*tmp;
    if (!((unsigned int)ch - 48U <= 9U)) {
      goto while_break___0;
    }
    nonzero |= (int)ch - 48;

  while_break___0:;

    ;
    if ((int)ch == decimal_point) {
      while (1) {

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
      }
      return ((int __attribute__((__pure__)))tmp___1);
    } else {
      return ((int __attribute__((__pure__)))0);
    }
  }
}
static int human_numcompare(char const *a, char const *b) {
  unsigned char tmp;
  unsigned char tmp___0;
  int diff;
  int __attribute__((__pure__)) tmp___1;
  int __attribute__((__pure__)) tmp___2;

  int tmp___4;

  {
    while (1) {

      if (!blanks[tmp]) {
        goto while_break;
      }
    }
  while_break:;

    tmp___0 = to_uchar((char)*b);
    if (!blanks[tmp___0]) {
    }

  while_break___0:
    tmp___1 = find_unit_order(a);
    tmp___2 = find_unit_order(b);
    diff = (int)(tmp___1 - tmp___2);
    if (diff) {
      tmp___4 = diff;
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

  int tmp___7;

  {
    tmp = strtold(sa, &ea);
    a = tmp;

    b = tmp___0;

    return (tmp___7);
  }
}

static int compare_random(char *__restrict texta, size_t lena,
                          char *__restrict textb, size_t lenb) {
  int xfrm_diff;

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

  size_t tmp___6;

  int diff;
  int tmp___8;
  size_t tmp___9;

  {

    s[0] = s[1];
    if (hard_LC_COLLATE) {

      while (1) {

        if (bufsize___1 < guess_bufsize) {

          free(allocated);
          allocated = malloc(bufsize___1);
          buf___1 = (char *)allocated;
        }
        if ((unsigned long)texta < (unsigned long)lima) {
          tmp = xstrxfrm(buf___1, (char const *)texta, bufsize___1);

        } else {
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

            lenb = sizeb;

            goto while_break;
          }
        }

        md5_process_bytes((void const *)(buf___1 + sizea), sizeb, &s[1]);
      }
    while_break:;
    }

    tmp___8 =
        memcmp((void const *)(dig[0]), (void const *)(dig[1]), sizeof(dig[0]));
    diff = tmp___8;
    if (!diff) {
      if (!xfrm_diff) {
        if (lena < lenb) {

        } else {
        }
        xfrm_diff = memcmp((void const *)texta, (void const *)textb, tmp___9);
      }
      diff = xfrm_diff;
    }

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
static void key_warnings(struct keyfield const *gkey, _Bool gkey_only) {
  struct keyfield const *key;
  struct keyfield ugkey;

  size_t sword;

  _Bool tmp___23;

  {

    key = (struct keyfield const *)keylist;

  while_break:
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

  size_t tmp___2;
  unsigned char tmp___3;
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

  int tmp___27;

  {
    key = keylist;
    texta = (char *)a->keybeg;
    textb = (char *)b->keybeg;

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

              if (ignore) {

              } else {
                if (translate) {

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
                  while (1) {

                    if (!(i < lena)) {
                      goto while_break___0;
                    }
                    if (ignore) {

                    } else {
                    _L:

                      if (translate) {

                      } else {
                        *(ta + tmp) = *(texta + i);
                      }
                    }
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
                    if (ignore) {

                      if (!*(ignore + (int)tmp___4)) {
                      }
                    } else {
                    _L___0:

                      tlenb++;
                      if (translate) {
                        tmp___3 = to_uchar(*(textb + i));

                      } else {
                        *(tb + tmp___2) = *(textb + i);
                      }
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

              } else {
                if (key->general_numeric) {
                  diff = general_numcompare((char const *)ta, (char const *)tb);
                } else {
                  if (key->human_numeric) {

                  } else {
                  }
                }
              }

            } else {
              if (ignore) {
                if (translate) {

                  if ((unsigned long)texta < (unsigned long)lima) {

                  } else {
                  }
                  texta++;

                while_break___4:;

                  if ((unsigned long)textb < (unsigned long)limb) {
                    tmp___8 = to_uchar(*textb);
                    if (!*(ignore + (int)tmp___8)) {
                      goto while_break___5;
                    }
                  } else {
                  }
                  textb++;

                while_break___5:;

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

                  diff = ((unsigned long)texta < (unsigned long)lima) -
                         ((unsigned long)textb < (unsigned long)limb);
                  goto while_break___2;

                while_break___2:;
                } else {
                  while (1) {

                    while (1) {

                      if ((unsigned long)texta < (unsigned long)lima) {
                        tmp___13 = to_uchar(*texta);

                      } else {
                        goto while_break___8;
                      }
                      texta++;

                    while_break___8:;

                      if ((unsigned long)textb < (unsigned long)limb) {

                        if (!*(ignore + (int)tmp___14)) {
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

                } else {
                  if (lenb == 0UL) {

                  } else {
                    if (translate) {

                      if ((unsigned long)texta < (unsigned long)lima) {
                        if (!((unsigned long)textb < (unsigned long)limb)) {
                        }
                      } else {
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
      goto not_equal;
    }
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

      while_break___11:;

        textb++;

      while_break___12:;
      }
    }

  while_break:;
    return (0);
  greater:
    diff = 1;
  not_equal:

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

  char const *tmp;

  char *tmp___2;
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

        die((char const *)tmp___2, output_file);
      }
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

  size_t tmp___0;
  struct line const *line;
  struct line const *tmp___1;

  _Bool tmp___8;

  {
    tmp = xfopen(file_name___3, "r");

    key = (struct keyfield const *)keylist;

    initbuf(&buf___1, sizeof(struct line), tmp___0);
    temp.text = (char *)((void *)0);

    tmp___8 = fillbuf___7(&buf___1, fp, file_name___3);
    if (!tmp___8) {
      goto while_break;
    }

    line = tmp___1;

    line_number += buf___1.nlines;
    if (alloc < (size_t)line->length) {

      if (!alloc) {
        alloc = (size_t)line->length;
      }

      temp.text = (char *)xmalloc(alloc);
    }
    memcpy((void *)temp.text, (void const *)line->text, (size_t)line->length);
    temp.length = (size_t)line->length;

  while_break:
    xfclose(fp, file_name___3);
  }
}
static size_t open_input_files(struct sortfile *files, size_t nfiles,
                               FILE ***pfps) {
  FILE **fps;

  int i;
  FILE *tmp___0;
  FILE *tmp___1;

  {

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

  while_break:;
  }
}
static void mergefps(struct sortfile *files, size_t ntemps, size_t nfiles,
                     FILE *ofp, char const *output_file, FILE **fps) {
  struct buffer *buffer;
  struct buffer *tmp;

  struct line const *savedline;

  struct line const **cur;
  struct line const **tmp___0;
  struct line const **base;
  struct line const **tmp___1;
  size_t *ord;
  size_t *tmp___2;
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

    tmp___0 = (struct line const **)xnmalloc(nfiles, sizeof(*cur));
    cur = tmp___0;
    tmp___1 = (struct line const **)xnmalloc(nfiles, sizeof(*base));
    base = tmp___1;
    tmp___2 = (size_t *)xnmalloc(nfiles, sizeof(*ord));
    ord = tmp___2;

    initbuf(buffer + i, sizeof(struct line), tmp___3);
    tmp___5 = fillbuf___7(buffer + i, *(fps + i), (files + i)->name);
    if (tmp___5) {

      linelim = tmp___4;
      *(cur + i) = linelim - 1;
      *(base + i) = linelim - (buffer + i)->nlines;

    } else {
      xfclose(*(fps + i), (files + i)->name);

      nfiles--;

      ;
    }

    if (!(i < nfiles)) {
    }
    *(ord + i) = i;
    i++;

  while_break___1:
    i = (size_t)1;

    tmp___6 = compare(*(cur + *(ord + (i - 1UL))), *(cur + *(ord + i)));
    if (0 < tmp___6) {
      t = *(ord + (i - 1UL));
      *(ord + (i - 1UL)) = *(ord + i);
      *(ord + i) = t;
    }
    i++;

    ;

    ;

    smallest = *(cur + *(ord + 0));
    if (unique) {
      if (savedline) {

        if (tmp___7) {
        }
      }

    } else {
      write_line(smallest, ofp, output_file);
    }
    if ((unsigned long)*(base + *(ord + 0)) < (unsigned long)smallest) {

    } else {
    }

    ord0 = *(ord + 0);

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
        }
      } else {
        lo = probe + 1UL;
      }
    }
    probe = (lo + hi) / 2UL;

  while_break___8:
    count_of_smaller_lines = lo - 1UL;
    j = (size_t)0;

    *(ord + count_of_smaller_lines) = ord0;

  while_break___3:;

    free((void *)buffer);
  }
}
static size_t mergefiles(struct sortfile *files, size_t ntemps, size_t nfiles,
                         FILE *ofp, char const *output_file) {
  FILE **fps;
  size_t nopened;
  size_t tmp;

  {

    nopened = tmp;
    if (nopened < nfiles) {
    }
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
  struct line *tmp___2;
  size_t tmp___3;

  {
    tmp = (struct merge_node *)xmalloc((2UL * sizeof(*merge_tree)) * nthreads);
    merge_tree = tmp;
    root = merge_tree;
    tmp___2 = (struct line *)((void *)0);

    tmp___1 = tmp___2;
    root->end_lo = tmp___1;
    tmp___0 = tmp___1;

    root->lo = tmp___0;

    tmp___3 = nlines;
    root->nhi = tmp___3;
    root->nlo = tmp___3;
    root->parent = (struct merge_node *)((void *)0);

    pthread_mutex_init(&root->lock, (pthread_mutexattr_t const *)((void *)0));
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

      node->lo_child = (struct merge_node *)node_pool;
      tmp___4 =
          init_node(node, node_pool, lo, lo_threads, total_lines, (_Bool)1);

      node_pool = tmp___5;
    } else {
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

static void queue_init(struct merge_node_queue *queue, size_t nthreads) {

  {
    queue->priority_queue = heap_alloc(&compare_nodes, 2UL * nthreads);
    pthread_mutex_init(&queue->mutex, (pthread_mutexattr_t const *)((void *)0));
    pthread_cond_init(&queue->cond, (pthread_condattr_t const *)((void *)0));
  }
}
static void queue_insert(struct merge_node_queue *queue,
                         struct merge_node *node) {

  {
    pthread_mutex_lock(&queue->mutex);
    heap_insert(queue->priority_queue, (void *)node);
    node->queued = (_Bool)1;
    pthread_mutex_unlock(&queue->mutex);
    pthread_cond_signal(&queue->cond);
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

    node->queued = (_Bool)0;
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

  size_t tmp___0;

  int tmp___3;
  size_t tmp___4;

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

      *(node->dest) = dest;
    } else {

      if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
        if ((unsigned long)node->hi != (unsigned long)node->end_hi) {

          to_merge--;
          if (!tmp___4) {
            goto while_break___2;
          }
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

      while_break___3:;
      } else {
        if (node->nlo == merged_lo) {

          if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
            tmp___6 = to_merge;
            to_merge--;
            if (!tmp___6) {
              goto while_break___4;
            }
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
  _Bool hi_avail;
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    if (!node->queued) {
      lo_avail = (_Bool)(node->lo - node->end_lo != 0L);
      hi_avail = (_Bool)(node->hi - node->end_hi != 0L);
      if (lo_avail) {

        tmp___1 = tmp;
      } else {
        if (hi_avail) {
          if (!node->nlo) {
            tmp___0 = 1;
          } else {
          }
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
static void sortlines(struct line *__restrict lines, size_t nthreads,
                      size_t total_lines, struct merge_node *node,
                      struct merge_node_queue *queue, FILE *tfp,
                      char const *temp_output);
static void *sortlines_thread(void *data) {
  struct thread_args const *args;

  {

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

    lo_threads = nthreads / 2UL;
    hi_threads = nthreads - lo_threads;
    args.lines = (struct line *)lines;

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

  struct tempnode *tempcopy;
  _Bool is_stdin;

  _Bool same;
  struct stat instat;

  int tmp___2;
  int tmp___3;
  int tmp___4;

  int tmp___6;

  {

    if (!(i < nfiles)) {
      goto while_break;
    }

    if (outfile) {

    } else {
    _L___0:
      if (!got_outstat) {

        if (tmp___2 != 0) {
          goto while_break;
        }
      }
      if (is_stdin) {

      } else {
        tmp___4 = stat((files + i)->name, &instat);
      }

      same = (_Bool)tmp___6;
    }
    if (same) {
      if (!tempcopy) {
      }
      (files + i)->name = (char const *)(tempcopy->name);
      (files + i)->temp = tempcopy;
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

  size_t num_merged;
  size_t tmp___0;
  size_t tmp___1;
  size_t tmp___2;

  FILE **fps;
  size_t nopened;
  size_t tmp___8;
  FILE *ofp;
  FILE *tmp___9;

  FILE *tfp___1;
  struct tempnode *temp___1;
  size_t tmp___13;
  size_t tmp___14;

  {

    in = (size_t)0;

    if (!((size_t)nmerge <= nfiles - in)) {
      goto while_break___0;
    }

    if (ntemps < (size_t)nmerge) {

    } else {
    }
    tmp___1 = mergefiles(files + in, tmp___0, (size_t)nmerge, tfp,
                         (char const *)(temp->name));
    num_merged = tmp___1;
    if (ntemps < num_merged) {

    } else {
    }
    ntemps -= tmp___2;
    (files + out)->name = (char const *)(temp->name);
    (files + out)->temp = temp;
    in += num_merged;
    out++;

  while_break___0:
    remainder = nfiles - in;
    cheap_slots = (unsigned long)nmerge - out % (unsigned long)nmerge;

    memmove((void *)(files + out), (void const *)(files + in),
            (nfiles - in) * sizeof(*files));
    ntemps += out;
    nfiles -= in - out;

  while_break:
    avoid_trashing_input(files, ntemps, nfiles, output_file);

    nopened = tmp___8;
    if (nopened == nfiles) {
      tmp___9 = stream_open(output_file, "w");

      if (ofp) {

        goto while_break___1;
      }

    } else {
    }

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

  size_t mult;
  size_t tmp___1;
  struct line *line;
  struct tempnode *tmp___2;
  struct merge_node_queue queue;
  struct merge_node *merge_tree;
  struct merge_node *tmp___3;
  struct merge_node *root;
  _Bool tmp___4;

  struct sortfile *tempfiles;
  struct sortfile *tmp___5;

  {
    ntemps = (size_t)0;

    buf___1.alloc = (size_t)0;

    if (!nfiles) {
      goto while_break;
    }
    file = (char const *)*files;
    tmp = xfopen(file, "r");
    fp = tmp;
    if (nthreads > 1UL) {

      mult = (size_t)1;

      bytes_per_line = mult * sizeof(struct line);
    } else {
    }
    if (!buf___1.alloc) {

      initbuf(&buf___1, bytes_per_line, tmp___1);
    }

    files++;
    nfiles--;

    tmp___4 = fillbuf___7(&buf___1, fp, file);
    if (!tmp___4) {
      goto while_break___1;
    }
    if (buf___1.eof) {
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
    }
    xfclose(tfp, temp_output);
    if (output_file_created) {
      goto finish;
    }

  while_break___1:
    xfclose(fp, file);

  while_break:;
  finish:
    free((void *)buf___1.buf);
    if (!output_file_created) {

      tempfiles = tmp___5;

      merge(tempfiles, ntemps, ntemps, output_file);
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

    if (!*p) {
      goto while_break;
    }

  while_break:
    *p = key;
    key->next = (struct keyfield *)((void *)0);
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

    if ((int const) * s == 77) {
    }
    if ((int const) * s == 110) {
    }

    if ((unsigned int)blanktype == 0U) {
      key->skipsblanks = (_Bool)1;
    } else {
    }

    goto switch_break;

    goto switch_break;

    goto switch_break;

    goto switch_break;
  case_77:

    goto switch_break;
  case_110:

    goto switch_break;

  switch_break:

      ;
  }
}
static struct keyfield *key_init(struct keyfield *key) {

  {}
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

  _Bool obsolete_usage;

  char **files;
  char *files_from;
  struct Tokens tok;
  char const *outfile;
  struct lconv const *locale;
  struct lconv const *tmp___1;
  size_t i;

  int oi;
  size_t tmp___3;
  int tmp___4;
  _Bool minus_pos_usage;
  int tmp___5;
  int tmp___6;
  char const *optarg1;
  int tmp___7;
  char *tmp___8;
  char *tmp___9;
  size_t tmp___10;
  ptrdiff_t tmp___11;
  char str[2];

  size_t tmp___15;

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
  _Bool tmp___46;
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

    files_from = (char *)((void *)0);
    outfile = (char const *)((void *)0);

    i = (size_t)0;

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
          if (c == 1) {
            goto case_1;
          }

          if (c == 99) {
          }
          if (c == 67) {
          }

          if (c == 130) {
            goto case_130;
          }

          if (c == 109) {
          }
          if (c == 132) {
            goto case_132;
          }

          if (c == 115) {
            goto case_115;
          }
          if (c == 83) {
          }
          if (c == 116) {
            goto case_116;
          }
          if (c == 84) {
          }

          goto switch_default;
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

          c = (int)sort_types[tmp___11];

          set_ordering((char const *)(str), &gkey, (enum blanktype)2);

        case_99:

        case_130:

          files_from = optarg;

        case_107:
          key = key_init(&key_buf);
          s = parse_field_count((char const *)optarg, &key->sword,
                                "invalid number at field start");

          if (!tmp___15) {
          }

          if ((int const) * s != 44) {

          } else {
            s = parse_field_count(s + 1, &key->eword,
                                  "invalid number after \',\'");

            s = (char const *)set_ordering(s, key, (enum blanktype)1);
          }

          insertkey(key);

        case_109:

        case_132:

        case_115:

          goto switch_break;
        case_83:

        case_116:

        case_84:

          nthreads = specify_nthreads(oi, (char)c, (char const *)optarg);

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

          tmp___31 = gettext("cannot open %s for reading");

          error(2, *tmp___32, (char const *)tmp___31, tmp___30);
        }
      }

      tmp___36 = readtokens0(stream, &tok);

      if (tok.n_tok) {

        files = tok.tok;
        nfiles = tok.n_tok;

        if (!(i___0 < nfiles)) {
        }

        if (tmp___42 == 0) {
          tmp___38 = quote((char const *)*(files + i___0));

        } else {
        }
        i___0++;

      while_break___3:;
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
    if (!keylist) {

      if (!tmp___46) {

        insertkey(&gkey);
      }
    }

    reverse = gkey.reverse;

    if (mergeonly) {

      merge(sortfiles, (size_t)0, nfiles, outfile);
    } else {
      if (!nthreads) {

        if (np < 8UL) {
          nthreads = np;
        } else {
          nthreads = (size_t)8;
        }
      }
      nthreads_max = 0xffffffffffffffffUL / (2UL * sizeof(struct merge_node));

      sort((char *const *)files, nfiles, outfile, nthreads);
    }

    exit(0);
  }
}
