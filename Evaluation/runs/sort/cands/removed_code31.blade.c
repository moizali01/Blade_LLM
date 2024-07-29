

if ((int const) * s == 46) {
  s = parse_field_count(s + 1, &key->schar, "invalid number after \'.\'");
  tmp___16 = key->schar;
  (key->schar)--;
  if (!tmp___16) {
    badfieldspec((char const *)optarg, "character offset is zero");
  }
}
