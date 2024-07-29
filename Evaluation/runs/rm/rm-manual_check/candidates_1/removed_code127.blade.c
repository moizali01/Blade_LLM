

static void fts_skip_tree(FTS *fts, FTSENT *ent) {

  {
    fts_set(fts, ent, 4);
    ent = fts_read(fts);
    return;
  }
}
