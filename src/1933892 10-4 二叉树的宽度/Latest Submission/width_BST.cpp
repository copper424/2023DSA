#include<iostream>
#include<vector>
#include<deque>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data{-1},left{nullptr},right{nullptr}{}
    TreeNode(int data):data{data},left{nullptr},right{nullptr}{}
};

void insert_bst(TreeNode* root,int value){
    if(root == nullptr){
        return ;
    }
    if(root->data > value){
        if(root->left){
            insert_bst(root->left,value);
        }else{
            root->left = new TreeNode(value);
        }
    }else{
        if(root->right){
            insert_bst(root->right,value);
        }else{
            root->right = new TreeNode(value);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int idx = 0;idx < n;idx++){
        int count;
        cin >> count;
        TreeNode* root {nullptr};
        for(int i = 0;i < count;i++){
            int tmp;
            cin >> tmp;
            if(root){
                insert_bst(root,tmp);
            }else{
                root = new TreeNode(tmp);
            }
        }
        deque<TreeNode*> dq(1,root);
        int maximum = 0;
        while (!dq.empty()){
            int size = dq.size();
            maximum = (maximum > size)? maximum : size;
            for(int i = 0;i < size;i++){
                auto curr = dq.front();
                // printf("curr:%d\n",curr->data);
                dq.pop_front();
                if (curr->left){
                    dq.push_back(curr->left);
                }
                if(curr->right){
                    dq.push_back(curr->right);
                }
            }
        }
        printf("%d\n",maximum);
    }
}