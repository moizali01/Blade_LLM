

if (!(sec < max_representable)) {
  r.tv_sec = ((1L << (sizeof(time_t) * 8UL - 2UL)) - 1L) * 2L + 1L;
  r.tv_nsec = (__syscall_slong_t)999999999;
} else {
  s = (time_t)sec;
  frac = (double)1000000000 * (sec - (double)s);
  ns = (long)frac;
  ns += (long)((double)ns < frac);
  s += ns / 1000000000L;
  ns %= 1000000000L;
  if (ns < 0L) {
    s--;
    ns += 1000000000L;
  }
  r.tv_sec = s;
  r.tv_nsec = ns;
}
