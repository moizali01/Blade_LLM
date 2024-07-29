

Hash_table *(__attribute__((__warn_unused_result__))
             hash_initialize)(size_t candidate, Hash_tuning const *tuning,
                              size_t (*hasher)(void const *, size_t),
                              _Bool (*comparator)(void const *, void const *),
                              void (*data_freer)(void *)) {
  Hash_table *table___0;
  _Bool tmp;

  {
    if ((unsigned long)hasher == (unsigned long)((void *)0)) {
      hasher = &raw_hasher;
    }
    if ((unsigned long)comparator == (unsigned long)((void *)0)) {
      comparator = &raw_comparator;
    }
    table___0 = (Hash_table *)malloc(sizeof(*table___0));
    if ((unsigned long)table___0 == (unsigned long)((void *)0)) {
      return ((Hash_table *)((void *)0));
    }
    if (!tuning) {
      tuning = &default_tuning;
    }
    table___0->tuning = tuning;
    tmp = check_tuning(table___0);
    if (!tmp) {
      goto fail;
    }
    table___0->n_buckets = compute_bucket_size(candidate, tuning);
    if (!table___0->n_buckets) {
      goto fail;
    }
    table___0->bucket = (struct hash_entry *)calloc(
        table___0->n_buckets, sizeof(*(table___0->bucket)));
    if ((unsigned long)table___0->bucket == (unsigned long)((void *)0)) {
      goto fail;
    }
    table___0->bucket_limit =
        (struct hash_entry const *)(table___0->bucket + table___0->n_buckets);
    table___0->n_buckets_used = (size_t)0;
    table___0->n_entries = (size_t)0;
    table___0->hasher = hasher;
    table___0->comparator = comparator;
    table___0->data_freer = data_freer;
    table___0->free_entry_list = (struct hash_entry *)((void *)0);
    return (table___0);
  fail:
    free((void *)table___0);
    return ((Hash_table *)((void *)0));
  }
}
void hash_free(Hash_table *table___0) {
  struct hash_entry *bucket;
  struct hash_entry *cursor;
  struct hash_entry *next;

  {
    if (table___0->data_freer) {
      if (table___0->n_entries) {
        bucket = table___0->bucket;
        while (1) {

          if (!((unsigned long)bucket <
                (unsigned long)table___0->bucket_limit)) {
            goto while_break;
          }
          if (bucket->data) {
            cursor = bucket;
            while (1) {

              if (!cursor) {
                goto while_break___0;
              }
              (*(table___0->data_freer))(cursor->data);
              cursor = cursor->next;
            }
          while_break___0:;
          }
          bucket++;
        }
      while_break:;
      }
    }
    bucket = table___0->bucket;
    while (1) {

      if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
        goto while_break___1;
      }
      cursor = bucket->next;
      while (1) {

        if (!cursor) {
          goto while_break___2;
        }
        next = cursor->next;
        free((void *)cursor);
        cursor = next;
      }
    while_break___2:
      bucket++;
    }
  while_break___1:
    cursor = table___0->free_entry_list;
    while (1) {

      if (!cursor) {
        goto while_break___3;
      }
      next = cursor->next;
      free((void *)cursor);
      cursor = next;
    }
  while_break___3:
    free((void *)table___0->bucket);
    free((void *)table___0);
    return;
  }
}
static struct hash_entry *allocate_entry(Hash_table *table___0) {
  struct hash_entry *new;

  {
    if (table___0->free_entry_list) {
      new = table___0->free_entry_list;
      table___0->free_entry_list = new->next;
    } else {
      new = (struct hash_entry *)malloc(sizeof(*new));
    }
    return (new);
  }
}
