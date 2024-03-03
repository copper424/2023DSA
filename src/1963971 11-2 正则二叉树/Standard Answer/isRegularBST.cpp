#include <iostream>
#include <vector>

using namespace std;

typedef int T;
struct BinaryNode{
  T data; //store data
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode* r=NULL):data(d), left(l), right(r) {};
};

bool isRegularBT_qhy(BinaryNode* root){
   if (root==NULL)
     return false;
   else if (root->left ==NULL && root->right == NULL)
       return true;
   else
     return isRegularBT_qhy(root->left) && isRegularBT_qhy(root->right);
}

void insert(BinaryNode* &root, T x){
  if (root==NULL)
     root = new BinaryNode(x);
  else if (x < root->data)
     insert(root->left,x);
  else insert(root->right, x);
  
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
      b = isRegularBT_qhy(root);
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

