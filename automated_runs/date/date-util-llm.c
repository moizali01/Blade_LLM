typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef unsigned long __ino_t;
typedef long __off_t;
typedef __builtin_va_list __gnuc_va_list;

typedef long __off64_t;
typedef long __ssize_t;
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

  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;

  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;

  signed char _vtable_offset;

  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;

  void *__pad4;
  size_t __pad5;
};
typedef __ssize_t ssize_t;
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
struct allocator;
struct allocator;
struct allocator;
struct allocator {
  void *(*allocate)(size_t);

  void (*free)(void *);
  void (*die)(size_t);
};
struct option {};
typedef long intmax_t;
typedef long __time_t;
typedef long __syscall_slong_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef unsigned int __gid_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
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

  struct timespec st_mtim;
  struct timespec st_ctim;
};
typedef int wchar_t;

typedef unsigned int wint_t;
typedef long __suseconds_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
typedef __time_t time_t;

struct __anonstruct___mbstate_t_22 {
  int __count;
};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
typedef __mbstate_t mbstate_t;
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
typedef int __clockid_t;

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

typedef __off_t off_t;
typedef struct timezone *__restrict __timezone_ptr_t;
struct quoting_options;
struct quoting_options;
struct quoting_options;
struct quoting_options {
  enum quoting_style style;
  int flags;
  unsigned int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
  char const *left_quote;
};
struct slotvec {
  size_t size;
  char *val;
};
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
struct __anonstruct_parser_control_32 {
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
  relative_time rel;
  _Bool timespec_seen;
  _Bool rels_seen;
  size_t dates_seen;
  size_t days_seen;
  size_t local_zones_seen;
  size_t dsts_seen;
  size_t times_seen;
  size_t zones_seen;
  table local_time_zone_table[3];
};
typedef struct __anonstruct_parser_control_32 parser_control;
union YYSTYPE;
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

enum Time_spec {
  TIME_SPEC_DATE = 0,
  TIME_SPEC_SECONDS = 1,
  TIME_SPEC_NS = 2,
  TIME_SPEC_HOURS = 3,
  TIME_SPEC_MINUTES = 4
};

int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));

_Bool c_isalpha(int c) __attribute__((__const__));
_Bool c_isspace(int c) __attribute__((__const__));

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
_Bool c_isspace(int c) __attribute__((__const__));
_Bool c_isspace(int c) {
  int tmp;

  {
    if (c == 32) {
      tmp = 1;
    } else {
      if (c == 9) {
        tmp = 1;
      } else {
        if (c == 10) {

        } else {
          if (c == 11) {
            tmp = 1;
          } else {
            if (c == 12) {
              tmp = 1;
            } else {
              if (c == 13) {
                tmp = 1;
              } else {
                tmp = 0;
              }
            }
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

int c_toupper(int c) {
  int tmp;

  {
    if (c >= 97) {
      if (c <= 122) {
        tmp = (c - 97) + 65;
      } else {
      }
    } else {
      tmp = c;
    }
    return (tmp);
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
char *last_component(char const *name) __attribute__((__pure__));
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
__attribute__((__noreturn__)) void xalloc_die(void);
void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
__inline void *xnmalloc(size_t n, size_t s)
    __attribute__((__malloc__, __alloc_size__(1, 2)));
__inline void *xnmalloc(size_t n, size_t s)
    __attribute__((__malloc__, __alloc_size__(1, 2)));
__inline void *xnmalloc(size_t n, size_t s) {
  int tmp;
  void *tmp___0;

  {

    if ((size_t)tmp / s < n) {
      xalloc_die();
    }
    tmp___0 = xmalloc(n * s);
  }
}
char *xcharalloc(size_t n) {
  void *tmp;
  void *tmp___0;
  void *tmp___1;

  {
    if (sizeof(char) == 1UL) {
      tmp = xmalloc(n);

    } else {
    }
    return ((char *)tmp___1);
  }
}

char *last_component(char const *name) {
  char const *base;
  char const *p;
  _Bool saw_slash;

  {

    while (1) {
    }
  while_break:
    p = base;

  while_break___0:;
  }
}
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(
    size_t __size) __attribute__((__malloc__));

char const *simple_backup_suffix;
void (*argmatch_die)(void);
ptrdiff_t __xargmatch_internal(char const *context, char const *arg,
                               char const *const *arglist, char const *vallist,
                               size_t valsize, void (*exit_fn)(void));

extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);

extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest,
                                          char const *__restrict __src);

ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize)
    __attribute__((__pure__));

extern struct _IO_FILE *stderr;

extern int putc_unlocked(int __c, FILE *__stream);
extern int fputs_unlocked(char const *__restrict __s,
                          FILE *__restrict __stream);

char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char const *quote_n(int n, char const *arg);

static void __argmatch_die(void) {

  {}
}
void (*argmatch_die)(void) = &__argmatch_die;
ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize)
    __attribute__((__pure__));
ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize) {
  size_t i;
  size_t arglen;
  ptrdiff_t matchind;

  size_t tmp___0;
  int tmp___1;

  {
    matchind = (ptrdiff_t)-1;

    while (1) {

      if (!*(arglist + i)) {
        goto while_break;
      }

      if (!tmp___1) {
        tmp___0 = strlen((char const *)*(arglist + i));
        if (tmp___0 == arglen) {

        } else {
          if (matchind == -1L) {
            matchind = (ptrdiff_t)i;
          } else {
            if ((unsigned long)vallist == (unsigned long)((void *)0)) {

            } else {
            }
          }
        }
      }
      i++;
    }
  while_break:;
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

    format = (char const *)tmp___1;
    tmp___2 = quote_n(1, context);
    tmp___3 = quotearg_n_style(0, (enum quoting_style)6, value);
    error(0, 0, format, tmp___3, tmp___2);
    return;
  }
}
void argmatch_valid(char const *const *arglist, char const *vallist,
                    size_t valsize) {
  size_t i;

  char *tmp;

  {

  while_break:
    putc_unlocked('\n', stderr);
    return;
  }
}
ptrdiff_t __xargmatch_internal(char const *context, char const *arg,
                               char const *const *arglist, char const *vallist,
                               size_t valsize, void (*exit_fn)(void)) {
  ptrdiff_t res;
  ptrdiff_t tmp;

  {

    res = tmp;

    argmatch_invalid(context, arg, res);
    argmatch_valid(arglist, vallist, valsize);
    (*exit_fn)();
    return ((ptrdiff_t)-1);
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
struct allocator const stdlib_allocator;
extern __attribute__((__nothrow__)) void *(__attribute__((
    __warn_unused_result__, __leaf__)) realloc)(void *__ptr, size_t __size);
struct allocator const stdlib_allocator = {
    (void *(*)(size_t))(&malloc), (void *(*)(void *, size_t))(&realloc),
    (void (*)(void *))(&free), (void (*)(size_t))((void *)0)};
extern struct _IO_FILE *stdin;
extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream);

extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strchr)(char const *__s, int __c)
    __attribute__((__pure__));
extern
    __attribute__((__nothrow__,
                   __noreturn__)) void(__attribute__((__leaf__)) abort)(void);
int volatile exit_failure;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
extern struct _IO_FILE *stdout;

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    tmp = malloc(n);

    return (p);
  }
}
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
void *xrealloc(void *p, size_t n) {

  { return (p); }
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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
__attribute__((__noreturn__)) void xalloc_die(void);
void xalloc_die(void) {
  char *tmp;

  { abort(); }
}

char const version_etc_copyright[47];

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
struct timespec get_stat_mtime(struct stat const *st) {

  {
  }
}
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
void gettime(struct timespec *ts);

extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrtowc)(
    wchar_t *__restrict __pwc, char const *__restrict __s, size_t __n,
    mbstate_t *__restrict __p);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern __attribute__((__nothrow__))
time_t(__attribute__((__leaf__)) mktime)(struct tm *__tp);
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) strftime)(
    char *__restrict __s, size_t __maxsize, char const *__restrict __format,
    struct tm const *__restrict __tp);

__inline static int iso_week_days(int yday, int wday) {
  int big_enough_multiple_of_7;

  {

    return (
        ((yday - (((yday - wday) + 4) + big_enough_multiple_of_7) % 7) + 4) -
        1);
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern int close(int __fd);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern __attribute__((__nothrow__)) int
sprintf(char *__restrict __s, char const *__restrict __format, ...);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern __attribute__((__nothrow__)) int(
    __attribute__((__leaf__)) ferror_unlocked)(FILE *__stream);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
int settime(struct timespec const *ts);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern __attribute__((__noreturn__)) void _exit(int __status);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(
    FILE *__stream);
int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) gettimeofday)(struct timeval *__restrict __tv,
                                             __timezone_ptr_t __tz);

char *quotearg_char_mem(char const *arg, size_t argsize, char ch);
struct quoting_options quote_quoting_options;

static struct quoting_options default_quoting_options;

static struct quoting_options
quoting_options_from_style(enum quoting_style style) {
  struct quoting_options o;
  unsigned int tmp;

  {
    o.style = (enum quoting_style)0;
    o.flags = 0;

    while (1) {

      if (!(!(tmp >= 8U))) {
      }
    }
  while_break:
    o.left_quote = (char const *)((void *)0);

    if ((unsigned int)style == 8U) {
    }

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

    quote_string_len = (size_t)0;

    tmp = __ctype_get_mb_cur_max();

    if ((unsigned int)quoting_style == 4U) {
      goto case_4;
    }
    if ((unsigned int)quoting_style == 3U) {
      goto case_3;
    }
    if ((unsigned int)quoting_style == 5U) {
      goto case_5;
    }
    if ((unsigned int)quoting_style == 6U) {
      goto case_6;
    }

    if ((unsigned int)quoting_style == 2U) {
      goto case_2;
    }

  case_4:
    quoting_style = (enum quoting_style)3;
    elide_outer_quotes = (_Bool)1;
  case_3:
    if (!elide_outer_quotes) {
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)'\"';
        }
        len++;
        goto while_break;
      }
    while_break:;
    }

    quote_string = "\"";
    quote_string_len = (size_t)1;
    goto switch_break;
  case_5:

    goto switch_break;
  case_6:
    if ((unsigned int)quoting_style != 8U) {
      left_quote = gettext_quote("`", quoting_style);
      right_quote = gettext_quote("\'", quoting_style);
    }
    if (!elide_outer_quotes) {
      quote_string = left_quote;
      while (1) {

        while (1) {

          goto while_break___1;
        }
      while_break___1:
        quote_string++;
      }
    while_break___0:;
    }

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
      }

      ;
    }
    quote_string = "\'";
    quote_string_len = (size_t)1;
    goto switch_break;
  case_0:
    elide_outer_quotes = (_Bool)0;
    goto switch_break;
  switch_default:

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

      if (backslash_escapes) {
        if (quote_string_len) {
          if (i + quote_string_len <= argsize) {
            tmp___0 = memcmp((void const *)(arg + i),
                             (void const *)quote_string, quote_string_len);
          }
        }
      }
      c = (unsigned char)*(arg + i);

      if ((int)c == 63) {
      }
      if ((int)c == 7) {
        goto case_7___0;
      }
      if ((int)c == 8) {
        goto case_8___0;
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

      if ((int)c == 125) {
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
      if ((int)c == 34) {
        goto case_32;
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
      }
      if ((int)c == 60) {
      }
      if ((int)c == 61) {
        goto case_32;
      }
      if ((int)c == 62) {
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
      }
      if ((int)c == 53) {
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

      if ((int)c == 65) {
        goto case_37;
      }
      if ((int)c == 66) {
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
      }
      if ((int)c == 76) {
        goto case_37;
      }
      if ((int)c == 77) {
        goto case_37;
      }
      if ((int)c == 78) {
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
      if ((int)c == 85) {
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
      }
      if ((int)c == 90) {
        goto case_37;
      }
      if ((int)c == 93) {
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
      if ((int)c == 101) {
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
      if ((int)c == 105) {
        goto case_37;
      }
      if ((int)c == 106) {
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
      if ((int)c == 112) {
        goto case_37;
      }

      if ((int)c == 114) {
        goto case_37;
      }
      if ((int)c == 115) {
        goto case_37;
      }
      if ((int)c == 116) {
        goto case_37;
      }

      if ((int)c == 118) {
        goto case_37;
      }
      if ((int)c == 119) {
        goto case_37;
      }
      if ((int)c == 120) {
        goto case_37;
      }

      if ((int)c == 122) {
        goto case_37;
      }
      goto switch_default___2;
    case_0___0:
      if (backslash_escapes) {

      while_break___4:;
        if (i + 1UL < argsize) {
          if (48 <= (int)*(arg + (i + 1UL))) {
            if ((int const) * (arg + (i + 1UL)) <= 57) {
              while (1) {

                if (len < buffersize) {
                  *(buffer + len) = (char)'0';
                }
                len++;
              }
            while_break___5:;
              while (1) {

                if (len < buffersize) {
                }
                len++;
                goto while_break___6;
              }
            while_break___6:;
            }
          }
        }
        c = (unsigned char)'0';
      } else {
      }

    case_63:
      if ((unsigned int)quoting_style == 2U) {
        goto case_2___0;
      }
      if ((unsigned int)quoting_style == 3U) {
        goto case_3___0;
      }

    case_2___0:

      goto switch_break___1;
    case_3___0:
      if (flags & 4) {
      }
      goto switch_break___1;
    switch_default___1:
      goto switch_break___1;
    switch_break___1:;
      goto switch_break___0;
    case_7___0:

      goto c_escape;
    case_8___0:
      esc = (unsigned char)'b';

    case_12:
      esc = (unsigned char)'f';

    case_10:
      esc = (unsigned char)'n';

    case_13:

      goto c_and_shell_escape;
    case_9:
      esc = (unsigned char)'t';

    case_11:

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

      if (!tmp___1) {
      }
    case_35:
      if (i != 0UL) {
        goto switch_break___0;
      }
    case_32:
      if ((unsigned int)quoting_style == 2U) {
      }
      goto switch_break___0;
    case_39___0:
      if ((unsigned int)quoting_style == 2U) {

        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)'\'';
          }
          len++;
          goto while_break___11;
        }
      while_break___11:;

      while_break___12:;
        while (1) {

          len++;
          goto while_break___13;
        }
      while_break___13:;
      }
      goto switch_break___0;
    case_37:
      goto switch_break___0;
    switch_default___2:
      if (unibyte_locale) {
        m = (size_t)1;

        printable = (_Bool)(((int const) * (*tmp___2 + (int)c) & 16384) != 0);
      } else {
        memset((void *)(&mbstate), 0, sizeof(mbstate));
        m = (size_t)0;

        while (1) {
          tmp___3 = mbrtowc(&w, arg + (i + m), argsize - (i + m), &mbstate);
          bytes = tmp___3;

          tmp___5 = mbsinit((mbstate_t const *)(&mbstate));
          if (tmp___5) {
            goto while_break___14;
          }
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
                  }
                while_break___18:;
                  while (1) {

                    if (len < buffersize) {
                      *(buffer + len) = (char)(48 + ((int)c >> 6));
                    }
                    len++;
                    goto while_break___19;
                  }
                while_break___19:;
                  while (1) {

                    if (len < buffersize) {
                      *(buffer + len) = (char)(48 + (((int)c >> 3) & 7));
                    }
                    len++;
                    goto while_break___20;
                  }
                while_break___20:
                  c = (unsigned char)(48 + ((int)c & 7));
                } else {
                  goto _L;
                }
              } else {
              _L:
                if (is_right_quote) {
                  while (1) {

                    len++;
                  }
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

              c = (unsigned char)*(arg + i);
            }
          while_break___17:;
            goto store_c;
          }
        }
      }
    switch_break___0:;
      if (backslash_escapes) {
        goto _L___3;
      } else {
        if (elide_outer_quotes) {
        _L___3:
          if (quote_these_too) {
            if (!(*(quote_these_too + (unsigned long)c / (sizeof(int) * 8UL)) &
                  (unsigned int const)(1 << (unsigned long)c %
                                                (sizeof(int) * 8UL)))) {
              goto _L___2;
            }
          } else {
          }
        } else {
        _L___2:
          if (!is_right_quote) {
            goto store_c;
          }
        }
      }
    store_escape:
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
      while (1) {

        if (len < buffersize) {
        }
      }
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
      if (!elide_outer_quotes) {
        while (1) {

          if (!*quote_string) {
            goto while_break___25;
          }
          while (1) {

            goto while_break___26;
          }
        while_break___26:
          quote_string++;
        }
      while_break___25:;
      }
    }
    if (len < buffersize) {
    }

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

  size_t qsize;

  int *tmp___3;

  {

    if (n < 0) {
    }
    if (nslots <= n0) {
      n1 = (size_t)(n0 + 1U);
      preallocated = (_Bool)((unsigned long)sv == (unsigned long)(&slotvec0));

      if ((size_t)tmp___0 / sizeof(*sv) < n1) {
        xalloc_die();
      }
      if (preallocated) {

      } else {
        tmp___1 = sv;
      }
      sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
      slotvec = sv;
      if (preallocated) {
        *sv = slotvec0;
      }

      nslots = (unsigned int)n1;
    }

    if (size <= qsize) {

      (sv + n)->size = size;
      if ((unsigned long)val != (unsigned long)(slot0)) {
        free((void *)val);
      }
      val = xcharalloc(size);
    }

    return (val);
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;

  char *tmp___0;

  {

    tmp___0 = quotearg_n_options(n, arg, (size_t)-1,
                                 (struct quoting_options const *)(&o));
  }
}

struct quoting_options quote_quoting_options = {(enum quoting_style)6,
                                                0,
                                                {0U},
                                                (char const *)((void *)0),
                                                (char const *)((void *)0)};

char const *quote_n(int n, char const *arg) {
  char const *tmp;

  {}
}
char const *quote(char const *arg) {

  {}
}

void set_program_name(char const *argv0);
extern char *program_invocation_name;
extern char *program_invocation_short_name;

char const *program_name = (char const *)((void *)0);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern __attribute__((__nothrow__))
time_t(__attribute__((__leaf__)) time)(time_t *__timer);
extern __attribute__((__nothrow__)) struct tm *(
    __attribute__((__leaf__)) localtime)(time_t const *__timer);
_Bool posixtime(time_t *p, char const *s, unsigned int syntax_bits);

static int year(struct tm *tm, int const *digit_pair, size_t n,
                unsigned int syntax_bits) {
  time_t now;
  struct tm *tmp;

  {
    if (n == 1UL) {
      goto case_1;
    }
    if (n == 2UL) {
      goto case_2;
    }
    if (n == 0UL) {
      goto case_0;
    }
    goto switch_default;
  case_1:
    tm->tm_year = (int)*digit_pair;
    if (*(digit_pair + 0) <= 68) {

      tm->tm_year += 100;
    }
    goto switch_break;
  case_2:
    if (!(syntax_bits & 4U)) {
      return (1);
    }
    tm->tm_year = (int)((*(digit_pair + 0) * 100 + *(digit_pair + 1)) - 1900);
    goto switch_break;
  case_0:
    time(&now);
    tmp = localtime((time_t const *)(&now));
    if (!tmp) {
      return (1);
    }
    tm->tm_year = tmp->tm_year;
    goto switch_break;
  switch_default:

  switch_break:;
    return (0);
  }
}
static int posix_time_parse(struct tm *tm, char const *s,
                            unsigned int syntax_bits) {
  char const *dot;
  int pair[6];
  int *p;
  size_t i;
  size_t s_len;
  size_t tmp;
  size_t len;
  size_t tmp___0;
  int tmp___1;
  int *tmp___2;
  int *tmp___3;
  int *tmp___4;
  int *tmp___5;
  int tmp___6;
  int seconds;

  {
    dot = (char const *)((void *)0);
    tmp = strlen(s);
    s_len = tmp;
    if (syntax_bits & 8U) {
      dot = (char const *)strchr(s, '.');
      if (dot) {
        tmp___0 = (size_t)(dot - s);
      } else {
      }
    } else {
      tmp___0 = s_len;
    }
    len = tmp___0;
    if (len != 8UL) {
      if (len != 10UL) {
      }
    }
    if (dot) {
      if (!(syntax_bits & 8U)) {
        return (1);
      }
      if (s_len - len != 3UL) {
        return (1);
      }
    }
    i = (size_t)0;
    while (1) {

      if (!(i < len)) {
        goto while_break;
      }
      if (!((unsigned int)*(s + i) - 48U <= 9U)) {
      }
    }
  while_break:
    len /= 2UL;
    i = (size_t)0;
    while (1) {

      if (!(i < len)) {
        goto while_break___0;
      }
      pair[i] = (10 * (int)((int const) * (s + 2UL * i) - 48) +
                 (int)*(s + (2UL * i + 1UL))) -
                48;
      i++;
    }
  while_break___0:
    p = pair;
    if (syntax_bits & 1U) {
      tmp___1 = year(tm, (int const *)p, len - 4UL, syntax_bits);
      if (tmp___1) {
        return (1);
      }
      p += len - 4UL;
      len = (size_t)4;
    }
    tmp___2 = p;
    p++;
    tm->tm_mon = *tmp___2 - 1;
    tmp___3 = p;
    p++;
    tm->tm_mday = *tmp___3;
    tmp___4 = p;
    p++;
    tm->tm_hour = *tmp___4;
    tmp___5 = p;
    p++;
    tm->tm_min = *tmp___5;
    len -= 4UL;

    if (!dot) {

    } else {
      dot++;

      seconds =
          (10 * (int)((int const) * (dot + 0) - 48) + (int)*(dot + 1)) - 48;
      tm->tm_sec = seconds;
    }
    return (0);
  }
}
_Bool posixtime(time_t *p, char const *s, unsigned int syntax_bits) {
  struct tm tm0;
  struct tm tm1;
  struct tm const *tm;
  time_t t;
  int tmp;
  time_t dummy;
  char buf___1[16];

  char *tmp___0;
  _Bool tmp___1;

  {
    tmp = posix_time_parse(&tm0, s, syntax_bits);
    if (tmp) {
      return ((_Bool)0);
    }
    tm1 = tm0;

    t = mktime(&tm1);
    if (t != -1L) {
      tm = (struct tm const *)(&tm1);
    } else {
      tm = (struct tm const *)localtime((time_t const *)(&t));
      if (!tm) {
        return ((_Bool)0);
      }
    }

    *p = t;
    return ((_Bool)1);
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
_Bool parse_datetime(struct timespec *result, char const *p,
                     struct timespec const *now);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(2), __leaf__)) setenv)(char const *__name, char const *__value,
                                       int __replace);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) unsetenv)(char const *__name);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

static int yylex(union YYSTYPE *lvalp, parser_control *pc);

static long time_zone_hhmm(parser_control *pc, textint s, long mm);
static void digits_to_date_time(parser_control *pc, textint text_int) {

  {
    if (pc->dates_seen) {
      if (!pc->year.digits) {
        if (!pc->rels_seen) {
          if (pc->times_seen) {
            pc->year = text_int;
          } else {
            if (2UL < text_int.digits) {
              pc->year = text_int;
            } else {
              goto _L___1;
            }
          }
        } else {
          goto _L___1;
        }
      } else {
        goto _L___1;
      }
    } else {
    _L___1:
      if (4UL < text_int.digits) {
        (pc->dates_seen)++;
        pc->day = text_int.value % 100L;
        pc->month = (text_int.value / 100L) % 100L;
        pc->year.value = text_int.value / 10000L;
        pc->year.digits = text_int.digits - 4UL;
      } else {
        (pc->times_seen)++;
        if (text_int.digits <= 2UL) {
          pc->hour = text_int.value;
          pc->minutes = 0L;
        } else {
          pc->hour = text_int.value / 100L;
          pc->minutes = text_int.value % 100L;
        }
        pc->seconds.tv_sec = (__time_t)0;
        pc->seconds.tv_nsec = (__syscall_slong_t)0;
        pc->meridian = 2;
      }
    }
    return;
  }
}
static void apply_relative_time(parser_control *pc, relative_time rel,
                                int factor) {

  {
    pc->rel.ns += (long)factor * rel.ns;
    pc->rel.seconds += (long_time_t)factor * rel.seconds;
    pc->rel.minutes += (long)factor * rel.minutes;
    pc->rel.hour += (long)factor * rel.hour;
    pc->rel.day += (long)factor * rel.day;
    pc->rel.month += (long)factor * rel.month;
    pc->rel.year += (long)factor * rel.year;

    return;
  }
}
static void set_hhmmss(parser_control *pc, long hour, long minutes, time_t sec,
                       long nsec) {

  {
    pc->hour = hour;
    pc->minutes = minutes;
    pc->seconds.tv_sec = sec;
    pc->seconds.tv_nsec = nsec;
  }
}
static yytype_uint8 const yytranslate[278] = {
    (yytype_uint8 const)0,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)26,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)27,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)25, (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)23, (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)24, (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)1,  (yytype_uint8 const)2,
    (yytype_uint8 const)3,  (yytype_uint8 const)4,  (yytype_uint8 const)5,
    (yytype_uint8 const)6,  (yytype_uint8 const)7,  (yytype_uint8 const)8,
    (yytype_uint8 const)9,  (yytype_uint8 const)10, (yytype_uint8 const)11,
    (yytype_uint8 const)12, (yytype_uint8 const)13, (yytype_uint8 const)14,
    (yytype_uint8 const)15, (yytype_uint8 const)16, (yytype_uint8 const)17,
    (yytype_uint8 const)18, (yytype_uint8 const)19, (yytype_uint8 const)20,
    (yytype_uint8 const)21, (yytype_uint8 const)22};
static yytype_uint8 const yyr1[92] = {
    (yytype_uint8 const)0,  (yytype_uint8 const)28, (yytype_uint8 const)29,
    (yytype_uint8 const)29, (yytype_uint8 const)30, (yytype_uint8 const)31,
    (yytype_uint8 const)31, (yytype_uint8 const)32, (yytype_uint8 const)32,
    (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32,
    (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32,
    (yytype_uint8 const)32, (yytype_uint8 const)33, (yytype_uint8 const)34,
    (yytype_uint8 const)35, (yytype_uint8 const)35, (yytype_uint8 const)35,
    (yytype_uint8 const)35, (yytype_uint8 const)36, (yytype_uint8 const)36,
    (yytype_uint8 const)36, (yytype_uint8 const)37, (yytype_uint8 const)37,
    (yytype_uint8 const)38, (yytype_uint8 const)39, (yytype_uint8 const)39,
    (yytype_uint8 const)40, (yytype_uint8 const)40, (yytype_uint8 const)40,
    (yytype_uint8 const)40, (yytype_uint8 const)40, (yytype_uint8 const)40,
    (yytype_uint8 const)40, (yytype_uint8 const)41, (yytype_uint8 const)41,
    (yytype_uint8 const)41, (yytype_uint8 const)41, (yytype_uint8 const)42,
    (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42,
    (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42,
    (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)43,
    (yytype_uint8 const)44, (yytype_uint8 const)44, (yytype_uint8 const)44,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)46,
    (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)46,
    (yytype_uint8 const)47, (yytype_uint8 const)48, (yytype_uint8 const)48,
    (yytype_uint8 const)49, (yytype_uint8 const)49, (yytype_uint8 const)50,
    (yytype_uint8 const)50, (yytype_uint8 const)51, (yytype_uint8 const)52,
    (yytype_uint8 const)53, (yytype_uint8 const)53};
static yytype_uint8 const yyr2[92] = {
    (yytype_uint8 const)0, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)2, (yytype_uint8 const)0,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)3,
    (yytype_uint8 const)2, (yytype_uint8 const)4, (yytype_uint8 const)6,
    (yytype_uint8 const)1, (yytype_uint8 const)2, (yytype_uint8 const)4,
    (yytype_uint8 const)6, (yytype_uint8 const)0, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)2,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)2,
    (yytype_uint8 const)2, (yytype_uint8 const)3, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)2,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)3,
    (yytype_uint8 const)5, (yytype_uint8 const)3, (yytype_uint8 const)3,
    (yytype_uint8 const)2, (yytype_uint8 const)4, (yytype_uint8 const)2,
    (yytype_uint8 const)3, (yytype_uint8 const)1, (yytype_uint8 const)3,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)2,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)2,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)2,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)2,
    (yytype_uint8 const)0, (yytype_uint8 const)2};
static yytype_uint8 const yydefact[114] = {
    (yytype_uint8 const)5,  (yytype_uint8 const)0,  (yytype_uint8 const)0,
    (yytype_uint8 const)2,  (yytype_uint8 const)3,  (yytype_uint8 const)85,
    (yytype_uint8 const)87, (yytype_uint8 const)84, (yytype_uint8 const)86,
    (yytype_uint8 const)4,  (yytype_uint8 const)82, (yytype_uint8 const)83,
    (yytype_uint8 const)1,  (yytype_uint8 const)56, (yytype_uint8 const)59,
    (yytype_uint8 const)65, (yytype_uint8 const)68, (yytype_uint8 const)73,
    (yytype_uint8 const)62, (yytype_uint8 const)81, (yytype_uint8 const)37,
    (yytype_uint8 const)35, (yytype_uint8 const)28, (yytype_uint8 const)0,
    (yytype_uint8 const)0,  (yytype_uint8 const)30, (yytype_uint8 const)0,
    (yytype_uint8 const)88, (yytype_uint8 const)0,  (yytype_uint8 const)0,
    (yytype_uint8 const)31, (yytype_uint8 const)6,  (yytype_uint8 const)7,
    (yytype_uint8 const)16, (yytype_uint8 const)8,  (yytype_uint8 const)21,
    (yytype_uint8 const)9,  (yytype_uint8 const)10, (yytype_uint8 const)12,
    (yytype_uint8 const)11, (yytype_uint8 const)49, (yytype_uint8 const)13,
    (yytype_uint8 const)52, (yytype_uint8 const)74, (yytype_uint8 const)53,
    (yytype_uint8 const)14, (yytype_uint8 const)15, (yytype_uint8 const)38,
    (yytype_uint8 const)29, (yytype_uint8 const)0,  (yytype_uint8 const)45,
    (yytype_uint8 const)54, (yytype_uint8 const)57, (yytype_uint8 const)63,
    (yytype_uint8 const)66, (yytype_uint8 const)69, (yytype_uint8 const)60,
    (yytype_uint8 const)39, (yytype_uint8 const)36, (yytype_uint8 const)90,
    (yytype_uint8 const)32, (yytype_uint8 const)75, (yytype_uint8 const)76,
    (yytype_uint8 const)78, (yytype_uint8 const)79, (yytype_uint8 const)80,
    (yytype_uint8 const)77, (yytype_uint8 const)55, (yytype_uint8 const)58,
    (yytype_uint8 const)64, (yytype_uint8 const)67, (yytype_uint8 const)70,
    (yytype_uint8 const)61, (yytype_uint8 const)40, (yytype_uint8 const)18,
    (yytype_uint8 const)47, (yytype_uint8 const)90, (yytype_uint8 const)0,
    (yytype_uint8 const)0,  (yytype_uint8 const)22, (yytype_uint8 const)89,
    (yytype_uint8 const)71, (yytype_uint8 const)72, (yytype_uint8 const)33,
    (yytype_uint8 const)0,  (yytype_uint8 const)51, (yytype_uint8 const)44,
    (yytype_uint8 const)0,  (yytype_uint8 const)0,  (yytype_uint8 const)34,
    (yytype_uint8 const)43, (yytype_uint8 const)48, (yytype_uint8 const)50,
    (yytype_uint8 const)27, (yytype_uint8 const)25, (yytype_uint8 const)41,
    (yytype_uint8 const)0,  (yytype_uint8 const)17, (yytype_uint8 const)46,
    (yytype_uint8 const)91, (yytype_uint8 const)19, (yytype_uint8 const)90,
    (yytype_uint8 const)0,  (yytype_uint8 const)23, (yytype_uint8 const)26,
    (yytype_uint8 const)0,  (yytype_uint8 const)0,  (yytype_uint8 const)25,
    (yytype_uint8 const)42, (yytype_uint8 const)25, (yytype_uint8 const)20,
    (yytype_uint8 const)24, (yytype_uint8 const)0,  (yytype_uint8 const)25};
static yytype_int8 const yydefgoto[26] = {
    (yytype_int8 const)-1,  (yytype_int8 const)2,   (yytype_int8 const)3,
    (yytype_int8 const)4,   (yytype_int8 const)31,  (yytype_int8 const)32,
    (yytype_int8 const)33,  (yytype_int8 const)34,  (yytype_int8 const)35,
    (yytype_int8 const)103, (yytype_int8 const)104, (yytype_int8 const)36,
    (yytype_int8 const)37,  (yytype_int8 const)38,  (yytype_int8 const)39,
    (yytype_int8 const)40,  (yytype_int8 const)41,  (yytype_int8 const)42,
    (yytype_int8 const)43,  (yytype_int8 const)44,  (yytype_int8 const)9,
    (yytype_int8 const)10,  (yytype_int8 const)11,  (yytype_int8 const)45,
    (yytype_int8 const)46,  (yytype_int8 const)93};
static yytype_int8 const yypact[114] = {
    (yytype_int8 const)38,  (yytype_int8 const)27,  (yytype_int8 const)77,
    (yytype_int8 const)-93, (yytype_int8 const)46,  (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)62,
    (yytype_int8 const)-93, (yytype_int8 const)82,  (yytype_int8 const)-3,
    (yytype_int8 const)66,  (yytype_int8 const)3,   (yytype_int8 const)74,
    (yytype_int8 const)-4,  (yytype_int8 const)83,  (yytype_int8 const)84,
    (yytype_int8 const)75,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)71,  (yytype_int8 const)-93,
    (yytype_int8 const)93,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)78,  (yytype_int8 const)72,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)25,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)21,  (yytype_int8 const)19,  (yytype_int8 const)79,
    (yytype_int8 const)80,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)81,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)85,  (yytype_int8 const)86,  (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-6,  (yytype_int8 const)76,
    (yytype_int8 const)17,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)87,
    (yytype_int8 const)69,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)88,  (yytype_int8 const)89,  (yytype_int8 const)-1,
    (yytype_int8 const)-93, (yytype_int8 const)18,  (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)69,  (yytype_int8 const)91};
static yytype_int8 const yypgoto[26] = {
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)20,
    (yytype_int8 const)-68, (yytype_int8 const)-27, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)60,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-92, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)43};
static yytype_uint8 const yytable[113] = {
    (yytype_uint8 const)79,  (yytype_uint8 const)67,  (yytype_uint8 const)68,
    (yytype_uint8 const)69,  (yytype_uint8 const)70,  (yytype_uint8 const)71,
    (yytype_uint8 const)72,  (yytype_uint8 const)58,  (yytype_uint8 const)73,
    (yytype_uint8 const)100, (yytype_uint8 const)107, (yytype_uint8 const)74,
    (yytype_uint8 const)75,  (yytype_uint8 const)101, (yytype_uint8 const)110,
    (yytype_uint8 const)76,  (yytype_uint8 const)49,  (yytype_uint8 const)50,
    (yytype_uint8 const)101, (yytype_uint8 const)102, (yytype_uint8 const)113,
    (yytype_uint8 const)77,  (yytype_uint8 const)59,  (yytype_uint8 const)78,
    (yytype_uint8 const)61,  (yytype_uint8 const)62,  (yytype_uint8 const)63,
    (yytype_uint8 const)64,  (yytype_uint8 const)65,  (yytype_uint8 const)66,
    (yytype_uint8 const)61,  (yytype_uint8 const)62,  (yytype_uint8 const)63,
    (yytype_uint8 const)64,  (yytype_uint8 const)65,  (yytype_uint8 const)66,
    (yytype_uint8 const)101, (yytype_uint8 const)101, (yytype_uint8 const)92,
    (yytype_uint8 const)111, (yytype_uint8 const)90,  (yytype_uint8 const)91,
    (yytype_uint8 const)106, (yytype_uint8 const)112, (yytype_uint8 const)88,
    (yytype_uint8 const)111, (yytype_uint8 const)5,   (yytype_uint8 const)6,
    (yytype_uint8 const)7,   (yytype_uint8 const)8,   (yytype_uint8 const)88,
    (yytype_uint8 const)13,  (yytype_uint8 const)14,  (yytype_uint8 const)15,
    (yytype_uint8 const)16,  (yytype_uint8 const)17,  (yytype_uint8 const)18,
    (yytype_uint8 const)19,  (yytype_uint8 const)20,  (yytype_uint8 const)21,
    (yytype_uint8 const)22,  (yytype_uint8 const)1,   (yytype_uint8 const)23,
    (yytype_uint8 const)24,  (yytype_uint8 const)25,  (yytype_uint8 const)26,
    (yytype_uint8 const)27,  (yytype_uint8 const)28,  (yytype_uint8 const)29,
    (yytype_uint8 const)79,  (yytype_uint8 const)30,  (yytype_uint8 const)51,
    (yytype_uint8 const)52,  (yytype_uint8 const)53,  (yytype_uint8 const)54,
    (yytype_uint8 const)55,  (yytype_uint8 const)56,  (yytype_uint8 const)12,
    (yytype_uint8 const)57,  (yytype_uint8 const)61,  (yytype_uint8 const)62,
    (yytype_uint8 const)63,  (yytype_uint8 const)64,  (yytype_uint8 const)65,
    (yytype_uint8 const)66,  (yytype_uint8 const)60,  (yytype_uint8 const)48,
    (yytype_uint8 const)80,  (yytype_uint8 const)47,  (yytype_uint8 const)6,
    (yytype_uint8 const)83,  (yytype_uint8 const)8,   (yytype_uint8 const)81,
    (yytype_uint8 const)82,  (yytype_uint8 const)26,  (yytype_uint8 const)84,
    (yytype_uint8 const)85,  (yytype_uint8 const)86,  (yytype_uint8 const)87,
    (yytype_uint8 const)94,  (yytype_uint8 const)95,  (yytype_uint8 const)96,
    (yytype_uint8 const)89,  (yytype_uint8 const)105, (yytype_uint8 const)97,
    (yytype_uint8 const)98,  (yytype_uint8 const)99,  (yytype_uint8 const)0,
    (yytype_uint8 const)108, (yytype_uint8 const)109, (yytype_uint8 const)101,
    (yytype_uint8 const)0,   (yytype_uint8 const)88};
static yytype_int8 const yycheck[113] = {
    (yytype_int8 const)27,  (yytype_int8 const)5,   (yytype_int8 const)6,
    (yytype_int8 const)7,   (yytype_int8 const)8,   (yytype_int8 const)9,
    (yytype_int8 const)10,  (yytype_int8 const)4,   (yytype_int8 const)12,
    (yytype_int8 const)15,  (yytype_int8 const)102, (yytype_int8 const)15,
    (yytype_int8 const)16,  (yytype_int8 const)19,  (yytype_int8 const)15,
    (yytype_int8 const)19,  (yytype_int8 const)19,  (yytype_int8 const)20,
    (yytype_int8 const)19,  (yytype_int8 const)25,  (yytype_int8 const)112,
    (yytype_int8 const)25,  (yytype_int8 const)19,  (yytype_int8 const)27,
    (yytype_int8 const)5,   (yytype_int8 const)6,   (yytype_int8 const)7,
    (yytype_int8 const)8,   (yytype_int8 const)9,   (yytype_int8 const)10,
    (yytype_int8 const)5,   (yytype_int8 const)6,   (yytype_int8 const)7,
    (yytype_int8 const)8,   (yytype_int8 const)9,   (yytype_int8 const)10,
    (yytype_int8 const)19,  (yytype_int8 const)19,  (yytype_int8 const)19,
    (yytype_int8 const)107, (yytype_int8 const)19,  (yytype_int8 const)20,
    (yytype_int8 const)25,  (yytype_int8 const)25,  (yytype_int8 const)25,
    (yytype_int8 const)113, (yytype_int8 const)19,  (yytype_int8 const)20,
    (yytype_int8 const)21,  (yytype_int8 const)22,  (yytype_int8 const)25,
    (yytype_int8 const)5,   (yytype_int8 const)6,   (yytype_int8 const)7,
    (yytype_int8 const)8,   (yytype_int8 const)9,   (yytype_int8 const)10,
    (yytype_int8 const)11,  (yytype_int8 const)12,  (yytype_int8 const)13,
    (yytype_int8 const)14,  (yytype_int8 const)23,  (yytype_int8 const)16,
    (yytype_int8 const)17,  (yytype_int8 const)18,  (yytype_int8 const)19,
    (yytype_int8 const)20,  (yytype_int8 const)21,  (yytype_int8 const)22,
    (yytype_int8 const)96,  (yytype_int8 const)24,  (yytype_int8 const)5,
    (yytype_int8 const)6,   (yytype_int8 const)7,   (yytype_int8 const)8,
    (yytype_int8 const)9,   (yytype_int8 const)10,  (yytype_int8 const)0,
    (yytype_int8 const)12,  (yytype_int8 const)5,   (yytype_int8 const)6,
    (yytype_int8 const)7,   (yytype_int8 const)8,   (yytype_int8 const)9,
    (yytype_int8 const)10,  (yytype_int8 const)25,  (yytype_int8 const)4,
    (yytype_int8 const)27,  (yytype_int8 const)26,  (yytype_int8 const)20,
    (yytype_int8 const)30,  (yytype_int8 const)22,  (yytype_int8 const)9,
    (yytype_int8 const)9,   (yytype_int8 const)19,  (yytype_int8 const)24,
    (yytype_int8 const)3,   (yytype_int8 const)19,  (yytype_int8 const)26,
    (yytype_int8 const)20,  (yytype_int8 const)20,  (yytype_int8 const)20,
    (yytype_int8 const)59,  (yytype_int8 const)27,  (yytype_int8 const)84,
    (yytype_int8 const)20,  (yytype_int8 const)20,  (yytype_int8 const)-1,
    (yytype_int8 const)20,  (yytype_int8 const)20,  (yytype_int8 const)19,
    (yytype_int8 const)-1,  (yytype_int8 const)25};
static yytype_uint8 const yystos[114] = {
    (yytype_uint8 const)0,  (yytype_uint8 const)23, (yytype_uint8 const)29,
    (yytype_uint8 const)30, (yytype_uint8 const)31, (yytype_uint8 const)19,
    (yytype_uint8 const)20, (yytype_uint8 const)21, (yytype_uint8 const)22,
    (yytype_uint8 const)48, (yytype_uint8 const)49, (yytype_uint8 const)50,
    (yytype_uint8 const)0,  (yytype_uint8 const)5,  (yytype_uint8 const)6,
    (yytype_uint8 const)7,  (yytype_uint8 const)8,  (yytype_uint8 const)9,
    (yytype_uint8 const)10, (yytype_uint8 const)11, (yytype_uint8 const)12,
    (yytype_uint8 const)13, (yytype_uint8 const)14, (yytype_uint8 const)16,
    (yytype_uint8 const)17, (yytype_uint8 const)18, (yytype_uint8 const)19,
    (yytype_uint8 const)20, (yytype_uint8 const)21, (yytype_uint8 const)22,
    (yytype_uint8 const)24, (yytype_uint8 const)32, (yytype_uint8 const)33,
    (yytype_uint8 const)34, (yytype_uint8 const)35, (yytype_uint8 const)36,
    (yytype_uint8 const)39, (yytype_uint8 const)40, (yytype_uint8 const)41,
    (yytype_uint8 const)42, (yytype_uint8 const)43, (yytype_uint8 const)44,
    (yytype_uint8 const)45, (yytype_uint8 const)46, (yytype_uint8 const)47,
    (yytype_uint8 const)51, (yytype_uint8 const)52, (yytype_uint8 const)26,
    (yytype_uint8 const)4,  (yytype_uint8 const)19, (yytype_uint8 const)20,
    (yytype_uint8 const)5,  (yytype_uint8 const)6,  (yytype_uint8 const)7,
    (yytype_uint8 const)8,  (yytype_uint8 const)9,  (yytype_uint8 const)10,
    (yytype_uint8 const)12, (yytype_uint8 const)4,  (yytype_uint8 const)19,
    (yytype_uint8 const)46, (yytype_uint8 const)5,  (yytype_uint8 const)6,
    (yytype_uint8 const)7,  (yytype_uint8 const)8,  (yytype_uint8 const)9,
    (yytype_uint8 const)10, (yytype_uint8 const)5,  (yytype_uint8 const)6,
    (yytype_uint8 const)7,  (yytype_uint8 const)8,  (yytype_uint8 const)9,
    (yytype_uint8 const)10, (yytype_uint8 const)12, (yytype_uint8 const)15,
    (yytype_uint8 const)16, (yytype_uint8 const)19, (yytype_uint8 const)25,
    (yytype_uint8 const)27, (yytype_uint8 const)38, (yytype_uint8 const)46,
    (yytype_uint8 const)9,  (yytype_uint8 const)9,  (yytype_uint8 const)46,
    (yytype_uint8 const)24, (yytype_uint8 const)3,  (yytype_uint8 const)19,
    (yytype_uint8 const)26, (yytype_uint8 const)25, (yytype_uint8 const)53,
    (yytype_uint8 const)19, (yytype_uint8 const)20, (yytype_uint8 const)19,
    (yytype_uint8 const)53, (yytype_uint8 const)20, (yytype_uint8 const)20,
    (yytype_uint8 const)20, (yytype_uint8 const)36, (yytype_uint8 const)20,
    (yytype_uint8 const)20, (yytype_uint8 const)15, (yytype_uint8 const)19,
    (yytype_uint8 const)25, (yytype_uint8 const)37, (yytype_uint8 const)38,
    (yytype_uint8 const)27, (yytype_uint8 const)25, (yytype_uint8 const)50,
    (yytype_uint8 const)20, (yytype_uint8 const)20, (yytype_uint8 const)15,
    (yytype_uint8 const)37, (yytype_uint8 const)25, (yytype_uint8 const)50};
static void yydestruct(char const *yymsg, int yytype, YYSTYPE *yyvaluep,
                       parser_control *pc) {

  {

    goto switch_default;
  switch_default:

  switch_break:;
  }
}
int yyparse(parser_control *pc);
int yyparse(parser_control *pc) {
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
  int yystate;
  int yyerrstatus;
  yytype_int16 yyssa[20];
  yytype_int16 *yyss;
  yytype_int16 *yyssp;
  YYSTYPE yyvsa[20];
  YYSTYPE *yyvs;
  YYSTYPE *yyvsp;
  unsigned long yystacksize;
  int yyn;
  int yyresult;
  int yytoken;
  YYSTYPE yyval;
  int yylen;
  unsigned long yysize;
  yytype_int16 *yyss1;
  union yyalloc *yyptr;
  union yyalloc *tmp;
  unsigned long yynewbytes;
  unsigned long yynewbytes___0;
  long tmp___0;
  relative_time __constr_expr_13;
  relative_time __constr_expr_14;
  relative_time __constr_expr_15;
  relative_time __constr_expr_16;
  relative_time __constr_expr_17;
  relative_time __constr_expr_18;
  relative_time __constr_expr_19;
  relative_time __constr_expr_20;
  relative_time __constr_expr_21;
  relative_time __constr_expr_22;
  relative_time __constr_expr_23;
  relative_time __constr_expr_24;
  relative_time __constr_expr_25;
  relative_time __constr_expr_26;
  relative_time __constr_expr_27;
  relative_time __constr_expr_28;
  relative_time __constr_expr_29;
  relative_time __constr_expr_30;
  relative_time __constr_expr_31;
  relative_time __constr_expr_32;
  relative_time __constr_expr_33;
  relative_time __constr_expr_34;
  relative_time __constr_expr_35;
  relative_time __constr_expr_36;
  relative_time __constr_expr_37;
  relative_time __constr_expr_38;
  relative_time __constr_expr_39;

  {

    yytoken = 0;
    yyss = yyssa;
    yyvs = yyvsa;
    yystacksize = 20UL;
    yystate = 0;

    yynerrs = 0;
    yychar = -2;
    yyssp = yyss;
    yyvsp = yyvs;
    goto yysetstate;
  yynewstate:
    yyssp++;
  yysetstate:
    *yyssp = (yytype_int16)yystate;

    if (yystate == 12) {
      goto yyacceptlab;
    }
    goto yybackup;
  yybackup:
    yyn = (int)yypact[yystate];
    if (yyn == -93) {
      goto yydefault;
    }
    if (yychar == -2) {
      yychar = yylex(&yylval, pc);
    }
    if (yychar <= 0) {
      yytoken = 0;

    } else {
      if ((unsigned int)yychar <= 277U) {
        yytoken = (int)yytranslate[yychar];
      } else {
      }
    }
    yyn += yytoken;
    if (yyn < 0) {
      goto yydefault;
    } else {
      if (112 < yyn) {
        goto yydefault;
      } else {
        if ((int const)yycheck[yyn] != (int const)yytoken) {
          goto yydefault;
        }
      }
    }
    yyn = (int)yytable[yyn];

    yychar = -2;
    yystate = yyn;
    yyvsp++;
    *yyvsp = yylval;
    goto yynewstate;
  yydefault:
    yyn = (int)yydefact[yystate];
    if (yyn == 0) {
      goto yyerrlab;
    }
    goto yyreduce;
  yyreduce:
    yylen = (int)yyr2[yyn];
    yyval = *(yyvsp + (1 - yylen));
    if (yyn == 4) {
    }
    if (yyn == 7) {
      goto case_7;
    }
    if (yyn == 8) {
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
    if (yyn == 12) {
      goto case_12;
    }
    if (yyn == 18) {
    }
    if (yyn == 19) {
      goto case_19;
    }
    if (yyn == 20) {
      goto case_20;
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
    if (yyn == 27) {
      goto case_27;
    }
    if (yyn == 28) {
      goto case_28;
    }

    if (yyn == 30) {
      goto case_30;
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

    if (yyn == 36) {
      goto case_36;
    }

    if (yyn == 38) {
      goto case_38;
    }
    if (yyn == 39) {
      goto case_39;
    }

    if (yyn == 41) {
      goto case_41;
    }
    if (yyn == 42) {
      goto case_42;
    }

    if (yyn == 45) {
      goto case_45;
    }

    if (yyn == 47) {
      goto case_47;
    }

    if (yyn == 50) {
      goto case_50;
    }
    if (yyn == 51) {
      goto case_51;
    }
    if (yyn == 52) {
      goto case_52;
    }
    if (yyn == 53) {
      goto case_53;
    }
    if (yyn == 54) {
      goto case_54;
    }

    if (yyn == 56) {
      goto case_56;
    }
    if (yyn == 57) {
      goto case_57;
    }
    if (yyn == 58) {
      goto case_58;
    }
    if (yyn == 59) {
      goto case_59;
    }
    if (yyn == 60) {
      goto case_60;
    }
    if (yyn == 61) {
      goto case_61;
    }

    if (yyn == 63) {
      goto case_63;
    }

    if (yyn == 65) {
      goto case_65;
    }
    if (yyn == 66) {
      goto case_66;
    }

    if (yyn == 68) {
      goto case_68;
    }
    if (yyn == 69) {
      goto case_69;
    }
    if (yyn == 70) {
      goto case_70;
    }
    if (yyn == 71) {
      goto case_71;
    }
    if (yyn == 72) {
      goto case_72;
    }
    if (yyn == 73) {
      goto case_73;
    }

    if (yyn == 76) {
      goto case_76;
    }
    if (yyn == 77) {
      goto case_77;
    }
    if (yyn == 78) {
    }
    if (yyn == 79) {
      goto case_79;
    }

    if (yyn == 81) {
      goto case_81;
    }

    if (yyn == 87) {
      goto case_87;
    }
    if (yyn == 88) {
      goto case_88;
    }
    if (yyn == 89) {
      goto case_89;
    }
    if (yyn == 90) {
      goto case_90;
    }
    if (yyn == 91) {
      goto case_91;
    }
    goto switch_default;
  case_4:
    pc->seconds = (yyvsp + 0)->timespec;

    goto switch_break;
  case_7:
    (pc->times_seen)++;
    (pc->dates_seen)++;
    goto switch_break;
  case_8:

    goto switch_break;
  case_9:
    (pc->local_zones_seen)++;
    goto switch_break;
  case_10:
    (pc->zones_seen)++;
    goto switch_break;
  case_11:
    (pc->dates_seen)++;
    goto switch_break;
  case_12:
    (pc->days_seen)++;
    goto switch_break;
  case_18:
    set_hhmmss(pc, (yyvsp + -1)->textintval.value, 0L, (time_t)0, 0L);
    pc->meridian = (int)(yyvsp + 0)->intval;
    goto switch_break;
  case_19:
    set_hhmmss(pc, (yyvsp + -3)->textintval.value,
               (yyvsp + -1)->textintval.value, (time_t)0, 0L);
    pc->meridian = (int)(yyvsp + 0)->intval;
    goto switch_break;
  case_20:
    set_hhmmss(pc, (yyvsp + -5)->textintval.value,
               (yyvsp + -3)->textintval.value, (yyvsp + -1)->timespec.tv_sec,
               (yyvsp + -1)->timespec.tv_nsec);
    pc->meridian = (int)(yyvsp + 0)->intval;
    goto switch_break;
  case_22:
    set_hhmmss(pc, (yyvsp + -1)->textintval.value, 0L, (time_t)0, 0L);
    pc->meridian = 2;

  case_23:
    set_hhmmss(pc, (yyvsp + -3)->textintval.value,
               (yyvsp + -1)->textintval.value, (time_t)0, 0L);

    goto switch_break;
  case_24:
    set_hhmmss(pc, (yyvsp + -5)->textintval.value,
               (yyvsp + -3)->textintval.value, (yyvsp + -1)->timespec.tv_sec,
               (yyvsp + -1)->timespec.tv_nsec);

    goto switch_break;
  case_27:

    pc->time_zone =
        time_zone_hhmm(pc, (yyvsp + -1)->textintval, (yyvsp + 0)->intval);
    goto switch_break;
  case_28:
    pc->local_isdst = (int)(yyvsp + 0)->intval;

    goto switch_break;
  case_29:
    pc->local_isdst = 1;

    goto switch_break;
  case_30:
    pc->time_zone = (yyvsp + 0)->intval;
    goto switch_break;
  case_31:
    pc->time_zone = 420L;

  case_32:
    pc->time_zone = (yyvsp + -1)->intval;
    apply_relative_time(pc, (yyvsp + 0)->rel, 1);
    goto switch_break;
  case_33:
    pc->time_zone = 420L;
    apply_relative_time(pc, (yyvsp + 0)->rel, 1);
    goto switch_break;
  case_34:
    tmp___0 = time_zone_hhmm(pc, (yyvsp + -1)->textintval, (yyvsp + 0)->intval);
    pc->time_zone = (yyvsp + -2)->intval + tmp___0;
    goto switch_break;
  case_35:
    pc->time_zone = (yyvsp + 0)->intval + 60L;
    goto switch_break;
  case_36:
    pc->time_zone = (yyvsp + -1)->intval + 60L;
    goto switch_break;
  case_37:
    pc->day_ordinal = 0L;
    pc->day_number = (int)(yyvsp + 0)->intval;
    goto switch_break;
  case_38:
    pc->day_ordinal = 0L;
    pc->day_number = (int)(yyvsp + -1)->intval;

  case_39:
    pc->day_ordinal = (yyvsp + -1)->intval;
    pc->day_number = (int)(yyvsp + 0)->intval;
    goto switch_break;
  case_40:
    pc->day_ordinal = (yyvsp + -1)->textintval.value;
    pc->day_number = (int)(yyvsp + 0)->intval;
    goto switch_break;
  case_41:
    pc->month = (yyvsp + -2)->textintval.value;
    pc->day = (yyvsp + 0)->textintval.value;
    goto switch_break;
  case_42:
    if (4UL <= (yyvsp + -4)->textintval.digits) {
      pc->year = (yyvsp + -4)->textintval;
      pc->month = (yyvsp + -2)->textintval.value;
      pc->day = (yyvsp + 0)->textintval.value;
    } else {
      pc->month = (yyvsp + -4)->textintval.value;
      pc->day = (yyvsp + -2)->textintval.value;
      pc->year = (yyvsp + 0)->textintval;
    }
    goto switch_break;
  case_43:
    pc->day = (yyvsp + -2)->textintval.value;
    pc->month = (yyvsp + -1)->intval;
    pc->year.value = -(yyvsp + 0)->textintval.value;
    pc->year.digits = (yyvsp + 0)->textintval.digits;
    goto switch_break;
  case_44:
    pc->month = (yyvsp + -2)->intval;
    pc->day = -(yyvsp + -1)->textintval.value;
    pc->year.value = -(yyvsp + 0)->textintval.value;
    pc->year.digits = (yyvsp + 0)->textintval.digits;
    goto switch_break;
  case_45:
    pc->month = (yyvsp + -1)->intval;
    pc->day = (yyvsp + 0)->textintval.value;
    goto switch_break;
  case_46:
    pc->month = (yyvsp + -3)->intval;
    pc->day = (yyvsp + -2)->textintval.value;
    pc->year = (yyvsp + 0)->textintval;
    goto switch_break;
  case_47:
    pc->day = (yyvsp + -1)->textintval.value;
    pc->month = (yyvsp + 0)->intval;
    goto switch_break;
  case_48:
    pc->day = (yyvsp + -2)->textintval.value;
    pc->month = (yyvsp + -1)->intval;
    pc->year = (yyvsp + 0)->textintval;
    goto switch_break;
  case_50:
    pc->year = (yyvsp + -2)->textintval;
    pc->month = -(yyvsp + -1)->textintval.value;
    pc->day = -(yyvsp + 0)->textintval.value;
    goto switch_break;
  case_51:
    apply_relative_time(pc, (yyvsp + -1)->rel, (int)(yyvsp + 0)->intval);
    goto switch_break;
  case_52:
    apply_relative_time(pc, (yyvsp + 0)->rel, 1);
    goto switch_break;
  case_53:
    apply_relative_time(pc, (yyvsp + 0)->rel, 1);
    goto switch_break;
  case_54:
    __constr_expr_13.year = 0L;
    __constr_expr_13.month = 0L;
    __constr_expr_13.day = 0L;
    __constr_expr_13.hour = 0L;
    __constr_expr_13.minutes = 0L;
    __constr_expr_13.seconds = (long_time_t)0;
    __constr_expr_13.ns = 0L;
    yyval.rel = __constr_expr_13;
    yyval.rel.year = (yyvsp + -1)->intval;
    goto switch_break;
  case_55:
    __constr_expr_14.year = 0L;
    __constr_expr_14.month = 0L;
    __constr_expr_14.day = 0L;
    __constr_expr_14.hour = 0L;
    __constr_expr_14.minutes = 0L;
    __constr_expr_14.seconds = (long_time_t)0;
    __constr_expr_14.ns = 0L;
    yyval.rel = __constr_expr_14;
    yyval.rel.year = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_56:
    __constr_expr_15.year = 0L;
    __constr_expr_15.month = 0L;
    __constr_expr_15.day = 0L;
    __constr_expr_15.hour = 0L;
    __constr_expr_15.minutes = 0L;
    __constr_expr_15.seconds = (long_time_t)0;
    __constr_expr_15.ns = 0L;
    yyval.rel = __constr_expr_15;
    yyval.rel.year = 1L;
    goto switch_break;
  case_57:
    __constr_expr_16.year = 0L;
    __constr_expr_16.month = 0L;
    __constr_expr_16.day = 0L;
    __constr_expr_16.hour = 0L;
    __constr_expr_16.minutes = 0L;
    __constr_expr_16.seconds = (long_time_t)0;
    __constr_expr_16.ns = 0L;
    yyval.rel = __constr_expr_16;
    yyval.rel.month = (yyvsp + -1)->intval;
    goto switch_break;
  case_58:
    __constr_expr_17.year = 0L;
    __constr_expr_17.month = 0L;
    __constr_expr_17.day = 0L;
    __constr_expr_17.hour = 0L;
    __constr_expr_17.minutes = 0L;
    __constr_expr_17.seconds = (long_time_t)0;
    __constr_expr_17.ns = 0L;
    yyval.rel = __constr_expr_17;
    yyval.rel.month = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_59:
    __constr_expr_18.year = 0L;
    __constr_expr_18.month = 0L;
    __constr_expr_18.day = 0L;
    __constr_expr_18.hour = 0L;
    __constr_expr_18.minutes = 0L;
    __constr_expr_18.seconds = (long_time_t)0;
    __constr_expr_18.ns = 0L;
    yyval.rel = __constr_expr_18;
    yyval.rel.month = 1L;
    goto switch_break;
  case_60:
    __constr_expr_19.year = 0L;
    __constr_expr_19.month = 0L;
    __constr_expr_19.day = 0L;
    __constr_expr_19.hour = 0L;
    __constr_expr_19.minutes = 0L;
    __constr_expr_19.seconds = (long_time_t)0;
    __constr_expr_19.ns = 0L;
    yyval.rel = __constr_expr_19;
    yyval.rel.day = (yyvsp + -1)->intval * (yyvsp + 0)->intval;
    goto switch_break;
  case_61:
    __constr_expr_20.year = 0L;
    __constr_expr_20.month = 0L;
    __constr_expr_20.day = 0L;
    __constr_expr_20.hour = 0L;
    __constr_expr_20.minutes = 0L;
    __constr_expr_20.seconds = (long_time_t)0;
    __constr_expr_20.ns = 0L;
    yyval.rel = __constr_expr_20;
    yyval.rel.day = (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
    goto switch_break;
  case_62:
    __constr_expr_21.year = 0L;
    __constr_expr_21.month = 0L;
    __constr_expr_21.day = 0L;
    __constr_expr_21.hour = 0L;
    __constr_expr_21.minutes = 0L;
    __constr_expr_21.seconds = (long_time_t)0;
    __constr_expr_21.ns = 0L;
    yyval.rel = __constr_expr_21;
    yyval.rel.day = (yyvsp + 0)->intval;
    goto switch_break;
  case_63:
    __constr_expr_22.year = 0L;
    __constr_expr_22.month = 0L;
    __constr_expr_22.day = 0L;
    __constr_expr_22.hour = 0L;
    __constr_expr_22.minutes = 0L;
    __constr_expr_22.seconds = (long_time_t)0;
    __constr_expr_22.ns = 0L;
    yyval.rel = __constr_expr_22;
    yyval.rel.hour = (yyvsp + -1)->intval;
    goto switch_break;
  case_64:
    __constr_expr_23.year = 0L;
    __constr_expr_23.month = 0L;
    __constr_expr_23.day = 0L;
    __constr_expr_23.hour = 0L;
    __constr_expr_23.minutes = 0L;
    __constr_expr_23.seconds = (long_time_t)0;
    __constr_expr_23.ns = 0L;
    yyval.rel = __constr_expr_23;
    yyval.rel.hour = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_65:
    __constr_expr_24.year = 0L;
    __constr_expr_24.month = 0L;
    __constr_expr_24.day = 0L;
    __constr_expr_24.hour = 0L;
    __constr_expr_24.minutes = 0L;
    __constr_expr_24.seconds = (long_time_t)0;
    __constr_expr_24.ns = 0L;
    yyval.rel = __constr_expr_24;
    yyval.rel.hour = 1L;
    goto switch_break;
  case_66:
    __constr_expr_25.year = 0L;
    __constr_expr_25.month = 0L;
    __constr_expr_25.day = 0L;
    __constr_expr_25.hour = 0L;
    __constr_expr_25.minutes = 0L;
    __constr_expr_25.seconds = (long_time_t)0;
    __constr_expr_25.ns = 0L;
    yyval.rel = __constr_expr_25;
    yyval.rel.minutes = (yyvsp + -1)->intval;
    goto switch_break;
  case_67:
    __constr_expr_26.year = 0L;
    __constr_expr_26.month = 0L;
    __constr_expr_26.day = 0L;
    __constr_expr_26.hour = 0L;
    __constr_expr_26.minutes = 0L;
    __constr_expr_26.seconds = (long_time_t)0;
    __constr_expr_26.ns = 0L;
    yyval.rel = __constr_expr_26;
    yyval.rel.minutes = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_68:
    __constr_expr_27.year = 0L;
    __constr_expr_27.month = 0L;
    __constr_expr_27.day = 0L;
    __constr_expr_27.hour = 0L;
    __constr_expr_27.minutes = 0L;
    __constr_expr_27.seconds = (long_time_t)0;
    __constr_expr_27.ns = 0L;
    yyval.rel = __constr_expr_27;
    yyval.rel.minutes = 1L;
    goto switch_break;
  case_69:
    __constr_expr_28.year = 0L;
    __constr_expr_28.month = 0L;
    __constr_expr_28.day = 0L;
    __constr_expr_28.hour = 0L;
    __constr_expr_28.minutes = 0L;
    __constr_expr_28.seconds = (long_time_t)0;
    __constr_expr_28.ns = 0L;
    yyval.rel = __constr_expr_28;
    yyval.rel.seconds = (yyvsp + -1)->intval;
    goto switch_break;
  case_70:
    __constr_expr_29.year = 0L;
    __constr_expr_29.month = 0L;
    __constr_expr_29.day = 0L;
    __constr_expr_29.hour = 0L;
    __constr_expr_29.minutes = 0L;
    __constr_expr_29.seconds = (long_time_t)0;
    __constr_expr_29.ns = 0L;
    yyval.rel = __constr_expr_29;
    yyval.rel.seconds = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_71:
    __constr_expr_30.year = 0L;
    __constr_expr_30.month = 0L;
    __constr_expr_30.day = 0L;
    __constr_expr_30.hour = 0L;
    __constr_expr_30.minutes = 0L;
    __constr_expr_30.seconds = (long_time_t)0;
    __constr_expr_30.ns = 0L;
    yyval.rel = __constr_expr_30;
    yyval.rel.seconds = (yyvsp + -1)->timespec.tv_sec;
    yyval.rel.ns = (yyvsp + -1)->timespec.tv_nsec;
    goto switch_break;
  case_72:
    __constr_expr_31.year = 0L;
    __constr_expr_31.month = 0L;
    __constr_expr_31.day = 0L;
    __constr_expr_31.hour = 0L;
    __constr_expr_31.minutes = 0L;
    __constr_expr_31.seconds = (long_time_t)0;
    __constr_expr_31.ns = 0L;
    yyval.rel = __constr_expr_31;
    yyval.rel.seconds = (yyvsp + -1)->timespec.tv_sec;
    yyval.rel.ns = (yyvsp + -1)->timespec.tv_nsec;
    goto switch_break;
  case_73:
    __constr_expr_32.year = 0L;
    __constr_expr_32.month = 0L;
    __constr_expr_32.day = 0L;
    __constr_expr_32.hour = 0L;
    __constr_expr_32.minutes = 0L;
    __constr_expr_32.seconds = (long_time_t)0;
    __constr_expr_32.ns = 0L;
    yyval.rel = __constr_expr_32;
    yyval.rel.seconds = (long_time_t)1;
    goto switch_break;
  case_75:
    __constr_expr_33.year = 0L;
    __constr_expr_33.month = 0L;
    __constr_expr_33.day = 0L;
    __constr_expr_33.hour = 0L;
    __constr_expr_33.minutes = 0L;
    __constr_expr_33.seconds = (long_time_t)0;
    __constr_expr_33.ns = 0L;
    yyval.rel = __constr_expr_33;
    yyval.rel.year = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_76:
    __constr_expr_34.year = 0L;
    __constr_expr_34.month = 0L;
    __constr_expr_34.day = 0L;
    __constr_expr_34.hour = 0L;
    __constr_expr_34.minutes = 0L;
    __constr_expr_34.seconds = (long_time_t)0;
    __constr_expr_34.ns = 0L;
    yyval.rel = __constr_expr_34;
    yyval.rel.month = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_77:
    __constr_expr_35.year = 0L;
    __constr_expr_35.month = 0L;
    __constr_expr_35.day = 0L;
    __constr_expr_35.hour = 0L;
    __constr_expr_35.minutes = 0L;
    __constr_expr_35.seconds = (long_time_t)0;
    __constr_expr_35.ns = 0L;
    yyval.rel = __constr_expr_35;
    yyval.rel.day = (yyvsp + -1)->textintval.value * (yyvsp + 0)->intval;
    goto switch_break;
  case_78:
    __constr_expr_36.year = 0L;
    __constr_expr_36.month = 0L;
    __constr_expr_36.day = 0L;
    __constr_expr_36.hour = 0L;
    __constr_expr_36.minutes = 0L;
    __constr_expr_36.seconds = (long_time_t)0;
    __constr_expr_36.ns = 0L;
    yyval.rel = __constr_expr_36;
    yyval.rel.hour = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_79:
    __constr_expr_37.year = 0L;
    __constr_expr_37.month = 0L;
    __constr_expr_37.day = 0L;
    __constr_expr_37.hour = 0L;
    __constr_expr_37.minutes = 0L;
    __constr_expr_37.seconds = (long_time_t)0;
    __constr_expr_37.ns = 0L;
    yyval.rel = __constr_expr_37;
    yyval.rel.minutes = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_80:
    __constr_expr_38.year = 0L;
    __constr_expr_38.month = 0L;
    __constr_expr_38.day = 0L;
    __constr_expr_38.hour = 0L;
    __constr_expr_38.minutes = 0L;
    __constr_expr_38.seconds = (long_time_t)0;
    __constr_expr_38.ns = 0L;
    yyval.rel = __constr_expr_38;
    yyval.rel.seconds = (yyvsp + -1)->textintval.value;
    goto switch_break;
  case_81:
    __constr_expr_39.year = 0L;
    __constr_expr_39.month = 0L;
    __constr_expr_39.day = 0L;
    __constr_expr_39.hour = 0L;
    __constr_expr_39.minutes = 0L;
    __constr_expr_39.seconds = (long_time_t)0;
    __constr_expr_39.ns = 0L;
    yyval.rel = __constr_expr_39;
    yyval.rel.day = (yyvsp + 0)->intval;
    goto switch_break;
  case_85:
    yyval.timespec.tv_sec = (yyvsp + 0)->textintval.value;
    yyval.timespec.tv_nsec = (__syscall_slong_t)0;
    goto switch_break;
  case_87:
    yyval.timespec.tv_sec = (yyvsp + 0)->textintval.value;
    yyval.timespec.tv_nsec = (__syscall_slong_t)0;
    goto switch_break;
  case_88:
    digits_to_date_time(pc, (yyvsp + 0)->textintval);
    goto switch_break;
  case_89:
    digits_to_date_time(pc, (yyvsp + -1)->textintval);
    apply_relative_time(pc, (yyvsp + 0)->rel, 1);
    goto switch_break;
  case_90:
    yyval.intval = -1L;
    goto switch_break;
  case_91:
    yyval.intval = (yyvsp + 0)->textintval.value;
    goto switch_break;
  switch_default:
    goto switch_break;
  switch_break:
    yyvsp -= yylen;
    yyssp -= yylen;
    yylen = 0;
    yyvsp++;
    *yyvsp = yyval;
    yyn = (int)yyr1[yyn];
    yystate = (int)((int const)yypgoto[yyn - 28] + (int const) * yyssp);
    if (0 <= yystate) {
      if (yystate <= 112) {
        if ((int const)yycheck[yystate] == (int const) * yyssp) {
          yystate = (int)yytable[yystate];
        } else {
          yystate = (int)yydefgoto[yyn - 28];
        }
      } else {
        yystate = (int)yydefgoto[yyn - 28];
      }
    } else {
      yystate = (int)yydefgoto[yyn - 28];
    }
    goto yynewstate;
  yyerrlab:
    if (!yyerrstatus) {
    }

    goto yyerrlab1;
    yyvsp -= yylen;
    yyssp -= yylen;
    yylen = 0;
    yystate = (int)*yyssp;
    goto yyerrlab1;
  yyerrlab1:
    yyerrstatus = 3;
    while (1) {
      yyn = (int)yypact[yystate];
      if (yyn != -93) {
        yyn++;
      }
      if ((unsigned long)yyssp == (unsigned long)yyss) {
        goto yyabortlab;
      }
      yydestruct("Error: popping", (int)yystos[yystate], yyvsp, pc);
      yyvsp--;
      yyssp--;
      yystate = (int)*yyssp;
    }

    *yyvsp = yylval;

    goto yynewstate;
  yyacceptlab:
    yyresult = 0;

  yyabortlab:

  yyreturn:
    if (yychar != -2) {
      yydestruct("Cleanup: discarding lookahead", yytoken, &yylval, pc);
    }

    yyssp -= yylen;

    ;
    if ((unsigned long)yyss != (unsigned long)(yyssa)) {
      free((void *)yyss);
    }
    return (yyresult);
  }
}
static table const meridian_table[5] = {{"AM", 270, 0},
                                        {"A.M.", 270, 0},
                                        {"PM", 270, 1},
                                        {"P.M.", 270, 1},
                                        {(char const *)((void *)0), 0, 0}};
static table const dst_table[1] = {{"DST", 259, 0}};
static table const month_and_day_table[25] = {
    {"JANUARY", 271, 1},
    {"FEBRUARY", 271, 2},
    {"MARCH", 271, 3},
    {"APRIL", 271, 4},
    {"MAY", 271, 5},
    {"JUNE", 271, 6},
    {"JULY", 271, 7},
    {"AUGUST", 271, 8},
    {"SEPTEMBER", 271, 9},
    {"SEPT", 271, 9},
    {"OCTOBER", 271, 10},
    {"NOVEMBER", 271, 11},
    {"DECEMBER", 271, 12},
    {"SUNDAY", 267, 0},
    {"MONDAY", 267, 1},
    {"TUESDAY", 267, 2},
    {"TUES", 267, 2},
    {"WEDNESDAY", 267, 3},
    {"WEDNES", 267, 3},
    {"THURSDAY", 267, 4},
    {"THUR", 267, 4},
    {"THURS", 267, 4},
    {"FRIDAY", 267, 5},
    {"SATURDAY", 267, 6},
    {(char const *)((void *)0), 0, 0}};
static table const time_units_table[11] = {{"YEAR", 260, 1},
                                           {"MONTH", 261, 1},
                                           {"FORTNIGHT", 265, 14},
                                           {"WEEK", 265, 7},
                                           {"DAY", 265, 1},
                                           {"HOUR", 262, 1},
                                           {"MINUTE", 263, 1},
                                           {"MIN", 263, 1},
                                           {"SECOND", 264, 1},
                                           {"SEC", 264, 1},
                                           {(char const *)((void *)0), 0, 0}};
static table const relative_time_table[21] = {
    {"TOMORROW", 266, 1},
    {"YESTERDAY", 266, -1},
    {"TODAY", 266, 0},
    {"NOW", 266, 0},
    {"LAST", 272, -1},
    {"THIS", 272, 0},
    {"NEXT", 272, 1},
    {"FIRST", 272, 1},
    {"THIRD", 272, 3},
    {"FOURTH", 272, 4},
    {"FIFTH", 272, 5},
    {"SIXTH", 272, 6},
    {"SEVENTH", 272, 7},
    {"EIGHTH", 272, 8},
    {"NINTH", 272, 9},
    {"TENTH", 272, 10},
    {"ELEVENTH", 272, 11},
    {"TWELFTH", 272, 12},
    {"AGO", 258, -1},
    {"HENCE", 258, 1},
    {(char const *)((void *)0), 0, 0}};
static table const universal_time_zone_table[4] = {
    {"GMT", 273, 0},
    {"UT", 273, 0},
    {"UTC", 273, 0},
    {(char const *)((void *)0), 0, 0}};
static table const time_zone_table[48] = {
    {"WET", 273, 0},     {"WEST", 268, 0},   {"BST", 268, 0},
    {"ART", 273, -180},  {"BRT", 273, -180}, {"BRST", 268, -180},
    {"NST", 273, -210},  {"NDT", 268, -210}, {"AST", 273, -240},
    {"ADT", 268, -240},  {"CLT", 273, -240}, {"CLST", 268, -240},
    {"EST", 273, -300},  {"EDT", 268, -300}, {"CST", 273, -360},
    {"CDT", 268, -360},  {"MST", 273, -420}, {"MDT", 268, -420},
    {"PST", 273, -480},  {"PDT", 268, -480}, {"AKST", 273, -540},
    {"AKDT", 268, -540}, {"HST", 273, -600}, {"HAST", 273, -600},
    {"HADT", 268, -600}, {"SST", 273, -720}, {"WAT", 273, 60},
    {"CET", 273, 60},    {"CEST", 268, 60},  {"MET", 273, 60},
    {"MEZ", 273, 60},    {"MEST", 268, 60},  {"MESZ", 268, 60},
    {"EET", 273, 120},   {"EEST", 268, 120}, {"CAT", 273, 120},
    {"SAST", 273, 120},  {"EAT", 273, 180},  {"MSK", 273, 180},
    {"MSD", 268, 180},   {"IST", 273, 330},  {"SGT", 273, 480},
    {"KST", 273, 540},   {"JST", 273, 540},  {"GST", 273, 600},
    {"NZST", 273, 720},  {"NZDT", 268, 720}, {(char const *)((void *)0), 0, 0}};
static table const military_table[26] = {
    {"A", 273, -60},  {"B", 273, -120},
    {"C", 273, -180}, {"D", 273, -240},
    {"E", 273, -300}, {"F", 273, -360},
    {"G", 273, -420}, {"H", 273, -480},
    {"I", 273, -540}, {"K", 273, -600},
    {"L", 273, -660}, {"M", 273, -720},
    {"N", 273, 60},   {"O", 273, 120},
    {"P", 273, 180},  {"Q", 273, 240},
    {"R", 273, 300},  {"S", 273, 360},
    {"T", 'T', 0},    {"U", 273, 480},
    {"V", 273, 540},  {"W", 273, 600},
    {"X", 273, 660},  {"Y", 273, 720},
    {"Z", 273, 0},    {(char const *)((void *)0), 0, 0}};
static long time_zone_hhmm(parser_control *pc, textint s, long mm) {
  long n_minutes;
  long tmp;
  int tmp___0;

  {

    if (mm < 0L) {
      n_minutes = (s.value / 100L) * 60L + s.value % 100L;
    } else {
      if (s.negative) {
        tmp = -mm;
      } else {
        tmp = mm;
      }
      n_minutes = s.value * 60L + tmp;
    }
    tmp___0 = abs((int)n_minutes);

    return (n_minutes);
  }
}
static int to_hour(long hours, int meridian) {
  long tmp;
  int tmp___0;
  long tmp___1;
  int tmp___2;
  long tmp___3;

  {
    if (meridian == 0) {
      goto case_0;
    }
    if (meridian == 1) {
      goto case_1;
    }

  switch_default:
    if (0L <= hours) {
      if (hours < 24L) {
        tmp = hours;
      } else {
      }
    } else {
      tmp = -1L;
    }
    return ((int)tmp);
  case_0:

    return ((int)tmp___1);
  case_1:
    if (0L < hours) {

    } else {
    _L___0:

      tmp___3 = (long)tmp___2;
    }
    return ((int)tmp___3);

    return (0);
  }
}
static long to_year(textint textyear) {
  long year___1;
  int tmp;

  {
    year___1 = textyear.value;

    return (year___1);
  }
}
static table const *__attribute__((__pure__))
lookup_zone(parser_control const *pc, char const *name) {
  table const *tp;
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    tp = universal_time_zone_table;
    while (1) {

      if (!tp->name) {
        goto while_break;
      }
      tmp = strcmp(name, (char const *)tp->name);
      if (tmp == 0) {
        return (tp);
      }
      tp++;
    }
  while_break:
    tp = (table const *)(pc->local_time_zone_table);
    while (1) {

      if (!tp->name) {
        goto while_break___0;
      }
      tmp___0 = strcmp(name, (char const *)tp->name);
      if (tmp___0 == 0) {
        return (tp);
      }
      tp++;
    }
  while_break___0:
    tp = time_zone_table;
    while (1) {

      if (!tp->name) {
        goto while_break___1;
      }
      tmp___1 = strcmp(name, (char const *)tp->name);
      if (tmp___1 == 0) {
        return (tp);
      }
      tp++;
    }
  while_break___1:;
    return ((table const *)((void *)0));
  }
}
static table const *lookup_word(parser_control const *pc, char *word___0) {
  char *p;
  char *q;
  size_t wordlen;
  table const *tp;
  _Bool period_found;
  _Bool abbrev;
  unsigned char ch;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  char tmp___8;

  {
    p = word___0;
    while (1) {

      if (!*p) {
        goto while_break;
      }
      ch = (unsigned char)*p;
      *p = (char)c_toupper((int)ch);
      p++;
    }
  while_break:
    tp = meridian_table;
    while (1) {

      if (!tp->name) {
        goto while_break___0;
      }
      tmp = strcmp((char const *)word___0, (char const *)tp->name);
      if (tmp == 0) {
        return (tp);
      }
      tp++;
    }
  while_break___0:
    wordlen = strlen((char const *)word___0);
    if (wordlen == 3UL) {
      tmp___0 = 1;
    } else {
      if (wordlen == 4UL) {
        if ((int)*(word___0 + 3) == 46) {

        } else {
        }
      } else {
        tmp___0 = 0;
      }
    }
    abbrev = (_Bool)tmp___0;
    tp = month_and_day_table;
    while (1) {

      if (!tp->name) {
        goto while_break___1;
      }
      if (abbrev) {
        tmp___1 =
            strncmp((char const *)word___0, (char const *)tp->name, (size_t)3);
        tmp___3 = tmp___1;
      } else {
        tmp___2 = strcmp((char const *)word___0, (char const *)tp->name);
        tmp___3 = tmp___2;
      }
      if (tmp___3 == 0) {
        return (tp);
      }
      tp++;
    }
  while_break___1:
    tp = (table const *)lookup_zone(pc, (char const *)word___0);
    if (tp) {
      return (tp);
    }
    tmp___4 = strcmp((char const *)word___0, (char const *)dst_table[0].name);
    if (tmp___4 == 0) {
      return (dst_table);
    }
    tp = time_units_table;
    while (1) {

      if (!tp->name) {
        goto while_break___2;
      }
      tmp___5 = strcmp((char const *)word___0, (char const *)tp->name);
      if (tmp___5 == 0) {
        return (tp);
      }
      tp++;
    }
  while_break___2:;
    if ((int)*(word___0 + (wordlen - 1UL)) == 83) {
      *(word___0 + (wordlen - 1UL)) = (char)'\000';
      tp = time_units_table;
      while (1) {

        if (!tp->name) {
          goto while_break___3;
        }
        tmp___6 = strcmp((char const *)word___0, (char const *)tp->name);
        if (tmp___6 == 0) {
          return (tp);
        }
        tp++;
      }
    while_break___3:
      *(word___0 + (wordlen - 1UL)) = (char)'S';
    }
    tp = relative_time_table;
    while (1) {

      if (!tp->name) {
        goto while_break___4;
      }
      tmp___7 = strcmp((char const *)word___0, (char const *)tp->name);
      if (tmp___7 == 0) {
        return (tp);
      }
      tp++;
    }
  while_break___4:;
    if (wordlen == 1UL) {
      tp = military_table;

    while_break___5:;
    }

    p = q;
    while (1) {

      if (!tmp___8) {
        goto while_break___6;
      }

      q++;
    }
  while_break___6:;
    if (period_found) {
      tp = (table const *)lookup_zone(pc, (char const *)word___0);
      if (tp) {
        return (tp);
      }
    }
  }
}
static int yylex(union YYSTYPE *lvalp, parser_control *pc) {
  unsigned char c;
  size_t count;
  _Bool tmp;
  char const *p;
  int sign;
  unsigned long value;
  _Bool tmp___0;
  unsigned long value1;
  time_t s;
  int ns;
  int digits;
  unsigned long value1___0;
  char const *tmp___1;
  char const *tmp___2;
  int tmp___3;
  int tmp___4;
  char buff[20];
  char *p___0;
  table const *tp;
  char *tmp___5;
  _Bool tmp___6;
  _Bool tmp___7;
  char const *tmp___8;
  int tmp___9;
  char const *tmp___10;

  {
    while (1) {

      while (1) {
        c = (unsigned char)*(pc->input);
        tmp = c_isspace((int)c);
        if (!tmp) {
          goto while_break___0;
        }
        (pc->input)++;
      }
    while_break___0:;
      if ((unsigned int)c - 48U <= 9U) {
        goto _L___2;
      } else {
        if ((int)c == 45) {
          goto _L___2;
        } else {
          if ((int)c == 43) {
          _L___2:
            if ((int)c == 45) {
              goto _L;
            } else {
              if ((int)c == 43) {
              _L:
                if ((int)c == 45) {
                  sign = -1;
                } else {
                  sign = 1;
                }
                while (1) {
                while_continue___1:
                  (pc->input)++;
                  c = (unsigned char)*(pc->input);
                  tmp___0 = c_isspace((int)c);
                  if (!tmp___0) {
                    goto while_break___1;
                  }
                  goto while_continue___1;
                }
              while_break___1:;
                if (!((unsigned int)c - 48U <= 9U)) {
                  goto __Cont;
                }
              } else {
              }
            }
            p = pc->input;
            value = 0UL;
            while (1) {
              value1 = value + (unsigned long)((int)c - 48);
              if (value1 < value) {
                return ('?');
              }
              value = value1;
              p++;
              c = (unsigned char)*p;
              if (!((unsigned int)c - 48U <= 9U)) {
                goto while_break___2;
              }
              if (1844674407370955161UL < value) {
                return ('?');
              }
              value *= 10UL;
            }
          while_break___2:;
            if ((int)c == 46) {

            } else {
              if ((int)c == 44) {

                if ((unsigned int)*(p + 1) - 48U <= 9U) {
                  if (sign < 0) {
                    s = (time_t)(-value);

                    value1___0 = (unsigned long)(-s);
                  } else {
                    s = (time_t)value;

                    value1___0 = (unsigned long)s;
                  }
                  if (value != value1___0) {
                    return ('?');
                  }
                  p++;
                  tmp___1 = p;
                  p++;
                  ns = (int)((int const) * tmp___1 - 48);
                  digits = 2;

                while_break___3:;

                  while (1) {

                    if (!((unsigned int)*p - 48U <= 9U)) {
                      goto while_break___5;
                    }
                  }
                while_break___5:;
                  if (sign < 0) {
                    if (ns) {
                      s--;

                      ns = 1000000000 - ns;
                    }
                  }
                  lvalp->timespec.tv_sec = s;
                  lvalp->timespec.tv_nsec = (__syscall_slong_t)ns;
                  pc->input = p;
                  if (sign) {

                  } else {
                  }
                  return (tmp___3);
                } else {
                  goto _L___0;
                }
              } else {
              _L___0:
                lvalp->textintval.negative = (_Bool)(sign < 0);
                if (sign < 0) {
                  lvalp->textintval.value = (long)(-value);
                  if (0L < lvalp->textintval.value) {
                    return ('?');
                  }
                } else {
                  lvalp->textintval.value = (long)value;
                  if (lvalp->textintval.value < 0L) {
                    return ('?');
                  }
                }
                lvalp->textintval.digits = (size_t)(p - pc->input);
                pc->input = p;
                if (sign) {
                  tmp___4 = 274;
                } else {
                  tmp___4 = 275;
                }
                return (tmp___4);
              }
            }
          }
        }
      }
      tmp___7 = c_isalpha((int)c);
      if (tmp___7) {
        p___0 = buff;
        while (1) {

          if ((unsigned long)(p___0 - buff) < sizeof(buff) - 1UL) {
            tmp___5 = p___0;
            p___0++;
            *tmp___5 = (char)c;
          }
          (pc->input)++;
          c = (unsigned char)*(pc->input);
          tmp___6 = c_isalpha((int)c);
          if (!tmp___6) {
            if (!((int)c == 46)) {
              goto while_break___6;
            }
          }
        }
      while_break___6:
        *p___0 = (char)'\000';
        tp = lookup_word((parser_control const *)pc, buff);
        if (!tp) {
          return ('?');
        }
        lvalp->intval = (long)tp->value;
        return ((int)tp->type);
      }
      if ((int)c != 40) {
        tmp___8 = pc->input;
        (pc->input)++;

        return (tmp___9);
      }
      count = (size_t)0;

    while_break___7:;
    __Cont:;
    }

    return (0);
  }
}
static int yyerror(parser_control const *pc __attribute__((__unused__)),
                   char const *s __attribute__((__unused__))) {

  { return (0); }
}
static _Bool mktime_ok(struct tm const *tm0, struct tm const *tm1, time_t t) {

  {
    if (t == -1L) {
      tm1 = (struct tm const *)localtime((time_t const *)(&t));
      if (!tm1) {
        return ((_Bool)0);
      }
    }
    return ((_Bool)(!(
        (((((tm0->tm_sec ^ tm1->tm_sec) | (tm0->tm_min ^ tm1->tm_min)) |
           (tm0->tm_hour ^ tm1->tm_hour)) |
          (tm0->tm_mday ^ tm1->tm_mday)) |
         (tm0->tm_mon ^ tm1->tm_mon)) |
        (tm0->tm_year ^ tm1->tm_year))));
  }
}
static char *get_tz(char *tzbuf) {
  char *tz;
  char *tmp;
  size_t tzsize;

  void *tmp___1;

  {

    tz = tmp;

    return (tz);
  }
}
_Bool parse_datetime(struct timespec *result, char const *p,
                     struct timespec const *now) {
  time_t Start;
  long Start_ns;
  struct tm const *tmp;
  struct tm tm;
  struct tm tm0;
  parser_control pc;
  struct timespec gettime_buffer;
  unsigned char c;
  _Bool tz_was_altered;
  char *tz0;
  char tz0buf[100];
  _Bool ok;
  _Bool tmp___0;

  size_t tzsize;
  char const *s;

  int tmp___4;
  relative_time __constr_expr_40;
  int quarter;
  time_t probe;
  struct tm const *probe_tm;
  struct tm const *tmp___5;

  int tmp___7;
  long tmp___8;

  long tmp___9;
  long abs_time_zone_hour;

  char tz1buf___0[sizeof("XXX+0:00") + (sizeof(pc.time_zone) * 8UL) / 3UL];
  int tmp___10;

  _Bool tmp___12;
  int tmp___13;
  int year___1;
  int month;
  int day;
  long delta;
  time_t t1;
  long sum_ns;
  long normalized_ns;
  time_t t0;
  long d1;
  time_t t1___0;
  long d2;
  time_t t2;
  long_time_t d3;
  long_time_t t3;
  long d4;
  long_time_t t4;
  time_t t5;
  int tmp___14;
  int tmp___15;
  int tmp___16;

  {

    tz0 = (char *)((void *)0);

    if (!now) {
      gettime(&gettime_buffer);
      now = (struct timespec const *)(&gettime_buffer);
    }
    Start = (time_t)now->tv_sec;

    tmp = (struct tm const *)localtime(&now->tv_sec);
    if (!tmp) {
      return ((_Bool)0);
    }
    while (1) {
      c = (unsigned char)*p;
      tmp___0 = c_isspace((int)c);
      if (!tmp___0) {
        goto while_break;
      }
      p++;
    }
  while_break:
    tmp___4 = strncmp(p, "TZ=\"", (size_t)4);

    if ((int const) * p == 0) {
    }
    pc.input = p;
    pc.year.value = (long)tmp->tm_year;
    pc.year.value += 1900L;
    pc.year.digits = (size_t)0;
    pc.month = (long)(tmp->tm_mon + 1);
    pc.day = (long)tmp->tm_mday;
    pc.hour = (long)tmp->tm_hour;
    pc.minutes = (long)tmp->tm_min;
    pc.seconds.tv_sec = (__time_t)tmp->tm_sec;

    tm.tm_isdst = (int)tmp->tm_isdst;
    pc.meridian = 2;
    __constr_expr_40.year = 0L;
    __constr_expr_40.month = 0L;
    __constr_expr_40.day = 0L;

    __constr_expr_40.minutes = 0L;

    pc.rel = __constr_expr_40;
    pc.timespec_seen = (_Bool)0;
    pc.rels_seen = (_Bool)0;
    pc.dates_seen = (size_t)0;
    pc.days_seen = (size_t)0;
    pc.times_seen = (size_t)0;
    pc.local_zones_seen = (size_t)0;
    pc.dsts_seen = (size_t)0;
    pc.zones_seen = (size_t)0;
    pc.local_time_zone_table[0].name = (char const *)tmp->tm_zone;
    pc.local_time_zone_table[0].type = 269;
    pc.local_time_zone_table[0].value = (int)tmp->tm_isdst;
    pc.local_time_zone_table[1].name = (char const *)((void *)0);

    while (1) {

      if (!(quarter <= 3)) {
        goto while_break___2;
      }
      probe = Start + (time_t)(quarter * 7776000);
      tmp___5 = (struct tm const *)localtime((time_t const *)(&probe));
      probe_tm = tmp___5;
      if (probe_tm) {
        if (probe_tm->tm_zone) {
          if (probe_tm->tm_isdst !=
              (int const)pc.local_time_zone_table[0].value) {
            pc.local_time_zone_table[1].name = (char const *)probe_tm->tm_zone;
            pc.local_time_zone_table[1].type = 269;
            pc.local_time_zone_table[1].value = (int)probe_tm->tm_isdst;

            goto while_break___2;
          }
        }
      }
      quarter++;
    }
  while_break___2:;

    tmp___7 = yyparse(&pc);
    if (tmp___7 != 0) {
      goto fail;
    }
    if (pc.timespec_seen) {
      *result = pc.seconds;
    } else {
      if (1UL <
          ((((pc.times_seen | pc.dates_seen) | pc.days_seen) | pc.dsts_seen) |
           (pc.local_zones_seen + pc.zones_seen))) {
        goto fail;
      }
      tmp___8 = to_year(pc.year);
      tm.tm_year = (int)(tmp___8 - 1900L);
      tm.tm_mon = (int)(pc.month - 1L);
      tm.tm_mday = (int)pc.day;
      if (pc.times_seen) {
        goto _L;
      } else {
        if (pc.rels_seen) {
          if (!pc.dates_seen) {
            if (!pc.days_seen) {
            _L:
              tm.tm_hour = to_hour(pc.hour, pc.meridian);
              if (tm.tm_hour < 0) {
                goto fail;
              }
              tm.tm_min = (int)pc.minutes;
              tm.tm_sec = (int)pc.seconds.tv_sec;
            } else {
              tm.tm_sec = 0;
              tm.tm_min = tm.tm_sec;

              pc.seconds.tv_nsec = (__syscall_slong_t)0;
            }
          } else {
            tm.tm_sec = 0;
            tm.tm_min = tm.tm_sec;
            tm.tm_hour = tm.tm_min;
            pc.seconds.tv_nsec = (__syscall_slong_t)0;
          }
        } else {
          tm.tm_sec = 0;
          tm.tm_min = tm.tm_sec;
          tm.tm_hour = tm.tm_min;
          pc.seconds.tv_nsec = (__syscall_slong_t)0;
        }
      }
      if ((pc.dates_seen | pc.days_seen) | pc.times_seen) {
        tm.tm_isdst = -1;
      }
      if (pc.local_zones_seen) {
        tm.tm_isdst = pc.local_isdst;
      }
      tm0 = tm;
      Start = mktime(&tm);
      tmp___12 =
          mktime_ok((struct tm const *)(&tm0), (struct tm const *)(&tm), Start);

      if (pc.days_seen) {
        if (!pc.dates_seen) {
          if (0L < pc.day_ordinal) {
            if (tm.tm_wday != pc.day_number) {
              tmp___13 = 1;
            } else {
            }
          } else {
            tmp___13 = 0;
          }
          tm.tm_mday = (int)((long)tm.tm_mday +
                             ((long)(((pc.day_number - tm.tm_wday) + 7) % 7) +
                              7L * (pc.day_ordinal - (long)tmp___13)));
          tm.tm_isdst = -1;
          Start = mktime(&tm);
          if (Start == -1L) {
            goto fail;
          }
        }
      }
      if ((pc.rel.year | pc.rel.month) | pc.rel.day) {
        year___1 = (int)((long)tm.tm_year + pc.rel.year);
        month = (int)((long)tm.tm_mon + pc.rel.month);
        day = (int)((long)tm.tm_mday + pc.rel.day);
        if ((((year___1 < tm.tm_year) ^ (pc.rel.year < 0L)) |
             ((month < tm.tm_mon) ^ (pc.rel.month < 0L))) |
            ((day < tm.tm_mday) ^ (pc.rel.day < 0L))) {
          goto fail;
        }
        tm.tm_year = year___1;
        tm.tm_mon = month;
        tm.tm_mday = day;
        tm.tm_hour = tm0.tm_hour;
        tm.tm_min = tm0.tm_min;
        tm.tm_sec = tm0.tm_sec;
        tm.tm_isdst = tm0.tm_isdst;
        Start = mktime(&tm);
        if (Start == -1L) {
          goto fail;
        }
      }
      if (pc.zones_seen) {
        delta = pc.time_zone * 60L;
        delta -= tm.tm_gmtoff;
        t1 = Start - delta;
        if ((Start < t1) != (delta < 0L)) {
          goto fail;
        }
        Start = t1;
      }

      t0 = Start;
      d1 = 3600L * pc.rel.hour;
      t1___0 = t0 + d1;
      d2 = 60L * pc.rel.minutes;
      t2 = t1___0 + d2;
      d3 = pc.rel.seconds;
      t3 = t2 + d3;
      d4 = (sum_ns - normalized_ns) / 1000000000L;
      t4 = t3 + d4;
      t5 = t4;
      if (((((((d1 / 3600L ^ pc.rel.hour) | (d2 / 60L ^ pc.rel.minutes)) |
              (long)((t1___0 < t0) ^ (d1 < 0L))) |
             (long)((t2 < t1___0) ^ (d2 < 0L))) |
            (long)((t3 < t2) ^ (d3 < 0L))) |
           (long)((t4 < t3) ^ (d4 < 0L))) |
          (long)(t5 != t4)) {
        goto fail;
      }
      result->tv_sec = t5;
      result->tv_nsec = normalized_ns;
    }
    goto done;
  fail:
    ok = (_Bool)0;
  done:
    if (tz_was_altered) {
      if (tz0) {
        tmp___14 = setenv("TZ", (char const *)tz0, 1);

      } else {
        tmp___15 = unsetenv("TZ");
      }
      ok = (_Bool)((int)ok & (tmp___16 == 0));
    }
    if ((unsigned long)tz0 != (unsigned long)(tz0buf)) {
      free((void *)tz0);
    }
    return (ok);
  }
}

extern int optind;

extern int ungetc(int __c, FILE *__stream);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
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

  char buf2[51];

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
        memcpy((void *)file_name___3, (void const *)dir, dir_len___0);
        if (add_slash) {
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
  size_t tmp___0;

  {

    if ((unsigned long)codeset == (unsigned long)((void *)0)) {
    }
    aliases = get_charset_aliases();
    while (1) {

      if (!((int const) * aliases != 0)) {
        goto while_break;
      }

      tmp = strlen(aliases);

      aliases += tmp___0 + 1UL;
    }
  while_break:;
    if ((int const) * (codeset + 0) == 0) {
      codeset = "ASCII";
    }
    return (codeset);
  }
}

char *(__attribute__((__warn_unused_result__)) imaxtostr)(intmax_t i,
                                                          char *buf___1) {
  char *p;

  {

    *p = (char)0;
    if (i < 0L) {
      while (1) {
        p--;
        *p = (char)(48L - i % 10L);
        i /= 10L;
      }

      p--;

    } else {

      ;
    }
    return (p);
  }
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
void gettime(struct timespec *ts) {
  int tmp;
  struct timeval tv;

  {
    tmp = clock_gettime(0, ts);
    if (tmp == 0) {
      return;
    }
    gettimeofday(&tv, (__timezone_ptr_t)((void *)0));
    ts->tv_sec = tv.tv_sec;
    ts->tv_nsec = tv.tv_usec * 1000L;
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
int(__attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp, off_t offset,
                                                int whence);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
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

          tmp___0 = lseek(tmp, offset, whence);
          pos = tmp___0;

          fp->_offset = pos;
          return (0);
        }
      }
    }
    tmp___1 = fseeko(fp, offset, whence);
    return (tmp___1);
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop

size_t fprintftime(FILE *s, char const *format, struct tm const *tp, int ut,
                   int ns);
static void fwrite_lowcase(FILE *fp, char const *src, size_t len) {
  int tmp;

  { ; }
}
static void fwrite_uppcase(FILE *fp, char const *src, size_t len) {

  size_t tmp___0;

  { ; }
}
static size_t strftime_case____0(_Bool upcase, FILE *s, char const *format,
                                 struct tm const *tp, int ut, int ns) {
  size_t maxsize;
  int hour12;
  char const *zone;
  size_t i;
  FILE *p;
  char const *f;
  int pad;
  int modifier;
  int digits;
  int number_value;
  unsigned int u_number_value;
  _Bool negative_number;
  _Bool always_output_a_sign;
  int tz_colon_mask;
  char const *subfmt;
  char sign_char;
  char *bufp;
  char buf___1[3UL + (((sizeof(time_t) * 8UL - 1UL) * 146UL) / 485UL + 2UL)];
  int width;
  _Bool to_lowcase;
  _Bool to_uppcase;
  size_t colons;
  _Bool change_case;
  int format_char;
  size_t _n;
  size_t _w;
  int tmp;
  size_t _incr;
  size_t tmp___0;
  size_t _delta;
  size_t _i;
  size_t _i___0;
  char const *tmp___1;
  size_t _n___0;
  size_t _w___0;
  int tmp___2;
  size_t _incr___0;
  size_t tmp___3;
  size_t _delta___0;
  size_t _i___1;

  size_t len;
  size_t tmp___4;
  size_t _n___1;
  size_t _w___1;
  int tmp___5;
  size_t _incr___1;
  size_t tmp___6;
  size_t _delta___1;
  size_t _i___3;
  size_t _i___4;
  char ufmt[5];
  char *u;
  char ubuf[1024];
  size_t len___0;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  char *tmp___10;
  size_t _n___2;
  size_t _w___2;
  int tmp___11;
  size_t _incr___2;
  size_t tmp___12;
  size_t _delta___2;
  size_t _i___5;
  size_t _i___6;
  int century;
  int tmp___13;
  int tmp___14;
  size_t _n___3;
  size_t _w___3;
  int tmp___15;
  size_t _incr___3;
  size_t tmp___16;
  size_t _delta___3;
  size_t _i___7;
  size_t _i___8;
  int padding;

  size_t _w___4;

  size_t tmp___18;

  size_t _i___10;

  size_t _delta___5;

  size_t _i___14;

  size_t _i___16;
  size_t _n___7;
  size_t _w___7;
  int tmp___23;
  size_t _incr___7;
  size_t tmp___24;
  size_t _delta___7;
  size_t _i___17;

  int j;
  size_t _n___8;
  size_t _w___8;
  int tmp___25;
  size_t _incr___8;
  size_t tmp___26;
  size_t _delta___8;
  size_t _i___19;

  struct tm ltm;
  time_t t;
  int d;
  int tmp___27;

  size_t _i___21;
  size_t _i___22;
  int year___1;
  int tmp___30;
  int year_adjust;
  int days;
  int tmp___31;
  int tmp___32;
  int d___0;
  int tmp___33;
  int tmp___34;
  int yy;
  int tmp___35;
  int yy___0;
  size_t _n___10;
  size_t tmp___36;
  size_t _w___10;
  int tmp___37;
  size_t _incr___10;
  size_t tmp___38;
  size_t _delta___10;
  size_t _i___23;
  size_t _i___24;
  int diff;
  int hour_diff;
  int min_diff;
  int sec_diff;
  int flen;
  size_t _n___11;
  size_t _w___11;
  int tmp___39;
  size_t _incr___11;
  size_t tmp___40;
  size_t _delta___11;

  size_t _i___26;

  {

    hour12 = (int)tp->tm_hour;
    i = (size_t)0;
    p = s;

    zone = (char const *)tp->tm_zone;

    f = format;
    while (1) {

      if (!((int const) * f != 0)) {
        goto while_break;
      }
      pad = 0;
      digits = 0;
      width = -1;
      to_lowcase = (_Bool)0;
      to_uppcase = upcase;
      change_case = (_Bool)0;
      if ((int const) * f != 37) {
        while (1) {

          if (width < 0) {
            tmp = 0;
          } else {
            tmp = width;
          }
          _w = (size_t)tmp;
          if (_n < _w) {
            tmp___0 = _w;
          } else {
            tmp___0 = _n;
          }
          _incr = tmp___0;
          if (_incr >= maxsize - i) {
            return ((size_t)0);
          }
          if (p) {
            if (digits == 0) {
              if (_n < _w) {
                _delta = (size_t)width - _n;
                if (pad == 48) {
                  while (1) {
                    _i = (size_t)0;
                    while (1) {

                      if (!(_i < _delta)) {
                      }
                      fputc('0', p);
                      _i++;
                    }
                  while_break___2:;
                    goto while_break___1;
                  }
                while_break___1:;
                } else {
                  while (1) {
                    _i___0 = (size_t)0;
                    while (1) {

                      if (!(_i___0 < _delta)) {
                        goto while_break___4;
                      }
                      fputc(' ', p);
                    }
                  while_break___4:;
                  }
                while_break___3:;
                }
              }
            }
            fputc((int)*f, p);
          }
          i += _incr;
          goto while_break___0;
        }
      while_break___0:;
        goto __Cont;
      }
      while (1) {
      while_continue___5:
        f++;
        if ((int const) * f == 95) {
          goto case_95;
        }
        if ((int const) * f == 45) {
          goto case_95;
        }
        if ((int const) * f == 48) {
          goto case_95;
        }
        if ((int const) * f == 94) {
        }
        if ((int const) * f == 35) {
          goto case_35;
        }
        goto switch_default;
      case_95:
        pad = (int)*f;
        goto while_continue___5;
      case_94:
        to_uppcase = (_Bool)1;

      case_35:
        change_case = (_Bool)1;

      switch_default:
        goto switch_break;
      switch_break:;
        goto while_break___5;
      }
    while_break___5:;
      if ((unsigned int)*f - 48U <= 9U) {
        width = 0;
        while (1) {

          if (width > 214748364) {

          } else {
            if (width == 214748364) {
              if ((int const) * f - 48 > 7) {

              } else {
                width *= 10;
                width += (int)((int const) * f - 48);
              }
            } else {
              width *= 10;
              width += (int)((int const) * f - 48);
            }
          }
          f++;
          if (!((unsigned int)*f - 48U <= 9U)) {
            goto while_break___6;
          }
        }
      while_break___6:;
      }
      if ((int const) * f == 69) {
        goto case_69;
      }
      if ((int const) * f == 79) {
        goto case_69;
      }
      goto switch_default___0;
    case_69:
      tmp___1 = f;
      f++;
      modifier = (int)*tmp___1;
      goto switch_break___0;
    switch_default___0:
      modifier = 0;
      goto switch_break___0;
    switch_break___0:
      format_char = (int)*f;
      if (format_char == 37) {
      }
      if (format_char == 97) {
        goto case_97;
      }
      if (format_char == 65) {
        goto case_65;
      }
      if (format_char == 98) {
        goto case_98;
      }

      if (format_char == 66) {
        goto case_66;
      }
      if (format_char == 99) {
        goto case_99;
      }
      if (format_char == 67) {
        goto case_67;
      }
      if (format_char == 120) {
        goto case_120;
      }
      if (format_char == 68) {
        goto case_68;
      }
      if (format_char == 100) {
        goto case_100;
      }

      if (format_char == 70) {
        goto case_70;
      }
      if (format_char == 72) {
        goto case_72;
      }
      if (format_char == 73) {
        goto case_73;
      }
      if (format_char == 107) {
        goto case_107;
      }

      if (format_char == 106) {
        goto case_106;
      }
      if (format_char == 77) {
        goto case_77;
      }
      if (format_char == 109) {
        goto case_109;
      }
      if (format_char == 78) {
        goto case_78;
      }
      if (format_char == 110) {
        goto case_110;
      }
      if (format_char == 80) {
        goto case_80;
      }
      if (format_char == 112) {
        goto case_112;
      }
      if (format_char == 82) {
        goto case_82;
      }
      if (format_char == 114) {
        goto case_114;
      }
      if (format_char == 83) {
        goto case_83;
      }
      if (format_char == 115) {
        goto case_115;
      }
      if (format_char == 88) {
        goto case_88;
      }
      if (format_char == 84) {
        goto case_84;
      }
      if (format_char == 116) {
        goto case_116;
      }
      if (format_char == 117) {
        goto case_117;
      }
      if (format_char == 85) {
        goto case_85;
      }
      if (format_char == 86) {
        goto case_86;
      }

      if (format_char == 71) {
        goto case_86;
      }
      if (format_char == 87) {
        goto case_87;
      }
      if (format_char == 119) {
        goto case_119;
      }
      if (format_char == 89) {
        goto case_89;
      }
      if (format_char == 121) {
        goto case_121;
      }
      if (format_char == 90) {
        goto case_90;
      }
      if (format_char == 58) {
        goto case_58;
      }
      if (format_char == 122) {
      }
      if (format_char == 0) {
        goto case_0___0;
      }

    case_37:
      if (modifier != 0) {
        goto bad_format;
      }
      while (1) {
        _n___0 = (size_t)1;

        _w___0 = (size_t)tmp___2;
        if (_n___0 < _w___0) {
          tmp___3 = _w___0;
        } else {
          tmp___3 = _n___0;
        }
        _incr___0 = tmp___3;
        if (_incr___0 >= maxsize - i) {
          return ((size_t)0);
        }
        if (p) {
          if (digits == 0) {
            if (_n___0 < _w___0) {
              _delta___0 = (size_t)width - _n___0;
              if (pad == 48) {
                while (1) {
                  _i___1 = (size_t)0;
                  while (1) {

                    if (!(_i___1 < _delta___0)) {
                    }
                    fputc('0', p);
                    _i___1++;
                  }
                while_break___9:;
                  goto while_break___8;
                }
              while_break___8:;
              } else {
                while (1) {

                while_break___11:;
                  goto while_break___10;
                }
              while_break___10:;
              }
            }
          }
          fputc((int)*f, p);
        }
        i += _incr___0;
        goto while_break___7;
      }
    while_break___7:;
      goto switch_break___1;
    case_97:
      if (modifier != 0) {
      }
      if (change_case) {
        to_uppcase = (_Bool)1;
      }
      goto underlying_strftime;
    case_65:
      if (modifier != 0) {
      }
      if (change_case) {
        to_uppcase = (_Bool)1;
      }
      goto underlying_strftime;
    case_98:
      if (change_case) {
        to_uppcase = (_Bool)1;
        to_lowcase = (_Bool)0;
      }
      if (modifier != 0) {
        goto bad_format;
      }
      goto underlying_strftime;
    case_66:
      if (modifier != 0) {
        goto bad_format;
      }
      if (change_case) {
      }
      goto underlying_strftime;
    case_99:
      if (modifier == 79) {
        goto bad_format;
      }
      goto underlying_strftime;
    subformat:
      tmp___4 = strftime_case____0(to_uppcase, (FILE *)((void *)0), subfmt, tp,
                                   ut, ns);
      len = tmp___4;
      while (1) {
        _n___1 = len;
        if (width < 0) {

        } else {
        }
        _w___1 = (size_t)tmp___5;
        if (_n___1 < _w___1) {
          tmp___6 = _w___1;
        } else {
          tmp___6 = _n___1;
        }
        _incr___1 = tmp___6;
        if (_incr___1 >= maxsize - i) {
          return ((size_t)0);
        }
        if (p) {
          if (digits == 0) {
            if (_n___1 < _w___1) {
              _delta___1 = (size_t)width - _n___1;
              if (pad == 48) {
                while (1) {
                  _i___3 = (size_t)0;
                  while (1) {

                    if (!(_i___3 < _delta___1)) {
                    }
                    fputc('0', p);
                  }
                while_break___14:;
                  goto while_break___13;
                }
              while_break___13:;
              } else {
                while (1) {
                  _i___4 = (size_t)0;
                  while (1) {

                    if (!(_i___4 < _delta___1)) {
                      goto while_break___16;
                    }

                    _i___4++;
                  }
                while_break___16:;
                }
              while_break___15:;
              }
            }
          }
          strftime_case____0(to_uppcase, p, subfmt, tp, ut, ns);
        }
        i += _incr___1;
        goto while_break___12;
      }
    while_break___12:;
      goto switch_break___1;
    underlying_strftime:

      tmp___7 = u;
      u++;
      *tmp___7 = (char)' ';

      u++;
      *tmp___8 = (char)'%';
      if (modifier != 0) {
        tmp___9 = u;
        u++;
        *tmp___9 = (char)modifier;
      }
      tmp___10 = u;
      u++;
      *tmp___10 = (char)format_char;
      *u = (char)'\000';
      len___0 = strftime(ubuf, sizeof(ubuf), (char const *)(ufmt), tp);
      if (len___0 != 0UL) {
        while (1) {
          _n___2 = len___0 - 1UL;
          if (width < 0) {

          } else {
          }
          _w___2 = (size_t)tmp___11;

          _incr___2 = tmp___12;
          if (_incr___2 >= maxsize - i) {
            return ((size_t)0);
          }
          if (p) {
            if (digits == 0) {
              if (_n___2 < _w___2) {
                _delta___2 = (size_t)width - _n___2;
                if (pad == 48) {
                  while (1) {
                    _i___5 = (size_t)0;
                    while (1) {

                      if (!(_i___5 < _delta___2)) {
                        goto while_break___19;
                      }
                      fputc('0', p);
                      _i___5++;
                    }
                  while_break___19:;
                    goto while_break___18;
                  }
                while_break___18:;
                } else {

                while_break___20:;
                }
              }
            }
            while (1) {

              if (to_lowcase) {
                fwrite_lowcase(p, (char const *)(ubuf + 1), _n___2);
              } else {
                if (to_uppcase) {
                  fwrite_uppcase(p, (char const *)(ubuf + 1), _n___2);
                } else {
                  fwrite((void const *)(ubuf + 1), _n___2, (size_t)1, p);
                }
              }
              goto while_break___22;
            }
          while_break___22:;
          }
          i += _incr___2;
          goto while_break___17;
        }
      while_break___17:;
      }
      goto switch_break___1;
    case_67:
      if (modifier == 79) {
        goto bad_format;
      }

      century = (int)(tp->tm_year / 100 + 19);
      if (tp->tm_year % 100 < 0) {

      } else {
        tmp___13 = 0;
      }
      century -= tmp___13;
      digits = 2;
      negative_number = (_Bool)(tp->tm_year < -1900);
      u_number_value = (unsigned int)century;
      goto do_signed_number;
    case_120:
      if (modifier == 79) {
        goto bad_format;
      }
      goto underlying_strftime;
    case_68:
      if (modifier != 0) {
        goto bad_format;
      }
      subfmt = "%m/%d/%y";
      goto subformat;
    case_100:
      if (modifier == 69) {
      }
      digits = 2;
      number_value = (int)tp->tm_mday;
      goto do_number;
    case_101:
      if (modifier == 69) {
      }
      digits = 2;
      number_value = (int)tp->tm_mday;
      goto do_number_spacepad;
    do_tz_offset:
      always_output_a_sign = (_Bool)1;
      goto do_number_body;
    do_number_spacepad:
      if (pad != 48) {
      }
    do_number:

      u_number_value = (unsigned int)number_value;
    do_signed_number:
      always_output_a_sign = (_Bool)0;

    do_number_body:

      bufp = buf___1 + sizeof(buf___1) / sizeof(buf___1[0]);
      if (negative_number) {
      }
      while (1) {

        if (tz_colon_mask & 1) {
          bufp--;
          *bufp = (char)':';
        }
        tz_colon_mask >>= 1;
        bufp--;
        *bufp = (char)(u_number_value % 10U + 48U);
        u_number_value /= 10U;
        if (!(u_number_value != 0U)) {
          if (!(tz_colon_mask != 0)) {
            goto while_break___23;
          }
        }
      }
    while_break___23:;
    do_number_sign_and_padding:
      if (digits < width) {
        digits = width;
      }
      if (negative_number) {
        sign_char = (char)'-';
      } else {
        if (always_output_a_sign) {

        } else {
          tmp___14 = 0;
        }
        sign_char = (char)tmp___14;
      }
      if (pad == 45) {
        if (sign_char) {
          while (1) {

            if (width < 0) {
              tmp___15 = 0;
            } else {
              tmp___15 = width;
            }
            _w___3 = (size_t)tmp___15;
            if (_n___3 < _w___3) {
              tmp___16 = _w___3;
            } else {
              tmp___16 = _n___3;
            }
            _incr___3 = tmp___16;
            if (_incr___3 >= maxsize - i) {
              return ((size_t)0);
            }
            if (p) {
              if (digits == 0) {
                if (_n___3 < _w___3) {
                  _delta___3 = (size_t)width - _n___3;
                  if (pad == 48) {

                  while_break___25:;
                  } else {
                    while (1) {
                      _i___8 = (size_t)0;
                      while (1) {

                        if (!(_i___8 < _delta___3)) {
                          goto while_break___28;
                        }
                        fputc(' ', p);
                      }
                    while_break___28:;
                      goto while_break___27;
                    }
                  while_break___27:;
                  }
                }
              }
              fputc((int)sign_char, p);
            }
            i += _incr___3;
            goto while_break___24;
          }
        while_break___24:;
        }
      } else {
        padding =
            (int)(((long)digits -
                   ((buf___1 + sizeof(buf___1) / sizeof(buf___1[0])) - bufp)) -
                  (long)(!(!sign_char)));
        if (padding > 0) {
          if (pad == 95) {
            if ((size_t)padding >= maxsize - i) {
              return ((size_t)0);
            }

            i += (size_t)padding;

          } else {
            if ((size_t)digits >= maxsize - i) {
              return ((size_t)0);
            }

            if (p) {
              while (1) {
                _i___14 = (size_t)0;
                while (1) {

                  if (!(_i___14 < (size_t)padding)) {
                    goto while_break___42;
                  }
                  fputc('0', p);
                  _i___14++;
                }
              while_break___42:;
                goto while_break___41;
              }
            while_break___41:;
            }
            i += (size_t)padding;
            width = 0;
          }
        } else {
        }
      }
      while (1) {
        _n___7 =
            (size_t)((buf___1 + sizeof(buf___1) / sizeof(buf___1[0])) - bufp);
        if (width < 0) {
          tmp___23 = 0;
        } else {
          tmp___23 = width;
        }
        _w___7 = (size_t)tmp___23;

        _incr___7 = tmp___24;
        if (_incr___7 >= maxsize - i) {
          return ((size_t)0);
        }
        if (p) {
          if (digits == 0) {
            if (_n___7 < _w___7) {
              _delta___7 = (size_t)width - _n___7;
              if (pad == 48) {

              while_break___49:;
              } else {

              while_break___51:;
              }
            }
          }
          while (1) {

            if (to_lowcase) {
              fwrite_lowcase(p, (char const *)bufp, _n___7);
            } else {
              if (to_uppcase) {

              } else {
                fwrite((void const *)bufp, _n___7, (size_t)1, p);
              }
            }
            goto while_break___53;
          }
        while_break___53:;
        }
        i += _incr___7;
        goto while_break___48;
      }
    while_break___48:;
      goto switch_break___1;
    case_70:
      if (modifier != 0) {
      }
      subfmt = "%Y-%m-%d";
      goto subformat;
    case_72:
      if (modifier == 69) {
      }

      number_value = (int)tp->tm_hour;
      goto do_number;
    case_73:
      if (modifier == 69) {
        goto bad_format;
      }
      digits = 2;
      number_value = hour12;
      goto do_number;
    case_107:
      if (modifier == 69) {
        goto bad_format;
      }
      digits = 2;
      number_value = (int)tp->tm_hour;
      goto do_number_spacepad;
    case_108:

      digits = 2;
      number_value = hour12;

    case_106:
      if (modifier == 69) {
        goto bad_format;
      }
      digits = 3;
      negative_number = (_Bool)(tp->tm_yday < -1);
      u_number_value = (unsigned int)tp->tm_yday + 1U;
      goto do_signed_number;
    case_77:
      if (modifier == 69) {
        goto bad_format;
      }
      digits = 2;
      number_value = (int)tp->tm_min;
      goto do_number;
    case_109:
      if (modifier == 69) {
      }
      digits = 2;

      u_number_value = (unsigned int)tp->tm_mon + 1U;
      goto do_signed_number;
    case_78:
      if (modifier == 69) {
        goto bad_format;
      }

      if (width == -1) {

      } else {
        j = width;
        while (1) {

          if (!(j < 9)) {
            goto while_break___54;
          }
          number_value /= 10;
          j++;
        }
      while_break___54:;
      }
      digits = width;

      goto do_number;
    case_110:
      while (1) {

        _w___8 = (size_t)tmp___25;

        _incr___8 = tmp___26;
        if (_incr___8 >= maxsize - i) {
          return ((size_t)0);
        }
        if (p) {
          if (digits == 0) {
            if (_n___8 < _w___8) {
              _delta___8 = (size_t)width - _n___8;
              if (pad == 48) {
                while (1) {

                  while (1) {

                    if (!(_i___19 < _delta___8)) {
                      goto while_break___57;
                    }
                    fputc('0', p);
                    _i___19++;
                  }
                while_break___57:;
                  goto while_break___56;
                }
              while_break___56:;
              } else {
                while (1) {

                  ;
                  goto while_break___58;
                }
              while_break___58:;
              }
            }
          }
          fputc('\n', p);
        }
        i += _incr___8;
        goto while_break___55;
      }
    while_break___55:;

    case_80:
      to_lowcase = (_Bool)1;
      format_char = 'p';
    case_112:

      goto underlying_strftime;
    case_82:
      subfmt = "%H:%M";

    case_114:
      goto underlying_strftime;
    case_83:
      if (modifier == 69) {
        goto bad_format;
      }
      digits = 2;
      number_value = (int)tp->tm_sec;
      goto do_number;
    case_115:
      ltm = (struct tm) * tp;
      t = mktime(&ltm);
      bufp = buf___1 + sizeof(buf___1) / sizeof(buf___1[0]);
      negative_number = (_Bool)(t < 0L);
      while (1) {
        d = (int)(t % 10L);
        t /= 10L;
        bufp--;
        if (negative_number) {
          tmp___27 = -d;
        } else {
          tmp___27 = d;
        }
        *bufp = (char)(tmp___27 + 48);
        if (!(t != 0L)) {
          goto while_break___60;
        }
      }
    while_break___60:
      digits = 1;
      always_output_a_sign = (_Bool)0;
      goto do_number_sign_and_padding;
    case_88:
      if (modifier == 79) {
        goto bad_format;
      }
      goto underlying_strftime;
    case_84:
      subfmt = "%H:%M:%S";
      goto subformat;
    case_116:

    while_break___61:;
      goto switch_break___1;
    case_117:
      digits = 1;
      number_value = (int)(((tp->tm_wday - 1) + 7) % 7 + 1);
      goto do_number;
    case_85:
      if (modifier == 69) {
        goto bad_format;
      }
      digits = 2;
      number_value = (int)(((tp->tm_yday - tp->tm_wday) + 7) / 7);
      goto do_number;
    case_86:
      if (modifier == 69) {
        goto bad_format;
      }
      if (tp->tm_year < 0) {
        tmp___30 = 300;
      } else {
        tmp___30 = -100;
      }
      year___1 = (int)(tp->tm_year + (int const)tmp___30);
      year_adjust = 0;
      tmp___31 = iso_week_days((int)tp->tm_yday, (int)tp->tm_wday);
      days = tmp___31;
      if (days < 0) {

        days = iso_week_days((int)(tp->tm_yday + (int const)(365 + tmp___32)),
                             (int)tp->tm_wday);
      } else {

        tmp___34 = iso_week_days(
            (int)(tp->tm_yday - (int const)(365 + tmp___33)), (int)tp->tm_wday);
        d___0 = tmp___34;
        if (0 <= d___0) {
          year_adjust = 1;
          days = d___0;
        }
      }
      if ((int const) * f == 103) {
        goto case_103___0;
      }
      if ((int const) * f == 71) {
        goto case_71___0;
      }
      goto switch_default___1;
    case_103___0:
      yy = (int)((tp->tm_year % 100 + (int const)year_adjust) % 100);
      digits = 2;
      if (0 <= yy) {
        number_value = yy;
      } else {
        if (tp->tm_year < (int const)(-1900 - year_adjust)) {

        } else {
          tmp___35 = yy + 100;
        }
        number_value = tmp___35;
      }
      goto do_number;
    case_71___0:
      digits = 4;
      negative_number = (_Bool)(tp->tm_year < (int const)(-1900 - year_adjust));
      u_number_value =
          ((unsigned int)tp->tm_year + 1900U) + (unsigned int)year_adjust;
      goto do_signed_number;
    switch_default___1:
      digits = 2;
      number_value = days / 7 + 1;
      goto do_number;

    case_87:

      digits = 2;
      number_value =
          (int)(((tp->tm_yday - ((tp->tm_wday - 1) + 7) % 7) + 7) / 7);
      goto do_number;
    case_119:
      if (modifier == 69) {
        goto bad_format;
      }
      digits = 1;
      number_value = (int)tp->tm_wday;
      goto do_number;
    case_89:
      if (modifier == 69) {
        goto underlying_strftime;
      }
      if (modifier == 79) {

      } else {
        digits = 4;
      }
      negative_number = (_Bool)(tp->tm_year < -1900);
      u_number_value = (unsigned int)tp->tm_year + 1900U;
      goto do_signed_number;
    case_121:
      if (modifier == 69) {
        goto underlying_strftime;
      }
      yy___0 = (int)(tp->tm_year % 100);
      if (yy___0 < 0) {
        if (tp->tm_year < -1900) {
          yy___0 = -yy___0;
        } else {
        }
      }
      digits = 2;
      number_value = yy___0;
      goto do_number;
    case_90:

      if (!zone) {
        zone = "";
      }
      while (1) {
        tmp___36 = strlen(zone);
        _n___10 = tmp___36;
        if (width < 0) {

        } else {
          tmp___37 = width;
        }
        _w___10 = (size_t)tmp___37;
        if (_n___10 < _w___10) {
          tmp___38 = _w___10;
        } else {
          tmp___38 = _n___10;
        }
        _incr___10 = tmp___38;
        if (_incr___10 >= maxsize - i) {
          return ((size_t)0);
        }
        if (p) {
          if (digits == 0) {
            if (_n___10 < _w___10) {
              _delta___10 = (size_t)width - _n___10;
              if (pad == 48) {
                while (1) {
                  _i___23 = (size_t)0;
                  while (1) {

                    _i___23++;
                  }
                while_break___68:;
                  goto while_break___67;
                }
              while_break___67:;
              } else {
                while (1) {
                  _i___24 = (size_t)0;

                while_break___70:;
                  goto while_break___69;
                }
              while_break___69:;
              }
            }
          }
          while (1) {

            if (to_lowcase) {

            } else {
              if (to_uppcase) {

              } else {
                fwrite((void const *)zone, _n___10, (size_t)1, p);
              }
            }
            goto while_break___71;
          }
        while_break___71:;
        }
        i += _incr___10;
        goto while_break___66;
      }
    while_break___66:;
      goto switch_break___1;
    case_58:
      colons = (size_t)1;

    while_break___72:;
      if ((int const) * (f + colons) != 122) {
        goto bad_format;
      }
      f += colons;
      goto do_z_conversion;
    case_122:
      colons = (size_t)0;
    do_z_conversion:
      if (tp->tm_isdst < 0) {
        goto switch_break___1;
      }
      diff = (int)tp->tm_gmtoff;
      hour_diff = (diff / 60) / 60;
      min_diff = (diff / 60) % 60;
      sec_diff = diff % 60;
      if (colons == 0UL) {
        goto case_0;
      }
      if (colons == 1UL) {
        goto tz_hh_mm;
      }
      if (colons == 2UL) {
        goto tz_hh_mm_ss;
      }
      if (colons == 3UL) {
        goto case_3;
      }
      goto switch_default___2;
    case_0:
      digits = 5;
      negative_number = (_Bool)(diff < 0);
      tz_colon_mask = 0;
      u_number_value = (unsigned int)(hour_diff * 100 + min_diff);
      goto do_tz_offset;
    tz_hh_mm:
      digits = 6;
      negative_number = (_Bool)(diff < 0);
      tz_colon_mask = 4;
      u_number_value = (unsigned int)(hour_diff * 100 + min_diff);
      goto do_tz_offset;
    tz_hh_mm_ss:

      u_number_value =
          (unsigned int)((hour_diff * 10000 + min_diff * 100) + sec_diff);
      goto do_tz_offset;
    case_3:
      if (sec_diff != 0) {
        goto tz_hh_mm_ss;
      }
      if (min_diff != 0) {
        goto tz_hh_mm;
      }
      digits = 3;

      u_number_value = (unsigned int)hour_diff;
      goto do_tz_offset;
    switch_default___2:
      goto bad_format;

    case_0___0:
      f--;
    bad_format:

        ;
      while (1) {
        _n___11 = (size_t)flen;
        if (width < 0) {
          tmp___39 = 0;
        } else {
          tmp___39 = width;
        }
        _w___11 = (size_t)tmp___39;
        if (_n___11 < _w___11) {
          tmp___40 = _w___11;
        } else {
          tmp___40 = _n___11;
        }
        _incr___11 = tmp___40;
        if (_incr___11 >= maxsize - i) {
          return ((size_t)0);
        }
        if (p) {
          if (digits == 0) {
            if (_n___11 < _w___11) {
              _delta___11 = (size_t)width - _n___11;
              if (pad == 48) {

              while_break___75:;
              } else {
                while (1) {
                  _i___26 = (size_t)0;
                  while (1) {

                    if (!(_i___26 < _delta___11)) {
                    }

                    _i___26++;
                  }
                while_break___78:;
                }
              while_break___77:;
              }
            }
          }
          while (1) {

            if (to_lowcase) {
              fwrite_lowcase(p, f + (1 - flen), _n___11);
            } else {
              if (to_uppcase) {
                fwrite_uppcase(p, f + (1 - flen), _n___11);
              } else {
                fwrite((void const *)(f + (1 - flen)), _n___11, (size_t)1, p);
              }
            }
            goto while_break___79;
          }
        while_break___79:;
        }
        i += _incr___11;
        goto while_break___74;
      }
    while_break___74:;
      goto switch_break___1;
    switch_break___1:;
    __Cont:
      f++;
    }
  while_break:;
    return (i);
  }
}
size_t fprintftime(FILE *s, char const *format, struct tm const *tp, int ut,
                   int ns) {
  size_t tmp;

  { tmp = strftime_case____0((_Bool)0, s, format, tp, ut, ns); }
}

int rpl_fflush(FILE *stream);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop

static void clear_ungetc_buffer_preserving_position(FILE *fp) {

  {}
}
int rpl_fflush(FILE *stream) {
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    if ((unsigned long)stream == (unsigned long)((void *)0)) {
      tmp = fflush(stream);

    } else {
      tmp___0 = __freading(stream);
      if (!(tmp___0 != 0)) {
        tmp = fflush(stream);
      }
    }
    clear_ungetc_buffer_preserving_position(stream);
    tmp___1 = fflush(stream);
  }
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
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

    fd = fileno(fp);
    if (fd < 0) {
      tmp = fclose(fp);
    }

    if (tmp___1 != 0) {
      tmp___2 = fileno(fp);
      tmp___3 = lseek(tmp___2, (__off_t)0, 1);
      if (tmp___3 != -1L) {

        tmp___4 = rpl_fflush(fp);
        if (tmp___4) {
          tmp___0 = __errno_location();
          saved_errno = *tmp___0;
        }
      }
    } else {
    }
    result = fclose(fp);
    if (saved_errno != 0) {
      tmp___5 = __errno_location();
      *tmp___5 = saved_errno;
    }
    return (result);
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
int volatile exit_failure = (int volatile)1;

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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
void close_stdout(void);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
int close_stream(FILE *stream);

static _Bool ignore_EPIPE;
void close_stdout(void) {

  int tmp___3;

  int tmp___5;

  {
    tmp___3 = close_stream(stdout);
    if (tmp___3 != 0) {
    }
    tmp___5 = close_stream(stderr);
    if (tmp___5 != 0) {
      _exit((int)exit_failure);
    }
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop

int close_stream(FILE *stream) {
  _Bool some_pending;

  _Bool prev_fail;
  int tmp___0;
  _Bool fclose_fail;
  int tmp___1;
  int *tmp___2;
  int *tmp___3;

  {

    prev_fail = (_Bool)(tmp___0 != 0);
    tmp___1 = rpl_fclose(stream);

    if (prev_fail) {
      goto _L___0;
    } else {
      if (fclose_fail) {
        if (some_pending) {
          goto _L___0;
        } else {

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

extern char *optarg;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop

__inline static char *timetostr(time_t t, char *buf___1) {
  char *tmp;

  { return (tmp); }
}
__inline static char *bad_cast(char const *s) {

  {}
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
static _Bool show_date(char const *format, struct timespec when);
static char const *const time_spec_string[6] = {
    "hours", "minutes", "date", "seconds", "ns", (char const *)((void *)0)};
static enum Time_spec const time_spec[5] = {
    (enum Time_spec const)3, (enum Time_spec const)4, (enum Time_spec const)0,
    (enum Time_spec const)1, (enum Time_spec const)2};
static char const rfc_2822_format[25] = {
    (char const)'%',   (char const)'a', (char const)',', (char const)' ',
    (char const)'%',   (char const)'d', (char const)' ', (char const)'%',
    (char const)'b',   (char const)' ', (char const)'%', (char const)'Y',
    (char const)' ',   (char const)'%', (char const)'H', (char const)':',
    (char const)'%',   (char const)'M', (char const)':', (char const)'%',
    (char const)'S',   (char const)' ', (char const)'%', (char const)'z',
    (char const)'\000'};
static char const short_options[14] = {
    (char const)'d', (char const)':',   (char const)'f', (char const)':',
    (char const)'I', (char const)':',   (char const)':', (char const)'r',
    (char const)':', (char const)'R',   (char const)'s', (char const)':',
    (char const)'u', (char const)'\000'};
static struct option const long_options___1[14] = {
    {"date", 1, (int *)((void *)0), 'd'},
    {"file", 1, (int *)((void *)0), 'f'},
    {"iso-8601", 2, (int *)((void *)0), 'I'},
    {"reference", 1, (int *)((void *)0), 'r'},
    {"rfc-822", 0, (int *)((void *)0), 'R'},
    {"rfc-2822", 0, (int *)((void *)0), 'R'},
    {"rfc-3339", 1, (int *)((void *)0), 128},
    {"set", 1, (int *)((void *)0), 's'},
    {"uct", 0, (int *)((void *)0), 'u'},
    {"utc", 0, (int *)((void *)0), 'u'},
    {"universal", 0, (int *)((void *)0), 'u'},
    {"help", 0, (int *)((void *)0), -130},
    {"version", 0, (int *)((void *)0), -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};

void usage(int status) {

  char *tmp___3;

  char *tmp___8;

  char *tmp___10;

  char *tmp___13;

  char *tmp___16;

  { exit(status); }
}
static _Bool batch_convert(char const *input_filename, char const *format) {
  _Bool ok;
  FILE *in_stream;
  char *line;
  size_t buflen;
  struct timespec when;

  int tmp___1;
  ssize_t line_length;
  ssize_t tmp___2;

  _Bool tmp___5;
  _Bool tmp___6;
  char const *tmp___7;
  int *tmp___8;
  int tmp___9;

  {
    tmp___1 = strcmp(input_filename, "-");
    if (tmp___1 == 0) {
      input_filename = (char const *)gettext("standard input");
      in_stream = stdin;
    } else {
      in_stream = fopen(input_filename, "r");
      if ((unsigned long)in_stream == (unsigned long)((void *)0)) {
      }
    }
    line = (char *)((void *)0);
    buflen = (size_t)0;
    ok = (_Bool)1;
    while (1) {
      tmp___2 = getline(&line, &buflen, in_stream);
      line_length = tmp___2;
      if (line_length < 0L) {
        goto while_break;
      }
      tmp___6 = parse_datetime(&when, (char const *)line,
                               (struct timespec const *)((void *)0));
      if (tmp___6) {
        tmp___5 = show_date(format, when);
        ok = (_Bool)((int)ok & (int)tmp___5);
      } else {
        if ((int)*(line + (line_length - 1L)) == 10) {
        }

        ok = (_Bool)0;
      }
    }
  while_break:
    tmp___9 = rpl_fclose(in_stream);
    if (tmp___9 == -1) {
      tmp___7 = quote(input_filename);
      tmp___8 = __errno_location();
      error(1, *tmp___8, "%s", tmp___7);
    }
    free((void *)line);
    return (ok);
  }
}
int main(int argc, char **argv);
static char const rfc_3339_format[3][32] = {
    {(char const)'%', (char const)'Y', (char const)'-', (char const)'%',
     (char const)'m', (char const)'-', (char const)'%', (char const)'d',
     (char const)'\000'},
    {(char const)'%',   (char const)'Y', (char const)'-', (char const)'%',
     (char const)'m',   (char const)'-', (char const)'%', (char const)'d',
     (char const)' ',   (char const)'%', (char const)'H', (char const)':',
     (char const)'%',   (char const)'M', (char const)':', (char const)'%',
     (char const)'S',   (char const)'%', (char const)':', (char const)'z',
     (char const)'\000'},
    {(char const)'%', (char const)'Y', (char const)'-', (char const)'%',
     (char const)'m', (char const)'-', (char const)'%', (char const)'d',
     (char const)' ', (char const)'%', (char const)'H', (char const)':',
     (char const)'%', (char const)'M', (char const)':', (char const)'%',
     (char const)'S', (char const)'.', (char const)'%', (char const)'N',
     (char const)'%', (char const)':', (char const)'z', (char const)'\000'}};
static char const iso_8601_format[5][32] = {
    {(char const)'%', (char const)'Y', (char const)'-', (char const)'%',
     (char const)'m', (char const)'-', (char const)'%', (char const)'d',
     (char const)'\000'},
    {(char const)'%', (char const)'Y', (char const)'-', (char const)'%',
     (char const)'m', (char const)'-', (char const)'%', (char const)'d',
     (char const)'T', (char const)'%', (char const)'H', (char const)':',
     (char const)'%', (char const)'M', (char const)':', (char const)'%',
     (char const)'S', (char const)'%', (char const)'z', (char const)'\000'},
    {(char const)'%', (char const)'Y', (char const)'-',   (char const)'%',
     (char const)'m', (char const)'-', (char const)'%',   (char const)'d',
     (char const)'T', (char const)'%', (char const)'H',   (char const)':',
     (char const)'%', (char const)'M', (char const)':',   (char const)'%',
     (char const)'S', (char const)',', (char const)'%',   (char const)'N',
     (char const)'%', (char const)'z', (char const)'\000'},
    {(char const)'%', (char const)'Y', (char const)'-', (char const)'%',
     (char const)'m', (char const)'-', (char const)'%', (char const)'d',
     (char const)'T', (char const)'%', (char const)'H', (char const)'%',
     (char const)'z', (char const)'\000'},
    {(char const)'%', (char const)'Y', (char const)'-', (char const)'%',
     (char const)'m', (char const)'-', (char const)'%', (char const)'d',
     (char const)'T', (char const)'%', (char const)'H', (char const)':',
     (char const)'%', (char const)'M', (char const)'%', (char const)'z',
     (char const)'\000'}};
int main(int argc, char **argv) {
  int optc;
  char const *datestr;
  char const *set_datestr;
  struct timespec when;
  _Bool set_date;
  char const *format;
  char *batch_file;
  char *reference;
  struct stat refstats;
  _Bool ok;
  int option_specified_date;
  char const *new_format;
  enum Time_spec i;
  ptrdiff_t tmp;
  enum Time_spec i___0;
  ptrdiff_t tmp___0;
  unsigned int tmp___1;
  char *tmp___2;
  int tmp___3;
  char *tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  char const *tmp___10;

  int tmp___13;

  char *tmp___15;
  _Bool valid_date;
  int *tmp___16;
  int tmp___17;

  int *tmp___21;
  int tmp___22;
  _Bool tmp___23;
  int tmp___24;

  {
    datestr = (char const *)((void *)0);

    set_date = (_Bool)0;
    format = (char const *)((void *)0);
    batch_file = (char *)((void *)0);
    reference = (char *)((void *)0);

    bindtextdomain("coreutils", "/usr/local/share/locale");

    while (1) {
      optc = getopt_long(argc, (char *const *)argv, short_options,
                         long_options___1, (int *)((void *)0));
      if (!(optc != -1)) {
        goto while_break;
      }
      new_format = (char const *)((void *)0);
      if (optc == 100) {
        goto case_100;
      }

      if (optc == 128) {
        goto case_128;
      }
      if (optc == 73) {
        goto case_73;
      }
      if (optc == 114) {
        goto case_114;
      }
      if (optc == 82) {
        goto case_82;
      }
      if (optc == 115) {
        goto case_115;
      }
      if (optc == 117) {
        goto case_117;
      }

      goto switch_default;
    case_100:
      datestr = (char const *)optarg;
      goto switch_break;
    case_102:

      goto switch_break;
    case_128:
      tmp = __xargmatch_internal("--rfc-3339", (char const *)optarg,
                                 time_spec_string + 2,
                                 (char const *)(time_spec + 2),
                                 sizeof(*(time_spec + 2)), argmatch_die);
      i = (enum Time_spec) * ((time_spec + 2) + tmp);
      new_format = rfc_3339_format[i];
      goto switch_break;
    case_73:
      if (optarg) {
        tmp___0 = __xargmatch_internal(
            "--iso-8601", (char const *)optarg, time_spec_string,
            (char const *)(time_spec), sizeof(time_spec[0]), argmatch_die);
        tmp___1 = (unsigned int)time_spec[tmp___0];
      } else {
        tmp___1 = 0U;
      }
      i___0 = (enum Time_spec)tmp___1;
      new_format = iso_8601_format[i___0];
      goto switch_break;
    case_114:
      reference = optarg;
      goto switch_break;
    case_82:
      new_format = rfc_2822_format;
      goto switch_break;
    case_115:
      set_datestr = (char const *)optarg;
      set_date = (_Bool)1;
      goto switch_break;
    case_117:
      tmp___2 = bad_cast("TZ=UTC0");
      tmp___3 = putenv(tmp___2);
      if (tmp___3 != 0) {
        xalloc_die();
      }
      goto switch_break;
    case_neg_130:

      goto switch_break;
    case_neg_131:

      exit(0);
      goto switch_break;
    switch_default:

    switch_break:;
      if (new_format) {

        format = new_format;
      }
    }
  while_break:;
    if (datestr) {
      tmp___5 = 1;
    } else {
      tmp___5 = 0;
    }
    if (batch_file) {

    } else {
      tmp___6 = 0;
    }

    option_specified_date = (tmp___5 + tmp___6) + tmp___7;
    if (option_specified_date > 1) {
    }
    if (set_date) {
      if (option_specified_date) {
      }
    }
    if (optind < argc) {

      if ((int)*(*(argv + optind) + 0) == 43) {

        tmp___13 = optind;
        optind++;
        format = (char const *)(*(argv + tmp___13) + 1);
      } else {
      }
    }
    if (!format) {

      if (!*format) {
      }
    }
    if ((unsigned long)batch_file != (unsigned long)((void *)0)) {
      ok = batch_convert((char const *)batch_file, format);
    } else {

      ok = (_Bool)1;
      if (!option_specified_date) {
        if (!set_date) {
          if (optind < argc) {
            set_date = (_Bool)1;
            datestr = (char const *)*(argv + optind);
            valid_date = posixtime(&when.tv_sec, datestr, 14U);
            when.tv_nsec = (__syscall_slong_t)0;
          } else {
            gettime(&when);
          }
        } else {
          goto _L;
        }
      } else {
      _L:
        if ((unsigned long)reference != (unsigned long)((void *)0)) {
          tmp___17 = stat((char const *)reference, &refstats);
          if (tmp___17 != 0) {
            tmp___16 = __errno_location();
          }
          when = get_stat_mtime((struct stat const *)(&refstats));
        } else {
          if (set_datestr) {
            datestr = set_datestr;
          }
          valid_date = parse_datetime(&when, datestr,
                                      (struct timespec const *)((void *)0));
        }
      }
      if (!valid_date) {
      }

      tmp___23 = show_date(format, when);
      ok = (_Bool)((int)ok & (int)tmp___23);
    }
    if (ok) {
      tmp___24 = 0;
    } else {
    }
    exit(tmp___24);
  }
}
static _Bool show_date(char const *format, struct timespec when) {
  struct tm *tm;
  char
      buf___1[(((sizeof(intmax_t) * 8UL - 1UL) * 146UL + 484UL) / 485UL + 1UL) +
              1UL];
  char *tmp;

  {
    tm = localtime((time_t const *)(&when.tv_sec));
    if (!tm) {
      tmp = timetostr(when.tv_sec, buf___1);

      return ((_Bool)0);
    }
    if ((unsigned long)format == (unsigned long)(rfc_2822_format)) {
      setlocale(2, "C");
    }
    fprintftime(stdout, format, (struct tm const *)tm, 0, (int)when.tv_nsec);
    fputc_unlocked('\n', stdout);
    if ((unsigned long)format == (unsigned long)(rfc_2822_format)) {
      setlocale(2, "");
    }
    return ((_Bool)1);
  }
}
