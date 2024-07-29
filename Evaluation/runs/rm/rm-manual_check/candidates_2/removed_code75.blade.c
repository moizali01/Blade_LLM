

if ((int)ent->fts_info == 6) {
  if (x->one_file_system) {
    if (0L < ent->fts_level) {
      if (ent->fts_statp[0].st_dev != fts->fts_dev) {
        mark_ancestor_dirs(ent);
        tmp___14 = quote((char const *)ent->fts_path);
        tmp___15 = gettext("skipping %s, since it\'s on a different device");
        error(0, 0, (char const *)tmp___15, tmp___14);
        return ((enum RM_status)4);
      }
    }
  }
}
