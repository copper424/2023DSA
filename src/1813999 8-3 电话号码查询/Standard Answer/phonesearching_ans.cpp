
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <functional>
using namespace std;

typedef pair<string,string> Account;
struct compLT {
  bool operator ()(Account a, Account b) {
     return a.first < b.first;
  }

};

void print(vector<Account> as){
  for (unsigned i = 0; i<as.size(); i++) {
    cout << as[i].first <<", " << as[i].second <<endl;
  }

}

bool cmp(Account a, string s){
  return (a.first < s);
}

struct cmp2:public binary_function<Account, string, bool>{
bool operator()(Account a, string s){
  return (a.first== s);}

};


int main(){

  //ifstream in("phonebook1.txt");
 // ofstream out("SortedATMLog.txt");
  string s, t, na,ph;
  int m; //number of pairs
  int n; //number of names to search

  cin >> m;
  getline(cin, s, '\n');
  vector<Account> accounts(m);
   map<string, string> f;
  for (int i=0; i<m; i++) {
    getline(cin, s, '\n');
    int k1;
    k1 = s.find(',');
    na = s.substr(0, k1);
    ph = s.substr(k1+1);
   // cout << id <<" " << date <<" " <<act<<" " <<amount<<endl;
   f[na] = ph;
//   accounts[i] = make_pair(na, ph);
  }

//  sort(accounts.begin(), accounts.end(), compLT());


  cin >> n;
  getline(cin, s, '\n');
  vector<string> names(n);
  //vector<Account> :: iterator it;
  map<string,string> :: iterator it;
  for (int i=0; i<n; i++) {
    getline(cin, s, '\n');
//cout<<"searching "<<s<<":";
    names[i] = s;
  }
  for (int i=0;i<names.size();i++){
//    it = lower_bound(accounts.begin(), accounts.end(), names[i], cmp);
    s = names[i];
   // it = find_if(accounts.begin(), accounts.end(), bind2nd(cmp2(), s));
    it = f.find(names[i]);
 
    cout<<names[i]<<":";
 //   if (it!= accounts.end()&& (*it).first == names[i]){
    if (it!=f.end()){
          cout<<(*it).second<<endl;
    }
    else
      cout<<"No"<<endl;      
  }

  return 0;
}
