#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    cin.get();
    for(int index = 0;index < n;index++){
        string tmp;
        while(true){
            char c;
            cin.get(c);
            if(c == '\n'){break;}
            tmp.push_back(c);
        }
        basic_istringstream<char> iss(tmp);
        
        int n;
        vector<int> arr;
        while(!iss.eof()){
            iss >> n;
            arr.push_back(n);
        }
        int cnt = 1;
        int val = arr.front();
        for(int i = 1;i < arr.size();i++){
            if(cnt == 0){
                cnt += 1;
                val = arr[i];
            }else if (val == arr[i]){
                cnt += 1;
            }else{
                cnt -= 1;
            }
        }
        cnt = 0;
        for(auto elem:arr){
            if (elem == val){
                cnt += 1;
            }
        }
        if (cnt > arr.size() /2){
            printf("%d\n",val);
        }else{
            printf("0\n");
        }
    }
}