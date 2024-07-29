

if ((unsigned long)dirp == (unsigned long)((void *)0)) {
  {
    fprintf((FILE * /* __restrict  */) stderr,
            (char const * /* __restrict  */) "%s: %s unreadable\n", progname,
            dir);
    exit_code = 1;
  }
  return;
}
