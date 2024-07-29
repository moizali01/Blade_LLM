

void version_etc(FILE *stream, char const *command_name, char const *package,
                 char const *version, ...) {
  va_list authors;

  {
    __builtin_va_start(authors, version);
    version_etc_va(stream, command_name, package, version, authors);
    __builtin_va_end(authors);
    return;
  }
}
