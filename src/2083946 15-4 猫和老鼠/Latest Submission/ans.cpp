#include <cstdint>
#include <cstring>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int MAX = 7;

// vector<vector<char>> grid;
int8_t dp[MAX][MAX][MAX][MAX][1000];

int row_offset[4] = { 0, 0, 1, -1 };
int col_offset[4] = { 1, -1, 0, 0 };

int rows,cols,fi, fj, mouseJump, catJump;

bool idx_is_valid(int i,int j){
    return i >= 0 && i < rows && j >= 0 && j < cols;
}

bool dfs(int ci,int cj,int mi,int mj,int steps,const vector<string>& grid){
        if(steps >= 128){
            return false;
        }
        if(dp[ci][cj][mi][mj][steps] != -1){
            return dp[ci][cj][mi][mj][steps];
        }
        // printf("%d %d\n",fi,fj);
        // printf("%d %d %d %d %d\n",ci,cj,mi,mj,steps);
        bool is_mouse = (steps & 0x1) == 0;
        bool ans = (is_mouse)?false:true;
        if(is_mouse){//mouse turn
            if(ci == mi && cj == mj) {
                ans = false;
            }else if(mi == fi && mj == fj){
                ans = true;
            }else if(ci == fi  && cj == fj){
                ans = false;
            }else{
                for(int idx = 0;idx < 4;idx++){
                    for(int scale = 0;scale <= mouseJump;scale++){
                        int mi2 = mi + scale * row_offset[idx];
                        int mj2 = mj + scale * col_offset[idx];
                        if(idx_is_valid(mi2,mj2) && grid[mi2][mj2] != '#'){
                            if(dfs(ci,cj,mi2,mj2,steps + 1,grid)){
                                ans = true;
                                goto label;
                            }
                        }else{
                            break;
                        }
                    }
                }
            }
        }else{//cat turn
            if(ci == mi && cj == mj){
                ans = false;
            }else if (ci == fi && cj == fj){
                ans = false;
            }else if(mi == fi && mj == fj){
                ans = true;
            }else{
                for(int idx = 0;idx < 4;idx++){
                    for(int scale = 0; scale <= catJump;scale++){
                        int ci2 = ci + scale * row_offset[idx];
                        int cj2 = cj + scale * col_offset[idx];
                        if(idx_is_valid(ci2,cj2) && grid[ci2][cj2] != '#'){
                            if(!dfs(ci2,cj2,mi,mj,steps + 1,grid)){
                                ans = false;
                                goto label;
                            }
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        label:
        dp[ci][cj][mi][mj][steps] = ans;
        return ans;
    }

int main()
{
    cin >> rows >> cols >> catJump >> mouseJump;
    // printf("%d %d %d %d\n",rows,cols,catJump,mouseJump);
    memset(dp, -1, sizeof(dp));
    vector<string> grid(rows,string(cols,'.'));
    int ci, cj, mi, mj;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char ch;
            cin.get(ch);
            if (isspace(ch)) {
                j--;
                continue;
            }
            // printf("%c",ch);
            grid[i][j] = ch;
            if (grid[i][j] == 'C') {
                grid[i][j] = '.';
                ci = i;
                cj = j;
            } else if (grid[i][j] == 'M') {
                grid[i][j] = '.';
                mi = i;
                mj = j;
            } else if (grid[i][j] == 'F') {
                grid[i][j] = '.';
                fi = i;
                fj = j;
            }
        }
        // cout << '\n';
    }
    if(dfs(ci, cj, mi, mj, 0, grid)){
        cout << "true\n";
    }else{
        cout << "false\n";
    }
}