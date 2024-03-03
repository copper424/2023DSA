#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<int> indegree;

template <typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
T read()
{
    T sum = 0, fl = 1; // 将 sum,fl 和 ch 以输入的类型定义
    int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) {
        if (ch == '-') {
            fl = -1;
        }
    }
    //   for (;isdigit(ch) && !cin.eof(); ch = getchar()) {
    //     sum = sum * 10 + ch - '0';
    //   }
    if (isdigit(ch)) {
        sum = sum * 10 + ch - '0';
    }

    return sum * fl;
};
int main()
{
    int n;
    cin >> n;
    cin.get();
    if (n == 1) {
        cout << 0;
        return 0;
    }
    graph.assign(n, vector<int>());
    indegree.assign(n, 0);
    for (int idx = 1; idx < n; idx++) {
        int a, b;
        cin >> a >> b;
        indegree[a] += 1;
        indegree[b] += 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 1) {
            dq.push_back(i);
        }
    }
    vector<int> topo;
    topo.reserve(n);
    while (!dq.empty()) {
        auto u = dq.front();
        dq.pop_front();
        topo.push_back(u);
        for (auto v : graph[u]) {
            if (indegree[v] > 1) {
                indegree[v] -= 1;
                if (indegree[v] == 1) {
                    dq.push_back(v);
                }
            }
        }
    }
    int candidate1 = topo.back();
    topo.pop_back();
    int candidate2 = topo.back();
    vector<bool> visited(n, false);
    int dist1 = 0;
    dq.push_back(candidate1);
    while (!dq.empty()) {
        int sz = dq.size();
        for (int idx = 0; idx < sz; idx++) {
            auto u = dq.front();
            dq.pop_front();
            visited[u] = true;
            for (auto v : graph[u]) {
                if (!visited[v]) {
                    dq.push_back(v);
                }
            }
        }
        dist1 += 1;
    }
    visited.assign(n, false);
    int dist2 = 0;
    dq.push_back(candidate2);
    while (!dq.empty()) {
        int sz = dq.size();
        for (int idx = 0; idx < sz; idx++) {
            auto u = dq.front();
            dq.pop_front();
            visited[u] = true;
            for (auto v : graph[u]) {
                if (!visited[v]) {
                    dq.push_back(v);
                }
            }
        }
        dist2 += 1;
    }
    vector<int> ans(1,candidate1);
    if (dist1 == dist2) {
        ans.push_back(candidate2);
    }
    for(int i = ans.size() - 1;i >= 0;i--){
        cout << ans[i] << ' ';
    }
}