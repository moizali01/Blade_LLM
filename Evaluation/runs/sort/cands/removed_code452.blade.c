

if (unibyte_locale) {
  m = (size_t)1;
  tmp___2 = __ctype_b_loc();
  printable = (_Bool)(((int const) * (*tmp___2 + (int)c) & 16384) != 0);
} else {
  memset((void *)(&mbstate), 0, sizeof(mbstate));
  m = (size_t)0;
  printable = (_Bool)1;
  if (argsize == 0xffffffffffffffffUL) {
    argsize = strlen(arg);
  }
  while (1) {
    tmp___3 = mbrtowc(&w, arg + (i + m), argsize - (i + m), &mbstate);
    bytes = tmp___3;
    if (bytes == 0UL) {
      goto while_break___14;
    } else {
      if (bytes == 0xffffffffffffffffUL) {
        printable = (_Bool)0;
        goto while_break___14;
      } else {
        if (bytes == 0xfffffffffffffffeUL) {
          printable = (_Bool)0;
          while (1) {

            if (i + m < argsize) {
              if (!*(arg + (i + m))) {
                goto while_break___15;
              }
            } else {
              goto while_break___15;
            }
            m++;
          }
        while_break___15:;
          goto while_break___14;
        } else {
          if (elide_outer_quotes) {
            if ((unsigned int)quoting_style == 2U) {
              j = (size_t)1;
              while (1) {

                if (!(j < bytes)) {
                  goto while_break___16;
                }
                if ((int const) * (arg + ((i + m) + j)) == 91) {
                  goto case_91___0;
                }
                if ((int const) * (arg + ((i + m) + j)) == 92) {
                  goto case_91___0;
                }
                if ((int const) * (arg + ((i + m) + j)) == 94) {
                  goto case_91___0;
                }
                if ((int const) * (arg + ((i + m) + j)) == 96) {
                  goto case_91___0;
                }
                if ((int const) * (arg + ((i + m) + j)) == 124) {
                  goto case_91___0;
                }
                goto switch_default___3;
              case_91___0:
                goto force_outer_quoting_style;
              switch_default___3:
                goto switch_break___3;
              switch_break___3:
                j++;
              }
            while_break___16:;
            }
          }
          tmp___4 = iswprint((wint_t)w);
          if (!tmp___4) {
            printable = (_Bool)0;
          }
          m += bytes;
        }
      }
    }
    tmp___5 = mbsinit((mbstate_t const *)(&mbstate));
    if (tmp___5) {
      goto while_break___14;
    }
  }
while_break___14:;
}
