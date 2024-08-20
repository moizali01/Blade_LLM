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

struct mbchar {

  _Bool wc_valid;
};
struct mbuiter_multi {

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

union __anonunion_fts_cycle_29 {
  struct hash_table *ht;
  struct cycle_check_state *state;
};
struct __anonstruct_FTS_28 {
  struct _ftsent *fts_cur;
  struct _ftsent *fts_child;
  struct _ftsent **fts_array;
  dev_t fts_dev;
  char *fts_path;
  int fts_rfd;
  int fts_cwd_fd;
  size_t fts_pathlen;
  size_t fts_nitems;
  int (*fts_compar)(struct _ftsent const **, struct _ftsent const **);
  int fts_options;

  union __anonunion_fts_cycle_29 fts_cycle;
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
struct slotvec {};
struct hash_entry {
  void *data;
  struct hash_entry *next;
};
struct hash_table {
  struct hash_entry *bucket;
  struct hash_entry const *bucket_limit;
  size_t n_buckets;
  size_t n_buckets_used;
  size_t n_entries;

  size_t (*hasher)(void const *, size_t);
  _Bool (*comparator)(void const *, void const *);
};

struct Active_dir {
  dev_t dev;
  ino_t ino;
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

extern DIR *fdopendir(int __fd);
DIR *rpl_fdopendir(int fd);

DIR *rpl_fdopendir(int fd) {
  struct stat st;
  int tmp;
  int *tmp___0;
  DIR *tmp___1;

  {
    tmp = fstat(fd, &st);

    if (!((st.st_mode & 61440U) == 16384U)) {

      return ((DIR *)((void *)0));
    }
    tmp___1 = fdopendir(fd);
    return (tmp___1);
  }
}

int fd_safer(int fd) {

  { return (fd); }
}

extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));

__inline static void mbuiter_multi_next(struct mbuiter_multi *iter) {

  size_t tmp___0;

  _Bool tmp___3;

  {

    if (tmp___3) {

      iter->cur.wc_valid = (_Bool)1;
    } else {

      tmp___0 = __ctype_get_mb_cur_max();
    }
    iter->next_done = (_Bool)1;
  }
}

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

_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb);

_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb) {
  _Bool tmp;

  {

    (state->chdir_counter)++;

    if (tmp) {
      if (state->chdir_counter == 0UL) {
      }
      state->dev_ino.st_dev = (dev_t)sb->st_dev;
      state->dev_ino.st_ino = (ino_t)sb->st_ino;
    }
  }
}

int close_stream(FILE *stream);

int close_stream(FILE *stream) {

  int *tmp___2;

  {}
}

extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file,
                                         struct stat *__restrict __buf);

char *last_component(char const *name) {
  char const *base;

  _Bool saw_slash;

  {

    saw_slash = (_Bool)0;
    while (1) {

      if (!((int const) * base == 47)) {
        goto while_break;
      }
      base++;
    }
  while_break:

      ;
    return ((char *)base);
  }
}

extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;
  unsigned short const **tmp___0;
  int *tmp___1;
  char *tmp___2;
  int *tmp___3;
  int *tmp___4;
  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;

  {
    err = (strtol_error)0;

    if (ptr) {

    } else {
      p = &t_ptr;
    }
    q = s;
    ch = (unsigned char)*q;
    while (1) {
      tmp___0 = __ctype_b_loc();
      if (!((int const) * (*tmp___0 + (int)ch) & 8192)) {
        goto while_break;
      }
    }
  while_break:;

    tmp___1 = __errno_location();
    *tmp___1 = 0;
    tmp = strtoul(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {
        if (*(*p)) {
          tmp___2 = strchr(valid_suffixes, (int)*(*p));
          if (tmp___2) {
            tmp = 1UL;
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
      tmp___4 = __errno_location();
    }
    if (!valid_suffixes) {

      return (err);
    }
    if ((int)*(*p) != 0) {
      base = 1024;

      tmp___5 = strchr(valid_suffixes, (int)*(*p));

      if ((int)*(*p) == 109) {
      }

      if ((int)*(*p) == 89) {
      }
      if ((int)*(*p) == 90) {
      }
      goto switch_default;

      overflow = bkm_scale___0(&tmp, 512);
      goto switch_break___0;
    case_66___0:
      overflow = bkm_scale___0(&tmp, 1024);
      goto switch_break___0;

      goto switch_break___0;

      overflow = bkm_scale_by_power___0(&tmp, base, 6);
      goto switch_break___0;

      goto switch_break___0;

      overflow = bkm_scale_by_power___0(&tmp, base, 1);
      goto switch_break___0;
    case_77:

      goto switch_break___0;

      overflow = bkm_scale_by_power___0(&tmp, base, 5);
      goto switch_break___0;

      goto switch_break___0;

      goto switch_break___0;
    case_89:

      goto switch_break___0;
    case_90:

      goto switch_break___0;
    switch_default:
      *val = tmp;

    switch_break___0:

      *p += suffixes;
    }
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
          error_msg = E_bad_spec;
        } else {
          tmp___3 =
              xstrtoul((char const *)u, (char **)((void *)0), 10, &tmp___2, "");
          if ((unsigned int)tmp___3 == 0U) {

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
          tmp___8 = xstrtoul(g, (char **)((void *)0), 10, &tmp___7, "");

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
      u = (char *)((void *)0);
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
  char const *tmp___1;

  {
    tmp = (char const *)strchr(spec, ':');
    colon = tmp;
    tmp___0 = parse_with_separator(spec, colon, uid, gid, username, groupname);
    error_msg = tmp___0;

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
  int flags;
  size_t qsize;
  size_t tmp___2;

  {

    if (n < 0) {
    }
    if (nslots <= n0) {

      sv = (struct slotvec *)xrealloc((void *)tmp___1, n1 * sizeof(*sv));
      slotvec = sv;
    }

    tmp___2 = quotearg_buffer_restyled(
        val, size, arg, argsize, (enum quoting_style)options->style, flags,
        (unsigned int const *)(options->quote_these_too),
        (char const *)options->left_quote, (char const *)options->right_quote);

    if (size <= qsize) {
    }
  }
}

char *quotearg_colon(char const *arg) {
  char *tmp;

  { return (tmp); }
}

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) dirfd)(DIR *__dirp);
DIR *opendir_safer(char const *name) {
  DIR *dp;
  DIR *tmp;

  DIR *newdp;

  {
    tmp = opendir(name);
    dp = tmp;
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
int open_safer(char const *file, int flags, ...) {
  mode_t mode;

  int tmp;

  { tmp = open(file, flags, mode); }
}
int mbscasecmp(char const *s1, char const *s2) {
  mbui_iterator_t iter1;
  mbui_iterator_t iter2;

  int tmp___16;

  size_t tmp___25;

  {

    if (tmp___25 > 1UL) {

      mbuiter_multi_next(&iter1);

      if (iter2.cur.wc_valid) {

      } else {
        tmp___16 = 1;
      }

    } else {

      ;
    }
  }
}

extern int optind;

static size_t compute_bucket_size(size_t candidate, Hash_tuning const *tuning) {

  {}
}
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(
    size_t candidate, Hash_tuning const *tuning,
    size_t (*hasher)(void const *, size_t),
    _Bool (*comparator)(void const *, void const *),
    void (*data_freer)(void *)) {
  Hash_table *table___0;

  {

    table___0->n_buckets = compute_bucket_size(candidate, tuning);

    table___0->bucket = (struct hash_entry *)calloc(
        table___0->n_buckets, sizeof(*(table___0->bucket)));

    table___0->n_buckets_used = (size_t)0;

    free((void *)table___0);
  }
}

static void *hash_find_entry(Hash_table *table___0, void const *entry,
                             struct hash_entry **bucket_head, _Bool delete) {
  struct hash_entry *bucket;

  struct hash_entry *cursor;

  {

    if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
      abort();
    }

    cursor = bucket;
    while (1) {

      if ((unsigned long)entry == (unsigned long)(cursor->next)->data) {

      } else {
      }
    }

    ;
    return ((void *)0);
  }
}
static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {
  struct hash_entry *bucket;

  struct hash_entry *next;

  {

  while_break:;
    return ((_Bool)1);
  }
}

void *(__attribute__((__warn_unused_result__)) hash_insert)(
    Hash_table *table___0, void const *entry) {
  void *data;
  struct hash_entry *bucket;

  {

    data = hash_find_entry(table___0, entry, &bucket, (_Bool)0);

    (table___0->n_entries)++;
    (table___0->n_buckets_used)++;
  }
}

static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen);
static FTSENT *fts_build(FTS *sp, int type);
static void fts_lfree(FTSENT *head);

static _Bool fts_palloc(FTS *sp, size_t more);
static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems);
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow);
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir);
static _Bool AD_compare(void const *x, void const *y) {

  int tmp;

  { return ((_Bool)tmp); }
}
static size_t AD_hash(void const *x, size_t table_size) {
  struct Active_dir const *ax;

  {
    ax = (struct Active_dir const *)x;
  }
}
static _Bool setup_dir(FTS *fts) {

  {
    if (fts->fts_options & 258) {
      fts->fts_cycle.ht =
          hash_initialize((size_t)31, (Hash_tuning const *)((void *)0),
                          &AD_hash, &AD_compare, (void (*)(void *))(&free));
      if (!fts->fts_cycle.ht) {
      }
    } else {
      fts->fts_cycle.state =
          (struct cycle_check_state *)malloc(sizeof(*(fts->fts_cycle.state)));
    }
  }
}
static _Bool enter_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;
  struct Active_dir *ad;

  {
    if (fts->fts_options & 258) {
      st = (struct stat const *)(ent->fts_statp);

      ad->dev = (dev_t)st->st_dev;
      ad->ino = (ino_t)st->st_ino;

    } else {
    }
    return ((_Bool)1);
  }
}
static void leave_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;

  {
    st = (struct stat const *)(ent->fts_statp);
  }
}
static void free_dir(FTS *sp) {

  { return; }
}

static void fts_set_stat_required(FTSENT *p, _Bool required) {

  {

    ;
    if (required) {
      p->fts_statp[0].st_size = (__off_t)2;
    } else {
      p->fts_statp[0].st_size = (__off_t)1;
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
      tmp___2 = tmp___1;
    }
    fd = tmp___2;
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

    sp = (FTS *)malloc(sizeof(FTS));
    if ((unsigned long)sp == (unsigned long)((void *)0)) {
    }
    memset((void *)sp, 0, sizeof(FTS));
    sp->fts_compar = compar;
    sp->fts_options = options;

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
      p->fts_level = (ptrdiff_t)0;
      p->fts_parent = parent;
      p->fts_accpath = p->fts_name;
      if (defer_stat) {

      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);
      }
      if (compar) {

        root = p;
      } else {
        p->fts_link = (struct _ftsent *)((void *)0);
        if ((unsigned long)root == (unsigned long)((void *)0)) {
          root = p;
          tmp = root;
        } else {

          tmp = p;
        }
      }
      argv++;
      nitems++;
    }
  while_break:;

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

    free((void *)sp);
    return ((FTS *)((void *)0));
  }
}
static void fts_load(FTS *sp, FTSENT *p) {
  size_t len;

  size_t tmp;

  {

    len = tmp;
    memmove((void *)sp->fts_path, (void const *)(p->fts_name), len + 1UL);

    return;
  }
}

int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp) {

  FTSENT *p;

  {

    if (sp->fts_cur) {
      p = sp->fts_cur;

    while_break:
      free((void *)p);
    }
    if (sp->fts_child) {
      fts_lfree(sp->fts_child);
    }

    free_dir(sp);
    free((void *)sp);
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
    }
    p = sp->fts_cur;
    instr = p->fts_instr;
    p->fts_instr = (unsigned short)3;

    if ((int)p->fts_info == 1) {
      if ((int)instr == 4) {

      } else {
        if (sp->fts_options & 64) {
          if (p->fts_statp[0].st_dev != sp->fts_dev) {
          _L___0:

            if (sp->fts_child) {

              sp->fts_child = (struct _ftsent *)((void *)0);
            }
            p->fts_info = (unsigned short)6;
            while (1) {
              leave_dir(sp, p);
              goto while_break;
            }
          while_break:;
            return (p);
          }
        }
      }

      if ((unsigned long)sp->fts_child != (unsigned long)((void *)0)) {
        tmp___3 = fts_safe_changedir(sp, p, -1, (char const *)p->fts_accpath);
        if (tmp___3) {

          p->fts_flags = (unsigned short)((int)p->fts_flags | 1);

          ;
        }
      } else {
        tmp___4 = fts_build(sp, 3);
        sp->fts_child = tmp___4;
        if ((unsigned long)tmp___4 == (unsigned long)((void *)0)) {

          if (p->fts_errno) {
          }
          while (1) {
            leave_dir(sp, p);
            goto while_break___1;
          }
        while_break___1:;
          return (p);
        }
      }
      p = sp->fts_child;
      sp->fts_child = (struct _ftsent *)((void *)0);
      goto name;
    }

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
            }
            tmp___7 = fchdir(tmp___6);
            tmp___8 = tmp___7;
          }

        } else {
          tmp___9 = 0;
        }

        fts_load(sp, p);
        setup_dir(sp);
        goto check_for_dir;
      }

    name:
      if ((int)*((p->fts_parent)->fts_path +
                 ((p->fts_parent)->fts_pathlen - 1UL)) == 47) {

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
            if (parent->fts_n_dirs_remaining == 0UL) {

            } else {
              goto _L___4;
            }
          } else {
          _L___4:
            p->fts_info = fts_stat(sp, p, (_Bool)0);
            if ((p->fts_statp[0].st_mode & 61440U) == 16384U) {
              if (p->fts_level != 0L) {
                if (parent->fts_n_dirs_remaining) {
                  (parent->fts_n_dirs_remaining)--;
                }
              }
            }
          }
        } else {
          while (1) {
          }

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
      free((void *)p);

      tmp___18 = (struct _ftsent *)((void *)0);
      sp->fts_cur = tmp___18;
    }

    *(sp->fts_path + p->fts_pathlen) = (char)'\000';
    if (p->fts_level == 0L) {

      if (!(sp->fts_options & 4)) {
        if (sp->fts_options & 512) {
          if (sp->fts_options & 512) {

          } else {
          }
          cwd_advance_fd(sp, tmp___20, (_Bool)1);
          tmp___23 = 0;
        } else {
          if (sp->fts_options & 512) {

          } else {
            tmp___21 = sp->fts_rfd;
          }
          tmp___22 = fchdir(tmp___21);
          tmp___23 = tmp___22;
        }
        if (tmp___23) {
          tmp___24 = 1;
        } else {
          tmp___24 = 0;
        }
      } else {
        tmp___24 = 0;
      }
      if (tmp___24) {

        p->fts_errno = *tmp___19;
        sp->fts_options |= 8192;
      }
    } else {
      if ((int)p->fts_flags & 2) {

      } else {
        if (!((int)p->fts_flags & 1)) {
          tmp___31 = fts_safe_changedir(sp, p->fts_parent, -1, "..");
          if (tmp___31) {
          }
        }
      }
    }
    if (p->fts_errno) {
      p->fts_info = (unsigned short)7;
    } else {
      p->fts_info = (unsigned short)6;
    }

    return (tmp___32);
  }
}

static void set_stat_type(struct stat *st, unsigned int dtype) {
  mode_t type;

  {
    if (dtype == 6U) {
    }

    if (dtype == 4U) {
      goto case_4;
    }

    if (dtype == 8U) {
    }

    goto switch_default;
  case_6:
    type = (mode_t)24576;
    goto switch_break;

    goto switch_break;
  case_4:
    type = (mode_t)16384;
    goto switch_break;

    type = (mode_t)4096;
    goto switch_break;

    type = (mode_t)40960;
    goto switch_break;
  case_8:

    goto switch_break;

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
  int *tmp;
  DIR *tmp___0;
  DIR *tmp___1;
  int *tmp___2;
  _Bool tmp___3;
  int tmp___4;
  int dir_fd;
  int tmp___5;

  int tmp___7;
  char *tmp___8;
  _Bool is_dir;
  size_t tmp___9;

  size_t tmp___12;
  _Bool tmp___13;
  size_t tmp___14;
  size_t tmp___15;

  _Bool skip_stat;
  int tmp___17;
  int tmp___18;
  int tmp___19;

  int tmp___26;

  {
    cur = sp->fts_cur;
    if (!(sp->fts_options & 4)) {
      if (sp->fts_options & 512) {
        tmp___0 = opendirat(sp->fts_cwd_fd, (char const *)cur->fts_accpath);
        dirp = tmp___0;
      } else {
      }
    } else {
      tmp___1 = opendir_safer((char const *)cur->fts_accpath);
      dirp = tmp___1;
    }

    if ((int)cur->fts_info == 11) {
      cur->fts_info = fts_stat(sp, cur, (_Bool)0);
    } else {
      if (sp->fts_options & 256) {
        while (1) {
          leave_dir(sp, cur);
          goto while_break;
        }
      while_break:
        fts_stat(sp, cur, (_Bool)0);
        tmp___3 = enter_dir(sp, cur);
      }
    }

    if (nlinks) {
      goto _L___0;
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

            cur->fts_flags = (unsigned short)((int)cur->fts_flags | 1);

          } else {
            descend = (_Bool)1;
          }
        }
      } else {
        descend = (_Bool)0;
      }
    }
    if ((int)*(cur->fts_path + (cur->fts_pathlen - 1UL)) == 47) {
      len = cur->fts_pathlen - 1UL;
    } else {
      len = cur->fts_pathlen;
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

          closedir(dirp);

          return ((FTSENT *)((void *)0));
        }
        if ((unsigned long)oldaddr != (unsigned long)sp->fts_path) {
        }
        maxlen = sp->fts_pathlen - len;
      }

      new_len = len + tmp___15;

      p->fts_level = level;
      p->fts_parent = sp->fts_cur;
      p->fts_pathlen = new_len;
      p->fts_statp[0].st_ino = dp->d_ino;
      if (sp->fts_options & 4) {

      } else {
        p->fts_accpath = p->fts_name;
      }
      if ((unsigned long)sp->fts_compar == (unsigned long)((void *)0) ||
          sp->fts_options & 1024) {
        if (sp->fts_options & 16) {
          if (sp->fts_options & 8) {
            if ((int)dp->d_type != 0) {
              if (!((int)dp->d_type == 4)) {

              } else {
                tmp___17 = 0;
              }
            } else {
              tmp___17 = 0;
            }
          } else {
            tmp___17 = 0;
          }
        } else {
          tmp___17 = 0;
        }
        skip_stat = (_Bool)tmp___17;
        p->fts_info = (unsigned short)11;
        set_stat_type(p->fts_statp, (unsigned int)dp->d_type);
        fts_set_stat_required(p, (_Bool)(!skip_stat));

        is_dir = (_Bool)tmp___18;
      } else {
        p->fts_info = fts_stat(sp, p, (_Bool)0);
        if ((int)p->fts_info == 1) {

        } else {
          if ((int)p->fts_info == 2) {

          } else {
            if ((int)p->fts_info == 5) {

            } else {
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
      if (type == 1 || !nitems) {

        if (tmp___26) {
          cur->fts_info = (unsigned short)7;

          return ((FTSENT *)((void *)0));
        }
      }
    }
    if (!nitems) {
      if (type == 3) {
        cur->fts_info = (unsigned short)6;
      }

      return ((FTSENT *)((void *)0));
    }

    return (head);
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;

  int *tmp___1;

  int tmp___3;

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

      } else {
        tmp___5 =
            fstatat(sp->fts_cwd_fd, (char const *)p->fts_accpath, sbp, 256);
      }
    }
    if ((sbp->st_mode & 61440U) == 16384U) {

      p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;

      return ((unsigned short)1);
    }
    if ((sbp->st_mode & 61440U) == 40960U) {
    }
  }
}

static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems) {
  FTSENT **ap;
  FTSENT *p;

  int (*compare)(void const *, void const *);
  int (*tmp)(void const *, void const *);

  {

    compare = tmp;
    if (nitems > sp->fts_nitems) {
      sp->fts_nitems = nitems + 40UL;
    }

    p = head;

    qsort((void *)sp->fts_array, nitems, sizeof(FTSENT *), compare);

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
    p->fts_name[namelen] = (char)'\000';
    p->fts_namelen = namelen;
    p->fts_fts = sp;
    p->fts_path = sp->fts_path;
    p->fts_errno = 0;

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
    new_len = (sp->fts_pathlen + more) + 256UL;

    sp->fts_pathlen = new_len;
    p = (char *)realloc((void *)sp->fts_path, sp->fts_pathlen);
    if ((unsigned long)p == (unsigned long)((void *)0)) {
    }
    sp->fts_path = p;
    return ((_Bool)1);
  }
}
static void fts_padjust(FTS *sp, FTSENT *head) {
  FTSENT *p;
  char *addr;

  {

    while (1) {

      if (!p) {
      }
      while (1) {

        if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
          p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
        }
        p->fts_path = addr;
        goto while_break___0;
      }
    while_break___0:
      p = p->fts_link;
    }
  while_break:

    while (1) {

      if (!(p->fts_level >= 0L)) {
      }
      while (1) {

        if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
          p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
        }
        p->fts_path = addr;
      }

      ;
      if (p->fts_link) {

      } else {
      }
    }
  while_break___1:;
    return;
  }
}
static size_t fts_maxarglen(char *const *argv) {

  size_t max;

  {

    ;
    return (max + 1UL);
  }
}
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir) {
  int ret;
  _Bool is_dotdot;

  int tmp___0;
  int newfd;

  struct stat sb;
  int tmp___2;

  int tmp___4;
  int oerrno;

  int *tmp___6;

  {

    is_dotdot = (_Bool)tmp___0;
    if (sp->fts_options & 4) {
      if (sp->fts_options & 512) {
        if (0 <= fd) {
        }
      }
      return (0);
    }

    newfd = fd;
    if (fd < 0) {
      newfd = diropen((FTS const *)sp, dir);
      if (newfd < 0) {
        return (-1);
      }
    }
    if (sp->fts_options & 2) {
      goto _L;
    } else {
      if (dir) {

        if (tmp___4 == 0) {
        _L:
          tmp___2 = fstat(newfd, &sb);

          if (p->fts_statp[0].st_dev != sb.st_dev) {

            ret = -1;
            goto bail;
          } else {
          }
        }
      }
    }

    ret = fchdir(newfd);
  bail:
    if (fd < 0) {

      close(newfd);
      tmp___6 = __errno_location();
      *tmp___6 = oerrno;
    }
    return (ret);
  }
}

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
extern void chopt_init(struct Chown_option *chopt);

extern _Bool chown_files(char **files, int bit_flags, uid_t uid, gid_t gid,
                         uid_t required_uid, gid_t required_gid,
                         struct Chown_option const *chopt);
__inline static void ignore_ptr(void *p) {

  {}
}
extern void chopt_init(struct Chown_option *chopt) {

  {

    chopt->root_dev_ino = (struct dev_ino *)((void *)0);

    chopt->recurse = (_Bool)0;
  }
}

static void describe_change(char const *file, enum Change_status changed,
                            char const *user, char const *group) {
  char const *fmt;
  char const *spec;
  char *spec_allocated;

  char *tmp___8;
  char *tmp___9;
  char *tmp___10;
  char *tmp___11;
  char *tmp___12;

  char const *tmp___17;

  {

    if (user) {

    } else {
      spec = group;
    }
    if ((unsigned int)changed == 2U) {
    }
    if ((unsigned int)changed == 3U) {
      goto case_3;
    }
    if ((unsigned int)changed == 4U) {
      goto case_4;
    }

  case_2:
    if (user) {

    } else {

      fmt = (char const *)tmp___8;
    }
    goto switch_break;
  case_3:
    if (user) {

      fmt = (char const *)tmp___9;
    } else {
      if (group) {
        tmp___10 = gettext("failed to change group of %s to %s\n");

      } else {
        tmp___11 = gettext("failed to change ownership of %s\n");
        tmp___12 = tmp___11;
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
  int tmp___0;
  int *tmp___1;
  int *tmp___2;

  int tmp___5;
  int tmp___6;
  int saved_errno;
  int *tmp___7;
  int *tmp___8;

  {
    status = (enum RCH_status)2;
    open_flags = 2304;

    fd = openat(cwd_fd, file, open_flags);
    if (!(0 <= fd)) {
      tmp___2 = __errno_location();
      if (*tmp___2 == 13) {
        if ((orig_st->st_mode & 61440U) == 32768U) {
          fd = openat(cwd_fd, file, 1 | open_flags);
          if (!(0 <= fd)) {
            goto _L___0;
          }
        } else {
          goto _L___0;
        }
      } else {
      _L___0:
        tmp___1 = __errno_location();
        if (*tmp___1 == 13) {

        } else {
          tmp___0 = 6;
        }
        return ((enum RCH_status)tmp___0);
      }
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

  int tmp___20;
  char const *tmp___21;
  char *tmp___22;
  char const *tmp___23;
  char const *tmp___24;
  char *tmp___25;
  int tmp___26;
  char *tmp___27;
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

    if ((int)ent->fts_info == 4) {
    }

    goto switch_default;
  case_1:
    if (chopt->recurse) {
      if (chopt->root_dev_ino) {
        if (ent->fts_statp[0].st_ino == (chopt->root_dev_ino)->st_ino) {
          if (ent->fts_statp[0].st_dev == (chopt->root_dev_ino)->st_dev) {
            while (1) {

              tmp___5 =
                  gettext("use --no-preserve-root to override this failsafe");
              error(0, 0, (char const *)tmp___5);
              goto while_break;
            }
          while_break:
            fts_set(fts, ent, 4);
            tmp___6 = fts_read(fts);
            ignore_ptr((void *)tmp___6);
            return ((_Bool)0);
          }
        }
      }
      return ((_Bool)1);
    }
    goto switch_break;
  case_6:

    goto switch_break;
  case_10:

    if (!chopt->force_silent) {
    }

    if (!chopt->force_silent) {
    }
    ok = (_Bool)0;

  case_4:
    if (!chopt->force_silent) {
    }
    ok = (_Bool)0;

  switch_default:

  switch_break:;
    if (!ok) {
      do_chown = (_Bool)0;

    } else {
      if (required_uid == 4294967295U) {
        if (required_gid == 4294967295U) {

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
                if (file_stats->st_ino ==
                    (__ino_t const)(chopt->root_dev_ino)->st_ino) {

                  while (1) {
                    tmp___26 = strcmp(file_full_name, "/");
                    if (tmp___26 == 0) {

                      error(0, 0, (char const *)tmp___22, tmp___21);
                    } else {

                      error(0, 0, (char const *)tmp___25, tmp___24, tmp___23);
                    }
                    tmp___27 = gettext(
                        "use --no-preserve-root to override this failsafe");
                    error(0, 0, (char const *)tmp___27);
                    goto while_break___1;
                  }
                while_break___1:;
                  return ((_Bool)0);
                }
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

      } else {
        tmp___30 = restricted_chown(fts->fts_cwd_fd, file, file_stats, uid, gid,
                                    required_uid, required_gid);

        if ((unsigned int)err == 5U) {
        }

        goto switch_default___0;

      case_5:
        tmp___31 = chownat(fts->fts_cwd_fd, file, uid, gid);
        ok = (_Bool)(tmp___31 == 0);

        ok = (_Bool)0;

        do_chown = (_Bool)0;
        ok = (_Bool)0;

      switch_default___0:

      switch_break___0:;
      }
      if (do_chown) {
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

  int *tmp___3;
  _Bool tmp___4;

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

      tmp___6 = __errno_location();
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
__attribute__((__noreturn__)) void usage(int status);
void usage(int status) {

  {
    if (status != 0) {

    } else {
    }
    exit(status);
  }
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

    chopt_init(&chopt);
    while (1) {
      optc = getopt_long(argc, (char *const *)argv, "HLPRcfhv",
                         long_options___1, (int *)((void *)0));
      if (!(optc != -1)) {
        goto while_break;
      }

      if (optc == 131) {
      }

      if (optc == 82) {
        goto case_82;
      }

      goto switch_default;

      goto switch_break;

      bit_flags = 16;
      goto switch_break;

      goto switch_break;

      goto switch_break;

    case_131:

      goto switch_break;

    case_82:

      goto switch_break;

      goto switch_break;
    switch_default:
      usage(1);
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

      optind++;
    }

    bit_flags |= 1024;
    ok = chown_files(argv + optind, bit_flags, uid, gid, required_uid,
                     required_gid, (struct Chown_option const *)(&chopt));

    if (ok) {

    } else {
      tmp___15 = 1;
    }
    exit(tmp___15);
  }
}
