

while (1) {
  ;

  if (len < buffersize) {
    *(buffer + len) = (char)*quote_string;
  }
  len++;
  goto while_break___24;
};
