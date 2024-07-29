

if (debug) {
  c = (char const *)buf___1;
  while (1) {

    if (!((unsigned long)c < (unsigned long)ebuf)) {
      goto while_break;
    }
    tmp = c;
    c++;
    wc = (char)*tmp;
    if ((int)wc == 9) {
      wc = (char)'>';
    } else {
      if ((unsigned long)c == (unsigned long)ebuf) {
        wc = (char)'\n';
      }
    }
    tmp___1 = fputc_unlocked((int)wc, fp);
    if (tmp___1 == -1) {
      tmp___0 = gettext("write failed");
      die((char const *)tmp___0, output_file);
    }
  }
while_break:
  debug_line(line);
} else {
  goto _L;
}
