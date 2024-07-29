

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
