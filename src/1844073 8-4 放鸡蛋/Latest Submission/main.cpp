#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void dfs(int m,int n,int i,vector<int>& table,set<vector<int>>& ans){
    // printf("reach,%d %d %d\n",m,n,i);
    if (i >= n){
        vector<int> arr(table.begin(),table.end());
        sort(arr.rbegin(),arr.rend());
        auto iter = ans.find(arr);
        if(iter == ans.end() && m <= 0){
            ans.insert(arr);
        }
        return;
    }
    for(int j = 0;j <= m;j++){
        table.push_back(j);
        dfs(m - j,n,i + 1,table,ans);
        table.pop_back();
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int index = 0;index < t;index++){
        int m,n;
        scanf("%d%d",&m,&n);
        vector<int> table;
        table.reserve(n);
        set<vector<int>> ans;
        dfs(m,n,0,table,ans);
        for(auto arr = ans.rbegin();arr != ans.rend();arr++){
            for(auto elem:*arr){
                printf("%d",elem);
            }
            printf("\n");
        }
    }
}