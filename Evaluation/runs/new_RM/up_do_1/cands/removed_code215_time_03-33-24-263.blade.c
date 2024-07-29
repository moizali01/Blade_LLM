

static _Bool dirent_inode_sort_may_be_useful(int dir_fd) {
  struct statfs fs_buf;
  int tmp;

  {
    tmp = fstatfs(dir_fd, &fs_buf);
    if (tmp != 0) {
      return ((_Bool)1);
    }
    if (fs_buf.f_type == 16914836L) {
      goto case_16914836;
    }
    if (fs_buf.f_type == 26985L) {
      goto case_16914836;
    }
    goto switch_default;
  case_16914836:
    return ((_Bool)0);
  switch_default:
    return ((_Bool)1);

    return ((_Bool)0);
  }
}
