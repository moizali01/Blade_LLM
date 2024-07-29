

static void cwd_advance_fd(FTS *sp, int fd, _Bool chdir_down_one) {
  int old;
  int prev_fd_in_slot;
  int tmp;

  {
    old = sp->fts_cwd_fd;
    while (1) {

      if (!(old != fd)) {
        if (!(old == -100)) {
          abort();
        }
      }
      goto while_break;
    }
  while_break:;
    if (chdir_down_one) {
      tmp = i_ring_push(&sp->fts_fd_ring, old);
      prev_fd_in_slot = tmp;
      if (0 <= prev_fd_in_slot) {
        close(prev_fd_in_slot);
      }
    } else {
      if (!(sp->fts_options & 4)) {
        if (0 <= old) {
          close(old);
        }
      }
    }
    sp->fts_cwd_fd = fd;
    return;
  }
}
__inline static int diropen(FTS const *sp, char const *dir) {
  int open_flags;
  int tmp;
  int fd;
  int tmp___0;
  int tmp___1;
  int tmp___2;

  {
    if (sp->fts_options & 16) {
      tmp = 131072;
    } else {
      tmp = 0;
    }
    open_flags = 67840 | tmp;
    if (sp->fts_options & 512) {
      tmp___0 = openat_safer((int)sp->fts_cwd_fd, dir, open_flags);
      tmp___2 = tmp___0;
    } else {
      tmp___1 = open_safer(dir, open_flags);
      tmp___2 = tmp___1;
    }
    fd = tmp___2;
    if (0 <= fd) {
      set_cloexec_flag(fd, (_Bool)1);
    }
    return (fd);
  }
}
__attribute__((__nothrow__))
FTS *(__attribute__((__warn_unused_result__, __leaf__))
      fts_open)(char *const *argv, int options,
                int (*compar)(FTSENT const **, FTSENT const **));
