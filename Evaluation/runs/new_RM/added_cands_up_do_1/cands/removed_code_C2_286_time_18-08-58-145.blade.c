

static void free_dir(FTS *sp) {

  {
    if (sp->fts_options & 258) {
      if (sp->fts_cycle.ht) {
        hash_free(sp->fts_cycle.ht);
      }
    } else {
      free((void *)sp->fts_cycle.state);
    }
    return;
  }
}
