

if (tmp___6 != 0) {
  tmp___4 = gettext("fts_close failed");
  tmp___5 = __errno_location();
  error(0, *tmp___5, (char const *)tmp___4);
  rm_status = (enum RM_status)4;
}
