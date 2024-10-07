

if (tmp___64) {
  {
    tmp___61 = quote(dirpath___0);
    tmp___62 = gettext("cannot change permissions of %s");
    tmp___63 = __errno_location();
    error(0, *tmp___63, (char const *)tmp___62, tmp___61);
    retval = 1;
  }
}
