

r.tv_sec = ~(((1L << (sizeof(time_t) * 8UL - 2UL)) - 1L) * 2L + 1L);
