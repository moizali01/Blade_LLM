

if (compare_dirs) {
  {
    source_dirname = dir_name(source);
    dest_dirname = dir_name(dest);
    tmp___6 =
        stat((char const * /* __restrict  */)((char const *)source_dirname),
             (struct stat * /* __restrict  */)(&source_dir_stats));
  }
  if (tmp___6) {
    {
      tmp___5 = __errno_location();
      error(1, *tmp___5, "%s", source_dirname);
    }
  }
  {
    tmp___8 = stat((char const * /* __restrict  */)((char const *)dest_dirname),
                   (struct stat * /* __restrict  */)(&dest_dir_stats));
  }
  if (tmp___8) {
    {
      tmp___7 = __errno_location();
      error(1, *tmp___7, "%s", dest_dirname);
    }
  }
  if (source_dir_stats.st_ino == dest_dir_stats.st_ino) {
    if (source_dir_stats.st_dev == dest_dir_stats.st_dev) {
      tmp___9 = 1;
    } else {
      tmp___9 = 0;
    }
  } else {
    tmp___9 = 0;
  }
  {
    same = (_Bool)tmp___9;
    rpl_free((void *)source_dirname);
    rpl_free((void *)dest_dirname);
  }
}
