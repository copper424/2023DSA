#include"bfs.h"
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
void BFSTraverse(GraphList *g){
    int k = g->numVertex; int m = g->numEdges;
    // queue<int> q(1,0);
    queue<int> q;
    // q.push(0);
    vector<bool> visited(k,false);
    for(int i = 0;i < k;i++){
        if(visited[g->adjList[i].value])
            continue;
        q.push(g->adjList[i].value);
        while(!q.empty()){
            auto curr = q.front();q.pop();
            cout << curr << ' ';
            visited[curr] = true;
            for(auto ptr = g->adjList[curr].firstedge;ptr != nullptr;ptr = ptr->next){
                if(!visited[ptr->adjvex]){
                    q.push(ptr->adjvex);
                }
            }
        }
    }
}