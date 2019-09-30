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
                Node(T content, Node * p) : data(content), next(p), prev(NULL){}
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
};




int main(){
    LinkedList<int> lp;
    lp.addFront(3);
    lp.addFront(5);
    lp.addFront(7);
    lp.showAll();
    return EXIT_SUCCESS;
}
