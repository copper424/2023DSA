#include <iostream>

#include <vector>

#include <stack>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int m;
        cin >> m;
        vector<int> p(m);
        vector<int> q(m);
        for(int i = 0;i < m;i++){
            cin >> p[i];
        }
        for(int i = 0;i < m;i++){
            cin >> q[i];
        }
        stack<int> myStack;
        int cnt = 0;
        for(int i = 0;i < m;i++){
            if(p[i] == q[cnt]){
                cnt += 1;
            }else if(!myStack.empty() && myStack.top() == q[cnt]){
                cnt += 1;
                myStack.pop();
                i--;
            }else{
                myStack.push(p[i]);
            }
        }
        while(!myStack.empty()){
            if(myStack.top() != q[cnt]){
                break;
            }else{
                myStack.pop();
                cnt += 1;
            }
        }
        if(myStack.empty()){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}