

if (have_working_fchdir) {
  {
    cwd->desc = open(".", 65536);
  }
  if (cwd->desc < 0) {
    return (1);
  }
}
