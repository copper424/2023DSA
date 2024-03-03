#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void shell_once(vector<int> &v, int increment){
    for(int i = 0;i < increment;i++){
        for(int j = i;j < v.size();j += increment){

            for(int k = j - increment;k >= 0;k -= increment){
                if(v[k] > v[k + increment]){
                    std::swap(v[k],v[k + increment]);
                }
            }
        }
    }
}