typedef int Int32;
typedef unsigned char Bool;
typedef unsigned char UChar;
typedef unsigned long size_t;
typedef long __off_t;
typedef long __off64_t;
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
struct __anonstruct_bz_stream_26 {
  char *next_in;
  unsigned int avail_in;
  unsigned int total_in_lo32;
  unsigned int total_in_hi32;
  char *next_out;
  unsigned int avail_out;
  unsigned int total_out_lo32;
  unsigned int total_out_hi32;
  void *state;
  void *(*bzalloc)(void *, int, int);
  void (*bzfree)(void *, void *);
  void *opaque;
};
typedef struct __anonstruct_bz_stream_26 bz_stream;
typedef unsigned int UInt32;
typedef unsigned short UInt16;
struct __anonstruct_DState_28 {
  bz_stream *strm;
  Int32 state;
  UChar state_out_ch;
  Int32 state_out_len;
  Bool blockRandomised;
  Int32 rNToGo;
  Int32 rTPos;
  UInt32 bsBuff;
  Int32 bsLive;
  Int32 blockSize100k;
  Bool smallDecompress;
  Int32 currBlockNo;
  Int32 verbosity;
  Int32 origPtr;
  UInt32 tPos;
  Int32 k0;
  Int32 unzftab[256];
  Int32 nblock_used;
  Int32 cftab[257];
  Int32 cftabCopy[257];
  UInt32 *tt;
  UInt16 *ll16;
  UChar *ll4;
  UInt32 storedBlockCRC;
  UInt32 storedCombinedCRC;
  UInt32 calculatedBlockCRC;
  UInt32 calculatedCombinedCRC;
  Int32 nInUse;
  Bool inUse[256];
  Bool inUse16[16];
  UChar seqToUnseq[256];
  UChar mtfa[4096];
  Int32 mtfbase[16];
  UChar selector[18002];
  UChar selectorMtf[18002];
  UChar len[6][258];
  Int32 limit[6][258];
  Int32 base[6][258];
  Int32 perm[6][258];
  Int32 minLens[6];
  Int32 save_i;
  Int32 save_j;
  Int32 save_t;
  Int32 save_alphaSize;
  Int32 save_nGroups;
  Int32 save_nSelectors;
  Int32 save_EOB;
  Int32 save_groupNo;
  Int32 save_groupPos;
  Int32 save_nextSym;
  Int32 save_nblockMAX;
  Int32 save_nblock;
  Int32 save_es;
  Int32 save_N;
  Int32 save_curr;
  Int32 save_zt;
  Int32 save_zn;
  Int32 save_zvec;
  Int32 save_zj;
  Int32 save_gSel;
  Int32 save_gMinlen;
  Int32 *save_gLimit;
  Int32 *save_gBase;
  Int32 *save_gPerm;
};
typedef struct __anonstruct_DState_28 DState;
struct __anonstruct_EState_27 {
  bz_stream *strm;
  Int32 mode;
  Int32 state;
  UInt32 avail_in_expect;
  UInt32 *arr1;
  UInt32 *arr2;
  UInt32 *ftab;
  Int32 origPtr;
  UInt32 *ptr;
  UChar *block;
  UInt16 *mtfv;
  UChar *zbits;
  Int32 workFactor;
  UInt32 state_in_ch;
  Int32 state_in_len;
  Int32 rNToGo;
  Int32 rTPos;
  Int32 nblock;
  Int32 nblockMAX;
  Int32 numZ;
  Int32 state_out_pos;
  Int32 nInUse;
  Bool inUse[256];
  UChar unseqToSeq[256];
  UInt32 bsBuff;
  Int32 bsLive;
  UInt32 blockCRC;
  UInt32 combinedCRC;
  Int32 verbosity;
  Int32 blockNo;
  Int32 blockSize100k;
  Int32 nMTF;
  Int32 mtfFreq[258];
  UChar selector[18002];
  UChar selectorMtf[18002];
  UChar len[6][258];
  Int32 code[6][258];
  Int32 rfreq[6][258];
  UInt32 len_pack[258][4];
};
typedef struct __anonstruct_EState_27 EState;
typedef void BZFILE;
typedef char Char;
struct __anonstruct_bzFile_29 {
  FILE *handle;
  Char buf[5000];
  Int32 bufN;
  Bool writing;
  bz_stream strm;
  Int32 lastErr;
  Bool initialisedOk;
};
typedef struct __anonstruct_bzFile_29 bzFile;
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
struct utimbuf {
  __time_t actime;
  __time_t modtime;
};
typedef short Int16;
typedef int IntNative;
struct __anonstruct_UInt64_56 {
  UChar b[8];
};
typedef struct __anonstruct_UInt64_56 UInt64;
struct zzzz {
  Char *name;
  struct zzzz *link;
};
typedef struct zzzz Cell;

void BZ2_bz__AssertH__fail(int errcode);
void BZ2_hbAssignCodes(Int32 *code, UChar *length, Int32 minLen, Int32 maxLen,
                       Int32 alphaSize);
void BZ2_hbMakeCodeLengths(UChar *len, Int32 *freq, Int32 alphaSize,
                           Int32 maxLen);
void BZ2_hbCreateDecodeTables(Int32 *limit, Int32 *base, Int32 *perm,
                              UChar *length, Int32 minLen, Int32 maxLen,
                              Int32 alphaSize);
void BZ2_hbMakeCodeLengths(UChar *len, Int32 *freq, Int32 alphaSize,
                           Int32 maxLen) {
  Int32 nNodes;
  Int32 nHeap;
  Int32 n1;
  Int32 n2;
  Int32 i;
  Int32 j;
  Int32 k;
  Bool tooLong;
  Int32 heap[260];
  Int32 weight[516];
  Int32 parent[516];
  int tmp;
  Int32 zz;
  Int32 tmp___0;
  Int32 zz___0;
  Int32 yy;
  Int32 tmp___1;
  Int32 zz___1;
  Int32 yy___0;
  Int32 tmp___2;
  Int32 tmp___3;
  int tmp___4;
  Int32 zz___2;
  Int32 tmp___5;

  {

    ;
    nNodes = alphaSize;
    nHeap = 0;

    {
      while (1) {
        ;
        if (!(i <= alphaSize)) {
          goto while_break___1;
        }

        nHeap++;
        heap[nHeap] = i;

        i++;
      }
    while_break___1: /* CIL Label */;
    }

    {
      while (1) {
        ;
        if (!(nHeap > 1)) {
          goto while_break___3;
        }
        n1 = heap[1];
        heap[1] = heap[nHeap];
        nHeap--;
        zz___0 = 1;
        tmp___1 = heap[zz___0];
        {
          while (1) {
            ;
            yy = zz___0 << 1;
            if (yy > nHeap) {
              goto while_break___4;
            }
            {
              if (weight[heap[yy + 1]] < weight[heap[yy]]) {
                yy++;
              }
            }

            heap[zz___0] = heap[yy];
            zz___0 = yy;
          }
        while_break___4: /* CIL Label */;
        }
        heap[zz___0] = tmp___1;
        n2 = heap[1];
        heap[1] = heap[nHeap];
        nHeap--;

        nNodes++;
        tmp___3 = nNodes;
        parent[n2] = tmp___3;
        parent[n1] = tmp___3;
        { tmp___4 = weight[n1] & 255; }

        weight[nNodes] = (Int32)((((unsigned int)weight[n1] & 4294967040U) +
                                  ((unsigned int)weight[n2] & 4294967040U)) |
                                 (unsigned int)(1 + tmp___4));
        parent[nNodes] = -1;
        nHeap++;
        heap[nHeap] = nNodes;
      }
    while_break___3: /* CIL Label */;
    }

    i = 1;
    {
      while (1) {
        ;
        if (!(i <= alphaSize)) {
          goto while_break___7;
        }
        j = 0;
        k = i;
        {
          while (1) {
            ;
            if (!(parent[k] >= 0)) {
              goto while_break___8;
            }
            k = parent[k];
            j++;
          }
        while_break___8: /* CIL Label */;
        }
        *(len + (i - 1)) = (UChar)j;

        i++;
      }
    while_break___7: /* CIL Label */;
    }
  }
}
void BZ2_hbAssignCodes(Int32 *code, UChar *length, Int32 minLen, Int32 maxLen,
                       Int32 alphaSize) {
  Int32 n;
  Int32 vec;
  Int32 i;

  {
    vec = 0;

    {
      while (1) {
        ;
        if (!(n <= maxLen)) {
          goto while_break;
        }
        i = 0;
        {
          while (1) {
            ;
            if (!(i < alphaSize)) {
              goto while_break___0;
            }
            if ((int)*(length + i) == n) {
              *(code + i) = vec;
              vec++;
            }
            i++;
          }
        while_break___0: /* CIL Label */;
        }
        vec <<= 1;
        n++;
      }
    while_break: /* CIL Label */;
    }
  }
}

extern int fprintf(FILE *__restrict __stream, char const *__restrict __format,
                   ...);
Int32 BZ2_indexIntoF(Int32 indx, Int32 *cftab);
Int32 BZ2_decompress(DState *s);

UInt32 BZ2_crc32Table[256] = {
    (UInt32)0L,          (UInt32)79764919L,   (UInt32)159529838L,
    (UInt32)222504665L,  (UInt32)319059676L,  (UInt32)398814059L,
    (UInt32)445009330L,  (UInt32)507990021L,  (UInt32)638119352L,
    (UInt32)583659535L,  (UInt32)797628118L,  (UInt32)726387553L,
    (UInt32)890018660L,  (UInt32)835552979L,  (UInt32)1015980042L,
    (UInt32)944750013L,  (UInt32)1276238704L, (UInt32)1221641927L,
    (UInt32)1167319070L, (UInt32)1095957929L, (UInt32)1595256236L,
    (UInt32)1540665371L, (UInt32)1452775106L, (UInt32)1381403509L,
    (UInt32)1780037320L, (UInt32)1859660671L, (UInt32)1671105958L,
    (UInt32)1733955601L, (UInt32)2031960084L, (UInt32)2111593891L,
    (UInt32)1889500026L, (UInt32)1952343757L, (UInt32)2552477408L,
    (UInt32)2632100695L, (UInt32)2443283854L, (UInt32)2506133561L,
    (UInt32)2334638140L, (UInt32)2414271883L, (UInt32)2191915858L,
    (UInt32)2254759653L, (UInt32)3190512472L, (UInt32)3135915759L,
    (UInt32)3081330742L, (UInt32)3009969537L, (UInt32)2905550212L,
    (UInt32)2850959411L, (UInt32)2762807018L, (UInt32)2691435357L,
    (UInt32)3560074640L, (UInt32)3505614887L, (UInt32)3719321342L,
    (UInt32)3648080713L, (UInt32)3342211916L, (UInt32)3287746299L,
    (UInt32)3467911202L, (UInt32)3396681109L, (UInt32)4063920168L,
    (UInt32)4143685023L, (UInt32)4223187782L, (UInt32)4286162673L,
    (UInt32)3779000052L, (UInt32)3858754371L, (UInt32)3904687514L,
    (UInt32)3967668269L, (UInt32)881225847L,  (UInt32)809987520L,
    (UInt32)1023691545L, (UInt32)969234094L,  (UInt32)662832811L,
    (UInt32)591600412L,  (UInt32)771767749L,  (UInt32)717299826L,
    (UInt32)311336399L,  (UInt32)374308984L,  (UInt32)453813921L,
    (UInt32)533576470L,  (UInt32)25881363L,   (UInt32)88864420L,
    (UInt32)134795389L,  (UInt32)214552010L,  (UInt32)2023205639L,
    (UInt32)2086057648L, (UInt32)1897238633L, (UInt32)1976864222L,
    (UInt32)1804852699L, (UInt32)1867694188L, (UInt32)1645340341L,
    (UInt32)1724971778L, (UInt32)1587496639L, (UInt32)1516133128L,
    (UInt32)1461550545L, (UInt32)1406951526L, (UInt32)1302016099L,
    (UInt32)1230646740L, (UInt32)1142491917L, (UInt32)1087903418L,
    (UInt32)2896545431L, (UInt32)2825181984L, (UInt32)2770861561L,
    (UInt32)2716262478L, (UInt32)3215044683L, (UInt32)3143675388L,
    (UInt32)3055782693L, (UInt32)3001194130L, (UInt32)2326604591L,
    (UInt32)2389456536L, (UInt32)2200899649L, (UInt32)2280525302L,
    (UInt32)2578013683L, (UInt32)2640855108L, (UInt32)2418763421L,
    (UInt32)2498394922L, (UInt32)3769900519L, (UInt32)3832873040L,
    (UInt32)3912640137L, (UInt32)3992402750L, (UInt32)4088425275L,
    (UInt32)4151408268L, (UInt32)4197601365L, (UInt32)4277358050L,
    (UInt32)3334271071L, (UInt32)3263032808L, (UInt32)3476998961L,
    (UInt32)3422541446L, (UInt32)3585640067L, (UInt32)3514407732L,
    (UInt32)3694837229L, (UInt32)3640369242L, (UInt32)1762451694L,
    (UInt32)1842216281L, (UInt32)1619975040L, (UInt32)1682949687L,
    (UInt32)2047383090L, (UInt32)2127137669L, (UInt32)1938468188L,
    (UInt32)2001449195L, (UInt32)1325665622L, (UInt32)1271206113L,
    (UInt32)1183200824L, (UInt32)1111960463L, (UInt32)1543535498L,
    (UInt32)1489069629L, (UInt32)1434599652L, (UInt32)1363369299L,
    (UInt32)622672798L,  (UInt32)568075817L,  (UInt32)748617968L,
    (UInt32)677256519L,  (UInt32)907627842L,  (UInt32)853037301L,
    (UInt32)1067152940L, (UInt32)995781531L,  (UInt32)51762726L,
    (UInt32)131386257L,  (UInt32)177728840L,  (UInt32)240578815L,
    (UInt32)269590778L,  (UInt32)349224269L,  (UInt32)429104020L,
    (UInt32)491947555L,  (UInt32)4046411278L, (UInt32)4126034873L,
    (UInt32)4172115296L, (UInt32)4234965207L, (UInt32)3794477266L,
    (UInt32)3874110821L, (UInt32)3953728444L, (UInt32)4016571915L,
    (UInt32)3609705398L, (UInt32)3555108353L, (UInt32)3735388376L,
    (UInt32)3664026991L, (UInt32)3290680682L, (UInt32)3236090077L,
    (UInt32)3449943556L, (UInt32)3378572211L, (UInt32)3174993278L,
    (UInt32)3120533705L, (UInt32)3032266256L, (UInt32)2961025959L,
    (UInt32)2923101090L, (UInt32)2868635157L, (UInt32)2813903052L,
    (UInt32)2742672763L, (UInt32)2604032198L, (UInt32)2683796849L,
    (UInt32)2461293480L, (UInt32)2524268063L, (UInt32)2284983834L,
    (UInt32)2364738477L, (UInt32)2175806836L, (UInt32)2238787779L,
    (UInt32)1569362073L, (UInt32)1498123566L, (UInt32)1409854455L,
    (UInt32)1355396672L, (UInt32)1317987909L, (UInt32)1246755826L,
    (UInt32)1192025387L, (UInt32)1137557660L, (UInt32)2072149281L,
    (UInt32)2135122070L, (UInt32)1912620623L, (UInt32)1992383480L,
    (UInt32)1753615357L, (UInt32)1816598090L, (UInt32)1627664531L,
    (UInt32)1707420964L, (UInt32)295390185L,  (UInt32)358241886L,
    (UInt32)404320391L,  (UInt32)483945776L,  (UInt32)43990325L,
    (UInt32)106832002L,  (UInt32)186451547L,  (UInt32)266083308L,
    (UInt32)932423249L,  (UInt32)861060070L,  (UInt32)1041341759L,
    (UInt32)986742920L,  (UInt32)613929101L,  (UInt32)542559546L,
    (UInt32)756411363L,  (UInt32)701822548L,  (UInt32)3316196985L,
    (UInt32)3244833742L, (UInt32)3425377559L, (UInt32)3370778784L,
    (UInt32)3601682597L, (UInt32)3530312978L, (UInt32)3744426955L,
    (UInt32)3689838204L, (UInt32)3819031489L, (UInt32)3881883254L,
    (UInt32)3928223919L, (UInt32)4007849240L, (UInt32)4037393693L,
    (UInt32)4100235434L, (UInt32)4180117107L, (UInt32)4259748804L,
    (UInt32)2310601993L, (UInt32)2373574846L, (UInt32)2151335527L,
    (UInt32)2231098320L, (UInt32)2596047829L, (UInt32)2659030626L,
    (UInt32)2470359227L, (UInt32)2550115596L, (UInt32)2947551409L,
    (UInt32)2876312838L, (UInt32)2788305887L, (UInt32)2733848168L,
    (UInt32)3165939309L, (UInt32)3094707162L, (UInt32)3040238851L,
    (UInt32)2985771188L};
void BZ2_blockSort(EState *s);
void BZ2_compressBlock(EState *s, Bool is_last_block);
void BZ2_bsInitWrite(EState *s);
void BZ2_bsInitWrite(EState *s) { s->bsLive = 0; }
static void bsFinishWrite(EState *s) {

  while (1) {
    ;
    if (!(s->bsLive > 0)) {
      goto while_break;
    }
    *(s->zbits + s->numZ) = (UChar)(s->bsBuff >> 24);
    (s->numZ)++;
    s->bsBuff <<= 8;
    s->bsLive -= 8;
  }
while_break: /* CIL Label */;
}
__inline static void bsW(EState *s, Int32 n, UInt32 v) {

  {
    while (1) {
      ;
      if (!(s->bsLive >= 8)) {
        goto while_break;
      }
      *(s->zbits + s->numZ) = (UChar)(s->bsBuff >> 24);
      (s->numZ)++;
      s->bsBuff <<= 8;
      s->bsLive -= 8;
    }
  while_break: /* CIL Label */;
  }
  s->bsBuff |= v << ((32 - s->bsLive) - n);
  s->bsLive += n;
}
static void bsPutUInt32(EState *s, UInt32 u) {

  bsW(s, 8, (UInt32)((long)(u >> 24) & 255L));
  bsW(s, 8, (UInt32)((long)(u >> 16) & 255L));
  bsW(s, 8, (UInt32)((long)(u >> 8) & 255L));
  bsW(s, 8, (UInt32)((long)u & 255L));
}
static void bsPutUChar(EState *s, UChar c) { bsW(s, 8, (UInt32)c); }
static void makeMaps_e(EState *s) {
  Int32 i;

  {
    s->nInUse = 0;
    i = 0;
    {
      while (1) {
        ;
        if (!(i < 256)) {
          goto while_break;
        }
        if (s->inUse[i]) {
          s->unseqToSeq[i] = (UChar)s->nInUse;
          (s->nInUse)++;
        }
        i++;
      }
    while_break: /* CIL Label */;
    }
  }
}
static void generateMTFValues(EState *s) {
  UChar yy[256];
  Int32 i;
  Int32 j;
  Int32 zPend;
  Int32 wr;
  Int32 EOB;
  UInt32 *ptr;
  UChar *block;
  UInt16 *mtfv;
  UChar ll_i;
  register UChar rtmp;
  register UChar *ryy_j;
  register UChar rll_i;
  register UChar rtmp2;

  {
    {
      ptr = s->ptr;
      block = s->block;
      mtfv = s->mtfv;
      makeMaps_e(s);
      EOB = s->nInUse + 1;
    }

    wr = 0;
    zPend = 0;
    i = 0;
    {
      while (1) {
        ;
        if (!(i < s->nInUse)) {
          goto while_break___0;
        }
        yy[i] = (UChar)i;
        i++;
      }
    while_break___0: /* CIL Label */;
    }
    i = 0;
    {
      while (1) {
        ;
        if (!(i < s->nblock)) {
          goto while_break___1;
        }
        j = (Int32)(*(ptr + i) - 1U);
        if (j < 0) {
          j += s->nblock;
        }
        ll_i = s->unseqToSeq[*(block + j)];
        if ((int)yy[0] == (int)ll_i) {
          zPend++;
        } else {
          if (zPend > 0) {
            zPend--;
            {
              while (1) {
                ;
                if (zPend & 1) {
                  *(mtfv + wr) = (UInt16)1;
                  wr++;

                } else {
                  *(mtfv + wr) = (UInt16)0;
                  wr++;
                }
                if (zPend < 2) {
                  goto while_break___2;
                }
                zPend = (zPend - 2) / 2;
              }
            while_break___2: /* CIL Label */;
            }
            zPend = 0;
          }
          rtmp = yy[1];
          yy[1] = yy[0];
          ryy_j = &yy[1];
          rll_i = ll_i;
          {
            while (1) {
              ;
              if (!((int)rll_i != (int)rtmp)) {
                goto while_break___3;
              }
              ryy_j++;
              rtmp2 = rtmp;
              rtmp = *ryy_j;
              *ryy_j = rtmp2;
            }
          while_break___3: /* CIL Label */;
          }
          yy[0] = rtmp;
          j = (Int32)(ryy_j - &yy[0]);
          *(mtfv + wr) = (UInt16)(j + 1);
          wr++;
        }
        i++;
      }
    while_break___1: /* CIL Label */;
    }
    if (zPend > 0) {
      zPend--;
      {
        while (1) {
          ;
          if (zPend & 1) {
            *(mtfv + wr) = (UInt16)1;
            wr++;

          } else {
            *(mtfv + wr) = (UInt16)0;
            wr++;
          }
          if (zPend < 2) {
            goto while_break___4;
          }
          zPend = (zPend - 2) / 2;
        }
      while_break___4: /* CIL Label */;
      }
    }
    *(mtfv + wr) = (UInt16)EOB;
    wr++;

    s->nMTF = wr;
  }
}
static void sendMTFValues(EState *s) {
  Int32 v;
  Int32 t;
  Int32 i;
  Int32 j;
  Int32 gs;
  Int32 ge;
  Int32 totc;
  Int32 bt;
  Int32 bc;
  Int32 iter;
  Int32 nSelectors;
  Int32 alphaSize;
  Int32 minLen;
  Int32 maxLen;
  Int32 selCtr;
  Int32 nGroups;
  Int32 nBytes;
  UInt16 cost[6];
  Int32 fave[6];
  UInt16 *mtfv;
  Int32 nPart;
  Int32 remF;
  Int32 tFreq;
  Int32 aFreq;
  register UInt32 cost01;
  register UInt32 cost23;
  register UInt32 cost45;
  register UInt16 icv;
  UInt16 icv___0;
  UChar pos[6];
  UChar ll_i;
  UChar tmp2;
  UChar tmp;
  Bool inUse16[16];
  Int32 curr;
  UInt16 mtfv_i;
  UChar *s_len_sel_selCtr;
  Int32 *s_code_sel_selCtr;

  {
    mtfv = s->mtfv;

    alphaSize = s->nInUse + 2;

    { nGroups = 2; }

    {

      ;

      nSelectors = 0;

      gs = 0;
      {
        while (1) {
          ;
          if (!(!(gs >= s->nMTF))) {
            goto while_break___9;
          }
          ge = (gs + 50) - 1;
          if (ge >= s->nMTF) {
            ge = s->nMTF - 1;
          }

          nSelectors++;

          gs = ge + 1;
        }
      while_break___9: /* CIL Label */;
      }

      t = 0;
      {
        while (1) {
          ;
          if (!(t < nGroups)) {
            goto while_break___16;
          }
          {
            BZ2_hbMakeCodeLengths(&s->len[t][0], &s->rfreq[t][0], alphaSize,
                                  17);
            t++;
          }
        }
      while_break___16: /* CIL Label */;
      }
    }

    t = 0;
    {

      ;

      maxLen = 0;
      i = 0;
      {
        while (1) {
          ;
          if (!(i < alphaSize)) {
            goto while_break___21;
          }
          if ((int)s->len[t][i] > maxLen) {
            maxLen = (Int32)s->len[t][i];
          }
          { minLen = (Int32)s->len[t][i]; }
          i++;
        }
      while_break___21: /* CIL Label */;
      }

      {
        BZ2_hbAssignCodes(&s->code[t][0], &s->len[t][0], minLen, maxLen,
                          alphaSize);
      }
    }

    i = 0;
    {
      while (1) {
        ;
        if (!(i < 16)) {
          goto while_break___24;
        }
        { bsW(s, 1, (UInt32)1); }

        i++;
      }
    while_break___24: /* CIL Label */;
    }
    i = 0;
    {
      while (1) {
        ;
        if (!(i < 16)) {
          goto while_break___25;
        }
        {
          j = 0;
          {
            while (1) {
              ;
              if (!(j < 16)) {
                goto while_break___26;
              }
              if (s->inUse[i * 16 + j]) {

                bsW(s, 1, (UInt32)1);

              } else {
                bsW(s, 1, (UInt32)0);
              }
              j++;
            }
          while_break___26: /* CIL Label */;
          }
        }
        i++;
      }
    while_break___25: /* CIL Label */;
    }

    {

      bsW(s, 3, (UInt32)nGroups);
      bsW(s, 15, (UInt32)nSelectors);
      i = 0;
    }
    {
      while (1) {
        ;
        if (!(i < nSelectors)) {
          goto while_break___27;
        }

        {
          bsW(s, 1, (UInt32)0);
          i++;
        }
      }
    while_break___27: /* CIL Label */;
    }

    {
      while (1) {
        ;
        if (!(t < nGroups)) {
          goto while_break___29;
        }
        {
          curr = (Int32)s->len[t][0];
          bsW(s, 5, (UInt32)curr);
          i = 0;
        }
        {
          while (1) {
            ;
            if (!(i < alphaSize)) {
              goto while_break___30;
            }
            {
              while (1) {
                ;
                if (!(curr < (Int32)s->len[t][i])) {
                  goto while_break___31;
                }
                {
                  bsW(s, 2, (UInt32)2);
                  curr++;
                }
              }
            while_break___31: /* CIL Label */;
            }
            {
              while (1) {
                ;
                if (!(curr > (Int32)s->len[t][i])) {
                  goto while_break___32;
                }
                {
                  bsW(s, 2, (UInt32)3);
                  curr--;
                }
              }
            while_break___32: /* CIL Label */;
            }
            {
              bsW(s, 1, (UInt32)0);
              i++;
            }
          }
        while_break___30: /* CIL Label */;
        }
        t++;
      }
    while_break___29: /* CIL Label */;
    }

    selCtr = 0;
    gs = 0;
    {

      ;

      {
      _L___1:
        i = gs;
        {
          while (1) {
            ;
            if (!(i <= ge)) {
              goto while_break___34;
            }
            {
              bsW(s, (Int32)s->len[s->selector[selCtr]][*(mtfv + i)],
                  (UInt32)s->code[s->selector[selCtr]][*(mtfv + i)]);
              i++;
            }
          }
        while_break___34: /* CIL Label */;
        }
      }
    }
  }
}
void BZ2_compressBlock(EState *s, Bool is_last_block) {

  {
    s->blockCRC = ~s->blockCRC;

    s->combinedCRC ^= s->blockCRC;

    { BZ2_blockSort(s); }
  }
  s->zbits = (UChar *)s->arr2 + s->nblock;
  {

    BZ2_bsInitWrite(s);
    bsPutUChar(s, (UChar)66);
    bsPutUChar(s, (UChar)90);
    bsPutUChar(s, (UChar)104);
    bsPutUChar(s, (UChar)(48 + s->blockSize100k));
  }
  {

    bsPutUChar(s, (UChar)49);
    bsPutUChar(s, (UChar)65);
    bsPutUChar(s, (UChar)89);
    bsPutUChar(s, (UChar)38);
    bsPutUChar(s, (UChar)83);
    bsPutUChar(s, (UChar)89);
    bsPutUInt32(s, s->blockCRC);
    bsW(s, 1, (UInt32)0);
    bsW(s, 24, (UInt32)s->origPtr);
    generateMTFValues(s);
    sendMTFValues(s);
  }
  {
    {
      bsPutUChar(s, (UChar)23);
      bsPutUChar(s, (UChar)114);
      bsPutUChar(s, (UChar)69);
      bsPutUChar(s, (UChar)56);
      bsPutUChar(s, (UChar)80);
      bsPutUChar(s, (UChar)144);
      bsPutUInt32(s, s->combinedCRC);
    }

    { bsFinishWrite(s); }
  }
}
extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__))
                                           malloc)(size_t __size)
    __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__))
                                         free)(void *__ptr);
extern __attribute__((__nothrow__, __noreturn__)) void(__attribute__((__leaf__))
                                                       exit)(int __status);

extern int fclose(FILE *__stream);
extern int fflush(FILE *__stream);

extern __attribute__((__nothrow__))
FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);
extern int fgetc(FILE *__stream);
extern int ungetc(int __c, FILE *__stream);
extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n,
                    FILE *__restrict __stream);
extern size_t fwrite(void const *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        ferror)(FILE *__stream);
extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcat)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcmp)(char const *__s1, char const *__s2) __attribute__((__pure__));
int BZ2_bzCompressInit(bz_stream *strm, int blockSize100k___0,
                       int verbosity___0, int workFactor___0);
int BZ2_bzCompress(bz_stream *strm, int action);
int BZ2_bzCompressEnd(bz_stream *strm);
int BZ2_bzDecompressInit(bz_stream *strm, int verbosity___0, int small);
int BZ2_bzDecompress(bz_stream *strm);
int BZ2_bzDecompressEnd(bz_stream *strm);
BZFILE *BZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity___0, int small,
                       void *unused, int nUnused);
void BZ2_bzReadClose(int *bzerror, BZFILE *b);
void BZ2_bzReadGetUnused(int *bzerror, BZFILE *b, void **unused, int *nUnused);
int BZ2_bzRead(int *bzerror, BZFILE *b, void *buf, int len);
BZFILE *BZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k___0,
                        int verbosity___0, int workFactor___0);
void BZ2_bzWrite(int *bzerror, BZFILE *b, void *buf, int len);
void BZ2_bzWriteClose64(int *bzerror, BZFILE *b, int abandon,
                        unsigned int *nbytes_in_lo32,
                        unsigned int *nbytes_in_hi32,
                        unsigned int *nbytes_out_lo32,
                        unsigned int *nbytes_out_hi32);
char const *BZ2_bzlibVersion(void);

static void *default_bzalloc(void *opaque, Int32 items, Int32 size) {
  void *v;
  void *tmp;

  {
    {
      tmp = malloc((size_t)(items * size));
      v = tmp;
    }
    return (v);
  }
}
static void default_bzfree(void *opaque, void *addr) { free(addr); }
static void prepare_new_block(EState *s) {
  Int32 i;

  {
    s->nblock = 0;
    s->numZ = 0;
    s->state_out_pos = 0;
    s->blockCRC = (UInt32)4294967295L;
  }
}
static void init_RL(EState *s) { s->state_in_ch = (UInt32)256; }

int BZ2_bzCompressInit(bz_stream *strm, int blockSize100k___0,
                       int verbosity___0, int workFactor___0) {
  Int32 n;
  EState *s;
  int tmp;

  {

    { strm->bzalloc = &default_bzalloc; }
    { strm->bzfree = &default_bzfree; }
    { s = (EState *)(*(strm->bzalloc))(strm->opaque, (int)sizeof(EState), 1); }

    {
      s->strm = strm;

      n = 100000 * blockSize100k___0;
      s->arr1 = (UInt32 *)(*(strm->bzalloc))(
          strm->opaque, (int)((unsigned long)n * sizeof(UInt32)), 1);
      s->arr2 = (UInt32 *)(*(strm->bzalloc))(
          strm->opaque, (int)((unsigned long)(n + 34) * sizeof(UInt32)), 1);
      s->ftab = (UInt32 *)(*(strm->bzalloc))(
          strm->opaque, (int)(65537UL * sizeof(UInt32)), 1);
    }

    {

      s->state = 2;
      s->mode = 2;
      s->combinedCRC = (UInt32)0;
      s->blockSize100k = blockSize100k___0;

      s->block = (UChar *)s->arr2;
      s->mtfv = (UInt16 *)s->arr1;

      s->ptr = s->arr1;
      strm->state = (void *)s;

      init_RL(s);
      prepare_new_block(s);
    }
    return (0);
  }
}
static void add_pair_to_block(EState *s) {
  Int32 i;
  UChar ch;

  {
    ch = (UChar)s->state_in_ch;
    i = 0;
    {
      while (1) {
        ;
        if (!(i < s->state_in_len)) {
          goto while_break;
        }
        s->blockCRC = (s->blockCRC << 8) ^
                      BZ2_crc32Table[(s->blockCRC >> 24) ^ (unsigned int)ch];
        i++;
      }
    while_break: /* CIL Label */;
    }
    s->inUse[s->state_in_ch] = (Bool)1;
    {
      if (s->state_in_len == 1) {
        goto case_1;
      }
      if (s->state_in_len == 2) {
        goto case_2;
      }
      if (s->state_in_len == 3) {
        goto case_3;
      }
      goto switch_default;
    case_1: /* CIL Label */
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      goto switch_break;
    case_2: /* CIL Label */
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      goto switch_break;
    case_3: /* CIL Label */
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      goto switch_break;
    switch_default: /* CIL Label */
      s->inUse[s->state_in_len - 4] = (Bool)1;
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      *(s->block + s->nblock) = ch;
      (s->nblock)++;
      *(s->block + s->nblock) = (UChar)(s->state_in_len - 4);
      (s->nblock)++;

    switch_break: /* CIL Label */;
    }
  }
}
static void flush_RL(EState *s) { add_pair_to_block(s); }
static Bool copy_input_until_stop(EState *s) {
  Bool progress_in;
  UInt32 zchh;
  UChar ch;
  UInt32 zchh___0;
  UChar ch___0;

  {

    {

      {
        ;

        if ((s->strm)->avail_in == 0U) {
          goto while_break;
        }
        progress_in = (Bool)1;
        zchh = (UInt32) * ((UChar *)(s->strm)->next_in);

        {
        _L___0:
          if (zchh != s->state_in_ch) {
            goto _L;
          } else {
            if (s->state_in_len == 255) {
            _L:
              if (s->state_in_ch < 256U) {

                add_pair_to_block(s);
              }
              s->state_in_ch = zchh;
              s->state_in_len = 1;
            } else {
              (s->state_in_len)++;
            }
          }
        }
        ((s->strm)->next_in)++;
        ((s->strm)->avail_in)--;
      }
    while_break: /* CIL Label */;
    }

    return (progress_in);
  }
}
static Bool copy_output_until_stop(EState *s) {
  Bool progress_out;

  {

    {

      ;

      progress_out = (Bool)1;
      *((s->strm)->next_out) = (char)*(s->zbits + s->state_out_pos);
      (s->state_out_pos)++;
      ((s->strm)->avail_out)--;
    }
    return (progress_out);
  }
}
static Bool handle_compress(bz_stream *strm) {
  Bool progress_in;
  Bool progress_out;
  EState *s;
  Bool tmp;
  Bool tmp___0;
  Bool tmp___1;
  Bool tmp___2;
  int tmp___3;

  {

    s = (EState *)strm->state;
    {
      {
        ;
        if (s->state == 1) {
          {
            tmp = copy_output_until_stop(s);
          }

          { goto while_break; }
        }
        {
          { tmp___2 = copy_input_until_stop(s); }
          if (s->mode != 2) {

            flush_RL(s);
            BZ2_compressBlock(s, (Bool)(s->mode == 4));
            s->state = 1;

          } else {
          }
        }
      }
    while_break: /* CIL Label */;
    }
    { tmp___3 = 1; }

    return ((Bool)tmp___3);
  }
}
int BZ2_bzCompress(bz_stream *strm, int action) {
  Bool progress;
  EState *s;
  int tmp;
  Bool tmp___0;
  Bool tmp___1;

  {

    s = (EState *)strm->state;

  preswitch : {

  case_2: /* CIL Label */
    if (action == 0) {

    } else {

      s->mode = 3;
    }

    { progress = handle_compress(strm); }

    {

      if (s->state_out_pos < s->numZ) {
        return (3);
      }
    }

    return (4);
  }
  }
}
int BZ2_bzCompressEnd(bz_stream *strm) {
  EState *s;

  {

    { (*(strm->bzfree))(strm->opaque, strm->state); }
    return (0);
  }
}

BZFILE *BZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k___0,
                        int verbosity___0, int workFactor___0) {
  Int32 ret;
  bzFile *bzf;
  int tmp;

  {

    { bzf = (bzFile *)malloc(sizeof(bzFile)); }

    bzf->handle = f;

    {
      ret = BZ2_bzCompressInit(&bzf->strm, blockSize100k___0, verbosity___0,
                               workFactor___0);
    }

    return ((BZFILE *)bzf);
  }
}
void BZ2_bzWrite(int *bzerror, BZFILE *b, void *buf, int len) {
  Int32 n;
  Int32 n2;
  Int32 ret;
  bzFile *bzf;
  int tmp;
  int tmp___0;

  {
    bzf = (bzFile *)b;

    bzf->strm.avail_in = (unsigned int)len;
    bzf->strm.next_in = (char *)buf;
    {
      while (1) {
        ;
        { ret = BZ2_bzCompress(&bzf->strm, 0); }

        if (bzf->strm.avail_in == 0U) {

          return;
        }
      };
    }
  }
}
void BZ2_bzWriteClose64(int *bzerror, BZFILE *b, int abandon,
                        unsigned int *nbytes_in_lo32,
                        unsigned int *nbytes_in_hi32,
                        unsigned int *nbytes_out_lo32,
                        unsigned int *nbytes_out_hi32) {
  Int32 n;
  Int32 n2;
  Int32 ret;
  bzFile *bzf;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;

  {
    bzf = (bzFile *)b;

    {

      while (1) {
        ;
        {
          bzf->strm.avail_out = 5000U;
          bzf->strm.next_out = bzf->buf;
          ret = BZ2_bzCompress(&bzf->strm, 2);
        }

        {

          n = (Int32)(5000U - bzf->strm.avail_out);
          n2 = (Int32)fwrite(
              (void const * /* __restrict  */)((void *)(bzf->buf)),
              sizeof(UChar), (size_t)n, (FILE * /* __restrict  */) bzf->handle);
        }
        if (ret == 4) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */;
    }

    { BZ2_bzCompressEnd(&bzf->strm); }
  }
}

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        remove)(char const *__filename);
extern void rewind(FILE *__stream);
extern void perror(char const *__s);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        fileno)(FILE *__stream);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1),
                                                          __leaf__))
                                           getenv)(char const *__name);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strcpy)(char *__restrict __dest, char const *__restrict __src);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strncpy)(char *__restrict __dest, char const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strncmp)(char const *__s1, char const *__s2, size_t __n)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__))
    strstr)(char const *__haystack, char const *__needle)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__))
                                           strerror)(int __errnum);
extern __attribute__((__nothrow__))
__sighandler_t(__attribute__((__leaf__)) signal)(int __sig,
                                                 void (*__handler)(int));
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern int(__attribute__((__nonnull__(1)))
           open)(char const *__file, int __oflag, ...) __asm__("open64");
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     utime)(char const *__file,
                                            struct utimbuf const *__file_times);
extern int close(int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        fchown)(int __fd, __uid_t __owner,
                                                __gid_t __group);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        isatty)(int __fd);
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    stat)(char const *__restrict __file,
          struct stat *__restrict __buf) __asm__("stat64");
extern __attribute__((__nothrow__)) int(
    __attribute__((__nonnull__(1, 2), __leaf__))
    lstat)(char const *__restrict __file,
           struct stat *__restrict __buf) __asm__("lstat64");
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        fchmod)(int __fd, __mode_t __mode);
Int32 verbosity;

Int32 blockSize100k;
Int32 exitValue;

Char inName[1034];
Char outName[1034];

Int32 workFactor;
static __attribute__((__noreturn__)) void panic(Char const *s);
static __attribute__((__noreturn__)) void ioError(void);
static __attribute__((__noreturn__)) void outOfMemory(void);
static __attribute__((__noreturn__)) void configError(void);
static __attribute__((__noreturn__)) void crcError(void);
static __attribute__((__noreturn__)) void cleanUpAndFail(Int32 ec);
static __attribute__((__noreturn__)) void compressedStreamEOF(void);
static void copyFileName(Char *to, Char *from);
static void *myMalloc(Int32 n);
static void applySavedFileAttrToOutputFile(IntNative fd);

static Bool myfeof___0(FILE *f) {
  Int32 c;
  Int32 tmp;

  {
    {
      tmp = fgetc(f);
      c = tmp;
    }
    if (c == -1) {
      return ((Bool)1);
    }
    { ungetc(c, f); }
  }
}
static void compressStream(FILE *stream, FILE *zStream) {
  BZFILE *bzf;
  UChar ibuf[5000];
  Int32 nIbuf;
  UInt32 nbytes_in_lo32;
  UInt32 nbytes_in_hi32;
  UInt32 nbytes_out_lo32;
  UInt32 nbytes_out_hi32;
  Int32 bzerr;
  Int32 bzerr_dummy;
  Int32 ret;
  int tmp;
  int tmp___0;
  Bool tmp___1;
  int tmp___2;
  int tmp___3;
  Int32 fd;
  Int32 tmp___4;
  int tmp___5;
  Char buf_nin[32];
  Char buf_nout[32];
  UInt64 nbytes_in;
  UInt64 nbytes_out;
  double nbytes_in_d;
  double nbytes_out_d;

  {

    {
      bzf = BZ2_bzWriteOpen(&bzerr, zStream, blockSize100k, verbosity,
                            workFactor);
    }

    {
      while (1) {
        ;
        { tmp___1 = myfeof___0(stream); }
        if (tmp___1) {
          goto while_break;
        }
        {
          nIbuf = (Int32)fread((void * /* __restrict  */)(ibuf), sizeof(UChar),
                               (size_t)5000, (FILE * /* __restrict  */) stream);
        }

        { BZ2_bzWrite(&bzerr, bzf, (void *)(ibuf), nIbuf); }
      }
    while_break: /* CIL Label */;
    }
    {
      BZ2_bzWriteClose64(&bzerr, bzf, 0, &nbytes_in_lo32, &nbytes_in_hi32,
                         &nbytes_out_lo32, &nbytes_out_hi32);
    }
  }
}

static __attribute__((__noreturn__)) void cleanUpAndFail(Int32 ec);

static __attribute__((__noreturn__)) void panic(Char const *s);

static __attribute__((__noreturn__)) void crcError(void);

static __attribute__((__noreturn__)) void compressedStreamEOF(void);

static __attribute__((__noreturn__)) void ioError(void);

static __attribute__((__noreturn__)) void outOfMemory(void);

static __attribute__((__noreturn__)) void configError(void);

static void copyFileName(Char *to, Char *from) {
  size_t tmp;

  {

    strncpy((char * /* __restrict  */)to, (char const * /* __restrict  */)from,
            (size_t)1024);
  }
}

static FILE *fopen_output_safely(Char *name, char const *mode) {
  FILE *fp;
  IntNative fh;

  {
    { fh = open((char const *)name, 193, 384); }

    { fp = fdopen(fh, mode); }

    return (fp);
  }
}

static void compress(Char *name) {
  FILE *inStr;
  FILE *outStr;
  Int32 n;
  Int32 i;
  struct stat statBuf;
  Bool tmp;
  int *tmp___0;
  char *tmp___1;
  Bool tmp___2;
  Bool tmp___3;
  Bool tmp___4;
  Bool tmp___5;
  char const *tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  int *tmp___11;
  char *tmp___12;
  int *tmp___13;
  char *tmp___14;
  int *tmp___15;
  char *tmp___16;
  IntNative retVal;
  IntNative tmp___17;

  {

    {

      case_3 : /* CIL Label */
          {copyFileName(inName, name);
    copyFileName(outName, name);
    strcat((char * /* __restrict  */)(outName),
           (char const * /* __restrict  */) ".bz2");
  }
}

{

  case_3___0 : /* CIL Label */
      {inStr = fopen((char const * /* __restrict  */)(inName),
                     (char const * /* __restrict  */) "rb");
outStr = fopen_output_safely(outName, "wb");
}
}

{ compressStream(inStr, outStr); }
{ tmp___17 = remove((char const *)(inName)); }
}
}

static void *myMalloc(Int32 n) {
  void *p;

  {
    { p = malloc((size_t)n); }

    return (p);
  }
}
static Cell *mkCell(void) {
  Cell *c;

  {
    { c = (Cell *)myMalloc((Int32)sizeof(Cell)); }
    return (c);
  }
}
static Cell *snocString(Cell *root, Char *name) {
  Cell *tmp;
  Cell *tmp___0;
  size_t tmp___1;
  Cell *tmp___3;

  {
    if ((unsigned long)root == (unsigned long)((void *)0)) {
      {
        tmp___0 = mkCell();
        tmp = tmp___0;
        tmp___1 = strlen((char const *)name);
        tmp->name = (Char *)myMalloc((Int32)(5UL + tmp___1));
        strcpy((char * /* __restrict  */)tmp->name,
               (char const * /* __restrict  */)name);
      }
      return (tmp);
    } else {
      tmp___3 = root;

      { tmp___3->link = snocString(tmp___3->link, name); }
    }
  }
}

IntNative main(IntNative argc, Char **argv) {
  Int32 i;
  Int32 j;
  Char *tmp;
  Cell *argList;
  Cell *aa;
  Bool decode;
  int tmp___0;
  size_t tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  char *tmp___8;
  int tmp___9;
  int tmp___10;
  int tmp___11;
  int tmp___12;
  int tmp___13;
  int tmp___14;
  int tmp___15;
  int tmp___16;
  int tmp___17;
  int tmp___18;
  int tmp___19;
  int tmp___20;
  int tmp___21;
  int tmp___22;
  int tmp___23;
  int tmp___24;
  int tmp___25;
  int tmp___26;
  int tmp___27;
  int tmp___28;
  int tmp___29;
  int tmp___30;
  int tmp___31;
  Cell *aa2;

  {

    { blockSize100k = 9; }

    { i = 1; }
    {
      while (1) {
        ;
        if (!(i <= argc - 1)) {
          goto while_break___0;
        }
        {
          argList = snocString(argList, *(argv + i));
          i++;
        }
      }
    while_break___0: /* CIL Label */;
    }

    {

      aa = argList;
      {
        while (1) {
          ;
          if (!((unsigned long)aa != (unsigned long)((void *)0))) {
            goto while_break___5;
          }

          { compress(aa->name); }
        __Cont___0:
          aa = aa->link;
        }
      while_break___5: /* CIL Label */;
      }
    }

    return (exitValue);
  }
}
__inline static void fallbackSimpleSort(UInt32 *fmap, UInt32 *eclass, Int32 lo,
                                        Int32 hi) {
  Int32 i;
  Int32 j;
  Int32 tmp;
  UInt32 ec_tmp;

  {

    i = hi - 1;
    {
      while (1) {
        ;
        if (!(i >= lo)) {
          goto while_break___1;
        }
        tmp = (Int32) * (fmap + i);
        ec_tmp = *(eclass + tmp);
        j = i + 1;
        {
          while (1) {
            ;
            if (j <= hi) {
              if (!(ec_tmp > *(eclass + *(fmap + j)))) {
                goto while_break___2;
              }
            } else {
              goto while_break___2;
            }
            *(fmap + (j - 1)) = *(fmap + j);
            j++;
          }
        while_break___2: /* CIL Label */;
        }
        *(fmap + (j - 1)) = (UInt32)tmp;
        i--;
      }
    while_break___1: /* CIL Label */;
    }
  }
}
static void fallbackQSort3(UInt32 *fmap, UInt32 *eclass, Int32 loSt,
                           Int32 hiSt) {
  Int32 unLo;
  Int32 unHi;
  Int32 ltLo;
  Int32 gtHi;
  Int32 n;
  Int32 m;
  Int32 sp;
  Int32 lo;
  Int32 hi;
  UInt32 med;
  UInt32 r;
  UInt32 r3;
  Int32 stackLo[100];
  Int32 stackHi[100];
  Int32 zztmp;
  Int32 zztmp___0;
  Int32 zztmp___1;
  Int32 yyp1;
  Int32 yyp2;
  Int32 yyn;
  Int32 zztmp___2;
  Int32 yyp1___0;
  Int32 yyp2___0;
  Int32 yyn___0;
  Int32 zztmp___3;

  {

    sp = 0;
    stackLo[sp] = loSt;
    stackHi[sp] = hiSt;
    sp++;
    {
      while (1) {
      while_continue: /* CIL Label */;
        if (!(sp > 0)) {
          goto while_break;
        }

        sp--;
        lo = stackLo[sp];
        hi = stackHi[sp];
        if (hi - lo < 10) {
          {
            fallbackSimpleSort(fmap, eclass, lo, hi);
          }
          goto while_continue;
        }

        { med = *(eclass + *(fmap + lo)); }

        ltLo = lo;
        unLo = ltLo;
        gtHi = hi;
        unHi = gtHi;
        {
          while (1) {
            ;
            {
              {

                if (n > 0) {
                  goto while_break___1;
                }
                unLo++;
              }
            while_break___1: /* CIL Label */;
            }
            {
              {
              while_continue___2: /* CIL Label */;
                if (!(!(unLo > unHi))) {
                  goto while_break___2;
                }
                n = (Int32) * (eclass + *(fmap + unHi)) - (Int32)med;
                if (n == 0) {
                  zztmp___0 = (Int32) * (fmap + unHi);
                  *(fmap + unHi) = *(fmap + gtHi);
                  *(fmap + gtHi) = (UInt32)zztmp___0;
                  gtHi--;
                  unHi--;
                  goto while_continue___2;
                }
                if (n < 0) {
                  goto while_break___2;
                }
                unHi--;
              }
            while_break___2: /* CIL Label */;
            }
            if (unLo > unHi) {
              goto while_break___0;
            }
            zztmp___1 = (Int32) * (fmap + unLo);
            *(fmap + unLo) = *(fmap + unHi);
            *(fmap + unHi) = (UInt32)zztmp___1;
          }
        while_break___0: /* CIL Label */;
        }

        { m = hi - gtHi; }

        yyp1___0 = unLo;
        yyp2___0 = (hi - m) + 1;
        yyn___0 = m;
        {
          while (1) {
            ;
            if (!(yyn___0 > 0)) {
              goto while_break___4;
            }
            zztmp___3 = (Int32) * (fmap + yyp1___0);
            *(fmap + yyp1___0) = *(fmap + yyp2___0);
            *(fmap + yyp2___0) = (UInt32)zztmp___3;
            yyp1___0++;
            yyp2___0++;
            yyn___0--;
          }
        while_break___4: /* CIL Label */;
        }
        n = ((lo + unLo) - ltLo) - 1;
        m = (hi - (gtHi - unHi)) + 1;
        {

          stackHi[sp] = n;
          sp++;
          stackLo[sp] = m;
          stackHi[sp] = hi;
          sp++;
        }
      }
    while_break: /* CIL Label */;
    }
  }
}
static void fallbackSort(UInt32 *fmap, UInt32 *eclass, UInt32 *bhtab,
                         Int32 nblock, Int32 verb) {
  Int32 ftab[257];
  Int32 ftabCopy[256];
  Int32 H;
  Int32 i;
  Int32 j;
  Int32 k;
  Int32 l;
  Int32 r;
  Int32 cc;
  Int32 cc1;
  Int32 nNotDone;
  Int32 nBhtab;
  UChar *eclass8;

  {
    eclass8 = (UChar *)eclass;

    i = 0;
    {
      while (1) {
        ;
        if (!(i < 257)) {
          goto while_break;
        }
        ftab[i] = 0;
        i++;
      }
    while_break: /* CIL Label */;
    }
    i = 0;
    {
      while (1) {
        ;
        if (!(i < nblock)) {
          goto while_break___0;
        }
        (ftab[*(eclass8 + i)])++;
        i++;
      }
    while_break___0: /* CIL Label */;
    }
    i = 0;
    {
      while (1) {
        ;
        if (!(i < 256)) {
          goto while_break___1;
        }
        ftabCopy[i] = ftab[i];
        i++;
      }
    while_break___1: /* CIL Label */;
    }
    i = 1;
    {
      while (1) {
        ;
        if (!(i < 257)) {
          goto while_break___2;
        }
        ftab[i] += ftab[i - 1];
        i++;
      }
    while_break___2: /* CIL Label */;
    }
    i = 0;
    {
      while (1) {
        ;
        if (!(i < nblock)) {
          goto while_break___3;
        }
        j = (Int32) * (eclass8 + i);
        k = ftab[j] - 1;
        ftab[j] = k;
        *(fmap + k) = (UInt32)i;
        i++;
      }
    while_break___3: /* CIL Label */;
    }

    i = 0;
    {
      while (1) {
        ;
        if (!(i < 256)) {
          goto while_break___5;
        }
        *(bhtab + (ftab[i] >> 5)) |= (unsigned int)(1 << (ftab[i] & 31));
        i++;
      }
    while_break___5: /* CIL Label */;
    }
    i = 0;
    {

      ;

      *(bhtab + ((nblock + 2 * i) >> 5)) |=
          (unsigned int)(1 << ((nblock + 2 * i) & 31));
    }
    H = 1;
    {
      while (1) {
        ;

        i = 0;
        {
          while (1) {
            ;
            if (!(i < nblock)) {
              goto while_break___8;
            }
            if (*(bhtab + (i >> 5)) & (unsigned int)(1 << (i & 31))) {
              j = i;
            }
            k = (Int32)(*(fmap + i) - (UInt32)H);
            if (k < 0) {
              k += nblock;
            }
            *(eclass + k) = (UInt32)j;
            i++;
          }
        while_break___8: /* CIL Label */;
        }

        r = -1;
        {
          while (1) {
            ;
            k = r + 1;

            {

              ;

              k++;
            }
            l = k - 1;

            {

              while (1) {
                ;
                if (!(!(*(bhtab + (k >> 5)) & (unsigned int)(1 << (k & 31))))) {
                  goto while_break___15;
                }
                k++;
              }
            while_break___15: /* CIL Label */;
            }
            r = k - 1;
            if (r >= nblock) {
              goto while_break___9;
            }
            {
              {

                fallbackQSort3(fmap, eclass, l, r);

                i = l;
              }
              {
                while (1) {
                  ;
                  if (!(i <= r)) {
                    goto while_break___16;
                  }
                  cc1 = (Int32) * (eclass + *(fmap + i));
                  if (cc != cc1) {
                    *(bhtab + (i >> 5)) |= (unsigned int)(1 << (i & 31));
                    cc = cc1;
                  }
                  i++;
                }
              while_break___16: /* CIL Label */;
              }
            }
          }
        while_break___9: /* CIL Label */;
        }

        H *= 2;
        if (H > nblock) {
          goto while_break___7;
        } else {
        }
      }
    while_break___7: /* CIL Label */;
    }

    j = 0;
    i = 0;
    {
      while (1) {
        ;
        if (!(i < nblock)) {
          goto while_break___17;
        }
        {
          while (1) {
            ;
            if (!(ftabCopy[j] == 0)) {
              goto while_break___18;
            }
            j++;
          }
        while_break___18: /* CIL Label */;
        }
        (ftabCopy[j])--;
        *(eclass8 + *(fmap + i)) = (UChar)j;
        i++;
      }
    while_break___17: /* CIL Label */;
    }
  }
}

void BZ2_blockSort(EState *s) {
  UInt32 *ptr;
  UChar *block;
  UInt32 *ftab;
  Int32 nblock;
  Int32 verb;
  Int32 wfact;
  UInt16 *quadrant;
  Int32 budget;
  Int32 budgetInit;
  Int32 i;
  int tmp;

  {
    ptr = s->ptr;

    ftab = s->ftab;
    nblock = s->nblock;
    verb = s->verbosity;

    { fallbackSort(s->arr1, s->arr2, ftab, nblock, verb); }

    {
      while (1) {
        ;

        if (*(ptr + i) == 0U) {
          s->origPtr = i;
          goto while_break;
        }
        i++;
      }
    while_break: /* CIL Label */;
    }
  }
}
