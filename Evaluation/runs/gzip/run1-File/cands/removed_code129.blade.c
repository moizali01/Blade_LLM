

if ((istat.st_mode & 61440U) == 16384U) {
  if (recursive) {
    {
      st = istat;
      treat_dir(iname);
      reset_times(iname, &st);
    }
  } else {
    if (!quiet) {
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const
                     * /* __restrict  */) "%s: %s is a directory -- ignored\n",
                progname, ifname);
      }
    }
    if (exit_code == 0) {
      exit_code = 2;
    }
  }
  return;
}
if (!((istat.st_mode & 61440U) == 32768U)) {
  if (!quiet) {
    {
      fprintf((FILE * /* __restrict  */) stderr,
              (char const * /* __restrict  */) "%s: %s is not a directory or a "
                                               "regular file - ignored\n",
              progname, ifname);
    }
  }
  if (exit_code == 0) {
    exit_code = 2;
  }
  return;
}
