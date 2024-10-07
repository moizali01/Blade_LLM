

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
