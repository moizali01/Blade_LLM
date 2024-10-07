

if (tmp___54) {
  {
    tmp___51 = quote((char const *)dirpath);
    tmp___52 = gettext("cannot change permissions of %s");
    tmp___53 = __errno_location();
    error(0, *tmp___53, (char const *)tmp___52, tmp___51);
    retval = 1;
  }
}
