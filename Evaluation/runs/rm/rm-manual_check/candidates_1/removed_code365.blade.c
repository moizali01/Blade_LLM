

if (defer_stat) {
  if ((unsigned long)root != (unsigned long)((void *)0)) {
    p->fts_info = (unsigned short)11;
    fts_set_stat_required(p, (_Bool)1);
  } else {
    p->fts_info = fts_stat(sp, p, (_Bool)0);
  }
} else {
  p->fts_info = fts_stat(sp, p, (_Bool)0);
}
