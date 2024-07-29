

if ((int)instr == 2) {
  if ((int)p->fts_info == 12) {
    goto _L;
  } else {
    if ((int)p->fts_info == 13) {
    _L:
      p->fts_info = fts_stat(sp, p, (_Bool)1);
      if ((int)p->fts_info == 1) {
        if (!(sp->fts_options & 4)) {
          tmp___1 = diropen((FTS const *)sp, ".");
          p->fts_symfd = tmp___1;
          if (tmp___1 < 0) {
            tmp___0 = __errno_location();
            p->fts_errno = *tmp___0;
            p->fts_info = (unsigned short)7;
          } else {
            p->fts_flags = (unsigned short)((int)p->fts_flags | 2);
          }
        }
      }
      goto check_for_dir;
    }
  }
}
