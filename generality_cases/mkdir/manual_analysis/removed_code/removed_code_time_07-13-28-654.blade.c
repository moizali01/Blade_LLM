

if (value & 256U) {
  tmp = (256 >> 3) | ((256 >> 3) >> 3);
} else {
  tmp = 0;
}
