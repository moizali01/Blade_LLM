

static void check_ordering_compatibility(void) {
  struct keyfield *key;
  char opts___1[sizeof(short_options)];
  _Bool tmp;
  _Bool tmp___0;

  {
    key = keylist;
    while (1) {

      if (!key) {
        goto while_break;
      }
      if (1 < ((((int)key->numeric + (int)key->general_numeric) +
                (int)key->human_numeric) +
               (int)key->month) +
                  (((int)key->version | (int)key->random) | !(!key->ignore))) {
        tmp___0 = (_Bool)0;
        key->reverse = tmp___0;
        tmp = tmp___0;
        key->skipeblanks = tmp;
        key->skipsblanks = tmp;
        key_to_opts((struct keyfield const *)key, opts___1);
        incompatible_options((char const *)(opts___1));
      }
      key = key->next;
    }
  while_break:;
    return;
  }
}
