

if (tmp___65) {
  {
    leading_dirs = (struct ptr_list *)((void *)0);
    tmp = umask((__mode_t)0);
    oldmask = tmp;
    tmp___0 = strlen(argpath);
    tmp___1 = __builtin_alloca(tmp___0 + 1UL);
    dirpath = (char *)tmp___1;
    strcpy((char * /* __restrict  */)dirpath,
           (char const * /* __restrict  */)argpath);
    strip_trailing_slashes(dirpath);
  }
  if ((parent_mode & 192) != 192) {
    tmp_mode = 448;
    re_protect = 1;
  } else {
    if (owner != 4294967295U) {
      goto _L;
    } else {
      if (group != 4294967295U) {
      _L:
        if ((parent_mode & 3584) != 0) {
          tmp_mode = 448;
          re_protect = 1;
        } else {
          tmp_mode = parent_mode;
          re_protect = 0;
        }
      } else {
        tmp_mode = parent_mode;
        re_protect = 0;
      }
    }
  }
  { tmp___2 = save_cwd(&cwd); }
  if (tmp___2) {
    tmp___3 = 0;
  } else {
    tmp___3 = 1;
  }
  do_chdir = tmp___3;
  if (do_chdir) {
    if ((int)*dirpath == 47) {
      {
        tmp___4 = chdir("/");
      }
      if (tmp___4 < 0) {
        do_chdir = 0;
      }
    }
  }
  slash = dirpath;
  {
    while (1) {
      ;

      if (!((int)*slash == 47)) {
        goto while_break;
      }
      slash++;
    };
  }
while_break:;
  {
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
                      tmp___6 = gettext(
                          "failed to return to initial working directory");
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
          _L___0: {
            tmp___19 = chown((char const *)basename_dir, owner, group);
          }
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
                          tmp___18 =
                              restore_cwd((struct saved_cwd const *)(&cwd));
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
  }
while_break___0:;
  if (!do_chdir) {
    basename_dir = dirpath;
  }
  {
    umask(oldmask);
    tmp___36 = make_dir((char const *)basename_dir, (char const *)dirpath,
                        (mode_t)mode, (int *)((void *)0));
  }
  if (tmp___36) {
    {
      while (1) {
        ;
        { umask(oldmask); }
        {
          while (1) {
            ;

            if (do_chdir) {
              {
                tmp___35 = restore_cwd((struct saved_cwd const *)(&cwd));
              }
              if (tmp___35 != 0) {
                {
                  tmp___31 = __errno_location();
                  _saved_errno___2 = *tmp___31;
                  tmp___32 =
                      gettext("failed to return to initial working directory");
                  tmp___33 = __errno_location();
                  error(0, *tmp___33, (char const *)tmp___32);
                  free_cwd(&cwd);
                  tmp___34 = __errno_location();
                  *tmp___34 = _saved_errno___2;
                }
                return (1);
              }
              { free_cwd(&cwd); }
            }
            goto while_break___9;
          };
        }
      while_break___9:;
        goto while_break___8;
      };
    }
  while_break___8:;
    return (1);
  }
  if ((unsigned long)verbose_fmt_string != (unsigned long)((void *)0)) {
    {
      tmp___37 = quote((char const *)dirpath);
      error(0, 0, verbose_fmt_string, tmp___37);
    }
  }
  if (owner != 4294967295U) {
    goto _L___1;
  } else {
    if (group != 4294967295U) {
    _L___1: { tmp___41 = chown((char const *)basename_dir, owner, group); }
      if (tmp___41) {
        {
          tmp___38 = quote((char const *)dirpath);
          tmp___39 = gettext("cannot change owner and/or group of %s");
          tmp___40 = __errno_location();
          error(0, *tmp___40, (char const *)tmp___39, tmp___38);
          retval = 1;
        }
      }
    }
  }
  if (mode & ~((448 | (448 >> 3)) | ((448 >> 3) >> 3))) {
    {
      tmp___45 = chmod((char const *)basename_dir, (__mode_t)mode);
    }
    if (tmp___45) {
      {
        tmp___42 = quote((char const *)dirpath);
        tmp___43 = gettext("cannot change permissions of %s");
        tmp___44 = __errno_location();
        error(0, *tmp___44, (char const *)tmp___43, tmp___42);
        retval = 1;
      }
    }
  }
  {
    while (1) {
      ;

      if (do_chdir) {
        {
          tmp___50 = restore_cwd((struct saved_cwd const *)(&cwd));
        }
        if (tmp___50 != 0) {
          {
            tmp___46 = __errno_location();
            _saved_errno___3 = *tmp___46;
            tmp___47 = gettext("failed to return to initial working directory");
            tmp___48 = __errno_location();
            error(0, *tmp___48, (char const *)tmp___47);
            free_cwd(&cwd);
            tmp___49 = __errno_location();
            *tmp___49 = _saved_errno___3;
          }
          return (1);
        }
        { free_cwd(&cwd); }
      }
      goto while_break___10;
    };
  }
while_break___10:
  p = leading_dirs;
  {
    while (1) {
      ;

      if (!((unsigned long)p != (unsigned long)((void *)0))) {
        goto while_break___11;
      }
      {
        *(p->dirname_end) = (char)'\000';
        tmp___54 = chmod((char const *)dirpath, (__mode_t)parent_mode);
      }
      if (tmp___54) {
        {
          tmp___51 = quote((char const *)dirpath);
          tmp___52 = gettext("cannot change permissions of %s");
          tmp___53 = __errno_location();
          error(0, *tmp___53, (char const *)tmp___52, tmp___51);
          retval = 1;
        }
      }
      p = p->next;
    };
  }
while_break___11:;
} else {
  dirpath___0 = argpath;
  if (!((stats.st_mode & 61440U) == 16384U)) {
    {
      tmp___55 = quote(dirpath___0);
      tmp___56 = gettext("%s exists but is not a directory");
      error(0, 0, (char const *)tmp___56, tmp___55);
    }
    return (1);
  }
  if (!preserve_existing) {
    if (owner != 4294967295U) {
      goto _L___2;
    } else {
      if (group != 4294967295U) {
      _L___2: { tmp___60 = chown(dirpath___0, owner, group); }
        if (tmp___60) {
          {
            tmp___57 = quote(dirpath___0);
            tmp___58 = gettext("cannot change owner and/or group of %s");
            tmp___59 = __errno_location();
            error(0, *tmp___59, (char const *)tmp___58, tmp___57);
            retval = 1;
          }
        }
      }
    }
    { tmp___64 = chmod(dirpath___0, (__mode_t)mode); }
    if (tmp___64) {
      {
        tmp___61 = quote(dirpath___0);
        tmp___62 = gettext("cannot change permissions of %s");
        tmp___63 = __errno_location();
        error(0, *tmp___63, (char const *)tmp___62, tmp___61);
        retval = 1;
      }
    }
  }
}
