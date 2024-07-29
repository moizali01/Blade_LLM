

static void fts_set_stat_required(FTSENT *p, _Bool required) {

  {
    while (1) {

      if (!((int)p->fts_info == 11)) {
        abort();
      }
      goto while_break;
    }
  while_break:;
    if (required) {
      p->fts_statp[0].st_size = (__off_t)2;
    } else {
      p->fts_statp[0].st_size = (__off_t)1;
    }
    return;
  }
}
