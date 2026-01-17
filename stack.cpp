#include <iostream>
#include <stdexcept>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            throw overflow_error("Stack Overflow");
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            throw underflow_error("Stack Underflow");
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            throw underflow_error("Stack is empty");
        }
        return arr[top];
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.peek() << endl;
    cout << "Stack size: " << s.size() << endl;
    
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    
    cout << "Stack size: " << s.size() << endl;
    
    return 0;
}