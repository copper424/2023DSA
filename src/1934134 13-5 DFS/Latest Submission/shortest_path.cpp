#include<iostream>
#include<vector>
#include<deque>
#include<cstdint>
using namespace std;

bool all_is_visited(const vector<uint8_t>& visited){
    for(int i = 0;i < visited.size();i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int index = 0;index < t;index++){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> graph(n,vector<int>());
        for(int i = 0;i < m;i++){
            int u,v;
            cin >> u >> v;
            u -= 1; v -= 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<uint8_t> visited(n,false);
        int counter = 0;
        while(!all_is_visited(visited)){
            int start = 0;
            for(int i = 0;i < visited.size();i++){
                if(!visited[i]){
                    start = i; break;
                }
            }
            counter += 1;
            deque<int> dq(1,start);
            while(!dq.empty()){
                auto curr = dq.front();dq.pop_front();
                visited[curr] = true;
                for(auto elem:graph[curr]){
                    if (!visited[elem]){
                        dq.push_back(elem);
                    }
                }
            }
        }
        if(counter == 1){
            printf("YES, 1 component.\n");
        }else{
            printf("NO, %d components.\n",counter);
        }
       
    }
}