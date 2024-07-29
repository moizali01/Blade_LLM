

int set_cloexec_flag(int desc, _Bool value) {
  int flags;
  int tmp;
  int newflags;
  int tmp___0;
  int tmp___1;

  {
    tmp = rpl_fcntl(desc, 1, 0);
    flags = tmp;
    if (0 <= flags) {
      if (value) {
        tmp___0 = flags | 1;
      } else {
        tmp___0 = flags & -2;
      }
      newflags = tmp___0;
      if (flags == newflags) {
        return (0);
      } else {
        tmp___1 = rpl_fcntl(desc, 2, newflags);
        if (tmp___1 != -1) {
          return (0);
        }
      }
    }
    return (-1);
  }
}
