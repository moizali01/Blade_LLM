

if ((int const)changes->flags & 1) {
  if (!((oldmode & 61440U) == 16384U)) {
    if ((newmode & (unsigned int)((64 | (64 >> 3)) | ((64 >> 3) >> 3))) == 0U) {
      value &= (unsigned int)(~((64 | (64 >> 3)) | ((64 >> 3) >> 3)));
    }
  }
}
