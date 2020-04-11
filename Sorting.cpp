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
        // Insert the first element of the un-heapifyied array 
        // to the last slot of the heap (already there)
        int heapCurr = boundary;
        // Increase the boundary by 1
        boundary ++;
        // Restore the ordering in the heap
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
        // by swapping the top with the last element in the heap
        swap(data[top], data[boundary]);
        // Decrease the boundary by 1
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

// Implementation of the merge function of merge sort
// L is the first element of the left array
// R is the first element of the right array
// m is the total length after merging
void merge(int * data, int L, int R, int m){
    int currL = L;
    int currR = R;
    int * temp = new int[m];
    int pos = 0;
    while(currL<R && currR<L+m){
        if(data[currL]<data[currR]){
            temp[pos] = data[currL];
            currL ++;
            pos ++;
        }
        else{
            temp[pos] = data[currR];
            currR ++;
            pos ++;
        }
    }
    // If there still are elements in the left portion 
    if(currL!=R){
        while(currL<R){
            temp[pos] = data[currL];
            currL ++;
            pos ++;
        }
    }
    // If there still are elements in the right portion
    if(currR!=L+m){
        while(currR<L+m){
            temp[pos] = data[currR];
            currR ++;
            pos ++;
        }
    }
    // Copy the sorted data back to the original array
    pos = 0;
    for(int i=L; i<L+m; i++){
        data[i] = temp[pos];
        pos ++;
    }
    delete[] temp;
}

// Implementation for the merge sort
// L is the first element of the left array
// R is the first element of the right array
void mergeSort(int * data, int n, int L, int R){
    if(n==1){
        return;
    }
    if(n==2){
        if(data[L]<data[R]){
            return;
        }
        else{
            swap(data[L], data[R]);
        }
    }
    else{
        int nL = R-L;
        int nR = n-nL;
        mergeSort(data, nL, L, L+nL/2);
        mergeSort(data, nR, R, R+nR/2);
        merge(data, L, R, n);
    }
}

// Interface for merge sort
void mergeSort(int * data, int n){
    int L = 0;
    int R = n/2;
    mergeSort(data, n, L, R);
}

// Helper function for quick sort
// Implement the rearrangement with respect to the pivot
// start/end is the index of the first/last element
// in the array to be rearranged, respectively
// Finally, return the index of the pivot (the partition, namely the left pointer)
// If -1 is returned, this means the pivot is already the largest element
int rearrange(int * data, int m, int start, int end){
    int pivot = data[end];
    int left = start;
    int right = end-1;
    while(true){
        // Firstly scan from left to right,
        // looking for an element that is smaller than (or equal to) the pivot
        // Note that if the pivot is already the largest, whole loop ends here
        while(data[left]<=pivot && left<end){
            left ++;
        }
        // Than scan from right to left,
        // looking for an element that is larger than the pivot
        while(data[right]>pivot){
            right --;
        }
        // Decide whether the rearrangement is completed
        if(right<left){
            // Swap the element which the left pointer points at
            // with the pivot to complete the rearrangement
            swap(data[left], data[end]);
            // Terminate the function
            break;
        }
        else{
            // Proceed with the rearrangement
            // Swap the left and right element into correct order
            swap(data[left], data[right]);
            continue;
        }
    }
    // If left pointer reaches end, this means the pivot is already the largest
    // Function returns -1 to indicate this special case
    if(left==end){
        return -1;
    }
    // Otherwise, return the index of left as the partition for next round
    else{
        return left;
    }
}

// Implementation of the quick sort
// start/end is the index of the first/last element
void quickSort(int * data, int n, int start, int end){
    // Base cases
    if(n<=2){
        if(n==2){
            if(data[start]<=data[end]){
                return;
            }
            else{
                swap(data[start], data[end]);
            }
        }
        else{
            return;
        }
    }
    // Sort the array and get the partition for next round
    int partition = rearrange(data, n, start, end);
    // If the partition==-1, the pivot is already the largest
    // Only recursively sort the elements expcept it
    if(partition == -1){
        quickSort(data, n-1, start, end-1);
    }
    else{
        // Recursively sort the left portion to the partition
        quickSort(data, partition-start, start, partition-1);
        // Recursively sort the right portition to the partition
        quickSort(data, end-partition, partition+1, end);
    }
}

// Interface for quick sort
void quickSort(int * data, int n){
    quickSort(data, n, 0, n-1);
}

int main()
{
    int test1[9] = {45, 6, 13, 67, 76, 25, 18, 53, 32};
    int test2[24] = {16, 36, 70, 61, 45, 32, 51, 9, 22, 17, 46, 43, 83, 10, 38, 11, 47, 78, 57, 70, 43, 66, 61, 28};
    printArray(test2, 24);
    quickSort(test2, 24);
    printArray(test2, 24);
    return EXIT_SUCCESS;
}
