//paranthesis checking 
#include<iostream>
using namespace std;
char in[100];
char st[100];
int top= -1;

int main(){
    cin>>in;
    for (int i = 0;in[i]!='\0';i++){
        if (in[i]=='{'|| in[i]=='['||in[i]=='('){
                top=top+1;
                st[top]=in[i];
        }
    //[{()}]
        else if(in[i]==')'){
            if(st[top]=='('){
                top=top-1;

            }
            else{
                cout<<"invalid expression\n";
            }
        }
         else if(in[i]=='}'){
            if(st[top]=='{'){
                top=top-1;

            }
            else{
                cout<<"invalid expression\n";
            }
        }
         else if(in[i]==']'){
            if(st[top]=='['){
                top=top-1;

            }
            else{
                cout<<"invalid expression\n";
            }
        }
        else{
            continue;
        }
    
}
if (top == -1){
    cout<<"valid expression\n";

}
else{
    cout<<"INVALID EXPRESSION!\n";
}
}