#include<iostream>
#include<array>
#include<deque>
#include<utility>
#include<vector>
#include<cstdint>
using namespace std;

int main(){
    array<int,4> row_offset = {0,0,1,-1};
    array<int,4> col_offset = {1,-1,0,0};
    while(true){
        int N; cin >> N;
        if(N == 0){
            break;
        }
        vector<vector<int>> graph(N,vector<int>(N,0));
        vector<vector<int8_t>> visited(N,vector<int8_t>(N,false));
        for(int i  = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                cin >> graph[i][j];
            }
        }
        int cnt = 0; bool flag = false;
        deque<pair<int,int>> dq;
        dq.push_back(make_pair(0,0));
        while(!dq.empty()){
            cnt += 1;
            int sz = dq.size();            
            for(int index = 0;index < sz;index++){
                auto curr = dq.front(); dq.pop_front();
                int x = curr.first; int y = curr.second;
                visited[x][y] = true;
                if(x == N - 1 && y == N - 1){
                    flag = true;
                    goto label;
                }
                for(int i = 0;i < 4;i++){
                    int x1 = x + row_offset[i];
                    int y1 = y + col_offset[i];
                    if(x1 >= 0 && y1 >= 0 && x1 < N && y1 < N && graph[x1][y1] != 1 &&!visited[x1][y1]){
                        dq.push_back(make_pair(x1,y1));
                    }
                }
            }
        }
        label:
        if(flag){
            printf("%d\n",cnt);
        }else{
            printf("0\n");
        }
    }
}