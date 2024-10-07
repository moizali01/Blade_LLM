

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
