#include <iostream>
using namespace std;

template<typename T>
class BST{
    private:
        class Node{
            T data;
            Node * left;
            Node * right;
            // Default constructor
            Node(T input) : data(input), left(NULL), right(NULL){}
        };
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
        // Default constructor
        BST() : root(NULL) {}
        // public interface
        void add(T input){
            root = add(root, input);
        }
};

int main(void){
    printf("Compiled success\n");
    return EXIT_SUCCESS;
}
