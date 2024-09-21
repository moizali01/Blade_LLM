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
static void fillbuf(int n) {}
static unsigned int getbits(int n) {}
static void init_getbits(void) {}
static void make_table(int nchar, uch *bitlen, int tablebits, ush *table) {}
static void read_pt_len(int nn, int nbit, int i_special) {}
static void read_c_len(void) {}
static unsigned int decode_c(void) {}
static unsigned int decode_p(void) {}
static void huf_decode_start(void) {}
static int j;
static int done;
static void decode_start(void) {}
static unsigned int i;
static unsigned int decode(unsigned int count, uch *buffer) {}
int unlzh(int in, int out) {}
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
static void read_tree(void) {}
static void build_tree(void) {}
int unpack(int in, int out) {}
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
extern struct _IO_FILE *stderr;
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format, ...);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1, 2), __leaf__)) memcpy)(void *__restrict __dest, void const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) void *(__attribute__((__nonnull__(1), __leaf__)) memset)(void *__s, int __c, size_t __n);
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
int unlzw(int in, int out) {}
int lzw(int in, int out);
static int msg_done = 0;
int lzw(int in, int out) {}
extern __attribute__((__nothrow__)) unsigned short const **(__attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) int *(__attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern ssize_t write(int __fd, void const *__buf, size_t __n);
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) calloc)(size_t __nmemb, size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(void *__ptr);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);
extern int _IO_putc(int __c, _IO_FILE *__fp);
extern void perror(char const *__s);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1), __leaf__)) strrchr)(char const *__s, int __c) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(1, 2), __leaf__)) strcspn)(char const *__s, char const *__reject) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(1, 2), __leaf__)) strspn)(char const *__s, char const *__accept) __attribute__((__pure__));
extern __attribute__((__nothrow__)) size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s) __attribute__((__pure__));
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
int copy(int in, int out) {}
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
            ;
            tmp = s;
            s++;
            c = crc_32_tab[((int)c ^ (int)*tmp) & 255] ^ (c >> 8);
            n--;
            if (!n) {
              goto while_break;
            }
          }
        while_break: /* CIL Label */;
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
        ;
        { len = (int)read(ifd, (void *)((char *)(inbuf) + insize), (size_t)(32768U - insize)); }
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
    while_break: /* CIL Label */;
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
void flush_outbuf(void) {}
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
        ;
        { n = (unsigned int)write(fd, (void const *)buf, (size_t)cnt); }
        if (!(n != cnt)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */;
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
        ;
        if (!*t) {
          goto while_break;
        }
        { tmp___0 = __ctype_b_loc(); }
        if ((int const) * (*tmp___0 + (int)*t) & 256) {

        } else {
          *t = *t;
        }
        t++;
      }
    while_break: /* CIL Label */;
    }
    return (s);
  }
}
char *basename(char *fname) {
  char *p;

  {
    { p = strrchr((char const *)fname, '/'); }
    if ((unsigned long)p != (unsigned long)((void *)0)) {
      fname = p + 1;
    }
    return (fname);
  }
}
char *add_envopt(int *argcp, char ***argvp, char *env___0) {

  int oargc;
  int nargc;
  char *tmp;

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

    } {

    }

    {

    }

    {

    } {}
  }
}
void error(char *m) {}
void read_error(void) {}
void write_error(void) {}
void display_ratio(long num, long den, FILE *file) {}
voidp xmalloc(unsigned int size) {}
ulg crc_32_tab[256] = {
    (ulg)0L,          (ulg)1996959894L, (ulg)3993919788L, (ulg)2567524794L, (ulg)124634137L,  (ulg)1886057615L, (ulg)3915621685L, (ulg)2657392035L, (ulg)249268274L,  (ulg)2044508324L, (ulg)3772115230L, (ulg)2547177864L, (ulg)162941995L,  (ulg)2125561021L, (ulg)3887607047L, (ulg)2428444049L,
    (ulg)498536548L,  (ulg)1789927666L, (ulg)4089016648L, (ulg)2227061214L, (ulg)450548861L,  (ulg)1843258603L, (ulg)4107580753L, (ulg)2211677639L, (ulg)325883990L,  (ulg)1684777152L, (ulg)4251122042L, (ulg)2321926636L, (ulg)335633487L,  (ulg)1661365465L, (ulg)4195302755L, (ulg)2366115317L,
    (ulg)997073096L,  (ulg)1281953886L, (ulg)3579855332L, (ulg)2724688242L, (ulg)1006888145L, (ulg)1258607687L, (ulg)3524101629L, (ulg)2768942443L, (ulg)901097722L,  (ulg)1119000684L, (ulg)3686517206L, (ulg)2898065728L, (ulg)853044451L,  (ulg)1172266101L, (ulg)3705015759L, (ulg)2882616665L,
    (ulg)651767980L,  (ulg)1373503546L, (ulg)3369554304L, (ulg)3218104598L, (ulg)565507253L,  (ulg)1454621731L, (ulg)3485111705L, (ulg)3099436303L, (ulg)671266974L,  (ulg)1594198024L, (ulg)3322730930L, (ulg)2970347812L, (ulg)795835527L,  (ulg)1483230225L, (ulg)3244367275L, (ulg)3060149565L,
    (ulg)1994146192L, (ulg)31158534L,   (ulg)2563907772L, (ulg)4023717930L, (ulg)1907459465L, (ulg)112637215L,  (ulg)2680153253L, (ulg)3904427059L, (ulg)2013776290L, (ulg)251722036L,  (ulg)2517215374L, (ulg)3775830040L, (ulg)2137656763L, (ulg)141376813L,  (ulg)2439277719L, (ulg)3865271297L,
    (ulg)1802195444L, (ulg)476864866L,  (ulg)2238001368L, (ulg)4066508878L, (ulg)1812370925L, (ulg)453092731L,  (ulg)2181625025L, (ulg)4111451223L, (ulg)1706088902L, (ulg)314042704L,  (ulg)2344532202L, (ulg)4240017532L, (ulg)1658658271L, (ulg)366619977L,  (ulg)2362670323L, (ulg)4224994405L,
    (ulg)1303535960L, (ulg)984961486L,  (ulg)2747007092L, (ulg)3569037538L, (ulg)1256170817L, (ulg)1037604311L, (ulg)2765210733L, (ulg)3554079995L, (ulg)1131014506L, (ulg)879679996L,  (ulg)2909243462L, (ulg)3663771856L, (ulg)1141124467L, (ulg)855842277L,  (ulg)2852801631L, (ulg)3708648649L,
    (ulg)1342533948L, (ulg)654459306L,  (ulg)3188396048L, (ulg)3373015174L, (ulg)1466479909L, (ulg)544179635L,  (ulg)3110523913L, (ulg)3462522015L, (ulg)1591671054L, (ulg)702138776L,  (ulg)2966460450L, (ulg)3352799412L, (ulg)1504918807L, (ulg)783551873L,  (ulg)3082640443L, (ulg)3233442989L,
    (ulg)3988292384L, (ulg)2596254646L, (ulg)62317068L,   (ulg)1957810842L, (ulg)3939845945L, (ulg)2647816111L, (ulg)81470997L,   (ulg)1943803523L, (ulg)3814918930L, (ulg)2489596804L, (ulg)225274430L,  (ulg)2053790376L, (ulg)3826175755L, (ulg)2466906013L, (ulg)167816743L,  (ulg)2097651377L,
    (ulg)4027552580L, (ulg)2265490386L, (ulg)503444072L,  (ulg)1762050814L, (ulg)4150417245L, (ulg)2154129355L, (ulg)426522225L,  (ulg)1852507879L, (ulg)4275313526L, (ulg)2312317920L, (ulg)282753626L,  (ulg)1742555852L, (ulg)4189708143L, (ulg)2394877945L, (ulg)397917763L,  (ulg)1622183637L,
    (ulg)3604390888L, (ulg)2714866558L, (ulg)953729732L,  (ulg)1340076626L, (ulg)3518719985L, (ulg)2797360999L, (ulg)1068828381L, (ulg)1219638859L, (ulg)3624741850L, (ulg)2936675148L, (ulg)906185462L,  (ulg)1090812512L, (ulg)3747672003L, (ulg)2825379669L, (ulg)829329135L,  (ulg)1181335161L,
    (ulg)3412177804L, (ulg)3160834842L, (ulg)628085408L,  (ulg)1382605366L, (ulg)3423369109L, (ulg)3138078467L, (ulg)570562233L,  (ulg)1426400815L, (ulg)3317316542L, (ulg)2998733608L, (ulg)733239954L,  (ulg)1555261956L, (ulg)3268935591L, (ulg)3050360625L, (ulg)752459403L,  (ulg)1541320221L,
    (ulg)2607071920L, (ulg)3965973030L, (ulg)1969922972L, (ulg)40735498L,   (ulg)2617837225L, (ulg)3943577151L, (ulg)1913087877L, (ulg)83908371L,   (ulg)2512341634L, (ulg)3803740692L, (ulg)2075208622L, (ulg)213261112L,  (ulg)2463272603L, (ulg)3855990285L, (ulg)2094854071L, (ulg)198958881L,
    (ulg)2262029012L, (ulg)4057260610L, (ulg)1759359992L, (ulg)534414190L,  (ulg)2176718541L, (ulg)4139329115L, (ulg)1873836001L, (ulg)414664567L,  (ulg)2282248934L, (ulg)4279200368L, (ulg)1711684554L, (ulg)285281116L,  (ulg)2405801727L, (ulg)4167216745L, (ulg)1634467795L, (ulg)376229701L,
    (ulg)2685067896L, (ulg)3608007406L, (ulg)1308918612L, (ulg)956543938L,  (ulg)2808555105L, (ulg)3495958263L, (ulg)1231636301L, (ulg)1047427035L, (ulg)2932959818L, (ulg)3654703836L, (ulg)1088359270L, (ulg)936918000L,  (ulg)2847714899L, (ulg)3736837829L, (ulg)1202900863L, (ulg)817233897L,
    (ulg)3183342108L, (ulg)3401237130L, (ulg)1404277552L, (ulg)615818150L,  (ulg)3134207493L, (ulg)3453421203L, (ulg)1423857449L, (ulg)601450431L,  (ulg)3009837614L, (ulg)3294710456L, (ulg)1567103746L, (ulg)711928724L,  (ulg)3020668471L, (ulg)3272380065L, (ulg)1510334235L, (ulg)755167117L};
int inflate(void);
int huft_build(unsigned int *b, unsigned int n, unsigned int s, ush *d, ush *e, struct huft **t, int *m);
int huft_free(struct huft *t);
int inflate_codes(struct huft *tl, struct huft *td, int bl, int bd);
int inflate_stored(void);
int inflate_fixed(void);
int inflate_dynamic(void);
int inflate_block(int *e);
static unsigned int border[19] = {16U, 17U, 18U, 0U, 8U, 7U, 9U, 6U, 10U, 5U, 11U, 4U, 12U, 3U, 13U, 2U, 14U, 1U, 15U};
static ush cplens[31] = {(ush)3,  (ush)4,  (ush)5,  (ush)6,  (ush)7,  (ush)8,  (ush)9,  (ush)10,  (ush)11,  (ush)13,  (ush)15,  (ush)17,  (ush)19,  (ush)23, (ush)27, (ush)31,
                         (ush)35, (ush)43, (ush)51, (ush)59, (ush)67, (ush)83, (ush)99, (ush)115, (ush)131, (ush)163, (ush)195, (ush)227, (ush)258, (ush)0,  (ush)0};
static ush cplext[31] = {(ush)0, (ush)0, (ush)0, (ush)0, (ush)0, (ush)0, (ush)0, (ush)0, (ush)1, (ush)1, (ush)1, (ush)1, (ush)2, (ush)2, (ush)2, (ush)2, (ush)3, (ush)3, (ush)3, (ush)3, (ush)4, (ush)4, (ush)4, (ush)4, (ush)5, (ush)5, (ush)5, (ush)5, (ush)0, (ush)99, (ush)99};
static ush cpdist[30] = {(ush)1,   (ush)2,   (ush)3,   (ush)4,   (ush)5,   (ush)7,    (ush)9,    (ush)13,   (ush)17,   (ush)25,   (ush)33,   (ush)49,   (ush)65,    (ush)97,    (ush)129,
                         (ush)193, (ush)257, (ush)385, (ush)513, (ush)769, (ush)1025, (ush)1537, (ush)2049, (ush)3073, (ush)4097, (ush)6145, (ush)8193, (ush)12289, (ush)16385, (ush)24577};
static ush cpdext[30] = {(ush)0, (ush)0, (ush)0, (ush)0, (ush)1, (ush)1, (ush)2, (ush)2, (ush)3, (ush)3, (ush)4, (ush)4, (ush)5, (ush)5, (ush)6, (ush)6, (ush)7, (ush)7, (ush)8, (ush)8, (ush)9, (ush)9, (ush)10, (ush)10, (ush)11, (ush)11, (ush)12, (ush)12, (ush)13, (ush)13};
ulg bb;
unsigned int bk;
ush mask_bits[17] = {(ush)0, (ush)1, (ush)3, (ush)7, (ush)15, (ush)31, (ush)63, (ush)127, (ush)255, (ush)511, (ush)1023, (ush)2047, (ush)4095, (ush)8191, (ush)16383, (ush)32767, (ush)65535};
int lbits = 9;
int dbits = 6;
unsigned int hufts;
int huft_build(unsigned int *b, unsigned int n, unsigned int s, ush *d, ush *e, struct huft **t, int *m) {
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
  unsigned int *tmp___0;
  unsigned int tmp___1;
  unsigned int *tmp___2;
  int tmp___4;
  unsigned int *tmp___5;
  unsigned int tmp___6;
  int tmp___7;

  {
    {
      memset((voidp)(c), 0, sizeof(c));
      p = b;
      i___0 = n;
    }
    {
      while (1) {
        ;
        (c[*p])++;
        p++;
        i___0--;
        if (!i___0) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */;
    }
    if (c[0] == n) {
      *t = (struct huft *)((void *)0);
      *m = 0;
      return (0);
    }
    l = *m;
    j___0 = 1U;
    {
      while (1) {
        ;
        if (!(j___0 <= 16U)) {
          goto while_break___0;
        }
        if (c[j___0]) {
          goto while_break___0;
        }
        j___0++;
      }
    while_break___0: /* CIL Label */;
    }
    k = (int)j___0;
    if ((unsigned int)l < j___0) {
      l = (int)j___0;
    }
    i___0 = 16U;
    {
      while (1) {
        ;
        if (!i___0) {
          goto while_break___1;
        }
        if (c[i___0]) {
          goto while_break___1;
        }
        i___0--;
      }
    while_break___1: /* CIL Label */;
    }
    g = (int)i___0;
    if ((unsigned int)l > i___0) {
      l = (int)i___0;
    }
    *m = l;
    y = 1 << j___0;
    {
      while (1) {
        ;
        if (!(j___0 < i___0)) {
          goto while_break___2;
        }
        y = (int)((unsigned int)y - c[j___0]);
        if (y < 0) {
          return (2);
        }
        j___0++;
        y <<= 1;
      }
    while_break___2: /* CIL Label */;
    }
    y = (int)((unsigned int)y - c[i___0]);
    if (y < 0) {
      return (2);
    }
    c[i___0] += (unsigned int)y;
    j___0 = 0U;
    x[1] = j___0;
    p = c + 1;
    xp = x + 2;
    {
      while (1) {
        ;
        i___0--;
        if (!i___0) {
          goto while_break___3;
        }
        tmp = xp;
        xp++;
        tmp___0 = p;
        p++;
        j___0 += *tmp___0;
        *tmp = j___0;
      }
    while_break___3: /* CIL Label */;
    }
    p = b;
    i___0 = 0U;
    {
      while (1) {
        ;
        tmp___2 = p;
        p++;
        j___0 = *tmp___2;
        if (j___0 != 0U) {
          tmp___1 = x[j___0];
          (x[j___0])++;
          v[tmp___1] = i___0;
        }
        i___0++;
        if (!(i___0 < n)) {
          goto while_break___4;
        }
      }
    while_break___4: /* CIL Label */;
    }
    i___0 = 0U;
    x[0] = i___0;
    p = v;
    h = -1;
    w = -l;
    u[0] = (struct huft *)((void *)0);
    q = (struct huft *)((void *)0);
    z = 0U;
    {
      while (1) {
        ;
        if (!(k <= g)) {
          goto while_break___5;
        }
        a = c[k];
        {
          while (1) {
            ;
            tmp___6 = a;
            a--;
            if (!tmp___6) {
              goto while_break___6;
            }
            {
              while (1) {
                ;
                if (!(k > w + l)) {
                  goto while_break___7;
                }
                h++;
                w += l;
                z = (unsigned int)(g - w);
                if (z > (unsigned int)l) {
                  z = (unsigned int)l;
                } else {
                  z = z;
                }
                j___0 = (unsigned int)(k - w);
                f = (unsigned int)(1 << j___0);
                if (f > a + 1U) {
                  f -= a + 1U;
                  xp = c + k;
                  {
                    while (1) {
                      ;
                      j___0++;
                      if (!(j___0 < z)) {
                        goto while_break___8;
                      }
                      f <<= 1;
                      xp++;
                      if (f <= *xp) {
                        goto while_break___8;
                      }
                      f -= *xp;
                    }
                  while_break___8: /* CIL Label */;
                  }
                }
                {
                  z = (unsigned int)(1 << j___0);
                  q = (struct huft *)malloc((unsigned long)(z + 1U) * sizeof(struct huft));
                }
                if ((unsigned long)q == (unsigned long)((struct huft *)((void *)0))) {
                  if (h) {
                    {
                      huft_free(u[0]);
                    }
                  }
                  return (3);
                }
                hufts += z + 1U;
                *t = q + 1;
                t = &q->v.t;
                *t = (struct huft *)((void *)0);
                q++;
                u[h] = q;
                if (h) {
                  x[h] = i___0;
                  r.b = (uch)l;
                  r.e = (uch)(16U + j___0);
                  r.v.t = q;
                  j___0 = i___0 >> (w - l);
                  *(u[h - 1] + j___0) = r;
                }
              }
            while_break___7: /* CIL Label */;
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
                ;
                if (!(j___0 < z)) {
                  goto while_break___9;
                }
                *(q + j___0) = r;
                j___0 += f;
              }
            while_break___9: /* CIL Label */;
            }
            j___0 = (unsigned int)(1 << (k - 1));
            {
              while (1) {
                ;
                if (!(i___0 & j___0)) {
                  goto while_break___10;
                }
                i___0 ^= j___0;
                j___0 >>= 1;
              }
            while_break___10: /* CIL Label */;
            }
            i___0 ^= j___0;
            {
              while (1) {
                ;
                if (!((i___0 & (unsigned int)((1 << w) - 1)) != x[h])) {
                  goto while_break___11;
                }
                h--;
                w -= l;
              }
            while_break___11: /* CIL Label */;
            }
          }
        while_break___6: /* CIL Label */;
        }
        k++;
      }
    while_break___5: /* CIL Label */;
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
        ;
        if (!((unsigned long)p != (unsigned long)((struct huft *)((void *)0)))) {
          goto while_break;
        }
        {
          p--;
          q = p->v.t;
          free((void *)((char *)p));
          p = q;
        }
      }
    while_break: /* CIL Label */;
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
  int tmp___3;
  int tmp___4;
  unsigned int tmp___5;
  unsigned int tmp___6;
  int tmp___7;
  int tmp___8;
  unsigned int tmp___9;
  int tmp___10;
  int tmp___11;
  unsigned int tmp___12;
  int tmp___13;
  int tmp___14;
  unsigned int tmp___15;
  int tmp___16;
  int tmp___17;
  unsigned int tmp___19;
  unsigned int tmp___20;
  unsigned int tmp___21;

  {
    b = bb;
    k = bk;
    w = outcnt;
    ml = (unsigned int)mask_bits[bl];
    md = (unsigned int)mask_bits[bd];
    {
      while (1) {
        ;
        {
          while (1) {
            ;
            if (!(k < (unsigned int)bl)) {
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
            b |= (ulg)((uch)tmp___1) << k;
            k += 8U;
          }
        while_break___0: /* CIL Label */;
        }
        t = tl + ((unsigned int)b & ml);
        e = (unsigned int)t->e;
        if (e > 16U) {
          {
            while (1) {
              ;
              if (e == 99U) {
                return (1);
              }
              b >>= (int)t->b;
              k -= (unsigned int)t->b;
              e -= 16U;
              {
                while (1) {
                  ;
                  if (!(k < e)) {
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
                  b |= (ulg)((uch)tmp___4) << k;
                  k += 8U;
                }
              while_break___2: /* CIL Label */;
              }
              t = t->v.t + ((unsigned int)b & (unsigned int)mask_bits[e]);
              e = (unsigned int)t->e;
              if (!(e > 16U)) {
                goto while_break___1;
              }
            }
          while_break___1: /* CIL Label */;
          }
        }
        b >>= (int)t->b;
        k -= (unsigned int)t->b;
        if (e == 16U) {
          tmp___5 = w;
          w++;
          window[tmp___5] = (uch)t->v.n;
          if (w == 32768U) {
            {
              outcnt = w;
              flush_window();
              w = 0U;
            }
          }
        } else {
          if (e == 15U) {
            goto while_break;
          }
          {
            while (1) {
              ;
              if (!(k < e)) {
                goto while_break___3;
              }
              if (inptr < insize) {
                tmp___6 = inptr;
                inptr++;
                tmp___8 = (int)inbuf[tmp___6];
              } else {
                {
                  tmp___7 = fill_inbuf(0);
                  tmp___8 = tmp___7;
                }
              }
              b |= (ulg)((uch)tmp___8) << k;
              k += 8U;
            }
          while_break___3: /* CIL Label */;
          }
          n = (unsigned int)t->v.n + ((unsigned int)b & (unsigned int)mask_bits[e]);
          b >>= e;
          k -= e;
          {
            while (1) {
              ;
              if (!(k < (unsigned int)bd)) {
                goto while_break___4;
              }
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
              b |= (ulg)((uch)tmp___11) << k;
              k += 8U;
            }
          while_break___4: /* CIL Label */;
          }
          t = td + ((unsigned int)b & md);
          e = (unsigned int)t->e;
          if (e > 16U) {
            {
              while (1) {
                ;
                if (e == 99U) {
                  return (1);
                }
                b >>= (int)t->b;
                k -= (unsigned int)t->b;
                e -= 16U;
                {
                  while (1) {
                    ;
                    if (!(k < e)) {
                      goto while_break___6;
                    }
                    if (inptr < insize) {
                      tmp___12 = inptr;
                      inptr++;
                      tmp___14 = (int)inbuf[tmp___12];
                    } else {
                      {
                        tmp___13 = fill_inbuf(0);
                        tmp___14 = tmp___13;
                      }
                    }
                    b |= (ulg)((uch)tmp___14) << k;
                    k += 8U;
                  }
                while_break___6: /* CIL Label */;
                }
                t = t->v.t + ((unsigned int)b & (unsigned int)mask_bits[e]);
                e = (unsigned int)t->e;
                if (!(e > 16U)) {
                  goto while_break___5;
                }
              }
            while_break___5: /* CIL Label */;
            }
          }
          b >>= (int)t->b;
          k -= (unsigned int)t->b;
          {
            while (1) {
              ;
              if (!(k < e)) {
                goto while_break___7;
              }
              if (inptr < insize) {
                tmp___15 = inptr;
                inptr++;
                tmp___17 = (int)inbuf[tmp___15];
              } else {
                {
                  tmp___16 = fill_inbuf(0);
                  tmp___17 = tmp___16;
                }
              }
              b |= (ulg)((uch)tmp___17) << k;
              k += 8U;
            }
          while_break___7: /* CIL Label */;
          }
          d = (w - (unsigned int)t->v.n) - ((unsigned int)b & (unsigned int)mask_bits[e]);
          b >>= e;
          k -= e;
          {
            while (1) {
              ;
              d &= 32767U;
              if (d > w) {
                tmp___19 = d;
              } else {
                tmp___19 = w;
              }
              e = 32768U - tmp___19;
              if (e > n) {
                e = n;
              } else {
                e = e;
              }
              n -= e;
              if (w - d >= e) {
                {
                  memcpy((void * /* __restrict  */)(window + w), (void const * /* __restrict  */)(window + d), (size_t)e);
                  w += e;
                  d += e;
                }
              } else {
                {
                  while (1) {
                    ;
                    tmp___20 = w;
                    w++;
                    tmp___21 = d;
                    d++;
                    window[tmp___20] = window[tmp___21];
                    e--;
                    if (!e) {
                      goto while_break___9;
                    }
                  }
                while_break___9: /* CIL Label */;
                }
              }
              if (w == 32768U) {
                {
                  outcnt = w;
                  flush_window();
                  w = 0U;
                }
              }
              if (!n) {
                goto while_break___8;
              }
            }
          while_break___8: /* CIL Label */;
          }
        }
      }
    while_break: /* CIL Label */;
    }
    outcnt = w;
    bb = b;
    bk = k;
    return (0);
  }
}
int inflate_stored(void) {
  unsigned int n;
  unsigned int w;
  register ulg b;
  register unsigned int k;
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
  unsigned int tmp___9;

  {
    b = bb;
    k = bk;
    w = outcnt;
    n = k & 7U;
    b >>= n;
    k -= n;
    {
      while (1) {
        ;
        if (!(k < 16U)) {
          goto while_break;
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
        b |= (ulg)((uch)tmp___1) << k;
        k += 8U;
      }
    while_break: /* CIL Label */;
    }
    n = (unsigned int)b & 65535U;
    b >>= 16;
    k -= 16U;
    {
      while (1) {
        ;
        if (!(k < 16U)) {
          goto while_break___0;
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
        b |= (ulg)((uch)tmp___4) << k;
        k += 8U;
      }
    while_break___0: /* CIL Label */;
    }
    if (n != (unsigned int)(~b & 65535UL)) {
      return (1);
    }
    b >>= 16;
    k -= 16U;
    {
      while (1) {
        ;
        tmp___9 = n;
        n--;
        if (!tmp___9) {
          goto while_break___1;
        }
        {
          while (1) {
            ;
            if (!(k < 8U)) {
              goto while_break___2;
            }
            if (inptr < insize) {
              tmp___5 = inptr;
              inptr++;
              tmp___7 = (int)inbuf[tmp___5];
            } else {
              {
                tmp___6 = fill_inbuf(0);
                tmp___7 = tmp___6;
              }
            }
            b |= (ulg)((uch)tmp___7) << k;
            k += 8U;
          }
        while_break___2: /* CIL Label */;
        }
        tmp___8 = w;
        w++;
        window[tmp___8] = (uch)b;
        if (w == 32768U) {
          {
            outcnt = w;
            flush_window();
            w = 0U;
          }
        }
        b >>= 8;
        k -= 8U;
      }
    while_break___1: /* CIL Label */;
    }
    outcnt = w;
    bb = b;
    bk = k;
    return (0);
  }
}
int inflate_fixed(void) {
  int i___0;
  struct huft *tl;
  struct huft *td;
  int bl;
  int bd;
  unsigned int l[288];
  int tmp;

  {
    i___0 = 0;
    {
      while (1) {
        ;
        if (!(i___0 < 144)) {
          goto while_break;
        }
        l[i___0] = 8U;
        i___0++;
      }
    while_break: /* CIL Label */;
    }
    {
      while (1) {
        ;
        if (!(i___0 < 256)) {
          goto while_break___0;
        }
        l[i___0] = 9U;
        i___0++;
      }
    while_break___0: /* CIL Label */;
    }
    {
      while (1) {
        ;
        if (!(i___0 < 280)) {
          goto while_break___1;
        }
        l[i___0] = 7U;
        i___0++;
      }
    while_break___1: /* CIL Label */;
    }
    {
      while (1) {
        ;
        if (!(i___0 < 288)) {
          goto while_break___2;
        }
        l[i___0] = 8U;
        i___0++;
      }
    while_break___2: /* CIL Label */;
    }
    {
      bl = 7;
      i___0 = huft_build(l, 288U, 257U, cplens, cplext, &tl, &bl);
    }

    i___0 = 0;
    {
      while (1) {
        ;
        if (!(i___0 < 30)) {
          goto while_break___3;
        }
        l[i___0] = 5U;
        i___0++;
      }
    while_break___3: /* CIL Label */;
    }
    {
      bd = 5;
      i___0 = huft_build(l, 30U, 0U, cpdist, cpdext, &td, &bd);
    }

    { tmp = inflate_codes(tl, td, bl, bd); }

    {
      huft_free(tl);
      huft_free(td);
    }
    return (0);
  }
}
int inflate_dynamic(void) {
  int i___0;
  unsigned int j___0;
  unsigned int l;
  unsigned int m;
  unsigned int n;
  struct huft *tl;
  struct huft *td;
  int bl;
  int bd;
  unsigned int nb;
  unsigned int nl;
  unsigned int nd;
  unsigned int ll[316];
  register ulg b;
  register unsigned int k;
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
  int tmp___14;
  unsigned int tmp___15;
  int tmp___16;
  int tmp___17;
  int tmp___18;
  unsigned int tmp___19;
  unsigned int tmp___20;
  int tmp___21;
  int tmp___22;
  int tmp___23;
  unsigned int tmp___24;
  unsigned int tmp___25;
  int tmp___26;
  int tmp___27;
  int tmp___28;
  unsigned int tmp___29;
  int tmp___30;

  {
    b = bb;
    k = bk;
    {
      while (1) {
        ;
        if (!(k < 5U)) {
          goto while_break;
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
        b |= (ulg)((uch)tmp___1) << k;
        k += 8U;
      }
    while_break: /* CIL Label */;
    }
    nl = 257U + ((unsigned int)b & 31U);
    b >>= 5;
    k -= 5U;
    {
      while (1) {
        ;
        if (!(k < 5U)) {
          goto while_break___0;
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
        b |= (ulg)((uch)tmp___4) << k;
        k += 8U;
      }
    while_break___0: /* CIL Label */;
    }
    nd = 1U + ((unsigned int)b & 31U);
    b >>= 5;
    k -= 5U;
    {
      while (1) {
        ;
        if (!(k < 4U)) {
          goto while_break___1;
        }
        if (inptr < insize) {
          tmp___5 = inptr;
          inptr++;
          tmp___7 = (int)inbuf[tmp___5];
        } else {
          {
            tmp___6 = fill_inbuf(0);
            tmp___7 = tmp___6;
          }
        }
        b |= (ulg)((uch)tmp___7) << k;
        k += 8U;
      }
    while_break___1: /* CIL Label */;
    }
    nb = 4U + ((unsigned int)b & 15U);
    b >>= 4;
    k -= 4U;
    if (nl > 286U) {
      return (1);
    } else {
      if (nd > 30U) {
        return (1);
      }
    }
    j___0 = 0U;
    {
      while (1) {
        ;
        if (!(j___0 < nb)) {
          goto while_break___2;
        }
        {
          while (1) {
            ;
            if (!(k < 3U)) {
              goto while_break___3;
            }
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
            b |= (ulg)((uch)tmp___10) << k;
            k += 8U;
          }
        while_break___3: /* CIL Label */;
        }
        ll[border[j___0]] = (unsigned int)b & 7U;
        b >>= 3;
        k -= 3U;
        j___0++;
      }
    while_break___2: /* CIL Label */;
    }
    {
      while (1) {
        ;
        if (!(j___0 < 19U)) {
          goto while_break___4;
        }
        ll[border[j___0]] = 0U;
        j___0++;
      }
    while_break___4: /* CIL Label */;
    }
    {
      bl = 7;
      i___0 = huft_build(ll, 19U, 19U, (ush *)((void *)0), (ush *)((void *)0), &tl, &bl);
    }
    if (i___0 != 0) {
      if (i___0 == 1) {
        {
          huft_free(tl);
        }
      }
      return (i___0);
    }
    n = nl + nd;
    m = (unsigned int)mask_bits[bl];
    l = 0U;
    i___0 = (int)l;
    {
      while (1) {
        ;
        if (!((unsigned int)i___0 < n)) {
          goto while_break___5;
        }
        {
          while (1) {
            ;
            if (!(k < (unsigned int)bl)) {
              goto while_break___6;
            }
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
            b |= (ulg)((uch)tmp___13) << k;
            k += 8U;
          }
        while_break___6: /* CIL Label */;
        }
        td = tl + ((unsigned int)b & m);
        j___0 = (unsigned int)td->b;
        b >>= j___0;
        k -= j___0;
        j___0 = (unsigned int)td->v.n;
        if (j___0 < 16U) {
          tmp___14 = i___0;
          i___0++;
          l = j___0;
          ll[tmp___14] = l;
        } else {
          if (j___0 == 16U) {
            {
              while (1) {
                ;
                if (!(k < 2U)) {
                  goto while_break___7;
                }
                if (inptr < insize) {
                  tmp___15 = inptr;
                  inptr++;
                  tmp___17 = (int)inbuf[tmp___15];
                } else {
                  {
                    tmp___16 = fill_inbuf(0);
                    tmp___17 = tmp___16;
                  }
                }
                b |= (ulg)((uch)tmp___17) << k;
                k += 8U;
              }
            while_break___7: /* CIL Label */;
            }
            j___0 = 3U + ((unsigned int)b & 3U);
            b >>= 2;
            k -= 2U;
            if ((unsigned int)i___0 + j___0 > n) {
              return (1);
            }
            {
              while (1) {
                ;
                tmp___19 = j___0;
                j___0--;
                if (!tmp___19) {
                  goto while_break___8;
                }
                tmp___18 = i___0;
                i___0++;
                ll[tmp___18] = l;
              }
            while_break___8: /* CIL Label */;
            }
          } else {
            if (j___0 == 17U) {
              {
                while (1) {
                  ;
                  if (!(k < 3U)) {
                    goto while_break___9;
                  }
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
                  b |= (ulg)((uch)tmp___22) << k;
                  k += 8U;
                }
              while_break___9: /* CIL Label */;
              }
              j___0 = 3U + ((unsigned int)b & 7U);
              b >>= 3;
              k -= 3U;
              if ((unsigned int)i___0 + j___0 > n) {
                return (1);
              }
              {
                while (1) {
                  ;
                  tmp___24 = j___0;
                  j___0--;
                  if (!tmp___24) {
                    goto while_break___10;
                  }
                  tmp___23 = i___0;
                  i___0++;
                  ll[tmp___23] = 0U;
                }
              while_break___10: /* CIL Label */;
              }
              l = 0U;
            } else {
              {
                while (1) {
                  ;
                  if (!(k < 7U)) {
                    goto while_break___11;
                  }
                  if (inptr < insize) {
                    tmp___25 = inptr;
                    inptr++;
                    tmp___27 = (int)inbuf[tmp___25];
                  } else {
                    {
                      tmp___26 = fill_inbuf(0);
                      tmp___27 = tmp___26;
                    }
                  }
                  b |= (ulg)((uch)tmp___27) << k;
                  k += 8U;
                }
              while_break___11: /* CIL Label */;
              }
              j___0 = 11U + ((unsigned int)b & 127U);
              b >>= 7;
              k -= 7U;
              if ((unsigned int)i___0 + j___0 > n) {
                return (1);
              }
              {
                while (1) {
                  ;
                  tmp___29 = j___0;
                  j___0--;
                  if (!tmp___29) {
                    goto while_break___12;
                  }
                  tmp___28 = i___0;
                  i___0++;
                  ll[tmp___28] = 0U;
                }
              while_break___12: /* CIL Label */;
              }
              l = 0U;
            }
          }
        }
      }
    while_break___5: /* CIL Label */;
    }
    {
      huft_free(tl);
      bb = b;
      bk = k;
      bl = lbits;
      i___0 = huft_build(ll, nl, 257U, cplens, cplext, &tl, &bl);
    }
    if (i___0 != 0) {
      if (i___0 == 1) {
        {
          fprintf((FILE * /* __restrict  */) stderr, (char const * /* __restrict  */) " incomplete literal tree\n");
          huft_free(tl);
        }
      }
      return (i___0);
    }
    {
      bd = dbits;
      i___0 = huft_build(ll + nl, nd, 0U, cpdist, cpdext, &td, &bd);
    }
    if (i___0 != 0) {
      if (i___0 == 1) {
        {
          fprintf((FILE * /* __restrict  */) stderr, (char const * /* __restrict  */) " incomplete distance tree\n");
          huft_free(td);
        }
      }
      { huft_free(tl); }
      return (i___0);
    }
    { tmp___30 = inflate_codes(tl, td, bl, bd); }
    if (tmp___30) {
      return (1);
    }
    {
      huft_free(tl);
      huft_free(td);
    }
    return (0);
  }
}
int inflate_block(int *e) {
  unsigned int t;
  register ulg b;
  register unsigned int k;
  unsigned int tmp;
  int tmp___0;
  int tmp___1;
  unsigned int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {
    b = bb;
    k = bk;
    {
      while (1) {
        ;
        if (!(k < 1U)) {
          goto while_break;
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
        b |= (ulg)((uch)tmp___1) << k;
        k += 8U;
      }
    while_break: /* CIL Label */;
    }
    *e = (int)b & 1;
    b >>= 1;
    k--;
    {
      while (1) {
        ;
        if (!(k < 2U)) {
          goto while_break___0;
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
        b |= (ulg)((uch)tmp___4) << k;
        k += 8U;
      }
    while_break___0: /* CIL Label */;
    }
    t = (unsigned int)b & 3U;
    b >>= 2;
    k -= 2U;
    bb = b;
    bk = k;
    if (t == 2U) {
      {
        tmp___5 = inflate_dynamic();
      }
      return (tmp___5);
    }
    if (t == 0U) {
      {
        tmp___6 = inflate_stored();
      }
      return (tmp___6);
    }
    if (t == 1U) {
      {
        tmp___7 = inflate_fixed();
      }
      return (tmp___7);
    }
    return (2);
  }
}
int inflate(void) {
  int e;
  int r;
  unsigned int h;

  {
    outcnt = 0U;
    bk = 0U;
    bb = (ulg)0;
    h = 0U;
    {
      while (1) {
        ;
        {
          hufts = 0U;
          r = inflate_block(&e);
        }

        if (hufts > h) {
          h = hufts;
        }
        if (!(!e)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */;
    }
    {
      while (1) {
        ;
        if (!(bk >= 8U)) {
          goto while_break___0;
        }
      }
    while_break___0: /* CIL Label */;
    }
    {
      outcnt = outcnt;
      flush_window();
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
int check_zipfile(int in) {}
int unzip(int in, int out) {
  ulg orig_crc;
  ulg orig_len___0;
  int n;
  uch buf[16];
  int res;
  int tmp;

  unsigned int tmp___6;

  int tmp___8;

  ulg tmp___12;

  {
    {
      orig_crc = (ulg)0;
      orig_len___0 = (ulg)0;
      ifd = in;
      ofd = out;
      updcrc((uch *)((void *)0), 0U);
    }

    if (method == 8) {
      {
        tmp = inflate();
        res = tmp;
      }

    } else {
    }
    if (!pkzip) {
      n = 0;
      {
        while (1) {
          ;
          if (!(n < 8)) {
            goto while_break___0;
          }
          if (inptr < insize) {
            tmp___6 = inptr;
            inptr++;
            tmp___8 = (int)inbuf[tmp___6];
          } else {
            {}
          }
          buf[n] = (uch)tmp___8;
          n++;
        }
      while_break___0: /* CIL Label */;
      }
      orig_crc = (ulg)((int)((ush)buf[0]) | ((int)((ush)buf[1]) << 8)) | ((ulg)((int)((ush) * ((buf + 2) + 0)) | ((int)((ush) * ((buf + 2) + 1)) << 8)) << 16);
      orig_len___0 = (ulg)((int)((ush) * ((buf + 4) + 0)) | ((int)((ush) * ((buf + 4) + 1)) << 8)) | ((ulg)((int)((ush) * (((buf + 4) + 2) + 0)) | ((int)((ush) * (((buf + 4) + 2) + 1)) << 8)) << 16);
    } else {
    }
    { tmp___12 = updcrc(outbuf, 0U); }

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
void bi_init(file_t zipfile) {}
void send_bits(int value, int length) {}
unsigned int bi_reverse(unsigned int code, int len) {}
void bi_windup(void) {}
void copy_block(char *buf, unsigned int len, int header) {}
int level;
void ct_init(ush *attr, int *methodp);
int ct_tally(int dist, int lc);
ulg flush_block(char *buf, ulg stored_len, int eof);
static int extra_lbits[29] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
static int extra_dbits[30] = {0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};
static int extra_blbits[19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 7};
static ct_data dyn_ltree[573];
static ct_data dyn_dtree[61];
static ct_data static_ltree[288];
static ct_data static_dtree[30];
static ct_data bl_tree[39];
static tree_desc l_desc = {dyn_ltree, static_ltree, extra_lbits, 257, 286, 15, 0};
static tree_desc d_desc = {dyn_dtree, static_dtree, extra_dbits, 0, 30, 15, 0};
static tree_desc bl_desc = {bl_tree, (ct_data *)0, extra_blbits, 0, 19, 7, 0};
static ush bl_count[16];
static uch bl_order[19] = {(uch)16, (uch)17, (uch)18, (uch)0, (uch)8, (uch)7, (uch)9, (uch)6, (uch)10, (uch)5, (uch)11, (uch)4, (uch)12, (uch)3, (uch)13, (uch)2, (uch)14, (uch)1, (uch)15};
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
void ct_init(ush *attr, int *methodp) {}
static void init_block(void) {}
static void pqdownheap(ct_data *tree, int k) {}
static void gen_bitlen(tree_desc *desc) {}
static void gen_codes(ct_data *tree, int max_code) {}
static void build_tree___0(tree_desc *desc) {}
static void scan_tree(ct_data *tree, int max_code) {}
static void send_tree(ct_data *tree, int max_code) {}
static int build_bl_tree(void) {}
static void send_all_trees(int lcodes, int dcodes, int blcodes) {}
ulg flush_block(char *buf, ulg stored_len, int eof) {}
int ct_tally(int dist, int lc) {}
static void compress_block(ct_data *ltree, ct_data *dtree) {}
static void set_file_type(void) {}
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
static config configuration_table[10] = {{(ush)0, (ush)0, (ush)0, (ush)0},    {(ush)4, (ush)4, (ush)8, (ush)4},      {(ush)4, (ush)5, (ush)16, (ush)8},     {(ush)4, (ush)6, (ush)32, (ush)32},       {(ush)4, (ush)4, (ush)16, (ush)16},
                                         {(ush)8, (ush)16, (ush)32, (ush)32}, {(ush)8, (ush)16, (ush)128, (ush)128}, {(ush)8, (ush)32, (ush)128, (ush)256}, {(ush)32, (ush)128, (ush)258, (ush)1024}, {(ush)32, (ush)258, (ush)258, (ush)4096}};
static void fill_window(void);
static ulg deflate_fast(void);
int longest_match(IPos cur_match);
void lm_init(int pack_level, ush *flags___0) {}
int longest_match(IPos cur_match) {}
static void fill_window(void) {}
static ulg deflate_fast(void) {}
ulg deflate(void) {}
long header_bytes;
long time_stamp;
int save_orig_name;
int zip(int in, int out);
static ulg crc___0;
int zip(int in, int out) {}
int file_read(char *buf, unsigned int size) {}
static char *license_msg[15] = {(char *)"   Copyright (C) 1992-1993 Jean-loup Gailly",
                                (char *)"   This program is free software; you can redistribute it and/or "
                                        "modify",
                                (char *)"   it under the terms of the GNU General Public License as "
                                        "published by",
                                (char *)"   the Free Software Foundation; either version 2, or (at your "
                                        "option)",
                                (char *)"   any later version.",
                                (char *)"",
                                (char *)"   This program is distributed in the hope that it will be useful,",
                                (char *)"   but WITHOUT ANY WARRANTY; without even the implied warranty of",
                                (char *)"   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the",
                                (char *)"   GNU General Public License for more details.",
                                (char *)"",
                                (char *)"   You should have received a copy of the GNU General Public "
                                        "License",
                                (char *)"   along with this program; if not, write to the Free Software",
                                (char *)"   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.",
                                (char *)0};
extern __attribute__((__nothrow__)) __sighandler_t(__attribute__((__leaf__)) signal)(int __sig, void (*__handler)(int));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) stat)(char const *__restrict __file, struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__)) fstat)(int __fd, struct stat *__buf);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) lstat)(char const *__restrict __file, struct stat *__restrict __buf);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) chmod)(char const *__file, __mode_t __mode);
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern int fflush(FILE *__stream);
extern int printf(char const *__restrict __format, ...);
extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(FILE *__stream);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) memcmp)(void const *__s1, void const *__s2, size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strncpy)(char *__restrict __dest, char const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2), __leaf__)) strcat)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2) __attribute__((__pure__));
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2), __leaf__)) strncmp)(char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
long ifile_size;
int verbose;
extern char *optarg;
extern int optind;
extern int getopt_long(int argc, char *const *argv, char const *shortopts, struct option const *longopts, int *longind);
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) ctime)(time_t const *__timer);
extern int(__attribute__((__nonnull__(1))) open)(char const *__file, int __oflag, ...);
extern __attribute__((__nothrow__)) __off_t(__attribute__((__leaf__)) lseek)(int __fd, __off_t __offset, int __whence);
extern int close(int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) chown)(char const *__file, __uid_t __owner, __gid_t __group);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) isatty)(int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) unlink)(char const *__name);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) atoi)(char const *__nptr) __attribute__((__pure__));
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__)) exit)(int __status);
extern DIR *(__attribute__((__nonnull__(1))) opendir)(char const *__name);
extern int(__attribute__((__nonnull__(1))) closedir)(DIR *__dirp);
extern struct dirent *(__attribute__((__nonnull__(1))) readdir)(DIR *__dirp);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__)) utime)(char const *__file, struct utimbuf const *__file_times);
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
struct option longopts[24] = {{"ascii", 0, (int *)0, 'a'},   {"to-stdout", 0, (int *)0, 'c'}, {"stdout", 0, (int *)0, 'c'},  {"decompress", 0, (int *)0, 'd'}, {"uncompress", 0, (int *)0, 'd'}, {"force", 0, (int *)0, 'f'},     {"help", 0, (int *)0, 'h'},   {"list", 0, (int *)0, 'l'},
                              {"license", 0, (int *)0, 'L'}, {"no-name", 0, (int *)0, 'n'},   {"name", 0, (int *)0, 'N'},    {"quiet", 0, (int *)0, 'q'},      {"silent", 0, (int *)0, 'q'},     {"recursive", 0, (int *)0, 'r'}, {"suffix", 1, (int *)0, 'S'}, {"test", 0, (int *)0, 't'},
                              {"no-time", 0, (int *)0, 'T'}, {"verbose", 0, (int *)0, 'v'},   {"version", 0, (int *)0, 'V'}, {"fast", 0, (int *)0, '1'},       {"best", 0, (int *)0, '9'},       {"lzw", 0, (int *)0, 'Z'},       {"bits", 1, (int *)0, 'b'},   {(char const *)0, 0, (int *)0, 0}};
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
static void usage(void) {}
static char *help_msg[18] = {(char *)" -c --stdout      write on standard output, keep original files "
                                     "unchanged",
                             (char *)" -d --decompress  decompress",
                             (char *)" -f --force       force overwrite of output file and compress "
                                     "links",
                             (char *)" -h --help        give this help",
                             (char *)" -l --list        list compressed file contents",
                             (char *)" -L --license     display software license",
                             (char *)" -n --no-name     do not save or restore the original name and "
                                     "time stamp",
                             (char *)" -N --name        save or restore the original name and time stamp",
                             (char *)" -q --quiet       suppress all warnings",
                             (char *)" -r --recursive   operate recursively on directories",
                             (char *)" -S .suf  --suffix .suf     use suffix .suf on compressed files",
                             (char *)" -t --test        test compressed file integrity",
                             (char *)" -v --verbose     verbose mode",
                             (char *)" -V --version     display version number",
                             (char *)" -1 --fast        compress faster",
                             (char *)" -9 --best        compress better",
                             (char *)" file...          files to (de)compress. If none given, use "
                                     "standard input.",
                             (char *)0};
static void help(void) {}
static void license(void) {}
static void version(void) {}
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

  {
    {
      progname = basename(*(argv + 0));
      proglen = (int)strlen((char const *)progname);
    }
    if (proglen > 4) {
      {
        tmp = strcmp((char const *)((progname + proglen) - 4), ".exe");
      }
      if (tmp == 0) {
        *(progname + (proglen - 4)) = (char)'\000';
      }
    }
    { env = add_envopt(&argc, &argv, (char *)"GZIP"); }
    if ((unsigned long)env != (unsigned long)((void *)0)) {
      args = argv;
    }
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
    if (tmp___5 == 0) {
      decompress = 1;
    } else {
      { tmp___6 = strncmp((char const *)progname, "gun", (size_t)3); }
      if (tmp___6 == 0) {
        decompress = 1;
      } else {
        { tmp___3 = strcmp((char const *)(progname + 1), "cat"); }
        if (tmp___3 == 0) {
          to_stdout = 1;
          decompress = to_stdout;
        } else {
          { tmp___4 = strcmp((char const *)progname, "gzcat"); }
          if (tmp___4 == 0) {
            to_stdout = 1;
            decompress = to_stdout;
          }
        }
      }
    }
    {
      strncpy((char * /* __restrict  */)(z_suffix), (char const * /* __restrict  */) ".gz", sizeof(z_suffix) - 1UL);
      z_len = (int)strlen((char const *)(z_suffix));
    }
    {
      while (1) {
        ;
        { optc = getopt_long(argc, (char *const *)argv, "ab:cdfhH?lLmMnNqrS:tvVZ123456789", (struct option const *)(longopts), (int *)0); }
        if (!(optc != -1)) {
          goto while_break;
        }
        {
          if (optc == 97) {
            goto case_97;
          }
          if (optc == 98) {
            goto case_98;
          }
          if (optc == 99) {
            goto case_99;
          }
          if (optc == 100) {
            goto case_100;
          }
          if (optc == 102) {
            goto case_102;
          }
          if (optc == 104) {
            goto case_104;
          }
          if (optc == 72) {
            goto case_104;
          }
          if (optc == 63) {
            goto case_104;
          }
          if (optc == 108) {
            goto case_108;
          }
          if (optc == 76) {
            goto case_76;
          }
          if (optc == 109) {
            goto case_109;
          }
          if (optc == 77) {
            goto case_77;
          }
          if (optc == 110) {
            goto case_110;
          }
          if (optc == 78) {
            goto case_78;
          }
          if (optc == 113) {
            goto case_113;
          }
          if (optc == 114) {
            goto case_114;
          }
          if (optc == 83) {
            goto case_83;
          }
          if (optc == 116) {
            goto case_116;
          }
          if (optc == 118) {
            goto case_118;
          }
          if (optc == 86) {
            goto case_86;
          }
          if (optc == 90) {
            goto case_90;
          }
          if (optc == 49) {
            goto case_49;
          }
          if (optc == 50) {
            goto case_49;
          }
          if (optc == 51) {
            goto case_49;
          }
          if (optc == 52) {
            goto case_49;
          }
          if (optc == 53) {
            goto case_49;
          }
          if (optc == 54) {
            goto case_49;
          }
          if (optc == 55) {
            goto case_49;
          }
          if (optc == 56) {
            goto case_49;
          }
          if (optc == 57) {
            goto case_49;
          }
          goto switch_default;
        case_97: /* CIL Label */
          ascii = 1;
          goto switch_break;
        case_98 : /* CIL Label */
        {
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
        case_104 : /* CIL Label */

        {
          help();
          do_exit(0);
        }
          goto switch_break;
        case_108: /* CIL Label */
          to_stdout = 1;
          decompress = to_stdout;
          list = decompress;
          goto switch_break;
        case_76 : /* CIL Label */
        {
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
        case_83 : /* CIL Label */
        {
          z_len = (int)strlen((char const *)optarg);
          strcpy((char * /* __restrict  */)(z_suffix), (char const * /* __restrict  */)optarg);
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
        case_86 : /* CIL Label */
        {
          version();
          do_exit(0);
        }
          goto switch_break;
        case_90 : /* CIL Label */
        {
          fprintf((FILE * /* __restrict  */) stderr,
                  (char const * /* __restrict  */) "%s: -Z not supported in "
                                                   "this version\n",
                  progname);
          usage();
          do_exit(1);
        }
          goto switch_break;
        case_49: /* CIL Label */

          level = optc - 48;
          goto switch_break;
        switch_default : /* CIL Label */
        {
          usage();
          do_exit(1);
        }
        switch_break: /* CIL Label */;
        }
      }
    while_break: /* CIL Label */;
    }
    if (no_time < 0) {
      no_time = decompress;
    }
    if (no_name < 0) {
      no_name = decompress;
    }
    file_count = argc - optind;
    if (ascii) {
      if (!quiet) {
        {
          fprintf((FILE * /* __restrict  */) stderr,
                  (char const * /* __restrict  */) "%s: option --ascii ignored "
                                                   "on this system\n",
                  progname);
        }
      }
    }
    if (z_len == 0) {
      if (!decompress) {
        {
          fprintf((FILE * /* __restrict  */) stderr, (char const * /* __restrict  */) "%s: incorrect suffix \'%s\'\n", progname, optarg);
          do_exit(1);
        }
      } else {
        goto _L;
      }
    } else {
    _L:
      if (z_len > 30) {
        {
          fprintf((FILE * /* __restrict  */) stderr, (char const * /* __restrict  */) "%s: incorrect suffix \'%s\'\n", progname, optarg);
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
      while_break___0: /* CIL Label */;
      }
    } else {
      { treat_stdin(); }
    }
    if (list) {
      if (!quiet) {
        if (file_count > 1) {
          {
            do_list(-1, -1);
          }
        }
      }
    }
    { do_exit(exit_code); }
    return (exit_code);
  }
}
static void treat_stdin(void) {}
static void treat_file(char *iname) {

  int tmp;
  int tmp___0;

  int tmp___2;
  int tmp___3;
  int tmp___4;

  int tmp___11;
  int tmp___12;

  {
    { tmp = strcmp((char const *)iname, "-"); }

    { tmp___0 = get_istat(iname, &istat); }

    ifile_size = istat.st_size;
    if (no_time) {
      if (!list) {
        time_stamp = 0L;
      } else {
      }
    } else {
    }
    if (to_stdout) {

    } else {
      { tmp___2 = make_ofname(); }
    }
    if (ascii) {

    } else {
      tmp___3 = 0;
    }
    { ifd = open((char const *)(ifname), tmp___3, 384); }

    {
      clear_bufs();
      part_nb = 0;
    }
    if (decompress) {
      {
        method = get_method(ifd);
      }
    }

    if (to_stdout) {
      {
      }
    } else {
      { tmp___4 = create_outfile(); }
    }
    if (!save_orig_name) {
      save_orig_name = !no_name;
    }

    {
      while (1) {
        ;
        { tmp___11 = (*work)(ifd, ofd); }

        if (!decompress) {

        } else {
          if (last_member) {

          } else {
            if (inptr == insize) {
              goto while_break;
            }
          }
        }
      }
    while_break: /* CIL Label */;
    }
    { close(ifd); }
    if (!to_stdout) {
      {
        tmp___12 = close(ofd);
      }
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

  {
    flags___0 = 193;

    {
      while (1) {
        ;
        { tmp = check_ofname(); }
        if (tmp != 0) {
          {
          }
          return (1);
        }
        {
          remove_ofname = 1;
          ofd = open((char const *)(ofname), flags___0, 384);
        }

        { tmp___0 = fstat(ofd, &ostat); }

        { tmp___1 = name_too_long(ofname, &ostat); }
        if (!tmp___1) {
          return (0);
        }

        {}
      };
    }
  }
}
static int do_stat(char *name, struct stat *sbuf) {
  int *tmp;
  int tmp___0;

  {
    {
      tmp = __errno_location();
      *tmp = 0;
    }
    if (!to_stdout) {
      if (!force) {
        {
          tmp___0 = lstat((char const * /* __restrict  */)name, (struct stat * /* __restrict  */) sbuf);
        }
        return (tmp___0);
      }
    }
  }
}
static char *known_suffixes[9] = {z_suffix, (char *)".gz", (char *)".z", (char *)".taz", (char *)".tgz", (char *)"-gz", (char *)"-z", (char *)"_z", (char *)((void *)0)};
static char *get_suffix(char *name) {
  int nlen;
  int slen;
  char suffix[33];
  char **suf;
  int tmp;
  int s;
  int tmp___0;
  int tmp___1;

  {
    {
      suf = known_suffixes;
      tmp = strcmp((char const *)(z_suffix), "z");
    }

    { nlen = (int)strlen((char const *)name); }
    if (nlen <= 32) {
      {
        strcpy((char * /* __restrict  */)(suffix), (char const * /* __restrict  */)name);
      }
    } else {
    }
    {
      strlwr(suffix);
      slen = (int)strlen((char const *)(suffix));
    }
    {
      while (1) {
        ;
        {
          tmp___0 = (int)strlen((char const *)*suf);
          s = tmp___0;
        }
        if (slen > s) {
          if ((int)suffix[(slen - s) - 1] != 47) {
            {
              tmp___1 = strcmp((char const *)((suffix + slen) - s), (char const *)*suf);
            }
            if (tmp___1 == 0) {
              return ((name + nlen) - s);
            }
          }
        }
      };
    }
  }
}
static char *suffixes[6] = {z_suffix, (char *)".gz", (char *)".z", (char *)"-z", (char *)".Z", (char *)((void *)0)};
static int get_istat(char *iname, struct stat *sbuf) {

  char **suf;

  int tmp;

  {
    {
      suf = suffixes;
      strcpy((char * /* __restrict  */)(ifname), (char const * /* __restrict  */)iname);
      tmp = do_stat(ifname, sbuf);
    }
    if (tmp == 0) {
      return (0);
    }

    {

    }

    {

    } {}
  }
}
static int make_ofname(void) {
  char *suff;
  int tmp;
  int tmp___0;

  {
    {
      strcpy((char * /* __restrict  */)(ofname), (char const * /* __restrict  */)(ifname));
      suff = get_suffix(ofname);
    }
    if (decompress) {

      {
        strlwr(suff);
        tmp = strcmp((char const *)suff, ".tgz");
      }
      if (tmp == 0) {
        {
        }
      } else {
        { tmp___0 = strcmp((char const *)suff, ".taz"); }
        if (tmp___0 == 0) {
          {
          }
        } else {
          *suff = (char)'\000';
        }
      }
    } else {
    }
    return (0);
  }
}
static int get_method(int in) {
  uch flags___0;
  char magic[2];
  ulg stamp;

  int tmp___6;
  int tmp___7;
  unsigned int tmp___8;

  int tmp___10;
  unsigned int tmp___11;

  int tmp___13;
  unsigned int tmp___14;

  int tmp___16;
  unsigned int tmp___17;

  int tmp___19;
  unsigned int tmp___20;

  int tmp___22;
  unsigned int tmp___23;

  int tmp___25;
  unsigned int tmp___26;

  int tmp___28;
  unsigned int tmp___29;
  unsigned int tmp___30;

  char c;
  unsigned int tmp___45;

  int tmp___61;
  int tmp___62;

  {
    if (force) {

    } else {
      ;
      if (inptr < insize) {

      } else {
        {
          tmp___6 = fill_inbuf(0);
          tmp___7 = tmp___6;
        }
      }
      magic[0] = (char)tmp___7;
      if (inptr < insize) {
        tmp___8 = inptr;
        inptr++;
        tmp___10 = (int)inbuf[tmp___8];
      } else {
        {}
      }
      magic[1] = (char)tmp___10;
    }
    {
      method = -1;
      part_nb++;
      header_bytes = 0L;
      last_member = 0;
      tmp___61 = memcmp((void const *)(magic), (void const *)"\037\213", (size_t)2);
    }
    if (tmp___61 == 0) {
      goto _L___4;
    } else {

      if (tmp___62 == 0) {
      _L___4:;
        if (inptr < insize) {
          tmp___11 = inptr;
          inptr++;
          tmp___13 = (int)inbuf[tmp___11];
        } else {
          {}
        }
        method = tmp___13;

        work = &unzip;
        if (inptr < insize) {
          tmp___14 = inptr;
          inptr++;
          tmp___16 = (int)inbuf[tmp___14];
        } else {
          {}
        }
        flags___0 = (uch)tmp___16;

        if (inptr < insize) {
          tmp___17 = inptr;
          inptr++;
          tmp___19 = (int)inbuf[tmp___17];
        } else {
          {}
        }
        stamp = (ulg)tmp___19;
        if (inptr < insize) {
          tmp___20 = inptr;
          inptr++;
          tmp___22 = (int)inbuf[tmp___20];
        } else {
          {}
        }
        stamp |= (ulg)tmp___22 << 8;
        if (inptr < insize) {
          tmp___23 = inptr;
          inptr++;
          tmp___25 = (int)inbuf[tmp___23];
        } else {
          {}
        }
        stamp |= (ulg)tmp___25 << 16;
        if (inptr < insize) {
          tmp___26 = inptr;
          inptr++;
          tmp___28 = (int)inbuf[tmp___26];
        } else {
          {}
        }
        stamp |= (ulg)tmp___28 << 24;

        if (inptr < insize) {
          tmp___29 = inptr;
          inptr++;
        } else {
        }
        if (inptr < insize) {
          tmp___30 = inptr;
          inptr++;
        } else {
        }

        if (((int)flags___0 & 8) != 0) {
          if (no_name) {
            goto _L___0;
          } else {
            if (to_stdout) {

            } else {
              ;
              if (part_nb > 1) {
              _L___0 : {
                while (1) {
                  ;
                  if (inptr < insize) {
                    tmp___45 = inptr;
                    inptr++;
                    c = (char)inbuf[tmp___45];
                  } else {
                    {}
                  }
                  if (!((int)c != 0)) {
                    goto while_break___0;
                  }
                }
              while_break___0: /* CIL Label */;
              }
              } else {
                {

                } {}
              }
            }
          }
        }

        if (part_nb == 1) {
          header_bytes = (long)((unsigned long)inptr + 2UL * sizeof(long));
        }
      } else {
      }
    }
    if (method >= 0) {
      return (method);
    }
  }
}
static int first_time = 1;
static char *methods[9] = {(char *)"store", (char *)"compr", (char *)"pack ", (char *)"lzh  ", (char *)"", (char *)"", (char *)"", (char *)"", (char *)"defla"};
static void do_list(int ifd___0, int method___0) {}
static int same_file(struct stat *stat1, struct stat *stat2) {}
static int name_too_long(char *name, struct stat *statb) {
  int s;
  int tmp;
  char c;
  struct stat tstat;
  int res;
  int tmp___0;

  int tmp___2;

  {
    {
      tmp = (int)strlen((char const *)name);
      s = tmp;
      c = *(name + (s - 1));
      tstat = *statb;
      *(name + (s - 1)) = (char)'\000';
      tmp___0 = stat((char const * /* __restrict  */)name, (struct stat * /* __restrict  */)(&tstat));
    }
    if (tmp___0 == 0) {
      {
      }

    } else {
      tmp___2 = 0;
    }
    res = tmp___2;
    *(name + (s - 1)) = c;
    return (res);
  }
}
static void shorten_name(char *name) {}
static int check_ofname(void) {
  struct stat ostat;
  int *tmp;
  int *tmp___0;
  int tmp___1;

  {
    {
      tmp = __errno_location();
      *tmp = 0;
    }
    {
      while (1) {
        ;
        { tmp___1 = stat((char const * /* __restrict  */)(ofname), (struct stat * /* __restrict  */)(&ostat)); }

        { tmp___0 = __errno_location(); }
        if (*tmp___0 != 36) {
          return (0);
        }
      };
    }

    {}
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

    {
      chown((char const *)(ofname), ifstat->st_uid, ifstat->st_gid);
      remove_ofname = 0;
      chmod((char const *)(ifname), (__mode_t)511);
      tmp___0 = unlink((char const *)(ifname));
    }

    return;
  }
}
static void treat_dir(char *dir) {}
static int in_exit = 0;
static void do_exit(int exitcode) {

  {

    in_exit = 1;

    { exit(exitcode); }
  }
}
void abort_gzip(void) {}
