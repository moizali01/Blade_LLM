

if ((size_t)tmp / s < n) {
  {
    xalloc_die();
  }
} else {
  { p = malloc(n * s); }
  if (!p) {
    {
      xalloc_die();
    }
  }
}
