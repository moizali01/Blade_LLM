

if ((newmode & (unsigned int)((64 | (64 >> 3)) | ((64 >> 3) >> 3))) == 0U) {
  value &= (unsigned int)(~((64 | (64 >> 3)) | ((64 >> 3) >> 3)));
}
