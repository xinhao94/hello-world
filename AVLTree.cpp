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

int getHeight(Node * curr){
    if(curr==NULL){
        return 0;
    }
    else{
        return curr->height;
    }
}
/*
void updateHeight(Node * curr){
    if(curr==NULL){
        return;
    }
    else{
        int leftHeight = getHeight(curr->left);
        int rightHeight = getHeight(curr->right);
        if(leftHeight>=rightHeight){
            curr->height = leftHeight+1;
        }
        else{
            curr->height = rightHeight+1;
        }
    }
}
*/

// Execute left rotation
void rotateLeft(Node ** curr){
    Node * v = *curr;
    *curr = (*curr)->right;
    Node * temp = (*curr)->left;
    v->right = temp;
    (*curr)->left = v;
    if((*curr)->left!=NULL){
            (*curr)->left->updateHeight();
        }
    if((*curr)->right!=NULL){
        (*curr)->right->updateHeight();
    }
    (*curr)->updateHeight();
}
// Execute right rotation
void rotateRight(Node ** curr){
    Node * v = *curr;
    *curr = (*curr)->left;
    Node * temp = (*curr)->right;
    v->left = temp;
    (*curr)->right = v;
    if((*curr)->left!=NULL){
        (*curr)->left->updateHeight();
    }
    if((*curr)->right!=NULL){
        (*curr)->right->updateHeight();
    }
    (*curr)->updateHeight();
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
            }
            // If the data is larger, add to right subtree
            else{
                Node * newRight = add(root->right, input);
                root->right = newRight;
            }
            // Update height of the root node
            root->updateHeight();
            // Check whether the node is balanced
            // If not, restore balance
            if(root->isBalanced()==false){
                // If height of right child is larger
                if(getHeight(root->right)>getHeight(root->left)){
                    // If the longest path is right, right
                    // Do single left rotation
                    if(getHeight(root->right->right)>getHeight(root->right->left)){
                        rotateLeft(&root);
                        cout<<"*** Left rotation executed ***"<<endl;
                    }
                    // If the longest path is right, left
                    // Do double rotations: right->left
                    else{
                        // Do right rotation for subtree rooted at right child
                        rotateRight(&(root->right));
                        cout<<"*** Right rotation executed ***"<<endl;
                        // Do left rotation
                        rotateLeft(&root);
                        cout<<"*** Left rotation executed ***"<<endl;
                    }
                }
                // If height of left child is larger
                if(getHeight(root->left)>getHeight(root->right)){
                    // If the longest path is left, left
                    // Do single right rotation
                    if(getHeight(root->left->left)>getHeight(root->left->right)){
                        rotateRight(&root);
                        cout<<"*** Right rotation executed ***"<<endl;
                    }
                    // If the longest path is left, right
                    // Do double rotations: left->right
                    else{
                        // Do left rotation for subtree rooted at left child
                        rotateLeft(&(root->left));
                        cout<<"*** Left rotation executed ***"<<endl;
                        // Do right rotation
                        rotateRight(&root);
                        cout<<"*** Right rotation executed ***"<<endl;
                    }
                }
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

    /*
    // Execute left rotation
    void rotateLeft(){
        Node ** curr = &root;
        Node * v = *curr;
        *curr = (*curr)->right;
        Node * temp = (*curr)->left;
        v->right = temp;
        (*curr)->left = v;
        if((*curr)->left!=NULL){
            (*curr)->left->updateHeight();
        }
        if((*curr)->right!=NULL){
            (*curr)->right->updateHeight();
        }
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
        if((*curr)->left!=NULL){
            (*curr)->left->updateHeight();
        }
        if((*curr)->right!=NULL){
            (*curr)->right->updateHeight();
        }
        (*curr)->updateHeight();
    }
    */
};


int main(){
    AVL tree(10);
    tree.add(5);
    tree.add(7);

    Node * root = tree.getRoot();
    root->printNodeInfo();

    Node * curr = root->left;
    curr->printNodeInfo();

    curr = root->right;
    curr->printNodeInfo();

    return EXIT_SUCCESS;
}
