

__inline static _Bool dot_or_dotdot(char const *file_name___3) {
  char sep;
  int tmp;

  {
    if ((int const) * (file_name___3 + 0) == 46) {
      sep = (char)*(file_name___3 +
                    (((int const) * (file_name___3 + 1) == 46) + 1));
      if (!sep) {
        tmp = 1;
      } else {
        if ((int)sep == 47) {
          tmp = 1;
        } else {
          tmp = 0;
        }
      }
      return ((_Bool)tmp);
    } else {
      return ((_Bool)0);
    }
  }
}
