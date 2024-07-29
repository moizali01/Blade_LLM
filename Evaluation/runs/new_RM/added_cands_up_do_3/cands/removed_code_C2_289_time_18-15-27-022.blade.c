

enum interactive_type {
  interactive_never = 0,
  interactive_once = 1,
  interactive_always = 2
};
size_t freadahead(FILE *fp);
size_t freadahead(FILE *fp) {
  long tmp;

  {
    if ((unsigned long)fp->_IO_write_ptr > (unsigned long)fp->_IO_write_base) {
      return ((size_t)0);
    }
    if (fp->_flags & 256) {
      tmp = fp->_IO_save_end - fp->_IO_save_base;
    } else {
      tmp = 0L;
    }
    return ((size_t)((fp->_IO_read_end - fp->_IO_read_ptr) + tmp));
  }
}
