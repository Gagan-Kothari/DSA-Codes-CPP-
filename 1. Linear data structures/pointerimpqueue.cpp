#include <iostream>
using namespace std;

class pointerQueue{
    private:
        struct node{
            int data;
            node *link;
        }*rear,*front;

    public:
        int count=0;

        pointerQueue(){
            rear = nullptr;
            front = nullptr;
        };

        void enqueue(int n){
            node *newQ;
            newQ = new node;
            newQ->data = n;
            newQ->link = NULL;

            if(front == NULL && rear == NULL){
                front = newQ;
                rear = newQ;
                count++;
                cout << "Element enqueued Successfully" << endl;         
            }
            else{
                rear->link = newQ;
                rear = newQ;
                count++;
                cout << "Element enqueued Successfully" << endl;
            }
        }

        void display(){
            node *temp;
            if(front == NULL && rear == NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                cout << "Queue is: " << endl;
                temp = front;
                while(temp!=NULL){
                    cout << temp->data << " ";
                    temp = temp->link;
                }
            }
        }

        void dequeue(){
            if(front == NULL and rear == NULL){
                cout << "Queue is empty" << endl;
            }

            else{
                node *temp;
                temp = front;
                front = front->link;
                delete temp;
                count--;
                cout << "First Element dequeued Successfully" << endl;
            }
        }

        void peeklast(){
            if(front==NULL && rear==NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                cout << "The last element of the queue is: " << rear->data << endl;
            }
        }

        void peek(){
            if(front == NULL && rear == NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                cout << "Element in the front of the queue is: " << front->data << endl;
            }
        }

        void size(){
            if(count == 0){
                cout << "Queue is empty" << endl;
            }
            else{
                cout << "The size of the queue is: " << count << endl;
            }
        }
};

int main(){
    int x=1;
    int option=0;
    int data = 0;
    pointerQueue Q;

    do{
        cout << "*********************************Pointer Implementation of Queue*********************************" << endl;
        cout << "MENU:" << endl;
        cout << "1.Display the Queue" << endl;
        cout << "2.Enqueue element" << endl;
        cout << "3.Deqeue element" << endl;
        cout << "4.Peek first element" << endl;
        cout << "5.Peek last element" << endl;
        cout << "6.Size of Queue" << endl;
        cout << "0.Exit the program" << endl;
        cout << "*************************************************************************************************" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch(option){
            default:   
                cout << "Please enter a valid option." << endl;
                break;

            case 1:
                Q.display();
                cout << endl;
                break;

            case 2:
                cout << "Enter data to enqueue: ";
                cin >> data;
                Q.enqueue(data);
                cout << endl;
                break;        

            case 3:
                Q.dequeue();
                break;

            case 4:
                Q.peek();
                break;
            
            case 5:
                Q.peeklast();
                break;

            case 6:
                Q.size();
                break;

            case 0:
                x = 0;
                cout << "Program exited successfully" << endl;
                break;
        }
    }while(x);
}