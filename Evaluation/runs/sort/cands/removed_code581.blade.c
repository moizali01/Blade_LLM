

_Bool c_isalnum(int c) {
  int tmp;

  {
    if (c >= 48) {
      if (c <= 57) {
        tmp = 1;
      } else {
        goto _L;
      }
    } else {
    _L:
      if ((c & -33) >= 65) {
        if ((c & -33) <= 90) {
          tmp = 1;
        } else {
          tmp = 0;
        }
      } else {
        tmp = 0;
      }
    }
    return ((_Bool)tmp);
  }
}
