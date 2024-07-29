

if (decompress) {
  { method = get_method(ifd); }
  if (method < 0) {
    { close(ifd); }
    return;
  }
}
if (list) {
  {
    do_list(ifd, method);
    close(ifd);
  }
  return;
}
