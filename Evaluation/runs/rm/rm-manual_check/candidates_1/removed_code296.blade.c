

if ((int)p->fts_info == 11) {
  if (p->fts_statp[0].st_size == 2L) {
    parent = p->fts_parent;
    if (0L < p->fts_level) {
      if (parent->fts_n_dirs_remaining == 0UL) {
        if (sp->fts_options & 8) {
          if (sp->fts_options & 16) {
            tmp___14 = link_count_optimize_ok((FTSENT const *)parent);
            if (!tmp___14) {
              goto _L___4;
            }
          } else {
            goto _L___4;
          }
        } else {
          goto _L___4;
        }
      } else {
        goto _L___4;
      }
    } else {
    _L___4:
      p->fts_info = fts_stat(sp, p, (_Bool)0);
      if ((p->fts_statp[0].st_mode & 61440U) == 16384U) {
        if (p->fts_level != 0L) {
          if (parent->fts_n_dirs_remaining) {
            (parent->fts_n_dirs_remaining)--;
          }
        }
      }
    }
  } else {
    while (1) {

      if (!(p->fts_statp[0].st_size == 1L)) {
        abort();
      }
      goto while_break___2;
    }
  while_break___2:;
  }
}
