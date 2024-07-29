

if (!((unsigned int)s == 2U)) {
  if (!((unsigned int)s == 3U)) {
    if (!((unsigned int)s == 4U)) {
      __assert_fail("((s) == RM_OK || (s) == RM_USER_DECLINED || (s) == "
                    "RM_ERROR)",
                    "/home/khheo/project/benchmark/coreutils-8.4/src/remove.c",
                    624U, "rm");
    }
  }
}
