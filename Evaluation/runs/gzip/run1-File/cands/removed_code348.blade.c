

static void fillbuf(int n) {
  unsigned int tmp;
  int tmp___0;
  int tmp___1;

  {
    bitbuf = (ush)((int)bitbuf << n);
    {
      while (1) {
      while_continue: /* CIL Label */
                      ;
        if (!(n > bitcount)) {
          goto while_break;
        }
        n -= bitcount;
        bitbuf = (ush)((unsigned int)bitbuf | (subbitbuf << n));
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
        subbitbuf = (unsigned int)tmp___1;
        if ((int)subbitbuf == -1) {
          subbitbuf = 0U;
        }
        bitcount = 8;
      }
    while_break: /* CIL Label */
                 ;
    }
    bitcount -= n;
    bitbuf = (ush)((unsigned int)bitbuf | (subbitbuf >> bitcount));
    return;
  }
}
static unsigned int getbits(int n) {
  unsigned int x;

  {
    {
      x = (unsigned int)((int)bitbuf >>
                         (16UL * sizeof(char) - (unsigned long)n));
      fillbuf(n);
    }
    return (x);
  }
}
static void init_getbits(void) {

  {
    {
      bitbuf = (ush)0;
      subbitbuf = 0U;
      bitcount = 0;
      fillbuf((int)(16UL * sizeof(char)));
    }
    return;
  }
}
