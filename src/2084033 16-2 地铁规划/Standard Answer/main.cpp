#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <map>

struct Node {
  int pos, pre, weight;
  Node (int pos_, int pre_ = 0, int weight_ = 0) :
      pos(pos_),
      pre(pre_),
      weight(weight_) {}
  friend bool operator<(const Node&a, const Node&b) {
    return (a.weight>b.weight);
  }
};

bool fun(const Node a, const Node b) {
  if (a.weight < b.weight) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int case_number, n;
  int matrix[100][100];
  int w[100];
  std::vector<int> adj;
  while (scanf("%d", &case_number) != EOF) {
    for (int number = 0; number < case_number; number++) {
      scanf ("%d", &n);
      int distance = 0;
      if (!adj.empty()) {
        adj.clear();
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          scanf ("%d", &matrix[i][j]);
        }
      }
      for (int i = 0; i < n; i++) {
        adj.push_back(i);
      }
      for (int i = 0; i < n; i++) {
        w[i] = matrix[0][i];
      }
      while (!adj.empty()) {
        std::vector<int>::iterator iter = adj.begin(), pos = iter;
        int min = w[*iter];
        for (; iter != adj.end(); iter++) {
          if (min > w[*iter]) {
            pos = iter;
            min = w[*iter];
          }
        }
        distance += min;
        int min_pos = *pos;
        adj.erase(pos);
        for (int i = 0; i < adj.size(); i++) {
          if (w[adj[i]] > matrix[min_pos][adj[i]]) {
            w[adj[i]] = matrix[min_pos][adj[i]];
          }
        }
      }
      printf("%d\n", distance);
    }
  }
  return 0;
}