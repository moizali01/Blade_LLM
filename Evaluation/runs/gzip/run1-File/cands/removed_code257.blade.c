

while_continue: /* CIL Label */
                ;
if (!(k < 1U)) {
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
