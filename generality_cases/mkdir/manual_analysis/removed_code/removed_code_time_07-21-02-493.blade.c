

if ((size_t)tmp / s < n) {
  {
    xalloc_die();
  }
} else {
  { p = realloc(p, n * s); }
  if (!p) {
    {
      xalloc_die();
    }
  }
}
