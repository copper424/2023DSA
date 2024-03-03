#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    char delimiter;
    scanf("%c",&delimiter);
    for(int index = 0;index < n;index++){
        string myString;
        std::getline(cin,myString);
        std::istringstream iss(myString);
        vector<string> arr;
        string tmp;
        while(std::getline(iss,tmp,' ')){
            arr.push_back(tmp);
        }

        std::sort(arr.begin(),arr.end(),[](auto& a,auto& b){
            int i,j;
            i = j = 0;
            while (i < a.size() && j < b.size()){
                if (a[i] < b[i]){
                    return true;
                }else if (a[i] > b[i]){
                    return false;
                }
                i += 1;
                j += 1;
            }
            if (i >= a.size() && j < b.size()){
                return true;
            }
            if (i < a.size() && j >= b.size()){
                return false;
            }
            return false;
        });
        for(auto& elem:arr){
            cout << elem;
        }
        cout << endl;
    }
}