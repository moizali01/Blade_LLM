typedef unsigned long uintmax_t;
enum strtol_error { LONGINT_OK = 0, LONGINT_OVERFLOW = 1, LONGINT_INVALID_SUFFIX_CHAR = 2, LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3, LONGINT_INVALID = 4 };
typedef enum strtol_error strtol_error;
typedef long intmax_t;
typedef unsigned long size_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;
typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
enum quoting_style { literal_quoting_style = 0, shell_quoting_style = 1, shell_always_quoting_style = 2, c_quoting_style = 3, escape_quoting_style = 4, locale_quoting_style = 5, clocale_quoting_style = 6 };
typedef long ptrdiff_t;
typedef unsigned short __u_short;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef __u_short u_short;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __nlink_t nlink_t;
struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
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

struct _ftsent;
struct _ftsent;

typedef struct __anonstruct_FTS_26 FTS;

typedef struct _ftsent FTSENT;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef long __off64_t;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef int wchar_t;
typedef unsigned int wint_t;

typedef enum __anonenum_arg_type_26 arg_type;

typedef struct __anonstruct_argument_27 argument;

typedef struct __anonstruct_arguments_29 arguments;

typedef struct __anonstruct_char_directive_30 char_directive;

typedef struct __anonstruct_char_directives_31 char_directives;
typedef long __suseconds_t;

typedef __gid_t gid_t;
typedef __uid_t uid_t;

typedef void *iconv_t;

union __anonunion___value_16 {
  unsigned int __wch;
  char __wchb[4];
};
struct __anonstruct___mbstate_t_15 {
  int __count;
  union __anonunion___value_16 __value;
};
typedef struct __anonstruct___mbstate_t_15 __mbstate_t;
typedef __mbstate_t mbstate_t;

typedef unsigned int md5_uint32;
typedef unsigned long md5_uintptr;

typedef int __clockid_t;
typedef __clockid_t clockid_t;

struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
};
struct __dirstream;
struct __dirstream;
typedef struct __dirstream DIR;
struct saved_cwd {
  int desc;
  char *name;
};
typedef int __int32_t;
typedef int __pid_t;

typedef struct utmpx STRUCT_UTMP;

typedef struct tokenbuffer token_buffer;
struct quoting_options;
struct quoting_options;
struct quoting_options {
  enum quoting_style style;
  int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
};
struct slotvec {
  size_t size;
  char *val;
};
typedef __off_t off_t;

typedef __mode_t mode_t;
struct mode_change {
  char op;
  char flags;
  mode_t affected;
  mode_t value;
  struct mode_change *next;
};

struct ptr_list {
  char *dirname_end;
  struct ptr_list *next;
};
struct option {
  char const *name;
  int has_arg;
  int *flag;
  int val;
};
typedef int nl_item;

typedef struct hash_tuning Hash_tuning;

typedef struct timezone *__restrict __timezone_ptr_t;

typedef struct __anonstruct_textint_22 textint;
struct __anonstruct_table_23 {
  char const *name;
  int type;
  int value;
};
typedef struct __anonstruct_table_23 table;

typedef struct __anonstruct_parser_control_25 parser_control;

typedef union YYSTYPE YYSTYPE;

typedef signed char yysigned_char;
typedef unsigned int __u_int;
typedef __u_int u_int;

typedef struct __anonstruct___fsid_t_2 __fsid_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsfilcnt_t;
typedef long __fsword_t;

struct exclude;
struct exclude;

typedef unsigned int __socklen_t;
typedef unsigned int uint32_t;
typedef uint32_t in_addr_t;

enum backup_type { none = 0, simple = 1, numbered_existing = 2, numbered = 3 };

extern int getchar_unlocked(void);

extern __attribute__((__nothrow__)) int *(__attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base, unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
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
        {
        }
      }
    }
    if (ptr) {
      p = ptr;
    } else {
      p = &t_ptr;
    }
    q = s;
    {

    while_break___0: /* CIL Label */;
    }
  while_break:;
    {
      tmp___1 = __errno_location();
      *tmp___1 = 0;
      tmp = strtoul((char const * /* __restrict  */)s, (char ** /* __restrict  */)p, strtol_base);
    }

    if ((int)*(*p) != 0) {
      {
        base = 1024;
        suffixes = 1;
        tmp___5 = strchr(valid_suffixes, (int)*(*p));
      }

      { tmp___6 = strchr(valid_suffixes, '0'); }

      goto switch_default;
    case_98: { overflow = bkm_scale___0(&tmp, 512); }
      goto switch_break___0;
    case_66___0: { overflow = bkm_scale___0(&tmp, 1024); }
      goto switch_break___0;
    case_99:
      overflow = (strtol_error)0;
      goto switch_break___0;
    case_69: { overflow = bkm_scale_by_power___0(&tmp, base, 6); }
      goto switch_break___0;
    case_103: { overflow = bkm_scale_by_power___0(&tmp, base, 3); }
      goto switch_break___0;
    case_75: { overflow = bkm_scale_by_power___0(&tmp, base, 1); }
      goto switch_break___0;
    case_109: { overflow = bkm_scale_by_power___0(&tmp, base, 2); }
      goto switch_break___0;
    case_80: { overflow = bkm_scale_by_power___0(&tmp, base, 5); }
      goto switch_break___0;
    case_116: { overflow = bkm_scale_by_power___0(&tmp, base, 4); }
      goto switch_break___0;
    case_119: { overflow = bkm_scale___0(&tmp, 2); }
      goto switch_break___0;
    case_89: { overflow = bkm_scale_by_power___0(&tmp, base, 8); }
      goto switch_break___0;
    case_90: { overflow = bkm_scale_by_power___0(&tmp, base, 7); }
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

__attribute__((__noreturn__)) void xalloc_die(void);

__attribute__((__nothrow__)) void(__attribute__((__leaf__)) rpl_free)(void *p);

void *xmalloc(size_t n);

extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) gettext)(char const *__msgid) __attribute__((__format_arg__(1)));
extern void error(int __status, int __errnum, char const *__format, ...);
int volatile exit_failure;
void (*xalloc_fail_func)(void);
char const xalloc_msg_memory_exhausted[17];
void *xrealloc(void *p, size_t n);

void (*xalloc_fail_func)(void) = (void (*)(void))0;

__attribute__((__noreturn__)) void xalloc_die(void);

extern int gethostname();
__attribute__((__nothrow__)) char *(__attribute__((__leaf__)) rpl_getcwd)(char *buf, size_t size);
char *xgetcwd(void);
char const *quote(char const *name);

extern int putc_unlocked(int __c, FILE *__stream);

char const *version_etc_copyright;

extern void endpwent(void);
extern struct passwd *getpwnam(char const *__name);
extern void endgrent(void);
extern struct group *getgrgid(__gid_t __gid);
extern struct group *getgrnam(char const *__name);

static char const *E_invalid_user = "invalid user";
static char const *E_invalid_group = "invalid group";
static char const *E_bad_spec = "cannot get the login group of a numeric UID";
static char const *E_cannot_omit_both = "cannot omit both user and group";

extern iconv_t iconv_open(char const *__tocode, char const *__fromcode);

static int initialized;
static int is_utf8;
static iconv_t utf8_to_local;

char *base_name(char const *name);
size_t base_len(char const *name);
int strip_trailing_slashes(char *path);

static mbstate_t const mbstate_zero;

extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
extern int close(int __fd);

int save_cwd(struct saved_cwd *cwd);
int restore_cwd(struct saved_cwd const *cwd);
void free_cwd(struct saved_cwd *cwd);
static int have_working_fchdir = 1;

int same_name(char const *source, char const *dest);
char *dir_name(char const *path);
extern ssize_t write(int __fd, void const *__buf, size_t __n);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);

extern void setutxent(void);
extern void endutxent(void);
extern struct utmpx *getutxent(void);
extern int utmpxname(char const *__file);
extern int getc_unlocked(FILE *__stream);
static char const *saved_delim = (char const *)((void *)0);
static char isdelim[256];
char const *const quoting_style_args[8];
enum quoting_style const quoting_style_vals[7];
int set_char_quoting(struct quoting_options *o, char c, int i);

char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char *quotearg_char(char const *arg, char ch);
char *quotearg_colon(char const *arg);

static struct quoting_options default_quoting_options;
int set_char_quoting(struct quoting_options *o, char c, int i) {
  unsigned char uc;
  int *p;
  struct quoting_options *tmp;
  int shift;
  int r;

  {
    uc = (unsigned char)c;

    p = tmp->quote_these_too + (unsigned long)uc / (sizeof(int) * 8UL);
    shift = (int)((unsigned long)uc % (sizeof(int) * 8UL));
    r = (*p >> shift) & 1;
    *p ^= ((i & 1) ^ r) << shift;
    return (r);
  }
}

static char slot0[256];

static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;

static struct quoting_options quoting_options_from_style(enum quoting_style style) {
  struct quoting_options o;
  void *__cil_tmp3;

  {
    {
      o.style = style;
      memset((void *)(o.quote_these_too), 0, sizeof(o.quote_these_too));
    }
    return (o);
  }
}
char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {
  struct quoting_options o;
  struct quoting_options tmp;
  char *tmp___0;
  void *__cil_tmp7;
  void *__cil_tmp8;

  {
    {
      tmp = quoting_options_from_style(s);
      o = tmp;
    }
    return (tmp___0);
  }
}
char *quotearg_char(char const *arg, char ch) {
  struct quoting_options options;
  char *tmp;
  void *__cil_tmp5;

  {
    {
      options = default_quoting_options;
      set_char_quoting(&options, ch, 1);
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
  char *tmp;

  {
    { tmp = quotearg_n_style(n, (enum quoting_style)5, name); }
    return ((char const *)tmp);
  }
}
char const *quote(char const *name) {
  char const *tmp;

  {
    { tmp = quote_n(0, name); }
    return (tmp);
  }
}

struct mode_change *mode_compile(char const *mode_string___0, unsigned int masked_ops);
mode_t mode_adjust(mode_t oldmode, struct mode_change const *changes);
void mode_free(struct mode_change *changes);
extern __attribute__((__nothrow__)) __mode_t(__attribute__((__leaf__)) umask)(__mode_t __mask);
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
    p->next = (struct mode_change *)((void *)0);
    p->op = (char)'=';
    p->flags = (char)0;
    p->value = new_mode;
    p->affected = (mode_t)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
    return (p);
  }
}
static void mode_append_entry(struct mode_change **head, struct mode_change **tail, struct mode_change *e) {
  struct mode_change *tmp;

  {
    if ((unsigned long)*head == (unsigned long)((void *)0)) {
      tmp = e;
      *tail = tmp;
      *head = tmp;
    } else {
      (*tail)->next = e;
      *tail = e;
    }
    return;
  }
}
struct mode_change *mode_compile(char const *mode_string___0, unsigned int masked_ops) {
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
  char *__cil_tmp33;

  {
    {
      head = (struct mode_change *)((void *)0);
      tmp___11 = xstrtoul(mode_string___0, (char **)((void *)0), 8, &octal_value, "");
    }
    if ((unsigned int)tmp___11 == 0U) {

      if (256 >> 3 == 32) {
        if (128 >> 3 == 16) {
          if (64 >> 3 == 8) {
            if ((256 >> 3) >> 3 == 4) {
              if ((128 >> 3) >> 3 == 2) {
                if ((64 >> 3) >> 3 == 1) {
                  mode = (mode_t)octal_value;
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

        if (octal_value & 64UL) {
          tmp___4 = 64;
        } else {
          tmp___4 = 0;
        }
        if (octal_value & 32UL) {
          tmp___5 = 256 >> 3;
        } else {
          tmp___5 = 0;
        }
        if (octal_value & 16UL) {
          tmp___6 = 128 >> 3;
        } else {
          tmp___6 = 0;
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
        mode = (mode_t)(((((((((((tmp | tmp___0) | tmp___1) | tmp___2) | tmp___3) | tmp___4) | tmp___5) | tmp___6) | tmp___7) | tmp___8) | tmp___9) | tmp___10);
      }
      { p = make_node_op_equals(mode); }
      if ((unsigned long)p == (unsigned long)((void *)0)) {
        return ((struct mode_change *)1);
      }
      { mode_append_entry(&head, &tail, p); }
      return (head);
    }
    {
      umask_value = umask((__mode_t)0);
      umask(umask_value);
      mode_string___0--;
    }
    {
      while (1) {
      while_continue: /* CIL Label */;
        affected_bits = (mode_t)0;
        ops_to_mask = 0U;
        affected_bits = (mode_t)0;
        ops_to_mask = 0U;
        mode_string___0++;
        {
          while (1) {
          while_continue___0: /* CIL Label */;
            if ((int const) * mode_string___0 == 103) {
              goto case_103;
            }

            if ((int const) * mode_string___0 == 97) {
              goto case_97;
            }
            goto switch_default;
          case_117:
            affected_bits |= 2496U;
            goto switch_break;
          case_103:
            affected_bits |= (unsigned int)(1024 | (448 >> 3));
            goto switch_break;
          case_111:
            affected_bits |= (unsigned int)(512 | ((448 >> 3) >> 3));
            goto switch_break;
          case_97:
            goto switch_break;
          switch_default:
            goto no_more_affected;
          switch_break:
            mode_string___0++;
          }
        while_break___3: /* CIL Label */;
        }
      no_more_affected:
        if (affected_bits) {
          who_specified_p = 1;
        } else {
          who_specified_p = 0;
          affected_bits = (mode_t)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
          ops_to_mask = masked_ops;
        }
        {
          while (1) {
          while_continue___1: /* CIL Label */;
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
                mode_free(head);
              }
              return ((struct mode_change *)1);
            }
            change->next = (struct mode_change *)((void *)0);
            change->op = (char)*mode_string___0;
            affected_masked = affected_bits;
            if (!who_specified_p) {
              if ((int const) * mode_string___0 == 61) {
                tmp___14 = 1;
              } else {
                tmp___14 = 0;
              }
              if (ops_to_mask & (unsigned int)tmp___14) {
                {
                  tmp___13 = make_node_op_equals((mode_t)0);
                  p___0 = tmp___13;
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
              change->value = (mode_t)0;
              change->flags = (char)0;
              mode_append_entry(&head, &tail, change);
              mode_string___0++;
            }
            {
              while (1) {
              while_continue___2: /* CIL Label */;
                if ((int const) * mode_string___0 == 114) {
                  goto case_114;
                }

                if ((int const) * mode_string___0 == 120) {
                  goto case_120;
                }
                if ((int const) * mode_string___0 == 115) {
                  goto case_115;
                }

                if ((int const) * mode_string___0 == 103) {
                  goto case_103___0;
                }

                goto switch_default___0;
              case_114:
                goto switch_break___0;
              case_119:
                change->value |= (unsigned int)((128 | (128 >> 3)) | ((128 >> 3) >> 3)) & affected_masked;
                goto switch_break___0;
              case_88:
                change->flags = (char)((int)change->flags | 1);
              case_120:
                change->value |= (unsigned int)((64 | (64 >> 3)) | ((64 >> 3) >> 3)) & affected_masked;
                goto switch_break___0;
              case_115:
                change->value |= 3072U & affected_masked;
                goto switch_break___0;
              case_116:
                change->value |= 512U & affected_masked;
                goto switch_break___0;
              case_117___0:
                change->value = (mode_t)448;
                change->flags = (char)((int)change->flags | 2);
                goto switch_break___0;
              case_103___0:
                change->value = (mode_t)(448 >> 3);
                change->flags = (char)((int)change->flags | 2);
                goto switch_break___0;
              case_111___0:
                change->value = (mode_t)((448 >> 3) >> 3);
                change->flags = (char)((int)change->flags | 2);
                goto switch_break___0;
              switch_default___0:
                goto no_more_values;
              switch_break___0:
                mode_string___0++;
              }
            while_break___5: /* CIL Label */;
            }
          no_more_values:;
          }
        while_break___4: /* CIL Label */;
        }
      while_break___1:;
        if (!((int const) * mode_string___0 == 44)) {
          goto while_break;
        }
      }
    while_break___2: /* CIL Label */;
    }
  while_break:;
  invalid: { mode_free(head); }
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
    newmode = oldmode & (unsigned int)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
    {
      while (1) {
      while_continue: /* CIL Label */;
        if (!changes) {
          goto while_break;
        }
        if ((int const)changes->flags & 2) {
          value = newmode & (unsigned int)changes->value;
          if (changes->value & 448U) {

            if (value & 128U) {
              tmp___0 = (128 >> 3) | ((128 >> 3) >> 3);
            } else {
              tmp___0 = 0;
            }
            if (value & 64U) {
              tmp___1 = (64 >> 3) | ((64 >> 3) >> 3);
            } else {
              tmp___1 = 0;
            }
            value |= (unsigned int)((tmp | tmp___0) | tmp___1);
          } else {
            if (changes->value & (unsigned int const)(448 >> 3)) {

              if (value & (unsigned int)(128 >> 3)) {
                tmp___3 = 128 | ((128 >> 3) >> 3);
              } else {
                tmp___3 = 0;
              }
              if (value & (unsigned int)(64 >> 3)) {
                tmp___4 = 64 | ((64 >> 3) >> 3);
              } else {
                tmp___4 = 0;
              }
              value |= (unsigned int)((tmp___2 | tmp___3) | tmp___4);
            } else {

              if (value & (unsigned int)((128 >> 3) >> 3)) {
                tmp___6 = 128 | (128 >> 3);
              } else {
                tmp___6 = 0;
              }

              value |= (unsigned int)((tmp___5 | tmp___6) | tmp___7);
            }
          }
          value &= (unsigned int)changes->affected;
        } else {
          value = (mode_t)changes->value;
        }
        if ((int const)changes->op == 61) {
          goto case_61;
        }

        if ((int const)changes->op == 45) {
          goto case_45;
        }
        goto switch_break;
      case_61:
        newmode = (newmode & (unsigned int)(~changes->affected)) | value;
        goto switch_break;
      case_43:
        newmode |= value;
        goto switch_break;
      case_45:
        newmode &= ~value;
        goto switch_break;
      switch_break:
        changes = (struct mode_change const *)changes->next;
      }
    while_break___0: /* CIL Label */;
    }
  while_break:;
    return (newmode);
  }
}
void mode_free(struct mode_change *changes) {
  register struct mode_change *next;

  {
    {

    while_break___0: /* CIL Label */;
    }
  while_break:;
    return;
  }
}
static unsigned short const __mon_yday[2][13] = {{(unsigned short const)0, (unsigned short const)31, (unsigned short const)59, (unsigned short const)90, (unsigned short const)120, (unsigned short const)151, (unsigned short const)181, (unsigned short const)212, (unsigned short const)243,
                                                  (unsigned short const)273, (unsigned short const)304, (unsigned short const)334, (unsigned short const)365},
                                                 {(unsigned short const)0, (unsigned short const)31, (unsigned short const)60, (unsigned short const)91, (unsigned short const)121, (unsigned short const)152, (unsigned short const)182, (unsigned short const)213, (unsigned short const)244,
                                                  (unsigned short const)274, (unsigned short const)305, (unsigned short const)335, (unsigned short const)366}};
static time_t localtime_offset;

int make_dir(char const *dir, char const *dirpath, mode_t mode, int *created_dir_p);

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) mkdir)(char const *__path, __mode_t __mode);

int make_dir(char const *dir, char const *dirpath, mode_t mode, int *created_dir_p) {
  int fail;
  int created_dir;
  int tmp;
  struct stat stats;
  int saved_errno;
  int *tmp___0;
  char const *tmp___1;
  char *tmp___2;
  char const *tmp___3;
  char *tmp___4;
  int tmp___5;
  void *__cil_tmp16;
  char *__cil_tmp17;
  char *__cil_tmp18;

  {
    {
      fail = 0;
      tmp = mkdir(dir, mode);
      created_dir = tmp == 0;
    }
    if (!created_dir) {
      {
        tmp___0 = __errno_location();
        saved_errno = *tmp___0;
      }
      if (tmp___5) {
        {
          tmp___1 = quote(dirpath);
          tmp___2 = gettext("cannot create directory %s");
          error(0, saved_errno, (char const *)tmp___2, tmp___1);
          fail = 1;
        }
      } else {
        if (!((stats.st_mode & 61440U) == 16384U)) {
          {
            tmp___3 = quote(dirpath);
            tmp___4 = gettext("%s exists but is not a directory");
            error(0, 0, (char const *)tmp___4, tmp___3);
            fail = 1;
          }
        }
      }
    }

    return (fail);
  }
}
extern struct _IO_FILE *stdout;

extern int optind;
extern int opterr;

extern int fclose(FILE *__stream);

extern int ungetc(int __c, FILE *__stream);

static char const *volatile charset_aliases;
extern struct passwd *getpwuid(__uid_t __uid);
static struct userid *user_alist;
static struct userid *nouser_alist;
static struct userid *group_alist;
static struct userid *nogroup_alist;

static int const block_size_opts[2] = {(int const)112, (int const)80};

extern void setgrent(void);
extern struct group *getgrent(void);

static unsigned char const yytranslate[274] = {
    (unsigned char const)0,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)20, (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)21, (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)19, (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2, (unsigned char const)2,
    (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)2,  (unsigned char const)1,  (unsigned char const)2,  (unsigned char const)3,  (unsigned char const)4,  (unsigned char const)5,  (unsigned char const)6,  (unsigned char const)7, (unsigned char const)8,
    (unsigned char const)9,  (unsigned char const)10, (unsigned char const)11, (unsigned char const)12, (unsigned char const)13, (unsigned char const)14, (unsigned char const)15, (unsigned char const)16, (unsigned char const)17, (unsigned char const)18};
static unsigned char const yyr1[56] = {(unsigned char const)0,  (unsigned char const)22, (unsigned char const)23, (unsigned char const)23, (unsigned char const)24, (unsigned char const)24, (unsigned char const)24, (unsigned char const)24, (unsigned char const)24, (unsigned char const)24,
                                       (unsigned char const)24, (unsigned char const)25, (unsigned char const)25, (unsigned char const)25, (unsigned char const)25, (unsigned char const)25, (unsigned char const)26, (unsigned char const)26, (unsigned char const)27, (unsigned char const)27,
                                       (unsigned char const)27, (unsigned char const)28, (unsigned char const)28, (unsigned char const)28, (unsigned char const)29, (unsigned char const)29, (unsigned char const)29, (unsigned char const)29, (unsigned char const)29, (unsigned char const)29,
                                       (unsigned char const)29, (unsigned char const)29, (unsigned char const)29, (unsigned char const)30, (unsigned char const)30, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
                                       (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)31,
                                       (unsigned char const)31, (unsigned char const)31, (unsigned char const)31, (unsigned char const)32, (unsigned char const)33, (unsigned char const)33};

static unsigned char const yydefact[66] = {(unsigned char const)2,  (unsigned char const)0,  (unsigned char const)1,  (unsigned char const)21, (unsigned char const)43, (unsigned char const)19, (unsigned char const)46, (unsigned char const)16, (unsigned char const)49, (unsigned char const)0,
                                           (unsigned char const)40, (unsigned char const)52, (unsigned char const)37, (unsigned char const)18, (unsigned char const)0,  (unsigned char const)53, (unsigned char const)3,  (unsigned char const)4,  (unsigned char const)5,  (unsigned char const)6,
                                           (unsigned char const)8,  (unsigned char const)7,  (unsigned char const)9,  (unsigned char const)34, (unsigned char const)10, (unsigned char const)22, (unsigned char const)17, (unsigned char const)0,  (unsigned char const)29, (unsigned char const)20,
                                           (unsigned char const)42, (unsigned char const)45, (unsigned char const)48, (unsigned char const)39, (unsigned char const)51, (unsigned char const)36, (unsigned char const)23, (unsigned char const)41, (unsigned char const)44, (unsigned char const)11,
                                           (unsigned char const)47, (unsigned char const)31, (unsigned char const)38, (unsigned char const)50, (unsigned char const)35, (unsigned char const)0,  (unsigned char const)0,  (unsigned char const)0,  (unsigned char const)33, (unsigned char const)28,
                                           (unsigned char const)0,  (unsigned char const)27, (unsigned char const)32, (unsigned char const)26, (unsigned char const)54, (unsigned char const)24, (unsigned char const)30, (unsigned char const)55, (unsigned char const)13, (unsigned char const)0,
                                           (unsigned char const)12, (unsigned char const)0,  (unsigned char const)54, (unsigned char const)25, (unsigned char const)15, (unsigned char const)14};

static yysigned_char const yypact[66] = {(yysigned_char const)-17, (yysigned_char const)0,   (yysigned_char const)-17, (yysigned_char const)1,   (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)19,  (yysigned_char const)-17, (yysigned_char const)-16,
                                         (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)32,  (yysigned_char const)26,  (yysigned_char const)14,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17,
                                         (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)27,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-13, (yysigned_char const)24,  (yysigned_char const)-17,
                                         (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17,
                                         (yysigned_char const)-17, (yysigned_char const)25,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)29,  (yysigned_char const)30,  (yysigned_char const)31,  (yysigned_char const)-17, (yysigned_char const)-17,
                                         (yysigned_char const)33,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)28,  (yysigned_char const)34,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)35,
                                         (yysigned_char const)-17, (yysigned_char const)36,  (yysigned_char const)-7,  (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17};
static yysigned_char const yypgoto[12] = {(yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17,
                                          (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-17, (yysigned_char const)-12};
static unsigned char const yytable[56] = {(unsigned char const)2,  (unsigned char const)27, (unsigned char const)28, (unsigned char const)57, (unsigned char const)49, (unsigned char const)3,  (unsigned char const)4,  (unsigned char const)5,  (unsigned char const)6,  (unsigned char const)7,
                                          (unsigned char const)64, (unsigned char const)8,  (unsigned char const)9,  (unsigned char const)10, (unsigned char const)11, (unsigned char const)12, (unsigned char const)13, (unsigned char const)14, (unsigned char const)15, (unsigned char const)36,
                                          (unsigned char const)37, (unsigned char const)25, (unsigned char const)38, (unsigned char const)26, (unsigned char const)39, (unsigned char const)40, (unsigned char const)41, (unsigned char const)42, (unsigned char const)43, (unsigned char const)44,
                                          (unsigned char const)48, (unsigned char const)45, (unsigned char const)30, (unsigned char const)46, (unsigned char const)31, (unsigned char const)47, (unsigned char const)29, (unsigned char const)32, (unsigned char const)57, (unsigned char const)33,
                                          (unsigned char const)34, (unsigned char const)35, (unsigned char const)51, (unsigned char const)52, (unsigned char const)50, (unsigned char const)58, (unsigned char const)53, (unsigned char const)59, (unsigned char const)54, (unsigned char const)55,
                                          (unsigned char const)65, (unsigned char const)56, (unsigned char const)0,  (unsigned char const)62, (unsigned char const)63, (unsigned char const)61};

static table const dst_table[1] = {{"DST", 259, 0}};

extern char *getcwd(char *buf, size_t size);
__attribute__((__nothrow__)) char *(__attribute__((__leaf__)) rpl_getcwd)(char *buf, size_t size);

extern int(__attribute__((__nonnull__(1))) dirfd)(DIR *__dirp);

__attribute__((__nothrow__)) void(__attribute__((__leaf__)) rpl_free)(void *p);
void(__attribute__((__leaf__)) rpl_free)(void *p) {

  { return; }
}

int volatile exit_failure = (int volatile)1;
extern struct _IO_FILE *stdin;

extern int fnmatch(char const *__pattern, char const *__name, int __flags);
extern int fcntl(int __fd, int __cmd, ...);
size_t dir_len(char const *path);
char const diacrit_base[256];
char const diacrit_diac[256];

void close_stdout(void);

static char const *file_name;
void close_stdout(void) {
  int e;
  int tmp___0;
  int tmp___1;
  size_t tmp___2;
  int *tmp___3;
  int tmp___4;
  char const *write_error;
  char *tmp___5;
  char *tmp___6;
  char *__cil_tmp10;

  {
    { tmp___1 = ferror_unlocked(stdout); }
    if (tmp___1) {
      tmp___0 = 0;
    } else {
      tmp___0 = -1;
    }
    e = tmp___0;

    { tmp___4 = fclose(stdout); }

    if (0 <= e) {
      {
        tmp___5 = gettext("write error");
        write_error = (char const *)tmp___5;
      }
      if (file_name) {
        {
          tmp___6 = quotearg_colon(file_name);
          error((int)exit_failure, e, "%s: %s", tmp___6, write_error);
        }
      } else {
        { error((int)exit_failure, e, "%s", write_error); }
      }
    }
    return;
  }
}

extern struct hostent *gethostbyname(char const *__name);

void (*argmatch_die)(void);
char const *simple_backup_suffix;
char const *simple_backup_suffix = "~";
static char const *const backup_args[9] = {(char const * /* const  */) "none", (char const * /* const  */) "off",      (char const * /* const  */) "simple", (char const * /* const  */) "never",         (char const * /* const  */) "existing",
                                           (char const * /* const  */) "nil",  (char const * /* const  */) "numbered", (char const * /* const  */) "t",      (char const * /* const  */)((char const *)0)};
static enum backup_type const backup_types[8] = {(enum backup_type const)0, (enum backup_type const)0, (enum backup_type const)1, (enum backup_type const)1, (enum backup_type const)2, (enum backup_type const)2, (enum backup_type const)3, (enum backup_type const)3};
extern struct _IO_FILE *stderr;
void usage(int status);

extern int printf(char const *__restrict __format, ...);
extern char *optarg;

char *program_name;
static int create_parents;
static struct option const longopts[6] = {{"mode", 1, (int *)((void *)0), 'm'}, {"parents", 0, (int *)((void *)0), 'p'}, {"verbose", 0, (int *)((void *)0), 'v'}, {"help", 0, (int *)0, -130}, {"version", 0, (int *)0, -131}, {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
void usage(int status) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;
  char *__cil_tmp10;
  char *__cil_tmp11;
  char *__cil_tmp12;
  char *__cil_tmp13;
  char *__cil_tmp14;
  char *__cil_tmp15;
  char *__cil_tmp16;
  char *__cil_tmp17;

  {

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
  char *tmp;
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
  char const *tmp___6;
  char *tmp___7;
  char const *tmp___8;
  char const *tmp___9;
  char *tmp___10;
  int *tmp___11;
  char *__cil_tmp28;
  char *__cil_tmp29;
  char *__cil_tmp30;
  char *__cil_tmp31;
  char *__cil_tmp32;
  char *__cil_tmp33;
  char *__cil_tmp34;
  char *__cil_tmp35;
  char *__cil_tmp36;

  {
    {
      specified_mode = (char const *)((void *)0);
      verbose_fmt_string = (char const *)((void *)0);
      errors = 0;
      program_name = *(argv + 0);
      setlocale(6, "");
      bindtextdomain("coreutils", "/usr/local/share/locale");
      textdomain("coreutils");
      atexit(&close_stdout);
      create_parents = 0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */;
        { optc = getopt_long(argc, (char *const *)argv, "pm:v", longopts, (int *)((void *)0)); }
        if (!(optc != -1)) {
          goto while_break;
        }

        if (optc == 109) {
          goto case_109;
        }

        goto switch_default;
      case_0:
        goto switch_break;
      case_112:
        create_parents = 1;
        goto switch_break;
      case_109:
        specified_mode = (char const *)optarg;
        goto switch_break;
      case_118: {
        tmp = gettext("created directory %s");
        verbose_fmt_string = (char const *)tmp;
      }
        goto switch_break;
      case_neg_130: { usage(0); }
        goto switch_break;
      case_neg_131: { exit(0); }
        goto switch_break;
      switch_default: { usage(1); }
      switch_break:;
      }
    while_break___1: /* CIL Label */;
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
      umask_value = tmp___1;
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
      }
      { newmode = mode_adjust(newmode, (struct mode_change const *)change); }
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */;
        if (!(optind < argc)) {
          goto while_break___0;
        }
        fail = 0;
        if (create_parents) {
          {
            dir = *(argv + optind);
          }
        } else {
          {
            dir___0 = (char const *)*(argv + optind);
            fail = make_dir(dir___0, dir___0, newmode, &dir_created);
          }

          if (fail == 0) {
            if (specified_mode) {
              if (dir_created) {
                {
                  fail = chmod(dir___0, newmode);
                }
                if (fail) {
                  {
                    tmp___9 = quote(dir___0);
                    tmp___10 = gettext("cannot set permissions of directory %s");
                    tmp___11 = __errno_location();
                    error(0, *tmp___11, (char const *)tmp___10, tmp___9);
                  }
                }
              }
            }
          }
        }

        optind++;
      }
    while_break___2: /* CIL Label */;
    }
  while_break___0: { exit(errors); }
  }
}
