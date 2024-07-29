

void *hash_lookup(Hash_table const *table___0, void const *entry) {
  struct hash_entry const *bucket;
  size_t tmp;
  struct hash_entry const *cursor;
  _Bool tmp___0;

  {
    tmp = (*(table___0->hasher))(entry, (size_t)table___0->n_buckets);
    bucket = (struct hash_entry const *)(table___0->bucket + tmp);
    if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
      abort();
    }
    if ((unsigned long)bucket->data == (unsigned long)((void *)0)) {
      return ((void *)0);
    }
    cursor = bucket;
    while (1) {

      if (!cursor) {
        goto while_break;
      }
      if ((unsigned long)entry == (unsigned long)cursor->data) {
        return ((void *)cursor->data);
      } else {
        tmp___0 = (*(table___0->comparator))(entry, (void const *)cursor->data);
        if (tmp___0) {
          return ((void *)cursor->data);
        }
      }
      cursor = (struct hash_entry const *)cursor->next;
    }
  while_break:;
    return ((void *)0);
  }
}
