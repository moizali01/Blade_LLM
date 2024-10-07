

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
