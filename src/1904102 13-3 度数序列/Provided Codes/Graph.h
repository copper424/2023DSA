#include <iostream>
#include <vector>
using namespace std;

struct  ALGraph{
    vector<vector<int> > adj; //adjacency list of the graph
    int order;// number of vertices
    int size;//number of edges

    //A  simple initialization.
   ALGraph(int n=0, int m=0):order(n), size(m){
        adj.resize(n);
   }
} ;
//假定n个结点分别用0,1,..., n-1表示。例如，3个结点的无向图的结点分别是0,1和2.