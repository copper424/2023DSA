#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//bool switches(queue<int> p, queue<int> q);

bool switches(queue<int> p, queue<int> q){
   stack<int> s;
   while (!p.empty() && !q.empty()){
      while (!p.empty() && q.front()!=p.front()){
          s.push(p.front());
          p.pop();
      }
      while (!p.empty() && !q.empty() && p.front() == q.front()){
           p.pop();
           q.pop();
      }
      while (!s.empty() && !q.empty() && s.top() == q.front()){
            q.pop();
            s.pop();
      }
   }

   if (p.empty() && q.empty() && s.empty())
     return true;
   else 
     return false;
}



int main(){
    int m,n,a,b;
    cin >> n;
    while (n--){
        cin >>m;
        queue<int> p,q;
        for (int i=0;i<m;i++){
           cin >>a;
           p.push(a);
        }
        for (int i=0;i<m;i++){
           cin >>a;
           q.push(a);
        }
        bool b = switches(p,q);
        if (b)
           cout <<"Yes"<<endl;
        else
           cout <<"No"<<endl;
    }
}