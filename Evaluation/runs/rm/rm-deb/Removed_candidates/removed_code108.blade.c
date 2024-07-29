

tmp = i_ring_empty((I_ring const *)ir);
if (tmp) {
  abort();
}
top_val = ir->ir_data[ir->ir_front];
