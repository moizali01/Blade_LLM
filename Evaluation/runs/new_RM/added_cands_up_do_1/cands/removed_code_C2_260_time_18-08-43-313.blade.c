

static _Bool link_count_optimize_ok(FTSENT const *p) {
  FTS *sp;
  Hash_table *h;
  struct LCO_ent tmp;
  struct LCO_ent *ent;
  _Bool opt_ok;
  struct LCO_ent *t2;
  struct hash_table *tmp___0;

  {
    sp = (FTS *)p->fts_fts;
    h = sp->fts_leaf_optimization_works_ht;
    if (!(sp->fts_options & 512)) {
      return ((_Bool)0);
    }
    if ((unsigned long)h == (unsigned long)((void *)0)) {
      tmp___0 =
          hash_initialize((size_t)13, (Hash_tuning const *)((void *)0),
                          &LCO_hash, &LCO_compare, (void (*)(void *))(&free));
      sp->fts_leaf_optimization_works_ht = tmp___0;
      h = tmp___0;
      if ((unsigned long)h == (unsigned long)((void *)0)) {
        return ((_Bool)0);
      }
    }
    tmp.st_dev = (dev_t)p->fts_statp[0].st_dev;
    ent = (struct LCO_ent *)hash_lookup((Hash_table const *)h,
                                        (void const *)(&tmp));
    if (ent) {
      return (ent->opt_ok);
    }
    t2 = (struct LCO_ent *)malloc(sizeof(*t2));
    if ((unsigned long)t2 == (unsigned long)((void *)0)) {
      return ((_Bool)0);
    }
    opt_ok = leaf_optimization_applies(sp->fts_cwd_fd);
    t2->opt_ok = opt_ok;
    t2->st_dev = (dev_t)p->fts_statp[0].st_dev;
    ent = (struct LCO_ent *)hash_insert(h, (void const *)t2);
    if ((unsigned long)ent == (unsigned long)((void *)0)) {
      free((void *)t2);
      return ((_Bool)0);
    }
    while (1) {

      if (!((unsigned long)ent == (unsigned long)t2)) {
        abort();
      }
      goto while_break;
    }
  while_break:;
    return (opt_ok);
  }
}
