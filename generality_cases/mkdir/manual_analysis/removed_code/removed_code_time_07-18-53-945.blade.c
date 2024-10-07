

if (quote_string_len) {
  if (i + quote_string_len <= argsize) {
    {
      tmp___2 = memcmp((void const *)(arg + i), (void const *)quote_string,
                       quote_string_len);
    }
    if (tmp___2 == 0) {
      {
        while (1) {
          ;

          if (len < buffersize) {
            *(buffer + len) = (char)'\\';
          }
          len++;
          goto while_break___4;
        };
      }
    while_break___4:;
    }
  }
}
