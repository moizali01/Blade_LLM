

extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__))
                                     unlinkat)(int __fd, char const *__name,
                                               int __flag);
__inline static int lstatat(int fd, char const *name, struct stat *st) {
  int tmp;

  {
    tmp = fstatat(fd, name, st, 256);
    return (tmp);
  }
}
