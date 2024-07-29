

char *quotearg_char_mem(char const *arg, size_t argsize, char ch) {
  struct quoting_options options;
  char *tmp;

  {
    options = default_quoting_options;
    set_char_quoting(&options, ch, 1);
    tmp = quotearg_n_options(0, arg, argsize,
                             (struct quoting_options const *)(&options));
    return (tmp);
  }
}
char *quotearg_char(char const *arg, char ch) {
  char *tmp;

  {
    tmp = quotearg_char_mem(arg, (size_t)-1, ch);
    return (tmp);
  }
}
