#include<iostream>
#include<utility>
#include<vector>
using namespace std;

pair<bool,int> helper(vector<int>& list,int low,int high,int target){
    if(low > high){
        return make_pair(false,0);
    }else if (low == high){
        if (list[low] == target){
            return make_pair(true,1);
        }else{
            return make_pair(false,1);
        }
    }else{
        int mid = (low + high) / 2;
        int x = list[mid];
        if (target > x){
            auto elem = helper(list,mid + 1,high,target);
            elem.second += 1;
            return elem;
        }else{
            auto elem = helper(list,low,mid,target);
            elem.second += 1;
            return elem;
        }
    }
}

pair<bool,int> binary_search(vector<int> list,int target){
    auto elem = helper(list,0,list.size() - 1,target);
    return elem;
}