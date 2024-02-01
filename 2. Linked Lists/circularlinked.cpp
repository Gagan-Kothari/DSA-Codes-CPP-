#include <iostream>
using namespace std;

class circularlinked{
    private:
        struct node{
            int data;
            node *link;
        }*tail;
    public:
        int count=0;
        circularlinked(){
            tail = nullptr;
        }

        void addtoempty(int n){
            node *temp;
            temp = new node;
            temp->data = n;
            temp->link = temp;
            tail = temp;
        }

        void addbeg(int n){
            node *newnode;
            newnode = new node;
            newnode->data = n;
            if(tail == nullptr){
                tail = newnode;
                tail->link = tail;
            }else{
                newnode->link = tail->link;
                tail->link = newnode;
            }
        }

        void display(){
            node *temp;
            temp = tail->link;
            do{
                cout << temp->data << "\t";
                temp = temp->link;
            }while(temp!=tail->link);
        }

        void length(){
            node *temp;
            temp = tail->link;
            do{
                count++;
                temp=temp->link;
            }while(temp!=tail->link);
            cout << "Total elements in the list are: " << count;
        }

        void addend(int n){
            node *temp;
            temp = new node;
            temp->data = n;
            temp->link = tail->link;
            tail->link = temp;
            tail = temp;
        }

        void addafter(int n1, int n2) {
            node *newnode;
            node *pos = tail->link;
            newnode = new node;
            newnode->data = n2;
            while (n1 > 1) {
                pos = pos->link;
                n1--;
            }
            newnode->link = pos->link;
            pos->link = newnode;
        }


        void deleteval(int n){
            node *pos;
            node *prev;
            pos = tail->link;
            while(pos->data!=n){
                prev = pos;
                pos = pos->link;
            }
            prev->link = pos->link;
            delete pos;
        }

        void delfirst() {
            if (tail == nullptr) {
                cout << "The list is empty" << endl;
                return;
            }
            node *temp = tail->link;
            if (tail == temp) {
                tail = nullptr;
            } else {
                tail->link = temp->link;
            }
            delete temp;
        }

        void dellast() {
            if (tail == nullptr) {
                cout << "The list is empty" << endl;
                return;
            }
            if (tail->link == tail) {
                delete tail;
                tail = nullptr;
            } else {
                node *temp = tail->link;
                while (temp->link != tail) {
                    temp = temp->link;
                }
                temp->link = tail->link;
                delete tail;
                tail = temp;
            }
        }

};

int main(){
    int x = 1;
    int option;
    int data1=0;
    int data2=0;
    circularlinked l;
    do{
        cout << "*********************(Doubly Linked List)*********************" << endl;
        cout << "1.Add element to empty" << endl;
        cout << "2.Add element to beginning" << endl;
        cout << "3.Add element at the end" << endl;
        cout << "4.Add element after an element" << endl;
        cout << "5.Display all values available in nodes" << endl;  
        cout << "6.Delete a specified data" << endl;
        cout << "7.Elements in the list" << endl;
        cout << "8.Delete first element" << endl;
        cout << "9.Delete last element" << endl;
        cout << "0.Exit the Menu" << endl;
        cout << "**************************************************************" << endl;
        cout << "Enter the option:" << endl;
        cin >> option;
        switch(option){
            default:
                cout << "Please enter a value from the Menu";
                cout << endl;
                break;
            case 1:
                cout << "Enter data: ";
                cin >> data1;
                l.addtoempty(data1);
                cout << endl;
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data1;
                l.addbeg(data1);
                cout << endl;
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data1;
                l.addend(data1);
                cout << endl;
                break;
            case 4:
                cout << "Enter index at which value is to be added: ";
                cin >> data1;
                cout << "Enter value to add: ";
                cin >> data2;
                l.addafter(data1,data2);
                cout<< endl;
                break;
            case 5:
                l.display();
                cout << endl;
                break;
            case 6:
                cout << "Enter the value to be deleted: ";
                cin >> data1;
                l.deleteval(data1);
                cout << endl;
                break;
            case 7:
                l.length();
                cout << endl;
                break;
            case 8:
                l.delfirst();
                cout << endl;
                break;
            case 9:
                l.dellast();
                cout << endl;
                break;
            case 0:
                x = 0;
                break;
        } 
    }while(x);
}