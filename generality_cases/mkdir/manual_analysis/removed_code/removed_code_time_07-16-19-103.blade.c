

while (1) {
  ;
  {
    tmp___4 =
        mbrtowc((wchar_t * /* __restrict  */)(&w),
                (char const * /* __restrict  */)(arg + (i + m)),
                argsize - (i + m), (mbstate_t * /* __restrict  */)(&mbstate));
    bytes = tmp___4;
  }
  if (bytes == 0UL) {
    goto while_break___14;
  } else {
    if (bytes == 0xffffffffffffffffUL) {
      printable = 0;
      goto while_break___14;
    } else {
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
    }
  }
  { tmp___6 = mbsinit((mbstate_t const *)(&mbstate)); }
  if (tmp___6) {
    goto while_break___14;
  }
};
