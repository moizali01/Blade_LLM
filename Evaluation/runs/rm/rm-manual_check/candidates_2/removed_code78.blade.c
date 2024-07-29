

if (!x->recursive) {
  tmp = quote((char const *)ent->fts_path);
  tmp___0 = gettext("cannot remove %s");
  error(0, 21, (char const *)tmp___0, tmp);
  mark_ancestor_dirs(ent);
  fts_skip_tree(fts, ent);
  return ((enum RM_status)4);
}
