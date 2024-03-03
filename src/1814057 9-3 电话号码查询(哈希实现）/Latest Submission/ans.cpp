#include<iostream>
#include<unordered_map>
#include<utility>
#include<string>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    cin.get();
    unordered_map<string,string> hash_table;
    hash_table.reserve(n);
    while(n--){
        std::string tmp;
        std::getline(std::cin,tmp);
        int pos = tmp.find(',');
        hash_table.insert(make_pair(tmp.substr(0,pos),tmp.substr(pos + 1,(tmp.size() - pos - 1))));
    }
    int m;
    scanf("%d",&m);
    cin.get();
    while(m--){
        string tmp;
        std::getline(std::cin,tmp);
        auto iter = hash_table.find(tmp);
        if(iter != hash_table.end()){
            cout << iter->first << ":" << iter->second << endl;
        }else{
            cout << tmp << ":No\n" ;
        }
    }
}