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

// Helper function for the selection sort
// Return the index of the smallest element in the unsorted region
int findMin(int * data, int start, int n){
    int min = start;
    int curr = start + 1;
    while(curr<n){
        if(data[curr]<data[min]){
            min = curr;
        }
        curr ++;
    }
    return min;
}

void selectionSort(int * data, int n){
    for(int pos=0; pos<n; pos++){
        int minIdx = findMin(data, pos, n);
        if(minIdx != pos){
            swap(data[pos], data[minIdx]);
        }
    }
}

// Helper function for the heap sort
// Rearrange the input integer array into a heap 
void heapify(int * data, int n){
    int boundary = 1;
    while(boundary<n){
        int curr = data[boundary];
        int heapCurr = boundary;
        boundary ++;
        while(heapCurr!=0){
            if(data[heapCurr]<data[(heapCurr-1)/2]){
                break;
            }
            else{
                swap(data[heapCurr], data[(heapCurr-1)/2]);
                heapCurr = (heapCurr-1)/2;
            }
        }
    }
}

void heapSort(int * data, int n){
    heapify(data, n);
    int top = 0;
    int boundary = n-1;
    while(boundary!=0){
        // Move the top of the maximum heap to sorted region
        swap(data[top], data[boundary]);
        boundary --;
        // Restore the ordering in the heap
        int curr = top;
        while(curr<=boundary){
            // If the current node has no child
            if((2*curr+1)>boundary){
                break;
            }
            // If the current node has only left child
            if((2*curr+2)>boundary){
                if(data[curr]>data[2*curr+1]){
                    break;
                }
                else{
                    swap(data[curr], data[2*curr+1]);
                    break;
                }
            }
            // If the current node has two children
            if(data[curr]>data[2*curr+1] && data[curr]>data[2*curr+2]){
                break;
            }
            else{
                if(data[2*curr+1]>data[2*curr+2]){
                    swap(data[curr], data[2*curr+1]);
                    curr = 2*curr+1;
                }
                else{
                    swap(data[curr], data[2*curr+2]);
                    curr = 2*curr+2;
                }
            }
        }
    }
}

int main()
{
    int test1[9] = {45, 6, 13, 67, 76, 25, 18, 53, 32};
    int test2[24] = {16, 36, 70, 61, 45, 32, 51, 9, 22, 17, 46, 43, 83, 10, 38, 11, 47, 78, 57, 70, 43, 66, 61, 28};
    printArray(test1, 9);
    heapSort(test1, 9);
    printArray(test1, 9);
    printArray(test2, 24);
    heapSort(test2, 24);
    printArray(test2, 24);
    return EXIT_SUCCESS;
}
