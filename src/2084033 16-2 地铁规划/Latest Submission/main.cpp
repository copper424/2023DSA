#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct State{
    int v,lowcost;
};
bool operator<(const State lhs,const State rhs){
    return lhs.lowcost > rhs.lowcost;
}
int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int N;
        cin >> N;
        vector<vector<int>> graph(N,vector<int>(N,0));
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                cin >> graph[i][j];
            }
        }
        int weight = 0;int cnt = 0;
        priority_queue<State> pq;
        vector<int> lowcost(N,1e9 + 7);
        vector<bool> visited(N,false);
        pq.push(
            State{
                0,0
            }
        );
        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            if(cnt >= N){
                break;
            }
            if(visited[curr.v]){
                continue;
            }
            // printf("curr:%d %d\n",curr.v,curr.lowcost);
            visited[curr.v] = true;
            weight += curr.lowcost;
            cnt += 1;
            for(int idx = 0;idx < N;idx++){
                if(graph[curr.v][idx] < lowcost[idx]){
                    lowcost[idx] = graph[curr.v][idx];
                    pq.push(State{idx,lowcost[idx]});
                }
            }
        }
        printf("%d\n",weight);
    }
}