

if (changes->value & 448U) {
  if (value & 256U) {
    tmp = (256 >> 3) | ((256 >> 3) >> 3);
  } else {
    tmp = 0;
  }
  if (value & 128U) {
    tmp___0 = (128 >> 3) | ((128 >> 3) >> 3);
  } else {
    tmp___0 = 0;
  }
  if (value & 64U) {
    tmp___1 = (64 >> 3) | ((64 >> 3) >> 3);
  } else {
    tmp___1 = 0;
  }
  value |= (unsigned int)((tmp | tmp___0) | tmp___1);
} else {
  if (changes->value & (unsigned int const)(448 >> 3)) {
    if (value & (unsigned int)(256 >> 3)) {
      tmp___2 = 256 | ((256 >> 3) >> 3);
    } else {
      tmp___2 = 0;
    }
    if (value & (unsigned int)(128 >> 3)) {
      tmp___3 = 128 | ((128 >> 3) >> 3);
    } else {
      tmp___3 = 0;
    }
    if (value & (unsigned int)(64 >> 3)) {
      tmp___4 = 64 | ((64 >> 3) >> 3);
    } else {
      tmp___4 = 0;
    }
    value |= (unsigned int)((tmp___2 | tmp___3) | tmp___4);
  } else {
    if (value & (unsigned int)((256 >> 3) >> 3)) {
      tmp___5 = 256 | (256 >> 3);
    } else {
      tmp___5 = 0;
    }
    if (value & (unsigned int)((128 >> 3) >> 3)) {
      tmp___6 = 128 | (128 >> 3);
    } else {
      tmp___6 = 0;
    }
    if (value & (unsigned int)((64 >> 3) >> 3)) {
      tmp___7 = 64 | (64 >> 3);
    } else {
      tmp___7 = 0;
    }
    value |= (unsigned int)((tmp___5 | tmp___6) | tmp___7);
  }
}
