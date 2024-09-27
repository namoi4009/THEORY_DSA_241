#include <iostream>

using namespace std;

unsigned int fibo(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    int prev = 0;
    int curr = 1;
    int fiboNum = 0;
    for (int i = 1; i < n; i++) {
        fiboNum = curr + prev;
        prev = curr;
        curr = fiboNum;
    }
    
    return fiboNum;
}

int main() {
    cout << fibo(3) << endl;
    return 0;
}