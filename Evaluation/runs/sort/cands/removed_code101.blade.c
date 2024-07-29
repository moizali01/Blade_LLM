

while (1) {

  if ((unsigned long)node->hi != (unsigned long)node->end_hi) {
    tmp___2 = to_merge;
    to_merge--;
    if (!tmp___2) {
      goto while_break___1;
    }
  } else {
    goto while_break___1;
  }
  dest--;
  (node->hi)--;
  *dest = *(node->hi);
}
