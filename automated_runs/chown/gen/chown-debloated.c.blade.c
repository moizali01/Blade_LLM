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

typedef __gid_t gid_t;
typedef __uid_t uid_t;
typedef unsigned long uintmax_t;
struct dev_ino {};

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
struct I_ring {};
typedef struct I_ring I_ring;
struct _ftsent;
struct _ftsent;

struct __anonstruct_FTS_28 {
  struct _ftsent *fts_cur;
  struct _ftsent *fts_child;

  char *fts_path;

  int fts_cwd_fd;
  size_t fts_pathlen;

  int (*fts_compar)(struct _ftsent const **, struct _ftsent const **);
  int fts_options;

  I_ring fts_fd_ring;
};
typedef struct __anonstruct_FTS_28 FTS;
struct _ftsent {

  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;

  char *fts_accpath;
  char *fts_path;
  int fts_errno;

  size_t fts_pathlen;

  ptrdiff_t fts_level;
  size_t fts_namelen;
  nlink_t fts_n_dirs_remaining;
  unsigned short fts_info;

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

struct slotvec {};

struct hash_table {};

struct Active_dir {
  dev_t dev;

  FTSENT *fts_ent;
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
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));

extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) gettext)(
    char const *__msgid) __attribute__((__format_arg__(1)));

extern DIR *fdopendir(int __fd);
DIR *rpl_fdopendir(int fd);

DIR *rpl_fdopendir(int fd) {
  struct stat st;

  DIR *tmp___1;

  {

    tmp___1 = fdopendir(fd);
    return (tmp___1);
  }
}

int fd_safer(int fd) {

  { return (fd); }
}

int dup_safer(int fd) {
  int tmp;

  { return (tmp); }
}

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);

int close_stream(FILE *stream) {

  int tmp___1;
  int *tmp___2;

  {

    tmp___1 = fclose(stream);

    return (0);
  }
}

extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes);
extern __attribute__((__nothrow__)) unsigned long(__attribute__((
    __nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr,
                                        char **__restrict __endptr, int __base);

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;

  int *tmp___4;

  {

    if (ptr) {

    } else {
      p = &t_ptr;
    }
    q = s;
    ch = (unsigned char)*q;

  while_break:;

    tmp = strtoul(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {

      } else {
        return ((strtol_error)4);
      }
    } else {
      tmp___4 = __errno_location();
    }

    *val = tmp;
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

  { tmp = gettext("memory exhausted"); }
}

char const *parse_user_spec(char const *spec, uid_t *uid, gid_t *gid,
                            char **username, char **groupname);

extern struct passwd *getpwnam(char const *__name);

extern struct group *getgrnam(char const *__name);

static char const *parse_with_separator(char const *spec, char const *separator,
                                        uid_t *uid, gid_t *gid, char **username,
                                        char **groupname);
static char const *E_invalid_user = "invalid user";
static char const *E_invalid_group = "invalid group";

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
  char *tmp;
  size_t ulen;
  struct passwd *tmp___0;
  _Bool use_login_group;
  int tmp___1;

  strtol_error tmp___3;

  char *tmp___4;

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

    } else {
      if ((int const) * (separator + 1) == 0) {
        g = (char const *)((void *)0);
      } else {
        g = separator + 1;
      }
    }
    if ((unsigned long)u != (unsigned long)((void *)0)) {
      if ((int)*u == 43) {

      } else {
        tmp___0 = getpwnam((char const *)u);
        pwd = tmp___0;
      }
      if ((unsigned long)pwd == (unsigned long)((void *)0)) {

        use_login_group = (_Bool)tmp___1;
        if (use_login_group) {

        } else {

          if ((unsigned int)tmp___3 == 0U) {

          } else {
            error_msg = E_invalid_user;
          }
        }
      } else {
        unum = pwd->pw_uid;
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
  char *p;

  {

    ;
    return (p);
  }
}

static size_t
quotearg_buffer_restyled(char *buffer, size_t buffersize, char const *arg,
                         size_t argsize, enum quoting_style quoting_style,
                         int flags, unsigned int const *quote_these_too,
                         char const *left_quote, char const *right_quote) {

  size_t len;

  _Bool elide_outer_quotes;

  size_t m;

  size_t tmp___7;

  {
    len = (size_t)0;

    if (!elide_outer_quotes) {

      ;
    }

  case_2:

      ;

    if (1UL < m) {

    } else {
    }

    ;

    ;

    ;

    ;

    if (len < buffersize) {
      *(buffer + len) = (char)'\000';
    }

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

  unsigned int n0;
  struct slotvec *sv;
  size_t n1;

  struct slotvec *tmp___1;
  size_t size;
  char *val;

  size_t qsize;
  size_t tmp___2;

  {

    sv = slotvec;

    if (nslots <= n0) {

      if (sizeof(ptrdiff_t) <= sizeof(size_t)) {

      } else {
      }

      sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
      slotvec = sv;
    }

    if (size <= qsize) {
    }

    return (val);
  }
}

char *quotearg_char(char const *arg, char ch) {
  char *tmp;

  { return (tmp); }
}
char *quotearg_colon(char const *arg) {
  char *tmp;

  { return (tmp); }
}

DIR *opendir_safer(char const *name) {

  DIR *tmp;

  { tmp = opendir(name); }
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

  {}
}

extern int optind;

int i_ring_push(I_ring *ir, int val) {

  {}
}

static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen);
static FTSENT *fts_build(FTS *sp, int type);

static _Bool fts_palloc(FTS *sp, size_t more);

static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow);
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir);

static _Bool enter_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;
  struct Active_dir *ad;
  struct Active_dir *tmp;
  struct Active_dir *ad_from_table;
  _Bool tmp___0;

  {
    if (fts->fts_options & 258) {

      if (!ad) {
        return ((_Bool)0);
      }
      ad->dev = (dev_t)st->st_dev;

    } else {

      if (tmp___0) {

        ent->fts_info = (unsigned short)2;
      }
    }
    return ((_Bool)1);
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

  {
    tmp = openat_safer(fd, dir, 67840);
    new_fd = tmp;
    if (new_fd < 0) {
    }

    dirp = rpl_fdopendir(new_fd);

    return (dirp);
  }
}
static void cwd_advance_fd(FTS *sp, int fd, _Bool chdir_down_one) {
  int old;
  int prev_fd_in_slot;
  int tmp;

  {

    ;
    if (chdir_down_one) {
      tmp = i_ring_push(&sp->fts_fd_ring, old);
      prev_fd_in_slot = tmp;

    } else {
    }
    sp->fts_cwd_fd = fd;
  }
}
__inline static int diropen(FTS const *sp, char const *dir) {
  int open_flags;
  int tmp;
  int fd;

  int tmp___2;

  {

    open_flags = 67840 | tmp;

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
  size_t tmp___4;
  size_t tmp___5;
  _Bool tmp___6;
  int tmp___7;
  size_t len;
  size_t tmp___8;
  struct _ftsent *tmp___9;

  {
    parent = (FTSENT *)((void *)0);

    sp = (FTS *)malloc(sizeof(FTS));

    memset((void *)sp, 0, sizeof(FTS));

    sp->fts_options = options;

    tmp___6 = fts_palloc(sp, tmp___5);

    if ((unsigned long)*argv != (unsigned long)((void *)0)) {

      if ((unsigned long)parent == (unsigned long)((void *)0)) {
      }
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

      p->fts_accpath = p->fts_name;
      if (defer_stat) {
        if ((unsigned long)root != (unsigned long)((void *)0)) {
          p->fts_info = (unsigned short)11;
          fts_set_stat_required(p, (_Bool)1);
        } else {
        }
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);
      }
      if (compar) {

      } else {

        if ((unsigned long)root == (unsigned long)((void *)0)) {
          root = p;
          tmp = root;
        } else {
          tmp->fts_link = p;
          tmp = p;
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

  mem2:

    free((void *)sp);
  }
}
static void fts_load(FTS *sp, FTSENT *p) {
  size_t len;

  size_t tmp;
  char *tmp___0;

  {
    tmp = p->fts_namelen;

    len = tmp;
    memmove((void *)sp->fts_path, (void const *)(p->fts_name), len + 1UL);

    p->fts_path = tmp___0;

    return;
  }
}

int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp) {

  {

    free((void *)sp);

    return (0);
  }
}

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
        return ((FTSENT *)((void *)0));
      }
    }
    p = sp->fts_cur;

    if ((int)p->fts_info == 1) {

      if ((unsigned long)sp->fts_child != (unsigned long)((void *)0)) {
        tmp___3 = fts_safe_changedir(sp, p, -1, (char const *)p->fts_accpath);

      } else {
        tmp___4 = fts_build(sp, 3);
        sp->fts_child = tmp___4;
      }
      p = sp->fts_child;

      goto name;
    }

    tmp = p;
    p = p->fts_link;
    if ((unsigned long)p != (unsigned long)((void *)0)) {

      free((void *)tmp);
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

            tmp___7 = fchdir(tmp___6);
            tmp___8 = tmp___7;
          }

        } else {
          tmp___9 = 0;
        }

        fts_load(sp, p);

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
          }
        } else {

          ;
        }
      }
      if ((int)p->fts_info == 1) {

        tmp___16 = enter_dir(sp, p);
      }
      return (p);
    }
    p = tmp->fts_parent;
    sp->fts_cur = p;

    if (p->fts_level == -1L) {

      tmp___18 = (struct _ftsent *)((void *)0);
      sp->fts_cur = tmp___18;
    }

    if (p->fts_errno) {

    } else {
      p->fts_info = (unsigned short)6;
    }

    if (sp->fts_options & 8192) {

    } else {
    }
    return (tmp___32);
  }
}

static void set_stat_type(struct stat *st, unsigned int dtype) {
  mode_t type;

  { st->st_mode = type; }
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
  int *tmp;
  DIR *tmp___0;
  DIR *tmp___1;
  int *tmp___2;
  _Bool tmp___3;

  int dir_fd;
  int tmp___5;
  int *tmp___6;
  int tmp___7;
  char *tmp___8;
  _Bool is_dir;
  size_t tmp___9;
  int *tmp___10;
  int *tmp___11;
  size_t tmp___12;
  _Bool tmp___13;
  size_t tmp___14;
  size_t tmp___15;

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

        dirp = tmp___1;
      }
    } else {
      tmp___1 = opendir_safer((char const *)cur->fts_accpath);
      dirp = tmp___1;
    }
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      if (type == 3) {
        cur->fts_info = (unsigned short)4;
      }
      return ((FTSENT *)((void *)0));
    }
    if ((int)cur->fts_info == 11) {

    } else {
    }

    if (nlinks) {
      goto _L___0;
    } else {
      if (type == 3) {
      _L___0:
        tmp___5 = dirfd(dirp);
        dir_fd = tmp___5;

        if (dir_fd < 0) {

        } else {
          tmp___7 =
              fts_safe_changedir(sp, cur, dir_fd, (char const *)((void *)0));
        }
      } else {
        descend = (_Bool)0;
      }
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

        tmp___12 = strlen((char const *)(dp->d_name));
        tmp___13 = fts_palloc(sp, (tmp___12 + len) + 1UL);
        if (!tmp___13) {
        mem1:
          tmp___10 = __errno_location();
        }
      }

      p->fts_parent = sp->fts_cur;

      p->fts_statp[0].st_ino = dp->d_ino;
      if (sp->fts_options & 4) {
        p->fts_accpath = p->fts_path;
        memmove((void *)cp, (void const *)(p->fts_name), p->fts_namelen + 1UL);
      } else {
        p->fts_accpath = p->fts_name;
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

      p->fts_link = (struct _ftsent *)((void *)0);
      if ((unsigned long)head == (unsigned long)((void *)0)) {
        tail = p;
        head = tail;
      } else {
        tail->fts_link = p;
        tail = p;
      }
      nitems++;
    __Cont:;
    }
  while_break___0:;

    return (head);
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;

  int tmp___3;

  int tmp___5;
  int tmp___6;

  {
    sbp = p->fts_statp;

    if (sp->fts_options & 2) {

    } else {
      if (follow) {

        tmp___3 = stat((char const *)p->fts_accpath, sbp);

      } else {
        tmp___5 =
            fstatat(sp->fts_cwd_fd, (char const *)p->fts_accpath, sbp, 256);
      }
    }
    if ((sbp->st_mode & 61440U) == 16384U) {

      p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;

      return ((unsigned short)1);
    }
  }
}

static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems) {
  FTSENT **ap;

  int (*compare)(void const *, void const *);
  int (*tmp)(void const *, void const *);

  {

    compare = tmp;

    (*(ap + 0))->fts_link = (struct _ftsent *)((void *)0);
    return (head);
  }
}
static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen) {
  FTSENT *p;
  size_t len;

  {
    len = sizeof(FTSENT) + namelen;
    p = (FTSENT *)malloc(len);

    memmove((void *)(p->fts_name), (void const *)name, namelen);
    p->fts_name[namelen] = (char)'\000';
    p->fts_namelen = namelen;

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
static void fts_padjust(FTS *sp, FTSENT *head) {
  FTSENT *p;
  char *addr;

  {

    p = sp->fts_child;

    if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
      p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
    }
    p->fts_path = addr;

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
  int tmp;
  int tmp___0;
  int newfd;

  {
    if (dir) {

      if (tmp == 0) {

      } else {
      }
    } else {
      tmp___0 = 0;
    }
    is_dotdot = (_Bool)tmp___0;
    if (sp->fts_options & 4) {

      return (0);
    }

    newfd = fd;
    if (fd < 0) {
    }

    if (sp->fts_options & 512) {
      cwd_advance_fd(sp, newfd, (_Bool)(!is_dotdot));
    }

  bail:

    return (ret);
  }
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
extern char *uid_to_name(uid_t uid) {

  struct passwd *tmp;

  char *tmp___2;
  char *tmp___3;

  {
    tmp = getpwuid(uid);

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

  char *tmp___12;

  char const *tmp___17;

  {

    if ((unsigned int)changed == 2U) {
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
    if (user) {

    } else {

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

  int tmp___4;
  int tmp___5;
  int tmp___6;
  int saved_errno;
  int *tmp___7;
  int *tmp___8;

  {
    status = (enum RCH_status)2;
    open_flags = 2304;

    fd = openat(cwd_fd, file, open_flags);

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
  struct stat stat_buf;
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
  char *tmp___8;
  char const *tmp___9;
  char *tmp___10;
  char const *tmp___11;
  char *tmp___12;
  char const *tmp___13;
  char *tmp___14;
  _Bool tmp___15;
  char const *tmp___16;
  char *tmp___17;

  int tmp___20;

  enum RCH_status tmp___30;

  enum Change_status ch_status;

  {

    file = (char const *)ent->fts_accpath;
    ok = (_Bool)1;

    goto switch_break;
  case_6:

    ok = (_Bool)0;

    ok = (_Bool)0;

  switch_break:;
    if (!ok) {
      do_chown = (_Bool)0;

    } else {
      if (required_uid == 4294967295U) {
        if (required_gid == 4294967295U) {
          if ((unsigned int const)chopt->verbosity == 2U) {

          } else {
            goto _L___3;
          }
        } else {
          goto _L___3;
        }
      } else {
      _L___3:
        file_stats = (struct stat const *)(ent->fts_statp);

        do_chown = (_Bool)tmp___20;
      }
    }
    if (ok) {
      if ((int)ent->fts_info == 1) {

      } else {
        if ((int)ent->fts_info == 2) {

        } else {
        }
      }
    }
    if (do_chown) {
      if (!chopt->affect_symlink_referent) {

      } else {
        tmp___30 = restricted_chown(fts->fts_cwd_fd, file, file_stats, uid, gid,
                                    required_uid, required_gid);

        ok = (_Bool)0;

        do_chown = (_Bool)0;
        ok = (_Bool)0;

        ;
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

  _Bool tmp___4;

  {
    ok = (_Bool)1;
    if (required_uid != 4294967295U) {
      tmp = 0;
    } else {
      if (required_gid != 4294967295U) {
        tmp = 0;
      } else {
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
    }
  while_break:

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

void usage(int status) {

  { exit(status); }
}
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
  char *u_dummy;
  char *g_dummy;
  char const *e;
  char const *tmp;
  char const *tmp___0;

  char const *tmp___3;
  char *tmp___4;
  int tmp___5;

  char const *tmp___6;
  char *tmp___7;
  int *tmp___8;
  int tmp___9;
  char const *e___0;
  char const *tmp___10;
  char const *tmp___11;

  int tmp___15;

  {

    required_uid = (uid_t)-1;

    bit_flags = 16;

    optc = getopt_long(argc, (char *const *)argv, "HLPRcfhv", long_options___1,
                       (int *)((void *)0));
    if (!(optc != -1)) {
    }

    goto switch_break;

    goto switch_break;

  case_82:

    goto switch_break;

    chopt.verbosity = (enum Verbosity)0;

  switch_break:;

  while_break:;

    chopt.affect_symlink_referent = (_Bool)(dereference != 0);
    if (reference_file) {

    } else {
      tmp___5 = 2;
    }
    if (argc - optind < tmp___5) {
      if (argc <= optind) {

      } else {

        tmp___4 = gettext("missing operand after %s");
        error(0, 0, (char const *)tmp___4, tmp___3);
      }
      usage(1);
    }
    if (reference_file) {

    } else {
      tmp___10 = parse_user_spec((char const *)*(argv + optind), &uid, &gid,
                                 &chopt.user_name, &chopt.group_name);
      e___0 = tmp___10;
      if (e___0) {

        error(1, 0, "%s: %s", e___0, tmp___11);
      }
    }

    ok = chown_files(argv + optind, bit_flags, uid, gid, required_uid,
                     required_gid, (struct Chown_option const *)(&chopt));

    if (ok) {
      tmp___15 = 0;
    } else {
    }
    exit(tmp___15);
  }
}
