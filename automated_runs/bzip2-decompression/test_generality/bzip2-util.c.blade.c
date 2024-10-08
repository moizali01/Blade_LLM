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

void BZ2_hbCreateDecodeTables(Int32 *limit, Int32 *base, Int32 *perm,
                              UChar *length, Int32 minLen, Int32 maxLen,
                              Int32 alphaSize) {
  Int32 pp;
  Int32 i;
  Int32 j;
  Int32 vec;

  {
    pp = 0;
    i = minLen;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(i <= maxLen)) {
          goto while_break;
        }
        j = 0;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            if (!(j < alphaSize)) {
              goto while_break___0;
            }
            if ((int)*(length + j) == i) {
              *(perm + pp) = j;
              pp++;
            }
            j++;
          }
        while_break___0: /* CIL Label */
            ;
        }
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!(i < 23)) {
          goto while_break___1;
        }
        *(base + i) = 0;
        i++;
      }
    while_break___1: /* CIL Label */
        ;
    }
    i = 0;
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
      while (1) {
      while_continue___3: /* CIL Label */
          ;
        if (!(i < 23)) {
          goto while_break___3;
        }
        *(base + i) += *(base + (i - 1));
        i++;
      }
    while_break___3: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
      while_continue___4: /* CIL Label */
          ;
        if (!(i < 23)) {
          goto while_break___4;
        }
        *(limit + i) = 0;
        i++;
      }
    while_break___4: /* CIL Label */
        ;
    }
    vec = 0;
    i = minLen;
    {
      while (1) {
      while_continue___5: /* CIL Label */
          ;
        if (!(i <= maxLen)) {
          goto while_break___5;
        }
        vec += *(base + (i + 1)) - *(base + i);
        *(limit + i) = vec - 1;
        vec <<= 1;
        i++;
      }
    while_break___5: /* CIL Label */
        ;
    }
    i = minLen + 1;
    {
      while (1) {
      while_continue___6: /* CIL Label */
          ;
        if (!(i <= maxLen)) {
          goto while_break___6;
        }
        *(base + i) = ((*(limit + (i - 1)) + 1) << 1) - *(base + i);
        i++;
      }
    while_break___6: /* CIL Label */
        ;
    }
    return;
  }
}
extern struct _IO_FILE *stderr;
extern int fprintf(FILE *__restrict __stream, char const *__restrict __format,
                   ...);
Int32 BZ2_indexIntoF(Int32 indx, Int32 *cftab);
Int32 BZ2_decompress(DState *s);
static void makeMaps_d(DState *s) {
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
          s->seqToUnseq[s->nInUse] = (UChar)i;
          (s->nInUse)++;
        }
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
    return;
  }
}
Int32 BZ2_decompress(DState *s) {
  UChar uc;
  Int32 retVal;
  Int32 minLen;
  Int32 maxLen;
  bz_stream *strm;
  Int32 i;
  Int32 j;
  Int32 t;
  Int32 alphaSize;
  Int32 nGroups;
  Int32 nSelectors;
  Int32 EOB;
  Int32 groupNo;
  Int32 groupPos;
  Int32 nextSym;
  Int32 nblockMAX;
  Int32 nblock;
  Int32 es;
  Int32 N;
  Int32 curr;
  Int32 zt;
  Int32 zn;
  Int32 zvec;
  Int32 zj;
  Int32 gSel;
  Int32 gMinlen;
  Int32 *gLimit;
  Int32 *gBase;
  Int32 *gPerm;
  UInt32 v;
  UInt32 v___0;
  UInt32 v___1;
  UInt32 v___2;
  UInt32 v___3;
  UInt32 v___4;
  UInt32 v___5;
  UInt32 v___6;
  UInt32 v___7;
  UInt32 v___8;
  UInt32 v___9;
  UInt32 v___10;
  UInt32 v___11;
  UInt32 v___12;
  UInt32 v___13;
  UInt32 v___14;
  UInt32 v___15;
  UInt32 v___16;
  UInt32 v___17;
  UInt32 v___18;
  UInt32 v___19;
  UInt32 v___20;
  UInt32 v___21;
  UChar pos[6];
  UChar tmp;
  UChar v___22;
  UInt32 v___23;
  UInt32 v___24;
  UInt32 v___25;
  Int32 ii;
  Int32 jj;
  Int32 kk;
  UInt32 v___26;
  UInt32 v___27;
  UInt32 v___28;
  UInt32 v___29;
  Int32 ii___0;
  Int32 jj___0;
  Int32 kk___0;
  Int32 pp;
  Int32 lno;
  Int32 off;
  UInt32 nn;
  Int32 z;
  UInt32 v___30;
  UInt32 v___31;
  Int32 tmp___0;
  int tmp___1;
  int tmp___2;
  UInt32 v___32;
  UInt32 v___33;
  UInt32 v___34;
  UInt32 v___35;
  UInt32 v___36;
  UInt32 v___37;
  UInt32 v___38;
  UInt32 v___39;
  UInt32 v___40;
  void *__cil_tmp92;

  {
    strm = s->strm;
    if (s->state == 10) {
      s->save_i = 0;
      s->save_j = 0;
      s->save_t = 0;
      s->save_alphaSize = 0;
      s->save_nGroups = 0;
      s->save_nSelectors = 0;
      s->save_EOB = 0;
      s->save_groupNo = 0;
      s->save_groupPos = 0;
      s->save_nextSym = 0;
      s->save_nblockMAX = 0;
      s->save_nblock = 0;
      s->save_es = 0;
      s->save_N = 0;
      s->save_curr = 0;
      s->save_zt = 0;
      s->save_zn = 0;
      s->save_zvec = 0;
      s->save_zj = 0;
      s->save_gSel = 0;
      s->save_gMinlen = 0;
      s->save_gLimit = (Int32 *)((void *)0);
      s->save_gBase = (Int32 *)((void *)0);
      s->save_gPerm = (Int32 *)((void *)0);
    }
    i = s->save_i;
    j = s->save_j;
    t = s->save_t;
    alphaSize = s->save_alphaSize;
    nGroups = s->save_nGroups;
    nSelectors = s->save_nSelectors;
    EOB = s->save_EOB;
    groupNo = s->save_groupNo;
    groupPos = s->save_groupPos;
    nextSym = s->save_nextSym;
    nblockMAX = s->save_nblockMAX;
    nblock = s->save_nblock;
    es = s->save_es;
    N = s->save_N;
    curr = s->save_curr;
    zt = s->save_zt;
    zn = s->save_zn;
    zvec = s->save_zvec;
    zj = s->save_zj;
    gSel = s->save_gSel;
    gMinlen = s->save_gMinlen;
    gLimit = s->save_gLimit;
    gBase = s->save_gBase;
    gPerm = s->save_gPerm;
    retVal = 0;
    {
      if (s->state == 10) {
        goto case_10;
      }
      if (s->state == 11) {
        goto case_11;
      }
      if (s->state == 12) {
        goto case_12;
      }
      if (s->state == 13) {
        goto case_13;
      }
      if (s->state == 14) {
        goto case_14;
      }
      if (s->state == 15) {
        goto case_15;
      }
      if (s->state == 16) {
        goto case_16;
      }
      if (s->state == 17) {
        goto case_17;
      }
      if (s->state == 18) {
        goto case_18;
      }
      if (s->state == 19) {
        goto case_19;
      }
      if (s->state == 20) {
        goto case_20;
      }
      if (s->state == 21) {
        goto case_21;
      }
      if (s->state == 22) {
        goto case_22;
      }
      if (s->state == 23) {
        goto case_23;
      }
      if (s->state == 24) {
        goto case_24;
      }
      if (s->state == 25) {
        goto case_25;
      }
      if (s->state == 26) {
        goto case_26;
      }
      if (s->state == 27) {
        goto case_27;
      }
      if (s->state == 28) {
        goto case_28;
      }
      if (s->state == 29) {
        goto case_29;
      }
      if (s->state == 30) {
        goto case_30;
      }
      if (s->state == 31) {
        goto case_31;
      }
      if (s->state == 32) {
        goto case_32;
      }
      if (s->state == 33) {
        goto case_33;
      }
      if (s->state == 34) {
        goto case_34;
      }
      if (s->state == 35) {
        goto case_35;
      }

      if (s->state == 37) {
        goto case_37;
      }
      if (s->state == 38) {
        goto case_38;
      }
      if (s->state == 39) {
        goto case_39;
      }
      if (s->state == 40) {
        goto case_40;
      }
      if (s->state == 41) {
        goto case_41;
      }
      if (s->state == 42) {
        goto endhdr_2;
      }
      if (s->state == 43) {
        goto case_43;
      }
      if (s->state == 44) {
        goto case_44;
      }
      if (s->state == 45) {
        goto case_45;
      }
      if (s->state == 46) {
        goto case_46;
      }
      if (s->state == 47) {
        goto case_47;
      }
      if (s->state == 48) {
        goto case_48;
      }

      if (s->state == 50) {
        goto case_50;
      }
      goto switch_default;
    case_10: /* CIL Label */
      s->state = 10;
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v = (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v;
            goto while_break;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break: /* CIL Label */
          ;
      }
      if ((int)uc != 66) {
        retVal = -5;
        goto save_state_and_return;
      }
    case_11: /* CIL Label */
      s->state = 11;
      {
        while (1) {
        while_continue___0: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___0 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___0;
            goto while_break___0;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___0: /* CIL Label */
          ;
      }
      if ((int)uc != 90) {
        retVal = -5;
        goto save_state_and_return;
      }
    case_12: /* CIL Label */
      s->state = 12;
      {
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___1 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___1;
            goto while_break___1;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___1: /* CIL Label */
          ;
      }

    case_13: /* CIL Label */
      s->state = 13;
      {
        while (1) {
        while_continue___2: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___2 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            s->blockSize100k = (Int32)v___2;
            goto while_break___2;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___2: /* CIL Label */
          ;
      }

      s->blockSize100k -= 48;
      if (s->smallDecompress) {
        {
          s->ll16 = (UInt16 *)(*(strm->bzalloc))(
              strm->opaque,
              (int)((unsigned long)(s->blockSize100k * 100000) *
                    sizeof(UInt16)),
              1);
          s->ll4 = (UChar *)(*(strm->bzalloc))(
              strm->opaque,
              (int)((unsigned long)((1 + s->blockSize100k * 100000) >> 1) *
                    sizeof(UChar)),
              1);
        }

      } else {
        {
          s->tt = (UInt32 *)(*(strm->bzalloc))(
              strm->opaque,
              (int)((unsigned long)(s->blockSize100k * 100000) * sizeof(Int32)),
              1);
        }
        if ((unsigned long)s->tt == (unsigned long)((void *)0)) {
          retVal = -3;
          goto save_state_and_return;
        }
      }
    case_14: /* CIL Label */
      s->state = 14;
      {
        while (1) {
        while_continue___3: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___3 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___3;
            goto while_break___3;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___3: /* CIL Label */
          ;
      }
      if ((int)uc == 23) {
        goto endhdr_2;
      }
      if ((int)uc != 49) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_15: /* CIL Label */
      s->state = 15;
      {
        while (1) {
        while_continue___4: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___4 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___4;
            goto while_break___4;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___4: /* CIL Label */
          ;
      }
      if ((int)uc != 65) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_16: /* CIL Label */
      s->state = 16;
      {
        while (1) {
        while_continue___5: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___5 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___5;
            goto while_break___5;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___5: /* CIL Label */
          ;
      }
      if ((int)uc != 89) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_17: /* CIL Label */
      s->state = 17;
      {
        while (1) {
        while_continue___6: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___6 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___6;
            goto while_break___6;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___6: /* CIL Label */
          ;
      }
      if ((int)uc != 38) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_18: /* CIL Label */
      s->state = 18;
      {
        while (1) {
        while_continue___7: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___7 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___7;
            goto while_break___7;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___7: /* CIL Label */
          ;
      }
      if ((int)uc != 83) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_19: /* CIL Label */
      s->state = 19;
      {
        while (1) {
        while_continue___8: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___8 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___8;
            goto while_break___8;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___8: /* CIL Label */
          ;
      }

      (s->currBlockNo)++;

      s->storedBlockCRC = (UInt32)0;
    case_20: /* CIL Label */
      s->state = 20;
      {
        while (1) {
        while_continue___9: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___9 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___9;
            goto while_break___9;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___9: /* CIL Label */
          ;
      }
      s->storedBlockCRC = (s->storedBlockCRC << 8) | (UInt32)uc;
    case_21: /* CIL Label */
      s->state = 21;
      {
        while (1) {
        while_continue___10: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___10 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___10;
            goto while_break___10;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___10: /* CIL Label */
          ;
      }
      s->storedBlockCRC = (s->storedBlockCRC << 8) | (UInt32)uc;
    case_22: /* CIL Label */
      s->state = 22;
      {
        while (1) {
        while_continue___11: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___11 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___11;
            goto while_break___11;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___11: /* CIL Label */
          ;
      }
      s->storedBlockCRC = (s->storedBlockCRC << 8) | (UInt32)uc;
    case_23: /* CIL Label */
      s->state = 23;
      {
        while (1) {
        while_continue___12: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___12 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___12;
            goto while_break___12;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___12: /* CIL Label */
          ;
      }
      s->storedBlockCRC = (s->storedBlockCRC << 8) | (UInt32)uc;
    case_24: /* CIL Label */
      s->state = 24;
      {
        while (1) {
        while_continue___13: /* CIL Label */
            ;
          if (s->bsLive >= 1) {
            v___13 =
                (s->bsBuff >> (s->bsLive - 1)) & (unsigned int)((1 << 1) - 1);
            (s->bsLive)--;
            s->blockRandomised = (Bool)v___13;
            goto while_break___13;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
        }
      while_break___13: /* CIL Label */
          ;
      }
      s->origPtr = 0;
    case_25: /* CIL Label */
      s->state = 25;
      {
        while (1) {
        while_continue___14: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___14 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___14;
            goto while_break___14;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___14: /* CIL Label */
          ;
      }
      s->origPtr = (s->origPtr << 8) | (Int32)uc;
    case_26: /* CIL Label */
      s->state = 26;
      {
        while (1) {
        while_continue___15: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___15 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___15;
            goto while_break___15;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___15: /* CIL Label */
          ;
      }
      s->origPtr = (s->origPtr << 8) | (Int32)uc;
    case_27: /* CIL Label */
      s->state = 27;
      {
        while (1) {
        while_continue___16: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___16 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___16;
            goto while_break___16;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___16: /* CIL Label */
          ;
      }
      s->origPtr = (s->origPtr << 8) | (Int32)uc;

      if (s->origPtr > 10 + 100000 * s->blockSize100k) {
        retVal = -4;
        goto save_state_and_return;
      }
      i = 0;
      {
        while (1) {
        while_continue___17: /* CIL Label */
            ;
          if (!(i < 16)) {
            goto while_break___17;
          }
        case_28: /* CIL Label */
          s->state = 28;
          {
            while (1) {
            while_continue___18: /* CIL Label */
                ;
              if (s->bsLive >= 1) {
                v___17 = (s->bsBuff >> (s->bsLive - 1)) &
                         (unsigned int)((1 << 1) - 1);
                (s->bsLive)--;
                uc = (UChar)v___17;
                goto while_break___18;
              }
              if ((s->strm)->avail_in == 0U) {
                retVal = 0;
                goto save_state_and_return;
              }
              s->bsBuff =
                  (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
              s->bsLive += 8;
              ((s->strm)->next_in)++;
              ((s->strm)->avail_in)--;
              ((s->strm)->total_in_lo32)++;
            }
          while_break___18: /* CIL Label */
              ;
          }
          if ((int)uc == 1) {
            s->inUse16[i] = (Bool)1;
          } else {
            s->inUse16[i] = (Bool)0;
          }
          i++;
        }
      while_break___17: /* CIL Label */
          ;
      }
      i = 0;
      {
        while (1) {
        while_continue___19: /* CIL Label */
            ;
          if (!(i < 256)) {
            goto while_break___19;
          }
          s->inUse[i] = (Bool)0;
          i++;
        }
      while_break___19: /* CIL Label */
          ;
      }
      i = 0;
      {
        while (1) {
        while_continue___20: /* CIL Label */
            ;
          if (!(i < 16)) {
            goto while_break___20;
          }
          if (s->inUse16[i]) {
            j = 0;
            {
              while (1) {
              while_continue___21: /* CIL Label */
                  ;
                if (!(j < 16)) {
                  goto while_break___21;
                }
              case_29: /* CIL Label */
                s->state = 29;
                {
                  while (1) {
                  while_continue___22: /* CIL Label */
                      ;
                    if (s->bsLive >= 1) {
                      v___18 = (s->bsBuff >> (s->bsLive - 1)) &
                               (unsigned int)((1 << 1) - 1);
                      (s->bsLive)--;
                      uc = (UChar)v___18;
                      goto while_break___22;
                    }
                    if ((s->strm)->avail_in == 0U) {
                      retVal = 0;
                      goto save_state_and_return;
                    }
                    s->bsBuff = (s->bsBuff << 8) |
                                (UInt32) * ((UChar *)(s->strm)->next_in);
                    s->bsLive += 8;
                    ((s->strm)->next_in)++;
                    ((s->strm)->avail_in)--;
                    ((s->strm)->total_in_lo32)++;
                    if ((s->strm)->total_in_lo32 == 0U) {
                      ((s->strm)->total_in_hi32)++;
                    }
                  }
                while_break___22: /* CIL Label */
                    ;
                }
                if ((int)uc == 1) {
                  s->inUse[i * 16 + j] = (Bool)1;
                }
                j++;
              }
            while_break___21: /* CIL Label */
                ;
            }
          }
          i++;
        }
      while_break___20: /* CIL Label */
          ;
      }
      { makeMaps_d(s); }
      if (s->nInUse == 0) {
        retVal = -4;
        goto save_state_and_return;
      }
      alphaSize = s->nInUse + 2;
    case_30: /* CIL Label */
      s->state = 30;
      {
        while (1) {
        while_continue___23: /* CIL Label */
            ;
          if (s->bsLive >= 3) {
            v___19 =
                (s->bsBuff >> (s->bsLive - 3)) & (unsigned int)((1 << 3) - 1);
            s->bsLive -= 3;
            nGroups = (Int32)v___19;
            goto while_break___23;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___23: /* CIL Label */
          ;
      }

    case_31: /* CIL Label */
      s->state = 31;
      {
        while (1) {
        while_continue___24: /* CIL Label */
            ;
          if (s->bsLive >= 15) {
            v___20 =
                (s->bsBuff >> (s->bsLive - 15)) & (unsigned int)((1 << 15) - 1);
            s->bsLive -= 15;
            nSelectors = (Int32)v___20;
            goto while_break___24;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
        }
      while_break___24: /* CIL Label */
          ;
      }
      if (nSelectors < 1) {
        retVal = -4;
        goto save_state_and_return;
      }
      i = 0;
      {
        while (1) {
        while_continue___25: /* CIL Label */
            ;
          if (!(i < nSelectors)) {
            goto while_break___25;
          }
          j = 0;
          {
            while (1) {
            while_continue___26: /* CIL Label */
                ;
            case_32: /* CIL Label */
              s->state = 32;
              {
                while (1) {
                while_continue___27: /* CIL Label */
                    ;
                  if (s->bsLive >= 1) {
                    v___21 = (s->bsBuff >> (s->bsLive - 1)) &
                             (unsigned int)((1 << 1) - 1);
                    (s->bsLive)--;
                    uc = (UChar)v___21;
                    goto while_break___27;
                  }
                  if ((s->strm)->avail_in == 0U) {
                    retVal = 0;
                    goto save_state_and_return;
                  }
                  s->bsBuff = (s->bsBuff << 8) |
                              (UInt32) * ((UChar *)(s->strm)->next_in);
                  s->bsLive += 8;
                  ((s->strm)->next_in)++;
                  ((s->strm)->avail_in)--;
                  ((s->strm)->total_in_lo32)++;
                  if ((s->strm)->total_in_lo32 == 0U) {
                    ((s->strm)->total_in_hi32)++;
                  }
                }
              while_break___27: /* CIL Label */
                  ;
              }
              if ((int)uc == 0) {
                goto while_break___26;
              }
              j++;
              if (j >= nGroups) {
                retVal = -4;
                goto save_state_and_return;
              }
            }
          while_break___26: /* CIL Label */
              ;
          }
          s->selectorMtf[i] = (UChar)j;
          i++;
        }
      while_break___25: /* CIL Label */
          ;
      }
      v___22 = (UChar)0;
      {
        while (1) {
        while_continue___28: /* CIL Label */
            ;
          if (!((int)v___22 < nGroups)) {
            goto while_break___28;
          }
          pos[v___22] = v___22;
          v___22 = (UChar)((int)v___22 + 1);
        }
      while_break___28: /* CIL Label */
          ;
      }
      i = 0;
      {
        while (1) {
        while_continue___29: /* CIL Label */
            ;
          if (!(i < nSelectors)) {
            goto while_break___29;
          }
          v___22 = s->selectorMtf[i];
          tmp = pos[v___22];
          {
            while (1) {
            while_continue___30: /* CIL Label */
                ;
              if (!((int)v___22 > 0)) {
                goto while_break___30;
              }
              pos[v___22] = pos[(int)v___22 - 1];
              v___22 = (UChar)((int)v___22 - 1);
            }
          while_break___30: /* CIL Label */
              ;
          }
          pos[0] = tmp;
          s->selector[i] = tmp;
          i++;
        }
      while_break___29: /* CIL Label */
          ;
      }
      t = 0;
      {
        while (1) {
        while_continue___31: /* CIL Label */
            ;
          if (!(t < nGroups)) {
            goto while_break___31;
          }
        case_33: /* CIL Label */
          s->state = 33;
          {
            while (1) {
            while_continue___32: /* CIL Label */
                ;
              if (s->bsLive >= 5) {
                v___23 = (s->bsBuff >> (s->bsLive - 5)) &
                         (unsigned int)((1 << 5) - 1);
                s->bsLive -= 5;
                curr = (Int32)v___23;
                goto while_break___32;
              }

              s->bsBuff =
                  (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
              s->bsLive += 8;
              ((s->strm)->next_in)++;
              ((s->strm)->avail_in)--;
              ((s->strm)->total_in_lo32)++;
              if ((s->strm)->total_in_lo32 == 0U) {
                ((s->strm)->total_in_hi32)++;
              }
            }
          while_break___32: /* CIL Label */
              ;
          }
          i = 0;
          {
            while (1) {
            while_continue___33: /* CIL Label */
                ;
              if (!(i < alphaSize)) {
                goto while_break___33;
              }
              {
                while (1) {
                while_continue___34: /* CIL Label */
                    ;
                  if (curr < 1) {
                    retVal = -4;
                    goto save_state_and_return;
                  } else {
                  }
                case_34: /* CIL Label */
                  s->state = 34;
                  {
                    while (1) {
                    while_continue___35: /* CIL Label */
                        ;
                      if (s->bsLive >= 1) {
                        v___24 = (s->bsBuff >> (s->bsLive - 1)) &
                                 (unsigned int)((1 << 1) - 1);
                        (s->bsLive)--;
                        uc = (UChar)v___24;
                        goto while_break___35;
                      }
                      if ((s->strm)->avail_in == 0U) {
                        retVal = 0;
                        goto save_state_and_return;
                      }
                      s->bsBuff = (s->bsBuff << 8) |
                                  (UInt32) * ((UChar *)(s->strm)->next_in);
                      s->bsLive += 8;
                      ((s->strm)->next_in)++;
                      ((s->strm)->avail_in)--;
                      ((s->strm)->total_in_lo32)++;
                      if ((s->strm)->total_in_lo32 == 0U) {
                        ((s->strm)->total_in_hi32)++;
                      }
                    }
                  while_break___35: /* CIL Label */
                      ;
                  }
                  if ((int)uc == 0) {
                    goto while_break___34;
                  }
                case_35: /* CIL Label */
                  s->state = 35;
                  {
                    while (1) {
                    while_continue___36: /* CIL Label */
                        ;
                      if (s->bsLive >= 1) {
                        v___25 = (s->bsBuff >> (s->bsLive - 1)) &
                                 (unsigned int)((1 << 1) - 1);
                        (s->bsLive)--;
                        uc = (UChar)v___25;
                        goto while_break___36;
                      }
                      if ((s->strm)->avail_in == 0U) {
                        retVal = 0;
                        goto save_state_and_return;
                      }
                      s->bsBuff = (s->bsBuff << 8) |
                                  (UInt32) * ((UChar *)(s->strm)->next_in);
                      s->bsLive += 8;
                      ((s->strm)->next_in)++;
                      ((s->strm)->avail_in)--;
                      ((s->strm)->total_in_lo32)++;
                      if ((s->strm)->total_in_lo32 == 0U) {
                        ((s->strm)->total_in_hi32)++;
                      }
                    }
                  while_break___36: /* CIL Label */
                      ;
                  }
                  if ((int)uc == 0) {
                    curr++;
                  } else {
                    curr--;
                  }
                }
              while_break___34: /* CIL Label */
                  ;
              }
              s->len[t][i] = (UChar)curr;
              i++;
            }
          while_break___33: /* CIL Label */
              ;
          }
          t++;
        }
      while_break___31: /* CIL Label */
          ;
      }
      t = 0;
      {
        while (1) {
        while_continue___37: /* CIL Label */
            ;
          if (!(t < nGroups)) {
            goto while_break___37;
          }
          minLen = 32;
          maxLen = 0;
          i = 0;
          {
            while (1) {
            while_continue___38: /* CIL Label */
                ;
              if (!(i < alphaSize)) {
                goto while_break___38;
              }
              if ((int)s->len[t][i] > maxLen) {
                maxLen = (Int32)s->len[t][i];
              }
              if ((int)s->len[t][i] < minLen) {
                minLen = (Int32)s->len[t][i];
              }
              i++;
            }
          while_break___38: /* CIL Label */
              ;
          }
          {
            BZ2_hbCreateDecodeTables(&s->limit[t][0], &s->base[t][0],
                                     &s->perm[t][0], &s->len[t][0], minLen,
                                     maxLen, alphaSize);
            s->minLens[t] = minLen;
            t++;
          }
        }
      while_break___37: /* CIL Label */
          ;
      }
      EOB = s->nInUse + 1;
      nblockMAX = 100000 * s->blockSize100k;
      groupNo = -1;
      groupPos = 0;
      i = 0;
      {
        while (1) {
        while_continue___39: /* CIL Label */
            ;
          if (!(i <= 255)) {
            goto while_break___39;
          }
          s->unzftab[i] = 0;
          i++;
        }
      while_break___39: /* CIL Label */
          ;
      }
      kk = 4095;
      ii = 15;
      {
        while (1) {
        while_continue___40: /* CIL Label */
            ;
          if (!(ii >= 0)) {
            goto while_break___40;
          }
          jj = 15;
          {
            while (1) {
            while_continue___41: /* CIL Label */
                ;
              if (!(jj >= 0)) {
                goto while_break___41;
              }
              s->mtfa[kk] = (UChar)(ii * 16 + jj);
              kk--;
              jj--;
            }
          while_break___41: /* CIL Label */
              ;
          }
          s->mtfbase[ii] = kk + 1;
          ii--;
        }
      while_break___40: /* CIL Label */
          ;
      }
      nblock = 0;
      if (groupPos == 0) {
        groupNo++;
        if (groupNo >= nSelectors) {
          retVal = -4;
          goto save_state_and_return;
        }
        groupPos = 50;
        gSel = (Int32)s->selector[groupNo];
        gMinlen = s->minLens[gSel];
        gLimit = &s->limit[gSel][0];
        gPerm = &s->perm[gSel][0];
        gBase = &s->base[gSel][0];
      }
      groupPos--;
      zn = gMinlen;
    case_36: /* CIL Label */
      s->state = 36;
      {
        while (1) {
        while_continue___42: /* CIL Label */
            ;
          if (s->bsLive >= zn) {
            v___26 =
                (s->bsBuff >> (s->bsLive - zn)) & (unsigned int)((1 << zn) - 1);
            s->bsLive -= zn;
            zvec = (Int32)v___26;
            goto while_break___42;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
        }
      while_break___42: /* CIL Label */
          ;
      }
      {
        while (1) {
        while_continue___43: /* CIL Label */
            ;
          if (zn > 20) {
            retVal = -4;
            goto save_state_and_return;
          }
          if (zvec <= *(gLimit + zn)) {
            goto while_break___43;
          }
          zn++;
        case_37: /* CIL Label */
          s->state = 37;
          {
            while (1) {
            while_continue___44: /* CIL Label */
                ;
              if (s->bsLive >= 1) {
                v___27 = (s->bsBuff >> (s->bsLive - 1)) &
                         (unsigned int)((1 << 1) - 1);
                (s->bsLive)--;
                zj = (Int32)v___27;
                goto while_break___44;
              }
              if ((s->strm)->avail_in == 0U) {
                retVal = 0;
                goto save_state_and_return;
              }
              s->bsBuff =
                  (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
              s->bsLive += 8;
              ((s->strm)->next_in)++;
              ((s->strm)->avail_in)--;
              ((s->strm)->total_in_lo32)++;
              if ((s->strm)->total_in_lo32 == 0U) {
                ((s->strm)->total_in_hi32)++;
              }
            }
          while_break___44: /* CIL Label */
              ;
          }
          zvec = (zvec << 1) | zj;
        }
      while_break___43: /* CIL Label */
          ;
      }
      if (zvec - *(gBase + zn) < 0) {
        retVal = -4;
        goto save_state_and_return;
      } else {
        if (zvec - *(gBase + zn) >= 258) {
          retVal = -4;
          goto save_state_and_return;
        }
      }
      nextSym = *(gPerm + (zvec - *(gBase + zn)));
      {
        while (1) {
        while_continue___45: /* CIL Label */
            ;
          if (!(!(nextSym == EOB))) {
            goto while_break___45;
          }
          if (nextSym == 0) {
            goto _L;
          } else {
            if (nextSym == 1) {
            _L:
              es = -1;
              N = 1;
              {
                while (1) {
                while_continue___46: /* CIL Label */
                    ;
                  if (nextSym == 0) {
                    es += N;
                  } else {
                    if (nextSym == 1) {
                      es += 2 * N;
                    }
                  }
                  N *= 2;
                  if (groupPos == 0) {
                    groupNo++;
                    if (groupNo >= nSelectors) {
                      retVal = -4;
                      goto save_state_and_return;
                    }
                    groupPos = 50;
                    gSel = (Int32)s->selector[groupNo];
                    gMinlen = s->minLens[gSel];
                    gLimit = &s->limit[gSel][0];
                    gPerm = &s->perm[gSel][0];
                    gBase = &s->base[gSel][0];
                  }
                  groupPos--;
                  zn = gMinlen;
                case_38: /* CIL Label */
                  s->state = 38;
                  {
                    while (1) {
                    while_continue___47: /* CIL Label */
                        ;
                      if (s->bsLive >= zn) {
                        v___28 = (s->bsBuff >> (s->bsLive - zn)) &
                                 (unsigned int)((1 << zn) - 1);
                        s->bsLive -= zn;
                        zvec = (Int32)v___28;
                        goto while_break___47;
                      }
                      if ((s->strm)->avail_in == 0U) {
                        retVal = 0;
                        goto save_state_and_return;
                      }
                      s->bsBuff = (s->bsBuff << 8) |
                                  (UInt32) * ((UChar *)(s->strm)->next_in);
                      s->bsLive += 8;
                      ((s->strm)->next_in)++;
                      ((s->strm)->avail_in)--;
                      ((s->strm)->total_in_lo32)++;
                      if ((s->strm)->total_in_lo32 == 0U) {
                        ((s->strm)->total_in_hi32)++;
                      }
                    }
                  while_break___47: /* CIL Label */
                      ;
                  }
                  {
                    while (1) {
                    while_continue___48: /* CIL Label */
                        ;
                      if (zn > 20) {
                        retVal = -4;
                        goto save_state_and_return;
                      }
                      if (zvec <= *(gLimit + zn)) {
                        goto while_break___48;
                      }
                      zn++;
                    case_39: /* CIL Label */
                      s->state = 39;
                      {
                        while (1) {
                        while_continue___49: /* CIL Label */
                            ;
                          if (s->bsLive >= 1) {
                            v___29 = (s->bsBuff >> (s->bsLive - 1)) &
                                     (unsigned int)((1 << 1) - 1);
                            (s->bsLive)--;
                            zj = (Int32)v___29;
                            goto while_break___49;
                          }
                          if ((s->strm)->avail_in == 0U) {
                            retVal = 0;
                            goto save_state_and_return;
                          }
                          s->bsBuff = (s->bsBuff << 8) |
                                      (UInt32) * ((UChar *)(s->strm)->next_in);
                          s->bsLive += 8;
                          ((s->strm)->next_in)++;
                          ((s->strm)->avail_in)--;
                          ((s->strm)->total_in_lo32)++;
                          if ((s->strm)->total_in_lo32 == 0U) {
                            ((s->strm)->total_in_hi32)++;
                          }
                        }
                      while_break___49: /* CIL Label */
                          ;
                      }
                      zvec = (zvec << 1) | zj;
                    }
                  while_break___48: /* CIL Label */
                      ;
                  }
                  if (zvec - *(gBase + zn) < 0) {
                    retVal = -4;
                    goto save_state_and_return;
                  } else {
                    if (zvec - *(gBase + zn) >= 258) {
                      retVal = -4;
                      goto save_state_and_return;
                    }
                  }
                  nextSym = *(gPerm + (zvec - *(gBase + zn)));
                  if (!(nextSym == 0)) {
                    if (!(nextSym == 1)) {
                      goto while_break___46;
                    }
                  }
                }
              while_break___46: /* CIL Label */
                  ;
              }
              es++;
              uc = s->seqToUnseq[s->mtfa[s->mtfbase[0]]];
              s->unzftab[uc] += es;
              if (s->smallDecompress) {
                {
                  while (1) {
                  while_continue___50: /* CIL Label */
                      ;
                    if (!(es > 0)) {
                      goto while_break___50;
                    }
                    if (nblock >= nblockMAX) {
                      retVal = -4;
                      goto save_state_and_return;
                    }
                    *(s->ll16 + nblock) = (UInt16)uc;
                    nblock++;
                    es--;
                  }
                while_break___50: /* CIL Label */
                    ;
                }
              } else {
                {
                  while (1) {
                  while_continue___51: /* CIL Label */
                      ;
                    if (!(es > 0)) {
                      goto while_break___51;
                    }
                    if (nblock >= nblockMAX) {
                      retVal = -4;
                      goto save_state_and_return;
                    }
                    *(s->tt + nblock) = (UInt32)uc;
                    nblock++;
                    es--;
                  }
                while_break___51: /* CIL Label */
                    ;
                }
              }
              goto while_continue___45;
            } else {
              if (nblock >= nblockMAX) {
                retVal = -4;
                goto save_state_and_return;
              }
              nn = (UInt32)(nextSym - 1);
              if (nn < 16U) {
                pp = s->mtfbase[0];
                uc = s->mtfa[(UInt32)pp + nn];
                {

                while_break___52: /* CIL Label */
                    ;
                }
                {
                  while (1) {
                  while_continue___53: /* CIL Label */
                      ;
                    if (!(nn > 0U)) {
                      goto while_break___53;
                    }
                    s->mtfa[(UInt32)pp + nn] = s->mtfa[((UInt32)pp + nn) - 1U];
                    nn--;
                  }
                while_break___53: /* CIL Label */
                    ;
                }
                s->mtfa[pp] = uc;
              } else {
                lno = (Int32)(nn / 16U);
                off = (Int32)(nn % 16U);
                pp = s->mtfbase[lno] + off;
                uc = s->mtfa[pp];
                {
                  while (1) {
                  while_continue___54: /* CIL Label */
                      ;
                    if (!(pp > s->mtfbase[lno])) {
                      goto while_break___54;
                    }
                    s->mtfa[pp] = s->mtfa[pp - 1];
                    pp--;
                  }
                while_break___54: /* CIL Label */
                    ;
                }
                (s->mtfbase[lno])++;
                {
                  while (1) {
                  while_continue___55: /* CIL Label */
                      ;
                    if (!(lno > 0)) {
                      goto while_break___55;
                    }
                    (s->mtfbase[lno])--;
                    s->mtfa[s->mtfbase[lno]] =
                        s->mtfa[(s->mtfbase[lno - 1] + 16) - 1];
                    lno--;
                  }
                while_break___55: /* CIL Label */
                    ;
                }
                (s->mtfbase[0])--;
                s->mtfa[s->mtfbase[0]] = uc;
                if (s->mtfbase[0] == 0) {
                  kk___0 = 4095;
                  ii___0 = 15;
                  {
                    while (1) {
                    while_continue___56: /* CIL Label */
                        ;
                      if (!(ii___0 >= 0)) {
                        goto while_break___56;
                      }
                      jj___0 = 15;
                      {
                        while (1) {
                        while_continue___57: /* CIL Label */
                            ;
                          if (!(jj___0 >= 0)) {
                            goto while_break___57;
                          }
                          s->mtfa[kk___0] =
                              s->mtfa[s->mtfbase[ii___0] + jj___0];
                          kk___0--;
                          jj___0--;
                        }
                      while_break___57: /* CIL Label */
                          ;
                      }
                      s->mtfbase[ii___0] = kk___0 + 1;
                      ii___0--;
                    }
                  while_break___56: /* CIL Label */
                      ;
                  }
                }
              }
              (s->unzftab[s->seqToUnseq[uc]])++;
              if (s->smallDecompress) {
                *(s->ll16 + nblock) = (UInt16)s->seqToUnseq[uc];
              } else {
                *(s->tt + nblock) = (UInt32)s->seqToUnseq[uc];
              }
              nblock++;
              if (groupPos == 0) {
                groupNo++;
                if (groupNo >= nSelectors) {
                  retVal = -4;
                  goto save_state_and_return;
                }
                groupPos = 50;
                gSel = (Int32)s->selector[groupNo];
                gMinlen = s->minLens[gSel];
                gLimit = &s->limit[gSel][0];
                gPerm = &s->perm[gSel][0];
                gBase = &s->base[gSel][0];
              }
              groupPos--;
              zn = gMinlen;
            case_40: /* CIL Label */
              s->state = 40;
              {
                while (1) {
                while_continue___58: /* CIL Label */
                    ;
                  if (s->bsLive >= zn) {
                    v___30 = (s->bsBuff >> (s->bsLive - zn)) &
                             (unsigned int)((1 << zn) - 1);
                    s->bsLive -= zn;
                    zvec = (Int32)v___30;
                    goto while_break___58;
                  }
                  if ((s->strm)->avail_in == 0U) {
                    retVal = 0;
                    goto save_state_and_return;
                  }
                  s->bsBuff = (s->bsBuff << 8) |
                              (UInt32) * ((UChar *)(s->strm)->next_in);
                  s->bsLive += 8;
                  ((s->strm)->next_in)++;
                  ((s->strm)->avail_in)--;
                  ((s->strm)->total_in_lo32)++;
                  if ((s->strm)->total_in_lo32 == 0U) {
                    ((s->strm)->total_in_hi32)++;
                  }
                }
              while_break___58: /* CIL Label */
                  ;
              }
              {
                while (1) {
                while_continue___59: /* CIL Label */
                    ;
                  if (zn > 20) {
                    retVal = -4;
                    goto save_state_and_return;
                  }
                  if (zvec <= *(gLimit + zn)) {
                    goto while_break___59;
                  }
                  zn++;
                case_41: /* CIL Label */
                  s->state = 41;
                  {
                    while (1) {
                    while_continue___60: /* CIL Label */
                        ;
                      if (s->bsLive >= 1) {
                        v___31 = (s->bsBuff >> (s->bsLive - 1)) &
                                 (unsigned int)((1 << 1) - 1);
                        (s->bsLive)--;
                        zj = (Int32)v___31;
                        goto while_break___60;
                      }
                      if ((s->strm)->avail_in == 0U) {
                        retVal = 0;
                        goto save_state_and_return;
                      }
                      s->bsBuff = (s->bsBuff << 8) |
                                  (UInt32) * ((UChar *)(s->strm)->next_in);
                      s->bsLive += 8;
                      ((s->strm)->next_in)++;
                      ((s->strm)->avail_in)--;
                      ((s->strm)->total_in_lo32)++;
                    }
                  while_break___60: /* CIL Label */
                      ;
                  }
                  zvec = (zvec << 1) | zj;
                }
              while_break___59: /* CIL Label */
                  ;
              }
              if (zvec - *(gBase + zn) < 0) {
                retVal = -4;
                goto save_state_and_return;
              } else {
                if (zvec - *(gBase + zn) >= 258) {
                  retVal = -4;
                  goto save_state_and_return;
                }
              }
              nextSym = *(gPerm + (zvec - *(gBase + zn)));
              goto while_continue___45;
            }
          }
        }
      while_break___45: /* CIL Label */
          ;
      }
      if (s->origPtr < 0) {
        retVal = -4;
        goto save_state_and_return;
      } else {
        if (s->origPtr >= nblock) {
          retVal = -4;
          goto save_state_and_return;
        }
      }
      s->cftab[0] = 0;
      i = 1;
      {
        while (1) {
        while_continue___61: /* CIL Label */
            ;
          if (!(i <= 256)) {
            goto while_break___61;
          }
          s->cftab[i] = s->unzftab[i - 1];
          i++;
        }
      while_break___61: /* CIL Label */
          ;
      }
      i = 1;
      {
        while (1) {
        while_continue___62: /* CIL Label */
            ;
          if (!(i <= 256)) {
            goto while_break___62;
          }
          s->cftab[i] += s->cftab[i - 1];
          i++;
        }
      while_break___62: /* CIL Label */
          ;
      }
      i = 0;
      {
        while (1) {
        while_continue___63: /* CIL Label */
            ;
          if (!(i <= 256)) {
            goto while_break___63;
          }
          if (s->cftab[i] < 0) {
            retVal = -4;
            goto save_state_and_return;
          } else {
            if (s->cftab[i] > nblock) {
              retVal = -4;
              goto save_state_and_return;
            }
          }
          i++;
        }
      while_break___63: /* CIL Label */
          ;
      }
      s->state_out_len = 0;
      s->state_out_ch = (UChar)0;
      s->calculatedBlockCRC = (UInt32)4294967295L;
      s->state = 2;

      if (s->smallDecompress) {
        i = 0;
        {
          while (1) {
          while_continue___64: /* CIL Label */
              ;
            if (!(i <= 256)) {
              goto while_break___64;
            }
            s->cftabCopy[i] = s->cftab[i];
            i++;
          }
        while_break___64: /* CIL Label */
            ;
        }
        i = 0;
        {
          while (1) {
          while_continue___65: /* CIL Label */
              ;
            if (!(i < nblock)) {
              goto while_break___65;
            }
            uc = (UChar) * (s->ll16 + i);
            *(s->ll16 + i) = (UInt16)(s->cftabCopy[uc] & 65535);
            if ((i & 1) == 0) {
              *(s->ll4 + (i >> 1)) = (UChar)(((int)*(s->ll4 + (i >> 1)) & 240) |
                                             (s->cftabCopy[uc] >> 16));
            } else {
              *(s->ll4 + (i >> 1)) = (UChar)(((int)*(s->ll4 + (i >> 1)) & 15) |
                                             ((s->cftabCopy[uc] >> 16) << 4));
            }
            (s->cftabCopy[uc])++;
            i++;
          }
        while_break___65: /* CIL Label */
            ;
        }
        i = s->origPtr;
        j = (Int32)((UInt32) * (s->ll16 + i) |
                    ((((UInt32) * (s->ll4 + (i >> 1)) >> ((i << 2) & 4)) & 15U)
                     << 16));
        {

        while_break___66: /* CIL Label */
            ;
        }
        s->tPos = (UInt32)s->origPtr;
        s->nblock_used = 0;

      } else {
        i = 0;
        {
          while (1) {
          while_continue___67: /* CIL Label */
              ;
            if (!(i < nblock)) {
              goto while_break___67;
            }
            uc = (UChar)(*(s->tt + i) & 255U);
            *(s->tt + s->cftab[uc]) |= (unsigned int)(i << 8);
            (s->cftab[uc])++;
            i++;
          }
        while_break___67: /* CIL Label */
            ;
        }
        s->tPos = *(s->tt + s->origPtr) >> 8;
        s->nblock_used = 0;
        if (s->blockRandomised) {
          s->rNToGo = 0;
          s->rTPos = 0;

          s->tPos = *(s->tt + s->tPos);
          s->k0 = (Int32)((UChar)(s->tPos & 255U));
          s->tPos >>= 8;
          (s->nblock_used)++;
          if (s->rNToGo == 0) {
            s->rNToGo = BZ2_rNums[s->rTPos];
            (s->rTPos)++;
            if (s->rTPos == 512) {
              s->rTPos = 0;
            }
          }
          (s->rNToGo)--;

          s->k0 ^= tmp___2;
        } else {
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Int32)((Bool)1));
          }
          s->tPos = *(s->tt + s->tPos);
          s->k0 = (Int32)((UChar)(s->tPos & 255U));
          s->tPos >>= 8;
          (s->nblock_used)++;
        }
      }
      retVal = 0;
      goto save_state_and_return;
    endhdr_2:
    case_42: /* CIL Label */
      s->state = 42;
      {
        while (1) {
        while_continue___68: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___32 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___32;
            goto while_break___68;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___68: /* CIL Label */
          ;
      }
      if ((int)uc != 114) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_43: /* CIL Label */
      s->state = 43;
      {
        while (1) {
        while_continue___69: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___33 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___33;
            goto while_break___69;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___69: /* CIL Label */
          ;
      }
      if ((int)uc != 69) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_44: /* CIL Label */
      s->state = 44;
      {
        while (1) {
        while_continue___70: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___34 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___34;
            goto while_break___70;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___70: /* CIL Label */
          ;
      }
      if ((int)uc != 56) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_45: /* CIL Label */
      s->state = 45;
      {
        while (1) {
        while_continue___71: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___35 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___35;
            goto while_break___71;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___71: /* CIL Label */
          ;
      }
      if ((int)uc != 80) {
        retVal = -4;
        goto save_state_and_return;
      }
    case_46: /* CIL Label */
      s->state = 46;
      {
        while (1) {
        while_continue___72: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___36 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___36;
            goto while_break___72;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___72: /* CIL Label */
          ;
      }
      if ((int)uc != 144) {
        retVal = -4;
        goto save_state_and_return;
      }
      s->storedCombinedCRC = (UInt32)0;
    case_47: /* CIL Label */
      s->state = 47;
      {
        while (1) {
        while_continue___73: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___37 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___37;
            goto while_break___73;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___73: /* CIL Label */
          ;
      }
      s->storedCombinedCRC = (s->storedCombinedCRC << 8) | (UInt32)uc;
    case_48: /* CIL Label */
      s->state = 48;
      {
        while (1) {
        while_continue___74: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___38 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___38;
            goto while_break___74;
          }
          if ((s->strm)->avail_in == 0U) {
            retVal = 0;
            goto save_state_and_return;
          }
          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___74: /* CIL Label */
          ;
      }
      s->storedCombinedCRC = (s->storedCombinedCRC << 8) | (UInt32)uc;
    case_49: /* CIL Label */
      s->state = 49;
      {
        while (1) {
        while_continue___75: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___39 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___39;
            goto while_break___75;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
        }
      while_break___75: /* CIL Label */
          ;
      }
      s->storedCombinedCRC = (s->storedCombinedCRC << 8) | (UInt32)uc;
    case_50: /* CIL Label */
      s->state = 50;
      {
        while (1) {
        while_continue___76: /* CIL Label */
            ;
          if (s->bsLive >= 8) {
            v___40 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___40;
            goto while_break___76;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
          ((s->strm)->total_in_lo32)++;
          if ((s->strm)->total_in_lo32 == 0U) {
            ((s->strm)->total_in_hi32)++;
          }
        }
      while_break___76: /* CIL Label */
          ;
      }
      s->storedCombinedCRC = (s->storedCombinedCRC << 8) | (UInt32)uc;
      s->state = 1;
      retVal = 4;
      goto save_state_and_return;
    switch_default: { /* CIL Label */
      BZ2_bz__AssertH__fail(4001);
    }
    switch_break: /* CIL Label */
        ;
    }
    { BZ2_bz__AssertH__fail(4002); }
  save_state_and_return:
    s->save_i = i;
    s->save_j = j;
    s->save_t = t;
    s->save_alphaSize = alphaSize;
    s->save_nGroups = nGroups;
    s->save_nSelectors = nSelectors;
    s->save_EOB = EOB;
    s->save_groupNo = groupNo;
    s->save_groupPos = groupPos;
    s->save_nextSym = nextSym;
    s->save_nblockMAX = nblockMAX;
    s->save_nblock = nblock;
    s->save_es = es;
    s->save_N = N;
    s->save_curr = curr;
    s->save_zt = zt;
    s->save_zn = zn;
    s->save_zvec = zvec;
    s->save_zj = zj;
    s->save_gSel = gSel;
    s->save_gMinlen = gMinlen;
    s->save_gLimit = gLimit;
    s->save_gBase = gBase;
    s->save_gPerm = gPerm;
    return (retVal);
  }
}
UInt32 BZ2_crc32Table[256];
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

extern __attribute__((__nothrow__)) void *(__attribute__((__leaf__)) malloc)(
    size_t __size) __attribute__((__malloc__));
extern __attribute__((__nothrow__)) void(__attribute__((__leaf__)) free)(
    void *__ptr);
extern __attribute__((__nothrow__, __noreturn__)) void(
    __attribute__((__leaf__)) exit)(int __status);
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
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
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) ferror)(
    FILE *__stream);
extern __attribute__((__nothrow__)) unsigned short const **(
    __attribute__((__leaf__)) __ctype_b_loc)(void)__attribute__((__const__));
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcat)(char *__restrict __dest,
                                          char const *__restrict __src);
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcmp)(char const *__s1, char const *__s2)
    __attribute__((__pure__));
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
void BZ2_bz__AssertH__fail(int errcode) {
  char const *tmp;

  {
    { tmp = BZ2_bzlibVersion(); }

    { exit(3); }
  }
}
static int bz_config_ok(void) {

  {

    if (sizeof(short) != 2UL) {
      return (0);
    }

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
    if ((unsigned long)addr != (unsigned long)((void *)0)) {
      {
        free(addr);
      }
    }
    return;
  }
}

int BZ2_bzDecompressInit(bz_stream *strm, int verbosity___0, int small) {
  DState *s;
  int tmp;

  {
    { tmp = bz_config_ok(); }

    if ((unsigned long)strm == (unsigned long)((void *)0)) {
      return (-2);
    }

    if ((unsigned long)strm->bzalloc == (unsigned long)((void *)0)) {
      strm->bzalloc = &default_bzalloc;
    }
    if ((unsigned long)strm->bzfree == (unsigned long)((void *)0)) {
      strm->bzfree = &default_bzfree;
    }
    { s = (DState *)(*(strm->bzalloc))(strm->opaque, (int)sizeof(DState), 1); }

    s->strm = strm;
    strm->state = (void *)s;
    s->state = 10;
    s->bsLive = 0;
    s->bsBuff = (UInt32)0;
    s->calculatedCombinedCRC = (UInt32)0;
    strm->total_in_lo32 = 0U;
    strm->total_in_hi32 = 0U;
    strm->total_out_lo32 = 0U;
    strm->total_out_hi32 = 0U;
    s->smallDecompress = (Bool)small;
    s->ll4 = (UChar *)((void *)0);
    s->ll16 = (UInt16 *)((void *)0);
    s->tt = (UInt32 *)((void *)0);
    s->currBlockNo = 0;
    s->verbosity = verbosity___0;
    return (0);
  }
}
static Bool unRLE_obuf_to_output_FAST(DState *s) {
  UChar k1;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
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
    if (s->blockRandomised) {
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          {

          while_break___0: /* CIL Label */
              ;
          }
          if (s->nblock_used == s->save_nblock + 1) {
            return ((Bool)0);
          }
          if (s->nblock_used > s->save_nblock + 1) {
            return ((Bool)1);
          }
          s->state_out_len = 1;
          s->state_out_ch = (UChar)s->k0;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          s->tPos = *(s->tt + s->tPos);
          k1 = (UChar)(s->tPos & 255U);
          s->tPos >>= 8;
          if (s->rNToGo == 0) {
            s->rNToGo = BZ2_rNums[s->rTPos];
            (s->rTPos)++;
          }
          (s->rNToGo)--;

          k1 = (UChar)((int)k1 ^ tmp);
          (s->nblock_used)++;
          if (s->nblock_used == s->save_nblock + 1) {
            goto while_continue;
          }
          if ((int)k1 != s->k0) {
            s->k0 = (Int32)k1;
            goto while_continue;
          }
          s->state_out_len = 2;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          s->tPos = *(s->tt + s->tPos);
          k1 = (UChar)(s->tPos & 255U);
          s->tPos >>= 8;

          (s->rNToGo)--;
          if (s->rNToGo == 1) {
            tmp___0 = 1;
          } else {
            tmp___0 = 0;
          }
          k1 = (UChar)((int)k1 ^ tmp___0);
          (s->nblock_used)++;
          if (s->nblock_used == s->save_nblock + 1) {
            goto while_continue;
          }
          if ((int)k1 != s->k0) {
            s->k0 = (Int32)k1;
            goto while_continue;
          }
          s->state_out_len = 3;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          s->tPos = *(s->tt + s->tPos);
          k1 = (UChar)(s->tPos & 255U);
          s->tPos >>= 8;
          if (s->rNToGo == 0) {
            s->rNToGo = BZ2_rNums[s->rTPos];
            (s->rTPos)++;
            if (s->rTPos == 512) {
              s->rTPos = 0;
            }
          }
          (s->rNToGo)--;

          k1 = (UChar)((int)k1 ^ tmp___1);
          (s->nblock_used)++;

          if ((int)k1 != s->k0) {
            s->k0 = (Int32)k1;
            goto while_continue;
          }
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          s->tPos = *(s->tt + s->tPos);
          k1 = (UChar)(s->tPos & 255U);
          s->tPos >>= 8;
          if (s->rNToGo == 0) {
            s->rNToGo = BZ2_rNums[s->rTPos];
            (s->rTPos)++;
            if (s->rTPos == 512) {
              s->rTPos = 0;
            }
          }
          (s->rNToGo)--;
          if (s->rNToGo == 1) {
            tmp___2 = 1;
          } else {
            tmp___2 = 0;
          }
          k1 = (UChar)((int)k1 ^ tmp___2);
          (s->nblock_used)++;
          s->state_out_len = (Int32)k1 + 4;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          s->tPos = *(s->tt + s->tPos);
          s->k0 = (Int32)((UChar)(s->tPos & 255U));
          s->tPos >>= 8;
          if (s->rNToGo == 0) {
            s->rNToGo = BZ2_rNums[s->rTPos];
            (s->rTPos)++;
          }
          (s->rNToGo)--;

          s->k0 ^= tmp___3;
          (s->nblock_used)++;
        }
      while_break: /* CIL Label */
          ;
      }
    } else {
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
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          if (c_state_out_len > 0) {
            {
              while (1) {
              while_continue___2: /* CIL Label */
                  ;
                if (cs_avail_out == 0U) {
                  goto return_notr;
                }
                if (c_state_out_len == 1) {
                  goto while_break___2;
                }
                *((UChar *)cs_next_out) = c_state_out_ch;
                c_calculatedBlockCRC =
                    (c_calculatedBlockCRC << 8) ^
                    BZ2_crc32Table[(c_calculatedBlockCRC >> 24) ^
                                   (unsigned int)c_state_out_ch];
                c_state_out_len--;
                cs_next_out++;
                cs_avail_out--;
              }
            while_break___2: /* CIL Label */
                ;
            }
          s_state_out_len_eq_one:
            if (cs_avail_out == 0U) {
              c_state_out_len = 1;
              goto return_notr;
            }
            *((UChar *)cs_next_out) = c_state_out_ch;
            c_calculatedBlockCRC = (c_calculatedBlockCRC << 8) ^
                                   BZ2_crc32Table[(c_calculatedBlockCRC >> 24) ^
                                                  (unsigned int)c_state_out_ch];
            cs_next_out++;
            cs_avail_out--;
          }

          if (c_nblock_used == s_save_nblockPP) {
            c_state_out_len = 0;
            goto return_notr;
          }
          c_state_out_ch = (UChar)c_k0;
          if (c_tPos >= 100000U * (UInt32)ro_blockSize100k) {
            return ((Bool)1);
          }
          c_tPos = *(c_tt + c_tPos);
          k1 = (UChar)(c_tPos & 255U);
          c_tPos >>= 8;
          c_nblock_used++;
          if ((int)k1 != c_k0) {
            c_k0 = (Int32)k1;
            goto s_state_out_len_eq_one;
          }

          c_state_out_len = 2;
          if (c_tPos >= 100000U * (UInt32)ro_blockSize100k) {
            return ((Bool)1);
          }
          c_tPos = *(c_tt + c_tPos);
          k1 = (UChar)(c_tPos & 255U);
          c_tPos >>= 8;
          c_nblock_used++;

          if ((int)k1 != c_k0) {
            c_k0 = (Int32)k1;
            goto while_continue___1;
          }
          c_state_out_len = 3;
          if (c_tPos >= 100000U * (UInt32)ro_blockSize100k) {
            return ((Bool)1);
          }
          c_tPos = *(c_tt + c_tPos);
          k1 = (UChar)(c_tPos & 255U);
          c_tPos >>= 8;
          c_nblock_used++;
          if (c_nblock_used == s_save_nblockPP) {
            goto while_continue___1;
          }
          if ((int)k1 != c_k0) {
            c_k0 = (Int32)k1;
            goto while_continue___1;
          }
          if (c_tPos >= 100000U * (UInt32)ro_blockSize100k) {
            return ((Bool)1);
          }
          c_tPos = *(c_tt + c_tPos);
          k1 = (UChar)(c_tPos & 255U);
          c_tPos >>= 8;
          c_nblock_used++;
          c_state_out_len = (Int32)k1 + 4;
          if (c_tPos >= 100000U * (UInt32)ro_blockSize100k) {
            return ((Bool)1);
          }
          c_tPos = *(c_tt + c_tPos);
          c_k0 = (Int32)((UChar)(c_tPos & 255U));
          c_tPos >>= 8;
          c_nblock_used++;
        }
      while_break___1: /* CIL Label */
          ;
      }
    return_notr:
      total_out_lo32_old = (s->strm)->total_out_lo32;
      (s->strm)->total_out_lo32 += avail_out_INIT - cs_avail_out;
      if ((s->strm)->total_out_lo32 < total_out_lo32_old) {
        ((s->strm)->total_out_hi32)++;
      }
      s->calculatedBlockCRC = c_calculatedBlockCRC;
      s->state_out_ch = c_state_out_ch;
      s->state_out_len = c_state_out_len;
      s->nblock_used = c_nblock_used;
      s->k0 = c_k0;
      s->tt = c_tt;
      s->tPos = c_tPos;
      (s->strm)->next_out = cs_next_out;
      (s->strm)->avail_out = cs_avail_out;
    }
    return ((Bool)0);
  }
}
Int32 BZ2_indexIntoF(Int32 indx, Int32 *cftab) {
  Int32 nb;
  Int32 na;
  Int32 mid;

  {
    nb = 0;
    na = 256;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        mid = (nb + na) >> 1;
        if (indx >= *(cftab + mid)) {
          nb = mid;
        } else {
          na = mid;
        }
        if (!(na - nb != 1)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return (nb);
  }
}
static Bool unRLE_obuf_to_output_SMALL(DState *s) {
  UChar k1;
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;

  {
    if (s->blockRandomised) {
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          {

          while_break___0: /* CIL Label */
              ;
          }
          if (s->nblock_used == s->save_nblock + 1) {
            return ((Bool)0);
          }
          if (s->nblock_used > s->save_nblock + 1) {
            return ((Bool)1);
          }
          s->state_out_len = 1;
          s->state_out_ch = (UChar)s->k0;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            k1 = (UChar)BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
          }
          if (s->rNToGo == 0) {
            s->rNToGo = BZ2_rNums[s->rTPos];
            (s->rTPos)++;
          }
          (s->rNToGo)--;

          k1 = (UChar)((int)k1 ^ tmp);
          (s->nblock_used)++;

          if ((int)k1 != s->k0) {
            s->k0 = (Int32)k1;
            goto while_continue;
          }
          s->state_out_len = 2;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            k1 = (UChar)BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
          }

          (s->rNToGo)--;
          if (s->rNToGo == 1) {
            tmp___0 = 1;
          } else {
            tmp___0 = 0;
          }
          k1 = (UChar)((int)k1 ^ tmp___0);
          (s->nblock_used)++;
          if (s->nblock_used == s->save_nblock + 1) {
            goto while_continue;
          }
          if ((int)k1 != s->k0) {
            s->k0 = (Int32)k1;
            goto while_continue;
          }
          s->state_out_len = 3;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            k1 = (UChar)BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
          }

          (s->rNToGo)--;

          k1 = (UChar)((int)k1 ^ tmp___1);
          (s->nblock_used)++;
          if (s->nblock_used == s->save_nblock + 1) {
            goto while_continue;
          }
          if ((int)k1 != s->k0) {
            s->k0 = (Int32)k1;
            goto while_continue;
          }
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            k1 = (UChar)BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
          }

          (s->rNToGo)--;
          if (s->rNToGo == 1) {
            tmp___2 = 1;
          } else {
            tmp___2 = 0;
          }
          k1 = (UChar)((int)k1 ^ tmp___2);
          (s->nblock_used)++;
          s->state_out_len = (Int32)k1 + 4;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            s->k0 = BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
          }

          (s->rNToGo)--;

          s->k0 ^= tmp___3;
          (s->nblock_used)++;
        }
      while_break: /* CIL Label */
          ;
      }
    } else {
      {
        while (1) {
        while_continue___1: /* CIL Label */
            ;
          {
            while (1) {
            while_continue___2: /* CIL Label */
                ;
              if ((s->strm)->avail_out == 0U) {
                return ((Bool)0);
              }
              if (s->state_out_len == 0) {
                goto while_break___2;
              }
              *((UChar *)(s->strm)->next_out) = s->state_out_ch;
              s->calculatedBlockCRC =
                  (s->calculatedBlockCRC << 8) ^
                  BZ2_crc32Table[(s->calculatedBlockCRC >> 24) ^
                                 (unsigned int)s->state_out_ch];
              (s->state_out_len)--;
              ((s->strm)->next_out)++;
              ((s->strm)->avail_out)--;
              ((s->strm)->total_out_lo32)++;
            }
          while_break___2: /* CIL Label */
              ;
          }
          if (s->nblock_used == s->save_nblock + 1) {
            return ((Bool)0);
          }
          if (s->nblock_used > s->save_nblock + 1) {
            return ((Bool)1);
          }
          s->state_out_len = 1;
          s->state_out_ch = (UChar)s->k0;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            k1 = (UChar)BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
            (s->nblock_used)++;
          }

          s->state_out_len = 2;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            k1 = (UChar)BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
            (s->nblock_used)++;
          }
          if (s->nblock_used == s->save_nblock + 1) {
            goto while_continue___1;
          }

          s->state_out_len = 3;
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            k1 = (UChar)BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
            (s->nblock_used)++;
          }

          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            k1 = (UChar)BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
            (s->nblock_used)++;
            s->state_out_len = (Int32)k1 + 4;
          }
          if (s->tPos >= 100000U * (UInt32)s->blockSize100k) {
            return ((Bool)1);
          }
          {
            s->k0 = BZ2_indexIntoF((Int32)s->tPos, s->cftab);
            s->tPos = (UInt32) * (s->ll16 + s->tPos) |
                      ((((UInt32) * (s->ll4 + (s->tPos >> 1)) >>
                         ((s->tPos << 2) & 4U)) &
                        15U)
                       << 16);
            (s->nblock_used)++;
          }
        }
      while_break___1: /* CIL Label */
          ;
      }
    }
  }
}
int BZ2_bzDecompress(bz_stream *strm) {
  Bool corrupt;
  DState *s;
  Int32 r;
  Int32 tmp;

  {
    if ((unsigned long)strm == (unsigned long)((void *)0)) {
      return (-2);
    }
    s = (DState *)strm->state;
    if ((unsigned long)s == (unsigned long)((void *)0)) {
      return (-2);
    }
    if ((unsigned long)s->strm != (unsigned long)strm) {
      return (-2);
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (s->state == 1) {
          return (-1);
        }
        if (s->state == 2) {
          if (s->smallDecompress) {
            {
              corrupt = unRLE_obuf_to_output_SMALL(s);
            }
          } else {
            { corrupt = unRLE_obuf_to_output_FAST(s); }
          }
          if (corrupt) {
            return (-4);
          }
          if (s->nblock_used == s->save_nblock + 1) {
            if (s->state_out_len == 0) {
              s->calculatedBlockCRC = ~s->calculatedBlockCRC;

              if (s->calculatedBlockCRC != s->storedBlockCRC) {
                return (-4);
              }
              s->calculatedCombinedCRC = (s->calculatedCombinedCRC << 1) |
                                         (s->calculatedCombinedCRC >> 31);
              s->calculatedCombinedCRC ^= s->calculatedBlockCRC;
              s->state = 14;
            } else {
              return (0);
            }
          } else {
            return (0);
          }
        }
        if (s->state >= 10) {
          {
            tmp = BZ2_decompress(s);
            r = tmp;
          }
          if (r == 4) {

            if (s->calculatedCombinedCRC != s->storedCombinedCRC) {
              return (-4);
            }
            return (r);
          }
          if (s->state != 2) {
            return (r);
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
    { BZ2_bz__AssertH__fail(6001); }
    return (0);
  }
}
int BZ2_bzDecompressEnd(bz_stream *strm) {
  DState *s;

  {
    if ((unsigned long)strm == (unsigned long)((void *)0)) {
      return (-2);
    }
    s = (DState *)strm->state;
    if ((unsigned long)s == (unsigned long)((void *)0)) {
      return (-2);
    }
    if ((unsigned long)s->strm != (unsigned long)strm) {
      return (-2);
    }

    if ((unsigned long)s->ll4 != (unsigned long)((void *)0)) {
      {
        (*(strm->bzfree))(strm->opaque, (void *)s->ll4);
      }
    }
    {
      (*(strm->bzfree))(strm->opaque, strm->state);
      strm->state = (void *)0;
    }
    return (0);
  }
}
static Bool myfeof(FILE *f) {
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
    return ((Bool)0);
  }
}

BZFILE *BZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity___0, int small,
                       void *unused, int nUnused) {
  bzFile *bzf;
  int ret;
  int tmp;
  void *__cil_tmp11;

  {
    bzf = (bzFile *)((void *)0);
    if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
      *bzerror = 0;
    }
    if ((unsigned long)bzf != (unsigned long)((void *)0)) {
      bzf->lastErr = 0;
    }
    if ((unsigned long)f == (unsigned long)((void *)0)) {
      goto _L___0;
    } else {
      if (small != 0) {

      } else {
      _L___2:
        if (verbosity___0 < 0) {
          goto _L___0;
        } else {
          if (verbosity___0 > 4) {
            goto _L___0;
          } else {
            if ((unsigned long)unused == (unsigned long)((void *)0)) {

            } else {
            _L___1:
              if ((unsigned long)unused != (unsigned long)((void *)0)) {
                if (nUnused < 0) {
                  goto _L___0;
                } else {
                  if (nUnused > 5000) {
                  _L___0:
                    if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
                      *bzerror = -2;
                    }
                    if ((unsigned long)bzf != (unsigned long)((void *)0)) {
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
    }
    { tmp = ferror(f); }
    if (tmp) {
      if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
        *bzerror = -6;
      }
      if ((unsigned long)bzf != (unsigned long)((void *)0)) {
        bzf->lastErr = -6;
      }
      return ((void *)0);
    }
    { bzf = (bzFile *)malloc(sizeof(bzFile)); }
    if ((unsigned long)bzf == (unsigned long)((void *)0)) {

      return ((void *)0);
    }

    bzf->initialisedOk = (Bool)0;
    bzf->handle = f;
    bzf->bufN = 0;
    bzf->writing = (Bool)0;
    bzf->strm.bzalloc = (void *(*)(void *, int, int))((void *)0);
    bzf->strm.bzfree = (void (*)(void *, void *))((void *)0);
    bzf->strm.opaque = (void *)0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(nUnused > 0)) {
          goto while_break;
        }
        bzf->buf[bzf->bufN] = (Char) * ((UChar *)unused);
        (bzf->bufN)++;
        unused = (void *)((UChar *)unused + 1);
        nUnused--;
      }
    while_break: /* CIL Label */
        ;
    }
    { ret = BZ2_bzDecompressInit(&bzf->strm, verbosity___0, small); }

    bzf->strm.avail_in = (unsigned int)bzf->bufN;
    bzf->strm.next_in = bzf->buf;
    bzf->initialisedOk = (Bool)1;
    return ((BZFILE *)bzf);
  }
}
void BZ2_bzReadClose(int *bzerror, BZFILE *b) {
  bzFile *bzf;

  {
    bzf = (bzFile *)b;

    if (bzf->writing) {

      if ((unsigned long)bzf != (unsigned long)((void *)0)) {
        bzf->lastErr = -1;
      }
      return;
    }
    if (bzf->initialisedOk) {
      {
        BZ2_bzDecompressEnd(&bzf->strm);
      }
    }
    { free((void *)bzf); }
    return;
  }
}
int BZ2_bzRead(int *bzerror, BZFILE *b, void *buf, int len) {
  Int32 n;
  Int32 ret;
  bzFile *bzf;
  int tmp;
  int tmp___0;
  Bool tmp___1;
  Bool tmp___2;

  {
    bzf = (bzFile *)b;

    if ((unsigned long)bzf != (unsigned long)((void *)0)) {
      bzf->lastErr = 0;
    }
    if ((unsigned long)bzf == (unsigned long)((void *)0)) {
      goto _L;
    } else {
      if ((unsigned long)buf == (unsigned long)((void *)0)) {
        goto _L;
      } else {
        if (len < 0) {
        _L:
          if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
            *bzerror = -2;
          }
          if ((unsigned long)bzf != (unsigned long)((void *)0)) {
            bzf->lastErr = -2;
          }
          return (0);
        }
      }
    }
    if (bzf->writing) {

      if ((unsigned long)bzf != (unsigned long)((void *)0)) {
        bzf->lastErr = -1;
      }
      return (0);
    }
    if (len == 0) {
      if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
        *bzerror = 0;
      }

      return (0);
    }
    bzf->strm.avail_out = (unsigned int)len;
    bzf->strm.next_out = (char *)buf;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        { tmp = ferror(bzf->handle); }
        if (tmp) {
          if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
            *bzerror = -6;
          }
          if ((unsigned long)bzf != (unsigned long)((void *)0)) {
            bzf->lastErr = -6;
          }
          return (0);
        }
        if (bzf->strm.avail_in == 0U) {
          {
            tmp___1 = myfeof(bzf->handle);
          }
          if (!tmp___1) {
            {
              n = (Int32)fread((void * /* __restrict  */)(bzf->buf),
                               sizeof(UChar), (size_t)5000,
                               (FILE * /* __restrict  */)bzf->handle);
              tmp___0 = ferror(bzf->handle);
            }
            if (tmp___0) {
              if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
                *bzerror = -6;
              }

              return (0);
            }
            bzf->bufN = n;
            bzf->strm.avail_in = (unsigned int)bzf->bufN;
            bzf->strm.next_in = bzf->buf;
          }
        }
        { ret = BZ2_bzDecompress(&bzf->strm); }
        if (ret != 0) {
          if (ret != 4) {
            if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
              *bzerror = ret;
            }
            if ((unsigned long)bzf != (unsigned long)((void *)0)) {
              bzf->lastErr = ret;
            }
            return (0);
          }
        }
        if (ret == 0) {
          {
            tmp___2 = myfeof(bzf->handle);
          }
          if (tmp___2) {
            if (bzf->strm.avail_in == 0U) {
              if (bzf->strm.avail_out > 0U) {

                if ((unsigned long)bzf != (unsigned long)((void *)0)) {
                  bzf->lastErr = -7;
                }
                return (0);
              }
            }
          }
        }
        if (ret == 4) {
          if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
            *bzerror = 4;
          }
          if ((unsigned long)bzf != (unsigned long)((void *)0)) {
            bzf->lastErr = 4;
          }
          return ((int)((unsigned int)len - bzf->strm.avail_out));
        }
        if (bzf->strm.avail_out == 0U) {
          if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
            *bzerror = 0;
          }
          if ((unsigned long)bzf != (unsigned long)((void *)0)) {
            bzf->lastErr = 0;
          }
          return (len);
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return (0);
  }
}
void BZ2_bzReadGetUnused(int *bzerror, BZFILE *b, void **unused, int *nUnused) {
  bzFile *bzf;

  {
    bzf = (bzFile *)b;
    if ((unsigned long)bzf == (unsigned long)((void *)0)) {

      if ((unsigned long)bzf != (unsigned long)((void *)0)) {
        bzf->lastErr = -2;
      }
      return;
    }
    if (bzf->lastErr != 4) {

      if ((unsigned long)bzf != (unsigned long)((void *)0)) {
        bzf->lastErr = -1;
      }
      return;
    }

    if ((unsigned long)bzerror != (unsigned long)((void *)0)) {
      *bzerror = 0;
    }
    if ((unsigned long)bzf != (unsigned long)((void *)0)) {
      bzf->lastErr = 0;
    }
    *nUnused = (int)bzf->strm.avail_in;
    *unused = (void *)bzf->strm.next_in;
    return;
  }
}
char const *BZ2_bzlibVersion(void) {
  char *__cil_tmp1;

  { return ("1.0.5, 10-Dec-2007"); }
}
static char const *bzerrorstrings[16] = {"OK",           "SEQUENCE_ERROR",
                                         "PARAM_ERROR",  "MEM_ERROR",
                                         "DATA_ERROR",   "DATA_ERROR_MAGIC",
                                         "IO_ERROR",     "UNEXPECTED_EOF",
                                         "OUTBUFF_FULL", "CONFIG_ERROR",
                                         "???",          "???",
                                         "???",          "???",
                                         "???",          "???"};
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) remove)(
    char const *__filename);
extern void rewind(FILE *__stream);
extern void perror(char const *__s);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fileno)(
    FILE *__stream);
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1), __leaf__)) getenv)(char const *__name);
extern __attribute__((__nothrow__)) char *(__attribute__((
    __nonnull__(1, 2), __leaf__)) strcpy)(char *__restrict __dest,
                                          char const *__restrict __src);
extern __attribute__((__nothrow__)) char *(__attribute__((__nonnull__(1, 2),
                                                          __leaf__)) strncpy)(
    char *__restrict __dest, char const *__restrict __src, size_t __n);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2),
                                                       __leaf__)) strncmp)(
    char const *__s1, char const *__s2, size_t __n) __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(
    __attribute__((__nonnull__(1, 2), __leaf__)) strstr)(char const *__haystack,
                                                         char const *__needle)
    __attribute__((__pure__));
extern __attribute__((__nothrow__))
size_t(__attribute__((__nonnull__(1), __leaf__)) strlen)(char const *__s)
    __attribute__((__pure__));
extern __attribute__((__nothrow__)) char *(__attribute__((__leaf__)) strerror)(
    int __errnum);
extern __attribute__((__nothrow__))
__sighandler_t(__attribute__((__leaf__)) signal)(int __sig,
                                                 void (*__handler)(int));
extern __attribute__((__nothrow__)) int *(
    __attribute__((__leaf__)) __errno_location)(void)__attribute__((__const__));
extern int(__attribute__((__nonnull__(1))) open)(char const *__file,
                                                 int __oflag,
                                                 ...) __asm__("open64");
extern __attribute__((__nothrow__)) int(__attribute__((
    __nonnull__(1), __leaf__)) utime)(char const *__file,
                                      struct utimbuf const *__file_times);
extern int close(int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchown)(
    int __fd, __uid_t __owner, __gid_t __group);
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) isatty)(
    int __fd);
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2),
                                                       __leaf__)) stat)(
    char const *__restrict __file,
    struct stat *__restrict __buf) __asm__("stat64");
extern __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1, 2),
                                                       __leaf__)) lstat)(
    char const *__restrict __file,
    struct stat *__restrict __buf) __asm__("lstat64");
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__)) fchmod)(
    int __fd, __mode_t __mode);
Int32 verbosity;
Bool keepInputFiles;
Bool smallMode;
Bool deleteOutputOnInterrupt;
Bool forceOverwrite;
Bool testFailsExist;
Bool unzFailsExist;
Bool noisy;
Int32 numFileNames;
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
    return ((Bool)0);
  }
}

static Bool uncompressStream(FILE *zStream, FILE *stream) {
  BZFILE *bzf;
  Int32 bzerr;
  Int32 bzerr_dummy;
  Int32 ret;
  Int32 nread;
  Int32 streamNo;
  Int32 i;
  UChar obuf[5000];
  UChar unused[5000];
  Int32 nUnused;
  void *unusedTmpV;
  UChar *unusedTmp;
  int tmp;
  int tmp___0;
  int tmp___1;
  Bool tmp___2;
  int tmp___3;
  Int32 fd;
  Int32 tmp___4;
  int tmp___5;
  Bool tmp___6;
  int tmp___7;
  int tmp___8;
  void *__cil_tmp27;
  void *__cil_tmp28;
  char *__cil_tmp29;
  char *__cil_tmp30;
  char *__cil_tmp31;
  char *__cil_tmp32;

  {
    {
      bzf = (void *)0;
      nUnused = 0;
      streamNo = 0;
      tmp = ferror(stream);
    }
    if (tmp) {
      goto errhandler_io;
    }
    { tmp___0 = ferror(zStream); }
    if (tmp___0) {
      goto errhandler_io;
    }
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        {
          bzf = BZ2_bzReadOpen(&bzerr, zStream, verbosity, (int)smallMode,
                               (void *)(unused), nUnused);
        }
        if ((unsigned long)bzf == (unsigned long)((void *)0)) {
          goto errhandler;
        } else {
          if (bzerr != 0) {
            goto errhandler;
          }
        }
        streamNo++;
        {
          while (1) {
          while_continue___0: /* CIL Label */
              ;
            if (!(bzerr == 0)) {
              goto while_break___0;
            }
            { nread = BZ2_bzRead(&bzerr, bzf, (void *)(obuf), 5000); }
            if (bzerr == -5) {
              goto trycat;
            }
            if (bzerr == 0) {
              goto _L;
            } else {
              if (bzerr == 4) {
              _L:
                if (nread > 0) {
                  {
                    fwrite((void const * /* __restrict  */)(obuf),
                           sizeof(UChar), (size_t)nread,
                           (FILE * /* __restrict  */)stream);
                  }
                }
              }
            }
            { tmp___1 = ferror(stream); }
            if (tmp___1) {
              goto errhandler_io;
            }
          }
        while_break___0: /* CIL Label */
            ;
        }
        if (bzerr != 4) {
          goto errhandler;
        }
        { BZ2_bzReadGetUnused(&bzerr, bzf, &unusedTmpV, &nUnused); }
        if (bzerr != 0) {
          {
            panic("decompress:bzReadGetUnused");
          }
        }
        unusedTmp = (UChar *)unusedTmpV;
        i = 0;
        {

        while_break___1: /* CIL Label */
            ;
        }
        { BZ2_bzReadClose(&bzerr, bzf); }
        if (bzerr != 0) {
          {
            panic("decompress:bzReadGetUnused");
          }
        }
        if (nUnused == 0) {
          {
            tmp___2 = myfeof___0(zStream);
          }
          if (tmp___2) {
            goto while_break;
          }
        }
      }
    while_break: /* CIL Label */
        ;
    }
  closeok: { tmp___3 = ferror(zStream); }

    if ((unsigned long)stream != (unsigned long)stdout) {
      {
        tmp___4 = fileno(stream);
        fd = tmp___4;
      }

      { applySavedFileAttrToOutputFile(fd); }
    }
    { ret = fclose(zStream); }
    if (ret == -1) {
      goto errhandler_io;
    }
    { tmp___5 = ferror(stream); }
    if (tmp___5) {
      goto errhandler_io;
    }
    { ret = fflush(stream); }
    if (ret != 0) {
      goto errhandler_io;
    }
    if ((unsigned long)stream != (unsigned long)stdout) {
      {
        ret = fclose(stream);
        outputHandleJustInCase = (FILE *)((void *)0);
      }
      if (ret == -1) {
        goto errhandler_io;
      }
    }
    outputHandleJustInCase = (FILE *)((void *)0);

    return ((Bool)1);
  trycat:
    if (forceOverwrite) {
      {
        rewind(zStream);
      }
      {
        while (1) {
        while_continue___2: /* CIL Label */
            ;
          { tmp___6 = myfeof___0(zStream); }
          if (tmp___6) {
            goto while_break___2;
          }
          {
            nread =
                (Int32)fread((void * /* __restrict  */)(obuf), sizeof(UChar),
                             (size_t)5000, (FILE * /* __restrict  */)zStream);
            tmp___7 = ferror(zStream);
          }
          if (tmp___7) {
            goto errhandler_io;
          }
          if (nread > 0) {
            {
              fwrite((void const * /* __restrict  */)(obuf), sizeof(UChar),
                     (size_t)nread, (FILE * /* __restrict  */)stream);
            }
          }
          { tmp___8 = ferror(stream); }
          if (tmp___8) {
            goto errhandler_io;
          }
        }
      while_break___2: /* CIL Label */
          ;
      }
      goto closeok;
    }
  errhandler: { BZ2_bzReadClose(&bzerr_dummy, bzf); }
    {
      if (bzerr == -9) {
        goto case_neg_9;
      }

      if (bzerr == -4) {
        goto case_neg_4;
      }
      if (bzerr == -3) {
        goto case_neg_3;
      }

      goto switch_default;
    case_neg_9: { /* CIL Label */
      configError();
    }
      goto switch_break;
    errhandler_io:
    case_neg_6: { /* CIL Label */
      ioError();
    }
      goto switch_break;
    case_neg_4: { /* CIL Label */
      crcError();
    }
    case_neg_3: { /* CIL Label */
      outOfMemory();
    }
    case_neg_7: { /* CIL Label */
      compressedStreamEOF();
    }
    case_neg_5: /* CIL Label */
      if ((unsigned long)zStream != (unsigned long)stdin) {
        {
          fclose(zStream);
        }
      }
      if ((unsigned long)stream != (unsigned long)stdout) {
        {
          fclose(stream);
        }
      }
      if (streamNo == 1) {
        return ((Bool)0);
      } else {

        return ((Bool)1);
      }
    switch_default: { /* CIL Label */
      panic("decompress:unexpected error");
    }
    switch_break: /* CIL Label */
        ;
    }
    { panic("decompress:end"); }
    return ((Bool)1);
  }
}

static void setExit(Int32 v) {

  {
    if (v > exitValue) {
      exitValue = v;
    }
    return;
  }
}
static void cadvise(void) {

  {
    if (noisy) {
      {
      }
    }
    return;
  }
}
static void showFileNames(void) {

  { return; }
}
static __attribute__((__noreturn__)) void cleanUpAndFail(Int32 ec);
static void cleanUpAndFail(Int32 ec) {
  IntNative retVal;
  struct stat statBuf;
  void *__cil_tmp4;

  {

    {
      setExit(ec);
      exit(exitValue);
    }
  }
}
static __attribute__((__noreturn__)) void panic(Char const *s);
static void panic(Char const *s) {

  {
    {

      showFileNames();
      cleanUpAndFail(3);
    }
  }
}
static __attribute__((__noreturn__)) void crcError(void);
static void crcError(void) {

  {
    {
      fprintf((FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "\n%s: Data integrity error "
                                               "when decompressing.\n",
              progName);
      showFileNames();
      cadvise();
      cleanUpAndFail(2);
    }
  }
}
static __attribute__((__noreturn__)) void compressedStreamEOF(void);

static __attribute__((__noreturn__)) void ioError(void);
static void ioError(void) {

  {
    {
      fprintf(
          (FILE * /* __restrict  */)stderr,
          (char const * /* __restrict  */) "\n%s: I/O or other error, bailing "
                                           "out.  Possible reason follows.\n",
          progName);
      perror((char const *)progName);
      showFileNames();
      cleanUpAndFail(1);
    }
  }
}
static void mySignalCatcher(IntNative n) {

  {
    {
      fprintf((FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "\n%s: Control-C or similar "
                                               "caught, quitting.\n",
              progName);
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
        cleanUpAndFail(3);
      }
    } else {
      {
        cadvise();
        cleanUpAndFail(2);
      }
    }
  }
}
static __attribute__((__noreturn__)) void outOfMemory(void);
static void outOfMemory(void) {

  {
    {
      fprintf(
          (FILE * /* __restrict  */)stderr,
          (char const
               * /* __restrict  */) "\n%s: couldn\'t allocate enough memory\n",
          progName);
      showFileNames();
      cleanUpAndFail(1);
    }
  }
}
static __attribute__((__noreturn__)) void configError(void);
static void configError(void) {

  {
    {

      setExit(3);
      exit(exitValue);
    }
  }
}

static void copyFileName(Char *to, Char *from) {
  size_t tmp;

  {
    { tmp = strlen((char const *)from); }

    {
      strncpy((char * /* __restrict  */)to,
              (char const * /* __restrict  */)from, (size_t)1024);
      *(to + 1024) = (Char)'\000';
    }
    return;
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
        fclose(tmp);
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
        close(fh);
      }
    }
    return (fp);
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
    return;
  }
}
static void applySavedTimeInfoToOutputFile(Char *dstName) {
  IntNative retVal;
  struct utimbuf uTimBuf;

  {
    {
      uTimBuf.actime = fileMetaInfo.st_atim.tv_sec;
      uTimBuf.modtime = fileMetaInfo.st_mtim.tv_sec;
      retVal = utime((char const *)dstName, (struct utimbuf const *)(&uTimBuf));
    }
    if (retVal != 0) {
      {
        ioError();
      }
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
        ioError();
      }
    }
    { fchown(fd, fileMetaInfo.st_uid, fileMetaInfo.st_gid); }
    return;
  }
}
static Bool containsDubiousChars(Char *name) {

  { return ((Bool)0); }
}
Char const *zSuffix[4] = {".bz2", ".bz", ".tbz2", ".tbz"};
Char const *unzSuffix[4] = {"", "", ".tar", ".tar"};
static Bool hasSuffix(Char *s, Char const *suffix) {
  Int32 ns;
  Int32 tmp;
  Int32 nx;
  Int32 tmp___0;
  int tmp___1;

  {
    {
      tmp = (Int32)strlen((char const *)s);
      ns = tmp;
      tmp___0 = (Int32)strlen(suffix);
      nx = tmp___0;
    }

    { tmp___1 = strcmp((char const *)((s + ns) - nx), suffix); }
    if (tmp___1 == 0) {
      return ((Bool)1);
    }
    return ((Bool)0);
  }
}
static Bool mapSuffix(Char *name, Char const *oldSuffix,
                      Char const *newSuffix) {
  Bool tmp;
  size_t tmp___0;
  size_t tmp___1;

  {
    { tmp = hasSuffix(name, oldSuffix); }
    if (!tmp) {
      return ((Bool)0);
    }
    {
      tmp___0 = strlen((char const *)name);
      tmp___1 = strlen(oldSuffix);
      *(name + (tmp___0 - tmp___1)) = (Char)0;
      strcat((char * /* __restrict  */)name,
             (char const * /* __restrict  */)newSuffix);
    }
    return ((Bool)1);
  }
}

static void uncompress(Char *name) {
  FILE *inStr;
  FILE *outStr;
  Int32 n;
  Int32 i;
  Bool magicNumberOK;
  Bool cantGuess;
  struct stat statBuf;
  Bool tmp;
  Bool tmp___0;
  int *tmp___1;
  char *tmp___2;
  Bool tmp___3;
  Bool tmp___4;
  Bool tmp___5;
  char const *tmp___6;
  int tmp___7;
  int tmp___8;
  int *tmp___9;
  char *tmp___10;
  int *tmp___11;
  char *tmp___12;
  int *tmp___13;
  char *tmp___14;
  IntNative retVal;
  IntNative tmp___15;
  IntNative retVal___0;
  IntNative tmp___16;
  void *__cil_tmp29;
  char *__cil_tmp30;
  char *__cil_tmp31;
  char *__cil_tmp32;
  char *__cil_tmp33;
  char *__cil_tmp34;
  char *__cil_tmp35;
  char *__cil_tmp36;
  char *__cil_tmp37;
  char *__cil_tmp38;

  {
    deleteOutputOnInterrupt = (Bool)0;
    if ((unsigned long)name == (unsigned long)((void *)0)) {
    }
    cantGuess = (Bool)0;
    {
      if (srcMode == 1) {
        goto case_1;
      }
      if (srcMode == 3) {
        goto case_3;
      }
      if (srcMode == 2) {
        goto case_2;
      }
      goto switch_break;
    case_1: { /* CIL Label */
      copyFileName(inName, (Char *)"(stdin)");
      copyFileName(outName, (Char *)"(stdout)");
    }
      goto switch_break;
    case_3: { /* CIL Label */
      copyFileName(inName, name);
      copyFileName(outName, name);
      i = 0;
    }
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if (!(i < 4)) {
            goto while_break;
          }
          { tmp = mapSuffix(outName, zSuffix[i], unzSuffix[i]); }
          if (tmp) {
            goto zzz;
          }
          i++;
        }
      while_break: /* CIL Label */
          ;
      }
      {
        cantGuess = (Bool)1;
        strcat((char * /* __restrict  */)(outName),
               (char const * /* __restrict  */) ".out");
      }
      goto switch_break;
    case_2: { /* CIL Label */
      copyFileName(inName, name);
      copyFileName(outName, (Char *)"(stdout)");
    }
      goto switch_break;
    switch_break: /* CIL Label */
        ;
    }
  zzz:
    if (srcMode != 1) {
      {
        tmp___0 = containsDubiousChars(inName);
      }
    }
    if (srcMode != 1) {
      {
        tmp___3 = fileExists(inName);
      }
      if (!tmp___3) {
        {
          tmp___1 = __errno_location();
          tmp___2 = strerror(*tmp___1);
          fprintf(
              (FILE * /* __restrict  */)stderr,
              (char const
                   * /* __restrict  */) "%s: Can\'t open input file %s: %s.\n",
              progName, inName, tmp___2);
          setExit(1);
        }
        return;
      }
    }
    if (srcMode == 3) {
      goto _L;
    } else {
      if (srcMode == 2) {
      _L: {
        stat((char const * /* __restrict  */)(inName),
             (struct stat * /* __restrict  */)(&statBuf));
      }
        if ((statBuf.st_mode & 61440U) == 16384U) {
          {
            fprintf(
                (FILE * /* __restrict  */)stderr,
                (char const
                     * /* __restrict  */) "%s: Input file %s is a directory.\n",
                progName, inName);
            setExit(1);
          }
          return;
        }
      }
    }

    if (srcMode == 3) {
      {
        tmp___5 = fileExists(outName);
      }
      if (tmp___5) {
      }
    }

    if (srcMode == 3) {
      {
        saveInputFileMetaInfo(inName);
      }
    }
    {

      if (srcMode == 2) {
        goto case_2___0;
      }
      if (srcMode == 3) {
        goto case_3___0;
      }
      goto switch_default;
    case_1___0: { /* CIL Label */
      inStr = stdin;
      outStr = stdout;
      tmp___7 = fileno(stdin);
      tmp___8 = isatty(tmp___7);
    }
      if (tmp___8) {
        {
          fprintf(
              (FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "%s: I won\'t read compressed "
                                               "data from a terminal.\n",
              progName);
          fprintf(
              (FILE * /* __restrict  */)stderr,
              (char const
                   * /* __restrict  */) "%s: For help, type: `%s --help\'.\n",
              progName, progName);
          setExit(1);
        }
        return;
      }
      goto switch_break___0;
    case_2___0: { /* CIL Label */
      inStr = fopen((char const * /* __restrict  */)(inName),
                    (char const * /* __restrict  */) "rb");
      outStr = stdout;
    }
      if ((unsigned long)inStr == (unsigned long)((void *)0)) {
        {
          tmp___9 = __errno_location();
          tmp___10 = strerror(*tmp___9);
          fprintf(
              (FILE * /* __restrict  */)stderr,
              (char const
                   * /* __restrict  */) "%s: Can\'t open input file %s:%s.\n",
              progName, inName, tmp___10);
        }
        if ((unsigned long)inStr != (unsigned long)((void *)0)) {
          {
            fclose(inStr);
          }
        }
        { setExit(1); }
        return;
      }
      goto switch_break___0;
    case_3___0: { /* CIL Label */
      inStr = fopen((char const * /* __restrict  */)(inName),
                    (char const * /* __restrict  */) "rb");
      outStr = fopen_output_safely(outName, "wb");
    }
      if ((unsigned long)outStr == (unsigned long)((void *)0)) {
        {
          tmp___11 = __errno_location();
          tmp___12 = strerror(*tmp___11);
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const * /* __restrict  */) "%s: Can\'t create output "
                                                   "file %s: %s.\n",
                  progName, outName, tmp___12);
        }
        if ((unsigned long)inStr != (unsigned long)((void *)0)) {
          {
            fclose(inStr);
          }
        }
        { setExit(1); }
        return;
      }
      if ((unsigned long)inStr == (unsigned long)((void *)0)) {
        {
          tmp___13 = __errno_location();
          tmp___14 = strerror(*tmp___13);
          fprintf(
              (FILE * /* __restrict  */)stderr,
              (char const
                   * /* __restrict  */) "%s: Can\'t open input file %s: %s.\n",
              progName, inName, tmp___14);
        }
        if ((unsigned long)outStr != (unsigned long)((void *)0)) {
          {
            fclose(outStr);
          }
        }
        { setExit(1); }
        return;
      }
      goto switch_break___0;
    switch_default: { /* CIL Label */
      panic("uncompress: bad srcMode");
    }
      goto switch_break___0;
    switch_break___0: /* CIL Label */
        ;
    }

    {
      outputHandleJustInCase = outStr;
      deleteOutputOnInterrupt = (Bool)1;
      magicNumberOK = uncompressStream(inStr, outStr);
      outputHandleJustInCase = (FILE *)((void *)0);
    }
    if (magicNumberOK) {
      if (srcMode == 3) {
        {
          applySavedTimeInfoToOutputFile(outName);
          deleteOutputOnInterrupt = (Bool)0;
        }
        if (!keepInputFiles) {
          {
            tmp___15 = remove((char const *)(inName));
            retVal = tmp___15;
          }
          if (retVal != 0) {
            {
              ioError();
            }
          }
        }
      }
    } else {
      unzFailsExist = (Bool)1;
      deleteOutputOnInterrupt = (Bool)0;
      if (srcMode == 3) {
        {
          tmp___16 = remove((char const *)(outName));
          retVal___0 = tmp___16;
        }
      }
    }
    deleteOutputOnInterrupt = (Bool)0;
    if (magicNumberOK) {

    } else {
      { setExit(2); }
      if (verbosity >= 1) {
        {
          fprintf((FILE * /* __restrict  */)stderr,
                  (char const * /* __restrict  */) "not a bzip2 file.\n");
        }
      } else {
        {
          fprintf(
              (FILE * /* __restrict  */)stderr,
              (char const * /* __restrict  */) "%s: %s is not a bzip2 file.\n",
              progName, inName);
        }
      }
    }
    return;
  }
}

static void usage(Char *fullProgName) {
  char const *tmp;

  {
    { tmp = BZ2_bzlibVersion(); }
    return;
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
        tmp___1 = strlen((char const *)name);
        tmp->name = (Char *)myMalloc((Int32)(5UL + tmp___1));
        strcpy((char * /* __restrict  */)tmp->name,
               (char const * /* __restrict  */)name);
      }
      return (tmp);
    } else {
      tmp___3 = root;
      {
        while (1) {
        while_continue: /* CIL Label */
            ;
          if (!((unsigned long)tmp___3->link != (unsigned long)((void *)0))) {
            goto while_break;
          }
          tmp___3 = tmp___3->link;
        }
      while_break: /* CIL Label */
          ;
      }
      { tmp___3->link = snocString(tmp___3->link, name); }
      return (root);
    }
  }
}
static void addFlagsFromEnvVar(Cell **argList, Char *varName) {
  Int32 i;
  Int32 j;
  Int32 k;
  Char *envbase;
  Char *p;
  unsigned short const **tmp;
  unsigned short const **tmp___0;

  {
    { envbase = getenv((char const *)varName); }

    return;
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
  char *__cil_tmp42;
  char *__cil_tmp43;
  char *__cil_tmp44;
  char *__cil_tmp45;

  {
    if (sizeof(Int32) != 4UL) {
      {
        configError();
      }
    } else {
    }
    {
      outputHandleJustInCase = (FILE *)((void *)0);
      smallMode = (Bool)0;
      keepInputFiles = (Bool)0;
      forceOverwrite = (Bool)0;
      noisy = (Bool)1;
      verbosity = 0;
      blockSize100k = 9;
      testFailsExist = (Bool)0;
      unzFailsExist = (Bool)0;
      numFileNames = 0;
      numFilesProcessed = 0;
      workFactor = 30;
      deleteOutputOnInterrupt = (Bool)0;
      exitValue = 0;
      j = 0;
      i = j;
      signal(11, &mySIGSEGVorSIGBUScatcher);
      signal(7, &mySIGSEGVorSIGBUScatcher);
      copyFileName(inName, (Char *)"(none)");
      copyFileName(outName, (Char *)"(none)");
      copyFileName(progNameReally, *(argv + 0));
      progName = &progNameReally[0];
      tmp = &progNameReally[0];
    }
    {

    while_break: /* CIL Label */
        ;
    }
    {
      argList = (Cell *)((void *)0);
      addFlagsFromEnvVar(&argList, (Char *)"BZIP2");
      addFlagsFromEnvVar(&argList, (Char *)"BZIP");
      i = 1;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
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
    longestFileName = 7;
    numFileNames = 0;
    decode = (Bool)1;
    aa = argList;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!((unsigned long)aa != (unsigned long)((void *)0))) {
          goto while_break___1;
        }
        { tmp___0 = strcmp((char const *)aa->name, "--"); }

        if ((int)*(aa->name + 0) == 45) {
          if (decode) {
            goto __Cont;
          }
        }
        {
          numFileNames++;
          tmp___2 = strlen((char const *)aa->name);
        }

      __Cont:
        aa = aa->link;
      }
    while_break___1: /* CIL Label */
        ;
    }
    if (numFileNames == 0) {
      srcMode = 1;
    } else {
      srcMode = 3;
    }
    {
      opMode = 1;
      tmp___3 = strstr((char const *)progName, "unzip");
    }

    { tmp___5 = strstr((char const *)progName, "z2cat"); }
    if ((unsigned long)tmp___5 != (unsigned long)((char *)0)) {
      goto _L;
    } else {
      { tmp___6 = strstr((char const *)progName, "Z2CAT"); }
      if ((unsigned long)tmp___6 != (unsigned long)((char *)0)) {
        goto _L;
      } else {
        { tmp___7 = strstr((char const *)progName, "zcat"); }
        if ((unsigned long)tmp___7 != (unsigned long)((char *)0)) {
          goto _L;
        } else {
          { tmp___8 = strstr((char const *)progName, "ZCAT"); }
          if ((unsigned long)tmp___8 != (unsigned long)((char *)0)) {
          _L:
            opMode = 2;
            if (numFileNames == 0) {
              srcMode = 1;
            } else {
              srcMode = 2;
            }
          }
        }
      }
    }
    aa = argList;
    {
      while (1) {
      while_continue___2: /* CIL Label */
          ;
        if (!((unsigned long)aa != (unsigned long)((void *)0))) {
          goto while_break___2;
        }
        { tmp___9 = strcmp((char const *)aa->name, "--"); }
        if (tmp___9 == 0) {
          goto while_break___2;
        }
        if ((int)*(aa->name + 0) == 45) {
          if ((int)*(aa->name + 1) != 45) {
            j = 1;
            {
              while (1) {
              while_continue___3: /* CIL Label */
                  ;
                if (!((int)*(aa->name + j) != 0)) {
                  goto while_break___3;
                }
                {

                  if ((int)*(aa->name + j) == 100) {
                    goto case_100;
                  }

                  goto switch_default;
                case_99: /* CIL Label */
                  srcMode = 2;
                  goto switch_break;
                case_100: /* CIL Label */
                  opMode = 2;
                  goto switch_break;
                case_122: /* CIL Label */
                  opMode = 1;
                  goto switch_break;
                case_102: /* CIL Label */
                  forceOverwrite = (Bool)1;
                  goto switch_break;
                case_116: /* CIL Label */
                  opMode = 3;
                  goto switch_break;
                case_107: /* CIL Label */
                  keepInputFiles = (Bool)1;
                  goto switch_break;
                case_115: /* CIL Label */
                  smallMode = (Bool)1;
                  goto switch_break;
                case_113: /* CIL Label */
                  noisy = (Bool)0;
                  goto switch_break;
                case_49: /* CIL Label */
                  blockSize100k = 1;
                  goto switch_break;
                case_50: /* CIL Label */
                  blockSize100k = 2;
                  goto switch_break;
                case_51: /* CIL Label */
                  blockSize100k = 3;
                  goto switch_break;
                case_52: /* CIL Label */
                  blockSize100k = 4;
                  goto switch_break;
                case_53: /* CIL Label */
                  blockSize100k = 5;
                  goto switch_break;
                case_54: /* CIL Label */
                  blockSize100k = 6;
                  goto switch_break;
                case_55: /* CIL Label */
                  blockSize100k = 7;
                  goto switch_break;
                case_56: /* CIL Label */
                  blockSize100k = 8;
                  goto switch_break;
                case_57: /* CIL Label */
                  blockSize100k = 9;
                  goto switch_break;
                case_86:   /* CIL Label */
                case_76: { /* CIL Label */
                  license();
                }
                  goto switch_break;
                case_118: /* CIL Label */
                  verbosity++;
                  goto switch_break;
                case_104: { /* CIL Label */
                  usage(progName);
                  exit(0);
                }
                  goto switch_break;
                switch_default: { /* CIL Label */
                  fprintf(
                      (FILE * /* __restrict  */)stderr,
                      (char const * /* __restrict  */) "%s: Bad flag `%s\'\n",
                      progName, aa->name);
                  usage(progName);
                  exit(1);
                }
                  goto switch_break;
                switch_break: /* CIL Label */
                    ;
                }
                j++;
              }
            while_break___3: /* CIL Label */
                ;
            }
          }
        }
        aa = aa->link;
      }
    while_break___2: /* CIL Label */
        ;
    }
    aa = argList;
    {
      while (1) {
      while_continue___4: /* CIL Label */
          ;
        if (!((unsigned long)aa != (unsigned long)((void *)0))) {
          goto while_break___4;
        }
        { tmp___10 = strcmp((char const *)aa->name, "--"); }
        if (tmp___10 == 0) {
          goto while_break___4;
        }
        { tmp___28 = strcmp((char const *)aa->name, "--stdout"); }
        if (tmp___28 == 0) {
          srcMode = 2;
        } else {
          { tmp___27 = strcmp((char const *)aa->name, "--decompress"); }
          if (tmp___27 == 0) {
            opMode = 2;
          } else {
            { tmp___26 = strcmp((char const *)aa->name, "--compress"); }
            if (tmp___26 == 0) {
              opMode = 1;
            } else {
              { tmp___25 = strcmp((char const *)aa->name, "--force"); }
              if (tmp___25 == 0) {
                forceOverwrite = (Bool)1;
              } else {
                { tmp___24 = strcmp((char const *)aa->name, "--test"); }
              }
            }
          }
        }
        aa = aa->link;
      }
    while_break___4: /* CIL Label */
        ;
    }

    if (opMode == 3) {
    }
    if (srcMode == 2) {
      if (numFileNames == 0) {
        srcMode = 1;
      }
    }

    if (srcMode == 3) {
      {
        signal(2, &mySignalCatcher);
        signal(15, &mySignalCatcher);
        signal(1, &mySignalCatcher);
      }
    }
    if (opMode == 1) {

    } else {
      if (opMode == 2) {
        unzFailsExist = (Bool)0;
        if (srcMode == 1) {
          {
            uncompress((Char *)((void *)0));
          }
        } else {
          decode = (Bool)1;
          aa = argList;
          {
            while (1) {
            while_continue___6: /* CIL Label */
                ;
              if (!((unsigned long)aa != (unsigned long)((void *)0))) {
                goto while_break___6;
              }
              { tmp___30 = strcmp((char const *)aa->name, "--"); }
              if (tmp___30 == 0) {
                decode = (Bool)0;
                goto __Cont___1;
              }
              if ((int)*(aa->name + 0) == 45) {
                if (decode) {
                  goto __Cont___1;
                }
              }
              {
                numFilesProcessed++;
                uncompress(aa->name);
              }
            __Cont___1:
              aa = aa->link;
            }
          while_break___6: /* CIL Label */
              ;
          }
        }
        if (unzFailsExist) {
          {
            setExit(2);
            exit(exitValue);
          }
        }
      } else {
        testFailsExist = (Bool)0;
      }
    }
    aa = argList;
    {

    while_break___8: /* CIL Label */
        ;
    }
    return (exitValue);
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
  void *__cil_tmp19;
  void *__cil_tmp20;

  {
    eclass8 = (UChar *)eclass;

    i = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(i < 257)) {
          goto while_break;
        }
        ftab[i] = 0;
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
    i = 0;
    {

    while_break___0: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
      while_continue___1: /* CIL Label */
          ;
        if (!(i < 256)) {
          goto while_break___1;
        }
        ftabCopy[i] = ftab[i];
        i++;
      }
    while_break___1: /* CIL Label */
        ;
    }
    i = 1;
    {

    while_break___2: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
      while_continue___3: /* CIL Label */
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
    while_break___3: /* CIL Label */
        ;
    }
    nBhtab = 2 + nblock / 32;
    i = 0;
    {
      while (1) {
      while_continue___4: /* CIL Label */
          ;
        if (!(i < nBhtab)) {
          goto while_break___4;
        }
        *(bhtab + i) = (UInt32)0;
        i++;
      }
    while_break___4: /* CIL Label */
        ;
    }
    i = 0;
    {

    while_break___5: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
      while_continue___6: /* CIL Label */
          ;
        if (!(i < 32)) {
          goto while_break___6;
        }
        *(bhtab + ((nblock + 2 * i) >> 5)) |=
            (unsigned int)(1 << ((nblock + 2 * i) & 31));
        *(bhtab + (((nblock + 2 * i) + 1) >> 5)) &=
            (unsigned int)(~(1 << (((nblock + 2 * i) + 1) & 31)));
        i++;
      }
    while_break___6: /* CIL Label */
        ;
    }
    H = 1;
    {
      while (1) {
      while_continue___7: /* CIL Label */
          ;

        j = 0;
        i = 0;
        {
          while (1) {
          while_continue___8: /* CIL Label */
              ;
            if (!(i < nblock)) {
              goto while_break___8;
            }

            k = (Int32)(*(fmap + i) - (UInt32)H);
            if (k < 0) {
              k += nblock;
            }
            *(eclass + k) = (UInt32)j;
            i++;
          }
        while_break___8: /* CIL Label */
            ;
        }
        nNotDone = 0;
        r = -1;
        {
          while (1) {
          while_continue___9: /* CIL Label */
              ;
            k = r + 1;
            {
              while (1) {
              while_continue___10: /* CIL Label */
                  ;

                k++;
              }
            while_break___10: /* CIL Label */
                ;
            }
            if (*(bhtab + (k >> 5)) & (unsigned int)(1 << (k & 31))) {
              {
                while (1) {
                while_continue___11: /* CIL Label */
                    ;
                  if (!(*(bhtab + (k >> 5)) == 4294967295U)) {
                    goto while_break___11;
                  }
                  k += 32;
                }
              while_break___11: /* CIL Label */
                  ;
              }
              {

              while_break___12: /* CIL Label */
                  ;
              }
            }
            l = k - 1;
            if (l >= nblock) {
              goto while_break___9;
            }
            {
              while (1) {
              while_continue___13: /* CIL Label */
                  ;

                k++;
              }
            while_break___13: /* CIL Label */
                ;
            }

            r = k - 1;
            if (r >= nblock) {
              goto while_break___9;
            }
            if (r > l) {
              {
                nNotDone += (r - l) + 1;
                fallbackQSort3(fmap, eclass, l, r);
                cc = -1;
                i = l;
              }
              {
                while (1) {
                while_continue___16: /* CIL Label */
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
              while_break___16: /* CIL Label */
                  ;
              }
            }
          }
        while_break___9: /* CIL Label */
            ;
        }

        H *= 2;
        if (H > nblock) {
          goto while_break___7;
        } else {
          if (nNotDone == 0) {
            goto while_break___7;
          }
        }
      }
    while_break___7: /* CIL Label */
        ;
    }
    if (verb >= 4) {
      {
        fprintf((FILE * /* __restrict  */)stderr,
                (char const
                     * /* __restrict  */) "        reconstructing block ...\n");
      }
    }
    j = 0;
    i = 0;
    {
      while (1) {
      while_continue___17: /* CIL Label */
          ;
        if (!(i < nblock)) {
          goto while_break___17;
        }
        {
          while (1) {
          while_continue___18: /* CIL Label */
              ;
            if (!(ftabCopy[j] == 0)) {
              goto while_break___18;
            }
            j++;
          }
        while_break___18: /* CIL Label */
            ;
        }
        (ftabCopy[j])--;
        *(eclass8 + *(fmap + i)) = (UChar)j;
        i++;
      }
    while_break___17: /* CIL Label */
        ;
    }
    if (!(j < 256)) {
      {
        BZ2_bz__AssertH__fail(1005);
      }
    }
    return;
  }
}
__inline static Bool mainGtU(UInt32 i1, UInt32 i2, UChar *block,
                             UInt16 *quadrant, UInt32 nblock, Int32 *budget) {
  Int32 k;
  UChar c1;
  UChar c2;
  UInt16 s1;
  UInt16 s2;

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
    k = (Int32)(nblock + 8U);
    {
      while (1) {
      while_continue: /* CIL Label */
          ;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2) {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2) {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2) {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2) {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2) {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2) {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);
        if ((int)s1 != (int)s2) {
          return ((Bool)((int)s1 > (int)s2));
        }
        i1++;
        i2++;
        c1 = *(block + i1);
        c2 = *(block + i2);
        if ((int)c1 != (int)c2) {
          return ((Bool)((int)c1 > (int)c2));
        }
        s1 = *(quadrant + i1);
        s2 = *(quadrant + i2);

        i1++;
        i2++;
        if (i1 >= nblock) {
          i1 -= nblock;
        }
        if (i2 >= nblock) {
          i2 -= nblock;
        }
        k -= 8;
        (*budget)--;
        if (!(k >= 0)) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
        ;
    }
    return ((Bool)0);
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
      while (1) {
      while_continue: /* CIL Label */
          ;
        if (!(incs[hp] < bigN)) {
          goto while_break;
        }
        hp++;
      }
    while_break: /* CIL Label */
        ;
    }
    hp--;
    {
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(hp >= 0)) {
          goto while_break___0;
        }
        h = incs[hp];
        i = lo + h;
        {
          while (1) {
          while_continue___1: /* CIL Label */
              ;
            if (!(!(i > hi))) {
              goto while_break___1;
            }
            v = *(ptr + i);
            j = i;
            {
              while (1) {
              while_continue___2: /* CIL Label */
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
            if (i > hi) {
              goto while_break___1;
            }
            v = *(ptr + i);
            j = i;
            {
              while (1) {
              while_continue___3: /* CIL Label */
                  ;
                {
                  tmp___0 = mainGtU(*(ptr + (j - h)) + (UInt32)d, v + (UInt32)d,
                                    block, quadrant, (UInt32)nblock, budget);
                }
                if (!tmp___0) {
                  goto while_break___3;
                }
                *(ptr + j) = *(ptr + (j - h));
                j -= h;
                if (j <= (lo + h) - 1) {
                  goto while_break___3;
                }
              }
            while_break___3: /* CIL Label */
                ;
            }
            *(ptr + j) = v;
            i++;
            if (i > hi) {
              goto while_break___1;
            }
            v = *(ptr + i);
            j = i;
            {
              while (1) {
              while_continue___4: /* CIL Label */
                  ;
                {
                  tmp___1 = mainGtU(*(ptr + (j - h)) + (UInt32)d, v + (UInt32)d,
                                    block, quadrant, (UInt32)nblock, budget);
                }
                if (!tmp___1) {
                  goto while_break___4;
                }
                *(ptr + j) = *(ptr + (j - h));
                j -= h;
                if (j <= (lo + h) - 1) {
                  goto while_break___4;
                }
              }
            while_break___4: /* CIL Label */
                ;
            }
            *(ptr + j) = v;
            i++;
            if (*budget < 0) {
              return;
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
    return;
  }
}
__inline static UChar mmed3(UChar a, UChar b, UChar c) {
  UChar t;

  {
    if ((int)a > (int)b) {
      t = a;
      a = b;
      b = t;
    }
    if ((int)b > (int)c) {
      b = c;
      if ((int)a > (int)b) {
        b = a;
      }
    }
    return (b);
  }
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
  Int32 tz;
  Int32 tz___0;
  Int32 tz___1;
  void *__cil_tmp41;
  void *__cil_tmp42;
  void *__cil_tmp43;
  void *__cil_tmp44;
  void *__cil_tmp45;
  void *__cil_tmp46;

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
        if (!(sp < 98)) {
          {
            BZ2_bz__AssertH__fail(1001);
          }
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
            if (*budget < 0) {
              return;
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
          while_continue___0: /* CIL Label */
              ;
            {
              while (1) {
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
              }
            while_break___1: /* CIL Label */
                ;
            }
            {
              while (1) {
              while_continue___2: /* CIL Label */
                  ;
                if (!(!(unLo > unHi))) {
                  goto while_break___2;
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
              }
            while_break___2: /* CIL Label */
                ;
            }
            if (unLo > unHi) {
              goto while_break___0;
            }
            zztmp___1 = (Int32) * (ptr + unLo);
            *(ptr + unLo) = *(ptr + unHi);
            *(ptr + unHi) = (UInt32)zztmp___1;
            unLo++;
            unHi--;
          }
        while_break___0: /* CIL Label */
            ;
        }
        if (gtHi < ltLo) {
          stackLo[sp] = lo;
          stackHi[sp] = hi;
          stackD[sp] = d + 1;
          sp++;
          goto while_continue;
        }
        if (ltLo - lo < unLo - ltLo) {
          n = ltLo - lo;
        } else {
          n = unLo - ltLo;
        }
        yyp1 = lo;
        yyp2 = unLo - n;
        yyn = n;
        {
          while (1) {
          while_continue___3: /* CIL Label */
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

        while_break___4: /* CIL Label */
            ;
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
        if (nextHi[0] - nextLo[0] < nextHi[1] - nextLo[1]) {
          tz = nextLo[0];
          nextLo[0] = nextLo[1];
          nextLo[1] = tz;
          tz = nextHi[0];
          nextHi[0] = nextHi[1];
          nextHi[1] = tz;
          tz = nextD[0];
          nextD[0] = nextD[1];
          nextD[1] = tz;
        }

        if (nextHi[0] - nextLo[0] < nextHi[1] - nextLo[1]) {
          tz___1 = nextLo[0];
          nextLo[0] = nextLo[1];
          nextLo[1] = tz___1;
          tz___1 = nextHi[0];
          nextHi[0] = nextHi[1];
          nextHi[1] = tz___1;
          tz___1 = nextD[0];
          nextD[0] = nextD[1];
          nextD[1] = tz___1;
        }
        stackLo[sp] = nextLo[0];
        stackHi[sp] = nextHi[0];
        stackD[sp] = nextD[0];
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
    return;
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
  Int32 tmp;
  Int32 tmp___0;
  Int32 bbStart;
  Int32 bbSize;
  Int32 shifts;
  Int32 a2update;
  UInt16 qVal;
  void *__cil_tmp31;
  void *__cil_tmp32;
  void *__cil_tmp33;
  void *__cil_tmp34;

  {

    i = 65536;
    {
      while (1) {
      while_continue: /* CIL Label */
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
      while (1) {
      while_continue___0: /* CIL Label */
          ;
        if (!(i >= 3)) {
          goto while_break___0;
        }
        *(quadrant + i) = (UInt16)0;
        j = (j >> 8) | ((int)((UInt16) * (block + i)) << 8);
        (*(ftab + j))++;
        *(quadrant + (i - 1)) = (UInt16)0;
        j = (j >> 8) | ((int)((UInt16) * (block + (i - 1))) << 8);
        (*(ftab + j))++;
        *(quadrant + (i - 2)) = (UInt16)0;
        j = (j >> 8) | ((int)((UInt16) * (block + (i - 2))) << 8);
        (*(ftab + j))++;
        *(quadrant + (i - 3)) = (UInt16)0;
        j = (j >> 8) | ((int)((UInt16) * (block + (i - 3))) << 8);
        (*(ftab + j))++;
        i -= 4;
      }
    while_break___0: /* CIL Label */
        ;
    }
    {

    while_break___1: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
      while_continue___2: /* CIL Label */
          ;
        if (!(i < 34)) {
          goto while_break___2;
        }
        *(block + (nblock + i)) = *(block + i);
        *(quadrant + (nblock + i)) = (UInt16)0;
        i++;
      }
    while_break___2: /* CIL Label */
        ;
    }
    if (verb >= 4) {
      {
        fprintf(
            (FILE * /* __restrict  */)stderr,
            (char const * /* __restrict  */) "        bucket sorting ...\n");
      }
    }
    i = 1;
    {
      while (1) {
      while_continue___3: /* CIL Label */
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
      while_continue___4: /* CIL Label */
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
      while (1) {
      while_continue___5: /* CIL Label */
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
    i = 0;
    {
      while (1) {
      while_continue___6: /* CIL Label */
          ;
        if (!(i <= 255)) {
          goto while_break___6;
        }
        bigDone[i] = (Bool)0;
        runningOrder[i] = i;
        i++;
      }
    while_break___6: /* CIL Label */
        ;
    }
    h = 1;
    {
      while (1) {
      while_continue___7: /* CIL Label */
          ;
        h = 3 * h + 1;
        if (!(h <= 256)) {
          goto while_break___7;
        }
      }
    while_break___7: /* CIL Label */
        ;
    }
    {
      while (1) {
      while_continue___8: /* CIL Label */
          ;
        h /= 3;
        i = h;
        {
          while (1) {
          while_continue___9: /* CIL Label */
              ;
            if (!(i <= 255)) {
              goto while_break___9;
            }
            vv = runningOrder[i];
            j = i;
            {
              while (1) {
              while_continue___10: /* CIL Label */
                  ;
                if (!(*(ftab + ((runningOrder[j - h] + 1) << 8)) -
                          *(ftab + (runningOrder[j - h] << 8)) >
                      *(ftab + ((vv + 1) << 8)) - *(ftab + (vv << 8)))) {
                  goto while_break___10;
                }
                runningOrder[j] = runningOrder[j - h];
                j -= h;
                if (j <= h - 1) {
                  goto zero;
                }
              }
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
    numQSorted = 0;
    i = 0;
    {
      while (1) {
      while_continue___11: /* CIL Label */
          ;
        if (!(i <= 255)) {
          goto while_break___11;
        }
        ss = runningOrder[i];
        j = 0;
        {
          while (1) {
          while_continue___12: /* CIL Label */
              ;
            if (!(j <= 255)) {
              goto while_break___12;
            }
            if (j != ss) {
              sb = (ss << 8) + j;
              if (!(*(ftab + sb) & (unsigned int)(1 << 21))) {
                lo = (Int32)(*(ftab + sb) & (unsigned int)(~(1 << 21)));
                hi = (Int32)((*(ftab + (sb + 1)) & (unsigned int)(~(1 << 21))) -
                             1U);
                if (hi > lo) {

                  {
                    mainQSort3(ptr, block, quadrant, nblock, lo, hi, 2, budget);
                    numQSorted += (hi - lo) + 1;
                  }
                  if (*budget < 0) {
                    return;
                  }
                }
              }
              *(ftab + sb) |= (unsigned int)(1 << 21);
            }
            j++;
          }
        while_break___12: /* CIL Label */
            ;
        }

        j = 0;
        {
          while (1) {
          while_continue___13: /* CIL Label */
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
          while_continue___14: /* CIL Label */
              ;
            if (!(j < copyStart[ss])) {
              goto while_break___14;
            }
            k = (Int32)(*(ptr + j) - 1U);

            c1 = *(block + k);
            if (!bigDone[c1]) {
              tmp = copyStart[c1];
              (copyStart[c1])++;
              *(ptr + tmp) = (UInt32)k;
            }
            j++;
          }
        while_break___14: /* CIL Label */
            ;
        }
        j = (Int32)((*(ftab + ((ss + 1) << 8)) & (unsigned int)(~(1 << 21))) -
                    1U);
        {
          while (1) {
          while_continue___15: /* CIL Label */
              ;
            if (!(j > copyEnd[ss])) {
              goto while_break___15;
            }
            k = (Int32)(*(ptr + j) - 1U);
            if (k < 0) {
              k += nblock;
            }
            c1 = *(block + k);
            if (!bigDone[c1]) {
              tmp___0 = copyEnd[c1];
              (copyEnd[c1])--;
              *(ptr + tmp___0) = (UInt32)k;
            }
            j--;
          }
        while_break___15: /* CIL Label */
            ;
        }

        j = 0;
        {
          while (1) {
          while_continue___16: /* CIL Label */
              ;
            if (!(j <= 255)) {
              goto while_break___16;
            }
            *(ftab + ((j << 8) + ss)) |= (unsigned int)(1 << 21);
            j++;
          }
        while_break___16: /* CIL Label */
            ;
        }
        bigDone[ss] = (Bool)1;
        if (i < 255) {
          bbStart = (Int32)(*(ftab + (ss << 8)) & (unsigned int)(~(1 << 21)));
          bbSize =
              (Int32)((*(ftab + ((ss + 1) << 8)) & (unsigned int)(~(1 << 21))) -
                      (unsigned int)bbStart);
          shifts = 0;
          {

          while_break___17: /* CIL Label */
              ;
          }
          j = bbSize - 1;
          {
            while (1) {
            while_continue___18: /* CIL Label */
                ;
              if (!(j >= 0)) {
                goto while_break___18;
              }
              a2update = (Int32) * (ptr + (bbStart + j));
              qVal = (UInt16)(j >> shifts);
              *(quadrant + a2update) = qVal;
              if (a2update < 34) {
                *(quadrant + (a2update + nblock)) = qVal;
              }
              j--;
            }
          while_break___18: /* CIL Label */
              ;
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
    block = s->block;
    ftab = s->ftab;
    nblock = s->nblock;
    verb = s->verbosity;
    wfact = s->workFactor;
    if (nblock < 10000) {
      {
        fallbackSort(s->arr1, s->arr2, ftab, nblock, verb);
      }
    } else {
      i = nblock + 34;

      quadrant = (UInt16 *)(block + i);

      if (wfact > 100) {
        wfact = 100;
      }
      {
        budgetInit = nblock * ((wfact - 1) / 3);
        budget = budgetInit;
        mainSort(ptr, block, quadrant, ftab, nblock, verb, &budget);
      }

      if (budget < 0) {
        if (verb >= 2) {
          {
          }
        }
        { fallbackSort(s->arr1, s->arr2, ftab, nblock, verb); }
      }
    }
    s->origPtr = -1;
    i = 0;
    {

    while_break: /* CIL Label */
        ;
    }

    return;
  }
}
