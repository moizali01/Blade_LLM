

ifile_size = istat.st_size;
if (no_time) {
  if (!list) {
    time_stamp = 0L;
  } else {
    time_stamp = istat.st_mtim.tv_sec;
  }
} else {
  time_stamp = istat.st_mtim.tv_sec;
}
