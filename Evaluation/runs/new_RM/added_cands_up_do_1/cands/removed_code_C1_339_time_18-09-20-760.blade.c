

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
