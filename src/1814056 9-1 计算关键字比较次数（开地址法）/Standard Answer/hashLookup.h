//returns a pair of bool and the number of key comparisons. The first component is true if k is present in hash table t, and false otherwise.
pair<pair<bool, size_t>, int>  lookup(const Table& t, const Key k){
    size_t ad = h(k, t.size());
    bool flag = false;
    int cmp = 0;
    for (size_t i=0;i<t.size(); i++){
        ad = ad % t.size();
//cout <<k<<":"<<t[ad].first<<":"<<t[ad].second<<endl;
        if (!t[ad].second){
           if (t[ad].first == k){
             cmp++;
             return make_pair(make_pair(true, ad), cmp);
           }
           else {
             cmp++;
             ad++;
           }
        }
        else if (t[ad].second) {
           if (t[ad].first==0) //really empty
           {
             cmp++;
             return make_pair(make_pair(false,ad), cmp);
           }
           else  //after deletion
           {
              cmp++;
              ad++;
           }
       }
   }
 // return make_pair(make_pair(false, ad), cmp);
}

