

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
