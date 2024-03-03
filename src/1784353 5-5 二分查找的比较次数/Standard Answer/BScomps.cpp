#include<iostream>
#include<vector>

using namespace std;

typedef int T;

pair<bool, int> binary_search(vector<T> list, int bot, int top, T target){
  if (top<bot)
     return make_pair(false, 0);
  if (bot==top){
     if (list[bot]==target)
          return make_pair(true, 1);
     else 
          return make_pair(false,1);
   }
  else {
     size_t mid = (bot + top)/2;
     if (list[mid] < target) {
        pair<bool,int> p =  binary_search(list, mid+1, top, target);
        return make_pair(p.first, 1+p.second);
     }
     else{
        pair<bool,int> p= binary_search(list, bot, mid, target);
        return make_pair(p.first, p.second+1);
    }
  } 
}

pair<bool, int> binary_search(vector<int> list, int target){
    return binary_search(list, 0, list.size()-1,target);
}