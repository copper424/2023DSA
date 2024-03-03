#include<iostream>
#include<ranges>
#include<string>
#include<vector>
struct TreeNode{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode():data{'!'},left{nullptr},right{nullptr}{}
    TreeNode(char data):data{data},left{nullptr},right{nullptr}{}
};
TreeNode* build_tree(const std::string& preorder,int& index){
    if (index >= preorder.size()){
        return nullptr;
    }
    if(preorder[index] == '#'){
        index += 1; return nullptr;
    }
    auto curr = new TreeNode(preorder[index++]);
    curr->left = build_tree(preorder,index);
    curr->right = build_tree(preorder,index);
    return curr;
}
void inorder_traverse(TreeNode* curr,std::vector<int>& arr){
    if(curr == nullptr) return;
    inorder_traverse(curr->left,arr);
    arr.push_back(curr->data);
    inorder_traverse(curr->right,arr);
}
int main(){
    std::string preorder;
    std::getline(std::cin,preorder,'\n');
    int index = 0;
    auto root = build_tree(preorder,index);
    std::vector<int> arr; 
    inorder_traverse(root,arr);
    printf("中序顺序遍历结果：\n");
    for(auto elem:arr){
        printf("%c ",elem);
    }
    printf("\n");

    printf("中序逆序遍历结果：\n");
    for(auto iter = arr.rbegin();iter != arr.rend();iter++){
        printf("%c ",*iter);
    }
    printf("\n");
}