

have_dupfd_cloexec = 1;
}
else {
  result = rpl_fcntl(fd, 0, target);
