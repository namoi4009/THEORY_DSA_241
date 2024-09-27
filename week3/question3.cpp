template <typename T>

class AList : public List<T>{
private:
    const static int MAXSIZE = 20; //the maximum members of the list
    T* data; // keep the list
    int cursor = 0; // keep the position of the cursor
    int listSize; // the real size of the list
public:
    AList() { this->data = new T[MAXSIZE]; }
    void remove() {
        if (this->cursor == listSize) throw out_of_range("Cannot remove element");
        for (int i = this->cursor; i < MAXSIZE; i++) {
            this->data[i] = this->data[i + 1];
        }
        listSize--;
    }
};

int main() {

    return 0;
}