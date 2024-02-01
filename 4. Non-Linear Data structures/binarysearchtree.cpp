#include <iostream>
using namespace std;

class binarysearchtree {
private:
    struct node {
        int data;
        node* left;
        node* right;
    }* root;

public:
    binarysearchtree() {
        root = NULL;
    }

    void joinnode(node* parent, node* branch) {
        if (parent->left == NULL) {
            parent->left = branch;
        }
        else if (parent->right == NULL) {
            parent->right = branch;
        }
    }

    node* createNode(int data) {
        node* newNode = new node;
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    void createnode(int n) {
        node* branch = createNode(n);
        if (root == NULL) {
            root = branch;
        }
        else {
            node* parent = root;
            while (parent != NULL) {
                if (n < parent->data) {
                    if (parent->left == NULL) {
                        parent->left = branch;
                        break;
                    }
                    else {
                        parent = parent->left;
                    }
                }
                else if (n > parent->data) {
                    if (parent->right == NULL) {
                        parent->right = branch;
                        break;
                    }
                    else {
                        parent = parent->right;
                    }
                }
                else {
                }
            }
        }
    }

    void inorderTraversal(node* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void display() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    binarysearchtree bst;
    int choice, data;
    do {
        cout << endl;
        cout << "*********************Binary Search Tree Menu***********************" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Display the binary search tree" << endl;
        cout << "3. Exit" << endl;
        cout << "************************************************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter node data: ";
            cin >> data;
            bst.createnode(data);
            break;
        case 2:
            cout << "The binary tree is: ";
            bst.display();
            cout << endl;
            break;
        case 3:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    return 0;
}