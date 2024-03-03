#include<stack>
#include<string>
#include<iostream>
using namespace std;
bool match(const string & line){
    std::stack<char> s;
    for(auto elem:line){
        // cout << "elem:" << elem << '\n';
        if (elem == '(' || elem == '[' || elem == '{'){
            s.push(elem);
        }else if(elem == ')'){
            if (s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }else if (elem == ']'){
            if (s.empty() || s.top() != '['){
                return false;
            }
            s.pop();
        }else if (elem == '}'){
            if (s.empty() || s.top() != '{'){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}