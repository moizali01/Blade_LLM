

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
void argmatch_valid(char const *const *arglist, char const *vallist,
                    size_t valsize) {
  size_t i;
  char const *last_val;
  char *tmp;
  int tmp___0;

  {
    last_val = (char const *)((void *)0);
    tmp = gettext("Valid arguments are:");
    fprintf(stderr, (char const *)tmp);
    i = (size_t)0;
    while (1) {

      if (!*(arglist + i)) {
        goto while_break;
      }
      if (i == 0UL) {
        fprintf(stderr, "\n  - `%s\'", *(arglist + i));
        last_val = vallist + valsize * i;
      } else {
        tmp___0 = memcmp((void const *)last_val,
                         (void const *)(vallist + valsize * i), valsize);
        if (tmp___0) {
          fprintf(stderr, "\n  - `%s\'", *(arglist + i));
          last_val = vallist + valsize * i;
        } else {
          fprintf(stderr, ", `%s\'", *(arglist + i));
        }
      }
      i++;
    }
  while_break:
    putc_unlocked('\n', stderr);
    return;
  }
}
ptrdiff_t __xargmatch_internal(char const *context, char const *arg,
                               char const *const *arglist, char const *vallist,
                               size_t valsize, void (*exit_fn)(void)) {
  ptrdiff_t res;
  ptrdiff_t tmp;

  {
    tmp = argmatch(arg, arglist, vallist, valsize);
    res = tmp;
    if (res >= 0L) {
      return (res);
    }
    argmatch_invalid(context, arg, res);
    argmatch_valid(arglist, vallist, valsize);
    (*exit_fn)();
    return ((ptrdiff_t)-1);
  }
}
extern
    __attribute__((__nothrow__)) void *(__attribute__((__warn_unused_result__,
                                                       __leaf__))
                                        realloc)(void *__ptr, size_t __size);
