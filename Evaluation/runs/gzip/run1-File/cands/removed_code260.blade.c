

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
    while_continue___3: /* CIL Label */
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
  while_break___3: /* CIL Label */
                   ;
  }
  n = (unsigned int)t->v.n + ((unsigned int)b & (unsigned int)mask_bits[e]);
  b >>= e;
  k -= e;
  {
    while (1) {
    while_continue___4: /* CIL Label */
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
  while_break___4: /* CIL Label */
                   ;
  }
  t = td + ((unsigned int)b & md);
  e = (unsigned int)t->e;
  if (e > 16U) {
    {
      while (1) {
      while_continue___5: /* CIL Label */
                          ;
        if (e == 99U) {
          return (1);
        }
        b >>= (int)t->b;
        k -= (unsigned int)t->b;
        e -= 16U;
        {
          while (1) {
          while_continue___6: /* CIL Label */
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
        while_break___6: /* CIL Label */
                         ;
        }
        t = t->v.t + ((unsigned int)b & (unsigned int)mask_bits[e]);
        e = (unsigned int)t->e;
        if (!(e > 16U)) {
          goto while_break___5;
        }
      }
    while_break___5: /* CIL Label */
                     ;
    }
  }
  b >>= (int)t->b;
  k -= (unsigned int)t->b;
  {
    while (1) {
    while_continue___7: /* CIL Label */
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
  while_break___7: /* CIL Label */
                   ;
  }
  d = (w - (unsigned int)t->v.n) -
      ((unsigned int)b & (unsigned int)mask_bits[e]);
  b >>= e;
  k -= e;
  {
    while (1) {
    while_continue___8: /* CIL Label */
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
          memcpy((void * /* __restrict  */)(window + w),
                 (void const * /* __restrict  */)(window + d), (size_t)e);
          w += e;
          d += e;
        }
      } else {
        {
          while (1) {
          while_continue___9: /* CIL Label */
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
        while_break___9: /* CIL Label */
                         ;
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
  while_break___8: /* CIL Label */
                   ;
  }
}
