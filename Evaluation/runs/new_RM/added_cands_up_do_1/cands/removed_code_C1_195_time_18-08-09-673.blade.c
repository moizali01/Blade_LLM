

if (sp->fts_options & 4) {
  if (len == sp->fts_pathlen) {
    cp--;
  } else {
    if (nitems == 0UL) {
      cp--;
    }
  }
  *cp = (char)'\000';
}
