#include<iostream>
#include<vector>
#include<cstdint>
using namespace std;

void traverse(int level,int n,vector<int8_t>& visited,vector<int>& res){
    if(level == n){
        for(auto elem:res){
            printf("%d",elem);
        }
        printf("\n");
        return;
    }
    for(int i = 1;i < visited.size();i++){

        if(!visited[i]){
            visited[i] = true;
            res.push_back(i);
            traverse(level + 1,n,visited,res);
            res.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    int m;
    cin >> m;
    while(m--){
        int n;
        cin >> n;
        vector<int8_t> arr(n + 1);
        vector<int> res;
        for(int i = 0;i < arr.size();i++){
            arr[i] = false;
        }
        traverse(0,n,arr,res);
    }
}