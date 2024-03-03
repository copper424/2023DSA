#include<iostream>
#include<vector>
#include<deque>

using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* build_tree(const vector<char>& preorder,const vector<char>& inorder,int i1,int j1,int i2,int j2){
    if(i1 > j1 || i2 > j2){
        return nullptr;
    }
    char root = preorder[i1]; int index = -1;
    for(int idx = i2;idx <= j2;idx += 1){
        if (inorder[idx] == root){
            index = idx;
            break;
        }
    }
    if(index == -1){
        return nullptr;
    }
    auto curr = new TreeNode(root);
    int left_len = index - i2;
    curr->left = build_tree(preorder,inorder,
        i1 + 1,i1 + left_len,
        i2,index - 1);
    curr->right = build_tree(preorder,inorder,
        i1 + left_len + 1,j1,
        index + 1,j2);
    return curr;
}

int main(){
    vector<char> preorder;
    vector<char>inorder;
    char ch = '!';
    while(!feof(stdin)){
        cin.get(ch);
        if(ch == '\n'){
            break;
        }
        preorder.push_back(ch);
    }
    while(!feof(stdin)){
        cin.get(ch);
        if(ch == '\n'){
            break;
        }
        inorder.push_back(ch);
    }
    int last = preorder.size() - 1;
    auto root = build_tree(preorder,inorder,0,last,0,last);
    deque<TreeNode*>dq;
    dq.push_back(root);
    while(!dq.empty()){
        auto curr = dq.front();
        dq.pop_front();
        printf("%c",curr->val);
        if(curr->left){
            dq.push_back(curr->left);
        }
        if(curr->right){
            dq.push_back(curr->right);
        }
    }
    return 0;
}