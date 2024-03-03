#include<iostream>
#include<list>
#include<array>
using namespace std;
constexpr int MOD = 13;
int hash_key(int key){
    return key % MOD;
}

int main(){
    while(true){
        int n;
        scanf("%d",&n);
        if (n == 0) break;
        array<list<int>,MOD> table;
        for(int idx = 0;idx < n;idx++){
            int num; scanf("%d",&num);
            int pos = hash_key(num);
            table[pos].push_back(num);
        }
        for(int idx = 0;idx < table.size();idx++){
            printf("%d#",idx);
            if(table[idx].empty()){
                printf("NULL\n");
            }else{
                for(auto value:table[idx]){
                    printf("%d ",value);
                }
                printf("\n");
            }
        }
    }
}