

if (nitems > 10000UL) {
  if (!sp->fts_compar) {
    if (sp->fts_options & 512) {
      tmp___27 = dirent_inode_sort_may_be_useful(sp->fts_cwd_fd);
      if (tmp___27) {
        sp->fts_compar = &fts_compare_ino;
        head = fts_sort(sp, head, nitems);
        sp->fts_compar = (int (*)(struct _ftsent const **,
                                  struct _ftsent const **))((void *)0);
      }
    }
  }
}
