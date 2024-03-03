#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val{val}{}
};

TreeNode* build_tree(int i1,int j1,const vector<int>& preorder,int i2,int j2,const vector<int>& inorder){
    if(i1 > j1 || i2 > j2){
        return nullptr;
    }
    // printf("i1:%d,j1:%d,i2:%d,j2:%d\n",i1,j1,i2,j2);
    int root = preorder[i1]; int index = -1;
    for(int idx = i2;idx <= j2;idx++){
        if (inorder[idx] == root){
            index = idx;
            break;
        }
    }

    auto ptr = new TreeNode(root);
    int left_len = index - i2;
    ptr->left = build_tree(i1 + 1,i1 + left_len,preorder,i2,index - 1,inorder);
    ptr->right = build_tree(i1 + left_len + 1 ,j1,preorder,index + 1,j2,inorder);
    return  ptr;
}
int get_max(TreeNode* root){
    if(root == nullptr){
        return INT_MIN;
    }
    int left_max = get_max(root->left);
    int right_max = get_max(root->right);
    return max(max(left_max,right_max),root->val);
}
int get_min(TreeNode* root){
    if(root == nullptr){
        return INT_MAX;
    }
    int left_min = get_min(root->left);
    int right_min = get_min(root->right);
    return min(min(left_min,right_min),root->val);
}
bool is_valid(TreeNode* root){
    if(root == nullptr){
        return true;
    }

    if ( root->left != nullptr && get_max(root->left) >= root->val){
        return false;
    }
    if (root->right != nullptr && get_min(root->right) <= root->val){
        return false;
    }

    return is_valid(root->left) && is_valid(root->right);
}
int main(){
    int n = 0;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        vector<int> preorder(m);
        vector<int> inorder(m);
        for(int i = 0;i < m;i++){
            scanf("%d",&preorder[i]);
        }
        for(int i = 0;i < m;i++){
            scanf("%d",&inorder[i]);
        }
        
        auto root = build_tree(0,m - 1,preorder,0,m - 1,inorder);
        if(is_valid(root)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}