

static void badfieldspec(char const *spec, char const *msgid) {
  char const *tmp;
  char *tmp___0;
  char *tmp___1;

  {
    tmp = quote(spec);
    tmp___0 = gettext(msgid);
    tmp___1 = gettext("%s: invalid field specification %s");
    error(2, 0, (char const *)tmp___1, tmp___0, tmp);
    abort();
  }
}
