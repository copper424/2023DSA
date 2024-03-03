#include "Graph.h"
#include <algorithm>

vector<int> degreeSequence(const ALGraph &g){
   size_t n = g.order;
   vector<int> v(n);
   for (size_t i=0; i< n;i++){
         v[i] = g.adj[i].size();
  }
  sort(v.begin(),v.end(),greater<int>());
  return v;
}
