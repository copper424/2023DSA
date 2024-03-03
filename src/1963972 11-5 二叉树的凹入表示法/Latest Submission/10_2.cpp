#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct TreeNode {
    char val; 
    int size{1};
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* build_tree(int x1,int y1,const string& preorder,int x2,int y2,const string& inorder){
    if(x1 > y1 || x2 > y2){
        return nullptr;
    }
    char root_value = preorder[x1]; int index = -1;
    for(int idx = x2 + 1;idx <= y2;idx++){
        if(root_value == inorder[idx]){
            index = idx; break;
        }
    }
    auto root_node = new TreeNode(root_value);
    if(index != -1){
        int left_size = index - x2;
        root_node->left = build_tree(x1 + 1,x1 + left_size,preorder,x2,index - 1,inorder);
        root_node->right = build_tree(x1 + left_size + 1,y1,preorder,index + 1,y2,inorder);
        if(root_node->left && root_node->right){
            root_node->size = root_node->left->size + root_node->right->size; 
        }else if(root_node->left){
            root_node->size = root_node->left->size;
        }else if(root_node->right){
            root_node->size = root_node->right->size;
        }
    }else{
        root_node->right = build_tree(x1 + 1,y1,preorder,x2 + 1,y2,inorder);
        if(root_node->right){
            root_node->size = root_node->right->size;
        }
    }
    return root_node;
}
int main(){
    std::string preorder;
    std::getline(std::cin,preorder,'\n');
    std::string inorder;
    std::getline(std::cin,inorder,'\n');
    auto root = build_tree(0,preorder.size() - 1,preorder,0,inorder.size() - 1,inorder);
    stack<TreeNode*> myStack;
    auto ptr = root;
    while(ptr != nullptr){
        while(ptr != nullptr){
            if(ptr->right){
                myStack.push(ptr->right);
            }
            for(int idx = 0;idx < ptr->size;idx++){
                printf("%c",ptr->val);
            }
            printf("\n");
            ptr = ptr->left;
        }
        if(!myStack.empty()){
            ptr = myStack.top();
            myStack.pop();
        }
    }
}