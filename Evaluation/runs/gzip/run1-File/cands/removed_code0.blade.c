

if (remove_ofname) {
  {
    close(ofd);
    unlink((char const *)(ofname));
  }
}
{ do_exit(1); }
return;
