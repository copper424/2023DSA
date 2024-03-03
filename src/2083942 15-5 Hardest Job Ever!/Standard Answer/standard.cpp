#include<iostream>
#include<queue>
#include<cstring>
#define INF 20000000
#define MAXN 205
#define MAXM 20005
using namespace std;
typedef pair<int,int> dis_v;
int T,N,M;
int head[MAXN],next[MAXM],V[MAXM],W[MAXM],dis[MAXN];
int adjacency[MAXN][MAXN];
int m;

void buildGraph() {  
    int u,v,w;
    m = 0;
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            adjacency[i][j] = INF;
            if(i == j) adjacency[i][j] = 0;
        }
    }

    while(M--) {  
        scanf("%d%d%d",&u,&v,&w);
        // addEdge
        if(w < adjacency[u][v] && w < adjacency[v][u])
            adjacency[u][v] = adjacency[v][u] = w;
    }
}

int Dijkstra(int st, int ed) {
    bool found[MAXN];
    for(int i = 1; i <= N; i++){
        found[i] = false;
        dis[i] = adjacency[st][i];
    }
    found[st] = true;
    dis[st] = 0;
    int new_node;
    for(int i = 1; i <= N; i++) {
        int min = INF;
        new_node = st;
        for(int j = 1; j <= N; j++) {
            if(!found[j]) {
                if(dis[j] < min) {
                    new_node = j;
                    min = dis[j];
                }
            }
        }
        found[new_node] = true;
        for(int j = 1; j <= N; j++) {
            if(!found[j]) {
                if(min + adjacency[new_node][j] < dis[j]) {
                    dis[j] = min + adjacency[new_node][j];
                }
            }
        }
    }  
    if(dis[ed] >= INF)  return -1;
    else return dis[ed];
}

int main() {
    scanf("%d",&T);
    while(T--)
    {  
        buildGraph();  
        printf("%d\n",Dijkstra(1,N));
    }  
    return 0;  
}