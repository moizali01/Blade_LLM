

while (1) {
  ;

  if (!*quote_string) {
    goto while_break___23;
  }
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)*quote_string;
      }
      len++;
      goto while_break___24;
    };
  }
while_break___24:
  quote_string++;
};
