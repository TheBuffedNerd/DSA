#include <iostream>
using namespace std;

class Stack {
		private:
			int *ptr;
			int tsize;
			int top;
		
		public:
			Stack(int tsize);
			~Stack();
			void push(int d);
			int pop();
			int peek();
			void usedsize();
			bool isEmpty();
			bool isFull();
		};

//contructor to initialize the private members			
	Stack::Stack(int t) {
		tsize = t;
		ptr = new int[tsize];
		top = -1;
	}

//tells if stack is empty		
	bool Stack::isEmpty() {
		if(top < 0) {
			return true;
		} else {
			return false;
		}
	}

//tells if stack is full	
	bool Stack::isFull() {
		if(top >= tsize-1){
			return true;
		} else {
			return false;
		}
	}

//tells the top value of stack	
	int Stack::peek() {
		if(!isEmpty()){
			cout << "The top element of the stack is "<< ptr[top]<<endl;
		} else {
			cout << "Stack is Empty" <<endl;
			exit(0);
		}
	}

//tells the used size of stack	
	void Stack::usedsize() {
		cout << "Currently there are " <<top+1<<" Elements on the stack"<<endl;
	}

//pushes a value on stack	
	void Stack::push(int d){
		if(isFull()) {
			cout << "Overflow Condition"<<endl;
			return;
		} else {
			cout << d << " is pushed on the stack" <<endl;
			top++;
			ptr[top] = d;
		}
	}
	
// pop function
	int Stack::pop() {
		if(isEmpty()) {
			cout << "Underflow Condition" << endl;
			exit(0);
		} else {
			cout << ptr[top] << " is popped from the stack" <<endl;
			top--;
		}
	}
	
//destructor to deallocate the DMA	
	Stack::~Stack() {
		delete[] ptr;
	}
	
	
// Main function
int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack s(size);

    int choice, value;
    
    while (true) {
        cout << "\n----- Stack Operations Menu -----" << endl;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check Size\n5. Exit\n";
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
                value = s.peek();
                break;
            case 4:
                s.usedsize();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

