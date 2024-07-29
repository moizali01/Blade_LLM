

__inline static DIR *opendirat(int fd, char const *dir) {
  int new_fd;
  int tmp;
  DIR *dirp;
  int saved_errno;
  int *tmp___0;
  int *tmp___1;

  {
    tmp = openat_safer(fd, dir, 67840);
    new_fd = tmp;
    if (new_fd < 0) {
      return ((DIR *)((void *)0));
    }
    set_cloexec_flag(new_fd, (_Bool)1);
    dirp = fdopendir(new_fd);
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      tmp___0 = __errno_location();
      saved_errno = *tmp___0;
      close(new_fd);
      tmp___1 = __errno_location();
      *tmp___1 = saved_errno;
    }
    return (dirp);
  }
}
