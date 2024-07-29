

if (status != 0) {
  tmp = gettext("Try `%s --help\' for more information.\n");
  fprintf(stderr, (char const *)tmp, program_name);
} else {
  tmp___0 = gettext("Usage: %s [OPTION]... FILE...\n");
  printf((char const *)tmp___0, program_name);
  tmp___1 = gettext("Remove (unlink) the FILE(s).\n\n  -f, --force         "
                    "  ignore nonexistent files, never prompt\n  -i        "
                    "            prompt before every removal\n");
  fputs_unlocked((char const *)tmp___1, stdout);
  tmp___2 = gettext(
      "  -I                    prompt once before removing more than three "
      "files, or\n                          when removing recursively.  "
      "Less intrusive than -i,\n                          while still "
      "giving protection against most mistakes\n      --interactive[=WHEN] "
      " prompt according to WHEN: never, once (-I), or\n                   "
      "       always (-i).  Without WHEN, prompt always\n");
  fputs_unlocked((char const *)tmp___2, stdout);
  tmp___3 =
      gettext("      --one-file-system  when removing a hierarchy "
              "recursively, skip any\n                          directory "
              "that is on a file system different from\n                   "
              "       that of the corresponding command line argument\n");
  fputs_unlocked((char const *)tmp___3, stdout);
  tmp___4 = gettext(
      "      --no-preserve-root  do not treat `/\' specially\n      "
      "--preserve-root   do not remove `/\' (default)\n  -r, -R, "
      "--recursive   remove directories and their contents recursively\n  "
      "-v, --verbose         explain what is being done\n");
  fputs_unlocked((char const *)tmp___4, stdout);
  tmp___5 = gettext("      --help     display this help and exit\n");
  fputs_unlocked((char const *)tmp___5, stdout);
  tmp___6 = gettext("      --version  output version information and exit\n");
  fputs_unlocked((char const *)tmp___6, stdout);
  tmp___7 = gettext("\nBy default, rm does not remove directories.  Use the "
                    "--recursive (-r or -R)\noption to remove each listed "
                    "directory, too, along with all of its contents.\n");
  fputs_unlocked((char const *)tmp___7, stdout);
  tmp___8 = gettext("\nTo remove a file whose name starts with a `-\', for "
                    "example `-foo\',\nuse one of these commands:\n  %s -- "
                    "-foo\n\n  %s ./-foo\n");
  printf((char const *)tmp___8, program_name, program_name);
  tmp___9 = gettext("\nNote that if you use rm to remove a file, it is "
                    "usually possible to recover\nthe contents of that "
                    "file.  If you want more assurance that the contents "
                    "are\ntruly unrecoverable, consider using shred.\n");
  fputs_unlocked((char const *)tmp___9, stdout);
  emit_ancillary_info();
}
