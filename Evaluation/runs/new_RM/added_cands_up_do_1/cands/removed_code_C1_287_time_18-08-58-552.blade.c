

static void leave_dir(FTS *fts, FTSENT *ent) {
  struct stat const *st;
  struct Active_dir obj;
  void *found;
  FTSENT *parent;

  {
    st = (struct stat const *)(ent->fts_statp);
    if (fts->fts_options & 258) {
      obj.dev = (dev_t)st->st_dev;
      obj.ino = (ino_t)st->st_ino;
      found = hash_delete(fts->fts_cycle.ht, (void const *)(&obj));
      if (!found) {
        abort();
      }
      free(found);
    } else {
      parent = ent->fts_parent;
      if ((unsigned long)parent != (unsigned long)((void *)0)) {
        if (0L <= parent->fts_level) {
          while (1) {

            if ((fts->fts_cycle.state)->chdir_counter == 0UL) {
              abort();
            }
            if ((fts->fts_cycle.state)->dev_ino.st_ino == (ino_t)st->st_ino) {
              if ((fts->fts_cycle.state)->dev_ino.st_dev == (dev_t)st->st_dev) {
                (fts->fts_cycle.state)->dev_ino.st_dev =
                    parent->fts_statp[0].st_dev;
                (fts->fts_cycle.state)->dev_ino.st_ino =
                    parent->fts_statp[0].st_ino;
              }
            }
            goto while_break;
          }
        while_break:;
        }
      }
    }
    return;
  }
}
