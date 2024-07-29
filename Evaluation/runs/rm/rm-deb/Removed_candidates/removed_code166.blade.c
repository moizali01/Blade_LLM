

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
