#include <iostream>

using namespace std;

template <typename T>
class AList :public List<T> {
private:
    const static int MAX = 20;
    T* data;
    int cursor = 0;
    int size;
public:
    AList() { data = new T[MAX];}

    void insert(const T& v) {
    for (int i = size; i > this->cursor; i--) {
        this->data[i] = this->data[i - 1];
    }
    size++;
    this->data[cursor] = v;
}
};

int main() {

    return 0;
}