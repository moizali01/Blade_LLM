

if (fail) {
  {
    tmp___9 = quote(dir___0);
    tmp___10 = gettext("cannot set permissions of directory %s");
    tmp___11 = __errno_location();
    error(0, *tmp___11, (char const *)tmp___10, tmp___9);
  }
}
