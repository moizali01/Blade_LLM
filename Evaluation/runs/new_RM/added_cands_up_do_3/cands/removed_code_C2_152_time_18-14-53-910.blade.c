

void *hash_delete(Hash_table *table___0, void const *entry) {
  void *data;
  struct hash_entry *bucket;
  Hash_tuning const *tuning;
  size_t candidate;
  float tmp;
  struct hash_entry *cursor;
  struct hash_entry *next;
  _Bool tmp___0;

  {
    data = hash_find_entry(table___0, entry, &bucket, (_Bool)1);
    if (!data) {
      return ((void *)0);
    }
    (table___0->n_entries)--;
    if (!bucket->data) {
      (table___0->n_buckets_used)--;
      if ((float const)table___0->n_buckets_used <
          (table___0->tuning)->shrink_threshold *
              (float const)table___0->n_buckets) {
        check_tuning(table___0);
        if ((float const)table___0->n_buckets_used <
            (table___0->tuning)->shrink_threshold *
                (float const)table___0->n_buckets) {
          tuning = table___0->tuning;
          if (tuning->is_n_buckets) {
            tmp = (float)((float const)table___0->n_buckets *
                          tuning->shrink_factor);
          } else {
            tmp = (float)(((float const)table___0->n_buckets *
                           tuning->shrink_factor) *
                          tuning->growth_threshold);
          }
          candidate = (size_t)tmp;
          tmp___0 = hash_rehash(table___0, candidate);
          if (!tmp___0) {
            cursor = table___0->free_entry_list;
            while (1) {

              if (!cursor) {
                goto while_break;
              }
              next = cursor->next;
              free((void *)cursor);
              cursor = next;
            }
          while_break:
            table___0->free_entry_list = (struct hash_entry *)((void *)0);
          }
        }
      }
    }
    return (data);
  }
}
size_t hash_pjw(void const *x, size_t tablesize);
