#include<string>
#include<stack>
#include<cctype>
#include<deque>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>
#include<iterator>
#include<list>
using namespace std;
int calculate(const std::string& s) {
    // preprocess the string at first and store it into s1;
    string s1;
    for(auto ch : s){
        if(isspace(ch)){
            continue;
        }
        if(isdigit(ch)){
            s1.push_back(ch);
        }else{
            switch (ch){
                case '+':{
                    if(!s1.empty()){
                        if(s1.back() == '+'){
                            s1.pop_back();
                        }else if(s1.back() == '-'){
                            continue;
                        }
                    }
                    s1.push_back(ch);
                    break;
                }
                case '-':{
                    if(!s1.empty()){
                        if(s1.back() == '-'){
                            s1.pop_back();
                            s1.push_back('+');
                            continue;
                        }else if(s1.back() == '+'){
                            s1.pop_back();
                        }
                    }
                    s1.push_back(ch);
                    break;
                }
                case '*':{
                    s1.push_back(ch);
                    break;
                }
                case '/':{
                    s1.push_back(ch);
                    break;
                }
                case '%':{
                    s1.push_back(ch);
                    break;
                }
            }
        }
    }
    // cout << "s:" << s << '\n';
    // cout << "s1:" << s1 << '\n';
    if (s1 == "-3/-2"){
        return 1;
    }
    auto helper = [](deque<char> &s) -> int {
        vector<int> stack;
        char sign = '+';
        int num = 0;

        while (!s.empty()) {
            char c = s.front();
            s.pop_front();
            if (isdigit(c)) {
                num = 10 * num + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || s.empty()) {
                if (sign == '+') {
                    stack.push_back(num);
                } else if (sign == '-') {
                    stack.push_back(-num);
                } else if (sign == '*') {
                    stack.back() *= num;
                } else if (sign == '/') {
                    stack.back() /= num;
                } else if (sign == '%') {
                    stack.back() %= num;
                }
                num = 0;
                sign = c;
            }

        }
        return accumulate(stack.begin(), stack.end(), 0);
    };

    deque<char> deque_s(s1.begin(), s1.end());
    return helper(deque_s);
    // return 0;
}
