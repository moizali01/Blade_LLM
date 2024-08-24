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
Int32 BZ2_rNums[512];
Int32 BZ2_rNums[512] = {
    619, 720, 127, 481, 931, 816, 813, 233, 566, 247, 985, 724, 205, 454, 863,
    491, 741, 242, 949, 214, 733, 859, 335, 708, 621, 574, 73,  654, 730, 472,
    419, 436, 278, 496, 867, 210, 399, 680, 480, 51,  878, 465, 811, 169, 869,
    675, 611, 697, 867, 561, 862, 687, 507, 283, 482, 129, 807, 591, 733, 623,
    150, 238, 59,  379, 684, 877, 625, 169, 643, 105, 170, 607, 520, 932, 727,
    476, 693, 425, 174, 647, 73,  122, 335, 530, 442, 853, 695, 249, 445, 515,
    909, 545, 703, 919, 874, 474, 882, 500, 594, 612, 641, 801, 220, 162, 819,
    984, 589, 513, 495, 799, 161, 604, 958, 533, 221, 400, 386, 867, 600, 782,
    382, 596, 414, 171, 516, 375, 682, 485, 911, 276, 98,  553, 163, 354, 666,
    933, 424, 341, 533, 870, 227, 730, 475, 186, 263, 647, 537, 686, 600, 224,
    469, 68,  770, 919, 190, 373, 294, 822, 808, 206, 184, 943, 795, 384, 383,
    461, 404, 758, 839, 887, 715, 67,  618, 276, 204, 918, 873, 777, 604, 560,
    951, 160, 578, 722, 79,  804, 96,  409, 713, 940, 652, 934, 970, 447, 318,
    353, 859, 672, 112, 785, 645, 863, 803, 350, 139, 93,  354, 99,  820, 908,
    609, 772, 154, 274, 580, 184, 79,  626, 630, 742, 653, 282, 762, 623, 680,
    81,  927, 626, 789, 125, 411, 521, 938, 300, 821, 78,  343, 175, 128, 250,
    170, 774, 972, 275, 999, 639, 495, 78,  352, 126, 857, 956, 358, 619, 580,
    124, 737, 594, 701, 612, 669, 112, 134, 694, 363, 992, 809, 743, 168, 974,
    944, 375, 748, 52,  600, 747, 642, 182, 862, 81,  344, 805, 988, 739, 511,
    655, 814, 334, 249, 515, 897, 955, 664, 981, 649, 113, 974, 459, 893, 228,
    433, 837, 553, 268, 926, 240, 102, 654, 459, 51,  686, 754, 806, 760, 493,
    403, 415, 394, 687, 700, 946, 670, 656, 610, 738, 392, 760, 799, 887, 653,
    978, 321, 576, 617, 626, 502, 894, 679, 243, 440, 680, 879, 194, 572, 640,
    724, 926, 56,  204, 700, 707, 151, 457, 449, 797, 195, 791, 558, 945, 679,
    297, 59,  87,  824, 713, 663, 412, 693, 342, 606, 134, 108, 571, 364, 631,
    212, 174, 643, 304, 329, 343, 97,  430, 751, 497, 314, 983, 374, 822, 928,
    140, 206, 73,  263, 980, 736, 876, 478, 430, 305, 170, 514, 364, 692, 829,
    82,  855, 953, 676, 246, 369, 970, 294, 750, 807, 827, 150, 790, 288, 923,
    804, 378, 215, 828, 592, 281, 565, 555, 710, 82,  896, 831, 547, 261, 524,
    462, 293, 465, 502, 56,  661, 821, 976, 991, 658, 869, 905, 758, 745, 193,
    768, 550, 608, 933, 378, 286, 215, 979, 792, 961, 61,  688, 793, 644, 986,
    403, 106, 366, 905, 644, 372, 567, 466, 434, 645, 210, 389, 550, 919, 135,
    780, 773, 635, 389, 707, 100, 626, 958, 165, 504, 920, 176, 193, 713, 857,
    265, 203, 50,  668, 108, 645, 990, 626, 197, 510, 357, 358, 850, 858, 364,
    936, 638};
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
  void *__cil_tmp29;
  void *__cil_tmp30;
  void *__cil_tmp31;

  {
    i = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
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
      while_continue___0: /* CIL Label */
          ;
        nNodes = alphaSize;
        nHeap = 0;

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
                /* CIL Label */
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
            /* CIL Label */
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

                if (weight[heap[yy + 1]] < weight[heap[yy]]) {
                  yy++;
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

        i = 1;
        {
          while (1) {
            /* CIL Label */
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

        {

        while_break___9: /* CIL Label */
            ;
        }
      }
    while_break___0: /* CIL Label */
        ;
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
            /* CIL Label */
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
        /* CIL Label */
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

    i = 0;
    {
      while (1) {
        /* CIL Label */
        ;
        if (!(i < 256)) {
          goto while_break;
        }

        s->unseqToSeq[i] = (UChar)s->nInUse;
        (s->nInUse)++;

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
        /* CIL Label */
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

    {

      /* CIL Label */
      ;

      *(mtfv + wr) = (UInt16)0;
      wr++;

      goto while_break___4;

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

  Int32 curr;
  UInt16 mtfv_i;
  UChar *s_len_sel_selCtr;
  Int32 *s_code_sel_selCtr;

  {
    mtfv = s->mtfv;

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

    nGroups = 6;

    nPart = nGroups;
    remF = s->nMTF;
    gs = 0;
    {
      while (1) {
        /* CIL Label */
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

            } else {
              goto while_break___2;
            }
            ge++;
            aFreq += s->mtfFreq[ge];
          }
        while_break___2: /* CIL Label */
            ;
        }

        if ((nGroups - nPart) % 2 == 1) {
          aFreq -= s->mtfFreq[ge];
          ge--;
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
        /* CIL Label */
        ;
        if (!(iter < 4)) {
          goto while_break___4;
        }

        {

        while_break___5: /* CIL Label */
            ;
        }
        t = 0;
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
                /* CIL Label */
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
                    /* CIL Label */
                    ;
                    if (!(t < nGroups)) {
                      goto while_break___12;
                    }
                    cost[t] = (UInt16)((int)cost[t] + (int)s->len[t][icv___0]);
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

            bc = 999999999;

            t = 0;
            {
              while (1) {
                /* CIL Label */
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
                  /* CIL Label */
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
            /* CIL Label */
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

        i = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(i < alphaSize)) {
              goto while_break___21;
            }

            maxLen = (Int32)s->len[t][i];

            if ((int)s->len[t][i] < minLen) {
              minLen = (Int32)s->len[t][i];
            }
            i++;
          }
        while_break___21: /* CIL Label */
            ;
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

    {

      /* CIL Label */
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

        { bsW(s, 1, (UInt32)1); }

        {}

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

        j = 0;
        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j < 16)) {
              goto while_break___26;
            }

            { bsW(s, 1, (UInt32)1); }

            {}

            j++;
          }
        while_break___26: /* CIL Label */
            ;
        }

        i++;
      }
    while_break___25: /* CIL Label */
        ;
    }

    {

      bsW(s, 3, (UInt32)nGroups);
      bsW(s, 15, (UInt32)nSelectors);
      i = 0;
    }
    {
      while (1) {
        /* CIL Label */
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
            /* CIL Label */
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
    if (s->nblock > 0) {
      s->blockCRC = ~s->blockCRC;

      s->combinedCRC ^= s->blockCRC;

      { BZ2_blockSort(s); }
    }
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

extern __attribute__((__nothrow__))
FILE *(__attribute__((__leaf__)) fdopen)(int __fd, char const *__modes);

void BZ2_bz__AssertH__fail(int errcode) {

  {
    {}

    {}
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

static void prepare_new_block(EState *s) {

  {

    s->blockCRC = (UInt32)4294967295L;

    {

      /* CIL Label */
      ;
    }
  }
}
static void init_RL(EState *s) {

  { s->state_in_ch = (UInt32)256; }
}

int BZ2_bzCompressInit(bz_stream *strm, int blockSize100k___0,
                       int verbosity___0, int workFactor___0) {
  Int32 n;
  EState *s;

  {
    {}

    strm->bzalloc = &default_bzalloc;

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

      s->mode = 2;

      s->blockSize100k = blockSize100k___0;

      s->block = (UChar *)s->arr2;
      s->mtfv = (UInt16 *)s->arr1;

      s->ptr = s->arr1;
      strm->state = (void *)s;

      init_RL(s);
      prepare_new_block(s);
    }
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

      if (s->state_in_len == 2) {
        goto case_2;
      }
      if (s->state_in_len == 3) {
        goto case_3;
      }
      goto switch_default;
      /* CIL Label */

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

    switch_break: /* CIL Label */
        ;
    }
  }
}
static void flush_RL(EState *s) {

  {
    if (s->state_in_ch < 256U) {
      {
        add_pair_to_block(s);
      }
    }
    {}
  }
}
static Bool copy_input_until_stop(EState *s) {

  UInt32 zchh;
  UChar ch;

  {

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
      }
    while_break: /* CIL Label */
        ;
    }

    {

      /* CIL Label */
      ;
    }
  }
}
static Bool copy_output_until_stop(EState *s) {
  Bool progress_out;

  {
    progress_out = (Bool)0;
    {

      /* CIL Label */
      ;

      if (s->state_out_pos >= s->numZ) {
        goto while_break;
      }
      progress_out = (Bool)1;
      *((s->strm)->next_out) = (char)*(s->zbits + s->state_out_pos);
      (s->state_out_pos)++;
      ((s->strm)->avail_out)--;

    while_break: /* CIL Label */
        ;
    }
    return (progress_out);
  }
}
static Bool handle_compress(bz_stream *strm) {

  Bool progress_out;
  EState *s;
  Bool tmp;

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

          {}

          goto while_break;

          {}
        }

        { tmp___2 = copy_input_until_stop(s); }
        if (s->mode != 2) {

          {
            flush_RL(s);
            BZ2_compressBlock(s, (Bool)(s->mode == 4));
            s->state = 1;
          }

        } else {
        _L:

        {}

          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }

    if (progress_out) {

    } else {
      tmp___3 = 0;
    }

    return ((Bool)tmp___3);
  }
}
int BZ2_bzCompress(bz_stream *strm, int action) {
  Bool progress;
  EState *s;
  int tmp;

  {

    s = (EState *)strm->state;

  preswitch: {

    if (s->mode == 2) {
      goto case_2;
    }

    goto case_4;

    /* CIL Label */

  case_2: /* CIL Label */
    if (action == 0) {
      {
        progress = handle_compress(strm);
      }

      return (tmp);
    } else {

      s->mode = 4;
      goto preswitch;
    }
  case_3: /* CIL Label */

  {}

    s->mode = 2;
    return (1);
  case_4: /* CIL Label */

  {
    progress = handle_compress(strm);
  }
    if (!progress) {
      return (-1);
    }

    {}

    s->mode = 1;
    return (4);
  switch_break: /* CIL Label */
      ;
  }
    return (0);
  }
}

Int32 BZ2_indexIntoF(Int32 indx, Int32 *cftab) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}

BZFILE *BZ2_bzWriteOpen(int *bzerror, FILE *f, int blockSize100k___0,
                        int verbosity___0, int workFactor___0) {
  Int32 ret;
  bzFile *bzf;

  {

    {}

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

  Int32 ret;
  bzFile *bzf;

  {
    bzf = (bzFile *)b;

    {}

    bzf->strm.avail_in = (unsigned int)len;
    bzf->strm.next_in = (char *)buf;
    {

      /* CIL Label */
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

  {
    bzf = (bzFile *)b;

    {}

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
      /* CIL Label */
      ;
    }

    {}
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

Int32 verbosity;

Int32 blockSize100k;

Int32 opMode;

Char inName[1034];
Char outName[1034];

Char *progName;
Char progNameReally[1034];

Int32 workFactor;

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

  Bool tmp___1;

  {
    {}

    {}

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

        { BZ2_bzWrite(&bzerr, bzf, (void *)(ibuf), nIbuf); }
      }
    while_break: /* CIL Label */
        ;
    }
    {
      BZ2_bzWriteClose64(&bzerr, bzf, 0, &nbytes_in_lo32, &nbytes_in_hi32,
                         &nbytes_out_lo32, &nbytes_out_hi32);
    }

    {}

    {}

    {}

    {}

    return;
  errhandler: {
    BZ2_bzWriteClose64(&bzerr_dummy, bzf, 1, &nbytes_in_lo32, &nbytes_in_hi32,
                       &nbytes_out_lo32, &nbytes_out_hi32);
  }
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
    {}
  }
}

static void panic(Char const *s) {

  {
    {}
  }
}

static void ioError(void) {

  {
    {}
  }
}

static void outOfMemory(void) {

  {
    {}
  }
}

static void configError(void) {

  {
    {}
  }
}

static void copyFileName(Char *to, Char *from) {

  {
    {}

    {
      strncpy((char * /* __restrict  */)to,
              (char const * /* __restrict  */)from, (size_t)1024);
    }
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

  IntNative tmp___17;

  {

    {

      { /* CIL Label */
      }

      { /* CIL Label */
        copyFileName(inName, name);
        copyFileName(outName, name);
        strcat((char * /* __restrict  */)(outName),
               (char const * /* __restrict  */) ".bz2");
      }

      {
          /* CIL Label */

      }

      /* CIL Label */
      ;
    }

    {

      /* CIL Label */
      ;
    }

    {

      { /* CIL Label */
      }

      { /* CIL Label */
      }

      { /* CIL Label */
        inStr = fopen((char const * /* __restrict  */)(inName),
                      (char const * /* __restrict  */) "rb");
        outStr = fopen_output_safely(outName, "wb");
      }

      {
          /* CIL Label */

      }

      /* CIL Label */
      ;
    }

    { compressStream(inStr, outStr); }

    {}

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

  {

    {
      tmp___0 = mkCell();
      tmp = tmp___0;

      tmp->name = (Char *)myMalloc((Int32)(5UL + tmp___1));
      strcpy((char * /* __restrict  */)tmp->name,
             (char const * /* __restrict  */)name);
    }
    return (tmp);

    {

      /* CIL Label */
      ;
    }
    {}
  }
}

IntNative main(IntNative argc, Char **argv) {
  Int32 i;

  Cell *argList;
  Cell *aa;

  char *tmp___3;

  {

    {

      blockSize100k = 9;

      progName = &progNameReally[0];
    }
    {

      /* CIL Label */
      ;
    }
    { i = 1; }
    {

      /* CIL Label */
      ;
      if (!(i <= argc - 1)) {
      }
      { argList = snocString(argList, *(argv + i)); }

    while_break___0: /* CIL Label */
        ;
    }

    {

      /* CIL Label */
      ;
    }

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

    {

      /* CIL Label */
      ;
      if (!((unsigned long)aa != (unsigned long)((void *)0))) {
      }
      {}

      { compress(aa->name); }

    while_break___5: /* CIL Label */
        ;
    }

    {

      /* CIL Label */
      ;
    }
  }
}

__inline static Bool mainGtU(UInt32 i1, UInt32 i2, UChar *block,
                             UInt16 *quadrant, UInt32 nblock, Int32 *budget) {

  UChar c1;
  UChar c2;

  {

    i1++;
    i2++;

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
      /* CIL Label */
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

            {

              /* CIL Label */
              ;
            }

            {

              /* CIL Label */
              ;
            }
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

static void mainQSort3(UInt32 *ptr, UChar *block, UInt16 *quadrant,
                       Int32 nblock, Int32 loSt, Int32 hiSt, Int32 dSt,
                       Int32 *budget) {
  Int32 unLo;
  Int32 unHi;

  Int32 n;
  Int32 m;

  Int32 sp;
  Int32 lo;
  Int32 hi;
  Int32 d;
  Int32 stackLo[100];
  Int32 stackHi[100];

  Int32 yyp1;
  Int32 yyp2;
  Int32 yyn;

  Int32 yyp1___0;
  Int32 yyp2___0;
  Int32 yyn___0;

  {

    stackLo[sp] = loSt;
    stackHi[sp] = hiSt;

    sp++;
    {

    while_continue: /* CIL Label */
        ;
      if (!(sp > 0)) {
        goto while_break;
      }

      sp--;
      lo = stackLo[sp];
      hi = stackHi[sp];

    _L: { mainSimpleSort(ptr, block, quadrant, nblock, lo, hi, d, budget); }

      goto while_continue;

      {}
      {
        while (1) {
          /* CIL Label */
          ;
          {

            /* CIL Label */
            ;
            if (!(!(unLo > unHi))) {
            }

            if (n > 0) {
            }

          while_break___1: /* CIL Label */
              ;
          }
          {

            /* CIL Label */
            ;
            if (!(!(unLo > unHi))) {
            }

            if (n < 0) {
            }

          while_break___2: /* CIL Label */
              ;
          }
          if (unLo > unHi) {
          }
        }
      while_break___0: /* CIL Label */
          ;
      }

      yyp1 = lo;
      yyp2 = unLo - n;
      yyn = n;
      {
        while (1) {
          /* CIL Label */
          ;
          if (!(yyn > 0)) {
          }
        }
      while_break___3: /* CIL Label */
          ;
      }

      yyp1___0 = unLo;
      yyp2___0 = (hi - m) + 1;
      yyn___0 = m;
      {
        while (1) {
          /* CIL Label */
          ;
          if (!(yyn___0 > 0)) {
          }
        }
      while_break___4: /* CIL Label */
          ;
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

  Int32 h;
  Int32 lo;
  Int32 hi;
  Int32 tmp;
  Int32 tmp___0;

  {

    {

      /* CIL Label */
      ;
    }
    j = (int)*(block + 0) << 8;
    i = nblock - 1;
    {

      /* CIL Label */
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
      while (1) {
        /* CIL Label */
        ;
        if (!(i >= 3)) {
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
    while_break___4: /* CIL Label */
        ;
    }
    {

      /* CIL Label */
      ;
      if (!(i >= 0)) {
      }
      s = (UInt16)(((int)s >> 8) | ((int)*(block + i) << 8));
      j = (Int32)(*(ftab + (int)s) - 1U);
      *(ftab + (int)s) = (UInt32)j;

      i--;

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

    {

      /* CIL Label */
      ;
    }
    {

      /* CIL Label */
      ;

      i = h;
      {

        /* CIL Label */
        ;
        if (!(i <= 255)) {
        }

        j = i;
        {

          /* CIL Label */
          ;

          /* CIL Label */
          ;
        }
      zero:

      while_break___9: /* CIL Label */
          ;
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

        {
          while (1) {
            /* CIL Label */
            ;
            if (!(j <= 255)) {
              goto while_break___12;
            }

            sb = (ss << 8) + j;

            lo = (Int32)(*(ftab + sb) & (unsigned int)(~(1 << 21)));
            hi =
                (Int32)((*(ftab + (sb + 1)) & (unsigned int)(~(1 << 21))) - 1U);

            { mainQSort3(ptr, block, quadrant, nblock, lo, hi, 2, budget); }

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

          /* CIL Label */
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
