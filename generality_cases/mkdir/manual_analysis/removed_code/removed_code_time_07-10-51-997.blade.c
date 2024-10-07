

if (do_chdir) {
  {
    tmp___50 = restore_cwd((struct saved_cwd const *)(&cwd));
  }
  if (tmp___50 != 0) {
    {
      tmp___46 = __errno_location();
      _saved_errno___3 = *tmp___46;
      tmp___47 = gettext("failed to return to initial working directory");
      tmp___48 = __errno_location();
      error(0, *tmp___48, (char const *)tmp___47);
      free_cwd(&cwd);
      tmp___49 = __errno_location();
      *tmp___49 = _saved_errno___3;
    }
    return (1);
  }
  { free_cwd(&cwd); }
}
