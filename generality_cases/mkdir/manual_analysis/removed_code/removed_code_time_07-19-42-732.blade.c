

if (!have_working_fchdir) {
  {
    cwd->name = xgetcwd();
  }
  if ((unsigned long)cwd->name == (unsigned long)((void *)0)) {
    return (1);
  }
}
