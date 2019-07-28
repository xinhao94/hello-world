#include <iostream>
#include <string>
using namespace std;

template<typename T>
T * arrMax(T * array, size_t n){
    if(n==0){
        return NULL;
    }
    T * ans = &array[0];
    for(size_t i=1; i<n; i++){
        if(array[i] > *ans){
            ans = &array[i];
        }
    }
    return ans;
}

template<typename T>
T * arrMin(T * array, size_t n){
    if(n==0){
        return NULL;
    }
    T * ans = &array[0];
    for(size_t i=1; i<n; i++){
        if(array[i] < *ans){
            ans = &array[i];
        }
    }
    return ans;
}

int main(void){
    int intArray[] = {1,3,6,9,2,7};
    size_t nInt = 6;
    int * p1 = arrMax<int>(intArray, nInt);
    cout<<*p1<<endl;
    p1 = arrMin<int>(intArray, nInt);
    cout<<*p1<<endl;
    string strArray[] = {"I", "like", "eating", "apples"};
    size_t nStr = 4;
    string * p2 = arrMax<string>(strArray, nStr);
    cout<<*p2<<endl;
    p2 = arrMin<string>(strArray, nStr);
    cout<<*p2<<endl;
    return EXIT_SUCCESS;
}
