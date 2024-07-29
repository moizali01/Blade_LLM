

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
static size_t next_prime(size_t candidate) {
  _Bool tmp;

  {
    if (candidate < 10UL) {
      candidate = (size_t)10;
    }
    candidate |= 1UL;
    while (1) {

      if (0xffffffffffffffffUL != candidate) {
        tmp = is_prime(candidate);
        if (tmp) {
          goto while_break;
        }
      } else {
        goto while_break;
      }
      candidate += 2UL;
    }
  while_break:;
    return (candidate);
  }
}
static size_t raw_hasher(void const *data, size_t n) {
  size_t val;
  size_t tmp;

  {
    tmp = rotr_sz((size_t)data, 3);
    val = tmp;
    return (val % n);
  }
}
static _Bool raw_comparator(void const *a, void const *b) {

  { return ((_Bool)((unsigned long)a == (unsigned long)b)); }
}
static _Bool check_tuning(Hash_table *table___0) {
  Hash_tuning const *tuning;
  float epsilon;

  {
    tuning = table___0->tuning;
    if ((unsigned long)tuning == (unsigned long)(&default_tuning)) {
      return ((_Bool)1);
    }
    epsilon = 0.1f;
    if (epsilon < (float)tuning->growth_threshold) {
      if (tuning->growth_threshold < (float const)((float)1 - epsilon)) {
        if ((float)1 + epsilon < (float)tuning->growth_factor) {
          if ((float const)0 <= tuning->shrink_threshold) {
            if (tuning->shrink_threshold + (float const)epsilon <
                tuning->shrink_factor) {
              if (tuning->shrink_factor <= (float const)1) {
                if (tuning->shrink_threshold + (float const)epsilon <
                    tuning->growth_threshold) {
                  return ((_Bool)1);
                }
              }
            }
          }
        }
      }
    }
    table___0->tuning = &default_tuning;
    return ((_Bool)0);
  }
}
static size_t compute_bucket_size(size_t candidate, Hash_tuning const *tuning) {
  float new_candidate;
  int tmp;

  {
    if (!tuning->is_n_buckets) {
      new_candidate =
          (float)((float const)candidate / tuning->growth_threshold);
      if ((float)0xffffffffffffffffUL <= new_candidate) {
        return ((size_t)0);
      }
      candidate = (size_t)new_candidate;
    }
    candidate = next_prime(candidate);
    if (sizeof(ptrdiff_t) <= sizeof(size_t)) {
      tmp = -1;
    } else {
      tmp = -2;
    }
    if ((size_t)tmp / sizeof(struct hash_entry *) < candidate) {
      return ((size_t)0);
    }
    return (candidate);
  }
}
Hash_table *(__attribute__((__warn_unused_result__))
             hash_initialize)(size_t candidate, Hash_tuning const *tuning,
                              size_t (*hasher)(void const *, size_t),
                              _Bool (*comparator)(void const *, void const *),
                              void (*data_freer)(void *)) {
  Hash_table *table___0;
  _Bool tmp;

  {
    if ((unsigned long)hasher == (unsigned long)((void *)0)) {
      hasher = &raw_hasher;
    }
    if ((unsigned long)comparator == (unsigned long)((void *)0)) {
      comparator = &raw_comparator;
    }
    table___0 = (Hash_table *)malloc(sizeof(*table___0));
    if ((unsigned long)table___0 == (unsigned long)((void *)0)) {
      return ((Hash_table *)((void *)0));
    }
    if (!tuning) {
      tuning = &default_tuning;
    }
    table___0->tuning = tuning;
    tmp = check_tuning(table___0);
    if (!tmp) {
      goto fail;
    }
    table___0->n_buckets = compute_bucket_size(candidate, tuning);
    if (!table___0->n_buckets) {
      goto fail;
    }
    table___0->bucket = (struct hash_entry *)calloc(
        table___0->n_buckets, sizeof(*(table___0->bucket)));
    if ((unsigned long)table___0->bucket == (unsigned long)((void *)0)) {
      goto fail;
    }
    table___0->bucket_limit =
        (struct hash_entry const *)(table___0->bucket + table___0->n_buckets);
    table___0->n_buckets_used = (size_t)0;
    table___0->n_entries = (size_t)0;
    table___0->hasher = hasher;
    table___0->comparator = comparator;
    table___0->data_freer = data_freer;
    table___0->free_entry_list = (struct hash_entry *)((void *)0);
    return (table___0);
  fail:
    free((void *)table___0);
    return ((Hash_table *)((void *)0));
  }
}
void hash_free(Hash_table *table___0) {
  struct hash_entry *bucket;
  struct hash_entry *cursor;
  struct hash_entry *next;

  {
    if (table___0->data_freer) {
      if (table___0->n_entries) {
        bucket = table___0->bucket;
        while (1) {

          if (!((unsigned long)bucket <
                (unsigned long)table___0->bucket_limit)) {
            goto while_break;
          }
          if (bucket->data) {
            cursor = bucket;
            while (1) {

              if (!cursor) {
                goto while_break___0;
              }
              (*(table___0->data_freer))(cursor->data);
              cursor = cursor->next;
            }
          while_break___0:;
          }
          bucket++;
        }
      while_break:;
      }
    }
    bucket = table___0->bucket;
    while (1) {

      if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
        goto while_break___1;
      }
      cursor = bucket->next;
      while (1) {

        if (!cursor) {
          goto while_break___2;
        }
        next = cursor->next;
        free((void *)cursor);
        cursor = next;
      }
    while_break___2:
      bucket++;
    }
  while_break___1:
    cursor = table___0->free_entry_list;
    while (1) {

      if (!cursor) {
        goto while_break___3;
      }
      next = cursor->next;
      free((void *)cursor);
      cursor = next;
    }
  while_break___3:
    free((void *)table___0->bucket);
    free((void *)table___0);
    return;
  }
}
static struct hash_entry *allocate_entry(Hash_table *table___0) {
  struct hash_entry *new;

  {
    if (table___0->free_entry_list) {
      new = table___0->free_entry_list;
      table___0->free_entry_list = new->next;
    } else {
      new = (struct hash_entry *)malloc(sizeof(*new));
    }
    return (new);
  }
}
static void free_entry(Hash_table *table___0, struct hash_entry *entry) {

  {
    entry->data = (void *)0;
    entry->next = table___0->free_entry_list;
    table___0->free_entry_list = entry;
    return;
  }
}
static void *hash_find_entry(Hash_table *table___0, void const *entry,
                             struct hash_entry **bucket_head, _Bool delete) {
  struct hash_entry *bucket;
  size_t tmp;
  struct hash_entry *cursor;
  void *data;
  struct hash_entry *next;
  _Bool tmp___0;
  void *data___0;
  struct hash_entry *next___0;
  _Bool tmp___1;

  {
    tmp = (*(table___0->hasher))(entry, table___0->n_buckets);
    bucket = table___0->bucket + tmp;
    if (!((unsigned long)bucket < (unsigned long)table___0->bucket_limit)) {
      abort();
    }
    *bucket_head = bucket;
    if ((unsigned long)bucket->data == (unsigned long)((void *)0)) {
      return ((void *)0);
    }
    if ((unsigned long)entry == (unsigned long)bucket->data) {
      goto _L;
    } else {
      tmp___0 = (*(table___0->comparator))(entry, (void const *)bucket->data);
      if (tmp___0) {
      _L:
        data = bucket->data;
        if (delete) {
          if (bucket->next) {
            next = bucket->next;
            *bucket = *next;
            free_entry(table___0, next);
          } else {
            bucket->data = (void *)0;
          }
        }
        return (data);
      }
    }
    cursor = bucket;
    while (1) {

      if (!cursor->next) {
        goto while_break;
      }
      if ((unsigned long)entry == (unsigned long)(cursor->next)->data) {
        goto _L___0;
      } else {
        tmp___1 = (*(table___0->comparator))(
            entry, (void const *)(cursor->next)->data);
        if (tmp___1) {
        _L___0:
          data___0 = (cursor->next)->data;
          if (delete) {
            next___0 = cursor->next;
            cursor->next = next___0->next;
            free_entry(table___0, next___0);
          }
          return (data___0);
        }
      }
      cursor = cursor->next;
    }
  while_break:;
    return ((void *)0);
  }
}
static _Bool transfer_entries(Hash_table *dst, Hash_table *src, _Bool safe) {
  struct hash_entry *bucket;
  struct hash_entry *cursor;
  struct hash_entry *next;
  void *data;
  struct hash_entry *new_bucket;
  size_t tmp;
  size_t tmp___0;
  struct hash_entry *new_entry;
  struct hash_entry *tmp___1;

  {
    bucket = src->bucket;
    while (1) {

      if (!((unsigned long)bucket < (unsigned long)src->bucket_limit)) {
        goto while_break;
      }
      if (bucket->data) {
        cursor = bucket->next;
        while (1) {

          if (!cursor) {
            goto while_break___0;
          }
          data = cursor->data;
          tmp = (*(dst->hasher))((void const *)data, dst->n_buckets);
          new_bucket = dst->bucket + tmp;
          if (!((unsigned long)new_bucket < (unsigned long)dst->bucket_limit)) {
            abort();
          }
          next = cursor->next;
          if (new_bucket->data) {
            cursor->next = new_bucket->next;
            new_bucket->next = cursor;
          } else {
            new_bucket->data = data;
            (dst->n_buckets_used)++;
            free_entry(dst, cursor);
          }
          cursor = next;
        }
      while_break___0:
        data = bucket->data;
        bucket->next = (struct hash_entry *)((void *)0);
        if (safe) {
          goto __Cont;
        }
        tmp___0 = (*(dst->hasher))((void const *)data, dst->n_buckets);
        new_bucket = dst->bucket + tmp___0;
        if (!((unsigned long)new_bucket < (unsigned long)dst->bucket_limit)) {
          abort();
        }
        if (new_bucket->data) {
          tmp___1 = allocate_entry(dst);
          new_entry = tmp___1;
          if ((unsigned long)new_entry == (unsigned long)((void *)0)) {
            return ((_Bool)0);
          }
          new_entry->data = data;
          new_entry->next = new_bucket->next;
          new_bucket->next = new_entry;
        } else {
          new_bucket->data = data;
          (dst->n_buckets_used)++;
        }
        bucket->data = (void *)0;
        (src->n_buckets_used)--;
      }
    __Cont:
      bucket++;
    }
  while_break:;
    return ((_Bool)1);
  }
}
_Bool(__attribute__((__warn_unused_result__))
      hash_rehash)(Hash_table *table___0, size_t candidate) {
  Hash_table storage;
  Hash_table *new_table;
  size_t new_size;
  size_t tmp;
  _Bool tmp___0;
  _Bool tmp___1;
  _Bool tmp___2;

  {
    tmp = compute_bucket_size(candidate, table___0->tuning);
    new_size = tmp;
    if (!new_size) {
      return ((_Bool)0);
    }
    if (new_size == table___0->n_buckets) {
      return ((_Bool)1);
    }
    new_table = &storage;
    new_table->bucket =
        (struct hash_entry *)calloc(new_size, sizeof(*(new_table->bucket)));
    if ((unsigned long)new_table->bucket == (unsigned long)((void *)0)) {
      return ((_Bool)0);
    }
    new_table->n_buckets = new_size;
    new_table->bucket_limit =
        (struct hash_entry const *)(new_table->bucket + new_size);
    new_table->n_buckets_used = (size_t)0;
    new_table->n_entries = (size_t)0;
    new_table->tuning = table___0->tuning;
    new_table->hasher = table___0->hasher;
    new_table->comparator = table___0->comparator;
    new_table->data_freer = table___0->data_freer;
    new_table->free_entry_list = table___0->free_entry_list;
    tmp___0 = transfer_entries(new_table, table___0, (_Bool)0);
    if (tmp___0) {
      free((void *)table___0->bucket);
      table___0->bucket = new_table->bucket;
      table___0->bucket_limit = new_table->bucket_limit;
      table___0->n_buckets = new_table->n_buckets;
      table___0->n_buckets_used = new_table->n_buckets_used;
      table___0->free_entry_list = new_table->free_entry_list;
      return ((_Bool)1);
    }
    table___0->free_entry_list = new_table->free_entry_list;
    tmp___1 = transfer_entries(table___0, new_table, (_Bool)1);
    if (tmp___1) {
      tmp___2 = transfer_entries(table___0, new_table, (_Bool)0);
      if (!tmp___2) {
        abort();
      }
    } else {
      abort();
    }
    free((void *)new_table->bucket);
    return ((_Bool)0);
  }
}
void *(__attribute__((__warn_unused_result__))
       hash_insert)(Hash_table *table___0, void const *entry) {
  void *data;
  struct hash_entry *bucket;
  Hash_tuning const *tuning;
  float candidate;
  float tmp;
  _Bool tmp___0;
  void *tmp___1;
  struct hash_entry *new_entry;
  struct hash_entry *tmp___2;

  {
    if (!entry) {
      abort();
    }
    data = hash_find_entry(table___0, entry, &bucket, (_Bool)0);
    if ((unsigned long)data != (unsigned long)((void *)0)) {
      return (data);
    }
    if ((float const)table___0->n_buckets_used >
        (table___0->tuning)->growth_threshold *
            (float const)table___0->n_buckets) {
      check_tuning(table___0);
      if ((float const)table___0->n_buckets_used >
          (table___0->tuning)->growth_threshold *
              (float const)table___0->n_buckets) {
        tuning = table___0->tuning;
        if (tuning->is_n_buckets) {
          tmp = (float)((float const)table___0->n_buckets *
                        tuning->growth_factor);
        } else {
          tmp = (float)(((float const)table___0->n_buckets *
                         tuning->growth_factor) *
                        tuning->growth_threshold);
        }
        candidate = tmp;
        if ((float)0xffffffffffffffffUL <= candidate) {
          return ((void *)0);
        }
        tmp___0 = hash_rehash(table___0, (size_t)candidate);
        if (!tmp___0) {
          return ((void *)0);
        }
        tmp___1 = hash_find_entry(table___0, entry, &bucket, (_Bool)0);
        if ((unsigned long)tmp___1 != (unsigned long)((void *)0)) {
          abort();
        }
      }
    }
    if (bucket->data) {
      tmp___2 = allocate_entry(table___0);
      new_entry = tmp___2;
      if ((unsigned long)new_entry == (unsigned long)((void *)0)) {
        return ((void *)0);
      }
      new_entry->data = (void *)entry;
      new_entry->next = bucket->next;
      bucket->next = new_entry;
      (table___0->n_entries)++;
      return ((void *)entry);
    }
    bucket->data = (void *)entry;
    (table___0->n_entries)++;
    (table___0->n_buckets_used)++;
    return ((void *)entry);
  }
}
void *hash_delete(Hash_table *table___0, void const *entry) {
  void *data;
  struct hash_entry *bucket;
  Hash_tuning const *tuning;
  size_t candidate;
  float tmp;
  struct hash_entry *cursor;
  struct hash_entry *next;
  _Bool tmp___0;

  {
    data = hash_find_entry(table___0, entry, &bucket, (_Bool)1);
    if (!data) {
      return ((void *)0);
    }
    (table___0->n_entries)--;
    if (!bucket->data) {
      (table___0->n_buckets_used)--;
      if ((float const)table___0->n_buckets_used <
          (table___0->tuning)->shrink_threshold *
              (float const)table___0->n_buckets) {
        check_tuning(table___0);
        if ((float const)table___0->n_buckets_used <
            (table___0->tuning)->shrink_threshold *
                (float const)table___0->n_buckets) {
          tuning = table___0->tuning;
          if (tuning->is_n_buckets) {
            tmp = (float)((float const)table___0->n_buckets *
                          tuning->shrink_factor);
          } else {
            tmp = (float)(((float const)table___0->n_buckets *
                           tuning->shrink_factor) *
                          tuning->growth_threshold);
          }
          candidate = (size_t)tmp;
          tmp___0 = hash_rehash(table___0, candidate);
          if (!tmp___0) {
            cursor = table___0->free_entry_list;
            while (1) {

              if (!cursor) {
                goto while_break;
              }
              next = cursor->next;
              free((void *)cursor);
              cursor = next;
            }
          while_break:
            table___0->free_entry_list = (struct hash_entry *)((void *)0);
          }
        }
      }
    }
    return (data);
  }
}
size_t hash_pjw(void const *x, size_t tablesize);
