#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data,TreeNode* left,TreeNode* right):data{data},left{left},right{right}{}
    TreeNode(int data):data{data},left{nullptr},right{nullptr}{}
    TreeNode():data{-1},left{nullptr},right{nullptr}{}
};
int huffman_wpl(TreeNode* root,int len){
    if(root == nullptr) return 0;
    if(!root->left && !root->right){
        // printf("%p %d %d\n",root,root->data,len);
        return root->data * len;
    }else{
        return huffman_wpl(root->left,len + 1) + huffman_wpl(root->right,len + 1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    vector<TreeNode*> table;
    table.reserve(n);
    for(int idx = 0;idx < n;idx++){
        int tmp;
        cin >> tmp;
        table.push_back(new TreeNode(tmp));
    }
    while(table.size() > 1){
        std::sort(table.begin(),table.end(),[](TreeNode* a,TreeNode* b){
            return a->data > b->data;
        });
        auto least1 = table.back();
        table.pop_back();
        auto least2 = table.back();
        table.pop_back();
        auto new_head = new TreeNode(least1->data + least2->data,least1,least2);
        table.push_back(new_head);
    }
    int ans = huffman_wpl(table.front(),0);
    printf("%d",ans);
}