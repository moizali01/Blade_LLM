

if (res_size == 0UL) {
  res_size = ((l1 + 1UL) + l2) + 1UL;
  res_ptr = (char *)malloc(res_size + 1UL);
} else {
  res_size += ((l1 + 1UL) + l2) + 1UL;
  res_ptr = (char *)realloc((void *)res_ptr, res_size + 1UL);
}
