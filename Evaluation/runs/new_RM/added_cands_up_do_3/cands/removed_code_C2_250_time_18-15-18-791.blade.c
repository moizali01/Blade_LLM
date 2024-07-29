

__inline static _Bool is_zero_or_power_of_two(uintmax_t i) {

  { return ((_Bool)((i & (i - 1UL)) == 0UL)); }
}
void cycle_check_init(struct cycle_check_state *state) {

  {
    state->chdir_counter = (uintmax_t)0;
    state->magic = 9827862;
    return;
  }
}
_Bool cycle_check(struct cycle_check_state *state, struct stat const *sb) {
  _Bool tmp;

  {
    if (!(state->magic == 9827862)) {
      __assert_fail(
          "state->magic == 9827862",
          "/home/khheo/project/benchmark/coreutils-8.4/lib/cycle-check.c", 60U,
          "cycle_check");
    }
    if (state->chdir_counter) {
      if (sb->st_ino == (__ino_t const)state->dev_ino.st_ino) {
        if (sb->st_dev == (__dev_t const)state->dev_ino.st_dev) {
          return ((_Bool)1);
        }
      }
    }
    (state->chdir_counter)++;
    tmp = is_zero_or_power_of_two(state->chdir_counter);
    if (tmp) {
      if (state->chdir_counter == 0UL) {
        return ((_Bool)1);
      }
      state->dev_ino.st_dev = (dev_t)sb->st_dev;
      state->dev_ino.st_ino = (ino_t)sb->st_ino;
    }
    return ((_Bool)0);
  }
}
