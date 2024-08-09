
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

  __mode_t st_mode;

  __off_t st_size;
};

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef int wchar_t;

typedef __gid_t gid_t;
typedef __uid_t uid_t;

typedef struct __dirstream DIR;
struct saved_cwd {};

struct quoting_options {
  enum quoting_style style;
  int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
};
struct slotvec {

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

struct option {
  char const *name;

  int val;
};

struct hash_tuning {};

typedef signed char yysigned_char;

enum backup_type { none = 0, simple = 1, numbered_existing = 2, numbered = 3 };

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes);

static strtol_error bkm_scale_by_power___0(unsigned long *x, int base,
                                           int power) {
  strtol_error err;

  {

    {

      /* CIL Label */
      ;
    }

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

  int *tmp___3;

  int base;

  strtol_error overflow;

  {
    err = (strtol_error)0;
    if (0 <= strtol_base) {
      if (!(strtol_base <= 36)) {
        {
        }
      }
    } else {
      {}
    }

    q = s;
    {

    while_break___0: /* CIL Label */
        ;
    }
  while_break:;

    {

      tmp = strtoul((char const * /* __restrict  */)s,
                    (char ** /* __restrict  */)p, strtol_base);
    }

    if ((int)*(*p) != 0) {
      {
      }

      {}

      if ((int)*(*p) == 75) {
      }

      if ((int)*(*p) == 109) {
      }

      if ((int)*(*p) == 119) {
        goto case_119;
      }

      if ((int)*(*p) == 90) {
        goto case_90;
      }
      goto switch_default;
    case_98: {}
      goto switch_break___0;
      {}
      goto switch_break___0;

      overflow = (strtol_error)0;
      goto switch_break___0;
    case_69: {}
      goto switch_break___0;
    case_103: { overflow = bkm_scale_by_power___0(&tmp, base, 3); }
      goto switch_break___0;
    case_75: {}
      goto switch_break___0;
    case_109: {}
      goto switch_break___0;
      {}
      goto switch_break___0;
      {}
      goto switch_break___0;
    case_119: {}
      goto switch_break___0;
      { overflow = bkm_scale_by_power___0(&tmp, base, 8); }
      goto switch_break___0;
    case_90: {}
      goto switch_break___0;
    switch_default:
      *val = tmp;

    switch_break___0:

      if (*(*p)) {
        err = (strtol_error)((unsigned int)err | 2U);
      }
    }
    *val = tmp;
    return (err);
  }
}
extern __attribute__((__nothrow__)) long(__attribute__((
    __nonnull__(1), __leaf__)) strtol)(char const *__restrict __nptr,
                                       char **__restrict __endptr, int __base);

__attribute__((__nothrow__)) void(__attribute__((__leaf__)) rpl_free)(void *p);

extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) gettext)(
    char const *__msgid) __attribute__((__format_arg__(1)));

void *xrealloc(void *p, size_t n);

__inline static void *xnmalloc_inline(size_t n, size_t s) {

  {}
}

__inline static void *xnrealloc_inline(void *p, size_t n, size_t s) {
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
  }
}
void *xrealloc(void *p, size_t n) {
  void *tmp;

  {
    { tmp = xnrealloc_inline(p, n, (size_t)1); }
  }
}

char *xgetcwd(void);

char *base_name(char const *name);

int strip_trailing_slashes(char *path);

extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);

int restore_cwd(struct saved_cwd const *cwd);

int save_cwd(struct saved_cwd *cwd) {

  { return (0); }
}

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);

int same_name(char const *source, char const *dest);

int same_name(char const *source, char const *dest) {

  char *tmp;

  size_t source_baselen;
  size_t tmp___1;
  size_t dest_baselen;

  _Bool identical_basenames;

  int tmp___4;
  _Bool compare_dirs;
  _Bool same;

  struct stat dest_dir_stats;
  char *source_dirname;
  char *dest_dirname;

  int tmp___8;
  int tmp___9;

  {
    {
      tmp = base_name(source);

      source_baselen = tmp___1;
    }
    if (source_baselen == dest_baselen) {
      {
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

      {
        tmp___8 =
            stat((char const * /* __restrict  */)((char const *)dest_dirname),
                 (struct stat * /* __restrict  */)(&dest_dir_stats));
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

static size_t quotearg_buffer_restyled(char *buffer, size_t buffersize,
                                       char const *arg, size_t argsize,
                                       enum quoting_style quoting_style,
                                       struct quoting_options const *o) {
  size_t i;
  size_t len;
  char const *quote_string;
  size_t quote_string_len;
  int backslash_escapes;

  unsigned char c;

  size_t m;
  int printable;

  size_t tmp___8;

  {
    {
      len = (size_t)0;
      quote_string = (char const *)0;

      backslash_escapes = 0;
    }
    if ((unsigned int)quoting_style == 3U) {
    }

    goto switch_default;
  case_3: {
    while (1) {
      /* CIL Label */
      ;

      if (len < buffersize) {
      }
      len++;
      goto while_break;
    }
    /* CIL Label */
    ;
  }
  while_break:

    quote_string = "\"";
    quote_string_len = (size_t)1;
    goto switch_break;

    {}
    {
      while (1) {
        /* CIL Label */
        ;

        {

          /* CIL Label */
          ;
        }

        quote_string++;
      }
      /* CIL Label */
      ;
    }
    {}

    {

      /* CIL Label */
      ;

      if (len < buffersize) {

      }

      /* CIL Label */
      ;
    }
  while_break___2:

    goto switch_break;
  switch_default:

  switch_break:

  {

    /* CIL Label */
    ;

    if (argsize == 0xffffffffffffffffUL) {

    } else {
    }

    if ((int)c == 0) {
    }

    if ((int)c == 7) {
      goto case_7;
    }

    if ((int)c == 12) {
    }

    if ((int)c == 92) {
      goto case_92;
    }

    if ((int)c == 96) {
      goto case_124;
    }

    if ((int)c == 40) {
    }
    if ((int)c == 38) {
    }

    if ((int)c == 32) {
      goto case_124;
    }

    if ((int)c == 125) {
    }

    if ((int)c == 121) {
    }

    if ((int)c == 119) {
    }

    if ((int)c == 116) {
    }

    if ((int)c == 106) {
    }

    if ((int)c == 103) {
    }

    if ((int)c == 95) {
      goto case_125;
    }

    if ((int)c == 90) {
      goto case_125;
    }

    if ((int)c == 78) {
      goto case_125;
    }

    if ((int)c == 76) {
    }

    if ((int)c == 71) {
    }

    if ((int)c == 65) {
    }

    if ((int)c == 58) {
    }
    if ((int)c == 57) {
    }

    if ((int)c == 55) {
    }

    if ((int)c == 51) {
    }
    if ((int)c == 50) {
    }

    if ((int)c == 47) {
      goto case_125;
    }
    if ((int)c == 46) {
      goto case_125;
    }
    if ((int)c == 45) {
      goto case_125;
    }

  case_0:

    goto switch_break___0;

    if ((unsigned int)quoting_style == 1U) {
      goto case_1;
    }

    goto switch_default___0;
  case_1:

  switch_default___0:

      ;

  case_7:

  case_8:

    goto c_escape;
  case_12:

    goto c_escape;
  case_10:

    goto c_and_shell_escape;
  case_13:

  case_9:

  case_11:

    goto c_escape;
  case_92:

    goto c_and_shell_escape;
  c_and_shell_escape:

  c_escape:
    if (backslash_escapes) {
    }

  case_126:

  case_124:
    if ((unsigned int)quoting_style == 1U) {
      goto use_shell_always_quoting_style;
    }

  case_39___0:

    if ((unsigned int)quoting_style == 2U) {
    }

    goto use_shell_always_quoting_style;
  case_2___0: {

    /* CIL Label */
    ;
  }

  ;
    {

      /* CIL Label */
      ;

      len++;

      /* CIL Label */
      ;
    }
  while_break___12:;
    {

      /* CIL Label */
      ;
    }

    ;

  switch_break___3:;

  case_125:

  switch_default___2:

    if (1UL < m) {

    } else {
      if (backslash_escapes) {
        if (!printable) {
        _L:

        {

          /* CIL Label */
          ;

          {

            /* CIL Label */
            ;
          }

          c = (unsigned char)*(arg + i);

          /* CIL Label */
          ;
        }
        while_break___16:;
          goto store_c;
        }
      }
    }
  switch_break___0:;
    if (backslash_escapes) {
      if (!(o->quote_these_too[(unsigned long)c / (sizeof(int) * 8UL)] &
            (1 << (unsigned long)c % (sizeof(int) * 8UL)))) {
        goto store_c;
      }
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
    }
    return (len);
  use_shell_always_quoting_style: {
    tmp___8 = quotearg_buffer_restyled(buffer, buffersize, arg, argsize,
                                       (enum quoting_style)2, o);
  }
    return (tmp___8);
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
    if (o) {

    } else {
    }
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

static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options) {

  unsigned int n0;
  unsigned int n1;
  int tmp___0;

  size_t size;
  char *val;
  size_t qsize;

  int *tmp___5;

  {
    {}

    if (nslots <= n0) {

      if ((size_t)tmp___0 / sizeof(*slotvec) < (size_t)n1) {
        {
          xalloc_die();
        }
      }
      if ((unsigned long)slotvec == (unsigned long)(&slotvec0)) {
        {

          *slotvec = slotvec0;
        }
      }
      {}
    }
    { val = (slotvec + n)->val; }
    if (size <= qsize) {

      if ((unsigned long)val != (unsigned long)(slot0)) {
        {
        }
      }
      {

        (slotvec + n)->val = val;
        quotearg_buffer(val, size, arg, argsize, options);
      }
    }
    { tmp___5 = __errno_location(); }
  }
}

char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;
  struct quoting_options tmp;

  {
    { o = tmp; }
  }
}

char const *quote_n(int n, char const *name) {
  char *tmp;

  {
    { tmp = quotearg_n_style(n, (enum quoting_style)5, name); }
  }
}
char const *quote(char const *name) {
  char const *tmp;

  {
    { tmp = quote_n(0, name); }
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
    p->affected = (mode_t)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
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
        }

        if (octal_value & 512UL) {
          tmp___1 = 512;
        } else {
        }
        if (octal_value & 256UL) {

        } else {
        }
        if (octal_value & 128UL) {

        } else {
          tmp___3 = 0;
        }
        if (octal_value & 64UL) {
          tmp___4 = 64;
        } else {
        }
        if (octal_value & 32UL) {

        } else {
        }

        if (octal_value & 8UL) {
          tmp___7 = 64 >> 3;
        } else {
        }

        if (octal_value & 2UL) {

        } else {
        }
        if (octal_value & 1UL) {

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

      /* CIL Label */
      ;
      affected_bits = (mode_t)0;

      ops_to_mask = 0U;
      mode_string___0++;
      {

        /* CIL Label */
        ;

        if ((int const) * mode_string___0 == 117) {
          goto case_117;
        }
        if ((int const) * mode_string___0 == 103) {
          goto case_103;
        }

      case_117:

        goto switch_break;
      case_103:

        goto switch_break;

        goto switch_break;
      case_97:
        affected_bits |=
            (unsigned int)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
        goto switch_break;
      switch_default:
        goto no_more_affected;
      switch_break:
        mode_string___0++;

        /* CIL Label */
        ;
      }

    no_more_affected:
      if (affected_bits) {

      } else {
      }
      {

        /* CIL Label */
        ;

        if (!((int const) * mode_string___0 == 61)) {
          if (!((int const) * mode_string___0 == 43)) {
            if (!((int const) * mode_string___0 == 45)) {
              goto while_break___1;
            }
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

        change->op = (char)*mode_string___0;

        if (!who_specified_p) {
          if ((int const) * mode_string___0 == 61) {

          } else {
            tmp___14 = 0;
          }
          if (ops_to_mask & (unsigned int)tmp___14) {
            {
              tmp___13 = make_node_op_equals((mode_t)0);
            }
            if ((unsigned long)p___0 == (unsigned long)((void *)0)) {
              return ((struct mode_change *)1);
            }
            { mode_append_entry(&head, &tail, p___0); }
          }
        }
        if ((int const) * mode_string___0 == 61) {
          tmp___16 = 1;
        } else {

          tmp___16 = tmp___15;
        }
        if (ops_to_mask & (unsigned int)tmp___16) {
          affected_masked &= ~umask_value;
        }
        {
          change->affected = affected_masked;

          change->flags = (char)0;
          mode_append_entry(&head, &tail, change);
          mode_string___0++;
        }
        {
          while (1) {
          while_continue___2: /* CIL Label */
              ;

            if ((int const) * mode_string___0 == 114) {
              goto case_114;
            }

            if ((int const) * mode_string___0 == 117) {
            }

          case_114:

            goto switch_break___0;

            goto switch_break___0;

          case_120:

            goto switch_break___0;

            change->value |= 3072U & affected_masked;
            goto switch_break___0;
          case_116:
            change->value |= 512U & affected_masked;
            goto switch_break___0;
          case_117___0:
            if (change->value) {
              goto invalid;
            }

            goto switch_break___0;

            change->value = (mode_t)(448 >> 3);

          case_111___0:

            change->value = (mode_t)((448 >> 3) >> 3);

            goto switch_break___0;

            goto no_more_values;
          switch_break___0:
            mode_string___0++;
          }
          /* CIL Label */
          ;
        }

      no_more_values:;

      while_break___4: /* CIL Label */
          ;
      }
    while_break___1:;
      if (!((int const) * mode_string___0 == 44)) {
        goto while_break;
      }

      /* CIL Label */
      ;
    }
  while_break:;
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

  {
    newmode = oldmode & (unsigned int)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
    {

      /* CIL Label */
      ;

      if ((int const)changes->flags & 2) {

        value &= (unsigned int)changes->affected;
      } else {
        value = (mode_t)changes->value;
      }
      if ((int const)changes->op == 61) {
        goto case_61;
      }

      goto switch_break;
    case_61:
      newmode = (newmode & (unsigned int)(~changes->affected)) | value;
      goto switch_break;
    case_43:
      newmode |= value;

      newmode &= ~value;
      goto switch_break;
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

  int tmp___5;

  {
    {
      fail = 0;
      tmp = mkdir(dir, mode);
      created_dir = tmp == 0;
    }
    if (!created_dir) {
      {

        tmp___5 = stat((char const * /* __restrict  */)dir,
                       (struct stat * /* __restrict  */)(&stats));
      }
      if (tmp___5) {
        {
        }
      } else {
        if (!((stats.st_mode & 61440U) == 16384U)) {
          {
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

  struct ptr_list *leading_dirs;
  int do_chdir;
  struct saved_cwd cwd;
  char *basename_dir;
  char *dirpath;
  mode_t oldmask;
  __mode_t tmp;
  size_t tmp___0;
  void *tmp___1;
  int tmp___2;
  int tmp___3;

  int newly_created_dir;
  int fail;

  int tmp___19;

  int *tmp___23;

  int tmp___29;
  char *tmp___30;

  int tmp___36;

  char const *tmp___38;
  char *tmp___39;
  int *tmp___40;
  int tmp___41;

  char const *dirpath___0;

  int tmp___60;
  char const *tmp___61;
  char *tmp___62;
  int *tmp___63;
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
        leading_dirs = (struct ptr_list *)((void *)0);

        oldmask = tmp;

        dirpath = (char *)tmp___1;
      }
      if ((parent_mode & 192) != 192) {

      } else {
        if (owner != 4294967295U) {
          goto _L;
        } else {
          if (group != 4294967295U) {
          _L:
            if ((parent_mode & 3584) != 0) {

            } else {
              tmp_mode = parent_mode;
            }
          } else {
            tmp_mode = parent_mode;
            re_protect = 0;
          }
        }
      }
      { tmp___2 = save_cwd(&cwd); }
      if (tmp___2) {

      } else {
        tmp___3 = 1;
      }
      do_chdir = tmp___3;
      if (do_chdir) {
      }

      {

        /* CIL Label */
        ;
      }

      ;
      {
        while (1) {
          /* CIL Label */
          ;
          { slash = strchr((char const *)slash, '/'); }

          {}
          if (fail) {
            {

              /* CIL Label */
              ;
            }

            ;
          }
          if (newly_created_dir) {

            if (owner != 4294967295U) {

            } else {
              if (group != 4294967295U) {
                {
                  tmp___19 = chown((char const *)basename_dir, owner, group);
                }
                if (tmp___19) {
                  {
                  }
                  {

                    /* CIL Label */
                    ;
                  }
                while_break___3:;
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

                tmp___23 = __errno_location();
              }
              {

                /* CIL Label */
                ;
              }

              ;
              return (1);
            }
          }
          tmp___30 = slash;
          slash++;
          *tmp___30 = (char)'/';
          {
            while (1) {
              /* CIL Label */
              ;

              if (!((int)*slash == 47)) {
                goto while_break___7;
              }
              slash++;
            }
          while_break___20: /* CIL Label */
              ;
          }
        while_break___7:;
        }
        /* CIL Label */
        ;
      }
    while_break___0:;
      if (!do_chdir) {
        basename_dir = dirpath;
      }
      {

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
        goto _L___1;
      } else {
        if (group != 4294967295U) {
        _L___1: { tmp___41 = chown((char const *)basename_dir, owner, group); }
          if (tmp___41) {
            {

              error(0, *tmp___40, (char const *)tmp___39, tmp___38);
              retval = 1;
            }
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

      if (!((stats.st_mode & 61440U) == 16384U)) {
        {
        }
      }
      if (!preserve_existing) {
        if (owner != 4294967295U) {

        } else {
          if (group != 4294967295U) {
            {
              tmp___60 = chown(dirpath___0, owner, group);
            }
            if (tmp___60) {
              {

                retval = 1;
              }
            }
          }
        }
        {}
        if (tmp___64) {
          {

            error(0, *tmp___63, (char const *)tmp___62, tmp___61);
          }
        }
      }
    }
  }
}

extern int optind;

extern int fclose(FILE *__stream);

static struct hash_tuning const default_tuning = {
    (float)0.0, (float)1.0, (float)0.8, (float)1.414, (_Bool)0};

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

  {
    {}
    if ((unsigned long)cwd == (unsigned long)((void *)0)) {
    }
    {}

    {}
  }
}

void(__attribute__((__leaf__)) rpl_free)(void *p) {

  {}
}

extern int fnmatch(char const *__pattern, char const *__name, int __flags);

size_t dir_len(char const *path) {
  size_t prefix_length;
  size_t length;
  char *tmp;

  {
    { prefix_length = (size_t)0; }
    {
      while (1) {
        /* CIL Label */
        ;

        if (!(prefix_length < length)) {
        }
        if (!((int const) * (path + (length - 1UL)) == 47)) {
        }

      }
      /* CIL Label */
      ;
    }
  while_break:;
  }
}
char *dir_name(char const *path) {
  size_t length;
  size_t tmp;

  char *newpath;
  void *tmp___0;

  {
    { tmp = dir_len(path); }
  }
}
char const diacrit_base[256];

char *base_name(char const *name) {
  char const *base;
  char const *p;

  {

    p = base;
    {

      /* CIL Label */
      ;

      p++;

      /* CIL Label */
      ;
    }

    ;
  }
}
size_t base_len(char const *name) {
  size_t len;

  {
    { len = strlen(name); }
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
void usage(int status);

extern char *optarg;

static int create_parents;
static struct option const longopts[6] = {
    {"mode", 1, (int *)((void *)0), 'm'},
    {"parents", 0, (int *)((void *)0), 'p'},
    {"verbose", 0, (int *)((void *)0), 'v'},
    {"help", 0, (int *)0, -130},
    {"version", 0, (int *)0, -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};

int main(int argc, char **argv) {
  mode_t newmode;
  mode_t parent_mode;
  char const *specified_mode;
  char const *verbose_fmt_string;
  int errors;
  int optc;

  char *tmp___0;
  mode_t umask_value;

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
    {

      errors = 0;

      create_parents = 0;
    }
    {

      /* CIL Label */
      ;
      {
        optc = getopt_long(argc, (char *const *)argv, "pm:v", longopts,
                           (int *)((void *)0));
      }
      if (!(optc != -1)) {
      }

      if (optc == 109) {
        goto case_109;
      }

      goto switch_default;
    case_0:

    case_109:
      specified_mode = (char const *)optarg;

      {}

      {}

      {}

    switch_default: {}

    ;

      /* CIL Label */
      ;
    }
  while_break:;
    if (optind == argc) {
      {
        tmp___0 = gettext("too few arguments");
        error(0, 0, (char const *)tmp___0);
      }
    }
    {

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

      /* CIL Label */
      ;

      if (!(optind < argc)) {
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
              if (fail) {
                {
                }
              }
            }
          }
        }
      }
      if (fail) {

      }

      /* CIL Label */
      ;
    }
  while_break___0: { exit(errors); }
  }
}
