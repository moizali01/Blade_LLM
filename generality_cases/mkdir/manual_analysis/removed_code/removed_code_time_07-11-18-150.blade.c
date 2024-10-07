

while (1) {
  ;
  {
    basename_dir = slash;
    slash = strchr((char const *)slash, '/');
  }
  if ((unsigned long)slash == (unsigned long)((void *)0)) {
    goto while_break___0;
  }
  if (!do_chdir) {
    basename_dir = dirpath;
  }
  {
    *slash = (char)'\000';
    fail = make_dir((char const *)basename_dir, (char const *)dirpath,
                    (mode_t)tmp_mode, &newly_created_dir);
  }
  if (fail) {
    {
      while (1) {
        ;
        { umask(oldmask); }
        {
          while (1) {
            ;

            if (do_chdir) {
              {
                tmp___9 = restore_cwd((struct saved_cwd const *)(&cwd));
              }
              if (tmp___9 != 0) {
                {
                  tmp___5 = __errno_location();
                  _saved_errno = *tmp___5;
                  tmp___6 =
                      gettext("failed to return to initial working directory");
                  tmp___7 = __errno_location();
                  error(0, *tmp___7, (char const *)tmp___6);
                  free_cwd(&cwd);
                  tmp___8 = __errno_location();
                  *tmp___8 = _saved_errno;
                }
                return (1);
              }
              { free_cwd(&cwd); }
            }
            goto while_break___2;
          };
        }
      while_break___2:;
        goto while_break___1;
      };
    }
  while_break___1:;
    return (1);
  }
  if (newly_created_dir) {
    if (verbose_fmt_string) {
      {
        tmp___10 = quote((char const *)dirpath);
        error(0, 0, verbose_fmt_string, tmp___10);
      }
    }
    if (owner != 4294967295U) {
      goto _L___0;
    } else {
      if (group != 4294967295U) {
      _L___0: { tmp___19 = chown((char const *)basename_dir, owner, group); }
        if (tmp___19) {
          {
            tmp___11 = quote((char const *)dirpath);
            tmp___12 = gettext("cannot change owner and/or group of %s");
            tmp___13 = __errno_location();
            error(0, *tmp___13, (char const *)tmp___12, tmp___11);
          }
          {
            while (1) {
              ;
              { umask(oldmask); }
              {
                while (1) {
                  ;

                  if (do_chdir) {
                    {
                      tmp___18 = restore_cwd((struct saved_cwd const *)(&cwd));
                    }
                    if (tmp___18 != 0) {
                      {
                        tmp___14 = __errno_location();
                        _saved_errno___0 = *tmp___14;
                        tmp___15 = gettext("failed to return to "
                                           "initial working directory");
                        tmp___16 = __errno_location();
                        error(0, *tmp___16, (char const *)tmp___15);
                        free_cwd(&cwd);
                        tmp___17 = __errno_location();
                        *tmp___17 = _saved_errno___0;
                      }
                      return (1);
                    }
                    { free_cwd(&cwd); }
                  }
                  goto while_break___4;
                };
              }
            while_break___4:;
              goto while_break___3;
            };
          }
        while_break___3:;
          return (1);
        }
      }
    }
    if (re_protect) {
      {
        tmp___20 = __builtin_alloca(sizeof(struct ptr_list));
        new = (struct ptr_list *)tmp___20;
        new->dirname_end = slash;
        new->next = leading_dirs;
        leading_dirs = new;
      }
    }
  }
  if (do_chdir) {
    {
      tmp___29 = chdir((char const *)basename_dir);
    }
    if (tmp___29 < 0) {
      {
        tmp___21 = quote((char const *)dirpath);
        tmp___22 = gettext("cannot chdir to directory %s");
        tmp___23 = __errno_location();
        error(0, *tmp___23, (char const *)tmp___22, tmp___21);
      }
      {
        while (1) {
          ;
          { umask(oldmask); }
          {
            while (1) {
              ;

              if (do_chdir) {
                {
                  tmp___28 = restore_cwd((struct saved_cwd const *)(&cwd));
                }
                if (tmp___28 != 0) {
                  {
                    tmp___24 = __errno_location();
                    _saved_errno___1 = *tmp___24;
                    tmp___25 = gettext("failed to return to initial "
                                       "working directory");
                    tmp___26 = __errno_location();
                    error(0, *tmp___26, (char const *)tmp___25);
                    free_cwd(&cwd);
                    tmp___27 = __errno_location();
                    *tmp___27 = _saved_errno___1;
                  }
                  return (1);
                }
                { free_cwd(&cwd); }
              }
              goto while_break___6;
            };
          }
        while_break___6:;
          goto while_break___5;
        };
      }
    while_break___5:;
      return (1);
    }
  }
  tmp___30 = slash;
  slash++;
  *tmp___30 = (char)'/';
  {
    while (1) {
      ;

      if (!((int)*slash == 47)) {
        goto while_break___7;
      }
      slash++;
    };
  }
while_break___7:;
};
