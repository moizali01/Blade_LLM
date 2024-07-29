

int(__attribute__((__warn_unused_result__, __leaf__)) fts_close)(FTS *sp) {
  register FTSENT *freep;
  register FTSENT *p;
  int saved_errno;
  int *tmp;
  int tmp___0;
  int *tmp___1;
  int tmp___2;
  int *tmp___3;
  int tmp___4;
  int *tmp___5;

  {
    saved_errno = 0;
    if (sp->fts_cur) {
      p = sp->fts_cur;
      while (1) {

        if (!(p->fts_level >= 0L)) {
          goto while_break;
        }
        freep = p;
        if ((unsigned long)p->fts_link != (unsigned long)((void *)0)) {
          p = p->fts_link;
        } else {
          p = p->fts_parent;
        }
        free((void *)freep);
      }
    while_break:
      free((void *)p);
    }
    if (sp->fts_child) {
      fts_lfree(sp->fts_child);
    }
    free((void *)sp->fts_array);
    free((void *)sp->fts_path);
    if (sp->fts_options & 512) {
      if (0 <= sp->fts_cwd_fd) {
        tmp___0 = close(sp->fts_cwd_fd);
        if (tmp___0) {
          tmp = __errno_location();
          saved_errno = *tmp;
        }
      }
    } else {
      if (!(sp->fts_options & 4)) {
        tmp___2 = fchdir(sp->fts_rfd);
        if (tmp___2) {
          tmp___1 = __errno_location();
          saved_errno = *tmp___1;
        }
        tmp___4 = close(sp->fts_rfd);
        if (tmp___4) {
          if (saved_errno == 0) {
            tmp___3 = __errno_location();
            saved_errno = *tmp___3;
          }
        }
      }
    }
    fd_ring_clear(&sp->fts_fd_ring);
    if (sp->fts_leaf_optimization_works_ht) {
      hash_free(sp->fts_leaf_optimization_works_ht);
    }
    free_dir(sp);
    free((void *)sp);
    if (saved_errno) {
      tmp___5 = __errno_location();
      *tmp___5 = saved_errno;
      return (-1);
    }
    return (0);
  }
}
extern
    __attribute__((__nothrow__)) int(__attribute__((__nonnull__(2), __leaf__))
                                     fstatfs)(int __fildes,
                                              struct statfs *__buf);
static _Bool dirent_inode_sort_may_be_useful(int dir_fd) {
  struct statfs fs_buf;
  int tmp;

  {
    tmp = fstatfs(dir_fd, &fs_buf);
    if (tmp != 0) {
      return ((_Bool)1);
    }
    if (fs_buf.f_type == 16914836L) {
      goto case_16914836;
    }
    if (fs_buf.f_type == 26985L) {
      goto case_16914836;
    }
    goto switch_default;
  case_16914836:
    return ((_Bool)0);
  switch_default:
    return ((_Bool)1);

    return ((_Bool)0);
  }
}
