

__inline static _Bool is_basic(char c) {

  {
    return ((_Bool)((is_basic_table[(int)((unsigned char)c) >> 5] >>
                     ((int)((unsigned char)c) & 31)) &
                    1U));
  }
}
