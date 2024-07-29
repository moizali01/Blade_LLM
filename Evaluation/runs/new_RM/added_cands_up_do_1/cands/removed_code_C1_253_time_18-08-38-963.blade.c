

static int fts_compare_ino(struct _ftsent const **a, struct _ftsent const **b) {
  int tmp;
  int tmp___0;

  {
    if ((*(a + 0))->fts_statp[0].st_ino < (*(b + 0))->fts_statp[0].st_ino) {
      tmp___0 = -1;
    } else {
      if ((*(b + 0))->fts_statp[0].st_ino < (*(a + 0))->fts_statp[0].st_ino) {
        tmp = 1;
      } else {
        tmp = 0;
      }
      tmp___0 = tmp;
    }
    return (tmp___0);
  }
}
