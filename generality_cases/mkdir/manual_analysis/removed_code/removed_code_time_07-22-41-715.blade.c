

if (0xffffffffffffffffUL / (unsigned long)scale_factor < *x) {
  *x = 0xffffffffffffffffUL;
  return ((strtol_error)1);
}
