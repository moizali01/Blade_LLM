

if (0 <= (int)cwd->desc) {
  {
    tmp = fchdir((int)cwd->desc);
  }
  return (tmp < 0);
} else {
  { tmp___0 = chdir((char const *)cwd->name); }
  return (tmp___0 < 0);
}
