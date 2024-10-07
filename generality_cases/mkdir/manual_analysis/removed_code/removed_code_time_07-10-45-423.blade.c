

if (!((stats.st_mode & 61440U) == 16384U)) {
  {
    tmp___55 = quote(dirpath___0);
    tmp___56 = gettext("%s exists but is not a directory");
    error(0, 0, (char const *)tmp___56, tmp___55);
  }
  return (1);
}
