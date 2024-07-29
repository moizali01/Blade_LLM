

ptrdiff_t argmatch(char const *arg, char const *const *arglist,
                   char const *vallist, size_t valsize) {
  size_t i;
  size_t arglen;
  ptrdiff_t matchind;
  _Bool ambiguous;
  int tmp;
  size_t tmp___0;
  int tmp___1;

  {
    matchind = (ptrdiff_t)-1;
    ambiguous = (_Bool)0;
    arglen = strlen(arg);
    i = (size_t)0;
    while (1) {

      if (!*(arglist + i)) {
        goto while_break;
      }
      tmp___1 = strncmp((char const *)*(arglist + i), arg, arglen);
      if (!tmp___1) {
        tmp___0 = strlen((char const *)*(arglist + i));
        if (tmp___0 == arglen) {
          return ((ptrdiff_t)i);
        } else {
          if (matchind == -1L) {
            matchind = (ptrdiff_t)i;
          } else {
            if ((unsigned long)vallist == (unsigned long)((void *)0)) {
              ambiguous = (_Bool)1;
            } else {
              tmp = memcmp((void const *)(vallist + valsize * (size_t)matchind),
                           (void const *)(vallist + valsize * i), valsize);
              if (tmp) {
                ambiguous = (_Bool)1;
              }
            }
          }
        }
      }
      i++;
    }
  while_break:;
    if (ambiguous) {
      return ((ptrdiff_t)-2);
    } else {
      return (matchind);
    }
  }
}
void argmatch_invalid(char const *context, char const *value,
                      ptrdiff_t problem) {
  char const *format;
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char const *tmp___2;
  char *tmp___3;

  {
    if (problem == -1L) {
      tmp = gettext("invalid argument %s for %s");
      tmp___1 = tmp;
    } else {
      tmp___0 = gettext("ambiguous argument %s for %s");
      tmp___1 = tmp___0;
    }
    format = (char const *)tmp___1;
    tmp___2 = quote_n(1, context);
    tmp___3 = quotearg_n_style(0, (enum quoting_style)6, value);
    error(0, 0, format, tmp___3, tmp___2);
    return;
  }
}
