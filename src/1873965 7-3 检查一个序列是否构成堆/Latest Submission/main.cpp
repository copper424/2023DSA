#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }
    bool is_min = true;
    bool is_max = true;
    // check whether is min heap
    int i = 0;
    while ((2 * i + 1) < n){
        bool should_break = ((2 * i + 2) < n && arr[i] > arr[2 * i + 2]) || (arr[i] > arr[2 * i + 1]);
        if (should_break){
            is_min = false;
            break;
        }else{
            i = 2 * i + 1;
        }
    }

    i = 0;
    while ((2 * i + 1) < n){
        bool should_break = ((2 * i + 2) < n && arr[i] < arr[2 * i + 2]) || (arr[i] < arr[2 * i + 1]);
        if (should_break){
            is_max = false;
            break;
        }else{
            i = 2 * i + 1;
        }
    }
    if (is_max && is_min){
        printf("both\n");
    }else if (is_max){
        printf("max heap\n");
    }else if(is_min){
        printf("min heap\n");
    }else{
        printf("no\n");
    }
}