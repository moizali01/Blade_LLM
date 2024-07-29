

while (1) {

  if (!(p->fts_level >= 0L)) {
    goto while_break___1;
  }
  while (1) {

    if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
      p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
    }
    p->fts_path = addr;
    goto while_break___2;
  }
while_break___2:;
  if (p->fts_link) {
    p = p->fts_link;
  } else {
    p = p->fts_parent;
  }
}
