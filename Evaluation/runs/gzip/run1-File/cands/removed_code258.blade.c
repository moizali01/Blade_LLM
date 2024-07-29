

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
      while_continue: /* CIL Label */
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
    while_break: /* CIL Label */
                 ;
    }
    n = (unsigned int)b & 65535U;
    b >>= 16;
    k -= 16U;
    {
      while (1) {
      while_continue___0: /* CIL Label */
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
    while_break___0: /* CIL Label */
                     ;
    }
    if (n != (unsigned int)(~b & 65535UL)) {
      return (1);
    }
    b >>= 16;
    k -= 16U;
    {
      while (1) {
      while_continue___1: /* CIL Label */
                          ;
        tmp___9 = n;
        n--;
        if (!tmp___9) {
          goto while_break___1;
        }
        {
          while (1) {
          while_continue___2: /* CIL Label */
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
        while_break___2: /* CIL Label */
                         ;
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
    while_break___1: /* CIL Label */
                     ;
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
  void *__cil_tmp8;

  {
    i___0 = 0;
    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
        if (!(i___0 < 144)) {
          goto while_break;
        }
        l[i___0] = 8U;
        i___0++;
      }
    while_break: /* CIL Label */
                 ;
    }
    {
      while (1) {
      while_continue___0: /* CIL Label */
                          ;
        if (!(i___0 < 256)) {
          goto while_break___0;
        }
        l[i___0] = 9U;
        i___0++;
      }
    while_break___0: /* CIL Label */
                     ;
    }
    {
      while (1) {
      while_continue___1: /* CIL Label */
                          ;
        if (!(i___0 < 280)) {
          goto while_break___1;
        }
        l[i___0] = 7U;
        i___0++;
      }
    while_break___1: /* CIL Label */
                     ;
    }
    {
      while (1) {
      while_continue___2: /* CIL Label */
                          ;
        if (!(i___0 < 288)) {
          goto while_break___2;
        }
        l[i___0] = 8U;
        i___0++;
      }
    while_break___2: /* CIL Label */
                     ;
    }
    {
      bl = 7;
      i___0 = huft_build(l, 288U, 257U, cplens, cplext, &tl, &bl);
    }
    if (i___0 != 0) {
      return (i___0);
    }
    i___0 = 0;
    {
      while (1) {
      while_continue___3: /* CIL Label */
                          ;
        if (!(i___0 < 30)) {
          goto while_break___3;
        }
        l[i___0] = 5U;
        i___0++;
      }
    while_break___3: /* CIL Label */
                     ;
    }
    {
      bd = 5;
      i___0 = huft_build(l, 30U, 0U, cpdist, cpdext, &td, &bd);
    }
    if (i___0 > 1) {
      { huft_free(tl); }
      return (i___0);
    }
    { tmp = inflate_codes(tl, td, bl, bd); }
    if (tmp) {
      return (1);
    }
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
  void *__cil_tmp48;

  {
    b = bb;
    k = bk;
    {
      while (1) {
      while_continue: /* CIL Label */
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
    while_break: /* CIL Label */
                 ;
    }
    nl = 257U + ((unsigned int)b & 31U);
    b >>= 5;
    k -= 5U;
    {
      while (1) {
      while_continue___0: /* CIL Label */
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
    while_break___0: /* CIL Label */
                     ;
    }
    nd = 1U + ((unsigned int)b & 31U);
    b >>= 5;
    k -= 5U;
    {
      while (1) {
      while_continue___1: /* CIL Label */
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
    while_break___1: /* CIL Label */
                     ;
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
      while_continue___2: /* CIL Label */
                          ;
        if (!(j___0 < nb)) {
          goto while_break___2;
        }
        {
          while (1) {
          while_continue___3: /* CIL Label */
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
        while_break___3: /* CIL Label */
                         ;
        }
        ll[border[j___0]] = (unsigned int)b & 7U;
        b >>= 3;
        k -= 3U;
        j___0++;
      }
    while_break___2: /* CIL Label */
                     ;
    }
    {
      while (1) {
      while_continue___4: /* CIL Label */
                          ;
        if (!(j___0 < 19U)) {
          goto while_break___4;
        }
        ll[border[j___0]] = 0U;
        j___0++;
      }
    while_break___4: /* CIL Label */
                     ;
    }
    {
      bl = 7;
      i___0 = huft_build(ll, 19U, 19U, (ush *)((void *)0), (ush *)((void *)0),
                         &tl, &bl);
    }
    if (i___0 != 0) {
      if (i___0 == 1) {
        { huft_free(tl); }
      }
      return (i___0);
    }
    n = nl + nd;
    m = (unsigned int)mask_bits[bl];
    l = 0U;
    i___0 = (int)l;
    {
      while (1) {
      while_continue___5: /* CIL Label */
                          ;
        if (!((unsigned int)i___0 < n)) {
          goto while_break___5;
        }
        {
          while (1) {
          while_continue___6: /* CIL Label */
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
        while_break___6: /* CIL Label */
                         ;
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
              while_continue___7: /* CIL Label */
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
            while_break___7: /* CIL Label */
                             ;
            }
            j___0 = 3U + ((unsigned int)b & 3U);
            b >>= 2;
            k -= 2U;
            if ((unsigned int)i___0 + j___0 > n) {
              return (1);
            }
            {
              while (1) {
              while_continue___8: /* CIL Label */
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
            while_break___8: /* CIL Label */
                             ;
            }
          } else {
            if (j___0 == 17U) {
              {
                while (1) {
                while_continue___9: /* CIL Label */
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
              while_break___9: /* CIL Label */
                               ;
              }
              j___0 = 3U + ((unsigned int)b & 7U);
              b >>= 3;
              k -= 3U;
              if ((unsigned int)i___0 + j___0 > n) {
                return (1);
              }
              {
                while (1) {
                while_continue___10: /* CIL Label */
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
              while_break___10: /* CIL Label */
                                ;
              }
              l = 0U;
            } else {
              {
                while (1) {
                while_continue___11: /* CIL Label */
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
              while_break___11: /* CIL Label */
                                ;
              }
              j___0 = 11U + ((unsigned int)b & 127U);
              b >>= 7;
              k -= 7U;
              if ((unsigned int)i___0 + j___0 > n) {
                return (1);
              }
              {
                while (1) {
                while_continue___12: /* CIL Label */
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
              while_break___12: /* CIL Label */
                                ;
              }
              l = 0U;
            }
          }
        }
      }
    while_break___5: /* CIL Label */
                     ;
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
          fprintf(
              (FILE * /* __restrict  */) stderr,
              (char const * /* __restrict  */) " incomplete literal tree\n");
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
          fprintf(
              (FILE * /* __restrict  */) stderr,
              (char const * /* __restrict  */) " incomplete distance tree\n");
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
