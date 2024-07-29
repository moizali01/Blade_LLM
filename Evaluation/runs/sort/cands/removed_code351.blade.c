

__inline static int order(unsigned char c) {
  _Bool tmp;
  _Bool tmp___0;

  {
    tmp___0 = c_isdigit((int)c);
    if (tmp___0) {
      return (0);
    } else {
      tmp = c_isalpha((int)c);
      if (tmp) {
        return ((int)c);
      } else {
        if ((int)c == 126) {
          return (-1);
        } else {
          return (((int)c + 255) + 1);
        }
      }
    }
  }
}
