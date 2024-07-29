

if (tab != 128) {
  while (1) {

    if ((unsigned long)ptr < (unsigned long)lim) {
      tmp = eword;
      eword--;
      if (!tmp) {
        goto while_break;
      }
    } else {
      goto while_break;
    }
    while (1) {

      if ((unsigned long)ptr < (unsigned long)lim) {
        if (!((int)*ptr != tab)) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      ptr++;
    }
  while_break___0:;
    if ((unsigned long)ptr < (unsigned long)lim) {
      if (eword) {
        ptr++;
      } else {
        if (echar) {
          ptr++;
        }
      }
    }
  }
while_break:;
} else {
  while (1) {

    if ((unsigned long)ptr < (unsigned long)lim) {
      tmp___2 = eword;
      eword--;
      if (!tmp___2) {
        goto while_break___1;
      }
    } else {
      goto while_break___1;
    }
    while (1) {

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp___0 = to_uchar(*ptr);
        if (!blanks[tmp___0]) {
          goto while_break___2;
        }
      } else {
        goto while_break___2;
      }
      ptr++;
    }
  while_break___2:;
    while (1) {

      if ((unsigned long)ptr < (unsigned long)lim) {
        tmp___1 = to_uchar(*ptr);
        if (blanks[tmp___1]) {
          goto while_break___3;
        }
      } else {
        goto while_break___3;
      }
      ptr++;
    }
  while_break___3:;
  }
while_break___1:;
}
