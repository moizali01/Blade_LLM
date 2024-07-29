

__inline static char *xcharalloc(size_t n) {
  void *tmp;
  void *tmp___0;
  void *tmp___1;

  {
    if (sizeof(char) == 1UL) {
      tmp = xmalloc(n);
      tmp___1 = tmp;
    } else {
      tmp___0 = xnmalloc(n, sizeof(char));
      tmp___1 = tmp___0;
    }
    return ((char *)tmp___1);
  }
}
