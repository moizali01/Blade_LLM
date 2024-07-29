

size_t triple_hash(void const *x, size_t table_size) {
  struct F_triple const *p;
  size_t tmp;
  size_t tmp___0;

  {
    p = (struct F_triple const *)x;
    tmp___0 = hash_pjw((void const *)p->name, table_size);
    tmp = tmp___0;
    return ((tmp ^ (unsigned long)p->st_ino) % table_size);
  }
}
_Bool triple_compare_ino_str(void const *x, void const *y) {
  struct F_triple const *a;
  struct F_triple const *b;
  int tmp___0;
  int tmp___1;

  {
    a = (struct F_triple const *)x;
    b = (struct F_triple const *)y;
    if (a->st_ino == b->st_ino) {
      if (a->st_dev == b->st_dev) {
        tmp___1 = strcmp((char const *)a->name, (char const *)b->name);
        if (tmp___1 == 0) {
          tmp___0 = 1;
        } else {
          tmp___0 = 0;
        }
      } else {
        tmp___0 = 0;
      }
    } else {
      tmp___0 = 0;
    }
    return ((_Bool)tmp___0);
  }
}
void triple_free(void *x) {
  struct F_triple *a;

  {
    a = (struct F_triple *)x;
    free((void *)a->name);
    free((void *)a);
    return;
  }
}
