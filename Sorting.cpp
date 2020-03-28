#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int * data, int n){
    for(int i=0; i<n; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int * data, int n){
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i=0; i<n-1; i++){
            if(data[i+1]<data[i]){
                swap(data[i], data[i+1]);
                swapped = true;
            }
        }
    }
}

// Helper function for the insertion sort
// Shift elements from first to last-1, 1 position to the right
void shift(int * data, int first, int last){
    int curr = last;
    while(curr>first){
        data[curr] = data[curr-1];
        curr -= 1;
    }   
}

void insertionSort(int * data, int n){
    int boundary = 1;
    while(boundary<n){
        int curr = data[boundary];
        int pos = 0;
        while(pos<boundary && curr>data[pos]){
            pos ++;
        }
        shift(data, pos, boundary);
        data[pos] = curr;
        boundary ++;
    }
}

int main()
{
    int test1[9] = {45, 6, 13, 67, 76, 25, 18, 53, 32};
    int test2[24] = {16, 36, 70, 61, 45, 32, 51, 9, 22, 17, 46, 43, 83, 10, 38, 11, 47, 78, 57, 70, 43, 66, 61, 28};
    printArray(test1, 9);
    insertionSort(test1, 9);
    printArray(test1, 9);
    printArray(test2, 24);
    insertionSort(test2, 24);
    printArray(test2, 24);
    return EXIT_SUCCESS;
}
