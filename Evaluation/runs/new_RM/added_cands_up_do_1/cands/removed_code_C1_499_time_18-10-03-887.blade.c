

if (prev_fail) {
  goto _L___0;
} else {
  if (fclose_fail) {
    if (some_pending) {
      goto _L___0;
    } else {
      tmp___3 = __errno_location();
      if (*tmp___3 != 9) {
      _L___0:
        if (!fclose_fail) {
          tmp___2 = __errno_location();
          *tmp___2 = 0;
        }
        return (-1);
      }
    }
  }
}
