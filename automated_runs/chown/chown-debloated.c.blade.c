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

struct __anonstruct_FTS_28 {
  struct _ftsent *fts_cur;

  char *fts_path;

  int fts_cwd_fd;
  size_t fts_pathlen;

  int fts_options;
};
typedef struct __anonstruct_FTS_28 FTS;
struct _ftsent {
  struct _ftsent *fts_cycle;
  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;

  char *fts_accpath;

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
};
struct group {
  char *gr_name;
  char *gr_passwd;
  __gid_t gr_gid;
};

enum Change_status {
  CH_NOT_APPLIED = 1,
  CH_SUCCEEDED = 2,
  CH_FAILED = 3,
  CH_NO_CHANGE_REQUESTED = 4
};

struct Chown_option {

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

extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag, ...);

DIR *rpl_fdopendir(int fd) {

  {}
}

int volatile exit_failure;

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchown)(
    int __fd, __uid_t __owner, __gid_t __group);

int close_stream(FILE *stream);

static char const *file_name;

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file,
                                         struct stat *__restrict __buf);

DIR *opendir_safer(char const *name);

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {

  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;

  strtol_error overflow;

  {

    q = s;
    ch = (unsigned char)*q;

    ;

    if (!valid_suffixes) {

      return (err);
    }
    if ((int)*(*p) != 0) {

    case_98:

    case_66___0:

      goto switch_break___0;
    case_99:

    case_69:

    case_71:

    case_107:

    case_77:

    case_80:

      goto switch_break___0;
    case_84:

      goto switch_break___0;
    case_119:

      goto switch_break___0;
    case_89:

    case_90:

      *val = tmp;

    switch_break___0:
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
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

  {}
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

__attribute__((__noreturn__)) void xalloc_die(void);
void xalloc_die(void) {
  char *tmp;

  { error((int)exit_failure, 0, "%s", tmp); }
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

  size_t ulen;
  struct passwd *tmp___0;
  _Bool use_login_group;
  int tmp___1;
  unsigned long tmp___2;
  strtol_error tmp___3;

  char *tmp___5;
  struct group *tmp___6;
  unsigned long tmp___7;
  strtol_error tmp___8;
  char const *tmp___9;

  {

    error_msg = (char const *)((void *)0);

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

        use_login_group = (_Bool)tmp___1;
        if (use_login_group) {

        } else {
          tmp___3 =
              xstrtoul((char const *)u, (char **)((void *)0), 10, &tmp___2, "");
          if ((unsigned int)tmp___3 == 0U) {
            if (tmp___2 <= 4294967295UL) {
              if ((uid_t)tmp___2 != 4294967295U) {

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
      *username = u;

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
  size_t i;
  size_t len;

  unsigned char c;

  size_t tmp___7;

  {
    len = (size_t)0;

  case_4:

  case_3:

  case_5:

  case_6:

  case_1:

  case_2:

  case_0:

    while (1) {

      if ((int)c == 54) {
      }
      if ((int)c == 55) {
      }

      if ((int)c == 70) {
        goto case_37;
      }

      if ((int)c == 88) {
      }

      if ((int)c == 105) {
      }

      if ((int)c == 116) {
      }

    case_0___0:

    case_63:

    case_2___0:

    case_3___0:

        ;
      goto switch_break___0;
    case_7___0:

    case_8___0:

    case_12:

    case_10:

    case_13:

    case_9:

    case_11:

    case_92:

    case_123:

    case_35:

    case_32:

    case_39___0:

    case_37:

    switch_break___0:;

      ;

      ;

      i++;
    }

    ;

    if (len < buffersize) {
    }

    tmp___7 = quotearg_buffer_restyled(
        buffer, buffersize, arg, argsize, quoting_style, flags & -3,
        (unsigned int const *)((void *)0), left_quote, right_quote);
  }
}

static char *quotearg_n_options(int n, char const *arg, size_t argsize,
                                struct quoting_options const *options) {

  int *tmp;

  char *val;

  size_t qsize;
  size_t tmp___2;

  { qsize = tmp___2; }
}

char *quotearg_colon(char const *arg) {

  {}
}

int openat_safer(int fd, char const *file, int flags, ...) {
  mode_t mode;

  int tmp;

  { tmp = openat(fd, file, flags, mode); }
}

extern int optind;

static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen);

static _Bool fts_palloc(FTS *sp, size_t more);

static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow);

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

  int *tmp___1;

  {

    if (new_fd < 0) {
      return ((DIR *)((void *)0));
    }
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

  size_t tmp___5;
  _Bool tmp___6;
  int tmp___7;
  size_t len;
  size_t tmp___8;

  {

    sp = (FTS *)malloc(sizeof(FTS));

    sp->fts_cwd_fd = -100;

    tmp___6 = fts_palloc(sp, tmp___5);

    if ((unsigned long)*argv != (unsigned long)((void *)0)) {
      parent = fts_alloc(sp, "", (size_t)0);

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
        }
      }
      argv++;
      nitems++;
    }
  while_break:;

    (sp->fts_cur)->fts_link = root;

    return (sp);
  mem3:

    free((void *)sp);
  }
}

int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp) {

  {}
}

FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp) {
  FTSENT *p;
  FTSENT *tmp;

  char *t;

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
      if ((int)p->fts_info == 11) {
        if (p->fts_statp[0].st_size == 2L) {

          if (0L < p->fts_level) {

          } else {
          _L___4:
            p->fts_info = fts_stat(sp, p, (_Bool)0);
          }
        } else {

          ;
        }
      }

      return (p);
    }
    p = tmp->fts_parent;
    sp->fts_cur = p;

    if (p->fts_level == -1L) {

      tmp___18 = (struct _ftsent *)((void *)0);

      return (tmp___18);
    }

    return (tmp___32);
  }
}
__attribute__((__nothrow__)) int(__attribute__((__leaf__)) fts_set)(
    FTS *sp __attribute__((__unused__)), FTSENT *p, int instr);

static FTSENT *fts_build(FTS *sp, int type) {

  FTSENT *head;
  size_t nitems;
  FTSENT *cur;
  FTSENT *tail;
  DIR *dirp;

  _Bool doadjust;
  ptrdiff_t level;

  size_t len;
  size_t maxlen;

  {

    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
    }

    len++;
    maxlen = sp->fts_pathlen - len;
    level = cur->fts_level + 1L;
    doadjust = (_Bool)0;
    tail = (FTSENT *)((void *)0);
    head = tail;
    nitems = (size_t)0;

  while_break___0:;
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;

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

    (*(ap + 0))->fts_link = (struct _ftsent *)((void *)0);
  }
}
static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen) {
  FTSENT *p;
  size_t len;

  {
    len = sizeof(FTSENT) + namelen;
    p = (FTSENT *)malloc(len);

    memmove((void *)(p->fts_name), (void const *)name, namelen);

    p->fts_namelen = namelen;

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

      return ((_Bool)0);
    }

    sp->fts_path = p;
    return ((_Bool)1);
  }
}

static size_t fts_maxarglen(char *const *argv) {

  { ; }
}
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir) {

  _Bool is_dotdot;

  int tmp___0;
  int newfd;

  {

    is_dotdot = (_Bool)tmp___0;

    if (fd < 0) {

      if (newfd < 0) {
        return (-1);
      }
    }

    if (fd < 0) {
    }
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

static void describe_change(char const *file, enum Change_status changed,
                            char const *user, char const *group) {
  char const *fmt;
  char const *spec;
  char *spec_allocated;

  char *tmp___8;

  char *tmp___12;

  char const *tmp___17;

  {

    goto switch_default;
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
      if (group) {

      } else {
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

  int *tmp___1;
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
    if (!((orig_st->st_mode & 61440U) == 32768U)) {
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

                  tmp___5 = fchown(fd, uid, gid);
                  if (tmp___5 == 0) {
                    tmp___4 = close(fd);
                    if (tmp___4 == 0) {

                    } else {
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

  _Bool ok;
  _Bool do_chown;

  int tmp___20;

  enum RCH_status err;
  enum RCH_status tmp___30;

  {

    file = (char const *)ent->fts_accpath;
    ok = (_Bool)1;

    if ((int)ent->fts_info == 10) {
    }

    goto switch_default;
  case_1:

    goto switch_break;
  case_6:

  case_10:

    ok = (_Bool)0;

  case_7:

    ok = (_Bool)0;

  case_4:

  case_2:

  switch_default:

  switch_break:;
    if (!ok) {

    } else {
      if (required_uid == 4294967295U) {
        if (required_gid == 4294967295U) {

        } else {
          goto _L___3;
        }
      } else {
      _L___3:
        file_stats = (struct stat const *)(ent->fts_statp);

        if (ok) {
          if (required_uid == 4294967295U) {

          } else {
            if (required_uid == (uid_t)file_stats->st_uid) {
            _L:
              if (required_gid == 4294967295U) {

              } else {
                if (required_gid == (gid_t)file_stats->st_gid) {
                  tmp___20 = 1;
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

      } else {
        tmp___30 = restricted_chown(fts->fts_cwd_fd, file, file_stats, uid, gid,
                                    required_uid, required_gid);
        err = tmp___30;

        if ((unsigned int)err == 5U) {
          goto case_5;
        }

      case_2___0:

      case_5:

      case_6___0:
        ok = (_Bool)0;

      case_4___0:
        do_chown = (_Bool)0;

      switch_default___0:

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

  int *tmp___2;

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

  int tmp___9;
  char const *e___0;
  char const *tmp___10;

  int tmp___15;

  {

    uid = (uid_t)-1;

    required_uid = (uid_t)-1;

    bit_flags = 16;

    while (1) {
      optc = getopt_long(argc, (char *const *)argv, "HLPRcfhv",
                         long_options___1, (int *)((void *)0));
      if (!(optc != -1)) {
        goto while_break;
      }

      if (optc == 130) {
      }

    case_72:

    case_76:

    case_80:
      bit_flags = 16;

    case_104:

      goto switch_break;
    case_128:

      goto switch_break;
    case_130:

    case_131:

    case_132:

    case_129:

    case_82:

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
    }

    if (reference_file) {

      if (tmp___9) {
      }

    } else {
      tmp___10 = parse_user_spec((char const *)*(argv + optind), &uid, &gid,
                                 &chopt.user_name, &chopt.group_name);
      e___0 = tmp___10;
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
