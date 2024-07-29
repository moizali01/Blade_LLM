

while_continue___0: /* CIL Label */
                    ;
if (!(k < (unsigned int)bl)) {
  goto while_break___0;
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
