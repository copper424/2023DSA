#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> arr1(N,0);
    vector<int> arr2(N,0);
    for(int i = 0;i < N;i++){
        cin >> arr1[i];
    }
    for(int i = 0;i < N;i++){
        cin >> arr2[i];
    }
    bool is_stack = false;
    bool is_queue = false;
    if(arr1 == arr2){
        is_queue = true;
    }
    std::reverse(arr2.begin(),arr2.end());
    if(arr1 == arr2){
        is_stack = true;
    }
    if(is_stack && is_queue){
        cout << "both\n";
    }else if(is_queue){
        cout << "queue\n";
    }else if(is_stack){
        cout << "stack\n";
    }else{
        cout << "neither\n";
    }
}