

struct dev_ino *get_root_dev_ino(struct dev_ino *root_d_i) {
  struct stat statbuf;
  int tmp;

  {
    tmp = lstat("/", &statbuf);
    if (tmp) {
      return ((struct dev_ino *)((void *)0));
    }
    root_d_i->st_ino = statbuf.st_ino;
    root_d_i->st_dev = statbuf.st_dev;
    return (root_d_i);
  }
}
