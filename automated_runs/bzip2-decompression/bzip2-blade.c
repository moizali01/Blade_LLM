typedef int Int32;
typedef unsigned char Bool;
typedef unsigned char UChar;
typedef unsigned long size_t;

typedef struct _IO_FILE FILE;
typedef void _IO_lock_t;

struct __anonstruct_bz_stream_26 {
  char *next_in;
  unsigned int avail_in;
  unsigned int total_in_lo32;

  char *next_out;
  unsigned int avail_out;

  void *state;
  void *(*bzalloc)(void *, int, int);

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

  UInt32 bsBuff;
  Int32 bsLive;
  Int32 blockSize100k;
  Bool smallDecompress;

  Int32 origPtr;
  UInt32 tPos;
  Int32 k0;
  Int32 unzftab[256];
  Int32 nblock_used;
  Int32 cftab[257];

  UInt32 *tt;
  UInt16 *ll16;
  UChar *ll4;

  UInt32 calculatedBlockCRC;

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

  Int32 save_alphaSize;

  Int32 save_nSelectors;
  Int32 save_EOB;
  Int32 save_groupNo;
  Int32 save_groupPos;

  Int32 save_nblockMAX;
  Int32 save_nblock;

  Int32 save_zt;
  Int32 save_zn;
  Int32 save_zvec;

  Int32 save_gSel;
  Int32 save_gMinlen;
  Int32 *save_gLimit;
  Int32 *save_gBase;
  Int32 *save_gPerm;
};
typedef struct __anonstruct_DState_28 DState;

typedef struct __anonstruct_EState_27 EState;
typedef void BZFILE;
typedef char Char;
struct __anonstruct_bzFile_29 {
  FILE *handle;
  Char buf[5000];
  Int32 bufN;

  bz_stream strm;
};
typedef struct __anonstruct_bzFile_29 bzFile;

typedef int IntNative;

struct zzzz {
  Char *name;
  struct zzzz *link;
};
typedef struct zzzz Cell;

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
        /* CIL Label */
        ;
        if (!(i <= maxLen)) {
          goto while_break;
        }
        j = 0;
        {
          while (1) {
            /* CIL Label */
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

    {

    while_break___1: /* CIL Label */
        ;
    }
    i = 0;
    {
      while (1) {
        /* CIL Label */
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
        /* CIL Label */
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
        /* CIL Label */
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
  }
}

static void makeMaps_d(DState *s) {
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
        if (s->inUse[i]) {
          s->seqToUnseq[s->nInUse] = (UChar)i;
          (s->nInUse)++;
        }
        i++;
      }
    while_break: /* CIL Label */
        ;
    }
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

  UInt32 v___30;
  UInt32 v___31;

  int tmp___2;

  {
    strm = s->strm;

    i = s->save_i;

    EOB = s->save_EOB;
    groupNo = s->save_groupNo;
    groupPos = s->save_groupPos;

    nblock = s->save_nblock;

    zn = s->save_zn;
    zvec = s->save_zvec;

    gMinlen = s->save_gMinlen;
    gLimit = s->save_gLimit;
    gBase = s->save_gBase;

    retVal = 0;
    {
      if (s->state == 10) {
        goto case_10;
      }

      if (s->state == 14) {
        goto case_14;
      }

      if (s->state == 19) {
      }

      if (s->state == 21) {
      }

      if (s->state == 27) {
      }

      if (s->state == 39) {
      }

      goto case_41;

    case_10: /* CIL Label */

    {
      while (1) {
        /* CIL Label */
        ;
        if (s->bsLive >= 8) {

          s->bsLive -= 8;

          goto while_break;
        }

        s->bsBuff = (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
        s->bsLive += 8;
        ((s->strm)->next_in)++;
        ((s->strm)->avail_in)--;
      }
    while_break: /* CIL Label */
        ;
    }
      if ((int)uc != 66) {
      }
    case_11: /* CIL Label */

    {
      while (1) {
        /* CIL Label */
        ;

        s->bsLive -= 8;

        goto while_break___0;
      }
    while_break___0: /* CIL Label */
        ;
    }

      /* CIL Label */

      {

        /* CIL Label */
        ;

        s->bsLive -= 8;

      while_break___1: /* CIL Label */
          ;
      }

      /* CIL Label */

      {
        while (1) {
          /* CIL Label */
          ;
          if (s->bsLive >= 8) {
            v___2 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            s->blockSize100k = (Int32)v___2;
            goto while_break___2;
          }

          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
        }
      while_break___2: /* CIL Label */
          ;
      }

      {}

      {
        s->tt = (UInt32 *)(*(strm->bzalloc))(
            strm->opaque,
            (int)((unsigned long)(s->blockSize100k * 100000) * sizeof(Int32)),
            1);
      }

    case_14: /* CIL Label */

    {
      while (1) {
        /* CIL Label */
        ;
        if (s->bsLive >= 8) {
          v___3 = (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
          s->bsLive -= 8;
          uc = (UChar)v___3;
          goto while_break___3;
        }

        s->bsBuff = (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
        s->bsLive += 8;
        ((s->strm)->next_in)++;
        ((s->strm)->avail_in)--;
      }
    while_break___3: /* CIL Label */
        ;
    }

      if ((int)uc != 49) {
        retVal = -4;
        goto save_state_and_return;
      }
      /* CIL Label */

      {

        /* CIL Label */
        ;

        s->bsLive -= 8;

      while_break___4: /* CIL Label */
          ;
      }

      /* CIL Label */

      {

        /* CIL Label */
        ;

        s->bsLive -= 8;

      while_break___5: /* CIL Label */
          ;
      }

      /* CIL Label */

      {

        /* CIL Label */
        ;

        s->bsLive -= 8;

      while_break___6: /* CIL Label */
          ;
      }

    case_18: /* CIL Label */

    {

      /* CIL Label */
      ;

      s->bsLive -= 8;

    while_break___7: /* CIL Label */
        ;
    }

    case_19: /* CIL Label */

    {

      /* CIL Label */
      ;

      s->bsLive -= 8;

    while_break___8: /* CIL Label */
        ;
    }

      /* CIL Label */

      {
        while (1) {
          /* CIL Label */
          ;

          s->bsLive -= 8;

          goto while_break___9;
        }
      while_break___9: /* CIL Label */
          ;
      }

    case_21: /* CIL Label */

    {

      /* CIL Label */
      ;

      s->bsLive -= 8;

    while_break___10: /* CIL Label */
        ;
    }

      /* CIL Label */

      {

        /* CIL Label */
        ;

        s->bsLive -= 8;

      while_break___11: /* CIL Label */
          ;
      }

      /* CIL Label */

      {
        while (1) {
          /* CIL Label */
          ;
          if (s->bsLive >= 8) {

            s->bsLive -= 8;

            goto while_break___12;
          }

          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
        }
      while_break___12: /* CIL Label */
          ;
      }

      /* CIL Label */

      {

        /* CIL Label */
        ;

        (s->bsLive)--;

        goto while_break___13;

        retVal = 0;

        ((s->strm)->next_in)++;

      while_break___13: /* CIL Label */
          ;
      }

      /* CIL Label */

      {
        while (1) {
          /* CIL Label */
          ;
          if (s->bsLive >= 8) {
            v___14 =
                (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
            s->bsLive -= 8;
            uc = (UChar)v___14;
            goto while_break___14;
          }

          s->bsBuff =
              (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
          s->bsLive += 8;
          ((s->strm)->next_in)++;
          ((s->strm)->avail_in)--;
        }
      while_break___14: /* CIL Label */
          ;
      }
      s->origPtr = (s->origPtr << 8) | (Int32)uc;
    case_26: /* CIL Label */

    {
      while (1) {
        /* CIL Label */
        ;
        if (s->bsLive >= 8) {
          v___15 =
              (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
          s->bsLive -= 8;
          uc = (UChar)v___15;
          goto while_break___15;
        }

        s->bsBuff = (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
        s->bsLive += 8;
        ((s->strm)->next_in)++;
        ((s->strm)->avail_in)--;
      }
    while_break___15: /* CIL Label */
        ;
    }
      s->origPtr = (s->origPtr << 8) | (Int32)uc;
    case_27: /* CIL Label */

    {
      while (1) {
        /* CIL Label */
        ;
        if (s->bsLive >= 8) {
          v___16 =
              (s->bsBuff >> (s->bsLive - 8)) & (unsigned int)((1 << 8) - 1);
          s->bsLive -= 8;
          uc = (UChar)v___16;
          goto while_break___16;
        }

        s->bsBuff = (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
        s->bsLive += 8;
        ((s->strm)->next_in)++;
        ((s->strm)->avail_in)--;
      }
    while_break___16: /* CIL Label */
        ;
    }
      s->origPtr = (s->origPtr << 8) | (Int32)uc;

      {
        while (1) {
          /* CIL Label */
          ;
          if (!(i < 16)) {
            goto while_break___17;
          }
          /* CIL Label */

          {
            while (1) {
              /* CIL Label */
              ;
              if (s->bsLive >= 1) {
                v___17 = (s->bsBuff >> (s->bsLive - 1)) &
                         (unsigned int)((1 << 1) - 1);
                (s->bsLive)--;
                uc = (UChar)v___17;
                goto while_break___18;
              }

              s->bsBuff =
                  (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
              s->bsLive += 8;
              ((s->strm)->next_in)++;
              ((s->strm)->avail_in)--;
            }
          while_break___18: /* CIL Label */
              ;
          }
          if ((int)uc == 1) {
            s->inUse16[i] = (Bool)1;
          } else {
          }
          i++;
        }
      while_break___17: /* CIL Label */
          ;
      }
      i = 0;
      {

      while_break___19: /* CIL Label */
          ;
      }

      {
        while (1) {
          /* CIL Label */
          ;
          if (!(i < 16)) {
            goto while_break___20;
          }
          if (s->inUse16[i]) {
            j = 0;
            {
              while (1) {
                /* CIL Label */
                ;
                if (!(j < 16)) {
                  goto while_break___21;
                }
              case_29: /* CIL Label */

              {
                while (1) {
                  /* CIL Label */
                  ;
                  if (s->bsLive >= 1) {
                    v___18 = (s->bsBuff >> (s->bsLive - 1)) &
                             (unsigned int)((1 << 1) - 1);
                    (s->bsLive)--;
                    uc = (UChar)v___18;
                    goto while_break___22;
                  }

                  s->bsBuff = (s->bsBuff << 8) |
                              (UInt32) * ((UChar *)(s->strm)->next_in);
                  s->bsLive += 8;
                  ((s->strm)->next_in)++;
                  ((s->strm)->avail_in)--;
                  ((s->strm)->total_in_lo32)++;
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

      alphaSize = s->nInUse + 2;
    case_30: /* CIL Label */

    {

      /* CIL Label */
      ;
      if (s->bsLive >= 3) {
        v___19 = (s->bsBuff >> (s->bsLive - 3)) & (unsigned int)((1 << 3) - 1);
        s->bsLive -= 3;
        nGroups = (Int32)v___19;
        goto while_break___23;
      }

    while_break___23: /* CIL Label */
        ;
    }

    case_31: /* CIL Label */

    {
      while (1) {
        /* CIL Label */
        ;
        if (s->bsLive >= 15) {
          v___20 =
              (s->bsBuff >> (s->bsLive - 15)) & (unsigned int)((1 << 15) - 1);
          s->bsLive -= 15;
          nSelectors = (Int32)v___20;
          goto while_break___24;
        }

        s->bsBuff = (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
        s->bsLive += 8;
        ((s->strm)->next_in)++;
        ((s->strm)->avail_in)--;
      }
    while_break___24: /* CIL Label */
        ;
    }

      i = 0;
      {
        while (1) {
          /* CIL Label */
          ;
          if (!(i < nSelectors)) {
            goto while_break___25;
          }
          j = 0;
          {
            while (1) {
              /* CIL Label */
              ;
            case_32: /* CIL Label */

            {
              while (1) {
                /* CIL Label */
                ;
                if (s->bsLive >= 1) {
                  v___21 = (s->bsBuff >> (s->bsLive - 1)) &
                           (unsigned int)((1 << 1) - 1);
                  (s->bsLive)--;
                  uc = (UChar)v___21;
                  goto while_break___27;
                }

                s->bsBuff =
                    (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
                s->bsLive += 8;
                ((s->strm)->next_in)++;
                ((s->strm)->avail_in)--;

                if ((s->strm)->total_in_lo32 == 0U) {
                }
              }
            while_break___27: /* CIL Label */
                ;
            }
              if ((int)uc == 0) {
                goto while_break___26;
              }
              j++;
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
          /* CIL Label */
          ;
          if (!(i < nSelectors)) {
            goto while_break___29;
          }
          v___22 = s->selectorMtf[i];
          tmp = pos[v___22];
          {
            while (1) {
              /* CIL Label */
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

      {
        while (1) {
          /* CIL Label */
          ;
          if (!(t < nGroups)) {
            goto while_break___31;
          }
        case_33: /* CIL Label */

        {
          while (1) {
            /* CIL Label */
            ;
            if (s->bsLive >= 5) {
              v___23 =
                  (s->bsBuff >> (s->bsLive - 5)) & (unsigned int)((1 << 5) - 1);
              s->bsLive -= 5;
              curr = (Int32)v___23;
              goto while_break___32;
            }

            s->bsBuff =
                (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
            s->bsLive += 8;
            ((s->strm)->next_in)++;
            ((s->strm)->avail_in)--;
          }
        while_break___32: /* CIL Label */
            ;
        }
          i = 0;
          {
            while (1) {
              /* CIL Label */
              ;
              if (!(i < alphaSize)) {
                goto while_break___33;
              }
              {
                while (1) {
                  /* CIL Label */
                  ;

                case_34: /* CIL Label */

                {
                  while (1) {
                    /* CIL Label */
                    ;
                    if (s->bsLive >= 1) {
                      v___24 = (s->bsBuff >> (s->bsLive - 1)) &
                               (unsigned int)((1 << 1) - 1);
                      (s->bsLive)--;
                      uc = (UChar)v___24;
                      goto while_break___35;
                    }

                    s->bsBuff = (s->bsBuff << 8) |
                                (UInt32) * ((UChar *)(s->strm)->next_in);
                    s->bsLive += 8;
                    ((s->strm)->next_in)++;
                    ((s->strm)->avail_in)--;
                  }
                while_break___35: /* CIL Label */
                    ;
                }
                  if ((int)uc == 0) {
                    goto while_break___34;
                  }
                case_35: /* CIL Label */

                {
                  while (1) {
                    /* CIL Label */
                    ;
                    if (s->bsLive >= 1) {
                      v___25 = (s->bsBuff >> (s->bsLive - 1)) &
                               (unsigned int)((1 << 1) - 1);
                      (s->bsLive)--;
                      uc = (UChar)v___25;
                      goto while_break___36;
                    }

                    s->bsBuff = (s->bsBuff << 8) |
                                (UInt32) * ((UChar *)(s->strm)->next_in);
                    s->bsLive += 8;
                    ((s->strm)->next_in)++;
                    ((s->strm)->avail_in)--;
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
          /* CIL Label */
          ;
          if (!(t < nGroups)) {
            goto while_break___37;
          }

          maxLen = 0;
          i = 0;
          {
            while (1) {
              /* CIL Label */
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

            t++;
          }
        }
      while_break___37: /* CIL Label */
          ;
      }
      EOB = s->nInUse + 1;

      groupNo = -1;

      {

        /* CIL Label */
        ;
      }
      kk = 4095;
      ii = 15;
      {
        while (1) {
          /* CIL Label */
          ;
          if (!(ii >= 0)) {
            goto while_break___40;
          }
          jj = 15;
          {
            while (1) {
              /* CIL Label */
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

      groupNo++;

      groupPos = 50;
      gSel = (Int32)s->selector[groupNo];
      gMinlen = s->minLens[gSel];
      gLimit = &s->limit[gSel][0];
      gPerm = &s->perm[gSel][0];
      gBase = &s->base[gSel][0];

      groupPos--;

    case_36: /* CIL Label */

    {

      /* CIL Label */
      ;

    while_break___42: /* CIL Label */
        ;
    }
      {
        while (1) {
          /* CIL Label */
          ;

          if (zvec <= *(gLimit + zn)) {
            goto while_break___43;
          }
          zn++;
        case_37: /* CIL Label */

        {
          while (1) {
            /* CIL Label */
            ;
            if (s->bsLive >= 1) {
              v___27 =
                  (s->bsBuff >> (s->bsLive - 1)) & (unsigned int)((1 << 1) - 1);
              (s->bsLive)--;
              zj = (Int32)v___27;
              goto while_break___44;
            }

            s->bsBuff =
                (s->bsBuff << 8) | (UInt32) * ((UChar *)(s->strm)->next_in);
            s->bsLive += 8;
            ((s->strm)->next_in)++;
            ((s->strm)->avail_in)--;
          }
        while_break___44: /* CIL Label */
            ;
        }
          zvec = (zvec << 1) | zj;
        }
      while_break___43: /* CIL Label */
          ;
      }

      nextSym = *(gPerm + (zvec - *(gBase + zn)));
      {
        while (1) {
          /* CIL Label */
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
                  /* CIL Label */
                  ;
                  if (nextSym == 0) {
                    es += N;
                  } else {

                    es += 2 * N;
                  }
                  N *= 2;
                  if (groupPos == 0) {
                    groupNo++;

                    groupPos = 50;
                    gSel = (Int32)s->selector[groupNo];

                    gLimit = &s->limit[gSel][0];
                    gPerm = &s->perm[gSel][0];
                    gBase = &s->base[gSel][0];
                  }
                  groupPos--;
                  zn = gMinlen;
                case_38: /* CIL Label */

                {
                  while (1) {
                    /* CIL Label */
                    ;
                    if (s->bsLive >= zn) {
                      v___28 = (s->bsBuff >> (s->bsLive - zn)) &
                               (unsigned int)((1 << zn) - 1);
                      s->bsLive -= zn;
                      zvec = (Int32)v___28;
                      goto while_break___47;
                    }

                    s->bsLive += 8;

                    ((s->strm)->avail_in)--;
                  }
                while_break___47: /* CIL Label */
                    ;
                }
                  {
                    while (1) {
                      /* CIL Label */
                      ;

                      if (zvec <= *(gLimit + zn)) {
                        goto while_break___48;
                      }
                      zn++;
                    case_39: /* CIL Label */

                    {
                      while (1) {
                        /* CIL Label */
                        ;
                        if (s->bsLive >= 1) {
                          v___29 = (s->bsBuff >> (s->bsLive - 1)) &
                                   (unsigned int)((1 << 1) - 1);
                          (s->bsLive)--;
                          zj = (Int32)v___29;
                          goto while_break___49;
                        }

                        s->bsBuff = (s->bsBuff << 8) |
                                    (UInt32) * ((UChar *)(s->strm)->next_in);
                        s->bsLive += 8;
                        ((s->strm)->next_in)++;
                        ((s->strm)->avail_in)--;
                      }
                    while_break___49: /* CIL Label */
                        ;
                    }
                      zvec = (zvec << 1) | zj;
                    }
                  while_break___48: /* CIL Label */
                      ;
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

              {

              while_break___50: /* CIL Label */
                  ;
              }

              {
                while (1) {
                  /* CIL Label */
                  ;
                  if (!(es > 0)) {
                    goto while_break___51;
                  }

                  *(s->tt + nblock) = (UInt32)uc;
                  nblock++;
                  es--;
                }
              while_break___51: /* CIL Label */
                  ;
              }

            } else {

              nn = (UInt32)(nextSym - 1);

              pp = s->mtfbase[0];
              uc = s->mtfa[(UInt32)pp + nn];
              {

                /* CIL Label */
                ;
              }
              {
                while (1) {
                  /* CIL Label */
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

              lno = (Int32)(nn / 16U);

              pp = s->mtfbase[lno] + off;

              {
                while (1) {
                  /* CIL Label */
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
                  /* CIL Label */
                  ;
                  if (!(lno > 0)) {
                    goto while_break___55;
                  }
                }
              while_break___55: /* CIL Label */
                  ;
              }
              (s->mtfbase[0])--;

              (s->unzftab[s->seqToUnseq[uc]])++;

              *(s->tt + nblock) = (UInt32)s->seqToUnseq[uc];

              nblock++;
              if (groupPos == 0) {
                groupNo++;

                groupPos = 50;
                gSel = (Int32)s->selector[groupNo];

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
                  /* CIL Label */
                  ;
                  if (s->bsLive >= zn) {

                    zvec = (Int32)v___30;
                    goto while_break___58;
                  }
                  if ((s->strm)->avail_in == 0U) {
                  }
                }
              while_break___58: /* CIL Label */
                  ;
              }
              {
                while (1) {
                  /* CIL Label */
                  ;

                  if (zvec <= *(gLimit + zn)) {
                    goto while_break___59;
                  }
                  zn++;
                case_41: /* CIL Label */
                  s->state = 41;
                  {
                    while (1) {
                      /* CIL Label */
                      ;
                      if (s->bsLive >= 1) {
                        v___31 = (s->bsBuff >> (s->bsLive - 1)) &
                                 (unsigned int)((1 << 1) - 1);
                        (s->bsLive)--;
                        zj = (Int32)v___31;
                        goto while_break___60;
                      }
                      if ((s->strm)->avail_in == 0U) {

                        goto save_state_and_return;
                      }
                      s->bsBuff = (s->bsBuff << 8) |
                                  (UInt32) * ((UChar *)(s->strm)->next_in);
                      s->bsLive += 8;
                      ((s->strm)->next_in)++;
                      ((s->strm)->avail_in)--;
                    }
                  while_break___60: /* CIL Label */
                      ;
                  }
                  zvec = (zvec << 1) | zj;
                }
              while_break___59: /* CIL Label */
                  ;
              }

              nextSym = *(gPerm + (zvec - *(gBase + zn)));
            }
          }
        }
      while_break___45: /* CIL Label */
          ;
      }

      i = 1;
      {
        while (1) {
          /* CIL Label */
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
          /* CIL Label */
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

      {

        /* CIL Label */
        ;
      }

      s->state = 2;

      if (s->smallDecompress) {

        {

          /* CIL Label */
          ;
        }

        {

        while_break___65: /* CIL Label */
            ;
        }
        i = s->origPtr;
        j = (Int32)((UInt32) * (s->ll16 + i) |
                    ((((UInt32) * (s->ll4 + (i >> 1)) >> ((i << 2) & 4)) & 15U)
                     << 16));
        {

          /* CIL Label */
          ;
        }

      } else {
        i = 0;
        {
          while (1) {
            /* CIL Label */
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

        s->k0 ^= tmp___2;

        s->tPos = *(s->tt + s->tPos);
        s->k0 = (Int32)((UChar)(s->tPos & 255U));
        s->tPos >>= 8;
        (s->nblock_used)++;
      }

    endhdr_2:
      /* CIL Label */

      {

        /* CIL Label */
        ;
      }

    case_43: /* CIL Label */

    {

      /* CIL Label */
      ;
    }

    case_44: /* CIL Label */

    {

      /* CIL Label */
      ;
    }

    case_45: /* CIL Label */

    {

      /* CIL Label */
      ;
    }

    case_46: /* CIL Label */

    {

      /* CIL Label */
      ;
    }

    case_47: /* CIL Label */

    {

      /* CIL Label */
      ;
    }

    case_48: /* CIL Label */

    {

      /* CIL Label */
      ;
    }

    case_49: /* CIL Label */

    {

      /* CIL Label */
      ;
    }

    case_50: /* CIL Label */

    {

      /* CIL Label */
      ;
    }

    switch_default: { /* CIL Label */

    } /* CIL Label */
    ;
    }
    {}
  save_state_and_return:

    s->save_nSelectors = nSelectors;
    s->save_EOB = EOB;
    s->save_groupNo = groupNo;
    s->save_groupPos = groupPos;

    s->save_nblockMAX = nblockMAX;
    s->save_nblock = nblock;

    s->save_zn = zn;
    s->save_zvec = zvec;

    s->save_gMinlen = gMinlen;
    s->save_gLimit = gLimit;
    s->save_gBase = gBase;
    s->save_gPerm = gPerm;
    return (retVal);
  }
}
UInt32 BZ2_crc32Table[256];

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

int BZ2_bzDecompressInit(bz_stream *strm, int verbosity___0, int small) {
  DState *s;

  {
    {}

    strm->bzalloc = &default_bzalloc;

    { s = (DState *)(*(strm->bzalloc))(strm->opaque, (int)sizeof(DState), 1); }

    s->strm = strm;
    strm->state = (void *)s;
    s->state = 10;
  }
}
static Bool unRLE_obuf_to_output_FAST(DState *s) {
  UChar k1;

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

    while_continue___1: /* CIL Label */
        ;
      if (c_state_out_len > 0) {
        {
          while (1) {
            /* CIL Label */
            ;

            if (c_state_out_len == 1) {
              goto while_break___2;
            }
            *((UChar *)cs_next_out) = c_state_out_ch;

            c_state_out_len--;
            cs_next_out++;
            cs_avail_out--;
          }
        while_break___2: /* CIL Label */
            ;
        }
      s_state_out_len_eq_one:
        if (cs_avail_out == 0U) {
        }
        *((UChar *)cs_next_out) = c_state_out_ch;

        cs_next_out++;
        cs_avail_out--;
      }

      if (c_nblock_used == s_save_nblockPP) {

        goto return_notr;
      }
      c_state_out_ch = (UChar)c_k0;

      c_tPos = *(c_tt + c_tPos);
      k1 = (UChar)(c_tPos & 255U);
      c_tPos >>= 8;
      c_nblock_used++;
      if ((int)k1 != c_k0) {
        c_k0 = (Int32)k1;
        goto s_state_out_len_eq_one;
      }

      c_state_out_len = 2;

      c_tPos = *(c_tt + c_tPos);
      k1 = (UChar)(c_tPos & 255U);
      c_tPos >>= 8;
      c_nblock_used++;

      if ((int)k1 != c_k0) {
        c_k0 = (Int32)k1;
        goto while_continue___1;
      }
      c_state_out_len = 3;

      c_tPos = *(c_tt + c_tPos);
      k1 = (UChar)(c_tPos & 255U);
      c_tPos >>= 8;
      c_nblock_used++;

      if ((int)k1 != c_k0) {
        c_k0 = (Int32)k1;
        goto while_continue___1;
      }

      c_tPos = *(c_tt + c_tPos);
      k1 = (UChar)(c_tPos & 255U);
      c_tPos >>= 8;
      c_nblock_used++;
      c_state_out_len = (Int32)k1 + 4;

      c_tPos = *(c_tt + c_tPos);
      c_k0 = (Int32)((UChar)(c_tPos & 255U));
      c_tPos >>= 8;
      c_nblock_used++;

      /* CIL Label */
      ;
    }
  return_notr:

    s->state_out_ch = c_state_out_ch;
    s->state_out_len = c_state_out_len;
    s->nblock_used = c_nblock_used;
    s->k0 = c_k0;

    s->tPos = c_tPos;

    (s->strm)->avail_out = cs_avail_out;
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

int BZ2_bzDecompress(bz_stream *strm) {
  Bool corrupt;
  DState *s;
  Int32 r;
  Int32 tmp;

  {

    s = (DState *)strm->state;

    {

      /* CIL Label */
      ;

      if (s->state == 2) {

        {
        }

        { corrupt = unRLE_obuf_to_output_FAST(s); }

        if (s->nblock_used == s->save_nblock + 1) {

          s->state = 14;

        } else {
          return (0);
        }
      }

      {
        tmp = BZ2_decompress(s);
        r = tmp;
      }

      return (r);

      /* CIL Label */
      ;
    }
    {}
  }
}

BZFILE *BZ2_bzReadOpen(int *bzerror, FILE *f, int verbosity___0, int small,
                       void *unused, int nUnused) {
  bzFile *bzf;
  int ret;

  {

    *bzerror = 0;

    {}

    { bzf = (bzFile *)malloc(sizeof(bzFile)); }

    bzf->handle = f;

    {

      /* CIL Label */
      ;
    }
    { ret = BZ2_bzDecompressInit(&bzf->strm, verbosity___0, small); }

    return ((BZFILE *)bzf);
  }
}

int BZ2_bzRead(int *bzerror, BZFILE *b, void *buf, int len) {
  Int32 n;
  Int32 ret;
  bzFile *bzf;

  {

    bzf->strm.avail_out = (unsigned int)len;
    bzf->strm.next_out = (char *)buf;
    {

      /* CIL Label */
      ;
      {}

      if (bzf->strm.avail_in == 0U) {
        {
        }

        {
          n = (Int32)fread((void * /* __restrict  */)(bzf->buf), sizeof(UChar),
                           (size_t)5000, (FILE * /* __restrict  */)bzf->handle);
        }

        bzf->bufN = n;
        bzf->strm.avail_in = (unsigned int)bzf->bufN;
        bzf->strm.next_in = bzf->buf;
      }
      { ret = BZ2_bzDecompress(&bzf->strm); }

      *bzerror = ret;

      return ((int)((unsigned int)len - bzf->strm.avail_out));

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

Int32 verbosity;

Bool smallMode;

Int32 opMode;
Int32 srcMode;

Char inName[1034];
Char outName[1034];

Char *progName;
Char progNameReally[1034];

static Bool uncompressStream(FILE *zStream, FILE *stream) {
  BZFILE *bzf;
  Int32 bzerr;

  Int32 nread;

  UChar obuf[5000];
  UChar unused[5000];
  Int32 nUnused;

  {
    {}

    {}

    {

      /* CIL Label */
      ;
      {
        bzf = BZ2_bzReadOpen(&bzerr, zStream, verbosity, (int)smallMode,
                             (void *)(unused), nUnused);
      }

      {
        while (1) {
          /* CIL Label */
          ;
          if (!(bzerr == 0)) {
            goto while_break___0;
          }
          { nread = BZ2_bzRead(&bzerr, bzf, (void *)(obuf), 5000); }

        _L:

        {
          fwrite((void const * /* __restrict  */)(obuf), sizeof(UChar),
                 (size_t)nread, (FILE * /* __restrict  */)stream);
        }

          {}
        }
      while_break___0: /* CIL Label */
          ;
      }

      {}

      {

        /* CIL Label */
        ;
      }
      {

      }

      /* CIL Label */
      ;
    }
    {}

    {}

    {}

    {}

  trycat:

  errhandler: {}
    {

    case_neg_9: { /* CIL Label */
    }

    errhandler_io: { /* CIL Label */
    }

    case_neg_4: { /* CIL Label */
    }
    case_neg_3: { /* CIL Label */
    }
    case_neg_7: { /* CIL Label */
    }
    case_neg_5: /* CIL Label */

    switch_default: { /* CIL Label */
    }
    switch_break: /* CIL Label */
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

static void crcError(void) {

  {
    {}
  }
}

static void compressedStreamEOF(void) {

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

static void applySavedFileAttrToOutputFile(IntNative fd) {

  {
    {}

    {}
  }
}

Char const *zSuffix[4] = {".bz2", ".bz", ".tbz2", ".tbz"};
Char const *unzSuffix[4] = {"", "", ".tar", ".tar"};

static Bool mapSuffix(Char *name, Char const *oldSuffix,
                      Char const *newSuffix) {

  size_t tmp___0;
  size_t tmp___1;

  {
    {}

    {
      tmp___0 = strlen((char const *)name);
      tmp___1 = strlen(oldSuffix);
      *(name + (tmp___0 - tmp___1)) = (Char)0;
    }
  }
}

static void uncompress(Char *name) {
  FILE *inStr;
  FILE *outStr;

  Int32 i;
  Bool magicNumberOK;

  Bool tmp;

  IntNative tmp___15;

  {

    {

      { /* CIL Label */
      }

      { /* CIL Label */
        copyFileName(inName, name);
        copyFileName(outName, name);
        i = 0;
      }
      {

        /* CIL Label */
        ;

        {
          tmp = mapSuffix(outName, zSuffix[i], unzSuffix[i]);
        }

        /* CIL Label */
        ;
      }
      {}

      {
          /* CIL Label */

      }

      /* CIL Label */
      ;
    }
  zzz:

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

    { magicNumberOK = uncompressStream(inStr, outStr); }

    {}

    { tmp___15 = remove((char const *)(inName)); }

    return;
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
  Int32 j;

  Cell *argList;
  Cell *aa;

  char *tmp___3;

  {

    {

      j = 0;
      i = j;

      progName = &progNameReally[0];
    }
    {

      /* CIL Label */
      ;
    }
    {}
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

      /* CIL Label */
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

    {
      while (1) {
        /* CIL Label */
        ;
        if (!((unsigned long)aa != (unsigned long)((void *)0))) {
          goto while_break___6;
        }
        {}

        { uncompress(aa->name); }

        aa = aa->link;
      }
    while_break___6: /* CIL Label */
        ;
    }

    {

      /* CIL Label */
      ;
    }
  }
}

static Int32 incs[14] = {1,    4,    13,    40,    121,    364,    1093,
                         3280, 9841, 29524, 88573, 265720, 797161, 2391484};

void BZ2_blockSort(EState *s) {

  {

    {

      /* CIL Label */
      ;
    }
  }
}
