#include<iostream>
#include<vector>
#include<queue>
#include<cstdint>
using namespace std;
struct Node{
    int v,w;
};
struct State{
    int v,lowcost;
    
};
bool operator<(const State& lhs,const State& rhs){
        return lhs.lowcost > rhs.lowcost;
}
int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int n,m; cin >> n >> m;
        vector<vector<Node>> graph(n);
        for(int idx = 0;idx < m;idx++){
            int x,y,d;
            cin >> x >> y >> d;
            // printf("%d %d %d\n",x,y,d);
            graph[x].push_back(Node{y, -1 * d});
            graph[y].push_back(Node{x,-1 * d});
        }
        int weight = 0;
        vector<int8_t> visited(n,false);
        vector<int> lowcost(n,1e9);
        while(true){
            int cnt = 0;int start = -1;
            for(int idx = 0;idx < n;idx++,cnt++){
                if(!visited[idx]){
                    start = idx;
                    break;
                }
            }
            if(cnt == n){
                break;
            }
            priority_queue<State> pq;
            pq.push(State{start,0});
            while(!pq.empty()){
                auto curr = pq.top();pq.pop();
                if(visited[curr.v]){
                    continue;
                }
                // printf("%d %d\n",curr.v,curr.lowcost);
                visited[curr.v] = true;
                weight += curr.lowcost;
                for(auto neigh:graph[curr.v]){
                    if(lowcost[neigh.v] > neigh.w){
                        lowcost[neigh.v] = neigh.w;
                        pq.push(State{neigh.v,lowcost[neigh.v]});
                    }
                }
            }
        }
        printf("%d\n",-1 * weight);
    }
}