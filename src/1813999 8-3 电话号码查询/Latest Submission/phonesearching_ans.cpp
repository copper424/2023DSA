#include<iostream>
#include<unordered_map>
#include<string>
#include<utility>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_map<string,string> table;
    table.reserve(n);
    for(int i = 0;i < n;i++){
        string tmp;
        cin >> tmp;
        int pos = tmp.find(',');
        string name (tmp.begin(),(tmp.begin() + pos));
        string num ((tmp.begin() + pos + 1),tmp.end());
        table.insert(make_pair(name,num));
    }
    int m;
    cin >> m;
    for(int i =0;i < m;i++){
        string query;
        cin >> query;
        auto iter = table.find(query);
        if(iter !=table.end()){
            cout << query << ":" << iter->second << endl;
        }else{
            cout << query << ":" << "No\n";
        }
    }
}