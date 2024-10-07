

if (!created_dir) {
  {
    tmp___0 = __errno_location();
    saved_errno = *tmp___0;
    tmp___5 = stat((char const * /* __restrict  */)dir,
                   (struct stat * /* __restrict  */)(&stats));
  }
  if (tmp___5) {
    {
      tmp___1 = quote(dirpath);
      tmp___2 = gettext("cannot create directory %s");
      error(0, saved_errno, (char const *)tmp___2, tmp___1);
      fail = 1;
    }
  } else {
    if (!((stats.st_mode & 61440U) == 16384U)) {
      {
        tmp___3 = quote(dirpath);
        tmp___4 = gettext("%s exists but is not a directory");
        error(0, 0, (char const *)tmp___4, tmp___3);
        fail = 1;
      }
    }
  }
}
