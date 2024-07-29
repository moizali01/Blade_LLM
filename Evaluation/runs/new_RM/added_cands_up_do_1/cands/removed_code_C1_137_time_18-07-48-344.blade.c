

while (1) {
  p = head;
  if (!p) {
    goto while_break;
  }
  head = head->fts_link;
  free((void *)p);
}
