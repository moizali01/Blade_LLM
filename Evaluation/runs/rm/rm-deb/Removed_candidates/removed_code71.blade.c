

if ((unsigned long)sp->fts_cur == (unsigned long)((void *)0)) {
  return ((FTSENT *)((void *)0));
} else {
  if (sp->fts_options & 8192) {
    return ((FTSENT *)((void *)0));
  }
}
p = sp->fts_cur;
