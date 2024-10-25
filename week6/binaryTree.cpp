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

// Question 3
template <typename E>
BNode<E>* findMin(BNode<E>* node) {
    while (node->left() != nullptr) {
        node = node->left();
    }
    return node;
}

template <typename E>
BNode<E>* BSTdelete(BNode<E>* root, E val) {
    if (root == nullptr) {
        return nullptr;
    }

    if (val < root->element()) {
        root->setLeft(BSTdelete(root->left(), val));
    }
    else if (val > root->element()) {
        root->setRight(BSTdelete(root->right(), val));
    }
    else {
        if (root->left() == nullptr && root->right() == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left() == nullptr) {
            BNode<E>* temp = root->right();
            root->setRight(nullptr);
            delete root;
            return temp;
        }
        else if (root->right() == nullptr) {
            BNode<E>* temp = root->left();
            root->setLeft(nullptr);
            delete root;
            return temp;
        }
        else {
            BNode<E>* successor = findMin(root->right());
            root->setElement(successor->element());
            root->setRight(BSTdelete(root->right(), successor->element()));
        }
    }
    return root;
}

// Question 4
template <typename E>
bool check(BNode<E>* node, E min, E max) {
    if (!node) return true;
    if (node->element() < min || node->element() > max)
        return false;
    return check(node->left(), min, node->element()) && check(node->right(), node->element(), max);
}

template <typename E>
bool isBST(BNode<E>* root) {
    if (!root) return false;
    return check(root, numeric_limits<E>::lowest(), numeric_limits<E>::max());
}

// Question 5
template <typename E>
int countNode(BNode<E>* root) {
    if (!root) return 0;
    return 1 + countNode(root->left()) + countNode(root->right());
}

template <typename E>
bool helper(BNode<E> node, int index, int total) {
    if (!node) return true;
    if (index >= total) return false;
    return helper(node->left(), 2 * index + 1, total) && helper(node->right(), 2 * index + 2, total);
}

template <typename E>
bool isComplete(BNode<E>* root) {
    if (!root) return false;
    int count = countNode(roots);
    return helper(root, 0, count);
}

// Question 6
template <typename E>
bool isFull(BNode<E>* root) {
    if (!root) return false;
    if (!root->left() && !root->right()) return true;
    if (root->left() && root->right()) return isFull(root->left()) && isFull(root->right());
    return false;
}

// Question 7
template <typename E>
void LargestSmaller(BNode<E>* root, E key) {
    E res = numeric_limits<E>::lowest();
    BNode<E>* curr = root;
    while (curr) {
        if (curr->element() < key) {
            res = curr->element();
            curr = curr->right();
        } else {
            curr = curr->left();
        }
    }
    if (res != numeric_limits<E>::lowest()) cout << res;
}


int main() {

    return 0;
}