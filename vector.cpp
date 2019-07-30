#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
void printElements(const T & container){
    // Use const_iterator to obtain a const reference
    typename T::const_iterator it = container.begin();
    while(it != container.end()){
        cout<<*it<<endl;
        ++it;
    }
}



int main(void){
    size_t length = 10;
    vector<int> intVec(length);
    for(int i=0; i<length; i++){
        intVec[i] = i+1;
    }
    vector<int>::iterator it = intVec.begin();
    while(it != intVec.end()){
        cout<<*it<<endl;
        // ++it is more efficient than it++
        // since it avoids object copying
        ++it;
    }
    // A space is required for consecutive right angle brackets
    printElements<vector<int> >(intVec);
    return EXIT_SUCCESS;
}
