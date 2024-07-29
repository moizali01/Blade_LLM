

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
          if (c == 7) {
            mask = 1U << ((16UL * sizeof(char) - 1UL) - 3UL);
            {
              while (1) {
              while_continue___2: /* CIL Label */
                                  ;
                if (!(mask & (unsigned int)bitbuf)) {
                  goto while_break___2;
                }
                mask >>= 1;
                c++;
              }
            while_break___2: /* CIL Label */
                             ;
            }
          }
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
            { c = (int)getbits(2); }
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
        while (1) {
        while_continue___1: /* CIL Label */
                            ;
          if (!(i___0 < n)) {
            goto while_break___1;
          }
          c = (int)pt_table[(int)bitbuf >> (16UL * sizeof(char) - 8UL)];
          if (c >= 19) {
            mask = 1U << ((16UL * sizeof(char) - 1UL) - 8UL);
            {
              while (1) {
              while_continue___2: /* CIL Label */
                                  ;
                if ((unsigned int)bitbuf & mask) {
                  c = (int)*((prev + 32768) + c);
                } else {
                  c = (int)prev[c];
                }
                mask >>= 1;
                if (!(c >= 19)) {
                  goto while_break___2;
                }
              }
            while_break___2: /* CIL Label */
                             ;
            }
          }
          { fillbuf((int)pt_len[c]); }
          if (c <= 2) {
            if (c == 0) {
              c = 1;
            } else {
              if (c == 1) {
                {
                  tmp = getbits(4);
                  c = (int)(tmp + 3U);
                }
              } else {
                {
                  tmp___0 = getbits(9);
                  c = (int)(tmp___0 + 20U);
                }
              }
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
                outbuf[tmp___1] = (uch)0;
              }
            while_break___3: /* CIL Label */
                             ;
            }
          } else {
            tmp___2 = i___0;
            i___0++;
            outbuf[tmp___2] = (uch)(c - 2);
          }
        }
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
      { blocksize = getbits(16); }
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
