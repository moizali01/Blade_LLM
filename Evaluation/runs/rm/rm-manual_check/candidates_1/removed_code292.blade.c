

if (p->fts_level == -1L) {
  free((void *)p);
  tmp___17 = __errno_location();
  *tmp___17 = 0;
  tmp___18 = (struct _ftsent *)((void *)0);
  sp->fts_cur = tmp___18;
  return (tmp___18);
}
