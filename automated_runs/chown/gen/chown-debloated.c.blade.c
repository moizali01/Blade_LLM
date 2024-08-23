typedef unsigned long size_t;
typedef long __off_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef long __time_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef long __syscall_slong_t;
typedef __mode_t mode_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
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

typedef struct hash_table Hash_table;

typedef struct __dirstream DIR;
typedef int wchar_t;

struct mbchar {

  _Bool wc_valid;
};
struct mbuiter_multi {
  _Bool in_shift;

  _Bool next_done;
  struct mbchar cur;
};
typedef struct mbuiter_multi mbui_iterator_t;
typedef __gid_t gid_t;
typedef __uid_t uid_t;
typedef unsigned long uintmax_t;
struct dev_ino {
  ino_t st_ino;
  dev_t st_dev;
};
struct cycle_check_state {
  struct dev_ino dev_ino;
  uintmax_t chdir_counter;
};
typedef long ptrdiff_t;
struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
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
enum strtol_error {
  LONGINT_OK = 0,
  LONGINT_OVERFLOW = 1,
  LONGINT_INVALID_SUFFIX_CHAR = 2,
  LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
  LONGINT_INVALID = 4
};
typedef enum strtol_error strtol_error;
struct option {};

typedef __nlink_t nlink_t;
struct I_ring {
  int ir_data[4];
  int ir_default_val;
  unsigned int ir_front;
  unsigned int ir_back;
};
typedef struct I_ring I_ring;

union __anonunion_fts_cycle_29 {

  struct cycle_check_state *state;
};
struct __anonstruct_FTS_28 {
  struct _ftsent *fts_cur;
  struct _ftsent *fts_child;
  struct _ftsent **fts_array;

  char *fts_path;
  int fts_rfd;
  int fts_cwd_fd;
  size_t fts_pathlen;
  size_t fts_nitems;
  int (*fts_compar)(struct _ftsent const **, struct _ftsent const **);
  int fts_options;

  union __anonunion_fts_cycle_29 fts_cycle;
  I_ring fts_fd_ring;
};
typedef struct __anonstruct_FTS_28 FTS;
struct _ftsent {
  struct _ftsent *fts_cycle;
  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;

  char *fts_accpath;
  char *fts_path;
  int fts_errno;

  size_t fts_pathlen;
  FTS *fts_fts;
  ptrdiff_t fts_level;
  size_t fts_namelen;
  nlink_t fts_n_dirs_remaining;
  unsigned short fts_info;
  unsigned short fts_flags;
  unsigned short fts_instr;
  struct stat fts_statp[1];
  char fts_name[1];
};
typedef struct _ftsent FTSENT;
struct passwd {
  char *pw_name;
  char *pw_passwd;
  __uid_t pw_uid;
};
struct group {
  char *gr_name;
  char *gr_passwd;
  __gid_t gr_gid;
};

struct quoting_options {
  enum quoting_style style;

  unsigned int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
  char const *left_quote;
  char const *right_quote;
};
struct slotvec {
  size_t size;
};

struct Active_dir {

  FTSENT *fts_ent;
};

enum Change_status {
  CH_NOT_APPLIED = 1,
  CH_SUCCEEDED = 2,
  CH_FAILED = 3,
  CH_NO_CHANGE_REQUESTED = 4
};

struct Chown_option {

  _Bool recurse;
  struct dev_ino *root_dev_ino;
  _Bool affect_symlink_referent;
  _Bool force_silent;
  char *user_name;
  char *group_name;
};
enum RCH_status {
  RC_ok = 2,
  RC_excluded = 3,
  RC_inode_changed = 4,
  RC_do_ordinary_chown = 5,
  RC_error = 6
};
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));

extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag, ...);

char *last_component(char const *name);

extern DIR *fdopendir(int __fd);
DIR *rpl_fdopendir(int fd);

DIR *rpl_fdopendir(int fd) {
  struct stat st;
  int tmp;

  DIR *tmp___1;

  {
    tmp = fstat(fd, &st);
    if (tmp) {
      return ((DIR *)((void *)0));
    }
    if (!((st.st_mode & 61440U) == 16384U)) {
    }
    tmp___1 = fdopendir(fd);
    return (tmp___1);
  }
}

int fd_safer(int fd) {

  int *tmp___0;

  { return (fd); }
}

__inline static void mbuiter_multi_next(struct mbuiter_multi *iter) {
  int tmp;
  size_t tmp___0;

  _Bool tmp___3;

  {
    if (iter->next_done) {
    }
    if (iter->in_shift) {
    }

    if (tmp___3) {

      iter->cur.wc_valid = (_Bool)1;
    } else {

    with_shift:
      tmp___0 = __ctype_get_mb_cur_max();
    }
  }
}

int dup_safer(int fd) {

  {}
}

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);

_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb);

_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb) {
  _Bool tmp;

  {

    (state->chdir_counter)++;

    if (tmp) {

      state->dev_ino.st_dev = (dev_t)sb->st_dev;
      state->dev_ino.st_ino = (ino_t)sb->st_ino;
    }
    return ((_Bool)0);
  }
}

int close_stream(FILE *stream);

int close_stream(FILE *stream) {

  int *tmp___2;

  {}
}

int set_cloexec_flag(int desc, _Bool value) {
  int flags;
  int tmp;

  {

    flags = tmp;

    return (-1);
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file,
                                         struct stat *__restrict __buf);

char *last_component(char const *name) {
  char const *base;
  char const *p;

  {

    while (1) {

      if (!((int const) * base == 47)) {
        goto while_break;
      }
    }
  while_break:
    p = base;

    ;
    return ((char *)base);
  }
}

extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {

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

    q = s;
    ch = (unsigned char)*q;
    while (1) {
    }

    ;

    tmp = strtoul(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {

    } else {
      tmp___4 = __errno_location();
    }
    if (!valid_suffixes) {

      return (err);
    }
    if ((int)*(*p) != 0) {

      if ((int)*(*p) == 71) {
      }

      if ((int)*(*p) == 80) {
      }

      goto switch_default;
    case_98:

      goto switch_break___0;
    case_66___0:

      goto switch_break___0;
    case_99:

      goto switch_break___0;
    case_69:
      overflow = bkm_scale_by_power___0(&tmp, base, 6);
      goto switch_break___0;
    case_71:

      goto switch_break___0;
    case_107:
      overflow = bkm_scale_by_power___0(&tmp, base, 1);
      goto switch_break___0;
    case_77:
      overflow = bkm_scale_by_power___0(&tmp, base, 2);
      goto switch_break___0;
    case_80:
      overflow = bkm_scale_by_power___0(&tmp, base, 5);
      goto switch_break___0;
    case_84:
      overflow = bkm_scale_by_power___0(&tmp, base, 4);
      goto switch_break___0;
    case_119:

      goto switch_break___0;
    case_89:
      overflow = bkm_scale_by_power___0(&tmp, base, 8);
      goto switch_break___0;
    case_90:

      goto switch_break___0;
    switch_default:
      *val = tmp;

    switch_break___0:
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
    }
    *val = tmp;
  }
}

void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    tmp = malloc(n);
    p = tmp;

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

char *xstrdup(char const *string) {
  size_t tmp;
  char *tmp___0;

  {
    tmp = strlen(string);
    tmp___0 = (char *)xmemdup((void const *)string, tmp + 1UL);
    return (tmp___0);
  }
}
__attribute__((__nothrow__))
FTS *(__attribute__((__warn_unused_result__, __leaf__)) fts_open)(
    char *const *argv, int options,
    int (*compar)(FTSENT const **, FTSENT const **));
FTS *xfts_open(char *const *argv, int options,
               int (*compar)(FTSENT const **, FTSENT const **));

FTS *xfts_open(char *const *argv, int options,
               int (*compar)(FTSENT const **, FTSENT const **)) {
  FTS *fts;
  FTS *tmp;
  int *tmp___0;

  {
    tmp = fts_open(argv, options | 512, compar);
    fts = tmp;

    return (fts);
  }
}

void xalloc_die(void) {

  {}
}

extern struct passwd *getpwnam(char const *__name);

extern struct group *getgrnam(char const *__name);

static char const *E_invalid_user = "invalid user";

static char const *parse_with_separator(char const *spec, char const *separator,
                                        uid_t *uid, gid_t *gid, char **username,
                                        char **groupname) {
  char const *error_msg;
  struct passwd *pwd;
  struct group *grp;
  char *u;
  char const *g;
  char *gname;
  uid_t unum;
  gid_t gnum;

  size_t ulen;
  struct passwd *tmp___0;
  _Bool use_login_group;
  int tmp___1;
  unsigned long tmp___2;
  strtol_error tmp___3;

  char *tmp___5;
  struct group *tmp___6;

  char const *tmp___9;

  {

    unum = *uid;
    gnum = *gid;
    error_msg = (char const *)((void *)0);

    u = (char *)((void *)0);
    if ((unsigned long)separator == (unsigned long)((void *)0)) {
      if (*spec) {
        u = xstrdup(spec);
      }
    } else {
      ulen = (size_t)(separator - spec);
      if (ulen != 0UL) {
        u = (char *)xmemdup((void const *)spec, ulen + 1UL);
        *(u + ulen) = (char)'\000';
      }
    }
    if ((unsigned long)separator == (unsigned long)((void *)0)) {
      g = (char const *)((void *)0);
    } else {
      if ((int const) * (separator + 1) == 0) {
        g = (char const *)((void *)0);
      } else {
        g = separator + 1;
      }
    }
    if ((unsigned long)u != (unsigned long)((void *)0)) {
      if ((int)*u == 43) {
        pwd = (struct passwd *)((void *)0);
      } else {
        tmp___0 = getpwnam((char const *)u);
        pwd = tmp___0;
      }
      if ((unsigned long)pwd == (unsigned long)((void *)0)) {

        use_login_group = (_Bool)tmp___1;
        if (use_login_group) {

        } else {

          if ((unsigned int)tmp___3 == 0U) {
            if (tmp___2 <= 4294967295UL) {
              if ((uid_t)tmp___2 != 4294967295U) {
                unum = (uid_t)tmp___2;
              } else {
              }
            } else {
              error_msg = E_invalid_user;
            }
          } else {
            error_msg = E_invalid_user;
          }
        }
      } else {
        unum = pwd->pw_uid;
        if ((unsigned long)g == (unsigned long)((void *)0)) {
        }
      }
      endpwent();
    }
    if ((unsigned long)g != (unsigned long)((void *)0)) {
      if ((unsigned long)error_msg == (unsigned long)((void *)0)) {
        if ((int const) * g == 43) {

        } else {
          tmp___6 = getgrnam(g);
          grp = tmp___6;
        }
        if ((unsigned long)grp == (unsigned long)((void *)0)) {

        } else {
          gnum = grp->gr_gid;
        }
        endgrent();
        gname = xstrdup(g);
      }
    }
    if ((unsigned long)error_msg == (unsigned long)((void *)0)) {
      *uid = unum;
      *gid = gnum;

      *groupname = gname;

    } else {
    }
    free((void *)u);
    tmp___9 = (char const *)gettext(error_msg);
    return (tmp___9);
  }
}
char const *parse_user_spec(char const *spec, uid_t *uid, gid_t *gid,
                            char **username, char **groupname) {
  char const *colon;
  char const *tmp;
  char const *error_msg;
  char const *tmp___0;
  char const *dot;

  {
    tmp = (char const *)strchr(spec, ':');
    colon = tmp;
    tmp___0 = parse_with_separator(spec, colon, uid, gid, username, groupname);

    return (error_msg);
  }
}

#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
size_t strnlen1(char const *string, size_t maxlen) {

  {}
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

  _Bool elide_outer_quotes;
  unsigned char c;
  unsigned char esc;

  int tmp___6;
  size_t tmp___7;

  {
    len = (size_t)0;

    if ((unsigned int)quoting_style == 6U) {
    }
    if ((unsigned int)quoting_style == 7U) {
      goto case_6;
    }

    if ((unsigned int)quoting_style == 0U) {
    }
    goto switch_default;
  case_4:

  case_3:
    if (!elide_outer_quotes) {

      ;
    }

    goto switch_break;
  case_5:

  case_6:
    if ((unsigned int)quoting_style != 8U) {
    }

    quote_string = right_quote;
    quote_string_len = strlen(quote_string);

  case_1:

  case_2:
    if (!elide_outer_quotes) {

      ;
    }

  case_0:

    goto switch_break;
  switch_default:

  switch_break:
    i = (size_t)0;
    while (1) {

      if (argsize == 0xffffffffffffffffUL) {

      } else {
        tmp___6 = i == argsize;
      }
      if (tmp___6) {
        goto while_break___3;
      }

      if ((int)c == 37) {
        goto case_37;
      }

      if ((int)c == 46) {
      }
      if ((int)c == 47) {
        goto case_37;
      }

      if ((int)c == 49) {
      }

      if ((int)c == 52) {
        goto case_37;
      }

      if ((int)c == 120) {
      }

    case_0___0:

    case_63:

    case_2___0:

    case_3___0:

      goto switch_break___1;

    switch_break___1:;

    case_7___0:

    case_8___0:

    case_12:

    case_10:

      goto c_and_shell_escape;
    case_13:

    case_9:
      esc = (unsigned char)'t';

    case_11:

    case_92:

    c_and_shell_escape:

    case_123:
      if (argsize == 0xffffffffffffffffUL) {

      } else {
      }

    case_35:

    case_32:

    case_39___0:

    case_37:

    switch_break___0:;

      ;
    store_c:
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)c;
        }
      }

      ;
    __Cont:
      i++;
    }
  while_break___3:;

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

  {

    if (n < 0) {
    }
    if (nslots <= n0) {

      if ((size_t)tmp___0 / sizeof(*sv) < n1) {
      }

      sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
      slotvec = sv;
    }

    tmp___2 = quotearg_buffer_restyled(
        val, size, arg, argsize, (enum quoting_style)options->style, flags,
        (unsigned int const *)(options->quote_these_too),
        (char const *)options->left_quote, (char const *)options->right_quote);

    if (size <= qsize) {

      (sv + n)->size = size;
    }
  }
}

char *quotearg_colon(char const *arg) {

  {}
}

char const *quote(char const *name) {
  char const *tmp;

  { return (tmp); }
}

DIR *opendir_safer(char const *name) {
  DIR *dp;
  DIR *tmp;

  DIR *newdp;

  {
    tmp = opendir(name);
    dp = tmp;

    return (dp);
  }
}

int openat_safer(int fd, char const *file, int flags, ...) {
  mode_t mode;

  int tmp;
  int tmp___0;

  {
    mode = (mode_t)0;

    tmp = openat(fd, file, flags, mode);
    tmp___0 = fd_safer(tmp);
    return (tmp___0);
  }
}

int mbscasecmp(char const *s1, char const *s2) {
  mbui_iterator_t iter1;
  mbui_iterator_t iter2;

  size_t tmp___25;

  {

    if (tmp___25 > 1UL) {

      mbuiter_multi_next(&iter1);

      mbuiter_multi_next(&iter2);

      return (0);
    } else {

      ;
    }
  }
}

extern int optind;

void *hash_delete(Hash_table *table___0, void const *entry);

__attribute__((__nothrow__))
FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp);
__attribute__((__nothrow__)) int(__attribute__((__leaf__)) fts_set)(
    FTS *sp __attribute__((__unused__)), FTSENT *p, int instr);

static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen);
static FTSENT *fts_build(FTS *sp, int type);

static void fts_padjust(FTS *sp, FTSENT *head);
static _Bool fts_palloc(FTS *sp, size_t more);

static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow);
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir);

static _Bool setup_dir(FTS *fts) {

  {
    if (fts->fts_options & 258) {

    } else {
      fts->fts_cycle.state =
          (struct cycle_check_state *)malloc(sizeof(*(fts->fts_cycle.state)));
      if (!fts->fts_cycle.state) {
        return ((_Bool)0);
      }
    }
  }
}
static _Bool enter_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;
  struct Active_dir *ad;

  struct Active_dir *ad_from_table;

  {
    if (fts->fts_options & 258) {
      st = (struct stat const *)(ent->fts_statp);

      if ((unsigned long)ad_from_table != (unsigned long)ad) {

        ent->fts_cycle = ad_from_table->fts_ent;
      }
    } else {
    }
    return ((_Bool)1);
  }
}
static void leave_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;

  FTSENT *parent;

  {
    st = (struct stat const *)(ent->fts_statp);
    if (fts->fts_options & 258) {

    } else {
      parent = ent->fts_parent;
      if ((unsigned long)parent != (unsigned long)((void *)0)) {
      }
    }
  }
}
static void free_dir(FTS *sp) {

  {
    if (sp->fts_options & 258) {

    } else {
    }
    return;
  }
}

static void fts_set_stat_required(FTSENT *p, _Bool required) {

  {

    ;
    if (required) {
      p->fts_statp[0].st_size = (__off_t)2;
    } else {
    }
    return;
  }
}
__inline static DIR *opendirat(int fd, char const *dir) {
  int new_fd;
  int tmp;
  DIR *dirp;

  int *tmp___1;

  {
    tmp = openat_safer(fd, dir, 67840);
    new_fd = tmp;
    if (new_fd < 0) {
      return ((DIR *)((void *)0));
    }
    set_cloexec_flag(new_fd, (_Bool)1);
    dirp = rpl_fdopendir(new_fd);

    return (dirp);
  }
}
static void cwd_advance_fd(FTS *sp, int fd, _Bool chdir_down_one) {

  {

    ;
    if (chdir_down_one) {

    } else {
      if (!(sp->fts_options & 4)) {
      }
    }
    sp->fts_cwd_fd = fd;
  }
}
__inline static int diropen(FTS const *sp, char const *dir) {
  int open_flags;
  int tmp;
  int fd;

  int tmp___1;
  int tmp___2;

  {

    open_flags = 67840 | tmp;
    if (sp->fts_options & 512) {

    } else {
      tmp___1 = open_safer(dir, open_flags);
    }
    fd = tmp___2;

    return (fd);
  }
}

FTS *(__attribute__((__warn_unused_result__, __leaf__)) fts_open)(
    char *const *argv, int options,
    int (*compar)(FTSENT const **, FTSENT const **)) {
  FTS *sp;
  FTSENT *p;
  FTSENT *root;
  size_t nitems;
  FTSENT *parent;
  FTSENT *tmp;
  _Bool defer_stat;
  int *tmp___0;
  int *tmp___1;
  int *tmp___2;
  size_t maxarglen;

  size_t tmp___5;
  _Bool tmp___6;
  int tmp___7;
  size_t len;
  size_t tmp___8;
  struct _ftsent *tmp___9;
  _Bool tmp___10;

  {

    if (!(options & 18)) {
    }
    sp = (FTS *)malloc(sizeof(FTS));
    if ((unsigned long)sp == (unsigned long)((void *)0)) {
    }
    memset((void *)sp, 0, sizeof(FTS));

    sp->fts_options = options;

    sp->fts_cwd_fd = -100;

    tmp___6 = fts_palloc(sp, tmp___5);
    if (!tmp___6) {
    }
    if ((unsigned long)*argv != (unsigned long)((void *)0)) {
      parent = fts_alloc(sp, "", (size_t)0);
      if ((unsigned long)parent == (unsigned long)((void *)0)) {
        goto mem2;
      }
      parent->fts_level = (ptrdiff_t)-1;
    }

    defer_stat = (_Bool)tmp___7;
    root = (FTSENT *)((void *)0);
    nitems = (size_t)0;
    while (1) {

      if (!((unsigned long)*argv != (unsigned long)((void *)0))) {
        goto while_break;
      }
      tmp___8 = strlen((char const *)*argv);
      len = tmp___8;
      p = fts_alloc(sp, (char const *)*argv, len);
      if ((unsigned long)p == (unsigned long)((void *)0)) {
      }

      p->fts_parent = parent;
      p->fts_accpath = p->fts_name;
      if (defer_stat) {
        if ((unsigned long)root != (unsigned long)((void *)0)) {
          p->fts_info = (unsigned short)11;
          fts_set_stat_required(p, (_Bool)1);
        } else {
          p->fts_info = fts_stat(sp, p, (_Bool)0);
        }
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);
      }
      if (compar) {
        p->fts_link = root;
        root = p;
      } else {
        p->fts_link = (struct _ftsent *)((void *)0);
        if ((unsigned long)root == (unsigned long)((void *)0)) {
          root = p;

        } else {
        }
      }
      argv++;
      nitems++;
    }
  while_break:;
    if (compar) {
    }
    tmp___9 = fts_alloc(sp, "", (size_t)0);
    sp->fts_cur = tmp___9;
    if ((unsigned long)tmp___9 == (unsigned long)((void *)0)) {
    }
    (sp->fts_cur)->fts_link = root;

    tmp___10 = setup_dir(sp);
    if (!tmp___10) {
    }

    return (sp);
  mem3:

  mem2:

  mem1:
    free((void *)sp);
  }
}
static void fts_load(FTS *sp, FTSENT *p) {

  char *cp;
  size_t tmp;
  char *tmp___0;

  {

    p->fts_pathlen = tmp;

    cp = strrchr((char const *)(p->fts_name), '/');

    tmp___0 = sp->fts_path;
    p->fts_path = tmp___0;

    return;
  }
}
__attribute__((__nothrow__)) int(__attribute__((__warn_unused_result__,
                                                __leaf__)) fts_close)(FTS *sp);
int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp) {

  int saved_errno;

  int *tmp___5;

  {
    saved_errno = 0;

    free((void *)sp->fts_path);

    if (saved_errno) {

      *tmp___5 = saved_errno;
    }
  }
}

__attribute__((__nothrow__))
FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp);
FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp) {
  FTSENT *p;
  FTSENT *tmp;
  unsigned short instr;
  char *t;
  int *tmp___0;
  int tmp___1;
  int *tmp___2;
  int tmp___3;
  struct _ftsent *tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int *tmp___10;
  int tmp___11;
  size_t tmp___12;
  char *tmp___13;
  FTSENT *parent;
  _Bool tmp___14;
  int *tmp___15;
  _Bool tmp___16;
  int *tmp___17;
  struct _ftsent *tmp___18;
  int *tmp___19;
  int tmp___20;
  int tmp___21;
  int tmp___22;
  int tmp___23;
  int tmp___24;

  int *tmp___25;
  int *tmp___26;
  int *tmp___27;
  int tmp___28;

  int *tmp___30;
  int tmp___31;
  FTSENT *tmp___32;

  {
    if ((unsigned long)sp->fts_cur == (unsigned long)((void *)0)) {
      return ((FTSENT *)((void *)0));
    } else {
      if (sp->fts_options & 8192) {
      }
    }
    p = sp->fts_cur;

    p->fts_instr = (unsigned short)3;

    if ((int)instr == 2) {
      if ((int)p->fts_info == 12) {
        goto _L;
      } else {
        if ((int)p->fts_info == 13) {
        _L:

          goto check_for_dir;
        }
      }
    }
    if ((int)p->fts_info == 1) {

      if ((unsigned long)sp->fts_child != (unsigned long)((void *)0)) {
        tmp___3 = fts_safe_changedir(sp, p, -1, (char const *)p->fts_accpath);
        if (tmp___3) {

          p = sp->fts_child;
          while (1) {

            p->fts_accpath = (p->fts_parent)->fts_accpath;
          }

          ;
        }
      } else {
        tmp___4 = fts_build(sp, 3);
        sp->fts_child = tmp___4;
        if ((unsigned long)tmp___4 == (unsigned long)((void *)0)) {

          while (1) {
            leave_dir(sp, p);
          }

          ;
          return (p);
        }
      }
      p = sp->fts_child;
      sp->fts_child = (struct _ftsent *)((void *)0);
      goto name;
    }
  next:
    tmp = p;
    p = p->fts_link;
    if ((unsigned long)p != (unsigned long)((void *)0)) {
      sp->fts_cur = p;

      if (p->fts_level == 0L) {

        if (!(sp->fts_options & 4)) {
          if (sp->fts_options & 512) {
            if (sp->fts_options & 512) {
              tmp___5 = -100;
            } else {
            }
            cwd_advance_fd(sp, tmp___5, (_Bool)1);
            tmp___8 = 0;
          } else {
            if (sp->fts_options & 512) {

            } else {
              tmp___6 = sp->fts_rfd;
            }
            tmp___7 = fchdir(tmp___6);
            tmp___8 = tmp___7;
          }

        } else {
          tmp___9 = 0;
        }

        free_dir(sp);

        goto check_for_dir;
      }

    name:
      if ((int)*((p->fts_parent)->fts_path +
                 ((p->fts_parent)->fts_pathlen - 1UL)) == 47) {
        tmp___12 = (p->fts_parent)->fts_pathlen - 1UL;
      } else {
        tmp___12 = (p->fts_parent)->fts_pathlen;
      }
      t = sp->fts_path + tmp___12;
      tmp___13 = t;
      t++;
      *tmp___13 = (char)'/';
      memmove((void *)t, (void const *)(p->fts_name), p->fts_namelen + 1UL);
    check_for_dir:
      sp->fts_cur = p;
      if ((int)p->fts_info == 11) {
        if (p->fts_statp[0].st_size == 2L) {
          parent = p->fts_parent;
          if (0L < p->fts_level) {

          } else {
          _L___4:
            p->fts_info = fts_stat(sp, p, (_Bool)0);
            if ((p->fts_statp[0].st_mode & 61440U) == 16384U) {
            }
          }
        } else {

          ;
        }
      }
      if ((int)p->fts_info == 1) {

        tmp___16 = enter_dir(sp, p);
        if (!tmp___16) {

          return ((FTSENT *)((void *)0));
        }
      }
      return (p);
    }
    p = tmp->fts_parent;
    sp->fts_cur = p;

    if (p->fts_level == -1L) {

      tmp___18 = (struct _ftsent *)((void *)0);
      sp->fts_cur = tmp___18;
    }

    *(sp->fts_path + p->fts_pathlen) = (char)'\000';

    if (p->fts_errno) {
      p->fts_info = (unsigned short)7;
    } else {
      p->fts_info = (unsigned short)6;
    }

    if (sp->fts_options & 8192) {

    } else {
      tmp___32 = p;
    }
    return (tmp___32);
  }
}

static void set_stat_type(struct stat *st, unsigned int dtype) {
  mode_t type;

  {
    if (dtype == 6U) {
      goto case_6;
    }

    if (dtype == 1U) {
    }
    if (dtype == 10U) {
      goto case_10;
    }

    goto switch_default;
  case_6:
    type = (mode_t)24576;
    goto switch_break;
  case_2:
    type = (mode_t)8192;
    goto switch_break;
  case_4:
    type = (mode_t)16384;

  case_1:
    type = (mode_t)4096;
    goto switch_break;
  case_10:

  case_8:
    type = (mode_t)32768;

  case_12:
    type = (mode_t)49152;

  switch_default:
    type = (mode_t)0;
  switch_break:
    st->st_mode = type;
  }
}
static FTSENT *fts_build(FTS *sp, int type) {
  struct dirent *dp;
  FTSENT *p;
  FTSENT *head;
  size_t nitems;
  FTSENT *cur;
  FTSENT *tail;
  DIR *dirp;
  void *oldaddr;

  _Bool descend;
  _Bool doadjust;
  ptrdiff_t level;
  nlink_t nlinks;
  _Bool nostat;
  size_t len;
  size_t maxlen;
  size_t new_len;
  char *cp;

  DIR *tmp___0;
  DIR *tmp___1;

  _Bool tmp___3;

  int dir_fd;
  int tmp___5;
  int *tmp___6;
  int tmp___7;

  _Bool is_dir;
  size_t tmp___9;

  _Bool tmp___13;
  size_t tmp___14;

  _Bool skip_stat;
  int tmp___17;
  int tmp___18;
  int tmp___19;

  {
    cur = sp->fts_cur;
    if (!(sp->fts_options & 4)) {
      if (sp->fts_options & 512) {
        tmp___0 = opendirat(sp->fts_cwd_fd, (char const *)cur->fts_accpath);
        dirp = tmp___0;
      } else {
        tmp___1 = opendir_safer((char const *)cur->fts_accpath);
        dirp = tmp___1;
      }
    } else {
      tmp___1 = opendir_safer((char const *)cur->fts_accpath);
      dirp = tmp___1;
    }

    if (nlinks) {

    } else {
      if (type == 3) {
      _L___0:
        tmp___5 = dirfd(dirp);
        dir_fd = tmp___5;

        if (dir_fd < 0) {
          goto _L;
        } else {
          tmp___7 =
              fts_safe_changedir(sp, cur, dir_fd, (char const *)((void *)0));
          if (tmp___7) {
          _L:
            if (nlinks) {
              if (type == 3) {
              }
            }
            cur->fts_flags = (unsigned short)((int)cur->fts_flags | 1);
            descend = (_Bool)0;
            closedir(dirp);

          } else {
            descend = (_Bool)1;
          }
        }
      } else {
        descend = (_Bool)0;
      }
    }

    if (sp->fts_options & 4) {
      cp = sp->fts_path + len;

      cp++;

    } else {
    }
    len++;
    maxlen = sp->fts_pathlen - len;
    level = cur->fts_level + 1L;
    doadjust = (_Bool)0;
    tail = (FTSENT *)((void *)0);
    head = tail;
    nitems = (size_t)0;
    while (1) {

      if (dirp) {
        dp = readdir(dirp);
        if (!dp) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      if (!(sp->fts_options & 32)) {
        if ((int)dp->d_name[0] == 46) {
          if (!dp->d_name[1]) {
            goto __Cont;
          } else {
            if ((int)dp->d_name[1] == 46) {
              if (!dp->d_name[2]) {
                goto __Cont;
              }
            }
          }
        }
      }
      tmp___9 = strlen((char const *)(dp->d_name));
      p = fts_alloc(sp, (char const *)(dp->d_name), tmp___9);
      if ((unsigned long)p == (unsigned long)((void *)0)) {
      }
      tmp___14 = strlen((char const *)(dp->d_name));
      if (tmp___14 >= maxlen) {

        if (!tmp___13) {
        mem1:

          closedir(dirp);
          cur->fts_info = (unsigned short)7;

          return ((FTSENT *)((void *)0));
        }
        if ((unsigned long)oldaddr != (unsigned long)sp->fts_path) {
        }
      }

      p->fts_parent = sp->fts_cur;
      p->fts_pathlen = new_len;
      p->fts_statp[0].st_ino = dp->d_ino;
      if (sp->fts_options & 4) {

        memmove((void *)cp, (void const *)(p->fts_name), p->fts_namelen + 1UL);
      } else {
        p->fts_accpath = p->fts_name;
      }
      if ((unsigned long)sp->fts_compar == (unsigned long)((void *)0) ||
          sp->fts_options & 1024) {
        if (sp->fts_options & 16) {

        } else {
          tmp___17 = 0;
        }
        skip_stat = (_Bool)tmp___17;
        p->fts_info = (unsigned short)11;
        set_stat_type(p->fts_statp, (unsigned int)dp->d_type);
        fts_set_stat_required(p, (_Bool)(!skip_stat));
        if (sp->fts_options & 16) {
          if ((int)dp->d_type == 4) {

          } else {
          }
        } else {
          tmp___18 = 0;
        }
        is_dir = (_Bool)tmp___18;
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);
        if ((int)p->fts_info == 1) {

        } else {
          if ((int)p->fts_info == 2) {

          } else {
            if ((int)p->fts_info == 5) {

            } else {
              tmp___19 = 0;
            }
          }
        }
        is_dir = (_Bool)tmp___19;
      }

      p->fts_link = (struct _ftsent *)((void *)0);
      if ((unsigned long)head == (unsigned long)((void *)0)) {
        tail = p;
        head = tail;
      } else {
        tail->fts_link = p;
      }
      nitems++;
    __Cont:;
    }
  while_break___0:;
    if (dirp) {
      closedir(dirp);
    }

    if (descend) {
    }
    if (!nitems) {
      if (type == 3) {
      }

      return ((FTSENT *)((void *)0));
    }

    return (head);
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;
  int saved_errno;

  int tmp___3;
  int *tmp___4;
  int tmp___5;
  int tmp___6;

  {
    sbp = p->fts_statp;

    if (sp->fts_options & 2) {
      goto _L;
    } else {
      if (follow) {
      _L:
        tmp___3 = stat((char const *)p->fts_accpath, sbp);
        if (tmp___3) {

          p->fts_errno = saved_errno;
          goto err;
        }
      } else {
        tmp___5 =
            fstatat(sp->fts_cwd_fd, (char const *)p->fts_accpath, sbp, 256);
        if (tmp___5) {

          p->fts_errno = *tmp___4;
        err:
          memset((void *)sbp, 0, sizeof(struct stat));
        }
      }
    }
    if ((sbp->st_mode & 61440U) == 16384U) {

      p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;

      return ((unsigned short)1);
    }
    if ((sbp->st_mode & 61440U) == 40960U) {
    }
    if ((sbp->st_mode & 61440U) == 32768U) {
      return ((unsigned short)8);
    }
  }
}

static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems) {
  FTSENT **ap;
  FTSENT *p;

  int (*compare)(void const *, void const *);
  int (*tmp)(void const *, void const *);
  FTSENT **a;

  {

    compare = tmp;
    if (nitems > sp->fts_nitems) {
      sp->fts_nitems = nitems + 40UL;
      if (0xffffffffffffffffUL / sizeof(*a) < sp->fts_nitems) {

        sp->fts_array = (struct _ftsent **)((void *)0);
        sp->fts_nitems = (size_t)0;
        return (head);
      } else {
        a = (FTSENT **)realloc((void *)sp->fts_array,
                               sp->fts_nitems * sizeof(*a));
        if (!a) {

          sp->fts_nitems = (size_t)0;
          return (head);
        }
      }
    }

    p = head;

  while_break___0:
    (*(ap + 0))->fts_link = (struct _ftsent *)((void *)0);
  }
}
static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen) {
  FTSENT *p;
  size_t len;

  {
    len = sizeof(FTSENT) + namelen;
    p = (FTSENT *)malloc(len);
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      return ((FTSENT *)((void *)0));
    }
    memmove((void *)(p->fts_name), (void const *)name, namelen);

    p->fts_namelen = namelen;
    p->fts_fts = sp;
    p->fts_path = sp->fts_path;

    return (p);
  }
}
static void fts_lfree(FTSENT *head) {

  { ; }
}
static _Bool fts_palloc(FTS *sp, size_t more) {
  char *p;
  size_t new_len;

  {

    if (new_len < sp->fts_pathlen) {

      sp->fts_path = (char *)((void *)0);

      return ((_Bool)0);
    }

    p = (char *)realloc((void *)sp->fts_path, sp->fts_pathlen);
    if ((unsigned long)p == (unsigned long)((void *)0)) {

      sp->fts_path = (char *)((void *)0);
      return ((_Bool)0);
    }
    sp->fts_path = p;
    return ((_Bool)1);
  }
}
static void fts_padjust(FTS *sp, FTSENT *head) {
  FTSENT *p;
  char *addr;

  {

    p = sp->fts_child;
    while (1) {

      while (1) {

        if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
          p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
        }
        p->fts_path = addr;
      }

      p = p->fts_link;
    }

    p = head;
    while (1) {

      while (1) {

        if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
          p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
        }
        p->fts_path = addr;
      }

      ;
    }
  while_break___1:;
    return;
  }
}
static size_t fts_maxarglen(char *const *argv) {

  { ; }
}
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir) {
  int ret;
  _Bool is_dotdot;

  int tmp___0;
  int newfd;

  struct stat sb;
  int tmp___2;
  int *tmp___3;
  int tmp___4;
  int oerrno;
  int *tmp___5;
  int *tmp___6;

  {

    is_dotdot = (_Bool)tmp___0;
    if (sp->fts_options & 4) {

      return (0);
    }

    newfd = fd;

    if (sp->fts_options & 2) {
      goto _L;
    } else {
      if (dir) {

        if (tmp___4 == 0) {
        _L:
          tmp___2 = fstat(newfd, &sb);
          if (tmp___2) {
            ret = -1;
            goto bail;
          }
        }
      }
    }

    ret = fchdir(newfd);
  bail:
    if (fd < 0) {
      tmp___5 = __errno_location();
      oerrno = *tmp___5;
      close(newfd);
      tmp___6 = __errno_location();
      *tmp___6 = oerrno;
    }
    return (ret);
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2),
                                                       __leaf__)) fchownat)(
    int __fd, char const *__file, __uid_t __owner, __gid_t __group, int __flag);
__inline static int chownat(int fd, char const *file, uid_t owner,
                            gid_t group) {
  int tmp;

  {
    tmp = fchownat(fd, file, owner, group, 0);
    return (tmp);
  }
}
__inline static int lchownat(int fd, char const *file, uid_t owner,
                             gid_t group) {
  int tmp;

  { return (tmp); }
}

extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid,
                         uid_t required_uid, gid_t required_gid,
                         struct Chown_option const *chopt);

extern char *gid_to_name(gid_t gid) {

  char *tmp___2;
  char *tmp___3;

  {

    tmp___3 = xstrdup((char const *)tmp___2);
    return (tmp___3);
  }
}

static void describe_change(char const *file, enum Change_status changed,
                            char const *user, char const *group) {
  char const *fmt;
  char const *spec;
  char *spec_allocated;

  char *tmp___8;

  char const *tmp___17;

  {
    spec_allocated = (char *)((void *)0);

    if (user) {
      if (group) {

        spec = (char const *)spec_allocated;
      } else {
        spec = user;
      }
    } else {
      spec = group;
    }
    if ((unsigned int)changed == 2U) {
    }

    if ((unsigned int)changed == 4U) {
      goto case_4;
    }

  case_2:
    if (user) {

    } else {
      if (group) {

      } else {
      }
      fmt = (char const *)tmp___8;
    }
    goto switch_break;
  case_3:

    goto switch_break;
  case_4:

    goto switch_break;
  switch_default:
    abort();
  switch_break:
    tmp___17 = quote(file);
    printf(fmt, tmp___17, spec);
    free((void *)spec_allocated);
    return;
  }
}
static enum RCH_status restricted_chown(int cwd_fd, char const *file,
                                        struct stat const *orig_st, uid_t uid,
                                        gid_t gid, uid_t required_uid,
                                        gid_t required_gid) {
  enum RCH_status status;
  struct stat st;
  int open_flags;
  int fd;

  int *tmp___2;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int saved_errno;
  int *tmp___7;
  int *tmp___8;

  {
    status = (enum RCH_status)2;
    open_flags = 2304;
    if (required_uid == 4294967295U) {
      if (required_gid == 4294967295U) {
        return ((enum RCH_status)5);
      }
    }

    fd = openat(cwd_fd, file, open_flags);
    if (!(0 <= fd)) {
      tmp___2 = __errno_location();
    }
    tmp___6 = fstat(fd, &st);
    if (tmp___6 != 0) {
      status = (enum RCH_status)6;
    } else {
      if (orig_st->st_ino == (__ino_t const)st.st_ino) {
        if (orig_st->st_dev == (__dev_t const)st.st_dev) {
          if (required_uid == 4294967295U) {
            goto _L___2;
          } else {
            if (required_uid == st.st_uid) {
            _L___2:
              if (required_gid == 4294967295U) {

              } else {
                if (required_gid == st.st_gid) {
                _L___1:
                  tmp___5 = fchown(fd, uid, gid);
                  if (tmp___5 == 0) {
                    tmp___4 = close(fd);

                    return (status);
                  } else {
                    status = (enum RCH_status)6;
                  }
                }
              }
            }
          }
        } else {
          status = (enum RCH_status)4;
        }
      } else {
        status = (enum RCH_status)4;
      }
    }
    tmp___7 = __errno_location();
    saved_errno = *tmp___7;
    close(fd);
    tmp___8 = __errno_location();
    *tmp___8 = saved_errno;
    return (status);
  }
}
static _Bool change_file_owner(FTS *fts, FTSENT *ent, uid_t uid, gid_t gid,
                               uid_t required_uid, gid_t required_gid,
                               struct Chown_option const *chopt) {
  char const *file_full_name;
  char const *file;
  struct stat const *file_stats;

  _Bool ok;
  _Bool do_chown;

  char const *tmp;
  char *tmp___0;
  char const *tmp___1;
  char const *tmp___2;
  char *tmp___3;
  int tmp___4;
  char *tmp___5;
  FTSENT *tmp___6;
  char const *tmp___7;

  char const *tmp___11;
  char *tmp___12;

  _Bool tmp___15;

  int tmp___20;

  int tmp___28;

  enum RCH_status err;
  enum RCH_status tmp___30;
  int tmp___31;

  {

    file = (char const *)ent->fts_accpath;
    ok = (_Bool)1;

    if ((int)ent->fts_info == 1) {
      goto case_1;
    }
    if ((int)ent->fts_info == 6) {
    }
    if ((int)ent->fts_info == 10) {
      goto case_10;
    }

    goto switch_default;
  case_1:

    goto switch_break;
  case_6:

    goto switch_break;
  case_10:
    if (ent->fts_level == 0L) {
    }

    ok = (_Bool)0;

  case_7:
    if (!chopt->force_silent) {
    }
    ok = (_Bool)0;

  case_4:
    if (!chopt->force_silent) {
      tmp___11 = quote(file_full_name);
      tmp___12 = gettext("cannot read directory %s");
    }
    ok = (_Bool)0;

  case_2:

    if (tmp___15) {

      ;
      return ((_Bool)0);
    }

  switch_default:
    goto switch_break;
  switch_break:;
    if (!ok) {
      do_chown = (_Bool)0;
      file_stats = (struct stat const *)((void *)0);
    } else {
      if (required_uid == 4294967295U) {
        if (required_gid == 4294967295U) {

        } else {
          goto _L___3;
        }
      } else {
      _L___3:
        file_stats = (struct stat const *)(ent->fts_statp);
        if (chopt->affect_symlink_referent) {
        }
        if (ok) {
          if (required_uid == 4294967295U) {

          } else {
            if (required_uid == (uid_t)file_stats->st_uid) {
            _L:
              if (required_gid == 4294967295U) {

              } else {
                if (required_gid == (gid_t)file_stats->st_gid) {

                } else {
                }
              }
            } else {
              tmp___20 = 0;
            }
          }
        } else {
          tmp___20 = 0;
        }
        do_chown = (_Bool)tmp___20;
      }
    }

    if (do_chown) {
      if (!chopt->affect_symlink_referent) {
        tmp___28 = lchownat(fts->fts_cwd_fd, file, uid, gid);

      } else {
        tmp___30 = restricted_chown(fts->fts_cwd_fd, file, file_stats, uid, gid,
                                    required_uid, required_gid);
        err = tmp___30;

        if ((unsigned int)err == 4U) {
          goto case_4___0;
        }
        if ((unsigned int)err == 3U) {
          goto case_4___0;
        }

      case_2___0:
        goto switch_break___0;
      case_5:
        tmp___31 = chownat(fts->fts_cwd_fd, file, uid, gid);

      case_6___0:
        ok = (_Bool)0;

      case_4___0:
        do_chown = (_Bool)0;
        ok = (_Bool)0;

      switch_break___0:;
      }
    }

    return (ok);
  }
}
extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid,
                         uid_t required_uid, gid_t required_gid,
                         struct Chown_option const *chopt) {
  _Bool ok;
  int stat_flags;
  int tmp;
  FTS *fts;
  FTS *tmp___0;
  FTSENT *ent;

  int *tmp___2;

  _Bool tmp___4;

  int tmp___7;

  {
    ok = (_Bool)1;
    if (required_uid != 4294967295U) {

    } else {
      if (required_gid != 4294967295U) {
        tmp = 0;
      } else {
        if (chopt->affect_symlink_referent) {

        } else {
        }
      }
    }
    stat_flags = tmp;
    tmp___0 = xfts_open((char *const *)files, bit_flags | stat_flags,
                        (int (*)(FTSENT const **, FTSENT const **))((void *)0));
    fts = tmp___0;
    while (1) {
      ent = fts_read(fts);
      if ((unsigned long)ent == (unsigned long)((void *)0)) {

        goto while_break;
      }
      tmp___4 = change_file_owner(fts, ent, uid, gid, required_uid,
                                  required_gid, chopt);
      ok = (_Bool)((int)ok & (int)tmp___4);
    }
  while_break:
    tmp___7 = fts_close(fts);
    if (tmp___7 != 0) {

      ok = (_Bool)0;
    }
    return (ok);
  }
}

static char *reference_file;
static struct option const long_options___1[14] = {
    {"recursive", 0, (int *)((void *)0), 'R'},
    {"changes", 0, (int *)((void *)0), 'c'},
    {"dereference", 0, (int *)((void *)0), 128},
    {"from", 1, (int *)((void *)0), 129},
    {"no-dereference", 0, (int *)((void *)0), 'h'},
    {"no-preserve-root", 0, (int *)((void *)0), 130},
    {"preserve-root", 0, (int *)((void *)0), 131},
    {"quiet", 0, (int *)((void *)0), 'f'},
    {"silent", 0, (int *)((void *)0), 'f'},
    {"reference", 1, (int *)((void *)0), 132},
    {"verbose", 0, (int *)((void *)0), 'v'},
    {"help", 0, (int *)((void *)0), -130},
    {"version", 0, (int *)((void *)0), -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};

static struct dev_ino dev_ino_buf;
int main(int argc, char **argv) {
  _Bool preserve_root;
  uid_t uid;
  gid_t gid;
  uid_t required_uid;
  gid_t required_gid;
  int bit_flags;
  int dereference;
  struct Chown_option chopt;
  _Bool ok;
  int optc;

  int tmp___5;
  struct stat ref_stats;

  int tmp___9;
  char const *e___0;
  char const *tmp___10;

  int tmp___15;

  {

    uid = (uid_t)-1;
    gid = (gid_t)-1;
    required_uid = (uid_t)-1;

    bit_flags = 16;

    while (1) {
      optc = getopt_long(argc, (char *const *)argv, "HLPRcfhv",
                         long_options___1, (int *)((void *)0));
      if (!(optc != -1)) {
        goto while_break;
      }

      if (optc == 128) {
        goto case_128;
      }
      if (optc == 130) {
        goto case_130;
      }
      if (optc == 131) {
        goto case_131;
      }
      if (optc == 132) {
      }

      if (optc == 82) {
        goto case_82;
      }

      if (optc == 102) {
      }

      goto switch_default;
    case_72:

    case_76:

      goto switch_break;
    case_80:
      bit_flags = 16;

    case_104:

      goto switch_break;
    case_128:
      dereference = 1;
      goto switch_break;
    case_130:

      goto switch_break;
    case_131:

    case_132:

    case_129:

    case_82:
      chopt.recurse = (_Bool)1;

    case_99:

    case_102:

    case_118:

    case_neg_130:

    case_neg_131:

    switch_default:

    switch_break:;
    }
  while_break:;

    chopt.affect_symlink_referent = (_Bool)(dereference != 0);
    if (reference_file) {

    } else {
      tmp___5 = 2;
    }

    if (reference_file) {
      tmp___9 = stat((char const *)reference_file, &ref_stats);
      if (tmp___9) {
      }

      chopt.group_name = gid_to_name(ref_stats.st_gid);
    } else {
      tmp___10 = parse_user_spec((char const *)*(argv + optind), &uid, &gid,
                                 &chopt.user_name, &chopt.group_name);
      e___0 = tmp___10;

      optind++;
    }
    if (chopt.recurse) {
      if (preserve_root) {

        if ((unsigned long)chopt.root_dev_ino == (unsigned long)((void *)0)) {
        }
      }
    }

    ok = chown_files(argv + optind, bit_flags, uid, gid, required_uid,
                     required_gid, (struct Chown_option const *)(&chopt));

    if (ok) {

    } else {
      tmp___15 = 1;
    }
    exit(tmp___15);
  }
}
