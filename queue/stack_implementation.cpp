/* 
    (Use 2 stacks)

    for enqueue/push operation - use stack 1
    for dequeue/pop operation - use stack 2 - if stack 2 is empty then push all elements of s1 into it and then pop
    (this maintains fifo concept)

    (if both stacks are empty means queue is empty)

*/

#include<iostream>
#include<stack>
using namespace std;

class queue{

    private:
    stack<int>s1; stack<int>s2;

    public:

    void push(int val){ // O(1)
        s1.push(val);
    }

    int pop(){ // O(n)

        if(s1.empty() && s2.empty()){
            cout<<"Queue Underflow!"<<endl;
            return -1;
        }

        if(s2.empty()){
            
            while(!s1.empty()){

                s2.push(s1.top());
                s1.pop();
            }
        }
        cout<<endl;
        int top= s2.top();
        s2.pop();
        return top;
    }

    bool empty(){

        if(s1.empty() && s2.empty()) return true;

        return false;
    }


};

int main(void){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop();
    cout<<q.pop()<<endl;
    cout<<q.pop();
}