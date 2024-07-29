

if (!elide_outer_quotes) {
  quote_string = left_quote;
  while (1) {

    if (!*quote_string) {
      goto while_break___0;
    }
    while (1) {

      if (len < buffersize) {
        *(buffer + len) = (char)*quote_string;
      }
      len++;
      goto while_break___1;
    }
  while_break___1:
    quote_string++;
  }
while_break___0:;
}
backslash_escapes = (_Bool)1;
quote_string = right_quote;
