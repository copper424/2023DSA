#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > Graph;
typedef int Vertex;


//vertices are named as 1, 2, ...,n, but internally 0,1,2,..., n-1.
//DFS starting from s
void DFS_rec(Graph g, vector<bool> &v, Vertex s);

int DFS(Graph g, Vertex s){
    size_t n = g.size();
    int c = 0;
    vector<bool> visited(n,false);
    for (size_t i=0;i<n;i++){
       if (!visited[i]){
          DFS_rec(g, visited, i);
          c++;
       }
    }
    return c; 
}

void DFS_rec(Graph g, vector<bool> &visited, Vertex s){
       size_t k = g[s].size();
       visited[s] = true;
       for (size_t j=0;j<k;j++){
          if (!visited[g[s][j]])
            DFS_rec(g, visited, g[s][j]);
       }
}

void print(Graph g){
  for (size_t i=0;i<g.size();i++){
    cout <<i+1<<":";
    for (size_t j=0;j<g[i].size();j++)
      cout <<g[i][j]+1<<" ";
    cout <<endl;
  }
}
Graph mkGraph(){
  int m,n,u,v;
  cin >>n>>m;
  Graph g;
  g.resize(n);
  for (int i=0;i<m; i++){
     cin>>u>>v;
     g[u-1].push_back(v-1);
     g[v-1].push_back(u-1);
   }
  return g;
}



int main(int argc, char* argv[]){
    int k,m,n;
    cin >> k;
    while (k--){
       Graph g;
//print(g);
       g = mkGraph();
//print(g);       
       int r = DFS(g,0);
//cout<<r<<endl;
       if (r==1)
         cout <<"YES, "<<r<<" component."<< endl;   
       else
         cout <<"NO, "<<r <<" components."<<endl;
    }

    return 0;
}
