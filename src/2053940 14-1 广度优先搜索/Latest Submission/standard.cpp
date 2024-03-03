#include<iostream>
#include<deque>
#include<vector>
#include<cstdint>
using namespace std;

int main(){
    int n,s;
    cin >> n >> s;
    vector<vector<int>> graph(n + 1,vector<int>());
    deque<int> dq(1,s);
    for(int index = 1;index <= n;index++){
        
        for(int i = 1;i <= n;i++){
            int v;
            cin >> v;
            if(v != 0)
                graph[index].push_back(i);
        }
    }
    vector<int8_t>visited(n + 1,false);
    while(!dq.empty()){
        auto curr = dq.front();dq.pop_front();
        if(visited[curr])
            continue;
        visited[curr] = true;
        cout << curr << ' ';
        for(auto elem:graph[curr]){
            
            dq.push_back(elem);
        }
    }
}