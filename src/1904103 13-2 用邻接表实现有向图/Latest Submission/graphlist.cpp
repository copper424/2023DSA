#include"graphlist.h"
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
// // 打印函数
// void printGraph(GraphList *g);
// void createGraph(GraphList* g);
void createGraph(GraphList* g){
    int k,m;
    cin >> k >> m;
    g->numVertex = k; g->numEdges = m;
    for(int i = 0;i < k;i++){
        int num;
        cin >> num;
        VertexNode tmp;
        tmp.value = num;
        tmp.firstedge = nullptr;
        g->adjList[i] = tmp;
    }
    for(int i = 0;i < m;i++){
        int vi,vj,w;
        cin >> vi >> vj >> w;
        for(int j = 0;j < k;j++){
            auto& start_node = g->adjList[j];
            if(start_node.value == vi){
                if(start_node.firstedge == nullptr){
                    start_node.firstedge = new EdgeNode;
                    start_node.firstedge->adjvex = vj;
                    start_node.firstedge->weight = w;
                    start_node.firstedge->next = nullptr;
                }else{
                    auto ptr = start_node.firstedge;
                    for(;ptr->next != nullptr;ptr = ptr->next){
                        
                    }
                    ptr->next = new EdgeNode;
                    ptr->next->adjvex = vj;
                    ptr->next->weight = w;
                    ptr->next->next = nullptr;
                }
                break;
            }
        }

    }
}