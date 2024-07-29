

tmp.st_dev = (dev_t)p->fts_statp[0].st_dev;
ent =
    (struct LCO_ent *)hash_lookup((Hash_table const *)h, (void const *)(&tmp));
