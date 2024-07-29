

static size_t LCO_hash(void const *x, size_t table_size) {
  struct LCO_ent const *ax;

  {
    ax = (struct LCO_ent const *)x;
    return ((uintmax_t)ax->st_dev % table_size);
  }
}
