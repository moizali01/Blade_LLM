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

typedef unsigned char char_type;
typedef long code_int;
typedef unsigned long cmp_code_int;
typedef struct _IO_FILE _IO_FILE;
struct huft;
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
  int elems;
  int max_length;
  int max_code;
};
typedef struct tree_desc tree_desc;
typedef ush Pos;
typedef unsigned int IPos;
struct config {
  ush good_length;
  ush max_lazy;
  ush nice_length;
  ush max_chain;
};
typedef struct config config;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
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
struct option {
  char const *name;
  int has_arg;
  int *flag;
  int val;
};
struct dirent {
  __ino_t d_ino;
  __off_t d_off;
  unsigned short d_reclen;
  unsigned char d_type;
  char d_name[256];
};
struct __dirstream;
struct __dirstream;
typedef struct __dirstream DIR;
typedef struct dirent dir_type;
struct utimbuf {
  __time_t actime;
  __time_t modtime;
};
uch inbuf[32832];
uch outbuf[18432];
ush d_buf[32768];
uch window[65536L];
ush prev[1L << 16];
unsigned int insize;
unsigned int inptr;
int ifd;
int ofd;
int test;
int unlzh(int in, int out);
int fill_inbuf(int eof_ok);
void write_buf(int fd, voidp buf, unsigned int cnt);
void error(char *m);
static unsigned int decode(unsigned int count, uch *buffer);
static void decode_start(void);
static void huf_decode_start(void);
static unsigned int decode_c(void);
static unsigned int decode_p(void);
static void read_pt_len(int nn, int nbit, int i_special);
static void read_c_len(void);
static void fillbuf(int n);
static unsigned int getbits(int n);
static void init_getbits(void);
static void make_table(int nchar, uch *bitlen, int tablebits, ush *table);
static uch pt_len[19];
static unsigned int blocksize;
static ush pt_table[256];
static ush bitbuf;
static unsigned int subbitbuf;
static int bitcount;
static void fillbuf(int n) {
  unsigned int tmp;
  int tmp___0;
  int tmp___1;

  {
    bitbuf = (ush)((int)bitbuf << n);
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(n > bitcount)) {
          goto while_break;
        }
        n -= bitcount;
        bitbuf = (ush)((unsigned int)bitbuf | (subbitbuf << n));
        if (inptr < insize) {
          tmp = inptr;
          inptr++;
          tmp___1 = (int)inbuf[tmp];
        } else {
          {
            tmp___0 = fill_inbuf(1);
            tmp___1 = tmp___0;
          }
        }
        subbitbuf = (unsigned int)tmp___1;

        bitcount = 8;
      }
    while_break: /* CIL Label */
        ;
    }
    bitcount -= n;
    bitbuf = (ush)((unsigned int)bitbuf | (subbitbuf >> bitcount));
    return;
  }
}
static unsigned int getbits(int n) {
  unsigned int x;

  {
    {
      x = (unsigned int)((int)bitbuf >>
                         (16UL * sizeof(char) - (unsigned long)n));
      fillbuf(n);
    }
    return (x);
  }
}
static void init_getbits(void) {

  {
    {
      bitbuf = (ush)0;
      subbitbuf = 0U;
      bitcount = 0;
      fillbuf((int)(16UL * sizeof(char)));
    }
    return;
  }
}
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
  ush tmp___0;
  unsigned int tmp___1;
  void *__cil_tmp20;
  void *__cil_tmp21;
  void *__cil_tmp22;
  char *__cil_tmp23;

  {
    i___0 = 1U;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(i___0 <= 16U)) {
          goto while_break;
        }
        count[i___0] = (ush)0;
        i___0++;
      }
    while_break: /* CIL Label */
        ;
    }
    i___0 = 0U;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(i___0 < (unsigned int)nchar)) {
          goto while_break___0;
        }
        count[*(bitlen + i___0)] = (ush)((int)count[*(bitlen + i___0)] + 1);
        i___0++;
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
        if (!(i___0 <= 16U)) {
          goto while_break___1;
        }
        start[i___0 + 1U] =
            (ush)((int)start[i___0] + ((int)count[i___0] << (16U - i___0)));
        i___0++;
      }
    while_break___1: /* CIL Label */
        ;
    }
    if (((int)start[17] & 65535) != 0) {
      {
        error((char *)"Bad table\n");
      }
    }
    jutbits = (unsigned int)(16 - tablebits);
    i___0 = 1U;
    {
      while (1) {
      while_continue___2: /* CIL Label */
          ;
        if (!(i___0 <= (unsigned int)tablebits)) {
          goto while_break___2;
        }
        start[i___0] = (ush)((int)start[i___0] >> jutbits);
        weight[i___0] = (ush)(1U << ((unsigned int)tablebits - i___0));
        i___0++;
      }
    while_break___2: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___3: /* CIL Label */
          ;
        if (!(i___0 <= 16U)) {
          goto while_break___3;
        }
        weight[i___0] = (ush)(1U << (16U - i___0));
        i___0++;
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
          tmp = i___0;
          i___0++;
          *(table + tmp) = (ush)0;
        }
      while_break___4: /* CIL Label */
          ;
      }
    }
    avail = (unsigned int)nchar;
    mask = 1U << (15 - tablebits);
    ch = 0U;
    {
      while (1) {
      while_continue___5: /* CIL Label */
          ;
        if (!(ch < (unsigned int)nchar)) {
          goto while_break___5;
        }
        len = (unsigned int)*(bitlen + ch);
        if (len == 0U) {
          goto __Cont;
        }
        nextcode = (unsigned int)((int)start[len] + (int)weight[len]);
        if (len <= (unsigned int)tablebits) {
          i___0 = (unsigned int)start[len];
          {
            while (1) {
            while_continue___6: /* CIL Label */
                ;
              if (!(i___0 < nextcode)) {
                goto while_break___6;
              }
              *(table + i___0) = (ush)ch;
              i___0++;
            }
          while_break___6: /* CIL Label */
              ;
          }
        } else {
          k = (unsigned int)start[len];
          p = table + (k >> jutbits);
          i___0 = len - (unsigned int)tablebits;
          {
            while (1) {
            while_continue___7: /* CIL Label */
                ;
              if (!(i___0 != 0U)) {
                goto while_break___7;
              }
              if ((int)*p == 0) {
                tmp___0 = (ush)0;
                prev[avail] = tmp___0;
                *((prev + 32768) + avail) = tmp___0;
                tmp___1 = avail;
                avail++;
                *p = (ush)tmp___1;
              }
              if (k & mask) {
                p = (prev + 32768) + (int)*p;
              } else {
                p = &prev[*p];
              }
              k <<= 1;
              i___0--;
            }
          while_break___7: /* CIL Label */
              ;
          }
          *p = (ush)ch;
        }
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
static void read_pt_len(int nn, int nbit, int i_special) {
  int i___0;
  int c;
  int n;
  unsigned int mask;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;

  {
    { n = (int)getbits(nbit); }
    if (n == 0) {
      {
        c = (int)getbits(nbit);
        i___0 = 0;
      }
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if (!(i___0 < nn)) {
            goto while_break;
          }
          pt_len[i___0] = (uch)0;
          i___0++;
        }
      while_break: /* CIL Label */
          ;
      }
      i___0 = 0;
      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;
          if (!(i___0 < 256)) {
            goto while_break___0;
          }
          pt_table[i___0] = (ush)c;
          i___0++;
        }
      while_break___0: /* CIL Label */
          ;
      }
    } else {
      i___0 = 0;
      {
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          if (!(i___0 < n)) {
            goto while_break___1;
          }
          c = (int)bitbuf >> (16UL * sizeof(char) - 3UL);

          if (c < 7) {
            tmp = 3;
          } else {
            tmp = c - 3;
          }
          {
            fillbuf(tmp);
            tmp___0 = i___0;
            i___0++;
            pt_len[tmp___0] = (uch)c;
          }
          if (i___0 == i_special) {
            {
              c = (int)getbits(2);
            }
            {
              while (1) {
              while_continue___3: /* CIL Label */
                  ;
                c--;
                if (!(c >= 0)) {
                  goto while_break___3;
                }
                tmp___1 = i___0;
                i___0++;
                pt_len[tmp___1] = (uch)0;
              }
            while_break___3: /* CIL Label */
                ;
            }
          }
        }
      while_break___1: /* CIL Label */
          ;
      }
      {
        while (1) {
        while_continue___4: /* CIL Label */
            ;
          if (!(i___0 < nn)) {
            goto while_break___4;
          }
          tmp___2 = i___0;
          i___0++;
          pt_len[tmp___2] = (uch)0;
        }
      while_break___4: /* CIL Label */
          ;
      }
      { make_table(nn, pt_len, 8, pt_table); }
    }
    return;
  }
}
static void read_c_len(void) {
  int i___0;
  int c;
  int n;
  unsigned int mask;
  unsigned int tmp;
  unsigned int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;

  {
    { n = (int)getbits(9); }
    if (n == 0) {
      {
        c = (int)getbits(9);
        i___0 = 0;
      }
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if (!(i___0 < 510)) {
            goto while_break;
          }
          outbuf[i___0] = (uch)0;
          i___0++;
        }
      while_break: /* CIL Label */
          ;
      }
      i___0 = 0;
      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;
          if (!(i___0 < 4096)) {
            goto while_break___0;
          }
          d_buf[i___0] = (ush)c;
          i___0++;
        }
      while_break___0: /* CIL Label */
          ;
      }
    } else {
      i___0 = 0;
      {

      while_break___1: /* CIL Label */
          ;
      }
      {
        while (1) {
        while_continue___4: /* CIL Label */
            ;
          if (!(i___0 < 510)) {
            goto while_break___4;
          }
          tmp___3 = i___0;
          i___0++;
          outbuf[tmp___3] = (uch)0;
        }
      while_break___4: /* CIL Label */
          ;
      }
      { make_table(510, outbuf, 12, d_buf); }
    }
    return;
  }
}
static unsigned int decode_c(void) {
  unsigned int j___0;
  unsigned int mask;

  {
    if (blocksize == 0U) {
      {
        blocksize = getbits(16);
      }
      if (blocksize == 0U) {
        return (510U);
      }
      {
        read_pt_len(19, 5, 3);
        read_c_len();
        read_pt_len(14, 4, -1);
      }
    }
    blocksize--;
    j___0 = (unsigned int)d_buf[(int)bitbuf >> (16UL * sizeof(char) - 12UL)];
    if (j___0 >= 510U) {
      mask = 1U << ((16UL * sizeof(char) - 1UL) - 12UL);
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if ((unsigned int)bitbuf & mask) {
            j___0 = (unsigned int)*((prev + 32768) + j___0);
          } else {
            j___0 = (unsigned int)prev[j___0];
          }
          mask >>= 1;
          if (!(j___0 >= 510U)) {
            goto while_break;
          }
        }
      while_break: /* CIL Label */
          ;
      }
    }
    { fillbuf((int)outbuf[j___0]); }
    return (j___0);
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
        while_continue: /* CIL Label */
            ;
          if ((unsigned int)bitbuf & mask) {
            j___0 = (unsigned int)*((prev + 32768) + j___0);
          } else {
            j___0 = (unsigned int)prev[j___0];
          }
          mask >>= 1;
          if (!(j___0 >= 14U)) {
            goto while_break;
          }
        }
      while_break: /* CIL Label */
          ;
      }
    }
    { fillbuf((int)pt_len[j___0]); }
    if (j___0 != 0U) {
      {
        tmp = getbits((int)(j___0 - 1U));
        j___0 = (1U << (j___0 - 1U)) + tmp;
      }
    }
    return (j___0);
  }
}
static void huf_decode_start(void) {

  {
    {
      init_getbits();
      blocksize = 0U;
    }
    return;
  }
}
static int j;
static int done;
static void decode_start(void) {

  {
    {
      huf_decode_start();
      j = 0;
      done = 0;
    }
    return;
  }
}
static unsigned int i;
static unsigned int decode(unsigned int count, uch *buffer) {
  unsigned int r;
  unsigned int c;
  unsigned int tmp;

  {
    r = 0U;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        j--;
        if (!(j >= 0)) {
          goto while_break;
        }
        *(buffer + r) = *(buffer + i);
        i = (i + 1U) & ((1U << 13) - 1U);
        r++;
        if (r == count) {
          return (r);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        { c = decode_c(); }
        if (c == 510U) {
          done = 1;
          return (r);
        }
        if (c <= 255U) {
          *(buffer + r) = (uch)c;
          r++;
          if (r == count) {
            return (r);
          }
        } else {
          {
            j = (int)(c - 253U);
            tmp = decode_p();
            i = ((r - tmp) - 1U) & ((1U << 13) - 1U);
          }
          {
            while (1) {
            while_continue___1: /* CIL Label */
                ;
              j--;
              if (!(j >= 0)) {
                goto while_break___1;
              }
              *(buffer + r) = *(buffer + i);
              i = (i + 1U) & ((1U << 13) - 1U);
              r++;
              if (r == count) {
                return (r);
              }
            }
          while_break___1: /* CIL Label */
              ;
          }
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
  }
}
int unlzh(int in, int out) {
  unsigned int n;

  {
    {
      ifd = in;
      ofd = out;
      decode_start();
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(!done)) {
          goto while_break;
        }
        { n = decode(1U << 13, window); }
        if (!test) {
          if (n > 0U) {
            {
              write_buf(out, (voidp)((char *)(window)), n);
            }
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return (0);
  }
}
unsigned int outcnt;
long bytes_out;
int unpack(int in, int out);
void flush_window(void);
static ulg orig_len;
static int max_len;
static uch literal[256];
static int lit_base[26];
static int leaves[26];
static int parents[26];
static int peek_bits;
static ulg bitbuf___0;
static int valid;
static void read_tree(void);
static void build_tree(void);
static void read_tree(void) {
  int len;
  int base;
  int n;
  unsigned int tmp;
  int tmp___0;
  int tmp___1;
  unsigned int tmp___2;
  int tmp___3;
  int tmp___4;
  unsigned int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  unsigned int tmp___9;
  int tmp___10;
  int tmp___11;
  char *__cil_tmp17;
  char *__cil_tmp18;

  {
    orig_len = (ulg)0;
    n = 1;
    {

    while_break: /* CIL Label */
        ;
    }
    if (inptr < insize) {
      tmp___2 = inptr;
      inptr++;
      tmp___4 = (int)inbuf[tmp___2];
    } else {
      {
        tmp___3 = fill_inbuf(0);
        tmp___4 = tmp___3;
      }
    }
    max_len = tmp___4;
    if (max_len > 25) {
      {
        error((char *)"invalid compressed data -- Huffman code > 32 bits");
      }
    }
    n = 0;
    len = 1;
    {

    while_break___0: /* CIL Label */
        ;
    }
    if (n > 256) {
      {
        error((char *)"too many leaves in Huffman tree");
      }
    }
    (leaves[max_len])++;
    base = 0;
    len = 1;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!(len <= max_len)) {
          goto while_break___1;
        }
        lit_base[len] = base;
        n = leaves[len];
        {
          while (1) {
          while_continue___2: /* CIL Label */
              ;
            if (!(n > 0)) {
              goto while_break___2;
            }
            tmp___8 = base;
            base++;
            if (inptr < insize) {
              tmp___9 = inptr;
              inptr++;
              tmp___11 = (int)inbuf[tmp___9];
            } else {
              {
                tmp___10 = fill_inbuf(0);
                tmp___11 = tmp___10;
              }
            }
            literal[tmp___8] = (uch)tmp___11;
            n--;
          }
        while_break___2: /* CIL Label */
            ;
        }
        len++;
      }
    while_break___1: /* CIL Label */
        ;
    }
    (leaves[max_len])++;
    return;
  }
}
static void build_tree(void) {
  int nodes;
  int len;
  uch *prefixp;
  int prefixes;
  int tmp;

  {
    nodes = 0;
    len = max_len;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(len >= 1)) {
          goto while_break;
        }
        nodes >>= 1;
        parents[len] = nodes;
        lit_base[len] -= nodes;
        nodes += leaves[len];
        len--;
      }
    while_break: /* CIL Label */
        ;
    }
    if (max_len <= 12) {
      peek_bits = max_len;
    } else {
      peek_bits = 12;
    }
    prefixp = &outbuf[1 << peek_bits];
    len = 1;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(len <= peek_bits)) {
          goto while_break___0;
        }
        prefixes = leaves[len] << (peek_bits - len);
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            tmp = prefixes;
            prefixes--;
            if (!tmp) {
              goto while_break___1;
            }
            prefixp--;
            *prefixp = (uch)len;
          }
        while_break___1: /* CIL Label */
            ;
        }
        len++;
      }
    while_break___0: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___2: /* CIL Label */
          ;
        if (!((unsigned long)prefixp > (unsigned long)(outbuf))) {
          goto while_break___2;
        }
        prefixp--;
        *prefixp = (uch)0;
      }
    while_break___2: /* CIL Label */
        ;
    }
    return;
  }
}
int unpack(int in, int out) {
  int len;
  unsigned int eob;
  register unsigned int peek;
  unsigned int peek_mask;
  unsigned int tmp;
  int tmp___0;
  int tmp___1;
  ulg mask;
  unsigned int tmp___2;
  int tmp___3;
  int tmp___4;
  unsigned int tmp___5;
  char *__cil_tmp15;

  {
    {
      ifd = in;
      ofd = out;
      read_tree();
      build_tree();
      valid = 0;
      bitbuf___0 = (ulg)0;
      peek_mask = (unsigned int)((1 << peek_bits) - 1);
      eob = (unsigned int)(leaves[max_len] - 1);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            if (!(valid < peek_bits)) {
              goto while_break___0;
            }
            if (inptr < insize) {
              tmp = inptr;
              inptr++;
              tmp___1 = (int)inbuf[tmp];
            } else {
              {
                tmp___0 = fill_inbuf(0);
                tmp___1 = tmp___0;
              }
            }
            bitbuf___0 = (bitbuf___0 << 8) | (ulg)tmp___1;
            valid += 8;
          }
        while_break___0: /* CIL Label */
            ;
        }
        peek = (unsigned int)((bitbuf___0 >> (valid - peek_bits)) &
                              (unsigned long)peek_mask);
        len = (int)outbuf[peek];
        if (len > 0) {
          peek >>= peek_bits - len;
        } else {
          mask = (ulg)peek_mask;
          len = peek_bits;
          {
            while (1) {
            while_continue___1: /* CIL Label */
                ;
              len++;
              mask = (mask << 1) + 1UL;
              {
                while (1) {
                while_continue___2: /* CIL Label */
                    ;
                  if (!(valid < len)) {
                    goto while_break___2;
                  }
                  if (inptr < insize) {
                    tmp___2 = inptr;
                    inptr++;
                    tmp___4 = (int)inbuf[tmp___2];
                  } else {
                    {
                      tmp___3 = fill_inbuf(0);
                      tmp___4 = tmp___3;
                    }
                  }
                  bitbuf___0 = (bitbuf___0 << 8) | (ulg)tmp___4;
                  valid += 8;
                }
              while_break___2: /* CIL Label */
                  ;
              }
              peek = (unsigned int)((bitbuf___0 >> (valid - len)) & mask);
              if (!(peek < (unsigned int)parents[len])) {
                goto while_break___1;
              }
            }
          while_break___1: /* CIL Label */
              ;
          }
        }
        if (peek == eob) {
          if (len == max_len) {
            goto while_break;
          }
        }
        tmp___5 = outcnt;
        outcnt++;
        window[tmp___5] = literal[peek + (unsigned int)lit_base[len]];
        if (outcnt == 32768U) {
          {
            flush_window();
          }
        }
        valid -= len;
      }
    while_break: /* CIL Label */
        ;
    }
    { flush_window(); }
    if (orig_len != (ulg)bytes_out) {
      {
        error((char *)"invalid compressed data--length error");
      }
    }
    return (0);
  }
}
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
extern struct _IO_FILE *stderr;
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format,
                   ...);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) memcpy)(
    void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) void *(__attribute__((
    __nonnull__(1), __leaf__)) memset)(void *__s, int __c, size_t __n);
long bytes_in;
char ifname[1024];
char *progname;
int exit_code;
int quiet;
int to_stdout;
void read_error(void);
int maxbits;
int block_mode;
int unlzw(int in, int out);
int block_mode = 128;
int unlzw(int in, int out) {
  register char_type *stackp;
  code_int code;
  int finchar;
  code_int oldcode;
  code_int incode;
  long inbits;
  long posbits;
  int outpos;
  unsigned int bitmask;
  code_int free_ent;
  code_int maxcode;
  code_int maxmaxcode;
  int n_bits;
  int rsize;
  unsigned int tmp;
  int tmp___0;
  register int i___0;
  int e;
  int o;
  register char_type *p;
  int tmp___1;
  char const *tmp___2;
  register int i___1;
  char *__cil_tmp27;
  char *__cil_tmp28;
  char *__cil_tmp29;

  {
    if (inptr < insize) {
      tmp = inptr;
      inptr++;
      maxbits = (int)inbuf[tmp];
    } else {
      {
        tmp___0 = fill_inbuf(0);
        maxbits = tmp___0;
      }
    }
    block_mode = maxbits & 128;
    if ((maxbits & 96) != 0) {
      if (!quiet) {
        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const * /* __restrict  */) "\n%s: %s: warning, unknown "
                                                   "flags 0x%x\n",
                  progname, ifname, maxbits & 96);
        }
      }
      if (exit_code == 0) {
        exit_code = 2;
      }
    }
    maxbits &= 31;
    maxmaxcode = 1L << maxbits;
    if (maxbits > 16) {
      {
        fprintf(
            (FILE * /* __restrict  */)stderr,
            (char const * /* __restrict  */) "\n%s: %s: compressed with %d "
                                             "bits, can only handle %d bits\n",
            progname, ifname, maxbits, 16);
        exit_code = 1;
      }
      return (1);
    }
    rsize = (int)insize;
    n_bits = 9;
    maxcode = (1L << n_bits) - 1L;
    bitmask = (unsigned int)((1 << n_bits) - 1);
    oldcode = (code_int)-1;
    finchar = 0;
    outpos = 0;
    posbits = (long)(inptr << 3);

    {
      memset((voidp)(prev), 0, (size_t)256);
      code = (code_int)255;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(code >= 0L)) {
          goto while_break;
        }
        window[code] = (char_type)code;
        code--;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
      resetbuf:
        o = (int)(posbits >> 3);
        e = (int)(insize - (unsigned int)o);
        i___0 = 0;
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            if (!(i___0 < e)) {
              goto while_break___1;
            }
            inbuf[i___0] = inbuf[i___0 + o];
            i___0++;
          }
        while_break___1: /* CIL Label */
            ;
        }
        insize = (unsigned int)e;
        posbits = 0L;
        if (insize < 64U) {
          {
            rsize = (int)read(in, (void *)((char *)(inbuf) + insize),
                              (size_t)32768);
          }
          if (rsize == -1) {
            {
              read_error();
            }
          }
          insize += (unsigned int)rsize;
          bytes_in = (long)((ulg)bytes_in + (ulg)rsize);
        }
        if (rsize != 0) {
          inbits = ((long)insize - (long)(insize % (unsigned int)n_bits)) << 3;
        } else {
          inbits = ((long)insize << 3) - (long)(n_bits - 1);
        }
        {
          while (1) {
          while_continue___2: /* CIL Label */
              ;
            if (!(inbits > posbits)) {
              goto while_break___2;
            }
            if (free_ent > maxcode) {
              posbits =
                  (posbits - 1L) + ((long)(n_bits << 3) -
                                    ((posbits - 1L) + (long)(n_bits << 3)) %
                                        (long)(n_bits << 3));
              n_bits++;
              if (n_bits == maxbits) {
                maxcode = maxmaxcode;
              } else {
                maxcode = (1L << n_bits) - 1L;
              }
              bitmask = (unsigned int)((1 << n_bits) - 1);
              goto resetbuf;
            }
            p = &inbuf[posbits >> 3];
            code = ((((long)*(p + 0) | ((long)*(p + 1) << 8)) |
                     ((long)*(p + 2) << 16)) >>
                    (posbits & 7L)) &
                   (long)bitmask;
            posbits += (long)n_bits;
            if (oldcode == -1L) {
              if (code >= 256L) {
                {
                  error((char *)"corrupt input.");
                }
              }
              tmp___1 = outpos;
              outpos++;
              oldcode = code;
              finchar = (int)oldcode;
              outbuf[tmp___1] = (char_type)finchar;
              goto while_continue___2;
            }
            if (code == 256L) {
              if (block_mode) {
                {
                  memset((voidp)(prev), 0, (size_t)256);
                  free_ent = (code_int)256;
                  posbits =
                      (posbits - 1L) + ((long)(n_bits << 3) -
                                        ((posbits - 1L) + (long)(n_bits << 3)) %
                                            (long)(n_bits << 3));
                  n_bits = 9;
                  maxcode = (1L << n_bits) - 1L;
                  bitmask = (unsigned int)((1 << n_bits) - 1);
                }
                goto resetbuf;
              }
            }
            incode = code;
            stackp = (char_type *)(&d_buf[32767]);
            if (code >= free_ent) {
              if (code > free_ent) {
                if (!test) {
                  if (outpos > 0) {
                    {
                      write_buf(out, (voidp)((char *)(outbuf)),
                                (unsigned int)outpos);
                      bytes_out = (long)((ulg)bytes_out + (ulg)outpos);
                    }
                  }
                }
                if (to_stdout) {
                  tmp___2 = "corrupt input.";
                } else {
                  tmp___2 = "corrupt input. Use zcat to recover some data.";
                }
                { error((char *)tmp___2); }
              }
              stackp--;
              *stackp = (char_type)finchar;
              code = oldcode;
            }
            {
              while (1) {
              while_continue___3: /* CIL Label */
                  ;
                if (!((cmp_code_int)code >= 256UL)) {
                  goto while_break___3;
                }
                stackp--;
                *stackp = window[code];
                code = (code_int)prev[code];
              }
            while_break___3: /* CIL Label */
                ;
            }
            stackp--;
            finchar = (int)window[code];
            *stackp = (char_type)finchar;
            i___1 = (int)((char_type *)(&d_buf[32767]) - stackp);
            if (outpos + i___1 >= 16384) {
              {
                while (1) {
                while_continue___4: /* CIL Label */
                    ;
                  if (i___1 > 16384 - outpos) {
                    i___1 = 16384 - outpos;
                  }
                  if (i___1 > 0) {
                    {
                      memcpy((void * /* __restrict  */)(outbuf + outpos),
                             (void const * /* __restrict  */)stackp,
                             (size_t)i___1);
                      outpos += i___1;
                    }
                  }
                  if (outpos >= 16384) {
                    if (!test) {
                      {
                        write_buf(out, (voidp)((char *)(outbuf)),
                                  (unsigned int)outpos);
                        bytes_out = (long)((ulg)bytes_out + (ulg)outpos);
                      }
                    }
                    outpos = 0;
                  }
                  stackp += i___1;
                  i___1 = (int)((char_type *)(&d_buf[32767]) - stackp);
                  if (!(i___1 > 0)) {
                    goto while_break___4;
                  }
                }
              while_break___4: /* CIL Label */
                  ;
              }
            } else {
              {
                memcpy((void * /* __restrict  */)(outbuf + outpos),
                       (void const * /* __restrict  */)stackp, (size_t)i___1);
                outpos += i___1;
              }
            }
            code = free_ent;
            if (code < maxmaxcode) {
              prev[code] = (unsigned short)oldcode;
              window[code] = (char_type)finchar;
              free_ent = code + 1L;
            }
            oldcode = incode;
          }
        while_break___2: /* CIL Label */
            ;
        }
        if (!(rsize != 0)) {
          goto while_break___0;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    if (!test) {
      if (outpos > 0) {
        {
          write_buf(out, (voidp)((char *)(outbuf)), (unsigned int)outpos);
          bytes_out = (long)((ulg)bytes_out + (ulg)outpos);
        }
      }
    }
    return (0);
  }
}
int lzw(int in, int out);
static int msg_done = 0;
int lzw(int in, int out) {

  {

    {
      msg_done = 1;
      fprintf((FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "output in compress .Z format "
                                               "not supported\n");
    }
    if (in != out) {
      exit_code = 1;
    }
    return (1);
  }
}
extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern ssize_t write(int __fd, void const *__buf, size_t __n);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(
    size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) calloc)(
    size_t __nmemb, size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(
    void *__ptr);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);
extern int _IO_putc(int __c, _IO_FILE *__fp);
extern void perror(char const *__s);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest,
                                          char const *__restrict __src);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) strrchr)(char const *__s, int __c)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1, 2),
                      __leaf__)) strcspn)(char const *__s, char const *__reject)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1, 2),
                      __leaf__)) strspn)(char const *__s, char const *__accept)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s)
    __attribute__((__pure__));
char ofname[1024];
void abort_gzip(void);
int copy(int in, int out);
ulg updcrc(uch *s, unsigned int n);
void clear_bufs(void);
void flush_outbuf(void);
char *strlwr(char *s);
char *basename(char *fname);
char *add_envopt(int *argcp, char ***argvp, char *env___0);
void write_error(void);
void display_ratio(long num, long den, FILE *file);
voidp xmalloc(unsigned int size);
ulg crc_32_tab[256];
int copy(int in, int out) {
  int *tmp;
  int *tmp___0;

  {
    {
      tmp = __errno_location();
      *tmp = 0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;

        {
          write_buf(out, (voidp)((char *)(inbuf)), insize);
          bytes_out += (long)insize;
          insize =
              (unsigned int)read(in, (void *)((char *)(inbuf)), (size_t)32768);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if ((int)insize == -1) {
      {
        tmp___0 = __errno_location();
      }
      if (*tmp___0 != 0) {
        {
          read_error();
        }
      }
    }
    bytes_in = bytes_out;
    return (0);
  }
}
static ulg crc = (ulg)4294967295L;
ulg updcrc(uch *s, unsigned int n) {
  register ulg c;
  uch *tmp;

  {
    if ((unsigned long)s == (unsigned long)((void *)0)) {
      c = (ulg)4294967295L;
    } else {
      c = crc;
      if (n) {
        {
          while (1) {
          while_continue: /* CIL Label */
              ;
            tmp = s;
            s++;
            c = crc_32_tab[((int)c ^ (int)*tmp) & 255] ^ (c >> 8);
            n--;
            if (!n) {
              goto while_break;
            }
          }
        while_break: /* CIL Label */
            ;
        }
      }
    }
    crc = c;
    return (c ^ 4294967295UL);
  }
}
void clear_bufs(void) {

  {
    outcnt = 0U;
    inptr = 0U;
    insize = inptr;
    bytes_out = 0L;
    bytes_in = bytes_out;
    return;
  }
}
int fill_inbuf(int eof_ok) {
  int len;
  int *tmp;

  {
    {
      insize = 0U;
      tmp = __errno_location();
      *tmp = 0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          len = (int)read(ifd, (void *)((char *)(inbuf) + insize),
                          (size_t)(32768U - insize));
        }
        if (len == 0) {
          goto while_break;
        } else {
          if (len == -1) {
            goto while_break;
          }
        }
        insize += (unsigned int)len;
        if (!(insize < 32768U)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if (insize == 0U) {
      if (eof_ok) {
        return (-1);
      }
      { read_error(); }
    }
    bytes_in = (long)((ulg)bytes_in + (ulg)insize);
    inptr = 1U;
    return ((int)inbuf[0]);
  }
}
void flush_outbuf(void) {

  {
    if (outcnt == 0U) {
      return;
    }
    {
      write_buf(ofd, (voidp)((char *)(outbuf)), outcnt);
      bytes_out = (long)((ulg)bytes_out + (ulg)outcnt);
      outcnt = 0U;
    }
    return;
  }
}
void flush_window(void) {

  {
    if (outcnt == 0U) {
      return;
    }
    { updcrc(window, outcnt); }
    if (!test) {
      {
        write_buf(ofd, (voidp)((char *)(window)), outcnt);
      }
    }
    bytes_out = (long)((ulg)bytes_out + (ulg)outcnt);
    outcnt = 0U;
    return;
  }
}
void write_buf(int fd, voidp buf, unsigned int cnt) {
  unsigned int n;

  {
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { n = (unsigned int)write(fd, (void const *)buf, (size_t)cnt); }
        if (!(n != cnt)) {
          goto while_break;
        }
        if (n == 4294967295U) {
          {
            write_error();
          }
        }
        cnt -= n;
        buf = (voidp)((char *)buf + n);
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
char *strlwr(char *s) {
  char *t;
  unsigned short const **tmp___0;

  {
    t = s;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!*t) {
          goto while_break;
        }
        { tmp___0 = __ctype_b_loc(); }
        if ((int const) * (*tmp___0 + (int)*t) & 256) {
          *t = (char)(((int)*t - 65) + 97);
        } else {
          *t = *t;
        }
        t++;
      }
    while_break: /* CIL Label */
        ;
    }
    return (s);
  }
}

char *add_envopt(int *argcp, char ***argvp, char *env___0) {
  char *p;
  char **oargv;
  char **nargv;
  int oargc;
  int nargc;
  char *tmp;
  size_t tmp___0;
  size_t tmp___2;
  size_t tmp___3;
  char *tmp___4;
  int tmp___6;
  char **tmp___7;
  char **tmp___8;
  size_t tmp___9;
  char **tmp___10;
  char *tmp___11;
  char **tmp___12;
  char **tmp___13;
  int tmp___14;
  char *__cil_tmp25;
  char *__cil_tmp26;

  {
    {
      oargc = *argcp;
      nargc = 0;
      tmp = getenv((char const *)env___0);
      env___0 = tmp;
    }
    if ((unsigned long)env___0 == (unsigned long)((void *)0)) {
      return ((char *)((void *)0));
    }
    {
      tmp___0 = strlen((char const *)env___0);
      p = (char *)xmalloc((unsigned int)(tmp___0 + 1UL));
      env___0 = strcpy((char * /* __restrict  */)p,
                       (char const * /* __restrict  */)env___0);
      p = env___0;
    }
    {

    while_break: /* CIL Label */
        ;
    }
    if (nargc == 0) {
      {
        free((void *)env___0);
      }
      return ((char *)((void *)0));
    }
    {
      *argcp += nargc;
      nargv = (char **)calloc((size_t)(*argcp + 1), sizeof(char *));
    }
    if ((unsigned long)nargv == (unsigned long)((void *)0)) {
      {
        error((char *)"out of memory");
      }
    }
    oargv = *argvp;
    *argvp = nargv;
    tmp___6 = oargc;
    oargc--;
    if (tmp___6 < 0) {
      {
        error((char *)"argc<=0");
      }
    }
    tmp___7 = nargv;
    nargv++;
    tmp___8 = oargv;
    oargv++;
    *tmp___7 = *tmp___8;
    p = env___0;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(nargc > 0)) {
          goto while_break___0;
        }
        {
          tmp___9 = strspn((char const *)p, " \t");
          p += tmp___9;
          tmp___10 = nargv;
          nargv++;
          *tmp___10 = p;
        }
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            tmp___11 = p;
            p++;
            if (!*tmp___11) {
              goto while_break___1;
            }
          }
        while_break___1: /* CIL Label */
            ;
        }
        nargc--;
      }
    while_break___0: /* CIL Label */
        ;
    }
    {

    while_break___2: /* CIL Label */
        ;
    }
    *nargv = (char *)((void *)0);
    return (env___0);
  }
}

void read_error(void) {
  int *tmp;

  {
    {
      fprintf((FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "\n%s: ", progname);
      tmp = __errno_location();
    }
    if (*tmp != 0) {
      {
        perror((char const *)(ifname));
      }
    } else {
      {
        fprintf((FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "%s: unexpected end of file\n",
                ifname);
      }
    }
    { abort_gzip(); }
    return;
  }
}
void write_error(void) {

  {
    {
      fprintf((FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "\n%s: ", progname);
      perror((char const *)(ofname));
      abort_gzip();
    }
    return;
  }
}

voidp xmalloc(unsigned int size) {
  voidp cp;
  voidp tmp;
  char *__cil_tmp4;

  {
    {
      tmp = malloc((size_t)size);
      cp = tmp;
    }
    if ((unsigned long)cp == (unsigned long)((void *)0)) {
      {
        error((char *)"out of memory");
      }
    }
    return (cp);
  }
}
ulg crc_32_tab[256] = {
    (ulg)0L,          (ulg)1996959894L, (ulg)3993919788L, (ulg)2567524794L,
    (ulg)124634137L,  (ulg)1886057615L, (ulg)3915621685L, (ulg)2657392035L,
    (ulg)249268274L,  (ulg)2044508324L, (ulg)3772115230L, (ulg)2547177864L,
    (ulg)162941995L,  (ulg)2125561021L, (ulg)3887607047L, (ulg)2428444049L,
    (ulg)498536548L,  (ulg)1789927666L, (ulg)4089016648L, (ulg)2227061214L,
    (ulg)450548861L,  (ulg)1843258603L, (ulg)4107580753L, (ulg)2211677639L,
    (ulg)325883990L,  (ulg)1684777152L, (ulg)4251122042L, (ulg)2321926636L,
    (ulg)335633487L,  (ulg)1661365465L, (ulg)4195302755L, (ulg)2366115317L,
    (ulg)997073096L,  (ulg)1281953886L, (ulg)3579855332L, (ulg)2724688242L,
    (ulg)1006888145L, (ulg)1258607687L, (ulg)3524101629L, (ulg)2768942443L,
    (ulg)901097722L,  (ulg)1119000684L, (ulg)3686517206L, (ulg)2898065728L,
    (ulg)853044451L,  (ulg)1172266101L, (ulg)3705015759L, (ulg)2882616665L,
    (ulg)651767980L,  (ulg)1373503546L, (ulg)3369554304L, (ulg)3218104598L,
    (ulg)565507253L,  (ulg)1454621731L, (ulg)3485111705L, (ulg)3099436303L,
    (ulg)671266974L,  (ulg)1594198024L, (ulg)3322730930L, (ulg)2970347812L,
    (ulg)795835527L,  (ulg)1483230225L, (ulg)3244367275L, (ulg)3060149565L,
    (ulg)1994146192L, (ulg)31158534L,   (ulg)2563907772L, (ulg)4023717930L,
    (ulg)1907459465L, (ulg)112637215L,  (ulg)2680153253L, (ulg)3904427059L,
    (ulg)2013776290L, (ulg)251722036L,  (ulg)2517215374L, (ulg)3775830040L,
    (ulg)2137656763L, (ulg)141376813L,  (ulg)2439277719L, (ulg)3865271297L,
    (ulg)1802195444L, (ulg)476864866L,  (ulg)2238001368L, (ulg)4066508878L,
    (ulg)1812370925L, (ulg)453092731L,  (ulg)2181625025L, (ulg)4111451223L,
    (ulg)1706088902L, (ulg)314042704L,  (ulg)2344532202L, (ulg)4240017532L,
    (ulg)1658658271L, (ulg)366619977L,  (ulg)2362670323L, (ulg)4224994405L,
    (ulg)1303535960L, (ulg)984961486L,  (ulg)2747007092L, (ulg)3569037538L,
    (ulg)1256170817L, (ulg)1037604311L, (ulg)2765210733L, (ulg)3554079995L,
    (ulg)1131014506L, (ulg)879679996L,  (ulg)2909243462L, (ulg)3663771856L,
    (ulg)1141124467L, (ulg)855842277L,  (ulg)2852801631L, (ulg)3708648649L,
    (ulg)1342533948L, (ulg)654459306L,  (ulg)3188396048L, (ulg)3373015174L,
    (ulg)1466479909L, (ulg)544179635L,  (ulg)3110523913L, (ulg)3462522015L,
    (ulg)1591671054L, (ulg)702138776L,  (ulg)2966460450L, (ulg)3352799412L,
    (ulg)1504918807L, (ulg)783551873L,  (ulg)3082640443L, (ulg)3233442989L,
    (ulg)3988292384L, (ulg)2596254646L, (ulg)62317068L,   (ulg)1957810842L,
    (ulg)3939845945L, (ulg)2647816111L, (ulg)81470997L,   (ulg)1943803523L,
    (ulg)3814918930L, (ulg)2489596804L, (ulg)225274430L,  (ulg)2053790376L,
    (ulg)3826175755L, (ulg)2466906013L, (ulg)167816743L,  (ulg)2097651377L,
    (ulg)4027552580L, (ulg)2265490386L, (ulg)503444072L,  (ulg)1762050814L,
    (ulg)4150417245L, (ulg)2154129355L, (ulg)426522225L,  (ulg)1852507879L,
    (ulg)4275313526L, (ulg)2312317920L, (ulg)282753626L,  (ulg)1742555852L,
    (ulg)4189708143L, (ulg)2394877945L, (ulg)397917763L,  (ulg)1622183637L,
    (ulg)3604390888L, (ulg)2714866558L, (ulg)953729732L,  (ulg)1340076626L,
    (ulg)3518719985L, (ulg)2797360999L, (ulg)1068828381L, (ulg)1219638859L,
    (ulg)3624741850L, (ulg)2936675148L, (ulg)906185462L,  (ulg)1090812512L,
    (ulg)3747672003L, (ulg)2825379669L, (ulg)829329135L,  (ulg)1181335161L,
    (ulg)3412177804L, (ulg)3160834842L, (ulg)628085408L,  (ulg)1382605366L,
    (ulg)3423369109L, (ulg)3138078467L, (ulg)570562233L,  (ulg)1426400815L,
    (ulg)3317316542L, (ulg)2998733608L, (ulg)733239954L,  (ulg)1555261956L,
    (ulg)3268935591L, (ulg)3050360625L, (ulg)752459403L,  (ulg)1541320221L,
    (ulg)2607071920L, (ulg)3965973030L, (ulg)1969922972L, (ulg)40735498L,
    (ulg)2617837225L, (ulg)3943577151L, (ulg)1913087877L, (ulg)83908371L,
    (ulg)2512341634L, (ulg)3803740692L, (ulg)2075208622L, (ulg)213261112L,
    (ulg)2463272603L, (ulg)3855990285L, (ulg)2094854071L, (ulg)198958881L,
    (ulg)2262029012L, (ulg)4057260610L, (ulg)1759359992L, (ulg)534414190L,
    (ulg)2176718541L, (ulg)4139329115L, (ulg)1873836001L, (ulg)414664567L,
    (ulg)2282248934L, (ulg)4279200368L, (ulg)1711684554L, (ulg)285281116L,
    (ulg)2405801727L, (ulg)4167216745L, (ulg)1634467795L, (ulg)376229701L,
    (ulg)2685067896L, (ulg)3608007406L, (ulg)1308918612L, (ulg)956543938L,
    (ulg)2808555105L, (ulg)3495958263L, (ulg)1231636301L, (ulg)1047427035L,
    (ulg)2932959818L, (ulg)3654703836L, (ulg)1088359270L, (ulg)936918000L,
    (ulg)2847714899L, (ulg)3736837829L, (ulg)1202900863L, (ulg)817233897L,
    (ulg)3183342108L, (ulg)3401237130L, (ulg)1404277552L, (ulg)615818150L,
    (ulg)3134207493L, (ulg)3453421203L, (ulg)1423857449L, (ulg)601450431L,
    (ulg)3009837614L, (ulg)3294710456L, (ulg)1567103746L, (ulg)711928724L,
    (ulg)3020668471L, (ulg)3272380065L, (ulg)1510334235L, (ulg)755167117L};
int inflate(void);
int huft_build(unsigned int *b, unsigned int n, unsigned int s, ush *d, ush *e,
               struct huft **t, int *m);
int huft_free(struct huft *t);
int inflate_codes(struct huft *tl, struct huft *td, int bl, int bd);
int inflate_stored(void);
int inflate_fixed(void);
int inflate_dynamic(void);
int inflate_block(int *e);
static unsigned int border[19] = {16U, 17U, 18U, 0U, 8U,  7U, 9U,  6U, 10U, 5U,
                                  11U, 4U,  12U, 3U, 13U, 2U, 14U, 1U, 15U};

static ush cplext[31] = {
    (ush)0, (ush)0, (ush)0, (ush)0, (ush)0, (ush)0,  (ush)0, (ush)0,
    (ush)1, (ush)1, (ush)1, (ush)1, (ush)2, (ush)2,  (ush)2, (ush)2,
    (ush)3, (ush)3, (ush)3, (ush)3, (ush)4, (ush)4,  (ush)4, (ush)4,
    (ush)5, (ush)5, (ush)5, (ush)5, (ush)0, (ush)99, (ush)99};

static ush cpdext[30] = {(ush)0,  (ush)0,  (ush)0,  (ush)0,  (ush)1,  (ush)1,
                         (ush)2,  (ush)2,  (ush)3,  (ush)3,  (ush)4,  (ush)4,
                         (ush)5,  (ush)5,  (ush)6,  (ush)6,  (ush)7,  (ush)7,
                         (ush)8,  (ush)8,  (ush)9,  (ush)9,  (ush)10, (ush)10,
                         (ush)11, (ush)11, (ush)12, (ush)12, (ush)13, (ush)13};
ulg bb;
unsigned int bk;
ush mask_bits[17] = {(ush)0,     (ush)1,    (ush)3,    (ush)7,    (ush)15,
                     (ush)31,    (ush)63,   (ush)127,  (ush)255,  (ush)511,
                     (ush)1023,  (ush)2047, (ush)4095, (ush)8191, (ush)16383,
                     (ush)32767, (ush)65535};
int lbits = 9;
int dbits = 6;
unsigned int hufts;

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
        {
          p--;
          q = p->v.t;
          free((void *)((char *)p));
          p = q;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return (0);
  }
}

int method;
int decrypt;
int unzip(int in, int out);
int check_zipfile(int in);
char *key;
int pkzip = 0;
int ext_header = 0;
int check_zipfile(int in) {
  uch *h;

  {
    h = inbuf + inptr;
    ifd = in;
    inptr += (unsigned int)((30 + ((int)((ush) * ((h + 26) + 0)) |
                                   ((int)((ush) * ((h + 26) + 1)) << 8))) +
                            ((int)((ush) * ((h + 28) + 0)) |
                             ((int)((ush) * ((h + 28) + 1)) << 8)));
    if (inptr > insize) {
      {
        fprintf(
            (FILE * /* __restrict  */)stderr,
            (char const * /* __restrict  */) "\n%s: %s: not a valid zip file\n",
            progname, ifname);
        exit_code = 1;
      }
      return (1);
    } else {
      if (((ulg)((int)((ush) * (h + 0)) | ((int)((ush) * (h + 1)) << 8)) |
           ((ulg)((int)((ush) * ((h + 2) + 0)) |
                  ((int)((ush) * ((h + 2) + 1)) << 8))
            << 16)) != 67324752UL) {
        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const
                       * /* __restrict  */) "\n%s: %s: not a valid zip file\n",
                  progname, ifname);
          exit_code = 1;
        }
        return (1);
      }
    }
    method = (int)*(h + 8);
    if (method != 0) {
      if (method != 8) {
        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const
                       * /* __restrict  */) "\n%s: %s: first entry not "
                                            "deflated or stored -- use unzip\n",
                  progname, ifname);
          exit_code = 1;
        }
        return (1);
      }
    }
    decrypt = (int)*(h + 6) & 1;
    if (decrypt != 0) {
      {
        fprintf(
            (FILE * /* __restrict  */)stderr,
            (char const
                 * /* __restrict  */) "\n%s: %s: encrypted file -- use unzip\n",
            progname, ifname);
        exit_code = 1;
      }
      return (1);
    }
    ext_header = ((int)*(h + 6) & 8) != 0;
    pkzip = 1;
    return (0);
  }
}
int unzip(int in, int out) {
  ulg orig_crc;
  ulg orig_len___0;
  int n;
  uch buf[16];
  int res;
  int tmp;
  register ulg n___0;
  int tmp___0;
  uch c;
  unsigned int tmp___1;
  int tmp___2;
  int tmp___3;
  unsigned int tmp___4;
  ulg tmp___5;
  unsigned int tmp___6;
  int tmp___7;
  int tmp___8;
  unsigned int tmp___9;
  int tmp___10;
  int tmp___11;
  ulg tmp___12;
  void *__cil_tmp24;
  char *__cil_tmp25;
  char *__cil_tmp26;
  char *__cil_tmp27;
  char *__cil_tmp28;
  char *__cil_tmp29;
  char *__cil_tmp30;
  char *__cil_tmp31;

  {
    {
      orig_crc = (ulg)0;
      orig_len___0 = (ulg)0;
      ifd = in;
      ofd = out;
      updcrc((uch *)((void *)0), 0U);
    }
    if (pkzip) {
      if (!ext_header) {
        orig_crc = (ulg)((int)((ush) * ((inbuf + 14) + 0)) |
                         ((int)((ush) * ((inbuf + 14) + 1)) << 8)) |
                   ((ulg)((int)((ush) * (((inbuf + 14) + 2) + 0)) |
                          ((int)((ush) * (((inbuf + 14) + 2) + 1)) << 8))
                    << 16);
        orig_len___0 = (ulg)((int)((ush) * ((inbuf + 22) + 0)) |
                             ((int)((ush) * ((inbuf + 22) + 1)) << 8)) |
                       ((ulg)((int)((ush) * (((inbuf + 22) + 2) + 0)) |
                              ((int)((ush) * (((inbuf + 22) + 2) + 1)) << 8))
                        << 16);
      }
    }

    if (!pkzip) {
      n = 0;
      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;
          if (!(n < 8)) {
            goto while_break___0;
          }

          buf[n] = (uch)tmp___8;
          n++;
        }
      while_break___0: /* CIL Label */
          ;
      }
      orig_crc = (ulg)((int)((ush)buf[0]) | ((int)((ush)buf[1]) << 8)) |
                 ((ulg)((int)((ush) * ((buf + 2) + 0)) |
                        ((int)((ush) * ((buf + 2) + 1)) << 8))
                  << 16);
      orig_len___0 = (ulg)((int)((ush) * ((buf + 4) + 0)) |
                           ((int)((ush) * ((buf + 4) + 1)) << 8)) |
                     ((ulg)((int)((ush) * (((buf + 4) + 2) + 0)) |
                            ((int)((ush) * (((buf + 4) + 2) + 1)) << 8))
                      << 16);
    } else {
      if (ext_header) {
        n = 0;
        {

        while_break___1: /* CIL Label */
            ;
        }
        orig_crc = (ulg)((int)((ush) * ((buf + 4) + 0)) |
                         ((int)((ush) * ((buf + 4) + 1)) << 8)) |
                   ((ulg)((int)((ush) * (((buf + 4) + 2) + 0)) |
                          ((int)((ush) * (((buf + 4) + 2) + 1)) << 8))
                    << 16);
        orig_len___0 = (ulg)((int)((ush) * ((buf + 12) + 0)) |
                             ((int)((ush) * ((buf + 12) + 1)) << 8)) |
                       ((ulg)((int)((ush) * (((buf + 12) + 2) + 0)) |
                              ((int)((ush) * (((buf + 12) + 2) + 1)) << 8))
                        << 16);
      }
    }
    { tmp___12 = updcrc(outbuf, 0U); }
    if (orig_crc != tmp___12) {
      {
        error((char *)"invalid compressed data--crc error");
      }
    }
    if (orig_len___0 != (ulg)bytes_out) {
      {
        error((char *)"invalid compressed data--length error");
      }
    }
    if (pkzip) {
      if (inptr + 4U < insize) {
      }
    }
    pkzip = 0;
    ext_header = pkzip;
    return (0);
  }
}
int file_read(char *buf, unsigned int size);
void bi_init(file_t zipfile);
void send_bits(int value, int length);
unsigned int bi_reverse(unsigned int code, int len);
void bi_windup(void);
void copy_block(char *buf, unsigned int len, int header);
int (*read_buf)(char *buf, unsigned int size);
static file_t zfile;
static unsigned short bi_buf;
static int bi_valid;
void bi_init(file_t zipfile) {

  {
    zfile = zipfile;
    bi_buf = (unsigned short)0;
    bi_valid = 0;
    if (zfile != -1) {
      read_buf = &file_read;
    }
    return;
  }
}
void send_bits(int value, int length) {
  unsigned int tmp;
  unsigned int tmp___0;
  unsigned int tmp___1;
  unsigned int tmp___2;

  {
    if (bi_valid > (int)(16UL * sizeof(char)) - length) {
      bi_buf = (unsigned short)((int)bi_buf | (value << bi_valid));
      if (outcnt < 16382U) {
        tmp = outcnt;
        outcnt++;
        outbuf[tmp] = (uch)((int)bi_buf & 255);
        tmp___0 = outcnt;
        outcnt++;
        outbuf[tmp___0] = (uch)((int)bi_buf >> 8);
      } else {
        tmp___1 = outcnt;
        outcnt++;
        outbuf[tmp___1] = (uch)((int)bi_buf & 255);
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
        tmp___2 = outcnt;
        outcnt++;
        outbuf[tmp___2] = (uch)((int)bi_buf >> 8);
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
      }
      bi_buf = (unsigned short)((int)((ush)value) >> (16UL * sizeof(char) -
                                                      (unsigned long)bi_valid));
      bi_valid = (int)((unsigned long)bi_valid +
                       ((unsigned long)length - 16UL * sizeof(char)));
    } else {
      bi_buf = (unsigned short)((int)bi_buf | (value << bi_valid));
      bi_valid += length;
    }
    return;
  }
}
unsigned int bi_reverse(unsigned int code, int len) {
  register unsigned int res;

  {
    res = 0U;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        res |= code & 1U;
        code >>= 1;
        res <<= 1;
        len--;
        if (!(len > 0)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return (res >> 1);
  }
}
void bi_windup(void) {
  unsigned int tmp;
  unsigned int tmp___0;
  unsigned int tmp___1;
  unsigned int tmp___2;
  unsigned int tmp___3;

  {
    if (bi_valid > 8) {
      if (outcnt < 16382U) {
        tmp = outcnt;
        outcnt++;
        outbuf[tmp] = (uch)((int)bi_buf & 255);
        tmp___0 = outcnt;
        outcnt++;
        outbuf[tmp___0] = (uch)((int)bi_buf >> 8);
      } else {
        tmp___1 = outcnt;
        outcnt++;
        outbuf[tmp___1] = (uch)((int)bi_buf & 255);
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
        tmp___2 = outcnt;
        outcnt++;
        outbuf[tmp___2] = (uch)((int)bi_buf >> 8);
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
      }
    } else {
      if (bi_valid > 0) {
        tmp___3 = outcnt;
        outcnt++;
        outbuf[tmp___3] = (uch)bi_buf;
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
      }
    }
    bi_buf = (unsigned short)0;
    bi_valid = 0;
    return;
  }
}
void copy_block(char *buf, unsigned int len, int header) {
  unsigned int tmp;
  unsigned int tmp___0;
  unsigned int tmp___1;
  unsigned int tmp___2;
  unsigned int tmp___3;
  unsigned int tmp___4;
  unsigned int tmp___5;
  unsigned int tmp___6;
  unsigned int tmp___7;
  char *tmp___8;
  unsigned int tmp___9;

  {
    { bi_windup(); }
    if (header) {
      if (outcnt < 16382U) {
        tmp = outcnt;
        outcnt++;
        outbuf[tmp] = (uch)((int)((ush)len) & 255);
        tmp___0 = outcnt;
        outcnt++;
        outbuf[tmp___0] = (uch)((int)((ush)len) >> 8);
      } else {
        tmp___1 = outcnt;
        outcnt++;
        outbuf[tmp___1] = (uch)((int)((ush)len) & 255);
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
        tmp___2 = outcnt;
        outcnt++;
        outbuf[tmp___2] = (uch)((int)((ush)len) >> 8);
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
      }
      if (outcnt < 16382U) {
        tmp___3 = outcnt;
        outcnt++;
        outbuf[tmp___3] = (uch)((int)((ush)(~len)) & 255);
        tmp___4 = outcnt;
        outcnt++;
        outbuf[tmp___4] = (uch)((int)((ush)(~len)) >> 8);
      } else {
        tmp___5 = outcnt;
        outcnt++;
        outbuf[tmp___5] = (uch)((int)((ush)(~len)) & 255);
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
        tmp___6 = outcnt;
        outcnt++;
        outbuf[tmp___6] = (uch)((int)((ush)(~len)) >> 8);
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
      }
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        tmp___9 = len;
        len--;
        if (!tmp___9) {
          goto while_break;
        }
        tmp___7 = outcnt;
        outcnt++;
        tmp___8 = buf;
        buf++;
        outbuf[tmp___7] = (uch)*tmp___8;
        if (outcnt == 16384U) {
          {
            flush_outbuf();
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
int level;
void ct_init(ush *attr, int *methodp);
int ct_tally(int dist, int lc);
ulg flush_block(char *buf, ulg stored_len, int eof);
static int extra_lbits[29] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2,
                              2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
static int extra_dbits[30] = {0, 0, 0,  0,  1,  1,  2,  2,  3,  3,
                              4, 4, 5,  5,  6,  6,  7,  7,  8,  8,
                              9, 9, 10, 10, 11, 11, 12, 12, 13, 13};
static int extra_blbits[19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 2, 3, 7};
static ct_data dyn_ltree[573];
static ct_data dyn_dtree[61];
static ct_data static_ltree[288];
static ct_data static_dtree[30];
static ct_data bl_tree[39];
static tree_desc l_desc = {dyn_ltree, static_ltree, extra_lbits, 257, 286, 15,
                           0};
static tree_desc d_desc = {dyn_dtree, static_dtree, extra_dbits, 0, 30, 15, 0};
static tree_desc bl_desc = {bl_tree, (ct_data *)0, extra_blbits, 0, 19, 7, 0};
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
static uch dist_code[512];
static int base_length[29];
static int base_dist[30];
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
static void gen_codes(ct_data *tree, int max_code);
static void build_tree___0(tree_desc *desc);
static void scan_tree(ct_data *tree, int max_code);
static void send_tree(ct_data *tree, int max_code);
static int build_bl_tree(void);
static void send_all_trees(int lcodes, int dcodes, int blcodes);
static void compress_block(ct_data *ltree, ct_data *dtree);
static void set_file_type(void);
void ct_init(ush *attr, int *methodp) {
  int n;
  int bits;
  int length;
  int code;
  int dist;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;

  {
    file_type = attr;
    file_method = methodp;
    input_len = (ulg)0L;
    compressed_len = input_len;
    if ((int)static_dtree[0].dl.len != 0) {
      return;
    }
    length = 0;
    code = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(code < 28)) {
          goto while_break;
        }
        base_length[code] = length;
        n = 0;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            if (!(n < 1 << extra_lbits[code])) {
              goto while_break___0;
            }
            tmp = length;
            length++;
            length_code[tmp] = (uch)code;
            n++;
          }
        while_break___0: /* CIL Label */
            ;
        }
        code++;
      }
    while_break: /* CIL Label */
        ;
    }
    length_code[length - 1] = (uch)code;
    dist = 0;
    code = 0;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!(code < 16)) {
          goto while_break___1;
        }
        base_dist[code] = dist;
        n = 0;
        {
          while (1) {
          while_continue___2: /* CIL Label */
              ;
            if (!(n < 1 << extra_dbits[code])) {
              goto while_break___2;
            }
            tmp___0 = dist;
            dist++;
            dist_code[tmp___0] = (uch)code;
            n++;
          }
        while_break___2: /* CIL Label */
            ;
        }
        code++;
      }
    while_break___1: /* CIL Label */
        ;
    }
    dist >>= 7;
    {
      while (1) {
      while_continue___3: /* CIL Label */
          ;
        if (!(code < 30)) {
          goto while_break___3;
        }
        base_dist[code] = dist << 7;
        n = 0;
        {
          while (1) {
          while_continue___4: /* CIL Label */
              ;
            if (!(n < 1 << (extra_dbits[code] - 7))) {
              goto while_break___4;
            }
            tmp___1 = dist;
            dist++;
            dist_code[256 + tmp___1] = (uch)code;
            n++;
          }
        while_break___4: /* CIL Label */
            ;
        }
        code++;
      }
    while_break___3: /* CIL Label */
        ;
    }
    bits = 0;
    {
      while (1) {
      while_continue___5: /* CIL Label */
          ;
        if (!(bits <= 15)) {
          goto while_break___5;
        }
        bl_count[bits] = (ush)0;
        bits++;
      }
    while_break___5: /* CIL Label */
        ;
    }
    n = 0;
    {
      while (1) {
      while_continue___6: /* CIL Label */
          ;
        if (!(n <= 143)) {
          goto while_break___6;
        }
        tmp___2 = n;
        n++;
        static_ltree[tmp___2].dl.len = (ush)8;
        bl_count[8] = (ush)((int)bl_count[8] + 1);
      }
    while_break___6: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___7: /* CIL Label */
          ;
        if (!(n <= 255)) {
          goto while_break___7;
        }
        tmp___3 = n;
        n++;
        static_ltree[tmp___3].dl.len = (ush)9;
        bl_count[9] = (ush)((int)bl_count[9] + 1);
      }
    while_break___7: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___8: /* CIL Label */
          ;
        if (!(n <= 279)) {
          goto while_break___8;
        }
        tmp___4 = n;
        n++;
        static_ltree[tmp___4].dl.len = (ush)7;
        bl_count[7] = (ush)((int)bl_count[7] + 1);
      }
    while_break___8: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___9: /* CIL Label */
          ;
        if (!(n <= 287)) {
          goto while_break___9;
        }
        tmp___5 = n;
        n++;
        static_ltree[tmp___5].dl.len = (ush)8;
        bl_count[8] = (ush)((int)bl_count[8] + 1);
      }
    while_break___9: /* CIL Label */
        ;
    }
    {
      gen_codes(static_ltree, 287);
      n = 0;
    }
    {
      while (1) {
      while_continue___10: /* CIL Label */
          ;
        if (!(n < 30)) {
          goto while_break___10;
        }
        {
          static_dtree[n].dl.len = (ush)5;
          static_dtree[n].fc.code = (ush)bi_reverse((unsigned int)n, 5);
          n++;
        }
      }
    while_break___10: /* CIL Label */
        ;
    }
    { init_block(); }
    return;
  }
}
static void init_block(void) {
  int n;

  {
    n = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(n < 286)) {
          goto while_break;
        }
        dyn_ltree[n].fc.freq = (ush)0;
        n++;
      }
    while_break: /* CIL Label */
        ;
    }
    n = 0;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(n < 30)) {
          goto while_break___0;
        }
        dyn_dtree[n].fc.freq = (ush)0;
        n++;
      }
    while_break___0: /* CIL Label */
        ;
    }
    n = 0;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!(n < 19)) {
          goto while_break___1;
        }
        bl_tree[n].fc.freq = (ush)0;
        n++;
      }
    while_break___1: /* CIL Label */
        ;
    }
    dyn_ltree[256].fc.freq = (ush)1;
    static_len = (ulg)0L;
    opt_len = static_len;
    last_flags = 0U;
    last_dist = last_flags;
    last_lit = last_dist;
    flags = (uch)0;
    flag_bit = (uch)1;
    return;
  }
}
static void pqdownheap(ct_data *tree, int k) {
  int v;
  int j___0;

  {
    v = heap[k];
    j___0 = k << 1;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(j___0 <= heap_len)) {
          goto while_break;
        }
        if (j___0 < heap_len) {
          if ((int)(tree + heap[j___0 + 1])->fc.freq <
              (int)(tree + heap[j___0])->fc.freq) {
            j___0++;
          } else {
            if ((int)(tree + heap[j___0 + 1])->fc.freq ==
                (int)(tree + heap[j___0])->fc.freq) {
              if ((int)depth[heap[j___0 + 1]] <= (int)depth[heap[j___0]]) {
                j___0++;
              }
            }
          }
        }
        if ((int)(tree + v)->fc.freq < (int)(tree + heap[j___0])->fc.freq) {
          goto while_break;
        } else {
          if ((int)(tree + v)->fc.freq == (int)(tree + heap[j___0])->fc.freq) {
            if ((int)depth[v] <= (int)depth[heap[j___0]]) {
              goto while_break;
            }
          }
        }
        heap[k] = heap[j___0];
        k = j___0;
        j___0 <<= 1;
      }
    while_break: /* CIL Label */
        ;
    }
    heap[k] = v;
    return;
  }
}
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
    base = desc->extra_base;
    max_code = desc->max_code;
    max_length = desc->max_length;
    stree = desc->static_tree;
    overflow = 0;
    bits = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(bits <= 15)) {
          goto while_break;
        }
        bl_count[bits] = (ush)0;
        bits++;
      }
    while_break: /* CIL Label */
        ;
    }
    (tree + heap[heap_max])->dl.len = (ush)0;
    h = heap_max + 1;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(h < 573)) {
          goto while_break___0;
        }
        n = heap[h];
        bits = (int)(tree + (int)(tree + n)->dl.dad)->dl.len + 1;
        if (bits > max_length) {
          bits = max_length;
          overflow++;
        }
        (tree + n)->dl.len = (ush)bits;
        if (n > max_code) {
          goto __Cont;
        }
        bl_count[bits] = (ush)((int)bl_count[bits] + 1);
        xbits = 0;
        if (n >= base) {
          xbits = *(extra + (n - base));
        }
        f = (tree + n)->fc.freq;
        opt_len += (ulg)f * (ulg)(bits + xbits);
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
        bits = max_length - 1;
        {
          while (1) {
          while_continue___2: /* CIL Label */
              ;
            if (!((int)bl_count[bits] == 0)) {
              goto while_break___2;
            }
            bits--;
          }
        while_break___2: /* CIL Label */
            ;
        }
        bl_count[bits] = (ush)((int)bl_count[bits] - 1);
        bl_count[bits + 1] = (ush)((int)bl_count[bits + 1] + 2);
        bl_count[max_length] = (ush)((int)bl_count[max_length] - 1);
        overflow -= 2;
        if (!(overflow > 0)) {
          goto while_break___1;
        }
      }
    while_break___1: /* CIL Label */
        ;
    }
    bits = max_length;
    {
      while (1) {
      while_continue___3: /* CIL Label */
          ;
        if (!(bits != 0)) {
          goto while_break___3;
        }
        n = (int)bl_count[bits];
        {
          while (1) {
          while_continue___4: /* CIL Label */
              ;
            if (!(n != 0)) {
              goto while_break___4;
            }
            h--;
            m = heap[h];
            if (m > max_code) {
              goto while_continue___4;
            }
            if ((unsigned int)(tree + m)->dl.len != (unsigned int)bits) {
              opt_len += (ulg)(((long)bits - (long)(tree + m)->dl.len) *
                               (long)(tree + m)->fc.freq);
              (tree + m)->dl.len = (ush)bits;
            }
            n--;
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
        code = (ush)(((int)code + (int)bl_count[bits - 1]) << 1);
        next_code[bits] = code;
        bits++;
      }
    while_break: /* CIL Label */
        ;
    }
    n = 0;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(n <= max_code)) {
          goto while_break___0;
        }
        len = (int)(tree + n)->dl.len;
        if (len == 0) {
          goto __Cont;
        }
        {
          tmp = next_code[len];
          next_code[len] = (ush)((int)next_code[len] + 1);
          (tree + n)->fc.code = (ush)bi_reverse((unsigned int)tmp, len);
        }
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
  int m;
  int max_code;
  int node;
  int new;
  int tmp;
  int tmp___0;
  int tmp___1;
  ush tmp___2;
  int tmp___3;

  {
    tree = desc->dyn_tree;
    stree = desc->static_tree;
    elems = desc->elems;
    max_code = -1;
    node = elems;
    heap_len = 0;
    heap_max = 573;
    n = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(n < elems)) {
          goto while_break;
        }
        if ((int)(tree + n)->fc.freq != 0) {
          heap_len++;
          max_code = n;
          heap[heap_len] = max_code;
          depth[n] = (uch)0;
        } else {
          (tree + n)->dl.len = (ush)0;
        }
        n++;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(heap_len < 2)) {
          goto while_break___0;
        }
        heap_len++;
        if (max_code < 2) {
          max_code++;
          tmp = max_code;
        } else {
          tmp = 0;
        }
        heap[heap_len] = tmp;
        new = tmp;
        (tree + new)->fc.freq = (ush)1;
        depth[new] = (uch)0;
        opt_len--;
        if (stree) {
          static_len -= (ulg)(stree + new)->dl.len;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    desc->max_code = max_code;
    n = heap_len / 2;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!(n >= 1)) {
          goto while_break___1;
        }
        {
          pqdownheap(tree, n);
          n--;
        }
      }
    while_break___1: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___2: /* CIL Label */
          ;
        {
          n = heap[1];
          tmp___0 = heap_len;
          heap_len--;
          heap[1] = heap[tmp___0];
          pqdownheap(tree, 1);
          m = heap[1];
          heap_max--;
          heap[heap_max] = n;
          heap_max--;
          heap[heap_max] = m;
          (tree + node)->fc.freq =
              (ush)((int)(tree + n)->fc.freq + (int)(tree + m)->fc.freq);
        }
        if ((int)depth[n] >= (int)depth[m]) {
          tmp___1 = (int)depth[n];
        } else {
          tmp___1 = (int)depth[m];
        }
        {
          depth[node] = (uch)(tmp___1 + 1);
          tmp___2 = (ush)node;
          (tree + m)->dl.dad = tmp___2;
          (tree + n)->dl.dad = tmp___2;
          tmp___3 = node;
          node++;
          heap[1] = tmp___3;
          pqdownheap(tree, 1);
        }
        if (!(heap_len >= 2)) {
          goto while_break___2;
        }
      }
    while_break___2: /* CIL Label */
        ;
    }
    {
      heap_max--;
      heap[heap_max] = heap[1];
      gen_bitlen(desc);
      gen_codes(tree, max_code);
    }
    return;
  }
}
static void scan_tree(ct_data *tree, int max_code) {
  int n;
  int prevlen;
  int curlen;
  int nextlen;
  int count;
  int max_count;
  int min_count;

  {
    prevlen = -1;
    nextlen = (int)(tree + 0)->dl.len;
    count = 0;
    max_count = 7;
    min_count = 4;
    if (nextlen == 0) {
      max_count = 138;
      min_count = 3;
    }
    (tree + (max_code + 1))->dl.len = (ush)65535;
    n = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(n <= max_code)) {
          goto while_break;
        }
        curlen = nextlen;
        nextlen = (int)(tree + (n + 1))->dl.len;
        count++;
        if (count < max_count) {
          if (curlen == nextlen) {
            goto __Cont;
          } else {
            goto _L;
          }
        } else {
        _L:
          if (count < min_count) {
            bl_tree[curlen].fc.freq =
                (ush)((int)bl_tree[curlen].fc.freq + count);
          } else {
            if (curlen != 0) {
              if (curlen != prevlen) {
                bl_tree[curlen].fc.freq =
                    (ush)((int)bl_tree[curlen].fc.freq + 1);
              }
              bl_tree[16].fc.freq = (ush)((int)bl_tree[16].fc.freq + 1);
            } else {
              if (count <= 10) {
                bl_tree[17].fc.freq = (ush)((int)bl_tree[17].fc.freq + 1);
              } else {
                bl_tree[18].fc.freq = (ush)((int)bl_tree[18].fc.freq + 1);
              }
            }
          }
        }
        count = 0;
        prevlen = curlen;
        if (nextlen == 0) {
          max_count = 138;
          min_count = 3;
        } else {
          if (curlen == nextlen) {
            max_count = 6;
            min_count = 3;
          } else {
            max_count = 7;
            min_count = 4;
          }
        }
      __Cont:
        n++;
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static void send_tree(ct_data *tree, int max_code) {
  int n;
  int prevlen;
  int curlen;
  int nextlen;
  int count;
  int max_count;
  int min_count;

  {
    prevlen = -1;
    nextlen = (int)(tree + 0)->dl.len;
    count = 0;
    max_count = 7;
    min_count = 4;
    if (nextlen == 0) {
      max_count = 138;
      min_count = 3;
    }
    n = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(n <= max_code)) {
          goto while_break;
        }
        curlen = nextlen;
        nextlen = (int)(tree + (n + 1))->dl.len;
        count++;
        if (count < max_count) {
          if (curlen == nextlen) {
            goto __Cont;
          } else {
            goto _L;
          }
        } else {
        _L:
          if (count < min_count) {
            {
              while (1) {
              while_continue___0: /* CIL Label */
                  ;
                {
                  send_bits((int)bl_tree[curlen].fc.code,
                            (int)bl_tree[curlen].dl.len);
                  count--;
                }
                if (!(count != 0)) {
                  goto while_break___0;
                }
              }
            while_break___0: /* CIL Label */
                ;
            }
          } else {
            if (curlen != 0) {
              if (curlen != prevlen) {
                {
                  send_bits((int)bl_tree[curlen].fc.code,
                            (int)bl_tree[curlen].dl.len);
                  count--;
                }
              }
              {
                send_bits((int)bl_tree[16].fc.code, (int)bl_tree[16].dl.len);
                send_bits(count - 3, 2);
              }
            } else {
              if (count <= 10) {
                {
                  send_bits((int)bl_tree[17].fc.code, (int)bl_tree[17].dl.len);
                  send_bits(count - 3, 3);
                }
              } else {
                {
                  send_bits((int)bl_tree[18].fc.code, (int)bl_tree[18].dl.len);
                  send_bits(count - 11, 7);
                }
              }
            }
          }
        }
        count = 0;
        prevlen = curlen;
        if (nextlen == 0) {
          max_count = 138;
          min_count = 3;
        } else {
          if (curlen == nextlen) {
            max_count = 6;
            min_count = 3;
          } else {
            max_count = 7;
            min_count = 4;
          }
        }
      __Cont:
        n++;
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
static int build_bl_tree(void) {
  int max_blindex;

  {
    {
      scan_tree(dyn_ltree, l_desc.max_code);
      scan_tree(dyn_dtree, d_desc.max_code);
      build_tree___0(&bl_desc);
      max_blindex = 18;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(max_blindex >= 3)) {
          goto while_break;
        }
        if ((int)bl_tree[bl_order[max_blindex]].dl.len != 0) {
          goto while_break;
        }
        max_blindex--;
      }
    while_break: /* CIL Label */
        ;
    }
    opt_len += (ulg)(((3 * (max_blindex + 1) + 5) + 5) + 4);
    return (max_blindex);
  }
}
static void send_all_trees(int lcodes, int dcodes, int blcodes) {
  int rank;

  {
    {
      send_bits(lcodes - 257, 5);
      send_bits(dcodes - 1, 5);
      send_bits(blcodes - 4, 4);
      rank = 0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(rank < blcodes)) {
          goto while_break;
        }
        {
          send_bits((int)bl_tree[bl_order[rank]].dl.len, 3);
          rank++;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      send_tree(dyn_ltree, lcodes - 1);
      send_tree(dyn_dtree, dcodes - 1);
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
      {
        set_file_type();
      }
    }
    {
      build_tree___0(&l_desc);
      build_tree___0(&d_desc);
      max_blindex = build_bl_tree();
      opt_lenb = ((opt_len + 3UL) + 7UL) >> 3;
      static_lenb = ((static_len + 3UL) + 7UL) >> 3;
      input_len += stored_len;
    }
    if (static_lenb <= opt_lenb) {
      opt_lenb = static_lenb;
    }
    if (stored_len <= opt_lenb) {
      if (eof) {
        if (compressed_len == 0UL) {
          goto _L___2;
        } else {
          goto _L___2;
        }
      } else {
        goto _L___2;
      }
    } else {
    _L___2:
      if (stored_len + 4UL <= opt_lenb) {
        if ((unsigned long)buf != (unsigned long)((char *)0)) {
          {
            send_bits(eof, 3);
            compressed_len =
                ((compressed_len + 3UL) + 7UL) & 0xfffffffffffffff8UL;
            compressed_len += (stored_len + 4UL) << 3;
            copy_block(buf, (unsigned int)stored_len, 1);
          }
        } else {
          goto _L;
        }
      } else {
      _L:
        if (static_lenb == opt_lenb) {
          {
            send_bits((1 << 1) + eof, 3);
            compress_block(static_ltree, static_dtree);
            compressed_len += 3UL + static_len;
          }
        } else {
          {
            send_bits((2 << 1) + eof, 3);
            send_all_trees(l_desc.max_code + 1, d_desc.max_code + 1,
                           max_blindex + 1);
            compress_block(dyn_ltree, dyn_dtree);
            compressed_len += 3UL + opt_len;
          }
        }
      }
    }
    { init_block(); }
    if (eof) {
      {
        bi_windup();
        compressed_len += 7UL;
      }
    }
    return (compressed_len >> 3);
  }
}
int ct_tally(int dist, int lc) {
  unsigned int tmp;
  int tmp___0;
  unsigned int tmp___1;
  unsigned int tmp___2;
  ulg out_length;
  ulg in_length;
  int dcode;
  int tmp___3;

  {
    tmp = last_lit;
    last_lit++;
    inbuf[tmp] = (uch)lc;
    if (dist == 0) {
      dyn_ltree[lc].fc.freq = (ush)((int)dyn_ltree[lc].fc.freq + 1);
    } else {
      dist--;
      dyn_ltree[((int)length_code[lc] + 256) + 1].fc.freq =
          (ush)((int)dyn_ltree[((int)length_code[lc] + 256) + 1].fc.freq + 1);
      if (dist < 256) {
        tmp___0 = (int)dist_code[dist];
      } else {
        tmp___0 = (int)dist_code[256 + (dist >> 7)];
      }
      dyn_dtree[tmp___0].fc.freq = (ush)((int)dyn_dtree[tmp___0].fc.freq + 1);
      tmp___1 = last_dist;
      last_dist++;
      d_buf[tmp___1] = (ush)dist;
      flags = (uch)((int)flags | (int)flag_bit);
    }
    flag_bit = (uch)((int)flag_bit << 1);
    if ((last_lit & 7U) == 0U) {
      tmp___2 = last_flags;
      last_flags++;
      flag_buf[tmp___2] = flags;
      flags = (uch)0;
      flag_bit = (uch)1;
    }
    if (level > 2) {
      if ((last_lit & 4095U) == 0U) {
        out_length = (ulg)last_lit * 8UL;
        in_length = (ulg)strstart - (ulg)block_start;
        dcode = 0;
        {
          while (1) {
          while_continue: /* CIL Label */
              ;
            if (!(dcode < 30)) {
              goto while_break;
            }
            out_length += (ulg)dyn_dtree[dcode].fc.freq *
                          (ulg)(5L + (long)extra_dbits[dcode]);
            dcode++;
          }
        while_break: /* CIL Label */
            ;
        }
        out_length >>= 3;
        if (last_dist < last_lit / 2U) {
          if (out_length < in_length / 2UL) {
            return (1);
          }
        }
      }
    }
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
  uch flag;
  unsigned int code;
  int extra;
  unsigned int tmp;
  unsigned int tmp___0;
  unsigned int tmp___1;

  {
    lx = 0U;
    dx = 0U;
    fx = 0U;
    flag = (uch)0;
    if (last_lit != 0U) {
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if ((lx & 7U) == 0U) {
            tmp = fx;
            fx++;
            flag = flag_buf[tmp];
          }
          tmp___0 = lx;
          lx++;
          lc = (int)inbuf[tmp___0];
          if (((int)flag & 1) == 0) {
            {
              send_bits((int)(ltree + lc)->fc.code, (int)(ltree + lc)->dl.len);
            }
          } else {
            {
              code = (unsigned int)length_code[lc];
              send_bits((int)(ltree + ((code + 256U) + 1U))->fc.code,
                        (int)(ltree + ((code + 256U) + 1U))->dl.len);
              extra = extra_lbits[code];
            }
            if (extra != 0) {
              {
                lc -= base_length[code];
                send_bits(lc, extra);
              }
            }
            tmp___1 = dx;
            dx++;
            dist = (unsigned int)d_buf[tmp___1];
            if (dist < 256U) {
              code = (unsigned int)dist_code[dist];
            } else {
              code = (unsigned int)dist_code[256U + (dist >> 7)];
            }
            {
              send_bits((int)(dtree + code)->fc.code,
                        (int)(dtree + code)->dl.len);
              extra = extra_dbits[code];
            }
            if (extra != 0) {
              {
                dist -= (unsigned int)base_dist[code];
                send_bits((int)dist, extra);
              }
            }
          }
          flag = (uch)((int)flag >> 1);
          if (!(lx < last_lit)) {
            goto while_break;
          }
        }
      while_break: /* CIL Label */
          ;
      }
    }
    { send_bits((int)(ltree + 256)->fc.code, (int)(ltree + 256)->dl.len); }
    return;
  }
}
static void set_file_type(void) {
  int n;
  unsigned int ascii_freq;
  unsigned int bin_freq;
  int tmp;
  int tmp___0;
  int tmp___1;

  {
    n = 0;
    ascii_freq = 0U;
    bin_freq = 0U;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(n < 7)) {
          goto while_break;
        }
        tmp = n;
        n++;
        bin_freq += (unsigned int)dyn_ltree[tmp].fc.freq;
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
        tmp___0 = n;
        n++;
        ascii_freq += (unsigned int)dyn_ltree[tmp___0].fc.freq;
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
        tmp___1 = n;
        n++;
        bin_freq += (unsigned int)dyn_ltree[tmp___1].fc.freq;
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
ulg deflate(void);
ulg window_size = 65536UL;
static unsigned int ins_h;
unsigned int prev_length;
unsigned int match_start;
static int eofile;
static unsigned int lookahead;
unsigned int max_chain_length;
static unsigned int max_lazy_match;
static int compr_level;
unsigned int good_match;
int nice_match;
static config configuration_table[10] = {
    {(ush)0, (ush)0, (ush)0, (ush)0},
    {(ush)4, (ush)4, (ush)8, (ush)4},
    {(ush)4, (ush)5, (ush)16, (ush)8},
    {(ush)4, (ush)6, (ush)32, (ush)32},
    {(ush)4, (ush)4, (ush)16, (ush)16},
    {(ush)8, (ush)16, (ush)32, (ush)32},
    {(ush)8, (ush)16, (ush)128, (ush)128},
    {(ush)8, (ush)32, (ush)128, (ush)256},
    {(ush)32, (ush)128, (ush)258, (ush)1024},
    {(ush)32, (ush)258, (ush)258, (ush)4096}};
static void fill_window(void);
static ulg deflate_fast(void);
int longest_match(IPos cur_match);
void lm_init(int pack_level, ush *flags___0) {
  register unsigned int j___0;
  unsigned int tmp;
  char *__cil_tmp6;
  char *__cil_tmp7;

  {
    if (pack_level < 1) {
      {
        error((char *)"bad pack level");
      }
    } else {
      if (pack_level > 9) {
        {
          error((char *)"bad pack level");
        }
      }
    }
    {
      compr_level = pack_level;
      memset((voidp)((char *)(prev + 32768)), 0,
             (unsigned long)((unsigned int)(1 << 15)) *
                 sizeof(*(prev + 32768)));
      max_lazy_match = (unsigned int)configuration_table[pack_level].max_lazy;
      good_match = (unsigned int)configuration_table[pack_level].good_length;
      nice_match = (int)configuration_table[pack_level].nice_length;
      max_chain_length =
          (unsigned int)configuration_table[pack_level].max_chain;
    }
    if (pack_level == 1) {
      *flags___0 = (ush)((int)*flags___0 | 4);
    } else {
      if (pack_level == 9) {
        *flags___0 = (ush)((int)*flags___0 | 2);
      }
    }
    strstart = 0U;
    block_start = 0L;
    if (sizeof(int) <= 2UL) {
      tmp = 32768U;
    } else {
      tmp = 65536U;
    }
    { lookahead = (unsigned int)(*read_buf)((char *)(window), tmp); }
    if (lookahead == 0U) {
      eofile = 1;
      lookahead = 0U;
      return;
    } else {
      if (lookahead == 4294967295U) {
        eofile = 1;
        lookahead = 0U;
        return;
      }
    }
    eofile = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (lookahead < 262U) {
          if (!(!eofile)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
        { fill_window(); }
      }
    while_break: /* CIL Label */
        ;
    }
    ins_h = 0U;
    j___0 = 0U;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(j___0 < 2U)) {
          goto while_break___0;
        }
        ins_h = ((ins_h << 5) ^ (unsigned int)window[j___0]) &
                ((unsigned int)(1 << 15) - 1U);
        j___0++;
      }
    while_break___0: /* CIL Label */
        ;
    }
    return;
  }
}
int longest_match(IPos cur_match) {
  unsigned int chain_length;
  register uch *scan;
  register uch *match;
  register int len;
  int best_len;
  IPos limit;
  unsigned int tmp;
  register uch *strend;
  register uch scan_end1;
  register uch scan_end;

  {
    chain_length = max_chain_length;
    scan = window + strstart;
    best_len = (int)prev_length;
    if (strstart > 32506U) {
      tmp = strstart - 32506U;
    } else {
      tmp = 0U;
    }
    limit = tmp;
    strend = (window + strstart) + 258;
    scan_end1 = *(scan + (best_len - 1));
    scan_end = *(scan + best_len);
    if (prev_length >= good_match) {
      chain_length >>= 2;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        match = window + cur_match;
        if ((int)*(match + best_len) != (int)scan_end) {
          goto __Cont;
        } else {
          if ((int)*(match + (best_len - 1)) != (int)scan_end1) {
            goto __Cont;
          } else {
            if ((int)*match != (int)*scan) {
              goto __Cont;
            } else {
              match++;
              if ((int)*match != (int)*(scan + 1)) {
                goto __Cont;
              }
            }
          }
        }
        scan += 2;
        match++;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            scan++;
            match++;
            if ((int)*scan == (int)*match) {
              scan++;
              match++;
              if ((int)*scan == (int)*match) {
                scan++;
                match++;
                if ((int)*scan == (int)*match) {
                  scan++;
                  match++;
                  if ((int)*scan == (int)*match) {
                    scan++;
                    match++;
                    if ((int)*scan == (int)*match) {
                      scan++;
                      match++;
                      if ((int)*scan == (int)*match) {
                        scan++;
                        match++;
                        if ((int)*scan == (int)*match) {
                          scan++;
                          match++;
                          if ((int)*scan == (int)*match) {
                            if (!((unsigned long)scan <
                                  (unsigned long)strend)) {
                              goto while_break___0;
                            }
                          } else {
                            goto while_break___0;
                          }
                        } else {
                          goto while_break___0;
                        }
                      } else {
                        goto while_break___0;
                      }
                    } else {
                      goto while_break___0;
                    }
                  } else {
                    goto while_break___0;
                  }
                } else {
                  goto while_break___0;
                }
              } else {
                goto while_break___0;
              }
            } else {
              goto while_break___0;
            }
          }
        while_break___0: /* CIL Label */
            ;
        }
        len = 258 - (int)(strend - scan);
        scan = strend - 258;
        if (len > best_len) {
          match_start = cur_match;
          best_len = len;
          if (len >= nice_match) {
            goto while_break;
          }
          scan_end1 = *(scan + (best_len - 1));
          scan_end = *(scan + best_len);
        }
      __Cont:
        cur_match = (IPos)prev[cur_match & 32767U];
        if (cur_match > limit) {
          chain_length--;
          if (!(chain_length != 0U)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return (best_len);
  }
}
static void fill_window(void) {
  register unsigned int n;
  register unsigned int m;
  unsigned int more;
  unsigned int tmp;
  unsigned int tmp___0;

  {
    more = (unsigned int)((window_size - (ulg)lookahead) - (ulg)strstart);
    if (more == 4294967295U) {
      more--;
    } else {
      if (strstart >= 65274U) {
        {
          memcpy((void * /* __restrict  */)((char *)(window)),
                 (void const * /* __restrict  */)((char *)(window) + 32768),
                 (size_t)32768U);
          match_start -= 32768U;
          strstart -= 32768U;
          block_start -= 32768L;
          n = 0U;
        }
        {
          while (1) {
          while_continue: /* CIL Label */
              ;
            if (!(n < (unsigned int)(1 << 15))) {
              goto while_break;
            }
            m = (unsigned int)*((prev + 32768) + n);
            if (m >= 32768U) {
              tmp = m - 32768U;
            } else {
              tmp = 0U;
            }
            *((prev + 32768) + n) = (Pos)tmp;
            n++;
          }
        while_break: /* CIL Label */
            ;
        }
        n = 0U;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            if (!(n < 32768U)) {
              goto while_break___0;
            }
            m = (unsigned int)prev[n];
            if (m >= 32768U) {
              tmp___0 = m - 32768U;
            } else {
              tmp___0 = 0U;
            }
            prev[n] = (Pos)tmp___0;
            n++;
          }
        while_break___0: /* CIL Label */
            ;
        }
        more += 32768U;
      }
    }
    if (!eofile) {
      {
        n = (unsigned int)(*read_buf)(((char *)(window) + strstart) + lookahead,
                                      more);
      }
      if (n == 0U) {
        eofile = 1;
      } else {
        if (n == 4294967295U) {
          eofile = 1;
        } else {
          lookahead += n;
        }
      }
    }
    return;
  }
}

ulg deflate(void) {
  IPos hash_head;
  IPos prev_match;
  int flush;
  int match_available;
  register unsigned int match_length;
  ulg tmp;
  char *tmp___0;
  char *tmp___1;
  int tmp___2;
  char *tmp___3;
  ulg tmp___4;

  {
    match_available = 0;
    match_length = 2U;

    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(lookahead != 0U)) {
          goto while_break;
        }
        ins_h = ((ins_h << 5) ^ (unsigned int)window[(strstart + 3U) - 1U]) &
                ((unsigned int)(1 << 15) - 1U);
        hash_head = (IPos) * ((prev + 32768) + ins_h);
        prev[strstart & 32767U] = (ush)hash_head;
        *((prev + 32768) + ins_h) = (ush)strstart;
        prev_length = match_length;
        prev_match = match_start;
        match_length = 2U;
        if (hash_head != 0U) {
          if (prev_length < max_lazy_match) {
            if (strstart - hash_head <= 32506U) {
              {
                match_length = (unsigned int)longest_match(hash_head);
              }
              if (match_length > lookahead) {
                match_length = lookahead;
              }
              if (match_length == 3U) {
                if (strstart - match_start > 4096U) {
                  match_length--;
                }
              }
            }
          }
        }
        if (prev_length >= 3U) {
          if (match_length <= prev_length) {
            {
              flush = ct_tally((int)((strstart - 1U) - prev_match),
                               (int)(prev_length - 3U));
              lookahead -= prev_length - 1U;
              prev_length -= 2U;
            }
            {
              while (1) {
              while_continue___0: /* CIL Label */
                  ;
                strstart++;
                ins_h = ((ins_h << 5) ^
                         (unsigned int)window[(strstart + 3U) - 1U]) &
                        ((unsigned int)(1 << 15) - 1U);
                hash_head = (IPos) * ((prev + 32768) + ins_h);
                prev[strstart & 32767U] = (ush)hash_head;
                *((prev + 32768) + ins_h) = (ush)strstart;
                prev_length--;
                if (!(prev_length != 0U)) {
                  goto while_break___0;
                }
              }
            while_break___0: /* CIL Label */
                ;
            }
            match_available = 0;
            match_length = 2U;
            strstart++;
            if (flush) {
              if (block_start >= 0L) {
                tmp___0 = (char *)(&window[(unsigned int)block_start]);
              } else {
                tmp___0 = (char *)((void *)0);
              }
              {
                flush_block(tmp___0, (ulg)((long)strstart - block_start), 0);
                block_start = (long)strstart;
              }
            }
          } else {
            goto _L;
          }
        } else {
        _L:
          if (match_available) {
            {
              tmp___2 = ct_tally(0, (int)window[strstart - 1U]);
            }
            if (tmp___2) {
              if (block_start >= 0L) {
                tmp___1 = (char *)(&window[(unsigned int)block_start]);
              } else {
                tmp___1 = (char *)((void *)0);
              }
              {
                flush_block(tmp___1, (ulg)((long)strstart - block_start), 0);
                block_start = (long)strstart;
              }
            }
            strstart++;
            lookahead--;
          } else {
            match_available = 1;
            strstart++;
            lookahead--;
          }
        }
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            if (lookahead < 262U) {
              if (!(!eofile)) {
                goto while_break___1;
              }
            } else {
              goto while_break___1;
            }
            { fill_window(); }
          }
        while_break___1: /* CIL Label */
            ;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if (match_available) {
      {
        ct_tally(0, (int)window[strstart - 1U]);
      }
    }
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
int zip(int in, int out);
static ulg crc___0;
int zip(int in, int out) {
  uch flags___0;
  ush attr;
  ush deflate_flags;
  unsigned int tmp;
  unsigned int tmp___0;
  unsigned int tmp___1;
  unsigned int tmp___2;
  unsigned int tmp___3;
  unsigned int tmp___4;
  unsigned int tmp___5;
  unsigned int tmp___6;
  unsigned int tmp___7;
  unsigned int tmp___8;
  unsigned int tmp___9;
  unsigned int tmp___10;
  unsigned int tmp___11;
  unsigned int tmp___12;
  char *p;
  char *tmp___13;
  unsigned int tmp___14;
  char *tmp___15;
  unsigned int tmp___16;
  unsigned int tmp___17;
  unsigned int tmp___18;
  unsigned int tmp___19;
  unsigned int tmp___20;
  unsigned int tmp___21;
  unsigned int tmp___22;
  unsigned int tmp___23;
  unsigned int tmp___24;
  unsigned int tmp___25;
  unsigned int tmp___26;
  unsigned int tmp___27;
  unsigned int tmp___28;
  unsigned int tmp___29;
  unsigned int tmp___30;
  unsigned int tmp___31;
  char *__cil_tmp40;
  char *__cil_tmp41;

  {
    flags___0 = (uch)0;
    attr = (ush)0;
    deflate_flags = (ush)0;
    ifd = in;
    ofd = out;
    outcnt = 0U;
    method = 8;
    tmp = outcnt;
    outcnt++;
    outbuf[tmp] = (uch) * ("\037\213" + 0);
    if (outcnt == 16384U) {
      {
        flush_outbuf();
      }
    }
    tmp___0 = outcnt;
    outcnt++;
    outbuf[tmp___0] = (uch) * ("\037\213" + 1);
    if (outcnt == 16384U) {
      {
        flush_outbuf();
      }
    }
    tmp___1 = outcnt;
    outcnt++;
    outbuf[tmp___1] = (uch)8;
    if (outcnt == 16384U) {
      {
        flush_outbuf();
      }
    }
    if (save_orig_name) {
      flags___0 = (uch)((int)flags___0 | 8);
    }
    tmp___2 = outcnt;
    outcnt++;
    outbuf[tmp___2] = flags___0;
    if (outcnt == 16384U) {
      {
        flush_outbuf();
      }
    }
    if (outcnt < 16382U) {
      tmp___3 = outcnt;
      outcnt++;
      outbuf[tmp___3] = (uch)((time_stamp & 65535L) & 255L);
      tmp___4 = outcnt;
      outcnt++;
      outbuf[tmp___4] = (uch)((int)((ush)(time_stamp & 65535L)) >> 8);
    } else {
      tmp___5 = outcnt;
      outcnt++;
      outbuf[tmp___5] = (uch)((time_stamp & 65535L) & 255L);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
      tmp___6 = outcnt;
      outcnt++;
      outbuf[tmp___6] = (uch)((int)((ush)(time_stamp & 65535L)) >> 8);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
    }
    if (outcnt < 16382U) {
      tmp___7 = outcnt;
      outcnt++;
      outbuf[tmp___7] = (uch)(((ulg)time_stamp >> 16) & 255UL);
      tmp___8 = outcnt;
      outcnt++;
      outbuf[tmp___8] = (uch)((int)((ush)((ulg)time_stamp >> 16)) >> 8);
    } else {
      tmp___9 = outcnt;
      outcnt++;
      outbuf[tmp___9] = (uch)(((ulg)time_stamp >> 16) & 255UL);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
      tmp___10 = outcnt;
      outcnt++;
      outbuf[tmp___10] = (uch)((int)((ush)((ulg)time_stamp >> 16)) >> 8);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
    }
    {
      crc___0 = updcrc((uch *)0, 0U);
      bi_init(out);
      ct_init(&attr, &method);
      lm_init(level, &deflate_flags);
      tmp___11 = outcnt;
      outcnt++;
      outbuf[tmp___11] = (uch)deflate_flags;
    }
    if (outcnt == 16384U) {
      {
        flush_outbuf();
      }
    }
    tmp___12 = outcnt;
    outcnt++;
    outbuf[tmp___12] = (uch)3;
    if (outcnt == 16384U) {
      {
        flush_outbuf();
      }
    }

    {
      header_bytes = (long)outcnt;
      deflate();
    }
    if (outcnt < 16382U) {
      tmp___16 = outcnt;
      outcnt++;
      outbuf[tmp___16] = (uch)((crc___0 & 65535UL) & 255UL);
      tmp___17 = outcnt;
      outcnt++;
      outbuf[tmp___17] = (uch)((int)((ush)(crc___0 & 65535UL)) >> 8);
    } else {
      tmp___18 = outcnt;
      outcnt++;
      outbuf[tmp___18] = (uch)((crc___0 & 65535UL) & 255UL);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
      tmp___19 = outcnt;
      outcnt++;
      outbuf[tmp___19] = (uch)((int)((ush)(crc___0 & 65535UL)) >> 8);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
    }
    if (outcnt < 16382U) {
      tmp___20 = outcnt;
      outcnt++;
      outbuf[tmp___20] = (uch)((crc___0 >> 16) & 255UL);
      tmp___21 = outcnt;
      outcnt++;
      outbuf[tmp___21] = (uch)((int)((ush)(crc___0 >> 16)) >> 8);
    } else {
      tmp___22 = outcnt;
      outcnt++;
      outbuf[tmp___22] = (uch)((crc___0 >> 16) & 255UL);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
      tmp___23 = outcnt;
      outcnt++;
      outbuf[tmp___23] = (uch)((int)((ush)(crc___0 >> 16)) >> 8);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
    }
    if (outcnt < 16382U) {
      tmp___24 = outcnt;
      outcnt++;
      outbuf[tmp___24] = (uch)((bytes_in & 65535L) & 255L);
      tmp___25 = outcnt;
      outcnt++;
      outbuf[tmp___25] = (uch)((int)((ush)(bytes_in & 65535L)) >> 8);
    } else {
      tmp___26 = outcnt;
      outcnt++;
      outbuf[tmp___26] = (uch)((bytes_in & 65535L) & 255L);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
      tmp___27 = outcnt;
      outcnt++;
      outbuf[tmp___27] = (uch)((int)((ush)(bytes_in & 65535L)) >> 8);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
    }
    if (outcnt < 16382U) {
      tmp___28 = outcnt;
      outcnt++;
      outbuf[tmp___28] = (uch)(((ulg)bytes_in >> 16) & 255UL);
      tmp___29 = outcnt;
      outcnt++;
      outbuf[tmp___29] = (uch)((int)((ush)((ulg)bytes_in >> 16)) >> 8);
    } else {
      tmp___30 = outcnt;
      outcnt++;
      outbuf[tmp___30] = (uch)(((ulg)bytes_in >> 16) & 255UL);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
      tmp___31 = outcnt;
      outcnt++;
      outbuf[tmp___31] = (uch)((int)((ush)((ulg)bytes_in >> 16)) >> 8);
      if (outcnt == 16384U) {
        {
          flush_outbuf();
        }
      }
    }
    {
      header_bytes = (long)((unsigned long)header_bytes + 2UL * sizeof(long));
      flush_outbuf();
    }
    return (0);
  }
}
int file_read(char *buf, unsigned int size) {
  unsigned int len;

  {
    { len = (unsigned int)read(ifd, (void *)buf, (size_t)size); }
    if (len == 4294967295U) {
      return ((int)len);
    } else {
      if (len == 0U) {
        return ((int)len);
      }
    }
    {
      crc___0 = updcrc((uch *)buf, len);
      bytes_in = (long)((ulg)bytes_in + (ulg)len);
    }
    return ((int)len);
  }
}

extern __attribute__((__nothrow__))
__sighandler_t(__attribute__((__leaf__)) signal)(int __sig,
                                                 void (*__handler)(int));
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file,
                                        struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(2), __leaf__)) fstat)(int __fd, struct stat *__buf);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file,
                                         struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) chmod)(char const *__file, __mode_t __mode);
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern int fflush(FILE *__stream);
extern int printf(char const *__restrict __format, ...);
extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(
    FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2,
                                          size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) strncpy)(
    char *__restrict __dest, char const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcat)(char *__restrict __dest,
                                          char const *__restrict __src);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2),
                                                       __leaf__)) strncmp)(
    char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
long ifile_size;
int verbose;
extern char *optarg;
extern int optind;
extern int getopt_long(int argc, char *const *argv, char const *shortopts,
                       struct option const *longopts, int *longind);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) ctime)(
    time_t const *__timer);
extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag, ...);
extern __attribute__((__nothrow__))
__off_t(__attribute__((__leaf__)) lseek)(int __fd, __off_t __offset,
                                         int __whence);
extern int close(int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) chown)(char const *__file, __uid_t __owner,
                                      __gid_t __group);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) isatty)(
    int __fd);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) unlink)(char const *__name);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1), __leaf__)) atoi)(char const *__nptr)
    __attribute__((__pure__));
extern __attribute__((__nothrow__, __noreturn__)) void(
    __attribute__((__leaf__)) exit)(int __status);
extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) utime)(char const *__file,
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
int quiet = 0;
int do_lzw = 0;
int test = 0;
int foreground;
int maxbits = 16;
int method = 8;
int level = 6;
int exit_code = 0;
int last_member;
int part_nb;
char *env;
char **args = (char **)((void *)0);
char z_suffix[31];
int z_len;
long total_in = 0L;
long total_out = 0L;
int remove_ofname = 0;
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
static void license(void);
static void version(void);
static void treat_stdin(void);
static void treat_file(char *iname);
static int create_outfile(void);
static int do_stat(char *name, struct stat *sbuf);
static char *get_suffix(char *name);
static int get_istat(char *iname, struct stat *sbuf);
static int make_ofname(void);
static int same_file(struct stat *stat1, struct stat *stat2);
static int name_too_long(char *name, struct stat *statb);
static void shorten_name(char *name);
static int get_method(int in);
static void do_list(int ifd___0, int method___0);
static int check_ofname(void);
static void copy_stat(struct stat *ifstat);
static void do_exit(int exitcode);
int main(int argc, char **argv);
int (*work)(int infile, int outfile) = &zip;
static void treat_dir(char *dir);
static void reset_times(char *name, struct stat *statb);
static void usage(void) {

  {
    {}
    return;
  }
}

int main(int argc, char **argv) {
  int file_count;
  int proglen;
  int optc;
  int tmp;
  void (*tmp___0)(int);
  void (*tmp___1)(int);
  void (*tmp___2)(int);
  int tmp___3;
  int tmp___4;
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

    { env = add_envopt(&argc, &argv, (char *)"GZIP"); }

    {
      tmp___0 = signal(2, (void (*)(int))1);
      foreground = (unsigned long)tmp___0 != (unsigned long)((void (*)(int))1);
    }
    if (foreground) {
      {
        signal(2, (void (*)(int))(&abort_gzip));
      }
    }
    { tmp___1 = signal(15, (void (*)(int))1); }
    if ((unsigned long)tmp___1 != (unsigned long)((void (*)(int))1)) {
      {
        signal(15, (void (*)(int))(&abort_gzip));
      }
    }
    { tmp___2 = signal(1, (void (*)(int))1); }
    if ((unsigned long)tmp___2 != (unsigned long)((void (*)(int))1)) {
      {
        signal(1, (void (*)(int))(&abort_gzip));
      }
    }
    { tmp___5 = strncmp((char const *)progname, "un", (size_t)2); }

    {
      strncpy((char * /* __restrict  */)(z_suffix),
              (char const * /* __restrict  */) ".gz", sizeof(z_suffix) - 1UL);
      z_len = (int)strlen((char const *)(z_suffix));
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          optc = getopt_long(argc, (char *const *)argv,
                             "ab:cdfhH?lLmMnNqrS:tvVZ123456789",
                             (struct option const *)(longopts), (int *)0);
        }
        if (!(optc != -1)) {
          goto while_break;
        }
        {

          if (optc == 98) {
            goto case_98;
          }
          if (optc == 99) {
            goto case_99;
          }

          if (optc == 109) {
            goto case_109;
          }

          if (optc == 90) {
            goto case_90;
          }

          if (optc == 50) {
            goto case_49;
          }

          if (optc == 52) {
            goto case_49;
          }

          if (optc == 57) {
            goto case_49;
          }
          goto switch_default;
        case_97: /* CIL Label */
          ascii = 1;
          goto switch_break;
        case_98: { /* CIL Label */
          maxbits = atoi((char const *)optarg);
        }
          goto switch_break;
        case_99: /* CIL Label */
          to_stdout = 1;
          goto switch_break;
        case_100: /* CIL Label */
          decompress = 1;
          goto switch_break;
        case_102: /* CIL Label */
          force++;
          goto switch_break;
        case_104:  /* CIL Label */
        case_72:   /* CIL Label */
        case_63: { /* CIL Label */
          help();
          do_exit(0);
        }
          goto switch_break;
        case_108: /* CIL Label */
          to_stdout = 1;
          decompress = to_stdout;
          list = decompress;
          goto switch_break;
        case_76: { /* CIL Label */
          license();
          do_exit(0);
        }
          goto switch_break;
        case_109: /* CIL Label */
          no_time = 1;
          goto switch_break;
        case_77: /* CIL Label */
          no_time = 0;
          goto switch_break;
        case_110: /* CIL Label */
          no_time = 1;
          no_name = no_time;
          goto switch_break;
        case_78: /* CIL Label */
          no_time = 0;
          no_name = no_time;
          goto switch_break;
        case_113: /* CIL Label */
          quiet = 1;
          verbose = 0;
          goto switch_break;
        case_114: /* CIL Label */
          recursive = 1;
          goto switch_break;
        case_83: { /* CIL Label */
          z_len = (int)strlen((char const *)optarg);
          strcpy((char * /* __restrict  */)(z_suffix),
                 (char const * /* __restrict  */)optarg);
        }
          goto switch_break;
        case_116: /* CIL Label */
          to_stdout = 1;
          decompress = to_stdout;
          test = decompress;
          goto switch_break;
        case_118: /* CIL Label */
          verbose++;
          quiet = 0;
          goto switch_break;
        case_86: { /* CIL Label */
          version();
          do_exit(0);
        }
          goto switch_break;
        case_90: { /* CIL Label */

          usage();
          do_exit(1);
        }
          goto switch_break;
        case_49: /* CIL Label */
        case_50: /* CIL Label */
        case_51: /* CIL Label */
        case_52: /* CIL Label */
        case_53: /* CIL Label */
        case_54: /* CIL Label */
        case_55: /* CIL Label */
        case_56: /* CIL Label */
        case_57: /* CIL Label */
          level = optc - 48;
          goto switch_break;
        switch_default: { /* CIL Label */
          usage();
          do_exit(1);
        }
        switch_break: /* CIL Label */
            ;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if (no_time < 0) {
      no_time = decompress;
    }

    file_count = argc - optind;

    if (z_len == 0) {

    } else {
    _L:
      if (z_len > 30) {
        {
          fprintf(
              (FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "%s: incorrect suffix \'%s\'\n",
              progname, optarg);
          do_exit(1);
        }
      }
    }
    if (do_lzw) {
      if (!decompress) {
        work = &lzw;
      }
    }
    if (file_count != 0) {
      if (to_stdout) {
        if (!test) {
          if (!list) {

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
      { treat_stdin(); }
    }

    { do_exit(exit_code); }
    return (exit_code);
  }
}
static void treat_stdin(void) {
  char const *tmp;
  char const *tmp___0;
  struct _IO_FILE *tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  char *__cil_tmp13;
  char *__cil_tmp14;
  char *__cil_tmp15;
  char *__cil_tmp16;
  char *__cil_tmp17;
  char *__cil_tmp18;
  char *__cil_tmp19;

  {
    if (!force) {
    }
    if (decompress) {
      tmp___4 = 1;
    } else {
      if (!ascii) {
        tmp___4 = 1;
      } else {
        tmp___4 = 0;
      }
    }
    if (!test) {
      if (!list) {
        if (!decompress) {
          tmp___5 = 1;
        } else {
          if (!ascii) {
            tmp___5 = 1;
          } else {
            tmp___5 = 0;
          }
        }
      } else {
        tmp___5 = 0;
      }
    } else {
      tmp___5 = 0;
    }
    {
      strcpy((char * /* __restrict  */)(ifname),
             (char const * /* __restrict  */) "stdin");
      strcpy((char * /* __restrict  */)(ofname),
             (char const * /* __restrict  */) "stdout");
      time_stamp = 0L;
    }

    {
      ifile_size = -1L;
      clear_bufs();
      to_stdout = 1;
      part_nb = 0;
    }

    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          tmp___8 = fileno(stdout);
          tmp___9 = fileno(stdin);
          tmp___10 = (*work)(tmp___9, tmp___8);
        }
        if (tmp___10 != 0) {
          return;
        }
        if (!decompress) {
          goto while_break;
        } else {
          if (last_member) {
            goto while_break;
          } else {
            if (inptr == insize) {
              goto while_break;
            }
          }
        }
        { method = get_method(ifd); }
        if (method < 0) {
          return;
        }
        bytes_out = 0L;
      }
    while_break: /* CIL Label */
        ;
    }

    return;
  }
}
static void treat_file(char *iname) {
  int cflag;
  int tmp;
  int tmp___0;
  struct stat st;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  char const *tmp___7;
  size_t tmp___8;
  char const *tmp___9;
  size_t tmp___10;
  int tmp___11;
  int tmp___12;
  void *__cil_tmp16;
  char *__cil_tmp17;
  char *__cil_tmp18;
  char *__cil_tmp19;
  char *__cil_tmp20;

  {
    { tmp = strcmp((char const *)iname, "-"); }
    if (tmp == 0) {
      {
        cflag = to_stdout;
        treat_stdin();
        to_stdout = cflag;
      }
      return;
    }
    { tmp___0 = get_istat(iname, &istat); }
    if (tmp___0 != 0) {
      return;
    }

    if (!((istat.st_mode & 61440U) == 32768U)) {
      if (!quiet) {
        {
        }
      }

      return;
    }
    if (istat.st_nlink > 1UL) {
      if (!to_stdout) {
        if (!force) {
          if (!quiet) {

            {
              fprintf((FILE * /* __restrict  */)stderr,
                      (char const * /* __restrict  */) "%s: %s has %d other "
                                                       "link%c -- unchanged\n",
                      progname, ifname, (int)istat.st_nlink - 1, tmp___1);
            }
          }
          if (exit_code == 0) {
            exit_code = 2;
          }
          return;
        }
      }
    }
    ifile_size = istat.st_size;
    if (no_time) {
      if (!list) {
        time_stamp = 0L;
      } else {
        time_stamp = istat.st_mtim.tv_sec;
      }
    } else {
      time_stamp = istat.st_mtim.tv_sec;
    }
    if (to_stdout) {

    } else {
    _L___0: { tmp___2 = make_ofname(); }
      if (tmp___2 != 0) {
        return;
      }
    }
    if (ascii) {

    } else {
      tmp___3 = 0;
    }
    { ifd = open((char const *)(ifname), tmp___3, 384); }
    if (ifd == -1) {
      {
        fprintf((FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "%s: ", progname);
        perror((char const *)(ifname));
        exit_code = 1;
      }
      return;
    }
    {
      clear_bufs();
      part_nb = 0;
    }
    if (decompress) {
      {
        method = get_method(ifd);
      }
      if (method < 0) {
        {
          close(ifd);
        }
        return;
      }
    }

    if (to_stdout) {
      {
        ofd = fileno(stdout);
      }
    } else {
      { tmp___4 = create_outfile(); }
      if (tmp___4 != 0) {
        return;
      }
    }
    if (!save_orig_name) {
      save_orig_name = !no_name;
    }

    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { tmp___11 = (*work)(ifd, ofd); }
        if (tmp___11 != 0) {
          method = -1;
          goto while_break;
        }
        if (!decompress) {
          goto while_break;
        } else {
          if (last_member) {
            goto while_break;
          } else {
            if (inptr == insize) {
              goto while_break;
            }
          }
        }
        { method = get_method(ifd); }
        if (method < 0) {
          goto while_break;
        }
        bytes_out = 0L;
      }
    while_break: /* CIL Label */
        ;
    }
    { close(ifd); }
    if (!to_stdout) {
      {
        tmp___12 = close(ofd);
      }
      if (tmp___12) {
        {
          write_error();
        }
      }
    }
    if (method == -1) {
      if (!to_stdout) {
        {
          unlink((char const *)(ofname));
        }
      }
      return;
    }

    if (!to_stdout) {
      {
        copy_stat(&istat);
      }
    }
    return;
  }
}
static int create_outfile(void) {
  struct stat ostat;
  int flags___0;
  int tmp;
  int tmp___0;
  int tmp___1;
  void *__cil_tmp6;

  {
    flags___0 = 193;

    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { tmp = check_ofname(); }
        if (tmp != 0) {
          {
            close(ifd);
          }
          return (1);
        }
        {
          remove_ofname = 1;
          ofd = open((char const *)(ofname), flags___0, 384);
        }
        if (ofd == -1) {
          {
            perror((char const *)(ofname));
            close(ifd);
            exit_code = 1;
          }
          return (1);
        }
        { tmp___0 = fstat(ofd, &ostat); }
        if (tmp___0 != 0) {
          {
            fprintf((FILE * /* __restrict  */)stderr,
                    (char const * /* __restrict  */) "%s: ", progname);
            perror((char const *)(ofname));
            close(ifd);
            close(ofd);
            unlink((char const *)(ofname));
            exit_code = 1;
          }
          return (1);
        }
        { tmp___1 = name_too_long(ofname, &ostat); }
        if (!tmp___1) {
          return (0);
        }
        if (decompress) {
          if (!quiet) {
            {
              fprintf(
                  (FILE * /* __restrict  */)stderr,
                  (char const
                       * /* __restrict  */) "%s: %s: warning, name truncated\n",
                  progname, ofname);
            }
          }

          return (0);
        }
        {
          close(ofd);
          unlink((char const *)(ofname));
          shorten_name(ofname);
        }
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
static int do_stat(char *name, struct stat *sbuf) {
  int *tmp;
  int tmp___0;
  int tmp___1;

  {
    {
      tmp = __errno_location();
      *tmp = 0;
    }
    if (!to_stdout) {
      if (!force) {
        {
          tmp___0 = lstat((char const * /* __restrict  */)name,
                          (struct stat * /* __restrict  */)sbuf);
        }
        return (tmp___0);
      }
    }
    {
      tmp___1 = stat((char const * /* __restrict  */)name,
                     (struct stat * /* __restrict  */)sbuf);
    }
    return (tmp___1);
  }
}
static char *known_suffixes[9] = {
    z_suffix,       (char *)".gz",  (char *)".z",
    (char *)".taz", (char *)".tgz", (char *)"-gz",
    (char *)"-z",   (char *)"_z",   (char *)((void *)0)};
static char *get_suffix(char *name) {
  int nlen;
  int slen;
  char suffix[33];
  char **suf;
  int tmp;
  int s;
  int tmp___0;
  int tmp___1;
  void *__cil_tmp13;

  {
    {
      suf = known_suffixes;
      tmp = strcmp((char const *)(z_suffix), "z");
    }
    if (tmp == 0) {
      suf++;
    }
    { nlen = (int)strlen((char const *)name); }
    if (nlen <= 32) {
      {
        strcpy((char * /* __restrict  */)(suffix),
               (char const * /* __restrict  */)name);
      }
    } else {
      {
        strcpy((char * /* __restrict  */)(suffix),
               (char const * /* __restrict  */)(((name + nlen) - 30) - 2));
      }
    }
    {
      strlwr(suffix);
      slen = (int)strlen((char const *)(suffix));
    }
    {

    while_break: /* CIL Label */
        ;
    }
    return ((char *)((void *)0));
  }
}
static char *suffixes[6] = {z_suffix,     (char *)".gz", (char *)".z",
                            (char *)"-z", (char *)".Z",  (char *)((void *)0)};
static int get_istat(char *iname, struct stat *sbuf) {
  int ilen;
  char **suf;
  char *s;
  int tmp;
  int *tmp___0;
  int tmp___1;
  int tmp___2;

  {
    {
      suf = suffixes;
      strcpy((char * /* __restrict  */)(ifname),
             (char const * /* __restrict  */)iname);
      tmp = do_stat(ifname, sbuf);
    }
    if (tmp == 0) {
      return (0);
    }
    if (!decompress) {
      {
        perror((char const *)(ifname));
        exit_code = 1;
      }
      return (1);
    } else {
      { tmp___0 = __errno_location(); }
      if (*tmp___0 != 2) {
        {
          perror((char const *)(ifname));
          exit_code = 1;
        }
        return (1);
      }
    }
    { s = get_suffix(ifname); }
    if ((unsigned long)s != (unsigned long)((void *)0)) {
      {
        perror((char const *)(ifname));
        exit_code = 1;
      }
      return (1);
    }
    {
      ilen = (int)strlen((char const *)(ifname));
      tmp___1 = strcmp((char const *)(z_suffix), ".gz");
    }
    if (tmp___1 == 0) {
      suf++;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          s = *suf;
          strcat((char * /* __restrict  */)(ifname),
                 (char const * /* __restrict  */)s);
          tmp___2 = do_stat(ifname, sbuf);
        }
        if (tmp___2 == 0) {
          return (0);
        }
        ifname[ilen] = (char)'\000';
        suf++;
        if (!((unsigned long)*suf != (unsigned long)((void *)0))) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      strcat((char * /* __restrict  */)(ifname),
             (char const * /* __restrict  */)(z_suffix));
      perror((char const *)(ifname));
      exit_code = 1;
    }
    return (1);
  }
}
static int make_ofname(void) {
  char *suff;
  int tmp;
  int tmp___0;
  char *__cil_tmp4;
  char *__cil_tmp5;

  {
    {
      strcpy((char * /* __restrict  */)(ofname),
             (char const * /* __restrict  */)(ifname));
      suff = get_suffix(ofname);
    }
    if (decompress) {
      if ((unsigned long)suff == (unsigned long)((void *)0)) {

        return (2);
      }
      {
        strlwr(suff);
        tmp = strcmp((char const *)suff, ".tgz");
      }

    } else {
      if ((unsigned long)suff != (unsigned long)((void *)0)) {
        if (verbose) {
          {
          }
        } else {
        }
        if (exit_code == 0) {
          exit_code = 2;
        }
        return (2);
      } else {
        {
          save_orig_name = 0;
          strcat((char * /* __restrict  */)(ofname),
                 (char const * /* __restrict  */)(z_suffix));
        }
      }
    }
    return (0);
  }
}
static int get_method(int in) {
  uch flags___0;
  char magic[2];
  ulg stamp;
  unsigned int tmp;
  int tmp___0;
  int tmp___1;
  unsigned int tmp___2;
  int tmp___3;
  int tmp___4;
  unsigned int tmp___5;
  int tmp___6;
  int tmp___7;
  unsigned int tmp___8;
  int tmp___9;
  int tmp___10;
  unsigned int tmp___11;
  int tmp___12;
  int tmp___13;
  unsigned int tmp___14;
  int tmp___15;
  int tmp___16;
  unsigned int tmp___17;
  int tmp___18;
  int tmp___19;
  unsigned int tmp___20;
  int tmp___21;
  int tmp___22;
  unsigned int tmp___23;
  int tmp___24;
  int tmp___25;
  unsigned int tmp___26;
  int tmp___27;
  int tmp___28;
  unsigned int tmp___29;
  unsigned int tmp___30;
  unsigned int part;
  unsigned int tmp___31;
  int tmp___32;
  int tmp___33;
  unsigned int tmp___34;
  int tmp___35;
  int tmp___36;
  unsigned int len;
  unsigned int tmp___37;
  int tmp___38;
  int tmp___39;
  unsigned int tmp___40;
  int tmp___41;
  int tmp___42;
  unsigned int tmp___43;
  unsigned int tmp___44;
  char c;
  unsigned int tmp___45;
  int tmp___46;
  char *p;
  char *tmp___47;
  char *base;
  unsigned int tmp___48;
  int tmp___49;
  int tmp___50;
  char *tmp___51;
  unsigned int tmp___52;
  int tmp___53;
  int tmp___54;
  int tmp___55;
  int tmp___56;
  int tmp___57;
  int tmp___58;
  int tmp___59;
  int tmp___60;
  int tmp___61;
  int tmp___62;
  void *__cil_tmp74;
  char *__cil_tmp75;

  {
    if (force) {
      if (to_stdout) {
        if (inptr < insize) {
          tmp = inptr;
          inptr++;
          tmp___1 = (int)inbuf[tmp];
        } else {
          {
            tmp___0 = fill_inbuf(1);
            tmp___1 = tmp___0;
          }
        }
        magic[0] = (char)tmp___1;
        if (inptr < insize) {
          tmp___2 = inptr;
          inptr++;
          tmp___4 = (int)inbuf[tmp___2];
        } else {
          {
            tmp___3 = fill_inbuf(1);
            tmp___4 = tmp___3;
          }
        }
        magic[1] = (char)tmp___4;
      } else {
        goto _L;
      }
    } else {
    _L:

      magic[0] = (char)tmp___7;
      if (inptr < insize) {
        tmp___8 = inptr;
        inptr++;
        tmp___10 = (int)inbuf[tmp___8];
      } else {
        {
          tmp___9 = fill_inbuf(0);
          tmp___10 = tmp___9;
        }
      }
      magic[1] = (char)tmp___10;
    }
    {
      method = -1;
      part_nb++;
      header_bytes = 0L;
      last_member = 0;
      tmp___61 =
          memcmp((void const *)(magic), (void const *)"\037\213", (size_t)2);
    }
    if (tmp___61 == 0) {
      goto _L___4;
    } else {
      {
        tmp___62 =
            memcmp((void const *)(magic), (void const *)"\037\236", (size_t)2);
      }
      if (tmp___62 == 0) {
      _L___4:
        if (inptr < insize) {
          tmp___11 = inptr;
          inptr++;
          tmp___13 = (int)inbuf[tmp___11];
        } else {
          {
            tmp___12 = fill_inbuf(0);
            tmp___13 = tmp___12;
          }
        }
        method = tmp___13;
        if (method != 8) {
          {

            exit_code = 1;
          }
          return (-1);
        }
        work = &unzip;
        if (inptr < insize) {
          tmp___14 = inptr;
          inptr++;
          tmp___16 = (int)inbuf[tmp___14];
        } else {
          {
            tmp___15 = fill_inbuf(0);
            tmp___16 = tmp___15;
          }
        }
        flags___0 = (uch)tmp___16;
        if (((int)flags___0 & 32) != 0) {
          {
            fprintf(
                (FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "%s: %s is encrypted -- get "
                                                 "newer version of gzip\n",
                progname, ifname);
            exit_code = 1;
          }
          return (-1);
        }
        if (((int)flags___0 & 2) != 0) {
          {

            exit_code = 1;
          }
          if (force <= 1) {
            return (-1);
          }
        }
        if (((int)flags___0 & 192) != 0) {
          {
            fprintf(
                (FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "%s: %s has flags 0x%x -- get "
                                                 "newer version of gzip\n",
                progname, ifname, (int)flags___0);
            exit_code = 1;
          }
          if (force <= 1) {
            return (-1);
          }
        }
        if (inptr < insize) {
          tmp___17 = inptr;
          inptr++;
          tmp___19 = (int)inbuf[tmp___17];
        } else {
          {
            tmp___18 = fill_inbuf(0);
            tmp___19 = tmp___18;
          }
        }
        stamp = (ulg)tmp___19;
        if (inptr < insize) {
          tmp___20 = inptr;
          inptr++;
          tmp___22 = (int)inbuf[tmp___20];
        } else {
          {
            tmp___21 = fill_inbuf(0);
            tmp___22 = tmp___21;
          }
        }
        stamp |= (ulg)tmp___22 << 8;
        if (inptr < insize) {
          tmp___23 = inptr;
          inptr++;
          tmp___25 = (int)inbuf[tmp___23];
        } else {
          {
            tmp___24 = fill_inbuf(0);
            tmp___25 = tmp___24;
          }
        }
        stamp |= (ulg)tmp___25 << 16;
        if (inptr < insize) {
          tmp___26 = inptr;
          inptr++;
          tmp___28 = (int)inbuf[tmp___26];
        } else {
          {
            tmp___27 = fill_inbuf(0);
            tmp___28 = tmp___27;
          }
        }
        stamp |= (ulg)tmp___28 << 24;
        if (stamp != 0UL) {
          if (!no_time) {
            time_stamp = (long)stamp;
          }
        }
        if (inptr < insize) {
          tmp___29 = inptr;
          inptr++;
        } else {
          { fill_inbuf(0); }
        }
        if (inptr < insize) {
          tmp___30 = inptr;
          inptr++;
        } else {
          { fill_inbuf(0); }
        }
        if (((int)flags___0 & 2) != 0) {
          if (inptr < insize) {
            tmp___31 = inptr;
            inptr++;
            tmp___33 = (int)inbuf[tmp___31];
          } else {
            {
              tmp___32 = fill_inbuf(0);
              tmp___33 = tmp___32;
            }
          }
          part = (unsigned int)tmp___33;
          if (inptr < insize) {
            tmp___34 = inptr;
            inptr++;
            tmp___36 = (int)inbuf[tmp___34];
          } else {
            {
              tmp___35 = fill_inbuf(0);
              tmp___36 = tmp___35;
            }
          }
          part |= (unsigned int)tmp___36 << 8;
        }
        if (((int)flags___0 & 4) != 0) {
          if (inptr < insize) {
            tmp___37 = inptr;
            inptr++;
            tmp___39 = (int)inbuf[tmp___37];
          } else {
            {
              tmp___38 = fill_inbuf(0);
              tmp___39 = tmp___38;
            }
          }
          len = (unsigned int)tmp___39;
          if (inptr < insize) {
            tmp___40 = inptr;
            inptr++;
            tmp___42 = (int)inbuf[tmp___40];
          } else {
            {
              tmp___41 = fill_inbuf(0);
              tmp___42 = tmp___41;
            }
          }
          len |= (unsigned int)tmp___42 << 8;

          {
            while (1) {
            while_continue: /* CIL Label */
                ;
              tmp___44 = len;
              len--;
              if (!tmp___44) {
                goto while_break;
              }
              if (inptr < insize) {
                tmp___43 = inptr;
                inptr++;
              } else {
                { fill_inbuf(0); }
              }
            }
          while_break: /* CIL Label */
              ;
          }
        }
        if (((int)flags___0 & 8) != 0) {
          if (no_name) {
            goto _L___0;
          } else {
            if (to_stdout) {

            } else {
            _L___1:
              if (part_nb > 1) {
              _L___0: {
                while (1) {
                while_continue___0: /* CIL Label */
                    ;
                  if (inptr < insize) {
                    tmp___45 = inptr;
                    inptr++;
                    c = (char)inbuf[tmp___45];
                  } else {
                    {
                      tmp___46 = fill_inbuf(0);
                      c = (char)tmp___46;
                    }
                  }
                  if (!((int)c != 0)) {
                    goto while_break___0;
                  }
                }
              while_break___0: /* CIL Label */
                  ;
              }
              } else {
                {
                  tmp___47 = basename(ofname);
                  p = tmp___47;
                  base = p;
                }
                {
                  while (1) {
                  while_continue___1: /* CIL Label */
                      ;
                    if (inptr < insize) {
                      tmp___48 = inptr;
                      inptr++;
                      tmp___50 = (int)inbuf[tmp___48];
                    } else {
                      {
                        tmp___49 = fill_inbuf(0);
                        tmp___50 = tmp___49;
                      }
                    }
                    *p = (char)tmp___50;
                    tmp___51 = p;
                    p++;
                    if ((int)*tmp___51 == 0) {
                      goto while_break___1;
                    }
                    if ((unsigned long)p >=
                        (unsigned long)(ofname + sizeof(ofname))) {
                      {
                        error((char *)"corrupted input -- file name too large");
                      }
                    }
                  }
                while_break___1: /* CIL Label */
                    ;
                }
              }
            }
          }
        }
        if (((int)flags___0 & 16) != 0) {
          {

          while_break___2: /* CIL Label */
              ;
          }
        }
        if (part_nb == 1) {
          header_bytes = (long)((unsigned long)inptr + 2UL * sizeof(long));
        }
      } else {
        {
          tmp___59 = memcmp((void const *)(magic), (void const *)"PK\003\004",
                            (size_t)2);
        }
        if (tmp___59 == 0) {
          if (inptr == 2U) {
            {
              tmp___60 = memcmp((void const *)((char *)(inbuf)),
                                (void const *)"PK\003\004", (size_t)4);
            }
            if (tmp___60 == 0) {
              {
                inptr = 0U;
                work = &unzip;
                tmp___55 = check_zipfile(in);
              }
              if (tmp___55 != 0) {
                return (-1);
              }
              last_member = 1;
            } else {
              goto _L___3;
            }
          } else {
            goto _L___3;
          }
        } else {
        _L___3: {
          tmp___58 = memcmp((void const *)(magic), (void const *)"\037\036",
                            (size_t)2);
        }
          if (tmp___58 == 0) {
            work = &unpack;
            method = 2;
          } else {
            {
              tmp___57 = memcmp((void const *)(magic), (void const *)"\037\235",
                                (size_t)2);
            }
            if (tmp___57 == 0) {
              work = &unlzw;
              method = 1;
              last_member = 1;
            } else {
              {
                tmp___56 = memcmp((void const *)(magic),
                                  (void const *)"\037\240", (size_t)2);
              }
              if (tmp___56 == 0) {
                work = &unlzh;
                method = 3;
                last_member = 1;
              } else {
                if (force) {
                  if (to_stdout) {
                    if (!list) {
                      method = 0;
                      work = &copy;
                      inptr = 0U;
                      last_member = 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (method >= 0) {
      return (method);
    }
    if (part_nb == 1) {
      {
        fprintf(
            (FILE * /* __restrict  */)stderr,
            (char const * /* __restrict  */) "\n%s: %s: not in gzip format\n",
            progname, ifname);
        exit_code = 1;
      }
      return (-1);
    } else {

      return (-2);
    }
  }
}
static int first_time = 1;
static char *methods[9] = {(char *)"store", (char *)"compr", (char *)"pack ",
                           (char *)"lzh  ", (char *)"",      (char *)"",
                           (char *)"",      (char *)"",      (char *)"defla"};
static void do_list(int ifd___0, int method___0) {
  ulg crc___1;
  char *date;
  __off_t tmp;
  uch buf[8];
  ssize_t tmp___0;
  char *tmp___1;
  void *__cil_tmp9;

  {
    if (first_time) {

    } else {
    _L:
      if (method___0 < 0) {
        if (total_in <= 0L) {
          return;
        } else {
        }

        {
          display_ratio(total_out - (total_in - header_bytes), total_out,
                        stdout);
          printf((char const * /* __restrict  */) " (totals)\n");
        }
        return;
      }
    }
    crc___1 = (ulg)(~0);
    bytes_out = -1L;
    bytes_in = ifile_size;
    if (method___0 == 8) {
      if (!last_member) {
        {
          tmp = lseek(ifd___0, (off_t)-8, 2);
          bytes_in = tmp;
        }
        if (bytes_in != -1L) {
          {
            bytes_in += 8L;
            tmp___0 = read(ifd___0, (void *)((char *)(buf)), sizeof(buf));
          }
          if ((unsigned long)tmp___0 != sizeof(buf)) {
            {
              read_error();
            }
          }
          crc___1 = (ulg)((int)((ush)buf[0]) | ((int)((ush)buf[1]) << 8)) |
                    ((ulg)((int)((ush) * ((buf + 2) + 0)) |
                           ((int)((ush) * ((buf + 2) + 1)) << 8))
                     << 16);
          bytes_out = (long)((ulg)((int)((ush) * ((buf + 4) + 0)) |
                                   ((int)((ush) * ((buf + 4) + 1)) << 8)) |
                             ((ulg)((int)((ush) * (((buf + 4) + 2) + 0)) |
                                    ((int)((ush) * (((buf + 4) + 2) + 1)) << 8))
                              << 16));
        }
      }
    }
    {
      tmp___1 = ctime((time_t const *)(&time_stamp));
      date = tmp___1 + 4;
      *(date + 12) = (char)'\000';
    }

    {
      printf((char const * /* __restrict  */) "%9ld %9ld ", bytes_in,
             bytes_out);
    }
    if (bytes_in == -1L) {
      total_in = -1L;
      header_bytes = 0L;
      bytes_out = header_bytes;
      bytes_in = bytes_out;
    } else {
      if (total_in >= 0L) {
        total_in += bytes_in;
      }
    }
    if (bytes_out == -1L) {
      total_out = -1L;
      header_bytes = 0L;
      bytes_out = header_bytes;
      bytes_in = bytes_out;
    } else {
      if (total_out >= 0L) {
        total_out += bytes_out;
      }
    }
    {
      display_ratio(bytes_out - (bytes_in - header_bytes), bytes_out, stdout);
      printf((char const * /* __restrict  */) " %s\n", ofname);
    }
    return;
  }
}
static int same_file(struct stat *stat1, struct stat *stat2) {
  int tmp;

  {
    if (stat1->st_ino == stat2->st_ino) {
      if (stat1->st_dev == stat2->st_dev) {
        tmp = 1;
      } else {
        tmp = 0;
      }
    } else {
      tmp = 0;
    }
    return (tmp);
  }
}
static int name_too_long(char *name, struct stat *statb) {
  int s;
  int tmp;
  char c;
  struct stat tstat;
  int res;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  void *__cil_tmp12;

  {
    {
      tmp = (int)strlen((char const *)name);
      s = tmp;
      c = *(name + (s - 1));
      tstat = *statb;
      *(name + (s - 1)) = (char)'\000';
      tmp___0 = stat((char const * /* __restrict  */)name,
                     (struct stat * /* __restrict  */)(&tstat));
    }
    if (tmp___0 == 0) {
      {
        tmp___1 = same_file(statb, &tstat);
      }
      if (tmp___1) {
        tmp___2 = 1;
      } else {
        tmp___2 = 0;
      }
    } else {
      tmp___2 = 0;
    }
    res = tmp___2;
    *(name + (s - 1)) = c;
    return (res);
  }
}
static void shorten_name(char *name) {
  int len;
  char *trunc;
  int plen;
  int min_part;
  char *p;
  int tmp;
  char *tmp___0;
  char *__cil_tmp11;
  char *__cil_tmp12;
  char *__cil_tmp13;
  char *__cil_tmp14;
  char *__cil_tmp15;

  {
    {
      trunc = (char *)((void *)0);
      min_part = 3;
      len = (int)strlen((char const *)name);
    }
    if (decompress) {

      *(name + (len - 1)) = (char)'\000';
      return;
    }
    { p = get_suffix(name); }
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      {
        error((char *)"can\'t recover suffix\n");
      }
    }
    *p = (char)'\000';
    save_orig_name = 1;
    if (len > 4) {
      {
        tmp = strcmp((char const *)(p - 4), ".tar");
      }
      if (tmp == 0) {
        {
          strcpy((char * /* __restrict  */)(p - 4),
                 (char const * /* __restrict  */) ".tgz");
        }
        return;
      }
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { p = strrchr((char const *)name, '/'); }
        if (p) {
          p++;
        } else {
          p = name;
        }
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            if (!*p) {
              goto while_break___0;
            }
            {
              plen = (int)strcspn((char const *)p, ".");
              p += plen;
            }
            if (plen > min_part) {
              trunc = p - 1;
            }
          }
        while_break___0: /* CIL Label */
            ;
        }
        if ((unsigned long)trunc == (unsigned long)((void *)0)) {
          min_part--;
          if (!(min_part != 0)) {
            goto while_break;
          }
        } else {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if ((unsigned long)trunc != (unsigned long)((void *)0)) {
      {
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          *(trunc + 0) = *(trunc + 1);
          tmp___0 = trunc;
          trunc++;
          if (!*tmp___0) {
            goto while_break___1;
          }
        }
      while_break___1: /* CIL Label */
          ;
      }
      trunc--;
    } else {
      { trunc = strrchr((char const *)name, (int)*("." + 0)); }
      if ((unsigned long)trunc == (unsigned long)((void *)0)) {
        {
          error((char *)"internal error in shorten_name");
        }
      }
      if ((int)*(trunc + 1) == 0) {
        trunc--;
      }
    }
    {
      strcpy((char * /* __restrict  */)trunc,
             (char const * /* __restrict  */)(z_suffix));
    }
    return;
  }
}
static int check_ofname(void) {
  struct stat ostat;
  int *tmp;
  int *tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  char const *tmp___4;
  int tmp___5;
  int tmp___6;
  char response[80];
  int tmp___7;
  int tmp___8;
  int tmp___10;
  unsigned short const **tmp___11;
  int tmp___12;
  void *__cil_tmp16;
  void *__cil_tmp17;
  char *__cil_tmp18;
  char *__cil_tmp19;
  char *__cil_tmp20;

  {
    {
      tmp = __errno_location();
      *tmp = 0;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          tmp___1 = stat((char const * /* __restrict  */)(ofname),
                         (struct stat * /* __restrict  */)(&ostat));
        }
        if (!(tmp___1 != 0)) {
          goto while_break;
        }
        { tmp___0 = __errno_location(); }
        if (*tmp___0 != 36) {
          return (0);
        }
        { shorten_name(ofname); }
      }
    while_break: /* CIL Label */
        ;
    }
    if (!decompress) {
      {
        tmp___3 = name_too_long(ofname, &ostat);
      }
      if (tmp___3) {
        {
          shorten_name(ofname);
          tmp___2 = stat((char const * /* __restrict  */)(ofname),
                         (struct stat * /* __restrict  */)(&ostat));
        }
        if (tmp___2 != 0) {
          return (0);
        }
      }
    }
    { tmp___6 = same_file(&istat, &ostat); }
    if (tmp___6) {
      {
        tmp___5 = strcmp((char const *)(ifname), (char const *)(ofname));
      }
      if (tmp___5 == 0) {

        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const * /* __restrict  */) "%s: %s: cannot %scompress "
                                                   "onto itself\n",
                  progname, ifname, tmp___4);
        }
      } else {
        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const
                       * /* __restrict  */) "%s: %s and %s are the same file\n",
                  progname, ifname, ofname);
        }
      }
      exit_code = 1;
      return (1);
    }
    if (!force) {
      {
        strcpy((char * /* __restrict  */)(response),
               (char const * /* __restrict  */) "n");
        fprintf((FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "%s: %s already exists;",
                progname, ofname);
      }

      { tmp___11 = __ctype_b_loc(); }
      if ((int const) * (*tmp___11 + (int)response[0]) & 256) {
        tmp___10 = ((int)response[0] - 65) + 97;
      } else {
        tmp___10 = (int)response[0];
      }
      if (tmp___10 != 121) {
        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const * /* __restrict  */) "\tnot overwritten\n");
        }
        if (exit_code == 0) {
          exit_code = 2;
        }
        return (1);
      }
    }
    {
      chmod((char const *)(ofname), (__mode_t)511);
      tmp___12 = unlink((char const *)(ofname));
    }
    if (tmp___12) {
      {
        fprintf((FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "%s: ", progname);
        perror((char const *)(ofname));
        exit_code = 1;
      }
      return (1);
    }
    return (0);
  }
}
static void reset_times(char *name, struct stat *statb) {
  struct utimbuf timep;
  int tmp;

  {
    {
      timep.actime = statb->st_atim.tv_sec;
      timep.modtime = statb->st_mtim.tv_sec;
      tmp = utime((char const *)name, (struct utimbuf const *)(&timep));
    }
    if (tmp) {
      if (!((statb->st_mode & 61440U) == 16384U)) {
        if (!quiet) {
          {
            fprintf((FILE * /* __restrict  */)stderr,
                    (char const * /* __restrict  */) "%s: ", progname);
          }
        }
        if (exit_code == 0) {
          exit_code = 2;
        }
        if (!quiet) {
          {
            perror((char const *)(ofname));
          }
        }
      }
    }
    return;
  }
}
static void copy_stat(struct stat *ifstat) {
  int tmp;
  int tmp___0;

  {

    {
      reset_times(ofname, ifstat);
      tmp = chmod((char const *)(ofname), ifstat->st_mode & 4095U);
    }
    if (tmp) {
      if (!quiet) {
        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const * /* __restrict  */) "%s: ", progname);
        }
      }
      if (exit_code == 0) {
        exit_code = 2;
      }
    }
    {
      chown((char const *)(ofname), ifstat->st_uid, ifstat->st_gid);
      remove_ofname = 0;
      chmod((char const *)(ifname), (__mode_t)511);
      tmp___0 = unlink((char const *)(ifname));
    }
    if (tmp___0) {
      if (!quiet) {
        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const * /* __restrict  */) "%s: ", progname);
        }
      }

      if (!quiet) {
        {
          perror((char const *)(ifname));
        }
      }
    }
    return;
  }
}
static void treat_dir(char *dir) {
  dir_type *dp;
  DIR *dirp;
  char nbuf[1024];
  int len;
  int tmp;
  int tmp___0;
  int tmp___1;
  size_t tmp___2;
  void *__cil_tmp11;

  {
    { dirp = opendir((char const *)dir); }
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      {
        fprintf((FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "%s: %s unreadable\n",
                progname, dir);
        exit_code = 1;
      }
      return;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { dp = readdir(dirp); }
        if (!((unsigned long)dp != (unsigned long)((void *)0))) {
          goto while_break;
        }
        { tmp = strcmp((char const *)(dp->d_name), "."); }
        if (tmp == 0) {
          goto while_continue;
        } else {
          { tmp___0 = strcmp((char const *)(dp->d_name), ".."); }
          if (tmp___0 == 0) {
            goto while_continue;
          }
        }
        {
          len = (int)strlen((char const *)dir);
          tmp___2 = strlen((char const *)(dp->d_name));
        }
        if ((len + (int)tmp___2) + 1 < 1023) {
          {
            strcpy((char * /* __restrict  */)(nbuf),
                   (char const * /* __restrict  */)dir);
          }
          if (len != 0) {
            tmp___1 = len;
            len++;
            nbuf[tmp___1] = (char)'/';
          }
          {
            strcpy((char * /* __restrict  */)(nbuf + len),
                   (char const * /* __restrict  */)(dp->d_name));
            treat_file(nbuf);
          }
        } else {
          {
            fprintf((FILE * /* __restrict  */)stderr,
                    (char const
                         * /* __restrict  */) "%s: %s/%s: pathname too long\n",
                    progname, dir, dp->d_name);
            exit_code = 1;
          }
        }
      }
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
    if (in_exit) {
      {
        exit(exitcode);
      }
    }
    in_exit = 1;
    if ((unsigned long)env != (unsigned long)((void *)0)) {
      {
        free((void *)env);
        env = (char *)((void *)0);
      }
    }
    if ((unsigned long)args != (unsigned long)((void *)0)) {
      {
        free((void *)((char *)args));
        args = (char **)((void *)0);
      }
    }
    { exit(exitcode); }
  }
}
void abort_gzip(void) {

  {
    if (remove_ofname) {
      {
        close(ofd);
        unlink((char const *)(ofname));
      }
    }
    { do_exit(1); }
    return;
  }
}
