#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct TreeNode{
    int val{0};
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};

};

TreeNode* build_tree(const vector<int>& table,int& index){
    if(index >= table.size())
        return nullptr;
    auto curr = new TreeNode;
    curr->val = table[index++];
    curr->left = build_tree(table,index);
    curr->right = build_tree(table,index);
    return curr;
}

TreeNode* insert(TreeNode* node,int val){
    if(node == nullptr){
        auto new_node = new TreeNode;
        new_node->val = val;
        return new_node;
    }
    if(val > node->val){
        node->right = insert(node->right,val);
    }else if (val < node->val){
        node->left = insert(node->left,val);
    }
    return node;
}

int traverse(TreeNode* node,bool& flag){
    if(node == nullptr || !flag){
        return 0;
    }
    // printf("%d %p\n",node->val,node);
    int l_height = traverse(node->left,flag);
    int r_height = traverse(node->right,flag);
    int bf = l_height - r_height;
    if(std::abs(bf) > 1){
        flag = false;
    }
    int height = ((l_height > r_height)?l_height:r_height) + 1;
    return height;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        TreeNode* root = nullptr;
        while(num--){
            int a;
            cin >> a;
            root = insert(root,a);
        }
        bool flag = true;
        traverse(root,flag);
        if(flag){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}