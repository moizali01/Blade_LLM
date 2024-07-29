

if (nitems > sp->fts_nitems) {
  sp->fts_nitems = nitems + 40UL;
  if (0xffffffffffffffffUL / sizeof(*a) < sp->fts_nitems) {
    free((void *)sp->fts_array);
    sp->fts_array = (struct _ftsent **)((void *)0);
    sp->fts_nitems = (size_t)0;
    return (head);
  } else {
    a = (FTSENT **)realloc((void *)sp->fts_array, sp->fts_nitems * sizeof(*a));
    if (!a) {
      free((void *)sp->fts_array);
      sp->fts_array = (struct _ftsent **)((void *)0);
      sp->fts_nitems = (size_t)0;
      return (head);
    }
  }
  sp->fts_array = a;
}
