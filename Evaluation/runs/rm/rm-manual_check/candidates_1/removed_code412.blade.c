

size_t hash_string(char const *string, size_t n_buckets) {
  size_t value;
  unsigned char ch;

  {
    value = (size_t)0;
    while (1) {
      ch = (unsigned char)*string;
      if (!ch) {
        goto while_break;
      }
      value = (value * 31UL + (size_t)ch) % n_buckets;
      string++;
    }
  while_break:;
    return (value);
  }
}
