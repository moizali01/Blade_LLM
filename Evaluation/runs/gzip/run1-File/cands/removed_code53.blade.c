

if (force) {
  if (to_stdout) {
    if (inptr < insize) {
      tmp = inptr;
      inptr++;
      tmp___1 = (int)inbuf[tmp];
    } else {
      {
        tmp___0 = fill_inbuf(1);
        tmp___1 = tmp___0;
      }
    }
    magic[0] = (char)tmp___1;
    if (inptr < insize) {
      tmp___2 = inptr;
      inptr++;
      tmp___4 = (int)inbuf[tmp___2];
    } else {
      {
        tmp___3 = fill_inbuf(1);
        tmp___4 = tmp___3;
      }
    }
    magic[1] = (char)tmp___4;
  } else {
    goto _L;
  }
} else {
_L:
  if (inptr < insize) {
    tmp___5 = inptr;
    inptr++;
    tmp___7 = (int)inbuf[tmp___5];
  } else {
    {
      tmp___6 = fill_inbuf(0);
      tmp___7 = tmp___6;
    }
  }
  magic[0] = (char)tmp___7;
  if (inptr < insize) {
    tmp___8 = inptr;
    inptr++;
    tmp___10 = (int)inbuf[tmp___8];
  } else {
    {
      tmp___9 = fill_inbuf(0);
      tmp___10 = tmp___9;
    }
  }
  magic[1] = (char)tmp___10;
}
{
  method = -1;
  part_nb++;
  header_bytes = 0L;
  last_member = 0;
  tmp___61 = memcmp((void const *)(magic), (void const *)"\037\213", (size_t)2);
}
if (tmp___61 == 0) {
  goto _L___4;
} else {
  {
    tmp___62 =
        memcmp((void const *)(magic), (void const *)"\037\236", (size_t)2);
  }
  if (tmp___62 == 0) {
  _L___4:
    if (inptr < insize) {
      tmp___11 = inptr;
      inptr++;
      tmp___13 = (int)inbuf[tmp___11];
    } else {
      {
        tmp___12 = fill_inbuf(0);
        tmp___13 = tmp___12;
      }
    }
    method = tmp___13;
    if (method != 8) {
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const * /* __restrict  */) "%s: %s: unknown method %d -- "
                                                 "get newer version of gzip\n",
                progname, ifname, method);
        exit_code = 1;
      }
      return (-1);
    }
    work = &unzip;
    if (inptr < insize) {
      tmp___14 = inptr;
      inptr++;
      tmp___16 = (int)inbuf[tmp___14];
    } else {
      {
        tmp___15 = fill_inbuf(0);
        tmp___16 = tmp___15;
      }
    }
    flags___0 = (uch)tmp___16;
    if (((int)flags___0 & 32) != 0) {
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const * /* __restrict  */) "%s: %s is encrypted -- get "
                                                 "newer version of gzip\n",
                progname, ifname);
        exit_code = 1;
      }
      return (-1);
    }
    if (((int)flags___0 & 2) != 0) {
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const
                     * /* __restrict  */) "%s: %s is a a multi-part gzip file "
                                          "-- get newer version of gzip\n",
                progname, ifname);
        exit_code = 1;
      }
      if (force <= 1) {
        return (-1);
      }
    }
    if (((int)flags___0 & 192) != 0) {
      {
        fprintf((FILE * /* __restrict  */) stderr,
                (char const * /* __restrict  */) "%s: %s has flags 0x%x -- get "
                                                 "newer version of gzip\n",
                progname, ifname, (int)flags___0);
        exit_code = 1;
      }
      if (force <= 1) {
        return (-1);
      }
    }
    if (inptr < insize) {
      tmp___17 = inptr;
      inptr++;
      tmp___19 = (int)inbuf[tmp___17];
    } else {
      {
        tmp___18 = fill_inbuf(0);
        tmp___19 = tmp___18;
      }
    }
    stamp = (ulg)tmp___19;
    if (inptr < insize) {
      tmp___20 = inptr;
      inptr++;
      tmp___22 = (int)inbuf[tmp___20];
    } else {
      {
        tmp___21 = fill_inbuf(0);
        tmp___22 = tmp___21;
      }
    }
    stamp |= (ulg)tmp___22 << 8;
    if (inptr < insize) {
      tmp___23 = inptr;
      inptr++;
      tmp___25 = (int)inbuf[tmp___23];
    } else {
      {
        tmp___24 = fill_inbuf(0);
        tmp___25 = tmp___24;
      }
    }
    stamp |= (ulg)tmp___25 << 16;
    if (inptr < insize) {
      tmp___26 = inptr;
      inptr++;
      tmp___28 = (int)inbuf[tmp___26];
    } else {
      {
        tmp___27 = fill_inbuf(0);
        tmp___28 = tmp___27;
      }
    }
    stamp |= (ulg)tmp___28 << 24;
    if (stamp != 0UL) {
      if (!no_time) {
        time_stamp = (long)stamp;
      }
    }
    if (inptr < insize) {
      tmp___29 = inptr;
      inptr++;
    } else {
      { fill_inbuf(0); }
    }
    if (inptr < insize) {
      tmp___30 = inptr;
      inptr++;
    } else {
      { fill_inbuf(0); }
    }
    if (((int)flags___0 & 2) != 0) {
      if (inptr < insize) {
        tmp___31 = inptr;
        inptr++;
        tmp___33 = (int)inbuf[tmp___31];
      } else {
        {
          tmp___32 = fill_inbuf(0);
          tmp___33 = tmp___32;
        }
      }
      part = (unsigned int)tmp___33;
      if (inptr < insize) {
        tmp___34 = inptr;
        inptr++;
        tmp___36 = (int)inbuf[tmp___34];
      } else {
        {
          tmp___35 = fill_inbuf(0);
          tmp___36 = tmp___35;
        }
      }
      part |= (unsigned int)tmp___36 << 8;
      if (verbose) {
        {
          fprintf((FILE * /* __restrict  */) stderr,
                  (char const * /* __restrict  */) "%s: %s: part number %u\n",
                  progname, ifname, part);
        }
      }
    }
    if (((int)flags___0 & 4) != 0) {
      if (inptr < insize) {
        tmp___37 = inptr;
        inptr++;
        tmp___39 = (int)inbuf[tmp___37];
      } else {
        {
          tmp___38 = fill_inbuf(0);
          tmp___39 = tmp___38;
        }
      }
      len = (unsigned int)tmp___39;
      if (inptr < insize) {
        tmp___40 = inptr;
        inptr++;
        tmp___42 = (int)inbuf[tmp___40];
      } else {
        {
          tmp___41 = fill_inbuf(0);
          tmp___42 = tmp___41;
        }
      }
      len |= (unsigned int)tmp___42 << 8;
      if (verbose) {
        {
          fprintf((FILE * /* __restrict  */) stderr,
                  (char const * /* __restrict  */) "%s: %s: extra field of "
                                                   "%u bytes ignored\n",
                  progname, ifname, len);
        }
      }
      {
        while (1) {
        while_continue: /* CIL Label */
                        ;
          tmp___44 = len;
          len--;
          if (!tmp___44) {
            goto while_break;
          }
          if (inptr < insize) {
            tmp___43 = inptr;
            inptr++;
          } else {
            { fill_inbuf(0); }
          }
        }
      while_break: /* CIL Label */
                   ;
      }
    }
    if (((int)flags___0 & 8) != 0) {
      if (no_name) {
        goto _L___0;
      } else {
        if (to_stdout) {
          if (!list) {
            goto _L___0;
          } else {
            goto _L___1;
          }
        } else {
        _L___1:
          if (part_nb > 1) {
          _L___0 : {
            while (1) {
            while_continue___0: /* CIL Label */
                                ;
              if (inptr < insize) {
                tmp___45 = inptr;
                inptr++;
                c = (char)inbuf[tmp___45];
              } else {
                {
                  tmp___46 = fill_inbuf(0);
                  c = (char)tmp___46;
                }
              }
              if (!((int)c != 0)) {
                goto while_break___0;
              }
            }
          while_break___0: /* CIL Label */
                           ;
          }
          } else {
            {
              tmp___47 = basename(ofname);
              p = tmp___47;
              base = p;
            }
            {
              while (1) {
              while_continue___1: /* CIL Label */
                                  ;
                if (inptr < insize) {
                  tmp___48 = inptr;
                  inptr++;
                  tmp___50 = (int)inbuf[tmp___48];
                } else {
                  {
                    tmp___49 = fill_inbuf(0);
                    tmp___50 = tmp___49;
                  }
                }
                *p = (char)tmp___50;
                tmp___51 = p;
                p++;
                if ((int)*tmp___51 == 0) {
                  goto while_break___1;
                }
                if ((unsigned long)p >=
                    (unsigned long)(ofname + sizeof(ofname))) {
                  { error((char *)"corrupted input -- file name too large"); }
                }
              }
            while_break___1: /* CIL Label */
                             ;
            }
            if (!list) {
              if (base) {
                list = 0;
              }
            }
          }
        }
      }
    }
    if (((int)flags___0 & 16) != 0) {
      {
        while (1) {
        while_continue___2: /* CIL Label */
                            ;
          if (inptr < insize) {
            tmp___52 = inptr;
            inptr++;
            tmp___54 = (int)inbuf[tmp___52];
          } else {
            {
              tmp___53 = fill_inbuf(0);
              tmp___54 = tmp___53;
            }
          }
          if (!(tmp___54 != 0)) {
            goto while_break___2;
          }
        }
      while_break___2: /* CIL Label */
                       ;
      }
    }
    if (part_nb == 1) {
      header_bytes = (long)((unsigned long)inptr + 2UL * sizeof(long));
    }
  } else {
    {
      tmp___59 =
          memcmp((void const *)(magic), (void const *)"PK\003\004", (size_t)2);
    }
    if (tmp___59 == 0) {
      if (inptr == 2U) {
        {
          tmp___60 = memcmp((void const *)((char *)(inbuf)),
                            (void const *)"PK\003\004", (size_t)4);
        }
        if (tmp___60 == 0) {
          {
            inptr = 0U;
            work = &unzip;
            tmp___55 = check_zipfile(in);
          }
          if (tmp___55 != 0) {
            return (-1);
          }
          last_member = 1;
        } else {
          goto _L___3;
        }
      } else {
        goto _L___3;
      }
    } else {
    _L___3 : {
      tmp___58 =
          memcmp((void const *)(magic), (void const *)"\037\036", (size_t)2);
    }
      if (tmp___58 == 0) {
        work = &unpack;
        method = 2;
      } else {
        {
          tmp___57 = memcmp((void const *)(magic), (void const *)"\037\235",
                            (size_t)2);
        }
        if (tmp___57 == 0) {
          work = &unlzw;
          method = 1;
          last_member = 1;
        } else {
          {
            tmp___56 = memcmp((void const *)(magic), (void const *)"\037\240",
                              (size_t)2);
          }
          if (tmp___56 == 0) {
            work = &unlzh;
            method = 3;
            last_member = 1;
          } else {
            if (force) {
              if (to_stdout) {
                if (!list) {
                  method = 0;
                  work = &copy;
                  inptr = 0U;
                  last_member = 1;
                }
              }
            }
          }
        }
      }
    }
  }
}
if (method >= 0) {
  return (method);
}
