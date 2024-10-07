

if (do_chdir) {
  {
    tmp___35 = restore_cwd((struct saved_cwd const *)(&cwd));
  }
  if (tmp___35 != 0) {
    {
      tmp___31 = __errno_location();
      _saved_errno___2 = *tmp___31;
      tmp___32 = gettext("failed to return to initial working directory");
      tmp___33 = __errno_location();
      error(0, *tmp___33, (char const *)tmp___32);
      free_cwd(&cwd);
      tmp___34 = __errno_location();
      *tmp___34 = _saved_errno___2;
    }
    return (1);
  }
  { free_cwd(&cwd); }
}
