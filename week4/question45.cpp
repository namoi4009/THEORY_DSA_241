#include <iostream>
#include <string>

using namespace std;

void Assert(bool val, string s)
{
    if (!val)
    { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
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
    AStack(int size = 10) // Constructor
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

bool parentheses(const string &L) {
    /* To do */
    Stack<char>* open = new AStack<char>();
    for (int i = 0; i < (int)L.length(); i++) {
        if (L[i] == '(') {
            open->push(L[i]);
        } else if (L[i] == ')') {
            if (open->length() == 0) {
                delete open;
                return false;
            } else open->pop();
        }
    }
    bool res = open->length() == 0;
    delete open;
    return res;
}

// bool isBalancedHelper(const std::string &str, unsigned int index, int balance)
// {
//     if (index == str.length())
//     {
//         return balance == 0;
//     }
//     if (str[index] == '(')
//     {
//         return isBalancedHelper(str, index + 1, balance + 1);
//     }
//     else if (str[index] == ')')
//     {
//         if (balance <= 0)
//         {
//             return false;
//         }
//         return isBalancedHelper(str, index + 1, balance - 1);
//     }
//     return isBalancedHelper(str, index + 1, balance);
// }

bool help(const char *s, Stack<char> *store)
{
    if (*s == '\0') return store->length() == 0;
    if (*s == '(') store->push(*s);
    if (*s == ')') {
        if (store->length() == 0) return false;
        store->pop();
    }
    return help(s + 1, store);
}

bool recursiveParentheses(const string &L)
{
    /* to check if the string L includes balanced parentheses or not */
    Stack<char> *store = new AStack<char>();
    return help(&L[0], store);
}

int main()
{
    string z = "((())())()";
    cout << parentheses(z) << endl;
    return 0;
}