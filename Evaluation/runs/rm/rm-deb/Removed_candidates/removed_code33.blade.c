

if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
  p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
}
p->fts_path = addr;
