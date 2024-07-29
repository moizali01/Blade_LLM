

size_t hash_pjw(void const *x, size_t tablesize) {
  char const *s;
  size_t h;

  {
    h = (size_t)0;
    s = (char const *)x;
    while (1) {

      if (!*s) {
        goto while_break;
      }
      h = (unsigned long)*s + ((h << 9) | (h >> (sizeof(size_t) * 8UL - 9UL)));
      s++;
    }
  while_break:;
    return (h % tablesize);
  }
}
