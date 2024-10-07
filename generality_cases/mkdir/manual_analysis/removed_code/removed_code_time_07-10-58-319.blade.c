

if (mode & ~((448 | (448 >> 3)) | ((448 >> 3) >> 3))) {
  {
    tmp___45 = chmod((char const *)basename_dir, (__mode_t)mode);
  }
  if (tmp___45) {
    {
      tmp___42 = quote((char const *)dirpath);
      tmp___43 = gettext("cannot change permissions of %s");
      tmp___44 = __errno_location();
      error(0, *tmp___44, (char const *)tmp___43, tmp___42);
      retval = 1;
    }
  }
}
