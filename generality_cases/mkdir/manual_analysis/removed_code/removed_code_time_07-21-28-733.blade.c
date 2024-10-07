

if ((int)*(*p) != 0) {
  {
    base = 1024;
    suffixes = 1;
    tmp___5 = strchr(valid_suffixes, (int)*(*p));
  }
  if (!tmp___5) {
    *val = tmp;
    return ((strtol_error)((unsigned int)err | 2U));
  }
  { tmp___6 = strchr(valid_suffixes, '0'); }
  if (tmp___6) {
    if ((int)*(*(p + 0) + 1) == 105) {
      goto case_105;
    }
    if ((int)*(*(p + 0) + 1) == 68) {
      goto case_68;
    }
    if ((int)*(*(p + 0) + 1) == 66) {
      goto case_68;
    }
    goto switch_break;
  case_105:
    if ((int)*(*(p + 0) + 2) == 66) {
      suffixes += 2;
    }
    goto switch_break;
  case_68:
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
  if ((int)*(*p) == 103) {
    goto case_103;
  }
  if ((int)*(*p) == 71) {
    goto case_103;
  }
  if ((int)*(*p) == 75) {
    goto case_75;
  }
  if ((int)*(*p) == 107) {
    goto case_75;
  }
  if ((int)*(*p) == 109) {
    goto case_109;
  }
  if ((int)*(*p) == 77) {
    goto case_109;
  }
  if ((int)*(*p) == 80) {
    goto case_80;
  }
  if ((int)*(*p) == 116) {
    goto case_116;
  }
  if ((int)*(*p) == 84) {
    goto case_116;
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
case_98: { overflow = bkm_scale___0(&tmp, 512); }
  goto switch_break___0;
case_66___0: { overflow = bkm_scale___0(&tmp, 1024); }
  goto switch_break___0;
case_99:
  overflow = (strtol_error)0;
  goto switch_break___0;
case_69: { overflow = bkm_scale_by_power___0(&tmp, base, 6); }
  goto switch_break___0;
case_103: { overflow = bkm_scale_by_power___0(&tmp, base, 3); }
  goto switch_break___0;
case_75: { overflow = bkm_scale_by_power___0(&tmp, base, 1); }
  goto switch_break___0;
case_109: { overflow = bkm_scale_by_power___0(&tmp, base, 2); }
  goto switch_break___0;
case_80: { overflow = bkm_scale_by_power___0(&tmp, base, 5); }
  goto switch_break___0;
case_116: { overflow = bkm_scale_by_power___0(&tmp, base, 4); }
  goto switch_break___0;
case_119: { overflow = bkm_scale___0(&tmp, 2); }
  goto switch_break___0;
case_89: { overflow = bkm_scale_by_power___0(&tmp, base, 8); }
  goto switch_break___0;
case_90: { overflow = bkm_scale_by_power___0(&tmp, base, 7); }
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
