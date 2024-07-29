

static int same_file(struct stat *stat1, struct stat *stat2) {
  int tmp;

  {
    if (stat1->st_ino == stat2->st_ino) {
      if (stat1->st_dev == stat2->st_dev) {
        tmp = 1;
      } else {
        tmp = 0;
      }
    } else {
      tmp = 0;
    }
    return (tmp);
  }
}
