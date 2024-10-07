

if ((parent_mode & 192) != 192) {
  tmp_mode = 448;
  re_protect = 1;
} else {
  if (owner != 4294967295U) {
    goto _L;
  } else {
    if (group != 4294967295U) {
    _L:
      if ((parent_mode & 3584) != 0) {
        tmp_mode = 448;
        re_protect = 1;
      } else {
        tmp_mode = parent_mode;
        re_protect = 0;
      }
    } else {
      tmp_mode = parent_mode;
      re_protect = 0;
    }
  }
}
