#include<iostream>
using namespace std;

class depthfirstsearch{
    private:
        int a[10][10];
        int n,*stack;
    public:
        depthfirstsearch(){  // initialising constructor
            cout<<"Depth first Search"<<endl;
            cout<<"Enter the no of node:";
            cin>>n;
            stack=new int[n]; // creates stack
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
                        cout<<"\n Enter the value at"<< i<<","<< j << ":"; // input values 1 or 0 in the adjacency matrix
                        cin>>a[i][j];
                    }
                }
            }
        }

        void searchfrom(int k){
            cout<<k<<"->";
            stack[k]=1;  // intitalises that element as 1 due to presence of link while searching
            for(int i=1;i<=n;i++){
                if(stack[i]==0 && a[k][i]!=0){ // runs until a 1 is found in the adjacency matrix and is 0 in the stack
                    searchfrom(i);             // i.e. element is in not visited but is linked in the graph
                }
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
    depthfirstsearch dfs;
    dfs.getval();
    dfs.display();
}