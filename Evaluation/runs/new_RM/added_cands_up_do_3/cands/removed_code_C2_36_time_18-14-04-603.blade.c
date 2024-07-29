

if (tmp___0 != 0) {
  return (-1);
}
if ((buf___1->st_mode & 61440U) == 40960U) {
  return (0);
}
tmp___1 = faccessat(fd_cwd, file, 2, 512);
