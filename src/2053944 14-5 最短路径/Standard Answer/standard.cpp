#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Point2d
{
 int x, y;
 bool operator == (const Point2d & rh)
 {
  return (x == rh.x && y == rh.y);
 }
 Point2d(int _x, int _y) : x(_x), y(_y)
 {}
 bool is_inner_map(int n, int m)
 {
  return (x >= 1 && x <= n && y >= 1 && y <= m);
 }
};
int main()
{
 int n = 0;
 int m = 0;
 cin >> n;
 cin >> m;
 bool ** map = new bool * [n + 1];
 for (int i = 1; i < n + 1; i++)
 {
  map[i] = new bool[m + 1];
  for (int j = 1; j < m + 1; j++)
  {
   cin >> map[i][j];
  }
 }
 int sx = 0;
 int sy = 0;
 int tx = 0;
 int ty = 0;
 cin >> sx;
 cin >> sy;
 cin >> tx;
 cin >> ty;
 vector<vector<int> > step(n + 1, vector<int>(m + 1));
 vector<vector<bool> > is_visit(n + 1, vector<bool>(m + 1));
 for (int i = 1; i < n + 1; i++)
 {
  for (int j = 1; j < m + 1; j++)
  {
   step[i][j] = 0;
   is_visit[i][j] = false;
  }
 }
 Point2d sf(sx, sy);
 Point2d tf(tx, ty);
 step[sx][sy] = 0;
 queue<Point2d> q;
 q.push(sf);
 while (!q.empty())
 {
  Point2d current_point = q.front();
  if (current_point == tf)   break;
  q.pop();
  if (is_visit[current_point.x][current_point.y] == false)
  {
   is_visit[current_point.x][current_point.y] = true;
   Point2d up(current_point.x, current_point.y + 1);
   if (up.is_inner_map(n,m) == true && is_visit[up.x][up.y] == false && map[up.x][up.y] == 0)
   {
    step[up.x][up.y] = step[current_point.x][current_point.y] + 1;
    q.push(up);
   }
   Point2d down(current_point.x, current_point.y - 1);
   if (down.is_inner_map(n, m) == true && is_visit[down.x][down.y] == false && map[down.x][down.y] == 0)
   {
    step[down.x][down.y] = step[current_point.x][current_point.y] + 1;
    q.push(down);
   }
   Point2d left(current_point.x - 1, current_point.y);
   if (left.is_inner_map(n, m) == true && is_visit[left.x][left.y] == false && map[left.x][left.y] == 0)
   {
    step[left.x][left.y] = step[current_point.x][current_point.y] + 1;
    q.push(left);
   }
   Point2d right(current_point.x + 1, current_point.y);
   if (right.is_inner_map(n, m) == true && is_visit[right.x][right.y] == false && map[right.x][right.y] == 0)
   {
    step[right.x][right.y] = step[current_point.x][current_point.y] + 1;
    q.push(right);
   }
  }
 }
 if (step[tx][ty] == 0)
 {
  cout << "No";
 }
 else
 cout << step[tx][ty];
 return 0;
}