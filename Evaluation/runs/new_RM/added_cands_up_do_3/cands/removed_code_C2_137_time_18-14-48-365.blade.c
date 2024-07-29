

static size_t AD_hash(void const *x, size_t table_size) {
  struct Active_dir const *ax;

  {
    ax = (struct Active_dir const *)x;
    return ((uintmax_t)ax->ino % table_size);
  }
}
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
static _Bool enter_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;
  struct Active_dir *ad;
  struct Active_dir *tmp;
  struct Active_dir *ad_from_table;
  _Bool tmp___0;

  {
    if (fts->fts_options & 258) {
      st = (struct stat const *)(ent->fts_statp);
      tmp = (struct Active_dir *)malloc(sizeof(*ad));
      ad = tmp;
      if (!ad) {
        return ((_Bool)0);
      }
      ad->dev = (dev_t)st->st_dev;
      ad->ino = (ino_t)st->st_ino;
      ad->fts_ent = ent;
      ad_from_table =
          (struct Active_dir *)hash_insert(fts->fts_cycle.ht, (void const *)ad);
      if ((unsigned long)ad_from_table != (unsigned long)ad) {
        free((void *)ad);
        if (!ad_from_table) {
          return ((_Bool)0);
        }
        ent->fts_cycle = ad_from_table->fts_ent;
        ent->fts_info = (unsigned short)2;
      }
    } else {
      tmp___0 = cycle_check(fts->fts_cycle.state,
                            (struct stat const *)(ent->fts_statp));
      if (tmp___0) {
        ent->fts_cycle = ent;
        ent->fts_info = (unsigned short)2;
      }
    }
    return ((_Bool)1);
  }
}
