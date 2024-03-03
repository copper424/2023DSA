#include<iostream>
#include<vector>
#include<queue>
#include<array>
using namespace std;
int main(){
    int k,m,n;
    scanf("%d%d%d",&k,&m,&n);
    vector<int> arr1(m);
    vector<int> arr2(n);
    for(int i = 0;i < m;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&arr2[i]);
    }
    if (k > m * n){
        for(auto elem:arr1){
            for(auto elem2:arr2){
                printf("%d,%d ",elem,elem2);
            }
        }
        printf("\n");
    }
    auto cmp = [&](auto& a,auto& b){
        return arr1[a.first] + arr2[a.second] > arr1[b.first] + arr2[b.second];
    };
    // auto pq = priority_queue(cmp,vector<pair<int,int>>);
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i = 0;i < m;i++){
        pq.push(make_pair(i,0));
    }
    for(int i = 0;i < k && !pq.empty();i++){
        auto [a,b] = pq.top();
        pq.pop();
        printf("%d,%d ",arr1[a],arr2[b]);
        if (b + 1 < n){
            pq.push(make_pair(a,b + 1));
        }
    }
}