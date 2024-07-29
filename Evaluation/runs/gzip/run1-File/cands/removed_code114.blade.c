

if (test) {
  {
    fprintf((FILE * /* __restrict  */) stderr,
            (char const * /* __restrict  */) " OK");
  }
} else {
  if (decompress) {
    { display_ratio(bytes_out - (bytes_in - header_bytes), bytes_out, stderr); }
  } else {
    { display_ratio(bytes_in - (bytes_out - header_bytes), bytes_in, stderr); }
  }
}
