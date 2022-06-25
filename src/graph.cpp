#include "../header/graph.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

graph_t *read_graph(string filename, int my_rank) {
  ifstream infile(filename);
  if (!infile.is_open() && my_rank == 0) {
    exit(1);
  }
  int from, to;

  std::string tmp_str;
  for (int i = 0; i < 4; i++) {
    getline(infile, tmp_str);
  }
  infile >> tmp_str;
  infile >> tmp_str;
  int vertex_num, edge_num;
  char ch;
  int start, end, cost;
  infile >> vertex_num >> edge_num;
  getline(infile, tmp_str);
  getline(infile, tmp_str);
  getline(infile, tmp_str);
  graph_t *ret = new graph_t;
  ret->num_vertices = vertex_num;
  ret->num_edges = edge_num;
  ret->v_adj_begin = new int[vertex_num];
  ret->v_adj_length = new int[vertex_num];
  ret->v_adj_list = new int[edge_num];
  vector<vector<int>> adj_graph(vertex_num);
  for (int i = 0; i < edge_num; i++) {
    infile >> ch >> start >> end >> cost;
    adj_graph[start - 1].push_back(end - 1);
  }
  infile.close();
  int offset = 0;
  for (int i = 0; i < vertex_num; i++) {
    int tmp_len = adj_graph[i].size();
    ret->v_adj_length[i] = tmp_len;
    ret->v_adj_begin[i] = offset;
    memcpy(ret->v_adj_list + offset, &adj_graph[i][0], sizeof(int) * tmp_len);
    offset += tmp_len;
  }
  return ret;
}
