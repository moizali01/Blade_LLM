

if (save_orig_name) {
  if (!verbose) {
    if (!quiet) {
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const * /* __restrict  */) "%s: %s compressed to %s\n",
                progname, ifname, ofname);
      }
    }
  }
}
