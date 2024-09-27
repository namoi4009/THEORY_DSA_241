#include <iostream> 

using namespace std;

typedef struct Item* ptr;
struct Item {
    double coef;
    int exp;
    ptr next;
};

ptr inputPolynomial() {
    ptr head = nullptr;
    while (1) {
        double coef = 0;
        int exp = 0;
        cin >> coef >> exp;
        if (coef == 0) {
            return head;
        } else {
            ptr newNode = new Item;
            newNode->coef = coef;
            newNode->exp = exp;
            newNode->next = head;
            head = newNode;
        }
    }
}

void printList(ptr head) {
    ptr temp = head;
    while (temp != nullptr) {
        cout << temp->coef << " " << temp->exp << endl;
        temp = temp->next;
    }
}

int main() {
    ptr head = inputPolynomial();
    printList(head);
    return 0;
}