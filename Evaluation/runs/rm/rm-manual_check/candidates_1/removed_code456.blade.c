

static char const *gettext_quote(char const *msgid, enum quoting_style s) {
  char const *translation;
  char const *tmp;

  {
    tmp = (char const *)gettext(msgid);
    translation = tmp;
    if ((unsigned long)translation == (unsigned long)msgid) {
      if ((unsigned int)s == 7U) {
        translation = "\"";
      }
    }
    return (translation);
  }
}
