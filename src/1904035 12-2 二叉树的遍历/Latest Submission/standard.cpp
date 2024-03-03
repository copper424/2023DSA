#include<iostream>
#include<vector>
#include<string>
#include<deque>
using namespace std;
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    char val;
};
TreeNode* build_tree(const string& preorder,int x1,int y1,const string& inorder,int x2,int y2){
    if(x1 > y1 || x2 > y2){
        return nullptr;
    }
    auto root_value = preorder[x1];int index = -1;
    for(int idx = x2;idx <= y2;idx++){
        if(inorder[idx] == root_value){
            index = idx; 
            break;
        }
    }
    auto new_head = new TreeNode;
    new_head->val = root_value;
    new_head->left = nullptr;
    new_head->right = nullptr;
    if(index != -1){
        int left_size = index - x2;
        new_head->left = build_tree(
            preorder,x1 + 1, x1 + left_size,
            inorder,x2,index - 1
        );
        new_head->right = build_tree(
            preorder,x1 + left_size + 1,y1,
            inorder,index + 1,y2
        );
    }else{
        new_head->right = build_tree(
            preorder,x1 + 1,y1,
            inorder,x2,y2
        );
    }
    
    return new_head;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string preorder;
        string inorder;
        std::getline(std::cin,preorder,' ');
        std::getline(std::cin,inorder,'\n');
        
        auto root = build_tree(preorder,0,preorder.size() - 1,inorder,0,inorder.size() - 1);
        deque<TreeNode*> dq(1,root);
        while(!dq.empty()){
            auto current = dq.front();dq.pop_front();
            printf("%c",current->val);
            if(current->left){
                dq.push_back(current->left);
            }
            if(current->right){
                dq.push_back(current->right);
            }
        }
        printf("\n");
    }
}