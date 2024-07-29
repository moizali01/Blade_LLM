

if ((int)p->fts_instr == 2) {
  p->fts_info = fts_stat(sp, p, (_Bool)1);
  if ((int)p->fts_info == 1) {
    if (!(sp->fts_options & 4)) {
      tmp___11 = diropen((FTS const *)sp, ".");
      p->fts_symfd = tmp___11;
      if (tmp___11 < 0) {
        tmp___10 = __errno_location();
        p->fts_errno = *tmp___10;
        p->fts_info = (unsigned short)7;
      } else {
        p->fts_flags = (unsigned short)((int)p->fts_flags | 2);
      }
    }
  }
  p->fts_instr = (unsigned short)3;
}
