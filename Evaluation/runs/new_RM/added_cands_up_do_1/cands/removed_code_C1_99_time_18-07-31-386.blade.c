

if (fd < 0) {
  if (is_dotdot) {
    if (sp->fts_options & 512) {
      tmp___1 = i_ring_empty((I_ring const *)(&sp->fts_fd_ring));
      if (!tmp___1) {
        parent_fd = i_ring_pop(&sp->fts_fd_ring);
        is_dotdot = (_Bool)1;
        if (0 <= parent_fd) {
          fd = parent_fd;
          dir = (char const *)((void *)0);
        }
      }
    }
  }
}
