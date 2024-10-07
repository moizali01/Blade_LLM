

while (1) {
  ;

  if (argsize == 0xffffffffffffffffUL) {
    tmp___7 = (int const) * (arg + i) == 0;
  } else {
    tmp___7 = i == argsize;
  }
  if (tmp___7) {
    goto while_break___3;
  }
  if (backslash_escapes) {
    if (quote_string_len) {
      if (i + quote_string_len <= argsize) {
        {
          tmp___2 = memcmp((void const *)(arg + i), (void const *)quote_string,
                           quote_string_len);
        }
        if (tmp___2 == 0) {
          {
            while (1) {
              ;

              if (len < buffersize) {
                *(buffer + len) = (char)'\\';
              }
              len++;
              goto while_break___4;
            };
          }
        while_break___4:;
        }
      }
    }
  }
  c = (unsigned char)*(arg + i);
  if ((int)c == 0) {
    goto case_0;
  }
  if ((int)c == 63) {
    goto case_63;
  }
  if ((int)c == 7) {
    goto case_7;
  }
  if ((int)c == 8) {
    goto case_8;
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
  if ((int)c == 126) {
    goto case_126;
  }
  if ((int)c == 35) {
    goto case_126;
  }
  if ((int)c == 124) {
    goto case_124;
  }
  if ((int)c == 96) {
    goto case_124;
  }
  if ((int)c == 94) {
    goto case_124;
  }
  if ((int)c == 91) {
    goto case_124;
  }
  if ((int)c == 62) {
    goto case_124;
  }
  if ((int)c == 60) {
    goto case_124;
  }
  if ((int)c == 59) {
    goto case_124;
  }
  if ((int)c == 42) {
    goto case_124;
  }
  if ((int)c == 41) {
    goto case_124;
  }
  if ((int)c == 40) {
    goto case_124;
  }
  if ((int)c == 38) {
    goto case_124;
  }
  if ((int)c == 36) {
    goto case_124;
  }
  if ((int)c == 34) {
    goto case_124;
  }
  if ((int)c == 33) {
    goto case_124;
  }
  if ((int)c == 32) {
    goto case_124;
  }
  if ((int)c == 39) {
    goto case_39___0;
  }
  if ((int)c == 125) {
    goto case_125;
  }
  if ((int)c == 123) {
    goto case_125;
  }
  if ((int)c == 122) {
    goto case_125;
  }
  if ((int)c == 121) {
    goto case_125;
  }
  if ((int)c == 120) {
    goto case_125;
  }
  if ((int)c == 119) {
    goto case_125;
  }
  if ((int)c == 118) {
    goto case_125;
  }
  if ((int)c == 117) {
    goto case_125;
  }
  if ((int)c == 116) {
    goto case_125;
  }
  if ((int)c == 115) {
    goto case_125;
  }
  if ((int)c == 114) {
    goto case_125;
  }
  if ((int)c == 113) {
    goto case_125;
  }
  if ((int)c == 112) {
    goto case_125;
  }
  if ((int)c == 111) {
    goto case_125;
  }
  if ((int)c == 110) {
    goto case_125;
  }
  if ((int)c == 109) {
    goto case_125;
  }
  if ((int)c == 108) {
    goto case_125;
  }
  if ((int)c == 107) {
    goto case_125;
  }
  if ((int)c == 106) {
    goto case_125;
  }
  if ((int)c == 105) {
    goto case_125;
  }
  if ((int)c == 104) {
    goto case_125;
  }
  if ((int)c == 103) {
    goto case_125;
  }
  if ((int)c == 102) {
    goto case_125;
  }
  if ((int)c == 101) {
    goto case_125;
  }
  if ((int)c == 100) {
    goto case_125;
  }
  if ((int)c == 99) {
    goto case_125;
  }
  if ((int)c == 98) {
    goto case_125;
  }
  if ((int)c == 97) {
    goto case_125;
  }
  if ((int)c == 95) {
    goto case_125;
  }
  if ((int)c == 93) {
    goto case_125;
  }
  if ((int)c == 90) {
    goto case_125;
  }
  if ((int)c == 89) {
    goto case_125;
  }
  if ((int)c == 88) {
    goto case_125;
  }
  if ((int)c == 87) {
    goto case_125;
  }
  if ((int)c == 86) {
    goto case_125;
  }
  if ((int)c == 85) {
    goto case_125;
  }
  if ((int)c == 84) {
    goto case_125;
  }
  if ((int)c == 83) {
    goto case_125;
  }
  if ((int)c == 82) {
    goto case_125;
  }
  if ((int)c == 81) {
    goto case_125;
  }
  if ((int)c == 80) {
    goto case_125;
  }
  if ((int)c == 79) {
    goto case_125;
  }
  if ((int)c == 78) {
    goto case_125;
  }
  if ((int)c == 77) {
    goto case_125;
  }
  if ((int)c == 76) {
    goto case_125;
  }
  if ((int)c == 75) {
    goto case_125;
  }
  if ((int)c == 74) {
    goto case_125;
  }
  if ((int)c == 73) {
    goto case_125;
  }
  if ((int)c == 72) {
    goto case_125;
  }
  if ((int)c == 71) {
    goto case_125;
  }
  if ((int)c == 70) {
    goto case_125;
  }
  if ((int)c == 69) {
    goto case_125;
  }
  if ((int)c == 68) {
    goto case_125;
  }
  if ((int)c == 67) {
    goto case_125;
  }
  if ((int)c == 66) {
    goto case_125;
  }
  if ((int)c == 65) {
    goto case_125;
  }
  if ((int)c == 61) {
    goto case_125;
  }
  if ((int)c == 58) {
    goto case_125;
  }
  if ((int)c == 57) {
    goto case_125;
  }
  if ((int)c == 56) {
    goto case_125;
  }
  if ((int)c == 55) {
    goto case_125;
  }
  if ((int)c == 54) {
    goto case_125;
  }
  if ((int)c == 53) {
    goto case_125;
  }
  if ((int)c == 52) {
    goto case_125;
  }
  if ((int)c == 51) {
    goto case_125;
  }
  if ((int)c == 50) {
    goto case_125;
  }
  if ((int)c == 49) {
    goto case_125;
  }
  if ((int)c == 48) {
    goto case_125;
  }
  if ((int)c == 47) {
    goto case_125;
  }
  if ((int)c == 46) {
    goto case_125;
  }
  if ((int)c == 45) {
    goto case_125;
  }
  if ((int)c == 44) {
    goto case_125;
  }
  if ((int)c == 43) {
    goto case_125;
  }
  if ((int)c == 37) {
    goto case_125;
  }
  goto switch_default___2;
case_0:
  if (backslash_escapes) {
    {
      while (1) {
        ;

        if (len < buffersize) {
          *(buffer + len) = (char)'\\';
        }
        len++;
        goto while_break___5;
      };
    }
  while_break___5:;
    {
      while (1) {
        ;

        if (len < buffersize) {
          *(buffer + len) = (char)'0';
        }
        len++;
        goto while_break___6;
      };
    }
  while_break___6:;
    {
      while (1) {
        ;

        if (len < buffersize) {
          *(buffer + len) = (char)'0';
        }
        len++;
        goto while_break___7;
      };
    }
  while_break___7:
    c = (unsigned char)'0';
  }
  goto switch_break___0;
case_63:
  if ((unsigned int)quoting_style == 1U) {
    goto case_1;
  }
  if ((unsigned int)quoting_style == 3U) {
    goto case_3___0;
  }
  goto switch_default___0;
case_1:
  goto use_shell_always_quoting_style;
case_3___0:
  if (i + 2UL < argsize) {
    if ((int const) * (arg + (i + 1UL)) == 63) {
      if ((int const) * (arg + (i + 2UL)) == 62) {
        goto case_62;
      }
      if ((int const) * (arg + (i + 2UL)) == 61) {
        goto case_62;
      }
      if ((int const) * (arg + (i + 2UL)) == 60) {
        goto case_62;
      }
      if ((int const) * (arg + (i + 2UL)) == 47) {
        goto case_62;
      }
      if ((int const) * (arg + (i + 2UL)) == 45) {
        goto case_62;
      }
      if ((int const) * (arg + (i + 2UL)) == 41) {
        goto case_62;
      }
      if ((int const) * (arg + (i + 2UL)) == 40) {
        goto case_62;
      }
      if ((int const) * (arg + (i + 2UL)) == 39) {
        goto case_62;
      }
      if ((int const) * (arg + (i + 2UL)) == 33) {
        goto case_62;
      }
      goto switch_break___2;
    case_62:
      c = (unsigned char)*(arg + (i + 2UL));
      i += 2UL;
      {
        while (1) {
          ;

          if (len < buffersize) {
            *(buffer + len) = (char)'?';
          }
          len++;
          goto while_break___8;
        };
      }
    while_break___8:;
      {
        while (1) {
          ;

          if (len < buffersize) {
            *(buffer + len) = (char)'\\';
          }
          len++;
          goto while_break___9;
        };
      }
    while_break___9:;
      {
        while (1) {
          ;

          if (len < buffersize) {
            *(buffer + len) = (char)'?';
          }
          len++;
          goto while_break___10;
        };
      }
    while_break___10:;
      goto switch_break___2;
    switch_break___2:;
    }
  }
  goto switch_break___1;
switch_default___0:
  goto switch_break___1;
switch_break___1:;
  goto switch_break___0;
case_7:
  esc = (unsigned char)'a';
  goto c_escape;
case_8:
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
  goto c_and_shell_escape;
c_and_shell_escape:
  if ((unsigned int)quoting_style == 1U) {
    goto use_shell_always_quoting_style;
  }
c_escape:
  if (backslash_escapes) {
    c = esc;
    goto store_escape;
  }
  goto switch_break___0;
case_126:
  if (i != 0UL) {
    goto switch_break___0;
  }
case_124:
  if ((unsigned int)quoting_style == 1U) {
    goto use_shell_always_quoting_style;
  }
  goto switch_break___0;
case_39___0:
  if ((unsigned int)quoting_style == 1U) {
    goto case_1___0;
  }
  if ((unsigned int)quoting_style == 2U) {
    goto case_2___0;
  }
  goto switch_default___1;
case_1___0:
  goto use_shell_always_quoting_style;
case_2___0: {
  while (1) {
    ;

    if (len < buffersize) {
      *(buffer + len) = (char)'\'';
    }
    len++;
    goto while_break___11;
  };
}
while_break___11:;
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)'\\';
      }
      len++;
      goto while_break___12;
    };
  }
while_break___12:;
  {
    while (1) {
      ;

      if (len < buffersize) {
        *(buffer + len) = (char)'\'';
      }
      len++;
      goto while_break___13;
    };
  }
while_break___13:;
  goto switch_break___3;
switch_default___1:
  goto switch_break___3;
switch_break___3:;
  goto switch_break___0;
case_125:
  goto switch_break___0;
switch_default___2:
  if (unibyte_locale) {
    {
      m = (size_t)1;
      tmp___3 = __ctype_b_loc();
      printable = (int)((int const) * (*tmp___3 + (int)c) & 16384);
    }
  } else {
    {
      memset((void *)(&mbstate), 0, sizeof(mbstate));
      m = (size_t)0;
      printable = 1;
    }
    if (argsize == 0xffffffffffffffffUL) {
      {
        argsize = strlen(arg);
      }
    }
    {
      while (1) {
        ;
        {
          tmp___4 = mbrtowc((wchar_t * /* __restrict  */)(&w),
                            (char const * /* __restrict  */)(arg + (i + m)),
                            argsize - (i + m),
                            (mbstate_t * /* __restrict  */)(&mbstate));
          bytes = tmp___4;
        }
        if (bytes == 0UL) {
          goto while_break___14;
        } else {
          if (bytes == 0xffffffffffffffffUL) {
            printable = 0;
            goto while_break___14;
          } else {
            if (bytes == 0xfffffffffffffffeUL) {
              printable = 0;
              {
                while (1) {
                  ;

                  if (i + m < argsize) {
                    if (!*(arg + (i + m))) {
                      goto while_break___15;
                    }
                  } else {
                    goto while_break___15;
                  }
                  m++;
                };
              }
            while_break___15:;
              goto while_break___14;
            } else {
              { tmp___5 = iswprint((wint_t)w); }
              if (!tmp___5) {
                printable = 0;
              }
              m += bytes;
            }
          }
        }
        { tmp___6 = mbsinit((mbstate_t const *)(&mbstate)); }
        if (tmp___6) {
          goto while_break___14;
        }
      };
    }
  while_break___14:;
  }
  if (1UL < m) {
    goto _L;
  } else {
    if (backslash_escapes) {
      if (!printable) {
      _L:
        ilim = i + m;
        {
          while (1) {
            ;

            if (backslash_escapes) {
              if (!printable) {
                {
                  while (1) {
                    ;

                    if (len < buffersize) {
                      *(buffer + len) = (char)'\\';
                    }
                    len++;
                    goto while_break___17;
                  };
                }
              while_break___17:;
                {
                  while (1) {
                    ;

                    if (len < buffersize) {
                      *(buffer + len) = (char)(48 + ((int)c >> 6));
                    }
                    len++;
                    goto while_break___18;
                  };
                }
              while_break___18:;
                {
                  while (1) {
                    ;

                    if (len < buffersize) {
                      *(buffer + len) = (char)(48 + (((int)c >> 3) & 7));
                    }
                    len++;
                    goto while_break___19;
                  };
                }
              while_break___19:
                c = (unsigned char)(48 + ((int)c & 7));
              }
            }
            if (ilim <= i + 1UL) {
              goto while_break___16;
            }
            {
              while (1) {
                ;

                if (len < buffersize) {
                  *(buffer + len) = (char)c;
                }
                len++;
                goto while_break___20;
              };
            }
          while_break___20:
            i++;
            c = (unsigned char)*(arg + i);
          };
        }
      while_break___16:;
        goto store_c;
      }
    }
  }
switch_break___0:;
  if (backslash_escapes) {
    if (!(o->quote_these_too[(unsigned long)c / (sizeof(int) * 8UL)] &
          (1 << (unsigned long)c % (sizeof(int) * 8UL)))) {
      goto store_c;
    }
  } else {
    goto store_c;
  }
store_escape: {
  while (1) {
    ;

    if (len < buffersize) {
      *(buffer + len) = (char)'\\';
    }
    len++;
    goto while_break___21;
  };
}
while_break___21:;
store_c: {
  while (1) {
    ;

    if (len < buffersize) {
      *(buffer + len) = (char)c;
    }
    len++;
    goto while_break___22;
  };
}
while_break___22:
  i++;
};
