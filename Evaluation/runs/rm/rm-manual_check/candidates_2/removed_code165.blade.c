

__inline static _Bool is_empty_dir(int fd_cwd, char const *dir) {
  DIR *dirp;
  struct dirent const *dp;
  int saved_errno;
  int fd;
  int tmp;
  int *tmp___0;
  int *tmp___1;
  int tmp___2;

  {
    tmp = openat(fd_cwd, dir, 198912);
    fd = tmp;
    if (fd < 0) {
      return ((_Bool)0);
    }
    dirp = fdopendir(fd);
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      close(fd);
      return ((_Bool)0);
    }
    tmp___0 = __errno_location();
    *tmp___0 = 0;
    dp = readdir_ignoring_dot_and_dotdot(dirp);
    tmp___1 = __errno_location();
    saved_errno = *tmp___1;
    closedir(dirp);
    if ((unsigned long)dp != (unsigned long)((void *)0)) {
      return ((_Bool)0);
    }
    if (saved_errno == 0) {
      tmp___2 = 1;
    } else {
      tmp___2 = 0;
    }
    return ((_Bool)tmp___2);
  }
}
