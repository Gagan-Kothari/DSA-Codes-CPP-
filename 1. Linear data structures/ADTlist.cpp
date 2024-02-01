#include <iostream>
using namespace std;

#define MAX 10
int list[MAX];
int last {-1};

void insertatend(int d){
    list[last+1] = d;
    last = last+1;

}

void display(){
    int i;
    for (i=0;i<=last;i++)
    cout << list[i] << "\t";
}

void datainbtw(int d, int p){
    int i;
    for(i=last;i>=p;i--)
    list[i+1] = list[i];
    list[p] = d;
    last = last+1;
}

void del(int p){
    int i;
    for(i=p;i<=last;i++)
    list[i] = list[i+1];
    last = last-1;
}

void get(int p){
    cout << list[p];
}

void replace(int p,int d){
    list[p] = d;
}

void removefirst(int d){
    int i;
    int j;
    for (i=0;i<=last;i++){
        if (d==list[i]){
            for (j=i;j<=last;j++){
                list[j] = list[j+1];
            }
            last = last-1;
            break;
        }
    }
}

int sizeoflist(){
    int i,count=0;
    for(i=0;i<=last;i++){
        count+=1;
    }
    return count;
}


void isfull(){
    if (sizeoflist() == MAX){
        cout << "true";
    }
    else{
        cout << "false";
    }
}

void isempty(){
    if (sizeoflist() == 0){
        cout << "true";
    }
    else{
        cout <<  "false";
    }
}

int main(){
    int option;
    int data;
    int position;
    int x = 1;
    do{
        cout << "*********************Array Implementation of List*********************" << endl;
        cout << "1.Insert element at end" << endl;
        cout << "2.Display" << endl;
        cout << "3.Insert element in between" << endl;
        cout << "4.Deletion" << endl;
        cout << "5.Get element at position" << endl;
        cout << "6.Replace element" << endl;
        cout << "7.Remove first Occurence" << endl;
        cout << "8.Is List full?" << endl;
        cout << "9.Is List Empty?" << endl;
        cout << "10.Size of list" << endl;
        cout << "0.Exit the Menu" << endl;
        cout << "**********************************************************************" << endl;
        cout << "Enter the option:" << endl;
        cin >> option;
        
        switch(option){
            case 1:
                cout << "Enter the data you want to add:" << endl;
                cin >> data;
                insertatend(data);
                break;
            case 2:
                cout << "Array: " << endl;
                display();
                cout << endl;
                break;
            case 3:
                cout << "Enter the data you want to enter: " << endl;
                cin >> data;
                cout << "Enter the postion where you want to enter the data: " << endl;
                cin >> position;
                datainbtw(data,position-1);
                break;
            case 4:
                cout << "Enter the postion of element you want to delete: " << endl;
                cin >> position;
                del(position-1);
                break;
            case 5:
                cout << "Enter the position of element you want to extract: " << endl;
                cin >> position;
                cout << "The element at that position is: " << endl;
                get(position-1);
                cout << endl;
                break;
            case 6:
                cout << "Enter the position: " << endl;
                cin >> position;
                cout << "Enter the data: " << endl;
                cin >> data;
                replace(position-1,data);
                break;
            case 7:
                cout << "Enter the value to remove: " << endl;
                cin >> data;
                removefirst(data);
                break;
            case 8:
                isfull();
                cout << endl;
                break;
            case 9:
                isempty();
                cout << endl;
                break;
            case 10:
                cout << "Total number of elements in list:" << endl << sizeoflist() << endl;
                break;
            case 0:
                x = 0;
                cout << "Exited Successfully";
        }
    }while(x);
}