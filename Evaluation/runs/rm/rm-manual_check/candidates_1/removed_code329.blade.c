

static _Bool LCO_compare(void const *x, void const *y) {
  struct LCO_ent const *ax;
  struct LCO_ent const *ay;

  {
    ax = (struct LCO_ent const *)x;
    ay = (struct LCO_ent const *)y;
    return ((_Bool)(ax->st_dev == ay->st_dev));
  }
}
