

if (doadjust) {
  fts_padjust(sp, head);
}
if (sp->fts_options & 4) {
  if (len == sp->fts_pathlen) {
    cp--;
  } else {
    if (nitems == 0UL) {
      cp--;
    }
  }
  *cp = (char)'\000';
}
if (descend) {
  if (type == 1) {
    goto _L___2;
  } else {
    if (!nitems) {
    _L___2:
      if (cur->fts_level == 0L) {
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
        tmp___26 = tmp___24;
      } else {
        tmp___25 = fts_safe_changedir(sp, cur->fts_parent, -1, "..");
        tmp___26 = tmp___25;
      }
      if (tmp___26) {
        cur->fts_info = (unsigned short)7;
        sp->fts_options |= 8192;
        fts_lfree(head);
        return ((FTSENT *)((void *)0));
      }
    }
  }
}
