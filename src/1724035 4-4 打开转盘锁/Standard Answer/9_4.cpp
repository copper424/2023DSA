#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

int openLock(vector<string>& deadends, string target) {
	unordered_set<string> deadlock(deadends.begin(), deadends.end());
	if (deadlock.count("0000")) return -1;
	int res = 0;
	unordered_set<string> visited{ { "0000" } };
	queue<string> q{ { "0000" } };
	while (!q.empty()) {
		++res;
		for (int k = q.size(); k > 0; --k) {
			auto t = q.front(); q.pop();
			for (int i = 0; i < t.size(); ++i) {
				char c = t[i];
				string str1 = t.substr(0, i) + to_string(c == '9' ? 0 : c - '0' + 1) + t.substr(i + 1);
				string str2 = t.substr(0, i) + to_string(c == '0' ? 9 : c - '0' - 1) + t.substr(i + 1);
				if (str1 == target || str2 == target) return res;
				if (!visited.count(str1) && !deadlock.count(str1)) q.push(str1);
				if (!visited.count(str2) && !deadlock.count(str2)) q.push(str2);
				visited.insert(str1);
				visited.insert(str2);
			}
		}
	}
	return -1;
}

int main()
{
	int n;
	string target;
	vector<string> deadends;
	cin >> target;
	while (cin >> n)
	{
		string tmp;
		for (int i = 0; i<n; i++)
		{
			cin >> tmp;
			deadends.push_back(tmp);
		}
		int result = openLock(deadends, target);
		cout << result << endl;
	}
	return 0;
}
