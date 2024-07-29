

if ((int)*(cur->fts_path + (cur->fts_pathlen - 1UL)) == 47) {
  len = cur->fts_pathlen - 1UL;
} else {
  len = cur->fts_pathlen;
}
