#include <iostream>
using namespace std;

template<typename T>
class LinkedList{
    private:
        // Node is an inner class
        class Node{
            public:
                T data;
                // Next is a recursively-defined pointer
                Node * next;
                // Default constructor
                Node(T ct) : data(ct), next(NULL){}
                Node(T ct, Node * p) : data(ct), next(p){}
        };
        Node * head;
    public:
        // Default constructor
        LinkedList() : head(NULL){}
        // Add one element to the head of the linked list
        void addFront(T data){
            head = new Node(data, head);
        }
        // A formatted way to print the whole linked list
        void showAll() const{
            Node * p = head;
            if(p!=NULL){
                cout<<"Head->";
            }
            else{
                cout<<"List is empty!"<<endl;
            }
            while(p!=NULL){
                cout<<p->data<<"->";
                p = p->next;
            }
            cout<<"Tail"<<endl;
        }
        // Find designated element from the linked list
        T * findElement(T element){
            Node * p = head;
            while(p!=NULL){
                if(p->data==element){
                    return &(p->data);
                }
                else{
                    p = p->next;
                }
            }
            return NULL;
        }
        // Insert one element into a sorted linked list: method 1
        void addSorted(const T & data){
            if(head==NULL || data<head->data){
                this->addFront(data);
            }
            else{
                Node * curr = head;
                while(curr->next!=NULL && data>curr->next->data){
                    curr = curr->next;
                }
                curr->next = new Node(data, curr->next);
            }
        }
        // Destructor
        ~LinkedList(){
            while(head != NULL){
                Node * temp = head->next;
                delete head;
                head = temp;
            }
        }
};

int main(){
    LinkedList<int> p;
    for(int i=9; i>=1; i=i-2){
        p.addFront(i);
    }
    p.showAll();
    int x = 0;
    p.addSorted(x);
    p.showAll();
    int y = 6;
    p.addSorted(y);
    p.showAll();
    return EXIT_SUCCESS;
}
