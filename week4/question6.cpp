#include <bits/stdc++.h>

using namespace std;

void Assert(bool val, string s)
{
    if (!val)
    { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
}

// Doubly linked list link node with freelist support
template <typename E>
class Link
{
private:
    static Link<E> *freelist; // Reference to freelist head
public:
    E element;  // Value for this node
    Link *next; // Pointer to next node in list
    Link *prev; // Pointer to previous node
    // Constructors
    Link(const E &it, Link *prevp, Link *nextp)
    {
        element = it;
        prev = prevp;
        next = nextp;
    }
    Link(Link *prevp = NULL, Link *nextp = NULL)
    {
        prev = prevp;
        next = nextp;
    }
    void *operator new(size t)
    { // Overloaded new operator
        if (freelist == NULL)
            return ::new Link;    // Create space
        Link<E> *temp = freelist; // Can take from freelist
        freelist = freelist->next;
        return temp; // Return the link
    }
    // Overloaded delete operator
    void operator delete(void *ptr)
    {
        ((Link<E> *)ptr)->next = freelist; // Put on freelist
        freelist = (Link<E> *)ptr;
    }

    E removePre() {
        E e;
        Assert(curr != head, "No element");
        Link<E>* delNode = curr;
        e = delNode->element;
        curr->next->prev = delNode->prev;
        curr->prev->next = delNode->next;
        curr = curr->prev;
        delete delNode;
        return e;
    }

    E remove()
    {
        if (curr->next == tail) // Nothing to remove
            return NULL;
        E it = curr->next->element;  // Remember value
        Link<E> *ltemp = curr->next; // Remember link node
        curr->next->next->prev = curr;
        curr->next = curr->next->next; // Remove from list
        delete ltemp;                  // Reclaim space
        cnt--;                         // Decrement cnt
        return it;
    }
};
// The freelist head pointer is actually created here
template <typename E>
Link<E> *Link<E>::freelist = NULL;