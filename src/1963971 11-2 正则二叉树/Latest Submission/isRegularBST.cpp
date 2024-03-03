#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* build(int start,int end,const vector<int>& elem){
    if(start > end){
        return nullptr;
    }
    auto middle = elem[start];int pivot = -1;
    for(int i = start + 1;i <= end;i++){
        if(elem[i] > middle){
            pivot = i;break;
        }
    }
    auto root = new TreeNode(middle);
    if(pivot == -1){
        root->left = build(start + 1,end,elem);
    }else{
        root->left = build(start + 1,pivot - 1,elem);
        root->right = build(pivot,end,elem);
    }
    return root;
}
void traverse(TreeNode* node,bool& flag){
    if(node == nullptr || (!node->left && !node->right) || !flag){
        return;
    }
    if(node->left && node->right){
        traverse(node->left,flag);
        traverse(node->right,flag);
    }else{
        flag = false;
    }
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        vector<int> tmp(m);
        for(int i = 0;i < m;i++){
            cin >> tmp[i];
        }
        auto root = build(0,m - 1,tmp);
        bool flag = true;
        traverse(root,flag);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}