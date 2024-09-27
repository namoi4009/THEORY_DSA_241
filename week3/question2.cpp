#include <iostream>

using namespace std;

template <typename T>
class AList {
private:
    const static int MAXSIZE = 20;
    T* data;
    int cursor = 0;
    int listSize;
public:
    AList() { this->data = new T[MAXSIZE]; }
    void insertBefore(const T& v, const T& k) {
        // Find the k value
        if (this->listSize == MAXSIZE) throw out_of_range("This list is full!");
        int i = 0;
        for (i = 0; i < this->listSize; i++) {
            if (this->data[i] == k) {
                this->cursor = i;
                for (int j = this->listSize; j > i; j--) {
                    this->data[j] = this->data[j - 1];
                }
                this->listSize++;
                this->data[cursor] = v;
                return;
            }
        }
    }
};

int main() {

    return 0;
}