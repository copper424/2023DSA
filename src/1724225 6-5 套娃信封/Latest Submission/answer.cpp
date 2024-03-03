#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<array<int,2>> arr(n,{0,0});
    for(int index = 0;index < n;index++){
        scanf("%d%d",&arr[index][0],&arr[index][1]);
    }
    std::stable_sort(arr.begin(),arr.end(),[](auto& a,auto& b){
            return a[0] < b[0];
    });
        
    vector<int> dp(n,1);
    dp[0] = 1;
    for(int i = 1;i < arr.size();i++){
        for(int j = 0;j < i;j++){
            if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1]){
                dp[i] = std::max(dp[i],dp[j] + 1);
            }
        }
    }
    int cnt = *std::max_element(dp.begin(),dp.end());
    printf("%d",cnt);
    // printf("%d",dp.back());
}