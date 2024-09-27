#include <iostream>

using namespace std;

typedef struct Item* ptr;
struct Item {
    double coef;
    int exp;
    ptr next;
};

ptr inputList(ptr head, double coef, int exp) {
    ptr newNode = new Item;
    newNode->coef = coef;
    newNode->exp = exp;    
    newNode->next = nullptr;
    
    if (!head) {
        head = newNode;
    } else {
        ptr temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    return head;
}

void normalizePolynomial(ptr& head) {
    if (!head) return;

    ptr i = head;
    while (i && i->next) {
        ptr j = i;
        while (j->next) {
            if (i->exp == j->next->exp) {
                i->coef += j->next->coef;

                ptr delNode = j->next;
                j->next = j->next->next;
                delete delNode;
            } else {
                j = j->next;
            }
        }
        i = i->next;
    }

    ptr dummyNode = new Item{0, 0, head};
    ptr prev = dummyNode;
    i = head;

    while (i) {
        if (i->coef == 0) {
            prev->next = i->next;
            delete i;
            i = prev->next;
        } else {
            prev = i;
            i = i->next;
        }
    }

    head = dummyNode->next;
    delete dummyNode;
}

void printList(ptr& head) {
    if (!head) {
        return;
    }
    ptr temp = head;
    while (temp->next != nullptr) {
        cout << "(" << temp->coef << ", " << temp->exp << ") ";
        temp = temp->next;
    }
    cout << "(" << temp->coef << ", " << temp->exp << ")" << endl;
}

int main() {
    ptr head = nullptr;
    head = inputList(head, 2, 3);
    head = inputList(head, 1, 4);
    head = inputList(head, -2, 3);
    head = inputList(head, 0, 0);
    printList(head);

    normalizePolynomial(head);
    printList(head);
    return 0;
}