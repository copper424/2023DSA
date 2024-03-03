#include<iostream>

int main(){
    int t;
    std::cin >> t;
    for(int i = 0;i < t;i++){
        int arr[3];
        std::cin >> arr[0] >> arr[1] >> arr[2];
        int ans = 0;
        for(int j = 0;j<3;j++){
            int num;
            std::cin >> num;
            if (num == arr[j]){
                ans += 1;
            }
        }
        std::cout << ans << '\n';
    }
}