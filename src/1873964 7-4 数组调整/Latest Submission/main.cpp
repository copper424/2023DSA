#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char delimiter;
    scanf("%c",&delimiter);
    for(int i = 0;i < n;i++){
        string myString;
        std::getline(cin,myString);
        std::istringstream iss(myString);
        vector<int> arr;
        int number;
        while(iss >> number){
            arr.push_back(number);
        }
        std::stable_sort(arr.begin(),arr.end(),[](int a,int b){
            // a is odd and b is even
            if ((a & 0x1) && !(b & 0x1)){
                return true;
            }else{
                return false;
            }
        });
        for(auto elem:arr){
            printf("%d ",elem);
        }
        printf("\n");
    }
}