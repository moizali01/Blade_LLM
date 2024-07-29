

if (verbose) {
  { tmp___10 = strlen((char const *)(ifname)); }
  if ((int)tmp___10 >= 15) {
    tmp___9 = "";
  } else {
    { tmp___8 = strlen((char const *)(ifname)); }
    if ((int)tmp___8 >= 7) {
      tmp___7 = "\t";
    } else {
      tmp___7 = "\t\t";
    }
    tmp___9 = tmp___7;
  }
  {
    fprintf((FILE * /* __restrict  */) stderr,
            (char const * /* __restrict  */) "%s:\t%s", ifname, tmp___9);
  }
}
