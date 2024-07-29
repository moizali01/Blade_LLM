

if ((int const) * (*tmp___4 + (int)c) & 16384) {
  if (width == 2147483647) {
    goto overflow;
  }
  width++;
} else {
  if (!(flags & 2)) {
    tmp___3 = __ctype_b_loc();
    if (!((int const) * (*tmp___3 + (int)c) & 2)) {
      if (width == 2147483647) {
        goto overflow;
      }
      width++;
    }
  } else {
    return (-1);
  }
}
