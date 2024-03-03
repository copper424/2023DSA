#include<iostream>
#include<string>
#include<deque>
using namespace std;

struct TreeNode{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data{'!'},left{nullptr},right{nullptr}{}
    TreeNode(char data):data{data},left{nullptr},right{nullptr}{}
};

TreeNode* build_tree(const string& preorder,int x1,int y1,const string& inorder,int x2,int y2){
    if(x1 > y1 || x2 > y2){
        return nullptr;
    }
    char root = preorder[x1];
    int index = -1;
    for(int idx = x2;idx <= y2;idx++){
        if(inorder[idx] == root){
            index = idx; 
            break;
        }
    }
    if(index == -1) {return nullptr;}
    auto curr = new TreeNode(root);
    int left_size = index - x2;
    curr->left = build_tree(
        preorder, x1 + 1, x1 + left_size,
        inorder,x2,index - 1
    );
    curr->right = build_tree(
        preorder, x1 + left_size + 1, y1,
        inorder,index + 1,y2
    );
    return curr;
}

int main(){
    string preorder;
    std::getline(std::cin,preorder,'\n');
    string inorder;
    std::getline(std::cin,inorder,'\n');
    // printf("%s %s\n",preorder.c_str(),inorder.c_str());
    int last = preorder.size() - 1;
    auto root = build_tree(preorder,0,last,inorder,0,last);
    if(root == nullptr){
        return 0;
    }
    deque<TreeNode*> dq;
    dq.push_back(root);
    while(!dq.empty()){
        int size = dq.size();
        for(int idx = 0;idx < size;idx++){
            auto curr = dq.front();
            dq.pop_front();
            printf("%c",curr->data);
            if(curr->left){
                dq.push_back(curr->left);
            }
            if(curr->right){
                dq.push_back(curr->right);
            }
        }
    }
}