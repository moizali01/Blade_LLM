

while (1) {
  ;

  if (do_chdir) {
    {
      tmp___18 = restore_cwd((struct saved_cwd const *)(&cwd));
    }
    if (tmp___18 != 0) {
      {
        tmp___14 = __errno_location();
        _saved_errno___0 = *tmp___14;
        tmp___15 = gettext("failed to return to "
                           "initial working directory");
        tmp___16 = __errno_location();
        error(0, *tmp___16, (char const *)tmp___15);
        free_cwd(&cwd);
        tmp___17 = __errno_location();
        *tmp___17 = _saved_errno___0;
      }
      return (1);
    }
    { free_cwd(&cwd); }
  }
  goto while_break___4;
};
