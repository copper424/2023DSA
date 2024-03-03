#include<iostream> 
#include<vector>
#include<utility>
#include<queue>
using namespace std;
bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int size = 0;
        vector<int> degree(numCourses, 0);
        queue<int> q;
        for (int i = 0; i < prerequisites.size(); i++) {
            degree[prerequisites[i].second]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            size++;
            for (int i = 0; i < prerequisites.size(); i++) {
                if (prerequisites[i].first == front) {
                    if (--degree[prerequisites[i].second] == 0) q.push(prerequisites[i].second);
                }
            }
        }
        return size == numCourses;
    }
int main(){
	int T;
	cin >>T;
	int total=T;
	vector< pair<int, int> > prerequisites;
	int n;
	cin >>n;
	while(n--){
		int a,b;
		cin >> a>>b;
		pair<int, int> p2(a,b);
		prerequisites.push_back(p2);
	}
	cout<<canFinish(total,  prerequisites)<<endl;
}
