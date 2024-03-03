#include <iostream>
#include <vector>

using namespace std;

typedef int T;
struct BinaryNode{
  T data; //store data
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode* r=NULL):data(d), left(l), right(r) {};
};



void insert(BinaryNode* &root, T x){
  if (root==NULL)
     root = new BinaryNode(x);
  else if (x < root->data)
     insert(root->left,x);
  else insert(root->right, x);
  
}

int height(BinaryNode *root){
    if (root==NULL)
      return -1;
    else
      return 1 + max(height(root->left), height(root->right));
}
bool isAVL(BinaryNode *root){
    if (root==NULL)
       return true;
    else
       return (abs(height(root->left)-height(root->right))<=1) && isAVL(root->left)&& isAVL(root->right);
}

void clear(BinaryNode*root){
  if (root){
    clear(root->left);clear(root->right);
    delete root;
  }
}

int main(){
  int m, n,x;
  bool b;
  cin >> m;
  while (m--) {
    cin >> n;
    BinaryNode *root = NULL;
    for (int i=0;i<n;i++){
      cin >>x;
      insert(root, x);
     //b1 = isRegularBT(root);
      b = isAVL(root);
//cout<<"after insert "<<x<<":"<<b1<<endl;
    }
      if (b)
        cout <<"YES"<<endl;
      else
        cout <<"NO"<<endl;
    
   clear(root);    
 }
  return 0;
}

