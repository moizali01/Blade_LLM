

void *hash_delete(Hash_table *table___0, void const *entry);
__inline static size_t rotr_sz(size_t x, int n) {

  {
    return (((x >> n) | (x << (8UL * sizeof(x) - (unsigned long)n))) &
            0xffffffffffffffffUL);
  }
}
static struct hash_tuning const default_tuning = {
    (float)0.0, (float)1.0, (float)0.8, (float)1.414, (_Bool)0};
