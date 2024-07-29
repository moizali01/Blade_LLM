

if (test) {
  {
    fprintf((FILE * /* __restrict  */) stderr,
            (char const * /* __restrict  */) " OK\n");
  }
} else {
  if (!decompress) {
    {
      display_ratio(bytes_in - (bytes_out - header_bytes), bytes_in, stderr);
      fprintf((FILE * /* __restrict  */) stderr,
              (char const * /* __restrict  */) "\n");
    }
  }
}
