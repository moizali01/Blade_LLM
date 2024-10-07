

if (!((stats.st_mode & 61440U) == 16384U)) {
  {
    tmp___3 = quote(dirpath);
    tmp___4 = gettext("%s exists but is not a directory");
    error(0, 0, (char const *)tmp___4, tmp___3);
    fail = 1;
  }
}
