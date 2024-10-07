

if (!who_specified_p) {
  if ((int const) * mode_string___0 == 61) {
    tmp___14 = 1;
  } else {
    tmp___14 = 0;
  }
  if (ops_to_mask & (unsigned int)tmp___14) {
    {
      tmp___13 = make_node_op_equals((mode_t)0);
      p___0 = tmp___13;
    }
    if ((unsigned long)p___0 == (unsigned long)((void *)0)) {
      return ((struct mode_change *)1);
    }
    { mode_append_entry(&head, &tail, p___0); }
  }
}
