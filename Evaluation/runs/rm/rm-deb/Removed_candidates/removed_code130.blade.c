

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
}
else {
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
