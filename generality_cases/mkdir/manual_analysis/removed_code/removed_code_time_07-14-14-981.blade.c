

if (affected_bits) {
  who_specified_p = 1;
} else {
  who_specified_p = 0;
  affected_bits = (mode_t)((4032 | (448 >> 3)) | ((448 >> 3) >> 3));
  ops_to_mask = masked_ops;
}
