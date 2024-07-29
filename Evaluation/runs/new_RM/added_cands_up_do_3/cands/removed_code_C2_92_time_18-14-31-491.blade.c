

if ((sbp->st_mode & 61440U) == 40960U) {
  return ((unsigned short)12);
}
if ((sbp->st_mode & 61440U) == 32768U) {
  return ((unsigned short)8);
}
return ((unsigned short)3);
