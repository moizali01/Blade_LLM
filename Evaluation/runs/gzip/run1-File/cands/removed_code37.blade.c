

tstat = *statb;
*(name + (s - 1)) = (char)'\000';
tmp___0 = stat((char const * /* __restrict  */)name,
               (struct stat * /* __restrict  */)(&tstat));
