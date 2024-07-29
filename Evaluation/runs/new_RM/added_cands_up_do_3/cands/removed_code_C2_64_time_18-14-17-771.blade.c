

while (1) {

  if (!*argv) {
    goto while_break;
  }
  len = strlen((char const *)*argv);
  if (len > max) {
    max = len;
  }
  argv++;
}
while_break:;
return (max + 1UL);
