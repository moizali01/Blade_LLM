

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
