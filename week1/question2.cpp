#include <iostream>
#include <string>

using namespace std;

struct action {
    string op;
    int (*func)(int, int);
};

int myadd(int x, int y) { return x + y;}
int mymin(int x, int y) { return x - y;}
int mymul(int x, int y) { return x * y;}
int mydiv(int x, int y) { return x / y;}

int infix_cal(const string& input) {
    int i = 0;
    string substr = "";

    // Handle first argument
    while (input[i] != ' ') {
        substr += input[i];
        i++;
    }
    int a = stoi(substr);
    i++;

    // Store the sign, wait for calculating
    string sign = "";
    sign += input[i];
    i = i + 2;

    // Handle the second argument
    substr = "";
    while (input[i] != '\0') {
        substr += input[i];
        i++;
    }
    int b = stoi(substr);

    // Calculation
    action calc[4] = {
        {"+", myadd},
        {"-", mymin},
        {"*", mymul},
        {"/", mydiv}
    };
    
    for (i = 0; i < 4; i++)
        if (sign == calc[i].op)
            return calc[i].func(a, b);

    return 0;
}

int main() {
    cout << infix_cal("10 - 2");
    return 0;
}