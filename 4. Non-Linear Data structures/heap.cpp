#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class MaxHeap {
public:
    void insert(int a[], int& n, int value) {
        int i = n;
        a[i] = value;
        while (i > 0) {
            int p = floor((i - 1) / 2);
            if (a[p] > a[i]) {
                swap(a[p], a[i]);
                i = p;
            }
            else {
                break;
            }
        }
        n++;
    }

    void remove(int a[], int& n) {
        if (n == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        swap(a[0], a[n - 1]);
        n--;
        int i = 0;
        while (i < n) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;
            if (left < n && a[left] < a[largest]) {
                largest = left;
            }
            if (right < n && a[right] < a[largest]) {
                largest = right;
            }
            if (largest != i) {
                swap(a[i], a[largest]);
                i = largest;
            }
            else {
                break;
            }
        }
    }

    void display(int a[], int n) {
        if(n == 0){
            cout << "Heap is empty";
        }
        else{
            for (int i = 0; i < n; i++) {
                cout << a[i] << "\t";
            }
        }
        cout << endl;
    }
};

int main() {
    int option = 0;
    int data = 0;
    int heapsize = 0;
    int heapstruct[30];
    MaxHeap h;

    do {
        cout << "*******************************************************" << endl;
        cout << "1. Display heap" << endl;
        cout << "2. Add element to heap" << endl;
        cout << "3. Delete element from heap" << endl;
        cout << "0. Exit" << endl;
        cout << "*******************************************************" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
        default:
            cout << "Enter a valid option!" << endl;
            break;

        case 1:
            h.display(heapstruct, heapsize);
            break;

        case 2:
            if (heapsize >= 30) {
                cout << "Heap is full!" << endl;
            }
            else {
                cout << "Enter element to insert in heap: ";
                cin >> data;
                h.insert(heapstruct, heapsize, data);
            }
            break;

        case 3:
            h.remove(heapstruct, heapsize);
            break;

        case 0:
            option = 0;
            cout << "Exited Successfully" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}