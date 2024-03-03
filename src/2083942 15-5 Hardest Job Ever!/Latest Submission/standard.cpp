#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
struct Node{
    int v,w;
};
vector<vector<Node>> graph;
vector<int> dist;
struct State{
    int u,dist;
};
int main(){
    int T;
    cin >> T;
    auto cmp = [](const auto& a,const auto& b){
        return a.dist > b.dist;
    };
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        graph.assign(n,vector<Node>());
        dist.assign(n,1e9+7);
        for(int idx = 0;idx < m;idx++){
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            i -= 1; j -= 1;
            // printf("%d %d %d\n",i,j,k);
            Node a = {j,k};
            Node b = {i,k};
            graph[i].push_back(a);
            graph[j].push_back(b);
        }
        dist[0] = 0;
        State start = {0,0};
        priority_queue<State,vector<State>,decltype(cmp)> pq(cmp);
        pq.push(start);
        // printf("n:%d m:%d\n",n,m);
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            // printf("Curr.u:%d\n",curr.u);
            if(curr.u == n - 1){
                dist[curr.u] = curr.dist;
                break;
            }
            if(curr.dist > dist[curr.u]){
                continue;
            }
            for(Node& neigh:graph[curr.u]){
                if(dist[neigh.v] > dist[curr.u] + neigh.w){
                    dist[neigh.v] = dist[curr.u] + neigh.w;
                    State next = {neigh.v,dist[neigh.v]};
                    pq.push(next);
                }
            }
        }
        if(dist.back() == (1e9 + 7)){
            cout << -1 << '\n';
        }else{
            cout << dist.back() << '\n';
        }
    }
}