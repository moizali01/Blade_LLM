

_Bool euidaccess_stat(struct stat const *st, int mode) {
  uid_t euid;
  unsigned int granted;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int tmp___10;
  gid_t egid;
  gid_t tmp___11;
  int tmp___12;

  {
    mode &= 7;
    if (mode == 0) {
      return ((_Bool)1);
    }
    euid = geteuid();
    if (euid == 0U) {
      if ((mode & 1) == 0) {
        return ((_Bool)1);
      } else {
        if (st->st_mode &
            (unsigned int const)((64 | (64 >> 3)) | ((64 >> 3) >> 3))) {
          return ((_Bool)1);
        }
      }
    }
    if (256 == 4 << 6) {
      if (128 == 2 << 6) {
        if (64 == 1 << 6) {
          if (256 >> 3 == 4 << 3) {
            if (128 >> 3 == 2 << 3) {
              if (64 >> 3 == 1 << 3) {
                if ((256 >> 3) >> 3 == 4) {
                  if ((128 >> 3) >> 3 == 2) {
                    if ((64 >> 3) >> 3 == 1) {
                      granted = (unsigned int)st->st_mode;
                    } else {
                      goto _L___6;
                    }
                  } else {
                    goto _L___6;
                  }
                } else {
                  goto _L___6;
                }
              } else {
                goto _L___6;
              }
            } else {
              goto _L___6;
            }
          } else {
            goto _L___6;
          }
        } else {
          goto _L___6;
        }
      } else {
        goto _L___6;
      }
    } else {
    _L___6:
      if (st->st_mode & 256U) {
        tmp___2 = 4 << 6;
      } else {
        tmp___2 = 0;
      }
      if (st->st_mode & 128U) {
        tmp___3 = 2 << 6;
      } else {
        tmp___3 = 0;
      }
      if (st->st_mode & 64U) {
        tmp___4 = 1 << 6;
      } else {
        tmp___4 = 0;
      }
      if (st->st_mode & (unsigned int const)(256 >> 3)) {
        tmp___5 = 4 << 3;
      } else {
        tmp___5 = 0;
      }
      if (st->st_mode & (unsigned int const)(128 >> 3)) {
        tmp___6 = 2 << 3;
      } else {
        tmp___6 = 0;
      }
      if (st->st_mode & (unsigned int const)(64 >> 3)) {
        tmp___7 = 1 << 3;
      } else {
        tmp___7 = 0;
      }
      if (st->st_mode & (unsigned int const)((256 >> 3) >> 3)) {
        tmp___8 = 4;
      } else {
        tmp___8 = 0;
      }
      if (st->st_mode & (unsigned int const)((128 >> 3) >> 3)) {
        tmp___9 = 2;
      } else {
        tmp___9 = 0;
      }
      if (st->st_mode & (unsigned int const)((64 >> 3) >> 3)) {
        tmp___10 = 1;
      } else {
        tmp___10 = 0;
      }
      granted = (unsigned int)((((((((tmp___2 + tmp___3) + tmp___4) + tmp___5) +
                                   tmp___6) +
                                  tmp___7) +
                                 tmp___8) +
                                tmp___9) +
                               tmp___10);
    }
    if (euid == (uid_t)st->st_uid) {
      granted >>= 6;
    } else {
      tmp___11 = getegid();
      egid = tmp___11;
      if (egid == (gid_t)st->st_gid) {
        granted >>= 3;
      } else {
        tmp___12 = group_member((__gid_t)st->st_gid);
        if (tmp___12) {
          granted >>= 3;
        }
      }
    }
    if (((unsigned int)mode & ~granted) == 0U) {
      return ((_Bool)1);
    }
    return ((_Bool)0);
  }
}
