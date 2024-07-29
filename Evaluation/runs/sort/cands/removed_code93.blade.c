

sortlines((struct line *)args->lines, (size_t)args->nthreads,
          (size_t)args->total_lines, (struct merge_node *)args->node,
          (struct merge_node_queue *)args->queue, (FILE *)args->tfp,
          (char const *)args->output_temp);
