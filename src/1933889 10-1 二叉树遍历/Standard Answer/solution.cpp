#include <iostream>
#include <string>
#include <queue>
using namespace std;

void toBFS(string preSeq,string inSeq)
{
    queue<string> preQue,inQue;
    string pre,in;
    preQue.push(preSeq);
    inQue.push(inSeq);
    while (!preQue.empty()){
        pre = preQue.front();
        in = inQue.front();
        preQue.pop();
        inQue.pop();
        int root = in.find(pre[0]);
        string inLeft,preLeft,inRight,preRight;
        cout << pre[0];
        if (root != 0){ //左子树存在
            inLeft = in.substr(0 ,root);
            preLeft = pre.substr(1,inLeft.size());
            preQue.push(preLeft);
            inQue.push(inLeft);
        }
        if (root != in.size() - 1){ //右子树存在
            inRight = in.substr(root+1,in.size() - root);
            preRight = pre.substr(preLeft.size()+1,pre.size() - preLeft.size() - 1);
            preQue.push( preRight );
            inQue.push( inRight );
        }
    }
}

int main() {
  string pre,in;
  cin >> pre >> in;
  toBFS(pre,in);
  cout << endl;
  return 0;
}


