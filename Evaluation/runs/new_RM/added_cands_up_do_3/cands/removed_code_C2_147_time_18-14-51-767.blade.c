

while (1) {

  if (!*s) {
    goto while_break;
  }
  h = (unsigned long)*s + ((h << 9) | (h >> (sizeof(size_t) * 8UL - 9UL)));
  s++;
}
while_break:;
return (h % tablesize);
