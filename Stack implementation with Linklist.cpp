#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
private:
    Node *head;

public:
    Stack() {
        head = NULL;
    }

    // Checks if the stack is empty
    bool isEmpty() {
        return head == NULL;
    }

    // Displays the top element
    void peek() {
        if (isEmpty()) {
            cout << "Stack is currently empty" << endl;
        } else {
            cout << head->data << " is the top element" << endl;
        }
    }

    // Returns the size of the stack
    int usedSize() {
        Node *tmp = head;
        int count = 0;
        while (tmp != NULL) {
            count++;
            tmp = tmp->next;
        }
        return count;
    }

    // Pushes an element onto the stack
    void push(int d) {
        Node *tmp = new Node;
        tmp->data = d;
        tmp->next = head;
        head = tmp;
        cout << head->data << " is pushed onto the stack" << endl;
    }

    // Pops the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Underflow Condition" << endl;
        } else {
            cout << head->data << " is popped from the stack" << endl;
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // Destructor to delete the stack
    ~Stack() {
        while (head != NULL) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        cout << "Stack is deleted" << endl;
    }
};

// Main function
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top Element)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Stack Size\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;
            case 5:
                cout << "Stack size: " << s.usedSize() << endl;
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

