

while (1) {

  if ((unsigned long)node->lo != (unsigned long)node->end_lo) {
    tmp___5 = to_merge;
    to_merge--;
    if (!tmp___5) {
      goto while_break___3;
    }
  } else {
    goto while_break___3;
  }
  (node->lo)--;
  write_unique((struct line const *)node->lo, tfp, temp_output);
}
