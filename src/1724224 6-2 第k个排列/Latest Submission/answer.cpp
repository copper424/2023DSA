#include<iostream>
#include<vector>
#include<stdint.h>
#include<algorithm>
using namespace std;

int fatroial(uint64_t n){
    uint64_t ans = 1;
    for(uint64_t i = 1;i <=n;i++){
        ans *= i;
    }
    return ans;
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> arr;
    arr.reserve(k);
    for(int i = 0;i < n;i++){
        arr.push_back(i + 1);
    }
    for(int i = 1;i < k;i++){
        std::next_permutation(arr.begin(),arr.end());
    }
    for(auto elem:arr){
        printf("%d",elem);
    }
    
}