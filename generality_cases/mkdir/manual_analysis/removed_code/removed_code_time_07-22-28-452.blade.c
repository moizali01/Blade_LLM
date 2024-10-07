

if (0 <= strtol_base) {
  if (!(strtol_base <= 36)) {
    {
      __assert_fail(
          "0 <= strtol_base && strtol_base <= 36",
          "/home/khheo/project/benchmark/coreutils-5.2.1/lib/xstrtol.c", 117U,
          "xstrtoul");
    }
  }
} else {
  {
    __assert_fail("0 <= strtol_base && strtol_base <= 36",
                  "/home/khheo/project/benchmark/coreutils-5.2.1/lib/xstrtol.c",
                  117U, "xstrtoul");
  }
}
