

if (tmp) {
  if (!((statb->st_mode & 61440U) == 16384U)) {
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
      { perror((char const *)(ofname)); }
    }
  }
}
return;
