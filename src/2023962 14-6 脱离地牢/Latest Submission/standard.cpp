#include<iostream>
#include<vector>
#include<array>
#include<climits>
#include<algorithm>
#include<deque>
#include<cstdint>
#include<cstring>
using namespace std;

struct State{
    int p_x,p_y,h_x,h_y,step;
};

vector<vector<char>> matrix;

array<array<int,2>,4> direction;
// N S W E
array<array<int,2>,4> offset{{{{-1,0}},{{1,0}},{{0,-1}},{{0,1}}}};

constexpr int MAX_SIZE = 20;

int8_t visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];

bool index_is_valid(int x,int y){
    return x >= 0 && y >= 0 && (x <= matrix.size() - 1) && (y <= matrix[0].size() - 1) && matrix[x][y] != '!';
}



int main(){
    memset(visited,0,sizeof(visited));
    int n,m;
    cin >> n >> m;
    matrix.assign(n,vector<char>(m,'\0'));
    int p_x,p_y,h_x,h_y;
    p_x = p_y = h_x = h_y = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 'H'){
                h_x = i; h_y = j;
                matrix[i][j] = '.';
            }else if(matrix[i][j] == 'P'){
                p_x = i; p_y = j;
                matrix[i][j] = '.';
            }
        }
    }
    for(int i = 0;i < 4;i++){
        char ch;
        cin >> ch;
        switch(ch){
            case 'N':{
                direction[i] = offset[0]; break;
            }
            case 'S':{
                direction[i] = offset[1]; break;
            }
            case 'W':{
                direction[i] = offset[2]; break;
            }
            case 'E':{
                direction[i] = offset[3]; break;
            }
            default:{
                cout << "Error Input!\n"; return -1;
            }
        }
    }
    State start; start.p_x = p_x; start.p_y = p_y;
    start.h_x = h_x; start.h_y = h_y; start.step = 0;
    deque<State> dq(1,start);
    while(!dq.empty()){
        auto curr = dq.front(); dq.pop_front();
        if(curr.step >= 256){
            break;
        }
        State new_state;
        for(int i = 0;i < 4;i++){
            new_state.p_x = offset[i][0] + curr.p_x;
            new_state.p_y = offset[i][1] + curr.p_y;
            new_state.h_x = direction[i][0] + curr.h_x;
            new_state.h_y = direction[i][1] + curr.h_y;
            new_state.step = curr.step + 1;
            if(matrix[new_state.h_x][new_state.h_y] == '#'){
                new_state.h_x = curr.h_x;
                new_state.h_y = curr.h_y;
            }

            if(matrix[new_state.p_x][new_state.p_y] == '.' && 
            matrix[new_state.h_x][new_state.h_y] != '!' && 
            !visited[new_state.p_x][new_state.p_y][new_state.h_x][new_state.h_y]){
                if((new_state.p_x == new_state.h_x && new_state.p_y == new_state.h_y) || (new_state.p_x == curr.h_x && new_state.p_y == curr.h_y && 
                new_state.h_x == curr.p_x && 
                new_state.h_y == curr.p_y)){
                    cout << new_state.step;
                    goto label;
                }
                visited[new_state.p_x][new_state.p_y][new_state.h_x][new_state.h_y] = true;
                dq.push_back(new_state);
            }
        }
    }
    cout << "Impossible\n";
    label:
    return 0;
}