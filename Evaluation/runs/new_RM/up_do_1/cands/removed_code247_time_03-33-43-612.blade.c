

static size_t raw_hasher(void const *data, size_t n) {
  size_t val;
  size_t tmp;

  {
    tmp = rotr_sz((size_t)data, 3);
    val = tmp;
    return (val % n);
  }
}
