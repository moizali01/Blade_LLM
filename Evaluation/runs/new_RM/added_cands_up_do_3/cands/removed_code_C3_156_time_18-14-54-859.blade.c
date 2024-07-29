

static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems) {
  register FTSENT **ap;
  register FTSENT *p;
  FTSENT *dummy = 0;
  int (*compare)(void const *, void const *);
  int (*tmp)(void const *, void const *);
  FTSENT **a;
  FTSENT **tmp___0;

  {
    if (sizeof(&dummy) == sizeof(void *)) {
      if ((long)(&dummy) == (long)((void *)(&dummy))) {
        tmp = (int (*)(void const *, void const *))sp->fts_compar;
      } else {
        tmp = &fts_compar;
      }
    } else {
      tmp = &fts_compar;
    }
    compare = tmp;
    if (nitems > sp->fts_nitems) {
      sp->fts_nitems = nitems + 40UL;
      if (0xffffffffffffffffUL / sizeof(*a) < sp->fts_nitems) {
        free((void *)sp->fts_array);
        sp->fts_array = (struct _ftsent **)((void *)0);
        sp->fts_nitems = (size_t)0;
        return (head);
      } else {
        a = (FTSENT **)realloc((void *)sp->fts_array,
                               sp->fts_nitems * sizeof(*a));
        if (!a) {
          free((void *)sp->fts_array);
          sp->fts_array = (struct _ftsent **)((void *)0);
          sp->fts_nitems = (size_t)0;
          return (head);
        }
      }
      sp->fts_array = a;
    }
    ap = sp->fts_array;
    p = head;
    while (1) {

      if (!p) {
        goto while_break;
      }
      tmp___0 = ap;
      ap++;
      *tmp___0 = p;
      p = p->fts_link;
    }
  while_break:
    qsort((void *)sp->fts_array, nitems, sizeof(FTSENT *), compare);
    ap = sp->fts_array;
    head = *ap;
    while (1) {
      nitems--;
      if (!nitems) {
        goto while_break___0;
      }
      (*(ap + 0))->fts_link = *(ap + 1);
      ap++;
    }
  while_break___0:
    (*(ap + 0))->fts_link = (struct _ftsent *)((void *)0);
    return (head);
  }
}
static FTSENT *fts_alloc(FTS *sp, char const *name, size_t namelen) {
  register FTSENT *p;
  size_t len;

  {
    len = sizeof(FTSENT) + namelen;
    p = (FTSENT *)malloc(len);
    if ((unsigned long)p == (unsigned long)((void *)0)) {
      return ((FTSENT *)((void *)0));
    }
    memmove((void *)(p->fts_name), (void const *)name, namelen);
    p->fts_name[namelen] = (char)'\000';
    p->fts_namelen = namelen;
    p->fts_fts = sp;
    p->fts_path = sp->fts_path;
    p->fts_errno = 0;
    p->fts_flags = (unsigned short)0;
    p->fts_instr = (unsigned short)3;
    p->fts_number = 0L;
    p->fts_pointer = (void *)0;
    return (p);
  }
}
static void fts_lfree(FTSENT *head) {
  register FTSENT *p;

  {
    while (1) {
      p = head;
      if (!p) {
        goto while_break;
      }
      head = head->fts_link;
      free((void *)p);
    }
  while_break:;
    return;
  }
}
