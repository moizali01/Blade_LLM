

while_continue___0: /* CIL Label */
                    ;
if (!(k < 2U)) {
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
