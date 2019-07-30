#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class OrderIgnoreCase{
    public:
        bool operator()(const string & s1, const string & s2) const{
            for(size_t i=0; i<s1.size() && i<s2.size(); i++){
                // tolower() converts a character to lower case
                char c1 = tolower(s1[i]);
                char c2 = tolower(s2[i]);
                if(c1 != c2){
                    return c1<c2;
                }
            }
            return s1.size()<s2.size();
        }
};


int main(){
    string str1 = "apple";
    string str2 = "Bed";
    string ans = min<string>(str1, str2);
    cout<<ans<<endl;
    ans = min<string, OrderIgnoreCase>(str1, str2, OrderIgnoreCase());
    cout<<ans<<endl;
    return EXIT_SUCCESS;
}
