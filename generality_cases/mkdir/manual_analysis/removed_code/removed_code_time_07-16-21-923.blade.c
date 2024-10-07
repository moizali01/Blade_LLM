

if (bytes == 0xfffffffffffffffeUL) {
  printable = 0;
  {
    while (1) {
      ;

      if (i + m < argsize) {
        if (!*(arg + (i + m))) {
          goto while_break___15;
        }
      } else {
        goto while_break___15;
      }
      m++;
    };
  }
while_break___15:;
  goto while_break___14;
} else {
  { tmp___5 = iswprint((wint_t)w); }
  if (!tmp___5) {
    printable = 0;
  }
  m += bytes;
}
