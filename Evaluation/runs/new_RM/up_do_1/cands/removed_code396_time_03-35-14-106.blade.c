

__inline static void clear_ungetc_buffer_preserving_position(FILE *fp) {

  {
    if (fp->_flags & 256) {
      rpl_fseeko(fp, (off_t)0, 1);
    }
    return;
  }
}
