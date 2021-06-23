// STACK USING ARRAY
// stack works on lifo - (last in first out)
// single enrty and exit point 

#include<iostream>
using namespace std;

#define n 100

// push - put element at top of stack (check overflow)
// pop - remove top element from stack (check underflow) 
// empty() - tells stack is empty or not i.e top =-1
class stack{

    private:
    int *arr; // dynamic array
    int top;  // points at top of the stack  

    public:
    stack(){
        arr= new int[n];
        top= -1;
    }

    void push(int val){

        //before pushing check if stack is full (overflow)
        if(top==n-1){
            cout<<"Stack overflow!!!";
            return;
        }

        // if stack is not full then insert element
        top+=1; // as top is initally -1
        arr[top] =val; // insert at top

    }

    void pop(){

        // note: (we actually dont delete a val, we just decement the top)
        //before popping check if stack is alerady empty (underflow)
        if(top==-1){
            cout<<"Stack underflow";
            return;
        }

        // if stack is not empty
        top--;
    }

    // fucntion to return top element
    int Top(){

        if(top==-1){
            cout<<"Stack is empty";
            return 0;
        }

        return arr[top];
    }

    bool empty(){
       return top==-1;
    }

};

int main(void){

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.Top()<<endl;
    s.pop();
    while(!s.empty()){
        cout<<s.Top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<s.empty();

}