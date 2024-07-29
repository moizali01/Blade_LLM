

if ((unsigned int)quoting_style == 2U) {
  if (elide_outer_quotes) {
    goto force_outer_quoting_style;
  }
  while (1) {

    if (len < buffersize) {
      *(buffer + len) = (char)'\'';
    }
    len++;
    goto while_break___11;
  }
while_break___11:;
  while (1) {

    if (len < buffersize) {
      *(buffer + len) = (char)'\\';
    }
    len++;
    goto while_break___12;
  }
while_break___12:;
  while (1) {

    if (len < buffersize) {
      *(buffer + len) = (char)'\'';
    }
    len++;
    goto while_break___13;
  }
while_break___13:;
}
goto switch_break___0;
