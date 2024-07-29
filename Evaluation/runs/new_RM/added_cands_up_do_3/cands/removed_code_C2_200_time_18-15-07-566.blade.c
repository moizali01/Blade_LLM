

size_t strnlen1(char const *string, size_t maxlen) {
  char const *end;
  char const *tmp;

  {
    tmp = (char const *)memchr((void const *)string, '\000', maxlen);
    end = tmp;
    if ((unsigned long)end != (unsigned long)((void *)0)) {
      return ((size_t)((end - string) + 1L));
    } else {
      return (maxlen);
    }
  }
}
_Bool strip_trailing_slashes(char *file);
