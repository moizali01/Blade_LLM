

while (1) {

  if (!p) {
    goto while_break;
  }
  tmp___0 = ap;
  ap++;
  *tmp___0 = p;
  p = p->fts_link;
}
