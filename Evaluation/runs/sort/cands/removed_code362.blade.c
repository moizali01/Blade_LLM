

while (1) {

  if (!cursor) {
    goto while_break___0;
  }
  data = cursor->data;
  new_bucket = safe_hasher((Hash_table const *)dst, (void const *)data);
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
