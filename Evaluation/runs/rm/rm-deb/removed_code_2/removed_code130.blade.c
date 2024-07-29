

if (!new_size) {
  return ((_Bool)0);
}
if (new_size == table___0->n_buckets) {
  return ((_Bool)1);
}
new_table = &storage;
