

if (re_protect) {
  {
    tmp___20 = __builtin_alloca(sizeof(struct ptr_list));
    new = (struct ptr_list *)tmp___20;
    new->dirname_end = slash;
    new->next = leading_dirs;
    leading_dirs = new;
  }
}
