

if (size <= qsize) {
  size = qsize + 1UL;
  (slotvec + n)->size = size;
  if ((unsigned long)val != (unsigned long)(slot0)) {
    {
      rpl_free((void *)val);
    }
  }
  {
    tmp___4 = xmalloc(size);
    val = (char *)tmp___4;
    (slotvec + n)->val = val;
    quotearg_buffer(val, size, arg, argsize, options);
  }
}
