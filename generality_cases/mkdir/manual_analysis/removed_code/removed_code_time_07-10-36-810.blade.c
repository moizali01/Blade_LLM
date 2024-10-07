

if (!preserve_existing) {
  if (owner != 4294967295U) {
    goto _L___2;
  } else {
    if (group != 4294967295U) {
    _L___2: { tmp___60 = chown(dirpath___0, owner, group); }
      if (tmp___60) {
        {
          tmp___57 = quote(dirpath___0);
          tmp___58 = gettext("cannot change owner and/or group of %s");
          tmp___59 = __errno_location();
          error(0, *tmp___59, (char const *)tmp___58, tmp___57);
          retval = 1;
        }
      }
    }
  }
  { tmp___64 = chmod(dirpath___0, (__mode_t)mode); }
  if (tmp___64) {
    {
      tmp___61 = quote(dirpath___0);
      tmp___62 = gettext("cannot change permissions of %s");
      tmp___63 = __errno_location();
      error(0, *tmp___63, (char const *)tmp___62, tmp___61);
      retval = 1;
    }
  }
}
