#include <iostream>

using namespace std;

// Custom Stack class
class Stack {
private:
    static const int MAX = 1000; // Maximum stack size
    char arr[MAX]; // Stack array
    int top;

public:
    Stack() { top = -1; } // Constructor initializes an empty stack

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0'; // Return null character if empty
        }
        return arr[top--];
    }
};

void Reverse_String() {
    string str;
    cout << "Enter the String: ";
    getline(cin, str);

    cout << "Original String is: " << str << endl;

    Stack s; // Use custom Stack class

    // Push all characters onto the stack (Replaced range-based loop)
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    cout << "String in Reverse is: ";

    // Pop and print characters to reverse the string
    while (!s.isEmpty()) {
        cout << s.pop();
    }

    cout << endl;
}

int main() {
    Reverse_String();
    return 0;
}

