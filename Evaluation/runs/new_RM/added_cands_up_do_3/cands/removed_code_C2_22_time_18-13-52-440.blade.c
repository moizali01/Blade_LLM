

static void diagnose_leading_hyphen(int argc, char **argv) {
  int i;
  char const *arg;
  struct stat st;
  char const *tmp;
  char *tmp___0;
  char *tmp___1;
  int tmp___2;

  {
    i = 1;
    while (1) {

      if (!(i < argc)) {
        goto while_break;
      }
      arg = (char const *)*(argv + i);
      if ((int const) * (arg + 0) == 45) {
        if (*(arg + 1)) {
          tmp___2 = lstat(arg, &st);
          if (tmp___2 == 0) {
            tmp = quote(arg);
            tmp___0 = quotearg_n_style(1, (enum quoting_style)1, arg);
            tmp___1 = gettext("Try `%s ./%s\' to remove the file %s.\n");
            fprintf(stderr, (char const *)tmp___1, *(argv + 0), tmp___0, tmp);
            goto while_break;
          }
        }
      }
      i++;
    }
  while_break:;
    return;
  }
}
__attribute__((__noreturn__)) void usage(int status);
