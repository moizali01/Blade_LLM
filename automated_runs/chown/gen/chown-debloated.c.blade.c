
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

typedef struct hash_tuning Hash_tuning;

typedef __gid_t gid_t;
typedef __uid_t uid_t;
typedef unsigned long uintmax_t;
struct dev_ino {};

typedef long ptrdiff_t;
struct dirent {

  unsigned char d_type;
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
typedef long intmax_t;

struct _ftsent;

struct __anonstruct_FTS_28 {
  struct _ftsent *fts_cur;

  char *fts_path;

  int fts_cwd_fd;
  size_t fts_pathlen;

  int (*fts_compar)(struct _ftsent const **, struct _ftsent const **);
  int fts_options;
};
typedef struct __anonstruct_FTS_28 FTS;
struct _ftsent {
  struct _ftsent *fts_cycle;
  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;

  char *fts_accpath;
  char *fts_path;

  size_t fts_pathlen;
  FTS *fts_fts;
  ptrdiff_t fts_level;
  size_t fts_namelen;

  unsigned short fts_info;

  struct stat fts_statp[1];
  char fts_name[1];
};
typedef struct _ftsent FTSENT;
struct passwd {
  char *pw_name;
  char *pw_passwd;
  __uid_t pw_uid;
  __gid_t pw_gid;
};
struct group {
  char *gr_name;
  char *gr_passwd;
  __gid_t gr_gid;
};

struct slotvec {

  char *val;
};

enum Change_status {
  CH_NOT_APPLIED = 1,
  CH_SUCCEEDED = 2,
  CH_FAILED = 3,
  CH_NO_CHANGE_REQUESTED = 4
};
enum Verbosity { V_high = 0, V_changes_only = 1, V_off = 2 };
struct Chown_option {
  enum Verbosity verbosity;
  _Bool recurse;
  struct dev_ino *root_dev_ino;
  _Bool affect_symlink_referent;

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

Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(
    size_t candidate, Hash_tuning const *tuning,
    size_t (*hasher)(void const *, size_t),
    _Bool (*comparator)(void const *, void const *),
    void (*data_freer)(void *));

int dup_safer(int fd) {
  int tmp;

  { return (tmp); }
}

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchown)(
    int __fd, __uid_t __owner, __gid_t __group);

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

static char const *file_name;

int close_stream(FILE *stream) {

  int *tmp___2;

  {}
}

DIR *opendir_safer(char const *name);

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {

  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;

  {
    err = (strtol_error)0;

    q = s;
    ch = (unsigned char)*q;

    ;

    if (!valid_suffixes) {

      return (err);
    }

    return (err);
  }
}

void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    tmp = malloc(n);
    p = tmp;
    if (!p) {
      if (n != 0UL) {
      }
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
               int (*compar)(FTSENT const **, FTSENT const **)) {
  FTS *fts;
  FTS *tmp;

  {
    tmp = fts_open(argv, options | 512, compar);
    fts = tmp;

    return (fts);
  }
}

void xalloc_die(void) {
  char *tmp;

  {}
}

char const *parse_user_spec(char const *spec, uid_t *uid, gid_t *gid,
                            char **username, char **groupname);

extern struct passwd *getpwnam(char const *__name);

extern struct group *getgrgid(__gid_t __gid);
extern struct group *getgrnam(char const *__name);

static char const *parse_with_separator(char const *spec, char const *separator,
                                        uid_t *uid, gid_t *gid, char **username,
                                        char **groupname);
static char const *E_invalid_user = "invalid user";
static char const *E_invalid_group = "invalid group";
static char const *E_bad_spec = "invalid spec";
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
  char buf___1[(((sizeof(uintmax_t) * 8UL) * 146UL) / 485UL + 1UL) + 1UL];
  char *tmp___4;
  char *tmp___5;
  struct group *tmp___6;
  unsigned long tmp___7;
  strtol_error tmp___8;
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
        if ((unsigned long)separator != (unsigned long)((void *)0)) {
          if ((unsigned long)g == (unsigned long)((void *)0)) {

          } else {
          }
        } else {
          tmp___1 = 0;
        }
        use_login_group = (_Bool)tmp___1;
        if (use_login_group) {
          error_msg = E_bad_spec;
        } else {
          tmp___3 =
              xstrtoul((char const *)u, (char **)((void *)0), 10, &tmp___2, "");
          if ((unsigned int)tmp___3 == 0U) {
            if (tmp___2 <= 4294967295UL) {
              if ((uid_t)tmp___2 != 4294967295U) {
                unum = (uid_t)tmp___2;
              } else {
                error_msg = E_invalid_user;
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
          if ((unsigned long)separator != (unsigned long)((void *)0)) {
            gnum = pwd->pw_gid;
            grp = getgrgid(gnum);
            if (grp) {
              tmp___5 = grp->gr_name;
            } else {

              tmp___5 = tmp___4;
            }
            gname = xstrdup((char const *)tmp___5);
            endgrent();
          }
        }
      }
      endpwent();
    }
    if ((unsigned long)g != (unsigned long)((void *)0)) {
      if ((unsigned long)error_msg == (unsigned long)((void *)0)) {
        if ((int const) * g == 43) {
          grp = (struct group *)((void *)0);
        } else {
          tmp___6 = getgrnam(g);
          grp = tmp___6;
        }
        if ((unsigned long)grp == (unsigned long)((void *)0)) {
          tmp___8 = xstrtoul(g, (char **)((void *)0), 10, &tmp___7, "");
          if ((unsigned int)tmp___8 == 0U) {
            if (tmp___7 <= 4294967295UL) {
              if ((gid_t)tmp___7 != 4294967295U) {
                gnum = (gid_t)tmp___7;
              } else {
                error_msg = E_invalid_group;
              }
            } else {
              error_msg = E_invalid_group;
            }
          } else {
            error_msg = E_invalid_group;
          }
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

  {
    tmp = (char const *)strchr(spec, ':');
    colon = tmp;
    tmp___0 = parse_with_separator(spec, colon, uid, gid, username, groupname);
    error_msg = tmp___0;

    return (error_msg);
  }
}
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1) {

  { ; }
}

static size_t
quotearg_buffer_restyled(char *buffer, size_t buffersize, char const *arg,
                         size_t argsize, enum quoting_style quoting_style,
                         int flags, unsigned int const *quote_these_too,
                         char const *left_quote, char const *right_quote) {

  size_t len;

  size_t tmp___7;

  {
    len = (size_t)0;

    if ((unsigned int)quoting_style == 6U) {
      goto case_6;
    }

    if ((unsigned int)quoting_style == 8U) {
    }

  case_4:

  case_3:

  case_5:

    goto switch_break;
  case_6:

  case_1:

  case_2:

    goto switch_break;
  case_0:

    goto switch_break;

  switch_break:

      ;
    if (len == 0UL) {
    }

    if (len < buffersize) {
      *(buffer + len) = (char)'\000';
    }
    return (len);

    tmp___7 = quotearg_buffer_restyled(
        buffer, buffersize, arg, argsize, quoting_style, flags & -3,
        (unsigned int const *)((void *)0), left_quote, right_quote);
  }
}

static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options) {
  int e;
  int *tmp;
  unsigned int n0;
  struct slotvec *sv;
  size_t n1;

  size_t size;
  char *val;

  size_t qsize;
  size_t tmp___2;

  {

    e = *tmp;
    n0 = (unsigned int)n;

    if (n < 0) {
    }

    val = (sv + n)->val;

    qsize = tmp___2;

    return (val);
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

  { tmp = quote_n(0, name); }
}

DIR *opendir_safer(char const *name) {
  DIR *dp;
  DIR *tmp;
  int fd;

  {
    tmp = opendir(name);
    dp = tmp;

    return (dp);
  }
}

int openat_safer(int fd, char const *file, int flags, ...) {

  int tmp___0;

  { return (tmp___0); }
}

extern int optind;

static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen);

static _Bool fts_palloc(FTS *sp, size_t more);

static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow);
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir);

__inline static DIR *opendirat(int fd, char const *dir) {
  int new_fd;

  DIR *dirp;

  {

    if (new_fd < 0) {
    }

    dirp = rpl_fdopendir(new_fd);

    return (dirp);
  }
}
static void cwd_advance_fd(FTS *sp, int fd, _Bool chdir_down_one) {

  {

    ;

    sp->fts_cwd_fd = fd;
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

  _Bool defer_stat;
  int *tmp___0;

  int *tmp___2;

  size_t tmp___5;
  _Bool tmp___6;
  int tmp___7;
  size_t len;
  size_t tmp___8;
  struct _ftsent *tmp___9;

  {

    if (!(options & 18)) {
      tmp___2 = __errno_location();
      *tmp___2 = 22;
    }
    sp = (FTS *)malloc(sizeof(FTS));
    if ((unsigned long)sp == (unsigned long)((void *)0)) {
      return ((FTS *)((void *)0));
    }
    memset((void *)sp, 0, sizeof(FTS));

    sp->fts_cwd_fd = -100;

    tmp___6 = fts_palloc(sp, tmp___5);

    if ((unsigned long)*argv != (unsigned long)((void *)0)) {
      parent = fts_alloc(sp, "", (size_t)0);
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

      p->fts_parent = parent;
      p->fts_accpath = p->fts_name;
      if (defer_stat) {
        if ((unsigned long)root != (unsigned long)((void *)0)) {

        } else {
          p->fts_info = fts_stat(sp, p, (_Bool)0);
        }
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);
      }
      if (compar) {

      } else {

        if ((unsigned long)root == (unsigned long)((void *)0)) {
          root = p;

        } else {
        }
      }
      argv++;
      nitems++;
    }
  while_break:;

    tmp___9 = fts_alloc(sp, "", (size_t)0);
    sp->fts_cur = tmp___9;

    (sp->fts_cur)->fts_link = root;

    return (sp);

    free((void *)sp);
  }
}
static void fts_load(FTS *sp, FTSENT *p) {
  size_t len;

  size_t tmp;

  {
    tmp = p->fts_namelen;
    p->fts_pathlen = tmp;
    len = tmp;
    memmove((void *)sp->fts_path, (void const *)(p->fts_name), len + 1UL);

    return;
  }
}

int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp) {
  FTSENT *freep;

  int *tmp___1;

  {}
}

FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp) {
  FTSENT *p;
  FTSENT *tmp;
  unsigned short instr;
  char *t;
  int *tmp___0;

  int tmp___9;

  size_t tmp___12;
  char *tmp___13;

  struct _ftsent *tmp___18;

  FTSENT *tmp___32;

  {

    p = sp->fts_cur;

    tmp = p;
    p = p->fts_link;
    if ((unsigned long)p != (unsigned long)((void *)0)) {

      if (p->fts_level == 0L) {

        if (!(sp->fts_options & 4)) {

        } else {
          tmp___9 = 0;
        }

        fts_load(sp, p);

        goto check_for_dir;
      }

    name:

      t = sp->fts_path + tmp___12;
      tmp___13 = t;
      t++;
      *tmp___13 = (char)'/';
      memmove((void *)t, (void const *)(p->fts_name), p->fts_namelen + 1UL);
    check_for_dir:
      sp->fts_cur = p;

      return (p);
    }
    p = tmp->fts_parent;
    sp->fts_cur = p;

    *(sp->fts_path + p->fts_pathlen) = (char)'\000';

    return (tmp___32);
  }
}

int(__attribute__((__leaf__)) fts_set)(FTS *sp __attribute__((__unused__)),
                                       FTSENT *p, int instr) {
  int *tmp;

  {}
}

static FTSENT *fts_build(FTS *sp, int type) {
  struct dirent *dp;
  FTSENT *p;
  FTSENT *head;
  size_t nitems;
  FTSENT *cur;
  FTSENT *tail;
  DIR *dirp;

  int saved_errno;

  _Bool doadjust;
  ptrdiff_t level;

  size_t len;
  size_t maxlen;
  size_t new_len;

  DIR *tmp___0;

  int *tmp___6;

  _Bool is_dir;

  size_t tmp___14;
  size_t tmp___15;

  _Bool skip_stat;
  int tmp___17;
  int tmp___18;
  int tmp___19;

  {

    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
    }
    if ((int)cur->fts_info == 11) {
      cur->fts_info = fts_stat(sp, cur, (_Bool)0);
    } else {
    }

    if ((int)*(cur->fts_path + (cur->fts_pathlen - 1UL)) == 47) {
      len = cur->fts_pathlen - 1UL;
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

        if (!dp) {
          goto while_break___0;
        }
      } else {
      }

      if (tmp___14 >= maxlen) {
      }

      new_len = len + tmp___15;

      p->fts_parent = sp->fts_cur;
      p->fts_pathlen = new_len;

      if (sp->fts_options & 4) {

      } else {
      }
      if ((unsigned long)sp->fts_compar == (unsigned long)((void *)0) ||
          sp->fts_options & 1024) {

        skip_stat = (_Bool)tmp___17;
        p->fts_info = (unsigned short)11;
        set_stat_type(p->fts_statp, (unsigned int)dp->d_type);
        fts_set_stat_required(p, (_Bool)(!skip_stat));

        is_dir = (_Bool)tmp___18;
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);

        is_dir = (_Bool)tmp___19;
      }

      nitems++;
    __Cont:;
    }
  while_break___0:;
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;

  int *tmp;
  int *tmp___0;

  int tmp___3;

  int tmp___5;

  {
    sbp = p->fts_statp;

    if (sp->fts_options & 2) {

    } else {
      if (follow) {

        tmp___3 = stat((char const *)p->fts_accpath, sbp);

      } else {
        tmp___5 =
            fstatat(sp->fts_cwd_fd, (char const *)p->fts_accpath, sbp, 256);
        if (tmp___5) {

        err:
          memset((void *)sbp, 0, sizeof(struct stat));
        }
      }
    }
  }
}

static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems) {
  FTSENT **ap;

  int (*compare)(void const *, void const *);
  int (*tmp)(void const *, void const *);

  {

    compare = tmp;

  while_break:

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
    }
    memmove((void *)(p->fts_name), (void const *)name, namelen);

    p->fts_namelen = namelen;
    p->fts_fts = sp;

    return (p);
  }
}
static void fts_lfree(FTSENT *head) {

  { ; }
}
static _Bool fts_palloc(FTS *sp, size_t more) {
  char *p;

  {

    p = (char *)realloc((void *)sp->fts_path, sp->fts_pathlen);

    sp->fts_path = p;
    return ((_Bool)1);
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

  int *tmp___5;
  int *tmp___6;

  {

    is_dotdot = (_Bool)tmp___0;

    newfd = fd;
    if (fd < 0) {
      newfd = diropen((FTS const *)sp, dir);
      if (newfd < 0) {
        return (-1);
      }
    }
    if (sp->fts_options & 2) {

    } else {
    }

  bail:

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

  {
    tmp = fchownat(fd, file, owner, group, 256);
    return (tmp);
  }
}

extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid,
                         uid_t required_uid, gid_t required_gid,
                         struct Chown_option const *chopt);

extern void chopt_init(struct Chown_option *chopt) {

  {

    return;
  }
}

extern char *gid_to_name(gid_t gid) {
  char
      buf___1[((((sizeof(intmax_t) * 8UL - 1UL) * 146UL) / 485UL + 1UL) + 1UL) +
              1UL];
  struct group *grp;
  struct group *tmp;

  char *tmp___2;
  char *tmp___3;

  {

    grp = tmp;
    if (grp) {
      tmp___2 = grp->gr_name;
    } else {
    }
    tmp___3 = xstrdup((char const *)tmp___2);
    return (tmp___3);
  }
}
extern char *uid_to_name(uid_t uid) {
  char
      buf___1[((((sizeof(intmax_t) * 8UL - 1UL) * 146UL) / 485UL + 1UL) + 1UL) +
              1UL];
  struct passwd *pwd;
  struct passwd *tmp;

  char *tmp___2;
  char *tmp___3;

  {
    tmp = getpwuid(uid);
    pwd = tmp;
    if (pwd) {
      tmp___2 = pwd->pw_name;
    } else {
    }
    tmp___3 = xstrdup((char const *)tmp___2);
    return (tmp___3);
  }
}
static void describe_change(char const *file, enum Change_status changed,
                            char const *user, char const *group) {
  char const *fmt;
  char const *spec;
  char *spec_allocated;

  size_t tmp___1;
  size_t tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;

  char *tmp___8;
  char *tmp___9;
  char *tmp___10;
  char *tmp___11;
  char *tmp___12;

  char const *tmp___17;

  {

    if (user) {
      if (group) {
        tmp___1 = strlen(user);
        tmp___2 = strlen(group);
        spec_allocated = (char *)xmalloc(((tmp___1 + 1UL) + tmp___2) + 1UL);
        tmp___3 = stpcpy(spec_allocated, user);
        tmp___4 = stpcpy(tmp___3, ":");
        stpcpy(tmp___4, group);
        spec = (char const *)spec_allocated;
      } else {
      }
    } else {
      spec = group;
    }
    if ((unsigned int)changed == 2U) {
      goto case_2;
    }
    if ((unsigned int)changed == 3U) {
      goto case_3;
    }
    if ((unsigned int)changed == 4U) {
      goto case_4;
    }

  case_2:
    if (user) {

      fmt = (char const *)tmp___5;
    } else {
      if (group) {

        tmp___8 = tmp___6;
      } else {
      }
      fmt = (char const *)tmp___8;
    }
    goto switch_break;
  case_3:
    if (user) {
      tmp___9 = gettext("failed to change ownership of %s to %s\n");
      fmt = (char const *)tmp___9;
    } else {
      if (group) {
        tmp___10 = gettext("failed to change group of %s to %s\n");
        tmp___12 = tmp___10;
      } else {
        tmp___11 = gettext("failed to change ownership of %s\n");
      }
      fmt = (char const *)tmp___12;
    }
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
                goto _L___1;
              } else {
                if (required_gid == st.st_gid) {
                _L___1:
                  tmp___5 = fchown(fd, uid, gid);
                  if (tmp___5 == 0) {
                    tmp___4 = close(fd);
                    if (tmp___4 == 0) {
                      status = (enum RCH_status)2;
                    } else {
                      status = (enum RCH_status)6;
                    }
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
  struct stat stat_buf;
  _Bool ok;
  _Bool do_chown;
  _Bool symlink_changed;

  int tmp___20;

  int tmp___28;
  int *tmp___29;
  enum RCH_status err;
  enum RCH_status tmp___30;
  int tmp___31;

  enum Change_status ch_status;

  {
    file_full_name = (char const *)ent->fts_path;
    file = (char const *)ent->fts_accpath;
    ok = (_Bool)1;
    symlink_changed = (_Bool)1;
    if ((int)ent->fts_info == 1) {
      goto case_1;
    }
    if ((int)ent->fts_info == 6) {
      goto case_6;
    }
    if ((int)ent->fts_info == 10) {
      goto case_10;
    }

    if ((int)ent->fts_info == 2) {
      goto case_2;
    }
    goto switch_default;
  case_1:

    goto switch_break;
  case_6:
    if (!chopt->recurse) {
      return ((_Bool)1);
    }

  case_10:

    ok = (_Bool)0;
    goto switch_break;
  case_7:

    ok = (_Bool)0;

  case_4:

    ok = (_Bool)0;
    goto switch_break;
  case_2:

    goto switch_break;
  switch_default:

  switch_break:;
    if (!ok) {
      do_chown = (_Bool)0;

    } else {
      if (required_uid == 4294967295U) {
        if (required_gid == 4294967295U) {
          if ((unsigned int const)chopt->verbosity == 2U) {
            if (!chopt->root_dev_ino) {

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
        file_stats = (struct stat const *)(ent->fts_statp);

        if (ok) {
          if (required_uid == 4294967295U) {
            goto _L;
          } else {
            if (required_uid == (uid_t)file_stats->st_uid) {
            _L:
              if (required_gid == 4294967295U) {
                tmp___20 = 1;
              } else {
                if (required_gid == (gid_t)file_stats->st_gid) {
                  tmp___20 = 1;
                } else {
                  tmp___20 = 0;
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
    if (ok) {
      if ((int)ent->fts_info == 1) {
        goto _L___4;
      } else {
        if ((int)ent->fts_info == 2) {
          goto _L___4;
        } else {
          if ((int)ent->fts_info == 6) {

          } else {
            if ((int)ent->fts_info == 4) {
            _L___4:
              if (chopt->root_dev_ino) {

              while_break___1:;
                return ((_Bool)0);
              }
            }
          }
        }
      }
    }
    if (do_chown) {
      if (!chopt->affect_symlink_referent) {
        tmp___28 = lchownat(fts->fts_cwd_fd, file, uid, gid);
        ok = (_Bool)(tmp___28 == 0);
        if (!ok) {
          tmp___29 = __errno_location();
        }
      } else {
        tmp___30 = restricted_chown(fts->fts_cwd_fd, file, file_stats, uid, gid,
                                    required_uid, required_gid);
        err = tmp___30;
        if ((unsigned int)err == 2U) {
        }

        if ((unsigned int)err == 3U) {
          goto case_4___0;
        }
        goto switch_default___0;
      case_2___0:
        goto switch_break___0;
      case_5:
        tmp___31 = chownat(fts->fts_cwd_fd, file, uid, gid);
        ok = (_Bool)(tmp___31 == 0);

      case_6___0:
        ok = (_Bool)0;
        goto switch_break___0;
      case_4___0:
        do_chown = (_Bool)0;

      switch_default___0:

      switch_break___0:;
      }
    }

    if (!chopt->recurse) {
      fts_set(fts, ent, 4);
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
  char *tmp___5;
  int *tmp___6;
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
      tmp___5 = gettext("fts_close failed");

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

  char const *e;
  char const *tmp;

  struct stat ref_stats;
  char const *tmp___6;
  char *tmp___7;
  int *tmp___8;
  int tmp___9;
  char const *e___0;
  char const *tmp___10;
  char const *tmp___11;

  int tmp___15;

  {

    uid = (uid_t)-1;
    gid = (gid_t)-1;
    required_uid = (uid_t)-1;

    bit_flags = 16;

    chopt_init(&chopt);
    while (1) {
      optc = getopt_long(argc, (char *const *)argv, "HLPRcfhv",
                         long_options___1, (int *)((void *)0));
      if (!(optc != -1)) {
        goto while_break;
      }

      if (optc == 104) {
      }
      if (optc == 128) {
      }
      if (optc == 130) {
        goto case_130;
      }

      if (optc == 82) {
      }
      if (optc == 99) {
      }

      goto switch_default;
    case_72:

    case_76:
      bit_flags = 2;
      goto switch_break;
    case_80:
      bit_flags = 16;

    case_104:

    case_128:

    case_130:

    case_131:

      goto switch_break;
    case_132:

      goto switch_break;
    case_129:

      e = tmp;

    case_82:

      goto switch_break;
    case_99:

    case_102:

    case_118:

      goto switch_break;
    case_neg_130:

    case_neg_131:

      exit(0);
      goto switch_break;
    switch_default:

    switch_break:;
    }
  while_break:;

    chopt.affect_symlink_referent = (_Bool)(dereference != 0);
    if (reference_file) {

    } else {
    }

    if (reference_file) {
      tmp___9 = stat((char const *)reference_file, &ref_stats);
      if (tmp___9) {
        tmp___6 = quote((char const *)reference_file);
        tmp___7 = gettext("failed to get attributes of %s");
        tmp___8 = __errno_location();
        error(1, *tmp___8, (char const *)tmp___7, tmp___6);
      }
      uid = ref_stats.st_uid;
      gid = ref_stats.st_gid;

    } else {
      tmp___10 = parse_user_spec((char const *)*(argv + optind), &uid, &gid,
                                 &chopt.user_name, &chopt.group_name);
      e___0 = tmp___10;
      if (e___0) {

        error(1, 0, "%s: %s", e___0, tmp___11);
      }

      optind++;
    }

    bit_flags |= 1024;
    ok = chown_files(argv + optind, bit_flags, uid, gid, required_uid,
                     required_gid, (struct Chown_option const *)(&chopt));

    if (ok) {
      tmp___15 = 0;
    } else {
      tmp___15 = 1;
    }
    exit(tmp___15);
  }
}
