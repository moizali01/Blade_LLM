

if (p->fts_level == 0L) {
  fd_ring_clear(&sp->fts_fd_ring);
  if (!(sp->fts_options & 4)) {
    if (sp->fts_options & 512) {
      if (sp->fts_options & 512) {
        tmp___20 = -100;
      } else {
        tmp___20 = sp->fts_rfd;
      }
      cwd_advance_fd(sp, tmp___20, (_Bool)1);
      tmp___23 = 0;
    } else {
      if (sp->fts_options & 512) {
        tmp___21 = -100;
      } else {
        tmp___21 = sp->fts_rfd;
      }
      tmp___22 = fchdir(tmp___21);
      tmp___23 = tmp___22;
    }
    if (tmp___23) {
      tmp___24 = 1;
    } else {
      tmp___24 = 0;
    }
  } else {
    tmp___24 = 0;
  }
  if (tmp___24) {
    tmp___19 = __errno_location();
    p->fts_errno = *tmp___19;
    sp->fts_options |= 8192;
  }
} else {
  if ((int)p->fts_flags & 2) {
    if (!(sp->fts_options & 4)) {
      if (sp->fts_options & 512) {
        cwd_advance_fd(sp, p->fts_symfd, (_Bool)1);
        tmp___29 = 0;
      } else {
        tmp___28 = fchdir(p->fts_symfd);
        tmp___29 = tmp___28;
      }
      if (tmp___29) {
        tmp___25 = __errno_location();
        saved_errno = *tmp___25;
        close(p->fts_symfd);
        tmp___26 = __errno_location();
        *tmp___26 = saved_errno;
        tmp___27 = __errno_location();
        p->fts_errno = *tmp___27;
        sp->fts_options |= 8192;
      }
    }
    close(p->fts_symfd);
  } else {
    if (!((int)p->fts_flags & 1)) {
      tmp___31 = fts_safe_changedir(sp, p->fts_parent, -1, "..");
      if (tmp___31) {
        tmp___30 = __errno_location();
        p->fts_errno = *tmp___30;
        sp->fts_options |= 8192;
      }
    }
  }
}
