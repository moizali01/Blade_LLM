

if (bytes == 0xffffffffffffffffUL) {
  if (!(flags & 1)) {
    p++;
    width++;
    goto while_break___0;
  } else {
    return (-1);
  }
}
