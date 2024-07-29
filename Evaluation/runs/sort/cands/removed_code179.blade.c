

if (ignore) {
  if (translate) {
    while (1) {

      while (1) {

        while (1) {

          if ((unsigned long)texta < (unsigned long)lima) {
            tmp___7 = to_uchar(*texta);
            if (!*(ignore + (int)tmp___7)) {
              goto while_break___4;
            }
          } else {
            goto while_break___4;
          }
          texta++;
        }
      while_break___4:;
        while (1) {

          if ((unsigned long)textb < (unsigned long)limb) {
            tmp___8 = to_uchar(*textb);
            if (!*(ignore + (int)tmp___8)) {
              goto while_break___5;
            }
          } else {
            goto while_break___5;
          }
          textb++;
        }
      while_break___5:;
        if ((unsigned long)texta < (unsigned long)lima) {
          if (!((unsigned long)textb < (unsigned long)limb)) {
            goto while_break___3;
          }
        } else {
          goto while_break___3;
        }
        tmp___9 = to_uchar(*texta);
        tmp___10 = to_uchar((char)*(translate + (int)tmp___9));
        tmp___11 = to_uchar(*textb);
        tmp___12 = to_uchar((char)*(translate + (int)tmp___11));
        diff = (int)tmp___10 - (int)tmp___12;
        if (diff) {
          goto not_equal;
        }
        texta++;
        textb++;
      }
    while_break___3:
      diff = ((unsigned long)texta < (unsigned long)lima) -
             ((unsigned long)textb < (unsigned long)limb);
      goto while_break___2;
    }
  while_break___2:;
  } else {
    while (1) {

      while (1) {

        while (1) {

          if ((unsigned long)texta < (unsigned long)lima) {
            tmp___13 = to_uchar(*texta);
            if (!*(ignore + (int)tmp___13)) {
              goto while_break___8;
            }
          } else {
            goto while_break___8;
          }
          texta++;
        }
      while_break___8:;
        while (1) {

          if ((unsigned long)textb < (unsigned long)limb) {
            tmp___14 = to_uchar(*textb);
            if (!*(ignore + (int)tmp___14)) {
              goto while_break___9;
            }
          } else {
            goto while_break___9;
          }
          textb++;
        }
      while_break___9:;
        if ((unsigned long)texta < (unsigned long)lima) {
          if (!((unsigned long)textb < (unsigned long)limb)) {
            goto while_break___7;
          }
        } else {
          goto while_break___7;
        }
        tmp___15 = to_uchar(*texta);
        tmp___16 = to_uchar(*textb);
        diff = (int)tmp___15 - (int)tmp___16;
        if (diff) {
          goto not_equal;
        }
        texta++;
        textb++;
      }
    while_break___7:
      diff = ((unsigned long)texta < (unsigned long)lima) -
             ((unsigned long)textb < (unsigned long)limb);
      goto while_break___6;
    }
  while_break___6:;
  }
} else {
  if (lena == 0UL) {
    diff = -(lenb != 0UL);
  } else {
    if (lenb == 0UL) {
      goto greater;
    } else {
      if (translate) {
        while (1) {

          if ((unsigned long)texta < (unsigned long)lima) {
            if (!((unsigned long)textb < (unsigned long)limb)) {
              goto while_break___10;
            }
          } else {
            goto while_break___10;
          }
          tmp___17 = texta;
          texta++;
          tmp___18 = to_uchar(*tmp___17);
          tmp___19 = to_uchar((char)*(translate + (int)tmp___18));
          tmp___20 = textb;
          textb++;
          tmp___21 = to_uchar(*tmp___20);
          tmp___22 = to_uchar((char)*(translate + (int)tmp___21));
          diff = (int)tmp___19 - (int)tmp___22;
          if (diff) {
            goto not_equal;
          }
        }
      while_break___10:;
      } else {
        if (lena < lenb) {
          tmp___23 = lena;
        } else {
          tmp___23 = lenb;
        }
        diff = memcmp((void const *)texta, (void const *)textb, tmp___23);
        if (diff) {
          goto not_equal;
        }
      }
      if (lena < lenb) {
        diff = -1;
      } else {
        diff = lena != lenb;
      }
    }
  }
}
