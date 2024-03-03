#include<iostream>
#include<deque>
#include<utility>
#include<vector>
#include<array>
#include<cstdint>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n,vector<int>(m));
    vector<vector<int8_t>> visited(n,vector<int8_t>(m,false));
    for(int i = 0;i < matrix.size();i++){
        for(int j = 0;j < matrix[0].size();j++){
            cin >> matrix[i][j];
        }
    }
    vector<pair<int,int>> direction = {{0,-1},{0,1},{-1,0},{1,0}};
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    sx -= 1; sy -= 1; tx -= 1; ty -= 1;
    deque<pair<int,int>> dq(1,make_pair(sx,sy));
    bool flag = false; int length = 0;
    while(!dq.empty()){
        int sz = dq.size();
        while(sz--){
            auto elem = dq.front(); dq.pop_front();
            int x = elem.first; int y = elem.second;
            visited[x][y] = true;
            if(x == tx && y == ty){
                flag = true;
                goto label;
            }
            for(auto pa:direction){
                int dx = x + pa.first; int dy = y + pa.second;
                if(dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy] && matrix[dx][dy] != 1){
                    dq.push_back(make_pair(dx,dy));
                }
            }
        }
        length += 1;
    }
    label:
    if(flag){
        cout << length << '\n';
    }else{
        cout << "No\n";
    }
}