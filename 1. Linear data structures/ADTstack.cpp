#include <iostream>
using namespace std;

#define MAX 10
int stack[MAX];
int top {-1};

void push(int d){
    stack[top+1]= d;
    top = top+1;
}

void sttop(){
    cout<<stack[top];
}

void size(){
    cout << top+1;
}

void pop(){
    top = top-1;
}

void empty(){
    top=-1;
}

void disp(){
    int i;
    cout << "The stack: " << endl;
    for (i=top;i>=0;i--){
        cout << "|"<<stack[i] << "|"<< endl<<"---"<<endl;
    }
}

int sizeofstack(){
    int i,count=0;
    for(i=0;i<=top;i++){
        count+=1;
    }
    return count;
}


int main(){
    int option;
    int data;
    int x = 1;
    do{
        cout << "*********************Array Implementation of Stack*********************" << endl;
        cout << "1.Push element in stack" << endl;
        cout << "2.Display top element" << endl;
        cout << "3.Size of stack" << endl;
        cout << "4.Pop element from stack" << endl;  
        cout << "5.Empty stack" << endl; 
        cout << "6.Display the stack"<< endl;
        cout << "0.Exit the Menu";
        cout << "**********************************************************************" << endl;
        cout << "Enter the option:" << endl;
        cin >> option;

        switch(option){
            case 1:
                cout << "Enter the data to insert: " << endl;
                cin >> data;
                push(data);
                break;
            case 2:
                cout << "The top-most element in the stack is: ";
                sttop();
                cout << endl;
                break;
            case 3:
                cout << "The size of the stack is: ";
                cout << sizeofstack() << endl;
                break;
            case 4:
                pop();
                break;
            case 5:
                empty();
                break;
            case 6:
                disp();
                cout << endl;
                break;
            case 0:
                x=0;
                cout << "Exited Successfully";
        }
    }while(x);
}