

if ((int)cur->fts_info == 11) {
  cur->fts_info = fts_stat(sp, cur, (_Bool)0);
} else {
  if (sp->fts_options & 256) {
    while (1) {
      leave_dir(sp, cur);
      goto while_break;
    }
  while_break:
    fts_stat(sp, cur, (_Bool)0);
    tmp___3 = enter_dir(sp, cur);
    if (!tmp___3) {
      tmp___2 = __errno_location();
      *tmp___2 = 12;
      return ((FTSENT *)((void *)0));
    }
  }
}
