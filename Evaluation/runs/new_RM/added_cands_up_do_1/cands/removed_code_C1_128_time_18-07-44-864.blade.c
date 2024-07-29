

if ((unsigned long)p == (unsigned long)((void *)0)) {
  free((void *)sp->fts_path);
  sp->fts_path = (char *)((void *)0);
  return ((_Bool)0);
}
