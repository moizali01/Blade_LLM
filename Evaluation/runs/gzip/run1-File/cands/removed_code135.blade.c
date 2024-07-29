

while (1) {
while_continue: /* CIL Label */
                ;
  {
    tmp___8 = fileno(stdout);
    tmp___9 = fileno(stdin);
    tmp___10 = (*work)(tmp___9, tmp___8);
  }
  if (tmp___10 != 0) {
    return;
  }
  if (!decompress) {
    goto while_break;
  } else {
    if (last_member) {
      goto while_break;
    } else {
      if (inptr == insize) {
        goto while_break;
      }
    }
  }
  { method = get_method(ifd); }
  if (method < 0) {
    return;
  }
  bytes_out = 0L;
}
while_break:
