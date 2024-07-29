

if (sizeof(&dummy) == sizeof(void *)) {
  if ((long)(&dummy) == (long)((void *)(&dummy))) {
    tmp = (int (*)(void const *, void const *))sp->fts_compar;
  } else {
    tmp = &fts_compar;
  }
} else {
  tmp = &fts_compar;
}
