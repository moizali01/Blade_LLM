

if (argc <= optind) {
  if (x.ignore_missing_files) {
    exit(0);
  } else {
    tmp___0 = gettext("missing operand");
    error(0, 0, (char const *)tmp___0);
    usage(1);
  }
}
if (x.recursive) {
  if (preserve_root) {
    x.root_dev_ino = get_root_dev_ino(&dev_ino_buf);
    if ((unsigned long)x.root_dev_ino == (unsigned long)((void *)0)) {
      tmp___1 = quote("/");
      tmp___2 = gettext("failed to get attributes of %s");
      tmp___3 = __errno_location();
      error(1, *tmp___3, (char const *)tmp___2, tmp___1);
    }
  }
}
n_files = (size_t)(argc - optind);
