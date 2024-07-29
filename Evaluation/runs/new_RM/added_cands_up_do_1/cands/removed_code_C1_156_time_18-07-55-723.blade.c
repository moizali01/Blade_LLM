

while (1) {
  nitems--;
  if (!nitems) {
    goto while_break___0;
  }
  (*(ap + 0))->fts_link = *(ap + 1);
  ap++;
}
