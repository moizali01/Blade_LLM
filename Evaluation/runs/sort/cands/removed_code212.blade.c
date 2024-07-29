

if (!gkey_only) {
  if (tab == 128) {
    if (!line_offset) {
      if (!key->skipsblanks) {
        if (implicit_skip) {
          goto _L___0;
        } else {
          if (maybe_space_aligned) {
            goto _L___0;
          } else {
            tmp___17 = gettext("leading blanks are significant in key "
                               "%lu; consider also specifying \'b\'");
            error(0, 0, (char const *)tmp___17, keynum);
          }
        }
      } else {
      _L___0:
        if (!key->skipsblanks) {
          if (key->schar) {
            tmp___17 = gettext("leading blanks are significant in key "
                               "%lu; consider also specifying \'b\'");
            error(0, 0, (char const *)tmp___17, keynum);
          } else {
            goto _L;
          }
        } else {
        _L:
          if (!key->skipeblanks) {
            if (key->echar) {
              tmp___17 = gettext("leading blanks are significant in key "
                                 "%lu; consider also specifying \'b\'");
              error(0, 0, (char const *)tmp___17, keynum);
            }
          }
        }
      }
    }
  }
}
