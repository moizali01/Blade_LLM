

tmp___2 = memcmp((void const *)iter1.cur.ptr, (void const *)iter2.cur.ptr,
                 iter1.cur.bytes);
tmp___10 = tmp___2;
}
else {
  if (iter1.cur.bytes < iter2.cur.bytes) {
    tmp___5 = memcmp((void const *)iter1.cur.ptr, (void const *)iter2.cur.ptr,
                     iter1.cur.bytes);
    if (tmp___5 > 0) {
      tmp___4 = 1;
    } else {
      tmp___4 = -1;
    }
    tmp___9 = tmp___4;
  } else {
    tmp___8 = memcmp((void const *)iter1.cur.ptr, (void const *)iter2.cur.ptr,
                     iter2.cur.bytes);
    if (tmp___8 >= 0) {
      tmp___7 = 1;
    } else {
      tmp___7 = -1;
    }
    tmp___9 = tmp___7;
  }
