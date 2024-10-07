

if (!printable) {
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)'\\';
      }
      len++;
      goto while_break___17;
    };
  }
while_break___17:;
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)(48 + ((int)c >> 6));
      }
      len++;
      goto while_break___18;
    };
  }
while_break___18:;
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)(48 + (((int)c >> 3) & 7));
      }
      len++;
      goto while_break___19;
    };
  }
while_break___19:
  c = (unsigned char)(48 + ((int)c & 7));
}
