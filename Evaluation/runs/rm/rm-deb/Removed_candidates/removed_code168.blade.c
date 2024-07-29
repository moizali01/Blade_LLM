

p = base;
while (1) {

  if (!*p) {
    goto while_break___0;
  }
  if ((int const) * p == 47) {
    saw_slash = (_Bool)1;
  } else {
    if (saw_slash) {
      base = p;
      saw_slash = (_Bool)0;
    }
  }
  p++;
}
while_break___0:
