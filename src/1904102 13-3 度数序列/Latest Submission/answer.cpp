#include"Graph.h"
#include<algorithm>
// struct  ALGraph{
//     vector<vector<int> > adj; //adjacency list of the graph
//     int order;// number of vertices
//     int size;//number of edges

//     //A  simple initialization.
//    ALGraph(int n=0, int m=0):order(n), size(m){
//         adj.resize(n);
//    }
// } ;
// //假定n个结点分别用0,1,..., n-1表示。例如，3个结点的无向图的结点分别是0,1和2.
vector<int> degreeSequence(const ALGraph &g){
    vector<int> ans;
    ans.reserve(g.order);
    for(int i = 0;i < g.order;i++){
        ans.push_back(g.adj[i].size());
    }
    std::sort(ans.begin(),ans.end(),std::greater<int>());
    return ans;
}