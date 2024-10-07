

struct __anonstruct_FTS_26 {
  struct _ftsent *fts_cur;
  struct _ftsent *fts_child;
  struct _ftsent **fts_array;
  dev_t fts_dev;
  char *fts_path;
  int fts_rfd;
  size_t fts_pathlen;
  int fts_nitems;
  int (*fts_compar)(void const *, void const *);
  int fts_options;
  Hash_table *active_dir_ht;
  struct cycle_check_state *cycle_state;
};
