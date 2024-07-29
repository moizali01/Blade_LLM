

_Bool can_write_any_file(void) {
  _Bool can;
  __uid_t tmp;

  {
    if (!initialized) {
      can = (_Bool)0;
      tmp = geteuid();
      can = (_Bool)(tmp == 0U);
      can_write = can;
      initialized = (_Bool)1;
    }
    return (can_write);
  }
}
