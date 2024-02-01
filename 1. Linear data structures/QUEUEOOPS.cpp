#include <iostream>
using namespace std;

class classname{
    private:
        #define MAX 10
        int queue[MAX];
        int rear {-1};
        int front {0};
    public:
        void enqueue(int val){
            if(rear>=10){
                cout << "The list is FULL";
            }
            else{
                queue[rear+1] = val;
                rear++;
                cout << "Your value has been enqueued";
            }
        }

        void display(){
            int i {0};
            for(i=front;i<=rear;i++){
                cout << queue[i] << " | ";
            }
        }
        
        void dequeue(){
            int i {0};
            for(i=1;i<=rear;i++){
                queue[i-1] = queue[i];
            }
            rear--;
        }

        void peek(){
            cout << "The first element in the Queue is : " <<queue[front];
        }

        void rearele(){
            cout << "The element at the rear end is : " << queue[rear];
        }

        void isempty(){
            if (front == rear+1){
                cout << "Queue is Empty";
            }
            else{
                cout << "Queue is not Empty";
            }
        }

        void isfull(){
            if (rear==9){
                cout << "Queue is full";
            }
            else{
                cout << "No queue is not full";
            }
        }
        
        void size(){
            cout << "The size of the queue is : " << rear+1;
        }
};

int main(){
    classname obj;
    int x = 1;
    int option;
    do{
        cout << endl <<"**********************************ARRAY IMPLEMENTATION OF QUEUE**********************************" << endl;
        cout << "MENU:" <<endl;
        cout << "1.Display the queue" << endl;
        cout << "2.Enqueue an element" << endl;
        cout << "3.Dequeue the front element" << endl;
        cout << "4.Peek front element" << endl;
        cout << "5.Get rear Element"<< endl;
        cout << "6.Is queue Empty" << endl;
        cout << "7.Is queue Full" << endl;
        cout << "8.Size of Queue" << endl;
        cout << "0.Exit the Menu" << endl;
        cout << "*************************************************************************************************" << endl;
        cout << "Enter Option" << endl;
        cin >> option;
        switch(option){
            case 1:
                cout << "The Queue is : " << endl;
                obj.display();
                cout << endl << endl;
                break;
            case 2:
                int val;
                cout << "Enter the value you want to enqueue: ";
                cin >> val;
                obj.enqueue(val);
                cout << endl << endl;
                break;
            case 3:
                obj.dequeue();
                cout << "The front element has been dequeued" << endl << endl;
                break;
            case 4:
                obj.peek();
                cout << endl;
                break;
            case 5:
                obj.rearele();
                cout << endl;
                break;
            case 6:
                obj.isempty();
                cout << endl;
                break;
            case 7:
                obj.isfull();
                cout << endl;
                break;
            case 8:
                obj.size();
                cout << endl;
                break;
            case 0:
                x=0;
                break;
        }
    }while(x);
}