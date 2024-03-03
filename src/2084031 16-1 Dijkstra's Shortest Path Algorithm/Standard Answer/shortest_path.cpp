
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <limits>

using namespace std;

typedef pair<int,int> Pos;
typedef int Nodes;
typedef vector<vector<int> > AdjMatrix;

//int infinity = INT_MAX;
int infinity  = std::numeric_limits<int>::max();

AdjMatrix mkGraph(){
  int n,m,u,v,w;
  cin >> n >> m;
  vector<int> vec(n,infinity);
  AdjMatrix g1(n,vec);
  
  for (int i=0; i<m;i++){
    cin >>u>>v>>w;
    g1[u-1][v-1] = w;
  }
  return g1;
}


Nodes minDistance(vector<int> dis, vector<bool> found){
    Nodes u = -1;
    int n = dis.size();
    int m = infinity;
    for (size_t i=0;i<n;i++){
//cout<<"dis "<<i<<":"<<dis[i]<<endl;
      if (!found[i] &&  dis[i] < m){
           u = i;
           m = dis[i];
//cout <<"u:"<<u<<endl;
//cout<<"m:"<<m<<endl;
      }
    }
//cout <<"return u:"<<u<<endl;
   return u;
}
void print(vector<int> d, int s){
  for (size_t i=0;i<d.size();i++)
      if (d[i] < infinity)
         cout <<s<<"-"<<(i+1)<<":"<<d[i]<<endl;
}
/*
void print(vector<vector<int> > g){
cout<<"matrix"<<endl;
  for (int i=0;i<g.size();i++){
cout<<i<<":"<<endl;
    copy(g[i].begin(),g[i].end(),ostream_iterator<int>(cout,", "));
    cout<<endl;
  }
}*/

vector<int> dijkstra(AdjMatrix graph, Nodes s){
    int n = graph.size();
    vector<int> distance(n,infinity);
    vector<bool> found(n,false);
    for (size_t i=0;i<n;i++){
       distance[i] = graph[s][i];
//cout<<"distance "<<i<<":"<<distance[i]<<endl;
    }
    found[s] = true;
    distance[s] = 0;
    for (int i=0;i<n;i++){
        int u = minDistance(distance, found);
//cout<<"u:"<<u<<endl;
        if (u==-1)
           break;
        found[u] = true;
        for (size_t i=0;i<n;i++){
//cout <<"graph "<<u<<" "<<i<< ":"<<graph[u][i] <<":"<< INFINITY<< endl;
             if (!found[i] && (graph[u][i] < infinity)){
               if  (distance[u] + graph[u][i] < distance[i]) 
                 distance[i] = distance[u]+graph[u][i]; 
//cout<<" while distance "<<i<<":"<<distance[i]<<endl;
//cout<<" while found"<<i<<":"<<found[i]<<endl;
        }
      }
    }
    return distance;
}

int main(){
 
  int k;
  cin >>k;
  while (k--) {
    AdjMatrix graph = mkGraph();
//print(graph);
    int s;
    cin >>s;
    vector<int> d = dijkstra(graph, s-1);
    print(d,s);
  }
  return 0;
}
