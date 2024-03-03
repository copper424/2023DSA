/* https://leetcode.cn/problems/minimum-height-trees/solutions/1395249/zui-xiao-gao-du-shu-by-leetcode-solution-6v6f/ */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (auto & edge : edges){
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> qu;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                qu.emplace(i);
            }
        }
        int remainNodes = n;
        while (remainNodes > 2) {
            int sz = qu.size();
            remainNodes -= sz;
            for (int i = 0; i < sz; i++) {
                int curr = qu.front();
                qu.pop();
                for (auto & v : adj[curr]) {
                    if (--degree[v] == 1) {
                        qu.emplace(v);
                    }
                }
            }
        }
        while (!qu.empty()) {
            ans.emplace_back(qu.front());
            qu.pop();
        }
        return ans;
    }

int main(){
    int a,b,n;
    cin >> n;
    vector<vector<int>> edges;
    vector<int> ans;
    for(int i=0;i<n-1;++i){
        cin >> a >>b;
        vector<int> edge{};
        edge.push_back(a);
        edge.push_back(b);
        edges.push_back(edge);
    }
    ans = findMinHeightTrees(n, edges);
    for(vector<int>::iterator iter=ans.begin();iter!=ans.end();++iter){
        cout << *iter<<" ";
    }
    return 0;
}