#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main(){
    int N;
    cin >> N;
    deque<int> q;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        if(s == "Count"){
            cout << q.size() << '\n';
        }else if(s == "In"){
            int number;
            cin >> number;
            q.push_back(number);
        }else if(s == "Out"){
            if (q.empty()){
                cout << -1 << '\n';
            }else{
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
    }
}