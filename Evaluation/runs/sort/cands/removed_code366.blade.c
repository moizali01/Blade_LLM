

if (0xffffffffffffffffUL != candidate) {
  tmp = is_prime(candidate);
  if (tmp) {
    goto while_break;
  }
} else {
  goto while_break;
}
