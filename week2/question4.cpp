#include <iostream>

using namespace std;

template <typename T>
int findMax(T arr[], int n) {
    T max = arr[0];
    for (int i = 0; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    int index = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == max) 
            index = i;
    return index;
}

int main() {
    int a[] = {1, 5, 3, 4, 5};
    int n = findMax<int>(a, 5);
    cout << n << endl;
    return 0;   
}