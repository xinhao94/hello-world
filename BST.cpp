#include <iostream>
using namespace std;

template<typename T>
class BST{
    public:
        class Node{
            private:
                T data;
                Node * left;
                Node * right;
            public:
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
        // private helper method
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
        // public interface method
        void add(T input){
            root = add(root, input);
        }
        Node * getRoot(void){
            return this->root;
        }
        Node * getLeftChinld(Node * current){
            return current->getLeft();
        }
        Node * getRightChild(Node * current){
            return current->getRight();
        }
        T getValue(Node * current){
            return current->getData();
        }
};

int main(){
    BST<int> tree(55);
    BST<int>::Node * curr = tree.getRoot();
    int value = tree.getValue(curr);
    cout<<value<<endl;
    return EXIT_SUCCESS;
}
