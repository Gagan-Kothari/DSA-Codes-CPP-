#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* link;
    };

    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int n) {
        Node* newNode = new Node;
        newNode->data = n;
        newNode->link = top;
        top = newNode;
        size++;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Empty Stack" << endl;
        } else {
            cout << "Data on top of stack is: " << top->data << endl;
        }
    }

    void sizeofstack() {
        cout << "Size of the stack is: " << size << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. No element to pop" << endl;
        } else {
            Node* temp = top;
            top = top->link;
            cout << "Popped element: " << temp->data << endl;
            delete temp;
            size--;
        }
    }

    void disp() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is: " << endl;
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << endl;
                current = current->link;
            }
        }
    }
};

int main() {
    int option;
    int data;
    int x = 1;
    Stack s;

    do {
        cout << "********************* Pointer Implementation of Stack *********************" << endl;
        cout << "1. Display the stack" << endl;
        cout << "2. Push element into the stack" << endl;
        cout << "3. Pop element from the stack" << endl;
        cout << "4. Display top element" << endl;
        cout << "5. Size of the stack" << endl;
        cout << "0. Exit the menu" << endl;
        cout << "**************************************************************************" << endl;
        cout << "Enter an option:" << endl;
        cin >> option;

        switch (option) {
            case 0:
                x = 0;
                cout << "Exited Successfully" << endl;
                break;
            case 1:
                s.disp();
                cout << endl;
                break;
            case 2:
                cout << "Enter the data to insert: " << endl;
                cin >> data;
                s.push(data);
                break;
            case 3:
                s.pop();
                cout << endl;
                break;
            case 4:
                s.peek();
                cout << endl;
                break;
            case 5:
                s.sizeofstack();
                cout << endl;
                break;
            default:
                cout << "Enter an option from the menu only" << endl;
                break;
        }
    } while (x);

    return 0;
}
