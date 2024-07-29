

if (tmp == 0) {
  {
    strcpy((char * /* __restrict  */)suff,
           (char const * /* __restrict  */) ".tar");
  }
} else {
  { tmp___0 = strcmp((char const *)suff, ".taz"); }
  if (tmp___0 == 0) {
    {
      strcpy((char * /* __restrict  */)suff,
             (char const * /* __restrict  */) ".tar");
    }
  } else {
    *suff = (char)'\000';
  }
}
