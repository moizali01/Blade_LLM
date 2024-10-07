

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
