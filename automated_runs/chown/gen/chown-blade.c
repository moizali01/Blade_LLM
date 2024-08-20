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

struct option {};

typedef __nlink_t nlink_t;

struct __anonstruct_FTS_28 {
  struct _ftsent *fts_cur;
  struct _ftsent *fts_child;
  struct _ftsent **fts_array;
  dev_t fts_dev;
  char *fts_path;

  int fts_cwd_fd;
  size_t fts_pathlen;

  int (*fts_compar)(struct _ftsent const **, struct _ftsent const **);
  int fts_options;
};
typedef struct __anonstruct_FTS_28 FTS;
struct _ftsent {

  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;

  char *fts_accpath;
  char *fts_path;

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

struct Chown_option {

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

extern DIR *fdopendir(int __fd);

DIR *rpl_fdopendir(int fd) {

  DIR *tmp___1;

  {

    tmp___1 = fdopendir(fd);
    return (tmp___1);
  }
}

int fd_safer(int fd) {

  { return (fd); }
}

int close_stream(FILE *stream) {

  {}
}

extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);

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

  {}
}

extern struct passwd *getpwnam(char const *__name);

extern struct group *getgrnam(char const *__name);

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

  struct group *tmp___6;

  char const *tmp___9;

  {

    unum = *uid;
    gnum = *gid;

    u = (char *)((void *)0);
    if ((unsigned long)separator == (unsigned long)((void *)0)) {

      u = xstrdup(spec);

    } else {
      ulen = (size_t)(separator - spec);
      if (ulen != 0UL) {
        u = (char *)xmemdup((void const *)spec, ulen + 1UL);
        *(u + ulen) = (char)'\000';
      }
    }
    if ((unsigned long)separator == (unsigned long)((void *)0)) {

    } else {

      g = separator + 1;
    }
    if ((unsigned long)u != (unsigned long)((void *)0)) {

      tmp___0 = getpwnam((char const *)u);
      pwd = tmp___0;

      use_login_group = (_Bool)tmp___1;

      unum = pwd->pw_uid;

      endpwent();
    }
    if ((unsigned long)g != (unsigned long)((void *)0)) {

      tmp___6 = getgrnam(g);
      grp = tmp___6;

      gnum = grp->gr_gid;

      endgrent();
      gname = xstrdup(g);
    }

    *uid = unum;
    *gid = gnum;

    free((void *)u);
    tmp___9 = (char const *)gettext(error_msg);
    return (tmp___9);
  }
}
char const *parse_user_spec(char const *spec, uid_t *uid, gid_t *gid,
                            char **username, char **groupname) {
  char const *colon;
  char const *tmp;

  char const *tmp___0;

  {
    tmp = (char const *)strchr(spec, ':');
    colon = tmp;
    tmp___0 = parse_with_separator(spec, colon, uid, gid, username, groupname);
  }
}
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i,
                                                          char *buf___1) {

  { ; }
}

char *quotearg_colon(char const *arg) {

  {}
}

DIR *opendir_safer(char const *name) {

  {}
}

int openat_safer(int fd, char const *file, int flags, ...) {
  mode_t mode;

  int tmp;
  int tmp___0;

  {

    tmp = openat(fd, file, flags, mode);
    tmp___0 = fd_safer(tmp);
    return (tmp___0);
  }
}

extern int optind;

static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen);
static FTSENT *fts_build(FTS *sp, int type);

static _Bool fts_palloc(FTS *sp, size_t more);

static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow);
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir);

static _Bool enter_dir(FTS *fts, FTSENT *ent) {

  {}
}

static void fts_set_stat_required(FTSENT *p, _Bool required) {

  {

    ;

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
  FTSENT *tmp;
  _Bool defer_stat;
  int *tmp___0;

  size_t tmp___5;
  _Bool tmp___6;
  int tmp___7;
  size_t len;
  size_t tmp___8;
  struct _ftsent *tmp___9;

  {

    sp = (FTS *)malloc(sizeof(FTS));

    memset((void *)sp, 0, sizeof(FTS));

    sp->fts_cwd_fd = -100;

    tmp___6 = fts_palloc(sp, tmp___5);

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

      root = p;

      argv++;
      nitems++;
    }
  while_break:;

    tmp___9 = fts_alloc(sp, "", (size_t)0);
    sp->fts_cur = tmp___9;

    (sp->fts_cur)->fts_link = root;

    return (sp);
  mem3:

    free((void *)sp);
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

  size_t tmp___12;
  char *tmp___13;

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
    }
    p = sp->fts_cur;

    if ((int)p->fts_info == 1) {

      tmp___4 = fts_build(sp, 3);
      sp->fts_child = tmp___4;
      if ((unsigned long)tmp___4 == (unsigned long)((void *)0)) {

        ;
        return (p);
      }

      p = sp->fts_child;

      goto name;
    }

    p = p->fts_link;
    if ((unsigned long)p != (unsigned long)((void *)0)) {

    name:

      t = sp->fts_path + tmp___12;
      tmp___13 = t;
      t++;
      *tmp___13 = (char)'/';
      memmove((void *)t, (void const *)(p->fts_name), p->fts_namelen + 1UL);
    check_for_dir:
      sp->fts_cur = p;

      goto _L___4;

    _L___4:
      p->fts_info = fts_stat(sp, p, (_Bool)0);

      ;

      tmp___16 = enter_dir(sp, p);

      return (p);
    }

    tmp___18 = (struct _ftsent *)((void *)0);
    sp->fts_cur = tmp___18;

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

  _Bool descend;
  _Bool doadjust;
  ptrdiff_t level;

  size_t len;
  size_t maxlen;

  DIR *tmp___0;
  DIR *tmp___1;

  int dir_fd;
  int tmp___5;

  int tmp___7;

  _Bool is_dir;
  size_t tmp___9;

  _Bool skip_stat;
  int tmp___17;
  int tmp___18;
  int tmp___19;

  {
    cur = sp->fts_cur;
    if (!(sp->fts_options & 4)) {

      tmp___0 = opendirat(sp->fts_cwd_fd, (char const *)cur->fts_accpath);
      dirp = tmp___0;

    } else {
      tmp___1 = opendir_safer((char const *)cur->fts_accpath);
      dirp = tmp___1;
    }
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {

      cur->fts_info = (unsigned short)4;

      return ((FTSENT *)((void *)0));
    }

  _L___0:
    tmp___5 = dirfd(dirp);
    dir_fd = tmp___5;

    tmp___7 = fts_safe_changedir(sp, cur, dir_fd, (char const *)((void *)0));

    descend = (_Bool)0;

    len++;
    maxlen = sp->fts_pathlen - len;
    level = cur->fts_level + 1L;
    doadjust = (_Bool)0;
    tail = (FTSENT *)((void *)0);
    head = tail;
    nitems = (size_t)0;
    while (1) {

      dp = readdir(dirp);
      if (!dp) {
        goto while_break___0;
      }

      if ((int)dp->d_name[0] == 46) {

        goto __Cont;
      }

      tmp___9 = strlen((char const *)(dp->d_name));
      p = fts_alloc(sp, (char const *)(dp->d_name), tmp___9);

      p->fts_level = level;
      p->fts_parent = sp->fts_cur;

      p->fts_accpath = p->fts_name;

      if ((unsigned long)sp->fts_compar == (unsigned long)((void *)0) ||
          sp->fts_options & 1024) {

        tmp___17 = 0;

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

  int tmp___5;
  int tmp___6;

  {
    sbp = p->fts_statp;

    if (follow) {

      return ((unsigned short)13);

    } else {
      tmp___5 = fstatat(sp->fts_cwd_fd, (char const *)p->fts_accpath, sbp, 256);
    }

    p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;

    return ((unsigned short)1);
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
    p->fts_name[namelen] = (char)'\000';
    p->fts_namelen = namelen;

    p->fts_path = sp->fts_path;

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

  _Bool is_dotdot;

  int tmp___0;
  int newfd;

  {

    is_dotdot = (_Bool)tmp___0;

    newfd = fd;

    cwd_advance_fd(sp, newfd, (_Bool)(!is_dotdot));

    if (fd < 0) {
    }
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

  int tmp___5;
  int tmp___6;
  int saved_errno;
  int *tmp___7;
  int *tmp___8;

  {

    open_flags = 2304;

    fd = openat(cwd_fd, file, open_flags);

    tmp___6 = fstat(fd, &st);

  _L___2:

    tmp___5 = fchown(fd, uid, gid);

    status = (enum RCH_status)4;

    status = (enum RCH_status)4;

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

  int tmp___20;

  enum RCH_status tmp___30;

  {

    file = (char const *)ent->fts_accpath;

    goto switch_break;
  case_6:

  switch_break:;

  _L___3:
    file_stats = (struct stat const *)(ent->fts_statp);

    do_chown = (_Bool)tmp___20;

    if (do_chown) {

      tmp___30 = restricted_chown(fts->fts_cwd_fd, file, file_stats, uid, gid,
                                  required_uid, required_gid);

      ;
    }
  }
}
extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid,
                         uid_t required_uid, gid_t required_gid,
                         struct Chown_option const *chopt) {

  int stat_flags;
  int tmp;
  FTS *fts;
  FTS *tmp___0;
  FTSENT *ent;

  _Bool tmp___4;

  int tmp___7;

  {

    tmp = 0;

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
    tmp___7 = fts_close(fts);
  }
}

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

  uid_t uid;
  gid_t gid;
  uid_t required_uid;
  gid_t required_gid;
  int bit_flags;
  int dereference;
  struct Chown_option chopt;
  _Bool ok;
  int optc;

  char const *tmp___10;

  int tmp___15;

  {

    uid = (uid_t)-1;
    gid = (gid_t)-1;

    bit_flags = 16;

    optc = getopt_long(argc, (char *const *)argv, "HLPRcfhv", long_options___1,
                       (int *)((void *)0));

    ;

  while_break:;

    chopt.affect_symlink_referent = (_Bool)(dereference != 0);

    tmp___10 = parse_user_spec((char const *)*(argv + optind), &uid, &gid,
                               &chopt.user_name, &chopt.group_name);

    ok = chown_files(argv + optind, bit_flags, uid, gid, required_uid,
                     required_gid, (struct Chown_option const *)(&chopt));

    exit(tmp___15);
  }
}
