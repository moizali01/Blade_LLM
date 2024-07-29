

__inline static void emit_ancillary_info(void) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char const *lc_messages;
  char const *tmp___3;
  char *tmp___4;
  char *tmp___5;
  int tmp___6;
  char *tmp___7;
  char *tmp___8;

  {
    tmp = last_component(program_name);
    tmp___0 = gettext("\nReport %s bugs to %s\n");
    printf((char const *)tmp___0, tmp, "bug-coreutils@gnu.org");
    tmp___1 = gettext("%s home page: <http://www.gnu.org/software/%s/>\n");
    printf((char const *)tmp___1, "GNU coreutils", "coreutils");
    tmp___2 = gettext(
        "General help using GNU software: <http://www.gnu.org/gethelp/>\n");
    fputs_unlocked((char const *)tmp___2, stdout);
    tmp___3 = (char const *)setlocale(5, (char const *)((void *)0));
    lc_messages = tmp___3;
    if (lc_messages) {
      tmp___6 = strncmp(lc_messages, "en_", (size_t)3);
      if (tmp___6) {
        tmp___4 = last_component(program_name);
        tmp___5 = gettext("Report %s translation bugs to "
                          "<http://translationproject.org/team/>\n");
        printf((char const *)tmp___5, tmp___4);
      }
    }
    tmp___7 = last_component(program_name);
    tmp___8 = gettext(
        "For complete documentation, run: info coreutils \'%s invocation\'\n");
    printf((char const *)tmp___8, tmp___7);
    return;
  }
}
