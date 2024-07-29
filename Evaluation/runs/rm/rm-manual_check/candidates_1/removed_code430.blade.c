

DIR *opendir_safer(char const *name) {
  DIR *dp;
  DIR *tmp;
  int fd;
  int tmp___0;
  DIR *newdp;
  int e;
  int f;
  int tmp___1;
  int *tmp___2;
  int *tmp___3;

  {
    tmp = opendir(name);
    dp = tmp;
    if (dp) {
      tmp___0 = dirfd(dp);
      fd = tmp___0;
      if (0 <= fd) {
        if (fd <= 2) {
          tmp___1 = dup_safer(fd);
          f = tmp___1;
          newdp = fdopendir(f);
          tmp___2 = __errno_location();
          e = *tmp___2;
          if (!newdp) {
            close(f);
          }
          closedir(dp);
          tmp___3 = __errno_location();
          *tmp___3 = e;
          dp = newdp;
        }
      }
    }
    return (dp);
  }
}
int openat_safer(int fd, char const *file, int flags, ...);
