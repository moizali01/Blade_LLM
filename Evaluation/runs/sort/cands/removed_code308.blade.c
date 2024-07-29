

if (0 < node->pid) {
  close(tempfd);
  close(pipefds[0]);
  tempfd = pipefds[1];
  register_proc(node);
} else {
  if (node->pid == 0) {
    close(pipefds[1]);
    dup2_or_die(tempfd, 1);
    close(tempfd);
    dup2_or_die(pipefds[0], 0);
    close(pipefds[0]);
    tmp___2 = execlp(compress_program, compress_program, (char *)((void *)0));
    if (tmp___2 < 0) {
      tmp___0 = gettext("couldn\'t execute %s");
      tmp___1 = __errno_location();
      error(2, *tmp___1, (char const *)tmp___0, compress_program);
    }
  }
}
