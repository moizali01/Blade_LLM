

if (tmp___4 == 0) {
  if (x->verbose) {
    tmp___0 = quote((char const *)ent->fts_path);
    if (is_dir) {
      tmp___1 = gettext("removed directory: %s\n");
      tmp___3 = tmp___1;
    } else {
      tmp___2 = gettext("removed %s\n");
      tmp___3 = tmp___2;
    }
    printf((char const *)tmp___3, tmp___0);
  }
  return ((enum RM_status)2);
}
