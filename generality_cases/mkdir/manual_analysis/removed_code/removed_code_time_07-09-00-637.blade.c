

if (!dir_created) {
  {
    tmp___6 = quote(dir___0);
    tmp___7 = gettext("cannot create directory %s");
    error(0, 17, (char const *)tmp___7, tmp___6);
    fail = 1;
  }
} else {
  goto _L;
}
