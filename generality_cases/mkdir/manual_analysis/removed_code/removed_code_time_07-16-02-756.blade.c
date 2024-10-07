

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
