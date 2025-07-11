#include<iostream>
using namespace std;

int main() {
    char operator_char;  // Renamed variable
    cout << "Enter operator: ";
    cin >> operator_char;

    int x;
    cout << "Enter first number: ";
    cin >> x;

    int y;
    cout << "Enter second number: ";
    cin >> y;

    if (operator_char == '+') {
        cout << x + y;
    } else if (operator_char == '-') {
        cout << x - y;
    } else if (operator_char == '*') {
        cout << x * y;
    } else if (operator_char == '/') {
        if (y != 0) {
            cout << x / y;
        } else {
            cout << "Division by zero is not allowed";
        }
    } else {
        cout << "Invalid operator";
    }

    return 0;
}
