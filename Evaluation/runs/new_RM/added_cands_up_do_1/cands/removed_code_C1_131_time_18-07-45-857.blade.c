

if (new_len < sp->fts_pathlen) {
  free((void *)sp->fts_path);
  sp->fts_path = (char *)((void *)0);
  tmp = __errno_location();
  *tmp = 36;
  return ((_Bool)0);
}
