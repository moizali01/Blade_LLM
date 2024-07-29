

if (sp->fts_options & 2) {
  goto _L;
} else {
  if (dir) {
    tmp___4 = strcmp(dir, "..");
    if (tmp___4 == 0) {
    _L:
      tmp___2 = fstat(newfd, &sb);
      if (tmp___2) {
        ret = -1;
        goto bail;
      }
      if (p->fts_statp[0].st_dev != sb.st_dev) {
        tmp___3 = __errno_location();
        *tmp___3 = 2;
        ret = -1;
        goto bail;
      } else {
        if (p->fts_statp[0].st_ino != sb.st_ino) {
          tmp___3 = __errno_location();
          *tmp___3 = 2;
          ret = -1;
          goto bail;
        }
      }
    }
  }
}
if (sp->fts_options & 512) {
  cwd_advance_fd(sp, newfd, (_Bool)(!is_dotdot));
  return (0);
}
ret = fchdir(newfd);
