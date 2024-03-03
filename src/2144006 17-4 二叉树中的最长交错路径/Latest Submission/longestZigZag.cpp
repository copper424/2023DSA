#include"TreeNode.h"
#include<algorithm>
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
// };
// direct == 1 is left
static int count = 0;
void solve(TreeNode* root,bool direct,int cnt){
    if(!root){
        count = std::max(count,cnt  - 1);
        return ;
    }
    if(direct){
        solve(root->left,true,1);
        solve(root->right,false,cnt + 1);
    }else{
        solve(root->left,true,cnt + 1);
        solve(root->right,false,1);
    }   
    return ;
}

int longestZigZag(TreeNode* root){
    count = 0;
    solve(root,true,1);
    solve(root,false,1);
    return count;
}