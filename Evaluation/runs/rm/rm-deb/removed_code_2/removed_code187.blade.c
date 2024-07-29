

fprintf(stderr, "\n  - `%s\'", *(arglist + i));
last_val = vallist + valsize * i;
}
else {
  fprintf(stderr, ", `%s\'", *(arglist + i));
