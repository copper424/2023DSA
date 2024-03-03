#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    vector<int> arr1(N);
    for(int i = 0;i < N;i++){
        cin >> arr1[i];
    }
    int target;
    cin >> target;
    int ans = 0;
    int diff = INT_MAX;
    for(int i = 0;i < N;i++){
        for(int j = i + 1;j < N;j++){
            for(int k = j + 1;k < N;k++){
                int sum = arr1[i] + arr1[j] + arr1[k];
                int diff2 = std::abs(target - sum);
                if(diff2 < diff){
                    diff = diff2;
                    ans = sum;
                }
            }
        }
    }
    printf("%d",ans);
}