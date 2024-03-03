#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target){
    auto iter = std::lower_bound(nums.begin(),nums.end(),target);
    if(iter == nums.end() || *iter != target){
        vector<int> ans = {-1,-1};
        return ans;
    }
    int i = iter - nums.begin();
    // cout << "i:" << i;
    iter = std::upper_bound(nums.begin(),nums.end(),target);
    int j = iter - nums.begin() - 1;
    // cout << "j:" << j << endl;
    vector<int> ans = {i,j};
    return ans;
}