#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node{
    int v,w;
};
bool operator<(Node lhs,Node rhs){
    return lhs.w > rhs.w;
}
int main(){
    while(true){
        int P,R;
        cin >> P >> R;
        if(P == 0){
            break;
        }
        vector<vector<Node>> graph(P);
        for(int i = 0;i < R;i++){
            int u,v,t;
            cin >> u >> v >> t;
            u -= 1; v -= 1;
            graph[u].push_back({v,t});
            graph[v].push_back({u,t});
        }
        vector<int> lowcost(P,10000);
        vector<bool> visited(P,false);
        priority_queue<Node> pq;
        int ans = 0; int cnt = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(visited[curr.v]){
                continue;
            }
            if(cnt >= P){
                break;
            }
            visited[curr.v] = true;
            ans += curr.w;
            cnt += 1;
            for(Node neigh:graph[curr.v]){
                if(neigh.w < lowcost[neigh.v]){
                    lowcost[neigh.v] = neigh.w;
                    pq.push({neigh.v,neigh.w});
                }
            }
        }
        cout << ans << endl;
    }
}