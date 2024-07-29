

while (1) {

  if ((unsigned long)ptr < (unsigned long)lim) {
    if (!((int)*ptr != tab)) {
      goto while_break___0;
    }
  } else {
    goto while_break___0;
  }
  ptr++;
}
