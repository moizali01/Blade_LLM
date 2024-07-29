

static int fts_compar(void const *a, void const *b) {
  FTSENT const **pa;
  FTSENT const **pb;
  int tmp;

  {
    pa = (FTSENT const **)a;
    pb = (FTSENT const **)b;
    tmp = (*(((*(pa + 0))->fts_fts)->fts_compar))(pa, pb);
    return (tmp);
  }
}
