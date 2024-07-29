

if (fd < 0) {
  newfd = diropen((FTS const *)sp, dir);
  if (newfd < 0) {
    return (-1);
  }
}
