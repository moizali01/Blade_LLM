

if (argc <= optind) {
  if (x.ignore_missing_files) {
    exit(0);
  } else {
    tmp___0 = gettext("missing operand");
    error(0, 0, (char const *)tmp___0);
    usage(1);
  }
}
