#include "BST.h"


void insert(BinaryNode* &root, T x){
  if (!root){
     root = new BinaryNode(x);
     return;
  }
  else if (x < root-> data)
     insert(root->left, x);
  else if (x > root->data)
     insert(root->right, x);
}


BinaryNode* buildTree(){
  BinaryNode* root = NULL;

  int n;
  T a;
  
  cin >> n;
  while (n--){
    cin >> a;
    insert(root, a);
  }

  return root;
}

int height(BinaryNode* root){

   if (!root)
     return -1;
   else
     return 1 + max(height(root->left), height(root->right));
}


int main(){
  BinaryNode* root = buildTree();
  int h = height(root);
  cout<<h<<endl;
}