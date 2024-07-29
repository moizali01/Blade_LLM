

void version_etc_arn(FILE *stream, char const *command_name,
                     char const *package, char const *version,
                     char const *const *authors, size_t n_authors) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char *tmp___2;
  char *tmp___3;
  char *tmp___4;
  char *tmp___5;
  char *tmp___6;
  char *tmp___7;
  char *tmp___8;
  char *tmp___9;
  char *tmp___10;

  {
    if (command_name) {
      fprintf(stream, "%s (%s) %s\n", command_name, package, version);
    } else {
      fprintf(stream, "%s %s\n", package, version);
    }
    tmp = gettext("(C)");
    fprintf(stream, version_etc_copyright, tmp, 2010);
    tmp___0 =
        gettext("\nLicense GPLv3+: GNU GPL version 3 or later "
                "<http://gnu.org/licenses/gpl.html>.\nThis is free software: "
                "you are free to change and redistribute it.\nThere is NO "
                "WARRANTY, to the extent permitted by law.\n\n");
    fputs_unlocked((char const *)tmp___0, stream);
    if (n_authors == 0UL) {
      goto case_0;
    }
    if (n_authors == 1UL) {
      goto case_1;
    }
    if (n_authors == 2UL) {
      goto case_2;
    }
    if (n_authors == 3UL) {
      goto case_3;
    }
    if (n_authors == 4UL) {
      goto case_4;
    }
    if (n_authors == 5UL) {
      goto case_5;
    }
    if (n_authors == 6UL) {
      goto case_6;
    }
    if (n_authors == 7UL) {
      goto case_7;
    }
    if (n_authors == 8UL) {
      goto case_8;
    }
    if (n_authors == 9UL) {
      goto case_9;
    }
    goto switch_default;
  case_0:
    abort();
  case_1:
    tmp___1 = gettext("Written by %s.\n");
    fprintf(stream, (char const *)tmp___1, *(authors + 0));
    goto switch_break;
  case_2:
    tmp___2 = gettext("Written by %s and %s.\n");
    fprintf(stream, (char const *)tmp___2, *(authors + 0), *(authors + 1));
    goto switch_break;
  case_3:
    tmp___3 = gettext("Written by %s, %s, and %s.\n");
    fprintf(stream, (char const *)tmp___3, *(authors + 0), *(authors + 1),
            *(authors + 2));
    goto switch_break;
  case_4:
    tmp___4 = gettext("Written by %s, %s, %s,\nand %s.\n");
    fprintf(stream, (char const *)tmp___4, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3));
    goto switch_break;
  case_5:
    tmp___5 = gettext("Written by %s, %s, %s,\n%s, and %s.\n");
    fprintf(stream, (char const *)tmp___5, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4));
    goto switch_break;
  case_6:
    tmp___6 = gettext("Written by %s, %s, %s,\n%s, %s, and %s.\n");
    fprintf(stream, (char const *)tmp___6, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5));
    goto switch_break;
  case_7:
    tmp___7 = gettext("Written by %s, %s, %s,\n%s, %s, %s, and %s.\n");
    fprintf(stream, (char const *)tmp___7, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6));
    goto switch_break;
  case_8:
    tmp___8 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\nand %s.\n");
    fprintf(stream, (char const *)tmp___8, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6), *(authors + 7));
    goto switch_break;
  case_9:
    tmp___9 = gettext("Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, and %s.\n");
    fprintf(stream, (char const *)tmp___9, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6), *(authors + 7), *(authors + 8));
    goto switch_break;
  switch_default:
    tmp___10 = gettext(
        "Written by %s, %s, %s,\n%s, %s, %s, %s,\n%s, %s, and others.\n");
    fprintf(stream, (char const *)tmp___10, *(authors + 0), *(authors + 1),
            *(authors + 2), *(authors + 3), *(authors + 4), *(authors + 5),
            *(authors + 6), *(authors + 7), *(authors + 8));
    goto switch_break;
  switch_break:;
    return;
  }
}
