#include <iostream>
using namespace std;

class linkedlist{
    private:
        struct node{
            int data;
            node *link;
        }*head;

    public:
        linkedlist(){
            head=nullptr;
        }

        void addbeg(int n){
            node *current;
            current = new node;
            current->data = n;
            current->link = head;
            head = current;
        }

        void addend(int n){
            node *current,*t;
            current = head;
            t = new node;
            t->data = n;
            t->link = NULL;
            if(current->link == NULL){
                current->link = t;
            }
            else{
                while(current->link!=NULL){
                    current = current->link;
                }
                current->link = t;
            }
        }

        void addafter(int n1,int n2){
            node *current;
            node *t;
            t = new node;
            t->data = n2;
            current = head;
            while(current->data!=n1){
                current = current->link;
            }
            t->link = current->link;
            current->link = t;
        }

        void deleteval(int n){
            node *current;
            node *r;
            current = head;
            r = head;
            while(current != NULL && current->data != n){
                r = current;
                current = current->link;
            }
            if(current == NULL){
                return;
            }
            if(current == head){
                head = head->link;
            }
            else{
                r->link = current->link;
            }
            delete current;
        }


        void display(){
            node *current;
            for(current = head;current!=NULL;current = current->link){
                cout << current->data << "\t";
            }
        }

        void length(){
            node *current;
            int count=0;
            for(current=head;current!=NULL;current=current->link){
                count++;
            }
            cout << "Elements in the list are " << count;
        }

};

int main(){
    int x = 1;
    int option;
    int data1=0;
    int data2=0;
    linkedlist l;
    do{
        cout << "*********************(Singly Linked List)*********************" << endl;
        cout << "1.Add element in beginning" << endl;
        cout << "2.Add element at the end" << endl;
        cout << "3.Add element after an element" << endl;
        cout << "4.Display all values available in nodes" << endl;  
        cout << "5.Delete a specified data" << endl;
        cout << "6.Elements in the list" << endl;
        cout << "0.Exit the Menu" << endl;
        cout << "**************************************************************" << endl;
        cout << "Enter the option:" << endl;
        cin >> option;
        switch(option){
            case 1:
                cout << "Enter data: ";
                cin >> data1;
                l.addbeg(data1);
                cout << endl;
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data1;
                l.addend(data1);
                cout << endl;
                break;
            case 3:
                cout << "Enter data after which value is to be added: ";
                cin >> data1;
                cout << "Enter value to add: ";
                cin >> data2;
                l.addafter(data1,data2);
                cout<< endl;
                break;
            case 4:
                l.display();
                cout << endl;
                break;
            case 5:
                cout << "Enter the value to be deleted: ";
                cin >> data1;
                l.deleteval(data1);
                cout << endl;
                break;
            case 6:
                l.length();
                cout << endl;
                break;
            case 0:
                x = 0;
                break;
        } 
    }while(x);
}