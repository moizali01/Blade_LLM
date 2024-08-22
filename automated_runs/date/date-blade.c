typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef unsigned long __ino_t;
typedef long __off_t;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef long __off64_t;
typedef long __ssize_t;
struct _IO_FILE;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

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
  void *(*reallocate)(void *, size_t);
  void (*free)(void *);
  void (*die)(size_t);
};
struct option {
  char const *name;
  int has_arg;
  int *flag;
  int val;
};
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
  __blksize_t st_blksize;
  __blkcnt_t st_blocks;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  __syscall_slong_t __glibc_reserved[3];
};
typedef int wchar_t;
typedef int nl_item;
typedef unsigned int wint_t;
typedef long __suseconds_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
typedef __time_t time_t;
union __anonunion___value_23 {
  unsigned int __wch;
};
struct __anonstruct___mbstate_t_22 {
  int __count;
  union __anonunion___value_23 __value;
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
typedef __clockid_t clockid_t;

typedef unsigned long reg_syntax_t;
typedef __off_t off_t;
typedef struct timezone *__restrict __timezone_ptr_t;
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
enum Time_spec {
  TIME_SPEC_DATE = 0,
  TIME_SPEC_SECONDS = 1,
  TIME_SPEC_NS = 2,
  TIME_SPEC_HOURS = 3,
  TIME_SPEC_MINUTES = 4
};
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));
int c_tolower(int c) __attribute__((__const__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));
int c_strcasecmp(char const *s1, char const *s2) {
  register unsigned char const *p1;
  register unsigned char const *p2;
  unsigned char c1;
  unsigned char c2;

  {

    p2 = (unsigned char const *)s2;
    if ((unsigned long)p1 == (unsigned long)p2) {
      return (0);
    }
    while (1) {
      c1 = (unsigned char)c_tolower((int)*p1);
      c2 = (unsigned char)c_tolower((int)*p2);
      if ((int)c1 == 0) {
        goto while_break;
      }
      p1++;
      p2++;
      if (!((int)c1 == (int)c2)) {
        goto while_break;
      }
    }
  while_break:;
    return ((int)c1 - (int)c2);
  }
}
_Bool c_isalpha(int c) __attribute__((__const__));
_Bool c_isspace(int c) __attribute__((__const__));
int c_toupper(int c) __attribute__((__const__));
_Bool c_isalpha(int c) __attribute__((__const__));
_Bool c_isalpha(int c) {
  int tmp;

  {
    if ((c & -33) >= 65) {
      if ((c & -33) <= 90) {
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
          tmp = 1;
        } else {

          tmp = 1;

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
    return ((_Bool)tmp);
  }
}
int c_tolower(int c) __attribute__((__const__));
int c_tolower(int c) {
  int tmp;

  {
    if (c >= 65) {
      if (c <= 90) {
        tmp = (c - 65) + 97;
      } else {
        tmp = c;
      }
    } else {
      tmp = c;
    }
    return (tmp);
  }
}
int c_toupper(int c) __attribute__((__const__));
int c_toupper(int c) {
  int tmp;

  {
    if (c >= 97) {
      if (c <= 122) {
        tmp = (c - 97) + 65;
      } else {
        tmp = c;
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
__inline void *xnmalloc(size_t n, size_t s) {
  int tmp;
  void *tmp___0;

  {
    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp = -1;
    } else {
    }
    if ((size_t)tmp / s < n) {
      xalloc_die();
    }
    tmp___0 = xmalloc(n * s);
    return (tmp___0);
  }
}
char *xcharalloc(size_t n) {
  void *tmp;
  void *tmp___0;
  void *tmp___1;

  {
    if (sizeof(char) == 1UL) {

      tmp___1 = tmp;
    } else {
      tmp___0 = xnmalloc(n, sizeof(char));
      tmp___1 = tmp___0;
    }
    return ((char *)tmp___1);
  }
}

char *last_component(char const *name) __attribute__((__pure__));
char *last_component(char const *name) {
  char const *base;
  char const *p;
  _Bool saw_slash;

  {
    base = name + 0;
    saw_slash = (_Bool)0;
    while (1) {

      if (!((int const) * base == 47)) {
        goto while_break;
      }
      base++;
    }
  while_break:
    p = base;

    if ((int const) * p == 47) {
      saw_slash = (_Bool)1;
    } else {
      if (saw_slash) {
        base = p;
        saw_slash = (_Bool)0;
      }
    }
    p++;

  while_break___0:;
    return ((char *)base);
  }
}
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(
    size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(
    void *__ptr);
char const *simple_backup_suffix;
void (*argmatch_die)(void);
ptrdiff_t __xargmatch_internal(char const *context, char const *arg,
                               char const *const *arglist, char const *vallist,
                               size_t valsize, void (*exit_fn)(void));
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) memcpy)(
    void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2,
                                          size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest,
                                          char const *__restrict __src);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
char const *simple_backup_suffix = "~";
ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize)
    __attribute__((__pure__));
void argmatch_invalid(char const *context, char const *value,
                      ptrdiff_t problem);
void argmatch_valid(char const *const *arglist, char const *vallist,
                    size_t valsize);
extern struct _IO_FILE *stderr;
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format,
                   ...);

extern void error(int __status, int __errnum, char const *__format, ...);
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char const *quote_n(int n, char const *arg);
char const *quote(char const *arg);
__attribute__((__noreturn__)) void usage(int status);
static void __argmatch_die(void) {

  {
    usage(1);
    return;
  }
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
  _Bool ambiguous;
  int tmp;
  size_t tmp___0;
  int tmp___1;

  {
    matchind = (ptrdiff_t)-1;
    ambiguous = (_Bool)0;
    arglen = strlen(arg);
    i = (size_t)0;

  while_break:;
    if (ambiguous) {
      return ((ptrdiff_t)-2);
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
    if (problem == -1L) {

      tmp___1 = tmp;
    } else {
      tmp___0 = gettext("ambiguous argument %s for %s");
      tmp___1 = tmp___0;
    }
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
  char const *last_val;
  char *tmp;
  char const *tmp___0;

  int tmp___2;

  {
    last_val = (char const *)((void *)0);
    tmp = gettext("Valid arguments are:");
    fputs_unlocked((char const *)tmp, stderr);
    i = (size_t)0;
    while (1) {

      if (!*(arglist + i)) {
        goto while_break;
      }

      i++;
    }
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
    tmp = argmatch(arg, arglist, vallist, valsize);

    if (res >= 0L) {
      return (res);
    }
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

extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strchr)(char const *__s, int __c)
    __attribute__((__pure__));

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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1), __leaf__)) memset)(void *__s, int __c, size_t __n);
void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
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
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
void *xrealloc(void *p, size_t n) {

  {
    if (!n) {
      if (p) {
        free(p);
        return ((void *)0);
      }
    }
    p = realloc(p, n);
    if (!p) {
      if (n) {
        xalloc_die();
      }
    }
    return (p);
  }
}
void *xmemdup(void const *p, size_t s)
    __attribute__((__malloc__, __alloc_size__(2)));

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

void xalloc_die(void) {
  char *tmp;

  {
    tmp = gettext("memory exhausted");
    error((int)exit_failure, 0, "%s", tmp);
    abort();
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
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2)
    __attribute__((__pure__));

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
extern size_t fwrite(void const *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
extern int printf(char const *__restrict __format, ...);
char const version_etc_copyright[47];
void version_etc_arn(FILE *stream, char const *command_name,
                     char const *package, char const *version,
                     char const *const *authors, size_t n_authors);

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
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  char *tmp___10;

  {
    if (command_name) {
      fprintf(stream, "%s (%s) %s\n", command_name, package, version);
    } else {
      fprintf(stream, "%s %s\n", package, version);
    }
    tmp = gettext("(C)");
    fprintf(stream, version_etc_copyright, tmp, 2013);
    tmp___0 =
        gettext("\nLicense GPLv3+: GNU GPL version 3 or later "
                "<http://gnu.org/licenses/gpl.html>.\nThis is free software: "
                "you are free to change and redistribute it.\nThere is NO "
                "WARRANTY, to the extent permitted by law.\n\n");
    fputs_unlocked((char const *)tmp___0, stream);
    if (n_authors == 0UL) {
      goto case_0;
    }
    if (n_authors == 1UL) {
      goto case_1;
    }
    if (n_authors == 2UL) {
      goto case_2;
    }
    if (n_authors == 3UL) {
      goto case_3;
    }
    if (n_authors == 4UL) {
      goto case_4;
    }
    if (n_authors == 5UL) {
      goto case_5;
    }
    if (n_authors == 6UL) {
      goto case_6;
    }

    if (n_authors == 8UL) {
      goto case_8;
    }
    if (n_authors == 9UL) {
      goto case_9;
    }

  case_0:
    abort();
  case_1:

    fprintf(stream, (char const *)tmp___1, *(authors + 0));

  case_2:
    tmp___2 = gettext("Written by %s and %s.\n");
    fprintf(stream, (char const *)tmp___2, *(authors + 0), *(authors + 1));
    goto switch_break;
  case_3:
    tmp___3 = gettext("Written by %s, %s, and %s.\n");
    fprintf(stream, (char const *)tmp___3, *(authors + 0), *(authors + 1),
            *(authors + 2));
    goto switch_break;
  case_4:
    tmp___4 = gettext("Written by %s, %s, %s,\nand %s.\n");
    fprintf(stream, (char const *)tmp___4, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3));
    goto switch_break;
  case_5:
    tmp___5 = gettext("Written by %s, %s, %s,\n%s, and %s.\n");
    fprintf(stream, (char const *)tmp___5, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4));
    goto switch_break;
  case_6:
    tmp___6 = gettext("Written by %s, %s, %s,\n%s, %s, and %s.\n");
    fprintf(stream, (char const *)tmp___6, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5));
    goto switch_break;
  case_7:
    tmp___7 = gettext("Written by %s, %s, %s,\n%s, %s, %s, and %s.\n");
    fprintf(stream, (char const *)tmp___7, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6));
    goto switch_break;
  case_8:
    tmp___8 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\nand %s.\n");
    fprintf(stream, (char const *)tmp___8, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6), *(authors + 7));
    goto switch_break;
  case_9:
    tmp___9 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, and %s.\n");

    goto switch_break;
  switch_default:
    tmp___10 = gettext(
        "Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, %s, and others.\n");
    fprintf(stream, (char const *)tmp___10, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6), *(authors + 7), *(authors + 8));
    goto switch_break;
  switch_break:;
    return;
  }
}
void version_etc_va(FILE *stream, char const *command_name, char const *package,
                    char const *version, va_list authors) {
  size_t n_authors;
  char const *authtab[10];
  char const *tmp;

  {
    n_authors = (size_t)0;
    while (1) {

      if (n_authors < 10UL) {
        tmp = __builtin_va_arg(authors, char const *);
        authtab[n_authors] = tmp;
        if (!((unsigned long)tmp != (unsigned long)((void *)0))) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      n_authors++;
    }
  while_break:
    version_etc_arn(stream, command_name, package, version,
                    (char const *const *)(authtab), n_authors);
    return;
  }
}
void version_etc(FILE *stream, char const *command_name, char const *package,
                 char const *version, ...) __attribute__((__sentinel__));
void version_etc(FILE *stream, char const *command_name, char const *package,
                 char const *version, ...) {
  va_list authors;

  {
    __builtin_va_start(authors, version);
    version_etc_va(stream, command_name, package, version, authors);
    __builtin_va_end(authors);
    return;
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
extern __attribute__((__nothrow__)) char *(
    __attribute__((__leaf__)) nl_langinfo)(nl_item __item);
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
    return ((struct timespec)st->st_mtim);
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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
char const *locale_charset(void);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) mbsinit)(
    mbstate_t const *__ps) __attribute__((__pure__));
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
unsigned int const is_basic_table[8];
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag, ...);
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
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) tolower)(
    int __c);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) toupper)(
    int __c);
__inline static int iso_week_days(int yday, int wday) {
  int big_enough_multiple_of_7;

  {
    big_enough_multiple_of_7 = 378;
    return (
        ((yday - (((yday - wday) + 4) + big_enough_multiple_of_7) % 7) + 4) -
        1);
  }
}

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
#pragma GCC diagnostic pop
extern
    __attribute__((__nothrow__)) int(__attribute__((__leaf__)) clock_settime)(
        clockid_t __clock_id, struct timespec const *__tp);

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
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
#pragma GCC diagnostic ignored "-Wtype-limits"
reg_syntax_t rpl_re_syntax_options;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
extern int getc_unlocked(FILE *__stream);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
extern FILE *fopen(char const *__restrict __filename,
                   char const *__restrict __modes);

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);

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
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
char const *const quoting_style_args[9];
enum quoting_style const quoting_style_vals[8];

char *quotearg_char(char const *arg, char ch);
char *quotearg_char_mem(char const *arg, size_t argsize, char ch);
struct quoting_options quote_quoting_options;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) iswprint)(
    wint_t __wc);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
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
    if (o) {

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
static struct quoting_options
quoting_options_from_style(enum quoting_style style) {
  struct quoting_options o;
  unsigned int tmp;

  {
    o.style = (enum quoting_style)0;
    o.flags = 0;
    o.quote_these_too[0] = 0U;
    tmp = 1U;
    while (1) {

      if (!(!(tmp >= 8U))) {
        goto while_break;
      }
      o.quote_these_too[tmp] = 0U;
      tmp++;
    }
  while_break:
    o.left_quote = (char const *)((void *)0);
    o.right_quote = (char const *)((void *)0);
    if ((unsigned int)style == 8U) {
      abort();
    }
    o.style = style;
    return (o);
  }
}
static char const *gettext_quote(char const *msgid, enum quoting_style s) {
  char const *translation;
  char const *tmp;
  char const *locale_code;
  char const *tmp___0;
  int tmp___1;
  char const *tmp___2;
  int tmp___3;
  char const *tmp___4;

  {
    tmp = (char const *)gettext(msgid);
    translation = tmp;
    if ((unsigned long)translation != (unsigned long)msgid) {
      return (translation);
    }
    locale_code = locale_charset();

    if (tmp___1 == 0) {
      if ((int const) * (msgid + 0) == 96) {
        tmp___0 = "\342\200\230";
      } else {
        tmp___0 = "\342\200\231";
      }
      return (tmp___0);
    }
    tmp___3 = c_strcasecmp(locale_code, "GB18030");
    if (tmp___3 == 0) {
      if ((int const) * (msgid + 0) == 96) {
        tmp___2 = "\241\ae";
      } else {
        tmp___2 = "\241\257";
      }
      return (tmp___2);
    }
    if ((unsigned int)s == 7U) {
      tmp___4 = "\"";
    } else {
      tmp___4 = "\'";
    }
    return (tmp___4);
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

    backslash_escapes = (_Bool)0;
    tmp = __ctype_get_mb_cur_max();
    unibyte_locale = (_Bool)(tmp == 1UL);
    elide_outer_quotes = (_Bool)((flags & 2) != 0);

    if ((unsigned int)quoting_style == 3U) {
    }
    if ((unsigned int)quoting_style == 5U) {
      goto case_5;
    }
    if ((unsigned int)quoting_style == 6U) {
      goto case_6;
    }

    if ((unsigned int)quoting_style == 8U) {
    }
    if ((unsigned int)quoting_style == 1U) {
      goto case_1;
    }

    if ((unsigned int)quoting_style == 0U) {
      goto case_0;
    }
    goto switch_default;

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
    backslash_escapes = (_Bool)1;
    quote_string = "\"";
    quote_string_len = (size_t)1;
    goto switch_break;
  case_5:

    elide_outer_quotes = (_Bool)0;

  case_6:
    if ((unsigned int)quoting_style != 8U) {
      left_quote = gettext_quote("`", quoting_style);
      right_quote = gettext_quote("\'", quoting_style);
    }
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

    while (1) {

      *(buffer + len) = (char)'\'';
    }

    ;

    quote_string = "\'";

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
      if (backslash_escapes) {
        if (quote_string_len) {
          if (i + quote_string_len <= argsize) {
            tmp___0 = memcmp((void const *)(arg + i),
                             (void const *)quote_string, quote_string_len);
            if (tmp___0 == 0) {
              if (elide_outer_quotes) {
                goto force_outer_quoting_style;
              }
              is_right_quote = (_Bool)1;
            }
          }
        }
      }
      c = (unsigned char)*(arg + i);

      if ((int)c == 63) {
        goto case_63;
      }
      if ((int)c == 7) {
        goto case_7___0;
      }

      if ((int)c == 12) {
        goto case_12;
      }

      if ((int)c == 13) {
      }

      goto case_9;

      if ((int)c == 11) {
        goto case_11;
      }
      if ((int)c == 92) {
        goto case_92;
      }

      if ((int)c == 125) {
        goto case_123;
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

      if ((int)c == 34) {
        goto case_32;
      }

      goto case_32;

      if ((int)c == 41) {
        goto case_32;
      }

      goto case_32;

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
      }

      if ((int)c == 124) {
        goto case_32;
      }
      if ((int)c == 39) {
        goto case_39___0;
      }

      if ((int)c == 43) {
        goto case_37;
      }
      if ((int)c == 44) {
        goto case_37;
      }

      if ((int)c == 46) {
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
        goto case_37;
      }

      if ((int)c == 54) {
        goto case_37;
      }
      if ((int)c == 55) {
        goto case_37;
      }

      goto case_37;

      goto case_37;

      if ((int)c == 58) {
        goto case_37;
      }

      if ((int)c == 66) {
        goto case_37;
      }
      if ((int)c == 67) {
        goto case_37;
      }
      if ((int)c == 68) {
        goto case_37;
      }

      goto case_37;

      if ((int)c == 70) {
        goto case_37;
      }
      if ((int)c == 71) {
        goto case_37;
      }

      if ((int)c == 74) {
        goto case_37;
      }
      if ((int)c == 75) {
        goto case_37;
      }

      if ((int)c == 77) {
        goto case_37;
      }
      if ((int)c == 78) {
        goto case_37;
      }
      if ((int)c == 79) {
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

      if ((int)c == 86) {
        goto case_37;
      }
      if ((int)c == 87) {
        goto case_37;
      }

      if ((int)c == 89) {
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

      goto case_37;

      if ((int)c == 104) {
        goto case_37;
      }

      if ((int)c == 107) {
        goto case_37;
      }
      if ((int)c == 108) {
        goto case_37;
      }
      if ((int)c == 109) {
      }

      if ((int)c == 111) {
        goto case_37;
      }

      if ((int)c == 113) {
        goto case_37;
      }
      if ((int)c == 114) {
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
      if ((int)c == 121) {
        goto case_37;
      }
      if ((int)c == 122) {
        goto case_37;
      }
      goto switch_default___2;
    case_0___0:
      if (backslash_escapes) {
        if (elide_outer_quotes) {
          goto force_outer_quoting_style;
        }
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)'\\';
          }
          len++;
          goto while_break___4;
        }
      while_break___4:;
        if (i + 1UL < argsize) {
          if (48 <= (int)*(arg + (i + 1UL))) {
          }
        }
        c = (unsigned char)'0';
      } else {

        goto __Cont;
      }

    case_63:
      if ((unsigned int)quoting_style == 2U) {
        goto case_2___0;
      }
      if ((unsigned int)quoting_style == 3U) {
        goto case_3___0;
      }
      goto switch_default___1;
    case_2___0:

      goto force_outer_quoting_style;

      goto switch_break___1;
    case_3___0:
      if (flags & 4) {
        if (i + 2UL < argsize) {
          if ((int const) * (arg + (i + 1UL)) == 63) {
            if ((int const) * (arg + (i + 2UL)) == 33) {
            }
            if ((int const) * (arg + (i + 2UL)) == 39) {
              goto case_33;
            }

            goto case_33;

            if ((int const) * (arg + (i + 2UL)) == 60) {
            }

            goto case_33;

          case_33:
            if (elide_outer_quotes) {
              goto force_outer_quoting_style;
            }
            c = (unsigned char)*(arg + (i + 2UL));
            i += 2UL;
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char)'?';
              }
              len++;
              goto while_break___7;
            }
          while_break___7:;

            if (len < buffersize) {
              *(buffer + len) = (char)'\"';
            }
            len++;
            goto while_break___8;

          while_break___8:;
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char)'\"';
              }
              len++;
              goto while_break___9;
            }
          while_break___9:;

            if (len < buffersize) {
            }
            len++;
            goto while_break___10;

          while_break___10:;

          switch_default___0:
            goto switch_break___2;
          switch_break___2:;
          }
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

      goto c_escape;
    case_12:
      esc = (unsigned char)'f';
      goto c_escape;
    case_10:

      goto c_and_shell_escape;
    case_13:
      esc = (unsigned char)'r';

    case_9:
      esc = (unsigned char)'t';
      goto c_and_shell_escape;
    case_11:
      esc = (unsigned char)'v';

    case_92:
      esc = c;
      if (backslash_escapes) {
        if (elide_outer_quotes) {
          if (quote_string_len) {
            goto store_c;
          }
        }
      }
    c_and_shell_escape:
      if ((unsigned int)quoting_style == 2U) {
        if (elide_outer_quotes) {
          goto force_outer_quoting_style;
        }
      }
    c_escape:
      if (backslash_escapes) {
        c = esc;
        goto store_escape;
      }
      goto switch_break___0;
    case_123:
      if (argsize == 0xffffffffffffffffUL) {
        tmp___1 = (int const) * (arg + 1) == 0;
      } else {
        tmp___1 = argsize == 1UL;
      }
      if (!tmp___1) {
        goto switch_break___0;
      }
    case_35:
      if (i != 0UL) {
        goto switch_break___0;
      }
    case_32:
      if ((unsigned int)quoting_style == 2U) {
        if (elide_outer_quotes) {
          goto force_outer_quoting_style;
        }
      }
      goto switch_break___0;
    case_39___0:
      if ((unsigned int)quoting_style == 2U) {

      while_break___11:;
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)'\\';
          }
        }
      while_break___12:;
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)'\'';
          }

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

      } else {

        printable = (_Bool)1;
        if (argsize == 0xffffffffffffffffUL) {
          argsize = strlen(arg);
        }
        while (1) {
          tmp___3 = mbrtowc(&w, arg + (i + m), argsize - (i + m), &mbstate);
          bytes = tmp___3;
          if (bytes == 0UL) {
            goto while_break___14;
          } else {
          }
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

            goto while_break___17;

            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char)c;
              }
              len++;
            }
          while_break___22:

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
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)'\\';
        }
        len++;
        goto while_break___23;
      }
    while_break___23:;
    store_c:

      if (len < buffersize) {
        *(buffer + len) = (char)c;
      }
      len++;
      goto while_break___24;

    while_break___24:;
    __Cont:
      i++;
    }
  while_break___3:;
    if (len == 0UL) {
      if ((unsigned int)quoting_style == 2U) {
        if (elide_outer_quotes) {
        }
      }
    }
    if (quote_string) {
      if (!elide_outer_quotes) {
        while (1) {

          while (1) {

            if (len < buffersize) {
            }
            len++;
            goto while_break___26;
          }
        while_break___26:
          quote_string++;
        }
      while_break___25:;
      }
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
      if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
        tmp___0 = -1;
      } else {
        tmp___0 = -2;
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

    return (val);
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;
  struct quoting_options tmp;
  char *tmp___0;

  {

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
  }
}
char *quotearg_char(char const *arg, char ch) {
  char *tmp;

  { tmp = quotearg_char_mem(arg, (size_t)-1, ch); }
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
char const *quote_n_mem(int n, char const *arg, size_t argsize) {
  char const *tmp;

  {}
}
char const *quote_n(int n, char const *arg) {
  char const *tmp;

  {
    tmp = quote_n_mem(n, arg, (size_t)-1);
    return (tmp);
  }
}
char const *quote(char const *arg) {
  char const *tmp;

  { return (tmp); }
}
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
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
char const *program_name;

extern char *program_invocation_name;
extern char *program_invocation_short_name;

extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strrchr)(char const *__s, int __c)
    __attribute__((__pure__));
char const *program_name = (char const *)((void *)0);
void set_program_name(char const *argv0) {
  char const *slash;
  char const *base;
  int tmp;
  int tmp___0;

  {
    if ((unsigned long)argv0 == (unsigned long)((void *)0)) {
      fputs("A NULL argv[0] was passed through an exec system call.\n", stderr);
      abort();
    }

    if ((unsigned long)slash != (unsigned long)((void *)0)) {
      base = slash + 1;
    } else {
    }
    if (base - argv0 >= 7L) {
      tmp___0 = strncmp(base - 7, "/.libs/", (size_t)7);
      if (tmp___0 == 0) {
        argv0 = base;
        tmp = strncmp(base, "lt-", (size_t)3);
        if (tmp == 0) {
          argv0 = base + 3;
          program_invocation_short_name = (char *)argv0;
        }
      }
    }
    program_name = argv0;
    program_invocation_name = (char *)argv0;
    return;
  }
}

extern __attribute__((__nothrow__)) struct tm *(
    __attribute__((__leaf__)) localtime)(time_t const *__timer);
_Bool posixtime(time_t *p, char const *s, unsigned int syntax_bits);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) stpcpy)(char *__restrict __dest,
                                          char const *__restrict __src);
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
    abort();
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

  int *tmp___2;
  int *tmp___3;
  int *tmp___4;
  int *tmp___5;
  int tmp___6;
  int seconds;

  {

    tmp = strlen(s);
    s_len = tmp;
    if (syntax_bits & 8U) {

      if (dot) {
        tmp___0 = (size_t)(dot - s);
      } else {
        tmp___0 = s_len;
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

      if (s_len - len != 3UL) {
      }
    }

    while (1) {

      goto while_break;

      if (!((unsigned int)*(s + i) - 48U <= 9U)) {
        return (1);
      }
      i++;
    }
  while_break:

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

    tmp___2 = p;
    p++;

    tmp___3 = p;
    p++;
    tm->tm_mday = *tmp___3;
    tmp___4 = p;

    tm->tm_hour = *tmp___4;
    tmp___5 = p;

    tm->tm_min = *tmp___5;
    len -= 4UL;
    if (syntax_bits & 2U) {

      if (tmp___6) {
        return (1);
      }
    }

    tm->tm_sec = 0;

    if (!((unsigned int)*(dot + 0) - 48U <= 9U)) {
      return (1);
    } else {
      if (!((unsigned int)*(dot + 1) - 48U <= 9U)) {
        return (1);
      }
    }
    seconds = (10 * (int)((int const) * (dot + 0) - 48) + (int)*(dot + 1)) - 48;
    tm->tm_sec = seconds;

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
  char *b;
  char *tmp___0;
  _Bool tmp___1;

  {
    tmp = posix_time_parse(&tm0, s, syntax_bits);
    if (tmp) {
      return ((_Bool)0);
    }
    tm1 = tm0;
    tm1.tm_isdst = -1;
    t = mktime(&tm1);
    if (t != -1L) {
      tm = (struct tm const *)(&tm1);
    } else {

      if (!tm) {
        return ((_Bool)0);
      }
    }
    if ((((((tm0.tm_year ^ (int)tm->tm_year) | (tm0.tm_mon ^ (int)tm->tm_mon)) |
           (tm0.tm_mday ^ (int)tm->tm_mday)) |
          (tm0.tm_hour ^ (int)tm->tm_hour)) |
         (tm0.tm_min ^ (int)tm->tm_min)) |
        (tm0.tm_sec ^ (int)tm->tm_sec)) {
      if (tm0.tm_sec != 60) {
        return ((_Bool)0);
      }
      tmp___0 = stpcpy(buf___1, s);
      b = tmp___0;

      tmp___1 = posixtime(&dummy, (char const *)(buf___1), syntax_bits);
      if (!tmp___1) {
        return ((_Bool)0);
      }
    }

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
static unsigned char to_uchar___0(char ch) {

  { return ((unsigned char)ch); }
}
static int yylex(union YYSTYPE *lvalp, parser_control *pc);
static int yyerror(parser_control const *pc __attribute__((__unused__)),
                   char const *s __attribute__((__unused__)));
static long time_zone_hhmm(parser_control *pc, textint s, long mm);
static void digits_to_date_time(parser_control *pc, textint text_int) {

  { return; }
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
    return;
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
    if (!yymsg) {
      yymsg = "Deleting";
    }

  switch_default:
    goto switch_break;
  switch_break:;
    return;
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
    yylen = 0;
    yytoken = 0;
    yyss = yyssa;
    yyvs = yyvsa;
    yystacksize = 20UL;
    yystate = 0;
    yyerrstatus = 0;
    yynerrs = 0;
    yychar = -2;
    yyssp = yyss;
    yyvsp = yyvs;

  yynewstate:
    yyssp++;
  yysetstate:
    *yyssp = (yytype_int16)yystate;
    if ((unsigned long)((yyss + yystacksize) - 1) <= (unsigned long)yyssp) {
      yysize = (unsigned long)((yyssp - yyss) + 1L);
      if (20UL <= yystacksize) {
        goto yyexhaustedlab;
      }
      yystacksize *= 2UL;

      yyss1 = yyss;

      if (!yyptr) {
        goto yyexhaustedlab;
      }
      while (1) {
        __builtin_memcpy((void *)(&yyptr->yyss_alloc), (void const *)yyss,
                         yysize * sizeof(*yyss));
        yyss = &yyptr->yyss_alloc;
        yynewbytes =
            yystacksize * sizeof(*yyss) + (sizeof(union yyalloc) - 1UL);

        goto while_break;
      }
    while_break:;

    while_break___0:;
      if ((unsigned long)yyss1 != (unsigned long)(yyssa)) {
        free((void *)yyss1);
      }
      yyssp = (yyss + yysize) - 1;

      if ((unsigned long)((yyss + yystacksize) - 1) <= (unsigned long)yyssp) {
        goto yyabortlab;
      }
    }
    if (yystate == 12) {
      goto yyacceptlab;
    }
    goto yybackup;
  yybackup:
    yyn = (int)yypact[yystate];

    if (yychar == -2) {
      yychar = yylex(&yylval, pc);
    }
    if (yychar <= 0) {
      yytoken = 0;

    } else {
      if ((unsigned int)yychar <= 277U) {
        yytoken = (int)yytranslate[yychar];
      } else {
        yytoken = 2;
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
    if (yyn <= 0) {
      if (yyn == 0) {

      } else {

        goto yyerrlab;
      }

      goto yyreduce;
    }

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

  yyreduce:

    yyval = *(yyvsp + (1 - yylen));
    if (yyn == 4) {
      goto case_4;
    }
    if (yyn == 7) {
      goto case_7;
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

    if (yyn == 22) {
    }
    if (yyn == 23) {
      goto case_23;
    }

    if (yyn == 28) {
      goto case_28;
    }

    if (yyn == 31) {
      goto case_31;
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

    if (yyn == 43) {
      goto case_43;
    }
    if (yyn == 44) {
      goto case_44;
    }
    if (yyn == 45) {
      goto case_45;
    }
    if (yyn == 46) {
    }
    if (yyn == 47) {
      goto case_47;
    }
    if (yyn == 48) {
      goto case_48;
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
    if (yyn == 64) {
      goto case_64;
    }
    if (yyn == 65) {
      goto case_65;
    }
    if (yyn == 66) {
      goto case_66;
    }
    if (yyn == 67) {
    }

    if (yyn == 69) {
      goto case_69;
    }
    if (yyn == 70) {
    }
    if (yyn == 71) {
    }

    if (yyn == 75) {
      goto case_75;
    }
    if (yyn == 76) {
      goto case_76;
    }

    if (yyn == 78) {
      goto case_78;
    }

    if (yyn == 80) {
      goto case_80;
    }
    if (yyn == 81) {
      goto case_81;
    }
    if (yyn == 85) {
    }
    if (yyn == 87) {
      goto case_87;
    }

    if (yyn == 91) {
      goto case_91;
    }
    goto switch_default;
  case_4:

    pc->timespec_seen = (_Bool)1;
    goto switch_break;
  case_7:
    (pc->times_seen)++;
    (pc->dates_seen)++;
    goto switch_break;
  case_8:
    (pc->times_seen)++;
    goto switch_break;
  case_9:
    (pc->local_zones_seen)++;

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

    pc->meridian = (int)(yyvsp + 0)->intval;
    goto switch_break;
  case_19:

    goto switch_break;
  case_20:
    set_hhmmss(pc, (yyvsp + -5)->textintval.value,
               (yyvsp + -3)->textintval.value, (yyvsp + -1)->timespec.tv_sec,
               (yyvsp + -1)->timespec.tv_nsec);
    pc->meridian = (int)(yyvsp + 0)->intval;

  case_22:
    set_hhmmss(pc, (yyvsp + -1)->textintval.value, 0L, (time_t)0, 0L);

    goto switch_break;
  case_23:
    set_hhmmss(pc, (yyvsp + -3)->textintval.value,
               (yyvsp + -1)->textintval.value, (time_t)0, 0L);
    pc->meridian = 2;
    goto switch_break;
  case_24:
    set_hhmmss(pc, (yyvsp + -5)->textintval.value,
               (yyvsp + -3)->textintval.value, (yyvsp + -1)->timespec.tv_sec,
               (yyvsp + -1)->timespec.tv_nsec);
    pc->meridian = 2;

  case_27:
    (pc->zones_seen)++;

    goto switch_break;
  case_28:
    pc->local_isdst = (int)(yyvsp + 0)->intval;
    pc->dsts_seen += (size_t)(0L < (yyvsp + 0)->intval);
    goto switch_break;
  case_29:

    pc->dsts_seen += (size_t)((0L < (yyvsp + -1)->intval) + 1);
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

    goto switch_break;
  case_34:

    pc->time_zone = (yyvsp + -2)->intval + tmp___0;
    goto switch_break;
  case_35:

    goto switch_break;
  case_36:

  case_37:

    pc->day_number = (int)(yyvsp + 0)->intval;
    goto switch_break;
  case_38:
    pc->day_ordinal = 0L;
    pc->day_number = (int)(yyvsp + -1)->intval;
    goto switch_break;
  case_39:

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

    } else {
      yystate = (int)yydefgoto[yyn - 28];
    }
    goto yynewstate;
  yyerrlab:
    if (!yyerrstatus) {
    }
    if (yyerrstatus == 3) {
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

      goto yyabortlab;

      yydestruct("Error: popping", (int)yystos[yystate], yyvsp, pc);
      yyvsp--;
      yyssp--;
      yystate = (int)*yyssp;
    }
  while_break___1:
    yyvsp++;
    *yyvsp = yylval;
    yystate = yyn;
    goto yynewstate;
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;
  yyabortlab:
    yyresult = 1;
    goto yyreturn;
  yyexhaustedlab:

  yyreturn:
    if (yychar != -2) {
      yydestruct("Cleanup: discarding lookahead", yytoken, &yylval, pc);
    }
    yyvsp -= yylen;
    yyssp -= yylen;
    while (1) {

      if (!((unsigned long)yyssp != (unsigned long)yyss)) {
        goto while_break___2;
      }
      yydestruct("Cleanup: popping", (int)yystos[*yyssp], yyvsp, pc);
      yyvsp--;
      yyssp--;
    }
  while_break___2:;
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

static long time_zone_hhmm(parser_control *pc, textint s, long mm) {
  long n_minutes;
  long tmp;
  int tmp___0;

  {
    if (s.digits <= 2UL) {
      if (mm < 0L) {
        s.value *= 100L;
      }
    }
    if (mm < 0L) {
      n_minutes = (s.value / 100L) * 60L + s.value % 100L;
    } else {
      if (s.negative) {

      } else {
        tmp = mm;
      }
      n_minutes = s.value * 60L + tmp;
    }
    tmp___0 = abs((int)n_minutes);

    (pc->zones_seen)++;

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
    goto switch_default;
  switch_default:
    if (0L <= hours) {
      if (hours < 24L) {
        tmp = hours;
      } else {
        tmp = -1L;
      }
    } else {
      tmp = -1L;
    }
    return ((int)tmp);
  case_0:

    return ((int)tmp___1);
  case_1:
    if (0L < hours) {
      if (hours < 12L) {
        tmp___3 = hours + 12L;
      } else {
        goto _L___0;
      }
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

      while (1) {

        if (!tp->name) {
          goto while_break___5;
        }
        if ((int)*(word___0 + 0) == (int)*(tp->name + 0)) {
          return (tp);
        }
        tp++;
      }
    while_break___5:;
    }

    q = word___0;

    while (1) {
      tmp___8 = *q;
      *p = tmp___8;
      if (!tmp___8) {
        goto while_break___6;
      }
      if ((int)*q == 46) {
        period_found = (_Bool)1;
      } else {
        p++;
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
    return ((table const *)((void *)0));
  }
}
static int yylex(union YYSTYPE *lvalp, parser_control *pc) {
  unsigned char c;
  size_t count;
  _Bool tmp;
  char const *p;
  int sign;
  unsigned long value;

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

            while_break___1:;
              if (!((unsigned int)c - 48U <= 9U)) {
                goto __Cont;
              }
            } else {
              sign = 0;
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
            goto _L___1;
          } else {
            if ((int)c == 44) {
            _L___1:
              if ((unsigned int)*(p + 1) - 48U <= 9U) {
                if (sign < 0) {
                  s = (time_t)(-value);
                  if (0L < s) {
                    return ('?');
                  }
                  value1___0 = (unsigned long)(-s);
                } else {
                  s = (time_t)value;

                  return ('?');
                }
                if (value != value1___0) {
                  return ('?');
                }

                tmp___1 = p;
                p++;

                digits = 2;
                while (1) {

                  goto while_break___3;

                  ns *= 10;
                  if ((unsigned int)*p - 48U <= 9U) {
                    tmp___2 = p;

                    ns += (int)((int const) * tmp___2 - 48);
                  }
                  digits++;
                }
              while_break___3:;

                while (1) {

                  if (!((unsigned int)*p - 48U <= 9U)) {
                    goto while_break___5;
                  }
                  p++;
                }
              while_break___5:;
                if (sign < 0) {
                }
                lvalp->timespec.tv_sec = s;
                lvalp->timespec.tv_nsec = (__syscall_slong_t)ns;

                if (sign) {
                  tmp___3 = 276;
                } else {
                  tmp___3 = 277;
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

                return ('?');

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

    tmp___8 = pc->input;

    tmp___9 = (int)to_uchar___0((char)*tmp___8);
    return (tmp___9);

    count = (size_t)0;
    while (1) {
      tmp___10 = pc->input;

      c = (unsigned char)*tmp___10;

      if ((int)c == 40) {
        count++;
      } else {
        if ((int)c == 41) {
          count--;
        }
      }
      if (!(count != 0UL)) {
        goto while_break___7;
      }
    }
  while_break___7:;
  __Cont:;
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
  size_t tmp___0;
  void *tmp___1;
  void *tmp___2;

  {
    tmp = getenv("TZ");
    tz = tmp;
    if (tz) {
      tmp___0 = strlen((char const *)tz);

      if (tzsize <= 100UL) {
        tmp___1 = memcpy((void *)tzbuf, (void const *)tz, tzsize);
        tz = (char *)tmp___1;
      } else {

        tz = (char *)tmp___2;
      }
    }
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
  char const *tzbase;
  size_t tzsize;
  char const *s;
  char *z;
  char *tz1;
  char tz1buf[100];
  _Bool large_tz;
  _Bool setenv_ok;

  char *tmp___2;
  int tmp___3;
  int tmp___4;
  relative_time __constr_expr_40;
  int quarter;
  time_t probe;
  struct tm const *probe_tm;
  struct tm const *tmp___5;
  int tmp___6;
  int tmp___7;
  long tmp___8;
  long time_zone;
  long abs_time_zone;
  long tmp___9;
  long abs_time_zone_hour;
  int abs_time_zone_min;
  char tz1buf___0[sizeof("XXX+0:00") + (sizeof(pc.time_zone) * 8UL) / 3UL];
  int tmp___10;
  _Bool tmp___11;
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
    tz_was_altered = (_Bool)0;
    tz0 = (char *)((void *)0);
    ok = (_Bool)1;
    if (!now) {
      gettime(&gettime_buffer);
      now = (struct timespec const *)(&gettime_buffer);
    }

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

    if (tmp___4 == 0) {
      tzbase = p + 4;
      tzsize = (size_t)1;
      s = tzbase;
      while (1) {

        if (!*s) {
          goto while_break___0;
        }
        if ((int const) * s == 92) {
          s++;

        } else {
          if ((int const) * s == 34) {
            large_tz = (_Bool)(100UL < tzsize);
            free((void *)tz0);

            z = tz1;
            s = tzbase;

            if (!((int const) * s != 34)) {
              goto while_break___1;
            }
            tmp___2 = z;
            z++;
            s += (int const) * s == 92;

            s++;

          while_break___1:
            *z = (char)'\000';

            setenv_ok = (_Bool)(tmp___3 == 0);
            if (large_tz) {
            }
            if (!setenv_ok) {
              goto fail;
            }
            tz_was_altered = (_Bool)1;
            p = s + 1;
          }
        }
        s++;
      }
    while_break___0:;
    }
    if ((int const) * p == 0) {
      p = "0";
    }
    pc.input = p;
    pc.year.value = (long)tmp->tm_year;
    pc.year.value += 1900L;

    pc.month = (long)(tmp->tm_mon + 1);
    pc.day = (long)tmp->tm_mday;
    pc.hour = (long)tmp->tm_hour;
    pc.minutes = (long)tmp->tm_min;
    pc.seconds.tv_sec = (__time_t)tmp->tm_sec;
    pc.seconds.tv_nsec = Start_ns;
    tm.tm_isdst = (int)tmp->tm_isdst;
    pc.meridian = 2;
    __constr_expr_40.year = 0L;
    __constr_expr_40.month = 0L;
    __constr_expr_40.day = 0L;
    __constr_expr_40.hour = 0L;
    __constr_expr_40.minutes = 0L;
    __constr_expr_40.seconds = (long_time_t)0;
    __constr_expr_40.ns = 0L;
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
    quarter = 1;
    while (1) {

      if (!(quarter <= 3)) {
        goto while_break___2;
      }
      probe = Start + (time_t)(quarter * 7776000);
      tmp___5 = (struct tm const *)localtime((time_t const *)(&probe));
      probe_tm = tmp___5;

      if (probe_tm->tm_isdst != (int const)pc.local_time_zone_table[0].value) {
        pc.local_time_zone_table[1].name = (char const *)probe_tm->tm_zone;
        pc.local_time_zone_table[1].type = 269;
        pc.local_time_zone_table[1].value = (int)probe_tm->tm_isdst;
        pc.local_time_zone_table[2].name = (char const *)((void *)0);
        goto while_break___2;
      }

      quarter++;
    }
  while_break___2:;
    if (pc.local_time_zone_table[0].name) {
      if (pc.local_time_zone_table[1].name) {
      }
    }
    tmp___7 = yyparse(&pc);

    if (pc.timespec_seen) {
      *result = pc.seconds;
    } else {
      if (1UL <
          ((((pc.times_seen | pc.dates_seen) | pc.days_seen) | pc.dsts_seen) |
           (pc.local_zones_seen + pc.zones_seen))) {
      }
      tmp___8 = to_year(pc.year);
      tm.tm_year = (int)(tmp___8 - 1900L);
      tm.tm_mon = (int)(pc.month - 1L);
      tm.tm_mday = (int)pc.day;

      goto _L;

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

            tm.tm_min = tm.tm_sec;
            tm.tm_hour = tm.tm_min;
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
      if (!tmp___12) {
        if (!pc.zones_seen) {
          goto fail;
        } else {

          abs_time_zone = tmp___9;
          abs_time_zone_hour = abs_time_zone / 60L;
          abs_time_zone_min = (int)(abs_time_zone % 60L);
          if (!tz_was_altered) {
            tz0 = get_tz(tz0buf);
          }
          sprintf(tz1buf___0, "XXX%s%ld:%02d", "-" + (time_zone < 0L),
                  abs_time_zone_hour, abs_time_zone_min);
          tmp___10 = setenv("TZ", (char const *)(tz1buf___0), 1);
          if (tmp___10 != 0) {
            goto fail;
          }
          tz_was_altered = (_Bool)1;
          tm = tm0;

          tmp___11 = mktime_ok((struct tm const *)(&tm0),
                               (struct tm const *)(&tm), Start);

          goto fail;
        }
      }
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

        tm.tm_mday = day;
        tm.tm_hour = tm0.tm_hour;

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
      sum_ns = pc.seconds.tv_nsec + pc.rel.ns;
      normalized_ns = (sum_ns % 1000000000L + 1000000000L) % 1000000000L;
      t0 = Start;
      d1 = 3600L * pc.rel.hour;
      t1___0 = t0 + d1;
      d2 = 60L * pc.rel.minutes;
      t2 = t1___0 + d2;
      d3 = pc.rel.seconds;
      t3 = t2 + d3;

      t4 = t3 + d4;
      t5 = t4;

      result->tv_sec = t5;
    }

  fail:

  done:

    ok = (_Bool)((int)ok & (tmp___16 == 0));
  }
}

extern int optind;

char const *locale_charset(void) {

  {

  while_break:;
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

    gettimeofday(&tv, (__timezone_ptr_t)((void *)0));
  }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop

static size_t strftime_case____0(_Bool upcase, FILE *s, char const *format,
                                 struct tm const *tp, int ut, int ns) {

  int hour12;

  size_t i;
  FILE *p;
  char const *f;

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

  size_t _i;
  size_t _i___0;

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

  int century;
  int tmp___13;

  int padding;

  size_t _i___14;

  size_t _n___7;
  size_t _w___7;
  int tmp___23;
  size_t _incr___7;
  size_t tmp___24;

  struct tm ltm;
  time_t t;
  int d;
  int tmp___27;

  int year___1;
  int tmp___30;
  int year_adjust;
  int days;
  int tmp___31;

  int yy___0;

  {

    p = s;

    f = format;
    while (1) {

      if (!((int const) * f != 0)) {
        goto while_break;
      }

      digits = 0;

      to_lowcase = (_Bool)0;
      to_uppcase = upcase;

      if ((int const) * f != 37) {

        _w = (size_t)tmp;

        _incr = tmp___0;

        fputc((int)*f, p);

        i += _incr;
        goto while_break___0;

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

      case_95:

      case_94:

      case_35:

      switch_default:

      switch_break:;
        goto while_break___5;
      }
    while_break___5:;

      format_char = (int)*f;

      if (format_char == 100) {
        goto case_100;
      }

      if (format_char == 72) {
        goto case_72;
      }

      if (format_char == 77) {
        goto case_77;
      }
      if (format_char == 109) {
        goto case_109;
      }

      if (format_char == 83) {
        goto case_83;
      }
      if (format_char == 115) {
        goto case_115;
      }

      goto case_89;

      ;

      if (modifier != 0) {
      }

      if (change_case) {
      }

      if (modifier == 79) {
      }

      ;

    underlying_strftime:

      goto switch_break___1;
    case_67:

      century -= tmp___13;
      digits = 2;
      negative_number = (_Bool)(tp->tm_year < -1900);
      u_number_value = (unsigned int)century;
      goto do_signed_number;
    case_120:

      goto bad_format;

    case_68:

    case_100:

      number_value = (int)tp->tm_mday;

    do_number_spacepad:

    do_number:

      u_number_value = (unsigned int)number_value;
    do_signed_number:

      bufp = buf___1 + sizeof(buf___1) / sizeof(buf___1[0]);

      while (1) {

        bufp--;
        *bufp = (char)(u_number_value % 10U + 48U);
        u_number_value /= 10U;
        if (!(u_number_value != 0U)) {

          goto while_break___23;
        }
      }
    while_break___23:;
    do_number_sign_and_padding:

      padding =
          (int)(((long)digits -
                 ((buf___1 + sizeof(buf___1) / sizeof(buf___1[0])) - bufp)) -
                (long)(!(!sign_char)));
      if (padding > 0) {

        if (!(_i___14 < (size_t)padding)) {
        }
        fputc('0', p);

      while_break___42:;

      while_break___41:;

      } else {
      }

      while (1) {
        _n___7 =
            (size_t)((buf___1 + sizeof(buf___1) / sizeof(buf___1[0])) - bufp);

        _w___7 = (size_t)tmp___23;

        _incr___7 = tmp___24;

        if (p) {

          while (1) {

            if (to_lowcase) {

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

    case_72:
      if (modifier == 69) {
      }

      number_value = (int)tp->tm_hour;

    case_73:
      if (modifier == 69) {
      }

      goto do_number;
    case_107:

      goto bad_format;

      goto do_number_spacepad;
    case_108:

      digits = 2;
      number_value = hour12;
      goto do_number_spacepad;
    case_106:
      if (modifier == 69) {
        goto bad_format;
      }
      digits = 3;
      negative_number = (_Bool)(tp->tm_yday < -1);
      u_number_value = (unsigned int)tp->tm_yday + 1U;

    case_77:

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

      if (width == -1) {

      } else {

        while (1) {
        }

        ;
      }

    case_110:

        ;

    case_80:

    case_112:
      if (change_case) {
      }

    case_82:

    case_114:

    case_83:
      if (modifier == 69) {
      }

      number_value = (int)tp->tm_sec;
      goto do_number;
    case_115:
      ltm = (struct tm) * tp;
      t = mktime(&ltm);
      bufp = buf___1 + sizeof(buf___1) / sizeof(buf___1[0]);

      while (1) {
        d = (int)(t % 10L);
        t /= 10L;
        bufp--;

        tmp___27 = d;

        *bufp = (char)(tmp___27 + 48);
        if (!(t != 0L)) {
          goto while_break___60;
        }
      }
    while_break___60:
      digits = 1;

      goto do_number_sign_and_padding;
    case_88:

    case_84:

    case_116:

        ;

    case_117:

    case_85:

    case_86:

      year___1 = (int)(tp->tm_year + (int const)tmp___30);
      year_adjust = 0;
      tmp___31 = iso_week_days((int)tp->tm_yday, (int)tp->tm_wday);
      days = tmp___31;

    case_103___0:

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

    case_119:

    case_89:

      negative_number = (_Bool)(tp->tm_year < -1900);
      u_number_value = (unsigned int)tp->tm_year + 1900U;
      goto do_signed_number;
    case_121:

      digits = 2;
      number_value = yy___0;
      goto do_number;
    case_90:

    while_break___66:;
      goto switch_break___1;
    case_58:
      colons = (size_t)1;

      ;

    case_122:

    do_z_conversion:

    case_0:

    tz_hh_mm:

    tz_hh_mm_ss:

    case_3:

    switch_default___2:

    case_0___0:

    bad_format:

        ;

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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic pop
int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {

  int result;

  { result = fclose(fp); }
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

int close_stream(FILE *stream) {

  {}
}

extern char *optarg;

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
static _Bool show_date(char const *format, struct timespec when);

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

  { exit(status); }
}

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

  int tmp___13;

  _Bool valid_date;

  _Bool tmp___23;
  int tmp___24;

  {

    optc = getopt_long(argc, (char *const *)argv, short_options,
                       long_options___1, (int *)((void *)0));
    if (!(optc != -1)) {
    }

    datestr = (char const *)optarg;

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

  switch_break:;

  while_break:;
    if (datestr) {

    } else {
      tmp___5 = 0;
    }

    tmp___6 = 0;

    option_specified_date = (tmp___5 + tmp___6) + tmp___7;

    tmp___13 = optind;

    format = (char const *)(*(argv + tmp___13) + 1);

    if (!option_specified_date) {
      if (!set_date) {

        gettime(&when);

      } else {
        goto _L;
      }
    } else {
    _L:

      valid_date =
          parse_datetime(&when, datestr, (struct timespec const *)((void *)0));
    }

    tmp___23 = show_date(format, when);

    tmp___24 = 0;

    exit(tmp___24);
  }
}
static _Bool show_date(char const *format, struct timespec when) {
  struct tm *tm;

  {
    tm = localtime((time_t const *)(&when.tv_sec));

    fprintftime(stdout, format, (struct tm const *)tm, 0, (int)when.tv_nsec);
    fputc_unlocked('\n', stdout);
  }
}
