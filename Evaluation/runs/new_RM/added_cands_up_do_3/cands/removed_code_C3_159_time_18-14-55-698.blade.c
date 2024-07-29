

static FTSENT *fts_build(FTS *sp, int type) {
  register struct dirent *dp;
  register FTSENT *p;
  register FTSENT *head;
  register size_t nitems;
  FTSENT *cur;
  FTSENT *tail;
  DIR *dirp;
  void *oldaddr;
  int saved_errno;
  _Bool descend;
  _Bool doadjust;
  ptrdiff_t level;
  nlink_t nlinks;
  _Bool nostat;
  size_t len;
  size_t maxlen;
  size_t new_len;
  char *cp;
  int *tmp;
  DIR *tmp___0;
  DIR *tmp___1;
  int *tmp___2;
  _Bool tmp___3;
  int tmp___4;
  int dir_fd;
  int tmp___5;
  int *tmp___6;
  int tmp___7;
  char *tmp___8;
  _Bool is_dir;
  size_t tmp___9;
  int *tmp___10;
  int *tmp___11;
  size_t tmp___12;
  _Bool tmp___13;
  size_t tmp___14;
  size_t tmp___15;
  int *tmp___16;
  _Bool skip_stat;
  int tmp___17;
  int tmp___18;
  int tmp___19;
  int tmp___20;
  int tmp___21;
  int tmp___22;
  int tmp___23;
  int tmp___24;
  int tmp___25;
  int tmp___26;
  _Bool tmp___27;

  {
    cur = sp->fts_cur;
    if (!(sp->fts_options & 4)) {
      if (sp->fts_options & 512) {
        tmp___0 = opendirat(sp->fts_cwd_fd, (char const *)cur->fts_accpath);
        dirp = tmp___0;
      } else {
        tmp___1 = opendir_safer((char const *)cur->fts_accpath);
        dirp = tmp___1;
      }
    } else {
      tmp___1 = opendir_safer((char const *)cur->fts_accpath);
      dirp = tmp___1;
    }
    if ((unsigned long)dirp == (unsigned long)((void *)0)) {
      if (type == 3) {
        cur->fts_info = (unsigned short)4;
        tmp = __errno_location();
        cur->fts_errno = *tmp;
      }
      return ((FTSENT *)((void *)0));
    }
    if ((int)cur->fts_info == 11) {
      cur->fts_info = fts_stat(sp, cur, (_Bool)0);
    } else {
      if (sp->fts_options & 256) {
        while (1) {
          leave_dir(sp, cur);
          goto while_break;
        }
      while_break:
        fts_stat(sp, cur, (_Bool)0);
        tmp___3 = enter_dir(sp, cur);
        if (!tmp___3) {
          tmp___2 = __errno_location();
          *tmp___2 = 12;
          return ((FTSENT *)((void *)0));
        }
      }
    }
    if (type == 2) {
      nlinks = (nlink_t)0;
      nostat = (_Bool)0;
    } else {
      if (sp->fts_options & 8) {
        if (sp->fts_options & 16) {
          if (sp->fts_options & 32) {
            tmp___4 = 0;
          } else {
            tmp___4 = 2;
          }
          nlinks = cur->fts_statp[0].st_nlink - (__nlink_t)tmp___4;
          nostat = (_Bool)1;
        } else {
          nlinks = (nlink_t)-1;
          nostat = (_Bool)0;
        }
      } else {
        nlinks = (nlink_t)-1;
        nostat = (_Bool)0;
      }
    }
    if (nlinks) {
      goto _L___0;
    } else {
      if (type == 3) {
      _L___0:
        tmp___5 = dirfd(dirp);
        dir_fd = tmp___5;
        if (sp->fts_options & 512) {
          if (0 <= dir_fd) {
            dir_fd = dup_safer(dir_fd);
            set_cloexec_flag(dir_fd, (_Bool)1);
          }
        }
        if (dir_fd < 0) {
          goto _L;
        } else {
          tmp___7 =
              fts_safe_changedir(sp, cur, dir_fd, (char const *)((void *)0));
          if (tmp___7) {
          _L:
            if (nlinks) {
              if (type == 3) {
                tmp___6 = __errno_location();
                cur->fts_errno = *tmp___6;
              }
            }
            cur->fts_flags = (unsigned short)((int)cur->fts_flags | 1);
            descend = (_Bool)0;
            closedir(dirp);
            if (sp->fts_options & 512) {
              if (0 <= dir_fd) {
                close(dir_fd);
              }
            }
            dirp = (DIR *)((void *)0);
          } else {
            descend = (_Bool)1;
          }
        }
      } else {
        descend = (_Bool)0;
      }
    }
    if ((int)*(cur->fts_path + (cur->fts_pathlen - 1UL)) == 47) {
      len = cur->fts_pathlen - 1UL;
    } else {
      len = cur->fts_pathlen;
    }
    if (sp->fts_options & 4) {
      cp = sp->fts_path + len;
      tmp___8 = cp;
      cp++;
      *tmp___8 = (char)'/';
    } else {
      cp = (char *)((void *)0);
    }
    len++;
    maxlen = sp->fts_pathlen - len;
    level = cur->fts_level + 1L;
    doadjust = (_Bool)0;
    tail = (FTSENT *)((void *)0);
    head = tail;
    nitems = (size_t)0;
    while (1) {

      if (dirp) {
        dp = readdir(dirp);
        if (!dp) {
          goto while_break___0;
        }
      } else {
        goto while_break___0;
      }
      if (!(sp->fts_options & 32)) {
        if ((int)dp->d_name[0] == 46) {
          if (!dp->d_name[1]) {
            goto __Cont;
          } else {
            if ((int)dp->d_name[1] == 46) {
              if (!dp->d_name[2]) {
                goto __Cont;
              }
            }
          }
        }
      }
      tmp___9 = strlen((char const *)(dp->d_name));
      p = fts_alloc(sp, (char const *)(dp->d_name), tmp___9);
      if ((unsigned long)p == (unsigned long)((void *)0)) {
        goto mem1;
      }
      tmp___14 = strlen((char const *)(dp->d_name));
      if (tmp___14 >= maxlen) {
        oldaddr = (void *)sp->fts_path;
        tmp___12 = strlen((char const *)(dp->d_name));
        tmp___13 = fts_palloc(sp, (tmp___12 + len) + 1UL);
        if (!tmp___13) {
        mem1:
          tmp___10 = __errno_location();
          saved_errno = *tmp___10;
          free((void *)p);
          fts_lfree(head);
          closedir(dirp);
          cur->fts_info = (unsigned short)7;
          sp->fts_options |= 8192;
          tmp___11 = __errno_location();
          *tmp___11 = saved_errno;
          return ((FTSENT *)((void *)0));
        }
        if ((unsigned long)oldaddr != (unsigned long)sp->fts_path) {
          doadjust = (_Bool)1;
          if (sp->fts_options & 4) {
            cp = sp->fts_path + len;
          }
        }
        maxlen = sp->fts_pathlen - len;
      }
      tmp___15 = strlen((char const *)(dp->d_name));
      new_len = len + tmp___15;
      if (new_len < len) {
        free((void *)p);
        fts_lfree(head);
        closedir(dirp);
        cur->fts_info = (unsigned short)7;
        sp->fts_options |= 8192;
        tmp___16 = __errno_location();
        *tmp___16 = 36;
        return ((FTSENT *)((void *)0));
      }
      p->fts_level = level;
      p->fts_parent = sp->fts_cur;
      p->fts_pathlen = new_len;
      p->fts_statp[0].st_ino = dp->d_ino;
      if (sp->fts_options & 4) {
        p->fts_accpath = p->fts_path;
        memmove((void *)cp, (void const *)(p->fts_name), p->fts_namelen + 1UL);
      } else {
        p->fts_accpath = p->fts_name;
      }
      if ((unsigned long)sp->fts_compar == (unsigned long)((void *)0)) {
        goto _L___1;
      } else {
        if (sp->fts_options & 1024) {
        _L___1:
          if (sp->fts_options & 16) {
            if (sp->fts_options & 8) {
              if ((int)dp->d_type != 0) {
                if (!((int)dp->d_type == 4)) {
                  tmp___17 = 1;
                } else {
                  tmp___17 = 0;
                }
              } else {
                tmp___17 = 0;
              }
            } else {
              tmp___17 = 0;
            }
          } else {
            tmp___17 = 0;
          }
          skip_stat = (_Bool)tmp___17;
          p->fts_info = (unsigned short)11;
          set_stat_type(p->fts_statp, (unsigned int)dp->d_type);
          fts_set_stat_required(p, (_Bool)(!skip_stat));
          if (sp->fts_options & 16) {
            if ((int)dp->d_type == 4) {
              tmp___18 = 1;
            } else {
              tmp___18 = 0;
            }
          } else {
            tmp___18 = 0;
          }
          is_dir = (_Bool)tmp___18;
        } else {
          p->fts_info = fts_stat(sp, p, (_Bool)0);
          if ((int)p->fts_info == 1) {
            tmp___19 = 1;
          } else {
            if ((int)p->fts_info == 2) {
              tmp___19 = 1;
            } else {
              if ((int)p->fts_info == 5) {
                tmp___19 = 1;
              } else {
                tmp___19 = 0;
              }
            }
          }
          is_dir = (_Bool)tmp___19;
        }
      }
      if (nlinks > 0UL) {
        if (is_dir) {
          nlinks -= (nlink_t)nostat;
        }
      }
      p->fts_link = (struct _ftsent *)((void *)0);
      if ((unsigned long)head == (unsigned long)((void *)0)) {
        tail = p;
        head = tail;
      } else {
        tail->fts_link = p;
        tail = p;
      }
      nitems++;
    __Cont:;
    }
  while_break___0:;
    if (dirp) {
      closedir(dirp);
    }
    if (doadjust) {
      fts_padjust(sp, head);
    }
    if (sp->fts_options & 4) {
      if (len == sp->fts_pathlen) {
        cp--;
      } else {
        if (nitems == 0UL) {
          cp--;
        }
      }
      *cp = (char)'\000';
    }
    if (descend) {
      if (type == 1) {
        goto _L___2;
      } else {
        if (!nitems) {
        _L___2:
          if (cur->fts_level == 0L) {
            fd_ring_clear(&sp->fts_fd_ring);
            if (!(sp->fts_options & 4)) {
              if (sp->fts_options & 512) {
                if (sp->fts_options & 512) {
                  tmp___20 = -100;
                } else {
                  tmp___20 = sp->fts_rfd;
                }
                cwd_advance_fd(sp, tmp___20, (_Bool)1);
                tmp___23 = 0;
              } else {
                if (sp->fts_options & 512) {
                  tmp___21 = -100;
                } else {
                  tmp___21 = sp->fts_rfd;
                }
                tmp___22 = fchdir(tmp___21);
                tmp___23 = tmp___22;
              }
              if (tmp___23) {
                tmp___24 = 1;
              } else {
                tmp___24 = 0;
              }
            } else {
              tmp___24 = 0;
            }
            tmp___26 = tmp___24;
          } else {
            tmp___25 = fts_safe_changedir(sp, cur->fts_parent, -1, "..");
            tmp___26 = tmp___25;
          }
          if (tmp___26) {
            cur->fts_info = (unsigned short)7;
            sp->fts_options |= 8192;
            fts_lfree(head);
            return ((FTSENT *)((void *)0));
          }
        }
      }
    }
    if (!nitems) {
      if (type == 3) {
        cur->fts_info = (unsigned short)6;
      }
      fts_lfree(head);
      return ((FTSENT *)((void *)0));
    }
    if (nitems > 10000UL) {
      if (!sp->fts_compar) {
        if (sp->fts_options & 512) {
          tmp___27 = dirent_inode_sort_may_be_useful(sp->fts_cwd_fd);
          if (tmp___27) {
            sp->fts_compar = &fts_compare_ino;
            head = fts_sort(sp, head, nitems);
            sp->fts_compar = (int (*)(struct _ftsent const **,
                                      struct _ftsent const **))((void *)0);
          }
        }
      }
    }
    if (sp->fts_compar) {
      if (nitems > 1UL) {
        head = fts_sort(sp, head, nitems);
      }
    }
    return (head);
  }
}
static unsigned short fts_stat(FTS *sp, FTSENT *p, _Bool follow) {
  struct stat *sbp;
  int saved_errno;
  int *tmp;
  int *tmp___0;
  int *tmp___1;
  int tmp___2;
  int tmp___3;
  int *tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;

  {
    sbp = p->fts_statp;
    if (p->fts_level == 0L) {
      if (sp->fts_options & 1) {
        follow = (_Bool)1;
      }
    }
    if (sp->fts_options & 2) {
      goto _L;
    } else {
      if (follow) {
      _L:
        tmp___3 = stat((char const *)p->fts_accpath, sbp);
        if (tmp___3) {
          tmp = __errno_location();
          saved_errno = *tmp;
          tmp___1 = __errno_location();
          if (*tmp___1 == 2) {
            tmp___2 = lstat((char const *)p->fts_accpath, sbp);
            if (tmp___2 == 0) {
              tmp___0 = __errno_location();
              *tmp___0 = 0;
              return ((unsigned short)13);
            }
          }
          p->fts_errno = saved_errno;
          goto err;
        }
      } else {
        tmp___5 =
            fstatat(sp->fts_cwd_fd, (char const *)p->fts_accpath, sbp, 256);
        if (tmp___5) {
          tmp___4 = __errno_location();
          p->fts_errno = *tmp___4;
        err:
          memset((void *)sbp, 0, sizeof(struct stat));
          return ((unsigned short)10);
        }
      }
    }
    if ((sbp->st_mode & 61440U) == 16384U) {
      if (sp->fts_options & 32) {
        tmp___6 = 0;
      } else {
        tmp___6 = 2;
      }
      p->fts_n_dirs_remaining = sbp->st_nlink - (__nlink_t)tmp___6;
      if ((int)p->fts_name[0] == 46) {
        if (!p->fts_name[1]) {
          goto _L___0;
        } else {
          if ((int)p->fts_name[1] == 46) {
            if (!p->fts_name[2]) {
            _L___0:
              if (p->fts_level == 0L) {
                tmp___7 = 1;
              } else {
                tmp___7 = 5;
              }
              return ((unsigned short)tmp___7);
            }
          }
        }
      }
      return ((unsigned short)1);
    }
    if ((sbp->st_mode & 61440U) == 40960U) {
      return ((unsigned short)12);
    }
    if ((sbp->st_mode & 61440U) == 32768U) {
      return ((unsigned short)8);
    }
    return ((unsigned short)3);
  }
}
static int fts_compar(void const *a, void const *b) {
  FTSENT const **pa;
  FTSENT const **pb;
  int tmp;

  {
    pa = (FTSENT const **)a;
    pb = (FTSENT const **)b;
    tmp = (*(((*(pa + 0))->fts_fts)->fts_compar))(pa, pb);
    return (tmp);
  }
}
static FTSENT *fts_sort(FTS *sp, FTSENT *head, size_t nitems) {
  register FTSENT **ap;
  register FTSENT *p;
  FTSENT *dummy = 0;
  int (*compare)(void const *, void const *);
  int (*tmp)(void const *, void const *);
