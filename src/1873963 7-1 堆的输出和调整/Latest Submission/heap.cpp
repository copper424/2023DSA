#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int index = 0;index < N;index ++){
        int n;
        cin >> n;
        vector<int> arr(n,0);
        for(auto& elem:arr){
            cin >> elem;
        }
        int tmp = arr.front();
        arr.front() = arr.back();
        arr.back() = tmp;

        int prev = 0;
        int i = 1;
        while (i < (n - 1)){
            if ((i + 1 < (n - 1)) && arr[i + 1] < arr[i]){
                i += 1;
            }
            if (arr[prev] < arr[i]){
                break;
            }else{
                int tmp = arr[i];
                arr[i] = arr[prev];
                arr[prev] = tmp;
                prev = i;
                i = (2 * i + 1);
            }
        }
        
        for(auto elem:arr){
            printf("%d ",elem);
        }
        cout << '\n';
    }
}