#include <iostream>
using namespace std;
#define MAX 100

int counter = 1;

class binarytree{
    private:
        int tree[MAX] {NULL};
    public:
        void add_element(int value){
            if(counter == 100){
                cout << "Maximum size of tree reached!" << endl;
            }
            else{
                tree[counter] = value;
                counter++;
            }
        }
};