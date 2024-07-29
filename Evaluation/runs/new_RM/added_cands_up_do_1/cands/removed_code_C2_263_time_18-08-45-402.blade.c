

static _Bool leaf_optimization_applies(int dir_fd) {
  struct statfs fs_buf;
  int tmp;

  {
    tmp = fstatfs(dir_fd, &fs_buf);
    if (tmp != 0) {
      return ((_Bool)0);
    }
    if (fs_buf.f_type == 1382369651L) {
      goto case_1382369651;
    }
    goto switch_default;
  case_1382369651:
    return ((_Bool)1);
  switch_default:
    return ((_Bool)0);

    return ((_Bool)0);
  }
}
