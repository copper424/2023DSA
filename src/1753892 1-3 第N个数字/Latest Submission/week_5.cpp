#include<iostream>
#include<string>
int main(){
    int t;
    std::cin >> t;
    std::string table;
    int cnt = 1;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        while (table.size() <= n){
            table.append(
                std::to_string(cnt)
            );
            cnt += 1;
        }
        std::cout << table[n - 1] << '\n';
    }
}