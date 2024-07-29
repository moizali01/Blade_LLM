

memmove((void *)(p->fts_name), (void const *)cp, len + 1UL);
p->fts_namelen = len;
}
else {
  if (*(cp + 1)) {
    cp++;
    len = strlen((char const *)cp);
    memmove((void *)(p->fts_name), (void const *)cp, len + 1UL);
    p->fts_namelen = len;
  }
