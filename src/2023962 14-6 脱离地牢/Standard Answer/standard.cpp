#include <iostream>
#include <stdio.h>
#include <queue>

enum direction {N, S, W, E};

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

char ma[23][23];

bool flag[23][23][23][23];

struct Node {
  int x, y, step, row, col;
  Node(int x_, int y_, int s_, int r_, int c_) :
       x(x_), y(y_), step(s_), row(r_), col(c_) {}
};

bool check(int px, int py, int hx, int hy, int n, int m) {
  if(px < 0 || px > n - 1 || py < 0 || py > m - 1
     || ma[px][py] == '#' || ma[px][py] == '!'
     || hx < 0 || hx > n - 1 || hy < 0 || hy > m - 1
     || ma[hx][hy] == '!') {
    return false;
  } else {
    return true;
  }
}

int main() {
  int n, m, H_row, H_col, P_row, P_col, ans;
  int d[4];
  char str[28];
  std::queue<Node> q;
  while(scanf("%d %d", &n, &m) != EOF) {
    for(int i = 0; i < n; i++) {
      scanf("%s", str);
      for(int j = 0; j < m; j++) {
        ma[i][j] = str[j];
        if(str[j] == 'H') {
          H_row = i, H_col = j;
          ma[i][j] = '.';
        }
        if(str[j] == 'P') {
          P_row = i, P_col = j;
          ma[i][j] = '.';
        }
      }
    }
    for(int i = 0; i < 23; i++) {
      for(int j = 0; j < 23; j++) {
        for(int k = 0; k < 23; k++) {
          for(int l = 0; l <23; l++) {
            flag[i][j][k][l] = false;
          }
        }
      }
    }
    scanf("%s", str);
    for(int i = 0; i < 4; i++) {
      if(str[i] == 'N') {
        d[i] = 0;
      } else if(str[i] == 'S') {
        d[i] = 1;
      } else if(str[i] == 'W') {
        d[i] = 2;
      } else if(str[i] == 'E') {
        d[i] = 3;
      }
    }
    while(!q.empty()) {
      q.pop();
    }
    ans = -1;
    q.push(Node(P_row, P_col, 0, H_row, H_col));
    flag[P_row][P_col][H_row][H_col] = true;
    while(!q.empty() && ans == -1) {
      Node temp = q.front();
      q.pop();
      //if(temp.x == temp.row && temp.y == temp.col) {
      //  ans = temp.step;
      //  break;
      //}
      if(temp.step > 255) {
        break;
      }
      for(int i = 0; i < 4; i++) {
        int px = temp.x + dir[i][0];
        int py = temp.y + dir[i][1];
        int hx = temp.row + dir[d[i]][0];
        int hy = temp.col + dir[d[i]][1];
        int s = temp.step + 1;
        if(check(px, py, hx, hy, n, m)) {
          if(ma[hx][hy] == '#') {
            hx = temp.row;
            hy = temp.col;
          }
          if(flag[px][py][hx][hy] == false) {
            flag[px][py][hx][hy] = true;
            if((px == hx && py == hy) || (temp.x == hx && temp.y == hy && temp.row == px && temp.col == py)) {
              ans = s;
              break;
            }
            q.push(Node(px, py, s, hx, hy));
          }
        }
      }
    }
    if(ans == -1) {
      printf("Impossible\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}                                 