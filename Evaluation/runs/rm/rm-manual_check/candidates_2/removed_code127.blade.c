

static void mark_ancestor_dirs(FTSENT *ent) {
  FTSENT *p;

  {
    p = ent->fts_parent;
    while (1) {

      if (!(0L <= p->fts_level)) {
        goto while_break;
      }
      if (p->fts_number) {
        goto while_break;
      }
      p->fts_number = 1L;
      p = p->fts_parent;
    }
  while_break:;
    return;
  }
}
