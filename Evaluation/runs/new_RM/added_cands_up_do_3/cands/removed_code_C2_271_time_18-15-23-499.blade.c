

static int have_dupfd_cloexec = 0;
int rpl_fcntl(int fd, int action, ...) {
  va_list arg;
  int result;
  int target;
  int tmp;
  int *tmp___0;
  int flags;
  int tmp___1;
  int saved_errno;
  int *tmp___2;
  int *tmp___3;
  int tmp___4;
  void *p;
  void *tmp___5;

  {
    result = -1;
    __builtin_va_start(arg, action);
    if (action == 1030) {
      goto case_1030;
    }
    goto switch_default;
  case_1030:
    tmp = __builtin_va_arg(arg, int);
    target = tmp;
    if (0 <= have_dupfd_cloexec) {
      result = fcntl(fd, action, target);
      if (0 <= result) {
        have_dupfd_cloexec = 1;
      } else {
        tmp___0 = __errno_location();
        if (*tmp___0 != 22) {
          have_dupfd_cloexec = 1;
        } else {
          result = rpl_fcntl(fd, 0, target);
          if (result < 0) {
            goto switch_break;
          }
          have_dupfd_cloexec = -1;
        }
      }
    } else {
      result = rpl_fcntl(fd, 0, target);
    }
    if (0 <= result) {
      if (have_dupfd_cloexec == -1) {
        tmp___1 = fcntl(result, 1);
        flags = tmp___1;
        if (flags < 0) {
          goto _L;
        } else {
          tmp___4 = fcntl(result, 2, flags | 1);
          if (tmp___4 == -1) {
          _L:
            tmp___2 = __errno_location();
            saved_errno = *tmp___2;
            close(result);
            tmp___3 = __errno_location();
            *tmp___3 = saved_errno;
            result = -1;
          }
        }
      }
    }
    goto switch_break;
  switch_default:
    tmp___5 = __builtin_va_arg(arg, void *);
    p = tmp___5;
    result = fcntl(fd, action, p);
    goto switch_break;
  switch_break:
    __builtin_va_end(arg);
    return (result);
  }
}
int volatile exit_failure;
