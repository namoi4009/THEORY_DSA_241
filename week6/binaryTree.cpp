#include <bits/stdc++.h>

using namespace std;

// Binary tree node abstract class
template <typename E>
class BNode {
public:
    virtual ~BNode() { } // Base destructor
    // Return the node’s value
    virtual E &element() = 0;
    // Set the node’s value
    virtual void setElement(const E &) = 0;
    // Return the node’s left child
    virtual BNode *left() const = 0;
    // Set the node’s left child
    virtual void setLeft(BNode *) = 0;
    // Return the node’s right child
    virtual BNode *right() const = 0;
    // Set the node’s right child
    virtual void setRight(BNode *) = 0;
    // Return true if the node is a leaf, false otherwise
    virtual bool isLeaf() = 0;
};

// Question 1
template <typename E>
int height(BNode<E>* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = height(root->left());
        int rightHeight = height(root->right());
        
        return 1 + max(leftHeight, rightHeight);
    }
}

// Question 2
template <typename E>
void LNRtraversal(BNode<E> * root, void (*f)(E)) {
    if (root == nullptr) {
        return; 
    } else {
        LNRtraversal(root->left(), f);
        f(root->element());
        LNRtraversal(root->right(), f);
    }
}

int main() {

    return 0;
}