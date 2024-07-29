

tmp = can_write_any_file();
if (tmp) {
  return (0);
}
tmp___0 = cache_fstatat(fd_cwd, file, buf___1, 256);
