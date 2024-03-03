#include "Graph.h"
#include <algorithm>

typedef ALGraph Graph;
ALGraph mkGraph(){
  int  n, m, u,v;//number of vertices, edges and edge pairs 
  cin >>n>>m;
  ALGraph g(n,m);
  while (m--){
      cin >> u >> v;
      g.adj[u].push_back(v);
      g.adj[v].push_back(u);
  }    
  return g;
}

//假定n个结点分别用0,1,..., n-1表示。例如，3个结点的无向图的结点分别是0,1和2.