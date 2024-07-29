

if (type == 2) {
  nlinks = (nlink_t)0;
  nostat = (_Bool)0;
} else {
  if (sp->fts_options & 8) {
    if (sp->fts_options & 16) {
      if (sp->fts_options & 32) {
        tmp___4 = 0;
      } else {
        tmp___4 = 2;
      }
      nlinks = cur->fts_statp[0].st_nlink - (__nlink_t)tmp___4;
      nostat = (_Bool)1;
    } else {
      nlinks = (nlink_t)-1;
      nostat = (_Bool)0;
    }
  } else {
    nlinks = (nlink_t)-1;
    nostat = (_Bool)0;
  }
}
