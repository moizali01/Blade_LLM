

size_t base_len(char const *name) {
  size_t len;
  size_t prefix_len;

  {
    prefix_len = (size_t)0;
    len = strlen(name);
    while (1) {

      if (1UL < len) {
        if (!((int const) * (name + (len - 1UL)) == 47)) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      goto __Cont;
    __Cont:
      len--;
    }
  while_break:;
    return (len);
  }
}
