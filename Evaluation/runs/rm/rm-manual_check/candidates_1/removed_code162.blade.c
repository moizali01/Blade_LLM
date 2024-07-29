

static int write_protected_non_symlink(int fd_cwd, char const *file,
                                       char const *full_name,
                                       struct stat *buf___1) {
  _Bool tmp;
  int tmp___0;
  int tmp___1;
  size_t file_name_len;
  size_t tmp___2;
  _Bool tmp___3;
  int tmp___4;
  int tmp___5;
  int *tmp___6;
  int *tmp___7;

  {
    tmp = can_write_any_file();
    if (tmp) {
      return (0);
    }
    tmp___0 = cache_fstatat(fd_cwd, file, buf___1, 256);
    if (tmp___0 != 0) {
      return (-1);
    }
    if ((buf___1->st_mode & 61440U) == 40960U) {
      return (0);
    }
    tmp___1 = faccessat(fd_cwd, file, 2, 512);
    if (tmp___1 == 0) {
      return (0);
    }
    tmp___2 = strlen(full_name);
    file_name_len = tmp___2;
    if (4096UL <= file_name_len) {
      tmp___3 = euidaccess_stat((struct stat const *)buf___1, 2);
      if (tmp___3) {
        tmp___4 = 0;
      } else {
        tmp___4 = 1;
      }
      return (tmp___4);
    }
    tmp___5 = euidaccess(full_name, 2);
    if (tmp___5 == 0) {
      return (0);
    }
    tmp___7 = __errno_location();
    if (*tmp___7 == 13) {
      tmp___6 = __errno_location();
      *tmp___6 = 0;
      return (1);
    }
    return (-1);
  }
}
