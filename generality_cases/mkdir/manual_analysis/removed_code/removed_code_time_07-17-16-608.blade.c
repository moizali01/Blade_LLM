

if (backslash_escapes) {
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)'\\';
      }
      len++;
      goto while_break___5;
    };
  }
while_break___5:;
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)'0';
      }
      len++;
      goto while_break___6;
    };
  }
while_break___6:;
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)'0';
      }
      len++;
      goto while_break___7;
    };
  }
while_break___7:
  c = (unsigned char)'0';
}
