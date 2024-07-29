

while (1) {
  c = getopt_long(argc, (char *const *)argv, "dfirvIR", long_opts,
                  (int *)((void *)0));
  if (!(c != -1)) {
    goto while_break;
  }
  if (c == 100) {
    goto case_100;
  }
  if (c == 102) {
    goto case_102;
  }
  if (c == 105) {
    goto case_105;
  }
  if (c == 73) {
    goto case_73;
  }
  if (c == 114) {
    goto case_114;
  }
  if (c == 82) {
    goto case_114;
  }
  if (c == 128) {
    goto case_128;
  }
  if (c == 129) {
    goto case_129;
  }
  if (c == 130) {
    goto case_130;
  }
  if (c == 131) {
    goto case_131;
  }
  if (c == 132) {
    goto case_132;
  }
  if (c == 118) {
    goto case_118;
  }
  if (c == -130) {
    goto case_neg_130;
  }
  if (c == -131) {
    goto case_neg_131;
  }
  goto switch_default;
case_100:
  goto switch_break;
case_102:
  x.interactive = (enum rm_interactive)5;
  x.ignore_missing_files = (_Bool)1;
  prompt_once = (_Bool)0;
  goto switch_break;
case_105:
  x.interactive = (enum rm_interactive)3;
  x.ignore_missing_files = (_Bool)0;
  prompt_once = (_Bool)0;
  goto switch_break;
case_73:
  x.interactive = (enum rm_interactive)5;
  x.ignore_missing_files = (_Bool)0;
  prompt_once = (_Bool)1;
  goto switch_break;
case_114:
  x.recursive = (_Bool)1;
  goto switch_break;
case_128:
  if (optarg) {
    tmp = __xargmatch_internal("--interactive", (char const *)optarg,
                               interactive_args,
                               (char const *)(interactive_types),
                               sizeof(interactive_types[0]), argmatch_die);
    i = (int)interactive_types[tmp];
  } else {
    i = 2;
  }
  if (i == 0) {
    goto case_0;
  }
  if (i == 1) {
    goto case_1;
  }
  if (i == 2) {
    goto case_2;
  }
  goto switch_break___0;
case_0:
  x.interactive = (enum rm_interactive)5;
  prompt_once = (_Bool)0;
  goto switch_break___0;
case_1:
  x.interactive = (enum rm_interactive)4;
  x.ignore_missing_files = (_Bool)0;
  prompt_once = (_Bool)1;
  goto switch_break___0;
case_2:
  x.interactive = (enum rm_interactive)3;
  x.ignore_missing_files = (_Bool)0;
  prompt_once = (_Bool)0;
  goto switch_break___0;
switch_break___0:;
  goto switch_break;
case_129:
  x.one_file_system = (_Bool)1;
  goto switch_break;
case_130:
  preserve_root = (_Bool)0;
  goto switch_break;
case_131:
  preserve_root = (_Bool)1;
  goto switch_break;
case_132:
  x.stdin_tty = (_Bool)1;
  goto switch_break;
case_118:
  x.verbose = (_Bool)1;
  goto switch_break;
case_neg_130:
  usage(0);
  goto switch_break;
case_neg_131:
  version_etc(stdout, "rm", "GNU coreutils", Version, "Paul Rubin",
              "David MacKenzie", "Richard M. Stallman", "Jim Meyering",
              (char *)((void *)0));
  exit(0);
  goto switch_break;
switch_default:
  diagnose_leading_hyphen(argc, argv);
  usage(1);
switch_break:;
}
