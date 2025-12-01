// lab 7 bsee 24062.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Node of linked list
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack class
class Stack {
private:
    Node* top;   // top of stack

public:
    Stack() {
        top = NULL;
    }

    // Push operation (insert at top)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << value << endl;
    }

    // Pop operation (remove top)
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to pop.\n";
            return;
        }
        Node* temp = top;
        cout << "Popped: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    // Peek operation (view top element)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }
};

// Main program (menu)
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top)\n";
        cout << "4. Is Empty?\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            s.peek();
        }
        else if (choice == 4) {
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack is NOT empty.\n";
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}