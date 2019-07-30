#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main(void){
    size_t length = 10;
    vector<int> intVec(length);
    for(int i=0; i<length; i++){
        intVec[i] = i+1;
    }
    vector<int>::iterator it = intVec.begin();
    while(it != intVec.end()){
        cout<<*it<<endl;
        ++it;
    }
    return EXIT_SUCCESS;
}
