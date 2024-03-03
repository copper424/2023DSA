#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int k;
    cin >> k;
    auto cmp = [](auto a,auto b){
        return a > b;
    };
    for(int index = 0;index < k;index++){
        int m;
        cin >> m;
        vector<int> A(m);
        for(int i = 0;i < m;i++){
            cin >> A[i];
        }
        int n;
        cin >> n;
        vector<int> B(n);
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        for(int i = 0;i < n;i++){
            cin >> B[i];
        }
        for(int i = 0;i < m;i++){
            if(!std::binary_search(B.cbegin(),B.cend(),A[i])){
                pq.push(A[i]);
            }
        }
        for(int i = 0;i < n;i++){
            if(!std::binary_search(A.cbegin(),A.cend(),B[i])){
                // cout << B[i] << ' ';
                pq.push(B[i]);
            }
        }
        while(!pq.empty()){
            cout << pq.top() << ' ';
            pq.pop();
        }
        cout << '\n';
    }
}