

int fd_safer(int fd) {
  int f;
  int tmp;
  int e;
  int *tmp___0;
  int *tmp___1;

  {
    if (0 <= fd) {
      if (fd <= 2) {
        tmp = dup_safer(fd);
        f = tmp;
        tmp___0 = __errno_location();
        e = *tmp___0;
        close(fd);
        tmp___1 = __errno_location();
        *tmp___1 = e;
        fd = f;
      }
    }
    return (fd);
  }
}
