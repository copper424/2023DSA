#include <iostream>
#include <vector>

using namespace std;

void shell_sub(vector<int> &v, int increment, int start){
   for (size_t i = start + increment; i<v.size();i +=increment){
      if (v[i] < v[i - increment]){
         size_t position = i;
         int current = v[i];
         
         do {
           v[position] = v[position - increment];
           position -= increment;
         } while (position > start  && v[position-increment]>current);
         v[position] = current;
      }
   }
}
//for every subsequence of (a_0, a_(increment), ...), (a_1, a_(1+increment),...),...., do inerstion sort
void shell_once(vector<int> &v, int increment){
    size_t n = v.size();
    for (size_t i = 0; i< increment; i++){
       shell_sub(v, increment, i);
    }
}
