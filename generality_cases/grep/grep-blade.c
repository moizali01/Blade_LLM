
struct option {};
typedef long intmax_t;
typedef long ptrdiff_t;
typedef unsigned long size_t;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef long __off_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef int wchar_t;
union __anonunion___value_23 {
  unsigned int __wch;
};
struct __anonstruct___mbstate_t_22 {
  int __count;
  union __anonunion___value_23 __value;
};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
typedef unsigned int wint_t;
typedef __mbstate_t mbstate_t;

typedef long __ssize_t;
typedef __ssize_t ssize_t;
enum quoting_style { literal_quoting_style = 0, shell_quoting_style = 1, shell_always_quoting_style = 2, c_quoting_style = 3, c_maybe_quoting_style = 4, escape_quoting_style = 5, locale_quoting_style = 6, clocale_quoting_style = 7, custom_quoting_style = 8 };

typedef struct __dirstream DIR;
typedef unsigned int __mode_t;
typedef __mode_t mode_t;
typedef unsigned long uintptr_t;
typedef unsigned long longword;

typedef struct hash_table Hash_table;

typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned long __nlink_t;

typedef long __time_t;
typedef long __blksize_t;
typedef long __blkcnt_t;

typedef long __syscall_slong_t;

typedef __nlink_t nlink_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
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

struct __anonstruct_FTS_18 {
  struct _ftsent *fts_cur;
  struct _ftsent *fts_child;

  char *fts_path;

  int fts_cwd_fd;
  size_t fts_pathlen;
  size_t fts_nitems;

  int fts_options;
};
typedef struct __anonstruct_FTS_18 FTS;
struct _ftsent {

  struct _ftsent *fts_parent;
  struct _ftsent *fts_link;
  DIR *fts_dirp;

  char *fts_accpath;
  char *fts_path;

  size_t fts_pathlen;

  ptrdiff_t fts_level;
  size_t fts_namelen;
  nlink_t fts_n_dirs_remaining;
  unsigned short fts_info;

  struct stat fts_statp[1];
  char fts_name[1];
};
typedef struct _ftsent FTSENT;
typedef unsigned long uintmax_t;

typedef unsigned long __re_long_size_t;
typedef unsigned long reg_syntax_t;

struct re_pattern_buffer {
  struct re_dfa_t *buffer;
  __re_long_size_t allocated;
  __re_long_size_t used;
  reg_syntax_t syntax;
  char *fastmap;
  unsigned char *translate;
  size_t re_nsub;
  unsigned int can_be_null : 1;
};

typedef int regoff_t;

typedef struct real_pcre pcre;

typedef struct real_pcre_jit_stack pcre_jit_stack;

typedef struct kwset *kwset_t;
typedef signed char mb_len_map_t;

struct obstack {

  char *next_free;

  int alignment_mask;
};

struct trie {

  struct tree *links;
};
struct kwset {

  struct trie *trie;
};

typedef int __re_idx_t;
typedef unsigned int __re_size_t;
struct re_registers {
  __re_size_t num_regs;
  regoff_t *start;
};

struct patterns {
  struct re_pattern_buffer regexbuf;
  struct re_registers regs;
};

typedef unsigned long wctype_t;
typedef unsigned int charclass_word;
typedef charclass_word charclass[8];
typedef ptrdiff_t token;
struct __anonstruct_position_35 {
  size_t index;
  unsigned int constraint;
};
typedef struct __anonstruct_position_35 position;
struct __anonstruct_position_set_36 {
  position *elems;
  size_t nelem;
  size_t alloc;
};
typedef struct __anonstruct_position_set_36 position_set;

struct __anonstruct_dfa_state_38 {
  size_t hash;
  position_set elems;
  unsigned char context;
  _Bool has_backref;

  unsigned short constraint;
  token first_end;
  position_set mbps;
};
typedef struct __anonstruct_dfa_state_38 dfa_state;
typedef ptrdiff_t state_num;

struct mb_char_classes {

  _Bool invert;
  wchar_t *chars;
  size_t nchars;
};
struct dfa {
  charclass *charclasses;
  size_t cindex;
  size_t calloc;
  token *tokens;
  size_t tindex;
  size_t talloc;
  size_t depth;
  size_t nleaves;
  size_t nregexps;
  _Bool fast;
  _Bool multibyte;
  token utf8_anychar_classes[5];
  mbstate_t mbs;
  int *multibyte_prop;

  struct mb_char_classes *mbcsets;
  size_t nmbcsets;
  size_t mbcsets_alloc;
  struct dfa *superset;
  dfa_state *states;
  state_num sindex;
  size_t salloc;
  position_set *follows;
  _Bool searchflag;
  state_num tralloc;
  int trcount;
  state_num **trans;
  state_num **fails;
  int *success;
  state_num *newlines;
  struct dfamust *musts;
  position_set mb_follows;
};

struct __anonstruct_stkalloc_43 {

  size_t nfirstpos;
};
enum __anonenum_status_transit_state_44 { TRANSIT_STATE_IN_PROGRESS = 0, TRANSIT_STATE_DONE = 1, TRANSIT_STATE_END_BUFFER = 2 };
typedef enum __anonenum_status_transit_state_44 status_transit_state;

typedef struct must must;

typedef __off_t off_t;

enum directories_type { READ_DIRECTORIES = 2, RECURSE_DIRECTORIES = 3, SKIP_DIRECTORIES = 4 };
enum __anonenum_devices_71 { READ_COMMAND_LINE_DEVICES = 0, READ_DEVICES = 1, SKIP_DEVICES = 2 };
enum __anonenum_binary_files_72 { BINARY_BINARY_FILES = 0, TEXT_BINARY_FILES = 1, WITHOUT_MATCH_BINARY_FILES = 2 };
enum __anonenum_File_type_73 { UNKNOWN = 0, DOS_BINARY = 1, DOS_TEXT = 2, UNIX_TEXT = 3 };
typedef enum __anonenum_File_type_73 File_type;

struct matcher {
  char const name[16];
  void (*compile)(char const *, size_t);
  size_t (*execute)(char const *, size_t, size_t *, char const *);
};

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));

void *xnmalloc(size_t n, size_t s) {

  void *tmp___0;

  {

    { tmp___0 = xmalloc(n * s); }
    return (tmp___0);
  }
}

void *xnrealloc(void *p, size_t n, size_t s) {

  void *tmp___0;

  {

    { tmp___0 = xrealloc(p, n * s); }
    return (tmp___0);
  }
}
void *x2nrealloc(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {

    n = 128UL / s;

    { tmp = xrealloc(p, n * s); }
    return (tmp);
  }
}

void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    {
      tmp = malloc(n);
      p = tmp;
    }

    return (p);
  }
}

void *xrealloc(void *p, size_t n) {

  {

    { p = realloc(p, n); }

    return (p);
  }
}

void *xmemdup(void const *p, size_t s) {
  void *tmp;
  void *tmp___0;

  {
    { tmp___0 = memcpy((void * /* __restrict  */)tmp, (void const * /* __restrict  */)p, s); }
    return (tmp___0);
  }
}

void xalloc_die(void) {

  {
    {}
  }
}

extern struct _IO_FILE *stdout;

size_t safe_read(int fd, void *buf, size_t count) {
  ssize_t result;
  ssize_t tmp;

  {
    {

      /* CIL Label */
      ;
      {
        tmp = read(fd, buf, count);
        result = tmp;
      }

      return ((size_t)result);

      {}

    __Cont:;

    while_break: /* CIL Label */
        ;
    }

    return (0UL);
  }
}
char const *const quoting_style_args[9];
enum quoting_style const quoting_style_vals[8];

char const *program_name;

extern DIR *fdopendir(int __fd);

int openat_safer(int fd, char const *file, int flags, ...) {
  mode_t mode___0;
  va_list ap;
  int tmp;
  int tmp___0;

  {

    { __builtin_va_start(ap, flags); }

    {
      tmp = openat(fd, file, flags, mode___0);
      tmp___0 = fd_safer(tmp);
    }
    return (tmp___0);
  }
}

char *(__attribute__((__nonnull__(1, 2))) mbsstr)(char const *haystack, char const *needle) {

  {
    {}

    return ((char *)0);
  }
}

extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);

static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen);
static FTSENT *fts_build(FTS *sp, int type);

static _Bool fts_palloc(FTS *sp, size_t more);

static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow);
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir);

static DIR *opendirat(int fd, char const *dir, int extra_flags, int *pdir_fd) {
  int new_fd;
  int tmp;
  DIR *dirp;

  {
    {
      tmp = openat_safer(fd, dir, 67840 | extra_flags);
      new_fd = tmp;
    }

    { dirp = fdopendir(new_fd); }

    *pdir_fd = new_fd;

    {}

    return (dirp);
  }
}
static void cwd_advance_fd(FTS *sp, int fd, _Bool chdir_down_one) {

  {

    {

      /* CIL Label */
      ;
    }

    ;

    sp->fts_cwd_fd = fd;
  }
}

FTS *(__attribute__((__warn_unused_result__)) fts_open)(char *const *argv, int options, int (*compar)(FTSENT const **, FTSENT const **)) {
  register FTS *sp;
  register FTSENT *p;
  register FTSENT *root;
  register size_t nitems;
  FTSENT *parent;
  FTSENT *tmp;
  _Bool defer_stat;
  int *tmp___0;
  int *tmp___1;
  int *tmp___2;
  size_t maxarglen;
  size_t tmp___5;
  size_t tmp___6;
  _Bool tmp___7;
  int tmp___8;
  size_t len;
  size_t tmp___9;
  char const *v;
  struct _ftsent *tmp___10;
  _Bool tmp___11;

  void *__cil_tmp31;
  char *__cil_tmp32;
  char *__cil_tmp33;
  char *__cil_tmp34;

  {

    { sp = (FTS *)malloc(sizeof(FTS)); }

    { sp->fts_options = options; }

    {}

    { tmp___7 = fts_palloc(sp, tmp___6); }

    defer_stat = (_Bool)tmp___8;
    root = (FTSENT *)((void *)0);
    nitems = (size_t)0;
    {

      /* CIL Label */
      ;

      if (!((unsigned long)*argv != (unsigned long)((void *)0))) {
      }
      {
        tmp___9 = strlen((char const *)*argv);
        len = tmp___9;
      }

      { p = fts_alloc(sp, (char const *)*argv, len); }

      p->fts_accpath = p->fts_name;

      { p->fts_info = fts_stat(sp, p, (_Bool)0); }

      root = p;

      argv++;
      nitems++;

    while_break___1: /* CIL Label */
        ;
    }
  while_break:;

    { sp->fts_cur = tmp___10; }

    { (sp->fts_cur)->fts_link = root; }

    {}
    return (sp);
  mem3: {}
    {}
    {}
  }
}
static void fts_load(FTS *sp, FTSENT *p) {
  register size_t len;

  size_t tmp;

  {
    {
      tmp = p->fts_namelen;
      p->fts_pathlen = tmp;
      len = tmp;
      memmove((void *)sp->fts_path, (void const *)(p->fts_name), len + 1UL);
    }
  }
}

FTSENT *(__attribute__((__warn_unused_result__)) fts_read)(FTS *sp) {
  register FTSENT *p;
  register FTSENT *tmp;
  register unsigned short instr;
  register char *t;
  int *tmp___0;
  int tmp___1;
  int *tmp___2;
  int tmp___3;
  struct _ftsent *tmp___4;
  int tmp___5;
  int *tmp___6;
  int tmp___7;
  size_t tmp___8;
  char *tmp___9;
  FTSENT *parent;
  _Bool tmp___10;
  int *tmp___11;
  _Bool tmp___12;
  int *tmp___13;
  struct _ftsent *tmp___14;
  int *tmp___15;
  int tmp___16;

  int *tmp___17;
  int *tmp___18;

  FTSENT *tmp___24;

  {
    if ((unsigned long)sp->fts_cur == (unsigned long)((void *)0)) {
      return ((FTSENT *)((void *)0));
    } else {
    }
    p = sp->fts_cur;

    if ((int)p->fts_info == 1) {

      {
      }

      {
        tmp___4 = fts_build(sp, 3);
        sp->fts_child = tmp___4;
      }

      p = sp->fts_child;

      goto name;
    }

    tmp = p;
    if ((unsigned long)p->fts_link == (unsigned long)((void *)0)) {

      {
        p = tmp->fts_parent;
        sp->fts_cur = p;

        p = fts_build(sp, 3);
      }
      if ((unsigned long)p == (unsigned long)((void *)0)) {

        goto cd_dot_dot;
      }
      {}
      goto name;
    }
    p = p->fts_link;

    {}

    {}

    { fts_load(sp, p); }
    goto check_for_dir;

  name:

    tmp___8 = (p->fts_parent)->fts_pathlen;

    {
      t = sp->fts_path + tmp___8;
      tmp___9 = t;
      t++;
      *tmp___9 = (char)'/';
      memmove((void *)t, (void const *)(p->fts_name), p->fts_namelen + 1UL);
    }
  check_for_dir:
    sp->fts_cur = p;

    return (p);

  cd_dot_dot: {}

    {

      tmp___14 = (struct _ftsent *)((void *)0);
      sp->fts_cur = tmp___14;
    }

    {

      /* CIL Label */
      ;
    }

    return (tmp___24);
  }
}

int fts_set(FTS *sp __attribute__((__unused__)), FTSENT *p, int instr) {
  int *tmp;

  {}
}

static FTSENT *fts_build(FTS *sp, int type) {
  register FTSENT *p;
  register FTSENT *head;
  register size_t nitems;
  FTSENT *tail;
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
  int dir_fd;
  FTSENT *cur;
  _Bool continue_readdir;
  DIR *dp;
  int *tmp;
  int *tmp___0;
  DIR *tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;

  size_t max_entries;
  unsigned long tmp___7;
  int tmp___8;

  int tmp___10;

  size_t d_namelen;
  struct dirent *dp___0;
  struct dirent *tmp___12;

  {
    cur = sp->fts_cur;
    continue_readdir = (_Bool)(!(!cur->fts_dirp));
    if (continue_readdir) {
      {
      }
      if (dir_fd < 0) {
        {

          /* CIL Label */
          ;
        }

        ;
      }
    } else {

      tmp___3 = 0;

      tmp___4 = -100;

      {
        tmp___1 = opendirat(tmp___4, (char const *)cur->fts_accpath, tmp___2 | tmp___3, &dir_fd);
        cur->fts_dirp = tmp___1;
      }
    }

    max_entries = tmp___7;

    if (sp->fts_options & 8) {
      if (sp->fts_options & 16) {
        if (sp->fts_options & 32) {

        } else {
          tmp___8 = 2;
        }
        nlinks = cur->fts_statp[0].st_nlink - (__nlink_t)tmp___8;
        nostat = (_Bool)1;
      } else {
        nlinks = (nlink_t)-1;
        nostat = (_Bool)0;
      }
    } else {
      nlinks = (nlink_t)-1;
      nostat = (_Bool)0;
    }

    if (continue_readdir) {

    } else {
      if (nlinks) {

      } else {

        if (dir_fd < 0) {

        } else {
          { tmp___10 = fts_safe_changedir(sp, cur, dir_fd, (char const *)((void *)0)); }
          if (tmp___10) {
          _L:

          {
            while (1) {
              /* CIL Label */
              ;
              {}

            }
            /* CIL Label */
            ;
          }

          ;

          } else {
          }
        }

        descend = (_Bool)0;
      }
    }

    len++;
    maxlen = sp->fts_pathlen - len;
    level = cur->fts_level + 1L;
    doadjust = (_Bool)0;
    head = (FTSENT *)((void *)0);
    tail = (FTSENT *)((void *)0);
    nitems = (size_t)0;
    {

      /* CIL Label */
      ;
    while_continue___2:;

      {
        tmp___12 = readdir(cur->fts_dirp);
        dp___0 = tmp___12;
      }
      if ((unsigned long)dp___0 == (unsigned long)((void *)0)) {
        goto while_break___2;
      }
      if (!(sp->fts_options & 32)) {
        if ((int)dp___0->d_name[0] == 46) {

          goto while_continue___2;
        }
      }
      {
        d_namelen = strlen((char const *)(dp___0->d_name));
        p = fts_alloc(sp, (char const *)(dp___0->d_name), d_namelen);
      }

      if (d_namelen >= maxlen) {
        {
        }
      }

      p->fts_parent = sp->fts_cur;

      if (sp->fts_options & 4) {
        {
        }
      } else {
        p->fts_accpath = p->fts_name;
      }

      if ((unsigned long)head == (unsigned long)((void *)0)) {
        tail = p;
        head = tail;
      } else {
      }
      nitems++;

      /* CIL Label */
      ;
    }
  while_break___2:;

  break_without_closedir:

    return (head);
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;
  int saved_errno;

  int *tmp___1;

  int tmp___3;

  int tmp___6;

  {
    sbp = p->fts_statp;

    follow = (_Bool)1;

    if (follow) {
      {
        tmp___3 = stat((char const * /* __restrict  */)((char const *)p->fts_accpath), (struct stat * /* __restrict  */)sbp);
      }

      {}
      if (*tmp___1 == 2) {
        {
        }
      }

    } else {
      {}
    }

    if ((sbp->st_mode & 61440U) == 16384U) {
      if (sp->fts_options & 32) {

      } else {
      }
      p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;

      return ((unsigned short)1);
    }
  }
}

static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems) {
  register FTSENT **ap;

  int (*compare)(void const *, void const *);
  int (*tmp)(void const *, void const *);

  {

    compare = tmp;
    if (nitems > sp->fts_nitems) {
    }

    {

      /* CIL Label */
      ;
    }
    {}
    {

      /* CIL Label */
      ;
    }

    (*(ap + 0))->fts_link = (struct _ftsent *)((void *)0);
  }
}
static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen) {
  register FTSENT *p;
  size_t len;

  {
    {
      len = sizeof(FTSENT) + namelen;
      p = (FTSENT *)malloc(len);
    }

    {
      memcpy((void * /* __restrict  */)((void *)(p->fts_name)), (void const * /* __restrict  */)((void const *)name), namelen);

      p->fts_namelen = namelen;

      p->fts_path = sp->fts_path;
    }
    return (p);
  }
}
static void fts_lfree(FTSENT *head) {

  {
    {

      /* CIL Label */
      ;
    }

    ;
  }
}
static _Bool fts_palloc(FTS *sp, size_t more) {
  char *p;

  {

    {}
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      {
      }
      return ((_Bool)0);
    }
    sp->fts_path = p;
    return ((_Bool)1);
  }
}

static size_t __attribute__((__pure__)) fts_maxarglen(char *const *argv) {

  {

    {

      /* CIL Label */
      ;
    }

    ;
  }
}
static int fts_safe_changedir(FTS *sp, FTSENT *p, int fd, char const *dir) {

  _Bool is_dotdot;

  int tmp___0;
  int newfd;

  int tmp___4;

  {

    is_dotdot = (_Bool)tmp___0;

    newfd = fd;

    if (sp->fts_options & 2) {
      goto _L;
    } else {
      if (dir) {
        {
        }
        if (tmp___4 == 0) {
        _L: {}

          goto bail;
        }
      }
    }

    { cwd_advance_fd(sp, newfd, (_Bool)(!is_dotdot)); }
    return (0);

    {}
  bail:

  {}
  }
}

int fd_safer(int fd) {

  { return (fd); }
}

int rpl_fcntl(int fd, int action, ...) {

  int result;

  int flags;
  int tmp___1;

  int *tmp___3;

  void *p;

  {
    {}

    {}

    { result = fcntl(fd, action, p); }

    {}
    return (result);
  }
}

int dup_safer(int fd) {
  int tmp;

  {
    { tmp = rpl_fcntl(fd, 0, 3); }
    return (tmp);
  }
}

void cycle_check_init(struct cycle_check_state *state) {

  {}
}
_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb) {

  {

    {}
  }
}

void init_colorize(void) {

  {}
}

int set_cloexec_flag(int desc, _Bool value) {

  {
    {}
  }
}
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1))) memrchr)(void const *__s, int __c, size_t __n) __attribute__((__pure__));

int c_strcasecmp(char const *s1, char const *s2) {

  {

    {

      /* CIL Label */
      ;
    }

    ;
  }
}

int c_tolower(int c) {
  int tmp;

  { return (tmp); }
}

void (*argmatch_die)(void);

int match_words;
int match_lines;
unsigned char eolbyte;

void Pcompile(char const *pattern, size_t size) {

  char *re;

  int flags;
  int tmp___0;
  int tmp___2;
  int tmp___3;
  char const *patlim;
  char *n;
  char const *p;

  void *tmp___5;

  {
    {}

    { tmp___3 = using_utf8(); }

    {
      flags = (2 | tmp___0) | tmp___2;
      patlim = pattern + size;
      n = re;
      tmp___5 = memchr((void const *)pattern, '\n', size);
    }

    {}
    {

    while_break___1: /* CIL Label */
        ;
    }
  while_break: {
    memcpy((void * /* __restrict  */)((void *)n), (void const * /* __restrict  */)((void const *)p), (size_t)(patlim - p));
    n += patlim - p;
    *n = (char)'\000';
  }

    {}

    {}

    {}

    {}
  }
}
size_t Pexecute(char const *buf, size_t size, size_t *match_size, char const *start_ptr) {

  char const *line_next;

  ptrdiff_t start_ofs;
  long tmp;

  {

    start_ofs = tmp;
    line_next = buf;
    {

    while_break___1: /* CIL Label */
        ;
    }
  while_break:;
  }
}

void kwsinit(kwset_t *kwset___1);

static kwset_t kwset;
void Fcompile(char const *pattern, size_t size) {

  char const *pat;

  char const *tmp___1;

  char const *p;

  {

    {
      pat = tmp___1;
      kwsinit(&kwset);
      p = pat;
    }
    {

      /* CIL Label */
      ;
    }
    {}
  }
}

size_t Fexecute(char const *buf, size_t size, size_t *match_size, char const *start_ptr) {
  char const *beg;

  char const *end;
  char const *mb_start;
  size_t len;
  char eol;

  size_t ret_val;
  mb_len_map_t *map;

  size_t off;

  {
    {}

    mb_start = beg;
    {

    while_break___2: /* CIL Label */
        ;
    }
  while_break:;
  failure:
    return ((size_t)-1);
  success: { end = (char const *)memchr((void const *)(beg + len), (int)eol, (size_t)((buf + size) - (beg + len))); }

    {

    while_break___4: /* CIL Label */
        ;
    }
  while_break___1:
    len = (size_t)(end - beg);
  success_in_beg_and_len: {
    off = (size_t)(beg - buf);
    mb_case_map_apply((mb_len_map_t const *)map, &off, &len);
    *match_size = len;
    ret_val = off;
  }
    return (ret_val);
  }
}

kwset_t kwsalloc(char const *trans___0) {

  struct obstack *__o1;

  char *tmp___0;
  char *tmp___1;

  {
    {}

    __o1->next_free = tmp___0 + (((__o1->next_free - tmp___1) + (long)__o1->alignment_mask) & (long)(~__o1->alignment_mask));
  }
}

static void treenext(struct tree const *tree, struct trie **next) {

  {

    {}
  }
}
void kwsprep(kwset_t kwset___1) {

  unsigned char deltabuf[256];
  unsigned char *delta;
  unsigned char *tmp;
  int tmp___0;
  struct trie *curr;
  struct trie *last;

  struct trie *nextbuf[256];
  struct trie **next;
  struct trie **tmp___2;

  {

    delta = tmp;

    {
      memset((void *)delta, tmp___0, sizeof(deltabuf));
      last = kwset___1->trie;
      curr = last;
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

    {
      next = tmp___2;
      memset((void *)next, 0, sizeof(nextbuf));
      treenext((struct tree const *)(kwset___1->trie)->links, next);
    }
  }
}

struct dfa *dfaalloc(void);

void dfacomp(char const *s, size_t len, struct dfa *d, int searchflag);
char *dfaexec(struct dfa *d, char const *begin, char *end, int allow_nl, size_t *count, int *backref);

static kwset_t kwset___0;
static struct dfa *dfa;
static struct patterns patterns0;
static struct patterns *patterns;
static size_t pcount;
static size_t kwset_exact_matches;
static _Bool begline;

void dfaerror(char const *mesg) {

  {
    {}
  }
}

static void kwsmusts(void) {

  {
    {}
  }
}

void GEAcompile(char const *pattern, size_t size, reg_syntax_t syntax_bits___0) {
  size_t total;
  char *motif;
  char const *p;
  size_t len;
  char const *sep;
  char const *tmp;
  char const *err;
  char const *tmp___0;

  char *n;

  char const *tmp___4;

  char const *tmp___7;
  size_t tmp___8;

  {
    total = size;

    { p = pattern; }
    {

      /* CIL Label */
      ;
      {
        tmp = (char const *)memchr((void const *)p, '\n', total);
        sep = tmp;
      }

      len = total;

      {
        patterns = (struct patterns *)xnrealloc((void *)patterns, pcount + 1UL, sizeof(*patterns));
        *(patterns + pcount) = patterns0;
        tmp___0 = re_compile_pattern(p, len, &(patterns + pcount)->regexbuf);
        err = tmp___0;
      }

      pcount++;
      p = sep;

      /* CIL Label */
      ;
    }
  while_break:;

    if (match_lines) {
      {
      }

      {
        strcpy((char * /* __restrict  */)n, (char const * /* __restrict  */)tmp___4);
        total = strlen((char const *)n);
        memcpy((void * /* __restrict  */)((void *)(n + total)), (void const * /* __restrict  */)((void const *)pattern), size);
        total += size;
      }

      {
        strcpy((char * /* __restrict  */)(n + total), (char const * /* __restrict  */)tmp___7);
        tmp___8 = strlen((char const *)(n + total));
        total += tmp___8;
        motif = n;
        pattern = (char const *)motif;
        size = total;
      }
    } else {
      motif = (char *)((void *)0);
    }

    {
      dfa = dfaalloc();
      dfacomp(pattern, size, dfa, 1);
      kwsmusts();
      free((void *)motif);
    }
    return;
  }
}
size_t EGexecute(char const *buf, size_t size, size_t *match_size, char const *start_ptr) {
  char const *buflim___0;
  char const *beg;
  char const *end;
  char const *ptr;

  char eol;
  int backref;
  regoff_t start;
  size_t len;

  size_t i;

  char const *next_beg;
  char const *dfa_beg;
  size_t count;

  size_t off;

  {
    {
      eol = (char)eolbyte;

      buflim___0 = buf + size;
      end = buf;
      beg = end;
    }
    {
      while (1) {
        /* CIL Label */
        ;

        if (!((unsigned long)end < (unsigned long)buflim___0)) {
          goto while_break;
        }
        end = buflim___0;
        if (!start_ptr) {
          dfa_beg = beg;

          { next_beg = (char const *)dfaexec(dfa, dfa_beg, (char *)end, 0, &count, &backref); }

          { end = (char const *)memchr((void const *)next_beg, (int)eol, (size_t)(buflim___0 - next_beg)); }

          end++;

          ptr = beg;
        } else {
        }
        if ((long)(((1 << (sizeof(regoff_t) * 8UL - 2UL)) - 1) * 2 + 1) < (end - beg) - 1L) {
          {
          }
        }

        i = (size_t)0;
        {
          while (1) {
            /* CIL Label */
            ;

            if (!(i < pcount)) {
              goto while_break___1;
            }
            { start = re_search(&(patterns + i)->regexbuf, beg, (__re_idx_t)((end - beg) - 1L), (__re_idx_t)(ptr - beg), (regoff_t)((end - ptr) - 1L), &(patterns + i)->regs); }

            {}

            if (0 <= start) {

              if (match_words) {
                {

                  /* CIL Label */
                  ;
                }

                ;
              }

            assess_pattern_match:
              if (!start_ptr) {
                goto success;
              }
            }

          __Cont___0:
            i++;
          }
          /* CIL Label */
          ;
        }
      while_break___1:;

        beg = end;
      }
      /* CIL Label */
      ;
    }
  while_break:;

    return ((size_t)-1);
  success:
    len = (size_t)(end - beg);

    off = (size_t)(beg - buf);
    *match_size = len;
    return (off);
  }
}

void dfaanalyze(struct dfa *d, int searchflag);

extern __attribute__((__nothrow__)) int islower(int);

extern __attribute__((__nothrow__)) int isprint(int);

extern __attribute__((__nothrow__)) int isblank(int);

extern __attribute__((__nothrow__)) int iswctype(wint_t __wc, wctype_t __desc);

static void dfamust(struct dfa *d);
static void regexp(void);

static size_t mbs_to_wchar(wint_t *pwc, char const *s, size_t n, struct dfa *d) {

  wint_t wc;

  {

    if (wc == 4294967295U) {
      {
      }

      {}
    }
  }
}

static void *maybe_realloc(void *ptr, size_t nitems, size_t *nalloc, size_t itemsize) {
  void *tmp;

  {
    if (nitems < *nalloc) {
    }
    { tmp = x2nrealloc(ptr, nalloc, itemsize); }
    return (tmp);
  }
}

static struct dfa *dfa___0;

static unsigned char eolbyte___0;

static charclass letters;

static int char_context(unsigned char c) {

  {

    {}
  }
}

static void setbit_case_fold_c(int b, charclass_word *c) {

  {
    {}
    {

      /* CIL Label */
      ;
    }

    ;
  }
}
static int utf8 = -1;
int using_utf8(void) {

  int tmp___0;

  {
    if (utf8 < 0) {
      {
      }

      utf8 = tmp___0;
    }
    return (utf8);
  }
}
static _Bool using_simple_locale(void);

static char const *lexptr;
static size_t lexleft;
static token lasttok;
static _Bool laststart;
static size_t parens;
static int minrep;
static int maxrep;
static int cur_mb_len = 1;
static wint_t wctok;
static short const lonesome_lower[19] = {(short const)181, (short const)305, (short const)383, (short const)453,  (short const)456,  (short const)459,  (short const)498,  (short const)837,  (short const)962, (short const)976,
                                         (short const)977, (short const)981, (short const)982, (short const)1008, (short const)1009, (short const)1010, (short const)1013, (short const)7835, (short const)8126};
static int case_folded_counterparts(wchar_t c, wchar_t *folded) {

  wint_t uc;

  wint_t lc;

  {
    {}

    if (lc != uc) {
    }

    {

      /* CIL Label */
      ;

      /* CIL Label */
      ;
    }

    ;
  }
}

static struct dfa_ctype const *__attribute__((__pure__)) find_pred(char const *str) {

  {

    {

      /* CIL Label */
      ;
    }

    ;
  }
}

static token lex(void) {
  int c;

  _Bool backslash;
  charclass ccl;
  int i;

  size_t nbytes;
  size_t tmp;

  char *tmp___1;

  int tmp___5;

  int tmp___7;

  char const *lim;
  char *tmp___8;

  char const *tmp___10;
  char *tmp___11;
  size_t tmp___12;

  size_t tmp___14;
  char const *lexptr_saved;

  unsigned short const **tmp___18;

  char *__cil_tmp39;

  char *__cil_tmp42;
  char *__cil_tmp43;

  {
    backslash = (_Bool)0;
    i = 0;
    {

    while_break___6: /* CIL Label */
        ;
    }
  while_break: {}
    return ((token)-1);
  }
}
static token tok;
static size_t depth;
static void addtok_mb(token t, int mbprop) {
  size_t tmp;

  {
    if (dfa___0->talloc == dfa___0->tindex) {
      {
        dfa___0->tokens = (token *)x2nrealloc((void *)dfa___0->tokens, &dfa___0->talloc, sizeof(*(dfa___0->tokens)));
      }
    }

    tmp = dfa___0->tindex;

    if (t == 266L) {
      goto case_264;
    }

    if (t == 269L) {
      goto case_268;
    }
    if (t == 257L) {
      goto case_257;
    }
    if (t == 256L) {
      goto case_256;
    }
    goto switch_default;
  case_264:

  case_268:

    goto switch_break;
  case_257:
    dfa___0->fast = (_Bool)0;
  switch_default:

  case_256:
    depth++;
    goto switch_break;
  switch_break:;

    return;
  }
}
static void addtok_wc(wint_t wc);
static void addtok(token t) {
  _Bool need_or;
  struct mb_char_classes *work_mbc;
  size_t i;

  {
    if (dfa___0->multibyte) {
      if (t == 273L) {
        need_or = (_Bool)0;

        if (!work_mbc->invert) {

          {

          while_continue: /* CIL Label */
              ;

            { addtok_wc((wint_t) * (work_mbc->chars + i)); }

            need_or = (_Bool)1;
            i++;

          while_break___0: /* CIL Label */
              ;
          }
        while_break:
          work_mbc->nchars = (size_t)0;
        }

      } else {
        {}
      }
    } else {
      { addtok_mb(t, 3); }
    }
    return;
  }
}
static void addtok_wc(wint_t wc) {
  unsigned char buf[16];
  mbstate_t s;
  int i;
  size_t stored_bytes;
  size_t tmp;
  int tmp___0;
  int tmp___1;

  {
    {
      s.__count = 0;
      s.__value.__wch = 0U;

      stored_bytes = tmp;
    }

    if (cur_mb_len == 1) {

    } else {
      tmp___0 = 1;
    }
    {
      addtok_mb((token)buf[0], tmp___0);
      i = 1;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;

        {
          addtok_mb((token)buf[i], tmp___1);
          addtok((token)268);
          i++;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
  while_break:;
    return;
  }
}
static void add_utf8_anychar(void);

static void atom(void) {
  wchar_t folded[21];
  int i;
  int n;
  int tmp;
  char *tmp___0;
  int tmp___1;

  char *__cil_tmp10;

  {
    if (tok == 274L) {
      if (wctok == 4294967295U) {
        {
        }
      } else {
        { addtok_wc(wctok); }

        {
          tmp = case_folded_counterparts((wchar_t)wctok, folded);

          i = 0;
        }
        {
          while (1) {
            /* CIL Label */
            ;

            if (!(i < n)) {
              goto while_break;
            }
            {
              addtok_wc((wint_t)folded[i]);
              addtok((token)269);
              i++;
            }
          }
          /* CIL Label */
          ;
        }
      while_break:;
      }
      { tok = lex(); }
    } else {
      if (tok == 272L) {
        {
          tmp___1 = using_utf8();
        }

      } else {
      _L___0:

      {}

        goto _L;

      _L:

      {}

        { addtok(tok); }

        { tok = lex(); }

        if (tok == 259L) {
          {
            addtok(tok);
            tok = lex();
          }
        } else {
          if (tok == 260L) {
            {
            }
          } else {
            if (tok == 272L) {
              {
                addtok(tok);
              }
            } else {

              {
                addtok(tok);
                tok = lex();
              }

              if (tok == 261L) {
                {

                  tok = lex();
                }
              } else {

                { addtok(tok); }

                if (tok == 263L) {
                  {

                    tok = lex();
                  }
                } else {
                  if (tok == 270L) {
                    {
                    }
                    if (tok != 271L) {
                      {
                        tmp___0 = gettext("unbalanced (");
                        dfaerror((char const *)tmp___0);
                      }
                    }
                    { tok = lex(); }
                  } else {
                    {}
                  }
                }
              }
            }
          }
        }
      }
    }
    return;
  }
}
static size_t __attribute__((__pure__)) nsubtoks(size_t tindex) {
  size_t ntoks1;
  size_t __attribute__((__pure__)) tmp;
  size_t __attribute__((__pure__)) tmp___0;

  {
    if (*(dfa___0->tokens + (tindex - 1UL)) == 264L) {
      goto case_264;
    }
    if (*(dfa___0->tokens + (tindex - 1UL)) == 265L) {
    }

    goto switch_default;
  switch_default:
    return ((size_t __attribute__((__pure__)))1);
  case_264: { tmp = nsubtoks(tindex - 1UL); }

  case_268: { ntoks1 = (size_t)nsubtoks(tindex - 1UL); }
  }
}
static void copytoks(size_t tindex, size_t ntokens) {
  size_t i;

  {
    if (dfa___0->multibyte) {
      i = (size_t)0;
      {

      while_continue: /* CIL Label */
          ;

        if (!(i < ntokens)) {
          goto while_break;
        }
        {
          addtok_mb(*(dfa___0->tokens + (tindex + i)), *(dfa___0->multibyte_prop + (tindex + i)));
          i++;
        }

        /* CIL Label */
        ;
      }
    while_break:;
    } else {

      {
        while (1) {
          /* CIL Label */
          ;

          if (!(i < ntokens)) {
            goto while_break___0;
          }
          {
            addtok_mb(*(dfa___0->tokens + (tindex + i)), 3);
            i++;
          }
        }
        /* CIL Label */
        ;
      }
    while_break___0:;
    }
  }
}
static void closure(void) {

  size_t __attribute__((__pure__)) tmp;

  {
    { atom(); }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;

        if (!(tok == 264L)) {
          if (!(tok == 265L)) {
            if (!(tok == 266L)) {
              if (!(tok == 267L)) {
                goto while_break;
              }
            }
          }
        }
      }
    while_break___2: /* CIL Label */
        ;
    }
  while_break:;
    return;
  }
}
static void branch(void) {

  {
    { closure(); }
    {
      while (1) {
        /* CIL Label */
        ;

        if (tok != 269L) {

        } else {
          goto while_break;
        }

        goto while_break;

        {
          closure();
          addtok((token)268);
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
  while_break:;
    return;
  }
}
static void regexp(void) {

  {
    { branch(); }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;

        goto while_break;

        {
          tok = lex();
          branch();
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
  while_break:;
    return;
  }
}
void dfaparse(char const *s, size_t len, struct dfa *d) {

  {
    dfa___0 = d;

    laststart = (_Bool)1;
    parens = (size_t)0;

    {
      tok = lex();
      depth = d->depth;
      regexp();
    }

    {}
    if (d->nregexps) {
      {
        addtok((token)269);
      }
    }
    (d->nregexps)++;
    return;
  }
}

static void alloc_position_set(position_set *s, size_t size) {

  {
    { s->elems = (position *)xnmalloc(size, sizeof(*(s->elems))); }
    return;
  }
}
static void insert(position p, position_set *s) {
  size_t count;
  size_t lo;
  size_t hi;

  {

    hi = count;
    {

    while_break___1: /* CIL Label */
        ;
    }
  while_break:;
    if (lo < count) {
    }
    {}
    {

    while_break___2: /* CIL Label */
        ;
    }

    *(s->elems + lo) = p;

    return;
  }
}
static void merge(position_set const *s1, position_set const *s2, position_set *m) {
  size_t i;
  size_t j;

  size_t tmp___0;

  size_t tmp___6;
  size_t tmp___7;
  size_t tmp___8;
  size_t tmp___9;

  {
    i = (size_t)0;
    j = (size_t)0;

    { m->elems = (position *)maybe_realloc((void *)0, (size_t)(s1->nelem + s2->nelem), &m->alloc, sizeof(*(m->elems))); }

    m->nelem = (size_t)0;
    {

    while_break___2: /* CIL Label */
        ;
    }
  while_break:;
    {
      while (1) {
        /* CIL Label */
        ;

        if (!(i < (size_t)s1->nelem)) {
          goto while_break___0;
        }
        tmp___6 = m->nelem;
        (m->nelem)++;
        tmp___7 = i;
      }
    while_break___3: /* CIL Label */
        ;
    }
  while_break___0:;
    {

    while_break___4: /* CIL Label */
        ;
    }
  while_break___1:;
  }
}
static void delete(position p, position_set *s) {
  size_t i;

  {

    {
      while (1) {
      while_continue: /* CIL Label */
          ;

        if (!(i < s->nelem)) {
        }
        if (p.index == (s->elems + i)->index) {
          goto while_break;
        }
        i++;
      }
    while_break___1: /* CIL Label */
        ;
    }
  while_break:;
    if (i < s->nelem) {
      (s->nelem)--;
      {

      while_break___2: /* CIL Label */
          ;
      }
    while_break___0:;
    }
    return;
  }
}
static state_num state_index(struct dfa *d, position_set const *s, int context) {
  size_t hash;
  int constraint;
  state_num i;
  state_num j;

  {
    hash = (size_t)0;
    i = (state_num)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;

        if (!((size_t const)i < s->nelem)) {
          goto while_break;
        }
        hash ^= (s->elems + i)->index + (size_t)(s->elems + i)->constraint;
      }
    while_break___3: /* CIL Label */
        ;
    }
  while_break:
    i = (state_num)0;
    {
      while (1) {
        /* CIL Label */
        ;

        if (!(i < d->sindex)) {
          goto while_break___0;
        }
        if (hash != (d->states + i)->hash) {
          goto __Cont;
        } else {
          if (s->nelem != (size_t const)(d->states + i)->elems.nelem) {

          } else {
          }
        }

        {
          while (1) {
            /* CIL Label */
            ;

            if ((s->elems + j)->constraint != ((d->states + i)->elems.elems + j)->constraint) {
              goto while_break___1;
            } else {
              if ((s->elems + j)->index != ((d->states + i)->elems.elems + j)->index) {
                goto while_break___1;
              }
            }
            j++;
          }
        while_break___5: /* CIL Label */
            ;
        }
      while_break___1:;
        if ((size_t const)j == s->nelem) {
          return (i);
        }
      __Cont:
        i++;
      }
      /* CIL Label */
      ;
    }
  while_break___0: {
    d->states = (dfa_state *)maybe_realloc((void *)d->states, (size_t)d->sindex, &d->salloc, sizeof(*(d->states)));

    (d->states + i)->context = (unsigned char)context;
    (d->states + i)->has_backref = (_Bool)0;

    (d->states + i)->constraint = (unsigned short)0;
    (d->states + i)->first_end = (token)0;
    (d->states + i)->mbps.nelem = (size_t)0;
    (d->states + i)->mbps.elems = (position *)((void *)0);
    j = (state_num)0;
  }
    {
      while (1) {
        /* CIL Label */
        ;

        if (!((size_t const)j < s->nelem)) {
          goto while_break___2;
        }

        j++;
      }
      /* CIL Label */
      ;
    }
  while_break___2:
    (d->sindex)++;
    return (i);
  }
}
static void epsclosure(position_set *s, struct dfa const *d, char *visited) {
  size_t i;

  _Bool initialized;

  {
    initialized = (_Bool)0;

    {
      while (1) {
        /* CIL Label */
        ;

        if (!(i < s->nelem)) {
          goto while_break;
        }

      __Cont:
        i++;
      }
    while_break___1: /* CIL Label */
        ;
    }
  while_break:;
    return;
  }
}
static int charclass_context(charclass_word *c) {
  int context;
  unsigned int j;
  _Bool tmp;

  {
    {
      context = 0;
      tmp = tstbit((unsigned int)eolbyte___0, (charclass_word * /* const  */)c);
    }
    if (tmp) {
      context |= 4;
    }
    j = 0U;
    {

      /* CIL Label */
      ;

      if (*(c + j) & letters[j]) {
        context |= 2;
      }

      j++;

      /* CIL Label */
      ;
    }
  while_break:;
  }
}
static int __attribute__((__pure__)) state_separate_contexts(position_set const *s) {
  int separate_contexts;

  {

    {

    while_break___0: /* CIL Label */
        ;
    }

    ;
    return ((int __attribute__((__pure__)))separate_contexts);
  }
}
void dfaanalyze(struct dfa *d, int searchflag) {
  position *posalloc;
  position *tmp;
  position *firstpos;
  position *lastpos;
  struct __anonstruct_stkalloc_43 *stkalloc;
  struct __anonstruct_stkalloc_43 *tmp___0;
  struct __anonstruct_stkalloc_43 *stk;
  position_set tmp___1;
  position_set merged;
  int separate_contexts;
  size_t i;
  size_t j;
  position *pos;
  char *visited;
  char *tmp___2;

  size_t tmp___6;

  int tmp___8;

  {
    {
      tmp = (position *)xnmalloc(d->nleaves, 2UL * sizeof(*posalloc));
      posalloc = tmp;

      lastpos = firstpos + d->nleaves;
      tmp___0 = (struct __anonstruct_stkalloc_43 *)xnmalloc(d->depth, sizeof(*stkalloc));
      stkalloc = tmp___0;

      tmp___2 = (char *)xnmalloc(d->tindex, sizeof(*visited));
      visited = tmp___2;
      d->searchflag = (_Bool)(searchflag != 0);
      alloc_position_set(&merged, d->nleaves);
    }
    {

    while_break___5: /* CIL Label */
        ;
    }

    i = (size_t)0;
    {

      /* CIL Label */
      ;
    }

    merged.nelem = (size_t)0;
    i = (size_t)0;
    {

    while_continue___4: /* CIL Label */
        ;

      if (!(i < (stk + -1)->nfirstpos)) {
        goto while_break___4;
      }
      {}

    while_break___10: /* CIL Label */
        ;
    }
  while_break___4: {
    epsclosure(&merged, (struct dfa const *)d, visited);
    separate_contexts = (int)state_separate_contexts((position_set const *)(&merged));
  }
    if (separate_contexts & 4) {
      tmp___8 = 4;
    } else {
      tmp___8 = separate_contexts ^ 7;
    }
    {
      state_index(d, (position_set const *)(&merged), tmp___8);
      free((void *)posalloc);
      free((void *)stkalloc);
      free((void *)merged.elems);
      free((void *)visited);
    }
    return;
  }
}

static void build_state(state_num s, struct dfa *d) {
  state_num *trans___0;
  state_num i;
  state_num maxstate;
  state_num *tmp;

  {

    *(d->success + s) = 0;

    *(d->success + s) |= 4;

    if (((int)(d->states + s)->constraint & 15) & (int)(d->states + s)->context) {
      *(d->success + s) |= 1;
    }
    {
      trans___0 = (state_num *)xmalloc(256UL * sizeof(*trans___0));
      dfastate(s, d, trans___0);
      maxstate = (state_num)-1;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;

        if (!(i < 256L)) {
          goto while_break___0;
        }

        i++;
      }
    while_break___2: /* CIL Label */
        ;
    }
  while_break___0: {}
    if ((d->states + s)->constraint) {
      *(d->fails + s) = trans___0;
    } else {
      *(d->trans + s) = trans___0;
    }
    return;
  }
}
static void build_state_zero(struct dfa *d) {
  int initial_tab_size;

  {
    {
      initial_tab_size = 1;
      d->tralloc = (state_num)0;

      d->trans = (state_num **)((void *)0);
      d->fails = (state_num **)((void *)0);
      d->success = (int *)((void *)0);
      d->newlines = (state_num *)((void *)0);
    }
    return;
  }
}
static status_transit_state transit_state_singlebyte(struct dfa *d, state_num s, unsigned char const *p, state_num *next_state) {
  state_num *t;
  state_num works;
  status_transit_state rval;

  {
    works = s;

    {

    while_break___0: /* CIL Label */
        ;
    }
  while_break:
    *next_state = works;
    return (rval);
  }
}

static status_transit_state transit_state_consume_1char(struct dfa *d, state_num s, unsigned char const **pp, wint_t wc, size_t mbclen, int *match_lens) {
  size_t i;
  size_t j;
  int k;
  state_num s1;
  state_num s2;
  status_transit_state rs;

  {
    rs = (status_transit_state)1;
    if (!match_lens) {
    }
    s1 = s;

    {

    while_break___2: /* CIL Label */
        ;
    }
  while_break: { i = (size_t)0; }
    {

      /* CIL Label */
      ;

      if (!(i < (d->states + s)->mbps.nelem)) {
        goto while_break___0;
      }

      {
        while (1) {
          /* CIL Label */
          ;

          if (!(j < (d->follows + ((d->states + s)->mbps.elems + i)->index)->nelem)) {
            goto while_break___1;
          }
          { insert(*((d->follows + ((d->states + s)->mbps.elems + i)->index)->elems + j), &d->mb_follows); }
        }
      while_break___4: /* CIL Label */
          ;
      }
    while_break___1:;

      i++;

    while_break___3: /* CIL Label */
        ;
    }
  while_break___0:;
  }
}

char *dfaexec(struct dfa *d, char const *begin, char *end, int allow_nl, size_t *count, int *backref) {
  state_num s;
  state_num s1;
  unsigned char const *p;
  unsigned char const *mbp;
  state_num **trans___0;

  unsigned char eol;
  unsigned char saved_end;
  size_t nlcount;
  wint_t wc;
  size_t tmp;
  unsigned char const *tmp___0;
  unsigned char const *tmp___1;
  state_num tmp___2;
  unsigned char const *tmp___3;
  unsigned char const *tmp___4;

  {
    eol = eolbyte___0;
    nlcount = (size_t)0;
    if (!d->tralloc) {
      {
      }
    }
    s1 = (state_num)0;

    mbp = (unsigned char const *)begin;
    p = mbp;

    saved_end = *((unsigned char *)end);
    *end = (char)eol;

    {

      /* CIL Label */
      ;

      if (s >= 0L) {

        {
        }

        trans___0 = d->trans;
        goto __Cont;
      }

      s = (state_num)0;
    __Cont:;

      /* CIL Label */
      ;
    }

  done:

    *count += nlcount;

    return ((char *)p);
  }
}

struct dfa *dfasuperset(struct dfa const *d) {

  {
    return ((struct dfa *)d->superset);
  }
}

_Bool dfaisfast(struct dfa const *d) {

  { return ((_Bool)d->fast); }
}

void dfacomp(char const *s, size_t len, struct dfa *d, int searchflag) {

  {
    {

      dfaparse(s, len, d);
      dfamust(d);

      dfaanalyze(d, searchflag);
    }
  }
}
void dfafree(struct dfa *d) {

  {
    {}

    {

      /* CIL Label */
      ;
    }
  while_break: {}

    {

      /* CIL Label */
      ;
    }

    ;
  }
}

static void dfamust(struct dfa *d) {

  int tmp___12;

  {

    {

    while_break___7: /* CIL Label */
        ;
    }
  while_break:;
  done:

  {

    /* CIL Label */
    ;
  }
  while_break___6:;
    return;
  }
}
struct dfa *dfaalloc(void) {
  struct dfa *tmp;

  {
    { tmp = (struct dfa *)xmalloc(sizeof(struct dfa)); }
    return (tmp);
  }
}
struct dfamust *__attribute__((__pure__)) dfamusts(struct dfa const *d) {

  {
    return ((struct dfamust * /* __attribute__((__pure__)) */)((struct dfamust *)d->musts));
  }
}

void kwsinit(kwset_t *kwset___1) {

  {

    {}

    { *kwset___1 = kwsalloc((char const *)((void *)0)); }
  }
}
static char *out;

char *mbtoupper(char const *beg, size_t *n, mb_len_map_t **len_map_p) {

  char const *end;
  char *p;

  {

    if (*n == 0UL) {
      return (out);
    }
    {}
    {

    while_break___0: /* CIL Label */
        ;
    }
  while_break:;

    *n = (size_t)(p - out);
    *p = (char)0;
    return (out);
  }
}

ptrdiff_t mb_goback(char const **mb_start, char const *cur, char const *end) {
  char const *p;

  long tmp___0;

  {
    {}
    {

    while_break___0: /* CIL Label */
        ;
    }
  while_break:
    *mb_start = p;

    return (tmp___0);
  }
}
wint_t mb_prev_wc(char const *buf, char const *cur, char const *end) {

  {

    {}
  }
}
wint_t mb_next_wc(char const *cur, char const *end) {

  unsigned int tmp___0;

  { return (tmp___0); }
}

extern char *optarg;
extern int optind;

static int show_help;
static int show_version;

static int color_option;
static int only_matching;
static int align_tabs;

static char const *filename_color = "35";
static char const *line_num_color = "32";

static char const *sep_color = "36";

static void pr_sgr_start_if(char const *s) {

  {}
}

static struct exclude *excluded_patterns;

static char const short_options[58] = {(char const)'0', (char const)'1', (char const)'2', (char const)'3', (char const)'4', (char const)'5', (char const)'6', (char const)'7', (char const)'8', (char const)'9', (char const)'A', (char const)':', (char const)'B',   (char const)':', (char const)'C',
                                       (char const)':', (char const)'D', (char const)':', (char const)'E', (char const)'F', (char const)'G', (char const)'H', (char const)'I', (char const)'P', (char const)'T', (char const)'U', (char const)'V', (char const)'X',   (char const)':', (char const)'a',
                                       (char const)'b', (char const)'c', (char const)'d', (char const)':', (char const)'e', (char const)':', (char const)'f', (char const)':', (char const)'h', (char const)'i', (char const)'L', (char const)'l', (char const)'m',   (char const)':', (char const)'n',
                                       (char const)'o', (char const)'q', (char const)'R', (char const)'r', (char const)'s', (char const)'u', (char const)'v', (char const)'w', (char const)'x', (char const)'y', (char const)'Z', (char const)'z', (char const)'\000'};
static struct option const long_options[50] = {{"basic-regexp", 0, (int *)((void *)0), 'G'},
                                               {"extended-regexp", 0, (int *)((void *)0), 'E'},
                                               {"fixed-regexp", 0, (int *)((void *)0), 'F'},
                                               {"fixed-strings", 0, (int *)((void *)0), 'F'},
                                               {"perl-regexp", 0, (int *)((void *)0), 'P'},
                                               {"after-context", 1, (int *)((void *)0), 'A'},
                                               {"before-context", 1, (int *)((void *)0), 'B'},
                                               {"binary-files", 1, (int *)((void *)0), 128},
                                               {"byte-offset", 0, (int *)((void *)0), 'b'},
                                               {"context", 1, (int *)((void *)0), 'C'},
                                               {"color", 2, (int *)((void *)0), 129},
                                               {"colour", 2, (int *)((void *)0), 129},
                                               {"count", 0, (int *)((void *)0), 'c'},
                                               {"devices", 1, (int *)((void *)0), 'D'},
                                               {"directories", 1, (int *)((void *)0), 'd'},
                                               {"exclude", 1, (int *)((void *)0), 131},
                                               {"exclude-from", 1, (int *)((void *)0), 132},
                                               {"exclude-dir", 1, (int *)((void *)0), 135},
                                               {"file", 1, (int *)((void *)0), 'f'},
                                               {"files-with-matches", 0, (int *)((void *)0), 'l'},
                                               {"files-without-match", 0, (int *)((void *)0), 'L'},
                                               {"group-separator", 1, (int *)((void *)0), 136},
                                               {"help", 0, &show_help, 1},
                                               {"include", 1, (int *)((void *)0), 130},
                                               {"ignore-case", 0, (int *)((void *)0), 'i'},
                                               {"initial-tab", 0, (int *)((void *)0), 'T'},
                                               {"label", 1, (int *)((void *)0), 134},
                                               {"line-buffered", 0, (int *)((void *)0), 133},
                                               {"line-number", 0, (int *)((void *)0), 'n'},
                                               {"line-regexp", 0, (int *)((void *)0), 'x'},
                                               {"max-count", 1, (int *)((void *)0), 'm'},
                                               {"no-filename", 0, (int *)((void *)0), 'h'},
                                               {"no-group-separator", 0, (int *)((void *)0), 136},
                                               {"no-messages", 0, (int *)((void *)0), 's'},
                                               {"null", 0, (int *)((void *)0), 'Z'},
                                               {"null-data", 0, (int *)((void *)0), 'z'},
                                               {"only-matching", 0, (int *)((void *)0), 'o'},
                                               {"quiet", 0, (int *)((void *)0), 'q'},
                                               {"recursive", 0, (int *)((void *)0), 'r'},
                                               {"dereference-recursive", 0, (int *)((void *)0), 'R'},
                                               {"regexp", 1, (int *)((void *)0), 'e'},
                                               {"invert-match", 0, (int *)((void *)0), 'v'},
                                               {"silent", 0, (int *)((void *)0), 'q'},
                                               {"text", 0, (int *)((void *)0), 'a'},
                                               {"binary", 0, (int *)((void *)0), 'U'},
                                               {"unix-byte-offsets", 0, (int *)((void *)0), 'u'},
                                               {"version", 0, (int *)((void *)0), 'V'},
                                               {"with-filename", 0, (int *)((void *)0), 'H'},
                                               {"word-regexp", 0, (int *)((void *)0), 'w'},
                                               {(char const *)0, 0, (int *)0, 0}};

static char const *filename;
static size_t filename_prefix_len;

static char const *const directories_args[4] = {(char const * /* const  */) "read", (char const * /* const  */) "recurse", (char const * /* const  */) "skip", (char const * /* const  */)((char const *)((void *)0))};
static enum directories_type const directories_types[3] = {(enum directories_type const)2, (enum directories_type const)3, (enum directories_type const)4};
static enum directories_type directories = (enum directories_type)2;
static int fts_options = 793;
static enum __anonenum_devices_71 devices = (enum __anonenum_devices_71)0;
static int grepfile(int dirdesc, char const *name, int follow, int command_line);
static int grepdesc(int desc, int command_line);

static int undossify_input(char *buf, size_t buflen);

static void (*compile)(char const *, size_t);
static size_t (*execute)(char const *, size_t, size_t *, char const *);

static int file_is_binary(char const *buf, size_t bufsize, int fd, struct stat const *st) {

  {

    {}

    {}
  }
}

static int skipped_file(char const *name, int command_line, int is_dir) {

  int tmp___0;
  _Bool tmp___1;
  int tmp___2;
  int tmp___3;

  {
    if (is_dir) {

      tmp___3 = tmp___0;
    } else {

      {}

      tmp___2 = 0;

      tmp___3 = tmp___2;
    }
    return (tmp___3);
  }
}
static char *buffer;
static size_t bufalloc;
static int bufdesc;
static char *bufbeg;
static char *buflim;
static size_t pagesize;
static off_t bufoffset;
static off_t after_last_match;
static int reset(int fd, struct stat const *st) {
  size_t tmp;
  int *tmp___0;
  char *tmp___1;

  {
    if (!pagesize) {
      {
        pagesize = (size_t)getpagesize();
      }
      if (pagesize == 0UL) {
        {
          abort();
        }
      } else {
        if (2UL * pagesize + 1UL <= pagesize) {
          {
            abort();
          }
        }
      }

      tmp = (size_t)32768;

      tmp = 32768UL + (pagesize - 32768UL % pagesize);

      {
        bufalloc = (tmp + pagesize) + 1UL;
        buffer = (char *)xmalloc(bufalloc);
      }
    }

    buflim = buffer + 1;

    buflim = (buffer + 1) + (pagesize - (size_t)(buffer + 1) % pagesize);

    bufbeg = buflim;
    *(bufbeg + -1) = (char)eolbyte;
    bufdesc = fd;

    if (fd != 0) {

    } else {
      { bufoffset = lseek(fd, (__off_t)0, 1); }
      if (bufoffset < 0L) {
        {
          tmp___0 = __errno_location();
          tmp___1 = gettext("lseek failed");
        }
      }
    }

    return (1);
  }
}
static int fillbuf(size_t save, struct stat const *st) {
  ssize_t fillsize;
  int cc;
  char *readbuf;
  size_t readsize;
  size_t saved_offset;
  size_t minsize;
  size_t newsize;
  size_t newalloc;
  char *newbuf;
  off_t to_be_read;
  off_t maxsize_off;
  int tmp;
  void *tmp___0;

  {
    cc = 1;

    if (pagesize <= (size_t)((buffer + bufalloc) - buflim)) {
      readbuf = buflim;
      bufbeg = buflim - save;
    } else {

      newsize = (bufalloc - pagesize) - 1UL;
      {
        while (1) {
          /* CIL Label */
          ;

          if (!(newsize < minsize)) {
            goto while_break;
          }
          if (newsize * 2UL < newsize) {
            {
            }
          } else {
          }
        }
      while_break___0: /* CIL Label */
          ;
      }
    while_break: {}
      if (tmp) {

        maxsize_off = (off_t)(save + (size_t)to_be_read);
      }
      newalloc = (newsize + pagesize) + 1UL;
      if (bufalloc < newalloc) {
        {

          tmp___0 = xmalloc(bufalloc);
          newbuf = (char *)tmp___0;
        }
      } else {
      }

      {
        bufbeg = readbuf - save;
        memmove((void *)bufbeg, (void const *)(buffer + saved_offset), save);
        *(bufbeg + -1) = (char)eolbyte;
      }
    }
    {
      readsize = (size_t)((buffer + bufalloc) - readbuf);

      fillsize = (ssize_t)safe_read(bufdesc, (void *)readbuf, readsize);
    }
    if (fillsize < 0L) {
      cc = 0;
    }
    {
      bufoffset += fillsize;
      fillsize = (ssize_t)undossify_input(readbuf, (size_t)fillsize);
      buflim = readbuf + fillsize;
    }
    return (cc);
  }
}
static enum __anonenum_binary_files_72 binary_files;
static int filename_mask;
static int out_quiet;
static _Bool out_invert;
static int out_file;
static int out_line;
static int out_byte;
static intmax_t out_before;
static intmax_t out_after;
static int count_matches;

static int no_filenames;
static intmax_t max_count;
static int line_buffered;

static uintmax_t totalcc;
static char const *lastnl;
static char const *lastout;

static intmax_t outleft;
static intmax_t pending;
static int done_on_match;

static File_type dos_file_type = (File_type)0;

static int undossify_input(char *buf, size_t buflen) {
  int chars_left;

  {

    if ((unsigned int)dos_file_type == 2U) {

      {

      while_break___1: /* CIL Label */
          ;
      }
    while_break:;
      return (chars_left);
    }
    return ((int)buflen);
  }
}

static void print_filename(void) {

  {
    { fputs_unlocked((char const * /* __restrict  */)filename, (FILE * /* __restrict  */)stdout); }
  }
}
static void print_sep(char sep) {

  {
    { fputc_unlocked((int)sep, stdout); }
  }
}

static void print_line_head(char const *beg, char const *lim, int sep) {
  int pending_sep;

  {
    pending_sep = 0;
    if (out_file) {
      {
        print_filename();
      }
      if (filename_mask) {
        pending_sep = 1;
      } else {
        {}
      }
    }

    if (pending_sep) {
      if (align_tabs) {
        {
        }
      }
      { print_sep((char)sep); }
    }
  }
}

static void prline(char const *beg, char const *lim, int sep) {

  {
    if (!only_matching) {
      {
        print_line_head(beg, lim, sep);
      }
    }

    if (!only_matching) {
      if ((unsigned long)lim > (unsigned long)beg) {
        {
          fwrite_unlocked((void const * /* __restrict  */)((void const *)beg), (size_t)1, (size_t)(lim - beg), (FILE * /* __restrict  */)stdout);
        }
      }
    }
    {}

    {}
  }
}

static _Bool used;
static void prtext(char const *beg, char const *lim) {
  char eol;
  char const *p;

  intmax_t n;
  char const *nl___0;
  char const *tmp___1;

  {

    if (out_invert) {

      {

        /* CIL Label */
        ;

        {
          tmp___1 = (char const *)memchr((void const *)p, (int)eol, (size_t)(lim - p));
          nl___0 = tmp___1;
          nl___0++;
        }

        /* CIL Label */
        ;
      }
    while_break___2:;
    } else {
      if (!out_quiet) {
        {
          prline(beg, lim, ':');
        }
      }
    }

    if (out_quiet) {

    } else {
    }
    used = (_Bool)1;
    outleft -= n;
    return;
  }
}
static size_t do_execute(char const *buf, size_t size, size_t *match_size, char const *start_ptr) {

  char const *line_next;
  size_t tmp;
  size_t tmp___0;

  {
    if ((unsigned long)execute == (unsigned long)(&Fexecute)) {

    } else {
      if ((unsigned long)execute == (unsigned long)(&Pexecute)) {
      _L: { tmp___0 = __ctype_get_mb_cur_max(); }
        if (tmp___0 == 1UL) {
          {
          }

        } else {
        }
      } else {
        { tmp = (*execute)(buf, size, match_size, start_ptr); }
        return (tmp);
      }
    }
    line_next = buf;
    {

      /* CIL Label */
      ;
    }
  while_break:;
  }
}
static intmax_t grepbuf(char const *beg, char const *lim) {

  char const *p;
  char const *endp;
  size_t match_size;
  size_t match_offset;
  size_t tmp;
  char const *b;
  char const *prbeg;
  char const *tmp___0;
  char const *prend;
  char const *tmp___1;

  {

    p = beg;
    {
      while (1) {
        /* CIL Label */
        ;

        if (!((unsigned long)p < (unsigned long)lim)) {
          goto while_break;
        }
        {
          tmp = do_execute(p, (size_t)(lim - p), &match_size, (char const *)((void *)0));
          match_offset = tmp;
        }
        if (match_offset == 0xffffffffffffffffUL) {

          goto while_break;
        }
        b = p + match_offset;
        endp = b + match_size;

        if (!out_invert) {
          goto _L___0;
        } else {
          if ((unsigned long)p < (unsigned long)b) {
          _L___0:
            if (out_invert) {

            } else {
              tmp___0 = b;
            }
            prbeg = tmp___0;

            tmp___1 = endp;

            {
              prend = tmp___1;
              prtext(prbeg, prend);
            }
          }
        }
        p = endp;
      }
      /* CIL Label */
      ;
    }
  while_break:;
  }
}
static intmax_t grep(int fd, struct stat const *st) {
  intmax_t nlines;
  intmax_t i;
  int not_text;

  size_t save;
  char oldc;
  char *beg;
  char *lim;
  char eol;
  int tmp;

  int tmp___1;
  int tmp___2;
  int tmp___3;
  intmax_t tmp___4;

  int tmp___6;

  intmax_t tmp___8;

  {
    {
      eol = (char)eolbyte;
      tmp = reset(fd, st);
    }

    {

      outleft = max_count;

      pending = (intmax_t)0;
      nlines = (intmax_t)0;

      save = (size_t)0;
      tmp___1 = fillbuf(save, st);
    }
    if (!tmp___1) {
      {
      }
      return ((intmax_t)0);
    }
    if ((unsigned int)binary_files == 0U) {
      if (!out_quiet) {
        goto _L;
      } else {
        goto _L___0;
      }
    } else {
    _L___0:
      if ((unsigned int)binary_files == 2U) {
      _L: { tmp___2 = file_is_binary((char const *)bufbeg, (size_t)(buflim - bufbeg), fd, st); }
        if (tmp___2) {

        } else {
          tmp___3 = 0;
        }
      } else {
        tmp___3 = 0;
      }
    }
    not_text = tmp___3;

    done_on_match += not_text;
    out_quiet += not_text;
    {
      while (1) {
        /* CIL Label */
        ;
        lastnl = (char const *)bufbeg;
        if (lastout) {
        }
        beg = bufbeg + save;
        if ((unsigned long)beg == (unsigned long)buflim) {
          goto while_break;
        }
        {

          lim = (char *)memrchr((void const *)(beg - 1), (int)eol, (size_t)((buflim - beg) + 1L));
          lim++;
          *(beg + -1) = oldc;
        }
        if ((unsigned long)lim == (unsigned long)beg) {
        }

        {
          tmp___4 = grepbuf((char const *)beg, (char const *)lim);
          nlines += tmp___4;
        }

        beg = lim;
        {
          while (1) {
            /* CIL Label */
            ;

            if (i < out_before) {

            } else {
              goto while_break___0;
            }
            i++;
            {

              /* CIL Label */
              ;
            }
          while_break___1:;
          }
        while_break___3: /* CIL Label */
            ;
        }
      while_break___0:;

        { tmp___6 = fillbuf(save, st); }

      }
      /* CIL Label */
      ;
    }
  while_break:;

  finish_grep:
    done_on_match -= not_text;
  }
}
static int grepdirent(FTS *fts, FTSENT *ent, int command_line) {
  int follow;
  int dirdesc;
  struct stat *st;
  int tmp;
  int tmp___0;
  int tmp___1;

  struct stat st1;
  int flag;
  int tmp___4;
  int *tmp___5;

  int tmp___8;

  char *__cil_tmp23;
  char *__cil_tmp24;

  {
    st = ent->fts_statp;

    if ((int)ent->fts_info == 6) {

      return (1);
    }
    if ((int)ent->fts_info == 1) {

    } else {

      tmp = 0;
    }
    { tmp___0 = skipped_file((char const *)(ent->fts_name), command_line, tmp); }
    if (tmp___0) {
      {
      }
    }
    filename = (char const *)(ent->fts_path + filename_prefix_len);

    follow = tmp___1;

    goto case_1;

    if ((int)ent->fts_info == 3) {
    }

    goto case_12;

  case_1:

    out_file |= 2 * !no_filenames;

    {}

  case_2:

  {}

  case_3:

  case_12:

  switch_default: {}
  switch_break:;

    dirdesc = fts->fts_cwd_fd;

    { tmp___8 = grepfile(dirdesc, (char const *)ent->fts_accpath, follow, command_line); }
    return (tmp___8);
  }
}
static int grepfile(int dirdesc, char const *name, int follow, int command_line) {
  int desc;
  int tmp;
  int tmp___0;

  int tmp___4;

  {

    {
      tmp___0 = openat_safer(dirdesc, name, tmp);
      desc = tmp___0;
    }

    { tmp___4 = grepdesc(desc, command_line); }
  }
}
static int grepdesc(int desc, int command_line) {
  intmax_t count;
  int status;
  struct stat st;

  int tmp___0;

  FTS *fts;
  FTSENT *ent;
  int opts;
  int tmp___2;
  char *fts_arg[2];

  int tmp___4;
  int tmp___5;

  {
    { tmp___0 = fstat(desc, &st); }

    if ((st.st_mode & 61440U) == 16384U) {

      {
        opts = fts_options & ~tmp___2;
        tmp___4 = close(desc);
      }

      {
        fts_arg[0] = (char *)filename;
        fts_arg[1] = (char *)((void *)0);
        fts = fts_open((char *const *)(fts_arg), opts, (int (*)(FTSENT const **, FTSENT const **))((void *)0));
      }

      {
        while (1) {
          /* CIL Label */
          ;
          { ent = fts_read(fts); }
          if (!ent) {
            goto while_break;
          }
          {
            tmp___5 = grepdirent(fts, ent, command_line);
            status &= tmp___5;
          }
        }
        /* CIL Label */
        ;
      }
    while_break: {}

      {}
    }

    {}

    { count = grep(desc, (struct stat const *)(&st)); }

    status = !count;

  closeout:

    return (status);
  }
}
static int grep_command_line_arg(char const *arg) {

  int tmp___0;
  int tmp___1;
  int tmp___2;

  {
    {}
    if (tmp___2 == 0) {

      {
        tmp___0 = grepdesc(0, 1);
      }
      return (tmp___0);
    } else {
      {
        filename = arg;
        tmp___1 = grepfile(-100, arg, 1, 1);
      }
      return (tmp___1);
    }
  }
}

void usage(int status) {

  {

    { exit(status); }
  }
}
static void Gcompile(char const *pattern, size_t size) {

  {
    {
      GEAcompile(pattern, size,
                 (((((1UL << 1) | ((1UL << 1) << 1)) | ((((((((1UL << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1)) | (((((((((1UL << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1)) | (((((((((((1UL << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1)) |
                     ((((((((((((((((1UL << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1) << 1));
    }
  }
}
static void Ecompile(char const *pattern, size_t size) {

  {
    {}
  }
}
static void Acompile(char const *pattern, size_t size) {

  {
    {}
  }
}
static void GAcompile(char const *pattern, size_t size) {

  {
    {}
  }
}
static void PAcompile(char const *pattern, size_t size) {

  {
    {}
  }
}
static struct matcher const matchers[8] = {{{(char const)'g', (char const)'r', (char const)'e', (char const)'p', (char const)'\000'}, &Gcompile, &EGexecute},
                                           {{(char const)'e', (char const)'g', (char const)'r', (char const)'e', (char const)'p', (char const)'\000'}, &Ecompile, &EGexecute},
                                           {{(char const)'f', (char const)'g', (char const)'r', (char const)'e', (char const)'p', (char const)'\000'}, &Fcompile, &Fexecute},
                                           {{(char const)'a', (char const)'w', (char const)'k', (char const)'\000'}, &Acompile, &EGexecute},
                                           {{(char const)'g', (char const)'a', (char const)'w', (char const)'k', (char const)'\000'}, &GAcompile, &EGexecute},
                                           {{(char const)'p', (char const)'o', (char const)'s', (char const)'i', (char const)'x', (char const)'a', (char const)'w', (char const)'k', (char const)'\000'}, &PAcompile, &EGexecute},
                                           {{(char const)'p', (char const)'e', (char const)'r', (char const)'l', (char const)'\000'}, &Pcompile, &Pexecute},
                                           {{(char const)'\000'}, (void (*)(char const *, size_t))((void *)0), (size_t(*)(char const *, size_t, size_t *, char const *))((void *)0)}};

static int get_nondigit_option(int argc, char *const *argv, intmax_t *default_context) {

  int opt;

  {

    {

      /* CIL Label */
      ;
      { opt = getopt_long(argc, (char *const *)((char **)argv), short_options, long_options, (int *)((void *)0)); }

      goto while_break;

      goto while_break;

      /* CIL Label */
      ;
    }
  while_break:;

    return (opt);
  }
}

int main(int argc, char **argv) {
  char *keys;
  size_t keycc;

  int with_filenames;

  int opt;
  int status;

  intmax_t default_context;

  ptrdiff_t tmp___3;

  int tmp___27;

  int tmp___37;

  int tmp___42;
  int tmp___43;

  {
    {

      eolbyte = (unsigned char)'\n';
      filename_mask = ~0;

      out_before = (intmax_t)-1;
      out_after = out_before;

      compile = (void (*)(char const *, size_t))matchers[0].compile;
      execute = (size_t(*)(char const *, size_t, size_t *, char const *))matchers[0].execute;
    }
    {
      while (1) {
        /* CIL Label */
        ;
        { opt = get_nondigit_option(argc, (char *const *)argv, &default_context); }
        if (!(opt != -1)) {
          goto while_break;
        }

        goto case_114;

      case_65: {}

      case_66: {}

        {}

        {}

        goto switch_break;
      case_69: { setmatcher("egrep"); }
        goto switch_break;
      case_70: { setmatcher("fgrep"); }
        goto switch_break;
      case_80: { setmatcher("perl"); }
        goto switch_break;
      case_71: { setmatcher("grep"); }
        goto switch_break;
      case_88: { setmatcher((char const *)optarg); }
        goto switch_break;
      case_72:
        with_filenames = 1;
        no_filenames = 0;
        goto switch_break;
      case_73:
        binary_files = (enum __anonenum_binary_files_72)2;
        goto switch_break;
      case_84:
        align_tabs = 1;
        goto switch_break;
      case_85: { dos_binary(); }
        goto switch_break;
      case_117: { dos_unix_byte_offsets(); }
        goto switch_break;
      case_86:
        show_version = 1;
        goto switch_break;
      case_97:
        binary_files = (enum __anonenum_binary_files_72)1;
        goto switch_break;
      case_98:
        out_byte = 1;
        goto switch_break;
      case_99:
        count_matches = 1;
        goto switch_break;
      case_100: {
        tmp___3 = __xargmatch_internal("--directories", (char const *)optarg, directories_args, (char const *)(directories_types), sizeof(directories_types[0]), argmatch_die);
        directories = (enum directories_type)directories_types[tmp___3];
      }

      case_101: {}

        {}

        {

          /* CIL Label */
          ;
        }
        {}
        {

          /* CIL Label */
          ;
        }
        {}

      case_105:

      case_76:

      {}

      case_0:

      switch_default: {}

      ;

      case_110:

      case_113:

      case_114:
        directories = (enum directories_type)3;

      case_115:

      case_118:

      case_128: {}

        goto switch_break;
      case_129:

        goto switch_break;
      case_131:

      {
        add_exclude(excluded_patterns, (char const *)optarg, (1 << 28) | tmp___27);
      }
        goto switch_break;
      case_132:

      {}

      case_135:

      {}

      case_136:

      case_134:

      {}

      switch_break:;
      }
      /* CIL Label */
      ;
    }
  while_break:;

    { init_colorize(); }

    {}

    {
      keycc = strlen((char const *)*(argv + optind));
      tmp___37 = optind;
      optind++;
      keys = (char *)xmemdup((void const *)*(argv + tmp___37), keycc + 1UL);
    }

    {}

    {}

    { (*compile)((char const *)keys, keycc); }
    if (argc - optind > 1) {

      out_file = 1;

    } else {
    _L___0:
      if (with_filenames) {
      }
    }
    {}

    {
      while (1) {
        /* CIL Label */
        ;
        {
          tmp___42 = grep_command_line_arg((char const *)*(argv + optind));
          status &= tmp___42;
          optind++;
        }
        if (!(optind < argc)) {
          goto while_break___2;
        }
      }
      /* CIL Label */
      ;
    }
  while_break___2:;

    tmp___43 = status;

    { exit(tmp___43); }
  }
}