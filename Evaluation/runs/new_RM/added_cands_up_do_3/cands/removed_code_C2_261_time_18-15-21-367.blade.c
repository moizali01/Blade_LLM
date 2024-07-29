

__inline static _Bool is_basic(char c) {

  {
    return ((_Bool)((is_basic_table[(int)((unsigned char)c) >> 5] >>
                     ((int)((unsigned char)c) & 31)) &
                    1U));
  }
}
size_t strnlen1(char const *string, size_t maxlen);
__inline static void mbuiter_multi_next(struct mbuiter_multi *iter) {
  int tmp;
  size_t tmp___0;
  size_t tmp___1;
  int tmp___2;
  _Bool tmp___3;

  {
    if (iter->next_done) {
      return;
    }
    if (iter->in_shift) {
      goto with_shift;
    }
    tmp___3 = is_basic((char)*(iter->cur.ptr));
    if (tmp___3) {
      iter->cur.bytes = (size_t)1;
      iter->cur.wc = (wchar_t) * (iter->cur.ptr);
      iter->cur.wc_valid = (_Bool)1;
    } else {
      tmp = mbsinit((mbstate_t const *)(&iter->state));
      if (!tmp) {
        __assert_fail(
            "mbsinit (&iter->state)",
            "/home/khheo/project/benchmark/coreutils-8.4/lib/mbuiter.h", 142U,
            "mbuiter_multi_next");
      }
      iter->in_shift = (_Bool)1;
    with_shift:
      tmp___0 = __ctype_get_mb_cur_max();
      tmp___1 = strnlen1(iter->cur.ptr, tmp___0);
      iter->cur.bytes =
          mbrtowc(&iter->cur.wc, iter->cur.ptr, tmp___1, &iter->state);
      if (iter->cur.bytes == 0xffffffffffffffffUL) {
        iter->cur.bytes = (size_t)1;
        iter->cur.wc_valid = (_Bool)0;
      } else {
        if (iter->cur.bytes == 0xfffffffffffffffeUL) {
          iter->cur.bytes = strlen(iter->cur.ptr);
          iter->cur.wc_valid = (_Bool)0;
        } else {
          if (iter->cur.bytes == 0UL) {
            iter->cur.bytes = (size_t)1;
            if (!((int const) * (iter->cur.ptr) == 0)) {
              __assert_fail(
                  "*iter->cur.ptr == \'\\0\'",
                  "/home/khheo/project/benchmark/coreutils-8.4/lib/mbuiter.h",
                  170U, "mbuiter_multi_next");
            }
            if (!(iter->cur.wc == 0)) {
              __assert_fail(
                  "iter->cur.wc == 0",
                  "/home/khheo/project/benchmark/coreutils-8.4/lib/mbuiter.h",
                  171U, "mbuiter_multi_next");
            }
          }
          iter->cur.wc_valid = (_Bool)1;
          tmp___2 = mbsinit((mbstate_t const *)(&iter->state));
          if (tmp___2) {
            iter->in_shift = (_Bool)0;
          }
        }
      }
    }
    iter->next_done = (_Bool)1;
    return;
  }
}
