

static char *known_suffixes[9] = {
    z_suffix,       (char *)".gz",  (char *)".z",
    (char *)".taz", (char *)".tgz", (char *)"-gz",
    (char *)"-z",   (char *)"_z",   (char *)((void *)0)};
static char *get_suffix(char *name) {
  int nlen;
  int slen;
  char suffix[33];
  char **suf;
  int tmp;
  int s;
  int tmp___0;
  int tmp___1;
  void *__cil_tmp13;

  {
    {
      suf = known_suffixes;
      tmp = strcmp((char const *)(z_suffix), "z");
    }
    if (tmp == 0) {
      suf++;
    }
    { nlen = (int)strlen((char const *)name); }
    if (nlen <= 32) {
      {
        strcpy((char * /* __restrict  */)(suffix),
               (char const * /* __restrict  */)name);
      }
    } else {
      {
        strcpy((char * /* __restrict  */)(suffix),
               (char const * /* __restrict  */)(((name + nlen) - 30) - 2));
      }
    }
    {
      strlwr(suffix);
      slen = (int)strlen((char const *)(suffix));
    }
    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
        {
          tmp___0 = (int)strlen((char const *)*suf);
          s = tmp___0;
        }
        if (slen > s) {
          if ((int)suffix[(slen - s) - 1] != 47) {
            {
              tmp___1 = strcmp((char const *)((suffix + slen) - s),
                               (char const *)*suf);
            }
            if (tmp___1 == 0) {
              return ((name + nlen) - s);
            }
          }
        }
        suf++;
        if (!((unsigned long)*suf != (unsigned long)((void *)0))) {
          goto while_break;
        }
      }
    while_break: /* CIL Label */
                 ;
    }
    return ((char *)((void *)0));
  }
}
static char *suffixes[6] = {z_suffix,     (char *)".gz", (char *)".z",
                            (char *)"-z", (char *)".Z",  (char *)((void *)0)};
