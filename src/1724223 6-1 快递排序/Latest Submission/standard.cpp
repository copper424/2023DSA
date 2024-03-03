#include<iostream>
#include<vector>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    for(int index = 0;index < T;index++){
        int N;
        scanf("%d",&N);
        vector<int> arr(N);
        for(int index2 = 0;index2 < N;index2++){
            scanf("%d",&arr[index2]);
        }
        int Time = 0;
        for(int i = 1;i < arr.size();i++){
            bool flag = false;
            for(int j = i;j >= 1;j--){
                if(arr[j] < arr[j - 1]){
                    int tmp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = tmp;
                    flag = true;
                }
            }
            if(flag){
                    Time += 5;
            }
        }
        printf("%d\n",Time);
    }
} 