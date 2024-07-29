typedef void *voidp;
typedef unsigned char uch;
typedef unsigned short ush;
typedef unsigned long ulg;
typedef long __off_t;
typedef long __off64_t;
typedef long __ssize_t;
typedef __ssize_t ssize_t;
typedef unsigned long size_t;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;
struct _IO_marker {};

union __anonunion_v_25 {
  ush n;
  struct huft *t;
};
struct huft {
  uch e;
  uch b;
  union __anonunion_v_25 v;
};
typedef int file_t;
union __anonunion_fc_7 {
  ush freq;
  ush code;
};
union __anonunion_dl_8 {
  ush dad;
  ush len;
};
struct ct_data {
  union __anonunion_fc_7 fc;
  union __anonunion_dl_8 dl;
};
typedef struct ct_data ct_data;
struct tree_desc {
  ct_data *dyn_tree;
  ct_data *static_tree;
  int *extra_bits;
  int extra_base;
};
typedef struct tree_desc tree_desc;
typedef ush Pos;
typedef unsigned int IPos;

typedef unsigned int __uid_t;
typedef unsigned int __gid_t;

typedef long __time_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef long __syscall_slong_t;
typedef __off_t off_t;
typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef void (*__sighandler_t)(int);
struct stat {};
struct option {
  char const *name;
};

typedef struct __dirstream DIR;
typedef struct dirent dir_type;
struct utimbuf {
  __time_t actime;
  __time_t modtime;
};

uch window[65536L];

int ifd;
int ofd;
int test;
int unlzh(int in, int out);
int fill_inbuf(int eof_ok);
void write_buf(int fd, voidp buf, unsigned int cnt);

static void huf_decode_start(void);

static void read_c_len(void);

static void make_table(int nchar, uch *bitlen, int tablebits, ush *table);
static uch pt_len[19];
static unsigned int blocksize;
static ush pt_table[256];
static ush bitbuf;
static unsigned int subbitbuf;
static int bitcount;

static void make_table(int nchar, uch *bitlen, int tablebits, ush *table) {
  ush count[17];
  ush weight[17];
  ush start[18];
  ush *p;
  unsigned int i___0;
  unsigned int k;
  unsigned int len;
  unsigned int ch;
  unsigned int jutbits;
  unsigned int avail;
  unsigned int nextcode;
  unsigned int mask;
  unsigned int tmp;

  {
    i___0 = 1U;
    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
      }
    while_break: /* CIL Label */
                 ;
    }
    i___0 = 0U;
    {
      while (1) {
      while_continue___0: /* CIL Label */
                          ;
      }
    while_break___0: /* CIL Label */
                     ;
    }
    start[1] = (ush)0;
    i___0 = 1U;
    {
      while (1) {
      while_continue___1: /* CIL Label */
                          ;
      }
    while_break___1: /* CIL Label */
                     ;
    }

    {
      while (1) {
      while_continue___2: /* CIL Label */
                          ;
        if (!(i___0 <= (unsigned int)tablebits)) {
          goto while_break___2;
        }
      }
    while_break___2: /* CIL Label */
                     ;
    }
    {
      while (1) {
      while_continue___3: /* CIL Label */
                          ;
      }
    while_break___3: /* CIL Label */
                     ;
    }
    i___0 = (unsigned int)((int)start[tablebits + 1] >> jutbits);
    if (i___0 != 0U) {
      k = (unsigned int)(1 << tablebits);
      {
        while (1) {
        while_continue___4: /* CIL Label */
                            ;
          if (!(i___0 != k)) {
            goto while_break___4;
          }
        }
      while_break___4: /* CIL Label */
                       ;
      }
    }

    {
      while (1) {

        start[len] = (ush)nextcode;
      __Cont:
        ch++;
      }
    while_break___5: /* CIL Label */
                     ;
    }
    return;
  }
}

static unsigned int decode_p(void) {
  unsigned int j___0;
  unsigned int mask;
  unsigned int tmp;

  {
    j___0 = (unsigned int)pt_table[(int)bitbuf >> (16UL * sizeof(char) - 8UL)];
    if (j___0 >= 14U) {
      mask = 1U << ((16UL * sizeof(char) - 1UL) - 8UL);
      {
        while (1) {
        }

        j___0 = (1U << (j___0 - 1U)) + tmp;
      }
    }
    return (j___0);
  }
}

int unlzh(int in, int out) {
  unsigned int n;

  {
    {
      ifd = in;
      ofd = out;

      /* CIL Label */
      ;
    }
    return (0);
  }
}
unsigned int outcnt;
long bytes_out;

static void build_tree(void);

extern ssize_t read(int __fd, void *__buf, size_t __nbytes);

extern
    __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1),
                                                       __leaf__))
                                        memset)(void *__s, int __c, size_t __n);
long bytes_in;
char ifname[1024];
char *progname;

void read_error(void);
int maxbits;
int block_mode;

int lzw(int in, int out);

extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));

extern __attribute__((__nothrow__)) void(__attribute__((__leaf__))
                                         free)(void *__ptr);

extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcpy)(char *__restrict __dest, char const *__restrict __src);

extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s)
    __attribute__((__pure__));
char ofname[1024];
void abort_gzip(void);
int copy(int in, int out);
ulg updcrc(uch *s, unsigned int n);

char *basename(char *fname);

voidp xmalloc(unsigned int size);

int huft_free(struct huft *t);

int inflate_dynamic(void);

ulg bb;
unsigned int bk;

unsigned int hufts;
int huft_build(unsigned int *b, unsigned int n, unsigned int s, ush *d, ush *e,
               struct huft **t, int *m) {
  unsigned int a;
  unsigned int c[17];
  unsigned int f;
  int g;
  int h;
  register unsigned int i___0;
  register unsigned int j___0;
  register int k;
  int l;
  register unsigned int *p;
  register struct huft *q;
  struct huft r;
  struct huft *u[16];
  unsigned int v[288];
  register int w;
  unsigned int x[17];
  unsigned int *xp;
  int y;
  unsigned int z;
  unsigned int *tmp;

  int tmp___4;
  unsigned int *tmp___5;
  unsigned int tmp___6;
  int tmp___7;
  void *__cil_tmp36;
  void *__cil_tmp37;

  {
    {
      memset((voidp)(c), 0, sizeof(c));
      p = b;

      /* CIL Label */
      ;
    }

    {
      while (1) {
      while_continue___0: /* CIL Label */
                          ;

      }

      /* CIL Label */
      ;
    }

    {
      while (1) {
      while_continue___3: /* CIL Label */
                          ;
        i___0--;
        if (!i___0) {
          goto while_break___3;
        }
      }
    while_break___3: /* CIL Label */
                     ;
    }
    p = b;
    i___0 = 0U;
    {
      while (1) {
      while_continue___4: /* CIL Label */
                          ;
      }
    while_break___4: /* CIL Label */
                     ;
    }
    i___0 = 0U;
    x[0] = i___0;

    {
      while (1) {

        {
          while (1) {
          while_continue___6: /* CIL Label */
                              ;

            {
              while (1) {

                j___0 = (unsigned int)(k - w);
                f = (unsigned int)(1 << j___0);
                if (f > a + 1U) {
                  f -= a + 1U;
                  xp = c + k;
                  {
                    while (1) {
                    while_continue___8: /* CIL Label */
                                        ;
                    }
                  while_break___8: /* CIL Label */
                                   ;
                  }
                }
                { z = (unsigned int)(1 << j___0); }
                hufts += z + 1U;
              }
            while_break___7: /* CIL Label */
                             ;
            }
            r.b = (uch)(k - w);
            if ((unsigned long)p >= (unsigned long)(v + n)) {
              r.e = (uch)99;
            } else {
              if (*p < s) {
                if (*p < 256U) {
                  tmp___4 = 16;
                } else {
                  tmp___4 = 15;
                }
                r.e = (uch)tmp___4;
                r.v.n = (ush)*p;
                p++;
              } else {
                r.e = (uch) * (e + (*p - s));
                tmp___5 = p;
                p++;
                r.v.n = *(d + (*tmp___5 - s));
              }
            }
            f = (unsigned int)(1 << (k - w));
            j___0 = i___0 >> w;
            {
              while (1) {
              while_continue___9: /* CIL Label */
                                  ;
              }
            while_break___9: /* CIL Label */
                             ;
            }
            j___0 = (unsigned int)(1 << (k - 1));
            {
              while (1) {
              while_continue___10: /* CIL Label */
                                   ;
              }
            while_break___10: /* CIL Label */
                              ;
            }
            i___0 ^= j___0;
            {
              while (1) {
              while_continue___11: /* CIL Label */
                                   ;
              }
            while_break___11: /* CIL Label */
                              ;
            }
          }
        while_break___6: /* CIL Label */
                         ;
        }
        k++;
      }
    while_break___5: /* CIL Label */
                     ;
    }
    if (y != 0) {
      if (g != 1) {
        tmp___7 = 1;
      } else {
        tmp___7 = 0;
      }
    } else {
      tmp___7 = 0;
    }
    return (tmp___7);
  }
}
int huft_free(struct huft *t) {
  register struct huft *p;
  register struct huft *q;

  {
    p = t;
    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
        if (!((unsigned long)p !=
              (unsigned long)((struct huft *)((void *)0)))) {
          goto while_break;
        }
        { p--; }
      }
    while_break: /* CIL Label */
                 ;
    }
    return (0);
  }
}
int inflate_codes(struct huft *tl, struct huft *td, int bl, int bd) {
  register unsigned int e;
  unsigned int n;
  unsigned int d;
  unsigned int w;
  struct huft *t;
  unsigned int ml;
  unsigned int md;
  register ulg b;
  register unsigned int k;
  unsigned int tmp;
  int tmp___0;
  int tmp___1;
  unsigned int tmp___2;

  {
    b = bb;
    k = bk;

    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
        {
          while (1) {

            b |= (ulg)((uch)tmp___1) << k;
            k += 8U;
          }
        while_break___0: /* CIL Label */
                         ;
        }
        t = tl + ((unsigned int)b & ml);
        e = (unsigned int)t->e;
        if (e > 16U) {
          {
            while (1) {
            while_continue___1: /* CIL Label */
                                ;
            }
          while_break___1: /* CIL Label */
                           ;
          }
        }
      }
    while_break: /* CIL Label */
                 ;
    }
    outcnt = w;
  }
}

int inflate_block(int *e) {
  unsigned int t;
  register ulg b;
  register unsigned int k;
  unsigned int tmp;
  int tmp___0;
  int tmp___1;

  {
    b = bb;
    k = bk;
    {
      while (1) {

        b |= (ulg)((uch)tmp___1) << k;
        k += 8U;
      }
    while_break: /* CIL Label */
                 ;
    }
    *e = (int)b & 1;
    b >>= 1;
    k--;
    {}
  }
}
int inflate(void) {
  int e;
  int r;
  unsigned int h;

  {
    outcnt = 0U;

    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
        {
          hufts = 0U;
          r = inflate_block(&e);
        }
      }
    while_break: /* CIL Label */
                 ;
    }
    { flush_window(); }
    return (0);
  }
}

int check_zipfile(int in);

void bi_init(file_t zipfile);

void copy_block(char *buf, unsigned int len, int header);

static int bi_valid;

void bi_windup(void) {
  unsigned int tmp;

  unsigned int tmp___3;

  {
    if (bi_valid > 8) {
    }
  }
}

int ct_tally(int dist, int lc);

static ush bl_count[16];
static uch bl_order[19] = {(uch)16, (uch)17, (uch)18, (uch)0,  (uch)8,
                           (uch)7,  (uch)9,  (uch)6,  (uch)10, (uch)5,
                           (uch)11, (uch)4,  (uch)12, (uch)3,  (uch)13,
                           (uch)2,  (uch)14, (uch)1,  (uch)15};
static int heap[573];
static int heap_len;
static int heap_max;
static uch depth[573];
static uch length_code[256];

static uch flag_buf[4096];
static unsigned int last_lit;
static unsigned int last_dist;
static unsigned int last_flags;
static uch flags;
static uch flag_bit;
static ulg opt_len;
static ulg static_len;
static ulg compressed_len;
static ulg input_len;
ush *file_type;
int *file_method;
long block_start;
unsigned int strstart;
static void init_block(void);
static void pqdownheap(ct_data *tree, int k);
static void gen_bitlen(tree_desc *desc);

static void send_tree(ct_data *tree, int max_code);

static void set_file_type(void);

static void gen_bitlen(tree_desc *desc) {
  ct_data *tree;
  int *extra;
  int base;
  int max_code;
  int max_length;
  ct_data *stree;
  int h;
  int n;
  int m;
  int bits;
  int xbits;
  ush f;
  int overflow;

  {
    tree = desc->dyn_tree;
    extra = desc->extra_bits;

    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
      }
    while_break: /* CIL Label */
                 ;
    }
    (tree + heap[heap_max])->dl.len = (ush)0;
    h = heap_max + 1;
    {
      while (1) {

        if (stree) {
          static_len += (ulg)f * (ulg)((int)(stree + n)->dl.len + xbits);
        }
      __Cont:
        h++;
      }
    while_break___0: /* CIL Label */
                     ;
    }
    if (overflow == 0) {
      return;
    }
    {
      while (1) {
      while_continue___1: /* CIL Label */
                          ;

        bl_count[bits + 1] = (ush)((int)bl_count[bits + 1] + 2);
      }
    while_break___1: /* CIL Label */
                     ;
    }
    bits = max_length;
    {
      while (1) {

        {
          while (1) {
          while_continue___4: /* CIL Label */
                              ;
          }
        while_break___4: /* CIL Label */
                         ;
        }
        bits--;
      }
    while_break___3: /* CIL Label */
                     ;
    }
    return;
  }
}
static void gen_codes(ct_data *tree, int max_code) {
  ush next_code[16];
  ush code;
  int bits;
  int n;
  int len;
  ush tmp;
  void *__cil_tmp10;

  {
    code = (ush)0;
    bits = 1;
    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
        if (!(bits <= 15)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
                 ;
    }
    n = 0;
    {
      while (1) {

        if (len == 0) {
          goto __Cont;
        }
        {}
      __Cont:
        n++;
      }
    while_break___0: /* CIL Label */
                     ;
    }
    return;
  }
}
static void build_tree___0(tree_desc *desc) {
  ct_data *tree;
  ct_data *stree;
  int elems;
  int n;

  {
    tree = desc->dyn_tree;

    {
      while (1) {
      while_continue___1: /* CIL Label */
                          ;
        if (!(n >= 1)) {
        }
      }
    while_break___1: /* CIL Label */
                     ;
    }
    {}
    return;
  }
}
static void scan_tree(ct_data *tree, int max_code) {
  int n;
  int prevlen;
  int curlen;
  int nextlen;

  {
    prevlen = -1;
    nextlen = (int)(tree + 0)->dl.len;

    {
      while (1) {
      while_continue: /* CIL Label */
                      ;

      __Cont:
        n++;
      }
    while_break: /* CIL Label */
                 ;
    }
    return;
  }
}

ulg flush_block(char *buf, ulg stored_len, int eof) {
  ulg opt_lenb;
  ulg static_lenb;
  int max_blindex;

  {
    flag_buf[last_flags] = flags;
    if ((int)*file_type == 65535) {
      { set_file_type(); }
    }
    {}
    if (static_lenb <= opt_lenb) {
      opt_lenb = static_lenb;
    }
  }
}
int ct_tally(int dist, int lc) {
  unsigned int tmp;

  int tmp___3;

  {

    if (last_lit == 32767U) {
      tmp___3 = 1;
    } else {
      if (last_dist == 32768U) {
        tmp___3 = 1;
      } else {
        tmp___3 = 0;
      }
    }
    return (tmp___3);
  }
}
static void compress_block(ct_data *ltree, ct_data *dtree) {
  unsigned int dist;
  int lc;
  unsigned int lx;
  unsigned int dx;
  unsigned int fx;

  { lx = 0U; }
}
static void set_file_type(void) {
  int n;
  unsigned int ascii_freq;
  unsigned int bin_freq;

  {

    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
        if (!(n < 7)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
                 ;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
                          ;
        if (!(n < 128)) {
          goto while_break___0;
        }
      }
    while_break___0: /* CIL Label */
                     ;
    }
    {
      while (1) {
      while_continue___1: /* CIL Label */
                          ;
        if (!(n < 256)) {
          goto while_break___1;
        }
      }
    while_break___1: /* CIL Label */
                     ;
    }
    if (bin_freq > ascii_freq >> 2) {
      *file_type = (ush)0;
    } else {
      *file_type = (ush)1;
    }
    return;
  }
}
void lm_init(int pack_level, ush *flags___0);

unsigned int prev_length;
unsigned int match_start;
static int eofile;

int longest_match(IPos cur_match);

static ulg deflate_fast(void) {
  IPos hash_head;
  int flush;
  unsigned int match_length;
  char *tmp;
  char *tmp___0;
  ulg tmp___1;

  {
    match_length = 0U;
    prev_length = 2U;
    {

    } {
      tmp___1 = flush_block(tmp___0, (ulg)((long)strstart - block_start), 1);
    }
    return (tmp___1);
  }
}
ulg deflate(void) {

  int match_available;
  register unsigned int match_length;
  ulg tmp;

  char *tmp___3;
  ulg tmp___4;

  {
    match_available = 0;
    match_length = 2U;

    if (block_start >= 0L) {
      tmp___3 = (char *)(&window[(unsigned int)block_start]);
    } else {
      tmp___3 = (char *)((void *)0);
    }
    { tmp___4 = flush_block(tmp___3, (ulg)((long)strstart - block_start), 1); }
    return (tmp___4);
  }
}
long header_bytes;
long time_stamp;
int save_orig_name;

int file_read(char *buf, unsigned int size) {
  unsigned int len;

  {
    { bytes_in = (long)((ulg)bytes_in + (ulg)len); }
    return ((int)len);
  }
}
static char *license_msg[15] = {
    (char *)"   Copyright (C) 1992-1993 Jean-loup Gailly",
    (char *)"   This program is free software; you can redistribute it and/or "
            "modify",
    (char *)"   it under the terms of the GNU General Public License as "
            "published by",
    (char *)"   the Free Software Foundation; either version 2, or (at your "
            "option)",
    (char *)"   any later version.",
    (char *)"",
    (char
         *)"   This program is distributed in the hope that it will be useful,",
    (char *)"   but WITHOUT ANY WARRANTY; without even the implied warranty of",
    (char *)"   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the",
    (char *)"   GNU General Public License for more details.",
    (char *)"",
    (char *)"   You should have received a copy of the GNU General Public "
            "License",
    (char *)"   along with this program; if not, write to the Free Software",
    (char *)"   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.",
    (char *)0};

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    lstat)(char const *__restrict __file, struct stat *__restrict __buf);

extern int fflush(FILE *__stream);

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    memcmp)(void const *__s1, void const *__s2, size_t __n)
    __attribute__((__pure__));

extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strncmp)(char const *__s1, char const *__s2, size_t __n)
    __attribute__((__pure__));

extern int optind;
extern int getopt_long(int argc, char *const *argv, char const *shortopts,
                       struct option const *longopts, int *longind);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           ctime)(time_t const *__timer);

extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     chown)(char const *__file, __uid_t __owner,
                                            __gid_t __group);

extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__))
                                                       exit)(int __status);

extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     utime)(char const *__file,
                                            struct utimbuf const *__file_times);
int ascii = 0;
int to_stdout = 0;
int decompress = 0;
int force = 0;
int no_name = -1;
int no_time = -1;
int recursive = 0;
int list = 0;
int verbose = 0;

char z_suffix[31];
int z_len;

struct stat istat;
struct option longopts[24] = {
    {"ascii", 0, (int *)0, 'a'},      {"to-stdout", 0, (int *)0, 'c'},
    {"stdout", 0, (int *)0, 'c'},     {"decompress", 0, (int *)0, 'd'},
    {"uncompress", 0, (int *)0, 'd'}, {"force", 0, (int *)0, 'f'},
    {"help", 0, (int *)0, 'h'},       {"list", 0, (int *)0, 'l'},
    {"license", 0, (int *)0, 'L'},    {"no-name", 0, (int *)0, 'n'},
    {"name", 0, (int *)0, 'N'},       {"quiet", 0, (int *)0, 'q'},
    {"silent", 0, (int *)0, 'q'},     {"recursive", 0, (int *)0, 'r'},
    {"suffix", 1, (int *)0, 'S'},     {"test", 0, (int *)0, 't'},
    {"no-time", 0, (int *)0, 'T'},    {"verbose", 0, (int *)0, 'v'},
    {"version", 0, (int *)0, 'V'},    {"fast", 0, (int *)0, '1'},
    {"best", 0, (int *)0, '9'},       {"lzw", 0, (int *)0, 'Z'},
    {"bits", 1, (int *)0, 'b'},       {(char const *)0, 0, (int *)0, 0}};
static void usage(void);
static void help(void);

static void treat_file(char *iname);
static int create_outfile(void);
static int do_stat(char *name, struct stat *sbuf);
static char *get_suffix(char *name);
static int get_istat(char *iname, struct stat *sbuf);
static int make_ofname(void);
static int same_file(struct stat *stat1, struct stat *stat2);
static int name_too_long(char *name, struct stat *statb);
static void shorten_name(char *name);

static void copy_stat(struct stat *ifstat);

static void treat_dir(char *dir);

int main(int argc, char **argv) {
  int file_count;
  int proglen;
  int optc;
  int tmp;
  void (*tmp___0)(int);
  void (*tmp___1)(int);

  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  char *__cil_tmp19;
  char *__cil_tmp20;

  {
    {
      progname = basename(*(argv + 0));
      proglen = (int)strlen((char const *)progname);
    }
    if (proglen > 4) {
      { tmp = strcmp((char const *)((progname + proglen) - 4), ".exe"); }
      if (tmp == 0) {
      }
    }
    {}
    if (tmp___5 == 0) {
    }
    {
      strncpy((char * /* __restrict  */)(z_suffix),
              (char const * /* __restrict  */) ".gz", sizeof(z_suffix) - 1UL);

      /* CIL Label */
      ;
    }
    if (no_time < 0) {
    }
    file_count = argc - optind;

    if (file_count != 0) {
      if (to_stdout) {
        if (!test) {
          if (!list) {
            if (!decompress) {
              tmp___7 = 1;
            } else {
              if (!ascii) {
                tmp___7 = 1;
              } else {
                tmp___7 = 0;
              }
            }
          } else {
            tmp___7 = 0;
          }
        } else {
          tmp___7 = 0;
        }
      } else {
        tmp___7 = 0;
      }
      {
        while (1) {
        while_continue___0: /* CIL Label */
                            ;
          if (!(optind < argc)) {
            goto while_break___0;
          }
          {
            tmp___8 = optind;
            optind++;
            treat_file(*(argv + tmp___8));
          }
        }
      while_break___0: /* CIL Label */
                       ;
      }
    } else {
      {}
    }
  }
}

static void treat_file(char *iname) {

  int tmp___0;

  int tmp___2;
  int tmp___3;
  int tmp___4;

  {
    {

    }

    {
      tmp___0 = get_istat(iname, &istat);
    }
    if (tmp___0 != 0) {
    }

    if (to_stdout) {

      goto _L___0;

    } else {
    _L___0 : { tmp___2 = make_ofname(); }
    }

    { ifd = open((char const *)(ifname), tmp___3, 384); }
    if (ifd == -1) {
      {}
    }
    {

    }

    {

    }

    {
      tmp___4 = create_outfile();
    }

    {}

    if (verbose) {

      {}
    }
  }
}
static int create_outfile(void) {

  int flags___0;

  {
    flags___0 = 193;

    {

      /* CIL Label */
      ;
      {

      } {

        ofd = open((char const *)(ofname), flags___0, 384);
      }

      {

      }

      {

      }

      /* CIL Label */
      ;
    }
  }
}
static int do_stat(char *name, struct stat *sbuf) {

  int tmp___0;

  {
    {

    }

    {

    }

    {}
  }
}

static int get_istat(char *iname, struct stat *sbuf) {

  int tmp;

  {
    {

      strcpy((char * /* __restrict  */)(ifname),
             (char const * /* __restrict  */)iname);
    }

    {

    }

    {

    }

    {

      /* CIL Label */
      ;
    }
    {}
  }
}
static int make_ofname(void) {

  {
    {
      strcpy((char * /* __restrict  */)(ofname),
             (char const * /* __restrict  */)(ifname));
    }

    {

    }

    {

      strcat((char * /* __restrict  */)(ofname),
             (char const * /* __restrict  */)(z_suffix));
    }

    return (0);
  }
}
static int get_method(int in) {

  {}
}

static void do_list(int ifd___0, int method___0) {

  {

    {

    }

    {}
  }
}

static int name_too_long(char *name, struct stat *statb) {
  int s;

  char c;

  int res;

  int tmp___2;

  {
    {}

    res = tmp___2;
    *(name + (s - 1)) = c;
    return (res);
  }
}
static void shorten_name(char *name) {

  {
    {

    }

    {

    while_break: /* CIL Label */
                 ;
    }
  }
}
static int check_ofname(void) {

  {
    {

      /* CIL Label */
      ;
    }

    {}
  }
}
static void reset_times(char *name, struct stat *statb) {

  {
    {}
  }
}
static void copy_stat(struct stat *ifstat) {

  {

    {}
  }
}
static void treat_dir(char *dir) {

  DIR *dirp;

  {
    {

    }

    {

    while_break: /* CIL Label */
                 ;
    }
    { closedir(dirp); }
    return;
  }
}
static int in_exit = 0;
static void do_exit(int exitcode) {

  {

    {}
  }
}
void abort_gzip(void) {

  {}
}
