

if (!(sp->fts_options & 4)) {
  if (sp->fts_options & 512) {
    if (sp->fts_options & 512) {
      tmp___5 = -100;
    } else {
      tmp___5 = sp->fts_rfd;
    }
    cwd_advance_fd(sp, tmp___5, (_Bool)1);
    tmp___8 = 0;
  } else {
    if (sp->fts_options & 512) {
      tmp___6 = -100;
    } else {
      tmp___6 = sp->fts_rfd;
    }
    tmp___7 = fchdir(tmp___6);
    tmp___8 = tmp___7;
  }
  if (tmp___8) {
    tmp___9 = 1;
  } else {
    tmp___9 = 0;
  }
} else {
  tmp___9 = 0;
}
