#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Generic hash function object
class StringHasher{
    private:
        const int multiplyBy;
    public:
        // Default constructor, use 29 for default
        StringHasher() : multiplyBy(29) {}
        // Customized constructor
        StringHasher(int m) : multiplyBy(m) {}
        // Overload () operator
        unsigned operator() (const string & str) const{
            unsigned ans = 0;
            for(string::const_iterator it = str.begin(); it != str.end(); ++it){
                ans = ans * multiplyBy + *it;
            }
            return ans;
        }
};

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
    string name;
    StringHasher hashFunc;
    cout<<"Please enter a name to be hashed: ";
    cin>>name;
    unsigned int hashValue = hashFunc(name);
    cout<<hashValue<<endl;
    return EXIT_SUCCESS; 
}
