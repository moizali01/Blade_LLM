

if (tmp___41) {
  {
    tmp___38 = quote((char const *)dirpath);
    tmp___39 = gettext("cannot change owner and/or group of %s");
    tmp___40 = __errno_location();
    error(0, *tmp___40, (char const *)tmp___39, tmp___38);
    retval = 1;
  }
}
