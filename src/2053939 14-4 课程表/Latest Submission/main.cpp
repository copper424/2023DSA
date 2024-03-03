#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main(){
    int T,n;
    cin >> T >> n;
    // cout << T << " " << n;
    vector<vector<int>> graph(T,vector<int>());
    vector<int> indegree(T,0);
    for(int idx = 0;idx < T;idx++){
        int a1,b1;
        cin >> a1 >> b1;
        graph[a1].push_back(b1);
        indegree[b1]++;
    }
    deque<int> dq;
    for(int i = 0;i < indegree.size();i++){
        if(indegree[i] == 0){
            dq.push_back(i);
        }
    }

    vector<bool> visited(T,false);
    int cnt = 0;
    while(!dq.empty()){
        auto curr = dq.front(); dq.pop_front();
        if(visited[curr]){
            continue;
        }
        cnt += 1;
        visited[curr] = true;
        for(auto elem:graph[curr]){
            if(indegree[elem] >= 1){
                indegree[elem] -= 1;
                if(indegree[elem] == 0){
                    dq.push_back(elem);
                }
            }
        }
    }
    label:
    if(cnt == T){
        cout << 1;
    }else{
        cout << 0;
    }
}   