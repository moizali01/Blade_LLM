

new_table->n_buckets = new_size;
new_table->bucket_limit =
    (struct hash_entry const *)(new_table->bucket + new_size);
