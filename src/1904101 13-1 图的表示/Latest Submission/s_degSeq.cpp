#include"Graph.h"
// #include<iostream>
/* 
struct  ALGraph{
    vector<vector<int> > adj; //adjacency list of the graph
    int order;// number of vertices
    int size;//number of edges

    //A  simple initialization.
   ALGraph(int n=0, int m=0):order(n), size(m){
        adj.resize(n);
   }
} ;
*/
ALGraph mkGraph(){
    int n,m;
    cin >> n >> m;
    ALGraph graph(n,m);
    for(int i = 0;i < m;i++){
        int x1,y1;
        cin >> x1 >> y1;
        graph.adj[x1].push_back(y1);
        graph.adj[y1].push_back(x1);
    }
    return graph;
}
