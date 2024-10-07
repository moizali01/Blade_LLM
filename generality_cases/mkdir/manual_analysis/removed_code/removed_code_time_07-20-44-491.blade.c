

if (command_name) {
  {
    fprintf((FILE * /* __restrict  */)stream,
            (char const * /* __restrict  */) "%s (%s) %s\n", command_name,
            package, version);
  }
} else {
  {
    fprintf((FILE * /* __restrict  */)stream,
            (char const * /* __restrict  */) "%s %s\n", package, version);
  }
}
