typedef int Int32;
typedef unsigned char Bool;
typedef unsigned char UChar;
typedef unsigned long size_t;
typedef long __off_t;

struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

struct __anonstruct_bz_stream_26
{
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
struct __anonstruct_DState_28
{
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
struct __anonstruct_EState_27
{
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
struct __anonstruct_bzFile_29
{
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
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};

struct stat
{
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
};
struct utimbuf
{
  __time_t actime;
  __time_t modtime;
};
typedef short Int16;
typedef int IntNative;
struct __anonstruct_UInt64_56
{
  UChar b[8];
};
typedef struct __anonstruct_UInt64_56 UInt64;
struct zzzz
{
  Char *name;
  struct zzzz *link;
};
typedef struct zzzz Cell;
Int32 BZ2_rNums[512];
Int32 BZ2_rNums[512] = {619, 720, 127, 481, 931, 816, 813, 233, 566, 247, 985, 724, 205, 454, 863, 491, 741, 242, 949, 214, 733, 859, 335, 708, 621, 574, 73, 654, 730, 472, 419, 436, 278, 496, 867, 210, 399, 680, 480, 51, 878, 465, 811, 169, 869, 675, 611, 697, 867, 561, 862, 687,
                        507, 283, 482, 129, 807, 591, 733, 623, 150, 238, 59, 379, 684, 877, 625, 169, 643, 105, 170, 607, 520, 932, 727, 476, 693, 425, 174, 647, 73, 122, 335, 530, 442, 853, 695, 249, 445, 515, 909, 545, 703, 919, 874, 474, 882, 500, 594, 612, 641, 801, 220, 162,
                        819, 984, 589, 513, 495, 799, 161, 604, 958, 533, 221, 400, 386, 867, 600, 782, 382, 596, 414, 171, 516, 375, 682, 485, 911, 276, 98, 553, 163, 354, 666, 933, 424, 341, 533, 870, 227, 730, 475, 186, 263, 647, 537, 686, 600, 224, 469, 68, 770, 919, 190, 373,
                        294, 822, 808, 206, 184, 943, 795, 384, 383, 461, 404, 758, 839, 887, 715, 67, 618, 276, 204, 918, 873, 777, 604, 560, 951, 160, 578, 722, 79, 804, 96, 409, 713, 940, 652, 934, 970, 447, 318, 353, 859, 672, 112, 785, 645, 863, 803, 350, 139, 93, 354, 99,
                        820, 908, 609, 772, 154, 274, 580, 184, 79, 626, 630, 742, 653, 282, 762, 623, 680, 81, 927, 626, 789, 125, 411, 521, 938, 300, 821, 78, 343, 175, 128, 250, 170, 774, 972, 275, 999, 639, 495, 78, 352, 126, 857, 956, 358, 619, 580, 124, 737, 594, 701, 612,
                        669, 112, 134, 694, 363, 992, 809, 743, 168, 974, 944, 375, 748, 52, 600, 747, 642, 182, 862, 81, 344, 805, 988, 739, 511, 655, 814, 334, 249, 515, 897, 955, 664, 981, 649, 113, 974, 459, 893, 228, 433, 837, 553, 268, 926, 240, 102, 654, 459, 51, 686, 754,
                        806, 760, 493, 403, 415, 394, 687, 700, 946, 670, 656, 610, 738, 392, 760, 799, 887, 653, 978, 321, 576, 617, 626, 502, 894, 679, 243, 440, 680, 879, 194, 572, 640, 724, 926, 56, 204, 700, 707, 151, 457, 449, 797, 195, 791, 558, 945, 679, 297, 59, 87, 824,
                        713, 663, 412, 693, 342, 606, 134, 108, 571, 364, 631, 212, 174, 643, 304, 329, 343, 97, 430, 751, 497, 314, 983, 374, 822, 928, 140, 206, 73, 263, 980, 736, 876, 478, 430, 305, 170, 514, 364, 692, 829, 82, 855, 953, 676, 246, 369, 970, 294, 750, 807, 827,
                        150, 790, 288, 923, 804, 378, 215, 828, 592, 281, 565, 555, 710, 82, 896, 831, 547, 261, 524, 462, 293, 465, 502, 56, 661, 821, 976, 991, 658, 869, 905, 758, 745, 193, 768, 550, 608, 933, 378, 286, 215, 979, 792, 961, 61, 688, 793, 644, 986, 403, 106, 366,
                        905, 644, 372, 567, 466, 434, 645, 210, 389, 550, 919, 135, 780, 773, 635, 389, 707, 100, 626, 958, 165, 504, 920, 176, 193, 713, 857, 265, 203, 50, 668, 108, 645, 990, 626, 197, 510, 357, 358, 850, 858, 364, 936, 638};
void BZ2_bz__AssertH__fail(int errcode);
void BZ2_hbAssignCodes(Int32 *code, UChar *length, Int32 minLen, Int32 maxLen, Int32 alphaSize);
void BZ2_hbMakeCodeLengths(UChar *len, Int32 *freq, Int32 alphaSize, Int32 maxLen)
{
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
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < alphaSize))
        {
          goto while_break;
        }
        if (*(freq + i) == 0)
        {
        }
        else
        {
          tmp = *(freq + i);
        }
        weight[i + 1] = tmp << 8;
        i++;
      }
    while_break: /* CIL Label */;
    }
    {
      while (1)
      {
        /* CIL Label */
        ;
        nNodes = alphaSize;
        nHeap = 0;

        weight[0] = 0;
        parent[0] = -2;
        i = 1;
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(i <= alphaSize))
            {
              goto while_break___1;
            }
            parent[i] = -1;
            nHeap++;
            heap[nHeap] = i;
            zz = nHeap;
            tmp___0 = heap[zz];
            {
              while (1)
              {
              while_continue___2: /* CIL Label */;
                if (!(weight[tmp___0] < weight[heap[zz >> 1]]))
                {
                  goto while_break___2;
                }
                heap[zz] = heap[zz >> 1];
                zz >>= 1;
              }
            while_break___2: /* CIL Label */;
            }
            heap[zz] = tmp___0;
            i++;
          }
        while_break___1: /* CIL Label */;
        }
        if (!(nHeap < 260))
        {
          {
            BZ2_bz__AssertH__fail(2001);
          }
        }
        {
          while (1)
          {
          while_continue___3: /* CIL Label */;
            if (!(nHeap > 1))
            {
              goto while_break___3;
            }
            n1 = heap[1];
            heap[1] = heap[nHeap];
            nHeap--;
            zz___0 = 1;
            tmp___1 = heap[zz___0];
            {
              while (1)
              {
                /* CIL Label */
                ;
                yy = zz___0 << 1;
                if (yy > nHeap)
                {
                  goto while_break___4;
                }
                if (yy < nHeap)
                {
                  if (weight[heap[yy + 1]] < weight[heap[yy]])
                  {
                    yy++;
                  }
                }
                if (weight[tmp___1] < weight[heap[yy]])
                {
                  goto while_break___4;
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
            zz___1 = 1;
            tmp___2 = heap[zz___1];
            {
              while (1)
              {
                /* CIL Label */
                ;
                yy___0 = zz___1 << 1;
                if (yy___0 > nHeap)
                {
                  goto while_break___5;
                }
                if (yy___0 < nHeap)
                {
                  if (weight[heap[yy___0 + 1]] < weight[heap[yy___0]])
                  {
                    yy___0++;
                  }
                }
                if (weight[tmp___2] < weight[heap[yy___0]])
                {
                  goto while_break___5;
                }
                heap[zz___1] = heap[yy___0];
                zz___1 = yy___0;
              }
            while_break___5: /* CIL Label */;
            }
            heap[zz___1] = tmp___2;
            nNodes++;
            tmp___3 = nNodes;
            parent[n2] = tmp___3;
            parent[n1] = tmp___3;
            if ((weight[n1] & 255) > (weight[n2] & 255))
            {
            }
            else
            {
              tmp___4 = weight[n2] & 255;
            }
            weight[nNodes] = (Int32)((((unsigned int)weight[n1] & 4294967040U) + ((unsigned int)weight[n2] & 4294967040U)) | (unsigned int)(1 + tmp___4));
            parent[nNodes] = -1;
            nHeap++;
            heap[nHeap] = nNodes;
            zz___2 = nHeap;
            tmp___5 = heap[zz___2];
            {
              while (1)
              {
                /* CIL Label */
                ;
                if (!(weight[tmp___5] < weight[heap[zz___2 >> 1]]))
                {
                  goto while_break___6;
                }
                heap[zz___2] = heap[zz___2 >> 1];
                zz___2 >>= 1;
              }
            while_break___6: /* CIL Label */;
            }
          }
        while_break___3: /* CIL Label */;
        }
        tooLong = (Bool)0;
        i = 1;
        {
          while (1)
          {
          while_continue___7: /* CIL Label */;
            if (!(i <= alphaSize))
            {
              goto while_break___7;
            }
            j = 0;
            k = i;
            {
              while (1)
              {
                /* CIL Label */
                ;
                if (!(parent[k] >= 0))
                {
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
        if (!tooLong)
        {
          goto while_break___0;
        }

        {
          while (1)
          {
          while_continue___9: /* CIL Label */;
            if (!(i <= alphaSize))
            {
              goto while_break___9;
            }
            j = weight[i] >> 8;
            j = 1 + j / 2;
            weight[i] = j << 8;
            i++;
          }
        while_break___9: /* CIL Label */;
        }
      }
    while_break___0: /* CIL Label */;
    }
  }
}
void BZ2_hbAssignCodes(Int32 *code, UChar *length, Int32 minLen, Int32 maxLen, Int32 alphaSize)
{
  Int32 n;
  Int32 vec;
  Int32 i;

  {
    vec = 0;
    n = minLen;
    {
      while (1)
      {
      while_continue: /* CIL Label */;
        if (!(n <= maxLen))
        {
          goto while_break;
        }
        i = 0;
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(i < alphaSize))
            {
              goto while_break___0;
            }
            if ((int)*(length + i) == n)
            {
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
    return;
  }
}
extern struct _IO_FILE *stderr;

Int32 BZ2_decompress(DState *s);
UInt32 BZ2_crc32Table[256] = {
    (UInt32)0L, (UInt32)79764919L, (UInt32)159529838L, (UInt32)222504665L, (UInt32)319059676L, (UInt32)398814059L, (UInt32)445009330L, (UInt32)507990021L, (UInt32)638119352L, (UInt32)583659535L, (UInt32)797628118L, (UInt32)726387553L, (UInt32)890018660L, (UInt32)835552979L,
    (UInt32)1015980042L, (UInt32)944750013L, (UInt32)1276238704L, (UInt32)1221641927L, (UInt32)1167319070L, (UInt32)1095957929L, (UInt32)1595256236L, (UInt32)1540665371L, (UInt32)1452775106L, (UInt32)1381403509L, (UInt32)1780037320L, (UInt32)1859660671L, (UInt32)1671105958L, (UInt32)1733955601L,
    (UInt32)2031960084L, (UInt32)2111593891L, (UInt32)1889500026L, (UInt32)1952343757L, (UInt32)2552477408L, (UInt32)2632100695L, (UInt32)2443283854L, (UInt32)2506133561L, (UInt32)2334638140L, (UInt32)2414271883L, (UInt32)2191915858L, (UInt32)2254759653L, (UInt32)3190512472L, (UInt32)3135915759L,
    (UInt32)3081330742L, (UInt32)3009969537L, (UInt32)2905550212L, (UInt32)2850959411L, (UInt32)2762807018L, (UInt32)2691435357L, (UInt32)3560074640L, (UInt32)3505614887L, (UInt32)3719321342L, (UInt32)3648080713L, (UInt32)3342211916L, (UInt32)3287746299L, (UInt32)3467911202L, (UInt32)3396681109L,
    (UInt32)4063920168L, (UInt32)4143685023L, (UInt32)4223187782L, (UInt32)4286162673L, (UInt32)3779000052L, (UInt32)3858754371L, (UInt32)3904687514L, (UInt32)3967668269L, (UInt32)881225847L, (UInt32)809987520L, (UInt32)1023691545L, (UInt32)969234094L, (UInt32)662832811L, (UInt32)591600412L,
    (UInt32)771767749L, (UInt32)717299826L, (UInt32)311336399L, (UInt32)374308984L, (UInt32)453813921L, (UInt32)533576470L, (UInt32)25881363L, (UInt32)88864420L, (UInt32)134795389L, (UInt32)214552010L, (UInt32)2023205639L, (UInt32)2086057648L, (UInt32)1897238633L, (UInt32)1976864222L,
    (UInt32)1804852699L, (UInt32)1867694188L, (UInt32)1645340341L, (UInt32)1724971778L, (UInt32)1587496639L, (UInt32)1516133128L, (UInt32)1461550545L, (UInt32)1406951526L, (UInt32)1302016099L, (UInt32)1230646740L, (UInt32)1142491917L, (UInt32)1087903418L, (UInt32)2896545431L, (UInt32)2825181984L,
    (UInt32)2770861561L, (UInt32)2716262478L, (UInt32)3215044683L, (UInt32)3143675388L, (UInt32)3055782693L, (UInt32)3001194130L, (UInt32)2326604591L, (UInt32)2389456536L, (UInt32)2200899649L, (UInt32)2280525302L, (UInt32)2578013683L, (UInt32)2640855108L, (UInt32)2418763421L, (UInt32)2498394922L,
    (UInt32)3769900519L, (UInt32)3832873040L, (UInt32)3912640137L, (UInt32)3992402750L, (UInt32)4088425275L, (UInt32)4151408268L, (UInt32)4197601365L, (UInt32)4277358050L, (UInt32)3334271071L, (UInt32)3263032808L, (UInt32)3476998961L, (UInt32)3422541446L, (UInt32)3585640067L, (UInt32)3514407732L,
    (UInt32)3694837229L, (UInt32)3640369242L, (UInt32)1762451694L, (UInt32)1842216281L, (UInt32)1619975040L, (UInt32)1682949687L, (UInt32)2047383090L, (UInt32)2127137669L, (UInt32)1938468188L, (UInt32)2001449195L, (UInt32)1325665622L, (UInt32)1271206113L, (UInt32)1183200824L, (UInt32)1111960463L,
    (UInt32)1543535498L, (UInt32)1489069629L, (UInt32)1434599652L, (UInt32)1363369299L, (UInt32)622672798L, (UInt32)568075817L, (UInt32)748617968L, (UInt32)677256519L, (UInt32)907627842L, (UInt32)853037301L, (UInt32)1067152940L, (UInt32)995781531L, (UInt32)51762726L, (UInt32)131386257L,
    (UInt32)177728840L, (UInt32)240578815L, (UInt32)269590778L, (UInt32)349224269L, (UInt32)429104020L, (UInt32)491947555L, (UInt32)4046411278L, (UInt32)4126034873L, (UInt32)4172115296L, (UInt32)4234965207L, (UInt32)3794477266L, (UInt32)3874110821L, (UInt32)3953728444L, (UInt32)4016571915L,
    (UInt32)3609705398L, (UInt32)3555108353L, (UInt32)3735388376L, (UInt32)3664026991L, (UInt32)3290680682L, (UInt32)3236090077L, (UInt32)3449943556L, (UInt32)3378572211L, (UInt32)3174993278L, (UInt32)3120533705L, (UInt32)3032266256L, (UInt32)2961025959L, (UInt32)2923101090L, (UInt32)2868635157L,
    (UInt32)2813903052L, (UInt32)2742672763L, (UInt32)2604032198L, (UInt32)2683796849L, (UInt32)2461293480L, (UInt32)2524268063L, (UInt32)2284983834L, (UInt32)2364738477L, (UInt32)2175806836L, (UInt32)2238787779L, (UInt32)1569362073L, (UInt32)1498123566L, (UInt32)1409854455L, (UInt32)1355396672L,
    (UInt32)1317987909L, (UInt32)1246755826L, (UInt32)1192025387L, (UInt32)1137557660L, (UInt32)2072149281L, (UInt32)2135122070L, (UInt32)1912620623L, (UInt32)1992383480L, (UInt32)1753615357L, (UInt32)1816598090L, (UInt32)1627664531L, (UInt32)1707420964L, (UInt32)295390185L, (UInt32)358241886L,
    (UInt32)404320391L, (UInt32)483945776L, (UInt32)43990325L, (UInt32)106832002L, (UInt32)186451547L, (UInt32)266083308L, (UInt32)932423249L, (UInt32)861060070L, (UInt32)1041341759L, (UInt32)986742920L, (UInt32)613929101L, (UInt32)542559546L, (UInt32)756411363L, (UInt32)701822548L,
    (UInt32)3316196985L, (UInt32)3244833742L, (UInt32)3425377559L, (UInt32)3370778784L, (UInt32)3601682597L, (UInt32)3530312978L, (UInt32)3744426955L, (UInt32)3689838204L, (UInt32)3819031489L, (UInt32)3881883254L, (UInt32)3928223919L, (UInt32)4007849240L, (UInt32)4037393693L, (UInt32)4100235434L,
    (UInt32)4180117107L, (UInt32)4259748804L, (UInt32)2310601993L, (UInt32)2373574846L, (UInt32)2151335527L, (UInt32)2231098320L, (UInt32)2596047829L, (UInt32)2659030626L, (UInt32)2470359227L, (UInt32)2550115596L, (UInt32)2947551409L, (UInt32)2876312838L, (UInt32)2788305887L, (UInt32)2733848168L,
    (UInt32)3165939309L, (UInt32)3094707162L, (UInt32)3040238851L, (UInt32)2985771188L};
void BZ2_blockSort(EState *s);

void BZ2_bsInitWrite(EState *s)
{

  {
    s->bsLive = 0;
  }
}
static void bsFinishWrite(EState *s)
{

  {
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(s->bsLive > 0))
        {
          goto while_break;
        }
        *(s->zbits + s->numZ) = (UChar)(s->bsBuff >> 24);
        (s->numZ)++;
        s->bsBuff <<= 8;
        s->bsLive -= 8;
      }
    while_break: /* CIL Label */;
    }
    return;
  }
}
__inline static void bsW(EState *s, Int32 n, UInt32 v)
{

  {
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(s->bsLive >= 8))
        {
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
    return;
  }
}
static void bsPutUInt32(EState *s, UInt32 u)
{

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
static void bsPutUChar(EState *s, UChar c)
{

  {
    {
      bsW(s, 8, (UInt32)c);
    }
    return;
  }
}
static void makeMaps_e(EState *s)
{
  Int32 i;

  {
    s->nInUse = 0;
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < 256))
        {
          goto while_break;
        }
        if (s->inUse[i])
        {
          s->unseqToSeq[i] = (UChar)s->nInUse;
          (s->nInUse)++;
        }
        i++;
      }
    while_break: /* CIL Label */;
    }
    return;
  }
}
static void generateMTFValues(EState *s)
{
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
      i = 0;
    }
    {

    while_break: /* CIL Label */;
    }
    wr = 0;
    zPend = 0;
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < s->nInUse))
        {
          goto while_break___0;
        }
        yy[i] = (UChar)i;
        i++;
      }
    while_break___0: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < s->nblock))
        {
          goto while_break___1;
        }
        j = (Int32)(*(ptr + i) - 1U);
        if (j < 0)
        {
          j += s->nblock;
        }
        ll_i = s->unseqToSeq[*(block + j)];
        if ((int)yy[0] == (int)ll_i)
        {
          zPend++;
        }
        else
        {
          if (zPend > 0)
          {
            zPend--;
            {
              while (1)
              {
              while_continue___2: /* CIL Label */;
                if (zPend & 1)
                {
                  *(mtfv + wr) = (UInt16)1;
                  wr++;
                  (s->mtfFreq[1])++;
                }
                else
                {
                  *(mtfv + wr) = (UInt16)0;
                  wr++;
                  (s->mtfFreq[0])++;
                }
                if (zPend < 2)
                {
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
            while (1)
            {
              /* CIL Label */
              ;
              if (!((int)rll_i != (int)rtmp))
              {
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
          (s->mtfFreq[j + 1])++;
        }
        i++;
      }
    while_break___1: /* CIL Label */;
    }
    if (zPend > 0)
    {
      zPend--;
      {
        while (1)
        {
          /* CIL Label */
          ;
          if (zPend & 1)
          {
            *(mtfv + wr) = (UInt16)1;
            wr++;
            (s->mtfFreq[1])++;
          }
          else
          {
            *(mtfv + wr) = (UInt16)0;
            wr++;
          }
          if (zPend < 2)
          {
            goto while_break___4;
          }
          zPend = (zPend - 2) / 2;
        }
      while_break___4: /* CIL Label */;
      }
      zPend = 0;
    }
    *(mtfv + wr) = (UInt16)EOB;
    wr++;
    (s->mtfFreq[EOB])++;
    s->nMTF = wr;
    return;
  }
}
static void sendMTFValues(EState *s)
{
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

  {
    mtfv = s->mtfv;

    alphaSize = s->nInUse + 2;
    t = 0;
    {
      while (1)
      {
      while_continue: /* CIL Label */;
        if (!(t < 6))
        {
          goto while_break;
        }

        t++;
      }
    while_break: /* CIL Label */;
    }
    if (!(s->nMTF > 0))
    {
      {
      }
    }
    if (s->nMTF < 200)
    {
      nGroups = 2;
    }
    else
    {
      if (s->nMTF < 600)
      {
        nGroups = 3;
      }
      else
      {
        if (s->nMTF < 1200)
        {
          nGroups = 4;
        }
        else
        {
          if (s->nMTF < 2400)
          {
            nGroups = 5;
          }
          else
          {
            nGroups = 6;
          }
        }
      }
    }
    nPart = nGroups;
    remF = s->nMTF;
    gs = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(nPart > 0))
        {
          goto while_break___1;
        }
        tFreq = remF / nPart;
        ge = gs - 1;
        aFreq = 0;
        {

        while_break___2: /* CIL Label */;
        }
        v = 0;
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(v < alphaSize))
            {
              goto while_break___3;
            }
            if (v >= gs)
            {
              if (v <= ge)
              {
                s->len[nPart - 1][v] = (UChar)0;
              }
              else
              {
                s->len[nPart - 1][v] = (UChar)15;
              }
            }
            else
            {
              s->len[nPart - 1][v] = (UChar)15;
            }
            v++;
          }
        while_break___3: /* CIL Label */;
        }
        nPart--;
        gs = ge + 1;
        remF -= aFreq;
      }
    while_break___1: /* CIL Label */;
    }
    iter = 0;
    {
      while (1)
      {
      while_continue___4: /* CIL Label */;
        if (!(iter < 4))
        {
          goto while_break___4;
        }
        t = 0;
        {
          while (1)
          {
          while_continue___6: /* CIL Label */;
            if (!(t < nGroups))
            {
              goto while_break___6;
            }
            v = 0;
            t++;
          }
        while_break___6: /* CIL Label */;
        }
        nSelectors = 0;

        gs = 0;
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(!(gs >= s->nMTF)))
            {
              goto while_break___9;
            }
            ge = (gs + 50) - 1;
            if (ge >= s->nMTF)
            {
              ge = s->nMTF - 1;
            }
            t = 0;
            {
              while (1)
              {
                /* CIL Label */
                ;
                if (!(t < nGroups))
                {
                  goto while_break___10;
                }
                cost[t] = (UInt16)0;
                t++;
              }
            while_break___10: /* CIL Label */;
            }
            if (nGroups == 6)
            {
              if (50 == (ge - gs) + 1)
              {
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

                cost45 += s->len_pack[icv][2];
                icv = *(mtfv + (gs + 47));
                cost01 += s->len_pack[icv][0];

                icv = *(mtfv + (gs + 48));
                cost01 += s->len_pack[icv][0];
                cost23 += s->len_pack[icv][1];

                icv = *(mtfv + (gs + 49));

                cost23 += s->len_pack[icv][1];
                cost45 += s->len_pack[icv][2];
                cost[0] = (UInt16)(cost01 & 65535U);
                cost[1] = (UInt16)(cost01 >> 16);
                cost[2] = (UInt16)(cost23 & 65535U);

                cost[4] = (UInt16)(cost45 & 65535U);
                cost[5] = (UInt16)(cost45 >> 16);
              }
              else
              {
                goto _L;
              }
            }
            else
            {
            _L:
              i = gs;
              {
                while (1)
                {
                while_continue___11: /* CIL Label */;
                  if (!(i <= ge))
                  {
                    goto while_break___11;
                  }
                  icv___0 = *(mtfv + i);
                  t = 0;
                  {
                    while (1)
                    {
                      /* CIL Label */
                      ;
                      if (!(t < nGroups))
                      {
                        goto while_break___12;
                      }
                      cost[t] = (UInt16)((int)cost[t] + (int)s->len[t][icv___0]);
                      t++;
                    }
                  while_break___12: /* CIL Label */;
                  }
                  i++;
                }
              while_break___11: /* CIL Label */;
              }
            }
            bc = 999999999;
            bt = -1;
            t = 0;
            {
              while (1)
              {
                /* CIL Label */
                ;
                if (!(t < nGroups))
                {
                  goto while_break___13;
                }
                if ((int)cost[t] < bc)
                {
                  bc = (Int32)cost[t];
                  bt = t;
                }
                t++;
              }
            while_break___13: /* CIL Label */;
            }
            s->selector[nSelectors] = (UChar)bt;
            nSelectors++;
            if (nGroups == 6)
            {
            }
            else
            {
            _L___0:
              i = gs;
            }
            gs = ge + 1;
          }
        while_break___9: /* CIL Label */;
        }
        t = 0;
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(t < nGroups))
            {
              goto while_break___16;
            }
            {
              BZ2_hbMakeCodeLengths(&s->len[t][0], &s->rfreq[t][0], alphaSize, 17);
              t++;
            }
          }
        while_break___16: /* CIL Label */;
        }
        iter++;
      }
    while_break___4: /* CIL Label */;
    }
    if (!(nGroups < 8))
    {
      {
      }
    }
    if (nSelectors < 32768)
    {
    }
    else
    {
      {
        BZ2_bz__AssertH__fail(3003);
      }
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < nGroups))
        {
          goto while_break___17;
        }
        pos[i] = (UChar)i;
        i++;
      }
    while_break___17: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < nSelectors))
        {
          goto while_break___18;
        }
        ll_i = s->selector[i];
        j = 0;
        tmp = pos[j];
        {
          while (1)
          {
          while_continue___19: /* CIL Label */;
            if (!((int)ll_i != (int)tmp))
            {
              goto while_break___19;
            }
            j++;
            tmp = pos[j];
            pos[j] = tmp2;
          }
        while_break___19: /* CIL Label */;
        }
        pos[0] = tmp;
        s->selectorMtf[i] = (UChar)j;
        i++;
      }
    while_break___18: /* CIL Label */;
    }
    t = 0;
    {
      while (1)
      {
      while_continue___20: /* CIL Label */;
        if (!(t < nGroups))
        {
          goto while_break___20;
        }
        minLen = 32;
        maxLen = 0;
        i = 0;
        {
          while (1)
          {
          while_continue___21: /* CIL Label */;
            if (!(i < alphaSize))
            {
              goto while_break___21;
            }
            if ((int)s->len[t][i] > maxLen)
            {
              maxLen = (Int32)s->len[t][i];
            }
            if ((int)s->len[t][i] < minLen)
            {
              minLen = (Int32)s->len[t][i];
            }
            i++;
          }
        while_break___21: /* CIL Label */;
        }
        if (!(!(maxLen > 17)))
        {
          {
            BZ2_bz__AssertH__fail(3004);
          }
        }
        if (!(!(minLen < 1)))
        {
          {
            BZ2_bz__AssertH__fail(3005);
          }
        }
        {
          BZ2_hbAssignCodes(&s->code[t][0], &s->len[t][0], minLen, maxLen, alphaSize);
          t++;
        }
      }
    while_break___20: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
      while_continue___22: /* CIL Label */;
        if (!(i < 16))
        {
          goto while_break___22;
        }
        inUse16[i] = (Bool)0;
        j = 0;
        {
          while (1)
          {
          while_continue___23: /* CIL Label */;
            if (!(j < 16))
            {
              goto while_break___23;
            }
            if (s->inUse[i * 16 + j])
            {
              inUse16[i] = (Bool)1;
            }
            j++;
          }
        while_break___23: /* CIL Label */;
        }
        i++;
      }
    while_break___22: /* CIL Label */;
    }
    nBytes = s->numZ;
    i = 0;
    {
      while (1)
      {
      while_continue___24: /* CIL Label */;
        if (!(i < 16))
        {
          goto while_break___24;
        }
        if (inUse16[i])
        {
          {
            bsW(s, 1, (UInt32)1);
          }
        }
        else
        {
          {
            bsW(s, 1, (UInt32)0);
          }
        }
        i++;
      }
    while_break___24: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < 16))
        {
          goto while_break___25;
        }
        if (inUse16[i])
        {
          j = 0;
          {
            while (1)
            {
            while_continue___26: /* CIL Label */;
              if (!(j < 16))
              {
                goto while_break___26;
              }
              if (s->inUse[i * 16 + j])
              {
                {
                  bsW(s, 1, (UInt32)1);
                }
              }
              else
              {
                {
                  bsW(s, 1, (UInt32)0);
                }
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
      nBytes = s->numZ;
      bsW(s, 3, (UInt32)nGroups);
      bsW(s, 15, (UInt32)nSelectors);
      i = 0;
    }
    {
      while (1)
      {
      while_continue___27: /* CIL Label */;
        if (!(i < nSelectors))
        {
          goto while_break___27;
        }
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(j < (Int32)s->selectorMtf[i]))
            {
              goto while_break___28;
            }
            {
              j++;
            }
          }
        while_break___28: /* CIL Label */;
        }
        {
          bsW(s, 1, (UInt32)0);
          i++;
        }
      }
    while_break___27: /* CIL Label */;
    }
    nBytes = s->numZ;
    t = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(t < nGroups))
        {
          goto while_break___29;
        }
        {
          curr = (Int32)s->len[t][0];
          bsW(s, 5, (UInt32)curr);
          i = 0;
        }
        {
          while (1)
          {
          while_continue___30: /* CIL Label */;
            if (!(i < alphaSize))
            {
              goto while_break___30;
            }
            {
              while (1)
              {
              while_continue___31: /* CIL Label */;
                if (!(curr < (Int32)s->len[t][i]))
                {
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
              while (1)
              {
              while_continue___32: /* CIL Label */;
                if (!(curr > (Int32)s->len[t][i]))
                {
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
    nBytes = s->numZ;
    selCtr = 0;
    gs = 0;
    {
      while (1)
      {
      while_continue___33: /* CIL Label */;
        if (!(!(gs >= s->nMTF)))
        {
          goto while_break___33;
        }
        if (ge >= s->nMTF)
        {
          ge = s->nMTF - 1;
        }

        if (nGroups == 6)
        {
          if (50 == (ge - gs) + 1)
          {
            {
              s_len_sel_selCtr = &s->len[s->selector[selCtr]][0];
              s_code_sel_selCtr = &s->code[s->selector[selCtr]][0];
              mtfv_i = *(mtfv + gs);
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 1));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 2));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 3));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 4));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 5));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 6));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 7));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 8));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 9));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 10));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 11));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 12));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 13));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 14));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 15));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 16));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 17));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 18));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 19));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 20));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 21));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 22));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 23));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 24));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 25));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 26));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 27));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 28));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 29));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 30));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 31));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 32));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 33));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 34));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 35));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 36));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 37));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 38));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 39));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 40));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 41));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 42));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 43));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 44));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 45));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 46));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 47));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 48));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
              mtfv_i = *(mtfv + (gs + 49));
              bsW(s, (Int32) * (s_len_sel_selCtr + (int)mtfv_i), (UInt32) * (s_code_sel_selCtr + (int)mtfv_i));
            }
          }
          else
          {
            goto _L___1;
          }
        }
        else
        {
        _L___1:
          i = gs;
          {
            while (1)
            {
            while_continue___34: /* CIL Label */;
              if (!(i <= ge))
              {
                goto while_break___34;
              }
              {
                bsW(s, (Int32)s->len[s->selector[selCtr]][*(mtfv + i)], (UInt32)s->code[s->selector[selCtr]][*(mtfv + i)]);
                i++;
              }
            }
          while_break___34: /* CIL Label */;
          }
        }
        gs = ge + 1;
        selCtr++;
      }
    while_break___33: /* CIL Label */;
    }
    if (!(selCtr == nSelectors))
    {
      {
        BZ2_bz__AssertH__fail(3007);
      }
    }

    return;
  }
}
void BZ2_compressBlock(EState *s, Bool is_last_block)
{

  {
    if (s->nblock > 0)
    {
      s->blockCRC = ~s->blockCRC;
      s->combinedCRC = (s->combinedCRC << 1) | (s->combinedCRC >> 31);
      s->combinedCRC ^= s->blockCRC;

      {
        BZ2_blockSort(s);
      }
    }
    s->zbits = (UChar *)s->arr2 + s->nblock;
    if (s->blockNo == 1)
    {
      {
        BZ2_bsInitWrite(s);
        bsPutUChar(s, (UChar)66);
        bsPutUChar(s, (UChar)90);
        bsPutUChar(s, (UChar)104);
        bsPutUChar(s, (UChar)(48 + s->blockSize100k));
      }
    }
    if (s->nblock > 0)
    {
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
    if (is_last_block)
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

      {
        bsFinishWrite(s);
      }
    }
    return;
  }
}

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern int fclose(FILE *__stream);

extern __attribute__((__nothrow__)) FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);

extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern size_t fwrite(void const *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __s);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ferror)(FILE *__stream);

int BZ2_bzCompressInit(bz_stream *strm, int blockSize100k___0, int verbosity___0, int workFactor___0);
int BZ2_bzCompress(bz_stream *strm, int action);

BZFILE *BZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity___0, int small, void *unused, int nUnused);

void BZ2_bz__AssertH__fail(int errcode) { char const *tmp; }

static void *default_bzalloc(void *opaque, Int32 items, Int32 size)
{
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
static void default_bzfree(void *opaque, void *addr)
{

  {
    if ((unsigned long)addr != (unsigned long)((void *)0))
    {
      {
      }
    }
  }
}
static void prepare_new_block(EState *s)
{
  Int32 i;

  {
    s->nblock = 0;
    s->numZ = 0;
    s->state_out_pos = 0;
    s->blockCRC = (UInt32)4294967295L;

    {
      while (1)
      {
      while_continue: /* CIL Label */;
        if (!(i < 256))
        {
          goto while_break;
        }
        s->inUse[i] = (Bool)0;
        i++;
      }
    while_break: /* CIL Label */;
    }
    (s->blockNo)++;
    return;
  }
}
static void init_RL(EState *s)
{

  {
    s->state_in_ch = (UInt32)256;
    s->state_in_len = 0;
  }
}
static Bool isempty_RL(EState *s)
{

  {
    if (s->state_in_ch < 256U)
    {
    }
    else
    {
      return ((Bool)1);
    }
  }
}
int BZ2_bzCompressInit(bz_stream *strm, int blockSize100k___0, int verbosity___0, int workFactor___0)
{
  Int32 n;
  EState *s;
  int tmp;

  {

    if ((unsigned long)strm == (unsigned long)((void *)0))
    {
    }
    else
    {
      if (blockSize100k___0 < 1)
      {
        return (-2);
      }
      else
      {
        if (blockSize100k___0 > 9)
        {
          return (-2);
        }
        else
        {
          if (workFactor___0 < 0)
          {
            return (-2);
          }
        }
      }
    }

    if ((unsigned long)strm->bzalloc == (unsigned long)((void *)0))
    {
      strm->bzalloc = &default_bzalloc;
    }
    if ((unsigned long)strm->bzfree == (unsigned long)((void *)0))
    {
      strm->bzfree = &default_bzfree;
    }
    {
      s = (EState *)(*(strm->bzalloc))(strm->opaque, (int)sizeof(EState), 1);
    }
    {
      s->strm = strm;
      s->arr1 = (UInt32 *)((void *)0);
      s->arr2 = (UInt32 *)((void *)0);

      n = 100000 * blockSize100k___0;
      s->arr1 = (UInt32 *)(*(strm->bzalloc))(strm->opaque, (int)((unsigned long)n * sizeof(UInt32)), 1);
      s->arr2 = (UInt32 *)(*(strm->bzalloc))(strm->opaque, (int)((unsigned long)(n + 34) * sizeof(UInt32)), 1);
      s->ftab = (UInt32 *)(*(strm->bzalloc))(strm->opaque, (int)(65537UL * sizeof(UInt32)), 1);
    }
    if ((unsigned long)s->arr1 == (unsigned long)((void *)0))
    {
    }
    else
    {
      if ((unsigned long)s->arr2 == (unsigned long)((void *)0))
      {
        goto _L;
      }
      else
      {
        if ((unsigned long)s->ftab == (unsigned long)((void *)0))
        {
        _L:
          if ((unsigned long)s->arr1 != (unsigned long)((void *)0))
          {
            {
              (*(strm->bzfree))(strm->opaque, (void *)s->arr1);
            }
          }
          if ((unsigned long)s->arr2 != (unsigned long)((void *)0))
          {
            {
            }
          }
          if ((unsigned long)s->ftab != (unsigned long)((void *)0))
          {
            {
            }
          }
          if ((unsigned long)s != (unsigned long)((void *)0))
          {
            {
            }
          }
        }
      }
    }
    {
      s->blockNo = 0;
      s->state = 2;
      s->mode = 2;

      s->blockSize100k = blockSize100k___0;
      s->nblockMAX = 100000 * blockSize100k___0 - 19;
      s->verbosity = verbosity___0;

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
static void add_pair_to_block(EState *s)
{
  Int32 i;
  UChar ch;

  {
    ch = (UChar)s->state_in_ch;
    i = 0;
    {
      while (1)
      {
      while_continue: /* CIL Label */;
        if (!(i < s->state_in_len))
        {
          goto while_break;
        }
        s->blockCRC = (s->blockCRC << 8) ^ BZ2_crc32Table[(s->blockCRC >> 24) ^ (unsigned int)ch];
        i++;
      }
    while_break: /* CIL Label */;
    }
    s->inUse[s->state_in_ch] = (Bool)1;
    {
      if (s->state_in_len == 1)
      {
        goto case_1;
      }
      if (s->state_in_len == 2)
      {
        goto case_2;
      }
      if (s->state_in_len == 3)
      {
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
static void flush_RL(EState *s)
{

  {
    if (s->state_in_ch < 256U)
    {
      {
        add_pair_to_block(s);
      }
    }
    {
      init_RL(s);
    }
    return;
  }
}
static Bool copy_input_until_stop(EState *s)
{
  Bool progress_in;
  UInt32 zchh;
  UChar ch;
  UInt32 zchh___0;
  UChar ch___0;

  {
    progress_in = (Bool)0;
    if (s->mode == 2)
    {
      {
        while (1)
        {
        while_continue: /* CIL Label */;
          if (!(!(s->nblock >= s->nblockMAX)))
          {
            goto while_break;
          }
          if ((s->strm)->avail_in == 0U)
          {
            goto while_break;
          }
          progress_in = (Bool)1;
          zchh = (UInt32) * ((UChar *)(s->strm)->next_in);
          if (zchh != s->state_in_ch)
          {
            if (s->state_in_len == 1)
            {
              ch = (UChar)s->state_in_ch;
              s->blockCRC = (s->blockCRC << 8) ^ BZ2_crc32Table[(s->blockCRC >> 24) ^ (unsigned int)ch];
              s->inUse[s->state_in_ch] = (Bool)1;
              *(s->block + s->nblock) = ch;
              (s->nblock)++;
              s->state_in_ch = zchh;
            }
            else
            {
              goto _L___0;
            }
          }
          else
          {
          _L___0:
            if (zchh != s->state_in_ch)
            {
              goto _L;
            }
            else
            {
              if (s->state_in_len == 255)
              {
              _L:
                if (s->state_in_ch < 256U)
                {
                  {
                    add_pair_to_block(s);
                  }
                }
                s->state_in_ch = zchh;
                s->state_in_len = 1;
              }
              else
              {
                (s->state_in_len)++;
              }
            }
          }
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
        }
      while_break: /* CIL Label */;
      }
    }
    else
    {
      {
        while (1)
        {
          /* CIL Label */
          ;
          if (!(!(s->nblock >= s->nblockMAX)))
          {
            goto while_break___0;
          }
          if ((s->strm)->avail_in == 0U)
          {
            goto while_break___0;
          }
          if (s->avail_in_expect == 0U)
          {
            goto while_break___0;
          }

          zchh___0 = (UInt32) * ((UChar *)(s->strm)->next_in);
          if (zchh___0 != s->state_in_ch)
          {
            if (s->state_in_len == 1)
            {
              ch___0 = (UChar)s->state_in_ch;
              s->blockCRC = (s->blockCRC << 8) ^ BZ2_crc32Table[(s->blockCRC >> 24) ^ (unsigned int)ch___0];
              s->inUse[s->state_in_ch] = (Bool)1;
              *(s->block + s->nblock) = ch___0;
              (s->nblock)++;
              s->state_in_ch = zchh___0;
            }
            else
            {
              goto _L___2;
            }
          }
          else
          {
          _L___2:
            if (zchh___0 != s->state_in_ch)
            {
              goto _L___1;
            }
            else
            {
              if (s->state_in_len == 255)
              {
              _L___1:
                if (s->state_in_ch < 256U)
                {
                  {
                    add_pair_to_block(s);
                  }
                }
                s->state_in_ch = zchh___0;
                s->state_in_len = 1;
              }
              else
              {
                (s->state_in_len)++;
              }
            }
          }
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
        }
      while_break___0: /* CIL Label */;
      }
    }
    return (progress_in);
  }
}
static Bool copy_output_until_stop(EState *s)
{
  Bool progress_out;

  {
    progress_out = (Bool)0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(!((s->strm)->avail_out == 0U)))
        {
          goto while_break;
        }
        if (s->state_out_pos >= s->numZ)
        {
          goto while_break;
        }

        *((s->strm)->next_out) = (char)*(s->zbits + s->state_out_pos);
        (s->state_out_pos)++;
        ((s->strm)->avail_out)--;
        ((s->strm)->next_out)++;
        ((s->strm)->total_out_lo32)++;
      }
    while_break: /* CIL Label */;
    }
    return (progress_out);
  }
}
static Bool handle_compress(bz_stream *strm)
{
  Bool progress_in;
  Bool progress_out;
  EState *s;
  Bool tmp;
  Bool tmp___0;

  Bool tmp___2;
  int tmp___3;

  {
    progress_in = (Bool)0;
    progress_out = (Bool)0;
    s = (EState *)strm->state;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (s->state == 1)
        {
          {
            tmp = copy_output_until_stop(s);
            progress_out = (Bool)((int)progress_out | (int)tmp);
          }
          if (s->state_out_pos < s->numZ)
          {
            goto while_break;
          }
          if (s->mode == 4)
          {
            if (s->avail_in_expect == 0U)
            {
              {
                tmp___0 = isempty_RL(s);
              }
              if (tmp___0)
              {
                goto while_break;
              }
            }
          }
          {
            prepare_new_block(s);
            s->state = 2;
          }
        }
        if (s->state == 2)
        {
          {
            tmp___2 = copy_input_until_stop(s);
            progress_in = (Bool)((int)progress_in | (int)tmp___2);
          }
          if (s->mode != 2)
          {
            if (s->avail_in_expect == 0U)
            {
              {
                flush_RL(s);
                BZ2_compressBlock(s, (Bool)(s->mode == 4));
                s->state = 1;
              }
            }
            else
            {
              goto _L;
            }
          }
          else
          {
          _L:
            if (s->nblock >= s->nblockMAX)
            {
              {
                BZ2_compressBlock(s, (Bool)0);
                s->state = 1;
              }
            }
            else
            {
              if ((s->strm)->avail_in == 0U)
              {
                goto while_break;
              }
            }
          }
        }
      }
    while_break: /* CIL Label */;
    }
    if (progress_in)
    {
      tmp___3 = 1;
    }
    return ((Bool)tmp___3);
  }
}
int BZ2_bzCompress(bz_stream *strm, int action)
{
  Bool progress;
  EState *s;
  int tmp;
  Bool tmp___0;
  Bool tmp___1;

  {
    s = (EState *)strm->state;
    if ((unsigned long)s == (unsigned long)((void *)0))
    {
      return (-2);
    }
    if ((unsigned long)s->strm != (unsigned long)strm)
    {
      return (-2);
    }
  preswitch:
  {
    if (s->mode == 1)
    {
    }
    if (s->mode == 2)
    {
      goto case_2;
    }
    if (s->mode == 4)
    {
      goto case_4;
    }
    goto switch_break;
  case_1: /* CIL Label */
    return (-1);
  case_2: /* CIL Label */
    if (action == 0)
    {
      {
        progress = handle_compress(strm);
      }
      if (progress)
      {
        tmp = 1;
      }
      return (tmp);
    }
    else
    {
      if (action == 1)
      {

        goto preswitch;
      }
      else
      {
        if (action == 2)
        {
          s->avail_in_expect = strm->avail_in;
          s->mode = 4;
          goto preswitch;
        }
      }
    }
  case_3: /* CIL Label */
    if (s->avail_in_expect != (s->strm)->avail_in)
    {
      return (-1);
    }
    {
      progress = handle_compress(strm);
    }
    if (s->avail_in_expect > 0U)
    {
      return (2);
    }
    else
    {
      {
        tmp___0 = isempty_RL(s);
      }
      if (tmp___0)
      {
        if (s->state_out_pos < s->numZ)
        {
          return (2);
        }
      }
    }
    s->mode = 2;
    return (1);
  case_4: /* CIL Label */
    if (action != 2)
    {
    }

    {
      progress = handle_compress(strm);
    }
    if (s->avail_in_expect > 0U)
    {
      return (3);
    }
    else
    {
      {
        tmp___1 = isempty_RL(s);
      }
      if (tmp___1)
      {
        if (s->state_out_pos < s->numZ)
        {
          return (3);
        }
      }
    }
    s->mode = 1;
    return (4);
  switch_break: /* CIL Label */;
  }
    return (0);
  }
}

BZFILE *BZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k___0, int verbosity___0, int workFactor___0)
{
  Int32 ret;
  bzFile *bzf;
  int tmp;

  {

    if ((unsigned long)bzf != (unsigned long)((void *)0))
    {
      bzf->lastErr = 0;
    }
    if ((unsigned long)f == (unsigned long)((void *)0))
    {
    }
    else
    {
      if (blockSize100k___0 < 1)
      {
      }
      else
      {
        if (blockSize100k___0 > 9)
        {
          goto _L___0;
        }
        else
        {
          if (workFactor___0 < 0)
          {
            goto _L___0;
          }
          else
          {
            if (workFactor___0 > 250)
            {
              goto _L___0;
            }
            else
            {
              if (verbosity___0 < 0)
              {
              }
              else
              {
                if (verbosity___0 > 4)
                {
                _L___0:
                  if ((unsigned long)bzerror != (unsigned long)((void *)0))
                  {
                    *bzerror = -2;
                  }
                  if ((unsigned long)bzf != (unsigned long)((void *)0))
                  {
                    bzf->lastErr = -2;
                  }
                  return ((void *)0);
                }
              }
            }
          }
        }
      }
    }
    {
      tmp = ferror(f);
    }
    if (tmp)
    {
      if ((unsigned long)bzerror != (unsigned long)((void *)0))
      {
        *bzerror = -6;
      }
      if ((unsigned long)bzf != (unsigned long)((void *)0))
      {
        bzf->lastErr = -6;
      }
      return ((void *)0);
    }
    {
      bzf = (bzFile *)malloc(sizeof(bzFile));
    }
    if ((unsigned long)bzf == (unsigned long)((void *)0))
    {
      if ((unsigned long)bzf != (unsigned long)((void *)0))
      {
        bzf->lastErr = -3;
      }
      return ((void *)0);
    }
    if ((unsigned long)bzf != (unsigned long)((void *)0))
    {
      bzf->lastErr = 0;
    }
    bzf->initialisedOk = (Bool)0;
    bzf->bufN = 0;
    bzf->handle = f;
    bzf->writing = (Bool)1;

    {
      ret = BZ2_bzCompressInit(&bzf->strm, blockSize100k___0, verbosity___0, workFactor___0);
    }
    if (ret != 0)
    {
      if ((unsigned long)bzf != (unsigned long)((void *)0))
      {
        bzf->lastErr = ret;
      }
      {
        free((void *)bzf);
      }
      return ((void *)0);
    }
    bzf->strm.avail_in = 0U;

    return ((BZFILE *)bzf);
  }
}
void BZ2_bzWrite(int *bzerror, BZFILE *b, void *buf, int len)
{
  Int32 n;
  Int32 n2;
  Int32 ret;
  bzFile *bzf;
  int tmp;
  int tmp___0;

  {
    bzf = (bzFile *)b;

    if ((unsigned long)bzf != (unsigned long)((void *)0))
    {
      bzf->lastErr = 0;
    }
    if ((unsigned long)bzf == (unsigned long)((void *)0))
    {
      goto _L;
    }
    else
    {
      if ((unsigned long)buf == (unsigned long)((void *)0))
      {
        goto _L;
      }
      else
      {
        if (len < 0)
        {
        _L:
          if ((unsigned long)bzerror != (unsigned long)((void *)0))
          {
            *bzerror = -2;
          }
          if ((unsigned long)bzf != (unsigned long)((void *)0))
          {
            bzf->lastErr = -2;
          }
          return;
        }
      }
    }
    if (!bzf->writing)
    {
      if ((unsigned long)bzerror != (unsigned long)((void *)0))
      {
        *bzerror = -1;
      }
      if ((unsigned long)bzf != (unsigned long)((void *)0))
      {
        bzf->lastErr = -1;
      }
      return;
    }
    {
      tmp = ferror(bzf->handle);
    }
    if (tmp)
    {
      if ((unsigned long)bzerror != (unsigned long)((void *)0))
      {
        *bzerror = -6;
      }
      if ((unsigned long)bzf != (unsigned long)((void *)0))
      {
        bzf->lastErr = -6;
      }
      return;
    }
    if (len == 0)
    {
      if ((unsigned long)bzerror != (unsigned long)((void *)0))
      {
        *bzerror = 0;
      }
      if ((unsigned long)bzf != (unsigned long)((void *)0))
      {
        bzf->lastErr = 0;
      }
    }
    bzf->strm.avail_in = (unsigned int)len;
    bzf->strm.next_in = (char *)buf;
    {
      while (1)
      {
        /* CIL Label */
        ;
        {
          bzf->strm.avail_out = 5000U;
          bzf->strm.next_out = bzf->buf;
          ret = BZ2_bzCompress(&bzf->strm, 0);
        }
        if (ret != 1)
        {
          if ((unsigned long)bzf != (unsigned long)((void *)0))
          {
            bzf->lastErr = ret;
          }
          return;
        }
        if (bzf->strm.avail_out < 5000U)
        {
          {
            n = (Int32)(5000U - bzf->strm.avail_out);
            n2 = (Int32)fwrite((void const * /* __restrict  */)((void *)(bzf->buf)), sizeof(UChar), (size_t)n, (FILE * /* __restrict  */)bzf->handle);
          }
          if (n != n2)
          {
            goto _L___0;
          }
          else
          {
            {
              tmp___0 = ferror(bzf->handle);
            }
            if (tmp___0)
            {
            _L___0:
              if ((unsigned long)bzerror != (unsigned long)((void *)0))
              {
              }
              return;
            }
          }
        }
        if (bzf->strm.avail_in == 0U)
        {
          if ((unsigned long)bzerror != (unsigned long)((void *)0))
          {
            *bzerror = 0;
          }
          if ((unsigned long)bzf != (unsigned long)((void *)0))
          {
            bzf->lastErr = 0;
          }
          return;
        }
      }
      /* CIL Label */
      ;
    }
  }
}
void BZ2_bzWriteClose64(int *bzerror, BZFILE *b, int abandon, unsigned int *nbytes_in_lo32, unsigned int *nbytes_in_hi32, unsigned int *nbytes_out_lo32, unsigned int *nbytes_out_hi32)
{
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
    if ((unsigned long)bzf == (unsigned long)((void *)0))
    {

      return;
    }
    if (!bzf->writing)
    {
      if ((unsigned long)bzerror != (unsigned long)((void *)0))
      {
        *bzerror = -1;
      }
      if ((unsigned long)bzf != (unsigned long)((void *)0))
      {
        bzf->lastErr = -1;
      }
      return;
    }
    {
      tmp = ferror(bzf->handle);
    }
    if (tmp)
    {
      if ((unsigned long)bzerror != (unsigned long)((void *)0))
      {
        *bzerror = -6;
      }

      return;
    }

    if (!abandon)
    {
      if (bzf->lastErr == 0)
      {
        {
          while (1)
          {
            /* CIL Label */
            ;
            {
              bzf->strm.avail_out = 5000U;
              bzf->strm.next_out = bzf->buf;
              ret = BZ2_bzCompress(&bzf->strm, 2);
            }
            if (ret != 3)
            {
              if (ret != 4)
              {
                if ((unsigned long)bzerror != (unsigned long)((void *)0))
                {
                  *bzerror = ret;
                }

                return;
              }
            }
            if (bzf->strm.avail_out < 5000U)
            {
              {
                n = (Int32)(5000U - bzf->strm.avail_out);
                n2 = (Int32)fwrite((void const * /* __restrict  */)((void *)(bzf->buf)), sizeof(UChar), (size_t)n, (FILE * /* __restrict  */)bzf->handle);
              }
              if (n != n2)
              {
                goto _L;
              }
              else
              {
                {
                  tmp___0 = ferror(bzf->handle);
                }
                if (tmp___0)
                {
                _L:
                  if ((unsigned long)bzerror != (unsigned long)((void *)0))
                  {
                  }
                  return;
                }
              }
            }
            if (ret == 4)
            {
              goto while_break;
            }
          }
        while_break: /* CIL Label */;
        }
      }
    }
    if (!abandon)
    {
      {
      }
      if (!tmp___2)
      {
        {

          tmp___1 = ferror(bzf->handle);
        }
        if (tmp___1)
        {

          return;
        }
      }
    }

    if ((unsigned long)bzerror != (unsigned long)((void *)0))
    {
      *bzerror = 0;
    }
    if ((unsigned long)bzf != (unsigned long)((void *)0))
    {
      bzf->lastErr = 0;
    }
    return;
  }
}

static char const *bzerrorstrings[16] = {"OK", "SEQUENCE_ERROR", "PARAM_ERROR", "MEM_ERROR", "DATA_ERROR", "DATA_ERROR_MAGIC", "IO_ERROR", "UNEXPECTED_EOF", "OUTBUFF_FULL", "CONFIG_ERROR", "???", "???", "???", "???", "???", "???"};

extern int(__attribute__((__nonnull__(1))) open)(char const *__file, int __oflag, ...) __asm__("open64");

Int32 verbosity;
Bool keepInputFiles;
Bool smallMode;
Bool deleteOutputOnInterrupt;
Bool forceOverwrite;

Bool unzFailsExist;
Bool noisy;
Int32 numFileNames;

Int32 blockSize100k;
Int32 exitValue;
Int32 opMode;
Int32 srcMode;
Int32 longestFileName;
Char inName[1034];
Char outName[1034];

Char *progName;
Char progNameReally[1034];
FILE *outputHandleJustInCase;
Int32 workFactor;
static __attribute__((__noreturn__)) void panic(Char const *s);
static __attribute__((__noreturn__)) void ioError(void);

static __attribute__((__noreturn__)) void compressedStreamEOF(void);
static void copyFileName(Char *to, Char *from);

static void uInt64_from_UInt32s(UInt64 *n, UInt32 lo32, UInt32 hi32)
{

  {

    n->b[2] = (UChar)((lo32 >> 16) & 255U);
    n->b[1] = (UChar)((lo32 >> 8) & 255U);
  }
}
static double uInt64_to_double(UInt64 *n)
{
  Int32 i;
  double base;
  double sum;

  {

    {
      while (1)
      {
      while_continue: /* CIL Label */;
        if (!(i < 8))
        {
          goto while_break;
        }

        base *= 256.0;
        i++;
      }
    while_break: /* CIL Label */;
    }
    return (sum);
  }
}
static void uInt64_toAscii(char *outbuf, UInt64 *n)
{

  Int32 q;
  UChar buf[32];
  Int32 nBuf;
  UInt64 n_copy;
  Bool tmp;

  {

    n_copy = *n;
    {
      while (1)
      {
      while_continue: /* CIL Label */;
        {
          nBuf++;
        }
        if (tmp)
        {
          goto while_break;
        }
      }
    while_break: /* CIL Label */;
    }
    *(outbuf + nBuf) = (char)0;
  }
}
static Bool myfeof___0(FILE *f)
{
  Int32 c;
  Int32 tmp;

  {
    {
      tmp = fgetc(f);
      c = tmp;
    }
    if (c == -1)
    {
      return ((Bool)1);
    }
    {
      ungetc(c, f);
    }
    return ((Bool)0);
  }
}
static void compressStream(FILE *stream, FILE *zStream)
{
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
      bzf = (void *)0;
      tmp = ferror(stream);
    }
    if (tmp)
    {
      goto errhandler_io;
    }
    {
      tmp___0 = ferror(zStream);
    }
    if (tmp___0)
    {
      goto errhandler_io;
    }
    {
      bzf = BZ2_bzWriteOpen(&bzerr, zStream, blockSize100k, verbosity, workFactor);
    }
    if (bzerr != 0)
    {
      goto errhandler;
    }

    {
      while (1)
      {
        /* CIL Label */
        ;
        {
          tmp___1 = myfeof___0(stream);
        }
        if (tmp___1)
        {
          goto while_break;
        }
        {
          nIbuf = (Int32)fread((void * /* __restrict  */)(ibuf), sizeof(UChar), (size_t)5000, (FILE * /* __restrict  */)stream);
          tmp___2 = ferror(stream);
        }
        if (tmp___2)
        {
          goto errhandler_io;
        }
        if (nIbuf > 0)
        {
          {
            BZ2_bzWrite(&bzerr, bzf, (void *)(ibuf), nIbuf);
          }
        }
        if (bzerr != 0)
        {
          goto errhandler;
        }
      }
    while_break: /* CIL Label */;
    }
    {
      BZ2_bzWriteClose64(&bzerr, bzf, 0, &nbytes_in_lo32, &nbytes_in_hi32, &nbytes_out_lo32, &nbytes_out_hi32);
    }
    if (bzerr != 0)
    {
      goto errhandler;
    }
    {
      tmp___3 = ferror(zStream);
    }

    {
      ret = fflush(zStream);
    }

    if ((unsigned long)zStream != (unsigned long)stdout)
    {
      {
        tmp___4 = fileno(zStream);
        fd = tmp___4;
      }
      if (fd < 0)
      {
        goto errhandler_io;
      }
      {
        ret = fclose(zStream);
      }
      if (ret == -1)
      {
        goto errhandler_io;
      }
    }
    {
      outputHandleJustInCase = (FILE *)((void *)0);
    }
    if (tmp___5)
    {
      goto errhandler_io;
    }
    {
      ret = fclose(stream);
    }
    if (verbosity >= 1)
    {
      if (nbytes_in_lo32 == 0U)
      {
      }
      else
      {
      _L:
      {
        uInt64_from_UInt32s(&nbytes_in, nbytes_in_lo32, nbytes_in_hi32);
        uInt64_from_UInt32s(&nbytes_out, nbytes_out_lo32, nbytes_out_hi32);
        nbytes_in_d = uInt64_to_double(&nbytes_in);
        nbytes_out_d = uInt64_to_double(&nbytes_out);
        uInt64_toAscii(buf_nin, &nbytes_in);
        uInt64_toAscii(buf_nout, &nbytes_out);
        fprintf((FILE * /* __restrict  */)stderr,
                (char const * /* __restrict  */) "%6.3f:1, %6.3f bits/byte, "
                                                 "%5.2f%% saved, %s in, %s out.\n",
                nbytes_in_d / nbytes_out_d, (8.0 * nbytes_out_d) / nbytes_in_d, 100.0 * (1.0 - nbytes_out_d / nbytes_in_d), buf_nin, buf_nout);
      }
      }
    }
    return;
  errhandler:
  {
    BZ2_bzWriteClose64(&bzerr_dummy, bzf, 1, &nbytes_in_lo32, &nbytes_in_hi32, &nbytes_out_lo32, &nbytes_out_hi32);
  }
    {
      if (bzerr == -6)
      {
        goto errhandler_io;
      }
      goto switch_default;
    case_neg_9:
    { /* CIL Label */
    }
      goto switch_break;
    case_neg_3:
    { /* CIL Label */
    }
      goto switch_break;
    errhandler_io:
    case_neg_6:
    { /* CIL Label */
    }
      goto switch_break;
    switch_default:
    { /* CIL Label */
      panic("compress:unexpected error");
    }
    switch_break: /* CIL Label */;
    }
    {
      panic("compress:end");
    }
  }
}
static void setExit(Int32 v)
{

  {
    return;
  }
}

static void cleanUpAndFail(Int32 ec)
{
  IntNative retVal;

  {

    {
      exit(exitValue);
    }
  }
}

static void panic(Char const *s)
{

  {
    {
      cleanUpAndFail(3);
    }
  }
}

static __attribute__((__noreturn__)) void compressedStreamEOF(void);

static __attribute__((__noreturn__)) void ioError(void);

static __attribute__((__noreturn__)) void outOfMemory(void);

static void copyFileName(Char *to, Char *from)
{
  size_t tmp;

  {
    {
      tmp = strlen((char const *)from);
    }
    if (tmp > 1024UL)
    {
      {
      }
    }
    {
      strncpy((char * /* __restrict  */)to, (char const * /* __restrict  */)from, (size_t)1024);
    }
    return;
  }
}
static Bool fileExists(Char *name)
{
  FILE *tmp;
  FILE *tmp___0;
  Bool exists;

  {
    {
      tmp___0 = fopen((char const * /* __restrict  */)name, (char const * /* __restrict  */) "rb");

      exists = (Bool)((unsigned long)tmp != (unsigned long)((void *)0));
    }

    return (exists);
  }
}
static FILE *fopen_output_safely(Char *name, char const *mode)
{
  FILE *fp;
  IntNative fh;

  {
    {
      fh = open((char const *)name, 193, 384);
    }
    {
      fp = fdopen(fh, mode);
    }
    if ((unsigned long)fp == (unsigned long)((void *)0))
    {
      {
        close(fh);
      }
    }
    return (fp);
  }
}
static Bool notAStandardFile(Char *name)
{
  IntNative i;
  struct stat statBuf;

  {
    {
      i = lstat((char const * /* __restrict  */)name, (struct stat * /* __restrict  */)(&statBuf));
    }
  }
}
static struct stat fileMetaInfo;

static Bool containsDubiousChars(Char *name) {}
Char const *zSuffix[4] = {".bz2", ".bz", ".tbz2", ".tbz"};

static void compress(Char *name)
{
  FILE *inStr;
  FILE *outStr;

  Int32 i;
  struct stat statBuf;
  Bool tmp;
  int *tmp___0;
  char *tmp___1;
  Bool tmp___2;

  Bool tmp___4;
  Bool tmp___5;

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
      if (srcMode == 1)
      {
        goto case_1;
      }
      if (srcMode == 3)
      {
        goto case_3;
      }
      if (srcMode == 2)
      {
        goto case_2;
      }
      goto switch_break;
    case_1:
    { /* CIL Label */
      copyFileName(outName, (Char *)"(stdout)");
    }

    case_3:
    { /* CIL Label */
      copyFileName(inName, name);
      copyFileName(outName, name);
      strcat((char * /* __restrict  */)(outName), (char const * /* __restrict  */) ".bz2");
    }

    case_2:
    { /* CIL Label */
      copyFileName(inName, name);
    }
      goto switch_break;
    switch_break: /* CIL Label */;
    }
    if (srcMode != 1)
    {
      {
        tmp = containsDubiousChars(inName);
      }
      if (tmp)
      {

        {
        }
        return;
      }
    }
    if (srcMode != 1)
    {
      {
        tmp___2 = fileExists(inName);
      }
      if (!tmp___2)
      {
        {
          tmp___0 = __errno_location();
          tmp___1 = strerror(*tmp___0);

          setExit(1);
        }
        return;
      }
    }
    i = 0;
    {

    while_break: /* CIL Label */;
    }
    if (srcMode == 3)
    {
      goto _L;
    }
    else
    {
      if (srcMode == 2)
      {
      _L:
      {
        stat((char const * /* __restrict  */)(inName), (struct stat * /* __restrict  */)(&statBuf));
      }
        if ((statBuf.st_mode & 61440U) == 16384U)
        {
          {
            fprintf((FILE * /* __restrict  */)stderr, (char const * /* __restrict  */) "%s: Input file %s is a directory.\n", progName, inName);
          }
          return;
        }
      }
    }
    if (srcMode == 3)
    {
      if (!forceOverwrite)
      {
        {
          tmp___4 = notAStandardFile(inName);
        }
        if (tmp___4)
        {

          {
            setExit(1);
          }
          return;
        }
      }
    }
    if (srcMode == 3)
    {
      {
        tmp___5 = fileExists(outName);
      }
    }

    if (srcMode == 3)
    {
      {
      }
    }
    {
      if (srcMode == 1)
      {
        goto case_1___0;
      }
      if (srcMode == 2)
      {
        goto case_2___0;
      }
      if (srcMode == 3)
      {
        goto case_3___0;
      }

    case_1___0:
    { /* CIL Label */
      outStr = stdout;
      tmp___7 = fileno(stdout);
      tmp___8 = isatty(tmp___7);
    }

      goto switch_break___0;
    case_2___0:
    { /* CIL Label */
      inStr = fopen((char const * /* __restrict  */)(inName), (char const * /* __restrict  */) "rb");
      tmp___9 = fileno(stdout);
      tmp___10 = isatty(tmp___9);
    }
      if (tmp___10)
      {
        {
        }
        if ((unsigned long)inStr != (unsigned long)((void *)0))
        {
          {
            fclose(inStr);
          }
        }
        {
          setExit(1);
        }
        return;
      }
      if ((unsigned long)inStr == (unsigned long)((void *)0))
      {
        {
          tmp___11 = __errno_location();
          tmp___12 = strerror(*tmp___11);
          fprintf((FILE * /* __restrict  */)stderr, (char const * /* __restrict  */) "%s: Can\'t open input file %s: %s.\n", progName, inName, tmp___12);
          setExit(1);
        }
        return;
      }

    case_3___0:
    { /* CIL Label */
      inStr = fopen((char const * /* __restrict  */)(inName), (char const * /* __restrict  */) "rb");
      outStr = fopen_output_safely(outName, "wb");
    }
      if ((unsigned long)outStr == (unsigned long)((void *)0))
      {
        {
          tmp___13 = __errno_location();

          fprintf((FILE * /* __restrict  */)stderr,
                  (char const * /* __restrict  */) "%s: Can\'t create output "
                                                   "file %s: %s.\n",
                  progName, outName, tmp___14);
        }
        if ((unsigned long)inStr != (unsigned long)((void *)0))
        {
          {
            fclose(inStr);
          }
        }
        {
          setExit(1);
        }
        return;
      }
      if ((unsigned long)inStr == (unsigned long)((void *)0))
      {
        {
          tmp___15 = __errno_location();

          fprintf((FILE * /* __restrict  */)stderr, (char const * /* __restrict  */) "%s: Can\'t open input file %s: %s.\n", progName, inName, tmp___16);
        }
        if ((unsigned long)outStr != (unsigned long)((void *)0))
        {
          {
            fclose(outStr);
          }
        }
        {
          setExit(1);
        }
        return;
      }

    switch_default:
    { /* CIL Label */
    }
    switch_break___0: /* CIL Label */;
    }
    {

      compressStream(inStr, outStr);
      outputHandleJustInCase = (FILE *)((void *)0);
    }
    if (srcMode == 3)
    {
      {
      }
      if (!keepInputFiles)
      {
        {
          tmp___17 = remove((char const *)(inName));
        }
        if (retVal != 0)
        {
          {
          }
        }
      }
    }
    deleteOutputOnInterrupt = (Bool)0;
    return;
  }
}
static void testf(Char *name)
{
  FILE *inStr;

  struct stat statBuf;
  Bool tmp;
  int *tmp___0;
  char *tmp___1;
  Bool tmp___2;
  int tmp___3;

  int *tmp___5;
  char *tmp___6;

  {

    {
      if (srcMode == 1)
      {
        goto case_1;
      }
      if (srcMode == 3)
      {
        goto case_3;
      }
      if (srcMode == 2)
      {
        goto case_2;
      }
      goto switch_break;
    case_1:
    { /* CIL Label */
      copyFileName(inName, (Char *)"(stdin)");
    }
      goto switch_break;
    case_3:
    { /* CIL Label */
      copyFileName(inName, name);
    }
      goto switch_break;
    case_2:
    { /* CIL Label */
      copyFileName(inName, name);
    }

    switch_break: /* CIL Label */;
    }
    if (srcMode != 1)
    {
      {
        tmp = containsDubiousChars(inName);
      }
      if (tmp)
      {

        {
          setExit(1);
        }
        return;
      }
    }
    if (srcMode != 1)
    {
      {
        tmp___2 = fileExists(inName);
      }
      if (!tmp___2)
      {
        {
          tmp___0 = __errno_location();

          fprintf((FILE * /* __restrict  */)stderr, (char const * /* __restrict  */) "%s: Can\'t open input %s: %s.\n", progName, inName, tmp___1);
          setExit(1);
        }
        return;
      }
    }
    if (srcMode != 1)
    {
      {
        stat((char const * /* __restrict  */)(inName), (struct stat * /* __restrict  */)(&statBuf));
      }
      if ((statBuf.st_mode & 61440U) == 16384U)
      {
        {

          setExit(1);
        }
        return;
      }
    }
    {

    case_1___0:
    { /* CIL Label */
      tmp___3 = fileno(stdin);
    }

      inStr = stdin;

    case_2___0: /* CIL Label */
    case_3___0:
    { /* CIL Label */
      inStr = fopen((char const * /* __restrict  */)(inName), (char const * /* __restrict  */) "rb");
    }
      if ((unsigned long)inStr == (unsigned long)((void *)0))
      {
        {
          tmp___5 = __errno_location();
          tmp___6 = strerror(*tmp___5);
          fprintf((FILE * /* __restrict  */)stderr, (char const * /* __restrict  */) "%s: Can\'t open input file %s:%s.\n", progName, inName, tmp___6);
          setExit(1);
        }
        return;
      }

    switch_default:
    { /* CIL Label */
    } /* CIL Label */
    ;
    }

    return;
  }
}
static void *myMalloc(Int32 n)
{
  void *p;

  {
    {
      p = malloc((size_t)n);
    }
    if ((unsigned long)p == (unsigned long)((void *)0))
    {
      {
      }
    }
    return (p);
  }
}
static Cell *mkCell(void)
{
  Cell *c;

  {
    {
      c = (Cell *)myMalloc((Int32)sizeof(Cell));

      c->link = (struct zzzz *)((void *)0);
    }
    return (c);
  }
}
static Cell *snocString(Cell *root, Char *name)
{
  Cell *tmp;
  Cell *tmp___0;
  size_t tmp___1;
  Cell *tmp___3;

  {
    if ((unsigned long)root == (unsigned long)((void *)0))
    {
      {
        tmp___0 = mkCell();
        tmp = tmp___0;
        tmp___1 = strlen((char const *)name);
        tmp->name = (Char *)myMalloc((Int32)(5UL + tmp___1));
        strcpy((char * /* __restrict  */)tmp->name, (char const * /* __restrict  */)name);
      }
      return (tmp);
    }
    else
    {
      tmp___3 = root;
      {
        while (1)
        {
          /* CIL Label */
          ;

          tmp___3 = tmp___3->link;
        }
        /* CIL Label */
        ;
      }
      {
        tmp___3->link = snocString(tmp___3->link, name);
      }
    }
  }
}

IntNative main(IntNative argc, Char **argv)
{
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

  int tmp___9;
  int tmp___10;

  int tmp___26;
  int tmp___27;
  int tmp___28;
  int tmp___29;

  int tmp___31;

  {

    {

      blockSize100k = 9;

      numFileNames = 0;

      deleteOutputOnInterrupt = (Bool)0;

      copyFileName(outName, (Char *)"(none)");

      progName = &progNameReally[0];
    }
    {
      i = 1;
    }
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i <= argc - 1))
        {
          goto while_break___0;
        }
        {
          argList = snocString(argList, *(argv + i));
          i++;
        }
      }
    while_break___0: /* CIL Label */;
    }
    longestFileName = 7;

    decode = (Bool)1;
    aa = argList;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!((unsigned long)aa != (unsigned long)((void *)0)))
        {
          goto while_break___1;
        }
        if (tmp___0 == 0)
        {

          goto __Cont;
        }

        {
          numFileNames++;
        }

      __Cont:
        aa = aa->link;
      }
    while_break___1: /* CIL Label */;
    }
    if (numFileNames == 0)
    {
      srcMode = 1;
    }
    else
    {
      srcMode = 3;
    }
    {
      opMode = 1;
      tmp___3 = strstr((char const *)progName, "unzip");
    }
    if ((unsigned long)tmp___3 != (unsigned long)((char *)0))
    {
      opMode = 2;
    }
    else
    {
      {
        tmp___4 = strstr((char const *)progName, "UNZIP");
      }
      if ((unsigned long)tmp___4 != (unsigned long)((char *)0))
      {
        opMode = 2;
      }
    }

    aa = argList;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!((unsigned long)aa != (unsigned long)((void *)0)))
        {
          goto while_break___2;
        }
        if (tmp___9 == 0)
        {
          goto while_break___2;
        }
        if ((int)*(aa->name + 0) == 45)
        {
          if ((int)*(aa->name + 1) != 45)
          {
            j = 1;
            {
              while (1)
              {
                /* CIL Label */
                ;
                {

                  if ((int)*(aa->name + j) == 51)
                  {
                    goto case_51;
                  }

                  goto switch_default;
                case_99: /* CIL Label */
                  goto switch_break;
                case_100: /* CIL Label */
                  goto switch_break;
                case_122: /* CIL Label */
                  goto switch_break;
                case_102: /* CIL Label */
                  goto switch_break;
                case_116: /* CIL Label */
                  goto switch_break;
                case_107: /* CIL Label */
                  goto switch_break;
                case_115: /* CIL Label */
                  goto switch_break;
                case_113: /* CIL Label */
                  noisy = (Bool)0;
                  goto switch_break;
                case_49: /* CIL Label */
                  goto switch_break;
                case_50: /* CIL Label */
                case_51: /* CIL Label */
                case_52: /* CIL Label */
                  goto switch_break;
                case_53: /* CIL Label */
                  goto switch_break;
                case_54: /* CIL Label */
                  goto switch_break;
                case_55: /* CIL Label */
                  goto switch_break;
                case_56: /* CIL Label */
                  goto switch_break;
                case_57: /* CIL Label */
                  goto switch_break;
                case_86: /* CIL Label */
                case_76:
                { /* CIL Label */
                }
                case_118: /* CIL Label */
                  goto switch_break;
                case_104:
                { /* CIL Label */
                }
                  goto switch_break;
                switch_default:
                { /* CIL Label */
                }
                switch_break: /* CIL Label */;
                }
                j++;
              }
            while_break___3: /* CIL Label */;
            }
          }
        }
      }
    while_break___2: /* CIL Label */;
    }
    aa = argList;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!((unsigned long)aa != (unsigned long)((void *)0)))
        {
          goto while_break___4;
        }
        if (tmp___10 == 0)
        {
          goto while_break___4;
        }
        if (tmp___28 == 0)
        {
          srcMode = 2;
        }
        else
        {
          if (tmp___27 == 0)
          {
          }
          else
          {
            if (tmp___26 == 0)
            {
            }
          }
        }
        aa = aa->link;
      }
    while_break___4: /* CIL Label */;
    }
    if (opMode == 1)
    {
      if (srcMode == 1)
      {
        {
        }
      }
      else
      {

        aa = argList;
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!((unsigned long)aa != (unsigned long)((void *)0)))
            {
              goto while_break___5;
            }
            {
              tmp___29 = strcmp((char const *)aa->name, "--");
            }
            if (tmp___29 == 0)
            {

              goto __Cont___0;
            }
            if ((int)*(aa->name + 0) == 45)
            {
              if (decode)
              {
                goto __Cont___0;
              }
            }
            {
              compress(aa->name);
            }
          __Cont___0:
            aa = aa->link;
          }
        while_break___5: /* CIL Label */;
        }
      }
    }
    else
    {
      if (opMode == 2)
      {

        if (srcMode == 1)
        {
          {
          }
        }
        else
        {
          decode = (Bool)1;
          aa = argList;
        }
        if (unzFailsExist)
        {
          {
          }
        }
      }
      else
      {

        if (srcMode == 1)
        {
          {
          }
        }
        else
        {
          decode = (Bool)1;

          {
            while (1)
            {
            while_continue___7: /* CIL Label */;
              if (!((unsigned long)aa != (unsigned long)((void *)0)))
              {
                goto while_break___7;
              }
              {
                tmp___31 = strcmp((char const *)aa->name, "--");
              }
              if (tmp___31 == 0)
              {

                goto __Cont___2;
              }
              if ((int)*(aa->name + 0) == 45)
              {
                if (decode)
                {
                  goto __Cont___2;
                }
              }
              {
                testf(aa->name);
              }
            __Cont___2:
              aa = aa->link;
            }
          while_break___7: /* CIL Label */;
          }
        }
      }
    }
    aa = argList;
    return (exitValue);
  }
}
__inline static void fallbackSimpleSort(UInt32 *fmap, UInt32 *eclass, Int32 lo, Int32 hi)
{
  Int32 i;
  Int32 j;
  Int32 tmp;
  UInt32 ec_tmp;

  {
    if (lo == hi)
    {
      return;
    }
    if (hi - lo > 3)
    {
      i = hi - 4;
      {
        while (1)
        {
        while_continue: /* CIL Label */;
          if (!(i >= lo))
          {
            goto while_break;
          }
          tmp = (Int32) * (fmap + i);
          ec_tmp = *(eclass + tmp);
          j = i + 4;
          {

          while_break___0: /* CIL Label */;
          }
          *(fmap + (j - 4)) = (UInt32)tmp;
          i--;
        }
      while_break: /* CIL Label */;
      }
    }
    i = hi - 1;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i >= lo))
        {
          goto while_break___1;
        }
        tmp = (Int32) * (fmap + i);
        ec_tmp = *(eclass + tmp);
        j = i + 1;
        {
          while (1)
          {
          while_continue___2: /* CIL Label */;
            if (j <= hi)
            {
              if (!(ec_tmp > *(eclass + *(fmap + j))))
              {
                goto while_break___2;
              }
            }
            else
            {
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
    return;
  }
}
static void fallbackQSort3(UInt32 *fmap, UInt32 *eclass, Int32 loSt, Int32 hiSt)
{
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
    r = (UInt32)0;
    sp = 0;
    stackLo[sp] = loSt;
    stackHi[sp] = hiSt;
    sp++;
    {
      while (1)
      {
      while_continue: /* CIL Label */;
        if (!(sp > 0))
        {
          goto while_break;
        }

        sp--;
        lo = stackLo[sp];
        hi = stackHi[sp];
        if (hi - lo < 10)
        {
          {
            fallbackSimpleSort(fmap, eclass, lo, hi);
          }
          goto while_continue;
        }
        r = (r * 7621U + 1U) % 32768U;
        r3 = r % 3U;
        if (r3 == 0U)
        {
          med = *(eclass + *(fmap + lo));
        }
        else
        {
          if (r3 == 1U)
          {
            med = *(eclass + *(fmap + ((lo + hi) >> 1)));
          }
          else
          {
            med = *(eclass + *(fmap + hi));
          }
        }
        ltLo = lo;
        unLo = ltLo;
        gtHi = hi;
        unHi = gtHi;
        {
          while (1)
          {
          while_continue___0: /* CIL Label */;
            {
              while (1)
              {
              while_continue___1: /* CIL Label */;
                if (!(!(unLo > unHi)))
                {
                  goto while_break___1;
                }
                n = (Int32) * (eclass + *(fmap + unLo)) - (Int32)med;
                if (n == 0)
                {
                  zztmp = (Int32) * (fmap + unLo);
                  *(fmap + unLo) = *(fmap + ltLo);
                  *(fmap + ltLo) = (UInt32)zztmp;
                  ltLo++;
                  unLo++;
                  goto while_continue___1;
                }
                if (n > 0)
                {
                  goto while_break___1;
                }
                unLo++;
              }
            while_break___1: /* CIL Label */;
            }
            {
              while (1)
              {
              while_continue___2: /* CIL Label */;
                if (!(!(unLo > unHi)))
                {
                  goto while_break___2;
                }
                n = (Int32) * (eclass + *(fmap + unHi)) - (Int32)med;
                if (n == 0)
                {
                  zztmp___0 = (Int32) * (fmap + unHi);
                  *(fmap + unHi) = *(fmap + gtHi);
                  *(fmap + gtHi) = (UInt32)zztmp___0;
                  gtHi--;
                  unHi--;
                  goto while_continue___2;
                }
                if (n < 0)
                {
                  goto while_break___2;
                }
                unHi--;
              }
            while_break___2: /* CIL Label */;
            }
            if (unLo > unHi)
            {
              goto while_break___0;
            }
            zztmp___1 = (Int32) * (fmap + unLo);
            *(fmap + unLo) = *(fmap + unHi);
            *(fmap + unHi) = (UInt32)zztmp___1;
            unLo++;
            unHi--;
          }
        while_break___0: /* CIL Label */;
        }
        if (gtHi < ltLo)
        {
          goto while_continue;
        }
        if (ltLo - lo < unLo - ltLo)
        {
          n = ltLo - lo;
        }
        else
        {
          n = unLo - ltLo;
        }
        yyp1 = lo;
        yyp2 = unLo - n;
        yyn = n;
        {
          while (1)
          {
          while_continue___3: /* CIL Label */;
            if (!(yyn > 0))
            {
              goto while_break___3;
            }
            zztmp___2 = (Int32) * (fmap + yyp1);
            *(fmap + yyp1) = *(fmap + yyp2);
            *(fmap + yyp2) = (UInt32)zztmp___2;
            yyp1++;
            yyp2++;
            yyn--;
          }
        while_break___3: /* CIL Label */;
        }
        if (hi - gtHi < gtHi - unHi)
        {
          m = hi - gtHi;
        }
        else
        {
          m = gtHi - unHi;
        }
        yyp1___0 = unLo;
        yyp2___0 = (hi - m) + 1;
        yyn___0 = m;
        {
          while (1)
          {
          while_continue___4: /* CIL Label */;
            if (!(yyn___0 > 0))
            {
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
        if (n - lo > hi - m)
        {
          stackLo[sp] = lo;
          stackHi[sp] = n;
          sp++;
          stackLo[sp] = m;
          stackHi[sp] = hi;
          sp++;
        }
        else
        {
          stackLo[sp] = m;
          stackHi[sp] = hi;
          sp++;
          stackLo[sp] = lo;
          stackHi[sp] = n;
          sp++;
        }
      }
    while_break: /* CIL Label */;
    }
    return;
  }
}
static void fallbackSort(UInt32 *fmap, UInt32 *eclass, UInt32 *bhtab, Int32 nblock, Int32 verb)
{
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
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < 257))
        {
          goto while_break;
        }
        ftab[i] = 0;
        i++;
      }
    while_break: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < nblock))
        {
          goto while_break___0;
        }
        (ftab[*(eclass8 + i)])++;
        i++;
      }
    while_break___0: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < 256))
        {
          goto while_break___1;
        }
        ftabCopy[i] = ftab[i];
        i++;
      }
    while_break___1: /* CIL Label */;
    }
    i = 1;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < 257))
        {
          goto while_break___2;
        }
        ftab[i] += ftab[i - 1];
        i++;
      }
    while_break___2: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < nblock))
        {
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
    nBhtab = 2 + nblock / 32;
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < nBhtab))
        {
          goto while_break___4;
        }
        *(bhtab + i) = (UInt32)0;
        i++;
      }
    while_break___4: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < 256))
        {
          goto while_break___5;
        }
        *(bhtab + (ftab[i] >> 5)) |= (unsigned int)(1 << (ftab[i] & 31));
        i++;
      }
    while_break___5: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < 32))
        {
          goto while_break___6;
        }
        *(bhtab + ((nblock + 2 * i) >> 5)) |= (unsigned int)(1 << ((nblock + 2 * i) & 31));
        *(bhtab + (((nblock + 2 * i) + 1) >> 5)) &= (unsigned int)(~(1 << (((nblock + 2 * i) + 1) & 31)));
        i++;
      }
    while_break___6: /* CIL Label */;
    }
    H = 1;
    {
      while (1)
      {
      while_continue___7: /* CIL Label */;
        j = 0;
        i = 0;
        {
          while (1)
          {
          while_continue___8: /* CIL Label */;
            if (!(i < nblock))
            {
              goto while_break___8;
            }
            if (*(bhtab + (i >> 5)) & (unsigned int)(1 << (i & 31)))
            {
              j = i;
            }
            k = (Int32)(*(fmap + i) - (UInt32)H);
            if (k < 0)
            {
              k += nblock;
            }
            *(eclass + k) = (UInt32)j;
            i++;
          }
        while_break___8: /* CIL Label */;
        }
        nNotDone = 0;
        r = -1;
        {
          while (1)
          {
          while_continue___9: /* CIL Label */;
            k = r + 1;
            {

            while_break___10: /* CIL Label */;
            }
            if (*(bhtab + (k >> 5)) & (unsigned int)(1 << (k & 31)))
            {
              {
                while (1)
                {
                while_continue___12: /* CIL Label */;
                  if (!(*(bhtab + (k >> 5)) & (unsigned int)(1 << (k & 31))))
                  {
                    goto while_break___12;
                  }
                  k++;
                }
              while_break___12: /* CIL Label */;
              }
            }
            l = k - 1;
            if (l >= nblock)
            {
              goto while_break___9;
            }
            {
              while (1)
              {
                /* CIL Label */
                ;
                if (!(*(bhtab + (k >> 5)) & (unsigned int)(1 << (k & 31))))
                {
                  if (!(k & 31))
                  {
                    goto while_break___13;
                  }
                }
                else
                {
                  goto while_break___13;
                }
                k++;
              }
            while_break___13: /* CIL Label */;
            }
            if (!(*(bhtab + (k >> 5)) & (unsigned int)(1 << (k & 31))))
            {
              {
                while (1)
                {
                while_continue___15: /* CIL Label */;
                  if (!(!(*(bhtab + (k >> 5)) & (unsigned int)(1 << (k & 31)))))
                  {
                    goto while_break___15;
                  }
                  k++;
                }
              while_break___15: /* CIL Label */;
              }
            }
            r = k - 1;
            if (r > l)
            {
              {
                nNotDone += (r - l) + 1;
                fallbackQSort3(fmap, eclass, l, r);
                cc = -1;
                i = l;
              }
              {
                while (1)
                {
                while_continue___16: /* CIL Label */;
                  if (!(i <= r))
                  {
                    goto while_break___16;
                  }
                  cc1 = (Int32) * (eclass + *(fmap + i));
                  if (cc != cc1)
                  {
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
        if (H > nblock)
        {
          goto while_break___7;
        }
        else
        {
          if (nNotDone == 0)
          {
            goto while_break___7;
          }
        }
      }
    while_break___7: /* CIL Label */;
    }
    j = 0;
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < nblock))
        {
          goto while_break___17;
        }
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(ftabCopy[j] == 0))
            {
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
    if (!(j < 256))
    {
      {
        BZ2_bz__AssertH__fail(1005);
      }
    }
    return;
  }
}
__inline static Bool mainGtU(UInt32 i1, UInt32 i2, UChar *block, UInt16 *quadrant, UInt32 nblock, Int32 *budget)
{
  Int32 k;
  UChar c1;
  UChar c2;
  UInt16 s1;
  UInt16 s2;

  {
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;
    c1 = *(block + i1);
    c2 = *(block + i2);
    if ((int)c1 != (int)c2)
    {
      return ((Bool)((int)c1 > (int)c2));
    }
    i1++;
    i2++;

    {
      while (1)
      {
      while_continue: /* CIL Label */;
        c1 = *(block + i1);
        c2 = *(block + i2);

        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2)
        {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2)
        {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2)
        {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2)
        {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2)
        {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2)
        {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2)
        {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2)
        {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2)
        {
          return ((Bool)((int)c1 > (int)c2));
        }

        s2 = *(quadrant + i2);

        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2)
        {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);

        i1++;
        i2++;

        k -= 8;
        (*budget)--;
        if (!(k >= 0))
        {
          goto while_break;
        }
      }
    while_break: /* CIL Label */;
    }
  }
}
static Int32 incs[14] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161, 2391484};
static void mainSimpleSort(UInt32 *ptr, UChar *block, UInt16 *quadrant, Int32 nblock, Int32 lo, Int32 hi, Int32 d, Int32 *budget)
{
  Int32 i;
  Int32 j;
  Int32 h;
  Int32 bigN;
  Int32 hp;
  UInt32 v;
  Bool tmp;
  Bool tmp___0;
  Bool tmp___1;

  {
    bigN = (hi - lo) + 1;

    hp = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(incs[hp] < bigN))
        {
          goto while_break;
        }
        hp++;
      }
    while_break: /* CIL Label */;
    }
    hp--;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(hp >= 0))
        {
          goto while_break___0;
        }
        h = incs[hp];
        i = lo + h;
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(!(i > hi)))
            {
              goto while_break___1;
            }
            v = *(ptr + i);
            j = i;
            {
              while (1)
              {
              while_continue___2: /* CIL Label */;
                {
                  tmp = mainGtU(*(ptr + (j - h)) + (UInt32)d, v + (UInt32)d, block, quadrant, (UInt32)nblock, budget);
                }
                if (!tmp)
                {
                  goto while_break___2;
                }
                *(ptr + j) = *(ptr + (j - h));
                j -= h;
                if (j <= (lo + h) - 1)
                {
                  goto while_break___2;
                }
              }
            while_break___2: /* CIL Label */;
            }
            *(ptr + j) = v;
            i++;
            if (i > hi)
            {
              goto while_break___1;
            }
            v = *(ptr + i);
            j = i;
            {
              while (1)
              {
                /* CIL Label */
                ;
                {
                  tmp___0 = mainGtU(*(ptr + (j - h)) + (UInt32)d, v + (UInt32)d, block, quadrant, (UInt32)nblock, budget);
                }
                if (!tmp___0)
                {
                  goto while_break___3;
                }
                *(ptr + j) = *(ptr + (j - h));
                j -= h;
                if (j <= (lo + h) - 1)
                {
                  goto while_break___3;
                }
              }
            while_break___3: /* CIL Label */;
            }
            *(ptr + j) = v;
            i++;
            if (i > hi)
            {
              goto while_break___1;
            }

            j = i;
            {
              while (1)
              {
              while_continue___4: /* CIL Label */;
                {
                  tmp___1 = mainGtU(*(ptr + (j - h)) + (UInt32)d, v + (UInt32)d, block, quadrant, (UInt32)nblock, budget);
                }
                if (!tmp___1)
                {
                  goto while_break___4;
                }
                *(ptr + j) = *(ptr + (j - h));
                j -= h;
                if (j <= (lo + h) - 1)
                {
                  goto while_break___4;
                }
              }
            while_break___4: /* CIL Label */;
            }
            *(ptr + j) = v;
            i++;
            if (*budget < 0)
            {
              return;
            }
          }
        while_break___1: /* CIL Label */;
        }
        hp--;
      }
    while_break___0: /* CIL Label */;
    }
    return;
  }
}
__inline static UChar mmed3(UChar a, UChar b, UChar c)
{

  {
    return (b);
  }
}
static void mainQSort3(UInt32 *ptr, UChar *block, UInt16 *quadrant, Int32 nblock, Int32 loSt, Int32 hiSt, Int32 dSt, Int32 *budget)
{
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
      while (1)
      {
      while_continue: /* CIL Label */;
        if (!(sp > 0))
        {
          goto while_break;
        }

        sp--;
        lo = stackLo[sp];
        hi = stackHi[sp];
        d = stackD[sp];
        if (hi - lo < 20)
        {
          goto _L;
        }
        else
        {
          if (d > 14)
          {
          _L:
          {
            mainSimpleSort(ptr, block, quadrant, nblock, lo, hi, d, budget);
          }
            if (*budget < 0)
            {
              return;
            }
            goto while_continue;
          }
        }
        {
          med = (Int32)mmed3(*(block + (*(ptr + lo) + (UInt32)d)), *(block + (*(ptr + hi) + (UInt32)d)), *(block + (*(ptr + ((lo + hi) >> 1)) + (UInt32)d)));
          ltLo = lo;
          unLo = ltLo;
          gtHi = hi;
          unHi = gtHi;
        }
        {
          while (1)
          {
          while_continue___0: /* CIL Label */;
            {
              while (1)
              {
              while_continue___1: /* CIL Label */;
                if (!(!(unLo > unHi)))
                {
                  goto while_break___1;
                }
                n = (Int32) * (block + (*(ptr + unLo) + (UInt32)d)) - med;
                if (n == 0)
                {
                  zztmp = (Int32) * (ptr + unLo);
                  *(ptr + unLo) = *(ptr + ltLo);
                  *(ptr + ltLo) = (UInt32)zztmp;
                  ltLo++;
                  unLo++;
                  goto while_continue___1;
                }
                if (n > 0)
                {
                  goto while_break___1;
                }
                unLo++;
              }
            while_break___1: /* CIL Label */;
            }
            {
              while (1)
              {
              while_continue___2: /* CIL Label */;
                if (!(!(unLo > unHi)))
                {
                  goto while_break___2;
                }
                n = (Int32) * (block + (*(ptr + unHi) + (UInt32)d)) - med;
                if (n == 0)
                {

                  *(ptr + unHi) = *(ptr + gtHi);
                  *(ptr + gtHi) = (UInt32)zztmp___0;
                  gtHi--;
                  unHi--;
                  goto while_continue___2;
                }
                if (n < 0)
                {
                  goto while_break___2;
                }
                unHi--;
              }
            while_break___2: /* CIL Label */;
            }
            if (unLo > unHi)
            {
              goto while_break___0;
            }
            zztmp___1 = (Int32) * (ptr + unLo);
            *(ptr + unLo) = *(ptr + unHi);
            *(ptr + unHi) = (UInt32)zztmp___1;
            unLo++;
            unHi--;
          }
        while_break___0: /* CIL Label */;
        }
        if (gtHi < ltLo)
        {
          stackLo[sp] = lo;
          stackHi[sp] = hi;
          stackD[sp] = d + 1;
          sp++;
        }
        if (ltLo - lo < unLo - ltLo)
        {
          n = ltLo - lo;
        }
        else
        {
          n = unLo - ltLo;
        }
        yyp1 = lo;
        yyp2 = unLo - n;
        yyn = n;
        {
          while (1)
          {
          while_continue___3: /* CIL Label */;
            if (!(yyn > 0))
            {
              goto while_break___3;
            }

            *(ptr + yyp1) = *(ptr + yyp2);
            *(ptr + yyp2) = (UInt32)zztmp___2;
            yyp1++;

            yyn--;
          }
        while_break___3: /* CIL Label */;
        }
        if (hi - gtHi < gtHi - unHi)
        {
          m = hi - gtHi;
        }
        else
        {
          m = gtHi - unHi;
        }
        yyp1___0 = unLo;
        yyp2___0 = (hi - m) + 1;
        yyn___0 = m;
        {
          while (1)
          {
          while_continue___4: /* CIL Label */;
            if (!(yyn___0 > 0))
            {
              goto while_break___4;
            }
            zztmp___3 = (Int32) * (ptr + yyp1___0);
            *(ptr + yyp1___0) = *(ptr + yyp2___0);
            *(ptr + yyp2___0) = (UInt32)zztmp___3;
            yyp1___0++;
            yyp2___0++;
            yyn___0--;
          }
        while_break___4: /* CIL Label */;
        }
        n = ((lo + unLo) - ltLo) - 1;
        m = (hi - (gtHi - unHi)) + 1;
        nextLo[0] = lo;
        nextHi[0] = n;
        nextD[0] = d;
        nextLo[1] = m;
        nextHi[1] = hi;
        nextD[1] = d;
        nextLo[2] = n + 1;
        nextHi[2] = m - 1;
        nextD[2] = d + 1;

        stackLo[sp] = nextLo[0];
        stackHi[sp] = nextHi[0];

        sp++;
        stackLo[sp] = nextLo[1];

        stackD[sp] = nextD[1];
        sp++;
        stackLo[sp] = nextLo[2];
        stackHi[sp] = nextHi[2];
        stackD[sp] = nextD[2];
        sp++;
      }
    while_break: /* CIL Label */;
    }
    return;
  }
}
static void mainSort(UInt32 *ptr, UChar *block, UInt16 *quadrant, UInt32 *ftab, Int32 nblock, Int32 verb, Int32 *budget)
{
  Int32 i;
  Int32 j;
  Int32 k;
  Int32 ss;
  Int32 sb;
  Int32 runningOrder[256];
  Bool bigDone[256];
  Int32 copyStart[256];
  Int32 copyEnd[256];
  UChar c1;
  Int32 numQSorted;
  UInt16 s;
  Int32 vv;
  Int32 h;
  Int32 lo;
  Int32 hi;

  Int32 tmp___0;
  Int32 bbStart;
  Int32 bbSize;
  Int32 shifts;
  Int32 a2update;
  UInt16 qVal;

  {
    i = 65536; // whyyyyyyyyyyyyyyyyyyyy
    {
      while (1)
      {
      while_continue: /* CIL Label */;
        if (!(i >= 0))
        {
          goto while_break;
        }
        *(ftab + i) = (UInt32)0;
        i--;
      }
    while_break: /* CIL Label */;
    }
    j = (int)*(block + 0) << 8;
    i = nblock - 1;
    {
      while (1)
      {
      while_continue___0: /* CIL Label */;
        if (!(i >= 3))
        {
          goto while_break___0;
        }
        *(quadrant + i) = (UInt16)0;
        j = (j >> 8) | ((int)((UInt16) * (block + i)) << 8);
        (*(ftab + j))++;

        j = (j >> 8) | ((int)((UInt16) * (block + (i - 1))) << 8);
        (*(ftab + j))++;

        j = (j >> 8) | ((int)((UInt16) * (block + (i - 2))) << 8);
        (*(ftab + j))++;
        *(quadrant + (i - 3)) = (UInt16)0;
        j = (j >> 8) | ((int)((UInt16) * (block + (i - 3))) << 8);
        (*(ftab + j))++;
        i -= 4;
      }
    while_break___0: /* CIL Label */;
    }
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i >= 0))
        {
          goto while_break___1;
        }
        *(quadrant + i) = (UInt16)0;
        j = (j >> 8) | ((int)((UInt16) * (block + i)) << 8);
        (*(ftab + j))++;
        i--;
      }
    while_break___1: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < 34))
        {
          goto while_break___2;
        }

        i++;
      }
    while_break___2: /* CIL Label */;
    }
    i = 1;
    {
      while (1)
      {
      while_continue___3: /* CIL Label */;
        if (!(i <= 65536))
        {
          goto while_break___3;
        }
        *(ftab + i) += *(ftab + (i - 1));
        i++;
      }
    while_break___3: /* CIL Label */;
    }
    s = (UInt16)((int)*(block + 0) << 8);
    i = nblock - 1;
    {
      while (1)
      {
      while_continue___4: /* CIL Label */;
        if (!(i >= 3))
        {
          goto while_break___4;
        }
        s = (UInt16)(((int)s >> 8) | ((int)*(block + i) << 8));
        j = (Int32)(*(ftab + (int)s) - 1U);
        *(ftab + (int)s) = (UInt32)j;
        *(ptr + j) = (UInt32)i;
        s = (UInt16)(((int)s >> 8) | ((int)*(block + (i - 1)) << 8));
        j = (Int32)(*(ftab + (int)s) - 1U);
        *(ftab + (int)s) = (UInt32)j;
        *(ptr + j) = (UInt32)(i - 1);
        s = (UInt16)(((int)s >> 8) | ((int)*(block + (i - 2)) << 8));
        j = (Int32)(*(ftab + (int)s) - 1U);
        *(ftab + (int)s) = (UInt32)j;
        *(ptr + j) = (UInt32)(i - 2);
        s = (UInt16)(((int)s >> 8) | ((int)*(block + (i - 3)) << 8));
        j = (Int32)(*(ftab + (int)s) - 1U);
        *(ftab + (int)s) = (UInt32)j;
        *(ptr + j) = (UInt32)(i - 3);
        i -= 4;
      }
    while_break___4: /* CIL Label */;
    }
    {
      while (1)
      {
      while_continue___5: /* CIL Label */;
        if (!(i >= 0))
        {
          goto while_break___5;
        }
        s = (UInt16)(((int)s >> 8) | ((int)*(block + i) << 8));
        j = (Int32)(*(ftab + (int)s) - 1U);
        *(ftab + (int)s) = (UInt32)j;
        *(ptr + j) = (UInt32)i;
        i--;
      }
    while_break___5: /* CIL Label */;
    }
    i = 0;
    {
      while (1)
      {
      while_continue___6: /* CIL Label */;
        if (!(i <= 255))
        {
          goto while_break___6;
        }
        bigDone[i] = (Bool)0;
        runningOrder[i] = i;
        i++;
      }
    while_break___6: /* CIL Label */;
    }
    h = 1;
    {
      while (1)
      {
      while_continue___7: /* CIL Label */;
        h = 3 * h + 1;
        if (!(h <= 256))
        {
          goto while_break___7;
        }
      }
    while_break___7: /* CIL Label */;
    }
    {
      while (1)
      {
        /* CIL Label */
        ;
        h /= 3;
        i = h;
        {
          while (1)
          {
            /* CIL Label */
            ;
            if (!(i <= 255))
            {
              goto while_break___9;
            }
            vv = runningOrder[i];
            j = i;
            {
              while (1)
              {
              while_continue___10: /* CIL Label */;
                if (!(*(ftab + ((runningOrder[j - h] + 1) << 8)) - *(ftab + (runningOrder[j - h] << 8)) > *(ftab + ((vv + 1) << 8)) - *(ftab + (vv << 8))))
                {
                  goto while_break___10;
                }
                runningOrder[j] = runningOrder[j - h];
                j -= h;
                if (j <= h - 1)
                {
                  goto zero;
                }
              }
            while_break___10: /* CIL Label */;
            }
          zero:
            runningOrder[j] = vv;
            i++;
          }
        while_break___9: /* CIL Label */;
        }
        if (!(h != 1))
        {
          goto while_break___8;
        }
      }
    while_break___8: /* CIL Label */;
    }
    numQSorted = 0;
    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i <= 255))
        {
          goto while_break___11;
        }
        ss = runningOrder[i];
        j = 0;
        {
          while (1)
          {
          while_continue___12: /* CIL Label */;
            if (!(j <= 255))
            {
              goto while_break___12;
            }
            if (j != ss)
            {
              sb = (ss << 8) + j;
              if (!(*(ftab + sb) & (unsigned int)(1 << 21)))
              {
                lo = (Int32)(*(ftab + sb) & (unsigned int)(~(1 << 21)));
                hi = (Int32)((*(ftab + (sb + 1)) & (unsigned int)(~(1 << 21))) - 1U);
                if (hi > lo)
                {

                  {
                    mainQSort3(ptr, block, quadrant, nblock, lo, hi, 2, budget);
                  }
                  if (*budget < 0)
                  {
                    return;
                  }
                }
              }
            }
            j++;
          }
        while_break___12: /* CIL Label */;
        }
        j = 0;
        {
          while (1)
          {
          while_continue___13: /* CIL Label */;
            if (!(j <= 255))
            {
              goto while_break___13;
            }
            copyStart[j] = (Int32)(*(ftab + ((j << 8) + ss)) & (unsigned int)(~(1 << 21)));
            copyEnd[j] = (Int32)((*(ftab + (((j << 8) + ss) + 1)) & (unsigned int)(~(1 << 21))) - 1U);
            j++;
          }
        while_break___13: /* CIL Label */;
        }
        j = (Int32)(*(ftab + (ss << 8)) & (unsigned int)(~(1 << 21)));
        j = (Int32)((*(ftab + ((ss + 1) << 8)) & (unsigned int)(~(1 << 21))) - 1U);
        {
          while (1)
          {
          while_continue___15: /* CIL Label */;
            if (!(j > copyEnd[ss]))
            {
              goto while_break___15;
            }
            k = (Int32)(*(ptr + j) - 1U);

            if (k < 0)
            {
              k += nblock;
            }
            c1 = *(block + k);
            if (!bigDone[c1])
            {
              tmp___0 = copyEnd[c1];
              (copyEnd[c1])--;
              *(ptr + tmp___0) = (UInt32)k;
            }
            j--;
          }
        while_break___15: /* CIL Label */;
        }
        j = 0;
        bigDone[ss] = (Bool)1;
        if (i < 255)
        {
          bbStart = (Int32)(*(ftab + (ss << 8)) & (unsigned int)(~(1 << 21)));
          bbSize = (Int32)((*(ftab + ((ss + 1) << 8)) & (unsigned int)(~(1 << 21))) - (unsigned int)bbStart);
          shifts = 0;
          j = bbSize - 1;
          {
            while (1)
            {
            while_continue___18: /* CIL Label */;
              if (!(j >= 0))
              {
                goto while_break___18;
              }
              a2update = (Int32) * (ptr + (bbStart + j));
              qVal = (UInt16)(j >> shifts);
              *(quadrant + a2update) = qVal;

              j--;
            }
          while_break___18: /* CIL Label */;
          }
          if (!((bbSize - 1) >> shifts <= 65535))
          {
            {
            }
          }
        }
        i++;
      }
    while_break___11: /* CIL Label */
        ;
    }
    return;
  }
}
void BZ2_blockSort(EState *s)
{
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

  {
    ptr = s->ptr;
    block = s->block;
    ftab = s->ftab;
    nblock = s->nblock;

    if (nblock < 10000)
    {
      {
        fallbackSort(s->arr1, s->arr2, ftab, nblock, verb);
      }
    }
    else
    {
      i = nblock + 34;
      if (i & 1)
      {
        i++;
      }
      quadrant = (UInt16 *)(block + i);
      if (wfact < 1)
      {
        wfact = 1;
      }
      if (wfact > 100)
      {
        wfact = 100;
      }
      {
        budgetInit = nblock * ((wfact - 1) / 3);
        budget = budgetInit;
        mainSort(ptr, block, quadrant, ftab, nblock, verb, &budget);
      }

      if (budget < 0)
      {

        {
          fallbackSort(s->arr1, s->arr2, ftab, nblock, verb);
        }
      }
    }

    i = 0;
    {
      while (1)
      {
        /* CIL Label */
        ;
        if (!(i < s->nblock))
        {
          goto while_break;
        }
        if (*(ptr + i) == 0U)
        {
          s->origPtr = i;
          goto while_break;
        }
        i++;
      }
    while_break: /* CIL Label */;
    }
    if (!(s->origPtr != -1))
    {
      {
        BZ2_bz__AssertH__fail(1003);
      }
    }
    return;
  }
}
