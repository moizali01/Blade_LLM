

if (prompt_once) {
  if (x.recursive) {
    goto _L;
  } else {
    if (3UL < n_files) {
    _L:
      if (x.recursive) {
        tmp___4 = gettext("%s: remove all arguments recursively? ");
        tmp___6 = tmp___4;
      } else {
        tmp___5 = gettext("%s: remove all arguments? ");
        tmp___6 = tmp___5;
      }
      fprintf(stderr, (char const *)tmp___6, program_name);
      tmp___7 = yesno();
      if (!tmp___7) {
        exit(0);
      }
    }
  }
}
