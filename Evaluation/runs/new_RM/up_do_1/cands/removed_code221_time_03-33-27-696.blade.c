

if (sp->fts_options & 512) {
  tmp___0 = openat_safer((int)sp->fts_cwd_fd, dir, open_flags);
  tmp___2 = tmp___0;
} else {
  tmp___1 = open_safer(dir, open_flags);
  tmp___2 = tmp___1;
}
