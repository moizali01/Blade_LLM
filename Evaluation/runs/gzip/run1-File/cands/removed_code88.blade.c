

while (1) {
while_continue: /* CIL Label */
                ;
  {
    s = *suf;
    strcat((char * /* __restrict  */)(ifname),
           (char const * /* __restrict  */)s);
    tmp___2 = do_stat(ifname, sbuf);
  }
  if (tmp___2 == 0) {
    return (0);
  }
  ifname[ilen] = (char)'\000';
  suf++;
  if (!((unsigned long)*suf != (unsigned long)((void *)0))) {
    goto while_break;
  }
}
while_break:
