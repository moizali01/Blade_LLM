typedef int Int32;
typedef unsigned char Bool;
typedef unsigned char UChar;
typedef unsigned long size_t;

typedef long __off64_t;

struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

struct __anonstruct_bz_stream_26 {
  char *next_in;
  unsigned int avail_in;
  unsigned int total_in_lo32;

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

  Int32 rNToGo;

  UInt32 bsBuff;

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

  UInt32 *tt;
  UInt16 *ll16;

  UInt32 calculatedBlockCRC;

  Int32 nInUse;

  Bool inUse16[16];
  UChar seqToUnseq[256];

  Int32 mtfbase[16];

  UChar selectorMtf[18002];

  Int32 base[6][258];
  Int32 perm[6][258];

  Int32 save_alphaSize;

  Int32 save_EOB;

  Int32 save_groupPos;

  Int32 save_nblockMAX;
  Int32 save_nblock;
  Int32 save_es;
  Int32 save_N;
  Int32 save_curr;
  Int32 save_zt;
  Int32 save_zn;
  Int32 save_zvec;

  Int32 save_gMinlen;
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

  UInt32 state_in_ch;
  Int32 state_in_len;

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

typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __time_t;

typedef long __blkcnt_t;
typedef long __syscall_slong_t;
struct timespec {
  __time_t tv_sec;
};
typedef void (*__sighandler_t)(int);
struct stat {

  __nlink_t st_nlink;
  __mode_t st_mode;
  __uid_t st_uid;
  __gid_t st_gid;
  int __pad0;
  __dev_t st_rdev;

  __blkcnt_t st_blocks;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
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
  void *__cil_tmp29;

  void *__cil_tmp31;

  {
    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < alphaSize)) {
          goto while_break;
        }
        if (*(freq + i) == 0) {
          tmp = 1;
        } else {
          tmp = *(freq + i);
        }
        weight[i + 1] = tmp << 8;
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
    {
      while (1) {
        /* CIL Label */
        ;
        nNodes = alphaSize;
        nHeap = 0;
        heap[0] = 0;

        i = 1;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(i <= alphaSize)) {
              goto while_break___1;
            }

            nHeap++;
            heap[nHeap] = i;
            zz = nHeap;
            tmp___0 = heap[zz];
            {
              while (1) {
              while_continue___2: /* CIL Label */
                  ;
                if (!(weight[tmp___0] < weight[heap[zz >> 1]])) {
                  goto while_break___2;
                }
                heap[zz] = heap[zz >> 1];
                zz >>= 1;
              }
            while_break___2: /* CIL Label */
                ;
            }
            heap[zz] = tmp___0;
            i++;
          }
        while_break___1: /* CIL Label */
            ;
        }

        {
          while (1) {
          while_continue___3: /* CIL Label */
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
                /* CIL Label */
                ;
                yy = zz___0 << 1;
                if (yy > nHeap) {
                  goto while_break___4;
                }
                if (yy < nHeap) {
                  if (weight[heap[yy + 1]] < weight[heap[yy]]) {
                    yy++;
                  }
                }
                if (weight[tmp___1] < weight[heap[yy]]) {
                  goto while_break___4;
                }
                heap[zz___0] = heap[yy];
                zz___0 = yy;
              }
            while_break___4: /* CIL Label */
                ;
            }
            heap[zz___0] = tmp___1;
            n2 = heap[1];
            heap[1] = heap[nHeap];
            nHeap--;
            zz___1 = 1;
            tmp___2 = heap[zz___1];
            {
              while (1) {
                /* CIL Label */
                ;
                yy___0 = zz___1 << 1;
                if (yy___0 > nHeap) {
                  goto while_break___5;
                }

                if (weight[heap[yy___0 + 1]] < weight[heap[yy___0]]) {
                  yy___0++;
                }

                if (weight[tmp___2] < weight[heap[yy___0]]) {
                  goto while_break___5;
                }
                heap[zz___1] = heap[yy___0];
                zz___1 = yy___0;
              }
            while_break___5: /* CIL Label */
                ;
            }
            heap[zz___1] = tmp___2;
            nNodes++;
            tmp___3 = nNodes;
            parent[n2] = tmp___3;
            parent[n1] = tmp___3;

            tmp___4 = weight[n2] & 255;

            weight[nNodes] =
                (Int32)((((unsigned int)weight[n1] & 4294967040U) +
                         ((unsigned int)weight[n2] & 4294967040U)) |
                        (unsigned int)(1 + tmp___4));
            parent[nNodes] = -1;
            nHeap++;
            heap[nHeap] = nNodes;
            zz___2 = nHeap;
            tmp___5 = heap[zz___2];
            {
              while (1) {
                /* CIL Label */
                ;
                if (!(weight[tmp___5] < weight[heap[zz___2 >> 1]])) {
                  goto while_break___6;
                }
                heap[zz___2] = heap[zz___2 >> 1];
                zz___2 >>= 1;
              }
            while_break___6: /* CIL Label */
                ;
            }
            heap[zz___2] = tmp___5;
          }
        while_break___3: /* CIL Label */
            ;
        }
        if (!(nNodes < 516)) {
          {
            BZ2_bz__AssertH__fail(2002);
          }
        }

        i = 1;
        {
          while (1) {
          while_continue___7: /* CIL Label */
              ;
            if (!(i <= alphaSize)) {
              goto while_break___7;
            }
            j = 0;
            k = i;
            {
              while (1) {
                /* CIL Label */
                ;
                if (!(parent[k] >= 0)) {
                  goto while_break___8;
                }
                k = parent[k];
                j++;
              }
            while_break___8: /* CIL Label */
                ;
            }
            *(len + (i - 1)) = (UChar)j;

            i++;
          }
        while_break___7: /* CIL Label */
            ;
        }

        goto while_break___0;

        i = 1;
        {
          while (1) {
          while_continue___9: /* CIL Label */
              ;

            goto while_break___9;

            j = weight[i] >> 8;

            i++;
          }
        while_break___9: /* CIL Label */
            ;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }
    return;
  }
}
void BZ2_hbAssignCodes(Int32 *code, UChar *length, Int32 minLen, Int32 maxLen,
                       Int32 alphaSize) {
  Int32 n;
  Int32 vec;
  Int32 i;

  {
    vec = 0;
    n = minLen;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(n <= maxLen)) {
          goto while_break;
        }
        i = 0;
        {
          while (1) {
          while_continue___0: /* CIL Label */
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
        while_break___0: /* CIL Label */
            ;
        }
        vec <<= 1;
        n++;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
void BZ2_hbCreateDecodeTables(Int32 *limit, Int32 *base, Int32 *perm,
                              UChar *length, Int32 minLen, Int32 maxLen,
                              Int32 alphaSize) {
  Int32 pp;
  Int32 i;
  Int32 j;
  Int32 vec;

  {

    i = minLen;
    {

      /* CIL Label */
      ;

      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;

          j++;
        }
      while_break___0: /* CIL Label */
          ;
      }
      i++;

    while_break: /* CIL Label */
        ;
    }

    {

    while_break___1: /* CIL Label */
        ;
    }

    {
      while (1) {
      while_continue___2: /* CIL Label */
          ;
        if (!(i < alphaSize)) {
          goto while_break___2;
        }
        (*(base + ((int)*(length + i) + 1)))++;
        i++;
      }
    while_break___2: /* CIL Label */
        ;
    }
    i = 1;
    {

    while_break___3: /* CIL Label */
        ;
    }

    {

    while_break___4: /* CIL Label */
        ;
    }
    vec = 0;
    i = minLen;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i <= maxLen)) {
        }
        vec += *(base + (i + 1)) - *(base + i);

        vec <<= 1;
      }
    while_break___5: /* CIL Label */
        ;
    }

    {
      while (1) {
        /* CIL Label */
        ;

      }
      /* CIL Label */
      ;
    }
  }
}
extern struct _IO_FILE *stderr;

static void makeMaps_d(DState *s) {
  Int32 i;

  {

    i = 0;
    {

      /* CIL Label */
      ;
    }
  }
}

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

static void bsFinishWrite(EState *s) {

  {
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(s->bsLive > 0)) {
          goto while_break;
        }
        *(s->zbits + s->numZ) = (UChar)(s->bsBuff >> 24);
        (s->numZ)++;
        s->bsBuff <<= 8;
        s->bsLive -= 8;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
__inline static void bsW(EState *s, Int32 n, UInt32 v) {

  {
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(s->bsLive >= 8)) {
          goto while_break;
        }
        *(s->zbits + s->numZ) = (UChar)(s->bsBuff >> 24);
        (s->numZ)++;
        s->bsBuff <<= 8;
        s->bsLive -= 8;
      }
    while_break: /* CIL Label */
        ;
    }
    s->bsBuff |= v << ((32 - s->bsLive) - n);
    s->bsLive += n;
    return;
  }
}
static void bsPutUInt32(EState *s, UInt32 u) {

  {
    {
      bsW(s, 8, (UInt32)((long)(u >> 24) & 255L));
      bsW(s, 8, (UInt32)((long)(u >> 16) & 255L));
      bsW(s, 8, (UInt32)((long)(u >> 8) & 255L));
      bsW(s, 8, (UInt32)((long)u & 255L));
    }
    return;
  }
}
static void bsPutUChar(EState *s, UChar c) {

  {
    { bsW(s, 8, (UInt32)c); }
  }
}
static void makeMaps_e(EState *s) {
  Int32 i;

  {
    s->nInUse = 0;
    i = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
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
    while_break: /* CIL Label */
        ;
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
    {

      /* CIL Label */
      ;

      goto while_break;

      i++;

    while_break: /* CIL Label */
        ;
    }
    wr = 0;
    zPend = 0;
    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < s->nInUse)) {
          goto while_break___0;
        }
        yy[i] = (UChar)i;
        i++;
      }
    while_break___0: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
      while_continue___1: /* CIL Label */
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
                /* CIL Label */
                ;
                if (zPend & 1) {
                  *(mtfv + wr) = (UInt16)1;
                  wr++;
                  (s->mtfFreq[1])++;
                } else {
                  *(mtfv + wr) = (UInt16)0;
                  wr++;
                  (s->mtfFreq[0])++;
                }
                if (zPend < 2) {
                  goto while_break___2;
                }
                zPend = (zPend - 2) / 2;
              }
            while_break___2: /* CIL Label */
                ;
            }
            zPend = 0;
          }
          rtmp = yy[1];
          yy[1] = yy[0];
          ryy_j = &yy[1];
          rll_i = ll_i;
          {
            while (1) {
              /* CIL Label */
              ;
              if (!((int)rll_i != (int)rtmp)) {
                goto while_break___3;
              }
              ryy_j++;
              rtmp2 = rtmp;
              rtmp = *ryy_j;
              *ryy_j = rtmp2;
            }
          while_break___3: /* CIL Label */
              ;
          }
          yy[0] = rtmp;
          j = (Int32)(ryy_j - &yy[0]);
          *(mtfv + wr) = (UInt16)(j + 1);
          wr++;
          (s->mtfFreq[j + 1])++;
        }
        i++;
      }
    while_break___1: /* CIL Label */
        ;
    }

    zPend--;
    {

    while_continue___4: /* CIL Label */
        ;
      if (zPend & 1) {

        wr++;
        (s->mtfFreq[1])++;
      } else {
        *(mtfv + wr) = (UInt16)0;
        wr++;
        (s->mtfFreq[0])++;
      }

      goto while_break___4;

      zPend = (zPend - 2) / 2;

    while_break___4: /* CIL Label */
        ;
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

  void *__cil_tmp41;
  void *__cil_tmp42;
  void *__cil_tmp43;

  {
    mtfv = s->mtfv;
    if (s->verbosity >= 3) {
      {
      }
    }
    alphaSize = s->nInUse + 2;
    t = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(t < 6)) {
          goto while_break;
        }
        v = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(v < alphaSize)) {
              goto while_break___0;
            }
            s->len[t][v] = (UChar)15;
            v++;
          }
        while_break___0: /* CIL Label */
            ;
        }
        t++;
      }
    while_break: /* CIL Label */
        ;
    }

    if (s->nMTF < 200) {
      nGroups = 2;
    } else {

      if (s->nMTF < 1200) {

      } else {
        if (s->nMTF < 2400) {

        } else {
          nGroups = 6;
        }
      }
    }
    nPart = nGroups;
    remF = s->nMTF;
    gs = 0;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!(nPart > 0)) {
          goto while_break___1;
        }
        tFreq = remF / nPart;
        ge = gs - 1;
        aFreq = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (aFreq < tFreq) {
              if (!(ge < alphaSize - 1)) {
                goto while_break___2;
              }
            } else {
              goto while_break___2;
            }
            ge++;
            aFreq += s->mtfFreq[ge];
          }
        while_break___2: /* CIL Label */
            ;
        }
        if (ge > gs) {
          if (nPart != nGroups) {
            if (nPart != 1) {
              if ((nGroups - nPart) % 2 == 1) {
                aFreq -= s->mtfFreq[ge];
                ge--;
              }
            }
          }
        }

        v = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(v < alphaSize)) {
              goto while_break___3;
            }
            if (v >= gs) {
              if (v <= ge) {
                s->len[nPart - 1][v] = (UChar)0;
              } else {
              }
            } else {
              s->len[nPart - 1][v] = (UChar)15;
            }
            v++;
          }
        while_break___3: /* CIL Label */
            ;
        }
        nPart--;
        gs = ge + 1;
        remF -= aFreq;
      }
    while_break___1: /* CIL Label */
        ;
    }
    iter = 0;
    {
      while (1) {
      while_continue___4: /* CIL Label */
          ;
        if (!(iter < 4)) {
          goto while_break___4;
        }
        t = 0;
        {
          while (1) {
          while_continue___5: /* CIL Label */
              ;

            goto while_break___5;
          }
        while_break___5: /* CIL Label */
            ;
        }

        {
          while (1) {
            /* CIL Label */
            ;
            if (!(t < nGroups)) {
              goto while_break___6;
            }
            v = 0;
            {
              while (1) {
              while_continue___7: /* CIL Label */
                  ;
                if (!(v < alphaSize)) {
                  goto while_break___7;
                }
                s->rfreq[t][v] = 0;
                v++;
              }
            while_break___7: /* CIL Label */
                ;
            }
            t++;
          }
        while_break___6: /* CIL Label */
            ;
        }
        if (nGroups == 6) {
          v = 0;
          {
            while (1) {
            while_continue___8: /* CIL Label */
                ;
              if (!(v < alphaSize)) {
                goto while_break___8;
              }
              s->len_pack[v][0] =
                  (UInt32)(((int)s->len[1][v] << 16) | (int)s->len[0][v]);
              s->len_pack[v][1] =
                  (UInt32)(((int)s->len[3][v] << 16) | (int)s->len[2][v]);
              s->len_pack[v][2] =
                  (UInt32)(((int)s->len[5][v] << 16) | (int)s->len[4][v]);
              v++;
            }
          while_break___8: /* CIL Label */
              ;
          }
        }
        nSelectors = 0;

        gs = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(!(gs >= s->nMTF))) {
              goto while_break___9;
            }
            ge = (gs + 50) - 1;
            if (ge >= s->nMTF) {
              ge = s->nMTF - 1;
            }
            t = 0;
            {
              while (1) {
                /* CIL Label */
                ;
                if (!(t < nGroups)) {
                  goto while_break___10;
                }
                cost[t] = (UInt16)0;
                t++;
              }
            while_break___10: /* CIL Label */
                ;
            }
            if (nGroups == 6) {
              if (50 == (ge - gs) + 1) {
                cost45 = (UInt32)0;
                cost23 = cost45;
                cost01 = cost23;
                icv = *(mtfv + gs);
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 1));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 2));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 3));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 4));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 5));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 6));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 7));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 8));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 9));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 10));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 11));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 12));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 13));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 14));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 15));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 16));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 17));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 18));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 19));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 20));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 21));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 22));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 23));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 24));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 25));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 26));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 27));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 28));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 29));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 30));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 31));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 32));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 33));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 34));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 35));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 36));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 37));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 38));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 39));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 40));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 41));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 42));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 43));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 44));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 45));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 46));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 47));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 48));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 49));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                cost[0] = (UInt16)(cost01 & 65535U);
                cost[1] = (UInt16)(cost01 >> 16);
                cost[2] = (UInt16)(cost23 & 65535U);
                cost[3] = (UInt16)(cost23 >> 16);
                cost[4] = (UInt16)(cost45 & 65535U);
                cost[5] = (UInt16)(cost45 >> 16);
              } else {
                goto _L;
              }
            } else {
            _L:
              i = gs;
              {
                while (1) {
                  /* CIL Label */
                  ;
                  if (!(i <= ge)) {
                    goto while_break___11;
                  }
                  icv___0 = *(mtfv + i);
                  t = 0;
                  {
                    while (1) {
                    while_continue___12: /* CIL Label */
                        ;
                      if (!(t < nGroups)) {
                        goto while_break___12;
                      }
                      cost[t] =
                          (UInt16)((int)cost[t] + (int)s->len[t][icv___0]);
                      t++;
                    }
                  while_break___12: /* CIL Label */
                      ;
                  }
                  i++;
                }
              while_break___11: /* CIL Label */
                  ;
              }
            }
            bc = 999999999;

            t = 0;
            {
              while (1) {
              while_continue___13: /* CIL Label */
                  ;
                if (!(t < nGroups)) {
                  goto while_break___13;
                }
                if ((int)cost[t] < bc) {
                  bc = (Int32)cost[t];
                  bt = t;
                }
                t++;
              }
            while_break___13: /* CIL Label */
                ;
            }

            s->selector[nSelectors] = (UChar)bt;
            nSelectors++;
            if (nGroups == 6) {
              if (50 == (ge - gs) + 1) {
                (s->rfreq[bt][*(mtfv + gs)])++;
                (s->rfreq[bt][*(mtfv + (gs + 1))])++;
                (s->rfreq[bt][*(mtfv + (gs + 2))])++;
                (s->rfreq[bt][*(mtfv + (gs + 3))])++;
                (s->rfreq[bt][*(mtfv + (gs + 4))])++;
                (s->rfreq[bt][*(mtfv + (gs + 5))])++;
                (s->rfreq[bt][*(mtfv + (gs + 6))])++;
                (s->rfreq[bt][*(mtfv + (gs + 7))])++;
                (s->rfreq[bt][*(mtfv + (gs + 8))])++;
                (s->rfreq[bt][*(mtfv + (gs + 9))])++;
                (s->rfreq[bt][*(mtfv + (gs + 10))])++;
                (s->rfreq[bt][*(mtfv + (gs + 11))])++;
                (s->rfreq[bt][*(mtfv + (gs + 12))])++;
                (s->rfreq[bt][*(mtfv + (gs + 13))])++;
                (s->rfreq[bt][*(mtfv + (gs + 14))])++;
                (s->rfreq[bt][*(mtfv + (gs + 15))])++;
                (s->rfreq[bt][*(mtfv + (gs + 16))])++;
                (s->rfreq[bt][*(mtfv + (gs + 17))])++;
                (s->rfreq[bt][*(mtfv + (gs + 18))])++;
                (s->rfreq[bt][*(mtfv + (gs + 19))])++;
                (s->rfreq[bt][*(mtfv + (gs + 20))])++;
                (s->rfreq[bt][*(mtfv + (gs + 21))])++;
                (s->rfreq[bt][*(mtfv + (gs + 22))])++;
                (s->rfreq[bt][*(mtfv + (gs + 23))])++;
                (s->rfreq[bt][*(mtfv + (gs + 24))])++;
                (s->rfreq[bt][*(mtfv + (gs + 25))])++;
                (s->rfreq[bt][*(mtfv + (gs + 26))])++;
                (s->rfreq[bt][*(mtfv + (gs + 27))])++;
                (s->rfreq[bt][*(mtfv + (gs + 28))])++;
                (s->rfreq[bt][*(mtfv + (gs + 29))])++;
                (s->rfreq[bt][*(mtfv + (gs + 30))])++;
                (s->rfreq[bt][*(mtfv + (gs + 31))])++;
                (s->rfreq[bt][*(mtfv + (gs + 32))])++;
                (s->rfreq[bt][*(mtfv + (gs + 33))])++;
                (s->rfreq[bt][*(mtfv + (gs + 34))])++;
                (s->rfreq[bt][*(mtfv + (gs + 35))])++;
                (s->rfreq[bt][*(mtfv + (gs + 36))])++;
                (s->rfreq[bt][*(mtfv + (gs + 37))])++;
                (s->rfreq[bt][*(mtfv + (gs + 38))])++;
                (s->rfreq[bt][*(mtfv + (gs + 39))])++;
                (s->rfreq[bt][*(mtfv + (gs + 40))])++;
                (s->rfreq[bt][*(mtfv + (gs + 41))])++;
                (s->rfreq[bt][*(mtfv + (gs + 42))])++;
                (s->rfreq[bt][*(mtfv + (gs + 43))])++;
                (s->rfreq[bt][*(mtfv + (gs + 44))])++;
                (s->rfreq[bt][*(mtfv + (gs + 45))])++;
                (s->rfreq[bt][*(mtfv + (gs + 46))])++;
                (s->rfreq[bt][*(mtfv + (gs + 47))])++;
                (s->rfreq[bt][*(mtfv + (gs + 48))])++;
                (s->rfreq[bt][*(mtfv + (gs + 49))])++;
              } else {
                goto _L___0;
              }
            } else {
            _L___0:
              i = gs;
              {
                while (1) {
                while_continue___14: /* CIL Label */
                    ;
                  if (!(i <= ge)) {
                    goto while_break___14;
                  }
                  (s->rfreq[bt][*(mtfv + i)])++;
                  i++;
                }
              while_break___14: /* CIL Label */
                  ;
              }
            }
            gs = ge + 1;
          }
        while_break___9: /* CIL Label */
            ;
        }
        if (s->verbosity >= 3) {
          {

            t = 0;
          }
          {
            while (1) {
              /* CIL Label */
              ;

              goto while_break___15;

              {}
            }
          while_break___15: /* CIL Label */
              ;
          }
          {}
        }
        t = 0;
        {
          while (1) {
            /* CIL Label */
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
        while_break___16: /* CIL Label */
            ;
        }
        iter++;
      }
    while_break___4: /* CIL Label */
        ;
    }
    if (!(nGroups < 8)) {
      {
        BZ2_bz__AssertH__fail(3002);
      }
    }

    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < nGroups)) {
          goto while_break___17;
        }
        pos[i] = (UChar)i;
        i++;
      }
    while_break___17: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < nSelectors)) {
          goto while_break___18;
        }
        ll_i = s->selector[i];
        j = 0;
        tmp = pos[j];
        {
          while (1) {
          while_continue___19: /* CIL Label */
              ;
            if (!((int)ll_i != (int)tmp)) {
              goto while_break___19;
            }
            j++;
            tmp2 = tmp;
            tmp = pos[j];
            pos[j] = tmp2;
          }
        while_break___19: /* CIL Label */
            ;
        }
        pos[0] = tmp;
        s->selectorMtf[i] = (UChar)j;
        i++;
      }
    while_break___18: /* CIL Label */
        ;
    }
    t = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(t < nGroups)) {
          goto while_break___20;
        }
        minLen = 32;
        maxLen = 0;
        i = 0;
        {
          while (1) {
          while_continue___21: /* CIL Label */
              ;
            if (!(i < alphaSize)) {
              goto while_break___21;
            }
            if ((int)s->len[t][i] > maxLen) {
              maxLen = (Int32)s->len[t][i];
            }
            if ((int)s->len[t][i] < minLen) {
              minLen = (Int32)s->len[t][i];
            }
            i++;
          }
        while_break___21: /* CIL Label */
            ;
        }

        if (!(!(minLen < 1))) {
          {
            BZ2_bz__AssertH__fail(3005);
          }
        }
        {
          BZ2_hbAssignCodes(&s->code[t][0], &s->len[t][0], minLen, maxLen,
                            alphaSize);
          t++;
        }
      }
    while_break___20: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < 16)) {
          goto while_break___22;
        }
        inUse16[i] = (Bool)0;
        j = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j < 16)) {
              goto while_break___23;
            }
            if (s->inUse[i * 16 + j]) {
              inUse16[i] = (Bool)1;
            }
            j++;
          }
        while_break___23: /* CIL Label */
            ;
        }
        i++;
      }
    while_break___22: /* CIL Label */
        ;
    }

    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < 16)) {
          goto while_break___24;
        }
        if (inUse16[i]) {
          {
            bsW(s, 1, (UInt32)1);
          }
        } else {
          { bsW(s, 1, (UInt32)0); }
        }
        i++;
      }
    while_break___24: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < 16)) {
          goto while_break___25;
        }
        if (inUse16[i]) {
          j = 0;
          {
            while (1) {
            while_continue___26: /* CIL Label */
                ;
              if (!(j < 16)) {
                goto while_break___26;
              }
              if (s->inUse[i * 16 + j]) {
                {
                  bsW(s, 1, (UInt32)1);
                }
              } else {
                { bsW(s, 1, (UInt32)0); }
              }
              j++;
            }
          while_break___26: /* CIL Label */
              ;
          }
        }
        i++;
      }
    while_break___25: /* CIL Label */
        ;
    }
    if (s->verbosity >= 3) {
      {
      }
    }
    {

      bsW(s, 3, (UInt32)nGroups);
      bsW(s, 15, (UInt32)nSelectors);
      i = 0;
    }
    {
      while (1) {
      while_continue___27: /* CIL Label */
          ;
        if (!(i < nSelectors)) {
          goto while_break___27;
        }
        j = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j < (Int32)s->selectorMtf[i])) {
              goto while_break___28;
            }
            {
              bsW(s, 1, (UInt32)1);
              j++;
            }
          }
        while_break___28: /* CIL Label */
            ;
        }
        {
          bsW(s, 1, (UInt32)0);
          i++;
        }
      }
    while_break___27: /* CIL Label */
        ;
    }

    nBytes = s->numZ;
    t = 0;
    {
      while (1) {
        /* CIL Label */
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
          while_continue___30: /* CIL Label */
              ;
            if (!(i < alphaSize)) {
              goto while_break___30;
            }
            {
              while (1) {
                /* CIL Label */
                ;
                if (!(curr < (Int32)s->len[t][i])) {
                  goto while_break___31;
                }
                {
                  bsW(s, 2, (UInt32)2);
                  curr++;
                }
              }
            while_break___31: /* CIL Label */
                ;
            }
            {
              while (1) {
                /* CIL Label */
                ;
                if (!(curr > (Int32)s->len[t][i])) {
                  goto while_break___32;
                }
                {
                  bsW(s, 2, (UInt32)3);
                  curr--;
                }
              }
            while_break___32: /* CIL Label */
                ;
            }
            {
              bsW(s, 1, (UInt32)0);
              i++;
            }
          }
        while_break___30: /* CIL Label */
            ;
        }
        t++;
      }
    while_break___29: /* CIL Label */
        ;
    }

    selCtr = 0;
    gs = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(!(gs >= s->nMTF))) {
          goto while_break___33;
        }
        ge = (gs + 50) - 1;
        if (ge >= s->nMTF) {
          ge = s->nMTF - 1;
        }

        if (nGroups == 6) {
          if (50 == (ge - gs) + 1) {
            {
              s_len_sel_selCtr = &s->len[s->selector[selCtr]][0];
              s_code_sel_selCtr = &s->code[s->selector[selCtr]][0];
              mtfv_i = *(mtfv + gs);
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 1));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 2));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 3));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 4));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 5));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 6));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 7));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 8));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 9));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 10));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 11));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 12));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 13));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 14));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 15));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 16));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 17));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 18));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 19));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 20));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 21));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 22));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 23));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 24));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 25));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 26));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 27));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 28));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 29));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 30));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 31));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 32));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 33));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 34));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 35));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 36));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 37));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 38));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 39));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 40));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 41));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 42));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 43));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 44));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 45));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 46));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 47));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 48));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 49));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i),
                  (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
            }
          } else {
            goto _L___1;
          }
        } else {
        _L___1:
          i = gs;
          {
            while (1) {
              /* CIL Label */
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
          while_break___34: /* CIL Label */
              ;
          }
        }
        gs = ge + 1;
        selCtr++;
      }
    while_break___33: /* CIL Label */
        ;
    }
  }
}
void BZ2_compressBlock(EState *s, Bool is_last_block) {

  {

    s->blockCRC = ~s->blockCRC;
    s->combinedCRC = (s->combinedCRC << 1) | (s->combinedCRC >> 31);
    s->combinedCRC ^= s->blockCRC;

    if (s->verbosity >= 2) {
      {
      }
    }
    { BZ2_blockSort(s); }

    s->zbits = (UChar *)s->arr2 + s->nblock;

    {

      bsPutUChar(s, (UChar)66);
      bsPutUChar(s, (UChar)90);
      bsPutUChar(s, (UChar)104);
      bsPutUChar(s, (UChar)(48 + s->blockSize100k));
    }

    if (s->nblock > 0) {
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
    }
    if (is_last_block) {
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
}

extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(
    void *__ptr);
extern __attribute__((__nothrow__, __noreturn__)) void(
    __attribute__((__leaf__)) exit)(int __status);
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;

extern __attribute__((__nothrow__))
FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);

extern size_t fwrite(void const *__restrict __ptr, size_t __size, size_t __n,
                     FILE *__restrict __s);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ferror)(
    FILE *__stream);

int BZ2_bzCompressInit(bz_stream *strm, int blockSize100k___0,
                       int verbosity___0, int workFactor___0);

BZFILE *BZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity___0, int small,
                       void *unused, int nUnused);

void BZ2_bz__AssertH__fail(int errcode) {

  {
    {}
    if (errcode == 1007) {
      {
        fprintf(
            (FILE * /* __restrict  */)stderr,
            (char const
                 * /* __restrict  */) "\n*** A special note about internal "
                                      "error number 1007 ***\n\nExperience "
                                      "suggests that a common cause of i.e. "
                                      "1007\nis unreliable memory or other "
                                      "hardware.  The 1007 assertion\njust "
                                      "happens to cross-check the results of "
                                      "huge numbers of\nmemory reads/writes, "
                                      "and so acts (unintendedly) as a "
                                      "stress\ntest of your memory "
                                      "system.\n\nI suggest the following: try "
                                      "compressing the file again,\npossibly "
                                      "monitoring progress in detail with the "
                                      "-vv flag.\n\n* If the error cannot be "
                                      "reproduced, and/or happens at "
                                      "different\n  points in compression, you "
                                      "may have a flaky memory system.\n  Try "
                                      "a memory-test program.  I have used "
                                      "Memtest86\n  (www.memtest86.com).  At "
                                      "the time of writing it is free "
                                      "(GPLd).\n  Memtest86 tests memory much "
                                      "more thorougly than your BIOSs\n  "
                                      "power-on test, and may find failures "
                                      "that the BIOS doesn\'t.\n\n* If the "
                                      "error can be repeatably reproduced, "
                                      "this is a bug in\n  bzip2, and I would "
                                      "very much like to hear about it.  "
                                      "Please\n  let me know, and, ideally, "
                                      "save a copy of the file causing the\n  "
                                      "problem -- without which I will be "
                                      "unable to investigate it.\n\n");
      }
    }
    { exit(3); }
  }
}
static int bz_config_ok(void) {

  {

    return (0);

    return (1);
  }
}
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
static void default_bzfree(void *opaque, void *addr) {

  {

    {}
  }
}
static void prepare_new_block(EState *s) {

  {
    s->nblock = 0;

    s->blockCRC = (UInt32)4294967295L;

    {

    while_break: /* CIL Label */
        ;
    }
    (s->blockNo)++;
  }
}
static void init_RL(EState *s) {

  { s->state_in_ch = (UInt32)256; }
}
static Bool isempty_RL(EState *s) {

  {
    if (s->state_in_ch < 256U) {

    } else {
      return ((Bool)1);
    }
  }
}
int BZ2_bzCompressInit(bz_stream *strm, int blockSize100k___0,
                       int verbosity___0, int workFactor___0) {
  Int32 n;
  EState *s;
  int tmp;

  {
    { tmp = bz_config_ok(); }

    strm->bzalloc = &default_bzalloc;

    if ((unsigned long)strm->bzfree == (unsigned long)((void *)0)) {
    }
    { s = (EState *)(*(strm->bzalloc))(strm->opaque, (int)sizeof(EState), 1); }

    {
      s->strm = strm;

      s->arr2 = (UInt32 *)((void *)0);

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

      s->blockSize100k = blockSize100k___0;
      s->nblockMAX = 100000 * blockSize100k___0 - 19;
      s->verbosity = verbosity___0;

      s->block = (UChar *)s->arr2;
      s->mtfv = (UInt16 *)s->arr1;

      s->ptr = s->arr1;
      strm->state = (void *)s;

      strm->total_out_lo32 = 0U;

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
        /* CIL Label */
        ;
        if (!(i < s->state_in_len)) {
          goto while_break;
        }
        s->blockCRC = (s->blockCRC << 8) ^
                      BZ2_crc32Table[(s->blockCRC >> 24) ^ (unsigned int)ch];
        i++;
      }
    while_break: /* CIL Label */
        ;
    }

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
      goto switch_break;
    switch_break: /* CIL Label */
        ;
    }
    return;
  }
}
static void flush_RL(EState *s) {

  {
    if (s->state_in_ch < 256U) {
      {
        add_pair_to_block(s);
      }
    }
    { init_RL(s); }
  }
}
static Bool copy_input_until_stop(EState *s) {

  UInt32 zchh;
  UChar ch;

  UChar ch___0;

  {

    if (s->mode == 2) {
      {
        while (1) {
          /* CIL Label */
          ;

          if ((s->strm)->avail_in == 0U) {
            goto while_break;
          }

          zchh = (UInt32) * ((UChar *)(s->strm)->next_in);
          if (zchh != s->state_in_ch) {
            if (s->state_in_len == 1) {
              ch = (UChar)s->state_in_ch;
              s->blockCRC =
                  (s->blockCRC << 8) ^
                  BZ2_crc32Table[(s->blockCRC >> 24) ^ (unsigned int)ch];
              s->inUse[s->state_in_ch] = (Bool)1;
              *(s->block + s->nblock) = ch;
              (s->nblock)++;
              s->state_in_ch = zchh;
            } else {
              goto _L___0;
            }
          } else {
          _L___0:
            if (zchh != s->state_in_ch) {
              goto _L;
            } else {
              if (s->state_in_len == 255) {
              _L:
                if (s->state_in_ch < 256U) {
                  {
                    add_pair_to_block(s);
                  }
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
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
          }
        }
      while_break: /* CIL Label */
          ;
      }
    } else {
      {

        /* CIL Label */
        ;

        if (s->avail_in_expect == 0U) {
          goto while_break___0;
        }

        ((s->strm)->next_in)++;
        ((s->strm)->avail_in)--;
        ((s->strm)->total_in_lo32)++;

      while_break___0: /* CIL Label */
          ;
      }
    }
  }
}
static Bool copy_output_until_stop(EState *s) {
  Bool progress_out;

  {

    {
      while (1) {
        /* CIL Label */
        ;
        if (!(!((s->strm)->avail_out == 0U))) {
          goto while_break;
        }
        if (s->state_out_pos >= s->numZ) {
          goto while_break;
        }
        progress_out = (Bool)1;
        *((s->strm)->next_out) = (char)*(s->zbits + s->state_out_pos);
        (s->state_out_pos)++;
        ((s->strm)->avail_out)--;
        ((s->strm)->next_out)++;

        if ((s->strm)->total_out_lo32 == 0U) {
          ((s->strm)->total_out_hi32)++;
        }
      }
    while_break: /* CIL Label */
        ;
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

  Bool tmp___2;
  int tmp___3;

  {

    s = (EState *)strm->state;
    {
      while (1) {
        /* CIL Label */
        ;
        if (s->state == 1) {
          {
            tmp = copy_output_until_stop(s);
            progress_out = (Bool)((int)progress_out | (int)tmp);
          }

          { tmp___0 = isempty_RL(s); }
          if (tmp___0) {
            goto while_break;
          }

          { prepare_new_block(s); }
        }

        { tmp___2 = copy_input_until_stop(s); }
        if (s->mode != 2) {
          if (s->avail_in_expect == 0U) {
            {
              flush_RL(s);
              BZ2_compressBlock(s, (Bool)(s->mode == 4));
              s->state = 1;
            }
          } else {
          }
        } else {
        _L:
          if (s->nblock >= s->nblockMAX) {
            {

              s->state = 1;
            }
          } else {

            goto while_break;
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
    if (progress_in) {
      tmp___3 = 1;
    } else {
      if (progress_out) {

      } else {
        tmp___3 = 0;
      }
    }
    return ((Bool)tmp___3);
  }
}
int BZ2_bzCompress(bz_stream *strm, int action) {
  Bool progress;
  EState *s;
  int tmp;

  Bool tmp___1;

  {

    s = (EState *)strm->state;

    if ((unsigned long)s->strm != (unsigned long)strm) {
    }
  preswitch: {

    if (s->mode == 2) {
    }

    if (s->mode == 4) {
      goto case_4;
    }

  case_1: /* CIL Label */

  case_2: /* CIL Label */
    if (action == 0) {
      {
        progress = handle_compress(strm);
      }

      return (tmp);
    } else {
      if (action == 1) {

      } else {

        s->avail_in_expect = strm->avail_in;
        s->mode = 4;
        goto preswitch;
      }
    }
  case_3: /* CIL Label */

  {}

    s->mode = 2;
    return (1);
  case_4: /* CIL Label */

    if (s->avail_in_expect != (s->strm)->avail_in) {
    }
    { progress = handle_compress(strm); }
    if (!progress) {
      return (-1);
    }
    if (s->avail_in_expect > 0U) {

    } else {
      {}
      if (tmp___1) {
        if (s->state_out_pos < s->numZ) {
          return (3);
        }
      } else {
        return (3);
      }
    }
    s->mode = 1;
    return (4);
  switch_break: /* CIL Label */
      ;
  }
    return (0);
  }
}
int BZ2_bzCompressEnd(bz_stream *strm) {

  {

    { (*(strm->bzfree))(strm->opaque, strm->state); }
  }
}

static Bool unRLE_obuf_to_output_FAST(DState *s) {

  UInt32 c_calculatedBlockCRC;
  UChar c_state_out_ch;
  Int32 c_state_out_len;
  Int32 c_nblock_used;
  Int32 c_k0;
  UInt32 *c_tt;
  UInt32 c_tPos;
  char *cs_next_out;
  unsigned int cs_avail_out;
  Int32 ro_blockSize100k;
  UInt32 avail_out_INIT;
  Int32 s_save_nblockPP;
  unsigned int total_out_lo32_old;

  {

    {

    while_break: /* CIL Label */
        ;
    }

    c_calculatedBlockCRC = s->calculatedBlockCRC;
    c_state_out_ch = s->state_out_ch;
    c_state_out_len = s->state_out_len;
    c_nblock_used = s->nblock_used;
    c_k0 = s->k0;
    c_tt = s->tt;
    c_tPos = s->tPos;
    cs_next_out = (s->strm)->next_out;
    cs_avail_out = (s->strm)->avail_out;
    ro_blockSize100k = s->blockSize100k;
    avail_out_INIT = cs_avail_out;
    s_save_nblockPP = s->save_nblock + 1;
    {

      /* CIL Label */
      ;
    }

    (s->strm)->total_out_lo32 += avail_out_INIT - cs_avail_out;
    if ((s->strm)->total_out_lo32 < total_out_lo32_old) {
      ((s->strm)->total_out_hi32)++;
    }

    s->nblock_used = c_nblock_used;

    s->tt = c_tt;

    (s->strm)->next_out = cs_next_out;
    (s->strm)->avail_out = cs_avail_out;
  }
}
Int32 BZ2_indexIntoF(Int32 indx, Int32 *cftab) {

  Int32 na;

  {

    {

    while_break: /* CIL Label */
        ;
    }
  }
}

int BZ2_bzDecompressEnd(bz_stream *strm) {
  DState *s;

  {
    if ((unsigned long)strm == (unsigned long)((void *)0)) {
    }

    if ((unsigned long)s->ll16 != (unsigned long)((void *)0)) {
      {
        (*(strm->bzfree))(strm->opaque, (void *)s->ll16);
      }
    }

    { strm->state = (void *)0; }
  }
}

BZFILE *BZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k___0,
                        int verbosity___0, int workFactor___0) {
  Int32 ret;
  bzFile *bzf;
  int tmp;

  {

    *bzerror = 0;

    if ((unsigned long)f == (unsigned long)((void *)0)) {

    } else {
      if (blockSize100k___0 < 1) {
        goto _L___0;
      } else {
        if (blockSize100k___0 > 9) {

        } else {
          if (workFactor___0 < 0) {

          } else {
            if (workFactor___0 > 250) {

            } else {
              if (verbosity___0 < 0) {

              } else {
                if (verbosity___0 > 4) {
                _L___0:

                  bzf->lastErr = -2;
                }
              }
            }
          }
        }
      }
    }
    { tmp = ferror(f); }
    if (tmp) {
    }
    { bzf = (bzFile *)malloc(sizeof(bzFile)); }
    if ((unsigned long)bzf == (unsigned long)((void *)0)) {
      if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
      }
    }

    bzf->handle = f;

    bzf->strm.bzalloc = (void *(*)(void *, int, int))((void *)0);

    {
      ret = BZ2_bzCompressInit(&bzf->strm, blockSize100k___0, verbosity___0,
                               workFactor___0);
    }
    if (ret != 0) {

      if ((unsigned long)bzf != (unsigned long)((void *)0)) {
      }
      {}
      return ((void *)0);
    }
    bzf->strm.avail_in = 0U;

    return ((BZFILE *)bzf);
  }
}
void BZ2_bzWrite(int *bzerror, BZFILE *b, void *buf, int len) {
  Int32 n;
  Int32 n2;
  Int32 ret;
  bzFile *bzf;
  int tmp;

  {
    bzf = (bzFile *)b;

    if (!bzf->writing) {
    }
    {}

    bzf->strm.avail_in = (unsigned int)len;
    bzf->strm.next_in = (char *)buf;
    {

    while_continue: /* CIL Label */
        ;
      {

        ret = BZ2_bzCompress(&bzf->strm, 0);
      }

      /* CIL Label */
      ;
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

  int tmp___1;

  {
    bzf = (bzFile *)b;

    if (!bzf->writing) {
    }
    {}

    if ((unsigned long)nbytes_in_hi32 != (unsigned long)((void *)0)) {
      *nbytes_in_hi32 = 0U;
    }

    {
      while (1) {
        /* CIL Label */
        ;
        {
          bzf->strm.avail_out = 5000U;
          bzf->strm.next_out = bzf->buf;
          ret = BZ2_bzCompress(&bzf->strm, 2);
        }
        if (ret != 3) {
          if (ret != 4) {

            return;
          }
        }

        {
          n = (Int32)(5000U - bzf->strm.avail_out);
          n2 = (Int32)fwrite(
              (void const * /* __restrict  */)((void *)(bzf->buf)),
              sizeof(UChar), (size_t)n, (FILE * /* __restrict  */)bzf->handle);
        }
      }
    while_break: /* CIL Label */
        ;
    }

    {}

    { free((void *)bzf); }
  }
}

void BZ2_bzReadClose(int *bzerror, BZFILE *b) {
  bzFile *bzf;

  {
    bzf = (bzFile *)b;

    if ((unsigned long)bzf == (unsigned long)((void *)0)) {

      if ((unsigned long)bzf != (unsigned long)((void *)0)) {
      }
    }

    if (bzf->initialisedOk) {
      {
      }
    }
    {}
  }
}
int BZ2_bzRead(int *bzerror, BZFILE *b, void *buf, int len) {
  Int32 n;

  bzFile *bzf;
  int tmp;

  Bool tmp___1;

  {

    if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
    }
    if ((unsigned long)bzf != (unsigned long)((void *)0)) {
    }

    if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
    }

    bzf->strm.avail_out = (unsigned int)len;

    {

      /* CIL Label */
      ;
    }
  }
}

char const *BZ2_bzlibVersion(void) {

  {}
}
static char const *bzerrorstrings[16] = {"OK",           "SEQUENCE_ERROR",
                                         "PARAM_ERROR",  "MEM_ERROR",
                                         "DATA_ERROR",   "DATA_ERROR_MAGIC",
                                         "IO_ERROR",     "UNEXPECTED_EOF",
                                         "OUTBUFF_FULL", "CONFIG_ERROR",
                                         "???",          "???",
                                         "???",          "???",
                                         "???",          "???"};

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(
    FILE *__stream);

extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) strncpy)(
    char *__restrict __dest, char const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2),
                                                       __leaf__)) strncmp)(
    char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));

extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag,
                                                 ...) __asm__("open64");

extern int close(int __fd);

extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchmod)(
    int __fd, __mode_t __mode);
Int32 verbosity;

Bool deleteOutputOnInterrupt;
Bool forceOverwrite;

Bool noisy;

Int32 numFilesProcessed;
Int32 blockSize100k;
Int32 exitValue;
Int32 opMode;
Int32 srcMode;
Int32 longestFileName;
Char inName[1034];
Char outName[1034];
Char tmpName[1034];
Char *progName;
Char progNameReally[1034];
FILE *outputHandleJustInCase;
Int32 workFactor;
static __attribute__((__noreturn__)) void panic(Char const *s);
static __attribute__((__noreturn__)) void ioError(void);

static __attribute__((__noreturn__)) void configError(void);

static __attribute__((__noreturn__)) void cleanUpAndFail(Int32 ec);

static void copyFileName(Char *to, Char *from);

static void applySavedFileAttrToOutputFile(IntNative fd);

static Bool uInt64_isZero(UInt64 *n) {
  Int32 i;

  {
    i = 0;
    {

      /* CIL Label */
      ;

    while_break: /* CIL Label */
        ;
    }
  }
}

static void uInt64_toAscii(char *outbuf, UInt64 *n) {
  Int32 i;
  Int32 q;
  UChar buf[32];
  Int32 nBuf;

  Bool tmp;

  {

    {

    while_continue: /* CIL Label */
        ;
      {

        buf[nBuf] = (UChar)(q + 48);
        nBuf++;
      }

    while_break: /* CIL Label */
        ;
    }

    i = 0;
    {

      /* CIL Label */
      ;
      if (!(i < nBuf)) {
        goto while_break___0;
      }

    while_break___0: /* CIL Label */
        ;
    }
  }
}
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

  int tmp___0;
  Bool tmp___1;
  int tmp___2;
  int tmp___3;

  Int32 tmp___4;
  int tmp___5;
  Char buf_nin[32];

  UInt64 nbytes_in;

  double nbytes_out_d;
  void *__cil_tmp28;

  void *__cil_tmp30;
  void *__cil_tmp31;
  void *__cil_tmp32;
  char *__cil_tmp33;

  {
    { bzf = (void *)0; }

    {}
    if (tmp___0) {
    }
    {
      bzf = BZ2_bzWriteOpen(&bzerr, zStream, blockSize100k, verbosity,
                            workFactor);
    }

    {
      while (1) {
        /* CIL Label */
        ;
        { tmp___1 = myfeof___0(stream); }
        if (tmp___1) {
          goto while_break;
        }
        {
          nIbuf = (Int32)fread((void * /* __restrict  */)(ibuf), sizeof(UChar),
                               (size_t)5000, (FILE * /* __restrict  */)stream);
        }
        if (tmp___2) {
        }
        if (nIbuf > 0) {
          {
            BZ2_bzWrite(&bzerr, bzf, (void *)(ibuf), nIbuf);
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      BZ2_bzWriteClose64(&bzerr, bzf, 0, &nbytes_in_lo32, &nbytes_in_hi32,
                         &nbytes_out_lo32, &nbytes_out_hi32);
    }

    {}
    if (tmp___3) {
      goto errhandler_io;
    }
    {}
    if (ret == -1) {
    }

    { tmp___4 = fileno(zStream); }

    {}

    {}

    {}
    if (ret == -1) {
    }

    return;
  errhandler: {
    BZ2_bzWriteClose64(&bzerr_dummy, bzf, 1, &nbytes_in_lo32, &nbytes_in_hi32,
                       &nbytes_out_lo32, &nbytes_out_hi32);
  }
    {

    case_neg_9: { /* CIL Label */
      configError();
    }

    case_neg_3: { /* CIL Label */
    }
      goto switch_break;
    errhandler_io: { /* CIL Label */
    }
      goto switch_break;
    switch_default: { /* CIL Label */
      panic("compress:unexpected error");
    }
    switch_break: /* CIL Label */
        ;
    }
    { panic("compress:end"); }
  }
}

static void setExit(Int32 v) {

  { return; }
}
static void cadvise(void) {

  {}
}
static void showFileNames(void) {

  {

    {
      fprintf((FILE * /* __restrict  */)stderr,
              (char const
                   * /* __restrict  */) "\tInput file = %s, output file = %s\n",
              inName, outName);
    }

    return;
  }
}

static void cleanUpAndFail(Int32 ec) {

  {
    if (srcMode == 3) {
    }

    { setExit(ec); }
  }
}
static __attribute__((__noreturn__)) void panic(Char const *s);
static void panic(Char const *s) {

  {
    {
      fprintf(
          (FILE * /* __restrict  */)stderr,
          (char const
               * /* __restrict  */) "\n%s: PANIC -- internal consistency "
                                    "error:\n\t%s\n\tThis is a BUG.  Please "
                                    "report it to me at:\n\tjseward@bzip.org\n",
          progName, s);

      cleanUpAndFail(3);
    }
  }
}

static void crcError(void) {

  {
    {
      fprintf((FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "\n%s: Data integrity error "
                                               "when decompressing.\n",
              progName);
      showFileNames();
    }
  }
}

static void compressedStreamEOF(void) {

  {
    if (noisy) {
      {
        fprintf((FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "\n%s: Compressed file ends "
                                                 "unexpectedly;\n\tperhaps it "
                                                 "is corrupted?  *Possible* "
                                                 "reason follows.\n",
                progName);
      }
    }
    {}
  }
}

static void ioError(void) {

  {
    {

      perror((char const *)progName);

      cleanUpAndFail(1);
    }
  }
}

static void mySIGSEGVorSIGBUScatcher(IntNative n) {

  {
    if (opMode == 1) {
      {
      }
    } else {
      {
        fprintf(
            (FILE * /* __restrict  */)stderr,
            (char const
                 * /* __restrict  */) "\n%s: Caught a SIGSEGV or SIGBUS whilst "
                                      "decompressing.\n\n   Possible causes "
                                      "are (most likely first):\n   (1) The "
                                      "compressed data is corrupted, and "
                                      "bzip2\'s usual checks\n       failed to "
                                      "detect this.  Try bzip2 -tvv "
                                      "my_file.bz2.\n   (2) This computer has "
                                      "unreliable memory or cache hardware\n   "
                                      "    (a surprisingly common problem; try "
                                      "a different machine.)\n   (3) A bug in "
                                      "the compiler used to create this "
                                      "executable\n       (unlikely, if you "
                                      "didn\'t compile bzip2 yourself.)\n   "
                                      "(4) A real bug in bzip2 -- I hope this "
                                      "should never be the case.\n   The "
                                      "user\'s manual, Section 4.3, has more "
                                      "info on (2) and (3).\n   \n   If you "
                                      "suspect this is a bug in bzip2, or are "
                                      "unsure about (2)\n   or (3), feel free "
                                      "to report it to me at: "
                                      "jseward@bzip.org.\n   Section 4.3 of "
                                      "the user\'s manual describes the info a "
                                      "useful\n   bug report should have.  If "
                                      "the manual is available on your\n   "
                                      "system, please try and read it before "
                                      "mailing me.  If you don\'t\n   have the "
                                      "manual or can\'t be bothered to read "
                                      "it, mail me anyway.\n\n",
            progName);
      }
    }
    { showFileNames(); }
    if (opMode == 1) {
      {
      }
    } else {
      {}
    }
  }
}

static void outOfMemory(void) {

  {
    { cleanUpAndFail(1); }
  }
}

static void configError(void) {

  {
    {

      setExit(3);
      exit(exitValue);
    }
  }
}
static void pad(Char *s) {
  Int32 i;
  size_t tmp;
  size_t tmp___0;

  {
    { tmp = strlen((char const *)s); }

    {
      while (1) {
        /* CIL Label */
        ;
        {}
        if (!(i <= longestFileName - (Int32)tmp___0)) {
          goto while_break;
        }
        {}
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
static void copyFileName(Char *to, Char *from) {
  size_t tmp;

  {
    {}

    {
      strncpy((char * /* __restrict  */)to,
              (char const * /* __restrict  */)from, (size_t)1024);
    }
  }
}
static Bool fileExists(Char *name) {
  FILE *tmp;
  FILE *tmp___0;
  Bool exists;

  {
    {
      tmp___0 = fopen((char const * /* __restrict  */)name,
                      (char const * /* __restrict  */) "rb");
      tmp = tmp___0;
      exists = (Bool)((unsigned long)tmp != (unsigned long)((void *)0));
    }
    if ((unsigned long)tmp != (unsigned long)((void *)0)) {
      {
      }
    }
    return (exists);
  }
}
static FILE *fopen_output_safely(Char *name, char const *mode) {
  FILE *fp;
  IntNative fh;

  {
    { fh = open((char const *)name, 193, 384); }

    { fp = fdopen(fh, mode); }
    if ((unsigned long)fp == (unsigned long)((void *)0)) {
      {
      }
    }
    return (fp);
  }
}
static Bool notAStandardFile(Char *name) {
  IntNative i;
  struct stat statBuf;

  {
    {
      i = lstat((char const * /* __restrict  */)name,
                (struct stat * /* __restrict  */)(&statBuf));
    }

    if ((statBuf.st_mode & 61440U) == 32768U) {
      return ((Bool)0);
    }
    return ((Bool)1);
  }
}
static Int32 countHardLinks(Char *name) {
  IntNative i;

  void *__cil_tmp4;

  {
    {}
    if (i != 0) {
    }
  }
}
static struct stat fileMetaInfo;
static void saveInputFileMetaInfo(Char *srcName) {
  IntNative retVal;

  {
    {
      retVal = stat((char const * /* __restrict  */)srcName,
                    (struct stat * /* __restrict  */)(&fileMetaInfo));
    }
    if (retVal != 0) {
      {
        ioError();
      }
    }
  }
}
static void applySavedTimeInfoToOutputFile(Char *dstName) {
  IntNative retVal;
  struct utimbuf uTimBuf;

  {
    {
      uTimBuf.actime = fileMetaInfo.st_atim.tv_sec;

      retVal = utime((char const *)dstName, (struct utimbuf const *)(&uTimBuf));
    }

    return;
  }
}
static void applySavedFileAttrToOutputFile(IntNative fd) {
  IntNative retVal;

  {
    { retVal = fchmod(fd, fileMetaInfo.st_mode); }
    if (retVal != 0) {
      {
      }
    }
    { fchown(fd, fileMetaInfo.st_uid, fileMetaInfo.st_gid); }
  }
}
static Bool containsDubiousChars(Char *name) {

  {}
}
Char const *zSuffix[4] = {".bz2", ".bz", ".tbz2", ".tbz"};

static Bool hasSuffix(Char *s, Char const *suffix) {
  Int32 ns;
  Int32 tmp;

  Int32 tmp___0;
  int tmp___1;

  {
    {
      tmp = (Int32)strlen((char const *)s);
      ns = tmp;
    }

    {}
    if (tmp___1 == 0) {
    }
  }
}

static void compress(Char *name) {
  FILE *inStr;
  FILE *outStr;

  Int32 i;
  struct stat statBuf;
  Bool tmp;
  int *tmp___0;
  char *tmp___1;
  Bool tmp___2;
  Bool tmp___3;
  Bool tmp___4;
  Bool tmp___5;

  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  int *tmp___11;
  char *tmp___12;

  char *tmp___14;
  int *tmp___15;
  char *tmp___16;

  IntNative tmp___17;

  char *__cil_tmp30;
  char *__cil_tmp31;
  char *__cil_tmp32;
  char *__cil_tmp33;

  char *__cil_tmp35;
  char *__cil_tmp36;

  {

    {

      if (srcMode == 3) {
        goto case_3;
      }

      goto switch_break;
      { /* CIL Label */
        copyFileName(inName, (Char *)"(stdin)");
      }

    case_3: { /* CIL Label */
      copyFileName(inName, name);
      copyFileName(outName, name);
      strcat((char * /* __restrict  */)(outName),
             (char const * /* __restrict  */) ".bz2");
    }
      goto switch_break;
    case_2: { /* CIL Label */
    }

    switch_break: /* CIL Label */
        ;
    }
    if (srcMode != 1) {
      {
        tmp = containsDubiousChars(inName);
      }
    }

    { tmp___2 = fileExists(inName); }
    if (!tmp___2) {
      {

        fprintf(
            (FILE * /* __restrict  */)stderr,
            (char const
                 * /* __restrict  */) "%s: Can\'t open input file %s: %s.\n",
            progName, inName, tmp___1);
        setExit(1);
      }
      return;
    }

    i = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;

        goto while_break;

        { tmp___3 = hasSuffix(inName, zSuffix[i]); }

        { setExit(1); }

        i++;
      }
    while_break: /* CIL Label */
        ;
    }

    if (srcMode == 3) {
    }

    { saveInputFileMetaInfo(inName); }

    {

      if (srcMode == 3) {
        goto case_3___0;
      }

    case_1___0: { /* CIL Label */
      inStr = stdin;

      tmp___7 = fileno(stdout);
      tmp___8 = isatty(tmp___7);
    }

      {}

      goto switch_break___0;
      { /* CIL Label */
        inStr = fopen((char const * /* __restrict  */)(inName),
                      (char const * /* __restrict  */) "rb");

        tmp___9 = fileno(stdout);
        tmp___10 = isatty(tmp___9);
      }

      if ((unsigned long)inStr == (unsigned long)((void *)0)) {
        {

          setExit(1);
        }
      }

    case_3___0: { /* CIL Label */
      inStr = fopen((char const * /* __restrict  */)(inName),
                    (char const * /* __restrict  */) "rb");
      outStr = fopen_output_safely(outName, "wb");
    }

      if ((unsigned long)inStr == (unsigned long)((void *)0)) {
        {
          tmp___15 = __errno_location();
          tmp___16 = strerror(*tmp___15);
          fprintf(
              (FILE * /* __restrict  */)stderr,
              (char const
                   * /* __restrict  */) "%s: Can\'t open input file %s: %s.\n",
              progName, inName, tmp___16);
        }

        {}

        {}
        return;
      }
      goto switch_break___0;
    switch_default: { /* CIL Label */
    }

    switch_break___0: /* CIL Label */
        ;
    }

    {
      outputHandleJustInCase = outStr;
      deleteOutputOnInterrupt = (Bool)1;
      compressStream(inStr, outStr);
      outputHandleJustInCase = (FILE *)((void *)0);
    }
    if (srcMode == 3) {
      {
        applySavedTimeInfoToOutputFile(outName);
      }

      { tmp___17 = remove((char const *)(inName)); }
    }
    deleteOutputOnInterrupt = (Bool)0;
  }
}

static void *myMalloc(Int32 n) {
  void *p;

  {
    { p = malloc((size_t)n); }
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      {
        outOfMemory();
      }
    }
    return (p);
  }
}
static Cell *mkCell(void) {
  Cell *c;

  {
    {
      c = (Cell *)myMalloc((Int32)sizeof(Cell));
      c->name = (Char *)((void *)0);
      c->link = (struct zzzz *)((void *)0);
    }
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

        tmp->name = (Char *)myMalloc((Int32)(5UL + tmp___1));
        strcpy((char * /* __restrict  */)tmp->name,
               (char const * /* __restrict  */)name);
      }
      return (tmp);
    } else {
      tmp___3 = root;
      {

        /* CIL Label */
        ;
      }
      { tmp___3->link = snocString(tmp___3->link, name); }
    }
  }
}
static void addFlagsFromEnvVar(Cell **argList, Char *varName) {

  Char *p;

  {
    {}

    {

    while_break: /* CIL Label */
        ;
    }
  }
}
IntNative main(IntNative argc, Char **argv) {
  Int32 i;

  Char *tmp;
  Cell *argList;
  Cell *aa;

  char *tmp___3;

  char *tmp___6;
  char *tmp___7;

  int tmp___12;

  int tmp___16;
  int tmp___17;

  int tmp___20;

  int tmp___24;

  int tmp___27;
  int tmp___28;

  char *__cil_tmp42;
  char *__cil_tmp43;
  char *__cil_tmp44;
  char *__cil_tmp45;

  {

    {

      forceOverwrite = (Bool)0;

      blockSize100k = 9;

      numFilesProcessed = 0;

      copyFileName(inName, (Char *)"(none)");

      progName = &progNameReally[0];
    }
    {
      while (1) {
        /* CIL Label */
        ;

        goto while_break;

        tmp++;
      }
    while_break: /* CIL Label */
        ;
    }
    { i = 1; }
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i <= argc - 1)) {
          goto while_break___0;
        }
        {
          argList = snocString(argList, *(argv + i));
          i++;
        }
      }
    while_break___0: /* CIL Label */
        ;
    }

    {

    while_break___1: /* CIL Label */
        ;
    }

    srcMode = 3;

    {
      opMode = 1;
      tmp___3 = strstr((char const *)progName, "unzip");
    }

    {}

    aa = argList;
    {

      /* CIL Label */
      ;
    }

    {

      /* CIL Label */
      ;
    }

    {}

    aa = argList;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!((unsigned long)aa != (unsigned long)((void *)0))) {
          goto while_break___5;
        }
        {}

        { compress(aa->name); }

        aa = aa->link;
      }
    while_break___5: /* CIL Label */
        ;
    }

    {

    while_break___8: /* CIL Label */
        ;
    }
  }
}

__inline static Bool mainGtU(UInt32 i1, UInt32 i2, UChar *block,
                             UInt16 *quadrant, UInt32 nblock, Int32 *budget) {

  UChar c1;
  UChar c2;

  {
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2) {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;

    {
      while (1) {
        /* CIL Label */
        ;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }

        i1++;
        i2++;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
static Int32 incs[14] = {1,    4,    13,    40,    121,    364,    1093,
                         3280, 9841, 29524, 88573, 265720, 797161, 2391484};
static void mainSimpleSort(UInt32 *ptr, UChar *block, UInt16 *quadrant,
                           Int32 nblock, Int32 lo, Int32 hi, Int32 d,
                           Int32 *budget) {
  Int32 i;
  Int32 j;
  Int32 h;

  Int32 hp;
  UInt32 v;
  Bool tmp;

  {

    hp = 0;
    {

      /* CIL Label */
      ;
    }

    {
      while (1) {
        /* CIL Label */
        ;
        if (!(hp >= 0)) {
          goto while_break___0;
        }
        h = incs[hp];
        i = lo + h;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(!(i > hi))) {
              goto while_break___1;
            }
            v = *(ptr + i);
            j = i;
            {
              while (1) {
                /* CIL Label */
                ;
                {
                  tmp = mainGtU(*(ptr + (j - h)) + (UInt32)d, v + (UInt32)d,
                                block, quadrant, (UInt32)nblock, budget);
                }
                if (!tmp) {
                  goto while_break___2;
                }
                *(ptr + j) = *(ptr + (j - h));
                j -= h;
                if (j <= (lo + h) - 1) {
                  goto while_break___2;
                }
              }
            while_break___2: /* CIL Label */
                ;
            }
            *(ptr + j) = v;
            i++;

            v = *(ptr + i);
            j = i;
            {

            while_break___3: /* CIL Label */
                ;
            }
            *(ptr + j) = v;

            {

            while_break___4: /* CIL Label */
                ;
            }
            *(ptr + j) = v;
          }
        while_break___1: /* CIL Label */
            ;
        }
        hp--;
      }
    while_break___0: /* CIL Label */
        ;
    }
  }
}
__inline static UChar mmed3(UChar a, UChar b, UChar c) {

  { return (b); }
}
static void mainQSort3(UInt32 *ptr, UChar *block, UInt16 *quadrant,
                       Int32 nblock, Int32 loSt, Int32 hiSt, Int32 dSt,
                       Int32 *budget) {
  Int32 unLo;
  Int32 unHi;
  Int32 ltLo;
  Int32 gtHi;
  Int32 n;
  Int32 m;
  Int32 med;
  Int32 sp;
  Int32 lo;
  Int32 hi;
  Int32 d;
  Int32 stackLo[100];
  Int32 stackHi[100];
  Int32 stackD[100];
  Int32 nextLo[3];
  Int32 nextHi[3];
  Int32 nextD[3];
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
    stackD[sp] = dSt;
    sp++;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(sp > 0)) {
          goto while_break;
        }

        sp--;
        lo = stackLo[sp];
        hi = stackHi[sp];
        d = stackD[sp];
        if (hi - lo < 20) {
          goto _L;
        } else {
          if (d > 14) {
          _L: {
            mainSimpleSort(ptr, block, quadrant, nblock, lo, hi, d, budget);
          }

            goto while_continue;
          }
        }
        {
          med =
              (Int32)mmed3(*(block + (*(ptr + lo) + (UInt32)d)),
                           *(block + (*(ptr + hi) + (UInt32)d)),
                           *(block + (*(ptr + ((lo + hi) >> 1)) + (UInt32)d)));
          ltLo = lo;
          unLo = ltLo;
          gtHi = hi;
          unHi = gtHi;
        }
        {
          while (1) {
            /* CIL Label */
            ;
            {

            while_continue___1: /* CIL Label */
                ;
              if (!(!(unLo > unHi))) {
                goto while_break___1;
              }
              n = (Int32) * (block + (*(ptr + unLo) + (UInt32)d)) - med;
              if (n == 0) {
                zztmp = (Int32) * (ptr + unLo);
                *(ptr + unLo) = *(ptr + ltLo);
                *(ptr + ltLo) = (UInt32)zztmp;
                ltLo++;
                unLo++;
                goto while_continue___1;
              }
              if (n > 0) {
                goto while_break___1;
              }
              unLo++;

            while_break___1: /* CIL Label */
                ;
            }
            {

            while_continue___2: /* CIL Label */
                ;
              if (!(!(unLo > unHi))) {
              }
              n = (Int32) * (block + (*(ptr + unHi) + (UInt32)d)) - med;
              if (n == 0) {
                zztmp___0 = (Int32) * (ptr + unHi);
                *(ptr + unHi) = *(ptr + gtHi);
                *(ptr + gtHi) = (UInt32)zztmp___0;
                gtHi--;
                unHi--;
                goto while_continue___2;
              }
              if (n < 0) {
                goto while_break___2;
              }
              unHi--;

            while_break___2: /* CIL Label */
                ;
            }
            if (unLo > unHi) {
              goto while_break___0;
            }
            zztmp___1 = (Int32) * (ptr + unLo);
            *(ptr + unLo) = *(ptr + unHi);
            *(ptr + unHi) = (UInt32)zztmp___1;
          }
        while_break___0: /* CIL Label */
            ;
        }
        if (gtHi < ltLo) {

          stackD[sp] = d + 1;
          sp++;
          goto while_continue;
        }

        n = unLo - ltLo;

        yyp1 = lo;
        yyp2 = unLo - n;
        yyn = n;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(yyn > 0)) {
              goto while_break___3;
            }
            zztmp___2 = (Int32) * (ptr + yyp1);
            *(ptr + yyp1) = *(ptr + yyp2);
            *(ptr + yyp2) = (UInt32)zztmp___2;
            yyp1++;
            yyp2++;
            yyn--;
          }
        while_break___3: /* CIL Label */
            ;
        }
        if (hi - gtHi < gtHi - unHi) {
          m = hi - gtHi;
        } else {
          m = gtHi - unHi;
        }
        yyp1___0 = unLo;
        yyp2___0 = (hi - m) + 1;
        yyn___0 = m;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(yyn___0 > 0)) {
              goto while_break___4;
            }
            zztmp___3 = (Int32) * (ptr + yyp1___0);
            *(ptr + yyp1___0) = *(ptr + yyp2___0);
            *(ptr + yyp2___0) = (UInt32)zztmp___3;
            yyp1___0++;
            yyp2___0++;
            yyn___0--;
          }
        while_break___4: /* CIL Label */
            ;
        }
        n = ((lo + unLo) - ltLo) - 1;
        m = (hi - (gtHi - unHi)) + 1;
        nextLo[0] = lo;
        nextHi[0] = n;

        nextLo[1] = m;
        nextHi[1] = hi;

        nextLo[2] = n + 1;
        nextHi[2] = m - 1;

        stackLo[sp] = nextLo[0];
        stackHi[sp] = nextHi[0];

        sp++;
        stackLo[sp] = nextLo[1];
        stackHi[sp] = nextHi[1];
        stackD[sp] = nextD[1];
        sp++;
        stackLo[sp] = nextLo[2];
        stackHi[sp] = nextHi[2];
        stackD[sp] = nextD[2];
        sp++;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
static void mainSort(UInt32 *ptr, UChar *block, UInt16 *quadrant, UInt32 *ftab,
                     Int32 nblock, Int32 verb, Int32 *budget) {
  Int32 i;
  Int32 j;
  Int32 k;
  Int32 ss;
  Int32 sb;
  Int32 runningOrder[256];

  Int32 copyStart[256];
  Int32 copyEnd[256];
  UChar c1;

  UInt16 s;
  Int32 vv;
  Int32 h;
  Int32 lo;
  Int32 hi;
  Int32 tmp;
  Int32 tmp___0;

  {

    i = 65536;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i >= 0)) {
          goto while_break;
        }
        *(ftab + i) = (UInt32)0;
        i--;
      }
    while_break: /* CIL Label */
        ;
    }
    j = (int)*(block + 0) << 8;
    i = nblock - 1;
    {

    while_break___0: /* CIL Label */
        ;
    }
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i >= 0)) {
          goto while_break___1;
        }

        j = (j >> 8) | ((int)((UInt16) * (block + i)) << 8);
        (*(ftab + j))++;
        i--;
      }
    while_break___1: /* CIL Label */
        ;
    }
    i = 0;
    {

      /* CIL Label */
      ;
      if (!(i < 34)) {
      }
      *(block + (nblock + i)) = *(block + i);

    while_break___2: /* CIL Label */
        ;
    }

    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i <= 65536)) {
          goto while_break___3;
        }
        *(ftab + i) += *(ftab + (i - 1));
        i++;
      }
    while_break___3: /* CIL Label */
        ;
    }
    s = (UInt16)((int)*(block + 0) << 8);
    i = nblock - 1;
    {

    while_break___4: /* CIL Label */
        ;
    }
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i >= 0)) {
          goto while_break___5;
        }
        s = (UInt16)(((int)s >> 8) | ((int)*(block + i) << 8));
        j = (Int32)(*(ftab + (int)s) - 1U);
        *(ftab + (int)s) = (UInt32)j;
        *(ptr + j) = (UInt32)i;
        i--;
      }
    while_break___5: /* CIL Label */
        ;
    }

    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i <= 255)) {
          goto while_break___6;
        }

        runningOrder[i] = i;
        i++;
      }
    while_break___6: /* CIL Label */
        ;
    }
    h = 1;
    {

      /* CIL Label */
      ;
      h = 3 * h + 1;

    while_break___7: /* CIL Label */
        ;
    }
    {
      while (1) {
        /* CIL Label */
        ;
        h /= 3;
        i = h;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(i <= 255)) {
              goto while_break___9;
            }
            vv = runningOrder[i];
            j = i;
            {

              /* CIL Label */
              ;
              if (!(*(ftab + ((runningOrder[j - h] + 1) << 8)) -
                        *(ftab + (runningOrder[j - h] << 8)) >
                    *(ftab + ((vv + 1) << 8)) - *(ftab + (vv << 8)))) {
              }
              runningOrder[j] = runningOrder[j - h];
              j -= h;

            while_break___10: /* CIL Label */
                ;
            }
          zero:
            runningOrder[j] = vv;
            i++;
          }
        while_break___9: /* CIL Label */
            ;
        }
        if (!(h != 1)) {
          goto while_break___8;
        }
      }
    while_break___8: /* CIL Label */
        ;
    }

    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i <= 255)) {
          goto while_break___11;
        }
        ss = runningOrder[i];
        j = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j <= 255)) {
              goto while_break___12;
            }

            sb = (ss << 8) + j;
            if (!(*(ftab + sb) & (unsigned int)(1 << 21))) {
              lo = (Int32)(*(ftab + sb) & (unsigned int)(~(1 << 21)));
              hi = (Int32)((*(ftab + (sb + 1)) & (unsigned int)(~(1 << 21))) -
                           1U);

              { mainQSort3(ptr, block, quadrant, nblock, lo, hi, 2, budget); }
            }

            j++;
          }
        while_break___12: /* CIL Label */
            ;
        }

        j = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j <= 255)) {
              goto while_break___13;
            }
            copyStart[j] =
                (Int32)(*(ftab + ((j << 8) + ss)) & (unsigned int)(~(1 << 21)));
            copyEnd[j] = (Int32)((*(ftab + (((j << 8) + ss) + 1)) &
                                  (unsigned int)(~(1 << 21))) -
                                 1U);
            j++;
          }
        while_break___13: /* CIL Label */
            ;
        }
        j = (Int32)(*(ftab + (ss << 8)) & (unsigned int)(~(1 << 21)));
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j < copyStart[ss])) {
              goto while_break___14;
            }
            k = (Int32)(*(ptr + j) - 1U);

            c1 = *(block + k);

            tmp = copyStart[c1];
            (copyStart[c1])++;
            *(ptr + tmp) = (UInt32)k;

            j++;
          }
        while_break___14: /* CIL Label */
            ;
        }
        j = (Int32)((*(ftab + ((ss + 1) << 8)) & (unsigned int)(~(1 << 21))) -
                    1U);
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j > copyEnd[ss])) {
              goto while_break___15;
            }
            k = (Int32)(*(ptr + j) - 1U);
            if (k < 0) {
              k += nblock;
            }
            c1 = *(block + k);

            tmp___0 = copyEnd[c1];
            (copyEnd[c1])--;
            *(ptr + tmp___0) = (UInt32)k;

            j--;
          }
        while_break___15: /* CIL Label */
            ;
        }

        j = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j <= 255)) {
              goto while_break___16;
            }

            j++;
          }
        while_break___16: /* CIL Label */
            ;
        }

        i++;
      }
    while_break___11: /* CIL Label */
        ;
    }
  }
}
void BZ2_blockSort(EState *s) {
  UInt32 *ptr;
  UChar *block;
  UInt32 *ftab;
  Int32 nblock;
  Int32 verb;

  UInt16 *quadrant;
  Int32 budget;

  Int32 i;

  {
    ptr = s->ptr;
    block = s->block;
    ftab = s->ftab;
    nblock = s->nblock;

    {}

    { mainSort(ptr, block, quadrant, ftab, nblock, verb, &budget); }

    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < s->nblock)) {
          goto while_break;
        }
        if (*(ptr + i) == 0U) {
          s->origPtr = i;
        }
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
  }
}
