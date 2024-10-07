

while (1) {
  ;

  if (!changes) {
    goto while_break;
  }
  {
    next = changes->next;
    rpl_free((void *)changes);
    changes = next;
  }
};
