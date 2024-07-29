

yes = (_Bool)0;
}
else {
  *(response + (response_len - 1L)) = (char)'\000';
  tmp___0 = rpmatch((char const *)response);
