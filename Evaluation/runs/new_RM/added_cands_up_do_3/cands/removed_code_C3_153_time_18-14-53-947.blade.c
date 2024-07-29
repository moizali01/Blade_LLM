

static _Bool fts_palloc(FTS *sp, size_t more) {
  char *p;
  size_t new_len;
  int *tmp;

  {
    new_len = (sp->fts_pathlen + more) + 256UL;
    if (new_len < sp->fts_pathlen) {
      free((void *)sp->fts_path);
      sp->fts_path = (char *)((void *)0);
      tmp = __errno_location();
      *tmp = 36;
      return ((_Bool)0);
    }
    sp->fts_pathlen = new_len;
    p = (char *)realloc((void *)sp->fts_path, sp->fts_pathlen);
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      free((void *)sp->fts_path);
      sp->fts_path = (char *)((void *)0);
      return ((_Bool)0);
    }
    sp->fts_path = p;
    return ((_Bool)1);
  }
}
static void fts_padjust(FTS *sp, FTSENT *head) {
  FTSENT *p;
  char *addr;

  {
    addr = sp->fts_path;
    p = sp->fts_child;
    while (1) {

      if (!p) {
        goto while_break;
      }
      while (1) {

        if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
          p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
        }
        p->fts_path = addr;
        goto while_break___0;
      }
    while_break___0:
      p = p->fts_link;
    }
  while_break:
    p = head;
    while (1) {

      if (!(p->fts_level >= 0L)) {
        goto while_break___1;
      }
      while (1) {

        if ((unsigned long)p->fts_accpath != (unsigned long)(p->fts_name)) {
          p->fts_accpath = addr + (p->fts_accpath - p->fts_path);
        }
        p->fts_path = addr;
        goto while_break___2;
      }
    while_break___2:;
      if (p->fts_link) {
        p = p->fts_link;
      } else {
        p = p->fts_parent;
      }
    }
  while_break___1:;
    return;
  }
}
static size_t fts_maxarglen(char *const *argv) {
  size_t len;
  size_t max;

  {
    max = (size_t)0;
    while (1) {

      if (!*argv) {
        goto while_break;
      }
      len = strlen((char const *)*argv);
      if (len > max) {
        max = len;
      }
      argv++;
    }
  while_break:;
    return (max + 1UL);
  }
}
