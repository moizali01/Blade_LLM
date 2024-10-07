

if (tmp___9 != 0) {
  {
    tmp___5 = __errno_location();
    _saved_errno = *tmp___5;
    tmp___6 = gettext("failed to return to initial working directory");
    tmp___7 = __errno_location();
    error(0, *tmp___7, (char const *)tmp___6);
    free_cwd(&cwd);
    tmp___8 = __errno_location();
    *tmp___8 = _saved_errno;
  }
  return (1);
}
