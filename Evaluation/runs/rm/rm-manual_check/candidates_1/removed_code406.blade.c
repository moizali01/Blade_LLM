

static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {
  struct hash_entry *bucket;
  struct hash_entry *cursor;
  struct hash_entry *next;
  void *data;
  struct hash_entry *new_bucket;
  size_t tmp;
  size_t tmp___0;
  struct hash_entry *new_entry;
  struct hash_entry *tmp___1;

  {
    bucket = src->bucket;
    while (1) {

      if (!((unsigned long)bucket < (unsigned long)src->bucket_limit)) {
        goto while_break;
      }
      if (bucket->data) {
        cursor = bucket->next;
        while (1) {

          if (!cursor) {
            goto while_break___0;
          }
          data = cursor->data;
          tmp = (*(dst->hasher))((void const *)data, dst->n_buckets);
          new_bucket = dst->bucket + tmp;
          if (!((unsigned long)new_bucket < (unsigned long)dst->bucket_limit)) {
            abort();
          }
          next = cursor->next;
          if (new_bucket->data) {
            cursor->next = new_bucket->next;
            new_bucket->next = cursor;
          } else {
            new_bucket->data = data;
            (dst->n_buckets_used)++;
            free_entry(dst, cursor);
          }
          cursor = next;
        }
      while_break___0:
        data = bucket->data;
        bucket->next = (struct hash_entry *)((void *)0);
        if (safe) {
          goto __Cont;
        }
        tmp___0 = (*(dst->hasher))((void const *)data, dst->n_buckets);
        new_bucket = dst->bucket + tmp___0;
        if (!((unsigned long)new_bucket < (unsigned long)dst->bucket_limit)) {
          abort();
        }
        if (new_bucket->data) {
          tmp___1 = allocate_entry(dst);
          new_entry = tmp___1;
          if ((unsigned long)new_entry == (unsigned long)((void *)0)) {
            return ((_Bool)0);
          }
          new_entry->data = data;
          new_entry->next = new_bucket->next;
          new_bucket->next = new_entry;
        } else {
          new_bucket->data = data;
          (dst->n_buckets_used)++;
        }
        bucket->data = (void *)0;
        (src->n_buckets_used)--;
      }
    __Cont:
      bucket++;
    }
  while_break:;
    return ((_Bool)1);
  }
}
