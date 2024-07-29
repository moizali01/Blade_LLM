

if (verbose) {
  {
    printf((char const * /* __restrict  */) "%5s %08lx %11s ",
           methods[method___0], crc___1, date);
  }
}
{ printf((char const * /* __restrict  */) "%9ld %9ld ", bytes_in, bytes_out); }
if (bytes_in == -1L) {
  total_in = -1L;
  header_bytes = 0L;
  bytes_out = header_bytes;
  bytes_in = bytes_out;
} else {
  if (total_in >= 0L) {
    total_in += bytes_in;
  }
}
