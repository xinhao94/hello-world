#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class IntPQ{
    private:
        // Heap is implemented as a integer list
        vector<int> nodes;
    public:
        // Default constructor without input
        IntPQ(){
            nodes.push_back(INT_MAX);
        }
        // Default constructor with input
        IntPQ(int root){
            nodes.push_back(INT_MAX);
            nodes.push_back(root);
        }
        size_t getSize(){
            return nodes.size();
        }
        void printVal(int index){
            if(index<nodes.size()){
                cout<<nodes[index]<<endl;
            }
            else{
                cout<<"Index out of range!"<<endl;
            }   
        }
        int getVal(int index){
            if(index<nodes.size()){
                return nodes[index];
            }
            else{
                cout<<"Index out of range!"<<endl;
                return INT_MAX;
            }    
        }
        void printHeap(){
            if(nodes.size() == 1){
                cout<<"Heap is empty!";
            }
            int i = 1;
            while(i < nodes.size()){
                cout<<nodes[i]<<" ";
                i += 1;
            }
            cout<<endl;
        }
        void enQueue(int x){
            nodes.push_back(x);
            int curr = nodes.size()-1;
            // Restore the ordering of the heap
            while(curr != 0){
                if(nodes[curr] < nodes[curr/2]){
                    break;
                }
                else{
                    int temp = nodes[curr/2];
                    nodes[curr/2] = nodes[curr];
                    nodes[curr] = temp;
                    curr = curr/2;
                }
            }
        }
        int deQueue(){
            if(nodes.size() == 1){
                cout<<"Heap is empty!"<<endl;
                return INT_MAX;
            }
            if(nodes.size() == 2){
                int ans = nodes[1];
                nodes.pop_back();
                return ans;
            }
            else{
                int ans = nodes[1];
                int curr = nodes.size()-1;
                nodes[1] = nodes[curr];
                nodes.pop_back();
                curr = 1;
                // Restore the ordering of the heap
                while(curr != nodes.size()-1){
                    if(nodes[curr]>nodes[2*curr] && nodes[curr]>nodes[2*curr+1]){
                        break;
                    }
                    else{
                        if(nodes[2*curr] > nodes[2*curr+1]){
                            int temp = nodes[2*curr];
                            nodes[2*curr] = nodes[curr];
                            nodes[curr] = temp;
                            curr = 2*curr;
                        }
                        else{
                            int temp = nodes[2*curr+1];
                            nodes[2*curr+1] = nodes[curr];
                            nodes[curr] = temp;
                            curr = 2*curr+1;
                        }
                    }
                }
                return ans;
            }
        }
};

int main()
{   
    IntPQ maxHeap(99);
    maxHeap.enQueue(42);
    maxHeap.enQueue(13);
    maxHeap.enQueue(1);
    maxHeap.enQueue(17);
    maxHeap.enQueue(3);
    maxHeap.enQueue(88);
    maxHeap.enQueue(75);
    maxHeap.printHeap();
    maxHeap.deQueue();
    maxHeap.printHeap();
    maxHeap.deQueue();
    maxHeap.printHeap();
    return EXIT_SUCCESS;
}
