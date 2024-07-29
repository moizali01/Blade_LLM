

if (!nitems) {
  if (type == 3) {
    cur->fts_info = (unsigned short)6;
  }
  fts_lfree(head);
  return ((FTSENT *)((void *)0));
}
