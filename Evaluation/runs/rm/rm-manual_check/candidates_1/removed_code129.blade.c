

__inline static _Bool nonexistent_file_errno(int errnum) {

  {
    if (errnum == 2) {
      goto case_2;
    }
    if (errnum == 20) {
      goto case_2;
    }
    goto switch_default;
  case_2:
    return ((_Bool)1);
  switch_default:
    return ((_Bool)0);

    return ((_Bool)0);
  }
}
