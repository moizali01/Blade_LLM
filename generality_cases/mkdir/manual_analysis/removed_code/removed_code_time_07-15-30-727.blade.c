

if (nslots <= n0) {
  n1 = n0 + 1U;
  if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
    tmp___0 = -1;
  } else {
    tmp___0 = -2;
  }
  if ((size_t)tmp___0 / sizeof(*slotvec) < (size_t)n1) {
    {
      xalloc_die();
    }
  }
  if ((unsigned long)slotvec == (unsigned long)(&slotvec0)) {
    {
      tmp___1 = xmalloc(sizeof(*slotvec));
      slotvec = (struct slotvec *)tmp___1;
      *slotvec = slotvec0;
    }
  }
  {
    tmp___2 = xrealloc((void *)slotvec, (unsigned long)n1 * sizeof(*slotvec));
    slotvec = (struct slotvec *)tmp___2;
    memset((void *)(slotvec + nslots), 0,
           (unsigned long)(n1 - nslots) * sizeof(*slotvec));
    nslots = n1;
  }
}
