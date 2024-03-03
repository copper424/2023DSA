#include<utility>
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0;i < T;i++){
        int N;
        cin  >> N;
        vector<int> arr(N,0);
        for(int j = 0;j < N;j++){
            cin >> arr[j];
        }
        int ans = 0;
        int k = 0;
        while (k < N){
            int tmp = 1;
            while(k + 1 < N && arr[k+1] > arr[k]){
                k += 1;
                tmp += 1;
            }
            ans = std::max(ans,tmp);
            if (k + 1 >= N){
                break;
            }
            if (arr[k + 1] <= arr[k]){
                k += 1;
            }
        }
        cout << ans << endl;
    }
}