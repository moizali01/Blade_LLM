

tmp___20 = gettext(
    "WARNING: Circular directory structure.\nThis almost certainly means "
    "that you have a corrupted file system.\nNOTIFY YOUR SYSTEM "
    "MANAGER.\nThe following directory is part of the cycle:\n  %s\n");
error(0, 0, (char const *)tmp___20, tmp___19);
goto while_break___0;
