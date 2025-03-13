#include <iostream>
#include <stack>

using namespace std;

void check_brackets(string str) {
    stack<char> s;

    for (size_t i = 0; i < str.length(); i++) {
        char a = str[i];

        if (a == '[' || a == '{' || a == '(') {
            s.push(a);
        } 
        else if (a == ']' || a == '}' || a == ')') {
            if (s.empty()) {
                cout << "Syntax Error" << endl;
                return;
            }
            char c = s.top();
            s.pop();

            if ((c == '[' && a != ']') || (c == '{' && a != '}') || (c == '(' && a != ')')) {
                cout << "Syntax Error" << endl;
                return;
            }
        }
    }

    if (!s.empty()) {
        cout << "Syntax Error in your string" << endl;
    } else {
        cout << "No Syntax Error in your string" << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string with brackets: ";
    getline(cin, input);

    check_brackets(input);

    return 0;
}

