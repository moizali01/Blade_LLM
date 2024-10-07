

if ((unsigned long)slotvec == (unsigned long)(&slotvec0)) {
  {
    tmp___1 = xmalloc(sizeof(*slotvec));
    slotvec = (struct slotvec *)tmp___1;
    *slotvec = slotvec0;
  }
}
