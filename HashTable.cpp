#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Collision resolved by chaining
template<typename Key, typename Value, typename Hasher>
class HashMap{
    private:
        Hasher hash;
        vector<list<pair<Key, Value> > > table;
    public:
        void add(const Key & k, const Value & v){
            unsigned int h = hash(k);
            h = h % table.size();
            table[h].push_front(pair<Key, Value>(k, v));
        }
};

int main()
{
    cout<<"Hello!"<<endl;
}
