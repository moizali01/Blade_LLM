

if ((unsigned long)fp->_IO_read_end == (unsigned long)fp->_IO_read_ptr) {
  if ((unsigned long)fp->_IO_write_ptr == (unsigned long)fp->_IO_write_base) {
    if ((unsigned long)fp->_IO_save_base == (unsigned long)((void *)0)) {
      if (whence == 2) {
        if (offset > 0L) {
          tmp = (off_t)0;
        } else {
          tmp = offset;
        }
      } else {
        tmp = offset;
      }
      tmp___0 = fileno(fp);
      tmp___1 = lseek(tmp___0, tmp, whence);
      pos = tmp___1;
      if (pos == -1L) {
        return (-1);
      }
      fp->_flags &= -17;
      if (whence == 2) {
        if (!(offset > 0L)) {
          return (0);
        }
      } else {
        return (0);
      }
    }
  }
}
