#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> st;
    int ans = 0;
    for(int i = 0;i < 2 * n;i++){
        string s;
        cin >>  s;
        if(s == "add"){
            int num;
            cin >> num;
            st.push_back(num);
        }else if(s == "remove"){
            if(is_sorted(st.rbegin(),st.rend())){
                st.pop_back();
            }else{
                std::sort(st.rbegin(),st.rend());
                st.pop_back();
                ans += 1;
            }
        }
    }
    std::cout << ans;
}