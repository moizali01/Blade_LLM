

while (1) {
  ;

  if (!*p) {
    goto while_break;
  }
  if ((int const) * p == 47) {
    {
      while (1) {
        ;
        p++;
        if (!((int const) * p == 47)) {
          goto while_break___0;
        }
      };
    }
  while_break___0:;
    if (!*p) {
      if ((int const) * base == 47) {
        base = p - 1;
      }
      goto while_break;
    }
    base = p;
  }
  p++;
};
