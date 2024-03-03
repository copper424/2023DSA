#include<iostream>
#include<algorithm>
#include<vector>
#include<array>
using namespace std;

int main(){
    int k,m,n;
    scanf("%d%d%d",&k,&m,&n);
    vector<int> arr1(m);
    vector<int> arr2(n);
    for(int i = 0;i < m;i++){
        cin >> arr1[i];
    }
    for(int i = 0;i < n;i++){
        cin >> arr2[i];
    }
    if(k > m * n){
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                printf("%d,%d ",arr1[i],arr2[j]);
            }
        }
        return 0;
    }
    vector<array<int ,3>> arr3;
    arr3.reserve(m * n);
    for(auto elem1:arr1){
        for(auto elem2:arr2){
            arr3.push_back({elem1+elem2,elem1,elem2});
        }
    }
    std::sort(arr3.begin(),arr3.end(),[](auto& a,auto& b){
        return a[0] < b[0];
    });
    for(int i = 0;i < k;i++){
        printf("%d,%d ",arr3[i][1],arr3[i][2]);
    }
}