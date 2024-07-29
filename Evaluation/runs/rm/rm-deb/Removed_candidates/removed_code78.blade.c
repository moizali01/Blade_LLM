

if (0 <= fd) {
  set_cloexec_flag(fd, (_Bool)1);
}
return (fd);
