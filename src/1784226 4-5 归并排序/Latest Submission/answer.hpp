#include<vector>
#include<cstdint>
#include<iostream>
using namespace std;
template<typename T>
auto merge(T begin,T mid,T end) -> void{
    vector<typename T::value_type> tmp(begin,end);
    // begin..guard
    int p1 = 0;
    int guard = mid - begin; 
    int p2 = guard;
    // guard..end
    int sz = end - begin;
    for(T iter = begin;iter != end;iter++){
        if(p1 >= guard){
            *iter = tmp[p2++];
        }else if(p2 >= sz){
            *iter = tmp[p1++];
        }else if(tmp[p1] > tmp[p2]){
            *iter = tmp[p2++];
        }else{
        // tmp[p1] <= tmp[p2]
            *iter = tmp[p1++];
        }
    }
}
template <typename T>
void mergeSort(T begin, T end){
    if(begin == end || begin + 1 == end){
        return;
    }
    T mid = begin + (end - begin) / 2;
    mergeSort(begin,mid);
    mergeSort(mid,end);
    merge(begin,mid,end);
}