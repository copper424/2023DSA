#include<iostream>
#include<vector>
#include<cmath>
#include<cstdint>

using namespace std;

bool all_is_visited(const vector<uint8_t>& visited){
    for(auto elem:visited){
        if(elem == 0){
            return false;
        }
    }
    return true;
}
vector<vector<int>> graph;
void dfs(int vertex,vector<uint8_t>& visited,vector<int>& component){
    if(visited[vertex]) 
        return;
    visited[vertex] = 1;
    component.push_back(vertex);
    for(auto neighbour:graph[vertex]){
        dfs(neighbour,visited,component);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    graph.assign(n + 1,vector<int>());
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int cnt = 0;
    vector<uint8_t> visited(n + 1,0);
    visited.front() = 1;
    while(!all_is_visited(visited)){
        int start = 1;
        vector<int> component;
        for(int i = 1;i < visited.size();i++){
            if (visited[i] == 0){
                start = i; break;
            }
        }
        dfs(start,visited,component);
        if(component.size() == 1){
            continue;
        }
        int i = 0;
        for(auto elem:component){
            // printf("elem:%d\n",elem);
            if((graph[elem].size() & 0x1)){
                i += 1;
            }
        }
        // printf("%d %d\n",start,i);
        if(i == 0 || i == 2){
            // cnt += 1;
        }else{
            // cnt += i / 2;
        }
        cnt += 1;
    }
    cout << cnt << '\n';
}