#include"circle.h"
#include<map>
#include<set>
// #include "graphlist.h"
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// #define MAXVEX 1000
// // 边表节点
// class EdgeNode {
//  public:
// 	int adjvex; //边指向哪个顶点的索引
// 	int weight;
// 	EdgeNode* next;
// };
// // 顶点表结构
// class VertexNode {
//  public:
// 	int value; //顶点的值，为了简化与序号相同，第一个是0
// 	EdgeNode *firstedge;
// };
// // 图结构
// class GraphList {
//  public:
// 	VertexNode adjList[MAXVEX];
// 	int numVertex;
// 	int numEdges;
// };
// void createGraph(GraphList* g){
//     int k,m;
//     cin >> k >> m;
//     g->numVertex = k; g->numEdges = m;
//     for(int index = 0;index < k;index++){
//         int vertex;
//         cin >> vertex;
//         g->adjList[index].value = vertex;
//         g->adjList[index].firstedge = nullptr;
//     } 

//     for(int idx = 0;idx < m;idx++){
//         int vi,vj,w;
//         cin >> vi >> vj >> w;
//         int index = -1;
//         for(int idx2 = 0;idx2 < k;idx2++){
//             if(g->adjList[idx2].value == vi){
//                 index = idx2;
//                 break;
//             }
//         }
//         if(index == -1){
//             cout << "idx does not exist!\n";
//             return;
//         }
//         EdgeNode*& ptr = g->adjList[index].firstedge;
//         while(ptr != nullptr){
//             ptr = ptr->next;
//         }
//         ptr = new EdgeNode;
//         ptr->adjvex = vj;
//         ptr->weight = w;
//         ptr->next = nullptr;
//         // if(g->adjList[index]->firstedge == nullptr){
//         //     g->adjList[index]->firstedge
//         // }else{

//         // }
//     }
// }

void Graphcircle(GraphList *g){
    vector<int> indegree(g->numVertex,0);
    for(int i = 0;i < g->numVertex;i++){
        for(auto ptr = g->adjList[i].firstedge;ptr != nullptr;ptr = ptr->next){
            indegree[ptr->adjvex] += 1;
        }
    }
    // cout << indegree.size() << endl;
    queue<int> q;
    for(int i = 0;i < indegree.size();i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    vector<bool> visited(g->numVertex,false);
    while(!q.empty()){
        auto curr = q.front();q.pop();
        if(visited[curr]){
            continue;
        }
        // printf("curr:%d\n",curr);
        visited[curr] = true;
        cnt += 1;
        for(auto neigh = g->adjList[curr].firstedge;neigh != nullptr;neigh = neigh->next){
            auto adj = neigh->adjvex;
            if(indegree[adj] >= 1){
                indegree[adj] -= 1;
                if(indegree[adj] == 0){
                    q.push(adj);
                }
            }
        }
        
    }
    // cout << cnt << endl;
    if(cnt != g->numVertex){
        cout << "has circle\n";
    }else{
        cout << "no circle\n";
    }
}