typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;

typedef unsigned long size_t;

typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;

typedef __mode_t mode_t;

struct stat {};

struct hash_table;
typedef struct hash_table Hash_table;

struct ino_map;
typedef size_t hashint;

typedef unsigned long uintmax_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

struct _IO_FILE {

  char *_IO_read_ptr;

  int _fileno;
};
typedef __off_t off_t;

typedef long __ssize_t;
typedef __ssize_t ssize_t;

typedef struct __dirstream DIR;
enum numbered_backup_result {
  BACKUP_IS_SAME_LENGTH = 0,
  BACKUP_IS_LONGER = 1,
  BACKUP_IS_NEW = 2
};
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;

enum argv_iter_err {
  AI_ERR_OK = 1,
  AI_ERR_EOF = 2,
  AI_ERR_MEM = 3,
  AI_ERR_READ = 4
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

struct option {
  char const *name;

  int val;
};

struct _ftsent;

typedef struct __anonstruct_FTS_24 FTS;
struct _ftsent {};
typedef struct _ftsent FTSENT;

typedef enum __anonenum_arg_type_27 arg_type;

typedef struct __anonstruct_arguments_30 arguments;

typedef unsigned long uint64_t;

struct obstack {};

typedef unsigned long uint_least64_t;
typedef struct timezone *__restrict __timezone_ptr_t;
typedef uint_least64_t isaac_word;

struct quoting_options {
  enum quoting_style style;

  unsigned int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
  char const *left_quote;
  char const *right_quote;
};
struct slotvec {

  char *val;
};

typedef long long_time_t;

struct __anonstruct_relative_time_31 {

  long_time_t seconds;
};

union YYSTYPE {};

typedef unsigned char yytype_uint8;
typedef signed char yytype_int8;

enum __anonenum_mbs_align_t_1 {
  MBS_ALIGN_LEFT = 0,
  MBS_ALIGN_RIGHT = 1,
  MBS_ALIGN_CENTER = 2
};

struct linebuffer {
  size_t size;
  size_t length;
  char *buffer;
};

struct hash_entry {};

enum countmode { count_occurrences = 0, count_none = 1 };

enum Skip_field_option_type { SFO_NONE = 0, SFO_OBSOLETE = 1, SFO_NEW = 2 };

extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(
    size_t __size) __attribute__((__malloc__));

extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));

extern int close(int __fd);

extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(
    void *__ptr);

void close_stdout(void);
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

int volatile exit_failure;

static char const *file_name;
static _Bool ignore_EPIPE;
extern struct _IO_FILE *stdin;

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);


extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s)
    __attribute__((__pure__));

extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1, 2), __leaf__)) memmove)(void *__dest, void const *__src,
                                           size_t __n);

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));

int c_tolower(int c) __attribute__((__const__));


char *last_component(char const *name) __attribute__((__pure__));


extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream);

static void collate_error(int collation_errno, char const *s1, size_t s1len,
                          char const *s2, size_t s2len) {

  {
    {}
  }
}
int xmemcoll(char *s1, size_t s1len, char *s2, size_t s2len) {
  int diff;
  int tmp;
  int collation_errno;

  {
    {
      tmp = memcoll(s1, s1len, s2, s2len);
      diff = tmp;
    }
    if (collation_errno) {
      {
        collate_error(collation_errno, (char const *)s1, s1len,
                      (char const *)s2, s2len);
      }
    }
    return (diff);
  }
}

__inline static void *x2nrealloc(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {
    n = *pn;
    if (!p) {
      if (!n) {
        n = 128UL / s;
      }
    } else {

      n += (n + 1UL) / 2UL;
    }
    {
      *pn = n;
      tmp = xrealloc(p, n * s);
    }
    return (tmp);
  }
}

void *xmalloc(size_t n) {

  void *tmp;

  {
    { tmp = malloc(n); }
  }
}

void *xrealloc(void *p, size_t n) {

  {

    { p = realloc(p, n); }
    if (!p) {
      if (n) {
        {
        }
      }
    }
    return (p);
  }
}
void *x2realloc(void *p, size_t *pn) {
  void *tmp;

  {
    { tmp = x2nrealloc(p, pn, (size_t)1); }
    return (tmp);
  }
}


extern size_t fwrite(void const *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);

char const version_etc_copyright[47];
         
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) utimes)(char const *__file,
                                       struct timeval const *__tvp);

extern ssize_t write(int __fd, void const *__buf, size_t __n);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);

struct quoting_options quote_quoting_options;
__inline static char *xcharalloc(size_t n)
    __attribute__((__malloc__, __alloc_size__(1)));

static char slot0[256];
static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
void set_program_name(char const *argv0);

static yytype_uint8 const yytranslate[278] = {
    (yytype_uint8 const)0,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)26,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)27,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)25, (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)23, (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)24, (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)2,  (yytype_uint8 const)2,
    (yytype_uint8 const)2,  (yytype_uint8 const)1,  (yytype_uint8 const)2,
    (yytype_uint8 const)3,  (yytype_uint8 const)4,  (yytype_uint8 const)5,
    (yytype_uint8 const)6,  (yytype_uint8 const)7,  (yytype_uint8 const)8,
    (yytype_uint8 const)9,  (yytype_uint8 const)10, (yytype_uint8 const)11,
    (yytype_uint8 const)12, (yytype_uint8 const)13, (yytype_uint8 const)14,
    (yytype_uint8 const)15, (yytype_uint8 const)16, (yytype_uint8 const)17,
    (yytype_uint8 const)18, (yytype_uint8 const)19, (yytype_uint8 const)20,
    (yytype_uint8 const)21, (yytype_uint8 const)22};
static yytype_int8 const yypact[114] = {
    (yytype_int8 const)38,  (yytype_int8 const)27,  (yytype_int8 const)77,
    (yytype_int8 const)-93, (yytype_int8 const)46,  (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)62,
    (yytype_int8 const)-93, (yytype_int8 const)82,  (yytype_int8 const)-3,
    (yytype_int8 const)66,  (yytype_int8 const)3,   (yytype_int8 const)74,
    (yytype_int8 const)-4,  (yytype_int8 const)83,  (yytype_int8 const)84,
    (yytype_int8 const)75,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)71,  (yytype_int8 const)-93,
    (yytype_int8 const)93,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)78,  (yytype_int8 const)72,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)25,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)21,  (yytype_int8 const)19,  (yytype_int8 const)79,
    (yytype_int8 const)80,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)81,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)85,  (yytype_int8 const)86,  (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-6,  (yytype_int8 const)76,
    (yytype_int8 const)17,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)-93, (yytype_int8 const)87,
    (yytype_int8 const)69,  (yytype_int8 const)-93, (yytype_int8 const)-93,
    (yytype_int8 const)88,  (yytype_int8 const)89,  (yytype_int8 const)-1,
    (yytype_int8 const)-93, (yytype_int8 const)18,  (yytype_int8 const)-93,
    (yytype_int8 const)-93, (yytype_int8 const)69,  (yytype_int8 const)91};

static yytype_uint8 const yytable[113] = {
    (yytype_uint8 const)79,  (yytype_uint8 const)67,  (yytype_uint8 const)68,
    (yytype_uint8 const)69,  (yytype_uint8 const)70,  (yytype_uint8 const)71,
    (yytype_uint8 const)72,  (yytype_uint8 const)58,  (yytype_uint8 const)73,
    (yytype_uint8 const)100, (yytype_uint8 const)107, (yytype_uint8 const)74,
    (yytype_uint8 const)75,  (yytype_uint8 const)101, (yytype_uint8 const)110,
    (yytype_uint8 const)76,  (yytype_uint8 const)49,  (yytype_uint8 const)50,
    (yytype_uint8 const)101, (yytype_uint8 const)102, (yytype_uint8 const)113,
    (yytype_uint8 const)77,  (yytype_uint8 const)59,  (yytype_uint8 const)78,
    (yytype_uint8 const)61,  (yytype_uint8 const)62,  (yytype_uint8 const)63,
    (yytype_uint8 const)64,  (yytype_uint8 const)65,  (yytype_uint8 const)66,
    (yytype_uint8 const)61,  (yytype_uint8 const)62,  (yytype_uint8 const)63,
    (yytype_uint8 const)64,  (yytype_uint8 const)65,  (yytype_uint8 const)66,
    (yytype_uint8 const)101, (yytype_uint8 const)101, (yytype_uint8 const)92,
    (yytype_uint8 const)111, (yytype_uint8 const)90,  (yytype_uint8 const)91,
    (yytype_uint8 const)106, (yytype_uint8 const)112, (yytype_uint8 const)88,
    (yytype_uint8 const)111, (yytype_uint8 const)5,   (yytype_uint8 const)6,
    (yytype_uint8 const)7,   (yytype_uint8 const)8,   (yytype_uint8 const)88,
    (yytype_uint8 const)13,  (yytype_uint8 const)14,  (yytype_uint8 const)15,
    (yytype_uint8 const)16,  (yytype_uint8 const)17,  (yytype_uint8 const)18,
    (yytype_uint8 const)19,  (yytype_uint8 const)20,  (yytype_uint8 const)21,
    (yytype_uint8 const)22,  (yytype_uint8 const)1,   (yytype_uint8 const)23,
    (yytype_uint8 const)24,  (yytype_uint8 const)25,  (yytype_uint8 const)26,
    (yytype_uint8 const)27,  (yytype_uint8 const)28,  (yytype_uint8 const)29,
    (yytype_uint8 const)79,  (yytype_uint8 const)30,  (yytype_uint8 const)51,
    (yytype_uint8 const)52,  (yytype_uint8 const)53,  (yytype_uint8 const)54,
    (yytype_uint8 const)55,  (yytype_uint8 const)56,  (yytype_uint8 const)12,
    (yytype_uint8 const)57,  (yytype_uint8 const)61,  (yytype_uint8 const)62,
    (yytype_uint8 const)63,  (yytype_uint8 const)64,  (yytype_uint8 const)65,
    (yytype_uint8 const)66,  (yytype_uint8 const)60,  (yytype_uint8 const)48,
    (yytype_uint8 const)80,  (yytype_uint8 const)47,  (yytype_uint8 const)6,
    (yytype_uint8 const)83,  (yytype_uint8 const)8,   (yytype_uint8 const)81,
    (yytype_uint8 const)82,  (yytype_uint8 const)26,  (yytype_uint8 const)84,
    (yytype_uint8 const)85,  (yytype_uint8 const)86,  (yytype_uint8 const)87,
    (yytype_uint8 const)94,  (yytype_uint8 const)95,  (yytype_uint8 const)96,
    (yytype_uint8 const)89,  (yytype_uint8 const)105, (yytype_uint8 const)97,
    (yytype_uint8 const)98,  (yytype_uint8 const)99,  (yytype_uint8 const)0,
    (yytype_uint8 const)108, (yytype_uint8 const)109, (yytype_uint8 const)101,
    (yytype_uint8 const)0,   (yytype_uint8 const)88};
static yytype_int8 const yycheck[113] = {
    (yytype_int8 const)27,  (yytype_int8 const)5,   (yytype_int8 const)6,
    (yytype_int8 const)7,   (yytype_int8 const)8,   (yytype_int8 const)9,
    (yytype_int8 const)10,  (yytype_int8 const)4,   (yytype_int8 const)12,
    (yytype_int8 const)15,  (yytype_int8 const)102, (yytype_int8 const)15,
    (yytype_int8 const)16,  (yytype_int8 const)19,  (yytype_int8 const)15,
    (yytype_int8 const)19,  (yytype_int8 const)19,  (yytype_int8 const)20,
    (yytype_int8 const)19,  (yytype_int8 const)25,  (yytype_int8 const)112,
    (yytype_int8 const)25,  (yytype_int8 const)19,  (yytype_int8 const)27,
    (yytype_int8 const)5,   (yytype_int8 const)6,   (yytype_int8 const)7,
    (yytype_int8 const)8,   (yytype_int8 const)9,   (yytype_int8 const)10,
    (yytype_int8 const)5,   (yytype_int8 const)6,   (yytype_int8 const)7,
    (yytype_int8 const)8,   (yytype_int8 const)9,   (yytype_int8 const)10,
    (yytype_int8 const)19,  (yytype_int8 const)19,  (yytype_int8 const)19,
    (yytype_int8 const)107, (yytype_int8 const)19,  (yytype_int8 const)20,
    (yytype_int8 const)25,  (yytype_int8 const)25,  (yytype_int8 const)25,
    (yytype_int8 const)113, (yytype_int8 const)19,  (yytype_int8 const)20,
    (yytype_int8 const)21,  (yytype_int8 const)22,  (yytype_int8 const)25,
    (yytype_int8 const)5,   (yytype_int8 const)6,   (yytype_int8 const)7,
    (yytype_int8 const)8,   (yytype_int8 const)9,   (yytype_int8 const)10,
    (yytype_int8 const)11,  (yytype_int8 const)12,  (yytype_int8 const)13,
    (yytype_int8 const)14,  (yytype_int8 const)23,  (yytype_int8 const)16,
    (yytype_int8 const)17,  (yytype_int8 const)18,  (yytype_int8 const)19,
    (yytype_int8 const)20,  (yytype_int8 const)21,  (yytype_int8 const)22,
    (yytype_int8 const)96,  (yytype_int8 const)24,  (yytype_int8 const)5,
    (yytype_int8 const)6,   (yytype_int8 const)7,   (yytype_int8 const)8,
    (yytype_int8 const)9,   (yytype_int8 const)10,  (yytype_int8 const)0,
    (yytype_int8 const)12,  (yytype_int8 const)5,   (yytype_int8 const)6,
    (yytype_int8 const)7,   (yytype_int8 const)8,   (yytype_int8 const)9,
    (yytype_int8 const)10,  (yytype_int8 const)25,  (yytype_int8 const)4,
    (yytype_int8 const)27,  (yytype_int8 const)26,  (yytype_int8 const)20,
    (yytype_int8 const)30,  (yytype_int8 const)22,  (yytype_int8 const)9,
    (yytype_int8 const)9,   (yytype_int8 const)19,  (yytype_int8 const)24,
    (yytype_int8 const)3,   (yytype_int8 const)19,  (yytype_int8 const)26,
    (yytype_int8 const)20,  (yytype_int8 const)20,  (yytype_int8 const)20,
    (yytype_int8 const)59,  (yytype_int8 const)27,  (yytype_int8 const)84,
    (yytype_int8 const)20,  (yytype_int8 const)20,  (yytype_int8 const)-1,
    (yytype_int8 const)20,  (yytype_int8 const)20,  (yytype_int8 const)19,
    (yytype_int8 const)-1,  (yytype_int8 const)25};

static yytype_uint8 const yyr1[92] = {
    (yytype_uint8 const)0,  (yytype_uint8 const)28, (yytype_uint8 const)29,
    (yytype_uint8 const)29, (yytype_uint8 const)30, (yytype_uint8 const)31,
    (yytype_uint8 const)31, (yytype_uint8 const)32, (yytype_uint8 const)32,
    (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32,
    (yytype_uint8 const)32, (yytype_uint8 const)32, (yytype_uint8 const)32,
    (yytype_uint8 const)32, (yytype_uint8 const)33, (yytype_uint8 const)34,
    (yytype_uint8 const)35, (yytype_uint8 const)35, (yytype_uint8 const)35,
    (yytype_uint8 const)35, (yytype_uint8 const)36, (yytype_uint8 const)36,
    (yytype_uint8 const)36, (yytype_uint8 const)37, (yytype_uint8 const)37,
    (yytype_uint8 const)38, (yytype_uint8 const)39, (yytype_uint8 const)39,
    (yytype_uint8 const)40, (yytype_uint8 const)40, (yytype_uint8 const)40,
    (yytype_uint8 const)40, (yytype_uint8 const)40, (yytype_uint8 const)40,
    (yytype_uint8 const)40, (yytype_uint8 const)41, (yytype_uint8 const)41,
    (yytype_uint8 const)41, (yytype_uint8 const)41, (yytype_uint8 const)42,
    (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42,
    (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)42,
    (yytype_uint8 const)42, (yytype_uint8 const)42, (yytype_uint8 const)43,
    (yytype_uint8 const)44, (yytype_uint8 const)44, (yytype_uint8 const)44,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)45, (yytype_uint8 const)45, (yytype_uint8 const)45,
    (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)46,
    (yytype_uint8 const)46, (yytype_uint8 const)46, (yytype_uint8 const)46,
    (yytype_uint8 const)47, (yytype_uint8 const)48, (yytype_uint8 const)48,
    (yytype_uint8 const)49, (yytype_uint8 const)49, (yytype_uint8 const)50,
    (yytype_uint8 const)50, (yytype_uint8 const)51, (yytype_uint8 const)52,
    (yytype_uint8 const)53, (yytype_uint8 const)53};
static yytype_uint8 const yyr2[92] = {
    (yytype_uint8 const)0, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)2, (yytype_uint8 const)0,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)3,
    (yytype_uint8 const)2, (yytype_uint8 const)4, (yytype_uint8 const)6,
    (yytype_uint8 const)1, (yytype_uint8 const)2, (yytype_uint8 const)4,
    (yytype_uint8 const)6, (yytype_uint8 const)0, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)2,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)2,
    (yytype_uint8 const)2, (yytype_uint8 const)3, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)2,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)3,
    (yytype_uint8 const)5, (yytype_uint8 const)3, (yytype_uint8 const)3,
    (yytype_uint8 const)2, (yytype_uint8 const)4, (yytype_uint8 const)2,
    (yytype_uint8 const)3, (yytype_uint8 const)1, (yytype_uint8 const)3,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)2,
    (yytype_uint8 const)2, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)2,
    (yytype_uint8 const)2, (yytype_uint8 const)2, (yytype_uint8 const)2,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)1,
    (yytype_uint8 const)1, (yytype_uint8 const)1, (yytype_uint8 const)2,
    (yytype_uint8 const)0, (yytype_uint8 const)2};

__inline static int strcoll_loop(char const *s1, size_t s1size, char const *s2,
                                 size_t s2size) {
  int diff;
  size_t size1;

  int *tmp___1;

  int tmp___3;

  {
    {

      /* CIL Label */;
      {
        tmp___1 = __errno_location();

        diff = strcoll(s1, s2);
      }
      if (diff) {

      } else {
        {}
      }
      if (tmp___3) {
        goto while_break;
      }
      { s1size -= size1; }

    while_break: /* CIL Label */;
    }
    return (diff);
  }
}
int memcoll(char *s1, size_t s1len, char *s2, size_t s2len) {
  int diff;

  char n1;
  char n2;

  {
    if (s1len == s2len) {
      {
      }

    } else {
    _L: {
      n1 = *(s1 + s1len);
      n2 = *(s2 + s2len);
      *(s1 + s1len) = (char)'\000';
      *(s2 + s2len) = (char)'\000';
      diff = strcoll_loop((char const *)s1, s1len + 1UL, (char const *)s2,
                          s2len + 1UL);
      *(s1 + s1len) = n1;
      *(s2 + s2len) = n2;
    }
    }
    return (diff);
  }
}

int memcasecmp(void const *vs1, void const *vs2, size_t n) {

  char const *s2;

  {

    s2 = (char const *)vs2;

    { /* CIL Label */; }
  }
}

extern int optind;


struct linebuffer *readlinebuffer_delim(struct linebuffer *linebuffer,
                                        FILE *stream, char delimiter);
void initbuffer(struct linebuffer *linebuffer) {

  {
    { memset((void *)linebuffer, 0, sizeof(*linebuffer)); }
  }
}
struct linebuffer *readlinebuffer_delim(struct linebuffer *linebuffer,
                                        FILE *stream, char delimiter) {
  int c;
  char *buffer;
  char *p;
  char *end;
  int tmp;
  int tmp___0;
  size_t oldsize;
  char *tmp___1;

  {
    {
      buffer = linebuffer->buffer;
      p = linebuffer->buffer;
      end = buffer + linebuffer->size;
      tmp = feof_unlocked(stream);
    }

    {
      while (1) {
        /* CIL Label */;
        { c = getc_unlocked(stream); }
        if (c == -1) {
          if ((unsigned long)p == (unsigned long)buffer) {
            return ((struct linebuffer *)((void *)0));
          } else {
            {}
          }
          if ((int)*(p + -1) == (int)delimiter) {
            goto while_break;
          }
        }
        if ((unsigned long)p == (unsigned long)end) {
          {
            oldsize = linebuffer->size;
            buffer = (char *)x2realloc((void *)buffer, &linebuffer->size);
            p = buffer + oldsize;
            linebuffer->buffer = buffer;
            end = buffer + linebuffer->size;
          }
        }
        tmp___1 = p;
        p++;
        *tmp___1 = (char)c;
        if (!(c != (int)delimiter)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */;
    }
    linebuffer->length = (size_t)(p - buffer);
    return (linebuffer);
  }
}

extern __attribute__((__nothrow__))
__off_t(__attribute__((__leaf__)) lseek)(int __fd, __off_t __offset,
                                         int __whence);
int(__attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp, off_t offset,
                                                int whence) {

  off_t tmp___0;

  {

    {}
  }
}

static _Bool protect_fd(int fd) {

  int *tmp___0;

  {
    {}
  }
}
FILE *freopen_safer(char const *name, char const *mode, FILE *f) {
  _Bool protect_in;
  _Bool protect_out;
  _Bool protect_err;
  int saved_errno;
  int tmp;

  _Bool tmp___3;

  _Bool tmp___5;
  int *tmp___6;

  {
    {

      protect_err = (_Bool)0;
      tmp = fileno(f);
    }
    {

      if (tmp == 0) {
      }

      { /* CIL Label */
      }

      { /* CIL Label */
      }

      { /* CIL Label */
      }

    case_0: /* CIL Label */

        /* CIL Label */;
    }
    if (protect_in) {
      {
        tmp___5 = protect_fd(0);
      }
      if (tmp___5) {

      } else {
        f = (FILE *)((void *)0);
      }
    } else {
    _L___0:
      if (protect_out) {
        {
        }

      } else {
      _L:
        if (protect_err) {
          {
          }
          if (tmp___3) {
            {
              f = freopen((char const * /* __restrict  */)name,
                          (char const * /* __restrict  */)mode,
                          (FILE * /* __restrict  */)f);
            }
          } else {
            f = (FILE *)((void *)0);
          }
        } else {
          {
            f = freopen((char const * /* __restrict  */)name,
                        (char const * /* __restrict  */)mode,
                        (FILE * /* __restrict  */)f);
          }
        }
      }
    }
    {
      tmp___6 = __errno_location();
      saved_errno = *tmp___6;
    }
  }
}

extern int fclose(FILE *__stream);
int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {

  int fd;
  int result;
  int tmp;

  {
    { fd = fileno(fp); }
    if (fd < 0) {
      {
      }
      return (tmp);
    }
    {}

    { result = fclose(fp); }

    return (result);
  }
}

#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic ignored "-Wsuggest-attribute=pure"
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma weak pthread_mutex_init
#pragma weak pthread_mutex_lock
#pragma weak pthread_mutex_unlock
#pragma weak pthread_mutex_destroy
#pragma weak pthread_rwlock_init
#pragma weak pthread_rwlock_rdlock
#pragma weak pthread_rwlock_wrlock
#pragma weak pthread_rwlock_unlock
#pragma weak pthread_rwlock_destroy
#pragma weak pthread_once
#pragma weak pthread_cond_init
#pragma weak pthread_cond_wait
#pragma weak pthread_cond_signal
#pragma weak pthread_cond_broadcast
#pragma weak pthread_cond_destroy
#pragma weak pthread_mutexattr_init
#pragma weak pthread_mutexattr_settype
#pragma weak pthread_mutexattr_destroy
#pragma weak pthread_self
#pragma weak pthread_cancel
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"
char const *Version = "8.16";
extern char *optarg;

extern size_t fwrite_unlocked(void const *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream);

static _Bool hard_LC_COLLATE;
static size_t skip_fields;
static size_t skip_chars;
static size_t check_chars;
static enum countmode countmode;
static _Bool output_unique;
static _Bool output_first_repeated;
static _Bool output_later_repeated;
static _Bool ignore_case;

static struct option const longopts[12] = {
    {"count", 0, (int *)((void *)0), 'c'},
    {"repeated", 0, (int *)((void *)0), 'd'},
    {"all-repeated", 2, (int *)((void *)0), 'D'},
    {"ignore-case", 0, (int *)((void *)0), 'i'},
    {"unique", 0, (int *)((void *)0), 'u'},
    {"skip-fields", 1, (int *)((void *)0), 'f'},
    {"skip-chars", 1, (int *)((void *)0), 's'},
    {"check-chars", 1, (int *)((void *)0), 'w'},
    {"zero-terminated", 0, (int *)((void *)0), 'z'},
    {"help", 0, (int *)((void *)0), -130},
    {"version", 0, (int *)((void *)0), -131},
    {(char const *)((void *)0), 0, (int *)((void *)0), 0}};

void usage(int status) {

  {
    if (status != 0) {
      {
      }
    } else {
      {}
    }
    { exit(status); }
  }
}

static char *__attribute__((__pure__))
find_field(struct linebuffer const *line) {

  char const *lp;
  size_t size;
  size_t i;

  size_t tmp___3;

  {
    lp = (char const *)line->buffer;
    size = (size_t)(line->length - 1UL);
    i = (size_t)0;

    {

    while_break: /* CIL Label */;
    }
    if (skip_chars < size - i) {
      tmp___3 = skip_chars;
    } else {
    }
    i += tmp___3;
    return ((char * /* __attribute__((__pure__)) */)(line->buffer + i));
  }
}
static _Bool different(char *old, char *new, size_t oldlen, size_t newlen) {
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;

  {

    if (check_chars < newlen) {
      newlen = check_chars;
    }
    if (ignore_case) {
      if (oldlen != newlen) {

      } else {
        { tmp = memcasecmp((void const *)old, (void const *)new, oldlen); }
      }
      return ((_Bool)tmp___0);
    } else {
      if (hard_LC_COLLATE) {
        {
          tmp___1 = xmemcoll(old, oldlen, new, newlen);
        }

      } else {
        if (oldlen != newlen) {
          tmp___3 = 1;
        } else {
          { tmp___2 = memcmp((void const *)old, (void const *)new, oldlen); }
          if (tmp___2) {
            tmp___3 = 1;
          } else {
          }
        }
        return ((_Bool)tmp___3);
      }
    }
  }
}
static void writeline(struct linebuffer const *line, _Bool match,
                      uintmax_t linecount) {

  int tmp___0;

  {

    {
      fwrite_unlocked((void const * /* __restrict  */)line->buffer,
                      sizeof(char), (size_t)line->length,
                      (FILE * /* __restrict  */)stdout);
    }
  }
}
static void check_file(char const *infile, char const *outfile,
                       char delimiter) {
  struct linebuffer lb1;
  struct linebuffer lb2;
  struct linebuffer *thisline;
  struct linebuffer *prevline;

  int tmp___0;
  FILE *tmp___1;

  char *prevfield;
  size_t prevlen;
  char *thisfield;
  size_t thislen;
  struct linebuffer *tmp___5;
  struct linebuffer *_tmp;
  _Bool tmp___6;
  int tmp___7;
  char *prevfield___0;
  size_t prevlen___0;
  uintmax_t match_count;
  _Bool first_delimiter;
  struct linebuffer *tmp___8;
  _Bool match;
  char *thisfield___0;
  size_t thislen___0;
  int tmp___9;
  struct linebuffer *tmp___10;
  _Bool tmp___11;
  int tmp___12;

  int tmp___14;

  int tmp___16;
  int tmp___17;

  {
    {}
    if (!(tmp___0 == 0)) {
      {
        tmp___1 = freopen_safer(infile, "r", stdin);
      }
      if (!tmp___1) {
        {
        }
      }
    }
    {}

    {

      thisline = &lb1;
      prevline = &lb2;
      initbuffer(thisline);
      initbuffer(prevline);
    }
    if (output_unique) {
      if (output_first_repeated) {
        if ((unsigned int)countmode == 1U) {
          {
            while (1) {
            while_continue: /* CIL Label */;
              { tmp___7 = feof_unlocked(stdin); }
              if (tmp___7) {
                goto while_break;
              }
              { tmp___5 = readlinebuffer_delim(thisline, stdin, delimiter); }
              if ((unsigned long)tmp___5 ==
                  (unsigned long)((struct linebuffer *)0)) {
                goto while_break;
              }
              {
                thisfield =
                    (char *)find_field((struct linebuffer const *)thisline);
                thislen = (thisline->length - 1UL) -
                          (size_t)(thisfield - thisline->buffer);
              }
              if (prevline->length == 0UL) {
                goto _L;
              } else {
                { tmp___6 = different(thisfield, prevfield, thislen, prevlen); }
                if (tmp___6) {
                _L: {
                  fwrite_unlocked(
                      (void const * /* __restrict  */)thisline->buffer,
                      sizeof(char), thisline->length,
                      (FILE * /* __restrict  */)stdout);
                }
                  {

                    /* CIL Label */;
                    _tmp = prevline;
                    prevline = thisline;
                    thisline = _tmp;
                    goto while_break___0;

                  while_break___0: /* CIL Label */;
                  }
                  prevfield = thisfield;
                  prevlen = thislen;
                }
              }
            }
          while_break: /* CIL Label */;
          }
        } else {
        }
      } else {
        goto _L___2;
      }
    } else {
    _L___2: {
      match_count = (uintmax_t)0;
      first_delimiter = (_Bool)1;
      tmp___8 = readlinebuffer_delim(prevline, stdin, delimiter);
    }

      {

        prevlen___0 = (prevline->length - 1UL) -
                      (size_t)(prevfield___0 - prevline->buffer);
      }
      {
        while (1) {
          /* CIL Label */;
          { tmp___14 = feof_unlocked(stdin); }

          { tmp___10 = readlinebuffer_delim(thisline, stdin, delimiter); }

          {
            thisfield___0 =
                (char *)find_field((struct linebuffer const *)thisline);
            thislen___0 = (thisline->length - 1UL) -
                          (size_t)(thisfield___0 - thisline->buffer);
            tmp___11 = different(thisfield___0, prevfield___0, thislen___0,
                                 prevlen___0);
          }
          if (tmp___11) {

          } else {
          }
          match = (_Bool)tmp___12;
          match_count += (uintmax_t)match;

          if (!match) {
            goto _L___0;
          } else {
            if (output_later_repeated) {
            _L___0: {
              writeline((struct linebuffer const *)prevline, match,
                        match_count);
            }
              { /* CIL Label */; }
            }
          }
        }
        /* CIL Label */;
      }
      {}
    }
  closefiles: {}
    if (tmp___16) {
      {
      }
    } else {
      { tmp___17 = rpl_fclose(stdin); }
      if (tmp___17 != 0) {
        {
        }
      }
    }
    {}
    return;
  }
}
int main(int argc, char **argv) {
  int optc;
  _Bool posixly_correct;
  char *tmp;
  enum Skip_field_option_type skip_field_option_type;
  int nfiles;
  char const *file[2];
  char delimiter;
  char const *tmp___0;
  char *tmp___1;
  int tmp___2;

  unsigned long size;

  int tmp___6;

  {
    {

      posixly_correct =
          (_Bool)((unsigned long)tmp != (unsigned long)((void *)0));

      nfiles = 0;
      delimiter = (char)'\n';

      check_chars = 0xffffffffffffffffUL;
      output_first_repeated = (_Bool)1;
      output_unique = output_first_repeated;

      countmode = (enum countmode)1;
    }
    {

    while_continue: /* CIL Label */;
      if (optc == -1) {

      } else {
        if (posixly_correct) {
          if (nfiles != 0) {

          } else {
          }
        } else {
        _L___3: {
          optc =
              getopt_long(argc, (char *const *)argv, "-0123456789Dcdf:is:uw:z",
                          longopts, (int *)((void *)0));
        }
          if (optc == -1) {

            if (argc <= optind) {
              goto while_break;
            }

            nfiles++;

          } else {
            {
              if (optc == 1) {
              }

              if (optc == 55) {
              }

              if (optc == 100) {
              }

              if (optc == 115) {
              }
              if (optc == 117) {
                goto case_117;
              }

              if (optc == 122) {
              }

            case_1: /* CIL Label */
              if ((int)*(optarg + 0) == 43) {
                {
                }

              } else {
              _L___1:
                if (nfiles == 2) {
                  {
                  }
                } else {

                  nfiles++;
                  file[tmp___6] = (char const *)optarg;
                }
              }
              goto switch_break;
            case_48: /* CIL Label */
            case_49: /* CIL Label */
            case_50: /* CIL Label */
            case_51: /* CIL Label */
            case_52: /* CIL Label */
            case_53: /* CIL Label */
            case_54: /* CIL Label */
            case_55: /* CIL Label */
            case_56: /* CIL Label */
            case_57: /* CIL Label */

              /* CIL Label */

            case_100: /* CIL Label */

              /* CIL Label */
              output_unique = (_Bool)0;

              goto switch_break;
            case_102: { /* CIL Label */
              skip_field_option_type = (enum Skip_field_option_type)2;
              skip_fields = size_opt((char const *)optarg,
                                     "invalid number of fields to skip");
            }
              goto switch_break;
            case_105: /* CIL Label */
              ignore_case = (_Bool)1;
              goto switch_break;
            case_115: { /* CIL Label */
              skip_chars = size_opt((char const *)optarg,
                                    "invalid number of bytes to skip");
            }
              goto switch_break;
            case_117: /* CIL Label */
              output_first_repeated = (_Bool)0;
              goto switch_break;
            case_119: { /* CIL Label */
              check_chars = size_opt((char const *)optarg,
                                     "invalid number of bytes to compare");
            }
              goto switch_break;
            case_122: /* CIL Label */
              delimiter = (char)'\000';
              goto switch_break;
            case_neg_130: { /* CIL Label */
              usage(0);
            }
              goto switch_break;
            case_neg_131: { /* CIL Label */
              version_etc(stdout, "uniq", "GNU coreutils", Version,
                          "Richard M. Stallman", "David MacKenzie",
                          (char *)((void *)0));
              exit(0);
            }
              goto switch_break;
            switch_default: { /* CIL Label */
              usage(1);
            }
            switch_break: /* CIL Label */;
            }
          }
        }
      }

    while_break: /* CIL Label */;
    }

    { check_file(file[0], file[1], delimiter); }
  }
}
