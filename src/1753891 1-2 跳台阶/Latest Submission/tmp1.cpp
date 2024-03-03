#include<iostream>

int solve(int n){
    if (n == 1){
        return 1;
    }
    if (n == 2){
        return 2;
    }
    int a = 1;
    int b = 2;
    int c = 0;
    for(int i = 2;i < n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int t;
    std::cin >> t;
    for(int i = 0;i < t;i++){
        int n;
        std::cin >> n;
        std::cout << solve(n) << '\n';
    }
}