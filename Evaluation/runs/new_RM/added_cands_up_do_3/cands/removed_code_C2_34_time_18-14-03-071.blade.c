

tmp___2 = strlen(full_name);
file_name_len = tmp___2;
if (4096UL <= file_name_len) {
  tmp___3 = euidaccess_stat((struct stat const *)buf___1, 2);
  if (tmp___3) {
    tmp___4 = 0;
  } else {
    tmp___4 = 1;
  }
  return (tmp___4);
}
