#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

struct graph_t {
  int *v_adj_list;
  int *v_adj_begin;
  int *v_adj_length;
  int num_vertices;
  int num_edges;
};

graph_t *read_graph(string filename, int my_rank);