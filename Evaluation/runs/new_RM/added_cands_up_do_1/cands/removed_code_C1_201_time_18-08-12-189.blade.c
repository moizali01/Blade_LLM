

if (nlinks) {
  goto _L___0;
} else {
  if (type == 3) {
  _L___0:
    tmp___5 = dirfd(dirp);
    dir_fd = tmp___5;
    if (sp->fts_options & 512) {
      if (0 <= dir_fd) {
        dir_fd = dup_safer(dir_fd);
        set_cloexec_flag(dir_fd, (_Bool)1);
      }
    }
    if (dir_fd < 0) {
      goto _L;
    } else {
      tmp___7 = fts_safe_changedir(sp, cur, dir_fd, (char const *)((void *)0));
      if (tmp___7) {
      _L:
        if (nlinks) {
          if (type == 3) {
            tmp___6 = __errno_location();
            cur->fts_errno = *tmp___6;
          }
        }
        cur->fts_flags = (unsigned short)((int)cur->fts_flags | 1);
        descend = (_Bool)0;
        closedir(dirp);
        if (sp->fts_options & 512) {
          if (0 <= dir_fd) {
            close(dir_fd);
          }
        }
        dirp = (DIR *)((void *)0);
      } else {
        descend = (_Bool)1;
      }
    }
  } else {
    descend = (_Bool)0;
  }
}
