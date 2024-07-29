

static enum RM_status rm_fts(FTS *fts, FTSENT *ent,
                             struct rm_options const *x) {
  char const *tmp;
  char *tmp___0;
  _Bool tmp___1;
  char const *tmp___2;
  char *tmp___3;
  char *tmp___4;
  _Bool tmp___5;
  char const *tmp___6;
  char *tmp___7;
  char const *tmp___8;
  char const *tmp___9;
  char *tmp___10;
  int tmp___11;
  char *tmp___12;
  Ternary is_empty_directory;
  enum RM_status s;
  enum RM_status tmp___13;
  char const *tmp___14;
  char *tmp___15;
  _Bool is_dir;
  int tmp___16;
  enum RM_status s___0;
  enum RM_status tmp___17;
  enum RM_status tmp___18;
  char const *tmp___19;
  char *tmp___20;
  char const *tmp___21;
  char *tmp___22;
  char const *tmp___23;
  char *tmp___24;

  {
    if ((int)ent->fts_info == 1) {
      goto case_1;
    }
    if ((int)ent->fts_info == 8) {
      goto case_8;
    }
    if ((int)ent->fts_info == 10) {
      goto case_8;
    }
    if ((int)ent->fts_info == 12) {
      goto case_8;
    }
    if ((int)ent->fts_info == 13) {
      goto case_8;
    }
    if ((int)ent->fts_info == 6) {
      goto case_8;
    }
    if ((int)ent->fts_info == 4) {
      goto case_8;
    }
    if ((int)ent->fts_info == 11) {
      goto case_8;
    }
    if ((int)ent->fts_info == 3) {
      goto case_8;
    }
    if ((int)ent->fts_info == 2) {
      goto case_2;
    }
    if ((int)ent->fts_info == 7) {
      goto case_7;
    }
    goto switch_default;
  case_1:
    if (!x->recursive) {
      tmp = quote((char const *)ent->fts_path);
      tmp___0 = gettext("cannot remove %s");
      error(0, 21, (char const *)tmp___0, tmp);
      mark_ancestor_dirs(ent);
      fts_skip_tree(fts, ent);
      return ((enum RM_status)4);
    }
    if (ent->fts_level == 0L) {
      tmp___1 = strip_trailing_slashes(ent->fts_path);
      if (tmp___1) {
        ent->fts_pathlen = strlen((char const *)ent->fts_path);
      }
      tmp___4 = last_component((char const *)ent->fts_accpath);
      tmp___5 = dot_or_dotdot((char const *)tmp___4);
      if (tmp___5) {
        tmp___2 = quote((char const *)ent->fts_path);
        tmp___3 = gettext("cannot remove directory: %s");
        error(0, 0, (char const *)tmp___3, tmp___2);
        fts_skip_tree(fts, ent);
        return ((enum RM_status)4);
      }
      if (x->root_dev_ino) {
        if (ent->fts_statp[0].st_ino == (x->root_dev_ino)->st_ino) {
          if (ent->fts_statp[0].st_dev == (x->root_dev_ino)->st_dev) {
            while (1) {
              tmp___11 = strcmp((char const *)ent->fts_path, "/");
              if (tmp___11 == 0) {
                tmp___6 = quote((char const *)ent->fts_path);
                tmp___7 =
                    gettext("it is dangerous to operate recursively on %s");
                error(0, 0, (char const *)tmp___7, tmp___6);
              } else {
                tmp___8 = quote_n(1, "/");
                tmp___9 = quote_n(0, (char const *)ent->fts_path);
                tmp___10 = gettext("it is dangerous to operate recursively on "
                                   "%s (same as %s)");
                error(0, 0, (char const *)tmp___10, tmp___9, tmp___8);
              }
              tmp___12 =
                  gettext("use --no-preserve-root to override this failsafe");
              error(0, 0, (char const *)tmp___12);
              goto while_break;
            }
          while_break:
            fts_skip_tree(fts, ent);
            return ((enum RM_status)4);
          }
        }
      }
    }
    tmp___13 = prompt((FTS const *)fts, (FTSENT const *)ent, (_Bool)1, x,
                      (enum Prompt_action)2, &is_empty_directory);
    s = tmp___13;
    if ((unsigned int)s == 2U) {
      if ((unsigned int)is_empty_directory == 4U) {
        s = excise(fts, ent, x, (_Bool)1);
        fts_skip_tree(fts, ent);
      }
    }
    if ((unsigned int)s != 2U) {
      mark_ancestor_dirs(ent);
      fts_skip_tree(fts, ent);
    }
    return (s);
  case_8:
    if ((int)ent->fts_info == 6) {
      if (x->one_file_system) {
        if (0L < ent->fts_level) {
          if (ent->fts_statp[0].st_dev != fts->fts_dev) {
            mark_ancestor_dirs(ent);
            tmp___14 = quote((char const *)ent->fts_path);
            tmp___15 =
                gettext("skipping %s, since it\'s on a different device");
            error(0, 0, (char const *)tmp___15, tmp___14);
            return ((enum RM_status)4);
          }
        }
      }
    }
    if ((int)ent->fts_info == 6) {
      tmp___16 = 1;
    } else {
      if ((int)ent->fts_info == 4) {
        tmp___16 = 1;
      } else {
        tmp___16 = 0;
      }
    }
    is_dir = (_Bool)tmp___16;
    tmp___17 = prompt((FTS const *)fts, (FTSENT const *)ent, is_dir, x,
                      (enum Prompt_action)3, (Ternary *)((void *)0));
    s___0 = tmp___17;
    if ((unsigned int)s___0 != 2U) {
      return (s___0);
    }
    tmp___18 = excise(fts, ent, x, is_dir);
    return (tmp___18);
  case_2:
    while (1) {
      tmp___19 = quote((char const *)ent->fts_path);
      tmp___20 = gettext(
          "WARNING: Circular directory structure.\nThis almost certainly means "
          "that you have a corrupted file system.\nNOTIFY YOUR SYSTEM "
          "MANAGER.\nThe following directory is part of the cycle:\n  %s\n");
      error(0, 0, (char const *)tmp___20, tmp___19);
      goto while_break___0;
    }
  while_break___0:
    fts_skip_tree(fts, ent);
    return ((enum RM_status)4);
  case_7:
    tmp___21 = quote((char const *)ent->fts_path);
    tmp___22 = gettext("traversal failed: %s");
    error(0, ent->fts_errno, (char const *)tmp___22, tmp___21);
    fts_skip_tree(fts, ent);
    return ((enum RM_status)4);
  switch_default:
    tmp___23 = quote((char const *)ent->fts_path);
    tmp___24 =
        gettext("unexpected failure: fts_info=%d: %s\nplease report to %s");
    error(0, 0, (char const *)tmp___24, (int)ent->fts_info, tmp___23,
          "bug-coreutils@gnu.org");
    abort();

    return ((enum RM_status)0);
  }
}
