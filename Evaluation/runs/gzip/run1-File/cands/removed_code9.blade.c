

if (tmp___0) {
  if (!quiet) {
    {
      fprintf((FILE * /* __restrict  */) stderr,
              (char const * /* __restrict  */) "%s: ", progname);
    }
  }
  if (exit_code == 0) {
    exit_code = 2;
  }
  if (!quiet) {
    { perror((char const *)(ifname)); }
  }
}
return;
