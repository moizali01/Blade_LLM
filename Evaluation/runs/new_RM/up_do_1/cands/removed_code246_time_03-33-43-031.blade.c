

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
