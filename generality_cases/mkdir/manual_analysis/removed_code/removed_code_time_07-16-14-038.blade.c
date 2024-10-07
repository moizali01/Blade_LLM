

while (1) {
  ;

  if (len < buffersize) {
    *(buffer + len) = (char)'\\';
  }
  len++;
  goto while_break___17;
};
