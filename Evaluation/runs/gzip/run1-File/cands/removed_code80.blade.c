

if (verbose) {
  {
    fprintf((FILE * /* __restrict  */) stderr,
            (char const * /* __restrict  */) "%s: %s already has %s "
                                             "suffix -- unchanged\n",
            progname, ifname, suff);
  }
} else {
  if (!recursive) {
    if (!quiet) {
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const * /* __restrict  */) "%s: %s already has %s "
                                                 "suffix -- unchanged\n",
                progname, ifname, suff);
      }
    }
  }
}
if (exit_code == 0) {
  exit_code = 2;
}
return (2);
