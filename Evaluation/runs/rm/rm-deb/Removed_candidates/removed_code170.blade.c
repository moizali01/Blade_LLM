

tmp___11 = getegid();
egid = tmp___11;
if (egid == (gid_t)st->st_gid) {
  granted >>= 3;
} else {
  tmp___12 = group_member((__gid_t)st->st_gid);
  if (tmp___12) {
    granted >>= 3;
  }
}
