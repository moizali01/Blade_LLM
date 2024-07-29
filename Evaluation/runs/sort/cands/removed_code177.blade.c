

if (key->sword != 0xffffffffffffffffUL) {
  texta = begfield(a, (struct keyfield const *)key);
  textb = begfield(b, (struct keyfield const *)key);
} else {
  texta = (char *)a->text;
  textb = (char *)b->text;
  if (key->skipsblanks) {
    while (1) {

      if ((unsigned long)texta < (unsigned long)lima) {
        tmp___25 = to_uchar(*texta);
        if (!blanks[tmp___25]) {
          goto while_break___11;
        }
      } else {
        goto while_break___11;
      }
      texta++;
    }
  while_break___11:;
    while (1) {

      if ((unsigned long)textb < (unsigned long)limb) {
        tmp___26 = to_uchar(*textb);
        if (!blanks[tmp___26]) {
          goto while_break___12;
        }
      } else {
        goto while_break___12;
      }
      textb++;
    }
  while_break___12:;
  }
}
