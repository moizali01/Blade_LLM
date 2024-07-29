

if (sp->fts_options & 4) {
  if (sp->fts_options & 512) {
    if (0 <= fd) {
      close(fd);
    }
  }
  return (0);
}
