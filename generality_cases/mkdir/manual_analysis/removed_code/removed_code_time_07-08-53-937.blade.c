

if (fail == 0) {
  if (specified_mode) {
    if (dir_created) {
      {
        fail = chmod(dir___0, newmode);
      }
      if (fail) {
        {
          tmp___9 = quote(dir___0);
          tmp___10 = gettext("cannot set permissions of directory %s");
          tmp___11 = __errno_location();
          error(0, *tmp___11, (char const *)tmp___10, tmp___9);
        }
      }
    }
  }
}
