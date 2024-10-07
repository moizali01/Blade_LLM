

static table const relative_time_table[20] = {
    {"TOMORROW", 261, 1}, {"YESTERDAY", 261, -1}, {"TODAY", 261, 0},
    {"NOW", 261, 0},      {"LAST", 273, -1},      {"THIS", 273, 0},
    {"NEXT", 273, 1},     {"FIRST", 273, 1},      {"THIRD", 273, 3},
    {"FOURTH", 273, 4},   {"FIFTH", 273, 5},      {"SIXTH", 273, 6},
    {"SEVENTH", 273, 7},  {"EIGHTH", 273, 8},     {"NINTH", 273, 9},
    {"TENTH", 273, 10},   {"ELEVENTH", 273, 11},  {"TWELFTH", 273, 12},
    {"AGO", 258, 1},      {(char const *)0, 0, 0}};
