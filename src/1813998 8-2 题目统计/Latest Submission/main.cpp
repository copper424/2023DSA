#include<iostream>
#include<vector>
#include<stdio.h>
int main(){
    int A,B;
    scanf("%d%d",&A,&B);
    std::vector<std::vector<int>> table(A,std::vector<int>(2*B,0));
    int m,n,t;
    while(!feof(stdin)){
        scanf("%d %d %d",&m,&n,&t);
        if(feof(stdin)){
            break;
        }
        if (t == 1){
            table[m - 1][2 * (n - 1)] += 1;
        }else if (t == 0){
            table[m - 1][2 * (n - 1) + 1] += 1;
        }
        
    }
    for(auto& row : table){
        int i = 0;
        for(;i < row.size() - 1;i++){
            printf("%d ",row[i]);
        }
        printf("%d\n",row[i]);
    }
}