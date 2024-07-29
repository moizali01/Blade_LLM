

if ((float const)table___0->n_buckets_used >
    (table___0->tuning)->growth_threshold * (float const)table___0->n_buckets) {
  tuning = table___0->tuning;
  if (tuning->is_n_buckets) {
    tmp = (float)((float const)table___0->n_buckets * tuning->growth_factor);
  } else {
    tmp = (float)(((float const)table___0->n_buckets * tuning->growth_factor) *
                  tuning->growth_threshold);
  }
  candidate = tmp;
  if ((float)0xffffffffffffffffUL <= candidate) {
    return ((void *)0);
  }
  tmp___0 = hash_rehash(table___0, (size_t)candidate);
  if (!tmp___0) {
    return ((void *)0);
  }
  tmp___1 = hash_find_entry(table___0, entry, &bucket, (_Bool)0);
  if ((unsigned long)tmp___1 != (unsigned long)((void *)0)) {
    abort();
  }
}
