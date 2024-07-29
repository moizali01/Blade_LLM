

static char const *file_name___0;
void close_stdin(void) {
  _Bool fail;
  int tmp;
  int tmp___0;
  size_t tmp___1;
  int tmp___2;
  char const *close_error;
  char const *tmp___3;
  char *tmp___4;
  int *tmp___5;
  int *tmp___6;

  {
    fail = (_Bool)0;
    tmp___1 = freadahead(stdin);
    if (tmp___1 > 0UL) {
      tmp = rpl_fseeko(stdin, (off_t)0, 1);
      if (tmp == 0) {
        tmp___0 = rpl_fflush(stdin);
        if (tmp___0 != 0) {
          fail = (_Bool)1;
        }
      }
    }
    tmp___2 = close_stream(stdin);
    if (tmp___2 != 0) {
      fail = (_Bool)1;
    }
    if (fail) {
      tmp___3 = (char const *)gettext("error closing file");
      close_error = tmp___3;
      if (file_name___0) {
        tmp___4 = quotearg_colon(file_name___0);
        tmp___5 = __errno_location();
        error(0, *tmp___5, "%s: %s", tmp___4, close_error);
      } else {
        tmp___6 = __errno_location();
        error(0, *tmp___6, "%s", close_error);
      }
    }
    close_stdout();
    if (fail) {
      _exit((int)exit_failure);
    }
    return;
  }
}
extern __attribute__((__nothrow__))
size_t(__attribute__((__leaf__)) __fpending)(FILE *__fp);
