

void *xrealloc(void *p, size_t n) {

  {
    p = realloc(p, n);
    if (!p) {
      if (n != 0UL) {
        xalloc_die();
      }
    }
    return (p);
  }
}
