#include<iostream>
#include<vector>
#include<cstdint>
using namespace std;


int main(){
    int n,h;
    scanf("%d%d",&n,&h);
    // dp[n][h] denotes the number of distinct binary search tree with n different values
    // and maximum height of h
    vector<vector<int64_t>> dp(n + 1,vector<int64_t>(n + 1,0));
    // Initialization
    for(int i = 0;i <= n;i++){
        dp[0][i] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            // k denotes the number of nodes in left subtree
            for(int k = 0;k < i;k++){
                dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1];
            }
        }
    }
    int64_t total = dp[n][n];
    int64_t less_than = dp[n][h - 1];
    printf("%lld\n",total - less_than);
}