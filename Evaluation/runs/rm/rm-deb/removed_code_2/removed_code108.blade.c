

if (!(sp->fts_options & 4)) {
  if (!(sp->fts_options & 512)) {
    tmp___11 = diropen((FTS const *)sp, ".");
    sp->fts_rfd = tmp___11;
    if (tmp___11 < 0) {
      sp->fts_options |= 4;
    }
  }
}
i_ring_init(&sp->fts_fd_ring, -1);
