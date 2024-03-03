#include <iostream>
#include <queue>
#include <stdio.h>

enum color {white, black, gray};

struct num {
  int row, col;
  num(int r = 0, int c = 0) : row(r), col(c) {}
};

struct Node {
  num pre;
  int distance;
  color co;
};

int main() {
  int matrix[30][30], n;
  const int start_vert = 0;
  std::queue<num> q;
  Node vert[30][30];
  scanf ("%d", &n);
  while(n != 0) {
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++) {
        scanf("%d", &matrix[row][col]);
      }
    }
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n; col++) {
        vert[row][col].pre = num(-1, -1);
        vert[row][col].distance = -1;
        vert[row][col].co = white;
      }
    }
    while(!q.empty()) {
      q.pop();
    }
    if (matrix[start_vert][start_vert] == 0) {
      vert[start_vert][start_vert].co = gray;
      vert[start_vert][start_vert].distance = 1;
      q.push(num(start_vert, start_vert));
    }
    while (!q.empty()) {
      num v = q.front();
      q.pop();
      if (v.row > 0) {
        if (matrix[v.row - 1][v.col] == 0) {
          if (vert[v.row - 1][v.col].co == white) {
            vert[v.row - 1][v.col].co = gray;
            vert[v.row - 1][v.col].distance = vert[v.row][v.col].distance + 1;
            vert[v.row - 1][v.col].pre = v;
            q.push(num(v.row - 1, v.col));
          }
        }
      }
      if (v.row < n - 1) {
        if (matrix[v.row + 1][v.col] == 0) {
          if (vert[v.row + 1][v.col].co == white) {
            vert[v.row + 1][v.col].co = gray;
            vert[v.row + 1][v.col].distance = vert[v.row][v.col].distance + 1;
            vert[v.row + 1][v.col].pre = v;
            q.push(num(v.row + 1, v.col));
          }
        }
      }
      if (v.col > 0) {
        if (matrix[v.row ][v.col - 1] == 0) {
          if (vert[v.row][v.col - 1].co == white) {
            vert[v.row][v.col - 1].co = gray;
            vert[v.row][v.col - 1].distance = vert[v.row][v.col].distance + 1;
            vert[v.row][v.col - 1].pre = v;
            q.push(num(v.row, v.col - 1));
          }
        }
      }
      if (v.col < n - 1) {
        if (matrix[v.row ][v.col + 1] == 0) {
          if (vert[v.row][v.col + 1].co == white) {
            vert[v.row][v.col + 1].co = gray;
            vert[v.row][v.col + 1].distance = vert[v.row][v.col].distance + 1;
            vert[v.row][v.col + 1].pre = v;
            q.push(num(v.row, v.col + 1));
          }
        }
      }
      vert[v.row][v.col].co = black;
    }
    if (vert[n - 1][n - 1].distance != -1) {
      printf("%d\n", vert[n - 1][n - 1].distance);
    } else {
      printf("0\n");
    }
    scanf ("%d", &n);
  }
  return 0;
}