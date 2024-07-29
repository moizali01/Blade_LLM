

if (0 <= have_dupfd_cloexec) {
  result = fcntl(fd, action, target);
  if (0 <= result) {
    have_dupfd_cloexec = 1;
  } else {
    tmp___0 = __errno_location();
    if (*tmp___0 != 22) {
      have_dupfd_cloexec = 1;
    } else {
      result = rpl_fcntl(fd, 0, target);
      if (result < 0) {
        goto switch_break;
      }
      have_dupfd_cloexec = -1;
    }
  }
} else {
  result = rpl_fcntl(fd, 0, target);
}
