#include <iostream>
using namespace std;

class Node{
public:
    int data;
    int height;
    Node * left;
    Node * right;
    // Deafult constructor
    Node(int input) : data(input), height(1), left(NULL), right(NULL){}
};
int getHeight(Node * curr){
    if(curr==NULL){
        return 0;
    }
    else{
        return curr->height;
    }
}
void updateHeight(Node * curr){
    int leftHeight = getHeight(curr->left);
    int rightHeight = getHeight(curr->right);
    if(leftHeight>=rightHeight){
        curr->height = leftHeight+1;
    }
    else{
        curr->height = rightHeight+1;
    }
}
void printNodeInfo(Node * curr){
    cout<<"Data: "<<curr->data<<", Height: "<<getHeight(curr)<<endl;
}

class AVL{
private:
    Node * root;
    // Private helper method
    // Add a node using recursion
    Node * add(Node * root, int input){
        // If the tree is empty
        // Base case
        if(root==NULL){
            Node * ans = new Node(input);
            return ans;
        }
        // If the tree is not empty
        else{
            // If the data is smaller, add to left subtree
            if(input<root->data){
                Node * newLeft = add(root->left, input);
                root->left = newLeft;
                // Update height of the root node
                updateHeight(root);
            }
            // If the data is larger, add to right subtree
            else{
                Node * newRight = add(root->right, input);
                root->right = newRight;
                // Update height of the root node
                updateHeight(root);
            }
            return root;
        }
    }
public:
    // Deafult constructor 1
    AVL() : root(NULL){}
    // Default constructor 2
    AVL(int input){
        root = new Node(input);
    }
    Node * getRoot(){
        return root;
    }
    // Add a node using recursion
    // Public interface
    void add(int input){
        root = add(root, input);
    }
};


int main(){
    AVL tree(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(2);

    Node * root = tree.getRoot();
    cout<<"Root:"<<endl;
    printNodeInfo(root);

    Node * curr = root->left;
    cout<<"Left child:"<<endl;
    printNodeInfo(curr);

    curr = root->right;
    cout<<"Right child:"<<endl;
    printNodeInfo(curr);
    return EXIT_SUCCESS;
}
