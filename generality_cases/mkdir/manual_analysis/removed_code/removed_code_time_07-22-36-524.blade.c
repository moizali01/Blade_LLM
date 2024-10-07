

while (1) {
  ;
  tmp___0 = power;
  power--;
  if (!tmp___0) {
    goto while_break;
  }
  {
    tmp = bkm_scale___0(x, base);
    err = (strtol_error)((unsigned int)err | (unsigned int)tmp);
  }
};
