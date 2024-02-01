#include <iostream>
using namespace std;

class doublelinked{
    private:
        struct node{
            int data;
            node *next;
            node *prev;
        }*head;

    public:
        doublelinked(){
            head = nullptr;
        };

        void addtoempty(int n){
            node *temp;
            temp = new node;
            temp->data = n;
            temp->prev = NULL;
            temp->next = NULL;
            head = temp;
        }

        void addbeg(int n){
            node *temp;
            temp = new node;
            temp->next = NULL;
            temp->data = n;
            temp->prev = NULL;
            head->prev = temp;
            temp->next = head;
            head = temp;
        }

        void display(){
            node *temp;
            for(temp = head;temp!=NULL;temp=temp->next){
                cout << temp->data << "\t";
            }
        }

        void addend(int n){
            node *temp;
            node *current;
            temp = new node;
            temp->next = NULL;
            temp->data = n;
            current = head;
            while(current->next!=NULL){
                current = current->next;

            }
            temp->prev = current;
            current->next = temp;
        }

        void addafter(int n1,int n2){
            node *temp;
            node *current;
            temp = new node;
            temp->data = n2;
            current = head;
            while(current->data!=n1){
                current = current->next;
            }
            temp->next = current->next;
            temp->prev = current;
            current->next = temp;
            temp->next->prev = temp;
        }

        void deleteval(int n){
            node *tempprev=head;
            node *current=head;
            node *tempnext=head;

            while(current->data!=n){
                tempprev = current;
                current=current->next;
            }

            if(current==NULL){
                return;
            }
            if(current == head){
                head = head->next;
            }
            else{
                tempnext = current->next;
                tempprev->next = tempnext;
                tempnext->prev = current->prev;
                delete current;
            }
        }

        void length(){
            node *current;
            int count=0;
            for(current=head;current!=NULL;current = current->next){
                count++;
            }
            cout << "The total elements in the list are " << count;
        }

        void delfirst(){
            head = head->next;
        }

        void dellast(){
            node *current = head;
            node *sec = NULL;
            while(current->next != NULL){
                sec = current;
                current=current->next;
            }
            if(sec == NULL){
                head = NULL;
            }
            else{
                sec->next = NULL;
            }
            delete current;
        }
};

int main(){
    int x = 1;
    int option;
    int data1=0;
    int data2=0;
    doublelinked l;
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
                cout << "Enter data after which value is to be added: ";
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