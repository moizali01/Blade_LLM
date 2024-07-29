

if (tmp <= 0) {
  dest--;
  (node->lo)--;
  *dest = *(node->lo);
} else {
  dest--;
  (node->hi)--;
  *dest = *(node->hi);
}
