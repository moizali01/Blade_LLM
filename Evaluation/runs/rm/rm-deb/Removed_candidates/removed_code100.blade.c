

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
_Bool(__attribute__((__warn_unused_result__))
      hash_rehash)(Hash_table *table___0, size_t candidate) {
  Hash_table storage;
  Hash_table *new_table;
  size_t new_size;
  size_t tmp;
  _Bool tmp___0;
  _Bool tmp___1;
  _Bool tmp___2;

  {
    tmp = compute_bucket_size(candidate, table___0->tuning);
    new_size = tmp;
    if (!new_size) {
      return ((_Bool)0);
    }
    if (new_size == table___0->n_buckets) {
      return ((_Bool)1);
    }
    new_table = &storage;
    new_table->bucket =
        (struct hash_entry *)calloc(new_size, sizeof(*(new_table->bucket)));
    if ((unsigned long)new_table->bucket == (unsigned long)((void *)0)) {
      return ((_Bool)0);
    }
    new_table->n_buckets = new_size;
    new_table->bucket_limit =
        (struct hash_entry const *)(new_table->bucket + new_size);
    new_table->n_buckets_used = (size_t)0;
    new_table->n_entries = (size_t)0;
    new_table->tuning = table___0->tuning;
    new_table->hasher = table___0->hasher;
    new_table->comparator = table___0->comparator;
    new_table->data_freer = table___0->data_freer;
    new_table->free_entry_list = table___0->free_entry_list;
    tmp___0 = transfer_entries(new_table, table___0, (_Bool)0);
    if (tmp___0) {
      free((void *)table___0->bucket);
      table___0->bucket = new_table->bucket;
      table___0->bucket_limit = new_table->bucket_limit;
      table___0->n_buckets = new_table->n_buckets;
      table___0->n_buckets_used = new_table->n_buckets_used;
      table___0->free_entry_list = new_table->free_entry_list;
      return ((_Bool)1);
    }
    table___0->free_entry_list = new_table->free_entry_list;
    tmp___1 = transfer_entries(table___0, new_table, (_Bool)1);
    if (tmp___1) {
      tmp___2 = transfer_entries(table___0, new_table, (_Bool)0);
      if (!tmp___2) {
        abort();
      }
    } else {
      abort();
    }
    free((void *)new_table->bucket);
    return ((_Bool)0);
  }
}
