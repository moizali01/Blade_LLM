

__inline static int lstatat(int fd, char const *name, struct stat *st) {
  int tmp;

  {
    tmp = fstatat(fd, name, st, 256);
    return (tmp);
  }
}
__inline static _Bool dot_or_dotdot(char const *file_name___3) {
  char sep;
  int tmp;

  {
    if ((int const) * (file_name___3 + 0) == 46) {
      sep = (char)*(file_name___3 +
                    (((int const) * (file_name___3 + 1) == 46) + 1));
      if (!sep) {
        tmp = 1;
      } else {
        if ((int)sep == 47) {
          tmp = 1;
        } else {
          tmp = 0;
        }
      }
      return ((_Bool)tmp);
    } else {
      return ((_Bool)0);
    }
  }
}
__inline static struct dirent const *
readdir_ignoring_dot_and_dotdot(DIR *dirp) {
  struct dirent const *dp;
  struct dirent const *tmp;
  _Bool tmp___0;

  {
    while (1) {
      tmp = (struct dirent const *)readdir(dirp);
      dp = tmp;
      if ((unsigned long)dp == (unsigned long)((void *)0)) {
        return (dp);
      } else {
        tmp___0 = dot_or_dotdot((char const *)(dp->d_name));
        if (!tmp___0) {
          return (dp);
        }
      }
    }

    return ((struct dirent const *)0);
  }
}
