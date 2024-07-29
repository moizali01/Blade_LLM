

__inline static _Bool ignorable_missing(struct rm_options const *x,
                                        int errnum) {
  _Bool tmp;
  int tmp___0;

  {
    if (x->ignore_missing_files) {
      tmp = nonexistent_file_errno(errnum);
      if (tmp) {
        tmp___0 = 1;
      } else {
        tmp___0 = 0;
      }
    } else {
      tmp___0 = 0;
    }
    return ((_Bool)tmp___0);
  }
}
