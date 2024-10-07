

if (!(o->quote_these_too[(unsigned long)c / (sizeof(int) * 8UL)] &
      (1 << (unsigned long)c % (sizeof(int) * 8UL)))) {
  goto store_c;
}
