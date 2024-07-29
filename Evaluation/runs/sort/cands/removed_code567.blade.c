

if (valid_suffixes) {
  if (*(*p)) {
    tmp___2 = strchr(valid_suffixes, (int)*(*p));
    if (tmp___2) {
      tmp = (uintmax_t)1;
    } else {
      return ((strtol_error)4);
    }
  } else {
    return ((strtol_error)4);
  }
} else {
  return ((strtol_error)4);
}
