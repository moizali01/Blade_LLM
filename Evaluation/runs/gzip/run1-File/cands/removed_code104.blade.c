

if (tmp___0 != 0) {
  {
    fprintf((FILE * /* __restrict  */) stderr,
            (char const * /* __restrict  */) "%s: ", progname);
    perror((char const *)(ofname));
    close(ifd);
    close(ofd);
    unlink((char const *)(ofname));
    exit_code = 1;
  }
  return (1);
}
{ tmp___1 = name_too_long(ofname, &ostat); }
if (!tmp___1) {
  return (0);
}
