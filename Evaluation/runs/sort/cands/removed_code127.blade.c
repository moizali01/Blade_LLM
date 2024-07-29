

if (unique) {
  if (savedline) {
    tmp___7 = compare(savedline, smallest);
    if (tmp___7) {
      savedline = (struct line const *)((void *)0);
      write_line((struct line const *)(&saved___0), ofp, output_file);
    }
  }
  if (!savedline) {
    savedline = (struct line const *)(&saved___0);
    if (savealloc < (size_t)smallest->length) {
      while (1) {

        if (!savealloc) {
          savealloc = (size_t)smallest->length;
          goto while_break___4;
        }
        savealloc *= 2UL;
        if (!(savealloc < (size_t)smallest->length)) {
          goto while_break___4;
        }
      }
    while_break___4:
      free((void *)saved___0.text);
      saved___0.text = (char *)xmalloc(savealloc);
    }
    saved___0.length = (size_t)smallest->length;
    memcpy((void *)saved___0.text, (void const *)smallest->text,
           saved___0.length);
    if (key) {
      saved___0.keybeg = saved___0.text + (smallest->keybeg - smallest->text);
      saved___0.keylim = saved___0.text + (smallest->keylim - smallest->text);
    }
  }
} else {
  write_line(smallest, ofp, output_file);
}
