#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<utility>
#include<deque>
using namespace std;
int main(){
    int n;
    cin >> n;
    std::cin.get();
    vector<vector<pair<int,int>>> graph(n);
    for(int i = 0;i < n;i++){
        string this_line;
        std::getline(std::cin,this_line,'\n');
        std::stringstream sst(this_line);
        int n;int j = i;
        while(sst >> n){
            j += 1;
            graph[i].push_back(make_pair(j,n));
        }
    }
    vector<int> dist(n,1e9+7);
    dist.front() = 0;
    deque<int> dq(1,0);
    while(!dq.empty()){
        auto u = dq.front(); dq.pop_front();
        for(auto p:graph[u]){
            int v = p.first; int w = p.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                dq.push_back(v);
            }
        }
    }
    cout << dist.back() << endl;
}