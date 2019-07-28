#include <iostream>
#include <string>
using namespace std;

// Templated functions
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

// Templated class
template<typename T>
class Array{
    private:
        T * data;
        size_t size;
    public:
        // Constructor without parameter
        Array(): data(NULL), size(0){}
        // Constructor with parameters
        explicit Array(size_t n): data(new T[n]()), size(n){}
        // Copy constructor
        Array(const Array & rhs): data(NULL), size(rhs.size){
            (*this) = rhs;
        }
        // Destructor
        ~Array(){
            delete[] data;
        }
        // Overload assignment operator
        Array & operator=(const Array & rhs){
            if(this != &rhs){
                T * temp = new T[rhs.size];
                for(int i=0; i<rhs.size; i++){
                    temp[i] = rhs.data[i];
                }
                delete[] data;
                data = temp;
                size = rhs.size;
            }
            return *this;
        }
        // Overload index operator
        T & operator[](unsigned ind){
            return data[ind];
        }
        const T & operator[](unsigned ind) const{
            return data[ind];
        }
        size_t getSize() const{
            return size;
        }
};

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
