#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int M;
    cin >> M;
    while(M--){
        int N;
        cin >> N;
        vector<int> table(N);
        for(int i = 0;i < N;i++){
            cin >> table[i];
        }
        for(int i = 0;i < N - 1;i++){
            int min_idx = i;
            for(int j = i + 1;j < N;j++){
                if(table[j] < table[min_idx]){
                    min_idx = j;
                }
            }
            std::swap(table[i],table[min_idx]);
            for(auto elem:table){
                cout << elem << " ";
            }
            cout << '\n';
        }
    }
}