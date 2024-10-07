

if (0 <= e) {
  {
    tmp___5 = gettext("write error");
    write_error = (char const *)tmp___5;
  }
  if (file_name) {
    {
      tmp___6 = quotearg_colon(file_name);
      error((int)exit_failure, e, "%s: %s", tmp___6, write_error);
    }
  } else {
    { error((int)exit_failure, e, "%s", write_error); }
  }
}
