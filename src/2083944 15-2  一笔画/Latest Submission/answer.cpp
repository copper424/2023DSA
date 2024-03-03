#include<iostream>
#include<vector>
#include<cstdint>
using namespace std;

vector<vector<int>> graph;
vector<int8_t> visited;
int cnt = 0;

void dfs(int u){
    visited[u] = true;
    for(auto neigh:graph[u]){
        if(!visited[neigh]){
            dfs(neigh);
            cnt += 1;
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    cnt = 0;
    // printf("%d %d %d \n",n,m,cnt);
    
    graph.assign(n,vector<int>());
    visited.assign(n,false);
    for(int idx = 0;idx < m;idx++){
        int a,b;
        cin >> a >> b;
        a -=  1; b -= 1;
        // printf("%d %d\n",a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = 0;
    while(cnt < m){
        int idx = -1;
        for(int i = 0;i < n;i++){
            if(!visited[i]){
                idx = i; break;
            }
        }
        if(idx == -1){
            // cout << "Error\n";
            break;
        }
        int prev_cnt = cnt;
        // cout <<"reach %d"<< idx <<"\n";
        dfs(idx);
        if(cnt > prev_cnt){
            ans += 1;
        }
    }
    // cout << cnt << endl;
    cout << ans << endl;
}