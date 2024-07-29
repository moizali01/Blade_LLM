

#pragma weak pthread_key_create
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_key_delete
#pragma weak pthread_self
#pragma weak pthread_cancel
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
