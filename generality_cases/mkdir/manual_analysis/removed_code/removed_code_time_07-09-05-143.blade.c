

if ((unsigned long)change == (unsigned long)((struct mode_change *)0)) {
  {
    tmp___4 = quote(specified_mode);
    tmp___5 = gettext("invalid mode %s");
    error(1, 0, (char const *)tmp___5, tmp___4);
  }
} else {
  if ((unsigned long)change == (unsigned long)((struct mode_change *)1)) {
    {
      xalloc_die();
    }
  }
}
