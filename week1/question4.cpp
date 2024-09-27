#include <iostream>

using namespace std;

typedef struct Item* ptr;
struct Item {
    int value;
    ptr next;
};

Item* inputList() {
    Item* head = nullptr;
    int input = 1;

    while (1) {
        cin >> input;
        if (input >= 0) {
            Item* newNode = new Item;
            newNode->value = input;
            newNode->next = head;
            head = newNode;
            newNode = nullptr;
            delete newNode;
        } else break;
    }
    return head;
}

int main() {
    Item* head = inputList();
    Item* temp = head;
    while (temp->next != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << temp->value;
    return 0;
}