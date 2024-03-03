// #include"hashTypes.h"
#include<utility>
// typedef int Key;
// typedef pair<Key, bool>  Cell;
// //a cell consists of a key and a flag of bool. If the cell is empty, the second component is set to true, otherwise false.
// typedef vector<Cell> Table; //type of a hash table

// //hash function, where M should be the hash table size.
// size_t h(Key k, size_t M = 11){
//     return k % M;
// }
using namespace std;
pair<pair<bool, size_t>, int>  lookup(const Table& t, const Key k){
    size_t pos  = h(k,t.size());
    int i = 1;
    while(pos < t.size()){
        auto& [key,flag] = t[pos];
        if (key == k && !flag){
            return make_pair(make_pair(true,pos),i);
        }else if (key == 0){
            return make_pair(make_pair(false,pos),i);
        }
        pos += 1;
        i += 1;
    }
    return make_pair(make_pair(false,pos - 1),i - 1);
}