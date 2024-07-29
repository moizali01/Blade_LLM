

if ((unsigned long)p == (unsigned long)((void *)0)) {
  return ((FTSENT *)((void *)0));
}
memmove((void *)(p->fts_name), (void const *)name, namelen);
p->fts_name[namelen] = (char)'\000';
