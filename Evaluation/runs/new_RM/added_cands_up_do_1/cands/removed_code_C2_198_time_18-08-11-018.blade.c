

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
