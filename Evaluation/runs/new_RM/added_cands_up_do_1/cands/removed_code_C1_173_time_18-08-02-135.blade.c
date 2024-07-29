

if ((sbp->st_mode & 61440U) == 16384U) {
  if (sp->fts_options & 32) {
    tmp___6 = 0;
  } else {
    tmp___6 = 2;
  }
  p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;
  if ((int)p->fts_name[0] == 46) {
    if (!p->fts_name[1]) {
      goto _L___0;
    } else {
      if ((int)p->fts_name[1] == 46) {
        if (!p->fts_name[2]) {
        _L___0:
          if (p->fts_level == 0L) {
            tmp___7 = 1;
          } else {
            tmp___7 = 5;
          }
          return ((unsigned short)tmp___7);
        }
      }
    }
  }
  return ((unsigned short)1);
}
