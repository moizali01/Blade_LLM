

if (!force) {
  if (!list) {
    if (decompress) {
      tmp___1 = stdin;
    } else {
      tmp___1 = stdout;
    }
    {
      tmp___2 = fileno(tmp___1);
      tmp___3 = isatty(tmp___2);
    }
    if (tmp___3) {
      if (decompress) {
        tmp = "de";
      } else {
        tmp = "";
      }
      if (decompress) {
        tmp___0 = "read from";
      } else {
        tmp___0 = "written to";
      }
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const * /* __restrict  */) "%s: compressed data not "
                                                 "%s a terminal. Use -f to "
                                                 "force %scompression.\n",
                progname, tmp___0, tmp);
        fprintf((FILE * /* __restrict  */) stderr,
                (char const * /* __restrict  */) "For help, type: %s -h\n",
                progname);
        do_exit(1);
      }
    }
  }
}
if (decompress) {
  tmp___4 = 1;
} else {
  if (!ascii) {
    tmp___4 = 1;
  } else {
    tmp___4 = 0;
  }
}
if (!test) {
  if (!list) {
    if (!decompress) {
      tmp___5 = 1;
    } else {
      if (!ascii) {
        tmp___5 = 1;
      } else {
        tmp___5 = 0;
      }
    }
  } else {
    tmp___5 = 0;
  }
} else {
  tmp___5 = 0;
}
