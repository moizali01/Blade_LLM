typedef long __time_t;

typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;
};
typedef unsigned long size_t;

typedef struct hash_table Hash_table;
typedef unsigned long uintmax_t;
typedef long __off64_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

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

struct option {};
typedef unsigned int uint32_t;

struct __anonstruct___sigset_t_9 {};
typedef struct __anonstruct___sigset_t_9 __sigset_t;
typedef __sigset_t sigset_t;

union __anonunion_temp_26 {
  long tempint;
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
};
struct Tokens {
  size_t n_tok;
  char **tok;
  size_t *tok_len;
  struct obstack o_data;
  struct obstack o_tok;
  struct obstack o_tok_len;
};

typedef unsigned long uint_least64_t;
typedef struct timezone *__restrict __timezone_ptr_t;
typedef uint_least64_t isaac_word;

struct md5_ctx {

  uint32_t B;
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

  __pthread_list_t __list;
};
union __anonunion_pthread_mutex_t_11 {
  struct __pthread_mutex_s __data;
};
typedef union __anonunion_pthread_mutex_t_11 pthread_mutex_t;

typedef union __anonunion_pthread_mutexattr_t_12 pthread_mutexattr_t;

struct heap {
  void **array;
  size_t capacity;
  size_t count;
};

union __anonunion___sigaction_handler_41 {
  void (*sa_handler)(int);
};
struct sigaction {
  union __anonunion___sigaction_handler_41 __sigaction_handler;

  int sa_flags;
  void (*sa_restorer)(void);
};

struct line {
  char *text;
  size_t length;
};
struct buffer {
  char *buf;
  size_t used;
  size_t nlines;
  size_t alloc;

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

  struct keyfield *next;
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

  unsigned int level;
  _Bool queued;
  pthread_mutex_t lock;
};
struct merge_node_queue {
  struct heap *priority_queue;
  pthread_mutex_t mutex;
};

struct tempnode {

  char name[1];
};

extern struct _IO_FILE *stdout;

int close_stream(FILE *stream) {

  {}
}

void *xmalloc(size_t n) __attribute__((__malloc__, __alloc_size__(1)));
void *xrealloc(void *p, size_t n) __attribute__((__alloc_size__(2)));

__inline static void *xnmalloc(size_t n, size_t s) {

  void *tmp___0;

  {

    tmp___0 = xmalloc(n * s);
    return (tmp___0);
  }
}

__inline static void *x2nrealloc(void *p, size_t *pn, size_t s) {
  size_t n;
  void *tmp;

  {
    n = *pn;

    n += (n + 1UL) / 2UL;

    *pn = n;
    tmp = xrealloc(p, n * s);
    return (tmp);
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

void *xrealloc(void *p, size_t n) {

  {

    p = realloc(p, n);

    return (p);
  }
}

void xalloc_die(void) {

  {}
}

void isaac_seed(struct isaac_state *s) {
  isaac_word a;
  unsigned long tmp;
  isaac_word b;
  unsigned long tmp___0;
  isaac_word c;
  unsigned long tmp___1;
  isaac_word d;
  unsigned long tmp___2;
  isaac_word e;
  unsigned long tmp___3;
  isaac_word f;
  unsigned long tmp___4;
  isaac_word g;
  unsigned long tmp___5;
  isaac_word h;
  unsigned long tmp___6;
  int i;

  isaac_word tmp___16;

  {

    a = tmp;

    b = tmp___0;

    c = tmp___1;

    d = tmp___2;

    e = tmp___3;

    f = tmp___4;

    g = tmp___5;

    h = tmp___6;
    i = 0;

    tmp___16 = (isaac_word)0;
  }
}

char *quotearg_n_style(int n, enum quoting_style s, char const *arg) {

  {}
}
char *quotearg_n_style_mem(int n, enum quoting_style s, char const *arg,
                           size_t argsize) {

  {}
}

char *quotearg_colon(char const *arg) {

  {}
}

char const *quote_n(int n, char const *name) {

  {}
}
char const *quote(char const *name) {

  {}
}

int(__attribute__((__nonnull__(1))) rpl_nanosleep)(
    struct timespec const *requested_delay, struct timespec *remaining_delay) {

  time_t seconds;
  struct timespec intermediate;

  {

    intermediate.tv_sec = seconds;
  }
}

int memcoll0(char const *s1, size_t s1size, char const *s2, size_t s2size) {

  {}
}

void(__attribute__((__leaf__)) md5_process_block)(void const *buffer,
                                                  size_t len,
                                                  struct md5_ctx *ctx) {

  uint32_t B;

  { ctx->B = B; }
}

char const *locale_charset(void) {

  { ; }
}

struct heap *heap_alloc(int (*compare___0)(void const *, void const *),
                        size_t n_reserve) {
  struct heap *heap;
  struct heap *tmp;

  {
    tmp = (struct heap *)xmalloc(sizeof(*heap));
    heap = tmp;

    heap->array = (void **)xnmalloc(n_reserve, sizeof(*(heap->array)));

    heap->capacity = n_reserve;

    return (heap);
  }
}

int heap_insert(struct heap *heap, void *item) {

  {
    if (heap->capacity - 1UL <= heap->count) {
      heap->array = (void **)x2nrealloc((void *)heap->array, &heap->capacity,
                                        sizeof(*(heap->array)));
    }
    (heap->count)++;
    *(heap->array + heap->count) = item;
  }
}
void *heap_remove_top(struct heap *heap) {
  void *top;
  size_t tmp;

  {

    top = *(heap->array + 1);
    tmp = heap->count;

    *(heap->array + 1) = *(heap->array + tmp);

    return (top);
  }
}
static size_t heapify_down(void **array, size_t count, size_t initial,
                           int (*compare___0)(void const *, void const *)) {

  size_t parent;

  { return (parent); }
}
static void heapify_up(void **array, size_t count,
                       int (*compare___0)(void const *, void const *)) {
  size_t k;
  void *new_element;

  {
    k = count;
    new_element = *(array + k);

  while_break:
    *(array + k) = new_element;
    return;
  }
}

FILE *fopen_safer(char const *file, char const *mode) {
  FILE *fp;
  FILE *tmp;

  {
    tmp = fopen(file, mode);
    fp = tmp;

    return (fp);
  }
}

#pragma GCC diagnostic ignored "-Wsuggest-attribute=const"

int fd_safer(int fd) {

  {}
}

int(__attribute__((__nonnull__(1))) rpl_fclose)(FILE *fp) {

  int result;

  { result = fclose(fp); }
}

int dup_safer(int fd) {

  {}
}

extern char *optarg;

static char eolchar = (char)'\n';

static _Bool reverse;

static struct keyfield *keylist;

void usage(int status) {

  { exit(status); }
}
static char const short_options[31] = {
    (char const)'-', (char const)'b', (char const)'c',   (char const)'C',
    (char const)'d', (char const)'f', (char const)'g',   (char const)'h',
    (char const)'i', (char const)'k', (char const)':',   (char const)'m',
    (char const)'M', (char const)'n', (char const)'o',   (char const)':',
    (char const)'r', (char const)'R', (char const)'s',   (char const)'S',
    (char const)':', (char const)'t', (char const)':',   (char const)'T',
    (char const)':', (char const)'u', (char const)'V',   (char const)'y',
    (char const)':', (char const)'z', (char const)'\000'};
static struct option const long_options___1[31] = {
    {"ignore-leading-blanks", 0, (int *)((void *)0), 'b'},
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
static char const *const check_args[4] = {"quiet", "silent", "diagnose-first",
                                          (char const *)((void *)0)};
static char const check_types[3] = {(char const)'C', (char const)'C',
                                    (char const)'c'};
static char const *const sort_args[7] = {
    "general-numeric", "human-numeric",          "month", "numeric", "random",
    "version",         (char const *)((void *)0)};
static char const sort_types[6] = {(char const)'g', (char const)'h',
                                   (char const)'M', (char const)'n',
                                   (char const)'R', (char const)'V'};
static sigset_t caught_signals;

static FILE *stream_open(char const *file, char const *how) {

  FILE *tmp___0;

  {
    if (!file) {
      return (stdout);
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

    return (fp);
  }
}
static void xfclose(FILE *fp, char const *file) {

  {

  case_1:

  switch_break:;
  }
}

static struct tempnode *create_temp(FILE **pfp) {

  {}
}

static size_t size_bound;

static void initbuf(struct buffer *buf___1, size_t line_bytes, size_t alloc) {
  size_t tmp;
  size_t tmp___0;

  {
    while (1) {

      buf___1->buf = (char *)malloc(alloc);
      if (buf___1->buf) {
        goto while_break;
      }
      alloc /= 2UL;
    }
  while_break:
    buf___1->line_bytes = line_bytes;
    buf___1->alloc = alloc;

    tmp = tmp___0;

    buf___1->used = tmp;
  }
}
__inline static struct line *buffer_linelim(struct buffer const *buf___1) {

  { return ((struct line *)(buf___1->buf + buf___1->alloc)); }
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

  struct line *tmp___8;

  {

    eol = eolchar;
    line_bytes = buf___1->line_bytes;

    if (buf___1->eof) {
    }

    ptr = buf___1->buf + buf___1->used;
    tmp = buffer_linelim((struct buffer const *)buf___1);
    linelim = tmp;
    line = linelim - buf___1->nlines;

    tmp___0 = buf___1->buf;

    line_start = tmp___0;

    readsize = (avail - 1UL) / (line_bytes + 1UL);
    tmp___1 = fread_unlocked((void *)ptr, (size_t)1, readsize, fp);

    ptrlim = ptr + bytes_read;

    buf___1->eof = (_Bool)1;

    while (1) {
      p = (char *)memchr((void const *)ptr, (int)eol, (size_t)(ptrlim - ptr));
      if (!p) {
        goto while_break___1;
      }

      ptr = p + 1;
      line--;
      line->text = line_start;
      line->length = (size_t)(ptr - line_start);

      avail -= line_bytes;

      line_start = ptr;
    }
  while_break___1:

  while_break___0:

    tmp___8 = buffer_linelim((struct buffer const *)buf___1);
    buf___1->nlines = (size_t)(tmp___8 - line);
  }
}

static int compare(struct line const *a, struct line const *b) {
  int diff;
  size_t alen;
  size_t blen;
  size_t tmp;
  int tmp___0;

  {

    alen = (size_t)(a->length - 1UL);

    tmp = alen;

    diff = memcmp((void const *)a->text, (void const *)b->text, tmp);
    if (!diff) {
      if (alen < blen) {

      } else {
        diff = alen != blen;
      }
    }

    tmp___0 = diff;

    return (tmp___0);
  }
}
static void write_line(struct line const *line, FILE *fp,
                       char const *output_file) {
  char *buf___1;
  size_t n_bytes;
  char *ebuf;

  size_t tmp___3;

  {
    buf___1 = (char *)line->text;
    n_bytes = (size_t)line->length;
    ebuf = buf___1 + n_bytes;

  _L:
    *(ebuf + -1) = eolchar;
    tmp___3 = fwrite_unlocked((void const *)buf___1, (size_t)1, n_bytes, fp);
  }
}

static void mergelines(struct line *__restrict t, size_t nlines,
                       struct line const *__restrict lo) {
  size_t nlo;
  size_t nhi;
  struct line *hi;
  int tmp;

  {
    nlo = nlines / 2UL;
    nhi = nlines - nlo;
    hi = (struct line *)(t - nlo);
    while (1) {
      tmp =
          compare((struct line const *)(lo - 1), (struct line const *)(hi - 1));
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
  }
}
static void sequential_sort(struct line *__restrict lines, size_t nlines,
                            struct line *__restrict temp, _Bool to_temp) {
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
      tmp = compare((struct line const *)(lines + -1),
                    (struct line const *)(lines + -2));
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

        *(temp + -1) = *(lo + -1);
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
static struct merge_node *init_node(struct merge_node *__restrict parent,
                                    struct merge_node *__restrict node_pool,
                                    struct line *dest, size_t nthreads,
                                    size_t total_lines, _Bool is_lo_child);
static struct merge_node *merge_tree_init(size_t nthreads, size_t nlines,
                                          struct line *dest) {
  struct merge_node *merge_tree;
  struct merge_node *tmp;
  struct merge_node *root;

  size_t tmp___3;

  {
    tmp = (struct merge_node *)xmalloc((2UL * sizeof(*merge_tree)) * nthreads);
    merge_tree = tmp;
    root = merge_tree;

    tmp___3 = nlines;
    root->nhi = tmp___3;

    init_node(root, root + 1, dest, nthreads, nlines, (_Bool)0);
    return (merge_tree);
  }
}

static struct merge_node *init_node(struct merge_node *__restrict parent,
                                    struct merge_node *__restrict node_pool,
                                    struct line *dest, size_t nthreads,
                                    size_t total_lines, _Bool is_lo_child) {
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

  {

    tmp = parent->nhi;

    nlines = tmp;
    nlo = nlines / 2UL;
    nhi = nlines - nlo;
    lo = dest - total_lines;
    hi = lo - nlo;

    tmp___0 = &parent->end_hi;

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

    return ((struct merge_node *)node_pool);
  }
}
static int compare_nodes(void const *a, void const *b) {

  {}
}

__inline static void unlock_node(struct merge_node *node) {

  {}
}

static void queue_init(struct merge_node_queue *queue, size_t nthreads) {

  { queue->priority_queue = heap_alloc(&compare_nodes, 2UL * nthreads); }
}
static void queue_insert(struct merge_node_queue *queue,
                         struct merge_node *node) {

  { heap_insert(queue->priority_queue, (void *)node); }
}
static struct merge_node *queue_pop(struct merge_node_queue *queue) {
  struct merge_node *node;

  {

    node = (struct merge_node *)heap_remove_top(queue->priority_queue);

  while_break:

    return (node);
  }
}

static void write_unique(struct line const *line, FILE *tfp,
                         char const *temp_output) {

  { write_line(line, tfp, temp_output); }
}
static void mergelines_node(struct merge_node *__restrict node,
                            size_t total_lines, FILE *tfp,
                            char const *temp_output) {
  struct line *lo_orig;
  struct line *hi_orig;

  size_t merged_lo;
  size_t merged_hi;
  struct line *dest;

  int tmp___3;

  {
    lo_orig = node->lo;
    hi_orig = node->hi;

  while_break:
    merged_lo = (size_t)(lo_orig - node->lo);
    merged_hi = (size_t)(hi_orig - node->hi);

    *(node->dest) = dest;

    if ((unsigned long)node->lo != (unsigned long)node->end_lo) {

    } else {
      goto while_break___2;
    }
    tmp___3 = compare((struct line const *)(node->lo - 1),
                      (struct line const *)(node->hi - 1));
    if (tmp___3 <= 0) {
      (node->lo)--;
      write_unique((struct line const *)node->lo, tfp, temp_output);
    } else {
      (node->hi)--;
      write_unique((struct line const *)node->hi, tfp, temp_output);
    }

  while_break___2:
    merged_lo = (size_t)(lo_orig - node->lo);
    merged_hi = (size_t)(hi_orig - node->hi);

  while_break___3:;

    if (node->nlo == merged_lo) {

      if ((unsigned long)node->hi != (unsigned long)node->end_hi) {

      } else {
        goto while_break___4;
      }
      (node->hi)--;
      write_unique((struct line const *)node->hi, tfp, temp_output);

    while_break___4:;
    }

    merged_lo = (size_t)(lo_orig - node->lo);
    merged_hi = (size_t)(hi_orig - node->hi);
    node->nlo -= merged_lo;
    node->nhi -= merged_hi;
    return;
  }
}
static void queue_check_insert(struct merge_node_queue *queue,
                               struct merge_node *node) {

  { queue_insert(queue, node); }
}
static void queue_check_insert_parent(struct merge_node_queue *queue,
                                      struct merge_node *node) {

  {

    if (node->nlo + node->nhi == 0UL) {
      queue_insert(queue, node->parent);
    }
  }
}
static void merge_loop(struct merge_node_queue *queue, size_t total_lines,
                       FILE *tfp, char const *temp_output) {
  struct merge_node *node;
  struct merge_node *tmp;

  {
    while (1) {
      tmp = queue_pop(queue);
      node = tmp;
      if (node->level == 0U) {

        goto while_break;
      }
      mergelines_node(node, total_lines, tfp, temp_output);
      queue_check_insert(queue, node);
      queue_check_insert_parent(queue, node);
    }
  while_break:;
  }
}

static void sortlines(struct line *__restrict lines, size_t nthreads,
                      size_t total_lines, struct merge_node *node,
                      struct merge_node_queue *queue, FILE *tfp,
                      char const *temp_output) {

  size_t nlo;
  size_t nhi;
  struct line *temp;

  {

  _L___0:
    nlo = node->nlo;
    nhi = node->nhi;
    temp = (struct line *)(lines - total_lines);

    sequential_sort(lines - nlo, nhi, temp - nlo / 2UL, (_Bool)0);

    sequential_sort(lines, nlo, temp, (_Bool)0);

    node->lo = (struct line *)lines;
    node->hi = (struct line *)(lines - nlo);
    node->end_lo = (struct line *)(lines - nlo);
    node->end_hi = (struct line *)((lines - nlo) - nhi);
    queue_insert(queue, node);
    merge_loop(queue, total_lines, tfp, temp_output);
  }
}
static void avoid_trashing_input(struct sortfile *files, size_t ntemps,
                                 size_t nfiles, char const *outfile) {

  { ; }
}
static void merge(struct sortfile *files, size_t ntemps, size_t nfiles,
                  char const *output_file) {

  {

  while_break:
    avoid_trashing_input(files, ntemps, nfiles, output_file);

  while_break___1:;
    return;
  }
}
static void sort(char *const *files, size_t nfiles, char const *output_file,
                 size_t nthreads) {
  struct buffer buf___1;
  size_t ntemps;

  char const *temp_output;
  char const *file;
  FILE *fp;
  FILE *tmp;
  FILE *tfp;
  size_t bytes_per_line;

  size_t tmp___1;
  struct line *line;
  struct tempnode *tmp___2;
  struct merge_node_queue queue;
  struct merge_node *merge_tree;
  struct merge_node *tmp___3;
  struct merge_node *root;
  _Bool tmp___4;

  {
    ntemps = (size_t)0;

    file = (char const *)*files;
    tmp = xfopen(file, "r");
    fp = tmp;

    bytes_per_line = (sizeof(struct line) * 3UL) / 2UL;

    initbuf(&buf___1, bytes_per_line, tmp___1);

    nfiles--;

    tmp___4 = fillbuf___7(&buf___1, fp, file);

    line = buffer_linelim((struct buffer const *)(&buf___1));
    if (buf___1.eof) {
      if (!nfiles) {
        if (!ntemps) {

          tfp = xfopen(output_file, "w");

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

    queue_init(&queue, nthreads);
    tmp___3 = merge_tree_init(nthreads, buf___1.nlines, line);
    merge_tree = tmp___3;
    root = merge_tree + 1;
    sortlines(line, nthreads, buf___1.nlines, root, &queue, tfp, temp_output);

    xfclose(tfp, temp_output);

    ;
  finish:
    free((void *)buf___1.buf);
  }
}

int main(int argc, char **argv) {
  struct keyfield *key;
  struct keyfield key_buf;
  struct keyfield gkey;
  _Bool gkey_only;
  char const *s;
  int c;

  _Bool mergeonly;
  char *random_source;
  _Bool need_random;
  size_t nthreads;
  size_t nfiles;
  _Bool posixly_correct;
  char *tmp;
  _Bool obsolete_usage;

  char **files;
  char *files_from;
  struct Tokens tok;
  char const *outfile;
  struct lconv const *locale;
  struct lconv const *tmp___1;
  size_t i;
  struct sigaction act;

  int oi;
  size_t tmp___3;
  int tmp___4;
  _Bool minus_pos_usage;
  int tmp___5;

  char const *optarg1;
  int tmp___7;
  char *tmp___8;
  char *tmp___9;
  size_t tmp___10;
  ptrdiff_t tmp___11;
  char str[2];
  ptrdiff_t tmp___12;
  char *tmp___13;
  int tmp___14;
  size_t tmp___15;
  size_t tmp___16;
  size_t tmp___17;
  char *tmp___18;

  int tmp___21;

  char *tmp___22;
  char const *tmp___23;
  char *tmp___24;
  int tmp___25;
  char *tmp___26;
  char const *p;
  FILE *stream;
  char const *tmp___27;
  char *tmp___28;
  char *tmp___29;
  char const *tmp___30;
  char *tmp___31;
  int *tmp___32;
  int tmp___33;
  char const *tmp___34;
  char *tmp___35;
  _Bool tmp___36;

  size_t i___0;
  char const *tmp___38;
  char *tmp___39;
  unsigned long file_number;
  char *tmp___40;
  char *tmp___41;
  int tmp___42;
  char const *tmp___43;
  char *tmp___44;
  _Bool tmp___45;

  char *tmp___47;
  char const *tmp___48;
  char *tmp___49;
  char *tmp___50;
  char const *tmp_dir;
  char const *tmp___51;
  char const *tmp___52;
  char const *tmp___53;
  char *tmp___54;
  int tmp___56;

  struct sortfile *sortfiles;
  struct sortfile *tmp___58;
  size_t i___1;
  unsigned long np;

  size_t nthreads_max;

  {

    mergeonly = (_Bool)0;

    nfiles = (size_t)0;

    outfile = (char const *)((void *)0);

    files = (char **)xnmalloc((size_t)argc, sizeof(*files));

  _L___1:
    c = getopt_long(argc, (char *const *)argv, short_options, long_options___1,
                    &oi);
    if (c == -1) {

      goto while_break___1;

    } else {

      nfiles++;
      *(files + tmp___10) = optarg;

    case_99:

        ;
    }

  while_break___1:;

    key = keylist;

    ;

    reverse = gkey.reverse;

    if (mergeonly) {

      merge(sortfiles, (size_t)0, nfiles, outfile);
    } else {

      nthreads = np;

      nthreads_max = 0xffffffffffffffffUL / (2UL * sizeof(struct merge_node));

      sort((char *const *)files, nfiles, outfile, nthreads);
    }
  }
}
