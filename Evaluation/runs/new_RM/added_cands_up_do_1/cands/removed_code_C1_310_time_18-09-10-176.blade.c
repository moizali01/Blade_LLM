

void triple_free(void *x) {
  struct F_triple *a;

  {
    a = (struct F_triple *)x;
    free((void *)a->name);
    free((void *)a);
    return;
  }
}
