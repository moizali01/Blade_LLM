

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
static enum RM_status prompt(FTS const *fts, FTSENT const *ent, _Bool is_dir,
                             struct rm_options const *x,
                             enum Prompt_action mode, Ternary *is_empty_p) {
  int fd_cwd;
  char const *full_name;
  char const *filename;
  struct stat st;
  struct stat *sbuf;
  int dirent_type;
  int tmp;
  int write_protected;
  int wp_errno;
  int *tmp___0;
  int *tmp___1;
  int tmp___2;
  char const *quoted_name;
  char const *tmp___3;
  char *tmp___4;
  _Bool is_empty;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  char *tmp___8;
  int *tmp___9;
  int tmp___10;
  char const *tmp___11;
  char *tmp___12;
  char *tmp___13;
  char *tmp___14;
  _Bool tmp___15;

  {
    fd_cwd = (int)fts->fts_cwd_fd;
    full_name = (char const *)ent->fts_path;
    filename = (char const *)ent->fts_accpath;
    if (is_empty_p) {
      *is_empty_p = (Ternary)2;
    }
    sbuf = &st;
    cache_stat_init(sbuf);
    if (is_dir) {
      tmp = 4;
    } else {
      tmp = 0;
    }
    dirent_type = tmp;
    write_protected = 0;
    if (ent->fts_number) {
      return ((enum RM_status)3);
    }
    if ((unsigned int const)x->interactive == 5U) {
      return ((enum RM_status)2);
    }
    wp_errno = 0;
    if (!x->ignore_missing_files) {
      if ((unsigned int const)x->interactive == 3U) {
        goto _L;
      } else {
        if (x->stdin_tty) {
        _L:
          if (dirent_type != 10) {
            write_protected =
                write_protected_non_symlink(fd_cwd, filename, full_name, sbuf);
            tmp___0 = __errno_location();
            wp_errno = *tmp___0;
          }
        }
      }
    }
    if (write_protected) {
      goto _L___2;
    } else {
      if ((unsigned int const)x->interactive == 3U) {
      _L___2:
        if (0 <= write_protected) {
          if (dirent_type == 0) {
            tmp___2 = cache_fstatat(fd_cwd, filename, sbuf, 256);
            if (tmp___2 == 0) {
              if ((sbuf->st_mode & 61440U) == 40960U) {
                dirent_type = 10;
              } else {
                if ((sbuf->st_mode & 61440U) == 16384U) {
                  dirent_type = 4;
                }
              }
            } else {
              write_protected = -1;
              tmp___1 = __errno_location();
              wp_errno = *tmp___1;
            }
          }
        }
        if (0 <= write_protected) {
          if (dirent_type == 10) {
            goto case_10;
          }
          if (dirent_type == 4) {
            goto case_4;
          }
          goto switch_break;
        case_10:
          if ((unsigned int const)x->interactive != 3U) {
            return ((enum RM_status)2);
          }
          goto switch_break;
        case_4:
          if (!x->recursive) {
            write_protected = -1;
            wp_errno = 21;
          }
          goto switch_break;
        switch_break:;
        }
        tmp___3 = quote(full_name);
        quoted_name = tmp___3;
        if (write_protected < 0) {
          tmp___4 = gettext("cannot remove %s");
          error(0, wp_errno, (char const *)tmp___4, quoted_name);
          return ((enum RM_status)4);
        }
        if (is_empty_p) {
          is_empty = is_empty_dir(fd_cwd, filename);
          if (is_empty) {
            *is_empty_p = (Ternary)4;
          } else {
            *is_empty_p = (Ternary)3;
          }
        } else {
          is_empty = (_Bool)0;
        }
        if (dirent_type == 4) {
          if ((unsigned int)mode == 2U) {
            if (!is_empty) {
              if (write_protected) {
                tmp___5 =
                    gettext("%s: descend into write-protected directory %s? ");
                tmp___7 = tmp___5;
              } else {
                tmp___6 = gettext("%s: descend into directory %s? ");
                tmp___7 = tmp___6;
              }
              fprintf(stderr, (char const *)tmp___7, program_name, quoted_name);
            } else {
              goto _L___1;
            }
          } else {
            goto _L___1;
          }
        } else {
        _L___1:
          tmp___10 = cache_fstatat(fd_cwd, filename, sbuf, 256);
          if (tmp___10 != 0) {
            tmp___8 = gettext("cannot remove %s");
            tmp___9 = __errno_location();
            error(0, *tmp___9, (char const *)tmp___8, quoted_name);
            return ((enum RM_status)4);
          }
          tmp___11 = file_type((struct stat const *)sbuf);
          if (write_protected) {
            tmp___12 = gettext("%s: remove write-protected %s %s? ");
            tmp___14 = tmp___12;
          } else {
            tmp___13 = gettext("%s: remove %s %s? ");
            tmp___14 = tmp___13;
          }
          fprintf(stderr, (char const *)tmp___14, program_name, tmp___11,
                  quoted_name);
        }
        tmp___15 = yesno();
        if (!tmp___15) {
          return ((enum RM_status)3);
        }
      }
    }
    return ((enum RM_status)2);
  }
}
__inline static _Bool nonexistent_file_errno(int errnum) {

  {
    if (errnum == 2) {
      goto case_2;
    }
    if (errnum == 20) {
      goto case_2;
    }
    goto switch_default;
  case_2:
    return ((_Bool)1);
  switch_default:
    return ((_Bool)0);

    return ((_Bool)0);
  }
}
