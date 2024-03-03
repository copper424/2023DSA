#include<iostream>

using namespace std;

constexpr int MOD = 1e9 + 7;

int solve(int n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    int a=1;
    int b=2;
    int ans = 0;
    for(int i = 0;i < (n - 2);i++){
        ans = (a + b) % MOD;
        a = b;
        b = ans;
    }
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        int n;
        scanf("%d",&n);
        // int ans = solve(n);
        printf("%d\n",solve(n));
    }
}