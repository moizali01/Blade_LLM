

if (len == 0UL) {
  if ((unsigned int)quoting_style == 2U) {
    if (elide_outer_quotes) {
      goto force_outer_quoting_style;
    }
  }
}
if (quote_string) {
  if (!elide_outer_quotes) {
    while (1) {

      if (!*quote_string) {
        goto while_break___25;
      }
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)*quote_string;
        }
        len++;
        goto while_break___26;
      }
    while_break___26:
      quote_string++;
    }
  while_break___25:;
  }
}
