

if (flags < 0) {
  goto _L;
} else {
  tmp___4 = fcntl(result, 2, flags | 1);
  if (tmp___4 == -1) {
  _L:
    tmp___2 = __errno_location();
    saved_errno = *tmp___2;
    close(result);
    tmp___3 = __errno_location();
    *tmp___3 = saved_errno;
    result = -1;
  }
}
