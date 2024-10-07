

if ((unsigned long)*p == (unsigned long)s) {
  if (valid_suffixes) {
    if (*(*p)) {
      {
        tmp___2 = strchr(valid_suffixes, (int)*(*p));
      }
      if (tmp___2) {
        tmp = 1UL;
      } else {
        return ((strtol_error)4);
      }
    } else {
      return ((strtol_error)4);
    }
  } else {
    return ((strtol_error)4);
  }
} else {
  { tmp___4 = __errno_location(); }
  if (*tmp___4 != 0) {
    {
      tmp___3 = __errno_location();
    }
    if (*tmp___3 != 34) {
      return ((strtol_error)4);
    }
    err = (strtol_error)1;
  }
}
