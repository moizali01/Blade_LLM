typedef long __time_t;
typedef long __syscall_slong_t;
typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef unsigned long size_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef __uid_t uid_t;
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
typedef __ino_t ino_t;
typedef __dev_t dev_t;
struct hash_tuning {
  float shrink_threshold;
  float shrink_factor;
  float growth_threshold;
  float growth_factor;
  _Bool is_n_buckets;
};
typedef struct hash_tuning Hash_tuning;
struct hash_table;
struct hash_table;
struct hash_table;
typedef struct hash_table Hash_table;
typedef unsigned long uintmax_t;
typedef long __off64_t;
struct _IO_FILE;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
struct _IO_FILE {
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[(15UL * sizeof(int) - 4UL * sizeof(void *)) - sizeof(size_t)];
};
typedef __off_t off_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;
struct allocator;
struct allocator;
struct allocator;
struct allocator {
  void *(*allocate)(size_t);
  void *(*reallocate)(void *, size_t);
  void (*free)(void *);
  void (*die)(size_t);
};
typedef long ptrdiff_t;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
enum quoting_style { literal_quoting_style = 0, shell_quoting_style = 1, shell_always_quoting_style = 2, c_quoting_style = 3, c_maybe_quoting_style = 4, escape_quoting_style = 5, locale_quoting_style = 6, clocale_quoting_style = 7, custom_quoting_style = 8 };
enum strtol_error { LONGINT_OK = 0, LONGINT_OVERFLOW = 1, LONGINT_INVALID_SUFFIX_CHAR = 2, LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3, LONGINT_INVALID = 4 };
typedef enum strtol_error strtol_error;
struct option {
  char const *name;
  int has_arg;
  int *flag;
  int val;
};
typedef unsigned int uint32_t;
typedef int __pid_t;
typedef __pid_t pid_t;
typedef int wchar_t;
typedef int nl_item;
typedef unsigned int wint_t;
typedef long __suseconds_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
union __anonunion___value_23 {
  unsigned int __wch;
  char __wchb[4];
};
struct __anonstruct___mbstate_t_22 {
  int __count;
  union __anonunion___value_23 __value;
};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
typedef __mbstate_t mbstate_t;
struct mbchar {
  char const *ptr;
  size_t bytes;
  _Bool wc_valid;
  wchar_t wc;
  char buf[24];
};
struct __anonstruct___sigset_t_9 {
  unsigned long __val[1024UL / (8UL * sizeof(unsigned long))];
};
typedef struct __anonstruct___sigset_t_9 __sigset_t;
typedef __sigset_t sigset_t;
struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};
struct obstack;
struct obstack;
struct obstack;
struct _obstack_chunk {
  char *limit;
  struct _obstack_chunk *prev;
  char contents[4];
};
union __anonunion_temp_26 {
  long tempint;
  void *tempptr;
};
struct obstack {
  long chunk_size;
  struct _obstack_chunk *chunk;
  char *object_base;
  char *next_free;
  char *chunk_limit;
  union __anonunion_temp_26 temp;
  int alignment_mask;
  struct _obstack_chunk *(*chunkfun)(void *, long);
  void (*freefun)(void *, struct _obstack_chunk *);
  void *extra_arg;
  unsigned int use_extra_arg : 1;
  unsigned int maybe_empty_object : 1;
  unsigned int alloc_failed : 1;
};
struct Tokens {
  size_t n_tok;
  char **tok;
  size_t *tok_len;
  struct obstack o_data;
  struct obstack o_tok;
  struct obstack o_tok_len;
};
struct randread_source;
struct randread_source;
struct randread_source;
typedef unsigned long uint_least64_t;
typedef struct timezone *__restrict __timezone_ptr_t;
typedef uint_least64_t isaac_word;
struct isaac_state {
  isaac_word m[1 << 8];
  isaac_word a;
  isaac_word b;
  isaac_word c;
};
union __anonunion_data_31 {
  isaac_word w[1 << 8];
  unsigned char b[(unsigned long)(1 << 8) * sizeof(isaac_word)];
};
struct isaac {
  size_t buffered;
  struct isaac_state state;
  union __anonunion_data_31 data;
};
union __anonunion_buf_30 {
  char c[2UL * ((unsigned long)(1 << 8) * sizeof(isaac_word))];
  struct isaac isaac;
};
struct randread_source {
  FILE *source;
  void (*handler)(void const *);
  void const *handler_arg;
  union __anonunion_buf_30 buf;
};
struct quoting_options;
struct quoting_options;
struct quoting_options;
struct quoting_options {
  enum quoting_style style;
  int flags;
  unsigned int quote_these_too[255UL / (sizeof(int) * 8UL) + 1UL];
  char const *left_quote;
  char const *right_quote;
};
struct slotvec {
  size_t size;
  char *val;
};
struct mbuiter_multi {
  _Bool in_shift;
  mbstate_t state;
  _Bool next_done;
  struct mbchar cur;
};
typedef struct mbuiter_multi mbui_iterator_t;
enum nproc_query { NPROC_ALL = 0, NPROC_CURRENT = 1, NPROC_CURRENT_OVERRIDABLE = 2 };
typedef unsigned long __cpu_mask;
struct __anonstruct_cpu_set_t_24 {
  __cpu_mask __bits[1024UL / (8UL * sizeof(__cpu_mask))];
};
typedef struct __anonstruct_cpu_set_t_24 cpu_set_t;
struct md5_ctx {
  uint32_t A;
  uint32_t B;
  uint32_t C;
  uint32_t D;
  uint32_t total[2];
  uint32_t buflen;
  uint32_t buffer[32];
};
struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  short __spins;
  short __elision;
  __pthread_list_t __list;
};
union __anonunion_pthread_mutex_t_11 {
  struct __pthread_mutex_s __data;
  char __size[40];
  long __align;
};
typedef union __anonunion_pthread_mutex_t_11 pthread_mutex_t;
union __anonunion_pthread_mutexattr_t_12 {
  char __size[4];
  int __align;
};
typedef union __anonunion_pthread_mutexattr_t_12 pthread_mutexattr_t;
struct lconv {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};
struct heap;
struct heap;
struct heap;
struct heap {
  void **array;
  size_t capacity;
  size_t count;
  int (*compare)(void const *, void const *);
};
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
  Hash_tuning const *tuning;
  size_t (*hasher)(void const *, size_t);
  _Bool (*comparator)(void const *, void const *);
  void (*data_freer)(void *);
  struct hash_entry *free_entry_list;
};
struct F_triple {
  char *name;
  ino_t st_ino;
  dev_t st_dev;
};
typedef long __clock_t;
union sigval {
  int sival_int;
  void *sival_ptr;
};
typedef union sigval sigval_t;
typedef __clock_t __sigchld_clock_t;
struct __anonstruct__kill_23 {
  __pid_t si_pid;
  __uid_t si_uid;
};
struct __anonstruct__timer_24 {
  int si_tid;
  int si_overrun;
  sigval_t si_sigval;
};
struct __anonstruct__rt_25 {
  __pid_t si_pid;
  __uid_t si_uid;
  sigval_t si_sigval;
};
struct __anonstruct__sigchld_26 {
  __pid_t si_pid;
  __uid_t si_uid;
  int si_status;
  __sigchld_clock_t si_utime;
  __sigchld_clock_t si_stime;
};
struct __anonstruct__sigfault_27 {
  void *si_addr;
  short si_addr_lsb;
};
struct __anonstruct__sigpoll_28 {
  long si_band;
  int si_fd;
};
struct __anonstruct__sigsys_29 {
  void *_call_addr;
  int _syscall;
  unsigned int _arch;
};
union __anonunion__sifields_22 {
  int _pad[128UL / sizeof(int) - 4UL];
  struct __anonstruct__kill_23 _kill;
  struct __anonstruct__timer_24 _timer;
  struct __anonstruct__rt_25 _rt;
  struct __anonstruct__sigchld_26 _sigchld;
  struct __anonstruct__sigfault_27 _sigfault;
  struct __anonstruct__sigpoll_28 _sigpoll;
  struct __anonstruct__sigsys_29 _sigsys;
};
struct __anonstruct_siginfo_t_21 {
  int si_signo;
  int si_errno;
  int si_code;
  union __anonunion__sifields_22 _sifields;
};
typedef struct __anonstruct_siginfo_t_21 siginfo_t;
union __anonunion___sigaction_handler_41 {
  void (*sa_handler)(int);
  void (*sa_sigaction)(int, siginfo_t *, void *);
};
struct sigaction {
  union __anonunion___sigaction_handler_41 __sigaction_handler;
  __sigset_t sa_mask;
  int sa_flags;
  void (*sa_restorer)(void);
};
enum __anonenum_fadvice_t_19 { FADVISE_NORMAL = 0, FADVISE_SEQUENTIAL = 2, FADVISE_NOREUSE = 5, FADVISE_DONTNEED = 4, FADVISE_WILLNEED = 3, FADVISE_RANDOM = 1 };
typedef enum __anonenum_fadvice_t_19 fadvice_t;
typedef unsigned long __rlim_t;
typedef unsigned long pthread_t;
union pthread_attr_t {
  char __size[56];
  long __align;
};
typedef union pthread_attr_t pthread_attr_t;
struct __anonstruct___data_7 {
  int __lock;
  unsigned int __futex;
  unsigned long long __total_seq;
  unsigned long long __wakeup_seq;
  unsigned long long __woken_seq;
  void *__mutex;
  unsigned int __nwaiters;
  unsigned int __broadcast_seq;
};
union __anonunion_pthread_cond_t_6 {
  struct __anonstruct___data_7 __data;
  char __size[48];
  long long __align;
};
typedef union __anonunion_pthread_cond_t_6 pthread_cond_t;
union __anonunion_pthread_condattr_t_8 {
  char __size[4];
  int __align;
};
typedef union __anonunion_pthread_condattr_t_8 pthread_condattr_t;
typedef void (*__sighandler_t)(int);
enum __rlimit_resource {
  RLIMIT_CPU = 0,
  RLIMIT_FSIZE = 1,
  RLIMIT_DATA = 2,
  RLIMIT_STACK = 3,
  RLIMIT_CORE = 4,
  __RLIMIT_RSS = 5,
  RLIMIT_NOFILE = 7,
  __RLIMIT_OFILE = 7,
  RLIMIT_AS = 9,
  __RLIMIT_NPROC = 6,
  __RLIMIT_MEMLOCK = 8,
  __RLIMIT_LOCKS = 10,
  __RLIMIT_SIGPENDING = 11,
  __RLIMIT_MSGQUEUE = 12,
  __RLIMIT_NICE = 13,
  __RLIMIT_RTPRIO = 14,
  __RLIMIT_RTTIME = 15,
  __RLIMIT_NLIMITS = 16,
  __RLIM_NLIMITS = 16
};
typedef __rlim_t rlim_t;
struct rlimit {
  rlim_t rlim_cur;
  rlim_t rlim_max;
};
typedef enum __rlimit_resource __rlimit_resource_t;
enum blanktype { bl_start = 0, bl_end = 1, bl_both = 2 };
struct line {
  char *text;
  size_t length;
  char *keybeg;
  char *keylim;
};
struct buffer {
  char *buf;
  size_t used;
  size_t nlines;
  size_t alloc;
  size_t left;
  size_t line_bytes;
  _Bool eof;
};
struct keyfield {
  size_t sword;
  size_t schar;
  size_t eword;
  size_t echar;
  _Bool const *ignore;
  char const *translate;
  _Bool skipsblanks;
  _Bool skipeblanks;
  _Bool numeric;
  _Bool random;
  _Bool general_numeric;
  _Bool human_numeric;
  _Bool month;
  _Bool reverse;
  _Bool version;
  _Bool obsolete_used;
  struct keyfield *next;
};
struct month {
  char const *name;
  int val;
};
struct merge_node {
  struct line *lo;
  struct line *hi;
  struct line *end_lo;
  struct line *end_hi;
  struct line **dest;
  size_t nlo;
  size_t nhi;
  struct merge_node *parent;
  struct merge_node *lo_child;
  struct merge_node *hi_child;
  unsigned int level;
  _Bool queued;
  pthread_mutex_t lock;
};
struct merge_node_queue {
  struct heap *priority_queue;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
};
struct cs_status {
  _Bool valid;
  sigset_t sigs;
};
struct tempnode {
  struct tempnode *volatile next;
  pid_t pid;
  char state;
  char name[1];
};
struct sortfile {
  char const *name;
  struct tempnode *temp;
};
union __anonunion_101 {
  int __in;
  int __i;
};
union __anonunion_102 {
  int __in;
  int __i;
};
struct thread_args {
  struct line *lines;
  size_t nthreads;
  size_t total_lines;
  struct merge_node *node;
  struct merge_node_queue *queue;
  FILE *tfp;
  char const *output_temp;
};
struct timespec dtotimespec(double sec);
__attribute__((__noreturn__)) void xalloc_die(void);
char *last_component(char const *name) __attribute__((__pure__));
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int *(__attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file, struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd, struct stat *__buf);
extern int close(int __fd);
char const diacrit_base[256];
char const diacrit_diac[256];
char const diacrit_base[256] = {
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)'A', (char const)'B', (char const)'C', (char const)'D', (char const)'E', (char const)'F', (char const)'G', (char const)'H', (char const)'I', (char const)'J', (char const)'K', (char const)'L', (char const)'M', (char const)'N', (char const)'O',
    (char const)'P', (char const)'Q', (char const)'R', (char const)'S', (char const)'T', (char const)'U', (char const)'V', (char const)'W', (char const)'X', (char const)'Y', (char const)'Z', (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)'a', (char const)'b', (char const)'c', (char const)'d', (char const)'e', (char const)'f', (char const)'g', (char const)'h', (char const)'i', (char const)'j', (char const)'k', (char const)'l', (char const)'m', (char const)'n', (char const)'o',
    (char const)'p', (char const)'q', (char const)'r', (char const)'s', (char const)'t', (char const)'u', (char const)'v', (char const)'w', (char const)'x', (char const)'y', (char const)'z', (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,   (char const)0,
    (char const)'A', (char const)'A', (char const)'A', (char const)'A', (char const)'A', (char const)'A', (char const)'A', (char const)'C', (char const)'E', (char const)'E', (char const)'E', (char const)'E', (char const)'I', (char const)'I', (char const)'I', (char const)'I',
    (char const)0,   (char const)'N', (char const)'O', (char const)'O', (char const)'O', (char const)'O', (char const)'O', (char const)0,   (char const)'O', (char const)'U', (char const)'U', (char const)'U', (char const)'U', (char const)'Y', (char const)0,   (char const)0,
    (char const)'a', (char const)'a', (char const)'a', (char const)'a', (char const)'a', (char const)'a', (char const)'a', (char const)'c', (char const)'e', (char const)'e', (char const)'e', (char const)'e', (char const)'i', (char const)'i', (char const)'i', (char const)'i',
    (char const)0,   (char const)'n', (char const)'o', (char const)'o', (char const)'o', (char const)'o', (char const)'o', (char const)0,   (char const)'o', (char const)'u', (char const)'u', (char const)'u', (char const)'u', (char const)'y', (char const)0,   (char const)'y'};
char const diacrit_diac[256] = {
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)4,
    (char const)0, (char const)3, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)6, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)3, (char const)2, (char const)4, (char const)6, (char const)5, (char const)8, (char const)1, (char const)7, (char const)3, (char const)2, (char const)4, (char const)5, (char const)3, (char const)2, (char const)4, (char const)5, (char const)0,
    (char const)6, (char const)3, (char const)2, (char const)4, (char const)6, (char const)5, (char const)0, (char const)9, (char const)3, (char const)2, (char const)4, (char const)5, (char const)2, (char const)0, (char const)0, (char const)3, (char const)2, (char const)4, (char const)6,
    (char const)5, (char const)8, (char const)1, (char const)7, (char const)3, (char const)2, (char const)4, (char const)5, (char const)3, (char const)2, (char const)4, (char const)5, (char const)0, (char const)6, (char const)3, (char const)2, (char const)4, (char const)6, (char const)5,
    (char const)0, (char const)9, (char const)3, (char const)2, (char const)4, (char const)5, (char const)2, (char const)0, (char const)0};
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(size_t candidate, Hash_tuning const *tuning, size_t (*hasher)(void const *, size_t), _Bool (*comparator)(void const *, void const *), void (*data_freer)(void *));
void *(__attribute__((__warn_unused_result__)) hash_insert)(Hash_table *table___0, void const *entry);
int hash_insert_if_absent(Hash_table *table___0, void const *entry, void const **matched_ent);
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(void *__ptr);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) __assert_fail)(char const *__assertion, char const *__file, unsigned int __line, char const *__function);
int fd_safer(int fd);
extern void error(int __status, int __errnum, char const *__format, ...);
char const *quote(char const *name);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) gettext)(char const *__msgid) __attribute__((__format_arg__(1)));
void close_stdout(void);
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern __attribute__((__noreturn__)) void _exit(int __status);
int close_stream(FILE *stream);
int volatile exit_failure;
char *quotearg_colon(char const *arg);
static char const *file_name;
static _Bool ignore_EPIPE;
void close_stdout(void) {
  char const *write_error;
  char const *tmp;

  int tmp___3;
  int *tmp___4;
  int tmp___5;

  {
    tmp___3 = close_stream(stdout);
    if (tmp___3 != 0) {
      if (ignore_EPIPE) {
        tmp___4 = __errno_location();

      } else {
        ;
        tmp = (char const *)gettext("write error");
        write_error = tmp;

        _exit((int)exit_failure);
      }
    }
    tmp___5 = close_stream(stderr);
    if (tmp___5 != 0) {
      _exit((int)exit_failure);
    }
    return;
  }
}
extern struct _IO_FILE *stdin;
int rpl_fflush(FILE *stream);
int(__attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp, off_t offset, int whence);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ferror_unlocked)(FILE *__stream);
int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp);
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) __fpending)(FILE *__fp);
int close_stream(FILE *stream) {
  _Bool some_pending;
  size_t tmp;
  _Bool prev_fail;
  int tmp___0;
  _Bool fclose_fail;
  int tmp___1;

  int *tmp___3;

  {
    tmp = __fpending(stream);
    some_pending = (_Bool)(tmp != 0UL);
    tmp___0 = ferror_unlocked(stream);
    prev_fail = (_Bool)(tmp___0 != 0);
    tmp___1 = rpl_fclose(stream);
    fclose_fail = (_Bool)(tmp___1 != 0);
    if (prev_fail) {
      goto _L___0;
    } else {
      if (fclose_fail) {
        if (some_pending) {
          goto _L___0;
        } else {
          tmp___3 = __errno_location();
          if (*tmp___3 != 9) {
          _L___0:;
            return (-1);
          }
        }
      }
    }
    return (0);
  }
}
int rpl_fcntl(int fd, int action, ...);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1), __leaf__)) memchr)(void const *__s, int __c, size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s) __attribute__((__pure__));
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) abort)(void);
struct allocator const stdlib_allocator;
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memmove)(void *__dest, void const *__src, size_t __n);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strchr)(char const *__s, int __c) __attribute__((__pure__));
size_t triple_hash(void const *x, size_t table_size) __attribute__((__pure__));
_Bool triple_compare_ino_str(void const *x, void const *y) __attribute__((__pure__));
void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strdup)(char const *__s) __attribute__((__malloc__));
int c_tolower(int c) __attribute__((__const__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));
int c_strcasecmp(char const *s1, char const *s2) __attribute__((__pure__));
_Bool c_isalnum(int c) __attribute__((__const__));
_Bool c_isalpha(int c) __attribute__((__const__));
_Bool c_isdigit(int c) __attribute__((__const__));
_Bool c_isspace(int c) __attribute__((__const__));
_Bool c_isalnum(int c) __attribute__((__const__));
_Bool c_isalpha(int c) __attribute__((__const__));
_Bool c_isdigit(int c) __attribute__((__const__));
_Bool c_isdigit(int c) {}
_Bool c_isspace(int c) __attribute__((__const__));
_Bool c_isspace(int c) {}
int c_tolower(int c) __attribute__((__const__));
char *last_component(char const *name) __attribute__((__pure__));
__inline static unsigned char to_uchar(char ch) {

  { return ((unsigned char)ch); }
}
char const *simple_backup_suffix;
void (*argmatch_die)(void);
ptrdiff_t __xargmatch_internal(char const *context, char const *arg, char const *const *arglist, char const *vallist, size_t valsize, void (*exit_fn)(void));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2, size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest, char const *__restrict __src);
char const *simple_backup_suffix = "~";
ptrdiff_t argmatch(char const *arg, char const *const *arglist, char const *vallist, size_t valsize) __attribute__((__pure__));
void argmatch_invalid(char const *context, char const *value, ptrdiff_t problem);
void argmatch_valid(char const *const *arglist, char const *vallist, size_t valsize);
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format, ...);
extern int putc_unlocked(int __c, FILE *__stream);
extern int fputs_unlocked(char const *__restrict __s, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strncmp)(char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
char *quotearg_n_style(int n, enum quoting_style s, char const *arg);
char const *quote_n(int n, char const *name);
__attribute__((__noreturn__)) void usage(int status);
static void __argmatch_die(void) {

  {
    usage(1);
    return;
  }
}
void (*argmatch_die)(void) = &__argmatch_die;
ptrdiff_t argmatch(char const *arg, char const *const *arglist, char const *vallist, size_t valsize) __attribute__((__pure__));
ptrdiff_t __xargmatch_internal(char const *context, char const *arg, char const *const *arglist, char const *vallist, size_t valsize, void (*exit_fn)(void)) {}
extern __attribute__((__nothrow__)) void *(__attribute__((__warn_unused_result__, __leaf__)) realloc)(void *__ptr, size_t __size);
struct allocator const stdlib_allocator = {(void *(*)(size_t))(&malloc), (void *(*)(void *, size_t))(&realloc), (void (*)(void *))(&free), (void (*)(size_t))((void *)0)};
__inline static void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__, __alloc_size__(1, 2)));
__inline static void *xnmalloc(size_t n, size_t s) __attribute__((__malloc__, __alloc_size__(1, 2)));
__inline static void *xnmalloc(size_t n, size_t s) {
  int tmp;
  void *tmp___0;

  {
    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp = -1;
    } else {
      tmp = -2;
    }
    if ((size_t)tmp / s < n) {
      xalloc_die();
    }
    tmp___0 = xmalloc(n * s);
    return (tmp___0);
  }
}
extern __attribute__((__nothrow__)) unsigned short const **(__attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) uintmax_t(__attribute__((__leaf__)) strtoumax)(char const *__restrict __nptr, char **__restrict __endptr, int __base);
strtol_error xstrtoumax(char const *s, char **ptr, int strtol_base, uintmax_t *val, char const *valid_suffixes);
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base, unsigned long *val, char const *valid_suffixes);
extern __attribute__((__nothrow__)) unsigned long(__attribute__((__nonnull__(1), __leaf__)) strtoul)(char const *__restrict __nptr, char **__restrict __endptr, int __base);
static strtol_error bkm_scale___0(unsigned long *x, int scale_factor) {

  {
    if (0xffffffffffffffffUL / (unsigned long)scale_factor < *x) {
      *x = 0xffffffffffffffffUL;
      return ((strtol_error)1);
    }
    *x *= (unsigned long)scale_factor;
    return ((strtol_error)0);
  }
}
static strtol_error bkm_scale_by_power___0(unsigned long *x, int base, int power) {}
strtol_error xstrtoul(char const *s, char **ptr, int strtol_base, unsigned long *val, char const *valid_suffixes) {

  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;

  int *tmp___1;

  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;
  char *tmp___6;

  {
    err = (strtol_error)0;

    q = s;
    ch = (unsigned char)*q;

    ;

    tmp___1 = __errno_location();
    *tmp___1 = 0;
    tmp = strtoul(s, p, strtol_base);

    if ((int)*(*p) != 0) {
      base = 1024;
      suffixes = 1;
      tmp___5 = strchr(valid_suffixes, (int)*(*p));

      tmp___6 = strchr(valid_suffixes, '0');

      if ((int)*(*p) == 66) {
        goto case_66___0;
      }
      if ((int)*(*p) == 99) {
        goto case_99;
      }

      if ((int)*(*p) == 107) {
        goto case_107;
      }

      if ((int)*(*p) == 109) {
        goto case_77;
      }

      if ((int)*(*p) == 116) {
        goto case_84;
      }

      goto switch_default;
      ;
      overflow = bkm_scale___0(&tmp, 512);
      goto switch_break___0;
    case_66___0:;
      overflow = bkm_scale___0(&tmp, 1024);
      goto switch_break___0;
    case_99:;
      overflow = (strtol_error)0;
      goto switch_break___0;
      ;
      overflow = bkm_scale_by_power___0(&tmp, base, 6);
      goto switch_break___0;
      ;
      overflow = bkm_scale_by_power___0(&tmp, base, 3);
      goto switch_break___0;
    case_107:;
      overflow = bkm_scale_by_power___0(&tmp, base, 1);
      goto switch_break___0;
    case_77:;
      overflow = bkm_scale_by_power___0(&tmp, base, 2);
      goto switch_break___0;
      ;
      overflow = bkm_scale_by_power___0(&tmp, base, 5);
      goto switch_break___0;
    case_84:;
      overflow = bkm_scale_by_power___0(&tmp, base, 4);
      goto switch_break___0;
      ;
      overflow = bkm_scale___0(&tmp, 2);
      goto switch_break___0;
      ;
      overflow = bkm_scale_by_power___0(&tmp, base, 8);
      goto switch_break___0;
      ;
      overflow = bkm_scale_by_power___0(&tmp, base, 7);
      goto switch_break___0;
    switch_default:;
      *val = tmp;
      return ((strtol_error)((unsigned int)err | 2U));
    switch_break___0:;
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
      *p += suffixes;
    }
    *val = tmp;
    return (err);
  }
}
extern __attribute__((__nothrow__)) long(__attribute__((__nonnull__(1), __leaf__)) strtol)(char const *__restrict __nptr, char **__restrict __endptr, int __base);
__attribute__((__noreturn__)) void xstrtol_fatal(enum strtol_error err, int opt_idx, char c, struct option const *long_options___2, char const *arg);
__attribute__((__noreturn__)) void xstrtol_fatal(enum strtol_error err, int opt_idx, char c, struct option const *long_options___2, char const *arg);
void xstrtol_fatal(enum strtol_error err, int opt_idx, char c, struct option const *long_options___2, char const *arg) {}
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ferror)(FILE *__stream);
int xnanosleep(double seconds);
int(__attribute__((__nonnull__(1))) rpl_nanosleep)(struct timespec const *requested_delay, struct timespec *remaining_delay);
int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size);
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg, size_t argsize);
int xmemcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size);
static void collate_error(int collation_errno, char const *s1, size_t s1len, char const *s2, size_t s2len) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;

  {
    tmp = gettext("string comparison failed");
    error(0, collation_errno, (char const *)tmp);
    tmp___0 = gettext("Set LC_ALL=\'C\' to work around the problem.");
    error(0, 0, (char const *)tmp___0);
    tmp___1 = quotearg_n_style_mem(1, (enum quoting_style)6, s2, s2len);
    tmp___2 = quotearg_n_style_mem(0, (enum quoting_style)6, s1, s1len);
    tmp___3 = gettext("The strings compared were %s and %s.");
    error((int)exit_failure, 0, (char const *)tmp___3, tmp___2, tmp___1);
    return;
  }
}
int xmemcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {
  int diff;
  int tmp;
  int collation_errno;
  int *tmp___0;

  {
    tmp = memcoll0(s1, s1size, s2, s2size);
    diff = tmp;
    tmp___0 = __errno_location();
    collation_errno = *tmp___0;
    if (collation_errno) {
      collate_error(collation_errno, s1, s1size - 1UL, s2, s2size - 1UL);
    }
    return (diff);
  }
}
void *xcalloc(size_t n, size_t s) __attribute__((__malloc__, __alloc_size__(1, 2)));
void *xmemdup(void const *p, size_t s) __attribute__((__malloc__, __alloc_size__(2)));
__inline static void *x2nrealloc(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {
    n = *pn;
    if (!p) {
      if (!n) {
        n = 128UL / s;
        n += (size_t)(!n);
      }
    } else {
      if (0xaaaaaaaaaaaaaaaaUL / s <= n) {
        xalloc_die();
      }
      n += (n + 1UL) / 2UL;
    }
    *pn = n;
    tmp = xrealloc(p, n * s);
    return (tmp);
  }
}
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) calloc)(size_t __nmemb, size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1), __leaf__)) memset)(void *__s, int __c, size_t __n);
void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xmalloc(size_t n) {
  void *p;
  void *tmp;

  {
    tmp = malloc(n);
    p = tmp;
    if (!p) {
      if (n != 0UL) {
        xalloc_die();
      }
    }
    return (p);
  }
}
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));
void *xrealloc(void *p, size_t n) {

  {

    p = realloc(p, n);

    return (p);
  }
}
void *xcalloc(size_t n, size_t s) __attribute__((__malloc__, __alloc_size__(1, 2)));
void *xcalloc(size_t n, size_t s) {
  void *p;

  {
    p = calloc(n, s);
    if (!p) {
      xalloc_die();
    }
    return (p);
  }
}
void *xmemdup(void const *p, size_t s) __attribute__((__malloc__, __alloc_size__(2)));
__attribute__((__noreturn__)) void xalloc_die(void);
void xalloc_die(void) {}
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2) __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) atexit)(void (*__func)(void));
extern __pid_t waitpid(__pid_t __pid, int *__stat_loc, int __options);
extern int printf(char const *__restrict __format, ...);
char const version_etc_copyright[47];
void version_etc_arn(FILE *stream, char const *command_name, char const *package, char const *version, char const *const *authors, size_t n_authors);
void version_etc_va(FILE *stream, char const *command_name, char const *package, char const *version, va_list authors);
void version_etc(FILE *stream, char const *command_name, char const *package, char const *version, ...) __attribute__((__sentinel__));
void version_etc(FILE *stream, char const *command_name, char const *package, char const *version, ...) __attribute__((__sentinel__));
void version_etc(FILE *stream, char const *command_name, char const *package, char const *version, ...) {}
char const version_etc_copyright[47] = {(char const)'C', (char const)'o', (char const)'p', (char const)'y', (char const)'r', (char const)'i', (char const)'g', (char const)'h', (char const)'t', (char const)' ', (char const)'%',   (char const)'s',
                                        (char const)' ', (char const)'%', (char const)'d', (char const)' ', (char const)'F', (char const)'r', (char const)'e', (char const)'e', (char const)' ', (char const)'S', (char const)'o',   (char const)'f',
                                        (char const)'t', (char const)'w', (char const)'a', (char const)'r', (char const)'e', (char const)' ', (char const)'F', (char const)'o', (char const)'u', (char const)'n', (char const)'d',   (char const)'a',
                                        (char const)'t', (char const)'i', (char const)'o', (char const)'n', (char const)',', (char const)' ', (char const)'I', (char const)'n', (char const)'c', (char const)'.', (char const)'\000'};
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) nl_langinfo)(nl_item __item);
char *(__attribute__((__warn_unused_result__)) umaxtostr)(uintmax_t i, char *buf___1);
char const *locale_charset(void);
char *(__attribute__((__warn_unused_result__)) uinttostr)(unsigned int i, char *buf___1);
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) __ctype_get_mb_cur_max)(void);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) mbsinit)(mbstate_t const *__ps) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__leaf__)) mbrtowc)(wchar_t *__restrict __pwc, char const *__restrict __s, size_t __n, mbstate_t *__restrict __p);
unsigned int const is_basic_table[8];
__inline static _Bool is_basic(char c) {

  { return ((_Bool)((is_basic_table[(int)((unsigned char)c) >> 5] >> ((int)((unsigned char)c) & 31)) & 1U)); }
}
extern int(__attribute__((__nonnull__(1))) open)(char const *__file, int __oflag, ...);
int __attribute__((__pure__)) strnumcmp(char const *a, char const *b, int decimal_point___0, int thousands_sep___0);
size_t strnlen1(char const *string, size_t maxlen) __attribute__((__pure__));
size_t strnlen1(char const *string, size_t maxlen) __attribute__((__pure__));
size_t strnlen1(char const *string, size_t maxlen) {}
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) tolower)(int __c);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) toupper)(int __c);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) sigprocmask)(int __how, sigset_t const *__restrict __set, sigset_t *__restrict __oset);
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) feof_unlocked)(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) raise)(int __sig);
extern __attribute__((__nothrow__)) __pid_t fork(void);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) unlink)(char const *__name);
extern int fgetc(FILE *__stream);
extern void _obstack_newchunk(struct obstack *, int);
extern int _obstack_begin(struct obstack *, int, int, void *(*)(long), void (*)(void *));
extern FILE *fopen(char const *__restrict __filename, char const *__restrict __modes);
void readtokens0_init(struct Tokens *t);
_Bool readtokens0(FILE *in, struct Tokens *t);
void readtokens0_init(struct Tokens *t) {

  {
    t->n_tok = (size_t)0;
    t->tok = (char **)((void *)0);
    t->tok_len = (size_t *)((void *)0);
    _obstack_begin(&t->o_data, 0, 0, (void *(*)(long))(&malloc), (void (*)(void *))(&free));
    _obstack_begin(&t->o_tok, 0, 0, (void *(*)(long))(&malloc), (void (*)(void *))(&free));
    _obstack_begin(&t->o_tok_len, 0, 0, (void *(*)(long))(&malloc), (void (*)(void *))(&free));
    return;
  }
}
static void save_token(struct Tokens *t) {
  size_t len;
  struct obstack const *__o;
  char const *s;
  struct obstack *__o1;
  void *__value;
  char *tmp;
  char *tmp___0;
  struct obstack *__o___0;
  struct obstack *__o1___0;
  struct obstack *__o___1;
  int __len;

  {
    __o = (struct obstack const *)(&t->o_data);
    len = (size_t)((unsigned int)(__o->next_free - __o->object_base) - 1U);
    __o1 = &t->o_data;
    __value = (void *)__o1->object_base;

    if (sizeof(long) < sizeof(void *)) {
      tmp = __o1->object_base;
    } else {
      tmp = (char *)0;
    }
    if (sizeof(long) < sizeof(void *)) {
      tmp___0 = __o1->object_base;
    } else {
      tmp___0 = (char *)0;
    }
    __o1->next_free = tmp + (((__o1->next_free - tmp___0) + (long)__o1->alignment_mask) & (long)(~__o1->alignment_mask));

    __o1->object_base = __o1->next_free;
    s = (char const *)__value;
    __o___0 = &t->o_tok;

    __o1___0 = __o___0;
    *((void const **)__o1___0->next_free) = (void const *)s;
    __o1___0->next_free += sizeof(void const *);
    __o___1 = &t->o_tok_len;
    __len = (int)sizeof(len);

    memcpy((void *)__o___1->next_free, (void const *)(&len), (size_t)__len);
    __o___1->next_free += __len;
    (t->n_tok)++;
    return;
  }
}
_Bool readtokens0(FILE *in, struct Tokens *t) {
  int c;
  int tmp;

  struct obstack *__o___1;
  char *tmp___1;
  struct obstack *__o___2;
  struct obstack *__o1;
  struct obstack *__o1___0;
  void *__value;
  char *tmp___2;
  char *tmp___3;
  struct obstack *__o1___1;
  void *__value___0;
  char *tmp___4;
  char *tmp___5;
  int tmp___6;
  int tmp___7;

  {
    while (1) {
      tmp = fgetc(in);
      c = tmp;

      __o___1 = &t->o_data;

      tmp___1 = __o___1->next_free;
      (__o___1->next_free)++;
      *tmp___1 = (char)c;
      if (c == 0) {
        save_token(t);
      }
    };
    __o___2 = &t->o_tok;
    if ((unsigned long)(__o___2->next_free + sizeof(void *)) > (unsigned long)__o___2->chunk_limit) {
      _obstack_newchunk(__o___2, (int)sizeof(void *));
    }
    __o1 = __o___2;
    *((void const **)__o1->next_free) = (void const *)((void *)0);
    __o1->next_free += sizeof(void const *);
    __o1___0 = &t->o_tok;
    __value = (void *)__o1___0->object_base;

    if (sizeof(long) < sizeof(void *)) {
      tmp___3 = __o1___0->object_base;
    } else {
      tmp___3 = (char *)0;
    }
    __o1___0->next_free = tmp___2 + (((__o1___0->next_free - tmp___3) + (long)__o1___0->alignment_mask) & (long)(~__o1___0->alignment_mask));

    __o1___0->object_base = __o1___0->next_free;
    t->tok = (char **)__value;
    __o1___1 = &t->o_tok_len;
    __value___0 = (void *)__o1___1->object_base;

    if (sizeof(long) < sizeof(void *)) {
      tmp___4 = __o1___1->object_base;
    } else {
      tmp___4 = (char *)0;
    }

    __o1___1->next_free = tmp___4 + (((__o1___1->next_free - tmp___5) + (long)__o1___1->alignment_mask) & (long)(~__o1___1->alignment_mask));

    __o1___1->object_base = __o1___1->next_free;
    t->tok_len = (size_t *)__value___0;
    tmp___6 = ferror(in);

    return ((_Bool)tmp___7);
  }
}
extern int getc_unlocked(FILE *__stream);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(FILE *__stream);
struct randread_source *randread_new(char const *name, size_t bytes_bound);
void randread(struct randread_source *s, void *buf___1, size_t size);
int randread_free(struct randread_source *s);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) setvbuf)(FILE *__restrict __stream, char *__restrict __buf, int __modes, size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) gettimeofday)(struct timeval *__restrict __tv, __timezone_ptr_t __tz);
extern __attribute__((__nothrow__)) __pid_t(__attribute__((__leaf__)) getpid)(void);
extern __attribute__((__nothrow__)) __pid_t(__attribute__((__leaf__)) getppid)(void);
extern __attribute__((__nothrow__)) __uid_t(__attribute__((__leaf__)) getuid)(void);
extern __attribute__((__nothrow__)) __gid_t(__attribute__((__leaf__)) getgid)(void);
void isaac_seed(struct isaac_state *s);
void isaac_refill(struct isaac_state *s, isaac_word *result);
FILE *fopen_safer(char const *file, char const *mode);
void *hash_delete(Hash_table *table___0, void const *entry);
char const *const quoting_style_args[9];
enum quoting_style const quoting_style_vals[8];
int set_char_quoting(struct quoting_options *o, char c, int i);
char *quotearg_char(char const *arg, char ch);
char *quotearg_char_mem(char const *arg, size_t argsize, char ch);
struct quoting_options quote_quoting_options;
__inline static char *xcharalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
__inline static char *xcharalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) iswprint)(wint_t __wc);
char const *const quoting_style_args[9] = {"literal", "shell", "shell-always", "c", "c-maybe", "escape", "locale", "clocale", (char const *)0};
enum quoting_style const quoting_style_vals[8] = {(enum quoting_style const)0, (enum quoting_style const)1, (enum quoting_style const)2, (enum quoting_style const)3, (enum quoting_style const)4, (enum quoting_style const)5, (enum quoting_style const)6, (enum quoting_style const)7};
static struct quoting_options default_quoting_options;
static size_t quotearg_buffer_restyled(char *buffer, size_t buffersize, char const *arg, size_t argsize, enum quoting_style quoting_style, int flags, unsigned int const *quote_these_too, char const *left_quote, char const *right_quote) {
  size_t i;
  size_t len;
  char const *quote_string;
  size_t quote_string_len;
  _Bool backslash_escapes;
  _Bool unibyte_locale;
  size_t tmp;
  _Bool elide_outer_quotes;
  unsigned char c;
  unsigned char esc;
  _Bool is_right_quote;

  int tmp___1;
  size_t m;
  _Bool printable;
  unsigned short const **tmp___2;
  mbstate_t mbstate;
  wchar_t w;
  size_t bytes;
  size_t tmp___3;
  size_t j;
  int tmp___4;
  int tmp___5;

  int tmp___6;
  size_t tmp___7;

  {
    len = (size_t)0;
    quote_string = (char const *)0;
    quote_string_len = (size_t)0;
    backslash_escapes = (_Bool)0;
    tmp = __ctype_get_mb_cur_max();
    unibyte_locale = (_Bool)(tmp == 1UL);
    elide_outer_quotes = (_Bool)((flags & 2) != 0);

    goto switch_default;
    ;
    quoting_style = (enum quoting_style)3;
    elide_outer_quotes = (_Bool)1;
    ;

    backslash_escapes = (_Bool)1;
    quote_string = "\"";
    quote_string_len = (size_t)1;
    goto switch_break;
    ;
    backslash_escapes = (_Bool)1;
    elide_outer_quotes = (_Bool)0;
    goto switch_break;
    ;

    backslash_escapes = (_Bool)1;
    quote_string = right_quote;
    quote_string_len = strlen(quote_string);
    goto switch_break;
    ;
    quoting_style = (enum quoting_style)2;
    elide_outer_quotes = (_Bool)1;
    ;

    quote_string = "\'";
    quote_string_len = (size_t)1;
    goto switch_break;
    ;
    elide_outer_quotes = (_Bool)0;
    goto switch_break;
  switch_default:;
    abort();
  switch_break:;
    i = (size_t)0;
    while (1) {

      if (tmp___6) {
        goto while_break___3;
      }
      is_right_quote = (_Bool)0;

      c = (unsigned char)*(arg + i);
      if ((int)c == 0) {
        goto case_0___0;
      }

      if ((int)c == 8) {
        goto case_8___0;
      }
      if ((int)c == 12) {
        goto case_12;
      }
      if ((int)c == 10) {
        goto case_10;
      }

      if ((int)c == 9) {
        goto case_9;
      }

      if ((int)c == 92) {
        goto case_92;
      }

      if ((int)c == 35) {
        goto case_35;
      }
      if ((int)c == 126) {
        goto case_35;
      }
      if ((int)c == 32) {
        goto case_32;
      }

      if ((int)c == 34) {
        goto case_32;
      }

      if ((int)c == 41) {
        goto case_32;
      }

      if ((int)c == 60) {
        goto case_32;
      }

      if ((int)c == 96) {
        goto case_32;
      }

      if ((int)c == 39) {
        goto case_39___0;
      }

      if ((int)c == 44) {
        goto case_37;
      }
      if ((int)c == 45) {
        goto case_37;
      }
      if ((int)c == 46) {
        goto case_37;
      }
      if ((int)c == 47) {
        goto case_37;
      }
      if ((int)c == 48) {
        goto case_37;
      }

      if ((int)c == 50) {
        goto case_37;
      }
      if ((int)c == 51) {
        goto case_37;
      }

      if ((int)c == 53) {
        goto case_37;
      }
      if ((int)c == 54) {
        goto case_37;
      }

      if ((int)c == 56) {
        goto case_37;
      }
      if ((int)c == 57) {
        goto case_37;
      }

      if ((int)c == 65) {
        goto case_37;
      }

      if ((int)c == 72) {
        goto case_37;
      }

      if ((int)c == 77) {
        goto case_37;
      }

      if ((int)c == 80) {
        goto case_37;
      }

      if ((int)c == 82) {
        goto case_37;
      }

      if ((int)c == 85) {
        goto case_37;
      }

      if ((int)c == 87) {
        goto case_37;
      }

      if ((int)c == 95) {
        goto case_37;
      }

      if ((int)c == 99) {
        goto case_37;
      }
      if ((int)c == 100) {
        goto case_37;
      }

      if ((int)c == 108) {
        goto case_37;
      }

      if ((int)c == 112) {
        goto case_37;
      }
      if ((int)c == 113) {
        goto case_37;
      }
      if ((int)c == 114) {
        goto case_37;
      }
      if ((int)c == 115) {
        goto case_37;
      }

      if ((int)c == 120) {
        goto case_37;
      }

      goto switch_default___2;
    case_0___0:;
      goto switch_break___0;
      ;
      if ((unsigned int)quoting_style == 2U) {
        goto case_2___0;
      }

      goto switch_default___1;
    case_2___0:;
      goto switch_break___1;
      ;

      goto switch_break___1;
    switch_default___1:;
      goto switch_break___1;
    switch_break___1:;
      goto switch_break___0;
      ;
      esc = (unsigned char)'a';
      goto c_escape;
    case_8___0:;
      esc = (unsigned char)'b';
      goto c_escape;
    case_12:;
      esc = (unsigned char)'f';
      goto c_escape;
    case_10:;
      esc = (unsigned char)'n';
      goto c_and_shell_escape;
      ;
      esc = (unsigned char)'r';
      goto c_and_shell_escape;
    case_9:;
      esc = (unsigned char)'t';
      goto c_and_shell_escape;
      ;
      esc = (unsigned char)'v';
      goto c_escape;
    case_92:;
      esc = c;
    c_and_shell_escape:;
    c_escape:;
      goto switch_break___0;
      ;

      if (!tmp___1) {
        goto switch_break___0;
      }
    case_35:;
    case_32:;
      goto switch_break___0;
    case_39___0:;
      goto switch_break___0;
    case_37:;
      goto switch_break___0;
    switch_default___2:;
      if (unibyte_locale) {
        m = (size_t)1;
        tmp___2 = __ctype_b_loc();
        printable = (_Bool)(((int const) * (*tmp___2 + (int)c) & 16384) != 0);
      } else {
        memset((void *)(&mbstate), 0, sizeof(mbstate));
        m = (size_t)0;
        printable = (_Bool)1;

        while (1) {
          tmp___3 = mbrtowc(&w, arg + (i + m), argsize - (i + m), &mbstate);
          bytes = tmp___3;
          if (bytes == 0UL) {
            goto while_break___14;
          } else {
            if (bytes == 0xffffffffffffffffUL) {
              printable = (_Bool)0;
              goto while_break___14;
            } else {
              if (bytes == 0xfffffffffffffffeUL) {
                printable = (_Bool)0;

                ;
                goto while_break___14;
              } else {
                if (elide_outer_quotes) {
                  if ((unsigned int)quoting_style == 2U) {
                    j = (size_t)1;

                    ;
                  }
                }
                tmp___4 = iswprint((wint_t)w);

                m += bytes;
              }
            }
          }
          tmp___5 = mbsinit((mbstate_t const *)(&mbstate));
          if (tmp___5) {
            goto while_break___14;
          }
        }
      while_break___14:;
      }
    switch_break___0:;
      ;
      ;
      ;

      ;
      ;
      i++;
    }
  while_break___3:;
    if (len < buffersize) {
      *(buffer + len) = (char)'\000';
    }
    return (len);
    ;
    tmp___7 = quotearg_buffer_restyled(buffer, buffersize, arg, argsize, quoting_style, flags & -3, (unsigned int const *)((void *)0), left_quote, right_quote);
    return (tmp___7);
  }
}
static char slot0[256];
static unsigned int nslots = 1U;
static struct slotvec slotvec0 = {sizeof(slot0), slot0};
static struct slotvec *slotvec = &slotvec0;
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg, size_t argsize) {}
struct quoting_options quote_quoting_options = {(enum quoting_style)6, 0, {0U}, (char const *)((void *)0), (char const *)((void *)0)};
char const *quote(char const *name) {}
__inline static void mbuiter_multi_next(struct mbuiter_multi *iter) {
  int tmp;
  size_t tmp___0;
  size_t tmp___1;
  int tmp___2;
  _Bool tmp___3;

  {
    if (iter->next_done) {
      return;
    }

    tmp___3 = is_basic((char)*(iter->cur.ptr));
    if (tmp___3) {
      iter->cur.bytes = (size_t)1;
      iter->cur.wc = (wchar_t) * (iter->cur.ptr);
      iter->cur.wc_valid = (_Bool)1;
    } else {
      tmp = mbsinit((mbstate_t const *)(&iter->state));

      iter->in_shift = (_Bool)1;
      ;
      tmp___0 = __ctype_get_mb_cur_max();
      tmp___1 = strnlen1(iter->cur.ptr, tmp___0);
      iter->cur.bytes = mbrtowc(&iter->cur.wc, iter->cur.ptr, tmp___1, &iter->state);
      if (iter->cur.bytes == 0xffffffffffffffffUL) {
        iter->cur.bytes = (size_t)1;
        iter->cur.wc_valid = (_Bool)0;
      } else {
        if (iter->cur.bytes == 0xfffffffffffffffeUL) {
          iter->cur.bytes = strlen(iter->cur.ptr);
          iter->cur.wc_valid = (_Bool)0;
        } else {

          iter->cur.wc_valid = (_Bool)1;
          tmp___2 = mbsinit((mbstate_t const *)(&iter->state));
        }
      }
    }
    iter->next_done = (_Bool)1;
    return;
  }
}
char const *program_name;
void set_program_name(char const *argv0);
extern char *program_invocation_name;
extern char *program_invocation_short_name;
extern int fputs(char const *__restrict __s, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strrchr)(char const *__s, int __c) __attribute__((__pure__));
char const *program_name = (char const *)((void *)0);
void set_program_name(char const *argv0) {
  char const *slash;
  char const *base;
  int tmp;
  int tmp___0;

  {
    if ((unsigned long)argv0 == (unsigned long)((void *)0)) {
      fputs("A NULL argv[0] was passed through an exec system call.\n", stderr);
      abort();
    }
    slash = (char const *)strrchr(argv0, '/');
    if ((unsigned long)slash != (unsigned long)((void *)0)) {
      base = slash + 1;
    } else {
      base = argv0;
    }
    if (base - argv0 >= 7L) {
      tmp___0 = strncmp(base - 7, "/.libs/", (size_t)7);
      if (tmp___0 == 0) {
        argv0 = base;
        tmp = strncmp(base, "lt-", (size_t)3);
      }
    }
    program_name = argv0;
    program_invocation_name = (char *)argv0;
    return;
  }
}
int posix2_version(void);
int posix2_version(void) {
  long v;
  char const *s;
  char const *tmp;

  long tmp___1;
  long tmp___2;

  {
    v = 200809L;
    tmp = (char const *)getenv("_POSIX2_VERSION");
    s = tmp;

    if (v < (-0x7FFFFFFF - 1)) {
      tmp___2 = (-0x7FFFFFFF - 1);
    } else {
      if (v < 2147483647L) {
        tmp___1 = v;
      } else {
        tmp___1 = 2147483647L;
      }
      tmp___2 = tmp___1;
    }
    return ((int)tmp___2);
  }
}
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) stpcpy)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) pipe)(int *__pipedes);
double physmem_total(void);
double physmem_available(void);
extern __attribute__((__nothrow__)) long(__attribute__((__leaf__)) sysconf)(int __name);
double physmem_total(void) {
  double pages;
  double tmp;
  double pagesize;
  double tmp___0;

  {
    tmp = (double)sysconf(85);
    pages = tmp;
    tmp___0 = (double)sysconf(30);
    pagesize = tmp___0;
    if ((double)0 <= pages) {
      if ((double)0 <= pagesize) {
        return (pages * pagesize);
      }
    }
    return ((double)67108864);
  }
}
double physmem_available(void) {
  double pages;
  double tmp;
  double pagesize;
  double tmp___0;
  double tmp___1;

  {
    tmp = (double)sysconf(86);
    pages = tmp;
    tmp___0 = (double)sysconf(30);
    pagesize = tmp___0;
    if ((double)0 <= pages) {
      if ((double)0 <= pagesize) {
        return (pages * pagesize);
      }
    }
    tmp___1 = physmem_total();
    return (tmp___1 / (double)4);
  }
}
int dup_safer(int fd);
unsigned long num_processors(enum nproc_query query);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) __sched_cpucount)(size_t __setsize, cpu_set_t const *__setp);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) sched_getaffinity)(__pid_t __pid, size_t __cpusetsize, cpu_set_t *__cpuset);
static unsigned long num_processors_via_affinity_mask(void) {
  cpu_set_t set;
  unsigned long count;
  int tmp;

  {
    tmp = sched_getaffinity(0, sizeof(set), &set);
    if (tmp == 0) {
      count = (unsigned long)__sched_cpucount(sizeof(cpu_set_t), (cpu_set_t const *)(&set));
      if (count > 0UL) {
        return (count);
      }
    }
    return (0UL);
  }
}
unsigned long num_processors(enum nproc_query query) {
  char const *envvalue;
  char const *tmp;

  char *endptr;
  unsigned long value;
  unsigned long tmp___1;
  _Bool tmp___2;

  _Bool tmp___4;
  unsigned long nprocs___0;
  unsigned long tmp___5;
  long nprocs___1;
  long tmp___6;
  long nprocs___2;
  long tmp___7;

  {
    if ((unsigned int)query == 2U) {
      tmp = (char const *)getenv("OMP_NUM_THREADS");
      envvalue = tmp;
      if ((unsigned long)envvalue != (unsigned long)((void *)0)) {
        while (1) {

          envvalue++;
        };
        tmp___4 = c_isdigit((int)*envvalue);
        if (tmp___4) {
          endptr = (char *)((void *)0);
          tmp___1 = strtoul(envvalue, &endptr, 10);
          value = tmp___1;
          if ((unsigned long)endptr != (unsigned long)((void *)0)) {
            while (1) {

              if ((int)*endptr != 0) {
                tmp___2 = c_isspace((int)*endptr);
                if (!tmp___2) {
                  goto while_break___0;
                }
              } else {
                goto while_break___0;
              }
              endptr++;
            }
          while_break___0:;
          }
        }
      }
      query = (enum nproc_query)1;
    }
    if ((unsigned int)query == 1U) {
      tmp___5 = num_processors_via_affinity_mask();
      nprocs___0 = tmp___5;
      if (nprocs___0 > 0UL) {
        return (nprocs___0);
      }
      tmp___6 = sysconf(84);
      nprocs___1 = tmp___6;

    } else {
      tmp___7 = sysconf(83);
      nprocs___2 = tmp___7;
    }
    return (1UL);
  }
}
extern int nanosleep(struct timespec const *__requested_time, struct timespec *__remaining);
int(__attribute__((__nonnull__(1))) rpl_nanosleep)(struct timespec const *requested_delay, struct timespec *remaining_delay) {

  time_t limit;
  time_t seconds;
  struct timespec intermediate;

  int tmp___0;

  {

    limit = (time_t)2073600;
    seconds = (time_t)requested_delay->tv_sec;
    intermediate.tv_nsec = (__syscall_slong_t)requested_delay->tv_nsec;

    ;
    intermediate.tv_sec = seconds;
    tmp___0 = nanosleep((struct timespec const *)(&intermediate), remaining_delay);
    return (tmp___0);
  }
}
int mkstemp_safer(char *templ);
extern int(__attribute__((__nonnull__(1))) mkstemp)(char *__template);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcoll)(char const *__s1, char const *__s2) __attribute__((__pure__));
__inline static int strcoll_loop(char const *s1, size_t s1size, char const *s2, size_t s2size) {
  int diff;
  size_t size1;
  size_t tmp;
  size_t size2;
  size_t tmp___0;
  int *tmp___1;

  int tmp___3;

  {
    while (1) {
      tmp___1 = __errno_location();
      *tmp___1 = 0;
      diff = strcoll(s1, s2);

      if (tmp___3) {
        goto while_break;
      }
      tmp = strlen(s1);
      size1 = tmp + 1UL;
      tmp___0 = strlen(s2);
      size2 = tmp___0 + 1UL;
      s1 += size1;
      s2 += size2;
      s1size -= size1;
      s2size -= size2;
      if (s1size == 0UL) {
        return (-(s2size != 0UL));
      }
      if (s2size == 0UL) {
        return (1);
      }
    }
  while_break:;
    return (diff);
  }
}
int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {
  int *tmp;
  int tmp___0;
  int tmp___1;

  {
    if (s1size == s2size) {
      tmp___1 = memcmp((void const *)s1, (void const *)s2, s1size);
      if (tmp___1 == 0) {
        tmp = __errno_location();
        *tmp = 0;
        return (0);
      } else {
        tmp___0 = strcoll_loop(s1, s1size, s2, s2size);
        return (tmp___0);
      }
    } else {
      tmp___0 = strcoll_loop(s1, s1size, s2, s2size);
      return (tmp___0);
    }
  }
}
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) md5_init_ctx)(struct md5_ctx *ctx);
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) md5_process_block)(void const *buffer, size_t len, struct md5_ctx *ctx);
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) md5_process_bytes)(void const *buffer, size_t len, struct md5_ctx *ctx);
__attribute__((__nothrow__)) void *(__attribute__((__leaf__)) md5_finish_ctx)(struct md5_ctx *ctx, void *resbuf);
__attribute__((__nothrow__)) void *(__attribute__((__leaf__)) md5_read_ctx)(struct md5_ctx const *ctx, void *resbuf);
static unsigned char const fillbuf___2[64] = {(unsigned char const)128, (unsigned char const)0};
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) md5_init_ctx)(struct md5_ctx *ctx);
void(__attribute__((__leaf__)) md5_init_ctx)(struct md5_ctx *ctx) {
  uint32_t tmp;

  {
    ctx->A = (uint32_t)1732584193;
    ctx->B = 4023233417U;
    ctx->C = 2562383102U;
    ctx->D = (uint32_t)271733878;
    tmp = (uint32_t)0;
    ctx->total[1] = tmp;
    ctx->total[0] = tmp;
    ctx->buflen = (uint32_t)0;
    return;
  }
}
__attribute__((__nothrow__)) void *(__attribute__((__leaf__)) md5_read_ctx)(struct md5_ctx const *ctx, void *resbuf);
void *(__attribute__((__leaf__)) md5_read_ctx)(struct md5_ctx const *ctx, void *resbuf) {}
__attribute__((__nothrow__)) void *(__attribute__((__leaf__)) md5_finish_ctx)(struct md5_ctx *ctx, void *resbuf);
void *(__attribute__((__leaf__)) md5_finish_ctx)(struct md5_ctx *ctx, void *resbuf) {
  uint32_t bytes;
  size_t size;
  int tmp;
  void *tmp___0;

  {
    bytes = ctx->buflen;

    size = (size_t)tmp;
    ctx->total[0] += bytes;
    if (ctx->total[0] < bytes) {
      (ctx->total[1])++;
    }
    ctx->buffer[size - 2UL] = ctx->total[0] << 3;
    ctx->buffer[size - 1UL] = (ctx->total[1] << 3) | (ctx->total[0] >> 29);
    memcpy((void *)((char *)(ctx->buffer) + bytes), (void const *)(fillbuf___2), (size - 2UL) * 4UL - (size_t)bytes);
    md5_process_block((void const *)(ctx->buffer), size * 4UL, ctx);
    tmp___0 = md5_read_ctx((struct md5_ctx const *)ctx, resbuf);
    return (tmp___0);
  }
}
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) md5_process_bytes)(void const *buffer, size_t len, struct md5_ctx *ctx);
void(__attribute__((__leaf__)) md5_process_bytes)(void const *buffer, size_t len, struct md5_ctx *ctx) {}
__attribute__((__nothrow__)) void(__attribute__((__leaf__)) md5_process_block)(void const *buffer, size_t len, struct md5_ctx *ctx);
void(__attribute__((__leaf__)) md5_process_block)(void const *buffer, size_t len, struct md5_ctx *ctx) {}
int mbsnwidth(char const *string, size_t nbytes, int flags);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) wcwidth)(wchar_t __c);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) iswcntrl)(wint_t __wc);
int(__attribute__((__nonnull__(1, 2))) mbscasecmp)(char const *s1, char const *s2);
extern __attribute__((__nothrow__)) wint_t(__attribute__((__leaf__)) towlower)(wint_t __wc);
int(__attribute__((__nonnull__(1, 2))) mbscasecmp)(char const *s1, char const *s2) {
  mbui_iterator_t iter1;
  mbui_iterator_t iter2;
  int cmp;
  wint_t tmp;
  wint_t tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___4;
  int tmp___5;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  int tmp___11;
  int tmp___12;
  int tmp___13;
  int tmp___14;
  int tmp___15;
  int tmp___16;
  unsigned char const *p1;
  unsigned char const *p2;
  unsigned char c1;
  unsigned char c2;
  int tmp___18;
  unsigned short const **tmp___19;

  unsigned short const **tmp___22;
  size_t tmp___25;

  {

    tmp___25 = __ctype_get_mb_cur_max();
    if (tmp___25 > 1UL) {
      iter1.cur.ptr = s1;
      iter1.in_shift = (_Bool)0;
      memset((void *)(&iter1.state), '\000', sizeof(mbstate_t));
      iter1.next_done = (_Bool)0;
      iter2.cur.ptr = s2;
      iter2.in_shift = (_Bool)0;
      memset((void *)(&iter2.state), '\000', sizeof(mbstate_t));
      iter2.next_done = (_Bool)0;
      while (1) {
        mbuiter_multi_next(&iter1);

        if (tmp___13) {
          mbuiter_multi_next(&iter2);

          if (!tmp___14) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        if (iter1.cur.wc_valid) {
          if (iter2.cur.wc_valid) {
            tmp = towlower((wint_t)iter1.cur.wc);
            tmp___0 = towlower((wint_t)iter2.cur.wc);
            tmp___1 = (int)tmp - (int)tmp___0;
          } else {
            tmp___1 = -1;
          }
          tmp___12 = tmp___1;
        } else {
          if (iter2.cur.wc_valid) {
            tmp___11 = 1;
          } else {
            if (iter1.cur.bytes == iter2.cur.bytes) {
              tmp___2 = memcmp((void const *)iter1.cur.ptr, (void const *)iter2.cur.ptr, iter1.cur.bytes);
              tmp___10 = tmp___2;
            } else {
              if (iter1.cur.bytes < iter2.cur.bytes) {
                tmp___5 = memcmp((void const *)iter1.cur.ptr, (void const *)iter2.cur.ptr, iter1.cur.bytes);

                tmp___9 = tmp___4;
              } else {
                tmp___8 = memcmp((void const *)iter1.cur.ptr, (void const *)iter2.cur.ptr, iter2.cur.bytes);
                if (tmp___8 >= 0) {
                  tmp___7 = 1;
                } else {
                  tmp___7 = -1;
                }
                tmp___9 = tmp___7;
              }
              tmp___10 = tmp___9;
            }
            tmp___11 = tmp___10;
          }
          tmp___12 = tmp___11;
        }
        cmp = tmp___12;
        if (cmp != 0) {
          return (cmp);
        }
        iter1.cur.ptr += iter1.cur.bytes;
        iter1.next_done = (_Bool)0;
        iter2.cur.ptr += iter2.cur.bytes;
        iter2.next_done = (_Bool)0;
      }
    while_break:;
      mbuiter_multi_next(&iter1);
      if (iter1.cur.wc_valid) {
        if (iter1.cur.wc == 0) {
          tmp___15 = 0;
        } else {
          tmp___15 = 1;
        }
      } else {
        tmp___15 = 1;
      }
      if (tmp___15) {
        return (1);
      }
      mbuiter_multi_next(&iter2);

      if (tmp___16) {
        return (-1);
      }
      return (0);
    } else {
      p1 = (unsigned char const *)s1;
      p2 = (unsigned char const *)s2;
      while (1) {
        tmp___19 = __ctype_b_loc();
        if ((int const) * (*tmp___19 + (int)*p1) & 256) {
          tmp___18 = tolower((int)*p1);
          c1 = (unsigned char)tmp___18;
        } else {
          c1 = (unsigned char)*p1;
        }
        tmp___22 = __ctype_b_loc();

        if ((int)c1 == 0) {
          goto while_break___0;
        }
        p1++;
        p2++;
        if (!((int)c1 == (int)c2)) {
          goto while_break___0;
        }
      }
    while_break___0:;
      return ((int)c1 - (int)c2);
    }
  }
}
unsigned int const is_basic_table[8] = {(unsigned int const)6656, (unsigned int const)4294967279U, (unsigned int const)4294967294U, (unsigned int const)2147483646};
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) exit)(int __status);
extern int optind;
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) getopt_long)(int ___argc, char *const *___argv, char const *__shortopts, struct option const *__longopts, int *__longind);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) pthread_mutex_init)(pthread_mutex_t *__mutex, pthread_mutexattr_t const *__mutexattr);
extern __attribute__((__nothrow__)) FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);
extern int fscanf(FILE *__restrict __stream, char const *__restrict __format, ...);
extern int ungetc(int __c, FILE *__stream);
static char const *volatile charset_aliases;
extern __attribute__((__nothrow__)) long double(__attribute__((__nonnull__(1), __leaf__)) strtold)(char const *__restrict __nptr, char **__restrict __endptr);
extern __attribute__((__nothrow__)) struct lconv *(__attribute__((__leaf__)) localeconv)(void);
struct heap *heap_alloc(int (*compare___0)(void const *, void const *), size_t n_reserve);
void heap_free(struct heap *heap);
int heap_insert(struct heap *heap, void *item);
void *heap_remove_top(struct heap *heap);
static size_t heapify_down(void **array, size_t count, size_t initial, int (*compare___0)(void const *, void const *));
static void heapify_up(void **array, size_t count, int (*compare___0)(void const *, void const *));
static int heap_default_compare(void const *a, void const *b) {

  { return (0); }
}
struct heap *heap_alloc(int (*compare___0)(void const *, void const *), size_t n_reserve) {
  struct heap *heap;
  struct heap *tmp;

  {
    tmp = (struct heap *)xmalloc(sizeof(*heap));
    heap = tmp;
    if (n_reserve == 0UL) {
      n_reserve = (size_t)1;
    }
    heap->array = (void **)xnmalloc(n_reserve, sizeof(*(heap->array)));
    *(heap->array + 0) = (void *)0;
    heap->capacity = n_reserve;
    heap->count = (size_t)0;
    if (compare___0) {
      heap->compare = compare___0;
    } else {
      heap->compare = &heap_default_compare;
    }
    return (heap);
  }
}
void heap_free(struct heap *heap) {

  {
    free((void *)heap->array);
    free((void *)heap);
    return;
  }
}
int heap_insert(struct heap *heap, void *item) {

  {
    if (heap->capacity - 1UL <= heap->count) {
      heap->array = (void **)x2nrealloc((void *)heap->array, &heap->capacity, sizeof(*(heap->array)));
    }
    (heap->count)++;
    *(heap->array + heap->count) = item;
    heapify_up(heap->array, heap->count, heap->compare);
    return (0);
  }
}
void *heap_remove_top(struct heap *heap) {
  void *top;
  size_t tmp;

  {
    if (heap->count == 0UL) {
      return ((void *)0);
    }
    top = *(heap->array + 1);
    tmp = heap->count;
    (heap->count)--;
    *(heap->array + 1) = *(heap->array + tmp);
    heapify_down(heap->array, heap->count, (size_t)1, heap->compare);
    return (top);
  }
}
static size_t heapify_down(void **array, size_t count, size_t initial, int (*compare___0)(void const *, void const *)) {
  void *element;
  size_t parent;
  size_t child;

  int tmp___0;

  {
    element = *(array + initial);
    parent = initial;
    while (1) {

      if (!(parent <= count / 2UL)) {
        goto while_break;
      }
      child = 2UL * parent;

      tmp___0 = (*compare___0)((void const *)*(array + child), (void const *)element);
      if (tmp___0 <= 0) {
        goto while_break;
      }
      *(array + parent) = *(array + child);
      parent = child;
    }
  while_break:;
    *(array + parent) = element;
    return (parent);
  }
}
static void heapify_up(void **array, size_t count, int (*compare___0)(void const *, void const *)) {
  size_t k;
  void *new_element;
  int tmp;

  {
    k = count;
    new_element = *(array + k);
    while (1) {

      if (k != 1UL) {
        tmp = (*compare___0)((void const *)*(array + k / 2UL), (void const *)new_element);
        if (!(tmp <= 0)) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      *(array + k) = *(array + k / 2UL);
      k /= 2UL;
    }
  while_break:;
    *(array + k) = new_element;
    return;
  }
}
size_t hash_string(char const *string, size_t n_buckets) __attribute__((__pure__));
_Bool(__attribute__((__warn_unused_result__)) hash_rehash)(Hash_table *table___0, size_t candidate);
static struct hash_tuning const default_tuning = {0.0f, 1.0f, 0.8f, 1.414f, (_Bool)0};
size_t hash_string(char const *string, size_t n_buckets) __attribute__((__pure__));
static _Bool is_prime(size_t candidate) __attribute__((__const__));
static _Bool is_prime(size_t candidate) __attribute__((__const__));
static size_t next_prime(size_t candidate) __attribute__((__const__));
static size_t next_prime(size_t candidate) __attribute__((__const__));
static size_t next_prime(size_t candidate) {}
static _Bool check_tuning(Hash_table *table___0) {
  Hash_tuning const *tuning;
  float epsilon;

  {
    tuning = table___0->tuning;

    epsilon = 0.1f;

    table___0->tuning = &default_tuning;
    return ((_Bool)0);
  }
}
static size_t __attribute__((__pure__)) compute_bucket_size(size_t candidate, Hash_tuning const *tuning) {

  {

    candidate = next_prime(candidate);

    return ((size_t __attribute__((__pure__)))candidate);
  }
}
Hash_table *(__attribute__((__warn_unused_result__)) hash_initialize)(size_t candidate, Hash_tuning const *tuning, size_t (*hasher)(void const *, size_t), _Bool (*comparator)(void const *, void const *), void (*data_freer)(void *)) {
  Hash_table *table___0;
  _Bool tmp;

  {

    table___0 = (Hash_table *)malloc(sizeof(*table___0));
    if ((unsigned long)table___0 == (unsigned long)((void *)0)) {
      return ((Hash_table *)((void *)0));
    }

    table___0->tuning = tuning;
    tmp = check_tuning(table___0);
    if (!tmp) {
      goto fail;
    }
    table___0->n_buckets = (size_t)compute_bucket_size(candidate, tuning);
    if (!table___0->n_buckets) {
      goto fail;
    }
    table___0->bucket = (struct hash_entry *)calloc(table___0->n_buckets, sizeof(*(table___0->bucket)));

    table___0->bucket_limit = (struct hash_entry const *)(table___0->bucket + table___0->n_buckets);
    table___0->n_buckets_used = (size_t)0;
    table___0->n_entries = (size_t)0;
    table___0->hasher = hasher;
    table___0->comparator = comparator;
    table___0->data_freer = data_freer;
    table___0->free_entry_list = (struct hash_entry *)((void *)0);
    return (table___0);
  fail:;
    free((void *)table___0);
    return ((Hash_table *)((void *)0));
  }
}
static void *hash_find_entry(Hash_table *table___0, void const *entry, struct hash_entry **bucket_head, _Bool delete) {}
static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {
  struct hash_entry *bucket;

  {
    bucket = src->bucket;
    while (1) {

      if (!((unsigned long)bucket < (unsigned long)src->bucket_limit)) {
        goto while_break;
      }

      ;
      bucket++;
    }
  while_break:;
    return ((_Bool)1);
  }
}
_Bool(__attribute__((__warn_unused_result__)) hash_rehash)(Hash_table *table___0, size_t candidate) {
  Hash_table storage;
  Hash_table *new_table;
  size_t new_size;
  size_t tmp;
  _Bool tmp___0;
  _Bool tmp___1;

  {
    tmp = (size_t)compute_bucket_size(candidate, table___0->tuning);
    new_size = tmp;

    new_table = &storage;
    new_table->bucket = (struct hash_entry *)calloc(new_size, sizeof(*(new_table->bucket)));
    if ((unsigned long)new_table->bucket == (unsigned long)((void *)0)) {
      return ((_Bool)0);
    }
    new_table->n_buckets = new_size;
    new_table->bucket_limit = (struct hash_entry const *)(new_table->bucket + new_size);
    new_table->n_buckets_used = (size_t)0;
    new_table->n_entries = (size_t)0;
    new_table->tuning = table___0->tuning;
    new_table->hasher = table___0->hasher;
    new_table->comparator = table___0->comparator;
    new_table->data_freer = table___0->data_freer;
    new_table->free_entry_list = table___0->free_entry_list;
    tmp___0 = transfer_entries(new_table, table___0, (_Bool)0);

    table___0->free_entry_list = new_table->free_entry_list;
    tmp___1 = transfer_entries(table___0, new_table, (_Bool)1);

    free((void *)new_table->bucket);
    return ((_Bool)0);
  }
}
int hash_insert_if_absent(Hash_table *table___0, void const *entry, void const **matched_ent) {
  void *data;
  struct hash_entry *bucket;

  {

    data = hash_find_entry(table___0, entry, &bucket, (_Bool)0);

    bucket->data = (void *)entry;
    (table___0->n_entries)++;
    (table___0->n_buckets_used)++;
    return (1);
  }
}
void *(__attribute__((__warn_unused_result__)) hash_insert)(Hash_table *table___0, void const *entry) {
  void const *matched_ent;
  int err;
  int tmp;
  void const *tmp___0;
  void *tmp___1;

  {
    tmp = hash_insert_if_absent(table___0, entry, &matched_ent);
    err = tmp;
    if (err == -1) {
      tmp___1 = (void *)0;
    } else {

      tmp___1 = (void *)tmp___0;
    }
    return (tmp___1);
  }
}
size_t hash_pjw(void const *x, size_t tablesize) __attribute__((__pure__));
size_t triple_hash(void const *x, size_t table_size) __attribute__((__pure__));
_Bool triple_compare_ino_str(void const *x, void const *y) __attribute__((__pure__));
size_t hash_pjw(void const *x, size_t tablesize) __attribute__((__pure__));
_Bool hard_locale(int category);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) setlocale)(int __category, char const *__locale);
_Bool hard_locale(int category) {
  _Bool hard;
  char const *p;
  char const *tmp;
  int tmp___0;
  int tmp___1;
  char *locale;
  char *tmp___2;

  {
    hard = (_Bool)1;
    tmp = (char const *)setlocale(category, (char const *)((void *)0));
    p = tmp;
    if (p) {
      if (1) {
        tmp___0 = strcmp(p, "C");
        if (tmp___0 == 0) {
          hard = (_Bool)0;
        } else {
          tmp___1 = strcmp(p, "POSIX");
        }
      } else {
        tmp___2 = strdup(p);
        locale = tmp___2;
      }
    }
    return (hard);
  }
}
extern int fflush_unlocked(FILE *__stream);
extern void(__attribute__((__nonnull__(1, 4))) qsort)(void *__base, size_t __nmemb, size_t __size, int (*__compar)(void const *, void const *));
extern int fseeko(FILE *__stream, __off_t __off, int __whence);
extern __attribute__((__nothrow__)) __off_t(__attribute__((__leaf__)) lseek)(int __fd, __off_t __offset, int __whence);
int(__attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp, off_t offset, int whence) {

  int tmp___1;

  {

    tmp___1 = fseeko(fp, offset, whence);
    return (tmp___1);
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) dup2)(int __fd, int __fd2);
FILE *fopen_safer(char const *file, char const *mode) {
  FILE *fp;
  FILE *tmp;
  int fd;
  int tmp___0;
  int f;
  int tmp___1;

  int e___0;
  int *tmp___4;
  int *tmp___5;
  int tmp___6;

  {
    tmp = fopen(file, mode);
    fp = tmp;
    if (fp) {
      tmp___0 = fileno(fp);
      fd = tmp___0;
      if (0 <= fd) {
        if (fd <= 2) {
          tmp___1 = dup_safer(fd);
          f = tmp___1;

          tmp___6 = rpl_fclose(fp);
          if (tmp___6 != 0) {
            goto _L;
          } else {
            fp = fdopen(f, mode);
            if (!fp) {
            _L:;
              tmp___4 = __errno_location();
              e___0 = *tmp___4;
              close(f);
              tmp___5 = __errno_location();
              *tmp___5 = e___0;
              return ((FILE *)((void *)0));
            }
          }
        }
      }
    }
    return (fp);
  }
}
int filevercmp(char const *s1, char const *s2);
extern int fflush(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) __freading)(FILE *__fp);
__inline static void clear_ungetc_buffer_preserving_position(FILE *fp) {

  {
    if (fp->_flags & 256) {
      rpl_fseeko(fp, (off_t)0, 1);
    }
    return;
  }
}
int rpl_fflush(FILE *stream) {
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    if ((unsigned long)stream == (unsigned long)((void *)0)) {
      tmp = fflush(stream);
      return (tmp);
    } else {
      tmp___0 = __freading(stream);
      if (!(tmp___0 != 0)) {
        tmp = fflush(stream);
        return (tmp);
      }
    }
    clear_ungetc_buffer_preserving_position(stream);
    tmp___1 = fflush(stream);
    return (tmp___1);
  }
}
extern int fcntl(int __fd, int __cmd, ...);
static int have_dupfd_cloexec = 0;
int rpl_fcntl(int fd, int action, ...) {}
extern int fclose(FILE *__stream);
int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {
  int saved_errno;
  int fd;
  int result;
  int tmp;
  int *tmp___0;
  int tmp___1;
  int tmp___2;
  __off_t tmp___3;
  int tmp___4;
  int *tmp___5;

  {
    saved_errno = 0;
    result = 0;
    fd = fileno(fp);
    if (fd < 0) {
      tmp = fclose(fp);
      return (tmp);
    }
    tmp___1 = __freading(fp);
    if (tmp___1 != 0) {
      tmp___2 = fileno(fp);
      tmp___3 = lseek(tmp___2, (__off_t)0, 1);
      if (tmp___3 != -1L) {
      _L:;
        tmp___4 = rpl_fflush(fp);
        if (tmp___4) {
          tmp___0 = __errno_location();
          saved_errno = *tmp___0;
        }
      }
    } else {
      goto _L;
    }
    result = fclose(fp);
    if (saved_errno != 0) {
      tmp___5 = __errno_location();
      *tmp___5 = saved_errno;
      result = -1;
    }
    return (result);
  }
}
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) sigemptyset)(sigset_t *__set);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) sigaddset)(sigset_t *__set, int __signo);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) sigaction)(int __sig, struct sigaction const *__restrict __act, struct sigaction *__restrict __oact);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) posix_fadvise)(int __fd, off_t __offset, off_t __len, int __advise);
void fdadvise(int fd, off_t offset, off_t len, fadvice_t advice);
void fadvise(FILE *fp, fadvice_t advice);
void fdadvise(int fd, off_t offset, off_t len, fadvice_t advice) {
  int __x;
  int tmp;

  {
    tmp = posix_fadvise(fd, offset, len, (int)advice);
    __x = tmp;
    return;
  }
}
void fadvise(FILE *fp, fadvice_t advice) {
  int tmp;

  {
    if (fp) {
      tmp = fileno(fp);
      fdadvise(tmp, (off_t)0, (off_t)0, advice);
    }
    return;
  }
}
int volatile exit_failure = (int volatile)1;
int dup_safer(int fd) {
  int tmp;

  {
    tmp = rpl_fcntl(fd, 0, 3);
    return (tmp);
  }
}
char const *Version = "8.16";
extern char *optarg;
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 3))) pthread_create)(pthread_t *__restrict __newthread, pthread_attr_t const *__restrict __attr, void *(*__start_routine)(void *), void *__restrict __arg);
extern int pthread_join(pthread_t __th, void **__thread_return);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) pthread_mutex_destroy)(pthread_mutex_t *__mutex);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1))) pthread_mutex_lock)(pthread_mutex_t *__mutex);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1))) pthread_mutex_unlock)(pthread_mutex_t *__mutex);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) pthread_cond_init)(pthread_cond_t *__restrict __cond, pthread_condattr_t const *__restrict __cond_attr);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) pthread_cond_destroy)(pthread_cond_t *__cond);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1))) pthread_cond_signal)(pthread_cond_t *__cond);
extern int(__attribute__((__nonnull__(1, 2))) pthread_cond_wait)(pthread_cond_t *__restrict __cond, pthread_mutex_t *__restrict __mutex);
extern __attribute__((__nothrow__)) __sighandler_t(__attribute__((__leaf__)) signal)(int __sig, void (*__handler)(int));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) sigismember)(sigset_t const *__set, int __signo);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) execlp)(char const *__file, char const *__arg, ...);
extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(2), __leaf__)) strxfrm)(char *__restrict __dest, char const *__restrict __src, size_t __n);
__inline static void initialize_exit_failure(int status) {

  {
    if (status != 1) {
      exit_failure = (int volatile)status;
    }
    return;
  }
}
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) ngettext)(char const *__msgid1, char const *__msgid2, unsigned long __n) __attribute__((__format_arg__(2), __format_arg__(1)));
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) textdomain)(char const *__domainname);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) bindtextdomain)(char const *__domainname, char const *__dirname);
extern int fputc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);
extern size_t fwrite_unlocked(void const *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) clearerr_unlocked)(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) getrlimit)(__rlimit_resource_t __resource, struct rlimit *__rlimits);
static int decimal_point;
static int thousands_sep;
static _Bool hard_LC_COLLATE;
static _Bool hard_LC_TIME;
static char eolchar = (char)'\n';
static _Bool blanks[256];
static _Bool nonprinting[256];
static _Bool nondictionary[256];
static char fold_toupper[256];
static struct month monthtab[12] = {{"APR", 4}, {"AUG", 8}, {"DEC", 12}, {"FEB", 2}, {"JAN", 1}, {"JUL", 7}, {"JUN", 6}, {"MAR", 3}, {"MAY", 5}, {"NOV", 11}, {"OCT", 10}, {"SEP", 9}};
static size_t merge_buffer_size = (size_t)262144;
static size_t sort_size;
static char const **temp_dirs;
static size_t temp_dir_count;
static size_t temp_dir_alloc;
static _Bool reverse;
static _Bool stable;
static int tab = 128;
static _Bool unique;
static _Bool have_read_stdin;
static struct keyfield *keylist;
static char const *compress_program;
static _Bool debug;
static unsigned int nmerge = 16U;
static __attribute__((__noreturn__)) void die(char const *message, char const *file);
static __attribute__((__noreturn__)) void die(char const *message, char const *file);
static void die(char const *message, char const *file) {

  char const *tmp___0;
  int *tmp___1;

  {

    tmp___1 = __errno_location();
    error(0, *tmp___1, "%s: %s", message, tmp___0);
    exit(2);
  }
}
__attribute__((__noreturn__)) void usage(int status);
void usage(int status) {}
static char const short_options[31] = {(char const)'-', (char const)'b', (char const)'c', (char const)'C', (char const)'d', (char const)'f', (char const)'g', (char const)'h', (char const)'i',   (char const)'k', (char const)':',
                                       (char const)'m', (char const)'M', (char const)'n', (char const)'o', (char const)':', (char const)'r', (char const)'R', (char const)'s', (char const)'S',   (char const)':', (char const)'t',
                                       (char const)':', (char const)'T', (char const)':', (char const)'u', (char const)'V', (char const)'y', (char const)':', (char const)'z', (char const)'\000'};
static struct option const long_options___1[31] = {{"ignore-leading-blanks", 0, (int *)((void *)0), 'b'},
                                                   {"check", 2, (int *)((void *)0), 128},
                                                   {"compress-program", 1, (int *)((void *)0), 129},
                                                   {"debug", 0, (int *)((void *)0), 130},
                                                   {"dictionary-order", 0, (int *)((void *)0), 'd'},
                                                   {"ignore-case", 0, (int *)((void *)0), 'f'},
                                                   {"files0-from", 1, (int *)((void *)0), 131},
                                                   {"general-numeric-sort", 0, (int *)((void *)0), 'g'},
                                                   {"ignore-nonprinting", 0, (int *)((void *)0), 'i'},
                                                   {"key", 1, (int *)((void *)0), 'k'},
                                                   {"merge", 0, (int *)((void *)0), 'm'},
                                                   {"month-sort", 0, (int *)((void *)0), 'M'},
                                                   {"numeric-sort", 0, (int *)((void *)0), 'n'},
                                                   {"human-numeric-sort", 0, (int *)((void *)0), 'h'},
                                                   {"version-sort", 0, (int *)((void *)0), 'V'},
                                                   {"random-sort", 0, (int *)((void *)0), 'R'},
                                                   {"random-source", 1, (int *)((void *)0), 133},
                                                   {"sort", 1, (int *)((void *)0), 134},
                                                   {"output", 1, (int *)((void *)0), 'o'},
                                                   {"reverse", 0, (int *)((void *)0), 'r'},
                                                   {"stable", 0, (int *)((void *)0), 's'},
                                                   {"batch-size", 1, (int *)((void *)0), 132},
                                                   {"buffer-size", 1, (int *)((void *)0), 'S'},
                                                   {"field-separator", 1, (int *)((void *)0), 't'},
                                                   {"temporary-directory", 1, (int *)((void *)0), 'T'},
                                                   {"unique", 0, (int *)((void *)0), 'u'},
                                                   {"zero-terminated", 0, (int *)((void *)0), 'z'},
                                                   {"parallel", 1, (int *)((void *)0), 135},
                                                   {"help", 0, (int *)((void *)0), -130},
                                                   {"version", 0, (int *)((void *)0), -131},
                                                   {(char const *)((void *)0), 0, (int *)((void *)0), 0}};
static char const *const check_args[4] = {"quiet", "silent", "diagnose-first", (char const *)((void *)0)};
static char const check_types[3] = {(char const)'C', (char const)'C', (char const)'c'};
static char const *const sort_args[7] = {"general-numeric", "human-numeric", "month", "numeric", "random", "version", (char const *)((void *)0)};
static char const sort_types[6] = {(char const)'g', (char const)'h', (char const)'M', (char const)'n', (char const)'R', (char const)'V'};
static sigset_t caught_signals;
static struct cs_status cs_enter(void) {}
static void cs_leave(struct cs_status status) {}
static struct tempnode *volatile temphead;
static struct tempnode *volatile *temptail = &temphead;
static Hash_table *proctab;
static pid_t nprocs;
static _Bool delete_proc(pid_t pid);
static pid_t reap(pid_t pid) {
  int status;
  pid_t cpid;
  int tmp;
  pid_t tmp___0;
  pid_t tmp___1;
  char *tmp___2;
  int *tmp___3;

  {

    tmp___1 = waitpid(tmp___0, &status, tmp);
    cpid = tmp___1;
    if (cpid < 0) {
      tmp___2 = gettext("waiting for %s [-d]");
      tmp___3 = __errno_location();
      error(2, *tmp___3, (char const *)tmp___2, compress_program);
    }
    return (cpid);
  }
}
static void reap_all(void) {

  {
    while (1) {

      if (!(0 < nprocs)) {
        goto while_break;
      }
      reap(-1);
    }
  while_break:;
    return;
  }
}
static void cleanup(void) {
  struct tempnode const *node;

  {
    node = (struct tempnode const *)temphead;
    while (1) {

      if (!node) {
        goto while_break;
      }
      unlink((char const *)(node->name));
      node = (struct tempnode const *)node->next;
    }
  while_break:;
    temphead = (struct tempnode *)((void *)0);
    return;
  }
}
static void exit_cleanup(void) {
  struct cs_status cs;
  struct cs_status tmp;

  {
    if (temphead) {
      tmp = cs_enter();
      cs = tmp;
      cleanup();
      cs_leave(cs);
    }
    close_stdout();
    return;
  }
}
static struct tempnode *create_temp_file(int *pfd, _Bool survive_fd_exhaustion);
static char const slashbase[12] = {(char const)'/', (char const)'s', (char const)'o', (char const)'r', (char const)'t', (char const)'X', (char const)'X', (char const)'X', (char const)'X', (char const)'X', (char const)'X', (char const)'\000'};
static size_t temp_dir_index;
static FILE *stream_open(char const *file, char const *how) {
  FILE *fp;
  int tmp;
  FILE *tmp___0;

  {
    if (!file) {
      return (stdout);
    }
    if ((int const) * how == 114) {
      tmp = strcmp(file, "-");
      if (tmp == 0) {
        have_read_stdin = (_Bool)1;
        fp = stdin;
      } else {
        fp = fopen_safer(file, how);
      }
      fadvise(fp, (fadvice_t)2);
      return (fp);
    }
    tmp___0 = fopen_safer(file, how);
    return (tmp___0);
  }
}
static FILE *xfopen(char const *file, char const *how) {
  FILE *fp;
  FILE *tmp;
  char *tmp___0;

  {
    tmp = stream_open(file, how);
    fp = tmp;
    if (!fp) {
      tmp___0 = gettext("open failed");
      die((char const *)tmp___0, file);
    }
    return (fp);
  }
}
static void xfclose(FILE *fp, char const *file) {
  int tmp;
  int tmp___0;
  char *tmp___1;
  int tmp___2;
  char *tmp___3;
  int tmp___4;

  {
    tmp = fileno(fp);
    if (tmp == 0) {
      goto case_0;
    }
    if (tmp == 1) {
      goto case_1;
    }
    goto switch_default;
  case_0:;
    tmp___0 = feof_unlocked(fp);
    goto switch_break;
  case_1:;
    tmp___2 = fflush_unlocked(fp);
    if (tmp___2 != 0) {
      tmp___1 = gettext("fflush failed");
      die((char const *)tmp___1, file);
    }
    goto switch_break;
  switch_default:;
    tmp___4 = rpl_fclose(fp);
    if (tmp___4 != 0) {
      tmp___3 = gettext("close failed");
      die((char const *)tmp___3, file);
    }
    goto switch_break;
  switch_break:;
    return;
  }
}
static struct tempnode *maybe_create_temp(FILE **pfp, _Bool survive_fd_exhaustion) {}
static struct tempnode *create_temp(FILE **pfp) {}
static FILE *open_temp(struct tempnode *temp) {}
static void add_temp_dir(char const *dir) {
  size_t tmp;

  {
    if (temp_dir_count == temp_dir_alloc) {
      temp_dirs = (char const **)x2nrealloc((void *)temp_dirs, &temp_dir_alloc, sizeof(*temp_dirs));
    }
    tmp = temp_dir_count;
    temp_dir_count++;
    *(temp_dirs + tmp) = dir;
    return;
  }
}
static int struct_month_cmp(void const *m1, void const *m2) {}
static void inittables(void) {
  size_t i;
  unsigned short const **tmp;
  int tmp___0;
  unsigned short const **tmp___1;
  int tmp___2;
  unsigned short const **tmp___3;
  unsigned short const **tmp___4;
  int tmp___5;
  char const *s;
  size_t s_len;
  size_t j;
  size_t k;
  char *name;

  {
    i = (size_t)0;
    while (1) {

      if (!(i < 256UL)) {
        goto while_break;
      }
      tmp = __ctype_b_loc();
      if ((int const) * (*tmp + (int)i) & 1) {
        tmp___0 = 1;
      } else {
        tmp___0 = 0;
      }
      blanks[i] = (_Bool)tmp___0;
      tmp___1 = __ctype_b_loc();
      if ((int const) * (*tmp___1 + (int)i) & 16384) {
        tmp___2 = 0;
      } else {
        tmp___2 = 1;
      }
      nonprinting[i] = (_Bool)tmp___2;
      tmp___3 = __ctype_b_loc();
      if ((int const) * (*tmp___3 + (int)i) & 8) {
        tmp___5 = 0;
      } else {
        tmp___4 = __ctype_b_loc();
        if ((int const) * (*tmp___4 + (int)i) & 1) {
          tmp___5 = 0;
        } else {
          tmp___5 = 1;
        }
      }
      nondictionary[i] = (_Bool)tmp___5;
      fold_toupper[i] = (char)toupper((int)i);
      i++;
    }
  while_break:;
    if (hard_LC_TIME) {
      i = (size_t)0;
      while (1) {

        if (!(i < 12UL)) {
          goto while_break___0;
        }
        s = (char const *)nl_langinfo((nl_item)(131086UL + i));
        s_len = strlen(s);
        name = (char *)xmalloc(s_len + 1UL);
        monthtab[i].name = (char const *)name;
        monthtab[i].val = (int)(i + 1UL);
        k = (size_t)0;
        j = k;

        ;
        *(name + k) = (char)'\000';
        i++;
      }
    while_break___0:;
      qsort((void *)(monthtab), (size_t)12, sizeof(monthtab[0]), &struct_month_cmp);
    }
    return;
  }
}
static void specify_nmerge(int oi, char c, char const *s) {}
static void specify_sort_size(int oi, char c, char const *s) {}
static size_t specify_nthreads(int oi, char c, char const *s) {
  unsigned long nthreads;
  enum strtol_error e;
  enum strtol_error tmp;
  char *tmp___0;

  {
    tmp = xstrtoul(s, (char **)((void *)0), 10, &nthreads, "");
    e = tmp;

    if ((unsigned int)e != 0U) {
      xstrtol_fatal(e, oi, c, long_options___1, s);
    }

    if (nthreads == 0UL) {
      tmp___0 = gettext("number in parallel must be nonzero");
      error(2, 0, (char const *)tmp___0);
    }
    return (nthreads);
  }
}
static size_t default_sort_size(void) {
  double avail;
  double tmp;
  double total;
  double tmp___0;
  double mem;
  double tmp___1;
  struct rlimit rlimit;
  size_t size;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  size_t tmp___5;

  {
    tmp = physmem_available();
    avail = tmp;
    tmp___0 = physmem_total();
    total = tmp___0;
    if (avail > total / (double)8) {
      tmp___1 = avail;
    } else {
      tmp___1 = total / (double)8;
    }
    mem = tmp___1;
    size = 0xffffffffffffffffUL;
    tmp___2 = getrlimit((__rlimit_resource_t)2, &rlimit);
    if (tmp___2 == 0) {
      if (rlimit.rlim_cur < size) {
        size = rlimit.rlim_cur;
      }
    }
    tmp___3 = getrlimit((__rlimit_resource_t)9, &rlimit);
    if (tmp___3 == 0) {
      if (rlimit.rlim_cur < size) {
        size = rlimit.rlim_cur;
      }
    }
    size /= 2UL;
    tmp___4 = getrlimit((__rlimit_resource_t)5, &rlimit);
    if (tmp___4 == 0) {
      if ((rlimit.rlim_cur / 16UL) * 15UL < size) {
        size = (rlimit.rlim_cur / 16UL) * 15UL;
      }
    }
    if (mem < (double)size) {
      size = (size_t)mem;
    }
    if (size > (unsigned long)nmerge * (2UL + sizeof(struct line))) {
      tmp___5 = size;
    } else {
      tmp___5 = (unsigned long)nmerge * (2UL + sizeof(struct line));
    }
    return (tmp___5);
  }
}
static size_t size_bound;
static size_t sort_buffer_size(FILE *const *fps, size_t nfps, char *const *files, size_t nfiles, size_t line_bytes) {
  size_t worst_case_per_input_byte;
  size_t size;
  size_t i;
  struct stat st;
  off_t file_size;
  size_t worst_case;
  char *tmp;
  int tmp___0;
  int tmp___1;

  int tmp___5;
  int tmp___6;
  int tmp___7;

  {
    worst_case_per_input_byte = line_bytes + 1UL;
    size = worst_case_per_input_byte + 1UL;
    i = (size_t)0;
    while (1) {

      if (!(i < nfiles)) {
        goto while_break;
      }
      if (i < nfps) {
        tmp___0 = fileno((FILE *)*(fps + i));
        tmp___1 = fstat(tmp___0, &st);
        tmp___7 = tmp___1;
      } else {
        tmp___6 = strcmp((char const *)*(files + i), "-");

        tmp___7 = tmp___5;
      }
      if (tmp___7 != 0) {
        tmp = gettext("stat failed");
        die((char const *)tmp, (char const *)*(files + i));
      }
      if ((st.st_mode & 61440U) == 32768U) {
        file_size = st.st_size;
      } else {

        file_size = (off_t)131072;
      }
      if (!size_bound) {
        size_bound = sort_size;
        if (!size_bound) {
          size_bound = default_sort_size();
        }
      }
      worst_case = (size_t)file_size * worst_case_per_input_byte + 1UL;
      if ((size_t)file_size != worst_case / worst_case_per_input_byte) {
        return (size_bound);
      } else {
        if (size_bound - size <= worst_case) {
          return (size_bound);
        }
      }
      size += worst_case;
      i++;
    }
  while_break:;
    return (size);
  }
}
static void initbuf(struct buffer *buf___1, size_t line_bytes, size_t alloc) {
  size_t tmp;
  size_t tmp___0;

  {
    while (1) {
      alloc += sizeof(struct line) - alloc % sizeof(struct line);
      buf___1->buf = (char *)malloc(alloc);
      if (buf___1->buf) {
        goto while_break;
      }
      alloc /= 2UL;
    }
  while_break:;
    buf___1->line_bytes = line_bytes;
    buf___1->alloc = alloc;
    tmp___0 = (size_t)0;
    buf___1->nlines = tmp___0;
    tmp = tmp___0;
    buf___1->left = tmp;
    buf___1->used = tmp;
    buf___1->eof = (_Bool)0;
    return;
  }
}
__inline static struct line *buffer_linelim(struct buffer const *buf___1) {

  { return ((struct line *)(buf___1->buf + buf___1->alloc)); }
}
static char *begfield(struct line const *line, struct keyfield const *key) {
  char *ptr;
  char *lim;
  size_t sword;
  size_t schar;

  {
    ptr = (char *)line->text;
    lim = (ptr + line->length) - 1;
    sword = (size_t)key->sword;
    schar = (size_t)key->schar;

    return (ptr);
  }
}
static char *limfield(struct line const *line, struct keyfield const *key) {
  char *ptr;
  char *lim;
  size_t eword;
  size_t echar;

  size_t tmp___2;

  {
    ptr = (char *)line->text;
    lim = (ptr + line->length) - 1;
    eword = (size_t)key->eword;
    echar = (size_t)key->echar;
    if (echar == 0UL) {
      eword++;
    }
    if (tab != 128) {

      ;
    } else {
      while (1) {

        if ((unsigned long)ptr < (unsigned long)lim) {
          tmp___2 = eword;
          eword--;
          if (!tmp___2) {
            goto while_break___1;
          }
        } else {
          goto while_break___1;
        }
        while (1) {

          ptr++;
        };

        ;
      }
    while_break___1:;
    }
    return (ptr);
  }
}
static _Bool fillbuf___7(struct buffer *buf___1, FILE *fp, char const *file) {
  struct keyfield const *key;
  char eol;
  size_t line_bytes;
  size_t mergesize;
  char *ptr;
  struct line *linelim;
  struct line *tmp;
  struct line *line;
  size_t avail;
  char *line_start;
  char *tmp___0;
  size_t readsize;
  size_t bytes_read;
  size_t tmp___1;
  char *ptrlim;
  char *p;
  char *tmp___2;
  int tmp___3;
  char *tmp___4;
  int tmp___5;
  char *tmp___6;

  struct line *tmp___8;
  size_t line_alloc;

  {
    key = (struct keyfield const *)keylist;
    eol = eolchar;
    line_bytes = buf___1->line_bytes;
    mergesize = merge_buffer_size - (2UL + sizeof(struct line));
    if (buf___1->eof) {
      return ((_Bool)0);
    }
    if (buf___1->used != buf___1->left) {
      memmove((void *)buf___1->buf, (void const *)((buf___1->buf + buf___1->used) - buf___1->left), buf___1->left);
      buf___1->used = buf___1->left;
      buf___1->nlines = (size_t)0;
    }
    while (1) {
      ptr = buf___1->buf + buf___1->used;
      tmp = buffer_linelim((struct buffer const *)buf___1);
      linelim = tmp;
      line = linelim - buf___1->nlines;
      avail = (size_t)(((char *)linelim - buf___1->nlines * line_bytes) - ptr);
      if (buf___1->nlines) {
        tmp___0 = line->text + line->length;
      } else {
        tmp___0 = buf___1->buf;
      }
      line_start = tmp___0;
      while (1) {

        if (!(line_bytes + 1UL < avail)) {
          goto while_break___0;
        }
        readsize = (avail - 1UL) / (line_bytes + 1UL);
        tmp___1 = fread_unlocked((void *)ptr, (size_t)1, readsize, fp);
        bytes_read = tmp___1;
        ptrlim = ptr + bytes_read;
        avail -= bytes_read;
        if (bytes_read != readsize) {
          tmp___3 = ferror_unlocked(fp);
          if (tmp___3) {
            tmp___2 = gettext("read failed");
            die((char const *)tmp___2, file);
          }
          tmp___5 = feof_unlocked(fp);
          if (tmp___5) {
            buf___1->eof = (_Bool)1;
            if ((unsigned long)buf___1->buf == (unsigned long)ptrlim) {
              return ((_Bool)0);
            }
            if ((unsigned long)line_start != (unsigned long)ptrlim) {
              if ((int)*(ptrlim + -1) != (int)eol) {
                tmp___4 = ptrlim;
                ptrlim++;
                *tmp___4 = eol;
              }
            }
          }
        }
        while (1) {
          p = (char *)memchr((void const *)ptr, (int)eol, (size_t)(ptrlim - ptr));
          if (!p) {
            goto while_break___1;
          }
          *p = (char)'\000';
          ptr = p + 1;
          line--;
          line->text = line_start;
          line->length = (size_t)(ptr - line_start);
          if (mergesize > line->length) {
            mergesize = mergesize;
          } else {
            mergesize = line->length;
          }
          avail -= line_bytes;
          if (key) {
            if (key->eword == 0xffffffffffffffffUL) {
              line->keylim = p;
            } else {
              tmp___6 = limfield((struct line const *)line, key);
              line->keylim = tmp___6;
            }
          }
          line_start = ptr;
        }
      while_break___1:;
        ptr = ptrlim;
        if (buf___1->eof) {
          goto while_break___0;
        }
      }
    while_break___0:;
      buf___1->used = (size_t)(ptr - buf___1->buf);
      tmp___8 = buffer_linelim((struct buffer const *)buf___1);
      buf___1->nlines = (size_t)(tmp___8 - line);
      if (buf___1->nlines != 0UL) {
        buf___1->left = (size_t)(ptr - line_start);
        merge_buffer_size = mergesize + (2UL + sizeof(struct line));
        return ((_Bool)1);
      }
      line_alloc = buf___1->alloc / sizeof(struct line);
      buf___1->buf = (char *)x2nrealloc((void *)buf___1->buf, &line_alloc, sizeof(struct line));
      buf___1->alloc = line_alloc * sizeof(struct line);
    }

    return ((_Bool)0);
  }
}
static char const unit_order[256] = {
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)6, (char const)0, (char const)3, (char const)0, (char const)0, (char const)0, (char const)1,
    (char const)0, (char const)2, (char const)0, (char const)0, (char const)5, (char const)0, (char const)0, (char const)0, (char const)4, (char const)0, (char const)0, (char const)0, (char const)0, (char const)8, (char const)7, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)1, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0,
    (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0, (char const)0};
static struct md5_ctx random_md5_state;
static void random_md5_state_init(char const *random_source) {}
__inline static _Bool key_numeric(struct keyfield const *key) {
  int tmp;

  {
    if (key->numeric) {
      tmp = 1;
    } else {
      if (key->general_numeric) {
        tmp = 1;
      } else {
        if (key->human_numeric) {
          tmp = 1;
        } else {
          tmp = 0;
        }
      }
    }
    return ((_Bool)tmp);
  }
}
static void debug_line(struct line const *line) {}
static _Bool default_key_compare(struct keyfield const *key) {
  _Bool tmp;
  int tmp___0;

  {
    if (key->ignore) {
      tmp___0 = 0;
    } else {
      if (key->translate) {
        tmp___0 = 0;
      } else {
        if (key->skipsblanks) {
          tmp___0 = 0;
        } else {
          if (key->skipeblanks) {
            tmp___0 = 0;
          } else {
            tmp = key_numeric(key);
            if (tmp) {
              tmp___0 = 0;
            } else {
              if (key->month) {
                tmp___0 = 0;
              } else {
                if (key->version) {
                  tmp___0 = 0;
                } else {
                  if (key->random) {
                    tmp___0 = 0;
                  } else {
                    tmp___0 = 1;
                  }
                }
              }
            }
          }
        }
      }
    }
    return ((_Bool)tmp___0);
  }
}
static void key_warnings(struct keyfield const *gkey, _Bool gkey_only) {}
static int keycompare(struct line const *a, struct line const *b) {
  struct keyfield *key;
  char *texta;
  char *textb;
  char *lima;
  char *limb;
  int diff;
  char const *translate;
  _Bool const *ignore;
  size_t lena;
  size_t lenb;

  _Bool tmp___24;

  int tmp___27;

  {
    key = keylist;
    texta = (char *)a->keybeg;
    textb = (char *)b->keybeg;
    lima = (char *)a->keylim;
    limb = (char *)b->keylim;
    while (1) {
      translate = key->translate;
      ignore = key->ignore;

      lena = (size_t)(lima - texta);
      lenb = (size_t)(limb - textb);
      if (hard_LC_COLLATE) {
        goto _L___2;
      } else {
        tmp___24 = key_numeric((struct keyfield const *)key);
        if (tmp___24) {
          goto _L___2;
        } else {
          if (key->month) {
            goto _L___2;
          } else {
            if (key->random) {
              goto _L___2;
            } else {
              if (key->version) {
              _L___2:;
                if (ignore) {
                }
              }
            }
          }
        }
      }
      if (diff) {
        goto not_equal;
      }
      key = key->next;
      if (!key) {
        goto while_break;
      }
      if (key->eword != 0xffffffffffffffffUL) {
        lima = limfield(a, (struct keyfield const *)key);
        limb = limfield(b, (struct keyfield const *)key);
      } else {
        lima = (char *)((a->text + a->length) - 1);
        limb = (char *)((b->text + b->length) - 1);
      }
      if (key->sword != 0xffffffffffffffffUL) {
        texta = begfield(a, (struct keyfield const *)key);
        textb = begfield(b, (struct keyfield const *)key);
      } else {
        texta = (char *)a->text;
        textb = (char *)b->text;
      }
    }
  while_break:;
    return (0);
    ;
    diff = 1;
  not_equal:;
    if (key->reverse) {
      tmp___27 = -diff;
    } else {
      tmp___27 = diff;
    }
    return (tmp___27);
  }
}
static int compare(struct line const *a, struct line const *b) {
  int diff;
  size_t alen;
  size_t blen;
  size_t tmp;
  int tmp___0;

  {
    if (keylist) {
      diff = keycompare(a, b);
      if (diff) {
        return (diff);
      } else {
        if (unique) {
          return (diff);
        }
      }
    }
    alen = (size_t)(a->length - 1UL);
    blen = (size_t)(b->length - 1UL);
    if (alen == 0UL) {
      diff = -(blen != 0UL);
    } else {
      if (blen == 0UL) {
        diff = 1;
      } else {
        if (hard_LC_COLLATE) {
          diff = xmemcoll0((char const *)a->text, alen + 1UL, (char const *)b->text, blen + 1UL);
        } else {
          if (alen < blen) {
            tmp = alen;
          } else {
            tmp = blen;
          }
          diff = memcmp((void const *)a->text, (void const *)b->text, tmp);
          if (!diff) {
            if (alen < blen) {
              diff = -1;
            } else {
              diff = alen != blen;
            }
          }
        }
      }
    }
    if (reverse) {
      tmp___0 = -diff;
    } else {
      tmp___0 = diff;
    }
    return (tmp___0);
  }
}
static void write_line(struct line const *line, FILE *fp, char const *output_file) {
  char *buf___1;
  size_t n_bytes;
  char *ebuf;
  char const *c;
  char wc;
  char const *tmp;
  char *tmp___0;
  int tmp___1;
  char *tmp___2;
  size_t tmp___3;

  {
    buf___1 = (char *)line->text;
    n_bytes = (size_t)line->length;
    ebuf = buf___1 + n_bytes;
    if (!output_file) {
      if (debug) {
        c = (char const *)buf___1;
        while (1) {

          if (!((unsigned long)c < (unsigned long)ebuf)) {
            goto while_break;
          }
          tmp = c;
          c++;
          wc = (char)*tmp;

          tmp___1 = fputc_unlocked((int)wc, fp);
          if (tmp___1 == -1) {
            tmp___0 = gettext("write failed");
            die((char const *)tmp___0, output_file);
          }
        }
      while_break:;
        debug_line(line);
      } else {
        goto _L;
      }
    } else {
    _L:;
      *(ebuf + -1) = eolchar;
      tmp___3 = fwrite_unlocked((void const *)buf___1, (size_t)1, n_bytes, fp);
      if (tmp___3 != n_bytes) {
        tmp___2 = gettext("write failed");
        die((char const *)tmp___2, output_file);
      }
      *(ebuf + -1) = (char)'\000';
    }
    return;
  }
}
static _Bool check(char const *file_name___3, char checkonly) {
  FILE *fp;
  FILE *tmp;
  struct buffer buf___1;
  struct line temp;
  size_t alloc;
  uintmax_t line_number;
  struct keyfield const *key;
  _Bool nonunique;
  _Bool ordered;
  size_t tmp___0;
  struct line const *line;
  struct line const *tmp___1;
  struct line const *linebase;

  _Bool tmp___8;

  {
    tmp = xfopen(file_name___3, "r");
    fp = tmp;
    alloc = (size_t)0;
    line_number = (uintmax_t)0;
    key = (struct keyfield const *)keylist;
    nonunique = (_Bool)(!unique);
    ordered = (_Bool)1;
    if (merge_buffer_size > sort_size) {
      tmp___0 = merge_buffer_size;
    } else {
      tmp___0 = sort_size;
    }
    initbuf(&buf___1, sizeof(struct line), tmp___0);
    temp.text = (char *)((void *)0);
    while (1) {
      tmp___8 = fillbuf___7(&buf___1, fp, file_name___3);
      if (!tmp___8) {
        goto while_break;
      }
      tmp___1 = (struct line const *)buffer_linelim((struct buffer const *)(&buf___1));
      line = tmp___1;
      linebase = line - buf___1.nlines;

      ;
      line_number += buf___1.nlines;
      if (alloc < (size_t)line->length) {

        ;
        free((void *)temp.text);
        temp.text = (char *)xmalloc(alloc);
      }
      memcpy((void *)temp.text, (void const *)line->text, (size_t)line->length);
      temp.length = (size_t)line->length;
    }
  while_break:;
    xfclose(fp, file_name___3);
    free((void *)buf___1.buf);
    free((void *)temp.text);
    return (ordered);
  }
}
static size_t open_input_files(struct sortfile *files, size_t nfiles, FILE ***pfps) {
  FILE **fps;
  FILE **tmp;
  int i;
  FILE *tmp___0;
  FILE *tmp___1;

  {
    tmp = (FILE **)xnmalloc(nfiles, sizeof(*fps));
    *pfps = tmp;
    fps = tmp;
    i = 0;
    while (1) {

      if (!((size_t)i < nfiles)) {
        goto while_break;
      }
      if ((files + i)->temp) {
        if ((int)((files + i)->temp)->state != 0) {
          tmp___0 = open_temp((files + i)->temp);
          *(fps + i) = tmp___0;
        } else {
          tmp___1 = stream_open((files + i)->name, "r");
          *(fps + i) = tmp___1;
        }
      } else {
        tmp___1 = stream_open((files + i)->name, "r");
        *(fps + i) = tmp___1;
      }
      if (!*(fps + i)) {
        goto while_break;
      }
      i++;
    }
  while_break:;
    return ((size_t)i);
  }
}
static void mergefps(struct sortfile *files, size_t ntemps, size_t nfiles, FILE *ofp, char const *output_file, FILE **fps) {
  struct buffer *buffer;
  struct buffer *tmp;
  struct line saved___0;
  struct line const *savedline;
  size_t savealloc;
  struct line const **cur;
  struct line const **tmp___0;
  struct line const **base;
  struct line const **tmp___1;
  size_t *ord;
  size_t *tmp___2;
  size_t i;
  size_t j;

  struct keyfield const *key;
  size_t tmp___3;
  struct line const *linelim;
  struct line const *tmp___4;
  _Bool tmp___5;
  int tmp___6;
  struct line const *smallest;

  struct line const *linelim___0;
  struct line const *tmp___8;
  _Bool tmp___9;
  size_t lo;
  size_t hi;
  size_t probe;
  size_t ord0;
  size_t count_of_smaller_lines;
  int cmp;
  int tmp___10;

  {
    tmp = (struct buffer *)xnmalloc(nfiles, sizeof(*buffer));
    buffer = tmp;
    savedline = (struct line const *)((void *)0);
    savealloc = (size_t)0;
    tmp___0 = (struct line const **)xnmalloc(nfiles, sizeof(*cur));
    cur = tmp___0;
    tmp___1 = (struct line const **)xnmalloc(nfiles, sizeof(*base));
    base = tmp___1;
    tmp___2 = (size_t *)xnmalloc(nfiles, sizeof(*ord));
    ord = tmp___2;
    key = (struct keyfield const *)keylist;
    saved___0.text = (char *)((void *)0);
    i = (size_t)0;
    while (1) {

      if (!(i < nfiles)) {
        goto while_break;
      }

      initbuf(buffer + i, sizeof(struct line), tmp___3);
      tmp___5 = fillbuf___7(buffer + i, *(fps + i), (files + i)->name);
      if (tmp___5) {
        tmp___4 = (struct line const *)buffer_linelim((struct buffer const *)(buffer + i));
        linelim = tmp___4;
        *(cur + i) = linelim - 1;
        *(base + i) = linelim - (buffer + i)->nlines;
        i++;
      } else {
        xfclose(*(fps + i), (files + i)->name);

        free((void *)(buffer + i)->buf);
        nfiles--;
        j = i;
        while (1) {

          if (!(j < nfiles)) {
            goto while_break___0;
          }
          *(files + j) = *(files + (j + 1UL));
          *(fps + j) = *(fps + (j + 1UL));
          j++;
        }
      while_break___0:;
      }
    }
  while_break:;
    i = (size_t)0;
    while (1) {

      if (!(i < nfiles)) {
        goto while_break___1;
      }
      *(ord + i) = i;
      i++;
    }
  while_break___1:;
    i = (size_t)1;
    while (1) {

      if (!(i < nfiles)) {
        goto while_break___2;
      }
      tmp___6 = compare(*(cur + *(ord + (i - 1UL))), *(cur + *(ord + i)));

      i++;
    }
  while_break___2:;
    while (1) {
    while_continue___3:;
      if (!nfiles) {
        goto while_break___3;
      }
      smallest = *(cur + *(ord + 0));

      if ((unsigned long)*(base + *(ord + 0)) < (unsigned long)smallest) {
        *(cur + *(ord + 0)) = smallest - 1;
      } else {
        tmp___9 = fillbuf___7(buffer + *(ord + 0), *(fps + *(ord + 0)), (files + *(ord + 0))->name);
        if (tmp___9) {
          tmp___8 = (struct line const *)buffer_linelim((struct buffer const *)(buffer + *(ord + 0)));
          linelim___0 = tmp___8;
          *(cur + *(ord + 0)) = linelim___0 - 1;
          *(base + *(ord + 0)) = linelim___0 - (buffer + *(ord + 0))->nlines;
        } else {
          i = (size_t)1;
          while (1) {

            if (!(i < nfiles)) {
              goto while_break___5;
            }
            if (*(ord + i) > *(ord + 0)) {
              (*(ord + i))--;
            }
            i++;
          }
        while_break___5:;
          nfiles--;
          xfclose(*(fps + *(ord + 0)), (files + *(ord + 0))->name);

          free((void *)(buffer + *(ord + 0))->buf);
          i = *(ord + 0);

          ;
          i = (size_t)0;

          ;
          goto while_continue___3;
        }
      }
      lo = (size_t)1;
      hi = nfiles;
      probe = lo;
      ord0 = *(ord + 0);
      while (1) {

        if (!(lo < hi)) {
          goto while_break___8;
        }
        tmp___10 = compare(*(cur + ord0), *(cur + *(ord + probe)));
        cmp = tmp___10;
        if (cmp < 0) {
          hi = probe;
        } else {
          if (cmp == 0) {
            if (ord0 < *(ord + probe)) {
              hi = probe;
            } else {
              lo = probe + 1UL;
            }
          } else {
            lo = probe + 1UL;
          }
        }
        probe = (lo + hi) / 2UL;
      }
    while_break___8:;
      count_of_smaller_lines = lo - 1UL;
      j = (size_t)0;
      while (1) {

        if (!(j < count_of_smaller_lines)) {
          goto while_break___9;
        }
        *(ord + j) = *(ord + (j + 1UL));
        j++;
      }
    while_break___9:;
      *(ord + count_of_smaller_lines) = ord0;
    }
  while_break___3:;
    xfclose(ofp, output_file);
    free((void *)fps);
    free((void *)buffer);
    free((void *)ord);
    free((void *)base);
    free((void *)cur);
    return;
  }
}
static size_t mergefiles(struct sortfile *files, size_t ntemps, size_t nfiles, FILE *ofp, char const *output_file) {
  FILE **fps;
  size_t nopened;
  size_t tmp;
  char *tmp___0;

  {
    tmp = open_input_files(files, nfiles, &fps);
    nopened = tmp;
    if (nopened < nfiles) {
      if (nopened < 2UL) {
        tmp___0 = gettext("open failed");
        die((char const *)tmp___0, (files + nopened)->name);
      }
    }
    mergefps(files, ntemps, nopened, ofp, output_file, fps);
    return (nopened);
  }
}
static void mergelines(struct line *__restrict t, size_t nlines, struct line const *__restrict lo) {
  size_t nlo;
  size_t nhi;
  struct line *hi;
  int tmp;

  {
    nlo = nlines / 2UL;
    nhi = nlines - nlo;
    hi = (struct line *)(t - nlo);
    while (1) {
      tmp = compare((struct line const *)(lo - 1), (struct line const *)(hi - 1));
      if (tmp <= 0) {
        t--;
        lo--;
        *t = (struct line) * lo;
        nlo--;
        if (!nlo) {
          return;
        }
      } else {
        t--;
        hi--;
        *t = *hi;
        nhi--;
        if (!nhi) {
          while (1) {
            t--;
            lo--;
            *t = (struct line) * lo;
            nlo--;
            if (!nlo) {
              goto while_break___0;
            }
          }
        while_break___0:;
          return;
        }
      }
    }

    return;
  }
}
static void sequential_sort(struct line *__restrict lines, size_t nlines, struct line *__restrict temp, _Bool to_temp) {
  int swap___1;
  int tmp;
  size_t nlo;
  size_t nhi;
  struct line *lo;
  struct line *hi;
  size_t tmp___0;
  struct line *dest;
  struct line const *sorted_lo;

  {
    if (nlines == 2UL) {
      tmp = compare((struct line const *)(lines + -1), (struct line const *)(lines + -2));
      swap___1 = 0 < tmp;
      if (to_temp) {
        *(temp + -1) = *(lines + (-1 - swap___1));
        *(temp + -2) = *(lines + (-2 + swap___1));
      } else {
        if (swap___1) {
          *(temp + -1) = *(lines + -1);
          *(lines + -1) = *(lines + -2);
          *(lines + -2) = *(temp + -1);
        }
      }
    } else {
      nlo = nlines / 2UL;
      nhi = nlines - nlo;
      lo = (struct line *)lines;
      hi = (struct line *)(lines - nlo);
      if (to_temp) {
        tmp___0 = nlo;
      } else {
        tmp___0 = (size_t)0;
      }
      sequential_sort(hi, nhi, temp - tmp___0, to_temp);
      if (1UL < nlo) {
        sequential_sort(lo, nlo, temp, (_Bool)(!to_temp));
      } else {
        if (!to_temp) {
          *(temp + -1) = *(lo + -1);
        }
      }
      if (to_temp) {
        dest = (struct line *)temp;
        sorted_lo = (struct line const *)lines;
      } else {
        dest = (struct line *)lines;
        sorted_lo = (struct line const *)temp;
      }
      mergelines(dest, nlines, sorted_lo);
    }
    return;
  }
}
static struct merge_node *init_node(struct merge_node *__restrict parent, struct merge_node *__restrict node_pool, struct line *dest, size_t nthreads, size_t total_lines, _Bool is_lo_child);
static struct merge_node *merge_tree_init(size_t nthreads, size_t nlines, struct line *dest) {
  struct merge_node *merge_tree;
  struct merge_node *tmp;
  struct merge_node *root;
  struct line *tmp___0;
  struct line *tmp___1;
  struct line *tmp___2;
  size_t tmp___3;

  {
    tmp = (struct merge_node *)xmalloc((2UL * sizeof(*merge_tree)) * nthreads);
    merge_tree = tmp;
    root = merge_tree;
    tmp___2 = (struct line *)((void *)0);
    root->end_hi = tmp___2;
    tmp___1 = tmp___2;
    root->end_lo = tmp___1;
    tmp___0 = tmp___1;
    root->hi = tmp___0;
    root->lo = tmp___0;
    root->dest = (struct line **)((void *)0);
    tmp___3 = nlines;
    root->nhi = tmp___3;
    root->nlo = tmp___3;
    root->parent = (struct merge_node *)((void *)0);
    root->level = 0U;
    root->queued = (_Bool)0;
    pthread_mutex_init(&root->lock, (pthread_mutexattr_t const *)((void *)0));
    init_node(root, root + 1, dest, nthreads, nlines, (_Bool)0);
    return (merge_tree);
  }
}
static void merge_tree_destroy(struct merge_node *merge_tree) {

  {
    free((void *)merge_tree);
    return;
  }
}
static struct merge_node *init_node(struct merge_node *__restrict parent, struct merge_node *__restrict node_pool, struct line *dest, size_t nthreads, size_t total_lines, _Bool is_lo_child) {
  size_t nlines;
  size_t tmp;
  size_t nlo;
  size_t nhi;
  struct line *lo;
  struct line *hi;
  struct line **parent_end;
  struct line **tmp___0;
  struct merge_node *node;
  struct merge_node *__restrict tmp___1;
  struct line *tmp___2;
  struct line *tmp___3;
  size_t lo_threads;
  size_t hi_threads;
  struct merge_node *tmp___4;
  struct merge_node *tmp___5;

  {
    if (is_lo_child) {
      tmp = parent->nlo;
    } else {
      tmp = parent->nhi;
    }
    nlines = tmp;
    nlo = nlines / 2UL;
    nhi = nlines - nlo;
    lo = dest - total_lines;
    hi = lo - nlo;
    if (is_lo_child) {
      tmp___0 = &parent->end_lo;
    } else {
      tmp___0 = &parent->end_hi;
    }
    parent_end = tmp___0;
    tmp___1 = node_pool;
    node_pool++;
    node = (struct merge_node *)tmp___1;
    tmp___2 = lo;
    node->end_lo = tmp___2;
    node->lo = tmp___2;
    tmp___3 = hi;
    node->end_hi = tmp___3;
    node->hi = tmp___3;
    node->dest = parent_end;
    node->nlo = nlo;
    node->nhi = nhi;
    node->parent = (struct merge_node *)parent;
    node->level = parent->level + 1U;
    node->queued = (_Bool)0;
    pthread_mutex_init(&node->lock, (pthread_mutexattr_t const *)((void *)0));
    if (nthreads > 1UL) {
      lo_threads = nthreads / 2UL;
      hi_threads = nthreads - lo_threads;
      node->lo_child = (struct merge_node *)node_pool;
      tmp___4 = init_node(node, node_pool, lo, lo_threads, total_lines, (_Bool)1);
      node_pool = tmp___4;
      node->hi_child = (struct merge_node *)node_pool;
      tmp___5 = init_node(node, node_pool, hi, hi_threads, total_lines, (_Bool)0);
      node_pool = tmp___5;
    } else {
      node->lo_child = (struct merge_node *)((void *)0);
      node->hi_child = (struct merge_node *)((void *)0);
    }
    return ((struct merge_node *)node_pool);
  }
}
static int compare_nodes(void const *a, void const *b) {
  struct merge_node const *nodea;
  struct merge_node const *nodeb;

  {
    nodea = (struct merge_node const *)a;
    nodeb = (struct merge_node const *)b;
    if (nodea->level == nodeb->level) {
      return (nodea->nlo + nodea->nhi < nodeb->nlo + nodeb->nhi);
    }
    return (nodea->level < nodeb->level);
  }
}
__inline static void lock_node(struct merge_node *node) {

  {
    pthread_mutex_lock(&node->lock);
    return;
  }
}
__inline static void unlock_node(struct merge_node *node) {

  {
    pthread_mutex_unlock(&node->lock);
    return;
  }
}
static void queue_destroy(struct merge_node_queue *queue) {

  {
    heap_free(queue->priority_queue);
    pthread_cond_destroy(&queue->cond);
    pthread_mutex_destroy(&queue->mutex);
    return;
  }
}
static void queue_init(struct merge_node_queue *queue, size_t nthreads) {

  {
    queue->priority_queue = heap_alloc(&compare_nodes, 2UL * nthreads);
    pthread_mutex_init(&queue->mutex, (pthread_mutexattr_t const *)((void *)0));
    pthread_cond_init(&queue->cond, (pthread_condattr_t const *)((void *)0));
    return;
  }
}
static void queue_insert(struct merge_node_queue *queue, struct merge_node *node) {

  {
    pthread_mutex_lock(&queue->mutex);
    heap_insert(queue->priority_queue, (void *)node);
    node->queued = (_Bool)1;
    pthread_mutex_unlock(&queue->mutex);
    pthread_cond_signal(&queue->cond);
    return;
  }
}
static struct merge_node *queue_pop(struct merge_node_queue *queue) {
  struct merge_node *node;

  {
    pthread_mutex_lock(&queue->mutex);
    while (1) {
      node = (struct merge_node *)heap_remove_top(queue->priority_queue);
      if (node) {
        goto while_break;
      }
      pthread_cond_wait(&queue->cond, &queue->mutex);
    }
  while_break:;
    pthread_mutex_unlock(&queue->mutex);
    lock_node(node);
    node->queued = (_Bool)0;
    return (node);
  }
}
static struct line saved;
static void write_unique(struct line const *line, FILE *tfp, char const *temp_output) {

  {
    if (unique) {

      saved = (struct line) * line;
    }
    write_line(line, tfp, temp_output);
    return;
  }
}
static void mergelines_node(struct merge_node *__restrict node, size_t total_lines, FILE *tfp, char const *temp_output) {
  struct line *lo_orig;
  struct line *hi_orig;
  size_t to_merge;
  size_t merged_lo;
  size_t merged_hi;
  struct line *dest;
  int tmp;
  size_t tmp___0;
  size_t tmp___1;
  size_t tmp___2;
  int tmp___3;
  size_t tmp___4;
  size_t tmp___5;
  size_t tmp___6;

  {
    lo_orig = node->lo;
    hi_orig = node->hi;
    to_merge = (total_lines >> 2U * (node->level + 1U)) + 1UL;
    if (node->level > 1U) {
      dest = *(node->dest);
      while (1) {

        if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
          if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
            tmp___0 = to_merge;
            to_merge--;
            if (!tmp___0) {
              goto while_break;
            }
          } else {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        tmp = compare((struct line const *)(node->lo - 1), (struct line const *)(node->hi - 1));
        if (tmp <= 0) {
          dest--;
          (node->lo)--;
          *dest = *(node->lo);
        } else {
          dest--;
          (node->hi)--;
          *dest = *(node->hi);
        }
      }
    while_break:;
      merged_lo = (size_t)(lo_orig - node->lo);
      merged_hi = (size_t)(hi_orig - node->hi);
      if (node->nhi == merged_hi) {
        while (1) {

          if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
            tmp___1 = to_merge;
            to_merge--;
            if (!tmp___1) {
              goto while_break___0;
            }
          } else {
            goto while_break___0;
          }
          dest--;
          (node->lo)--;
          *dest = *(node->lo);
        }
      while_break___0:;
      } else {
        if (node->nlo == merged_lo) {
          while (1) {

            if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
              tmp___2 = to_merge;
              to_merge--;
              if (!tmp___2) {
                goto while_break___1;
              }
            } else {
              goto while_break___1;
            }
            dest--;
            (node->hi)--;
            *dest = *(node->hi);
          }
        while_break___1:;
        }
      }
      *(node->dest) = dest;
    } else {
      while (1) {

        if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
          if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
            tmp___4 = to_merge;
            to_merge--;
            if (!tmp___4) {
              goto while_break___2;
            }
          } else {
            goto while_break___2;
          }
        } else {
          goto while_break___2;
        }
        tmp___3 = compare((struct line const *)(node->lo - 1), (struct line const *)(node->hi - 1));
        if (tmp___3 <= 0) {
          (node->lo)--;
          write_unique((struct line const *)node->lo, tfp, temp_output);
        } else {
          (node->hi)--;
          write_unique((struct line const *)node->hi, tfp, temp_output);
        }
      }
    while_break___2:;
      merged_lo = (size_t)(lo_orig - node->lo);
      merged_hi = (size_t)(hi_orig - node->hi);
      if (node->nhi == merged_hi) {
        while (1) {

          if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
            tmp___5 = to_merge;
            to_merge--;
            if (!tmp___5) {
              goto while_break___3;
            }
          } else {
            goto while_break___3;
          }
          (node->lo)--;
          write_unique((struct line const *)node->lo, tfp, temp_output);
        }
      while_break___3:;
      } else {
        if (node->nlo == merged_lo) {
          while (1) {

            if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
              tmp___6 = to_merge;
              to_merge--;
              if (!tmp___6) {
                goto while_break___4;
              }
            } else {
              goto while_break___4;
            }
            (node->hi)--;
            write_unique((struct line const *)node->hi, tfp, temp_output);
          }
        while_break___4:;
        }
      }
    }
    merged_lo = (size_t)(lo_orig - node->lo);
    merged_hi = (size_t)(hi_orig - node->hi);
    node->nlo -= merged_lo;
    node->nhi -= merged_hi;
    return;
  }
}
static void queue_check_insert(struct merge_node_queue *queue, struct merge_node *node) {
  _Bool lo_avail;
  _Bool hi_avail;
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    if (!node->queued) {
      lo_avail = (_Bool)(node->lo - node->end_lo != 0L);
      hi_avail = (_Bool)(node->hi - node->end_hi != 0L);
      if (lo_avail) {
        if (hi_avail) {
          tmp = 1;
        }
        tmp___1 = tmp;
      } else {
        if (hi_avail) {
          if (!node->nlo) {
            tmp___0 = 1;
          } else {
            tmp___0 = 0;
          }
        } else {
          tmp___0 = 0;
        }
        tmp___1 = tmp___0;
      }
      if (tmp___1) {
        queue_insert(queue, node);
      }
    }
    return;
  }
}
static void queue_check_insert_parent(struct merge_node_queue *queue, struct merge_node *node) {

  {
    if (node->level > 1U) {
      lock_node(node->parent);
      queue_check_insert(queue, node->parent);
      unlock_node(node->parent);
    } else {
      if (node->nlo + node->nhi == 0UL) {
        queue_insert(queue, node->parent);
      }
    }
    return;
  }
}
static void merge_loop(struct merge_node_queue *queue, size_t total_lines, FILE *tfp, char const *temp_output) {
  struct merge_node *node;
  struct merge_node *tmp;

  {
    while (1) {
      tmp = queue_pop(queue);
      node = tmp;
      if (node->level == 0U) {
        unlock_node(node);
        queue_insert(queue, node);
        goto while_break;
      }
      mergelines_node(node, total_lines, tfp, temp_output);
      queue_check_insert(queue, node);
      queue_check_insert_parent(queue, node);
      unlock_node(node);
    }
  while_break:;
    return;
  }
}
static void sortlines(struct line *__restrict lines, size_t nthreads, size_t total_lines, struct merge_node *node, struct merge_node_queue *queue, FILE *tfp, char const *temp_output);
static void *sortlines_thread(void *data) {
  struct thread_args const *args;

  {
    args = (struct thread_args const *)data;
    sortlines((struct line *)args->lines, (size_t)args->nthreads, (size_t)args->total_lines, (struct merge_node *)args->node, (struct merge_node_queue *)args->queue, (FILE *)args->tfp, (char const *)args->output_temp);
    return ((void *)0);
  }
}
static void sortlines(struct line *__restrict lines, size_t nthreads, size_t total_lines, struct merge_node *node, struct merge_node_queue *queue, FILE *tfp, char const *temp_output) {
  size_t nlines;
  size_t lo_threads;
  size_t hi_threads;
  pthread_t thread;
  struct thread_args args;
  size_t nlo;
  size_t nhi;
  struct line *temp;
  int tmp;

  {
    nlines = node->nlo + node->nhi;
    lo_threads = nthreads / 2UL;
    hi_threads = nthreads - lo_threads;
    args.lines = (struct line *)lines;
    args.nthreads = lo_threads;
    args.total_lines = total_lines;
    args.node = node->lo_child;
    args.queue = queue;
    args.tfp = tfp;
    args.output_temp = temp_output;
    if (nthreads > 1UL) {
      if (131072UL <= nlines) {
        tmp = pthread_create(&thread, (pthread_attr_t const *)((void *)0), &sortlines_thread, (void *)(&args));

      } else {
        goto _L___0;
      }
    } else {
    _L___0:;
      nlo = node->nlo;
      nhi = node->nhi;
      temp = (struct line *)(lines - total_lines);
      if (1UL < nhi) {
        sequential_sort(lines - nlo, nhi, temp - nlo / 2UL, (_Bool)0);
      }
      if (1UL < nlo) {
        sequential_sort(lines, nlo, temp, (_Bool)0);
      }
      node->lo = (struct line *)lines;
      node->hi = (struct line *)(lines - nlo);
      node->end_lo = (struct line *)(lines - nlo);
      node->end_hi = (struct line *)((lines - nlo) - nhi);
      queue_insert(queue, node);
      merge_loop(queue, total_lines, tfp, temp_output);
    }
    pthread_mutex_destroy(&node->lock);
    return;
  }
}
static void avoid_trashing_input(struct sortfile *files, size_t ntemps, size_t nfiles, char const *outfile) {
  size_t i;
  _Bool got_outstat;

  struct tempnode *tempcopy;

  {
    got_outstat = (_Bool)0;
    tempcopy = (struct tempnode *)((void *)0);
    i = ntemps;

    ;
    return;
  }
}
static void merge(struct sortfile *files, size_t ntemps, size_t nfiles, char const *output_file) {
  size_t in;
  size_t out;
  size_t remainder;
  size_t cheap_slots;
  FILE *tfp;
  struct tempnode *temp;
  struct tempnode *tmp;
  size_t num_merged;
  size_t tmp___0;
  size_t tmp___1;
  size_t tmp___2;

  FILE **fps;
  size_t nopened;
  size_t tmp___8;
  FILE *ofp;
  FILE *tmp___9;
  char *tmp___10;
  int *tmp___11;

  FILE *tfp___1;
  struct tempnode *temp___1;
  size_t tmp___13;
  size_t tmp___14;

  {
    while (1) {

      if (!((size_t)nmerge < nfiles)) {
        goto while_break;
      }
      in = (size_t)0;
      out = in;
      while (1) {

        if (!((size_t)nmerge <= nfiles - in)) {
          goto while_break___0;
        }
        tmp = create_temp(&tfp);
        temp = tmp;

        tmp___1 = mergefiles(files + in, tmp___0, (size_t)nmerge, tfp, (char const *)(temp->name));
        num_merged = tmp___1;

        ntemps -= tmp___2;
        (files + out)->name = (char const *)(temp->name);
        (files + out)->temp = temp;
        in += num_merged;
        out++;
      }
    while_break___0:;
      remainder = nfiles - in;
      cheap_slots = (unsigned long)nmerge - out % (unsigned long)nmerge;

      memmove((void *)(files + out), (void const *)(files + in), (nfiles - in) * sizeof(*files));
      ntemps += out;
      nfiles -= in - out;
    }
  while_break:;
    avoid_trashing_input(files, ntemps, nfiles, output_file);
    while (1) {
      tmp___8 = open_input_files(files, nfiles, &fps);
      nopened = tmp___8;
      if (nopened == nfiles) {
        tmp___9 = stream_open(output_file, "w");
        ofp = tmp___9;
        if (ofp) {
          mergefps(files, ntemps, nfiles, ofp, output_file, fps);
          goto while_break___1;
        }
        tmp___11 = __errno_location();
        if (*tmp___11 != 24) {
          tmp___10 = gettext("open failed");
          die((char const *)tmp___10, output_file);
        } else {
          if (nopened <= 2UL) {
            tmp___10 = gettext("open failed");
            die((char const *)tmp___10, output_file);
          }
        }
      }
      while (1) {
        nopened--;
        xfclose(*(fps + nopened), (files + nopened)->name);
        temp___1 = maybe_create_temp(&tfp___1, (_Bool)(!(nopened <= 2UL)));
        if (!(!temp___1)) {
          goto while_break___2;
        }
      }
    while_break___2:;
      mergefps(files + 0, tmp___13, nopened, tfp___1, (char const *)(temp___1->name), fps);

      ntemps -= tmp___14;
      (files + 0)->name = (char const *)(temp___1->name);
      (files + 0)->temp = temp___1;
      memmove((void *)(files + 1), (void const *)(files + nopened), (nfiles - nopened) * sizeof(*files));
      ntemps++;
      nfiles -= nopened - 1UL;
    }
  while_break___1:;
    return;
  }
}
static void sort(char *const *files, size_t nfiles, char const *output_file, size_t nthreads) {
  struct buffer buf___1;
  size_t ntemps;
  _Bool output_file_created;
  char const *temp_output;
  char const *file;
  FILE *fp;
  FILE *tmp;
  FILE *tfp;
  size_t bytes_per_line;
  size_t tmp___0;
  size_t mult;
  size_t tmp___1;
  struct line *line;
  struct tempnode *tmp___2;
  struct merge_node_queue queue;
  struct merge_node *merge_tree;
  struct merge_node *tmp___3;
  struct merge_node *root;
  _Bool tmp___4;
  size_t i;
  struct tempnode *node;
  struct sortfile *tempfiles;
  struct sortfile *tmp___5;

  {
    ntemps = (size_t)0;
    output_file_created = (_Bool)0;
    buf___1.alloc = (size_t)0;
    while (1) {

      if (!nfiles) {
        goto while_break;
      }
      file = (char const *)*files;
      tmp = xfopen(file, "r");
      fp = tmp;
      if (nthreads > 1UL) {
        tmp___0 = (size_t)1;
        mult = (size_t)1;
        while (1) {

          if (!(tmp___0 < nthreads)) {
            goto while_break___0;
          }
          tmp___0 *= 2UL;
          mult++;
        }
      while_break___0:;
        bytes_per_line = mult * sizeof(struct line);
      } else {
        bytes_per_line = (sizeof(struct line) * 3UL) / 2UL;
      }
      if (!buf___1.alloc) {
        tmp___1 = sort_buffer_size((FILE *const *)(&fp), (size_t)1, files, nfiles, bytes_per_line);
        initbuf(&buf___1, bytes_per_line, tmp___1);
      }
      buf___1.eof = (_Bool)0;
      files++;
      nfiles--;
      while (1) {
        tmp___4 = fillbuf___7(&buf___1, fp, file);
        if (!tmp___4) {
          goto while_break___1;
        }

        line = buffer_linelim((struct buffer const *)(&buf___1));
        if (buf___1.eof) {
          if (!nfiles) {
            if (!ntemps) {
              if (!buf___1.left) {
                xfclose(fp, file);
                tfp = xfopen(output_file, "w");
                temp_output = output_file;
                output_file_created = (_Bool)1;
              } else {
                ntemps++;
                tmp___2 = create_temp(&tfp);
                temp_output = (char const *)(tmp___2->name);
              }
            } else {
              ntemps++;
              tmp___2 = create_temp(&tfp);
              temp_output = (char const *)(tmp___2->name);
            }
          } else {
            ntemps++;
            tmp___2 = create_temp(&tfp);
            temp_output = (char const *)(tmp___2->name);
          }
        } else {
          ntemps++;
          tmp___2 = create_temp(&tfp);
          temp_output = (char const *)(tmp___2->name);
        }
        if (1UL < buf___1.nlines) {
          queue_init(&queue, nthreads);
          tmp___3 = merge_tree_init(nthreads, buf___1.nlines, line);
          merge_tree = tmp___3;
          root = merge_tree + 1;
          sortlines(line, nthreads, buf___1.nlines, root, &queue, tfp, temp_output);
          queue_destroy(&queue);
          pthread_mutex_destroy(&root->lock);
          merge_tree_destroy(merge_tree);
        } else {
          write_unique((struct line const *)(line - 1), tfp, temp_output);
        }
        xfclose(tfp, temp_output);
        if (output_file_created) {
          goto finish;
        }
      }
    while_break___1:;
      xfclose(fp, file);
    }
  while_break:;
  finish:;
    free((void *)buf___1.buf);
    if (!output_file_created) {
      node = (struct tempnode *)temphead;
      tmp___5 = (struct sortfile *)xnmalloc(ntemps, sizeof(*tempfiles));
      tempfiles = tmp___5;
      i = (size_t)0;
      while (1) {

        if (!node) {
          goto while_break___2;
        }
        (tempfiles + i)->name = (char const *)(node->name);
        (tempfiles + i)->temp = node;
        node = (struct tempnode *)node->next;
        i++;
      }
    while_break___2:;
      merge(tempfiles, ntemps, ntemps, output_file);
      free((void *)tempfiles);
    }
    reap_all();
    return;
  }
}
static void insertkey(struct keyfield *key_arg) {}
static __attribute__((__noreturn__)) void badfieldspec(char const *spec, char const *msgid);
static __attribute__((__noreturn__)) void badfieldspec(char const *spec, char const *msgid);
static __attribute__((__noreturn__)) void incompatible_options(char const *opts___1);
static __attribute__((__noreturn__)) void incompatible_options(char const *opts___1);
static void check_ordering_compatibility(void) {
  struct keyfield *key;

  {
    key = keylist;
    while (1) {

      if (!key) {
        goto while_break;
      }

      key = key->next;
    }
  while_break:;
    return;
  }
}
static char const *parse_field_count(char const *string, size_t *val, char const *msgid) {}
static char *set_ordering(char const *s, struct keyfield *key, enum blanktype blanktype) {}
static struct keyfield *key_init(struct keyfield *key) {

  {
    memset((void *)key, 0, sizeof(*key));
    key->eword = 0xffffffffffffffffUL;
    return (key);
  }
}
static void sighandler(int sig___0) {}
int main(int argc, char **argv);
static int const sig[11] = {(int const)14, (int const)1, (int const)2, (int const)13, (int const)3, (int const)15, (int const)29, (int const)27, (int const)26, (int const)24, (int const)25};
static char opts[10] = {(char)'X', (char)' ', (char)'-', (char)'-', (char)'d', (char)'e', (char)'b', (char)'u', (char)'g', (char)'\000'};
static char *minus = (char *)"-";
static char opts___0[3] = {(char)0, (char)'o', (char)0};
int main(int argc, char **argv) {
  struct keyfield *key;
  struct keyfield key_buf;
  struct keyfield gkey;
  _Bool gkey_only;
  char const *s;
  int c;
  char checkonly;
  _Bool mergeonly;
  char *random_source;
  _Bool need_random;
  size_t nthreads;
  size_t nfiles;
  _Bool posixly_correct;
  char *tmp;
  _Bool obsolete_usage;
  int tmp___0;
  char **files;
  char *files_from;
  struct Tokens tok;
  char const *outfile;
  struct lconv const *locale;
  struct lconv const *tmp___1;
  size_t i;
  struct sigaction act;
  int tmp___2;
  int oi;
  size_t tmp___3;
  int tmp___4;
  _Bool minus_pos_usage;
  int tmp___5;
  int tmp___6;

  size_t tmp___10;
  ptrdiff_t tmp___11;
  char str[2];

  size_t tmp___15;

  char newtab;

  FILE *stream;
  char const *tmp___27;
  char *tmp___28;
  char *tmp___29;

  int tmp___33;

  _Bool tmp___36;

  _Bool tmp___45;
  _Bool tmp___46;

  char const *tmp_dir;
  char const *tmp___51;
  char const *tmp___52;

  int tmp___56;
  _Bool tmp___57;
  struct sortfile *sortfiles;
  struct sortfile *tmp___58;
  size_t i___1;
  unsigned long np;
  unsigned long tmp___59;
  size_t nthreads_max;

  int tmp___61;

  {
    gkey_only = (_Bool)0;
    c = 0;
    checkonly = (char)0;
    mergeonly = (_Bool)0;
    random_source = (char *)((void *)0);
    need_random = (_Bool)0;
    nthreads = (size_t)0;
    nfiles = (size_t)0;
    tmp = getenv("POSIXLY_CORRECT");
    posixly_correct = (_Bool)((unsigned long)tmp != (unsigned long)((void *)0));
    tmp___0 = posix2_version();
    obsolete_usage = (_Bool)(tmp___0 < 200112);
    files_from = (char *)((void *)0);
    outfile = (char const *)((void *)0);
    set_program_name((char const *)*(argv + 0));
    setlocale(6, "");
    bindtextdomain("coreutils", "/usr/local/share/locale");
    textdomain("coreutils");
    initialize_exit_failure(2);
    hard_LC_COLLATE = hard_locale(3);
    hard_LC_TIME = hard_locale(2);
    tmp___1 = (struct lconv const *)localeconv();
    locale = tmp___1;
    decimal_point = (int)to_uchar(*(locale->decimal_point + 0));
    if (!decimal_point) {
      decimal_point = '.';
    } else {
      if (*(locale->decimal_point + 1)) {
        decimal_point = '.';
      }
    }
    thousands_sep = (int)to_uchar(*(locale->thousands_sep));
    if (!thousands_sep) {
      thousands_sep = -1;
    } else {
      if (*(locale->thousands_sep + 1)) {
        thousands_sep = -1;
      }
    }
    have_read_stdin = (_Bool)0;
    inittables();
    sigemptyset(&caught_signals);
    i = (size_t)0;
    while (1) {

      if (!(i < 11UL)) {
        goto while_break;
      }
      sigaction((int)sig[i], (struct sigaction const *)((void *)0), &act);
      if ((unsigned long)act.__sigaction_handler.sa_handler != (unsigned long)((void (*)(int))1)) {
        sigaddset(&caught_signals, (int)sig[i]);
      }
      i++;
    }
  while_break:;
    act.__sigaction_handler.sa_handler = &sighandler;
    act.sa_mask = caught_signals;
    act.sa_flags = 0;
    i = (size_t)0;
    while (1) {

      if (!(i < 11UL)) {
        goto while_break___0;
      }
      tmp___2 = sigismember((sigset_t const *)(&caught_signals), (int)sig[i]);
      if (tmp___2) {
        sigaction((int)sig[i], (struct sigaction const *)(&act), (struct sigaction *)((void *)0));
      }
      i++;
    }
  while_break___0:;
    signal(17, (void (*)(int))0);
    atexit(&exit_cleanup);
    key_init(&gkey);
    gkey.sword = 0xffffffffffffffffUL;
    files = (char **)xnmalloc((size_t)argc, sizeof(*files));
    while (1) {
      oi = -1;
      if (c == -1) {
        goto _L;
      } else {
        if (posixly_correct) {

        } else {
          ;
          c = getopt_long(argc, (char *const *)argv, short_options, long_options___1, &oi);
          if (c == -1) {
          _L:;
            if (argc <= optind) {
              goto while_break___1;
            }
            tmp___3 = nfiles;
            nfiles++;
            tmp___4 = optind;
            optind++;
            *(files + tmp___3) = *(argv + tmp___4);
          } else {
            if (c == 1) {
              goto case_1;
            }

            if (c == 100) {
              goto case_98;
            }
            if (c == 102) {
              goto case_98;
            }
            if (c == 103) {
              goto case_98;
            }

            if (c == 105) {
              goto case_98;
            }

            if (c == 99) {
              goto case_99;
            }

            if (c == 109) {
              goto case_109;
            }

            if (c == 117) {
              goto case_117;
            }

            goto switch_default;
          case_1:;
            key = (struct keyfield *)((void *)0);
            if ((int)*(optarg + 0) == 43) {

              minus_pos_usage = (_Bool)tmp___5;

              obsolete_usage = (_Bool)((int)obsolete_usage | tmp___6);
            }
            if (!key) {
              tmp___10 = nfiles;
              nfiles++;
              *(files + tmp___10) = optarg;
            }
            goto switch_break;
            ;
            tmp___11 = __xargmatch_internal("--sort", (char const *)optarg, sort_args, sort_types, sizeof(sort_types[0]), argmatch_die);
            c = (int)sort_types[tmp___11];
          case_98:;
            str[0] = (char)c;
            str[1] = (char)'\000';
            set_ordering((char const *)(str), &gkey, (enum blanktype)2);
            goto switch_break;
            ;

          case_99:;
            checkonly = (char)c;
            goto switch_break;
            ;

            compress_program = (char const *)optarg;
            goto switch_break;
            ;
            debug = (_Bool)1;
            goto switch_break;
            ;
            files_from = optarg;
            goto switch_break;
            ;
            key = key_init(&key_buf);
            s = parse_field_count((char const *)optarg, &key->sword, "invalid number at field start");
            tmp___15 = key->sword;
            (key->sword)--;

            s = (char const *)set_ordering(s, key, (enum blanktype)0);

            insertkey(key);
            goto switch_break;
          case_109:;
            mergeonly = (_Bool)1;
            goto switch_break;
            ;
            specify_nmerge(oi, (char)c, (char const *)optarg);
            goto switch_break;
            ;

            outfile = (char const *)optarg;
            goto switch_break;
            ;

            random_source = optarg;
            goto switch_break;
            ;
            stable = (_Bool)1;
            goto switch_break;
            ;
            specify_sort_size(oi, (char)c, (char const *)optarg);
            goto switch_break;
            ;
            newtab = *(optarg + 0);

            tab = (int)newtab;
            goto switch_break;
            ;
            add_temp_dir((char const *)optarg);
            goto switch_break;
            ;
            nthreads = specify_nthreads(oi, (char)c, (char const *)optarg);
            goto switch_break;
          case_117:;
            unique = (_Bool)1;
            goto switch_break;
            ;

            goto switch_break;
            ;
            eolchar = (char)0;
            goto switch_break;
            ;
            usage(0);
            goto switch_break;
            ;
            version_etc(stdout, "sort", "GNU coreutils", Version, "Mike Haertel", "Paul Eggert", (char *)((void *)0));
            exit(0);
            goto switch_break;
          switch_default:;
            usage(2);
          switch_break:;
          }
        }
      }
    }
  while_break___1:;
    if (files_from) {
      if (nfiles) {
        tmp___27 = quote((char const *)*(files + 0));
        tmp___28 = gettext("extra operand %s");
        error(0, 0, (char const *)tmp___28, tmp___27);
        tmp___29 = gettext("file operands cannot be combined with --files0-from");
        fprintf(stderr, "%s\n", tmp___29);
        usage(2);
      }
      tmp___33 = strcmp((char const *)files_from, "-");

      readtokens0_init(&tok);
      tmp___36 = readtokens0(stream, &tok);
    }
    key = keylist;
    while (1) {

      if (!key) {
        goto while_break___4;
      }
      tmp___45 = default_key_compare((struct keyfield const *)key);

      need_random = (_Bool)((int)need_random | (int)key->random);
      key = key->next;
    }
  while_break___4:;
    if (!keylist) {
      tmp___46 = default_key_compare((struct keyfield const *)(&gkey));
      if (!tmp___46) {
        gkey_only = (_Bool)1;
        insertkey(&gkey);
        need_random = (_Bool)((int)need_random | (int)gkey.random);
      }
    }
    check_ordering_compatibility();
    if (debug) {

      key_warnings((struct keyfield const *)(&gkey), gkey_only);
    }
    reverse = gkey.reverse;
    if (need_random) {
      random_md5_state_init((char const *)random_source);
    }
    if (temp_dir_count == 0UL) {
      tmp___51 = (char const *)getenv("TMPDIR");
      tmp_dir = tmp___51;
      if (tmp_dir) {
        tmp___52 = tmp_dir;
      } else {
        tmp___52 = "/tmp";
      }
      add_temp_dir(tmp___52);
    }
    if (nfiles == 0UL) {
      nfiles = (size_t)1;
      free((void *)files);
      files = &minus;
    }

    if (checkonly) {

      tmp___57 = check((char const *)*(files + 0), checkonly);

      exit(tmp___56);
    }
    if (mergeonly) {
      tmp___58 = (struct sortfile *)xcalloc(nfiles, sizeof(*sortfiles));
      sortfiles = tmp___58;
      i___1 = (size_t)0;

      ;
      merge(sortfiles, (size_t)0, nfiles, outfile);
    } else {
      if (!nthreads) {
        tmp___59 = num_processors((enum nproc_query)2);
        np = tmp___59;
        if (np < 8UL) {
          nthreads = np;
        } else {
          nthreads = (size_t)8;
        }
      }
      nthreads_max = 0xffffffffffffffffUL / (2UL * sizeof(struct merge_node));
      if (nthreads < nthreads_max) {
        nthreads = nthreads;
      } else {
        nthreads = nthreads_max;
      }
      sort((char *const *)files, nfiles, outfile, nthreads);
    }
    if (have_read_stdin) {
      tmp___61 = rpl_fclose(stdin);
    }
    exit(0);
  }
}
