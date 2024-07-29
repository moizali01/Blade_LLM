

if (ugkey.ignore) {
  if ((unsigned long)ugkey.ignore == (unsigned long)key->ignore) {
    ugkey.ignore = (_Bool const *)((void *)0);
  }
}
