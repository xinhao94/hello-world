#include <iostream>
using namespace std;

template<typename T>
class BST{
    public:
        class Node{
            public:
                T data;
                Node * left;
                Node * right;
                // Default constructor
                Node(T input) : data(input), left(NULL), right(NULL){}
                T getData(void){
                    return data;
                }
                Node * getLeft(void){
                    return left;
                }
                Node * getRight(void){
                    return right;
                }
        };
    private:
        Node * root;
        // private helper method: add using recursion
        Node * add(Node * current, T input){
            if(current == NULL){
                Node * ans = new Node(input);
                return ans;           
            }
            else{
                if(input < current->data){
                    Node * newLeft = add(current->left, input);
                    current->left = newLeft;
                }
                else{
                    Node * newRight = add(current->right, input);
                    current->right = newRight;
                }
                return current;
            }
        }
    public:
        // Default constructor without argument
        BST() : root(NULL) {}
        // Constructor with argument
        BST(T input){
            root = new Node(input);
        }
        // public interface method: add using recursion
        void add(T input){
            root = add(root, input);
        }
        Node * getRoot(void){
            return this->root;
        }
        Node * getLeftChild(Node * current){
            return current->getLeft();
        }
        Node * getRightChild(Node * current){
            return current->getRight();
        }
        T getValue(Node * current){
            if(current == NULL){
                cout<<"Node does not exist"<<endl;
                return 0;
            }
            else{
                return current->getData();
            }
        }
        // add using iteration
        void add2(T input){
            Node ** current = &root;
            while(*current != NULL){
                if(input<(*current)->data){
                    current = &((*current)->left);
                }
                else{
                    current = &((*current)->right);
                }
            }
            *current = new Node(input); 
        }
        // search a particular value
        bool contains(T input){
            Node * current = root;
            while(current != NULL){
                if(input == current->data){
                    return true;
                }
                else if(input < current->data){
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }
            return false;
        }
        // return a pointer to particular value
        Node * search(T input){
            if(this->root == NULL){
                cout<<"The tree is empty!"<<endl;
                return NULL;
            }
            else{
                Node ** current = &root;
                while(*current != NULL){
                    if(input == (*current)->data){
                        return *current;
                    }
                    else if(input < (*current)->data){
                        current = &((*current)->left);
                    }
                    else{
                        current = &((*current)->right);
                    }
                }
                cout<<"The value does not exist"<<endl;
                return NULL;
            }
        }
        // return a pointer to a pointer to a particulat value
        Node ** searchHandle(T input){
            if(this->root == NULL){
                cout<<"The tree is empty!"<<endl;
                return NULL;
            }
            else{
                Node ** current = &root;
                while(*current != NULL){
                    if(input == (*current)->data){
                        return current;
                    }
                    else if(input < (*current)->data){
                        current = &((*current)->left);
                    }
                    else{
                        current = &((*current)->right);
                    }
                }
                return NULL;
            }
        }
        // remove a particular value
        bool remove(T input){
            Node ** handle = this->searchHandle(input);
            if(handle == NULL){
                cout<<"Value does not exist!"<<endl;
                return false;
            }
            else{
                if((*handle)->left == NULL && (*handle)->right == NULL){
                    delete *handle;
                    *handle = NULL;
                    return true;
                }
            }
            return false;
        }
};

int main(){
    BST<int> tree(55);
    BST<int>::Node * curr = tree.getRoot();
    int value = tree.getValue(curr);
    cout<<value<<endl;
    tree.add(20);
    tree.add2(70);
    BST<int>::Node * leftCld = tree.getLeftChild(curr);
    value = tree.getValue(leftCld);
    cout<<value<<endl;
    BST<int>::Node * rightCld = tree.getRightChild(curr);
    value = tree.getValue(rightCld);
    cout<<value<<endl;
    BST<int>::Node * handle = tree.search(70);
    value = tree.getValue(handle);
    cout<<value<<endl;
    bool status = tree.remove(70);
    cout<<status<<endl;
    handle = tree.search(70);
    return EXIT_SUCCESS;
}
