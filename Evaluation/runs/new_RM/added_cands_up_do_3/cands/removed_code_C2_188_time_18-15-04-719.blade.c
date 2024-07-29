

static size_t
quotearg_buffer_restyled(char *buffer, size_t buffersize, char const *arg,
                         size_t argsize, enum quoting_style quoting_style,
                         int flags, unsigned int const *quote_these_too,
                         char const *left_quote, char const *right_quote) {
  size_t i;
  size_t len;
  char const *quote_string;
  size_t quote_string_len;
  _Bool backslash_escapes;
  _Bool unibyte_locale;
  size_t tmp;
  _Bool elide_outer_quotes;
  unsigned char c;
  unsigned char esc;
  _Bool is_right_quote;
  int tmp___0;
  int tmp___1;
  size_t m;
  _Bool printable;
  unsigned short const **tmp___2;
  mbstate_t mbstate;
  wchar_t w;
  size_t bytes;
  size_t tmp___3;
  size_t j;
  int tmp___4;
  int tmp___5;
  size_t ilim;
  int tmp___6;
  size_t tmp___7;

  {
    len = (size_t)0;
    quote_string = (char const *)0;
    quote_string_len = (size_t)0;
    backslash_escapes = (_Bool)0;
    tmp = __ctype_get_mb_cur_max();
    unibyte_locale = (_Bool)(tmp == 1UL);
    elide_outer_quotes = (_Bool)((flags & 2) != 0);
    if ((unsigned int)quoting_style == 4U) {
      goto case_4;
    }
    if ((unsigned int)quoting_style == 3U) {
      goto case_3;
    }
    if ((unsigned int)quoting_style == 5U) {
      goto case_5;
    }
    if ((unsigned int)quoting_style == 6U) {
      goto case_6;
    }
    if ((unsigned int)quoting_style == 7U) {
      goto case_6;
    }
    if ((unsigned int)quoting_style == 8U) {
      goto case_6;
    }
    if ((unsigned int)quoting_style == 1U) {
      goto case_1;
    }
    if ((unsigned int)quoting_style == 2U) {
      goto case_2;
    }
    if ((unsigned int)quoting_style == 0U) {
      goto case_0;
    }
    goto switch_default;
  case_4:
    quoting_style = (enum quoting_style)3;
    elide_outer_quotes = (_Bool)1;
  case_3:
    if (!elide_outer_quotes) {
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)'\"';
        }
        len++;
        goto while_break;
      }
    while_break:;
    }
    backslash_escapes = (_Bool)1;
    quote_string = "\"";
    quote_string_len = (size_t)1;
    goto switch_break;
  case_5:
    backslash_escapes = (_Bool)1;
    elide_outer_quotes = (_Bool)0;
    goto switch_break;
  case_6:
    if ((unsigned int)quoting_style != 8U) {
      left_quote = gettext_quote("`", quoting_style);
      right_quote = gettext_quote("\'", quoting_style);
    }
    if (!elide_outer_quotes) {
      quote_string = left_quote;
      while (1) {

        if (!*quote_string) {
          goto while_break___0;
        }
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)*quote_string;
          }
          len++;
          goto while_break___1;
        }
      while_break___1:
        quote_string++;
      }
    while_break___0:;
    }
    backslash_escapes = (_Bool)1;
    quote_string = right_quote;
    quote_string_len = strlen(quote_string);
    goto switch_break;
  case_1:
    quoting_style = (enum quoting_style)2;
    elide_outer_quotes = (_Bool)1;
  case_2:
    if (!elide_outer_quotes) {
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)'\'';
        }
        len++;
        goto while_break___2;
      }
    while_break___2:;
    }
    quote_string = "\'";
    quote_string_len = (size_t)1;
    goto switch_break;
  case_0:
    elide_outer_quotes = (_Bool)0;
    goto switch_break;
  switch_default:
    abort();
  switch_break:
    i = (size_t)0;
    while (1) {

      if (argsize == 0xffffffffffffffffUL) {
        tmp___6 = (int const) * (arg + i) == 0;
      } else {
        tmp___6 = i == argsize;
      }
      if (tmp___6) {
        goto while_break___3;
      }
      is_right_quote = (_Bool)0;
      if (backslash_escapes) {
        if (quote_string_len) {
          if (i + quote_string_len <= argsize) {
            tmp___0 = memcmp((void const *)(arg + i),
                             (void const *)quote_string, quote_string_len);
            if (tmp___0 == 0) {
              if (elide_outer_quotes) {
                goto force_outer_quoting_style;
              }
              is_right_quote = (_Bool)1;
            }
          }
        }
      }
      c = (unsigned char)*(arg + i);
      if ((int)c == 0) {
        goto case_0___0;
      }
      if ((int)c == 63) {
        goto case_63;
      }
      if ((int)c == 7) {
        goto case_7___0;
      }
      if ((int)c == 8) {
        goto case_8___0;
      }
      if ((int)c == 12) {
        goto case_12;
      }
      if ((int)c == 10) {
        goto case_10;
      }
      if ((int)c == 13) {
        goto case_13;
      }
      if ((int)c == 9) {
        goto case_9;
      }
      if ((int)c == 11) {
        goto case_11;
      }
      if ((int)c == 92) {
        goto case_92;
      }
      if ((int)c == 123) {
        goto case_123;
      }
      if ((int)c == 125) {
        goto case_123;
      }
      if ((int)c == 35) {
        goto case_35;
      }
      if ((int)c == 126) {
        goto case_35;
      }
      if ((int)c == 32) {
        goto case_32;
      }
      if ((int)c == 33) {
        goto case_32;
      }
      if ((int)c == 34) {
        goto case_32;
      }
      if ((int)c == 36) {
        goto case_32;
      }
      if ((int)c == 38) {
        goto case_32;
      }
      if ((int)c == 40) {
        goto case_32;
      }
      if ((int)c == 41) {
        goto case_32;
      }
      if ((int)c == 42) {
        goto case_32;
      }
      if ((int)c == 59) {
        goto case_32;
      }
      if ((int)c == 60) {
        goto case_32;
      }
      if ((int)c == 61) {
        goto case_32;
      }
      if ((int)c == 62) {
        goto case_32;
      }
      if ((int)c == 91) {
        goto case_32;
      }
      if ((int)c == 94) {
        goto case_32;
      }
      if ((int)c == 96) {
        goto case_32;
      }
      if ((int)c == 124) {
        goto case_32;
      }
      if ((int)c == 39) {
        goto case_39___0;
      }
      if ((int)c == 37) {
        goto case_37;
      }
      if ((int)c == 43) {
        goto case_37;
      }
      if ((int)c == 44) {
        goto case_37;
      }
      if ((int)c == 45) {
        goto case_37;
      }
      if ((int)c == 46) {
        goto case_37;
      }
      if ((int)c == 47) {
        goto case_37;
      }
      if ((int)c == 48) {
        goto case_37;
      }
      if ((int)c == 49) {
        goto case_37;
      }
      if ((int)c == 50) {
        goto case_37;
      }
      if ((int)c == 51) {
        goto case_37;
      }
      if ((int)c == 52) {
        goto case_37;
      }
      if ((int)c == 53) {
        goto case_37;
      }
      if ((int)c == 54) {
        goto case_37;
      }
      if ((int)c == 55) {
        goto case_37;
      }
      if ((int)c == 56) {
        goto case_37;
      }
      if ((int)c == 57) {
        goto case_37;
      }
      if ((int)c == 58) {
        goto case_37;
      }
      if ((int)c == 65) {
        goto case_37;
      }
      if ((int)c == 66) {
        goto case_37;
      }
      if ((int)c == 67) {
        goto case_37;
      }
      if ((int)c == 68) {
        goto case_37;
      }
      if ((int)c == 69) {
        goto case_37;
      }
      if ((int)c == 70) {
        goto case_37;
      }
      if ((int)c == 71) {
        goto case_37;
      }
      if ((int)c == 72) {
        goto case_37;
      }
      if ((int)c == 73) {
        goto case_37;
      }
      if ((int)c == 74) {
        goto case_37;
      }
      if ((int)c == 75) {
        goto case_37;
      }
      if ((int)c == 76) {
        goto case_37;
      }
      if ((int)c == 77) {
        goto case_37;
      }
      if ((int)c == 78) {
        goto case_37;
      }
      if ((int)c == 79) {
        goto case_37;
      }
      if ((int)c == 80) {
        goto case_37;
      }
      if ((int)c == 81) {
        goto case_37;
      }
      if ((int)c == 82) {
        goto case_37;
      }
      if ((int)c == 83) {
        goto case_37;
      }
      if ((int)c == 84) {
        goto case_37;
      }
      if ((int)c == 85) {
        goto case_37;
      }
      if ((int)c == 86) {
        goto case_37;
      }
      if ((int)c == 87) {
        goto case_37;
      }
      if ((int)c == 88) {
        goto case_37;
      }
      if ((int)c == 89) {
        goto case_37;
      }
      if ((int)c == 90) {
        goto case_37;
      }
      if ((int)c == 93) {
        goto case_37;
      }
      if ((int)c == 95) {
        goto case_37;
      }
      if ((int)c == 97) {
        goto case_37;
      }
      if ((int)c == 98) {
        goto case_37;
      }
      if ((int)c == 99) {
        goto case_37;
      }
      if ((int)c == 100) {
        goto case_37;
      }
      if ((int)c == 101) {
        goto case_37;
      }
      if ((int)c == 102) {
        goto case_37;
      }
      if ((int)c == 103) {
        goto case_37;
      }
      if ((int)c == 104) {
        goto case_37;
      }
      if ((int)c == 105) {
        goto case_37;
      }
      if ((int)c == 106) {
        goto case_37;
      }
      if ((int)c == 107) {
        goto case_37;
      }
      if ((int)c == 108) {
        goto case_37;
      }
      if ((int)c == 109) {
        goto case_37;
      }
      if ((int)c == 110) {
        goto case_37;
      }
      if ((int)c == 111) {
        goto case_37;
      }
      if ((int)c == 112) {
        goto case_37;
      }
      if ((int)c == 113) {
        goto case_37;
      }
      if ((int)c == 114) {
        goto case_37;
      }
      if ((int)c == 115) {
        goto case_37;
      }
      if ((int)c == 116) {
        goto case_37;
      }
      if ((int)c == 117) {
        goto case_37;
      }
      if ((int)c == 118) {
        goto case_37;
      }
      if ((int)c == 119) {
        goto case_37;
      }
      if ((int)c == 120) {
        goto case_37;
      }
      if ((int)c == 121) {
        goto case_37;
      }
      if ((int)c == 122) {
        goto case_37;
      }
      goto switch_default___2;
    case_0___0:
      if (backslash_escapes) {
        if (elide_outer_quotes) {
          goto force_outer_quoting_style;
        }
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)'\\';
          }
          len++;
          goto while_break___4;
        }
      while_break___4:;
        if (i + 1UL < argsize) {
          if (48 <= (int)*(arg + (i + 1UL))) {
            if ((int const) * (arg + (i + 1UL)) <= 57) {
              while (1) {

                if (len < buffersize) {
                  *(buffer + len) = (char)'0';
                }
                len++;
                goto while_break___5;
              }
            while_break___5:;
              while (1) {

                if (len < buffersize) {
                  *(buffer + len) = (char)'0';
                }
                len++;
                goto while_break___6;
              }
            while_break___6:;
            }
          }
        }
        c = (unsigned char)'0';
      } else {
        if (flags & 1) {
          goto __Cont;
        }
      }
      goto switch_break___0;
    case_63:
      if ((unsigned int)quoting_style == 2U) {
        goto case_2___0;
      }
      if ((unsigned int)quoting_style == 3U) {
        goto case_3___0;
      }
      goto switch_default___1;
    case_2___0:
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
      goto switch_break___1;
    case_3___0:
      if (flags & 4) {
        if (i + 2UL < argsize) {
          if ((int const) * (arg + (i + 1UL)) == 63) {
            if ((int const) * (arg + (i + 2UL)) == 33) {
              goto case_33;
            }
            if ((int const) * (arg + (i + 2UL)) == 39) {
              goto case_33;
            }
            if ((int const) * (arg + (i + 2UL)) == 40) {
              goto case_33;
            }
            if ((int const) * (arg + (i + 2UL)) == 41) {
              goto case_33;
            }
            if ((int const) * (arg + (i + 2UL)) == 45) {
              goto case_33;
            }
            if ((int const) * (arg + (i + 2UL)) == 47) {
              goto case_33;
            }
            if ((int const) * (arg + (i + 2UL)) == 60) {
              goto case_33;
            }
            if ((int const) * (arg + (i + 2UL)) == 61) {
              goto case_33;
            }
            if ((int const) * (arg + (i + 2UL)) == 62) {
              goto case_33;
            }
            goto switch_default___0;
          case_33:
            if (elide_outer_quotes) {
              goto force_outer_quoting_style;
            }
            c = (unsigned char)*(arg + (i + 2UL));
            i += 2UL;
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char)'?';
              }
              len++;
              goto while_break___7;
            }
          while_break___7:;
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char)'\"';
              }
              len++;
              goto while_break___8;
            }
          while_break___8:;
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char)'\"';
              }
              len++;
              goto while_break___9;
            }
          while_break___9:;
            while (1) {

              if (len < buffersize) {
                *(buffer + len) = (char)'?';
              }
              len++;
              goto while_break___10;
            }
          while_break___10:;
            goto switch_break___2;
          switch_default___0:
            goto switch_break___2;
          switch_break___2:;
          }
        }
      }
      goto switch_break___1;
    switch_default___1:
      goto switch_break___1;
    switch_break___1:;
      goto switch_break___0;
    case_7___0:
      esc = (unsigned char)'a';
      goto c_escape;
    case_8___0:
      esc = (unsigned char)'b';
      goto c_escape;
    case_12:
      esc = (unsigned char)'f';
      goto c_escape;
    case_10:
      esc = (unsigned char)'n';
      goto c_and_shell_escape;
    case_13:
      esc = (unsigned char)'r';
      goto c_and_shell_escape;
    case_9:
      esc = (unsigned char)'t';
      goto c_and_shell_escape;
    case_11:
      esc = (unsigned char)'v';
      goto c_escape;
    case_92:
      esc = c;
      if (backslash_escapes) {
        if (elide_outer_quotes) {
          if (quote_string_len) {
            goto store_c;
          }
        }
      }
    c_and_shell_escape:
      if ((unsigned int)quoting_style == 2U) {
        if (elide_outer_quotes) {
          goto force_outer_quoting_style;
        }
      }
    c_escape:
      if (backslash_escapes) {
        c = esc;
        goto store_escape;
      }
      goto switch_break___0;
    case_123:
      if (argsize == 0xffffffffffffffffUL) {
        tmp___1 = (int const) * (arg + 1) == 0;
      } else {
        tmp___1 = argsize == 1UL;
      }
      if (!tmp___1) {
        goto switch_break___0;
      }
    case_35:
      if (i != 0UL) {
        goto switch_break___0;
      }
    case_32:
      if ((unsigned int)quoting_style == 2U) {
        if (elide_outer_quotes) {
          goto force_outer_quoting_style;
        }
      }
      goto switch_break___0;
    case_39___0:
      if ((unsigned int)quoting_style == 2U) {
        if (elide_outer_quotes) {
          goto force_outer_quoting_style;
        }
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)'\'';
          }
          len++;
          goto while_break___11;
        }
      while_break___11:;
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)'\\';
          }
          len++;
          goto while_break___12;
        }
      while_break___12:;
        while (1) {

          if (len < buffersize) {
            *(buffer + len) = (char)'\'';
          }
          len++;
          goto while_break___13;
        }
      while_break___13:;
      }
      goto switch_break___0;
    case_37:
      goto switch_break___0;
    switch_default___2:
      if (unibyte_locale) {
        m = (size_t)1;
        tmp___2 = __ctype_b_loc();
        printable = (_Bool)(((int const) * (*tmp___2 + (int)c) & 16384) != 0);
      } else {
        memset((void *)(&mbstate), 0, sizeof(mbstate));
        m = (size_t)0;
        printable = (_Bool)1;
        if (argsize == 0xffffffffffffffffUL) {
          argsize = strlen(arg);
        }
        while (1) {
          tmp___3 = mbrtowc(&w, arg + (i + m), argsize - (i + m), &mbstate);
          bytes = tmp___3;
          if (bytes == 0UL) {
            goto while_break___14;
          } else {
            if (bytes == 0xffffffffffffffffUL) {
              printable = (_Bool)0;
              goto while_break___14;
            } else {
              if (bytes == 0xfffffffffffffffeUL) {
                printable = (_Bool)0;
                while (1) {

                  if (i + m < argsize) {
                    if (!*(arg + (i + m))) {
                      goto while_break___15;
                    }
                  } else {
                    goto while_break___15;
                  }
                  m++;
                }
              while_break___15:;
                goto while_break___14;
              } else {
                if (elide_outer_quotes) {
                  if ((unsigned int)quoting_style == 2U) {
                    j = (size_t)1;
                    while (1) {

                      if (!(j < bytes)) {
                        goto while_break___16;
                      }
                      if ((int const) * (arg + ((i + m) + j)) == 91) {
                        goto case_91___0;
                      }
                      if ((int const) * (arg + ((i + m) + j)) == 92) {
                        goto case_91___0;
                      }
                      if ((int const) * (arg + ((i + m) + j)) == 94) {
                        goto case_91___0;
                      }
                      if ((int const) * (arg + ((i + m) + j)) == 96) {
                        goto case_91___0;
                      }
                      if ((int const) * (arg + ((i + m) + j)) == 124) {
                        goto case_91___0;
                      }
                      goto switch_default___3;
                    case_91___0:
                      goto force_outer_quoting_style;
                    switch_default___3:
                      goto switch_break___3;
                    switch_break___3:
                      j++;
                    }
                  while_break___16:;
                  }
                }
                tmp___4 = iswprint((wint_t)w);
                if (!tmp___4) {
                  printable = (_Bool)0;
                }
                m += bytes;
              }
            }
          }
          tmp___5 = mbsinit((mbstate_t const *)(&mbstate));
          if (tmp___5) {
            goto while_break___14;
          }
        }
      while_break___14:;
      }
      if (1UL < m) {
        goto _L___0;
      } else {
        if (backslash_escapes) {
          if (!printable) {
          _L___0:
            ilim = i + m;
            while (1) {

              if (backslash_escapes) {
                if (!printable) {
                  if (elide_outer_quotes) {
                    goto force_outer_quoting_style;
                  }
                  while (1) {

                    if (len < buffersize) {
                      *(buffer + len) = (char)'\\';
                    }
                    len++;
                    goto while_break___18;
                  }
                while_break___18:;
                  while (1) {

                    if (len < buffersize) {
                      *(buffer + len) = (char)(48 + ((int)c >> 6));
                    }
                    len++;
                    goto while_break___19;
                  }
                while_break___19:;
                  while (1) {

                    if (len < buffersize) {
                      *(buffer + len) = (char)(48 + (((int)c >> 3) & 7));
                    }
                    len++;
                    goto while_break___20;
                  }
                while_break___20:
                  c = (unsigned char)(48 + ((int)c & 7));
                } else {
                  goto _L;
                }
              } else {
              _L:
                if (is_right_quote) {
                  while (1) {

                    if (len < buffersize) {
                      *(buffer + len) = (char)'\\';
                    }
                    len++;
                    goto while_break___21;
                  }
                while_break___21:
                  is_right_quote = (_Bool)0;
                }
              }
              if (ilim <= i + 1UL) {
                goto while_break___17;
              }
              while (1) {

                if (len < buffersize) {
                  *(buffer + len) = (char)c;
                }
                len++;
                goto while_break___22;
              }
            while_break___22:
              i++;
              c = (unsigned char)*(arg + i);
            }
          while_break___17:;
            goto store_c;
          }
        }
      }
    switch_break___0:;
      if (backslash_escapes) {
        goto _L___3;
      } else {
        if (elide_outer_quotes) {
        _L___3:
          if (quote_these_too) {
            if (!(*(quote_these_too + (unsigned long)c / (sizeof(int) * 8UL)) &
                  (unsigned int const)(1 << (unsigned long)c %
                                                (sizeof(int) * 8UL)))) {
              goto _L___2;
            }
          } else {
            goto _L___2;
          }
        } else {
        _L___2:
          if (!is_right_quote) {
            goto store_c;
          }
        }
      }
    store_escape:
      if (elide_outer_quotes) {
        goto force_outer_quoting_style;
      }
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)'\\';
        }
        len++;
        goto while_break___23;
      }
    while_break___23:;
    store_c:
      while (1) {

        if (len < buffersize) {
          *(buffer + len) = (char)c;
        }
        len++;
        goto while_break___24;
      }
    while_break___24:;
    __Cont:
      i++;
    }
  while_break___3:;
    if (len == 0UL) {
      if ((unsigned int)quoting_style == 2U) {
        if (elide_outer_quotes) {
          goto force_outer_quoting_style;
        }
      }
    }
    if (quote_string) {
      if (!elide_outer_quotes) {
        while (1) {

          if (!*quote_string) {
            goto while_break___25;
          }
          while (1) {

            if (len < buffersize) {
              *(buffer + len) = (char)*quote_string;
            }
            len++;
            goto while_break___26;
          }
        while_break___26:
          quote_string++;
        }
      while_break___25:;
      }
    }
    if (len < buffersize) {
      *(buffer + len) = (char)'\000';
    }
    return (len);
  force_outer_quoting_style:
    tmp___7 = quotearg_buffer_restyled(
        buffer, buffersize, arg, argsize, quoting_style, flags & -3,
        (unsigned int const *)((void *)0), left_quote, right_quote);
    return (tmp___7);
  }
}
static char slot0[256];
static unsigned int nslots = 1U;
