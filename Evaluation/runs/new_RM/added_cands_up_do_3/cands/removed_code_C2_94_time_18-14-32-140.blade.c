

sbp = p->fts_statp;
if (p->fts_level == 0L) {
  if (sp->fts_options & 1) {
    follow = (_Bool)1;
  }
}
if (sp->fts_options & 2) {
  goto _L;
} else {
  if (follow) {
  _L:
    tmp___3 = stat((char const *)p->fts_accpath, sbp);
    if (tmp___3) {
      tmp = __errno_location();
      saved_errno = *tmp;
      tmp___1 = __errno_location();
      if (*tmp___1 == 2) {
        tmp___2 = lstat((char const *)p->fts_accpath, sbp);
        if (tmp___2 == 0) {
          tmp___0 = __errno_location();
          *tmp___0 = 0;
          return ((unsigned short)13);
        }
      }
      p->fts_errno = saved_errno;
      goto err;
    }
  } else {
    tmp___5 = fstatat(sp->fts_cwd_fd, (char const *)p->fts_accpath, sbp, 256);
    if (tmp___5) {
      tmp___4 = __errno_location();
      p->fts_errno = *tmp___4;
    err:
      memset((void *)sbp, 0, sizeof(struct stat));
      return ((unsigned short)10);
    }
  }
}
