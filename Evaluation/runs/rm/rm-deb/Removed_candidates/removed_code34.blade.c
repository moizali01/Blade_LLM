

if (!p) {
  goto while_break;
}
while (1) {

  if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
    p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
  }
  p->fts_path = addr;
  goto while_break___0;
}
while_break___0:
