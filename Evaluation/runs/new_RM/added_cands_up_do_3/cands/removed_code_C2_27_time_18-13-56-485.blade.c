

enum RM_status rm(char *const *file, struct rm_options const *x) {
  enum RM_status rm_status;
  int bit_flags;
  FTS *fts;
  FTS *tmp;
  FTSENT *ent;
  char *tmp___0;
  int *tmp___1;
  int *tmp___2;
  enum RM_status s;
  enum RM_status tmp___3;
  char *tmp___4;
  int *tmp___5;
  int tmp___6;

  {
    rm_status = (enum RM_status)2;
    if (*file) {
      bit_flags = 536;
      if (x->one_file_system) {
        bit_flags |= 64;
      }
      tmp = xfts_open(file, bit_flags,
                      (int (*)(FTSENT const **, FTSENT const **))((void *)0));
      fts = tmp;
      while (1) {
        ent = fts_read(fts);
        if ((unsigned long)ent == (unsigned long)((void *)0)) {
          tmp___2 = __errno_location();
          if (*tmp___2 != 0) {
            tmp___0 = gettext("fts_read failed");
            tmp___1 = __errno_location();
            error(0, *tmp___1, (char const *)tmp___0);
            rm_status = (enum RM_status)4;
          }
          goto while_break;
        }
        tmp___3 = rm_fts(fts, ent, x);
        s = tmp___3;
        if (!((unsigned int)s == 2U)) {
          if (!((unsigned int)s == 3U)) {
            if (!((unsigned int)s == 4U)) {
              __assert_fail(
                  "((s) == RM_OK || (s) == RM_USER_DECLINED || (s) == "
                  "RM_ERROR)",
                  "/home/khheo/project/benchmark/coreutils-8.4/src/remove.c",
                  624U, "rm");
            }
          }
        }
        while (1) {

          if ((unsigned int)s == 4U) {
            rm_status = s;
          } else {
            if ((unsigned int)s == 3U) {
              if ((unsigned int)rm_status == 2U) {
                rm_status = s;
              }
            }
          }
          goto while_break___0;
        }
      while_break___0:;
      }
    while_break:
      tmp___6 = fts_close(fts);
      if (tmp___6 != 0) {
        tmp___4 = gettext("fts_close failed");
        tmp___5 = __errno_location();
        error(0, *tmp___5, (char const *)tmp___4);
        rm_status = (enum RM_status)4;
      }
    }
    return (rm_status);
  }
}
extern char *optarg;
extern __attribute__((__nothrow__)) int(__attribute__((__leaf__))
                                        isatty)(int __fd);
