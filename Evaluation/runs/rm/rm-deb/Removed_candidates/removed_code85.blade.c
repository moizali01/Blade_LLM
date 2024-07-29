

if ((unsigned long)ad_from_table != (unsigned long)ad) {
  free((void *)ad);
  if (!ad_from_table) {
    return ((_Bool)0);
  }
  ent->fts_cycle = ad_from_table->fts_ent;
  ent->fts_info = (unsigned short)2;
}
}
else {
  tmp___0 =
      cycle_check(fts->fts_cycle.state, (struct stat const *)(ent->fts_statp));
