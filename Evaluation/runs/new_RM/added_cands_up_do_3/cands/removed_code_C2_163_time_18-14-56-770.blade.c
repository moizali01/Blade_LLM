

void *hash_lookup(Hash_table const *table___0, void const *entry) {
  struct hash_entry const *bucket;
  size_t tmp;
  struct hash_entry const *cursor;
  _Bool tmp___0;

  {
    tmp = (*(table___0->hasher))(entry, (size_t)table___0->n_buckets);
    bucket = (struct hash_entry const *)(table___0->bucket + tmp);
    if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
      abort();
    }
    if ((unsigned long)bucket->data == (unsigned long)((void *)0)) {
      return ((void *)0);
    }
    cursor = bucket;
    while (1) {

      if (!cursor) {
        goto while_break;
      }
      if ((unsigned long)entry == (unsigned long)cursor->data) {
        return ((void *)cursor->data);
      } else {
        tmp___0 = (*(table___0->comparator))(entry, (void const *)cursor->data);
        if (tmp___0) {
          return ((void *)cursor->data);
        }
      }
      cursor = (struct hash_entry const *)cursor->next;
    }
  while_break:;
    return ((void *)0);
  }
}
size_t hash_string(char const *string, size_t n_buckets) {
  size_t value;
  unsigned char ch;

  {
    value = (size_t)0;
    while (1) {
      ch = (unsigned char)*string;
      if (!ch) {
        goto while_break;
      }
      value = (value * 31UL + (size_t)ch) % n_buckets;
      string++;
    }
  while_break:;
    return (value);
  }
}
static _Bool is_prime(size_t candidate) {
  size_t divisor;
  size_t square;
  int tmp;

  {
    divisor = (size_t)3;
    square = divisor * divisor;
    while (1) {

      if (square < candidate) {
        if (!(candidate % divisor)) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      divisor++;
      square += 4UL * divisor;
      divisor++;
    }
  while_break:;
    if (candidate % divisor) {
      tmp = 1;
    } else {
      tmp = 0;
    }
    return ((_Bool)tmp);
  }
}
