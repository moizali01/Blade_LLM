

tmp = chmod((char const *)(ofname), ifstat->st_mode & 4095U);
}
if (tmp) {
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
{
  chown((char const *)(ofname), ifstat->st_uid, ifstat->st_gid);
