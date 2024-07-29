

if (i + 2UL < argsize) {
  if ((int const) * (arg + (i + 1UL)) == 63) {
    if ((int const) * (arg + (i + 2UL)) == 33) {
      goto case_33;
    }
    if ((int const) * (arg + (i + 2UL)) == 39) {
      goto case_33;
    }
    if ((int const) * (arg + (i + 2UL)) == 40) {
      goto case_33;
    }
    if ((int const) * (arg + (i + 2UL)) == 41) {
      goto case_33;
    }
    if ((int const) * (arg + (i + 2UL)) == 45) {
      goto case_33;
    }
    if ((int const) * (arg + (i + 2UL)) == 47) {
      goto case_33;
    }
    if ((int const) * (arg + (i + 2UL)) == 60) {
      goto case_33;
    }
    if ((int const) * (arg + (i + 2UL)) == 61) {
      goto case_33;
    }
    if ((int const) * (arg + (i + 2UL)) == 62) {
      goto case_33;
    }
    goto switch_default___0;
  case_33:
    if (elide_outer_quotes) {
      goto force_outer_quoting_style;
    }
    c = (unsigned char)*(arg + (i + 2UL));
    i += 2UL;
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char)'?';
      }
      len++;
      goto while_break___7;
    }
  while_break___7:;
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char)'\"';
      }
      len++;
      goto while_break___8;
    }
  while_break___8:;
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char)'\"';
      }
      len++;
      goto while_break___9;
    }
  while_break___9:;
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char)'?';
      }
      len++;
      goto while_break___10;
    }
  while_break___10:;
    goto switch_break___2;
  switch_default___0:
    goto switch_break___2;
  switch_break___2:;
  }
}
