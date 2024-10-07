

struct cycle_check_state {
  struct dev_ino dev_ino;
  size_t chdir_counter;
  unsigned long magic;
};
