

if (sp->fts_cur) {
  p = sp->fts_cur;
  while (1) {

    if (!(p->fts_level >= 0L)) {
      goto while_break;
    }
    freep = p;
    if ((unsigned long)p->fts_link != (unsigned long)((void *)0)) {
      p = p->fts_link;
    } else {
      p = p->fts_parent;
    }
    free((void *)freep);
  }
while_break:
  free((void *)p);
}
