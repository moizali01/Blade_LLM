

next = cursor->next;
free((void *)cursor);
cursor = next;
