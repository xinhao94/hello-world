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

    // Update height of current node
    void updateHeight(){
        // Get the height of left child
        int leftHeight;
        if(this->left==NULL){
            leftHeight = 0;
        }
        else{
            leftHeight = this->left->height;
        }
        // Get the height of right child
        int rightHeight;
        if(this->right==NULL){
            rightHeight = 0;
        }
        else{
            rightHeight = this->right->height;
        }
        // Update the height of current node
        if(leftHeight>=rightHeight){
            this->height = leftHeight+1;
        }
        else{
            this->height = rightHeight+1;
        }
    }
    
    // Test whether current node is balanced
    bool isBalanced(){
        // Get the height of left child
        int leftHeight;
        if(this->left==NULL){
            leftHeight = 0;
        }
        else{
            leftHeight = this->left->height;
        }
        // Get the height of right child
        int rightHeight;
        if(this->right==NULL){
            rightHeight = 0;
        }
        else{
            rightHeight = this->right->height;
        }
        // If the heights of left and right child differ by more than 1
        // this node is not balanced
        if(abs(leftHeight-rightHeight)<=1){
            return true;
        }
        else{
            return false;
        }
    }

    // Print info of current node
    void printNodeInfo(){
        char status;
        if(this->isBalanced()==true){
            status = 'Y';
        }
        else{
            status = 'N';
        }
        cout<<"Data: "<<data<<", Height: "<<height<<", Balanced: "<<status<<endl;
    }
};

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
                root->updateHeight();
            }
            // If the data is larger, add to right subtree
            else{
                Node * newRight = add(root->right, input);
                root->right = newRight;
                // Update height of the root node
                root->updateHeight();
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

    // Execute left rotation
    void rotateLeft(){
        Node ** curr = &root;
        Node * v = *curr;
        *curr = (*curr)->right;
        Node * temp = (*curr)->left;
        v->right = temp;
        (*curr)->left = v;
        (*curr)->left->updateHeight();
        (*curr)->right->updateHeight();
        (*curr)->updateHeight();
    }

    // Execute right rotation
    void rotateRight(){
        Node ** curr = &root;
        Node * v = *curr;
        *curr = (*curr)->left;
        Node * temp = (*curr)->right;
        v->left = temp;
        (*curr)->right = v;
        (*curr)->left->updateHeight();
        (*curr)->right->updateHeight();
        (*curr)->updateHeight();
    }
};


int main(){
    AVL tree(1);
    tree.add(5);
    tree.add(10);

    Node * root = tree.getRoot();
    root->printNodeInfo();
    Node * curr = root->right;
    curr->printNodeInfo();
    curr = curr->right;
    curr->printNodeInfo();

    cout<<"Execute left rotation"<<endl;
    tree.rotateLeft();

    root = tree.getRoot();
    root->printNodeInfo();
    curr = root->left;
    curr->printNodeInfo();
    curr = root->right;
    curr->printNodeInfo();

    return EXIT_SUCCESS;
}
