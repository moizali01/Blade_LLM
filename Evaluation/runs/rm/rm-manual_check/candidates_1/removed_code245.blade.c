

if ((unsigned long)dirp == (unsigned long)((void *)0)) {
  if (type == 3) {
    cur->fts_info = (unsigned short)4;
    tmp = __errno_location();
    cur->fts_errno = *tmp;
  }
  return ((FTSENT *)((void *)0));
}
