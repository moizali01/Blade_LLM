

static _Bool setup_dir(FTS *fts) {

  {
    if (fts->fts_options & 258) {
      fts->fts_cycle.ht =
          hash_initialize((size_t)31, (Hash_tuning const *)((void *)0),
                          &AD_hash, &AD_compare, (void (*)(void *))(&free));
      if (!fts->fts_cycle.ht) {
        return ((_Bool)0);
      }
    } else {
      fts->fts_cycle.state =
          (struct cycle_check_state *)malloc(sizeof(*(fts->fts_cycle.state)));
      if (!fts->fts_cycle.state) {
        return ((_Bool)0);
      }
      cycle_check_init(fts->fts_cycle.state);
    }
    return ((_Bool)1);
  }
}
