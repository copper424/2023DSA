#include<iostream>
#include<array>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<climits>
#include<cstdint>
using namespace std;


struct Edge{
    int from;
    int to;
    int apples;
    Edge(int from,int to,int apples):from{from},to{to},apples{apples}{}
};
vector<int> subtree_apple;
vector<vector<Edge>> graph;

int main(){
    int N,Q;
    cin >> N >> Q;

    graph.resize(N + 1);
    for(int i = 1;i <= N - 1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        // printf("from:%d,to:%d,apples:%d\n",a,b,c);
        graph[a].push_back(Edge(a,b,c));
        graph[b].push_back(Edge(b,a,c));
    }
    auto cmp = [](auto& a,auto& b){
        return a.apples < b.apples;
    };
    auto cmp1 = [](auto& a,auto& b){
        if(a.from == b.from){
            return a.to < b.to;
        }
        return a.from < b.from;
    };
    set<Edge,decltype(cmp1)> visited(cmp1);
    set<Edge,decltype(cmp1)> mst(cmp1);
   
    priority_queue<Edge,vector<Edge>,decltype(cmp)> pq(cmp);
    for(const auto& edge:graph[1]){
        pq.push(edge);
    }
    while(!pq.empty() && mst.size() < Q){
        auto curr = pq.top();
        pq.pop();
        // printf("%d %d %d\n",curr.from,curr.to,curr.apples);
        mst.insert(curr);
        visited.insert(curr);
        for(const auto& exist_edge:mst){
            int node1 = exist_edge.from;
            int node2 = exist_edge.to;
            // printf("node:%d %d\n",node1,node2);
            for(const auto& neighbour:graph[node1]){
                if(visited.count(neighbour) || 
                visited.count(Edge(neighbour.to,neighbour.from,neighbour.apples))){
                    continue;
                }
                visited.insert(neighbour);
                // printf("neighbour:%d %d\n",neighbour.from,neighbour.to);
                pq.push(neighbour);
            }
            for(const auto& neighbour:graph[node2]){
                if(visited.count(neighbour) || 
                visited.count(Edge(neighbour.to,neighbour.from,neighbour.apples))){
                    continue;
                }
                // printf("neighbour:%d %d\n",neighbour.from,neighbour.to);
                visited.insert(neighbour);
                pq.push(neighbour);
            }
        }
    }
    
    int ans = 0;
    for(const auto& edge:mst){
        // printf("mst edge:%d %d %d\n",edge.from,edge.to,edge.apples);
        ans += edge.apples;
    }
    printf("%d\n",ans);
}