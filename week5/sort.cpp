#include <bits/stdc++.h>

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

// Question 1
template <typename E>
void bubbleSort(List<E> &L)
{
    int n = L.length();

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            L.moveToPos(j);
            const E &current = L.getValue();

            L.moveToPos(j + 1);
            const E &next = L.getValue();

            if (current > next)
            {
                L.moveToPos(j + 1);
                L.remove();
                L.moveToPos(j);
                L.remove();
                L.insert(next);
                L.next();
                L.insert(current);
            }
        }
    }
}

// Question 2
template <typename E>
void selectionSort(List<E> &L)
{
    int n = L.length();

    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        L.moveToPos(i);
        E minValue = L.getValue();

        for (int j = i + 1; j < n; ++j)
        {
            L.moveToPos(j);
            E currentValue = L.getValue();

            if (currentValue < minValue)
            {
                minIndex = j;
                minValue = currentValue;
            }
        }

        if (minIndex != i)
        {
            L.moveToPos(minIndex);
            E minElement = L.getValue();
            L.remove();
            L.moveToPos(i);
            L.insert(minElement);
        }
    }
}

// Question 3
template <typename E>
void insertionSort(List<E> &L) {
    int n = L.length();
    for (int i = 0; i < len - 1; i++) {
        L.moveToPos(i);
        E key = L.getValue();
        L.remove();
        int j = i - 1;

        while (j > 0) {
            L.moveToPos(j);
            E prev = L.getValue();
            if (prev > key) {
                j--;
                L.moveToPos[j];
                prev = L.getValue();
            } else {
                L.insert(key);
                break;
            }
        }
    }
}

// Question 4
template <typename T>
void mergesort(T arr[],int left, int right)
{
     if (left < right) {
        int mid = left + (right - left) / 2; 
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Question 5
template <typename E>
int partition(List<E> &L, int low, int high, E& pivot) {
    int n = L.length();
    if (low < 0) low = 0;
    if (high >= n) high = n - 1;
    L.moveToPos(high);
    pivot = L.getValue();
    int i = low;
    for (int j = low; j < high; ++j) {
        L.moveToPos(j);
        if (L.getValue() <= pivot) {
            if (i != j) {
                swap(L, i, j);
            }
            i++;
        }
    }
    swap(L, i, high);
    return i;   
}

// Question 6
template <typename E>
void quickSort(List<E> &L)
{
    if (L.length() > 0)
    {
        lol(L, 0, L.length() - 1);
    }
}

int main() {
    // Testcase
    cout << endl << k << endl;
    return 0;
}