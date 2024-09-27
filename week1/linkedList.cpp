#include <iostream>
#include <vector>

using namespace std;

typedef Item* ptr;
struct Item {
    int num;
    ptr next;
};

ptr addNode(ptr& head, int num) {    
    ptr newNode = new Item;
    newNode->num = num;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        ptr temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
    return head;
}

ptr deleteNode(ptr& head, int x) {
    ptr dummyNode = new Item;
    dummyNode->next = head;
    ptr temp = dummyNode;
    while (temp->next) {
        if (temp->next->num == x) {
            ptr delNode = temp->next;
            if (temp->next == head) head = head->next;
            temp->next = temp->next->next;
            delete delNode;
            delNode = nullptr;
        }
    }
    delete dummyNode;
    dummyNode = nullptr;
    return head;
}

int main() {
    ptr head = nullptr;
    ptr head = addNode(head, 5);
    ptr head = addNode(head, 6);
    ptr head = addNode(head, 7);
    ptr head = addNode(head, 8);
    ptr head = addNode(head, 9);
    return 0;
}