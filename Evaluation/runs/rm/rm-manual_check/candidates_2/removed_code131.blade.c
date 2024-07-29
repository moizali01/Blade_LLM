

if (!x->ignore_missing_files) {
  if ((unsigned int const)x->interactive == 3U) {
    goto _L;
  } else {
    if (x->stdin_tty) {
    _L:
      if (dirent_type != 10) {
        write_protected =
            write_protected_non_symlink(fd_cwd, filename, full_name, sbuf);
        tmp___0 = __errno_location();
        wp_errno = *tmp___0;
      }
    }
  }
}
