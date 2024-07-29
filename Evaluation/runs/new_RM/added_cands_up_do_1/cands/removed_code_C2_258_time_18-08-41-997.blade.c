

FTSENT *(__attribute__((__warn_unused_result__, __leaf__)) fts_read)(FTS *sp) {
  register FTSENT *p;
  register FTSENT *tmp;
  register unsigned short instr;
  register char *t;
  int *tmp___0;
  int tmp___1;
  int *tmp___2;
  int tmp___3;
  struct _ftsent *tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  int tmp___9;
  int *tmp___10;
  int tmp___11;
  size_t tmp___12;
  char *tmp___13;
  FTSENT *parent;
  _Bool tmp___14;
  int *tmp___15;
  _Bool tmp___16;
  int *tmp___17;
  struct _ftsent *tmp___18;
  int *tmp___19;
  int tmp___20;
  int tmp___21;
  int tmp___22;
  int tmp___23;
  int tmp___24;
  int saved_errno;
  int *tmp___25;
  int *tmp___26;
  int *tmp___27;
  int tmp___28;
  int tmp___29;
  int *tmp___30;
  int tmp___31;
  FTSENT *tmp___32;

  {
    if ((unsigned long)sp->fts_cur == (unsigned long)((void *)0)) {
      return ((FTSENT *)((void *)0));
    } else {
      if (sp->fts_options & 8192) {
        return ((FTSENT *)((void *)0));
      }
    }
    p = sp->fts_cur;
    instr = p->fts_instr;
    p->fts_instr = (unsigned short)3;
    if ((int)instr == 1) {
      p->fts_info = fts_stat(sp, p, (_Bool)0);
      return (p);
    }
    if ((int)instr == 2) {
      if ((int)p->fts_info == 12) {
        goto _L;
      } else {
        if ((int)p->fts_info == 13) {
        _L:
          p->fts_info = fts_stat(sp, p, (_Bool)1);
          if ((int)p->fts_info == 1) {
            if (!(sp->fts_options & 4)) {
              tmp___1 = diropen((FTS const *)sp, ".");
              p->fts_symfd = tmp___1;
              if (tmp___1 < 0) {
                tmp___0 = __errno_location();
                p->fts_errno = *tmp___0;
                p->fts_info = (unsigned short)7;
              } else {
                p->fts_flags = (unsigned short)((int)p->fts_flags | 2);
              }
            }
          }
          goto check_for_dir;
        }
      }
    }
    if ((int)p->fts_info == 1) {
      if ((int)instr == 4) {
        goto _L___0;
      } else {
        if (sp->fts_options & 64) {
          if (p->fts_statp[0].st_dev != sp->fts_dev) {
          _L___0:
            if ((int)p->fts_flags & 2) {
              close(p->fts_symfd);
            }
            if (sp->fts_child) {
              fts_lfree(sp->fts_child);
              sp->fts_child = (struct _ftsent *)((void *)0);
            }
            p->fts_info = (unsigned short)6;
            while (1) {
              leave_dir(sp, p);
              goto while_break;
            }
          while_break:;
            return (p);
          }
        }
      }
      if ((unsigned long)sp->fts_child != (unsigned long)((void *)0)) {
        if (sp->fts_options & 4096) {
          sp->fts_options &= -4097;
          fts_lfree(sp->fts_child);
          sp->fts_child = (struct _ftsent *)((void *)0);
        }
      }
      if ((unsigned long)sp->fts_child != (unsigned long)((void *)0)) {
        tmp___3 = fts_safe_changedir(sp, p, -1, (char const *)p->fts_accpath);
        if (tmp___3) {
          tmp___2 = __errno_location();
          p->fts_errno = *tmp___2;
          p->fts_flags = (unsigned short)((int)p->fts_flags | 1);
          p = sp->fts_child;
          while (1) {

            if (!((unsigned long)p != (unsigned long)((void *)0))) {
              goto while_break___0;
            }
            p->fts_accpath = (p->fts_parent)->fts_accpath;
            p = p->fts_link;
          }
        while_break___0:;
        }
      } else {
        tmp___4 = fts_build(sp, 3);
        sp->fts_child = tmp___4;
        if ((unsigned long)tmp___4 == (unsigned long)((void *)0)) {
          if (sp->fts_options & 8192) {
            return ((FTSENT *)((void *)0));
          }
          if (p->fts_errno) {
            if ((int)p->fts_info != 4) {
              p->fts_info = (unsigned short)7;
            }
          }
          while (1) {
            leave_dir(sp, p);
            goto while_break___1;
          }
        while_break___1:;
          return (p);
        }
      }
      p = sp->fts_child;
      sp->fts_child = (struct _ftsent *)((void *)0);
      goto name;
    }
  next:
    tmp = p;
    p = p->fts_link;
    if ((unsigned long)p != (unsigned long)((void *)0)) {
      sp->fts_cur = p;
      free((void *)tmp);
      if (p->fts_level == 0L) {
        fd_ring_clear(&sp->fts_fd_ring);
        if (!(sp->fts_options & 4)) {
          if (sp->fts_options & 512) {
            if (sp->fts_options & 512) {
              tmp___5 = -100;
            } else {
              tmp___5 = sp->fts_rfd;
            }
            cwd_advance_fd(sp, tmp___5, (_Bool)1);
            tmp___8 = 0;
          } else {
            if (sp->fts_options & 512) {
              tmp___6 = -100;
            } else {
              tmp___6 = sp->fts_rfd;
            }
            tmp___7 = fchdir(tmp___6);
            tmp___8 = tmp___7;
          }
          if (tmp___8) {
            tmp___9 = 1;
          } else {
            tmp___9 = 0;
          }
        } else {
          tmp___9 = 0;
        }
        if (tmp___9) {
          sp->fts_options |= 8192;
          return ((FTSENT *)((void *)0));
        }
        free_dir(sp);
        fts_load(sp, p);
        setup_dir(sp);
        goto check_for_dir;
      }
      if ((int)p->fts_instr == 4) {
        goto next;
      }
      if ((int)p->fts_instr == 2) {
        p->fts_info = fts_stat(sp, p, (_Bool)1);
        if ((int)p->fts_info == 1) {
          if (!(sp->fts_options & 4)) {
            tmp___11 = diropen((FTS const *)sp, ".");
            p->fts_symfd = tmp___11;
            if (tmp___11 < 0) {
              tmp___10 = __errno_location();
              p->fts_errno = *tmp___10;
              p->fts_info = (unsigned short)7;
            } else {
              p->fts_flags = (unsigned short)((int)p->fts_flags | 2);
            }
          }
        }
        p->fts_instr = (unsigned short)3;
      }
    name:
      if ((int)*((p->fts_parent)->fts_path +
                 ((p->fts_parent)->fts_pathlen - 1UL)) == 47) {
        tmp___12 = (p->fts_parent)->fts_pathlen - 1UL;
      } else {
        tmp___12 = (p->fts_parent)->fts_pathlen;
      }
      t = sp->fts_path + tmp___12;
      tmp___13 = t;
      t++;
      *tmp___13 = (char)'/';
      memmove((void *)t, (void const *)(p->fts_name), p->fts_namelen + 1UL);
    check_for_dir:
      sp->fts_cur = p;
      if ((int)p->fts_info == 11) {
        if (p->fts_statp[0].st_size == 2L) {
          parent = p->fts_parent;
          if (0L < p->fts_level) {
            if (parent->fts_n_dirs_remaining == 0UL) {
              if (sp->fts_options & 8) {
                if (sp->fts_options & 16) {
                  tmp___14 = link_count_optimize_ok((FTSENT const *)parent);
                  if (!tmp___14) {
                    goto _L___4;
                  }
                } else {
                  goto _L___4;
                }
              } else {
                goto _L___4;
              }
            } else {
              goto _L___4;
            }
          } else {
          _L___4:
            p->fts_info = fts_stat(sp, p, (_Bool)0);
            if ((p->fts_statp[0].st_mode & 61440U) == 16384U) {
              if (p->fts_level != 0L) {
                if (parent->fts_n_dirs_remaining) {
                  (parent->fts_n_dirs_remaining)--;
                }
              }
            }
          }
        } else {
          while (1) {

            if (!(p->fts_statp[0].st_size == 1L)) {
              abort();
            }
            goto while_break___2;
          }
        while_break___2:;
        }
      }
      if ((int)p->fts_info == 1) {
        if (p->fts_level == 0L) {
          sp->fts_dev = p->fts_statp[0].st_dev;
        }
        tmp___16 = enter_dir(sp, p);
        if (!tmp___16) {
          tmp___15 = __errno_location();
          *tmp___15 = 12;
          return ((FTSENT *)((void *)0));
        }
      }
      return (p);
    }
    p = tmp->fts_parent;
    sp->fts_cur = p;
    free((void *)tmp);
    if (p->fts_level == -1L) {
      free((void *)p);
      tmp___17 = __errno_location();
      *tmp___17 = 0;
      tmp___18 = (struct _ftsent *)((void *)0);
      sp->fts_cur = tmp___18;
      return (tmp___18);
    }
    while (1) {

      if (!((int)p->fts_info != 11)) {
        abort();
      }
      goto while_break___3;
    }
  while_break___3:
    *(sp->fts_path + p->fts_pathlen) = (char)'\000';
    if (p->fts_level == 0L) {
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
      if (tmp___24) {
        tmp___19 = __errno_location();
        p->fts_errno = *tmp___19;
        sp->fts_options |= 8192;
      }
    } else {
      if ((int)p->fts_flags & 2) {
        if (!(sp->fts_options & 4)) {
          if (sp->fts_options & 512) {
            cwd_advance_fd(sp, p->fts_symfd, (_Bool)1);
            tmp___29 = 0;
          } else {
            tmp___28 = fchdir(p->fts_symfd);
            tmp___29 = tmp___28;
          }
          if (tmp___29) {
            tmp___25 = __errno_location();
            saved_errno = *tmp___25;
            close(p->fts_symfd);
            tmp___26 = __errno_location();
            *tmp___26 = saved_errno;
            tmp___27 = __errno_location();
            p->fts_errno = *tmp___27;
            sp->fts_options |= 8192;
          }
        }
        close(p->fts_symfd);
      } else {
        if (!((int)p->fts_flags & 1)) {
          tmp___31 = fts_safe_changedir(sp, p->fts_parent, -1, "..");
          if (tmp___31) {
            tmp___30 = __errno_location();
            p->fts_errno = *tmp___30;
            sp->fts_options |= 8192;
          }
        }
      }
    }
    if (p->fts_errno) {
      p->fts_info = (unsigned short)7;
    } else {
      p->fts_info = (unsigned short)6;
    }
    if (p->fts_errno == 0) {
      while (1) {
        leave_dir(sp, p);
        goto while_break___4;
      }
    while_break___4:;
    }
    if (sp->fts_options & 8192) {
      tmp___32 = (FTSENT *)((void *)0);
    } else {
      tmp___32 = p;
    }
    return (tmp___32);
  }
}
