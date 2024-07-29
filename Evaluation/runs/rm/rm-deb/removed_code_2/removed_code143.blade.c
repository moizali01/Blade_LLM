

if (!ch) {
  goto while_break;
}
value = (value * 31UL + (size_t)ch) % n_buckets;
