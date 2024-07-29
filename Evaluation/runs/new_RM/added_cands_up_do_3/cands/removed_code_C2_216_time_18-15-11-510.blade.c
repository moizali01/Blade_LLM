

extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(1), __leaf__))
                                     rpmatch)(char const *__response);
extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n,
                         FILE *__restrict __stream);
_Bool yesno(void) {
  _Bool yes;
  char *response;
  size_t response_size;
  ssize_t response_len;
  ssize_t tmp;
  int tmp___0;

  {
    response = (char *)((void *)0);
    response_size = (size_t)0;
    tmp = getline(&response, &response_size, stdin);
    response_len = tmp;
    if (response_len <= 0L) {
      yes = (_Bool)0;
    } else {
      *(response + (response_len - 1L)) = (char)'\000';
      tmp___0 = rpmatch((char const *)response);
      yes = (_Bool)(0 < tmp___0);
    }
    free((void *)response);
    return (yes);
  }
}
