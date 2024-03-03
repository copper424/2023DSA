#include<iostream>
#include"BST.h"

BinaryNode* insert(BinaryNode* node,T val){
    if(node == nullptr){
        return new BinaryNode(val);
    }
    if(node->data > val){
        node->left = insert(node->left,val);
    }else if(node->data < val){
        node->right = insert(node->right,val);
    }else{
        node->data = val;
    }
    return node;
}

int get_height(BinaryNode* node){
    if(!node)
        return 0;
    int l_height = get_height(node->left);
    int r_height = get_height(node->right);
    int height = ((l_height > r_height)?l_height:r_height) + 1;
    return height;
}

int main(){
    BinaryNode* root {nullptr};
    int n;
    std::cin >> n;
    while(n--){
        int a;
        std::cin >> a;
        root = insert(root,a);
    }
    std::cout << (get_height(root) - 1) << '\n';
}