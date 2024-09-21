typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;

typedef int __pid_t;
typedef long __time_t;

typedef long __blksize_t;
typedef long __blkcnt_t;
typedef long __ssize_t;
typedef long __syscall_slong_t;
typedef __mode_t mode_t;
typedef __off_t off_t;
typedef __pid_t pid_t;
typedef __ssize_t ssize_t;
typedef __time_t time_t;

typedef unsigned long size_t;
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

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

typedef unsigned long uintmax_t;
struct posix_header {
  char name[100];
  char mode[8];
  char uid[8];
  char gid[8];
  char size[12];
  char mtime[12];
  char chksum[8];
  char typeflag;

  char uname[32];
  char gname[32];
  char devmajor[8];
  char devminor[8];
};

struct tar_stat_info {
  char *orig_file_name;
  char *file_name;

  unsigned int devminor;
  unsigned int devmajor;
  char *uname;
  char *gname;
  struct stat stat;
  unsigned long atime_nsec;
  unsigned long mtime_nsec;
  unsigned long ctime_nsec;
  off_t archive_file_size;
  _Bool is_sparse;
  size_t sparse_map_avail;
  size_t sparse_map_size;
  struct sp_array *sparse_map;
};
union block {
  char buffer[512];
  struct posix_header header;
};

enum subcommand {
  UNKNOWN_SUBCOMMAND = 0,
  APPEND_SUBCOMMAND = 1,
  CAT_SUBCOMMAND = 2,
  CREATE_SUBCOMMAND = 3,
  DELETE_SUBCOMMAND = 4,
  DIFF_SUBCOMMAND = 5,
  EXTRACT_SUBCOMMAND = 6,
  LIST_SUBCOMMAND = 7,
  UPDATE_SUBCOMMAND = 8
};
enum access_mode { ACCESS_READ = 0, ACCESS_WRITE = 1, ACCESS_UPDATE = 2 };
typedef __dev_t dev_t;

enum archive_format {
  DEFAULT_FORMAT = 0,
  V7_FORMAT = 1,
  OLDGNU_FORMAT = 2,
  USTAR_FORMAT = 3,
  POSIX_FORMAT = 4,
  STAR_FORMAT = 5,
  GNU_FORMAT = 6
};
enum read_header {
  HEADER_STILL_UNREAD = 0,
  HEADER_SUCCESS = 1,
  HEADER_SUCCESS_EXTENDED = 2,
  HEADER_ZERO_BLOCK = 3,
  HEADER_END_OF_FILE = 4,
  HEADER_FAILURE = 5
};

typedef __gid_t gid_t;
typedef __uid_t uid_t;

struct name {
  struct name *next;
  size_t length;
  uintmax_t found_count;

  char firstch;
  char regexp;
  int change_dir;
  char const *dir_contents;

  char name[1];
};
enum dump_status {
  dump_status_ok = 0,
  dump_status_short = 1,
  dump_status_fail = 2,
  dump_status_not_implemented = 3
};

typedef struct hash_tuning Hash_tuning;

typedef struct hash_table Hash_table;

enum old_files {
  DEFAULT_OLD_FILES = 0,
  NO_OVERWRITE_DIR_OLD_FILES = 1,
  OVERWRITE_OLD_FILES = 2,
  UNLINK_FIRST_OLD_FILES = 3,
  KEEP_OLD_FILES = 4,
  KEEP_NEWER_FILES = 5
};
enum remove_option {
  ORDINARY_REMOVE_OPTION = 0,
  RECURSIVE_REMOVE_OPTION = 1,
  WANT_DIRECTORY_REMOVE_OPTION = 2
};

enum strtol_error {
  LONGINT_OK = 0,
  LONGINT_OVERFLOW = 1,
  LONGINT_INVALID_SUFFIX_CHAR = 2,
  LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
  LONGINT_INVALID = 4
};
typedef enum strtol_error strtol_error;

enum quoting_style {
  literal_quoting_style = 0,
  shell_quoting_style = 1,
  shell_always_quoting_style = 2,
  c_quoting_style = 3,
  escape_quoting_style = 4,
  locale_quoting_style = 5,
  clocale_quoting_style = 6
};

enum backup_type { none = 0, simple = 1, numbered_existing = 2, numbered = 3 };

struct passwd {
  char *pw_name;
};
struct group {
  char *gr_name;
};

typedef int __daddr_t;
typedef void (*__sighandler_t)(int);

enum sparse_scan_state { scan_begin = 0, scan_block = 1, scan_end = 2 };
struct tar_sparse_optab {};
struct tar_sparse_file {

  size_t dumped_size;
  struct tar_stat_info *stat_info;
};

struct option {};
struct fmttab {};
typedef void *iconv_t;
struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
};

typedef struct __dirstream DIR;

struct lconv {
  char *decimal_point;
};

struct quoting_options {
  enum quoting_style style;
};

/* #pragma merger("0","000.buffer.o.i","") */

extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) valloc)(
    size_t __size) __attribute__((__malloc__));

void *xmalloc(size_t n);
char *xstrdup(char const *string);

size_t safe_read(int fd, void *buf, size_t count);

int blocking_factor;
size_t record_size;
_Bool backup_option;

_Bool read_full_records_option;

_Bool to_stdout_option;
_Bool totals_option;
int verbose_option;
_Bool verify_option;
char const *volno_file_option;
char const *volume_label_option;
int archive;
_Bool dev_null_output;
struct timespec start_timespec;

char const **archive_name_array;
int archive_names;
char const **archive_name_cursor;

enum access_mode access_mode;
FILE *stdlis;

void flush_archive(void);

void assign_string(char **string, char const *value);

char *safer_name_suffix(char const *file_name, _Bool link_target);

size_t sys_write_archive_buffer(void);

union block *record_start;
union block *record_end;
union block *current_block;

union block *find_next_block(void) {

  {
    if ((unsigned long)current_block == (unsigned long)record_end) {

      {
        flush_archive();
      }
    }
    return (current_block);
  }
}
void set_next_block_after(union block *block) {

  {
    {
      while (1) {
        /* CIL Label */
        ;
        if (!((unsigned long)block >= (unsigned long)current_block)) {
          goto while_break;
        }
        current_block++;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
size_t available_space_after(union block *pointer) {

  { return ((size_t)(record_end->buffer - pointer->buffer)); }
}

void open_archive(enum access_mode wanted_access) {

  char *tmp;
  char *tmp___0;
  void *tmp___1;
  void *tmp___2;
  char *tmp___3;
  int tmp___4;
  char *tmp___5;
  int tmp___7;

  void *tmp___9;
  int tmp___11;

  void *tmp___13;

  int tmp___16;
  void *tmp___17;
  int tmp___19;

  void *tmp___21;
  int tmp___22;

  int *tmp___23;
  int *tmp___24;
  _Bool tmp___25;
  union block *label;
  union block *tmp___26;

  unsigned int tmp___33;

  {

    {}

    {}

    {
      tmp___2 = valloc(record_size);
      record_start = (union block *)tmp___2;
    }

    current_block = record_start;
    record_end = record_start + blocking_factor;

    access_mode = (enum access_mode)tmp___33;

    {

    case_0: { /* CIL Label */
    }

    case_1: { /* CIL Label */
    }

    case_2: { /* CIL Label */
    }

    switch_break: /* CIL Label */
        ;
    }

    {}

    {

    case_0___0: /* CIL Label */

    case_1___0: /* CIL Label */

    case_2___0: /* CIL Label */

    switch_break___0: /* CIL Label */
        ;
    }

    {

      goto case_1___1;

    case_0___1: /* CIL Label */

      goto switch_break___1;
    case_1___1: /* CIL Label */

    {}

      {
        tmp___16 = creat(*(archive_name_array + 0),
                         (mode_t)(((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                  ((256 | (256 >> 3)) | ((256 >> 3) >> 3))));
        archive = tmp___16;
      }

      {
        tmp___16 = creat(*(archive_name_array + 0),
                         (mode_t)(((128 | (128 >> 3)) | ((128 >> 3) >> 3)) |
                                  ((256 | (256 >> 3)) | ((256 >> 3) >> 3))));
        archive = tmp___16;
      }

      goto switch_break___1;
    case_2___1: /* CIL Label */

      goto switch_break___1;
    switch_break___1: /* CIL Label */
        ;
    }

    {}
    {

    case_2___2: /* CIL Label */

    case_0___2: { /* CIL Label */
    }

    case_1___2: /* CIL Label */

      goto switch_break___2;
    switch_break___2: /* CIL Label */
        ;
    }
    return;
  }
}
void flush_write(void) {

  size_t tmp___1;

  {

  _L___0: /* CIL Label */

  {
    tmp___1 = sys_write_archive_buffer();
  }

    {}

    {}

    return;
  }
}

void archive_write_error(ssize_t status) {

  {

    {}
  }
}

void flush_archive(void) {

  {

    current_block = record_start;

    {

      { /* CIL Label */
      }

      { /* CIL Label */
        flush_write();
      }

      {
          /* CIL Label */

      } /* CIL Label */
      ;
    }
  }
}
static void backspace_output(void) {

  off_t position;

  off_t tmp___8;

  {

    {}

    position = tmp___8;
    position = (off_t)((size_t)position - record_size);
  }
}
void close_archive(void) {

  union block *tmp___2;

  {

    {}

    { flush_archive(); }

    {}

    {}

    tmp___2 = record_start;

    { free((void *)tmp___2); }
    return;
  }
}

static FILE *read_file;
static int looped;
static _Bool new_volume(enum access_mode mode) {

  int tmp___31;

  {

    { tmp___31 = strcmp(*(archive_name_cursor + 0), "-"); }
  }
}
/* #pragma merger("0","001.compare.o.i","") */

_Bool dereference_option;

int deref_stat(_Bool deref, char const *name, struct stat *buf);

/* #pragma merger("0","002.create.o.i","") */

char *savedir(char const *dir);

enum archive_format archive_format;

_Bool interactive_option;

struct mode_change *mode_option;

int recursion_option;

_Bool sparse_option;

void dump_file(char *p, int top_level, dev_t parent_device);

char *name_next(int change_dirs);

static void to_octal(uintmax_t value, char *where, size_t size) {
  uintmax_t v;
  size_t i;

  {
    v = value;
    i = size;
    {
      while (1) {
        /* CIL Label */
        ;
        i--;
        *(where + i) = (char)(48UL + (v & (unsigned long)((1 << 3) - 1)));
        v >>= 3;
        if (!i) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
  }
}

static void to_chars(int negative, uintmax_t value, size_t valsize,
                     uintmax_t (*substitute)(int *), char *where, size_t size,
                     char const *type) {
  int base256_allowed;

  int tmp___8;

  {

    base256_allowed = tmp___8;

    { to_octal(value, where, size - 1UL); }

  _L___5: /* CIL Label */

    return;
  }
}
static gid_t gid_nobody;

void off_to_chars(off_t v, char *p, size_t s) {

  {
    {
      to_chars(v < 0L, (uintmax_t)v, sizeof(v), (uintmax_t(*)(int *))0, p, s,
               "off_t");
    }
  }
}

void time_to_chars(time_t v, char *p, size_t s) {

  {
    {}
  }
}

void uintmax_to_chars(uintmax_t v, char *p, size_t s) {

  {
    { to_chars(0, v, sizeof(v), (uintmax_t(*)(int *))0, p, s, "uintmax_t"); }
  }
}

_Bool file_dumpable_p(struct tar_stat_info *st) {
  int tmp;

  { return ((_Bool)tmp); }
}
void write_eot(void) {
  union block *pointer;
  union block *tmp;

  {
    {
      tmp = find_next_block();
      pointer = tmp;
      memset((void *)(pointer->buffer), 0, (size_t)512);
    }
  }
}
static void tar_copy_str(char *dst, char const *src, size_t len) {

  {
    {

      strncpy((char * /* __restrict  */)dst,
              (char const * /* __restrict  */)src, len);
    }
  }
}

static union block *write_short_name(struct tar_stat_info *st) {
  union block *header;
  union block *tmp;

  {
    {
      tmp = find_next_block();
      header = tmp;
      memset((void *)(header->buffer), 0, sizeof(union block));
      tar_copy_str(header->header.name, (char const *)st->file_name,
                   (size_t)100);
    }
    return (header);
  }
}

static union block *write_header_name(struct tar_stat_info *st) {

  union block *tmp___1;
  size_t tmp___2;

  {

    {}

  _L: { tmp___2 = strlen((char const *)st->file_name); }

    {}

    { tmp___1 = write_short_name(st); }
    return (tmp___1);
  }
}
union block *start_header(struct tar_stat_info *st) {
  union block *header;

  int tmp___4;

  {
    { header = write_header_name(st); }

    {
      off_to_chars(st->stat.st_size, header->header.size,
                   sizeof(header->header.size));
    }

    {
      time_to_chars(st->stat.st_mtim.tv_sec, header->header.mtime,
                    sizeof(header->header.mtime));
    }

    tmp___4 = '0';

    header->header.typeflag = (char)tmp___4;
    {

      /* CIL Label */

      /* CIL Label */
      { /* CIL Label */
      }

      /* CIL Label */
      { /* CIL Label */
      }

      {
          /* CIL Label */

      } /* CIL Label */
      ;
    }

    return (header);
  }
}
void simple_finish_header(union block *header) {
  size_t i;
  int sum;
  char *p;
  char *tmp;
  size_t tmp___0;

  {
    {
      memcpy((void * /* __restrict  */)(header->header.chksum),
             (void const * /* __restrict  */) "        ",
             sizeof(header->header.chksum));

      p = header->buffer;
      i = sizeof(*header);
    }
    {
      while (1) {
        /* CIL Label */
        ;
        tmp___0 = i;
        i--;
        if (!(tmp___0 != 0UL)) {
          goto while_break;
        }
        tmp = p;
        p++;
        sum += 255 & (int)*tmp;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      uintmax_to_chars((uintmax_t)sum, header->header.chksum, (size_t)7);
      set_next_block_after(header);
    }
  }
}
void finish_header(struct tar_stat_info *st, union block *header,
                   off_t block_ordinal) {

  {

    { simple_finish_header(header); }
  }
}
void pad_archive(off_t size_left) {

  {
    {

      /* CIL Label */
      ;
    }
  }
}
static enum dump_status dump_regular_file(int fd, struct tar_stat_info *st) {
  off_t size_left;
  off_t block_ordinal;
  union block *blk;
  size_t bufsize;
  size_t count;
  size_t tmp;

  {
    {
      size_left = st->stat.st_size;

      blk = start_header(st);
    }

    { finish_header(st, blk, block_ordinal); }
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(size_left > 0L)) {
          goto while_break;
        }

        {
          blk = find_next_block();
          bufsize = available_space_after(blk);
        }
        if ((size_t)size_left < bufsize) {
          bufsize = (size_t)size_left;
        }

        {
          tmp = safe_read(fd, (void *)(blk->buffer), bufsize);
          count = tmp;
        }

        if (count == 0xffffffffffffffffUL) {
          {
          }
          return ((enum dump_status)1);
        }
        {
          size_left = (off_t)((size_t)size_left - count);
          set_next_block_after(blk + (bufsize - 1UL) / 512UL);
        }
      }
    while_break: /* CIL Label */
        ;
    }
  }
}

static void dump_dir0(char *directory, struct tar_stat_info *st, int top_level,
                      dev_t parent_device) {
  dev_t our_device;

  char const *entry;
  size_t entry_len;
  char *name_buf;
  char *tmp___4;
  size_t name_size;
  size_t tmp___5;
  size_t name_len;

  {
    {}

    {
      tmp___4 = strdup((char const *)st->orig_file_name);
      name_buf = tmp___4;
      tmp___5 = strlen((char const *)name_buf);
      name_size = tmp___5;
      name_len = name_size;
      entry = (char const *)directory;
    }
    {
      while (1) {
        /* CIL Label */
        ;
        { entry_len = strlen(entry); }
        if (!(entry_len != 0UL)) {
          goto while_break___1;
        }

        {
          strcpy((char * /* __restrict  */)(name_buf + name_len),
                 (char const * /* __restrict  */)entry);
        }

        { dump_file(name_buf, 0, our_device); }

        entry += entry_len + 1UL;
      }
    while_break___1: /* CIL Label */
        ;
    }
    {}
  }
}
static void ensure_slash(char **pstr) {
  size_t len;
  size_t tmp;

  size_t tmp___1;

  {
    {
      tmp = strlen((char const *)*pstr);
      len = tmp;
    }
    {

    while_break: /* CIL Label */
        ;
    }

    tmp___1 = len;
    len++;
    *(*pstr + tmp___1) = (char)'/';
    *(*pstr + len) = (char)'\000';
  }
}
static _Bool dump_dir(struct tar_stat_info *st, int top_level,
                      dev_t parent_device) {
  char *directory;

  {
    { directory = savedir((char const *)st->orig_file_name); }
    if (!directory) {
      {
      }
      return ((_Bool)0);
    }
    {
      ensure_slash(&st->orig_file_name);
      ensure_slash(&st->file_name);
      dump_dir0(directory, st, top_level, parent_device);
    }
  }
}
void create_archive(void) {
  char *p;

  {
    { open_archive((enum access_mode)1); }

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

    {
      while (1) {
        /* CIL Label */
        ;
        { p = name_next(1); }
        if (!((unsigned long)p != (unsigned long)((void *)0))) {
          goto while_break___4;
        }
        {}

        { dump_file(p, 1, (dev_t)0); }
      }
    while_break___4: /* CIL Label */
        ;
    }

    {
      write_eot();
      close_archive();
    }
  }
}

static void dump_file0(struct tar_stat_info *st, char *p, int top_level,
                       dev_t parent_device) {

  char *tmp___0;
  int tmp___1;

  int fd;
  enum dump_status status;

  _Bool tmp___11;

  {

    {
      assign_string(&st->orig_file_name, (char const *)p);
      tmp___0 = safer_name_suffix((char const *)p, (_Bool)0);
      assign_string(&st->file_name, (char const *)tmp___0);
      tmp___1 = deref_stat(dereference_option, (char const *)p, &st->stat);
    }
    if (tmp___1 != 0) {
      {
      }
    }
    {}

    {}

    { dump_dir(st, top_level, parent_device); }

    {}

    {}

  _L___6: { /* CIL Label */
    tmp___11 = file_dumpable_p(st);
  }
    if (tmp___11) {
      {
        fd = open((char const *)st->orig_file_name, 0);
      }

    } else {
      fd = -1;
    }

    {}

    { status = dump_regular_file(fd, st); }

    {

      /* CIL Label */

      {}

      /* CIL Label */

      {}

      { /* CIL Label */
      }

      {
          /* CIL Label */

      } /* CIL Label */
      ;
    }

    {}

    {}

    {}
  }
}
void dump_file(char *p, int top_level, dev_t parent_device) {
  struct tar_stat_info st;

  {
    { dump_file0(&st, p, top_level, parent_device); }
  }
}
/* #pragma merger("0","003.delete.o.i","") */

/* #pragma merger("0","004.extract.o.i","") */

size_t full_write(int fd, void const *buf, size_t count);
_Bool absolute_names_option;
enum old_files old_files_option;

int same_owner_option;
int same_permissions_option;
size_t strip_path_elements;

void extract_finish(void) {

  {
    {}
  }
}

void fatal_exit(void) {

  {
    {}
  }
}
/* #pragma merger("0","005.xheader.o.i","") */

strtol_error xstrtoumax(char const *s, char **ptr, int strtol_base,
                        uintmax_t *val, char const *valid_suffixes);

char *xheader_xhdr_name(struct tar_stat_info *st) {

  {

    {}
  }
}

void xheader_write(char type, char *name, struct xheader *xhdr) {

  {
    {}
    {

      /* CIL Label */
      ;
    }
    {}
  }
}
void xheader_write_global(void) {

  {

    {}
    {

      /* CIL Label */
      ;
    }
    {}
  }
}

static _Bool xheader_protected_keyword_p(char const *keyword) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}

void xheader_decode(struct tar_stat_info *st) {

  {
    {}

    {}
  }
}

void xheader_store(char const *keyword, struct tar_stat_info const *st,
                   void *data) {

  {

    {}

    {}

    {}
  }
}

void xheader_finish(struct xheader *xhdr) {

  {

    {

      /* CIL Label */
      ;
    }

    {}
  }
}

static void code_string(char const *string, char const *keyword,
                        struct xheader *xhdr) {

  {
    {}

    {}
  }
}

/* #pragma merger("0","006.incremen.o.i","") */

char *get_directory_contents(char *path, dev_t device) {

  char *buffer___2;

  {
    {}

    return (buffer___2);
  }
}
static FILE *listed_incremental_stream;

void write_directory_file(void) {

  {

    {}

    {}

    {}

    {}

    {}
  }
}
void gnu_restore(char const *directory_name) {

  {
    {}

    {}
    {

      /* CIL Label */
      ;
    }

    {

      /* CIL Label */
      ;
    }
    {}
  }
}
/* #pragma merger("0","007.list.o.i","") */

_Bool utc_option;
_Bool block_number_option;

mode_t mode_from_header(char const *p, size_t s);

time_t time_from_header(char const *p, size_t s);

enum read_header read_header(_Bool raw_extended_headers) {

  {

    {

    while_break: /* CIL Label */
        ;
    }
  }
}
void decode_header(union block *header, struct tar_stat_info *stat_info,
                   enum archive_format *format_pointer, int do_user_group) {
  enum archive_format format;

  int tmp___1;
  int tmp___2;

  {
    {}

    {
      *format_pointer = format;
      stat_info->stat.st_mode = mode_from_header(
          (char const *)(header->header.mode), sizeof(header->header.mode));
      stat_info->stat.st_mtim.tv_sec = time_from_header(
          (char const *)(header->header.mtime), sizeof(header->header.mtime));
      assign_string(&stat_info->uname, (char const *)(header->header.uname));
      assign_string(&stat_info->gname, (char const *)(header->header.gname));
      tmp___1 = major_from_header((char const *)(header->header.devmajor),
                                  sizeof(header->header.devmajor));
      stat_info->devmajor = (unsigned int)tmp___1;
      tmp___2 = minor_from_header((char const *)(header->header.devminor),
                                  sizeof(header->header.devminor));
      stat_info->devminor = (unsigned int)tmp___2;
      stat_info->stat.st_atim.tv_sec = start_timespec.tv_sec;
      stat_info->stat.st_ctim.tv_sec = start_timespec.tv_sec;
    }

    {}
  }
}

int major_from_header(char const *p, size_t s) {

  {
    {}
  }
}
int minor_from_header(char const *p, size_t s) {

  {
    {}
  }
}
mode_t mode_from_header(char const *p, size_t s) {

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
  int tmp___11;

  {
    {}

    return (
        (mode_t)(((((((((((tmp___0 | tmp___1) | tmp___2) | tmp___3) | tmp___4) |
                       tmp___5) |
                      tmp___6) |
                     tmp___7) |
                    tmp___8) |
                   tmp___9) |
                  tmp___10) |
                 tmp___11));
  }
}
off_t off_from_header(char const *p, size_t s) {

  {
    {}
  }
}

time_t time_from_header(char const *p, size_t s) {

  {
    {}
  }
}

uintmax_t uintmax_from_header(char const *p, size_t s) {

  {
    {}
  }
}
char *stringify_uintmax_t_backwards(uintmax_t o___0, char *buf) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
static char buffer[27UL];
char const *tartime(time_t t) {
  char *p;
  struct tm *tm;

  struct tm *tmp___1;
  uintmax_t tmp___2;

  {

    tm = tmp___1;

    { p = stringify_uintmax_t_backwards(tmp___2, buffer + sizeof(buffer)); }

    {

      /* CIL Label */
      ;
    }
  }
}

void print_header(struct tar_stat_info *st, off_t block_ordinal) {

  {

    {}
  }
}
void print_for_mkdir(char *pathname, int length, mode_t mode) {

  {}
}
void skip_file(off_t size) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
void skip_member(void) {

  {
    {}
  }
}
/* #pragma merger("0","008.mangle.o.i","") */

void extract_mangle(void) {

  {
    {}

    {

      /* CIL Label */
      ;
    }
    {

      /* CIL Label */
      ;
    }
  }
}
/* #pragma merger("0","009.misc.o.i","") */

void assign_string(char **string, char const *value) {
  char *tmp;

  {

    {
      tmp = xstrdup(value);
      *string = tmp;
    }

    return;
  }
}
char *quote_copy_string(char const *string) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
int unquote_string(char *string) {

  {

    {

    while_break: /* CIL Label */
        ;
    }
  }
}

int remove_any_file(char const *path, enum remove_option option) {

  int tmp___5;

  {

    {}

    {}
    {

      /* CIL Label */

      return (tmp___5);
    case_0:    /* CIL Label */
    case_17:   /* CIL Label */
    case_39: { /* CIL Label */

      /* CIL Label */

      /* CIL Label */

      { /* CIL Label */
      }

      {

        /* CIL Label */
        ;
      }
      {

      }

      /* CIL Label */
      ;
    }

    /* CIL Label */
    ;
    }
  }
}
_Bool maybe_backup_file(char const *path, int this_is_the_archive) {

  {

    {}

    {}

    {}
  }
}
void undo_last_backup(void) {

  {}
}
int deref_stat(_Bool deref, char const *name, struct stat *buf) {

  int tmp___0;
  int tmp___1;

  {

    {}

    {
      tmp___0 = lstat((char const * /* __restrict  */)name,
                      (struct stat * /* __restrict  */)buf);
      tmp___1 = tmp___0;
    }

    return (tmp___1);
  }
}
static struct wd *wd;
static size_t wds;
static size_t wd_alloc;

void decode_mode(mode_t mode, char *string) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  int tmp___8;
  int tmp___9;

  int tmp___12;
  int tmp___13;
  int tmp___14;

  int tmp___17;
  int tmp___18;
  int tmp___19;

  int tmp___22;

  {

    *tmp = (char)tmp___8;
    tmp___0 = string;
    string++;

    *tmp___0 = (char)tmp___9;
    tmp___1 = string;
    string++;

    *tmp___1 = (char)tmp___12;
    tmp___2 = string;
    string++;

    *tmp___2 = (char)tmp___13;
    tmp___3 = string;
    string++;

    *tmp___3 = (char)tmp___14;
    tmp___4 = string;
    string++;

    *tmp___4 = (char)tmp___17;
    tmp___5 = string;
    string++;

    *tmp___5 = (char)tmp___18;
    tmp___6 = string;
    string++;

    *tmp___6 = (char)tmp___19;
    tmp___7 = string;
    string++;

    *tmp___7 = (char)tmp___22;
    *string = (char)'\000';
    return;
  }
}

void chmod_error_details(char const *name, mode_t mode) {

  {
    {}
  }
}
void chown_error_details(char const *name, uid_t uid, gid_t gid) {

  {
    {}
  }
}
void close_error(char const *name) {

  {
    {}
  }
}
void close_warn(char const *name) {

  {
    {}
  }
}
void close_diag(char const *name) {

  { return; }
}

void link_error(char const *target, char const *source) {

  {
    {}
  }
}
void mkdir_error(char const *name) {

  {
    {}
  }
}
void mkfifo_error(char const *name) {

  {
    {}
  }
}
void mknod_error(char const *name) {

  {
    {}
  }
}
void open_error(char const *name) {

  {
    {}
  }
}

void open_fatal(char const *name) {

  {
    {}
  }
}
void open_warn(char const *name) {

  {
    {}
  }
}
void open_diag(char const *name) {

  { return; }
}
void read_error(char const *name) {

  {
    {}
  }
}

void read_diag_details(char const *name, off_t offset, size_t size) {

  { return; }
}

void readlink_error(char const *name) {

  {
    {}
  }
}
void readlink_warn(char const *name) {

  {
    {}
  }
}
void readlink_diag(char const *name) {

  { return; }
}
void savedir_error(char const *name) {

  {
    {}
  }
}

void savedir_diag(char const *name) {

  { return; }
}
void seek_error(char const *name) {

  {
    {}
  }
}
void seek_error_details(char const *name, off_t offset) {

  {
    {}
  }
}
void seek_warn(char const *name) {

  {
    {}
  }
}

void symlink_error(char const *contents, char const *name) {

  {
    {}
  }
}
void stat_error(char const *name) {

  {
    {}
  }
}
void stat_warn(char const *name) {

  {
    {}
  }
}
void stat_diag(char const *name) {

  { return; }
}
void truncate_error(char const *name) {

  {
    {}
  }
}
void truncate_warn(char const *name) {

  {
    {}
  }
}
void unlink_error(char const *name) {

  {
    {}
  }
}
void utime_error(char const *name) {

  {
    {}
  }
}

void write_error(char const *name) {

  {
    {}
  }
}
void write_error_details(char const *name, size_t status, size_t size) {

  { return; }
}

void write_fatal_details(char const *name, ssize_t status, size_t size) {

  {
    {}
  }
}

char const *quote_n(int n, char const *name) {

  {
    {}
  }
}
char const *quote(char const *name) {

  {
    {}
  }
}
/* #pragma merger("0","00a.names.o.i","") */

extern struct passwd *getpwuid(__uid_t __uid);

char filename_terminator;
struct exclude *excluded;
char const *files_from_option;
_Bool same_order_option;

static char *cached_uname;
static char *cached_gname;
static uid_t cached_uid;
static gid_t cached_gid;

void uid_to_uname(uid_t uid, char **uname) {
  struct passwd *passwd;

  {

  _L___3: { /* CIL Label */
    passwd = getpwuid(uid);
  }

    { assign_string(&cached_uname, (char const *)passwd->pw_name); }

    {}

    { *uname = strdup((char const *)cached_uname); }
    return;
  }
}
void gid_to_gname(gid_t gid, char **gname) {
  struct group *group;

  {

    if (!cached_gname) {
      goto _L___3;
    } else {
      if (gid != cached_gid) {
      _L___3: { /* CIL Label */
      }

        { assign_string(&cached_gname, (char const *)group->gr_name); }

        {}
      }
    }
    { *gname = strdup((char const *)cached_gname); }
    return;
  }
}
int uname_to_uid(char const *uname, uid_t *uidp) {

  {

    *uidp = cached_uid;
    return (1);
  }
}
int gname_to_gid(char const *gname, gid_t *gidp) {

  {

    *gidp = cached_gid;
    return (1);
  }
}
static struct name *namelist;
static struct name **nametail = &namelist;
static char const **name_array;
static int allocated_names;
static int names;
static int name_index;
void init_names(void) {
  void *tmp;

  {
    {

      tmp = xmalloc(sizeof(char const *) * (unsigned long)allocated_names);
      name_array = (char const **)tmp;
    }
  }
}
void name_add(char const *name) {

  int tmp___0;

  {

    tmp___0 = names;
    names++;
    *(name_array + tmp___0) = name;
  }
}

static char *name_buffer;

void name_init(void) {
  void *tmp;

  {
    {
      tmp = xmalloc((size_t)102);
      name_buffer = (char *)tmp;
    }

    return;
  }
}

char *name_next(int change_dirs) {
  char const *source;

  int tmp___0;

  int tmp___4;
  int tmp___5;

  {

    {
      while (1) {
        /* CIL Label */
        ;
        if (name_index == names) {

          goto while_break;

          {}

        } else {
          {
            tmp___0 = name_index;
            name_index++;
            source = *(name_array + tmp___0);
          }

          {
            strcpy((char * /* __restrict  */)name_buffer,
                   (char const * /* __restrict  */)source);
          }
        }
        {}
        {

        while_break___1: /* CIL Label */
            ;
        }

        { tmp___4 = chdir((char const *)name_buffer); }

        if (change_dirs) {
          {
            tmp___5 = strcmp((char const *)name_buffer, "-C");
          }
          if (tmp___5 == 0) {

          } else {
            {}
            return (name_buffer);
          }
        } else {
          { unquote_string(name_buffer); }
          return (name_buffer);
        }
      }
    while_break: /* CIL Label */
        ;
    }

    return ((char *)0);
  }
}

void name_gather(void) {

  {}
}
struct name *addname(char const *string, int change_dir___0) {
  size_t length;

  size_t tmp___0;
  struct name *name;
  void *tmp___1;

  {

    {
      length = tmp___0;
      tmp___1 =
          xmalloc(((unsigned long)(&((struct name *)0)->name) + length) + 1UL);
      name = (struct name *)tmp___1;
    }

    name->next = (struct name *)0;
    name->length = length;
    name->found_count = (uintmax_t)0;
    name->regexp = (char)0;
    name->firstch = (char)1;
    name->change_dir = change_dir___0;
    name->dir_contents = (char const *)0;
  }
}

int name_match(char const *path) {

  {
    {}
    {

    while_break: /* CIL Label */
        ;
    }
  }
}
_Bool all_names_found(struct tar_stat_info *p) {

  {

    {}
    {

    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
void names_notfound(void) {

  {

    {

    while_break: /* CIL Label */
        ;
    }
    namelist = (struct name *)0;
    nametail = &namelist;
  }
}

void collect_and_sort_names(void) {

  {
    {}

    {

      /* CIL Label */
      ;
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
  }
}
struct name *name_scan(char const *path) {

  {
    {}
    {

    while_break: /* CIL Label */
        ;
    }
  }
}
char *name_from_list(void) {

  {

    {

    while_break: /* CIL Label */
        ;
    }
  }
}
void blank_name_list(void) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
char *new_name(char const *path, char const *name) {
  size_t pathlen;

  size_t namesize;

  int slash;
  char *buffer___2;
  void *tmp___1;
  int tmp___2;

  {
    {}

    {
      slash = tmp___2;
      tmp___1 = xmalloc((pathlen + (size_t)slash) + namesize);
      buffer___2 = (char *)tmp___1;
      memcpy((void * /* __restrict  */)buffer___2,
             (void const * /* __restrict  */)path, pathlen);
      *(buffer___2 + pathlen) = (char)'/';
      memcpy((void * /* __restrict  */)((buffer___2 + pathlen) + slash),
             (void const * /* __restrict  */)name, namesize);
    }
    return (buffer___2);
  }
}
_Bool excluded_name(char const *name) {

  {
    {}
  }
}

static Hash_table *avoided_name_table;

_Bool is_avoided_name(char const *name) {

  {
    {}
  }
}

char *safer_name_suffix(char const *file_name, _Bool link_target) {
  char const *p;

  { return ((char *)p); }
}
size_t stripped_prefix_len(char const *file_name, size_t num) {

  {

    {

      /* CIL Label */
      ;
    }
    {

      /* CIL Label */
      ;
    }
  }
}
_Bool contains_dot_dot(char const *name) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
/* #pragma merger("0","00b.rtapelib.o.i","") */

static int from_remote[4][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
static int to_remote[4][2] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};

static int do_command(int handle, char const *buffer___2) {

  {
    {}

    {}
  }
}

static void encode_oflag(char *buf, int oflag) {

  {
    {}
    {

      { /* CIL Label */
      }

      { /* CIL Label */
      }

      { /* CIL Label */
      }

      {
          /* CIL Label */

      } /* CIL Label */
      ;
    }
  }
}
int rmt_open__(char const *path, int open_mode, int bias,
               char const *remote_shell) {
  int remote_pipe_number;

  char *remote_file;

  size_t remote_file_len;
  size_t tmp___10;
  char *command_buffer;
  void *tmp___11;

  int tmp___13;

  {

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

    {}

    {
      close(from_remote[remote_pipe_number][1]);
      close(to_remote[remote_pipe_number][0]);
      tmp___10 = strlen((char const *)remote_file);
      remote_file_len = tmp___10;
      tmp___11 = xmalloc(remote_file_len + 1000UL);
      command_buffer = (char *)tmp___11;
      sprintf((char * /* __restrict  */)command_buffer,
              (char const * /* __restrict  */) "O%s\n", remote_file);
      encode_oflag((command_buffer + remote_file_len) + 2, open_mode);
      strcat((char * /* __restrict  */)command_buffer,
             (char const * /* __restrict  */) "\n");
      tmp___13 = do_command(remote_pipe_number, (char const *)command_buffer);
    }

    {}
  }
}
int rmt_close__(int handle) {

  {
    {}

    {}
  }
}
size_t rmt_read__(int handle, char *buffer___2, size_t length) {

  {
    {}

    {

      /* CIL Label */
      ;
    }
  }
}

off_t rmt_lseek__(int handle, off_t offset, int whence) {

  char operand_buffer[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                      1UL];

  char *p;

  {

    p = operand_buffer + sizeof(operand_buffer);
    p--;
    *p = (char)0;
    {

      /* CIL Label */
      ;
    }

    {

      /* CIL Label */

      /* CIL Label */

      /* CIL Label */

      {
          /* CIL Label */

      } /* CIL Label */
      ;
    }
    {}

    {}
  }
}
int rmt_ioctl__(int handle, int operation, char *argument) {

  char operand_buffer[(((sizeof(uintmax_t) * 8UL) * 302UL) / 1000UL + 1UL) +
                      1UL];

  char *p;

  {
    {

      { /* CIL Label */
      }

      /* CIL Label */

      p = operand_buffer + sizeof(operand_buffer);
      p--;
      *p = (char)0;
      {

        /* CIL Label */
        ;
      }

      {}

      {}

      { /* CIL Label */
      }

      {

        /* CIL Label */
        ;
      }

      {

        /* CIL Label */
        ;
      }

      /* CIL Label */
      ;
    }
  }
}
/* #pragma merger("0","00c.sparse.o.i","") */

static _Bool tar_sparse_done(struct tar_sparse_file *file) {

  {}
}

static _Bool tar_sparse_decode_header(struct tar_sparse_file *file) {

  {}
}

static char buffer___1[512];
static _Bool sparse_scan_file(struct tar_sparse_file *file) {

  {
    {}

    {}

    {

      /* CIL Label */
      ;
    }

    {}
  }
}

static _Bool sparse_dump_region(struct tar_sparse_file *file, size_t i) {

  {
    {}

    {

      /* CIL Label */
      ;
    }
  }
}
static _Bool sparse_extract_region(struct tar_sparse_file *file, size_t i) {

  {
    {}
  }
}
enum dump_status sparse_dump_file(int fd, struct tar_stat_info *st) {
  _Bool rc___1;
  struct tar_sparse_file file;

  _Bool tmp___1;
  int tmp___2;

  {
    {}

    { rc___1 = sparse_scan_file(&file); }

    {
      pad_archive((off_t)((size_t)(file.stat_info)->archive_file_size -
                          file.dumped_size));
      tmp___1 = tar_sparse_done(&file);
    }

    return ((enum dump_status)tmp___2);
  }
}
_Bool sparse_file_p(struct tar_stat_info *st) {

  {}
}
_Bool sparse_member_p(struct tar_stat_info *st) {

  {
    {}

    {}
  }
}
_Bool sparse_fixup_header(struct tar_stat_info *st) {

  {
    {}

    {}
  }
}
enum dump_status sparse_extract_file(int fd, struct tar_stat_info *st,
                                     off_t *size) {
  _Bool rc___1;
  struct tar_sparse_file file;
  size_t i;

  _Bool tmp___1;
  int tmp___2;

  {
    {}

    {
      rc___1 = tar_sparse_decode_header(&file);
      i = (size_t)0;
    }
    {

    while_break: /* CIL Label */
        ;
    }
    {
      *size = (off_t)((size_t)(file.stat_info)->archive_file_size -
                      file.dumped_size);
      tmp___1 = tar_sparse_done(&file);
    }

    return ((enum dump_status)tmp___2);
  }
}
enum dump_status sparse_skip_file(struct tar_stat_info *st) {
  _Bool rc___1;
  struct tar_sparse_file file;

  _Bool tmp___1;
  int tmp___2;

  {
    {}

    {
      rc___1 = tar_sparse_decode_header(&file);
      skip_file((file.stat_info)->archive_file_size);
      tmp___1 = tar_sparse_done(&file);
    }

    return ((enum dump_status)tmp___2);
  }
}
static char diff_buffer___0[512];

_Bool sparse_diff_file(int fd, struct tar_stat_info *st) {
  _Bool rc___1;
  struct tar_sparse_file file;
  size_t i;

  {
    {}

    {
      rc___1 = tar_sparse_decode_header(&file);
      i = (size_t)0;
    }
    {

    while_break: /* CIL Label */
        ;
    }

    {}
  }
}
static _Bool oldgnu_sparse_member_p(struct tar_sparse_file *file
                                    __attribute__((__unused__))) {

  {}
}

static _Bool oldgnu_fixup_header(struct tar_sparse_file *file) {

  {
    {}
  }
}

static _Bool oldgnu_get_sparse_info(struct tar_sparse_file *file) {

  {

    {

      /* CIL Label */
      ;
    }

    {

    while_break___0: /* CIL Label */
        ;
    }
  }
}

static _Bool oldgnu_dump_header(struct tar_sparse_file *file) {

  {
    {}

    {}
    {

    while_break: /* CIL Label */
        ;
    }
    return ((_Bool)1);
  }
}
static struct tar_sparse_optab oldgnu_optab = {
    (_Bool(*)(struct tar_sparse_file *))((void *)0),
    (_Bool(*)(struct tar_sparse_file *))((void *)0),
    &oldgnu_sparse_member_p,
    &oldgnu_dump_header,
    &oldgnu_fixup_header,
    &oldgnu_get_sparse_info,
    (_Bool(*)(struct tar_sparse_file *, enum sparse_scan_state, void *))(
        (void *)0),
    &sparse_dump_region,
    &sparse_extract_region};

/* #pragma merger("0","00d.system.o.i","") */

void sys_stat_nanoseconds(struct tar_stat_info *st) {

  {}
}
static struct stat archive_stat;
_Bool sys_get_archive_stat(void) {
  int tmp;

  {
    { tmp = fstat(archive, &archive_stat); }
    return ((_Bool)(tmp == 0));
  }
}
_Bool sys_file_is_archive(struct tar_stat_info *p) {
  int tmp;

  {

    tmp = 0;

    return ((_Bool)tmp);
  }
}
void sys_save_archive_dev_ino(void) {

  { return; }
}
static char const dev_null[10] = {
    (char const)'/', (char const)'d',   (char const)'e', (char const)'v',
    (char const)'/', (char const)'n',   (char const)'u', (char const)'l',
    (char const)'l', (char const)'\000'};
void sys_detect_dev_null_output(void) {

  int tmp___1;

  {
    {}

    dev_null_output = (_Bool)tmp___1;
    return;
  }
}
void sys_drain_input_pipe(void) {

  { return; }
}
void sys_wait_for_child(pid_t child_pid___0) {

  {}
}
void sys_spawn_shell(void) {

  {
    {}

    {}
  }
}
_Bool sys_compare_uid(struct stat *a, struct stat *b) {

  {}
}
_Bool sys_compare_gid(struct stat *a, struct stat *b) {

  {}
}
_Bool sys_compare_links(struct stat *link_data, struct stat *stat_data) {
  int tmp;

  { return ((_Bool)tmp); }
}
int sys_truncate(int fd) {

  int tmp___1;

  {
    {}

    return (tmp___1);
  }
}
void sys_reset_uid_gid(void) {

  {
    {}
  }
}

size_t sys_write_archive_buffer(void) {

  size_t tmp___0;
  size_t tmp___1;

  {

    {}

    {
      tmp___0 = full_write(archive, (void const *)(record_start->buffer),
                           record_size);
      tmp___1 = tmp___0;
    }

    return (tmp___1);
  }
}

pid_t sys_child_open_for_compress(void) {

  {
    {}

    {}

    {}

    {}

    {

      /* CIL Label */
      ;
    }
    {

      /* CIL Label */
      ;
    }

    {}
  }
}
pid_t sys_child_open_for_uncompress(void) {

  {
    {}

    {}

    {}

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
  }
}
/* #pragma merger("0","00e.tar.o.i","") */
extern char *optarg;

void add_exclude(struct exclude *ex, char const *pattern, int options);
int add_exclude_file(void (*add_func)(struct exclude *, char const *, int),
                     struct exclude *ex, char const *filename, int options,
                     char line_end);
struct mode_change *mode_compile(char const *mode_string,
                                 unsigned int masked_ops);
int check_links_option;
int allocated_archive_names;

void request_stdin(char const *option) {

  {}
}

int confirm(char const *message_action, char const *message_name) {
  char const *tmp;
  int reply;

  int tmp___1;
  int character;
  int tmp___2;

  {

    {
      tmp = quote(message_name);
      fprintf((FILE * /* __restrict  */)stdlis,
              (char const * /* __restrict  */) "%s %s?", message_action, tmp);
      fflush_unlocked(stdlis);
    }

    reply = tmp___1;
    character = reply;
    {

      /* CIL Label */
      ;
    }

    return (tmp___2);
  }
}
static struct fmttab const fmttab[6] = {
    {"v7", (enum archive_format)1},
    {"oldgnu", (enum archive_format)2},
    {"ustar", (enum archive_format)3},
    {"posix", (enum archive_format)4},
    {"gnu", (enum archive_format)6},
    {(char const *)((void *)0), (enum archive_format)0}};

static int show_help;
static int show_version;
static struct option long_options[104] = {
    {"absolute-names", 0, (int *)0, 'P'},
    {"after-date", 1, (int *)0, 'N'},
    {"anchored", 0, (int *)0, 128},
    {"append", 0, (int *)0, 'r'},
    {"atime-preserve", 0, (int *)0, 129},
    {"backup", 2, (int *)0, 130},
    {"block-number", 0, (int *)0, 'R'},
    {"blocking-factor", 1, (int *)0, 'b'},
    {"bzip2", 0, (int *)0, 'j'},
    {"catenate", 0, (int *)0, 'A'},
    {"checkpoint", 0, (int *)0, 131},
    {"check-links", 0, &check_links_option, 1},
    {"compare", 0, (int *)0, 'd'},
    {"compress", 0, (int *)0, 'Z'},
    {"concatenate", 0, (int *)0, 'A'},
    {"confirmation", 0, (int *)0, 'w'},
    {"create", 0, (int *)0, 'c'},
    {"delete", 0, (int *)0, 132},
    {"dereference", 0, (int *)0, 'h'},
    {"diff", 0, (int *)0, 'd'},
    {"directory", 1, (int *)0, 'C'},
    {"exclude", 1, (int *)0, 133},
    {"exclude-from", 1, (int *)0, 'X'},
    {"extract", 0, (int *)0, 'x'},
    {"file", 1, (int *)0, 'f'},
    {"files-from", 1, (int *)0, 'T'},
    {"force-local", 0, (int *)0, 134},
    {"format", 1, (int *)0, 135},
    {"get", 0, (int *)0, 'x'},
    {"group", 1, (int *)0, 136},
    {"gunzip", 0, (int *)0, 'z'},
    {"gzip", 0, (int *)0, 'z'},
    {"help", 0, &show_help, 1},
    {"ignore-case", 0, (int *)0, 137},
    {"ignore-failed-read", 0, (int *)0, 138},
    {"ignore-zeros", 0, (int *)0, 'i'},
    {"incremental", 0, (int *)0, 'G'},
    {"index-file", 1, (int *)0, 139},
    {"info-script", 1, (int *)0, 'F'},
    {"interactive", 0, (int *)0, 'w'},
    {"keep-newer-files", 0, (int *)0, 140},
    {"keep-old-files", 0, (int *)0, 'k'},
    {"label", 1, (int *)0, 'V'},
    {"list", 0, (int *)0, 't'},
    {"listed-incremental", 1, (int *)0, 'g'},
    {"mode", 1, (int *)0, 141},
    {"multi-volume", 0, (int *)0, 'M'},
    {"new-volume-script", 1, (int *)0, 'F'},
    {"newer", 1, (int *)0, 'N'},
    {"newer-mtime", 1, (int *)0, 142},
    {"null", 0, (int *)0, 148},
    {"no-anchored", 0, (int *)0, 143},
    {"no-ignore-case", 0, (int *)0, 144},
    {"no-overwrite-dir", 0, (int *)0, 145},
    {"no-wildcards", 0, (int *)0, 146},
    {"no-wildcards-match-slash", 0, (int *)0, 147},
    {"no-recursion", 0, &recursion_option, 0},
    {"no-same-owner", 0, &same_owner_option, -1},
    {"no-same-permissions", 0, &same_permissions_option, -1},
    {"numeric-owner", 0, (int *)0, 149},
    {"occurrence", 2, (int *)0, 150},
    {"old-archive", 0, (int *)0, 'o'},
    {"one-file-system", 0, (int *)0, 'l'},
    {"overwrite", 0, (int *)0, 151},
    {"owner", 1, (int *)0, 152},
    {"pax-option", 1, (int *)0, 153},
    {"portability", 0, (int *)0, 'o'},
    {"posix", 0, (int *)0, 154},
    {"preserve", 0, (int *)0, 155},
    {"preserve-order", 0, (int *)0, 's'},
    {"preserve-permissions", 0, (int *)0, 'p'},
    {"recursion", 0, &recursion_option, 1 << 3},
    {"recursive-unlink", 0, (int *)0, 157},
    {"read-full-records", 0, (int *)0, 'B'},
    {"record-size", 1, (int *)0, 156},
    {"remove-files", 0, (int *)0, 158},
    {"rmt-command", 1, (int *)0, 159},
    {"rsh-command", 1, (int *)0, 160},
    {"same-order", 0, (int *)0, 's'},
    {"same-owner", 0, &same_owner_option, 1},
    {"same-permissions", 0, (int *)0, 'p'},
    {"show-defaults", 0, (int *)0, 161},
    {"show-omitted-dirs", 0, (int *)0, 162},
    {"sparse", 0, (int *)0, 'S'},
    {"starting-file", 1, (int *)0, 'K'},
    {"strip-path", 1, (int *)0, 163},
    {"suffix", 1, (int *)0, 164},
    {"tape-length", 1, (int *)0, 'L'},
    {"to-stdout", 0, (int *)0, 'O'},
    {"totals", 0, (int *)0, 165},
    {"touch", 0, (int *)0, 'm'},
    {"uncompress", 0, (int *)0, 'Z'},
    {"ungzip", 0, (int *)0, 'z'},
    {"unlink-first", 0, (int *)0, 'U'},
    {"update", 0, (int *)0, 'u'},
    {"utc", 0, (int *)0, 167},
    {"use-compress-program", 1, (int *)0, 166},
    {"verbose", 0, (int *)0, 'v'},
    {"verify", 0, (int *)0, 'W'},
    {"version", 0, &show_version, 1},
    {"volno-file", 1, (int *)0, 168},
    {"wildcards", 0, (int *)0, 169},
    {"wildcards-match-slash", 0, (int *)0, 170},
    {(char const *)0, 0, (int *)0, 0}};

void usage(int status) {

  {

    { exit(status); }
  }
}

static void decode_options(int argc, char **argv) {
  int optchar;

  char const *textual_date_option;
  char const *backup_suffix_string;
  char const *version_control_string;
  int exclude_options;
  _Bool o_option;
  int pax_option;

  int new_argc;
  char **new_argv;
  char *const *in;
  char **out;
  char const *letter;
  char buffer___2[3];
  char const *cursor;
  size_t tmp___0;
  void *tmp___1;
  char **tmp___2;
  char *const *tmp___3;
  char *const *tmp___4;
  char **tmp___5;
  char *tmp___6;
  char **tmp___7;
  char *const *tmp___8;
  char *tmp___9;
  char **tmp___10;
  char *const *tmp___11;
  char *tmp___12;
  uintmax_t u;
  char *tmp___13;
  char *tmp___14;
  strtol_error tmp___15;
  void *tmp___16;
  int tmp___17;

  int tmp___31;

  size_t tmp___45;

  uintmax_t u___3;

  strtol_error tmp___49;

  uintmax_t u___4;

  char *tmp___55;

  {
    {

      blocking_factor = 20;
      record_size = (size_t)10240;

      recursion_option = 1 << 3;
    }

    {}
    {
      while (1) {
        /* CIL Label */
        ;
        {
          optchar = getopt_long(
              argc, (char *const *)argv,
              "-01234567ABC:F:GIK:L:MN:OPRST:UV:WX:Zb:cdf:g:hijklmoprstuvwxyz",
              (struct option const *)(long_options), (int *)0);
        }
        if (!(optchar != -1)) {
          goto while_break___1;
        }
        {

          if (optchar == 1) {
            goto case_1;
          }

          if (optchar == 67) {
            goto case_67;
          }

          goto case_102;

        case_63: { /* CIL Label */
        }
        case_0: /* CIL Label */

        case_1: { /* CIL Label */
          name_add((char const *)optarg);
        }

        case_65: { /* CIL Label */
        }

        case_98: { /* CIL Label */
        }

          goto switch_break;
        case_66: /* CIL Label */
          read_full_records_option = (_Bool)1;
          goto switch_break;
        case_99: { /* CIL Label */
          set_subcommand_option((enum subcommand)3);
        }
          goto switch_break;
        case_67: { /* CIL Label */
          name_add("-C");
          name_add((char const *)optarg);
        }
          goto switch_break;
        case_100: { /* CIL Label */
          set_subcommand_option((enum subcommand)5);
        }
          goto switch_break;
        case_102: /* CIL Label */

          archive_names++;
          *(archive_name_array + tmp___17) = (char const *)optarg;

        case_70: /* CIL Label */

        case_103: /* CIL Label */

        case_71: /* CIL Label */

        case_104: /* CIL Label */

        case_105: /* CIL Label */

        case_73: { /* CIL Label */
        }

        case_106: { /* CIL Label */
        }

        case_107: /* CIL Label */

        case_75: { /* CIL Label */
        }

        case_108: /* CIL Label */

        case_76: { /* CIL Label */
        }

        case_109: /* CIL Label */

        case_77: /* CIL Label */

        case_78: /* CIL Label */

        case_142: /* CIL Label */

          goto switch_break;
        case_111: /* CIL Label */
          o_option = (_Bool)1;
          goto switch_break;
        case_79: /* CIL Label */
          to_stdout_option = (_Bool)1;
          goto switch_break;
        case_112: /* CIL Label */
          same_permissions_option = 1;
          goto switch_break;
        case_80: /* CIL Label */
          absolute_names_option = (_Bool)1;
          goto switch_break;
        case_114: { /* CIL Label */
          set_subcommand_option((enum subcommand)1);
        }
          goto switch_break;
        case_82: /* CIL Label */
          block_number_option = (_Bool)1;
          goto switch_break;
        case_115: /* CIL Label */
          same_order_option = (_Bool)1;
          goto switch_break;
        case_83: /* CIL Label */
          sparse_option = (_Bool)1;
          goto switch_break;
        case_116: { /* CIL Label */
          set_subcommand_option((enum subcommand)7);
          verbose_option++;
        }
          goto switch_break;
        case_84: /* CIL Label */
          files_from_option = (char const *)optarg;
          goto switch_break;
        case_117: { /* CIL Label */
          set_subcommand_option((enum subcommand)8);
        }
          goto switch_break;
        case_85: /* CIL Label */
          old_files_option = (enum old_files)3;
          goto switch_break;
        case_167: /* CIL Label */
          utc_option = (_Bool)1;
          goto switch_break;
        case_118: /* CIL Label */
          verbose_option++;
          goto switch_break;
        case_86: /* CIL Label */
          volume_label_option = (char const *)optarg;
          goto switch_break;
        case_119: /* CIL Label */
          interactive_option = (_Bool)1;
          goto switch_break;
        case_87: /* CIL Label */
          verify_option = (_Bool)1;
          goto switch_break;
        case_120: { /* CIL Label */
          set_subcommand_option((enum subcommand)6);
        }
          goto switch_break;
        case_88: { /* CIL Label */
          tmp___31 =
              add_exclude_file(&add_exclude, excluded, (char const *)optarg,
                               exclude_options | recursion_option, (char)'\n');
        }

        case_121: { /* CIL Label */
        }

        case_122: { /* CIL Label */
        }

        case_90: { /* CIL Label */
        }

        case_128: /* CIL Label */

        case_129: /* CIL Label */

        case_131: /* CIL Label */

        case_130: /* CIL Label */

        case_132: { /* CIL Label */
        }

        case_133: { /* CIL Label */
        }

        case_134: /* CIL Label */

        case_135: { /* CIL Label */
        }

        case_139: /* CIL Label */

        case_137: /* CIL Label */

        case_138: /* CIL Label */

        case_140: /* CIL Label */

        case_136: { /* CIL Label */
        }

          goto switch_break;
        case_141: { /* CIL Label */
          mode_option = mode_compile((char const *)optarg, 7U);
        }

        case_143: /* CIL Label */

        case_144: /* CIL Label */

        case_145: /* CIL Label */

        case_146: /* CIL Label */

        case_147: /* CIL Label */

        case_148: /* CIL Label */

        case_149: /* CIL Label */

        case_150: /* CIL Label */

          goto switch_break;
        case_151: /* CIL Label */
          old_files_option = (enum old_files)2;
          goto switch_break;
        case_152: { /* CIL Label */
          tmp___45 = strlen((char const *)optarg);
        }

          goto switch_break;
        case_153: { /* CIL Label */
          pax_option++;
          xheader_set_option(optarg);
        }
          goto switch_break;
        case_154: { /* CIL Label */
          set_archive_format("posix");
        }
          goto switch_break;
        case_155: /* CIL Label */
          same_permissions_option = 1;
          same_order_option = (_Bool)1;
          goto switch_break;
        case_156: { /* CIL Label */
          tmp___49 =
              xstrtoumax((char const *)optarg, (char **)0, 10, &u___3, "");
        }

          record_size = u___3;

        case_157: /* CIL Label */

        case_158: /* CIL Label */

        case_159: /* CIL Label */

        case_160: /* CIL Label */

        case_161: { /* CIL Label */
        }
        case_163: { /* CIL Label */
        }

          strip_path_elements = u___4;
          goto switch_break;
        case_164: /* CIL Label */
          backup_option = (_Bool)1;
          backup_suffix_string = (char const *)optarg;
          goto switch_break;
        case_165: /* CIL Label */
          totals_option = (_Bool)1;
          goto switch_break;
        case_166: { /* CIL Label */
          set_use_compress_program_option((char const *)optarg);
        }
          goto switch_break;
        case_168: /* CIL Label */
          volno_file_option = (char const *)optarg;
          goto switch_break;
        case_169: /* CIL Label */
          exclude_options |= 1 << 28;
          goto switch_break;
        case_170: /* CIL Label */
          exclude_options &= -2;
          goto switch_break;
        case_48:   /* CIL Label */
        case_49:   /* CIL Label */
        case_50:   /* CIL Label */
        case_51:   /* CIL Label */
        case_52:   /* CIL Label */
        case_53:   /* CIL Label */
        case_54:   /* CIL Label */
        case_55: { /* CIL Label */
          tmp___55 =
              gettext("Options `-[0-7][lmh]\' not supported by *this* tar");
          error(0, 0, (char const *)tmp___55);
          usage(2);
        }
        switch_break: /* CIL Label */
            ;
        }
      }
    while_break___1: /* CIL Label */
        ;
    }

    {

      /* CIL Label */
      ;
    }

    archive_format = (enum archive_format)6;

    {

      /* CIL Label */

      /* CIL Label */
      /* CIL Label */
      /* CIL Label */

      {

        /* CIL Label */
        ;
      }

      /* CIL Label */
      /* CIL Label */
      /* CIL Label */

      {

        /* CIL Label */
        ;
      }
      /* CIL Label */

      /* CIL Label */
      ;
    }
  }
}
int main(int argc, char **argv) {

  void *tmp___0;

  {
    {}

    {

      filename_terminator = (char)'\n';

      tmp___0 = xmalloc(sizeof(char const *) *
                        (unsigned long)allocated_archive_names);
      archive_name_array = (char const **)tmp___0;

      init_names();
      decode_options(argc, argv);
      name_init();
    }

    {

      { /* CIL Label */
      }
      /* CIL Label */
      /* CIL Label */
      { /* CIL Label */
      }

      { /* CIL Label */
      }

      { /* CIL Label */
        create_archive();
      }

      { /* CIL Label */
      }

      { /* CIL Label */
      }

      {
          /* CIL Label */

      }

      /* CIL Label */
      ;
    }

    {}

    {}
  }
}
void tar_stat_init(struct tar_stat_info *st) {

  {
    { memset((void *)st, 0, sizeof(*st)); }
  }
}
void tar_stat_destroy(struct tar_stat_info *st) {

  {
    {}
  }
}
/* #pragma merger("0","00f.update.o.i","") */

void update_archive(void) {

  {
    {}
    {

      /* CIL Label */
      ;
    }
    {}
    {

    while_break___0: /* CIL Label */
        ;
    }
    {
      write_eot();
      close_archive();
      names_notfound();
    }
    return;
  }
}
/* #pragma merger("0","010.utf8.o.i","") */
static iconv_t conv_desc[2] = {(iconv_t)-1, (iconv_t)-1};

_Bool utf8_convert(_Bool to_utf, char const *input, char **output) {

  {
    {}

    {}
  }
}
_Bool string_ascii_p(char const *str) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
/* #pragma merger("0","011.addext.o.i","") */

/* #pragma merger("0","012.argmatch.o.i","") */

/* #pragma merger("0","013.backupfile.o.i","") */
extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);

extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);

char *find_backup_file_name(char const *file,
                            enum backup_type backup_type___0) {

  char *s;

  {
    {}

    {}

    return (s);
  }
}

static int version_number(char const *base, char const *backup,
                          size_t base_length) {

  {
    {}
  }
}

/* #pragma merger("0","014.basename.o.i","") */
char *base_name(char const *name) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}

/* #pragma merger("0","015.dirname.o.i","") */

char *dir_name(char const *path) {

  {
    {}
  }
}
/* #pragma merger("0","016.exclude.o.i","") */

struct exclude *new_exclude(void) {

  {
    {}
  }
}

_Bool excluded_filename(struct exclude const *ex, char const *f) {

  {}
}
void add_exclude(struct exclude *ex, char const *pattern, int options) {

  {}
}
int add_exclude_file(void (*add_func)(struct exclude *, char const *, int),
                     struct exclude *ex, char const *filename, int options,
                     char line_end) {
  _Bool use_stdin;

  char *buf;
  char *p;
  char const *pattern;
  char const *lim;
  size_t buf_alloc;
  size_t buf_count;

  int e;

  int tmp___9;
  int tmp___10;
  int tmp___11;

  {

    use_stdin = (_Bool)tmp___9;
    buf = (char *)((void *)0);
    buf_alloc = (size_t)0;
    buf_count = (size_t)0;
    e = 0;

    {

      /* CIL Label */
      ;
    }
    {}

    {}

    lim = (char const *)((buf + buf_count) + tmp___10);
    pattern = (char const *)buf;
    p = buf;
    {

      /* CIL Label */
      ;
    }
    {}

    return (tmp___11);
  }
}
/* #pragma merger("0","017.exitfail.o.i","") */
int volatile exit_failure = (int volatile)1;
/* #pragma merger("0","018.full-write.o.i","") */
size_t safe_write(int fd, void const *buf, size_t count);
size_t full_write(int fd, void const *buf, size_t count) {
  size_t total;
  char const *ptr;
  size_t n_rw;
  size_t tmp;

  {
    total = (size_t)0;
    ptr = (char const *)buf;
    {

      /* CIL Label */
      ;
      if (!(count > 0UL)) {
      }
      {
        tmp = safe_write(fd, (void const *)ptr, count);
        n_rw = tmp;
      }

      total += n_rw;

    while_break: /* CIL Label */
        ;
    }
    return (total);
  }
}
/* #pragma merger("0","019.getdate.o.i","") */

_Bool get_date(struct timespec *result, char const *p,
               struct timespec const *now) {

  {

    {}

    {

      /* CIL Label */
      ;
    }

    {}

    {}

    {}
  }
}
/* #pragma merger("0","01a.getopt1.o.i","") */
/* #pragma merger("0","01b.getopt.o.i","") */
/* #pragma merger("0","01c.gettime.o.i","") */

/* #pragma merger("0","01d.hash.o.i","") */

void *hash_lookup(Hash_table const *table___0, void const *entry) {

  {
    {}

    {

      /* CIL Label */
      ;
    }
  }
}
void *hash_get_first(Hash_table const *table___0) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
void *hash_get_next(Hash_table const *table___0, void const *entry) {

  {
    {}

    {

      /* CIL Label */
      ;
    }
    {

      /* CIL Label */
      ;
    }
  }
}
size_t hash_do_for_each(Hash_table const *table___0,
                        _Bool (*processor)(void *, void *),
                        void *processor_data) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
size_t hash_string(char const *string, size_t n_buckets) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}

Hash_table *hash_initialize(size_t candidate, Hash_tuning const *tuning,
                            size_t (*hasher)(void const *, size_t),
                            _Bool (*comparator)(void const *, void const *),
                            void (*data_freer)(void *)) {

  {

    {}

    {}

    {}

    {}

    {}
  }
}

void *hash_insert(Hash_table *table___0, void const *entry) {

  {

    {}
  }
}
/* #pragma merger("0","01e.human.o.i","") */

static char const power_letter[9] = {
    (char const)0,   (char const)'K', (char const)'M',
    (char const)'G', (char const)'T', (char const)'P',
    (char const)'E', (char const)'Z', (char const)'Y'};

char *human_readable(uintmax_t n, char *buf, int opts,
                     uintmax_t from_block_size, uintmax_t to_block_size) {

  unsigned int base;

  int exponent;
  int exponent_max;

  char const *decimal_point;
  size_t decimal_pointlen;
  char const *grouping;
  char const *thousands_sep;
  struct lconv const *l;
  struct lconv *tmp;
  size_t pointlen;
  size_t tmp___0;

  long double dto_block_size;
  long double damt;

  int tmp___8;

  {

    {
      base = (unsigned int)tmp___8;
      exponent = -1;
      exponent_max = (int)(sizeof(power_letter) - 1UL);
      decimal_point = ".";
      decimal_pointlen = (size_t)1;
      grouping = "";
      thousands_sep = "";
      tmp = localeconv();
      l = (struct lconv const *)tmp;
      tmp___0 = strlen((char const *)l->decimal_point);
      pointlen = tmp___0;
    }

    {}

    dto_block_size = (long double)to_block_size;
    damt = (long double)n * ((long double)from_block_size / dto_block_size);

    {}

    {

      /* CIL Label */
      ;
    }

    {}
  }
}

/* #pragma merger("0","01f.mktime.o.i","") */

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

time_t(__attribute__((__leaf__)) rpl_mktime)(struct tm *tp) {

  {
    {}
  }
}
/* #pragma merger("0","020.modechange.o.i","") */

struct mode_change *mode_compile(char const *mode_string,
                                 unsigned int masked_ops) {

  {
    {}

    {}
    {

      /* CIL Label */
      ;
    }

    {}
  }
}
mode_t mode_adjust(mode_t oldmode, struct mode_change const *changes) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
void mode_free(struct mode_change *changes) {

  {
    {

      /* CIL Label */
      ;
    }
  }
}
/* #pragma merger("0","021.prepargs.o.i","") */

void prepend_default_options(char const *options, int *pargc, char ***pargv) {

  {}
}
/* #pragma merger("0","022.quotearg.o.i","") */
char const *const quoting_style_args[8];

static struct quoting_options default_quoting_options;
struct quoting_options *clone_quoting_options(struct quoting_options *o___0) {
  int e;

  struct quoting_options *p;

  int *tmp___1;
  struct quoting_options *tmp___2;

  {
    {}

    {
      *p = *tmp___2;
      tmp___1 = __errno_location();
      *tmp___1 = e;
    }
    return (p);
  }
}
void set_quoting_style(struct quoting_options *o___0, enum quoting_style s) {
  struct quoting_options *tmp;

  {

    tmp = &default_quoting_options;

    tmp->style = s;
    return;
  }
}

static size_t quotearg_buffer_restyled(char *buffer___2, size_t buffersize,
                                       char const *arg, size_t argsize,
                                       enum quoting_style quoting_style,
                                       struct quoting_options const *o___0) {

  {
    {}
    {

      { /* CIL Label */

        /* CIL Label */
        ;
      }

      /* CIL Label */

      /* CIL Label */
      { /* CIL Label */
      }
      {

        /* CIL Label */
        ;
      }
      {}

      { /* CIL Label */

        /* CIL Label */
        ;
      }

      /* CIL Label */

      /* CIL Label */
      ;
    }

    {

      /* CIL Label */
      ;
    }

    {}
  }
}
size_t quotearg_buffer(char *buffer___2, size_t buffersize, char const *arg,
                       size_t argsize, struct quoting_options const *o___0) {
  struct quoting_options const *p;
  int e;
  int *tmp;
  size_t r;
  size_t tmp___0;
  int *tmp___1;

  {

    {
      tmp = __errno_location();
      e = *tmp;
      tmp___0 = quotearg_buffer_restyled(buffer___2, buffersize, arg, argsize,
                                         (enum quoting_style)p->style, p);
      r = tmp___0;
      tmp___1 = __errno_location();
      *tmp___1 = e;
    }
    return (r);
  }
}
static char slot0[256];

char *quotearg(char const *arg) {

  {
    {}
  }
}

char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {

  {
    {}
  }
}

char *quotearg_colon(char const *arg) {

  {
    {}
  }
}
/* #pragma merger("0","023.quote.o.i","") */
/* #pragma merger("0","024.safe-read.o.i","") */

size_t safe_read(int fd, void *buf, size_t count) {
  ssize_t result;

  {

    {

      /* CIL Label */
      ;
      { result = read(fd, buf, count); }

    while_break: /* CIL Label */
        ;
    }
    return ((size_t)result);
  }
}
/* #pragma merger("0","025.safe-write.o.i","") */

size_t safe_write(int fd, void const *buf, size_t count) {
  ssize_t result;

  {

    {

      /* CIL Label */
      ;
      { result = write(fd, buf, count); }

    while_break: /* CIL Label */
        ;
    }
    return ((size_t)result);
  }
}
/* #pragma merger("0","026.save-cwd.o.i","") */

int save_cwd(struct saved_cwd *cwd) {

  {}
}
int restore_cwd(struct saved_cwd const *cwd) {

  {}
}
/* #pragma merger("0","027.savedir.o.i","") */
char *savedir(char const *dir) {
  DIR *dirp;
  struct dirent *dp;
  char *name_space;
  size_t allocated;
  size_t used;
  int save_errno;
  void *tmp;
  int *tmp___0;
  char const *entry;
  size_t entry_size;
  size_t tmp___1;
  void *tmp___2;
  int *tmp___3;
  int *tmp___4;
  int tmp___5;

  int tmp___7;
  int tmp___8;

  {
    {
      allocated = (size_t)512;
      used = (size_t)0;
      dirp = opendir(dir);
    }
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      return ((char *)((void *)0));
    }
    {
      tmp = xmalloc(allocated);
      name_space = (char *)tmp;
    }
    {
      while (1) {
        /* CIL Label */
        ;
        { dp = readdir(dirp); }
        if (!((unsigned long)dp != (unsigned long)((void *)0))) {
          goto while_break;
        }
        entry = (char const *)(dp->d_name);
        if ((int const) * (entry + 0) != 46) {

        } else {

          tmp___8 = tmp___7;
        }
        if ((int const) * (entry + tmp___8) != 0) {
          {
            tmp___1 = strlen(entry);
            entry_size = tmp___1 + 1UL;
          }

          {
            memcpy((void * /* __restrict  */)(name_space + used),
                   (void const * /* __restrict  */)entry, entry_size);
            used += entry_size;
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
    { *(name_space + used) = (char)'\000'; }

    return (name_space);
  }
}
/* #pragma merger("0","028.stripslash.o.i","") */
int strip_trailing_slashes(char *path) {

  {
    {}
  }
}
/* #pragma merger("0","029.xgetcwd.o.i","") */

char *xgetcwd(void) {

  {
    {}
  }
}
/* #pragma merger("0","02a.xmalloc.o.i","") */

void xalloc_die(void) {

  {

    {}
  }
}
__inline static void *xnmalloc_inline(size_t n, size_t s) {
  void *p;

  {

    {}

    { p = malloc(n * s); }

    return (p);
  }
}
void *xmalloc(size_t n) {
  void *tmp;

  {
    { tmp = xnmalloc_inline(n, (size_t)1); }
    return (tmp);
  }
}
__inline static void *xnrealloc_inline(void *p, size_t n, size_t s) {

  { return (p); }
}
void *xrealloc(void *p, size_t n) {
  void *tmp;

  {
    { tmp = xnrealloc_inline(p, n, (size_t)1); }
    return (tmp);
  }
}

void *x2nrealloc(void *p, size_t *pn, size_t s) {

  {
    {}
  }
}
void *x2realloc(void *p, size_t *pn) {

  {
    {}
  }
}
void *xzalloc(size_t s) {
  void *tmp;
  void *tmp___0;

  {
    {
      tmp = xmalloc(s);
      tmp___0 = memset(tmp, 0, s);
    }
    return (tmp___0);
  }
}
void *xclone(void const *p, size_t s) {
  void *tmp;
  void *tmp___0;

  {
    {
      tmp = xmalloc(s);
      tmp___0 = memcpy((void * /* __restrict  */)tmp,
                       (void const * /* __restrict  */)p, s);
    }
    return (tmp___0);
  }
}
/* #pragma merger("0","02b.xstrdup.o.i","") */
char *xstrdup(char const *string) {
  size_t tmp;
  void *tmp___0;

  {
    {
      tmp = strlen(string);
      tmp___0 = xclone((void const *)string, tmp + 1UL);
    }
    return ((char *)tmp___0);
  }
}
/* #pragma merger("0","02c.xstrtol.o.i","") */

/* #pragma merger("0","02d.xstrtoul.o.i","") */

strtol_error xstrtoumax(char const *s, char **ptr, int strtol_base,
                        uintmax_t *val, char const *valid_suffixes) {

  char const *q;

  {

    q = s;
    {

      /* CIL Label */
      ;
    }

    {}
  }
}
/* #pragma merger("0","../../lib/addext.o.i","") */
/* #pragma merger("0","../../lib/argmatch.o.i","") */
/* #pragma merger("0","../../lib/backupfile.o.i","") */
/* #pragma merger("0","../../lib/basename.o.i","") */
/* #pragma merger("0","../../lib/dirname.o.i","") */
/* #pragma merger("0","../../lib/exclude.o.i","") */
/* #pragma merger("0","../../lib/exitfail.o.i","") */
/* #pragma merger("0","../../lib/full-write.o.i","") */
/* #pragma merger("0","../../lib/getdate.o.i","") */
/* #pragma merger("0","../../lib/getopt1.o.i","") */
/* #pragma merger("0","../../lib/getopt.o.i","") */
/* #pragma merger("0","../../lib/gettime.o.i","") */
/* #pragma merger("0","../../lib/hash.o.i","") */
/* #pragma merger("0","../../lib/human.o.i","") */
/* #pragma merger("0","../../lib/mktime.o.i","") */
/* #pragma merger("0","../../lib/modechange.o.i","") */
/* #pragma merger("0","../../lib/prepargs.o.i","") */
/* #pragma merger("0","../../lib/quotearg.o.i","") */
/* #pragma merger("0","../../lib/quote.o.i","") */
/* #pragma merger("0","../../lib/safe-read.o.i","") */
/* #pragma merger("0","../../lib/safe-write.o.i","") */
/* #pragma merger("0","../../lib/save-cwd.o.i","") */
/* #pragma merger("0","../../lib/savedir.o.i","") */
/* #pragma merger("0","../../lib/stripslash.o.i","") */
/* #pragma merger("0","../../lib/xgetcwd.o.i","") */
/* #pragma merger("0","../../lib/xmalloc.o.i","") */
/* #pragma merger("0","../../lib/xstrdup.o.i","") */
/* #pragma merger("0","../../lib/xstrtol.o.i","") */
/* #pragma merger("0","../../lib/xstrtoul.o.i","") */
/* #pragma merger("0","../../lib/xstrtoumax.o.i","") */
