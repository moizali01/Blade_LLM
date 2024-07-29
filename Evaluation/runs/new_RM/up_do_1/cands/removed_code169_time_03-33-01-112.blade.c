

if (sp->fts_options & 512) {
  tmp___0 = opendirat(sp->fts_cwd_fd, (char const *)cur->fts_accpath);
  dirp = tmp___0;
} else {
  tmp___1 = opendir_safer((char const *)cur->fts_accpath);
  dirp = tmp___1;
}
