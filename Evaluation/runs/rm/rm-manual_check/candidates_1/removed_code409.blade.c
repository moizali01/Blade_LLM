

static size_t compute_bucket_size(size_t candidate, Hash_tuning const *tuning) {
  float new_candidate;
  int tmp;

  {
    if (!tuning->is_n_buckets) {
      new_candidate =
          (float)((float const)candidate / tuning->growth_threshold);
      if ((float)0xffffffffffffffffUL <= new_candidate) {
        return ((size_t)0);
      }
      candidate = (size_t)new_candidate;
    }
    candidate = next_prime(candidate);
    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp = -1;
    } else {
      tmp = -2;
    }
    if ((size_t)tmp / sizeof(struct hash_entry *) < candidate) {
      return ((size_t)0);
    }
    return (candidate);
  }
}
