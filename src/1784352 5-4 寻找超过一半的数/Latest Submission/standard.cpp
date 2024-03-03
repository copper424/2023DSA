#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    vector<int> arr(N);
    for(auto& elem:arr){
        cin >> elem;
    }
    int m = 0;
    int cnt = 0;
    for(auto elem:arr){
        if(cnt == 0){
            cnt += 1;
            m = elem;
        }else if(elem == m){
            cnt += 1;
        }else{
            cnt -= 1;
        }
    }
    cout << m;
}