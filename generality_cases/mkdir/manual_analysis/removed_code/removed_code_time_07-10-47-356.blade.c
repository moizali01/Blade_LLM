

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
