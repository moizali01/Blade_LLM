

if ((unsigned long)dirp == (unsigned long)((void *)0)) {
  if (type == 3) {
    cur->fts_info = (unsigned short)4;
    tmp = __errno_location();
    cur->fts_errno = *tmp;
  }
  return ((FTSENT *)((void *)0));
}
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
if (type == 2) {
  nlinks = (nlink_t)0;
  nostat = (_Bool)0;
} else {
  if (sp->fts_options & 8) {
    if (sp->fts_options & 16) {
      if (sp->fts_options & 32) {
        tmp___4 = 0;
      } else {
        tmp___4 = 2;
      }
      nlinks = cur->fts_statp[0].st_nlink - (__nlink_t)tmp___4;
      nostat = (_Bool)1;
    } else {
      nlinks = (nlink_t)-1;
      nostat = (_Bool)0;
    }
  } else {
    nlinks = (nlink_t)-1;
    nostat = (_Bool)0;
  }
}
