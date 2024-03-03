#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//insert minheap
//[low+1..high] satisfy heap property, modify it so [low..high] is a heap
//permote the left child always if it is not smaller than the right one
void insert(vector<int> &A, size_t low, size_t high){

  size_t k = 2*low +1;
  int current = A[low];
  size_t smaller = k;
  while (smaller <= high){
      if (smaller+1<=high && A[smaller] > A[smaller+1])
         smaller++;
      if (current < A[smaller])  
           break;
      else{
          A[low] = A[smaller];
          low = smaller;
          smaller = 2*low+1;
      }
  }
  A[low] = current;
}

void print(vector<int> v){
 // cout<<v.size()<<endl;
  for (size_t i=0;i<v.size();i++)
     cout<<v[i] <<" ";
  cout<<endl;
}


int main(){
  int n, m;
  cin >> n;
  while (n--){
     cin >>m;
     vector<int> v(m);
     for (size_t i=0;i<m;i++)
        cin >> v[i];
     int current = v[m-1];
     v[m-1] = v[0];
     v[0] = current;
     insert(v, 0, m-2);     
     print(v);
 }

}

