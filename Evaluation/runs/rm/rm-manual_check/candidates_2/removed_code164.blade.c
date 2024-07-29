

static int cache_fstatat(int fd, char const *file, struct stat *st, int flag) {
  int *tmp;
  int tmp___0;
  int *tmp___1;

  {
    if (st->st_size == -1L) {
      tmp___0 = fstatat(fd, file, st, flag);
      if (tmp___0 != 0) {
        st->st_size = (__off_t)-2;
        tmp = __errno_location();
        st->st_ino = (__ino_t)*tmp;
      }
    }
    if (0L <= st->st_size) {
      return (0);
    }
    tmp___1 = __errno_location();
    *tmp___1 = (int)st->st_ino;
    return (-1);
  }
}
