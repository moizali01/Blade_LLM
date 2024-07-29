

if (command_name) {
  fprintf(stream, "%s (%s) %s\n", command_name, package, version);
} else {
  fprintf(stream, "%s %s\n", package, version);
}
tmp = gettext("(C)");
fprintf(stream, version_etc_copyright, tmp, 2010);
tmp___0 = gettext("\nLicense GPLv3+: GNU GPL version 3 or later "
                  "<http://gnu.org/licenses/gpl.html>.\nThis is free software: "
                  "you are free to change and redistribute it.\nThere is NO "
                  "WARRANTY, to the extent permitted by law.\n\n");
fputs_unlocked((char const *)tmp___0, stream);
if (n_authors == 0UL) {
  goto case_0;
}
