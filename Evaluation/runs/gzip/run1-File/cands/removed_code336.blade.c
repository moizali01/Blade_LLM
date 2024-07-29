

if (len == 0U) {
  goto __Cont;
}
nextcode = (unsigned int)((int)start[len] + (int)weight[len]);
if (len <= (unsigned int)tablebits) {
  i___0 = (unsigned int)start[len];
  {
    while (1) {
    while_continue___6: /* CIL Label */
                        ;
      if (!(i___0 < nextcode)) {
        goto while_break___6;
      }
      *(table + i___0) = (ush)ch;
      i___0++;
    }
  while_break___6: /* CIL Label */
                   ;
  }
} else {
  k = (unsigned int)start[len];
  p = table + (k >> jutbits);
  i___0 = len - (unsigned int)tablebits;
  {
    while (1) {
    while_continue___7: /* CIL Label */
                        ;
      if (!(i___0 != 0U)) {
        goto while_break___7;
      }
      if ((int)*p == 0) {
        tmp___0 = (ush)0;
        prev[avail] = tmp___0;
        *((prev + 32768) + avail) = tmp___0;
        tmp___1 = avail;
        avail++;
        *p = (ush)tmp___1;
      }
      if (k & mask) {
        p = (prev + 32768) + (int)*p;
      } else {
        p = &prev[*p];
      }
      k <<= 1;
      i___0--;
    }
  while_break___7: /* CIL Label */
                   ;
  }
  *p = (ush)ch;
}
