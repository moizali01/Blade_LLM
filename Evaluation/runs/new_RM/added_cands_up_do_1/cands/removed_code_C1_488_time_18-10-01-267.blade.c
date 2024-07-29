

char *last_component(char const *name) {
  char const *base;
  char const *p;
  _Bool saw_slash;

  {
    base = name + 0;
    saw_slash = (_Bool)0;
    while (1) {

      if (!((int const) * base == 47)) {
        goto while_break;
      }
      base++;
    }
  while_break:
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
  while_break___0:;
    return ((char *)base);
  }
}
