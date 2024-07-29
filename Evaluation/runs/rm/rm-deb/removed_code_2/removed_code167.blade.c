

if (!elide_outer_quotes) {
  while (1) {

    if (len < buffersize) {
      *(buffer + len) = (char)'\'';
    }
    len++;
    goto while_break___2;
  }
while_break___2:;
}
quote_string = "\'";
quote_string_len = (size_t)1;
