

if (sp->fts_options & 512) {
  cwd_advance_fd(sp, newfd, (_Bool)(!is_dotdot));
  return (0);
}
