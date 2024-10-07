

if (source_dir_stats.st_ino == dest_dir_stats.st_ino) {
  if (source_dir_stats.st_dev == dest_dir_stats.st_dev) {
    tmp___9 = 1;
  } else {
    tmp___9 = 0;
  }
} else {
  tmp___9 = 0;
}
