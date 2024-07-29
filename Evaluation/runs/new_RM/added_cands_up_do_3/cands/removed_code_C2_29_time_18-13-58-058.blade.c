

static void fts_skip_tree(FTS *fts, FTSENT *ent) {

  {
    fts_set(fts, ent, 4);
    ent = fts_read(fts);
    return;
  }
}
static void mark_ancestor_dirs(FTSENT *ent) {
  FTSENT *p;

  {
    p = ent->fts_parent;
    while (1) {

      if (!(0L <= p->fts_level)) {
        goto while_break;
      }
      if (p->fts_number) {
        goto while_break;
      }
      p->fts_number = 1L;
      p = p->fts_parent;
    }
  while_break:;
    return;
  }
}
static enum RM_status excise(FTS *fts, FTSENT *ent, struct rm_options const *x,
                             _Bool is_dir) {
  int flag;
  int tmp;
  char const *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  int tmp___4;
  struct stat st;
  int *tmp___5;
  int tmp___6;
  int *tmp___7;
  int *tmp___8;
  int *tmp___9;
  _Bool tmp___10;
  int *tmp___11;
  char const *tmp___12;
  char *tmp___13;
  int *tmp___14;

  {
    if (is_dir) {
      tmp = 512;
    } else {
      tmp = 0;
    }
    flag = tmp;
    tmp___4 = unlinkat(fts->fts_cwd_fd, (char const *)ent->fts_accpath, flag);
    if (tmp___4 == 0) {
      if (x->verbose) {
        tmp___0 = quote((char const *)ent->fts_path);
        if (is_dir) {
          tmp___1 = gettext("removed directory: %s\n");
          tmp___3 = tmp___1;
        } else {
          tmp___2 = gettext("removed %s\n");
          tmp___3 = tmp___2;
        }
        printf((char const *)tmp___3, tmp___0);
      }
      return ((enum RM_status)2);
    }
    tmp___8 = __errno_location();
    if (*tmp___8 == 30) {
      tmp___6 = lstatat(fts->fts_cwd_fd, (char const *)ent->fts_accpath, &st);
      if (tmp___6) {
        tmp___7 = __errno_location();
        if (!(*tmp___7 == 2)) {
          tmp___5 = __errno_location();
          *tmp___5 = 30;
        }
      } else {
        tmp___5 = __errno_location();
        *tmp___5 = 30;
      }
    }
    tmp___9 = __errno_location();
    tmp___10 = ignorable_missing(x, *tmp___9);
    if (tmp___10) {
      return ((enum RM_status)2);
    }
    if ((int)ent->fts_info == 4) {
      tmp___11 = __errno_location();
      *tmp___11 = ent->fts_errno;
    }
    tmp___12 = quote((char const *)ent->fts_path);
    tmp___13 = gettext("cannot remove %s");
    tmp___14 = __errno_location();
    error(0, *tmp___14, (char const *)tmp___13, tmp___12);
    mark_ancestor_dirs(ent);
    return ((enum RM_status)4);
  }
}
