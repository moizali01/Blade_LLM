

strtol_error xstrtoul(char const *s, char **ptr, int strtol_base,
                      unsigned long *val, char const *valid_suffixes) {
  char *t_ptr;
  char **p;
  unsigned long tmp;
  strtol_error err;
  char const *q;
  unsigned char ch;
  unsigned short const **tmp___0;
  int *tmp___1;
  char *tmp___2;
  int *tmp___3;
  int *tmp___4;
  int base;
  int suffixes;
  strtol_error overflow;
  char *tmp___5;
  char *tmp___6;

  {
    err = (strtol_error)0;
    if (0 <= strtol_base) {
      if (!(strtol_base <= 36)) {
        __assert_fail("0 <= strtol_base && strtol_base <= 36",
                      "/home/khheo/project/program-reduce/benchmark/"
                      "coreutils-8.16/lib/xstrtol.c",
                      96U, "xstrtoul");
      }
    } else {
      __assert_fail("0 <= strtol_base && strtol_base <= 36",
                    "/home/khheo/project/program-reduce/benchmark/"
                    "coreutils-8.16/lib/xstrtol.c",
                    96U, "xstrtoul");
    }
    if (ptr) {
      p = ptr;
    } else {
      p = &t_ptr;
    }
    q = s;
    ch = (unsigned char)*q;
    while (1) {
      tmp___0 = __ctype_b_loc();
      if (!((int const) * (*tmp___0 + (int)ch) & 8192)) {
        goto while_break;
      }
      q++;
      ch = (unsigned char)*q;
    }
  while_break:;
    if ((int)ch == 45) {
      return ((strtol_error)4);
    }
    tmp___1 = __errno_location();
    *tmp___1 = 0;
    tmp = strtoul(s, p, strtol_base);
    if ((unsigned long)*p == (unsigned long)s) {
      if (valid_suffixes) {
        if (*(*p)) {
          tmp___2 = strchr(valid_suffixes, (int)*(*p));
          if (tmp___2) {
            tmp = 1UL;
          } else {
            return ((strtol_error)4);
          }
        } else {
          return ((strtol_error)4);
        }
      } else {
        return ((strtol_error)4);
      }
    } else {
      tmp___4 = __errno_location();
      if (*tmp___4 != 0) {
        tmp___3 = __errno_location();
        if (*tmp___3 != 34) {
          return ((strtol_error)4);
        }
        err = (strtol_error)1;
      }
    }
    if (!valid_suffixes) {
      *val = tmp;
      return (err);
    }
    if ((int)*(*p) != 0) {
      base = 1024;
      suffixes = 1;
      tmp___5 = strchr(valid_suffixes, (int)*(*p));
      if (!tmp___5) {
        *val = tmp;
        return ((strtol_error)((unsigned int)err | 2U));
      }
      tmp___6 = strchr(valid_suffixes, '0');
      if (tmp___6) {
        if ((int)*(*(p + 0) + 1) == 105) {
          goto case_105;
        }
        if ((int)*(*(p + 0) + 1) == 66) {
          goto case_66;
        }
        if ((int)*(*(p + 0) + 1) == 68) {
          goto case_66;
        }
        goto switch_break;
      case_105:
        if ((int)*(*(p + 0) + 2) == 66) {
          suffixes += 2;
        }
        goto switch_break;
      case_66:
        base = 1000;
        suffixes++;
        goto switch_break;
      switch_break:;
      }
      if ((int)*(*p) == 98) {
        goto case_98;
      }
      if ((int)*(*p) == 66) {
        goto case_66___0;
      }
      if ((int)*(*p) == 99) {
        goto case_99;
      }
      if ((int)*(*p) == 69) {
        goto case_69;
      }
      if ((int)*(*p) == 71) {
        goto case_71;
      }
      if ((int)*(*p) == 103) {
        goto case_71;
      }
      if ((int)*(*p) == 107) {
        goto case_107;
      }
      if ((int)*(*p) == 75) {
        goto case_107;
      }
      if ((int)*(*p) == 77) {
        goto case_77;
      }
      if ((int)*(*p) == 109) {
        goto case_77;
      }
      if ((int)*(*p) == 80) {
        goto case_80;
      }
      if ((int)*(*p) == 84) {
        goto case_84;
      }
      if ((int)*(*p) == 116) {
        goto case_84;
      }
      if ((int)*(*p) == 119) {
        goto case_119;
      }
      if ((int)*(*p) == 89) {
        goto case_89;
      }
      if ((int)*(*p) == 90) {
        goto case_90;
      }
      goto switch_default;
    case_98:
      overflow = bkm_scale___0(&tmp, 512);
      goto switch_break___0;
    case_66___0:
      overflow = bkm_scale___0(&tmp, 1024);
      goto switch_break___0;
    case_99:
      overflow = (strtol_error)0;
      goto switch_break___0;
    case_69:
      overflow = bkm_scale_by_power___0(&tmp, base, 6);
      goto switch_break___0;
    case_71:
      overflow = bkm_scale_by_power___0(&tmp, base, 3);
      goto switch_break___0;
    case_107:
      overflow = bkm_scale_by_power___0(&tmp, base, 1);
      goto switch_break___0;
    case_77:
      overflow = bkm_scale_by_power___0(&tmp, base, 2);
      goto switch_break___0;
    case_80:
      overflow = bkm_scale_by_power___0(&tmp, base, 5);
      goto switch_break___0;
    case_84:
      overflow = bkm_scale_by_power___0(&tmp, base, 4);
      goto switch_break___0;
    case_119:
      overflow = bkm_scale___0(&tmp, 2);
      goto switch_break___0;
    case_89:
      overflow = bkm_scale_by_power___0(&tmp, base, 8);
      goto switch_break___0;
    case_90:
      overflow = bkm_scale_by_power___0(&tmp, base, 7);
      goto switch_break___0;
    switch_default:
      *val = tmp;
      return ((strtol_error)((unsigned int)err | 2U));
    switch_break___0:
      err = (strtol_error)((unsigned int)err | (unsigned int)overflow);
      *p += suffixes;
      if (*(*p)) {
        err = (strtol_error)((unsigned int)err | 2U);
      }
    }
    *val = tmp;
    return (err);
  }
}
