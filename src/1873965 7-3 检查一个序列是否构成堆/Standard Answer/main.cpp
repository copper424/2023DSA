#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >>n;
  vector<int> v(n);
  for (size_t i=0;i<v.size();i++)
    cin >> v[i];
  bool b1 = is_heap(v.begin(),v.end(),greater<int>());
  bool b2 = is_heap(v.begin(),v.end());
  if (b1 && b2)
    cout<<"both"<<endl;
  else if (b1)
    cout <<"min heap"<<endl;
  else if (b2)
    cout <<"max heap"<<endl;
  else
    cout <<"no"<<endl;
  return 0;

}                                 