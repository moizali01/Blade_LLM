

if ((int)*(optarg + 0) == 43) {
  if (optind != argc) {
    if ((int)*(*(argv + optind) + 0) == 45) {
      if ((unsigned int)*(*(argv + optind) + 1) - 48U <= 9U) {
        tmp___5 = 1;
      } else {
        tmp___5 = 0;
      }
    } else {
      tmp___5 = 0;
    }
  } else {
    tmp___5 = 0;
  }
  minus_pos_usage = (_Bool)tmp___5;
  if (minus_pos_usage) {
    if (!posixly_correct) {
      tmp___6 = 1;
    } else {
      tmp___6 = 0;
    }
  } else {
    tmp___6 = 0;
  }
  obsolete_usage = (_Bool)((int)obsolete_usage | tmp___6);
  if (obsolete_usage) {
    key = key_init(&key_buf);
    s = parse_field_count((char const *)(optarg + 1), &key->sword,
                          (char const *)((void *)0));
    if (s) {
      if ((int const) * s == 46) {
        s = parse_field_count(s + 1, &key->schar, (char const *)((void *)0));
      }
    }
    if (!key->sword) {
      if (!key->schar) {
        key->sword = 0xffffffffffffffffUL;
      }
    }
    if (!s) {
      key = (struct keyfield *)((void *)0);
    } else {
      tmp___9 = set_ordering(s, key, (enum blanktype)0);
      if (*tmp___9) {
        key = (struct keyfield *)((void *)0);
      } else {
        if (minus_pos_usage) {
          tmp___7 = optind;
          optind++;
          optarg1 = (char const *)*(argv + tmp___7);
          s = parse_field_count(optarg1 + 1, &key->eword,
                                "invalid number after \'-\'");
          if ((int const) * s == 46) {
            s = parse_field_count(s + 1, &key->echar,
                                  "invalid number after \'.\'");
          }
          if (!key->echar) {
            if (key->eword) {
              (key->eword)--;
            }
          }
          tmp___8 = set_ordering(s, key, (enum blanktype)1);
          if (*tmp___8) {
            badfieldspec(optarg1, "stray character in field spec");
          }
        }
        key->obsolete_used = (_Bool)1;
        insertkey(key);
      }
    }
  }
}
