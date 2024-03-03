#include<iostream>
#include<vector>
#include<array>
#include<type_traits>
#include<algorithm>
using namespace std;

bool is_symmetric(int curr,const vector<array<int,2>>& children,const vector<int>& weight){
    if(curr == -1 || children[curr][0] == -1 && children[curr][1] == -1){
        return true;
    }
    if(children[curr][0] != -1 && children[curr][1] != -1){
        return is_symmetric(children[curr][0],children,weight) && is_symmetric(children[curr][1],children,weight);
    }
    return false;
}

int solve1(int curr,const vector<array<int,2>>& children,const vector<int>& weight){
    if(curr == -1){
        return 0;
    }
    int left_size = solve1(children[curr][0],children,weight);
    int right_size = solve1(children[curr][1],children,weight);
    int tmp = 0;
    if(is_symmetric(curr,children,weight)){
        tmp = left_size + right_size + 1;
    }
    return max(left_size,max(right_size,tmp));
}

int main(){
    int n;
    cin >> n;
    vector<int> weight(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> weight[i];
    }
    vector<array<int,2>> children(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> children[i][0] >> children[i][1];
    }
    int maximum = 0;
    for(int i = 1;i <= n;i++){
        maximum = max(maximum,solve1(i,children,weight));
    }
    cout << maximum;
}