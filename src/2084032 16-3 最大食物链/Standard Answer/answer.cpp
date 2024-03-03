#include <iostream>
#include <queue>
using namespace std;

const int P = 80112002;
const int MAXN = 5001;
const int MAXM = 500001;

struct Point {
    int num, comein, sum;
} p[MAXN];

struct Side {
    int next, to;
} s[MAXM];

int fr[MAXN], tails, n, m, p1, p2, nowuse;
queue<int> ready;
long long total;

void add(int from, int to) {
    s[++tails].to = to;
    s[tails].next = fr[from];
    fr[from] = tails;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> p1 >> p2;
        add(p1, p2);
        p[p2].comein++;
    }

    for (int i = 1; i <= n; i++) {
        if (!p[i].comein)
            p[i].sum = 1, ready.push(i);
        p[i].num = i;
    }

    while (!ready.empty()) {
        nowuse = ready.front();
        ready.pop();
        int lzh = fr[p[nowuse].num];

        if (!lzh)
            total = (total + p[nowuse].sum) % P;

        for (; lzh; lzh = s[lzh].next) {
            p[s[lzh].to].sum = (p[s[lzh].to].sum + p[nowuse].sum) % P;
            if (!(--p[s[lzh].to].comein))
                ready.push(s[lzh].to);
        }
    }

    cout << total % P;

    return 0;
}
