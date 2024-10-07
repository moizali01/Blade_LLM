

if (i + 2UL < argsize) {
  if ((int const) * (arg + (i + 1UL)) == 63) {
    if ((int const) * (arg + (i + 2UL)) == 62) {
      goto case_62;
    }
    if ((int const) * (arg + (i + 2UL)) == 61) {
      goto case_62;
    }
    if ((int const) * (arg + (i + 2UL)) == 60) {
      goto case_62;
    }
    if ((int const) * (arg + (i + 2UL)) == 47) {
      goto case_62;
    }
    if ((int const) * (arg + (i + 2UL)) == 45) {
      goto case_62;
    }
    if ((int const) * (arg + (i + 2UL)) == 41) {
      goto case_62;
    }
    if ((int const) * (arg + (i + 2UL)) == 40) {
      goto case_62;
    }
    if ((int const) * (arg + (i + 2UL)) == 39) {
      goto case_62;
    }
    if ((int const) * (arg + (i + 2UL)) == 33) {
      goto case_62;
    }
    goto switch_break___2;
  case_62:
    c = (unsigned char)*(arg + (i + 2UL));
    i += 2UL;
    {
      while (1) {
        ;

        if (len < buffersize) {
          *(buffer + len) = (char)'?';
        }
        len++;
        goto while_break___8;
      };
    }
  while_break___8:;
    {
      while (1) {
        ;

        if (len < buffersize) {
          *(buffer + len) = (char)'\\';
        }
        len++;
        goto while_break___9;
      };
    }
  while_break___9:;
    {
      while (1) {
        ;

        if (len < buffersize) {
          *(buffer + len) = (char)'?';
        }
        len++;
        goto while_break___10;
      };
    }
  while_break___10:;
    goto switch_break___2;
  switch_break___2:;
  }
}
