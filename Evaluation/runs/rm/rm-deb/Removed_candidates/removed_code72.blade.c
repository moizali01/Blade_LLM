

while (1) {

  if (!((unsigned long)ent == (unsigned long)t2)) {
    abort();
  }
  goto while_break;
}
while_break:
