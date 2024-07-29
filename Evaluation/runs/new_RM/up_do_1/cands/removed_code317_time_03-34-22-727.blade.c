

FTS *xfts_open(char *const *argv, int options,
               int (*compar)(FTSENT const **, FTSENT const **)) {
  FTS *fts;
  FTS *tmp;
  int *tmp___0;

  {
    tmp = fts_open(argv, options | 512, compar);
    fts = tmp;
    if ((unsigned long)fts == (unsigned long)((void *)0)) {
      tmp___0 = __errno_location();
      if (!(*tmp___0 != 22)) {
        __assert_fail("(*__errno_location ()) != 22",
                      "/home/khheo/project/benchmark/coreutils-8.4/lib/xfts.c",
                      41U, "xfts_open");
      }
      xalloc_die();
    }
    return (fts);
  }
}
