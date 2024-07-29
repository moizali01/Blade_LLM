

if (!tuning->is_n_buckets) {
  new_candidate = (float)((float const)candidate / tuning->growth_threshold);
  if ((float)0xffffffffffffffffUL <= new_candidate) {
    return ((size_t)0);
  }
  candidate = (size_t)new_candidate;
}
candidate = next_prime(candidate);
