

if (len < buffersize) {
  *(buffer + len) = (char)(48 + (((int)c >> 3) & 7));
}
