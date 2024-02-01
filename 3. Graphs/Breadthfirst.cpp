#include<iostream>
using namespace std;

class breadthfirstsearch{
    private:
        int a[10][10];
        int n,*stack;
    public:
        breadthfirstsearch(){  // initialising constructor
            cout<<"Breadth first Search"<<endl;
            cout<<"Enter the no of node:";
            cin>>n;
            stack = new int[n]; // creates stack
            for(int i=0;i<=n;i++){ // initialises all stack values to zero
                stack[i]=0; 
                for(int j=0;j<=n;j++){
                    a[i][j]=0; // intitialises all matrix values to zero
                }
            }               
        }

        void getval(){
            for(int i=1;i<n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=j){
                        cout<<"\n Enter the value at "<< i <<","<< j << ":"; // input values 1 or 0 in the adjacency matrix
                        cin>>a[i][j];
                    }
                }
            }
        }

        void searchfrom(int k){
            for(int i=1;i<=n;i++){
                if(a[k][i]!=0){
                    if(stack[i]==0){
                        stack[i] = 1;
                        cout << i << "->";
                    }
                }
            }
            while(k<n){
                searchfrom(k+1);
                break;
            }
        }
        
        void display(){
        cout<<"\n Nodes visited in order:"<<endl;
        for(int i=1;i<=n;i++){ 
            if(stack[i]==0){ // if element in stack is found to be zero it searches from that i
                searchfrom(i);
            }
        }
    }
};

int main(){                    
    breadthfirstsearch bfs;
    bfs.getval();
    bfs.display();
}