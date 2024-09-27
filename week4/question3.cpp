#include <bits/stdc++.h>

using namespace std;

static void Assert(bool b, string message) {
    if (!b) throw out_of_range(message);
}

// Stack abtract class
template <typename E>
class Stack
{
private:
    void operator=(const Stack &) {} // Protect assignment
    Stack(const Stack &) {}          // Protect copy constructor
public:
    Stack() {}          // Default constructor
    virtual ~Stack() {} // Base destructor
    // Reinitialize the stack. The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void clear() = 0;
    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(const E &it) = 0;
    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual E pop() = 0;
    // Return: A copy of the top element.
    virtual const E &topValue() const = 0;
    // Return: The number of elements in the stack.
    virtual int length() const = 0;
};

// Array-based stack implementation
template <typename E>
class AStack : public Stack<E>
{
private:
    int maxSize;  // Maximum size of stack
    int top;      // Index for top element
    E *listArray; // Array holding stack elements
public:
    AStack(int size = 1) // Constructor
    {
        maxSize = size;
        top = 0;
        listArray = new E[size];
    }
    ~AStack() { delete[] listArray; } // Destructor
    void clear() { top = 0; }         // Reinitialize
    void push(const E &it)
    { // Put "it" on stack
        Assert(top != maxSize, "Stack is full");
        listArray[top++] = it;
    }
    E pop()
    { // Pop top element
        Assert(top != 0, "Stack is empty");
        return listArray[--top];
    }
    const E &topValue() const
    { // Return top element
        Assert(top != 0, "Stack is empty");
        return listArray[top - 1];
    }
    int length() const { return top; } // Return length
};

int Fib(const int n)
{
    /* To do */
    if (n <= 1) return 1;

    int res = 1, temp = 1;
    AStack<int> fibo;
    fibo.push(temp);

    for (int i = 0; i < n - 1; i++)
    {
        temp = res;
        res += fibo.pop();
        fibo.push(temp);
    }

    return res;
}

int main()
{
    cout << Fib(5);
    return 0;
}