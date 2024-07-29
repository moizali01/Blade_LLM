

__inline static int lstatat(int fd, char const *name, struct stat *st) {
  int tmp;

  {
    tmp = fstatat(fd, name, st, 256);
    return (tmp);
  }
}
