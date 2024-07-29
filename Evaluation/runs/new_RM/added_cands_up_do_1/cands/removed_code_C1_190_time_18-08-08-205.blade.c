

if (sp->fts_compar) {
  if (nitems > 1UL) {
    head = fts_sort(sp, head, nitems);
  }
}
