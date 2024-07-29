

void version_etc_va(FILE *stream, char const *command_name, char const *package,
                    char const *version, va_list authors) {
  size_t n_authors;
  char const *authtab[10];
  char const *tmp;

  {
    n_authors = (size_t)0;
    while (1) {

      if (n_authors < 10UL) {
        tmp = __builtin_va_arg(authors, char const *);
        authtab[n_authors] = tmp;
        if (!((unsigned long)tmp != (unsigned long)((void *)0))) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      n_authors++;
    }
  while_break:
    version_etc_arn(stream, command_name, package, version,
                    (char const *const *)(authtab), n_authors);
    return;
  }
}
