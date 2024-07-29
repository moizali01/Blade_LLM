

int open_safer(char const *file, int flags, ...) {
  mode_t mode;
  va_list ap;
  int tmp;
  int tmp___0;

  {
    mode = (mode_t)0;
    if (flags & 64) {
      __builtin_va_start(ap, flags);
      mode = __builtin_va_arg(ap, mode_t);
      __builtin_va_end(ap);
    }
    tmp = open(file, flags, mode);
    tmp___0 = fd_safer(tmp);
    return (tmp___0);
  }
}
