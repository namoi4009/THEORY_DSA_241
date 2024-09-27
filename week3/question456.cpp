#include <iostream>

using namespace std;

template <typename E>
class List
{ // List ADT
private:
    void operator=(const List &) {} // Protect assignment
    List(const List &) {}           // Protect copy constructor
public:
    List() {}          // Default constructor
    virtual ~List() {} // Base destructor

    // Clear contents from the list, to make it empty.
    virtual void clear() = 0;

    // Insert an element at the current location.
    // item: The element to be inserted
    virtual void insert(const E &item) = 0;

    // Append an element at the end of the list.
    // item: The element to be appended.
    virtual void append(const E &item) = 0;

    // Remove and return the current element.
    // Return: the element that was removed.
    virtual E remove() = 0;

    // Set the current position to the start of the list
    virtual void moveToStart() = 0;

    // Set the current position to the end of the list
    virtual void moveToEnd() = 0;

    // Move the current position one step left. No change
    // if already at beginning.
    virtual void prev() = 0;

    // Move the current position one step right. No change
    // if already at end.
    virtual void next() = 0;

    // Return: The number of elements in the list.
    virtual int length() const = 0;

    // Return: The position of the current element.
    virtual int currPos() const = 0;

    // Set current position.
    // pos: The position to make current.
    virtual void moveToPos(int pos) = 0;

    // Return: The current element.
    virtual const E &getValue() const = 0;
};

// Code cau 4
template <typename E>
int count(List<E> &L,E K) {
    int count = 0;
    for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
        int it = L.getValue();
        if (it == K) count++;
    }
    return count;
}

// Code cau 5
template <typename T> 
void del(List<T> &L,T k) {
    L.moveToStart();
    while(L.currPos() < L.length()) {
        if (L.getValue() == k) {
            L.remove();
            L.prev();
        } else L.next();
    }
}

// Code cau 6
template <typename T>
void DuplicationKiller(List<T> &L) {
    int i = 0;
    
    while (i < L.length()) {
        L.moveToPos(i);
        T data = L.getValue();
        bool isDuplicate = false;
        
        int j = i + 1;
        while (j < L.length()) {
            L.moveToPos(j);
            if (L.getValue() == data) {
                L.remove();
                isDuplicate = true;
            } else {
                j++;
            }
        }
        
        if (isDuplicate) {
            L.moveToPos(i);
            L.remove();
        } else {
            i++;
        }
    }
}

int main() {

    return 0;
}