

if (status != 0) {
  {
    tmp = gettext("Try `%s --help\' for more information.\n");
    fprintf((FILE * /* __restrict  */)stderr,
            (char const * /* __restrict  */)((char const *)tmp), program_name);
  }
} else {
  {
    tmp___0 = gettext("Usage: %s [OPTION] DIRECTORY...\n");
    printf((char const * /* __restrict  */)((char const *)tmp___0),
           program_name);
    tmp___1 =
        gettext("Create the DIRECTORY(ies), if they do not already exist.\n\n");
    fputs_unlocked((char const * /* __restrict  */)((char const *)tmp___1),
                   (FILE * /* __restrict  */)stdout);
    tmp___2 = gettext("Mandatory arguments to long options are mandatory "
                      "for short options too.\n");
    fputs_unlocked((char const * /* __restrict  */)((char const *)tmp___2),
                   (FILE * /* __restrict  */)stdout);
    tmp___3 = gettext(
        "  -m, --mode=MODE   set permission mode (as in chmod), not "
        "rwxrwxrwx - umask\n  -p, --parents     no error if existing, make "
        "parent directories as needed\n  -v, --verbose     print a message "
        "for each created directory\n");
    fputs_unlocked((char const * /* __restrict  */)((char const *)tmp___3),
                   (FILE * /* __restrict  */)stdout);
    tmp___4 = gettext("      --help     display this help and exit\n");
    fputs_unlocked((char const * /* __restrict  */)((char const *)tmp___4),
                   (FILE * /* __restrict  */)stdout);
    tmp___5 = gettext("      --version  output version information and exit\n");
    fputs_unlocked((char const * /* __restrict  */)((char const *)tmp___5),
                   (FILE * /* __restrict  */)stdout);
    tmp___6 = gettext("\nReport bugs to <%s>.\n");
    printf((char const * /* __restrict  */)((char const *)tmp___6),
           "bug-coreutils@gnu.org");
  }
}
