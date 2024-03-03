#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node{
    int v,w;
};

struct State{
    int v,dis;
   
};
bool operator<(const State lhs,const State other){
    return lhs.dis > other.dis;
}
int main(){
    int testcase; cin >> testcase;
    while(testcase--){
        int n,m; cin >> n >> m;
        vector<vector<Node>> graph(n + 1,vector<Node>());
        for(int idx = 0;idx < m;idx++){
            int u,v,w;
            cin >> u >> v >> w;
            // printf("u:%d v:%d w:%d\n",u,v,w);
            graph[u].push_back(Node{v,w});
        }
        int start;
        cin >> start;
        priority_queue<State,vector<State>> pq;
        pq.push(State{start,0});
        vector<int> dist(n + 1,1e9 + 7);
        dist[start] = 0;
        while(!pq.empty()){
            auto curr = pq.top();pq.pop();
            
            if(dist[curr.v] < curr.dis){
                continue;
            }
            for(auto neighbour:graph[curr.v]){
                int v = neighbour.v;
                int w = neighbour.w;
                if(dist[v] > dist[curr.v] + w){
                    dist[v] = dist[curr.v] + w;
                    pq.push(State{v,dist[v]});
                }
            }
        }
        for(int idx = 1;idx < n + 1;idx++){
            if(dist[idx] == (1e9 + 7)){
                continue;
            }
            printf("%d-%d:%d\n",start,idx,dist[idx]);
        }
    }
}