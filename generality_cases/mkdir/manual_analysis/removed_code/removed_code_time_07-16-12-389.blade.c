

while (1) {
  ;

  if (len < buffersize) {
    *(buffer + len) = (char)(48 + ((int)c >> 6));
  }
  len++;
  goto while_break___18;
};
