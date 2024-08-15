
enum strtol_error {
  LONGINT_OK = 0,
  LONGINT_OVERFLOW = 1,
  LONGINT_INVALID_SUFFIX_CHAR = 2,
  LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
  LONGINT_INVALID = 4
};
typedef enum strtol_error strtol_error;

typedef unsigned long size_t;

enum quoting_style {
  literal_quoting_style = 0,
  shell_quoting_style = 1,
  shell_always_quoting_style = 2,
  c_quoting_style = 3,
  escape_quoting_style = 4,
  locale_quoting_style = 5,
  clocale_quoting_style = 6
};

typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;

typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __nlink_t nlink_t;

typedef struct hash_table Hash_table;
struct stat {
  __dev_t st_dev;
  __ino_t st_ino;

  __mode_t st_mode;
  __uid_t st_uid;

  __off_t st_size;
};

struct _ftsent;

typedef struct _ftsent FTSENT;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef __gid_t gid_t;
typedef __uid_t uid_t;
struct passwd {};
struct group {

  char **gr_mem;
};

struct dirent {
  __ino_t d_ino;

  unsigned char d_type;
};

typedef struct __dirstream DIR;
struct saved_cwd {
  int desc;
};

typedef struct tokenbuffer token_buffer;

struct quoting_options {
  enum quoting_style style;
};
struct slotvec {
  size_t size;
  char *val;
};

typedef __mode_t mode_t;
struct mode_change {
  char op;
  char flags;
  mode_t affected;
  mode_t value;
  struct mode_change *next;
};

struct option {};

typedef signed char yysigned_char;

enum backup_type { none = 0, simple = 1, numbered_existing = 2, numbered = 3 };

extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes);

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;

  int *tmp___1;
  char *tmp___2;

  int *tmp___4;

  {

    if (0 <= strtol_base) {

    } else {
      {}
    }
    if (ptr) {

    } else {
      p = &t_ptr;
    }
    q = s;
    {

      /* CIL Label */
      ;
    }

    ;

    {
      tmp___1 = __errno_location();
      *tmp___1 = 0;
      tmp = strtoul((char const * /* __restrict  */)s,
                    (char ** /* __restrict  */)p, strtol_base);
    }
    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {
        if (*(*p)) {
          {
            tmp___2 = strchr(valid_suffixes, (int)*(*p));
          }
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
      { tmp___4 = __errno_location(); }
      if (*tmp___4 != 0) {
        {
        }
      }
    }

    *val = tmp;
    return (err);
  }
}

__attribute__((__nothrow__)) void(__attribute__((__leaf__)) rpl_free)(void *p);

extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) gettext)(
    char const *__msgid) __attribute__((__format_arg__(1)));

__inline static void *xnmalloc_inline(size_t n, size_t s) {
  void *p;
  int tmp;

  {

    if ((size_t)tmp / s < n) {
      {
      }
    } else {
      {}
      if (!p) {
        {
        }
      }
    }
    return (p);
  }
}

char *xgetcwd(void);

void version_etc_va(FILE *stream, char const *command_name, char const *package,
                    char const *version, va_list authors) {

  {
    {}
    {

      /* CIL Label */
      ;
    }

    ;

    goto switch_default;
    {}
    {}

    {}

    {}

    {}

    {}

    {}

    {}

    {}

    {}

  switch_default: {}
    goto switch_break;
  switch_break: {}
  }
}

char *base_name(char const *name);
size_t base_len(char const *name);

int strip_trailing_slashes(char *path) {

  char *tmp;

  int had_slash;

  {
    { tmp = base_name((char const *)path); }
    return (had_slash);
  }
}

static int have_working_fchdir = 1;
int save_cwd(struct saved_cwd *cwd) {

  {
    cwd->desc = -1;

    if (have_working_fchdir) {
      {
      }
    }

    return (0);
  }
}
int restore_cwd(struct saved_cwd const *cwd) {

  {}
}

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);

int same_name(char const *source, char const *dest) {
  char const *source_basename;
  char *tmp;
  char const *dest_basename;

  size_t source_baselen;
  size_t tmp___1;
  size_t dest_baselen;
  size_t tmp___2;
  _Bool identical_basenames;
  int tmp___3;
  int tmp___4;
  _Bool compare_dirs;
  _Bool same;
  struct stat source_dir_stats;
  struct stat dest_dir_stats;
  char *source_dirname;
  char *dest_dirname;

  int tmp___6;
  int *tmp___7;
  int tmp___8;
  int tmp___9;

  {
    {
      tmp = base_name(source);

      tmp___1 = base_len(source_basename);

      tmp___2 = base_len(dest_basename);
    }
    if (source_baselen == dest_baselen) {
      {
        tmp___3 = memcmp((void const *)source_basename,
                         (void const *)dest_basename, dest_baselen);
      }

    } else {
      tmp___4 = 0;
    }
    identical_basenames = (_Bool)tmp___4;
    compare_dirs = identical_basenames;
    same = (_Bool)0;
    if (compare_dirs) {
      {
      }
      if (tmp___6) {
        {
        }
      }
      {
        tmp___8 =
            stat((char const * /* __restrict  */)((char const *)dest_dirname),
                 (struct stat * /* __restrict  */)(&dest_dir_stats));
      }
      if (tmp___8) {
        {

          error(1, *tmp___7, "%s", dest_dirname);
        }
      }

      {
        same = (_Bool)tmp___9;
        rpl_free((void *)source_dirname);
        rpl_free((void *)dest_dirname);
      }
    }
    return ((int)same);
  }
}

size_t quotearg_buffer(char *buffer, size_t buffersize, char const *arg,
                       size_t argsize, struct quoting_options const *o);

static size_t quotearg_buffer_restyled(char *buffer, size_t buffersize,
                                       char const *arg, size_t argsize,
                                       enum quoting_style quoting_style,
                                       struct quoting_options const *o) {
  size_t i;
  size_t len;
  char const *quote_string;

  int backslash_escapes;
  int unibyte_locale;

  unsigned char c;

  size_t m;

  int tmp___7;
  size_t tmp___8;

  {
    {}

    if ((unsigned int)quoting_style == 4U) {
    }

    if ((unsigned int)quoting_style == 5U) {
    }
    if ((unsigned int)quoting_style == 2U) {
    }

    {

      /* CIL Label */
      ;

      len++;
      goto while_break;

      /* CIL Label */
      ;
    }
  while_break:

  case_4:

  case_6: {}
    {

      /* CIL Label */
      ;
    }
  while_break___0: {}

  case_2: {

    /* CIL Label */
    ;
  }
  while_break___2:
    quote_string = "\'";

    goto switch_break;
  switch_break:
    i = (size_t)0;
    {

      /* CIL Label */
      ;

      if (tmp___7) {
        goto while_break___3;
      }
      if (backslash_escapes) {
      }
      c = (unsigned char)*(arg + i);
      if ((int)c == 0) {
      }

      if ((int)c == 7) {
      }

      if ((int)c == 10) {
      }
      if ((int)c == 13) {
      }

      if ((int)c == 11) {
      }
      if ((int)c == 92) {
      }

      if ((int)c == 59) {
      }

      if ((int)c == 32) {
      }

      if ((int)c == 123) {
      }

      if ((int)c == 117) {
        goto case_125;
      }

      if ((int)c == 109) {
        goto case_125;
      }

      if ((int)c == 100) {
      }

      if ((int)c == 89) {
      }

      if ((int)c == 87) {
        goto case_125;
      }

      if ((int)c == 81) {
        goto case_125;
      }
      if ((int)c == 80) {
        goto case_125;
      }

      if ((int)c == 78) {
        goto case_125;
      }

      if ((int)c == 73) {
      }

      if ((int)c == 65) {
        goto case_125;
      }

      if ((int)c == 56) {
        goto case_125;
      }

    case_0:

    case_63:

    case_3___0:

      goto switch_break___1;

    switch_break___1:;
      goto switch_break___0;
    case_7:

    case_8:

    case_12:

    case_10:

    case_13:

      goto c_and_shell_escape;
    case_9:

      goto c_and_shell_escape;
    case_11:

    case_92:

      goto c_and_shell_escape;
    c_and_shell_escape:
      if ((unsigned int)quoting_style == 1U) {
        goto use_shell_always_quoting_style;
      }

    case_126:

    case_124:
      if ((unsigned int)quoting_style == 1U) {
      }

    case_39___0:

    case_2___0: {

      /* CIL Label */
      ;
    }

    ;
      {

        /* CIL Label */
        ;

        if (len < buffersize) {

        }

        /* CIL Label */
        ;
      }

      ;
      {

        /* CIL Label */
        ;
      }

      ;

      ;

    case_125:

      if (unibyte_locale) {
        {
        }
      } else {
        {}

        {

          /* CIL Label */
          ;
          {}

          {

          }

          /* CIL Label */
          ;
        }

        ;
      }
      if (1UL < m) {

      } else {
      }
    switch_break___0:;
      if (backslash_escapes) {

      } else {
      }
    store_escape: {

      /* CIL Label */
      ;
    }

    ;
    store_c: {

      /* CIL Label */
      ;
    }
    while_break___22:
      i++;

      /* CIL Label */
      ;
    }
  while_break___3:;

    if (len < buffersize) {
      *(buffer + len) = (char)'\000';
    }
    return (len);
  use_shell_always_quoting_style: {
    tmp___8 = quotearg_buffer_restyled(buffer, buffersize, arg, argsize,
                                       (enum quoting_style)2, o);
  }
  }
}
size_t quotearg_buffer(char *buffer, size_t buffersize, char const *arg,
                       size_t argsize, struct quoting_options const *o) {
  struct quoting_options const *p;
  struct quoting_options const *tmp;
  int e;
  int *tmp___0;
  size_t r;
  size_t tmp___1;
  int *tmp___2;

  {

    {
      p = tmp;
      tmp___0 = __errno_location();
      e = *tmp___0;
      tmp___1 = quotearg_buffer_restyled(buffer, buffersize, arg, argsize,
                                         (enum quoting_style)p->style, p);
      r = tmp___1;
      tmp___2 = __errno_location();
      *tmp___2 = e;
    }
    return (r);
  }
}
static char slot0[256];

static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options) {

  unsigned int n0;

  size_t size;
  char *val;
  size_t qsize;
  size_t tmp___3;
  void *tmp___4;

  {
    { n0 = (unsigned int)n; }

    { tmp___3 = quotearg_buffer(val, size, arg, argsize, options); }
    if (size <= qsize) {

      (slotvec + n)->size = size;

      {

        val = (char *)tmp___4;
        (slotvec + n)->val = val;
        quotearg_buffer(val, size, arg, argsize, options);
      }
    }
    {}
    return (val);
  }
}

char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;
  struct quoting_options tmp;
  char *tmp___0;

  {
    {

      o = tmp;
      tmp___0 = quotearg_n_options(n, arg, (size_t)-1,
                                   (struct quoting_options const *)(&o));
    }
  }
}
char *quotearg_char(char const *arg, char ch) {
  struct quoting_options options;
  char *tmp;

  {
    {

      tmp = quotearg_n_options(0, arg, (size_t)-1,
                               (struct quoting_options const *)(&options));
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

  {
    {}
  }
}
char const *quote(char const *name) {
  char const *tmp;

  {
    { tmp = quote_n(0, name); }
    return (tmp);
  }
}

struct mode_change *mode_compile(char const *mode_string___0,
                                 unsigned int masked_ops);
mode_t mode_adjust(mode_t oldmode, struct mode_change const *changes);

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

    p->op = (char)'=';

    p->value = new_mode;
  }
}
static void mode_append_entry(struct mode_change **head,
                              struct mode_change **tail,
                              struct mode_change *e) {
  struct mode_change *tmp;

  {
    if ((unsigned long)*head == (unsigned long)((void *)0)) {

      *head = tmp;
    } else {
    }
    return;
  }
}
struct mode_change *mode_compile(char const *mode_string___0,
                                 unsigned int masked_ops) {
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
  struct mode_change *p___0;
  struct mode_change *tmp___13;
  int tmp___14;
  int tmp___15;
  int tmp___16;

  {
    {
      head = (struct mode_change *)((void *)0);
      tmp___11 =
          xstrtoul(mode_string___0, (char **)((void *)0), 8, &octal_value, "");
    }
    if ((unsigned int)tmp___11 == 0U) {
      if (octal_value != (octal_value & 4095UL)) {
        return ((struct mode_change *)0);
      }
      if (256 >> 3 == 32) {
        if (128 >> 3 == 16) {
          if (64 >> 3 == 8) {
            if ((256 >> 3) >> 3 == 4) {
              if ((128 >> 3) >> 3 == 2) {
                if ((64 >> 3) >> 3 == 1) {
                  mode = (mode_t)octal_value;
                } else {
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
        }
        if (octal_value & 32UL) {
          tmp___5 = 256 >> 3;
        } else {
          tmp___5 = 0;
        }
        if (octal_value & 16UL) {
          tmp___6 = 128 >> 3;
        } else {
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
        mode =
            (mode_t)(((((((((((tmp | tmp___0) | tmp___1) | tmp___2) | tmp___3) |
                           tmp___4) |
                          tmp___5) |
                         tmp___6) |
                        tmp___7) |
                       tmp___8) |
                      tmp___9) |
                     tmp___10);
      }
      { p = make_node_op_equals(mode); }
      if ((unsigned long)p == (unsigned long)((void *)0)) {
      }
      { mode_append_entry(&head, &tail, p); }
      return (head);
    }
    {
      umask_value = umask((__mode_t)0);
      umask(umask_value);
    }
    {
      while (1) {
        /* CIL Label */
        ;

        ops_to_mask = 0U;
        mode_string___0++;
        {

          /* CIL Label */
          ;

          if ((int const) * mode_string___0 == 117) {
          }

          if ((int const) * mode_string___0 == 111) {
            goto case_111;
          }
          if ((int const) * mode_string___0 == 97) {
          }

        case_117:
          affected_bits |= 2496U;

        case_103:

        case_111:
          affected_bits |= (unsigned int)(512 | ((448 >> 3) >> 3));

        case_97:

        switch_default:

        switch_break:
          mode_string___0++;

          /* CIL Label */
          ;
        }

      no_more_affected:
        if (affected_bits) {
          who_specified_p = 1;
        } else {

          ops_to_mask = masked_ops;
        }
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;

            if (!((int const) * mode_string___0 == 61)) {
              if (!((int const) * mode_string___0 == 43)) {
              }
            }
            {
              tmp___12 = malloc(sizeof(struct mode_change));
              change = (struct mode_change *)tmp___12;
            }
            if ((unsigned long)change == (unsigned long)((void *)0)) {
              {
              }
            }
            change->next = (struct mode_change *)((void *)0);
            change->op = (char)*mode_string___0;
            affected_masked = affected_bits;
            if (!who_specified_p) {
              if ((int const) * mode_string___0 == 61) {
                tmp___14 = 1;
              } else {
              }
              if (ops_to_mask & (unsigned int)tmp___14) {
                {
                  tmp___13 = make_node_op_equals((mode_t)0);
                  p___0 = tmp___13;
                }
                if ((unsigned long)p___0 == (unsigned long)((void *)0)) {
                }
                {}
              }
            }
            if ((int const) * mode_string___0 == 61) {
              tmp___16 = 1;
            } else {
              if ((int const) * mode_string___0 == 43) {
                tmp___15 = 2;
              } else {
                tmp___15 = 4;
              }
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

            while_continue___2: /* CIL Label */
                ;

              if ((int const) * mode_string___0 == 114) {
                goto case_114;
              }
              if ((int const) * mode_string___0 == 119) {
                goto case_119;
              }
              if ((int const) * mode_string___0 == 88) {
              }
              if ((int const) * mode_string___0 == 120) {
              }

            case_114:
              change->value |=
                  (unsigned int)((256 | (256 >> 3)) | ((256 >> 3) >> 3)) &
                  affected_masked;
              goto switch_break___0;
            case_119:
              change->value |=
                  (unsigned int)((128 | (128 >> 3)) | ((128 >> 3) >> 3)) &
                  affected_masked;

            case_88:

            case_120:

            case_116:
              change->value |= 512U & affected_masked;

            case_117___0:
              if (change->value) {
                goto invalid;
              }

            case_103___0:

              change->value = (mode_t)(448 >> 3);

            case_111___0:

              change->value = (mode_t)((448 >> 3) >> 3);
              change->flags = (char)((int)change->flags | 2);

            switch_default___0:

            switch_break___0:
              mode_string___0++;

              /* CIL Label */
              ;
            }

            ;
          }
          /* CIL Label */
          ;
        }

        ;

      }
      /* CIL Label */
      ;
    }

    ;
    if ((int const) * mode_string___0 == 0) {
      return (head);
    }
  invalid: {}
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

    {

      /* CIL Label */
      ;

      if ((int const)changes->flags & 2) {
        value = newmode & (unsigned int)changes->value;
        if (changes->value & 448U) {
          if (value & 256U) {
            tmp = (256 >> 3) | ((256 >> 3) >> 3);
          } else {
            tmp = 0;
          }

          if (value & 64U) {
            tmp___1 = (64 >> 3) | ((64 >> 3) >> 3);
          } else {
          }
          value |= (unsigned int)((tmp | tmp___0) | tmp___1);
        } else {
          if (changes->value & (unsigned int const)(448 >> 3)) {
            if (value & (unsigned int)(256 >> 3)) {

            } else {
              tmp___2 = 0;
            }
            if (value & (unsigned int)(128 >> 3)) {
              tmp___3 = 128 | ((128 >> 3) >> 3);
            } else {
            }
            if (value & (unsigned int)(64 >> 3)) {

            } else {
              tmp___4 = 0;
            }
            value |= (unsigned int)((tmp___2 | tmp___3) | tmp___4);
          } else {
            if (value & (unsigned int)((256 >> 3) >> 3)) {

            } else {
            }
            if (value & (unsigned int)((128 >> 3) >> 3)) {

            } else {
              tmp___6 = 0;
            }

            value |= (unsigned int)((tmp___5 | tmp___6) | tmp___7);
          }
        }
        value &= (unsigned int)changes->affected;
      } else {
        value = (mode_t)changes->value;
        if ((int const)changes->flags & 1) {
        }
      }

      if ((int const)changes->op == 43) {
        goto case_43;
      }
      if ((int const)changes->op == 45) {
      }

    case_61:
      newmode = (newmode & (unsigned int)(~changes->affected)) | value;
      goto switch_break;
    case_43:
      newmode |= value;

    case_45:
      newmode &= ~value;

    switch_break:
      changes = (struct mode_change const *)changes->next;

      /* CIL Label */
      ;
    }
  while_break:;
    return (newmode);
  }
}
void mode_free(struct mode_change *changes) {

  {
    {

      /* CIL Label */
      ;
    }

    ;
  }
}
static unsigned short const __mon_yday[2][13] = {
    {(unsigned short const)0, (unsigned short const)31,
     (unsigned short const)59, (unsigned short const)90,
     (unsigned short const)120, (unsigned short const)151,
     (unsigned short const)181, (unsigned short const)212,
     (unsigned short const)243, (unsigned short const)273,
     (unsigned short const)304, (unsigned short const)334,
     (unsigned short const)365},
    {(unsigned short const)0, (unsigned short const)31,
     (unsigned short const)60, (unsigned short const)91,
     (unsigned short const)121, (unsigned short const)152,
     (unsigned short const)182, (unsigned short const)213,
     (unsigned short const)244, (unsigned short const)274,
     (unsigned short const)305, (unsigned short const)335,
     (unsigned short const)366}};

int make_path(char const *argpath, int mode, int parent_mode, uid_t owner,
              gid_t group, int preserve_existing,
              char const *verbose_fmt_string);
int make_dir(char const *dir, char const *dirpath, mode_t mode,
             int *created_dir_p);

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) mkdir)(char const *__path, __mode_t __mode);

int make_dir(char const *dir, char const *dirpath, mode_t mode,
             int *created_dir_p) {
  int fail;
  int created_dir;
  int tmp;
  struct stat stats;
  int saved_errno;
  int *tmp___0;

  char *tmp___2;

  char *tmp___4;
  int tmp___5;

  {
    {
      fail = 0;
      tmp = mkdir(dir, mode);
      created_dir = tmp == 0;
    }
    if (!created_dir) {
      {

        saved_errno = *tmp___0;
        tmp___5 = stat((char const * /* __restrict  */)dir,
                       (struct stat * /* __restrict  */)(&stats));
      }
      if (tmp___5) {
        {

          tmp___2 = gettext("cannot create directory %s");
        }
      } else {
        if (!((stats.st_mode & 61440U) == 16384U)) {
          {

            tmp___4 = gettext("%s exists but is not a directory");

            fail = 1;
          }
        }
      }
    }

    return (fail);
  }
}
int make_path(char const *argpath, int mode, int parent_mode, uid_t owner,
              gid_t group, int preserve_existing,
              char const *verbose_fmt_string) {
  struct stat stats;
  int retval;
  char *slash;
  int tmp_mode;
  int re_protect;

  int do_chdir;
  struct saved_cwd cwd;
  char *basename_dir;
  char *dirpath;
  mode_t oldmask;

  size_t tmp___0;
  void *tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int newly_created_dir;
  int fail;

  int tmp___19;

  int tmp___29;

  int tmp___36;

  char const *tmp___38;
  char *tmp___39;
  int *tmp___40;
  int tmp___41;
  char const *tmp___42;
  char *tmp___43;
  int *tmp___44;
  int tmp___45;

  char const *dirpath___0;

  char const *tmp___57;
  char *tmp___58;
  int *tmp___59;
  int tmp___60;

  int tmp___64;
  int tmp___65;

  {
    {
      retval = 0;
      tmp___65 = stat((char const * /* __restrict  */)argpath,
                      (struct stat * /* __restrict  */)(&stats));
    }
    if (tmp___65) {
      {

        tmp___1 = __builtin_alloca(tmp___0 + 1UL);
        dirpath = (char *)tmp___1;
        strcpy((char * /* __restrict  */)dirpath,
               (char const * /* __restrict  */)argpath);
        strip_trailing_slashes(dirpath);
      }
      if ((parent_mode & 192) != 192) {
        tmp_mode = 448;
        re_protect = 1;
      } else {
        if (owner != 4294967295U) {
          goto _L;
        } else {
          if (group != 4294967295U) {
          _L:
            if ((parent_mode & 3584) != 0) {

            } else {
              tmp_mode = parent_mode;
              re_protect = 0;
            }
          } else {
            tmp_mode = parent_mode;
            re_protect = 0;
          }
        }
      }
      { tmp___2 = save_cwd(&cwd); }

      do_chdir = tmp___3;
      if (do_chdir) {
        if ((int)*dirpath == 47) {
          {
          }
          if (tmp___4 < 0) {
          }
        }
      }
      slash = dirpath;
      {

      while_continue: /* CIL Label */
          ;

        if (!((int)*slash == 47)) {

        }

        /* CIL Label */
        ;
      }
    while_break:;
      {

        /* CIL Label */
        ;
        {
          basename_dir = slash;
          slash = strchr((char const *)slash, '/');
        }
        if ((unsigned long)slash == (unsigned long)((void *)0)) {
        }
        if (!do_chdir) {
          basename_dir = dirpath;
        }
        {
          *slash = (char)'\000';
          fail = make_dir((char const *)basename_dir, (char const *)dirpath,
                          (mode_t)tmp_mode, &newly_created_dir);
        }

        if (newly_created_dir) {

          if (owner != 4294967295U) {

          } else {
            if (group != 4294967295U) {
            _L___0: {
              tmp___19 = chown((char const *)basename_dir, owner, group);
            }
              if (tmp___19) {
                {
                }
                {

                  /* CIL Label */
                  ;
                }

                ;
                return (1);
              }
            }
          }
        }
        if (do_chdir) {
          {
          }
          if (tmp___29 < 0) {
            {
            }
            {

              /* CIL Label */
              ;
            }

            ;
          }
        }

        {

          /* CIL Label */
          ;
        }

        ;

        /* CIL Label */
        ;
      }
    while_break___0:;

      {
        umask(oldmask);
        tmp___36 = make_dir((char const *)basename_dir, (char const *)dirpath,
                            (mode_t)mode, (int *)((void *)0));
      }
      if (tmp___36) {
        {

          /* CIL Label */
          ;
        }

        ;
      }

      if (owner != 4294967295U) {

      } else {
        if (group != 4294967295U) {
        _L___1: { tmp___41 = chown((char const *)basename_dir, owner, group); }
          if (tmp___41) {
            {

              tmp___40 = __errno_location();
              error(0, *tmp___40, (char const *)tmp___39, tmp___38);
              retval = 1;
            }
          }
        }
      }
      if (mode & ~((448 | (448 >> 3)) | ((448 >> 3) >> 3))) {
        {
          tmp___45 = chmod((char const *)basename_dir, (__mode_t)mode);
        }
        if (tmp___45) {
          {

            error(0, *tmp___44, (char const *)tmp___43, tmp___42);
          }
        }
      }
      {

        /* CIL Label */
        ;
      }

      {

        /* CIL Label */
        ;
      }

      ;
    } else {

      if (!preserve_existing) {
        if (owner != 4294967295U) {

        } else {
          if (group != 4294967295U) {
          _L___2: { tmp___60 = chown(dirpath___0, owner, group); }
            if (tmp___60) {
              {

                tmp___59 = __errno_location();
                error(0, *tmp___59, (char const *)tmp___58, tmp___57);
                retval = 1;
              }
            }
          }
        }
        { tmp___64 = chmod(dirpath___0, (__mode_t)mode); }
        if (tmp___64) {
          {

            retval = 1;
          }
        }
      }
    }
    return (retval);
  }
}

extern int optind;

static unsigned char const yytranslate[274] = {
    (unsigned char const)0,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)20,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)21,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)19, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)1,  (unsigned char const)2,
    (unsigned char const)3,  (unsigned char const)4,  (unsigned char const)5,
    (unsigned char const)6,  (unsigned char const)7,  (unsigned char const)8,
    (unsigned char const)9,  (unsigned char const)10, (unsigned char const)11,
    (unsigned char const)12, (unsigned char const)13, (unsigned char const)14,
    (unsigned char const)15, (unsigned char const)16, (unsigned char const)17,
    (unsigned char const)18};
static unsigned char const yyr1[56] = {
    (unsigned char const)0,  (unsigned char const)22, (unsigned char const)23,
    (unsigned char const)23, (unsigned char const)24, (unsigned char const)24,
    (unsigned char const)24, (unsigned char const)24, (unsigned char const)24,
    (unsigned char const)24, (unsigned char const)24, (unsigned char const)25,
    (unsigned char const)25, (unsigned char const)25, (unsigned char const)25,
    (unsigned char const)25, (unsigned char const)26, (unsigned char const)26,
    (unsigned char const)27, (unsigned char const)27, (unsigned char const)27,
    (unsigned char const)28, (unsigned char const)28, (unsigned char const)28,
    (unsigned char const)29, (unsigned char const)29, (unsigned char const)29,
    (unsigned char const)29, (unsigned char const)29, (unsigned char const)29,
    (unsigned char const)29, (unsigned char const)29, (unsigned char const)29,
    (unsigned char const)30, (unsigned char const)30, (unsigned char const)31,
    (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
    (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
    (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
    (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
    (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
    (unsigned char const)31, (unsigned char const)31, (unsigned char const)32,
    (unsigned char const)33, (unsigned char const)33};

static unsigned char const yydefact[66] = {
    (unsigned char const)2,  (unsigned char const)0,  (unsigned char const)1,
    (unsigned char const)21, (unsigned char const)43, (unsigned char const)19,
    (unsigned char const)46, (unsigned char const)16, (unsigned char const)49,
    (unsigned char const)0,  (unsigned char const)40, (unsigned char const)52,
    (unsigned char const)37, (unsigned char const)18, (unsigned char const)0,
    (unsigned char const)53, (unsigned char const)3,  (unsigned char const)4,
    (unsigned char const)5,  (unsigned char const)6,  (unsigned char const)8,
    (unsigned char const)7,  (unsigned char const)9,  (unsigned char const)34,
    (unsigned char const)10, (unsigned char const)22, (unsigned char const)17,
    (unsigned char const)0,  (unsigned char const)29, (unsigned char const)20,
    (unsigned char const)42, (unsigned char const)45, (unsigned char const)48,
    (unsigned char const)39, (unsigned char const)51, (unsigned char const)36,
    (unsigned char const)23, (unsigned char const)41, (unsigned char const)44,
    (unsigned char const)11, (unsigned char const)47, (unsigned char const)31,
    (unsigned char const)38, (unsigned char const)50, (unsigned char const)35,
    (unsigned char const)0,  (unsigned char const)0,  (unsigned char const)0,
    (unsigned char const)33, (unsigned char const)28, (unsigned char const)0,
    (unsigned char const)27, (unsigned char const)32, (unsigned char const)26,
    (unsigned char const)54, (unsigned char const)24, (unsigned char const)30,
    (unsigned char const)55, (unsigned char const)13, (unsigned char const)0,
    (unsigned char const)12, (unsigned char const)0,  (unsigned char const)54,
    (unsigned char const)25, (unsigned char const)15, (unsigned char const)14};

static yysigned_char const yypact[66] = {
    (yysigned_char const)-17, (yysigned_char const)0,
    (yysigned_char const)-17, (yysigned_char const)1,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)19,
    (yysigned_char const)-17, (yysigned_char const)-16,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)32,
    (yysigned_char const)26,  (yysigned_char const)14,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)27,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-13,
    (yysigned_char const)24,  (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)25,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)29,
    (yysigned_char const)30,  (yysigned_char const)31,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)33,  (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)28,  (yysigned_char const)34,
    (yysigned_char const)-17, (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)35,
    (yysigned_char const)-17, (yysigned_char const)36,
    (yysigned_char const)-7,  (yysigned_char const)-17,
    (yysigned_char const)-17, (yysigned_char const)-17};

static unsigned char const yytable[56] = {
    (unsigned char const)2,  (unsigned char const)27, (unsigned char const)28,
    (unsigned char const)57, (unsigned char const)49, (unsigned char const)3,
    (unsigned char const)4,  (unsigned char const)5,  (unsigned char const)6,
    (unsigned char const)7,  (unsigned char const)64, (unsigned char const)8,
    (unsigned char const)9,  (unsigned char const)10, (unsigned char const)11,
    (unsigned char const)12, (unsigned char const)13, (unsigned char const)14,
    (unsigned char const)15, (unsigned char const)36, (unsigned char const)37,
    (unsigned char const)25, (unsigned char const)38, (unsigned char const)26,
    (unsigned char const)39, (unsigned char const)40, (unsigned char const)41,
    (unsigned char const)42, (unsigned char const)43, (unsigned char const)44,
    (unsigned char const)48, (unsigned char const)45, (unsigned char const)30,
    (unsigned char const)46, (unsigned char const)31, (unsigned char const)47,
    (unsigned char const)29, (unsigned char const)32, (unsigned char const)57,
    (unsigned char const)33, (unsigned char const)34, (unsigned char const)35,
    (unsigned char const)51, (unsigned char const)52, (unsigned char const)50,
    (unsigned char const)58, (unsigned char const)53, (unsigned char const)59,
    (unsigned char const)54, (unsigned char const)55, (unsigned char const)65,
    (unsigned char const)56, (unsigned char const)0,  (unsigned char const)62,
    (unsigned char const)63, (unsigned char const)61};
static yysigned_char const yycheck[56] = {
    (yysigned_char const)0,  (yysigned_char const)17, (yysigned_char const)18,
    (yysigned_char const)10, (yysigned_char const)17, (yysigned_char const)5,
    (yysigned_char const)6,  (yysigned_char const)7,  (yysigned_char const)8,
    (yysigned_char const)9,  (yysigned_char const)17, (yysigned_char const)11,
    (yysigned_char const)12, (yysigned_char const)13, (yysigned_char const)14,
    (yysigned_char const)15, (yysigned_char const)16, (yysigned_char const)17,
    (yysigned_char const)18, (yysigned_char const)5,  (yysigned_char const)6,
    (yysigned_char const)20, (yysigned_char const)8,  (yysigned_char const)4,
    (yysigned_char const)10, (yysigned_char const)11, (yysigned_char const)12,
    (yysigned_char const)13, (yysigned_char const)14, (yysigned_char const)15,
    (yysigned_char const)3,  (yysigned_char const)17, (yysigned_char const)6,
    (yysigned_char const)19, (yysigned_char const)8,  (yysigned_char const)21,
    (yysigned_char const)4,  (yysigned_char const)11, (yysigned_char const)10,
    (yysigned_char const)13, (yysigned_char const)14, (yysigned_char const)15,
    (yysigned_char const)17, (yysigned_char const)18, (yysigned_char const)20,
    (yysigned_char const)17, (yysigned_char const)17, (yysigned_char const)19,
    (yysigned_char const)18, (yysigned_char const)18, (yysigned_char const)62,
    (yysigned_char const)18, (yysigned_char const)-1, (yysigned_char const)18,
    (yysigned_char const)18, (yysigned_char const)21};

char *(__attribute__((__leaf__)) rpl_getcwd)(char *buf, size_t size) {
  char *cwd;
  char *tmp;

  {
    {
      tmp = getcwd(buf, size);
      cwd = tmp;
    }
    if ((unsigned long)cwd == (unsigned long)((void *)0)) {
      return ((char *)((void *)0));
    }
    {}

    {}
  }
}

void(__attribute__((__leaf__)) rpl_free)(void *p) {

  { return; }
}

size_t dir_len(char const *path);

char *dir_name(char const *path) {
  size_t length;
  size_t tmp;
  int append_dot;
  char *newpath;
  void *tmp___0;
  size_t tmp___1;

  {
    {

      length = tmp;

      newpath = (char *)tmp___0;
      memcpy((void * /* __restrict  */)((void *)newpath),
             (void const * /* __restrict  */)((void const *)path), length);
    }
    if (append_dot) {
    }
    *(newpath + length) = (char)0;
  }
}
char const diacrit_base[256];

char *base_name(char const *name) {

  char const *p;

  {

    {

      /* CIL Label */
      ;

      if ((int const) * p == 47) {
        {

          /* CIL Label */
          ;
        }

        ;

      }

      /* CIL Label */
      ;
    }
  while_break:;
  }
}
size_t base_len(char const *name) {
  size_t len;

  {
    {}
    {

    while_break___0: /* CIL Label */
        ;
    }
  while_break:;
    return (len);
  }
}
void (*argmatch_die)(void);
char const *simple_backup_suffix;
char const *simple_backup_suffix = "~";
static char const *const backup_args[9] = {
    (char const * /* const  */) "none",
    (char const * /* const  */) "off",
    (char const * /* const  */) "simple",
    (char const * /* const  */) "never",
    (char const * /* const  */) "existing",
    (char const * /* const  */) "nil",
    (char const * /* const  */) "numbered",
    (char const * /* const  */) "t",
    (char const * /* const  */)((char const *)0)};
static enum backup_type const backup_types[8] = {
    (enum backup_type const)0, (enum backup_type const)0,
    (enum backup_type const)1, (enum backup_type const)1,
    (enum backup_type const)2, (enum backup_type const)2,
    (enum backup_type const)3, (enum backup_type const)3};
extern struct _IO_FILE *stderr;

extern char *optarg;

static int create_parents;
static struct option const longopts[6] = {
    {"mode", 1, (int *)((void *)0), 'm'},
    {"parents", 0, (int *)((void *)0), 'p'},
    {"verbose", 0, (int *)((void *)0), 'v'},
    {"help", 0, (int *)0, -130},
    {"version", 0, (int *)0, -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
void usage(int status) {

  char *tmp___3;

  {
    if (status != 0) {
      {
      }
    } else {
      {

        tmp___3 = gettext(
            "  -m, --mode=MODE   set permission mode (as in chmod), not "
            "rwxrwxrwx - umask\n  -p, --parents     no error if existing, make "
            "parent directories as needed\n  -v, --verbose     print a message "
            "for each created directory\n");
      }
    }
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

  char *tmp___0;
  mode_t umask_value;
  __mode_t tmp___1;
  struct mode_change *change;
  struct mode_change *tmp___2;
  __mode_t tmp___3;
  char const *tmp___4;
  char *tmp___5;
  int fail;
  char *dir;
  char const *dir___0;
  int dir_created;

  {
    { errors = 0; }
    {

      /* CIL Label */
      ;
      {
        optc = getopt_long(argc, (char *const *)argv, "pm:v", longopts,
                           (int *)((void *)0));
      }

      if (optc == 109) {
      }

    case_109:
      specified_mode = (char const *)optarg;
      goto switch_break;
      {}

      {}

      {}

    switch_default: { usage(1); }
    switch_break:;

      /* CIL Label */
      ;
    }
  while_break:;
    if (optind == argc) {
      {
        tmp___0 = gettext("too few arguments");
        error(0, 0, (char const *)tmp___0);
        usage(1);
      }
    }
    {
      newmode = (mode_t)((448 | (448 >> 3)) | ((448 >> 3) >> 3));
      tmp___1 = umask((__mode_t)0);

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
      if ((unsigned long)change == (unsigned long)((struct mode_change *)0)) {
        {
          tmp___4 = quote(specified_mode);
          tmp___5 = gettext("invalid mode %s");
          error(1, 0, (char const *)tmp___5, tmp___4);
        }
      } else {
      }
      { newmode = mode_adjust(newmode, (struct mode_change const *)change); }
    }
    {
      while (1) {
        /* CIL Label */
        ;

        if (!(optind < argc)) {
          goto while_break___0;
        }
        fail = 0;
        if (create_parents) {
          {
            dir = *(argv + optind);
            fail = make_path((char const *)dir, (int)newmode, (int)parent_mode,
                             (uid_t)-1, (gid_t)-1, 1, verbose_fmt_string);
          }
        } else {
          {
            dir___0 = (char const *)*(argv + optind);
            fail = make_dir(dir___0, dir___0, newmode, &dir_created);
          }
          if (!fail) {
            if (!create_parents) {

            } else {
            _L:
              if (verbose_fmt_string) {
                {
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
              }
            }
          }
        }
        if (fail) {
        }
        optind++;
      }
      /* CIL Label */
      ;
    }
  while_break___0: { exit(errors); }
  }
}
