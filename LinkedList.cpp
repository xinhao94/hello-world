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
                Node * prev;
                // Default constructor
                Node(T ct) : data(ct), next(NULL), prev(NULL){}
                Node(T ct, Node * p) : data(ct), next(p), prev(NULL){}
                Node(T ct, Node * p1, Node * p2) : data(ct), next(p1), prev(p2){}
        };
        Node * head;
        Node * tail;
        size_t size;
    public:
        // Default constructor
        LinkedList() : head(NULL), tail(NULL), size(0){}
        size_t getSize() const{
            return size;
        }
        T getHead() const{
            return head->data;
        }
        T getTail() const{
            return tail->data;
        }
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
        void addFront(T data){
            head = new Node(data, head);
            if(tail==NULL){
                tail = head;
            }
            else{
                head->next->prev = head;
            }
            size ++;
        }
        void addBack(T data){
            tail = new Node(data, NULL, tail);
            if(head==NULL){
                head = tail;
            }
            else{
                tail->prev->next = tail;
            }
            size ++;
        }
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
};




int main(){
    LinkedList<int> lp;
    lp.addBack(5);
    lp.addFront(3);
    lp.addBack(7);
    cout<<"No. of Nodes: "<<lp.getSize()<<endl;
    lp.showAll();
    return EXIT_SUCCESS;
}
