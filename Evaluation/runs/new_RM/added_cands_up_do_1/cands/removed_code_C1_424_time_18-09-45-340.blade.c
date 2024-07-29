

_Bool strip_trailing_slashes(char *file) {
  char *base;
  char *tmp;
  char *base_lim;
  _Bool had_slash;
  size_t tmp___0;

  {
    tmp = last_component((char const *)file);
    base = tmp;
    if (!*base) {
      base = file;
    }
    tmp___0 = base_len((char const *)base);
    base_lim = base + tmp___0;
    had_slash = (_Bool)((int)*base_lim != 0);
    *base_lim = (char)'\000';
    return (had_slash);
  }
}
