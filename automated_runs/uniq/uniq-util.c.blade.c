

typedef unsigned long size_t;

typedef struct hash_table Hash_table;

typedef size_t hashint;

typedef unsigned long uintmax_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef struct __dirstream DIR;
enum numbered_backup_result {
  BACKUP_IS_SAME_LENGTH = 0,
  BACKUP_IS_LONGER = 1,
  BACKUP_IS_NEW = 2
};
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;

enum argv_iter_err {
  AI_ERR_OK = 1,
  AI_ERR_EOF = 2,
  AI_ERR_MEM = 3,
  AI_ERR_READ = 4
};

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

struct option {};

typedef unsigned long uint_least64_t;
typedef struct timezone *__restrict __timezone_ptr_t;
typedef uint_least64_t isaac_word;

struct linebuffer {
  size_t size;
  size_t length;
  char *buffer;
};

enum Skip_field_option_type { SFO_NONE = 0, SFO_OBSOLETE = 1, SFO_NEW = 2 };

extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));

extern struct _IO_FILE *stdout;

extern struct _IO_FILE *stdin;

void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));

__inline static void *x2nrealloc(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {

    n = 128UL / s;

    { tmp = xrealloc(p, n * s); }
    return (tmp);
  }
}

void *xrealloc(void *p, size_t n) {

  {

    { p = realloc(p, n); }

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

void xalloc_die(void) {

  {
    {}
  }
}

char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {

  {
    {}
  }
}
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg,
                           size_t argsize) {

  {
    {}
  }
}

char *quotearg_colon(char const *arg) {

  {
    {}
  }
}

char const *quote_n(int n, char const *name) {

  {
    {}
  }
}
char const *quote(char const *name) {

  {
    {}
  }
}

int memcoll(char *s1, size_t s1len, char *s2, size_t s2len) {
  int diff;

  { return (diff); }
}

char const *locale_charset(void) {

  {
    {}

    {}
    {

      /* CIL Label */
      ;
    }
  }
}

void initbuffer(struct linebuffer *linebuffer) {

  {
    { memset((void *)linebuffer, 0, sizeof(*linebuffer)); }
  }
}
struct linebuffer *readlinebuffer_delim(struct linebuffer *linebuffer,
                                        FILE *stream, char delimiter) {
  int c;
  char *buffer;
  char *p;
  char *end;

  size_t oldsize;
  char *tmp___1;

  {
    {
      buffer = linebuffer->buffer;
      p = linebuffer->buffer;
      end = buffer + linebuffer->size;
    }

    {
      while (1) {
        /* CIL Label */
        ;
        { c = getc_unlocked(stream); }
        if (c == -1) {

          return ((struct linebuffer *)((void *)0));

          {}
        }
        if ((unsigned long)p == (unsigned long)end) {
          {
            oldsize = linebuffer->size;
            buffer = (char *)x2realloc((void *)buffer, &linebuffer->size);
            p = buffer + oldsize;
            linebuffer->buffer = buffer;
          }
        }
        tmp___1 = p;
        p++;
        *tmp___1 = (char)c;
        if (!(c != (int)delimiter)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    linebuffer->length = (size_t)(p - buffer);
  }
}

FILE *freopen_safer(char const *name, char const *mode, FILE *f) {

  int saved_errno;

  int *tmp___6;

  {
    {}
    {

      { /* CIL Label */
      }

      { /* CIL Label */
      }

      {
          /* CIL Label */

      }

      /* CIL Label */

      /* CIL Label */
      ;
    }

    {}

  _L___0:

  {}

  _L:

  {}

    {
      f = freopen((char const * /* __restrict  */)name,
                  (char const * /* __restrict  */)mode,
                  (FILE * /* __restrict  */)f);
    }

    {
      tmp___6 = __errno_location();
      saved_errno = *tmp___6;
    }
  }
}

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {

  int result;

  {
    {}

    {}

    { result = fclose(fp); }
  }
}

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

static size_t skip_fields;
static size_t skip_chars;
static size_t check_chars;

static _Bool output_first_repeated;

static _Bool ignore_case;

static struct option const longopts[12] = {
    {"count", 0, (int *)((void *)0), 'c'},
    {"repeated", 0, (int *)((void *)0), 'd'},
    {"all-repeated", 2, (int *)((void *)0), 'D'},
    {"ignore-case", 0, (int *)((void *)0), 'i'},
    {"unique", 0, (int *)((void *)0), 'u'},
    {"skip-fields", 1, (int *)((void *)0), 'f'},
    {"skip-chars", 1, (int *)((void *)0), 's'},
    {"check-chars", 1, (int *)((void *)0), 'w'},
    {"zero-terminated", 0, (int *)((void *)0), 'z'},
    {"help", 0, (int *)((void *)0), -130},
    {"version", 0, (int *)((void *)0), -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};

void usage(int status) {

  {

    { exit(status); }
  }
}

static char *__attribute__((__pure__))
find_field(struct linebuffer const *line) {

  size_t i;

  size_t tmp___3;

  {

    i = (size_t)0;

    {

    while_break: /* CIL Label */
        ;
    }

    tmp___3 = skip_chars;

    i += tmp___3;
    return ((char * /* __attribute__((__pure__)) */)(line->buffer + i));
  }
}
static _Bool different(char *old, char *new, size_t oldlen, size_t newlen) {
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;

  {

    if (ignore_case) {

      return ((_Bool)tmp___0);
    } else {

      {}

      if (oldlen != newlen) {
        tmp___3 = 1;
      } else {
        { tmp___2 = memcmp((void const *)old, (void const *)new, oldlen); }
        if (tmp___2) {
          tmp___3 = 1;
        } else {
        }
      }
      return ((_Bool)tmp___3);
    }
  }
}

static void check_file(char const *infile, char const *outfile,
                       char delimiter) {
  struct linebuffer lb1;
  struct linebuffer lb2;
  struct linebuffer *thisline;
  struct linebuffer *prevline;

  FILE *tmp___1;

  char *prevfield;
  size_t prevlen;
  char *thisfield;
  size_t thislen;
  struct linebuffer *tmp___5;
  struct linebuffer *_tmp;
  _Bool tmp___6;

  uintmax_t match_count;
  _Bool first_delimiter;
  struct linebuffer *tmp___8;

  {
    {}

    { tmp___1 = freopen_safer(infile, "r", stdin); }

    {}

    {

      prevline = &lb2;
      initbuffer(thisline);
      initbuffer(prevline);
    }

    {
      while (1) {
        /* CIL Label */
        ;
        {}

        { tmp___5 = readlinebuffer_delim(thisline, stdin, delimiter); }
        if ((unsigned long)tmp___5 == (unsigned long)((struct linebuffer *)0)) {
          goto while_break;
        }
        {
          thisfield = (char *)find_field((struct linebuffer const *)thisline);
          thislen =
              (thisline->length - 1UL) - (size_t)(thisfield - thisline->buffer);
        }
        if (prevline->length == 0UL) {
          goto _L;
        } else {
          { tmp___6 = different(thisfield, prevfield, thislen, prevlen); }
          if (tmp___6) {
          _L: {
            fwrite_unlocked((void const * /* __restrict  */)thisline->buffer,
                            sizeof(char), thisline->length,
                            (FILE * /* __restrict  */)stdout);
          }
            {

              /* CIL Label */
              ;
              _tmp = prevline;
              prevline = thisline;
              thisline = _tmp;

            while_break___0: /* CIL Label */
                ;
            }
            prevfield = thisfield;
            prevlen = thislen;
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }

    goto _L___2;

  _L___2: {
    match_count = (uintmax_t)0;
    first_delimiter = (_Bool)1;
    tmp___8 = readlinebuffer_delim(prevline, stdin, delimiter);
  }

    {}
    {

      /* CIL Label */
      ;
    }
    {}

    {}

    {}
  }
}
int main(int argc, char **argv) {
  int optc;

  enum Skip_field_option_type skip_field_option_type;

  char const *file[2];
  char delimiter;

  int tmp___2;
  int tmp___3;

  int tmp___6;

  {
    { delimiter = (char)'\n'; }
    {

      /* CIL Label */
      ;

    _L___3: {
      optc = getopt_long(argc, (char *const *)argv, "-0123456789Dcdf:is:uw:z",
                         longopts, (int *)((void *)0));
    }
      if (optc == -1) {

        goto while_break;

      } else {
        {

          /* CIL Label */

          {}

        _L___1:

        {}

          file[tmp___6] = (char const *)optarg;

          goto switch_break;
        case_48: /* CIL Label */
        case_49: /* CIL Label */
        case_50: /* CIL Label */
        case_51: /* CIL Label */
        case_52: /* CIL Label */
        case_53: /* CIL Label */
        case_54: /* CIL Label */
        case_55: /* CIL Label */
        case_56: /* CIL Label */
        case_57: /* CIL Label */

          /* CIL Label */

          /* CIL Label */

          /* CIL Label */

          goto switch_break;
        case_102: { /* CIL Label */
          skip_field_option_type = (enum Skip_field_option_type)2;
          skip_fields = size_opt((char const *)optarg,
                                 "invalid number of fields to skip");
        }
          goto switch_break;
        case_105: /* CIL Label */
          ignore_case = (_Bool)1;
          goto switch_break;
        case_115: { /* CIL Label */
          skip_chars =
              size_opt((char const *)optarg, "invalid number of bytes to skip");
        }
          goto switch_break;
        case_117: /* CIL Label */
          output_first_repeated = (_Bool)0;
          goto switch_break;
        case_119: { /* CIL Label */
          check_chars = size_opt((char const *)optarg,
                                 "invalid number of bytes to compare");
        }
          goto switch_break;
        case_122: /* CIL Label */
          delimiter = (char)'\000';
          goto switch_break;
        case_neg_130: { /* CIL Label */
          usage(0);
        }
          goto switch_break;
        case_neg_131: { /* CIL Label */
          version_etc(stdout, "uniq", "GNU coreutils", Version,
                      "Richard M. Stallman", "David MacKenzie",
                      (char *)((void *)0));
          exit(0);
        }
          goto switch_break;
        switch_default: { /* CIL Label */
          usage(1);
        }
        switch_break: /* CIL Label */
            ;
        }
      }

    while_break: /* CIL Label */
        ;
    }

    { check_file(file[0], file[1], delimiter); }
  }
}
