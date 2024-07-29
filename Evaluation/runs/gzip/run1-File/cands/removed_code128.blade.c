

if (!to_stdout) {
  if (!force) {
    if (!quiet) {
      if (istat.st_nlink > 2UL) {
        tmp___1 = 's';
      } else {
        tmp___1 = ' ';
      }
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const * /* __restrict  */) "%s: %s has %d other "
                                                 "link%c -- unchanged\n",
                progname, ifname, (int)istat.st_nlink - 1, tmp___1);
      }
    }
    if (exit_code == 0) {
      exit_code = 2;
    }
    return;
  }
}
