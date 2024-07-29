

e -= 16U;
{
  while (1) {
  while_continue___2: /* CIL Label */
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
while_break___2: /* CIL Label */
                 ;
}
t = t->v.t + ((unsigned int)b & (unsigned int)mask_bits[e]);
e = (unsigned int)t->e;
if (!(e > 16U)) {
  goto while_break___1;
}
