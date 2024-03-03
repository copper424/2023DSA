#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct State {
    int v, w;
};
bool operator<(const State lhs, const State rhs)
{
    return lhs.w > rhs.w;
}

vector<int> vertices;
vector<vector<int>> matrix;

void solve(int level, int idx, int n, int m, vector<int>& onPath, vector<vector<int>>& answer, double& ratio)
{
    if (level >= m) {

        vector<bool> visited(n, false);
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (onPath.cend() == std::find(onPath.cbegin(), onPath.cend(), i)) {
                visited[i] = true;
            } else {
                start = i;
            }
        }
        vector<int> lowcost(n, 1e9 + 7);
        priority_queue<State> pq;
        pq.push(State { start, 0 });
        int edge_weight = 0;
        int node_weight = 0;
        int count = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            if (visited[curr.v]) {
                continue;
            }
            if (count == m) {
                break;
            }
            count += 1;
            edge_weight += curr.w;
            node_weight += vertices[curr.v];
            visited[curr.v] = true;
            for (int i = 0; i < n; i++) {
                if (curr.v != i && onPath.cend() != std::find(onPath.cbegin(), onPath.cend(), i) && matrix[curr.v][i] < lowcost[i]) {
                    lowcost[i] = matrix[curr.v][i];
                    pq.push(State { i, lowcost[i] });
                }
            }
        }
        double ratio_curr = static_cast<double>(edge_weight) / static_cast<double>(node_weight);
        if (ratio_curr < ratio) {
            answer.clear();
            answer.push_back(vector<int>(onPath.cbegin(), onPath.cend()));
            ratio = ratio_curr;
        }
        return;
    }
    for (int i = idx; i < n; i++) {
        onPath.push_back(i);
        solve(level + 1, i + 1, n, m, onPath, answer, ratio);
        onPath.pop_back();
    }
}

int main()
{
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        vertices = vector<int>(n);
        for (int i = 0; i < n; i++) {
            int w;
            cin >> vertices[i];
        }
        matrix = vector<vector<int>>(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        vector<int> onPath;
        vector<vector<int>> answer;
        double ratio = 1e9 + 7;
        solve(0, 0, n, m, onPath, answer, ratio);
        std::sort(answer.begin(), answer.end());
        for (auto elem : answer.front()) {
            cout << elem + 1 << ' ';
        }
        cout << '\n';
    }
}