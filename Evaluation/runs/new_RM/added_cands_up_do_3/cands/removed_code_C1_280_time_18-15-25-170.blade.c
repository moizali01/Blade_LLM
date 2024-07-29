

char const *file_type(struct stat const *st) {
  char *tmp;
  char *tmp___0;
  char *tmp___1;
  char const *tmp___2;
  char const *tmp___3;
  char const *tmp___4;
  char const *tmp___5;
  char const *tmp___6;
  char const *tmp___7;
  char const *tmp___8;
  char const *tmp___9;
  char const *tmp___10;
  char const *tmp___12;

  {
    if ((st->st_mode & 61440U) == 32768U) {
      if (st->st_size == 0L) {
        tmp = gettext("regular empty file");
        tmp___1 = tmp;
      } else {
        tmp___0 = gettext("regular file");
        tmp___1 = tmp___0;
      }
      return ((char const *)tmp___1);
    }
    if ((st->st_mode & 61440U) == 16384U) {
      tmp___2 = (char const *)gettext("directory");
      return (tmp___2);
    }
    if ((st->st_mode & 61440U) == 24576U) {
      tmp___3 = (char const *)gettext("block special file");
      return (tmp___3);
    }
    if ((st->st_mode & 61440U) == 8192U) {
      tmp___4 = (char const *)gettext("character special file");
      return (tmp___4);
    }
    if ((st->st_mode & 61440U) == 4096U) {
      tmp___5 = (char const *)gettext("fifo");
      return (tmp___5);
    }
    if ((st->st_mode & 61440U) == 40960U) {
      tmp___6 = (char const *)gettext("symbolic link");
      return (tmp___6);
    }
    if ((st->st_mode & 61440U) == 49152U) {
      tmp___7 = (char const *)gettext("socket");
      return (tmp___7);
    }
    if (st->st_mode - st->st_mode) {
      tmp___8 = (char const *)gettext("message queue");
      return (tmp___8);
    }
    if (st->st_mode - st->st_mode) {
      tmp___9 = (char const *)gettext("semaphore");
      return (tmp___9);
    }
    if (st->st_mode - st->st_mode) {
      tmp___10 = (char const *)gettext("shared memory object");
      return (tmp___10);
    }
    tmp___12 = (char const *)gettext("weird file");
    return (tmp___12);
  }
}
