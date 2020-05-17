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
    if(curr==NULL){
        cout<<"Data: NULL, Height: "<<getHeight(curr)<<endl;
    }
    else{
        cout<<"Data: "<<curr->data<<", Height: "<<getHeight(curr)<<endl;
    }
}
bool isBalanced(Node * curr){
    int leftHeight = getHeight(curr->left);
    int rightHeight = getHeight(curr->right);
    // If the heights of left and right child differ by more than 1
    // this node is not balanced
    if(abs(leftHeight-rightHeight)<=1){
        return true;
    }
    else{
        return false;
    }
}
void rotateLeft(Node ** curr){
    Node * v = *curr;
    *curr = (*curr)->right;
    Node * temp = (*curr)->left;
    v->right = temp;
    (*curr)->left = v;
    updateHeight((*curr)->left);
    updateHeight((*curr)->right);
    updateHeight(*curr);
}
void rotateRight(Node ** curr){
    Node * v = *curr;
    *curr = (*curr)->left;
    Node * temp = (*curr)->right;
    v->left = temp;
    (*curr)->right = v;
    updateHeight((*curr)->left);
    updateHeight((*curr)->right);
    updateHeight(*curr);
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
    tree.add(1);

    Node * root = tree.getRoot();
    cout<<isBalanced(root)<<endl;
    printNodeInfo(root);
    printNodeInfo(root->left);
    printNodeInfo(root->left->left);

    rotateRight(&root);
    cout<<isBalanced(root)<<endl;
    printNodeInfo(root);
    printNodeInfo(root->left);
    printNodeInfo(root->right);

    return EXIT_SUCCESS;
}
