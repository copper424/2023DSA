#include<iostream>
#include<vector>
#include<deque>
#include<set>
using namespace std;

void dfs(int curr,const vector<vector<int>>& graph,vector<int>& visited,int& count,int end){

    // printf("%d\n",curr);
    visited[curr] = true;
    if(curr == end){
        count += 1;
    }else{
        for(auto neigh:graph[curr]){
            if(!visited[neigh]){
                dfs(neigh,graph,visited,count,end);
            }
        }
    }
    visited[curr] = false;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> indegree(n,0);
    vector<int> outdegree(n,0);
    for(int idx = 0;idx < m;idx++){
        int u,v;
        cin >> u >> v;
        u -= 1; v-= 1;
        graph[u].push_back(v);
        indegree[v] += 1;
        outdegree[u] += 1;
    }
    set<int>start;
    set<int>end;
    for(int idx = 0;idx < n;idx++){
        if(indegree[idx] == 0){
            start.insert(idx);
        }
        if(outdegree[idx] == 0){
            end.insert(idx);
        }
    }
    int count = 0;
    vector<int> visited(n,false);
    for(auto elem:start){
        for(auto elem2:end){
            dfs(elem,graph,visited,count,elem2);
        }
    }
    cout << count;
}