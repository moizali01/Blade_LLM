

a = (struct F_triple *)x;
free((void *)a->name);
free((void *)a);
