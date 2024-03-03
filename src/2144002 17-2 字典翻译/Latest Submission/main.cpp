#include<iostream>
#include<string>
#include<unordered_map>
#include<utility>

using namespace std;

int main(){ 
    unordered_map<string,string> table;
    
    std::string temp;
    for(int i = 0;i < 1e5;i++){
        std::getline(std::cin,temp,'\n');
        if(temp.empty()){
            break;
        }
        int pos = temp.find(' ');
        if(pos == 0){
            break;
        }
        string a = temp.substr(0,pos);
        int right_len = temp.size() - pos - 1;
        string b = temp.substr(pos + 1,right_len);
        // printf("%s %s\n",a.c_str(),b.c_str());
        table.insert(make_pair(b,a));
    }
    
    for(int i = 0;i < 1e5;i++){
        if(cin.eof()){
            break;
        }
        std::getline(std::cin,temp,'\n');
        // cout << "temp:" << temp << endl;
        if(temp.empty()){
            break;
        }
        auto iter = table.find(temp);
        if(iter == table.end()){
            cout << "eh\n";
        }else{
            cout << iter->second << endl;
        }
    }
}