

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
