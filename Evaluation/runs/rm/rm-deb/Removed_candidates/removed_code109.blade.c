

if (dest_idx == ir->ir_back) {
  ir->ir_back = (ir->ir_back + (unsigned int)(!ir->ir_empty)) % 4U;
}
ir->ir_empty = (_Bool)0;
