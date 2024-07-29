

if ((int)tmpb == 45) {
  while (1) {
    b++;
    tmpb = (unsigned char)*b;
    if (!((int)tmpb == 48)) {
      if (!((int)tmpb == thousands_sep___0)) {
        goto while_break___11;
      }
    }
  }
while_break___11:;
  if ((int)tmpb == decimal_point___0) {
    while (1) {
      b++;
      tmpb = (unsigned char)*b;
      if (!((int)tmpb == 48)) {
        goto while_break___12;
      }
    }
  while_break___12:;
  }
  if ((unsigned int)tmpb - 48U <= 9U) {
    return ((int __attribute__((__pure__)))1);
  }
  while (1) {

    if (!((int)tmpa == 48)) {
      if (!((int)tmpa == thousands_sep___0)) {
        goto while_break___13;
      }
    }
    a++;
    tmpa = (unsigned char)*a;
  }
while_break___13:;
  if ((int)tmpa == decimal_point___0) {
    while (1) {
      a++;
      tmpa = (unsigned char)*a;
      if (!((int)tmpa == 48)) {
        goto while_break___14;
      }
    }
  while_break___14:;
  }
  return ((int __attribute__((__pure__)))((unsigned int)tmpa - 48U <= 9U));
} else {
  while (1) {

    if (!((int)tmpa == 48)) {
      if (!((int)tmpa == thousands_sep___0)) {
        goto while_break___15;
      }
    }
    a++;
    tmpa = (unsigned char)*a;
  }
while_break___15:;
  while (1) {

    if (!((int)tmpb == 48)) {
      if (!((int)tmpb == thousands_sep___0)) {
        goto while_break___16;
      }
    }
    b++;
    tmpb = (unsigned char)*b;
  }
while_break___16:;
  while (1) {

    if ((int)tmpa == (int)tmpb) {
      if (!((unsigned int)tmpa - 48U <= 9U)) {
        goto while_break___17;
      }
    } else {
      goto while_break___17;
    }
    while (1) {
      a++;
      tmpa = (unsigned char)*a;
      if (!((int)tmpa == thousands_sep___0)) {
        goto while_break___18;
      }
    }
  while_break___18:;
    while (1) {
      b++;
      tmpb = (unsigned char)*b;
      if (!((int)tmpb == thousands_sep___0)) {
        goto while_break___19;
      }
    }
  while_break___19:;
  }
while_break___17:;
  if ((int)tmpa == decimal_point___0) {
    if (!((unsigned int)tmpb - 48U <= 9U)) {
      tmp___2 = fraccompare(a, b, (char)decimal_point___0);
      return (tmp___2);
    } else {
      goto _L___0;
    }
  } else {
  _L___0:
    if ((int)tmpb == decimal_point___0) {
      if (!((unsigned int)tmpa - 48U <= 9U)) {
        tmp___2 = fraccompare(a, b, (char)decimal_point___0);
        return (tmp___2);
      }
    }
  }
  tmp = (int)tmpa - (int)tmpb;
  log_a = (size_t)0;
  while (1) {

    if (!((unsigned int)tmpa - 48U <= 9U)) {
      goto while_break___20;
    }
    while (1) {
      a++;
      tmpa = (unsigned char)*a;
      if (!((int)tmpa == thousands_sep___0)) {
        goto while_break___21;
      }
    }
  while_break___21:
    log_a++;
  }
while_break___20:
  log_b = (size_t)0;
  while (1) {

    if (!((unsigned int)tmpb - 48U <= 9U)) {
      goto while_break___22;
    }
    while (1) {
      b++;
      tmpb = (unsigned char)*b;
      if (!((int)tmpb == thousands_sep___0)) {
        goto while_break___23;
      }
    }
  while_break___23:
    log_b++;
  }
while_break___22:;
  if (log_a != log_b) {
    if (log_a < log_b) {
      tmp___3 = -1;
    } else {
      tmp___3 = 1;
    }
    return ((int __attribute__((__pure__)))tmp___3);
  }
  if (!log_a) {
    return ((int __attribute__((__pure__)))0);
  }
  return ((int __attribute__((__pure__)))tmp);
}
